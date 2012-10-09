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
#ifndef __wyDatabase_h__
#define __wyDatabase_h__

#include "wyObject.h"
#include <stdbool.h>
#include "wyHashSet.h"
#include "wyArray.h"
#include "wyStatement.h"
#include "wyResultSet.h"

struct sqlite3;

/**
 * @class wyDatabase
 *
 * \link wyDatabase wyDatabase\endlink是一个对sqlite3数据库的C++封装层。它是一个
 * FMDB的C++移植版，使用方法和FMDB大致相同。
 *
 * \par what is FMDB
 * an Objective-C wrapper for sqlite3: https://github.com/ccgus/fmdb
 */
class WIENGINE_API wyDatabase : public wyObject {
	friend class wyResultSet;

private:
	/**
	 * sqlite3的数据库对象
	 */
	sqlite3* m_db;

	/**
	 * 数据库的路径
	 */
	const char* m_databasePath;

	/**
	 * true表示数据库正在被使用
	 */
	bool m_inUse;

	/**
	 * true表示数据库正在一个事务中
	 */
	bool m_inTransaction;

	/**
	 * true表示执行过的预编译语句将被缓存
	 */
	bool m_shouldCacheStatements;

	/**
	 * 数据库忙时，重试的次数，缺省是0，即一直重试直到成功为止
	 */
	int m_busyRetryTimeout;

	/**
	 * 预编译的语句缓冲
	 */
	wyHashSet* m_cachedStatements;

	/**
	 * 当前已经打开的结果集
	 */
	wyArray* m_resultSets;

private:
	static int statementHashEquals(void* ptr, void* elt);
	static void* buildStatementHash(void* ptr, void* data);
	static bool releaseHash(void* elt, void* data);
	static bool releaseResultSet(wyArray* arr, void* ptr, int index, void* data);

	/**
	 * 打印一条log警告当前数据库正在被使用
	 */
	void warnInUse();

	/**
	 * 获得缓存的语句
	 *
	 * @param sql 查询语句
	 * @return \link wyStatement wyStatement\endlink, 如果没有找到对应的语句，返回NULL
	 */
	wyStatement* getCachedStatement(const char* sql);

	/**
	 * 设置一个缓存的语句
	 *
	 * @param sql 查询语句，用作语句对象的关键字
	 * @param statement \link wyStatement wyStatement\endlink
	 */
	void setCachedStatement(const char* sql, wyStatement* statement);

	/**
	 * 执行一个SQL查询语句
	 *
	 * @param sql 最终的SQL语句，不能包括格式化占位符
	 * @return \link wyResultSet wyResultSet\endlink, 如果失败返回NULL
	 */
	wyResultSet* _executeQuery(const char* sql);

	/**
	 * 执行一个SQL非查询语句
	 *
	 * @param sql 最终的SQL语句，不能包括格式化占位符
	 * @return 成功返回true，失败返回false
	 */
	bool _executeUpdate(const char* sql);

	/**
	 * 在结果集别关闭之后调用，这是由\link wyResultSet wyResultSet\endlink主动调用
	 * 的回调方法
	 *
	 * @param rs \link wyResultSet wyResultSet\endlink
	 */
	void postResultSetClosed(wyResultSet* rs);

protected:
	/**
	 * 构造函数
	 *
	 * @param path 数据库文件绝对路径, 在iOS平台上会被映射到~/Documents下
	 */
	wyDatabase(const char* path);

public:
	virtual ~wyDatabase();

	/**
	 * 静态构造函数
	 *
	 * @param path 数据库文件绝对路径. 在iOS平台上会被映射到~/Documents下
	 * @return \link wyDatabase wyDatabase\endlink实例
	 */
	static wyDatabase* make(const char* path);

	/**
	 * 数据库访问是否是线程安全的
	 *
	 * @return true表示是线程安全的
	 */
	static bool isThreadSafe();

	/**
	 * 得到底层sqlite库的版本
	 *
	 * @return 版本字符串
	 */
	static const char* sqliteLibVersion();

	/**
	 * 获得sqlite3的句柄
	 *
	 * @return sqlite3结构指针
	 */
	sqlite3* sqliteHandle() { return m_db; }

	/**
	 * 打开数据库
	 *
	 * @param flags 打开时的标志，这个选项只能当sqlite版本号大于等于3.5.0时才能使用，
	 * 		如果指定了这个标志但是sqlite版本不够，则会被忽略. 缺省值是0，即没有标志.
	 * @return true表示打开成功
	 */
	bool open(int flags = 0);

