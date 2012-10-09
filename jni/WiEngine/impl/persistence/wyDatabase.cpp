/*
 * Copyright (c) 2010 WiYun Inc.
 * Author: luma(stubma@gmail.com)
 *
 * For all entities this program is free software; you can redistribute
 * it and/or modify it under the terms of the 'WiEngine' license with
 * the additional provision that 'WiEngine' must be credited in a manner
 * that can be be observed by end users, for example, in the credits or during
 * start up. (please find WiEngine logo in sdk's logo folder)
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
#include "wyDatabase.h"
#include "wyTypes.h"
#include "wyUtils.h"
#include "wyLog.h"
#include "sqlite3.h"
#include <string.h>
#include <unistd.h>
#include <ctype.h>

typedef struct wyStatementHash {
	const char* query;
	wyStatement* statement;
} wyStatementHash;

wyDatabase::wyDatabase(const char* path) :
		m_db(NULL),
		m_databasePath(wyUtils::copy(path)),
		m_inUse(false),
		m_inTransaction(false),
		m_shouldCacheStatements(false),
		m_busyRetryTimeout(0),
		m_resultSets(wyArrayNew(10)),
		m_cachedStatements(wyHashSetNew(10, statementHashEquals, buildStatementHash)) {
}

wyDatabase::~wyDatabase() {
	close();

	wyHashSetDestroy(m_cachedStatements);
	m_cachedStatements = NULL;

	wyArrayDestroy(m_resultSets);
	m_resultSets = NULL;

	wyFree((void*)m_databasePath);
}

wyDatabase* wyDatabase::make(const char* path) {
	wyDatabase* d = WYNEW wyDatabase(path);
	return (wyDatabase*)d->autoRelease();
}

bool wyDatabase::isThreadSafe() {
	return sqlite3_threadsafe() != SQLITE_CONFIG_SINGLETHREAD;
}

const char* wyDatabase::sqliteLibVersion() {
	return sqlite3_libversion();
}

int wyDatabase::statementHashEquals(void* ptr, void* elt) {
	const char* query = (const char*)ptr;
	wyStatementHash* hash = (wyStatementHash*)elt;
	return !strcmp(query, hash->query);
}

void* wyDatabase::buildStatementHash(void* ptr, void* data) {
	// we don't retain statement here because its retain count is 1
	wyStatementHash* hash = (wyStatementHash*)wyCalloc(1, sizeof(wyStatementHash));
	hash->query = wyUtils::copy((const char*)ptr);
	hash->statement = (wyStatement*)data;
	return hash;
}

bool wyDatabase::releaseHash(void* elt, void* data) {
	wyStatementHash* hash = (wyStatementHash*)elt;
	wyFree((void*)hash->query);
	hash->statement->release();
	wyFree(hash);
	return false;
}

bool wyDatabase::releaseResultSet(wyArray* arr, void* ptr, int index, void* data) {
	wyResultSet* rs = (wyResultSet*)ptr;
	rs->close();
	return true;
}

bool wyDatabase::open(int flags) {
    if(m_db) {
        return true;
    }

	// database path which is not mapped yet
	const char* path = m_databasePath;
	
	// if null, create it in memory
	// if not null, create intermediate directory
	if(!path)
		path = wyUtils::copy(":memory:");
	else {
		if(!wyUtils::createIntermediateFolders(path)) {
			LOGE("failed to create containing directory for database");
			return false;
		}
		
		// map to platform
		path = wyUtils::mapLocalPath(path);
	}
	
	// create database
    int err = SQLITE_OK;
#if SQLITE_VERSION_NUMBER >= 3005000
    if(flags != 0)
		err = sqlite3_open_v2(path, &m_db, flags, NULL);
    else
#endif
    	err = sqlite3_open(path, &m_db);
	
	// free path
	wyFree((void*)path);
	
	// check error
    if(err != SQLITE_OK) {
        LOGE("wyDatabase:open: error opening: %d", err);
        m_db = NULL;
        return false;
    }

    return true;
}

bool wyDatabase::close() {
	clearResultSets();
	clearCachedStatements();

	// check db
	if(!m_db) {
		return true;
	}

	// variables
    int rc;
	bool retry;
	int numberOfRetries = 0;

	// try to close db
	// if it is busy or locked, wait for a while and retry
	// m_busyRetryTimeout controls max number of retries
    do {
		retry = false;
		rc = sqlite3_close(m_db);
		if(SQLITE_BUSY == rc || SQLITE_LOCKED == rc) {
			retry = true;
			usleep(20);
			if(m_busyRetryTimeout && (numberOfRetries++ > m_busyRetryTimeout)) {
				LOGW("wyDatabase:close: Database busy, unable to close");
				return false;
			}
		} else if(SQLITE_OK != rc) {
			LOGW("wyDatabase:close: error closing!: %d", rc);
		}
	} while(retry);

    // nullify reference
	m_db = NULL;

	return true;
}

bool wyDatabase::goodConnection() {
	// basic check
	if(!m_db) {
		return false;
	}

	// select something from sqlite_master to verify the connection
	wyResultSet* rs = executeQuery("select name from sqlite_master where type='table'");

	// if we can get result from sqlite_mast, return true
	if(rs) {
		rs->release();
		return true;
	}

	return false;
}

void wyDatabase::clearCachedStatements() {
	if(m_cachedStatements) {
		wyHashSetFilter(m_cachedStatements, releaseHash, NULL);
	}
}

void wyDatabase::clearResultSets() {
	if(m_resultSets) {
		wyArrayConcurrentEach(m_resultSets, releaseResultSet, NULL);
		wyArrayClear(m_resultSets);
	}
}

bool wyDatabase::databaseExists() {
    if (!m_db) {
        LOGW("The wyDatabase %d is not open.", this);
        return false;
    }

    return true;
}

bool wyDatabase::executeUpdate(const char* sql, ...) {
	// generate final sql string
    va_list args;
    va_start(args, sql);
    char buf[512];
    vsprintf(buf, sql, args);
    va_end(args);

    // execute the final sql
    return _executeUpdate(buf);
}

bool wyDatabase::_executeUpdate(const char* sql) {
	// database check
    if (!databaseExists()) {
        return NULL;
    }

    // is in use?
    if (m_inUse) {
        warnInUse();
        return NULL;
    }

    // use it now
    setInUse(true);

    // variables
    int rc = 0;
	sqlite3_stmt* pStmt = NULL;
	wyStatement* cachedStmt = NULL;

	// get cached statement
	cachedStmt = getCachedStatement(sql);
	pStmt = cachedStmt ? cachedStmt->getStatement() : NULL;

    // retry flags
    int numberOfRetries = 0;
	bool retry = false;

	// compile statement until success or fail
    if(!pStmt) {
		do {
			// prepare statement
			retry = false;
			rc = sqlite3_prepare_v2(m_db, sql, -1, &pStmt, 0);

			// wait if busy
			if(SQLITE_BUSY == rc || SQLITE_LOCKED == rc) {
				retry = true;
				usleep(20);

				if(m_busyRetryTimeout && (numberOfRetries++ > m_busyRetryTimeout)) {
					LOGW("wyDatabase:_executeUpdate: Database busy");
					sqlite3_finalize(pStmt);
					setInUse(false);
					return false;
				}
			} else if(SQLITE_OK != rc) {
				// log error
				LOGE("wyDatabase:_executeUpdate: DB Error: %d \"%s\"", lastErrorCode(), lastErrorMessage());

				// release statement
				sqlite3_finalize(pStmt);

				// set in use
				setInUse(false);
				return false;
			}
		} while(retry);
	}

    /*
     * Call sqlite3_step() to run the virtual machine. Since the SQL being
     * executed is not a SELECT statement, we assume no data will be returned.
     */
    numberOfRetries = 0;
	do {
		rc = sqlite3_step(pStmt);
		retry = false;

		if(SQLITE_BUSY == rc || SQLITE_LOCKED == rc) {
			// this will happen if the db is locked, like if we are doing an update or insert.
			// in that case, retry the step... and maybe wait just 10 milliseconds.
			retry = true;
			if(SQLITE_LOCKED == rc) {
				rc = sqlite3_reset(pStmt);
				if(rc != SQLITE_LOCKED) {
					LOGE("wyDatabase:_executeUpdate: Unexpected result from sqlite3_reset (%d) eu", rc);
				}
			}
			usleep(20);

			if(m_busyRetryTimeout && (numberOfRetries++ > m_busyRetryTimeout)) {
				LOGW("wyDatabase:_executeUpdate: Database busy 2");
				retry = false;
			}
		} else if(SQLITE_DONE == rc || SQLITE_ROW == rc) {
			// all is well, let's return.
		} else if(SQLITE_ERROR == rc) {
			LOGE("Error calling sqlite3_step (%d: %s) SQLITE_ERROR", rc, lastErrorMessage());
		} else if(SQLITE_MISUSE == rc) {
			LOGE("Error calling sqlite3_step (%d: %s) SQLITE_MISUSE", rc, lastErrorMessage());
		} else {
			LOGE("Unknown error calling sqlite3_step (%d: %s) eu", rc, lastErrorMessage());
		}
	} while(retry);

	// cache statement
    if(m_shouldCacheStatements && !cachedStmt) {
		cachedStmt = WYNEW wyStatement();
		cachedStmt->setStatement(pStmt);
		cachedStmt->setQuery(sql);
		cachedStmt->m_useCount = 1;
		setCachedStatement(sql, cachedStmt);
	}

    // if statement is cached, don't finalize it
    if(cachedStmt) {
		rc = sqlite3_reset(pStmt);
	} else {
		/*
		 * Finalize the virtual machine. This releases all memory and other
		 * resources allocated by the sqlite3_prepare() call above.
		 */
		rc = sqlite3_finalize(pStmt);
	}

    // release usage
    setInUse(false);

    // returb
    return rc == SQLITE_OK;
}

