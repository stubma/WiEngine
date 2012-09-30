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
#include "wyResultSet.h"
#include "wyDatabase.h"
#include "wyStatement.h"
#include "wyTypes.h"
#include "wyUtils.h"
#include "wyLog.h"
#include <unistd.h>
#include "sqlite3.h"

wyResultSet::wyResultSet(wyDatabase* db, wyStatement* statement) :
		m_db(db),
		m_statement(statement),
		m_sql(wyUtils::copy(statement->getQuery())),
		m_columnNames(NULL) {
	// setup column names
    int columnCount = sqlite3_column_count(statement->getStatement());
    m_columnNames = wyArrayNew(columnCount);
    for(int i = 0; i < columnCount; i++) {
    	char* name = (char*)wyUtils::copy(sqlite3_column_name(statement->getStatement(), i));
    	wyUtils::toLowercase(name);
    	wyArrayPush(m_columnNames, name);
    }
}

wyResultSet::~wyResultSet() {
	// close
	close();

	// free sql
	wyFree((void*)m_sql);

	// free column names
	wyArrayEach(m_columnNames, releaseColumn, NULL);
	wyArrayDestroy(m_columnNames);
}

wyResultSet* wyResultSet::make(wyDatabase* db, wyStatement* statement) {
	wyResultSet* rs = WYNEW wyResultSet(db, statement);
	return (wyResultSet*)rs->autoRelease();
}

bool wyResultSet::releaseColumn(wyArray* arr, void* ptr, int index, void* data) {
	wyFree(ptr);
	return true;
}

bool wyResultSet::next() {
	int rc = 0;
	if(m_statement) {
		bool retry;
		int numberOfRetries = 0;
		do {
			retry = false;

			rc = sqlite3_step(m_statement->getStatement());

			if(SQLITE_BUSY == rc || SQLITE_LOCKED == rc) {
				// this will happen if the db is locked, like if we are doing an update or insert.
				// in that case, retry the step... and maybe wait just 10 milliseconds.
				retry = true;
				if(SQLITE_LOCKED == rc) {
					rc = sqlite3_reset(m_statement->getStatement());
					if(rc != SQLITE_LOCKED) {
						LOGE("wyResultSet::next: Unexpected result from sqlite3_reset (%d) rs", rc);
					}
				}
				usleep(20);

				if(m_db->getBusyRetryTimeout() && (numberOfRetries++ > m_db->getBusyRetryTimeout())) {
					LOGW("wyResultSet::next: Database busy (%@)");
					break;
				}
			} else if(SQLITE_DONE == rc || SQLITE_ROW == rc) {
				// all is well, let's return.
			} else if(SQLITE_ERROR == rc) {
				LOGE("Error calling sqlite3_step (%d: %s) rs", rc, m_db->lastErrorMessage());
				break;
			} else if(SQLITE_MISUSE == rc) {
				LOGE("Error calling sqlite3_step (%d: %s) rs", rc, m_db->lastErrorMessage());
				break;
			} else {
				LOGE("Unknown error calling sqlite3_step (%d: %s) rs", rc, m_db->lastErrorMessage());
				break;
			}
		} while(retry);
	}

	if(rc != SQLITE_ROW) {
		close();
	}

	return rc == SQLITE_ROW;
}

bool wyResultSet::hasAnotherRow() {
	return sqlite3_errcode(m_db->sqliteHandle()) == SQLITE_ROW;
}

void wyResultSet::close() {
	if(m_statement) {
		m_statement->reset();
		m_statement = NULL;
		
		// post close
		if(m_db)
			m_db->postResultSetClosed(this);
	}
}

int wyResultSet::columnCount() {
	return sqlite3_column_count(m_statement->getStatement());
}

bool wyResultSet::columnIndexIsNull(int columnIdx) {
	return sqlite3_column_type(m_statement->getStatement(), columnIdx) == SQLITE_NULL;
}

bool wyResultSet::columnIsNull(const char* columnName) {
	return columnIndexIsNull(columnIndexForName(columnName));
}