	/**
	 * 关闭数据库，释放资源。当然这个只是释放数据库相关的资源，wyDatabase实例并不会
	 * 被释放。您可以重新调用open再次打开数据库。
	 *
	 * \note
	 * \link wyDatabase wyDatabase\endlink在析构中也会调用close，因此如果不再使用
	 * 数据库，直接release也可以，不需要先调用close.
	 *
	 * @return true表示关闭成功
	 */
	bool close();

	/**
	 * 数据库是否已经打开
	 *
	 * @return true表示数据库已经打开
	 */
	bool databaseExists();

	/**
	 * 验证是否数据库链接还是有效的
	 *
	 * @return true表示底层的数据路链接仍然是畅通的
	 */
	bool goodConnection();

	/**
	 * 清除缓存的sql语句对象
	 */
	void clearCachedStatements();

	/**
	 * 关闭当前所有结果集, 释放结果集对象
	 */
	void clearResultSets();

	/**
	 * 执行查询
	 *
	 * @param sql SQL语句，可以包含格式化占位符, 这个参数后面可以跟随和格式化占位符数量相等的参数
	 * @return \link wyResultSet wyResultSet\endlink, 如果失败返回NULL
	 */
	wyResultSet* executeQuery(const char* sql, ...);

	/**
	 * 执行更新
	 *
	 * @param sql SQL语句，可以包含格式化占位符, 这个参数后面可以跟随和格式化占位符数量相等的参数
	 * @return 成功返回true，失败返回false
	 */
	bool executeUpdate(const char* sql, ...);

	/**
	 * 获得最近一次的操作错误信息
	 *
	 * @return 错误信息字符串，调用者不需要负责释放. 如果没有返回NULL
	 */
	const char* lastErrorMessage();

	/**
	 * 获得最近一次的操作错误码
	 *
	 * @return 错误码，或者SQLITE_OK表示无错误
	 */
	int lastErrorCode();

	/**
	 * 最近的操作是否有错误发生
	 *
	 * @return true表示有错误发生
	 */
	bool hadError();

	/**
	 * 最近一次插入的行的id
	 *
	 * @return 最近一次插入的行的id
	 */
	int64_t lastInsertRowId();

	/**
	 * 检查数据库是否正在使用
	 *
	 * @return true表示数据库正在使用
	 */
	bool inUse() { return m_inUse || m_inTransaction; }

	/**
	 * 设置数据库是否正在使用
	 *
	 * @param value true表示数据库正在使用
	 */
	void setInUse(bool value) { m_inUse = value; }

	/**
	 * 是否要缓存预编译的语句
	 *
	 * @return true表示会缓存预编译的语句
	 */
	bool shouldCacheStatements() { return m_shouldCacheStatements; }

	/**
	 * 设置是否要缓存预编译的语句
	 *
	 * @param value true表示会缓存预编译的语句
	 */
	void setShouldCacheStatements(bool value);

	/**
	 * 返回最近一次操作改变的行数
	 *
	 * @return 最近一次操作改变的行数
	 */
	int changes();

	/**
	 * 回滚事务
	 *
	 * @return true表示回滚成功
	 */
	bool rollback();

	/**
	 * 提交事务
	 *
	 * @return true表示提交成功
	 */
	bool commit();

	/**
	 * 开始一个延迟事务
	 *
	 * @return true表示启动成功
	 */
	bool beginDeferredTransaction();

	/**
	 * 开始一个事务
	 *
	 * @return true表示启动成功
	 */
	bool beginTransaction();

	/**
	 * 检查某个表是否存在
	 *
	 * @param tableName 表名称
	 * @return true表示表存在
	 */
	bool tableExists(const char* tableName);

	/**
	 * 一个快捷的封装方法，如果查询返回的第一列是整数类型，则可以用这个方法快速
	 * 得到结果
	 *
	 * @param sql SQL语句，可以包含格式化占位符, 这个参数后面可以跟随和格式化占位符数量相等的参数
	 * @return 结果集中第一列的整数形式结果
	 */
	int intForQuery(const char* sql, ...);

	/**
	 * 一个快捷的封装方法，如果查询返回的第一列是长整数类型，则可以用这个方法快速
	 * 得到结果
	 *
	 * @param sql SQL语句，可以包含格式化占位符, 这个参数后面可以跟随和格式化占位符数量相等的参数
	 * @return 结果集中第一列的长整数形式结果
	 */
	long longForQuery(const char* sql, ...);

	/**
	 * 一个快捷的封装方法，如果查询返回的第一列是64位整数类型，则可以用这个方法快速
	 * 得到结果
	 *
	 * @param sql SQL语句，可以包含格式化占位符, 这个参数后面可以跟随和格式化占位符数量相等的参数
	 * @return 结果集中第一列的64位整数形式结果
	 */
	int64_t int64ForQuery(const char* sql, ...);