wyResultSet* wyDatabase::executeQuery(const char* sql, ...) {
	// generate final sql string
    va_list args;
    va_start(args, sql);
    char buf[512];
    vsprintf(buf, sql, args);
    va_end(args);

    // execute the final sql
    return _executeQuery(buf);
}

wyResultSet* wyDatabase::_executeQuery(const char* sql) {
	// database check
    if (!databaseExists()) {
        return NULL;
    }

    // is in use?
    if (m_inUse) {
        warnInUse();
        return NULL;
    }

    // use it now
    setInUse(true);

    // variables
    wyResultSet* rs = NULL;
	int rc = 0;
	sqlite3_stmt* pStmt = NULL;
	wyStatement* statement = NULL;

	// get cached statement
	statement = getCachedStatement(sql);
	pStmt = statement ? statement->getStatement() : NULL;

    // retry flags
    int numberOfRetries = 0;
	bool retry = false;

	// compile statement until success or fail
    if(!pStmt) {
		do {
			// prepare statement
			retry = false;
			rc = sqlite3_prepare_v2(m_db, sql, -1, &pStmt, 0);

			// wait if busy
			if(SQLITE_BUSY == rc || SQLITE_LOCKED == rc) {
				retry = true;
				usleep(20);

				if(m_busyRetryTimeout && (numberOfRetries++ > m_busyRetryTimeout)) {
					LOGW("wyDatabase:_executeQuery: Database busy");
					sqlite3_finalize(pStmt);
					setInUse(false);
					return NULL;
				}
			} else if(SQLITE_OK != rc) {
				// log error
				LOGE("wyDatabase:_executeQuery: DB Error: %d \"%s\"", lastErrorCode(), lastErrorMessage());

				// release statement
				sqlite3_finalize(pStmt);

				// set in use
				setInUse(false);
				return NULL;
			}
		} while(retry);
	}

    // create wyStatement
    if (!statement) {
        statement = WYNEW wyStatement();
        statement->setStatement(pStmt);
        statement->setQuery(sql);
        statement->m_useCount = 1;
		setCachedStatement(sql, statement);
    } else {
    	statement->m_useCount++;
    }

    // now query
    rs = wyResultSet::make(this, statement);
    wyArrayPush(m_resultSets, rs);

    // set in use flag
    setInUse(false);

    // return
    return rs;
}