int wyResultSet::columnIndexForName(const char* columnName) {
	for(int i = 0; i < m_columnNames->num; i++) {
		char* ptr = (char*)wyArrayGet(m_columnNames, i);
		if(!strcmp(ptr, columnName))
			return i;
	}

	LOGW("Can't find column index for name: %s", columnName);
	return -1;
}

const char* wyResultSet::columnNameForIndex(int columnIdx) {
	if(columnIdx < 0 || columnIdx >= m_columnNames->num)
		return NULL;
	else
		return (const char*)wyArrayGet(m_columnNames, columnIdx);
}

int wyResultSet::intForColumn(const char* columnName) {
	return intForColumnIndex(columnIndexForName(columnName));
}

int wyResultSet::intForColumnIndex(int columnIdx) {
	return sqlite3_column_int(m_statement->getStatement(), columnIdx);
}

long wyResultSet::longForColumn(const char* columnName) {
	return longForColumnIndex(columnIndexForName(columnName));
}

long wyResultSet::longForColumnIndex(int columnIdx) {
	return (long)sqlite3_column_int64(m_statement->getStatement(), columnIdx);
}

int64_t wyResultSet::int64ForColumn(const char* columnName) {
	return int64ForColumnIndex(columnIndexForName(columnName));
}

int64_t wyResultSet::int64ForColumnIndex(int columnIdx) {
	return (int64_t)sqlite3_column_int64(m_statement->getStatement(), columnIdx);
}

bool wyResultSet::boolForColumn(const char* columnName) {
	return boolForColumnIndex(columnIndexForName(columnName));
}

bool wyResultSet::boolForColumnIndex(int columnIdx) {
	return intForColumnIndex(columnIdx) != 0;
}

double wyResultSet::doubleForColumn(const char* columnName) {
	return doubleForColumnIndex(columnIndexForName(columnName));
}

double wyResultSet::doubleForColumnIndex(int columnIdx) {
	return sqlite3_column_double(m_statement->getStatement(), columnIdx);
}

const char* wyResultSet::stringForColumn(const char* columnName) {
	return stringForColumnIndex(columnIndexForName(columnName));
}

const char* wyResultSet::stringForColumnIndex(int columnIdx) {
    if (sqlite3_column_type(m_statement->getStatement(), columnIdx) == SQLITE_NULL || (columnIdx < 0)) {
        return NULL;
    }

    const char* c = (const char*)sqlite3_column_text(m_statement->getStatement(), columnIdx);
    return wyUtils::copy(c);
}

const char* wyResultSet::dataForColumn(const char* columnName, size_t* outLen) {
	return dataForColumnIndex(columnIndexForName(columnName), outLen);
}

const char* wyResultSet::dataForColumnIndex(int columnIdx, size_t* outLen) {
	// check type
    if (sqlite3_column_type(m_statement->getStatement(), columnIdx) == SQLITE_NULL || (columnIdx < 0)) {
    	*outLen = 0;
        return NULL;
    }

    // copy data
    int dataSize = sqlite3_column_bytes(m_statement->getStatement(), columnIdx);
    char* buf = (char*)wyMalloc(dataSize * sizeof(char));
    memcpy(buf, sqlite3_column_blob(m_statement->getStatement(), columnIdx), dataSize);

    // return buffer
    *outLen = dataSize;
    return (const char*)buf;
}

const char* wyResultSet::dataNoCopyForColumn(const char* columnName, size_t* outLen) {
	return dataNoCopyForColumnIndex(columnIndexForName(columnName), outLen);
}

const char* wyResultSet::dataNoCopyForColumnIndex(int columnIdx, size_t* outLen) {
    if (sqlite3_column_type(m_statement->getStatement(), columnIdx) == SQLITE_NULL || (columnIdx < 0)) {
    	*outLen = 0;
        return NULL;
    }

    *outLen = sqlite3_column_bytes(m_statement->getStatement(), columnIdx);
    return (const char*)sqlite3_column_blob(m_statement->getStatement(), columnIdx);
}
