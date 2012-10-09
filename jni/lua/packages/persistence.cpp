/*
** Lua binding: persistence
** Generated automatically by tolua++-1.0.92 on Wed Nov 23 22:00:42 2011.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_persistence_open (lua_State* tolua_S);

#include "WiEngine.h"

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_wyDatabase (lua_State* tolua_S)
{
 wyDatabase* self = (wyDatabase*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyStatement (lua_State* tolua_S)
{
 wyStatement* self = (wyStatement*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyResultSet (lua_State* tolua_S)
{
 wyResultSet* self = (wyResultSet*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_int64_t (lua_State* tolua_S)
{
 int64_t* self = (int64_t*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"size_t");
 tolua_usertype(tolua_S,"wyStatement");
 tolua_usertype(tolua_S,"sqlite3_stmt");
 tolua_usertype(tolua_S,"wyDatabase");
 tolua_usertype(tolua_S,"wyResultSet");
 tolua_usertype(tolua_S,"sqlite3");
 tolua_usertype(tolua_S,"wyObject");
 tolua_usertype(tolua_S,"wyPrefs");
 tolua_usertype(tolua_S,"int64_t");
}

/* method: getInt of class  wyPrefs */
#ifndef TOLUA_DISABLE_tolua_persistence_wyPrefs_getInt00
static int tolua_persistence_wyPrefs_getInt00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyPrefs",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* key = ((const char*)  tolua_tostring(tolua_S,2,0));
  int defValue = ((int)  tolua_tonumber(tolua_S,3,0));
  {
   int tolua_ret = (int)  wyPrefs::getInt(key,defValue);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getInt'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setInt of class  wyPrefs */
#ifndef TOLUA_DISABLE_tolua_persistence_wyPrefs_setInt00
static int tolua_persistence_wyPrefs_setInt00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyPrefs",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* key = ((const char*)  tolua_tostring(tolua_S,2,0));
  int value = ((int)  tolua_tonumber(tolua_S,3,0));
  {
   wyPrefs::setInt(key,value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setInt'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getBool of class  wyPrefs */
#ifndef TOLUA_DISABLE_tolua_persistence_wyPrefs_getBool00
static int tolua_persistence_wyPrefs_getBool00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyPrefs",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,3,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* key = ((const char*)  tolua_tostring(tolua_S,2,0));
  bool defValue = ((bool)  tolua_toboolean(tolua_S,3,false));
  {
   bool tolua_ret = (bool)  wyPrefs::getBool(key,defValue);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getBool'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setBool of class  wyPrefs */
#ifndef TOLUA_DISABLE_tolua_persistence_wyPrefs_setBool00
static int tolua_persistence_wyPrefs_setBool00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyPrefs",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* key = ((const char*)  tolua_tostring(tolua_S,2,0));
  bool value = ((bool)  tolua_toboolean(tolua_S,3,0));
  {
   wyPrefs::setBool(key,value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setBool'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setInt64 of class  wyPrefs */
#ifndef TOLUA_DISABLE_tolua_persistence_wyPrefs_setInt6400
static int tolua_persistence_wyPrefs_setInt6400(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyPrefs",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"int64_t",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* key = ((const char*)  tolua_tostring(tolua_S,2,0));
  int64_t value = *((int64_t*)  tolua_tousertype(tolua_S,3,0));
  {
   wyPrefs::setInt64(key,value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setInt64'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getInt64 of class  wyPrefs */
#ifndef TOLUA_DISABLE_tolua_persistence_wyPrefs_getInt6400
static int tolua_persistence_wyPrefs_getInt6400(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyPrefs",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"int64_t",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* key = ((const char*)  tolua_tostring(tolua_S,2,0));
  int64_t defValue = *((int64_t*)  tolua_tousertype(tolua_S,3,0));
  {
   int64_t tolua_ret = (int64_t)  wyPrefs::getInt64(key,defValue);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((int64_t)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"int64_t");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(int64_t));
     tolua_pushusertype(tolua_S,tolua_obj,"int64_t");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getInt64'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getString of class  wyPrefs */
#ifndef TOLUA_DISABLE_tolua_persistence_wyPrefs_getString00
static int tolua_persistence_wyPrefs_getString00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyPrefs",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* key = ((const char*)  tolua_tostring(tolua_S,2,0));
  const char* defValue = ((const char*)  tolua_tostring(tolua_S,3,0));
  {
   const char* tolua_ret = (const char*)  wyPrefs::getString(key,defValue);
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getString'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setString of class  wyPrefs */
#ifndef TOLUA_DISABLE_tolua_persistence_wyPrefs_setString00
static int tolua_persistence_wyPrefs_setString00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyPrefs",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* key = ((const char*)  tolua_tostring(tolua_S,2,0));
  const char* value = ((const char*)  tolua_tostring(tolua_S,3,0));
  {
   wyPrefs::setString(key,value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setString'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: clear of class  wyPrefs */
#ifndef TOLUA_DISABLE_tolua_persistence_wyPrefs_clear00
static int tolua_persistence_wyPrefs_clear00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyPrefs",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   wyPrefs::clear();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'clear'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: remove of class  wyPrefs */
#ifndef TOLUA_DISABLE_tolua_persistence_wyPrefs_remove00
static int tolua_persistence_wyPrefs_remove00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyPrefs",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* key = ((const char*)  tolua_tostring(tolua_S,2,0));
  {
   wyPrefs::remove(key);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'remove'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  wyDatabase */
#ifndef TOLUA_DISABLE_tolua_persistence_wyDatabase_delete00
static int tolua_persistence_wyDatabase_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyDatabase",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyDatabase* self = (wyDatabase*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: make of class  wyDatabase */
#ifndef TOLUA_DISABLE_tolua_persistence_wyDatabase_make00
static int tolua_persistence_wyDatabase_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyDatabase",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* path = ((const char*)  tolua_tostring(tolua_S,2,0));
  {
   wyDatabase* tolua_ret = (wyDatabase*)  wyDatabase::make(path);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyDatabase");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'make'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isThreadSafe of class  wyDatabase */
#ifndef TOLUA_DISABLE_tolua_persistence_wyDatabase_isThreadSafe00
static int tolua_persistence_wyDatabase_isThreadSafe00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyDatabase",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   bool tolua_ret = (bool)  wyDatabase::isThreadSafe();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isThreadSafe'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: sqliteLibVersion of class  wyDatabase */
#ifndef TOLUA_DISABLE_tolua_persistence_wyDatabase_sqliteLibVersion00
static int tolua_persistence_wyDatabase_sqliteLibVersion00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyDatabase",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   const char* tolua_ret = (const char*)  wyDatabase::sqliteLibVersion();
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'sqliteLibVersion'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: sqliteHandle of class  wyDatabase */
#ifndef TOLUA_DISABLE_tolua_persistence_wyDatabase_sqliteHandle00
static int tolua_persistence_wyDatabase_sqliteHandle00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyDatabase",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyDatabase* self = (wyDatabase*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'sqliteHandle'", NULL);
#endif
  {
   sqlite3* tolua_ret = (sqlite3*)  self->sqliteHandle();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"sqlite3");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'sqliteHandle'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: open of class  wyDatabase */
#ifndef TOLUA_DISABLE_tolua_persistence_wyDatabase_open00
static int tolua_persistence_wyDatabase_open00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyDatabase",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyDatabase* self = (wyDatabase*)  tolua_tousertype(tolua_S,1,0);
  int flags = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'open'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->open(flags);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'open'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: close of class  wyDatabase */
#ifndef TOLUA_DISABLE_tolua_persistence_wyDatabase_close00
static int tolua_persistence_wyDatabase_close00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyDatabase",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyDatabase* self = (wyDatabase*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'close'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->close();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'close'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: databaseExists of class  wyDatabase */
#ifndef TOLUA_DISABLE_tolua_persistence_wyDatabase_databaseExists00
static int tolua_persistence_wyDatabase_databaseExists00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyDatabase",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyDatabase* self = (wyDatabase*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'databaseExists'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->databaseExists();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'databaseExists'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: goodConnection of class  wyDatabase */
#ifndef TOLUA_DISABLE_tolua_persistence_wyDatabase_goodConnection00
static int tolua_persistence_wyDatabase_goodConnection00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyDatabase",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyDatabase* self = (wyDatabase*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'goodConnection'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->goodConnection();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'goodConnection'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: clearCachedStatements of class  wyDatabase */
#ifndef TOLUA_DISABLE_tolua_persistence_wyDatabase_clearCachedStatements00
static int tolua_persistence_wyDatabase_clearCachedStatements00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyDatabase",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyDatabase* self = (wyDatabase*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'clearCachedStatements'", NULL);
#endif
  {
   self->clearCachedStatements();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'clearCachedStatements'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: clearResultSets of class  wyDatabase */
#ifndef TOLUA_DISABLE_tolua_persistence_wyDatabase_clearResultSets00
static int tolua_persistence_wyDatabase_clearResultSets00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyDatabase",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyDatabase* self = (wyDatabase*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'clearResultSets'", NULL);
#endif
  {
   self->clearResultSets();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'clearResultSets'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: lastErrorMessage of class  wyDatabase */
#ifndef TOLUA_DISABLE_tolua_persistence_wyDatabase_lastErrorMessage00
static int tolua_persistence_wyDatabase_lastErrorMessage00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyDatabase",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyDatabase* self = (wyDatabase*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'lastErrorMessage'", NULL);
#endif
  {
   const char* tolua_ret = (const char*)  self->lastErrorMessage();
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'lastErrorMessage'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: lastErrorCode of class  wyDatabase */
#ifndef TOLUA_DISABLE_tolua_persistence_wyDatabase_lastErrorCode00
static int tolua_persistence_wyDatabase_lastErrorCode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyDatabase",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyDatabase* self = (wyDatabase*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'lastErrorCode'", NULL);
#endif
  {
   int tolua_ret = (int)  self->lastErrorCode();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'lastErrorCode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: hadError of class  wyDatabase */
#ifndef TOLUA_DISABLE_tolua_persistence_wyDatabase_hadError00
static int tolua_persistence_wyDatabase_hadError00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyDatabase",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyDatabase* self = (wyDatabase*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'hadError'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->hadError();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'hadError'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: lastInsertRowId of class  wyDatabase */
#ifndef TOLUA_DISABLE_tolua_persistence_wyDatabase_lastInsertRowId00
static int tolua_persistence_wyDatabase_lastInsertRowId00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyDatabase",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyDatabase* self = (wyDatabase*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'lastInsertRowId'", NULL);
#endif
  {
   int64_t tolua_ret = (int64_t)  self->lastInsertRowId();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((int64_t)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"int64_t");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(int64_t));
     tolua_pushusertype(tolua_S,tolua_obj,"int64_t");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'lastInsertRowId'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: inUse of class  wyDatabase */
#ifndef TOLUA_DISABLE_tolua_persistence_wyDatabase_inUse00
static int tolua_persistence_wyDatabase_inUse00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyDatabase",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyDatabase* self = (wyDatabase*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'inUse'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->inUse();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'inUse'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setInUse of class  wyDatabase */
#ifndef TOLUA_DISABLE_tolua_persistence_wyDatabase_setInUse00
static int tolua_persistence_wyDatabase_setInUse00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyDatabase",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyDatabase* self = (wyDatabase*)  tolua_tousertype(tolua_S,1,0);
  bool value = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setInUse'", NULL);
#endif
  {
   self->setInUse(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setInUse'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: shouldCacheStatements of class  wyDatabase */
#ifndef TOLUA_DISABLE_tolua_persistence_wyDatabase_shouldCacheStatements00
static int tolua_persistence_wyDatabase_shouldCacheStatements00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyDatabase",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyDatabase* self = (wyDatabase*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'shouldCacheStatements'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->shouldCacheStatements();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'shouldCacheStatements'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setShouldCacheStatements of class  wyDatabase */
#ifndef TOLUA_DISABLE_tolua_persistence_wyDatabase_setShouldCacheStatements00
static int tolua_persistence_wyDatabase_setShouldCacheStatements00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyDatabase",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyDatabase* self = (wyDatabase*)  tolua_tousertype(tolua_S,1,0);
  bool value = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setShouldCacheStatements'", NULL);
#endif
  {
   self->setShouldCacheStatements(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setShouldCacheStatements'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: changes of class  wyDatabase */
#ifndef TOLUA_DISABLE_tolua_persistence_wyDatabase_changes00
static int tolua_persistence_wyDatabase_changes00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyDatabase",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyDatabase* self = (wyDatabase*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'changes'", NULL);
#endif
  {
   int tolua_ret = (int)  self->changes();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'changes'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: rollback of class  wyDatabase */
#ifndef TOLUA_DISABLE_tolua_persistence_wyDatabase_rollback00
static int tolua_persistence_wyDatabase_rollback00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyDatabase",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyDatabase* self = (wyDatabase*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'rollback'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->rollback();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'rollback'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: commit of class  wyDatabase */
#ifndef TOLUA_DISABLE_tolua_persistence_wyDatabase_commit00
static int tolua_persistence_wyDatabase_commit00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyDatabase",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyDatabase* self = (wyDatabase*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'commit'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->commit();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'commit'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: beginDeferredTransaction of class  wyDatabase */
#ifndef TOLUA_DISABLE_tolua_persistence_wyDatabase_beginDeferredTransaction00
static int tolua_persistence_wyDatabase_beginDeferredTransaction00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyDatabase",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyDatabase* self = (wyDatabase*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'beginDeferredTransaction'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->beginDeferredTransaction();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'beginDeferredTransaction'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: beginTransaction of class  wyDatabase */
#ifndef TOLUA_DISABLE_tolua_persistence_wyDatabase_beginTransaction00
static int tolua_persistence_wyDatabase_beginTransaction00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyDatabase",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyDatabase* self = (wyDatabase*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'beginTransaction'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->beginTransaction();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'beginTransaction'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: tableExists of class  wyDatabase */
#ifndef TOLUA_DISABLE_tolua_persistence_wyDatabase_tableExists00
static int tolua_persistence_wyDatabase_tableExists00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyDatabase",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyDatabase* self = (wyDatabase*)  tolua_tousertype(tolua_S,1,0);
  const char* tableName = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'tableExists'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->tableExists(tableName);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'tableExists'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getSchema of class  wyDatabase */
#ifndef TOLUA_DISABLE_tolua_persistence_wyDatabase_getSchema00
static int tolua_persistence_wyDatabase_getSchema00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyDatabase",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyDatabase* self = (wyDatabase*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getSchema'", NULL);
#endif
  {
   wyResultSet* tolua_ret = (wyResultSet*)  self->getSchema();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyResultSet");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getSchema'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getTableSchema of class  wyDatabase */
#ifndef TOLUA_DISABLE_tolua_persistence_wyDatabase_getTableSchema00
static int tolua_persistence_wyDatabase_getTableSchema00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyDatabase",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyDatabase* self = (wyDatabase*)  tolua_tousertype(tolua_S,1,0);
  const char* tableName = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getTableSchema'", NULL);
#endif
  {
   wyResultSet* tolua_ret = (wyResultSet*)  self->getTableSchema(tableName);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyResultSet");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getTableSchema'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: columnExists of class  wyDatabase */
#ifndef TOLUA_DISABLE_tolua_persistence_wyDatabase_columnExists00
static int tolua_persistence_wyDatabase_columnExists00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyDatabase",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyDatabase* self = (wyDatabase*)  tolua_tousertype(tolua_S,1,0);
  const char* tableName = ((const char*)  tolua_tostring(tolua_S,2,0));
  const char* columnName = ((const char*)  tolua_tostring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'columnExists'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->columnExists(tableName,columnName);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'columnExists'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: executeSQL of class  wyDatabase */
#ifndef TOLUA_DISABLE_tolua_persistence_wyDatabase_executeSQL00
static int tolua_persistence_wyDatabase_executeSQL00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyDatabase",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyDatabase* self = (wyDatabase*)  tolua_tousertype(tolua_S,1,0);
  int resId = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'executeSQL'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->executeSQL(resId);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'executeSQL'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: executeSQL of class  wyDatabase */
#ifndef TOLUA_DISABLE_tolua_persistence_wyDatabase_executeSQL01
static int tolua_persistence_wyDatabase_executeSQL01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyDatabase",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,3,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  wyDatabase* self = (wyDatabase*)  tolua_tousertype(tolua_S,1,0);
  const char* path = ((const char*)  tolua_tostring(tolua_S,2,0));
  bool isFile = ((bool)  tolua_toboolean(tolua_S,3,false));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'executeSQL'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->executeSQL(path,isFile);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
tolua_lerror:
 return tolua_persistence_wyDatabase_executeSQL00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: executeSQL of class  wyDatabase */
#ifndef TOLUA_DISABLE_tolua_persistence_wyDatabase_executeSQL02
static int tolua_persistence_wyDatabase_executeSQL02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyDatabase",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"size_t",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  wyDatabase* self = (wyDatabase*)  tolua_tousertype(tolua_S,1,0);
  const char* data = ((const char*)  tolua_tostring(tolua_S,2,0));
  size_t length = *((size_t*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'executeSQL'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->executeSQL(data,length);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
tolua_lerror:
 return tolua_persistence_wyDatabase_executeSQL01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: getDatabasePath of class  wyDatabase */
#ifndef TOLUA_DISABLE_tolua_persistence_wyDatabase_getDatabasePath00
static int tolua_persistence_wyDatabase_getDatabasePath00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyDatabase",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyDatabase* self = (wyDatabase*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getDatabasePath'", NULL);
#endif
  {
   const char* tolua_ret = (const char*)  self->getDatabasePath();
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getDatabasePath'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getSqlite3Handle of class  wyDatabase */
#ifndef TOLUA_DISABLE_tolua_persistence_wyDatabase_getSqlite3Handle00
static int tolua_persistence_wyDatabase_getSqlite3Handle00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyDatabase",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyDatabase* self = (wyDatabase*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getSqlite3Handle'", NULL);
#endif
  {
   sqlite3* tolua_ret = (sqlite3*)  self->getSqlite3Handle();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"sqlite3");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getSqlite3Handle'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getBusyRetryTimeout of class  wyDatabase */
#ifndef TOLUA_DISABLE_tolua_persistence_wyDatabase_getBusyRetryTimeout00
static int tolua_persistence_wyDatabase_getBusyRetryTimeout00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyDatabase",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyDatabase* self = (wyDatabase*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getBusyRetryTimeout'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getBusyRetryTimeout();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getBusyRetryTimeout'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setBusyRetryTimeout of class  wyDatabase */
#ifndef TOLUA_DISABLE_tolua_persistence_wyDatabase_setBusyRetryTimeout00
static int tolua_persistence_wyDatabase_setBusyRetryTimeout00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyDatabase",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyDatabase* self = (wyDatabase*)  tolua_tousertype(tolua_S,1,0);
  int c = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setBusyRetryTimeout'", NULL);
#endif
  {
   self->setBusyRetryTimeout(c);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setBusyRetryTimeout'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isInTransaction of class  wyDatabase */
#ifndef TOLUA_DISABLE_tolua_persistence_wyDatabase_isInTransaction00
static int tolua_persistence_wyDatabase_isInTransaction00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyDatabase",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyDatabase* self = (wyDatabase*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isInTransaction'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isInTransaction();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isInTransaction'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  wyResultSet */
#ifndef TOLUA_DISABLE_tolua_persistence_wyResultSet_delete00
static int tolua_persistence_wyResultSet_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyResultSet",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyResultSet* self = (wyResultSet*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: next of class  wyResultSet */
#ifndef TOLUA_DISABLE_tolua_persistence_wyResultSet_next00
static int tolua_persistence_wyResultSet_next00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyResultSet",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyResultSet* self = (wyResultSet*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'next'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->next();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'next'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: hasAnotherRow of class  wyResultSet */
#ifndef TOLUA_DISABLE_tolua_persistence_wyResultSet_hasAnotherRow00
static int tolua_persistence_wyResultSet_hasAnotherRow00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyResultSet",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyResultSet* self = (wyResultSet*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'hasAnotherRow'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->hasAnotherRow();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'hasAnotherRow'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: columnCount of class  wyResultSet */
#ifndef TOLUA_DISABLE_tolua_persistence_wyResultSet_columnCount00
static int tolua_persistence_wyResultSet_columnCount00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyResultSet",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyResultSet* self = (wyResultSet*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'columnCount'", NULL);
#endif
  {
   int tolua_ret = (int)  self->columnCount();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'columnCount'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: columnIndexIsNull of class  wyResultSet */
#ifndef TOLUA_DISABLE_tolua_persistence_wyResultSet_columnIndexIsNull00
static int tolua_persistence_wyResultSet_columnIndexIsNull00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyResultSet",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyResultSet* self = (wyResultSet*)  tolua_tousertype(tolua_S,1,0);
  int columnIdx = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'columnIndexIsNull'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->columnIndexIsNull(columnIdx);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'columnIndexIsNull'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: columnIsNull of class  wyResultSet */
#ifndef TOLUA_DISABLE_tolua_persistence_wyResultSet_columnIsNull00
static int tolua_persistence_wyResultSet_columnIsNull00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyResultSet",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyResultSet* self = (wyResultSet*)  tolua_tousertype(tolua_S,1,0);
  const char* columnName = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'columnIsNull'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->columnIsNull(columnName);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'columnIsNull'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: columnIndexForName of class  wyResultSet */
#ifndef TOLUA_DISABLE_tolua_persistence_wyResultSet_columnIndexForName00
static int tolua_persistence_wyResultSet_columnIndexForName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyResultSet",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyResultSet* self = (wyResultSet*)  tolua_tousertype(tolua_S,1,0);
  const char* columnName = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'columnIndexForName'", NULL);
#endif
  {
   int tolua_ret = (int)  self->columnIndexForName(columnName);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'columnIndexForName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: columnNameForIndex of class  wyResultSet */
#ifndef TOLUA_DISABLE_tolua_persistence_wyResultSet_columnNameForIndex00
static int tolua_persistence_wyResultSet_columnNameForIndex00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyResultSet",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyResultSet* self = (wyResultSet*)  tolua_tousertype(tolua_S,1,0);
  int columnIdx = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'columnNameForIndex'", NULL);
#endif
  {
   const char* tolua_ret = (const char*)  self->columnNameForIndex(columnIdx);
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'columnNameForIndex'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: intForColumn of class  wyResultSet */
#ifndef TOLUA_DISABLE_tolua_persistence_wyResultSet_intForColumn00
static int tolua_persistence_wyResultSet_intForColumn00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyResultSet",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyResultSet* self = (wyResultSet*)  tolua_tousertype(tolua_S,1,0);
  const char* columnName = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'intForColumn'", NULL);
#endif
  {
   int tolua_ret = (int)  self->intForColumn(columnName);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'intForColumn'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: intForColumnIndex of class  wyResultSet */
#ifndef TOLUA_DISABLE_tolua_persistence_wyResultSet_intForColumnIndex00
static int tolua_persistence_wyResultSet_intForColumnIndex00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyResultSet",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyResultSet* self = (wyResultSet*)  tolua_tousertype(tolua_S,1,0);
  int columnIdx = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'intForColumnIndex'", NULL);
#endif
  {
   int tolua_ret = (int)  self->intForColumnIndex(columnIdx);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'intForColumnIndex'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: longForColumn of class  wyResultSet */
#ifndef TOLUA_DISABLE_tolua_persistence_wyResultSet_longForColumn00
static int tolua_persistence_wyResultSet_longForColumn00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyResultSet",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyResultSet* self = (wyResultSet*)  tolua_tousertype(tolua_S,1,0);
  const char* columnName = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'longForColumn'", NULL);
#endif
  {
   long tolua_ret = (long)  self->longForColumn(columnName);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'longForColumn'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: longForColumnIndex of class  wyResultSet */
#ifndef TOLUA_DISABLE_tolua_persistence_wyResultSet_longForColumnIndex00
static int tolua_persistence_wyResultSet_longForColumnIndex00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyResultSet",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyResultSet* self = (wyResultSet*)  tolua_tousertype(tolua_S,1,0);
  int columnIdx = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'longForColumnIndex'", NULL);
#endif
  {
   long tolua_ret = (long)  self->longForColumnIndex(columnIdx);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'longForColumnIndex'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: int64ForColumn of class  wyResultSet */
#ifndef TOLUA_DISABLE_tolua_persistence_wyResultSet_int64ForColumn00
static int tolua_persistence_wyResultSet_int64ForColumn00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyResultSet",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyResultSet* self = (wyResultSet*)  tolua_tousertype(tolua_S,1,0);
  const char* columnName = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'int64ForColumn'", NULL);
#endif
  {
   int64_t tolua_ret = (int64_t)  self->int64ForColumn(columnName);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((int64_t)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"int64_t");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(int64_t));
     tolua_pushusertype(tolua_S,tolua_obj,"int64_t");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'int64ForColumn'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: int64ForColumnIndex of class  wyResultSet */
#ifndef TOLUA_DISABLE_tolua_persistence_wyResultSet_int64ForColumnIndex00
static int tolua_persistence_wyResultSet_int64ForColumnIndex00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyResultSet",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyResultSet* self = (wyResultSet*)  tolua_tousertype(tolua_S,1,0);
  int columnIdx = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'int64ForColumnIndex'", NULL);
#endif
  {
   int64_t tolua_ret = (int64_t)  self->int64ForColumnIndex(columnIdx);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((int64_t)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"int64_t");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(int64_t));
     tolua_pushusertype(tolua_S,tolua_obj,"int64_t");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'int64ForColumnIndex'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: boolForColumn of class  wyResultSet */
#ifndef TOLUA_DISABLE_tolua_persistence_wyResultSet_boolForColumn00
static int tolua_persistence_wyResultSet_boolForColumn00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyResultSet",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyResultSet* self = (wyResultSet*)  tolua_tousertype(tolua_S,1,0);
  const char* columnName = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'boolForColumn'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->boolForColumn(columnName);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'boolForColumn'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: boolForColumnIndex of class  wyResultSet */
#ifndef TOLUA_DISABLE_tolua_persistence_wyResultSet_boolForColumnIndex00
static int tolua_persistence_wyResultSet_boolForColumnIndex00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyResultSet",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyResultSet* self = (wyResultSet*)  tolua_tousertype(tolua_S,1,0);
  int columnIdx = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'boolForColumnIndex'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->boolForColumnIndex(columnIdx);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'boolForColumnIndex'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: doubleForColumn of class  wyResultSet */
#ifndef TOLUA_DISABLE_tolua_persistence_wyResultSet_doubleForColumn00
static int tolua_persistence_wyResultSet_doubleForColumn00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyResultSet",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyResultSet* self = (wyResultSet*)  tolua_tousertype(tolua_S,1,0);
  const char* columnName = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'doubleForColumn'", NULL);
#endif
  {
   double tolua_ret = (double)  self->doubleForColumn(columnName);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'doubleForColumn'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: doubleForColumnIndex of class  wyResultSet */
#ifndef TOLUA_DISABLE_tolua_persistence_wyResultSet_doubleForColumnIndex00
static int tolua_persistence_wyResultSet_doubleForColumnIndex00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyResultSet",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyResultSet* self = (wyResultSet*)  tolua_tousertype(tolua_S,1,0);
  int columnIdx = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'doubleForColumnIndex'", NULL);
#endif
  {
   double tolua_ret = (double)  self->doubleForColumnIndex(columnIdx);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'doubleForColumnIndex'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: stringForColumn of class  wyResultSet */
#ifndef TOLUA_DISABLE_tolua_persistence_wyResultSet_stringForColumn00
static int tolua_persistence_wyResultSet_stringForColumn00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyResultSet",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyResultSet* self = (wyResultSet*)  tolua_tousertype(tolua_S,1,0);
  const char* columnName = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'stringForColumn'", NULL);
#endif
  {
   const char* tolua_ret = (const char*)  self->stringForColumn(columnName);
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'stringForColumn'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: stringForColumnIndex of class  wyResultSet */
#ifndef TOLUA_DISABLE_tolua_persistence_wyResultSet_stringForColumnIndex00
static int tolua_persistence_wyResultSet_stringForColumnIndex00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyResultSet",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyResultSet* self = (wyResultSet*)  tolua_tousertype(tolua_S,1,0);
  int columnIdx = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'stringForColumnIndex'", NULL);
#endif
  {
   const char* tolua_ret = (const char*)  self->stringForColumnIndex(columnIdx);
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'stringForColumnIndex'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: dataForColumn of class  wyResultSet */
#ifndef TOLUA_DISABLE_tolua_persistence_wyResultSet_dataForColumn00
static int tolua_persistence_wyResultSet_dataForColumn00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyResultSet",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"size_t",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyResultSet* self = (wyResultSet*)  tolua_tousertype(tolua_S,1,0);
  const char* columnName = ((const char*)  tolua_tostring(tolua_S,2,0));
  size_t* outLen = ((size_t*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'dataForColumn'", NULL);
#endif
  {
   const char* tolua_ret = (const char*)  self->dataForColumn(columnName,outLen);
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'dataForColumn'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: dataForColumnIndex of class  wyResultSet */
#ifndef TOLUA_DISABLE_tolua_persistence_wyResultSet_dataForColumnIndex00
static int tolua_persistence_wyResultSet_dataForColumnIndex00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyResultSet",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"size_t",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyResultSet* self = (wyResultSet*)  tolua_tousertype(tolua_S,1,0);
  int columnIdx = ((int)  tolua_tonumber(tolua_S,2,0));
  size_t* outLen = ((size_t*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'dataForColumnIndex'", NULL);
#endif
  {
   const char* tolua_ret = (const char*)  self->dataForColumnIndex(columnIdx,outLen);
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'dataForColumnIndex'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: dataNoCopyForColumn of class  wyResultSet */
#ifndef TOLUA_DISABLE_tolua_persistence_wyResultSet_dataNoCopyForColumn00
static int tolua_persistence_wyResultSet_dataNoCopyForColumn00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyResultSet",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"size_t",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyResultSet* self = (wyResultSet*)  tolua_tousertype(tolua_S,1,0);
  const char* columnName = ((const char*)  tolua_tostring(tolua_S,2,0));
  size_t* outLen = ((size_t*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'dataNoCopyForColumn'", NULL);
#endif
  {
   const char* tolua_ret = (const char*)  self->dataNoCopyForColumn(columnName,outLen);
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'dataNoCopyForColumn'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: dataNoCopyForColumnIndex of class  wyResultSet */
#ifndef TOLUA_DISABLE_tolua_persistence_wyResultSet_dataNoCopyForColumnIndex00
static int tolua_persistence_wyResultSet_dataNoCopyForColumnIndex00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyResultSet",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"size_t",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyResultSet* self = (wyResultSet*)  tolua_tousertype(tolua_S,1,0);
  int columnIdx = ((int)  tolua_tonumber(tolua_S,2,0));
  size_t* outLen = ((size_t*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'dataNoCopyForColumnIndex'", NULL);
#endif
  {
   const char* tolua_ret = (const char*)  self->dataNoCopyForColumnIndex(columnIdx,outLen);
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'dataNoCopyForColumnIndex'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getDatabase of class  wyResultSet */
#ifndef TOLUA_DISABLE_tolua_persistence_wyResultSet_getDatabase00
static int tolua_persistence_wyResultSet_getDatabase00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyResultSet",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyResultSet* self = (wyResultSet*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getDatabase'", NULL);
#endif
  {
   wyDatabase* tolua_ret = (wyDatabase*)  self->getDatabase();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyDatabase");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getDatabase'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getStatement of class  wyResultSet */
#ifndef TOLUA_DISABLE_tolua_persistence_wyResultSet_getStatement00
static int tolua_persistence_wyResultSet_getStatement00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyResultSet",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyResultSet* self = (wyResultSet*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getStatement'", NULL);
#endif
  {
   wyStatement* tolua_ret = (wyStatement*)  self->getStatement();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyStatement");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getStatement'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  wyStatement */
#ifndef TOLUA_DISABLE_tolua_persistence_wyStatement_delete00
static int tolua_persistence_wyStatement_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyStatement",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyStatement* self = (wyStatement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setQuery of class  wyStatement */
#ifndef TOLUA_DISABLE_tolua_persistence_wyStatement_setQuery00
static int tolua_persistence_wyStatement_setQuery00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyStatement",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyStatement* self = (wyStatement*)  tolua_tousertype(tolua_S,1,0);
  const char* q = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setQuery'", NULL);
#endif
  {
   self->setQuery(q);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setQuery'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getQuery of class  wyStatement */
#ifndef TOLUA_DISABLE_tolua_persistence_wyStatement_getQuery00
static int tolua_persistence_wyStatement_getQuery00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyStatement",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyStatement* self = (wyStatement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getQuery'", NULL);
#endif
  {
   const char* tolua_ret = (const char*)  self->getQuery();
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getQuery'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setStatement of class  wyStatement */
#ifndef TOLUA_DISABLE_tolua_persistence_wyStatement_setStatement00
static int tolua_persistence_wyStatement_setStatement00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyStatement",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"sqlite3_stmt",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyStatement* self = (wyStatement*)  tolua_tousertype(tolua_S,1,0);
  sqlite3_stmt* s = ((sqlite3_stmt*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setStatement'", NULL);
#endif
  {
   self->setStatement(s);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setStatement'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getStatement of class  wyStatement */
#ifndef TOLUA_DISABLE_tolua_persistence_wyStatement_getStatement00
static int tolua_persistence_wyStatement_getStatement00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyStatement",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyStatement* self = (wyStatement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getStatement'", NULL);
#endif
  {
   sqlite3_stmt* tolua_ret = (sqlite3_stmt*)  self->getStatement();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"sqlite3_stmt");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getStatement'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: close of class  wyStatement */
#ifndef TOLUA_DISABLE_tolua_persistence_wyStatement_close00
static int tolua_persistence_wyStatement_close00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyStatement",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyStatement* self = (wyStatement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'close'", NULL);
#endif
  {
   self->close();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'close'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: reset of class  wyStatement */
#ifndef TOLUA_DISABLE_tolua_persistence_wyStatement_reset00
static int tolua_persistence_wyStatement_reset00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyStatement",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyStatement* self = (wyStatement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'reset'", NULL);
#endif
  {
   self->reset();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'reset'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_persistence_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  tolua_cclass(tolua_S,"wyPrefs","wyPrefs","",NULL);
  tolua_beginmodule(tolua_S,"wyPrefs");
   tolua_function(tolua_S,"getInt",tolua_persistence_wyPrefs_getInt00);
   tolua_function(tolua_S,"setInt",tolua_persistence_wyPrefs_setInt00);
   tolua_function(tolua_S,"getBool",tolua_persistence_wyPrefs_getBool00);
   tolua_function(tolua_S,"setBool",tolua_persistence_wyPrefs_setBool00);
   tolua_function(tolua_S,"setInt64",tolua_persistence_wyPrefs_setInt6400);
   tolua_function(tolua_S,"getInt64",tolua_persistence_wyPrefs_getInt6400);
   tolua_function(tolua_S,"getString",tolua_persistence_wyPrefs_getString00);
   tolua_function(tolua_S,"setString",tolua_persistence_wyPrefs_setString00);
   tolua_function(tolua_S,"clear",tolua_persistence_wyPrefs_clear00);
   tolua_function(tolua_S,"remove",tolua_persistence_wyPrefs_remove00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyDatabase","wyDatabase","wyObject",tolua_collect_wyDatabase);
  #else
  tolua_cclass(tolua_S,"wyDatabase","wyDatabase","wyObject",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyDatabase");
   tolua_function(tolua_S,"delete",tolua_persistence_wyDatabase_delete00);
   tolua_function(tolua_S,"make",tolua_persistence_wyDatabase_make00);
   tolua_function(tolua_S,"isThreadSafe",tolua_persistence_wyDatabase_isThreadSafe00);
   tolua_function(tolua_S,"sqliteLibVersion",tolua_persistence_wyDatabase_sqliteLibVersion00);
   tolua_function(tolua_S,"sqliteHandle",tolua_persistence_wyDatabase_sqliteHandle00);
   tolua_function(tolua_S,"open",tolua_persistence_wyDatabase_open00);
   tolua_function(tolua_S,"close",tolua_persistence_wyDatabase_close00);
   tolua_function(tolua_S,"databaseExists",tolua_persistence_wyDatabase_databaseExists00);
   tolua_function(tolua_S,"goodConnection",tolua_persistence_wyDatabase_goodConnection00);
   tolua_function(tolua_S,"clearCachedStatements",tolua_persistence_wyDatabase_clearCachedStatements00);
   tolua_function(tolua_S,"clearResultSets",tolua_persistence_wyDatabase_clearResultSets00);
   tolua_function(tolua_S,"lastErrorMessage",tolua_persistence_wyDatabase_lastErrorMessage00);
   tolua_function(tolua_S,"lastErrorCode",tolua_persistence_wyDatabase_lastErrorCode00);
   tolua_function(tolua_S,"hadError",tolua_persistence_wyDatabase_hadError00);
   tolua_function(tolua_S,"lastInsertRowId",tolua_persistence_wyDatabase_lastInsertRowId00);
   tolua_function(tolua_S,"inUse",tolua_persistence_wyDatabase_inUse00);
   tolua_function(tolua_S,"setInUse",tolua_persistence_wyDatabase_setInUse00);
   tolua_function(tolua_S,"shouldCacheStatements",tolua_persistence_wyDatabase_shouldCacheStatements00);
   tolua_function(tolua_S,"setShouldCacheStatements",tolua_persistence_wyDatabase_setShouldCacheStatements00);
   tolua_function(tolua_S,"changes",tolua_persistence_wyDatabase_changes00);
   tolua_function(tolua_S,"rollback",tolua_persistence_wyDatabase_rollback00);
   tolua_function(tolua_S,"commit",tolua_persistence_wyDatabase_commit00);
   tolua_function(tolua_S,"beginDeferredTransaction",tolua_persistence_wyDatabase_beginDeferredTransaction00);
   tolua_function(tolua_S,"beginTransaction",tolua_persistence_wyDatabase_beginTransaction00);
   tolua_function(tolua_S,"tableExists",tolua_persistence_wyDatabase_tableExists00);
   tolua_function(tolua_S,"getSchema",tolua_persistence_wyDatabase_getSchema00);
   tolua_function(tolua_S,"getTableSchema",tolua_persistence_wyDatabase_getTableSchema00);
   tolua_function(tolua_S,"columnExists",tolua_persistence_wyDatabase_columnExists00);
   tolua_function(tolua_S,"executeSQL",tolua_persistence_wyDatabase_executeSQL00);
   tolua_function(tolua_S,"executeSQL",tolua_persistence_wyDatabase_executeSQL01);
   tolua_function(tolua_S,"executeSQL",tolua_persistence_wyDatabase_executeSQL02);
   tolua_function(tolua_S,"getDatabasePath",tolua_persistence_wyDatabase_getDatabasePath00);
   tolua_function(tolua_S,"getSqlite3Handle",tolua_persistence_wyDatabase_getSqlite3Handle00);
   tolua_function(tolua_S,"getBusyRetryTimeout",tolua_persistence_wyDatabase_getBusyRetryTimeout00);
   tolua_function(tolua_S,"setBusyRetryTimeout",tolua_persistence_wyDatabase_setBusyRetryTimeout00);
   tolua_function(tolua_S,"isInTransaction",tolua_persistence_wyDatabase_isInTransaction00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyResultSet","wyResultSet","wyObject",tolua_collect_wyResultSet);
  #else
  tolua_cclass(tolua_S,"wyResultSet","wyResultSet","wyObject",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyResultSet");
   tolua_function(tolua_S,"delete",tolua_persistence_wyResultSet_delete00);
   tolua_function(tolua_S,"next",tolua_persistence_wyResultSet_next00);
   tolua_function(tolua_S,"hasAnotherRow",tolua_persistence_wyResultSet_hasAnotherRow00);
   tolua_function(tolua_S,"columnCount",tolua_persistence_wyResultSet_columnCount00);
   tolua_function(tolua_S,"columnIndexIsNull",tolua_persistence_wyResultSet_columnIndexIsNull00);
   tolua_function(tolua_S,"columnIsNull",tolua_persistence_wyResultSet_columnIsNull00);
   tolua_function(tolua_S,"columnIndexForName",tolua_persistence_wyResultSet_columnIndexForName00);
   tolua_function(tolua_S,"columnNameForIndex",tolua_persistence_wyResultSet_columnNameForIndex00);
   tolua_function(tolua_S,"intForColumn",tolua_persistence_wyResultSet_intForColumn00);
   tolua_function(tolua_S,"intForColumnIndex",tolua_persistence_wyResultSet_intForColumnIndex00);
   tolua_function(tolua_S,"longForColumn",tolua_persistence_wyResultSet_longForColumn00);
   tolua_function(tolua_S,"longForColumnIndex",tolua_persistence_wyResultSet_longForColumnIndex00);
   tolua_function(tolua_S,"int64ForColumn",tolua_persistence_wyResultSet_int64ForColumn00);
   tolua_function(tolua_S,"int64ForColumnIndex",tolua_persistence_wyResultSet_int64ForColumnIndex00);
   tolua_function(tolua_S,"boolForColumn",tolua_persistence_wyResultSet_boolForColumn00);
   tolua_function(tolua_S,"boolForColumnIndex",tolua_persistence_wyResultSet_boolForColumnIndex00);
   tolua_function(tolua_S,"doubleForColumn",tolua_persistence_wyResultSet_doubleForColumn00);
   tolua_function(tolua_S,"doubleForColumnIndex",tolua_persistence_wyResultSet_doubleForColumnIndex00);
   tolua_function(tolua_S,"stringForColumn",tolua_persistence_wyResultSet_stringForColumn00);
   tolua_function(tolua_S,"stringForColumnIndex",tolua_persistence_wyResultSet_stringForColumnIndex00);
   tolua_function(tolua_S,"dataForColumn",tolua_persistence_wyResultSet_dataForColumn00);
   tolua_function(tolua_S,"dataForColumnIndex",tolua_persistence_wyResultSet_dataForColumnIndex00);
   tolua_function(tolua_S,"dataNoCopyForColumn",tolua_persistence_wyResultSet_dataNoCopyForColumn00);
   tolua_function(tolua_S,"dataNoCopyForColumnIndex",tolua_persistence_wyResultSet_dataNoCopyForColumnIndex00);
   tolua_function(tolua_S,"getDatabase",tolua_persistence_wyResultSet_getDatabase00);
   tolua_function(tolua_S,"getStatement",tolua_persistence_wyResultSet_getStatement00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyStatement","wyStatement","wyObject",tolua_collect_wyStatement);
  #else
  tolua_cclass(tolua_S,"wyStatement","wyStatement","wyObject",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyStatement");
   tolua_function(tolua_S,"delete",tolua_persistence_wyStatement_delete00);
   tolua_function(tolua_S,"setQuery",tolua_persistence_wyStatement_setQuery00);
   tolua_function(tolua_S,"getQuery",tolua_persistence_wyStatement_getQuery00);
   tolua_function(tolua_S,"setStatement",tolua_persistence_wyStatement_setStatement00);
   tolua_function(tolua_S,"getStatement",tolua_persistence_wyStatement_getStatement00);
   tolua_function(tolua_S,"close",tolua_persistence_wyStatement_close00);
   tolua_function(tolua_S,"reset",tolua_persistence_wyStatement_reset00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_persistence (lua_State* tolua_S) {
 return tolua_persistence_open(tolua_S);
};
#endif