void wyDatabase::postResultSetClosed(wyResultSet* rs) {
	// remove it from result set
	rs->m_db = NULL;
	wyArrayDeleteObj(m_resultSets, rs, NULL, NULL);

	// find related statement
	const char* sql = rs->m_sql;
	wyStatementHash* hash = (wyStatementHash*)wyHashSetFind(m_cachedStatements, wyUtils::strHash(sql), (void*)sql);
	if(hash) {
		// decrease use count and release it if it is zero as well as cache flag is false
		hash->statement->m_useCount--;
		if(hash->statement->m_useCount <= 0 && !m_shouldCacheStatements) {
			wyHashSetRemove(m_cachedStatements, wyUtils::strHash(sql), (void*)sql);
			releaseHash(hash, NULL);
		}
	}
}

void wyDatabase::warnInUse() {
    LOGW("The wyDatabase %d is currently in use.", this);
}

const char* wyDatabase::lastErrorMessage() {
	if(m_db)
		return sqlite3_errmsg(m_db);
	else
		return NULL;
}

int wyDatabase::lastErrorCode() {
	if(m_db)
		return sqlite3_errcode(m_db);
	else
		return SQLITE_OK;
}

bool wyDatabase::hadError() {
    int lastErrCode = lastErrorCode();
    return (lastErrCode > SQLITE_OK && lastErrCode < SQLITE_ROW);
}

