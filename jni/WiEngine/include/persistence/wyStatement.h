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
#ifndef __wyStatement_h__
#define __wyStatement_h__

#include "wyObject.h"

struct sqlite3_stmt;
class wyDatabase;

/**
 * @class wyStatement
 *
 * 封装sqlite3的语句对象
 */
class WIENGINE_API wyStatement : public wyObject {
	friend class wyDatabase;

private:
	/**
	 * sqlite3的语句对象
	 */
    sqlite3_stmt* m_statement;

    /**
     * 查询字符串
     */
    const char* m_query;

    /**
     * 被引用的次数
     */
    int m_useCount;

private:
    wyStatement();

public:
    virtual ~wyStatement();

    /**
     * 设置查询语句
     *
     * @param q 查询语句，其内容会被复制，因此方法返回后可以立刻释放
     */
    void setQuery(const char* q);

    /**
     * 获得查询语句
     *
     * @return 查询语句
     */
    const char* getQuery() { return m_query; }

    /**
     * 设置底层的语句对象
     *
     * @param s sqlite3_stmt结构指针
     */
    void setStatement(sqlite3_stmt* s);

    /**
     * 得到底层的语句对象
     *
     * @return sqlite3_stmt结构指针
     */
    sqlite3_stmt* getStatement() { return m_statement; }

    /**
     * 关闭底层的语句对象
     */
    void close();

    /**
     * 重置底层的语句对象
     */
    void reset();
};

#endif // __wyStatement_h__