	/**
	 * 一个快捷的封装方法，如果查询返回的第一列是布尔类型，则可以用这个方法快速
	 * 得到结果
	 *
	 * @param sql SQL语句，可以包含格式化占位符, 这个参数后面可以跟随和格式化占位符数量相等的参数
	 * @return 结果集中第一列的布尔结果
	 */
	bool boolForQuery(const char* sql, ...);

	/**
	 * 一个快捷的封装方法，如果查询返回的第一列是浮点类型，则可以用这个方法快速
	 * 得到结果
	 *
	 * @param sql SQL语句，可以包含格式化占位符, 这个参数后面可以跟随和格式化占位符数量相等的参数
	 * @return 结果集中第一列的浮点结果
	 */
	double doubleForQuery(const char* sql, ...);

	/**
	 * 一个快捷的封装方法，如果查询返回的第一列是字符串类型，则可以用这个方法快速
	 * 得到结果
	 *
	 * @param sql SQL语句，可以包含格式化占位符, 这个参数后面可以跟随和格式化占位符数量相等的参数
	 * @return 结果集中第一列的字符串结果, 调用者要负责释放该字符串
	 */
	const char* stringForQuery(const char* sql, ...);

	/**
	 * 一个快捷的封装方法，如果查询返回的第一列是二进制类型，则可以用这个方法快速
	 * 得到结果
	 *
	 * @param sql SQL语句，可以包含格式化占位符, 这个参数后面可以跟随和格式化占位符数量相等的参数
	 * @param outLen 用来返回数据长度
	 * @return 结果集中第一列的二进制结果, 调用者要负责释放指针
	 */
	const char* dataForQuery(const char* sql, size_t* outLen, ...);

	/**
	 * 一个快捷的封装方法，如果查询返回的第一列是二进制类型，则可以用这个方法快速
	 * 得到结果
	 *
	 * @param sql SQL语句，可以包含格式化占位符, 这个参数后面可以跟随和格式化占位符数量相等的参数
	 * @param outLen 用来返回数据长度
	 * @return 结果集中第一列的二进制结果, 调用者不需要负责释放指针
	 */
	const char* dataNoCopyForQuery(const char* sql, size_t* outLen, ...);

	/**
	 * 校验sql语句是否合法
	 *
	 * @param sql SQL语句，可以包含格式化占位符, 这个参数后面可以跟随和格式化占位符数量相等的参数
	 * @return NULL表示语句合法，如果不为NULL，表示不合法且其是一个错误字符串，调用者不需要负责释放该字符串
	 */
	const char* validateSQL(const char* sql, ...);

	/**
	 * 得到数据库的schema
	 *
	 * @return \link wyResultSet wyResultSet\endlink
	 */
	wyResultSet* getSchema();

	/**
	 * 得到某个表的schema
	 *
	 * @param tableName 表名
	 * @return \link wyResultSet wyResultSet\endlink
	 */
	wyResultSet* getTableSchema(const char* tableName);

	/**
	 * 检查某个表中是否存在某列
	 *
	 * @param tableName 表名
	 * @param columnName 列名
	 * @return true表示该列存在
	 */
	bool columnExists(const char* tableName, const char* columnName);

	/**
	 * 执行一个SQL文件, 文件的执行会在一个事务中进行，因此要么全部成功要么失败
	 *
	 * @param resId sql文件的资源id，文件必须是utf-8编码
	 * @return true表示执行成功，false表示失败
	 */
	bool executeSQL(int resId);

	/**
	 * 执行一个SQL文件, 文件的执行会在一个事务中进行，因此要么全部成功要么失败
	 *
	 * @param path sql文件的路径，文件必须是utf-8编码
	 * @param isFile true表示\c path 是一个文件系统路径，false表示\c path 是一个assets下的相对路径, 缺省是false
	 * @return true表示执行成功，false表示失败
	 */
	bool executeSQL(const char* path, bool isFile = false);

	/**
	 * 执行一个SQL文件, 文件的执行会在一个事务中进行，因此要么全部成功要么失败
	 *
	 * @param data sql文件的原始字节数据
	 * @param length data的长度
	 * @return true表示执行成功，false表示失败
	 */
	bool executeSQL(const char* data, size_t length);

	/*
	 * setter and getter
	 */

	const char* getDatabasePath() { return m_databasePath; }
	sqlite3* getSqlite3Handle() { return m_db; }
	int getBusyRetryTimeout() { return m_busyRetryTimeout; }
	void setBusyRetryTimeout(int c) { m_busyRetryTimeout = c; }
	bool isInTransaction() { return m_inTransaction; }
};

#endif // __wyDatabase_h__