int64_t wyDatabase::lastInsertRowId() {
    if(m_inUse) {
    	warnInUse();
        return false;
    }

    setInUse(true);
    sqlite_int64 ret = sqlite3_last_insert_rowid(m_db);
    setInUse(false);

    return (int64_t)ret;
}

void wyDatabase::setShouldCacheStatements(bool value) {
	m_shouldCacheStatements = value;

	if(m_shouldCacheStatements && !m_cachedStatements) {
		m_cachedStatements = wyHashSetNew(10, statementHashEquals, buildStatementHash);
	}

	if(!m_shouldCacheStatements) {
		clearCachedStatements();
	}
}

int wyDatabase::changes() {
    if (m_inUse) {
        warnInUse();
        return 0;
    }

    setInUse(true);
    int ret = sqlite3_changes(m_db);
    setInUse(false);

    return ret;
}

wyStatement* wyDatabase::getCachedStatement(const char* sql) {
	wyStatementHash* hash = (wyStatementHash*)wyHashSetFind(m_cachedStatements, wyUtils::strHash(sql), (void*)sql);
	return hash == NULL ? NULL : hash->statement;
}

void wyDatabase::setCachedStatement(const char* sql, wyStatement* statement) {
	wyHashSetInsert(m_cachedStatements, wyUtils::strHash(sql), (void*)sql, statement);
}

bool wyDatabase::rollback() {
	bool b = executeUpdate("ROLLBACK TRANSACTION;");
    if (b) {
        m_inTransaction = false;
    }
    return b;
}

bool wyDatabase::commit() {
    bool b = executeUpdate("COMMIT TRANSACTION;");
    if (b) {
    	m_inTransaction = false;
    }
    return b;
}

bool wyDatabase::beginDeferredTransaction() {
	bool b = executeUpdate("BEGIN DEFERRED TRANSACTION;");
    if (b) {
    	m_inTransaction = true;
    }
    return b;
}

bool wyDatabase::beginTransaction() {
	bool b = executeUpdate("BEGIN EXCLUSIVE TRANSACTION;");
    if (b) {
    	m_inTransaction = true;
    }
    return b;
}

bool wyDatabase::tableExists(const char* tableName) {
    bool returnBool;

    // search in sqlite_master table if table exists
    char* name = (char*)wyUtils::copy(tableName);
    wyUtils::toLowercase(name);
    wyResultSet* rs = executeQuery("select [sql] from sqlite_master where [type] = 'table' and lower(name) = '%s'", name);
    wyFree(name);

    // if at least one next exists, table exists
    returnBool = rs->next();

    // close and free object
    rs->close();

    return returnBool;
}

int wyDatabase::intForQuery(const char* sql, ...) {
	// generate final sql string
    va_list args;
    va_start(args, sql);
    char buf[512];
    vsprintf(buf, sql, args);
    va_end(args);

    wyResultSet* rs = _executeQuery(buf);
    rs->next();
    return rs->intForColumnIndex(0);
}

long wyDatabase::longForQuery(const char* sql, ...) {
	// generate final sql string
    va_list args;
    va_start(args, sql);
    char buf[512];
    vsprintf(buf, sql, args);
    va_end(args);

    wyResultSet* rs = _executeQuery(buf);
    rs->next();
    return rs->longForColumnIndex(0);
}

int64_t wyDatabase::int64ForQuery(const char* sql, ...) {
	// generate final sql string
    va_list args;
    va_start(args, sql);
    char buf[512];
    vsprintf(buf, sql, args);
    va_end(args);

    wyResultSet* rs = _executeQuery(buf);
    rs->next();
    return rs->int64ForColumnIndex(0);
}

bool wyDatabase::boolForQuery(const char* sql, ...) {
	// generate final sql string
    va_list args;
    va_start(args, sql);
    char buf[512];
    vsprintf(buf, sql, args);
    va_end(args);

    wyResultSet* rs = _executeQuery(buf);
    rs->next();
    return rs->boolForColumnIndex(0);
}

double wyDatabase::doubleForQuery(const char* sql, ...) {
	// generate final sql string
    va_list args;
    va_start(args, sql);
    char buf[512];
    vsprintf(buf, sql, args);
    va_end(args);

    wyResultSet* rs = _executeQuery(buf);
    rs->next();
    return rs->doubleForColumnIndex(0);
}

const char* wyDatabase::stringForQuery(const char* sql, ...) {
	// generate final sql string
    va_list args;
    va_start(args, sql);
    char buf[512];
    vsprintf(buf, sql, args);
    va_end(args);

    wyResultSet* rs = _executeQuery(buf);
    rs->next();
    return rs->stringForColumnIndex(0);
}

const char* wyDatabase::dataForQuery(const char* sql, size_t* outLen, ...) {
	// generate final sql string
    va_list args;
    va_start(args, outLen);
    char buf[512];
    vsprintf(buf, sql, args);
    va_end(args);

    wyResultSet* rs = _executeQuery(buf);
    rs->next();
    return rs->dataForColumnIndex(0, outLen);
}

const char* wyDatabase::dataNoCopyForQuery(const char* sql, size_t* outLen, ...) {
	// generate final sql string
    va_list args;
    va_start(args, outLen);
    char buf[512];
    vsprintf(buf, sql, args);
    va_end(args);

    wyResultSet* rs = _executeQuery(buf);
    rs->next();
    return rs->dataNoCopyForColumnIndex(0, outLen);
}

const char* wyDatabase::validateSQL(const char* sql, ...) {
	// generate final sql string
	va_list args;
	va_start(args, sql);
	char buf[512];
	vsprintf(buf, sql, args);
	va_end(args);

	// variables
	sqlite3_stmt* pStmt = NULL;
	bool keepTrying = true;
	int numberOfRetries = 0;
	const char* ret = NULL;

	// set in use flag
	setInUse(true);

	// trying until success or fail
	while(keepTrying) {
		keepTrying = false;
		int rc = sqlite3_prepare_v2(m_db, buf, -1, &pStmt, 0);
		if(rc == SQLITE_BUSY || rc == SQLITE_LOCKED) {
			keepTrying = true;
			usleep(20);

			if(m_busyRetryTimeout && (numberOfRetries++ > m_busyRetryTimeout)) {
				LOGW("wyDatabase::validateSQL: Database busy");
			}
		} else if(rc != SQLITE_OK) {
			ret = lastErrorMessage();
		}
	}

	// set in use flag
	setInUse(false);

	// release statement
	sqlite3_finalize(pStmt);

	return ret;
}

wyResultSet* wyDatabase::getSchema() {
	// result columns: type[STRING], name[STRING],tbl_name[STRING], rootpage[INTEGER], sql[STRING]
    wyResultSet* rs = executeQuery("SELECT type, name, tbl_name, rootpage, sql FROM (SELECT * FROM sqlite_master UNION ALL SELECT * FROM sqlite_temp_master) WHERE type != 'meta' AND name NOT LIKE 'sqlite_%' ORDER BY tbl_name, type DESC, name");
    return rs;
}

wyResultSet* wyDatabase::getTableSchema(const char* tableName) {
    // result columns: cid[INTEGER], name, type [STRING], notnull[INTEGER], dflt_value[], pk[INTEGER]
    wyResultSet* rs = executeQuery("PRAGMA table_info(%s)", tableName);
    return rs;
}

bool wyDatabase::columnExists(const char* tableName, const char* columnName) {
    bool returnBool = false;

    // lower case table name
    const char* tn = wyUtils::copy(tableName);
    wyUtils::toLowercase((char*)tn);

    // lower case column name
    const char* cn = wyUtils::copy(columnName);
    wyUtils::toLowercase((char*)cn);

    // get table schema
    wyResultSet* rs = getTableSchema(tableName);

    // check if column is present in table schema
    while(rs->next()) {
    	const char* column = rs->stringForColumn("name");
    	wyUtils::toLowercase((char*)column);
    	if(!strcmp(column, columnName)) {
    		returnBool = true;
    		wyFree((void*)column);
    		break;
    	}

		wyFree((void*)column);
    }

    // free
    wyFree((void*)tn);
    wyFree((void*)cn);

    return returnBool;
}

bool wyDatabase::executeSQL(int resId) {
	size_t len;
	char* raw = wyUtils::loadRaw(resId, &len);
	bool ret = executeSQL(raw, len);
	wyFree(raw);
	return ret;
}

bool wyDatabase::executeSQL(const char* path, bool isFile) {
	size_t len;
	char* raw = wyUtils::loadRaw(path, isFile, &len);
	bool ret = executeSQL(raw, len);
	wyFree(raw);
	return ret;
}

bool wyDatabase::executeSQL(const char* data, size_t length) {
	// begin transaction
	if(!beginTransaction()) {
		LOGE("wyDatabase::executeSQL: failed to start transaction");
		return false;
	}

	// find every line and execute it
	char* tmp = (char*)data;
	int start = 0;
	for(int i = 0; i < length; i++) {
		if(isspace(tmp[i]) && i == start) {
			start++;
		} else if(tmp[i] == ';') {
			// make a temp c string
			tmp[i] = 0;

			// execute
			bool success = executeUpdate(tmp + start);

			// restore
			tmp[i] = ';';

			// if success, go to next start
			// if failed, abort
			if(success) {
				start = i + 1;
			} else {
				// commit
				if(!rollback()) {
					LOGE("wyDatabase::executeSQL: failed to rollback transaction");
				}

				return false;
			}
		}
	}

	// commit
	if(!commit()) {
		LOGE("wyDatabase::executeSQL: failed to commit transaction");
		return false;
	}

	return true;
}
