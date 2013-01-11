/*
** Lua binding: utils
** Generated automatically by tolua++-1.0.92 on Fri Jan 11 11:11:13 2013.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_utils_open (lua_State* tolua_S);

#include "WiEngine.h"

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_wyZwoptexManager (lua_State* tolua_S)
{
 wyZwoptexManager* self = (wyZwoptexManager*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyVerletStick (lua_State* tolua_S)
{
 wyVerletStick* self = (wyVerletStick*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wySize (lua_State* tolua_S)
{
 wySize* self = (wySize*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyAssetInputStream (lua_State* tolua_S)
{
 wyAssetInputStream* self = (wyAssetInputStream*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyTargetSelector (lua_State* tolua_S)
{
 wyTargetSelector* self = (wyTargetSelector*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyZwoptexFrame (lua_State* tolua_S)
{
 wyZwoptexFrame* self = (wyZwoptexFrame*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyZwoptex (lua_State* tolua_S)
{
 wyZwoptex* self = (wyZwoptex*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyVerletRope (lua_State* tolua_S)
{
 wyVerletRope* self = (wyVerletRope*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyPoint (lua_State* tolua_S)
{
 wyPoint* self = (wyPoint*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyRunnable (lua_State* tolua_S)
{
 wyRunnable* self = (wyRunnable*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyColor3B (lua_State* tolua_S)
{
 wyColor3B* self = (wyColor3B*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyVerletPoint (lua_State* tolua_S)
{
 wyVerletPoint* self = (wyVerletPoint*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyAssetOutputStream (lua_State* tolua_S)
{
 wyAssetOutputStream* self = (wyAssetOutputStream*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyRect (lua_State* tolua_S)
{
 wyRect* self = (wyRect*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyScroller (lua_State* tolua_S)
{
 wyScroller* self = (wyScroller*) tolua_tousertype(tolua_S,1,0);
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
 tolua_usertype(tolua_S,"wySprite");
 tolua_usertype(tolua_S,"wyTGALoader");
 tolua_usertype(tolua_S,"wySize");
 tolua_usertype(tolua_S,"wyMD5");
 tolua_usertype(tolua_S,"char32_t");
 tolua_usertype(tolua_S,"wyKeyEvent");
 tolua_usertype(tolua_S,"wySpriteFrame");
 tolua_usertype(tolua_S,"FILE");
 tolua_usertype(tolua_S,"wyVerletRope");
 tolua_usertype(tolua_S,"int64_t");
 tolua_usertype(tolua_S,"size_t");
 tolua_usertype(tolua_S,"wyAffineTransform");
 tolua_usertype(tolua_S,"wyAssetOutputStream");
 tolua_usertype(tolua_S,"wyScroller");
 tolua_usertype(tolua_S,"wyTargetSelector");
 tolua_usertype(tolua_S,"wyMath");
 tolua_usertype(tolua_S,"wyZwoptexFrame");
 tolua_usertype(tolua_S,"wyImagePickerCallback");
 tolua_usertype(tolua_S,"wyPoint");
 tolua_usertype(tolua_S,"wySpriteEx");
 tolua_usertype(tolua_S,"wyZwoptexManager");
 tolua_usertype(tolua_S,"wyZwoptex");
 tolua_usertype(tolua_S,"char16_t");
 tolua_usertype(tolua_S,"wyObject");
 tolua_usertype(tolua_S,"wyImagePicker");
 tolua_usertype(tolua_S,"wyVerletStick");
 tolua_usertype(tolua_S,"wyPVRHeader");
 tolua_usertype(tolua_S,"wyUtils");
 tolua_usertype(tolua_S,"wyMotionEvent");
 tolua_usertype(tolua_S,"wyAssetInputStream");
 tolua_usertype(tolua_S,"wyVerletPoint");
 tolua_usertype(tolua_S,"wyColor3B");
 tolua_usertype(tolua_S,"wyTexture2D");
 tolua_usertype(tolua_S,"wyArray");
 tolua_usertype(tolua_S,"wyQuad2D");
 tolua_usertype(tolua_S,"wyRect");
 tolua_usertype(tolua_S,"wyPVRFormat");
 tolua_usertype(tolua_S,"wyQuad3D");
 tolua_usertype(tolua_S,"wyColor4B");
 tolua_usertype(tolua_S,"wyTGA");
 tolua_usertype(tolua_S,"wyBezierConfig");
 tolua_usertype(tolua_S,"wyRunnable");
}

/* method: make of class  wyAssetOutputStream */
#ifndef TOLUA_DISABLE_tolua_utils_wyAssetOutputStream_make00
static int tolua_utils_wyAssetOutputStream_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyAssetOutputStream",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,3,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* path = ((const char*)  tolua_tostring(tolua_S,2,0));
  bool append = ((bool)  tolua_toboolean(tolua_S,3,false));
  {
   wyAssetOutputStream* tolua_ret = (wyAssetOutputStream*)  wyAssetOutputStream::make(path,append);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyAssetOutputStream");
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

/* method: delete of class  wyAssetOutputStream */
#ifndef TOLUA_DISABLE_tolua_utils_wyAssetOutputStream_delete00
static int tolua_utils_wyAssetOutputStream_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAssetOutputStream",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAssetOutputStream* self = (wyAssetOutputStream*)  tolua_tousertype(tolua_S,1,0);
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

/* method: open of class  wyAssetOutputStream */
#ifndef TOLUA_DISABLE_tolua_utils_wyAssetOutputStream_open00
static int tolua_utils_wyAssetOutputStream_open00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAssetOutputStream",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAssetOutputStream* self = (wyAssetOutputStream*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'open'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->open();
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

/* method: close of class  wyAssetOutputStream */
#ifndef TOLUA_DISABLE_tolua_utils_wyAssetOutputStream_close00
static int tolua_utils_wyAssetOutputStream_close00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAssetOutputStream",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAssetOutputStream* self = (wyAssetOutputStream*)  tolua_tousertype(tolua_S,1,0);
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

/* method: write of class  wyAssetOutputStream */
#ifndef TOLUA_DISABLE_tolua_utils_wyAssetOutputStream_write00
static int tolua_utils_wyAssetOutputStream_write00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAssetOutputStream",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"size_t",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAssetOutputStream* self = (wyAssetOutputStream*)  tolua_tousertype(tolua_S,1,0);
  const char* data = ((const char*)  tolua_tostring(tolua_S,2,0));
  size_t len = *((size_t*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'write'", NULL);
#endif
  {
   int tolua_ret = (int)  self->write(data,len);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'write'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: write of class  wyAssetOutputStream */
#ifndef TOLUA_DISABLE_tolua_utils_wyAssetOutputStream_write01
static int tolua_utils_wyAssetOutputStream_write01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAssetOutputStream",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"size_t",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  wyAssetOutputStream* self = (wyAssetOutputStream*)  tolua_tousertype(tolua_S,1,0);
  const int data = ((const int)  tolua_tonumber(tolua_S,2,0));
  size_t len = *((size_t*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'write'", NULL);
#endif
  {
   int tolua_ret = (int)  self->write(&data,len);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
   tolua_pushnumber(tolua_S,(lua_Number)data);
  }
 }
 return 2;
tolua_lerror:
 return tolua_utils_wyAssetOutputStream_write00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: getPosition of class  wyAssetOutputStream */
#ifndef TOLUA_DISABLE_tolua_utils_wyAssetOutputStream_getPosition00
static int tolua_utils_wyAssetOutputStream_getPosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAssetOutputStream",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAssetOutputStream* self = (wyAssetOutputStream*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getPosition'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getPosition();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getPosition'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: seek of class  wyAssetOutputStream */
#ifndef TOLUA_DISABLE_tolua_utils_wyAssetOutputStream_seek00
static int tolua_utils_wyAssetOutputStream_seek00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAssetOutputStream",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAssetOutputStream* self = (wyAssetOutputStream*)  tolua_tousertype(tolua_S,1,0);
  int offset = ((int)  tolua_tonumber(tolua_S,2,0));
  int mode = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'seek'", NULL);
#endif
  {
   int tolua_ret = (int)  self->seek(offset,mode);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'seek'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: make of class  wyAssetInputStream */
#ifndef TOLUA_DISABLE_tolua_utils_wyAssetInputStream_make00
static int tolua_utils_wyAssetInputStream_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyAssetInputStream",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  int resId = ((int)  tolua_tonumber(tolua_S,2,0));
  {
   wyAssetInputStream* tolua_ret = (wyAssetInputStream*)  wyAssetInputStream::make(resId);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyAssetInputStream");
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

/* method: make of class  wyAssetInputStream */
#ifndef TOLUA_DISABLE_tolua_utils_wyAssetInputStream_make01
static int tolua_utils_wyAssetInputStream_make01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyAssetInputStream",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,3,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const char* path = ((const char*)  tolua_tostring(tolua_S,2,0));
  bool isFile = ((bool)  tolua_toboolean(tolua_S,3,false));
  {
   wyAssetInputStream* tolua_ret = (wyAssetInputStream*)  wyAssetInputStream::make(path,isFile);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyAssetInputStream");
  }
 }
 return 1;
tolua_lerror:
 return tolua_utils_wyAssetInputStream_make00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  wyAssetInputStream */
#ifndef TOLUA_DISABLE_tolua_utils_wyAssetInputStream_delete00
static int tolua_utils_wyAssetInputStream_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAssetInputStream",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAssetInputStream* self = (wyAssetInputStream*)  tolua_tousertype(tolua_S,1,0);
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

/* method: getBuffer of class  wyAssetInputStream */
#ifndef TOLUA_DISABLE_tolua_utils_wyAssetInputStream_getBuffer00
static int tolua_utils_wyAssetInputStream_getBuffer00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAssetInputStream",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAssetInputStream* self = (wyAssetInputStream*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getBuffer'", NULL);
#endif
  {
   char* tolua_ret = (char*)  self->getBuffer();
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getBuffer'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getPosition of class  wyAssetInputStream */
#ifndef TOLUA_DISABLE_tolua_utils_wyAssetInputStream_getPosition00
static int tolua_utils_wyAssetInputStream_getPosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAssetInputStream",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAssetInputStream* self = (wyAssetInputStream*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getPosition'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getPosition();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getPosition'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getLength of class  wyAssetInputStream */
#ifndef TOLUA_DISABLE_tolua_utils_wyAssetInputStream_getLength00
static int tolua_utils_wyAssetInputStream_getLength00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAssetInputStream",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAssetInputStream* self = (wyAssetInputStream*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getLength'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getLength();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getLength'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: available of class  wyAssetInputStream */
#ifndef TOLUA_DISABLE_tolua_utils_wyAssetInputStream_available00
static int tolua_utils_wyAssetInputStream_available00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAssetInputStream",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAssetInputStream* self = (wyAssetInputStream*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'available'", NULL);
#endif
  {
   int tolua_ret = (int)  self->available();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'available'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: open of class  wyAssetInputStream */
#ifndef TOLUA_DISABLE_tolua_utils_wyAssetInputStream_open00
static int tolua_utils_wyAssetInputStream_open00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAssetInputStream",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAssetInputStream* self = (wyAssetInputStream*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'open'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->open();
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

/* method: close of class  wyAssetInputStream */
#ifndef TOLUA_DISABLE_tolua_utils_wyAssetInputStream_close00
static int tolua_utils_wyAssetInputStream_close00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAssetInputStream",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAssetInputStream* self = (wyAssetInputStream*)  tolua_tousertype(tolua_S,1,0);
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

/* method: read of class  wyAssetInputStream */
#ifndef TOLUA_DISABLE_tolua_utils_wyAssetInputStream_read00
static int tolua_utils_wyAssetInputStream_read00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAssetInputStream",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"size_t",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAssetInputStream* self = (wyAssetInputStream*)  tolua_tousertype(tolua_S,1,0);
  char* buffer = ((char*)  tolua_tostring(tolua_S,2,0));
  size_t length = *((size_t*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'read'", NULL);
#endif
  {
   int tolua_ret = (int)  self->read(buffer,length);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'read'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: readByte of class  wyAssetInputStream */
#ifndef TOLUA_DISABLE_tolua_utils_wyAssetInputStream_readByte00
static int tolua_utils_wyAssetInputStream_readByte00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAssetInputStream",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAssetInputStream* self = (wyAssetInputStream*)  tolua_tousertype(tolua_S,1,0);
  char* ret = ((char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'readByte'", NULL);
#endif
  {
   int tolua_ret = (int)  self->readByte(ret);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'readByte'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: readShort of class  wyAssetInputStream */
#ifndef TOLUA_DISABLE_tolua_utils_wyAssetInputStream_readShort00
static int tolua_utils_wyAssetInputStream_readShort00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAssetInputStream",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAssetInputStream* self = (wyAssetInputStream*)  tolua_tousertype(tolua_S,1,0);
  short ret = ((short)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'readShort'", NULL);
#endif
  {
   int tolua_ret = (int)  self->readShort(&ret);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
   tolua_pushnumber(tolua_S,(lua_Number)ret);
  }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'readShort'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: readInt of class  wyAssetInputStream */
#ifndef TOLUA_DISABLE_tolua_utils_wyAssetInputStream_readInt00
static int tolua_utils_wyAssetInputStream_readInt00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAssetInputStream",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAssetInputStream* self = (wyAssetInputStream*)  tolua_tousertype(tolua_S,1,0);
  int ret = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'readInt'", NULL);
#endif
  {
   int tolua_ret = (int)  self->readInt(&ret);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
   tolua_pushnumber(tolua_S,(lua_Number)ret);
  }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'readInt'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: readInt64 of class  wyAssetInputStream */
#ifndef TOLUA_DISABLE_tolua_utils_wyAssetInputStream_readInt6400
static int tolua_utils_wyAssetInputStream_readInt6400(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAssetInputStream",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"int64_t",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAssetInputStream* self = (wyAssetInputStream*)  tolua_tousertype(tolua_S,1,0);
  int64_t* ret = ((int64_t*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'readInt64'", NULL);
#endif
  {
   int64_t tolua_ret = (int64_t)  self->readInt64(ret);
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
 tolua_error(tolua_S,"#ferror in function 'readInt64'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: seek of class  wyAssetInputStream */
#ifndef TOLUA_DISABLE_tolua_utils_wyAssetInputStream_seek00
static int tolua_utils_wyAssetInputStream_seek00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAssetInputStream",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAssetInputStream* self = (wyAssetInputStream*)  tolua_tousertype(tolua_S,1,0);
  int offset = ((int)  tolua_tonumber(tolua_S,2,0));
  int mode = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'seek'", NULL);
#endif
  {
   int tolua_ret = (int)  self->seek(offset,mode);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'seek'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setBigEndian of class  wyAssetInputStream */
#ifndef TOLUA_DISABLE_tolua_utils_wyAssetInputStream_setBigEndian00
static int tolua_utils_wyAssetInputStream_setBigEndian00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAssetInputStream",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAssetInputStream* self = (wyAssetInputStream*)  tolua_tousertype(tolua_S,1,0);
  bool big = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setBigEndian'", NULL);
#endif
  {
   self->setBigEndian(big);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setBigEndian'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isBigEndian of class  wyAssetInputStream */
#ifndef TOLUA_DISABLE_tolua_utils_wyAssetInputStream_isBigEndian00
static int tolua_utils_wyAssetInputStream_isBigEndian00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAssetInputStream",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAssetInputStream* self = (wyAssetInputStream*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isBigEndian'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isBigEndian();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isBigEndian'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: md5 of class  wyMD5 */
#ifndef TOLUA_DISABLE_tolua_utils_wyMD5_md500
static int tolua_utils_wyMD5_md500(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyMD5",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* s = ((const char*)  tolua_tostring(tolua_S,2,0));
  {
   const char* tolua_ret = (const char*)  wyMD5::md5(s);
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'md5'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: md5 of class  wyMD5 */
#ifndef TOLUA_DISABLE_tolua_utils_wyMD5_md501
static int tolua_utils_wyMD5_md501(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyMD5",0,&tolua_err) ||
     !tolua_isuserdata(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"size_t",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const void* data = ((const void*)  tolua_touserdata(tolua_S,2,0));
  size_t len = *((size_t*)  tolua_tousertype(tolua_S,3,0));
  {
   const char* tolua_ret = (const char*)  wyMD5::md5(data,len);
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
tolua_lerror:
 return tolua_utils_wyMD5_md500(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* function: wyRecordTime */
#ifndef TOLUA_DISABLE_tolua_utils_wyRecordTime00
static int tolua_utils_wyRecordTime00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isstring(tolua_S,1,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* name = ((const char*)  tolua_tostring(tolua_S,1,0));
  {
   wyRecordTime(name);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'wyRecordTime'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: wyOutputTime */
#ifndef TOLUA_DISABLE_tolua_utils_wyOutputTime00
static int tolua_utils_wyOutputTime00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   wyOutputTime();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'wyOutputTime'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  wyRunnable */
#ifndef TOLUA_DISABLE_tolua_utils_wyRunnable_delete00
static int tolua_utils_wyRunnable_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyRunnable",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyRunnable* self = (wyRunnable*)  tolua_tousertype(tolua_S,1,0);
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

/* method: run of class  wyRunnable */
#ifndef TOLUA_DISABLE_tolua_utils_wyRunnable_run00
static int tolua_utils_wyRunnable_run00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyRunnable",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyRunnable* self = (wyRunnable*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'run'", NULL);
#endif
  {
   self->run();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'run'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: make of class  wyScroller */
#ifndef TOLUA_DISABLE_tolua_utils_wyScroller_make00
static int tolua_utils_wyScroller_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyScroller",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   wyScroller* tolua_ret = (wyScroller*)  wyScroller::make();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyScroller");
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

/* method: new of class  wyScroller */
#ifndef TOLUA_DISABLE_tolua_utils_wyScroller_new00
static int tolua_utils_wyScroller_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyScroller",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   wyScroller* tolua_ret = (wyScroller*)  Mtolua_new((wyScroller)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyScroller");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  wyScroller */
#ifndef TOLUA_DISABLE_tolua_utils_wyScroller_new00_local
static int tolua_utils_wyScroller_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyScroller",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   wyScroller* tolua_ret = (wyScroller*)  Mtolua_new((wyScroller)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyScroller");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  wyScroller */
#ifndef TOLUA_DISABLE_tolua_utils_wyScroller_delete00
static int tolua_utils_wyScroller_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyScroller",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyScroller* self = (wyScroller*)  tolua_tousertype(tolua_S,1,0);
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

/* method: isFinished of class  wyScroller */
#ifndef TOLUA_DISABLE_tolua_utils_wyScroller_isFinished00
static int tolua_utils_wyScroller_isFinished00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const wyScroller",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const wyScroller* self = (const wyScroller*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isFinished'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isFinished();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isFinished'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: forceFinished of class  wyScroller */
#ifndef TOLUA_DISABLE_tolua_utils_wyScroller_forceFinished00
static int tolua_utils_wyScroller_forceFinished00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyScroller",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyScroller* self = (wyScroller*)  tolua_tousertype(tolua_S,1,0);
  bool finished = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'forceFinished'", NULL);
#endif
  {
   self->forceFinished(finished);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'forceFinished'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getDuration of class  wyScroller */
#ifndef TOLUA_DISABLE_tolua_utils_wyScroller_getDuration00
static int tolua_utils_wyScroller_getDuration00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const wyScroller",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const wyScroller* self = (const wyScroller*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getDuration'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getDuration();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getDuration'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getCurrX of class  wyScroller */
#ifndef TOLUA_DISABLE_tolua_utils_wyScroller_getCurrX00
static int tolua_utils_wyScroller_getCurrX00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const wyScroller",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const wyScroller* self = (const wyScroller*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getCurrX'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getCurrX();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getCurrX'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getCurrY of class  wyScroller */
#ifndef TOLUA_DISABLE_tolua_utils_wyScroller_getCurrY00
static int tolua_utils_wyScroller_getCurrY00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const wyScroller",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const wyScroller* self = (const wyScroller*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getCurrY'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getCurrY();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getCurrY'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getCurrVelocity of class  wyScroller */
#ifndef TOLUA_DISABLE_tolua_utils_wyScroller_getCurrVelocity00
static int tolua_utils_wyScroller_getCurrVelocity00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const wyScroller",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const wyScroller* self = (const wyScroller*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getCurrVelocity'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getCurrVelocity();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getCurrVelocity'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getStartX of class  wyScroller */
#ifndef TOLUA_DISABLE_tolua_utils_wyScroller_getStartX00
static int tolua_utils_wyScroller_getStartX00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const wyScroller",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const wyScroller* self = (const wyScroller*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getStartX'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getStartX();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getStartX'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getStartY of class  wyScroller */
#ifndef TOLUA_DISABLE_tolua_utils_wyScroller_getStartY00
static int tolua_utils_wyScroller_getStartY00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const wyScroller",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const wyScroller* self = (const wyScroller*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getStartY'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getStartY();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getStartY'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getFinalX of class  wyScroller */
#ifndef TOLUA_DISABLE_tolua_utils_wyScroller_getFinalX00
static int tolua_utils_wyScroller_getFinalX00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const wyScroller",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const wyScroller* self = (const wyScroller*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getFinalX'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getFinalX();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getFinalX'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getFinalY of class  wyScroller */
#ifndef TOLUA_DISABLE_tolua_utils_wyScroller_getFinalY00
static int tolua_utils_wyScroller_getFinalY00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const wyScroller",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const wyScroller* self = (const wyScroller*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getFinalY'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getFinalY();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getFinalY'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: computeScrollOffset of class  wyScroller */
#ifndef TOLUA_DISABLE_tolua_utils_wyScroller_computeScrollOffset00
static int tolua_utils_wyScroller_computeScrollOffset00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyScroller",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyScroller* self = (wyScroller*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'computeScrollOffset'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->computeScrollOffset();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'computeScrollOffset'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: startScroll of class  wyScroller */
#ifndef TOLUA_DISABLE_tolua_utils_wyScroller_startScroll00
static int tolua_utils_wyScroller_startScroll00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyScroller",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyScroller* self = (wyScroller*)  tolua_tousertype(tolua_S,1,0);
  float startX = ((float)  tolua_tonumber(tolua_S,2,0));
  float startY = ((float)  tolua_tonumber(tolua_S,3,0));
  float dx = ((float)  tolua_tonumber(tolua_S,4,0));
  float dy = ((float)  tolua_tonumber(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'startScroll'", NULL);
#endif
  {
   self->startScroll(startX,startY,dx,dy);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'startScroll'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: startScroll of class  wyScroller */
#ifndef TOLUA_DISABLE_tolua_utils_wyScroller_startScroll01
static int tolua_utils_wyScroller_startScroll01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyScroller",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  wyScroller* self = (wyScroller*)  tolua_tousertype(tolua_S,1,0);
  float startX = ((float)  tolua_tonumber(tolua_S,2,0));
  float startY = ((float)  tolua_tonumber(tolua_S,3,0));
  float dx = ((float)  tolua_tonumber(tolua_S,4,0));
  float dy = ((float)  tolua_tonumber(tolua_S,5,0));
  int duration = ((int)  tolua_tonumber(tolua_S,6,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'startScroll'", NULL);
#endif
  {
   self->startScroll(startX,startY,dx,dy,duration);
  }
 }
 return 0;
tolua_lerror:
 return tolua_utils_wyScroller_startScroll00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: fling of class  wyScroller */
#ifndef TOLUA_DISABLE_tolua_utils_wyScroller_fling00
static int tolua_utils_wyScroller_fling00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyScroller",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,7,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,8,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,9,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,10,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyScroller* self = (wyScroller*)  tolua_tousertype(tolua_S,1,0);
  float startX = ((float)  tolua_tonumber(tolua_S,2,0));
  float startY = ((float)  tolua_tonumber(tolua_S,3,0));
  float velocityX = ((float)  tolua_tonumber(tolua_S,4,0));
  float velocityY = ((float)  tolua_tonumber(tolua_S,5,0));
  float minX = ((float)  tolua_tonumber(tolua_S,6,0));
  float maxX = ((float)  tolua_tonumber(tolua_S,7,0));
  float minY = ((float)  tolua_tonumber(tolua_S,8,0));
  float maxY = ((float)  tolua_tonumber(tolua_S,9,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'fling'", NULL);
#endif
  {
   self->fling(startX,startY,velocityX,velocityY,minX,maxX,minY,maxY);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'fling'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: abortAnimation of class  wyScroller */
#ifndef TOLUA_DISABLE_tolua_utils_wyScroller_abortAnimation00
static int tolua_utils_wyScroller_abortAnimation00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyScroller",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyScroller* self = (wyScroller*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'abortAnimation'", NULL);
#endif
  {
   self->abortAnimation();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'abortAnimation'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: extendDuration of class  wyScroller */
#ifndef TOLUA_DISABLE_tolua_utils_wyScroller_extendDuration00
static int tolua_utils_wyScroller_extendDuration00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyScroller",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyScroller* self = (wyScroller*)  tolua_tousertype(tolua_S,1,0);
  int extend = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'extendDuration'", NULL);
#endif
  {
   self->extendDuration(extend);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'extendDuration'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: timePassed of class  wyScroller */
#ifndef TOLUA_DISABLE_tolua_utils_wyScroller_timePassed00
static int tolua_utils_wyScroller_timePassed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const wyScroller",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const wyScroller* self = (const wyScroller*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'timePassed'", NULL);
#endif
  {
   int tolua_ret = (int)  self->timePassed();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'timePassed'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setFinalX of class  wyScroller */
#ifndef TOLUA_DISABLE_tolua_utils_wyScroller_setFinalX00
static int tolua_utils_wyScroller_setFinalX00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyScroller",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyScroller* self = (wyScroller*)  tolua_tousertype(tolua_S,1,0);
  float newX = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setFinalX'", NULL);
#endif
  {
   self->setFinalX(newX);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setFinalX'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setFinalY of class  wyScroller */
#ifndef TOLUA_DISABLE_tolua_utils_wyScroller_setFinalY00
static int tolua_utils_wyScroller_setFinalY00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyScroller",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyScroller* self = (wyScroller*)  tolua_tousertype(tolua_S,1,0);
  float newY = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setFinalY'", NULL);
#endif
  {
   self->setFinalY(newY);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setFinalY'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setScrollFriction of class  wyScroller */
#ifndef TOLUA_DISABLE_tolua_utils_wyScroller_setScrollFriction00
static int tolua_utils_wyScroller_setScrollFriction00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyScroller",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyScroller* self = (wyScroller*)  tolua_tousertype(tolua_S,1,0);
  float friction = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setScrollFriction'", NULL);
#endif
  {
   self->setScrollFriction(friction);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setScrollFriction'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: makeId of class  wyTargetSelector */
#ifndef TOLUA_DISABLE_tolua_utils_wyTargetSelector_make_v00
static int tolua_utils_wyTargetSelector_make_v00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyTargetSelector",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyObject",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyObject* callback = ((wyObject*)  tolua_tousertype(tolua_S,2,0));
  int id = ((int)  tolua_tonumber(tolua_S,3,0));
  {
   wyTargetSelector* tolua_ret = (wyTargetSelector*)  wyTargetSelector::makeId(callback,id);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyTargetSelector");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'make_v'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: makeId of class  wyTargetSelector */
#ifndef TOLUA_DISABLE_tolua_utils_wyTargetSelector_make_i00
static int tolua_utils_wyTargetSelector_make_i00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyTargetSelector",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyObject",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyObject* callback = ((wyObject*)  tolua_tousertype(tolua_S,2,0));
  int id = ((int)  tolua_tonumber(tolua_S,3,0));
  int data = ((int)  tolua_tonumber(tolua_S,4,0));
  {
   wyTargetSelector* tolua_ret = (wyTargetSelector*)  wyTargetSelector::makeId(callback,id,data);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyTargetSelector");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'make_i'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: makeId of class  wyTargetSelector */
#ifndef TOLUA_DISABLE_tolua_utils_wyTargetSelector_make_f00
static int tolua_utils_wyTargetSelector_make_f00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyTargetSelector",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyObject",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyObject* callback = ((wyObject*)  tolua_tousertype(tolua_S,2,0));
  int id = ((int)  tolua_tonumber(tolua_S,3,0));
  float data = ((float)  tolua_tonumber(tolua_S,4,0));
  {
   wyTargetSelector* tolua_ret = (wyTargetSelector*)  wyTargetSelector::makeId(callback,id,data);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyTargetSelector");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'make_f'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: makeId of class  wyTargetSelector */
#ifndef TOLUA_DISABLE_tolua_utils_wyTargetSelector_make_p00
static int tolua_utils_wyTargetSelector_make_p00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyTargetSelector",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyObject",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isuserdata(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyObject* callback = ((wyObject*)  tolua_tousertype(tolua_S,2,0));
  int id = ((int)  tolua_tonumber(tolua_S,3,0));
  void* data = ((void*)  tolua_touserdata(tolua_S,4,0));
  {
   wyTargetSelector* tolua_ret = (wyTargetSelector*)  wyTargetSelector::makeId(callback,id,data);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyTargetSelector");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'make_p'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  wyTargetSelector */
#ifndef TOLUA_DISABLE_tolua_utils_wyTargetSelector_delete00
static int tolua_utils_wyTargetSelector_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTargetSelector",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTargetSelector* self = (wyTargetSelector*)  tolua_tousertype(tolua_S,1,0);
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

/* method: setDelta of class  wyTargetSelector */
#ifndef TOLUA_DISABLE_tolua_utils_wyTargetSelector_setDelta00
static int tolua_utils_wyTargetSelector_setDelta00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTargetSelector",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTargetSelector* self = (wyTargetSelector*)  tolua_tousertype(tolua_S,1,0);
  float delta = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setDelta'", NULL);
#endif
  {
   self->setDelta(delta);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setDelta'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: invoke of class  wyTargetSelector */
#ifndef TOLUA_DISABLE_tolua_utils_wyTargetSelector_invoke00
static int tolua_utils_wyTargetSelector_invoke00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTargetSelector",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTargetSelector* self = (wyTargetSelector*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'invoke'", NULL);
#endif
  {
   self->invoke();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'invoke'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getTarget of class  wyTargetSelector */
#ifndef TOLUA_DISABLE_tolua_utils_wyTargetSelector_getTarget00
static int tolua_utils_wyTargetSelector_getTarget00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTargetSelector",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTargetSelector* self = (wyTargetSelector*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getTarget'", NULL);
#endif
  {
   wyObject* tolua_ret = (wyObject*)  self->getTarget();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyObject");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getTarget'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getId of class  wyTargetSelector */
#ifndef TOLUA_DISABLE_tolua_utils_wyTargetSelector_getId00
static int tolua_utils_wyTargetSelector_getId00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTargetSelector",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTargetSelector* self = (wyTargetSelector*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getId'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getId();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getId'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setId of class  wyTargetSelector */
#ifndef TOLUA_DISABLE_tolua_utils_wyTargetSelector_setId00
static int tolua_utils_wyTargetSelector_setId00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTargetSelector",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTargetSelector* self = (wyTargetSelector*)  tolua_tousertype(tolua_S,1,0);
  int id = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setId'", NULL);
#endif
  {
   self->setId(id);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setId'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getDelta of class  wyTargetSelector */
#ifndef TOLUA_DISABLE_tolua_utils_wyTargetSelector_getDelta00
static int tolua_utils_wyTargetSelector_getDelta00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTargetSelector",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTargetSelector* self = (wyTargetSelector*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getDelta'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getDelta();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getDelta'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: wyTargetSelectorEquals */
#ifndef TOLUA_DISABLE_tolua_utils_wyTargetSelectorEquals00
static int tolua_utils_wyTargetSelectorEquals00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTargetSelector",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyTargetSelector",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTargetSelector* ts1 = ((wyTargetSelector*)  tolua_tousertype(tolua_S,1,0));
  wyTargetSelector* ts2 = ((wyTargetSelector*)  tolua_tousertype(tolua_S,2,0));
  {
   bool tolua_ret = (bool)  wyTargetSelectorEquals(ts1,ts2);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'wyTargetSelectorEquals'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: status of class  wyTGA */
#ifndef TOLUA_DISABLE_tolua_get_wyTGA_status
static int tolua_get_wyTGA_status(lua_State* tolua_S)
{
  wyTGA* self = (wyTGA*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'status'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->status);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: status of class  wyTGA */
#ifndef TOLUA_DISABLE_tolua_set_wyTGA_status
static int tolua_set_wyTGA_status(lua_State* tolua_S)
{
  wyTGA* self = (wyTGA*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'status'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->status = ((wyTGAError) (int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: type of class  wyTGA */
#ifndef TOLUA_DISABLE_tolua_get_wyTGA_type
static int tolua_get_wyTGA_type(lua_State* tolua_S)
{
  wyTGA* self = (wyTGA*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'type'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->type);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: type of class  wyTGA */
#ifndef TOLUA_DISABLE_tolua_set_wyTGA_type
static int tolua_set_wyTGA_type(lua_State* tolua_S)
{
  wyTGA* self = (wyTGA*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'type'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->type = ((char)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: pixelDepth of class  wyTGA */
#ifndef TOLUA_DISABLE_tolua_get_wyTGA_pixelDepth
static int tolua_get_wyTGA_pixelDepth(lua_State* tolua_S)
{
  wyTGA* self = (wyTGA*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'pixelDepth'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->pixelDepth);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: pixelDepth of class  wyTGA */
#ifndef TOLUA_DISABLE_tolua_set_wyTGA_pixelDepth
static int tolua_set_wyTGA_pixelDepth(lua_State* tolua_S)
{
  wyTGA* self = (wyTGA*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'pixelDepth'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->pixelDepth = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: bytesPerPixel of class  wyTGA */
#ifndef TOLUA_DISABLE_tolua_get_wyTGA_bytesPerPixel
static int tolua_get_wyTGA_bytesPerPixel(lua_State* tolua_S)
{
  wyTGA* self = (wyTGA*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'bytesPerPixel'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->bytesPerPixel);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: bytesPerPixel of class  wyTGA */
#ifndef TOLUA_DISABLE_tolua_set_wyTGA_bytesPerPixel
static int tolua_set_wyTGA_bytesPerPixel(lua_State* tolua_S)
{
  wyTGA* self = (wyTGA*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'bytesPerPixel'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->bytesPerPixel = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: width of class  wyTGA */
#ifndef TOLUA_DISABLE_tolua_get_wyTGA_width
static int tolua_get_wyTGA_width(lua_State* tolua_S)
{
  wyTGA* self = (wyTGA*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'width'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->width);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: width of class  wyTGA */
#ifndef TOLUA_DISABLE_tolua_set_wyTGA_width
static int tolua_set_wyTGA_width(lua_State* tolua_S)
{
  wyTGA* self = (wyTGA*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'width'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->width = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: height of class  wyTGA */
#ifndef TOLUA_DISABLE_tolua_get_wyTGA_height
static int tolua_get_wyTGA_height(lua_State* tolua_S)
{
  wyTGA* self = (wyTGA*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'height'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->height);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: height of class  wyTGA */
#ifndef TOLUA_DISABLE_tolua_set_wyTGA_height
static int tolua_set_wyTGA_height(lua_State* tolua_S)
{
  wyTGA* self = (wyTGA*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'height'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->height = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: imageData of class  wyTGA */
#ifndef TOLUA_DISABLE_tolua_get_wyTGA_imageData
static int tolua_get_wyTGA_imageData(lua_State* tolua_S)
{
  wyTGA* self = (wyTGA*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'imageData'",NULL);
#endif
  tolua_pushstring(tolua_S,(const char*)self->imageData);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: imageData of class  wyTGA */
#ifndef TOLUA_DISABLE_tolua_set_wyTGA_imageData
static int tolua_set_wyTGA_imageData(lua_State* tolua_S)
{
  wyTGA* self = (wyTGA*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'imageData'",NULL);
  if (!tolua_isstring(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->imageData = ((char*)  tolua_tostring(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: flipped of class  wyTGA */
#ifndef TOLUA_DISABLE_tolua_get_wyTGA_flipped
static int tolua_get_wyTGA_flipped(lua_State* tolua_S)
{
  wyTGA* self = (wyTGA*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'flipped'",NULL);
#endif
  tolua_pushboolean(tolua_S,(bool)self->flipped);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: flipped of class  wyTGA */
#ifndef TOLUA_DISABLE_tolua_set_wyTGA_flipped
static int tolua_set_wyTGA_flipped(lua_State* tolua_S)
{
  wyTGA* self = (wyTGA*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'flipped'",NULL);
  if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->flipped = ((bool)  tolua_toboolean(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: load of class  wyTGALoader */
#ifndef TOLUA_DISABLE_tolua_utils_wyTGALoader_load00
static int tolua_utils_wyTGALoader_load00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyTGALoader",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  int resId = ((int)  tolua_tonumber(tolua_S,2,0));
  {
   wyTGA* tolua_ret = (wyTGA*)  wyTGALoader::load(resId);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyTGA");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'load'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: load of class  wyTGALoader */
#ifndef TOLUA_DISABLE_tolua_utils_wyTGALoader_load01
static int tolua_utils_wyTGALoader_load01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyTGALoader",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,3,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const char* path = ((const char*)  tolua_tostring(tolua_S,2,0));
  bool isFile = ((bool)  tolua_toboolean(tolua_S,3,false));
  {
   wyTGA* tolua_ret = (wyTGA*)  wyTGALoader::load(path,isFile);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyTGA");
  }
 }
 return 1;
tolua_lerror:
 return tolua_utils_wyTGALoader_load00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: destroyTGA of class  wyTGALoader */
#ifndef TOLUA_DISABLE_tolua_utils_wyTGALoader_destroyTGA00
static int tolua_utils_wyTGALoader_destroyTGA00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyTGALoader",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyTGA",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTGA* tga = ((wyTGA*)  tolua_tousertype(tolua_S,2,0));
  {
   wyTGALoader::destroyTGA(tga);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'destroyTGA'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getResId of class  wyUtils */
#ifndef TOLUA_DISABLE_tolua_utils_wyUtils_getResId00
static int tolua_utils_wyUtils_getResId00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyUtils",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isstring(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* name = ((const char*)  tolua_tostring(tolua_S,2,0));
  const char* type = ((const char*)  tolua_tostring(tolua_S,3,0));
  const char* type2 = ((const char*)  tolua_tostring(tolua_S,4,0));
  {
   int tolua_ret = (int)  wyUtils::getResId(name,type,type2);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getResId'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getResId of class  wyUtils */
#ifndef TOLUA_DISABLE_tolua_utils_wyUtils_getResId01
static int tolua_utils_wyUtils_getResId01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyUtils",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const char* fullName = ((const char*)  tolua_tostring(tolua_S,2,0));
  {
   int tolua_ret = (int)  wyUtils::getResId(fullName);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
tolua_lerror:
 return tolua_utils_wyUtils_getResId00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: getString of class  wyUtils */
#ifndef TOLUA_DISABLE_tolua_utils_wyUtils_getString00
static int tolua_utils_wyUtils_getString00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyUtils",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* fullName = ((const char*)  tolua_tostring(tolua_S,2,0));
  {
   const char* tolua_ret = (const char*)  wyUtils::getString(fullName);
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

/* method: getString of class  wyUtils */
#ifndef TOLUA_DISABLE_tolua_utils_wyUtils_getString01
static int tolua_utils_wyUtils_getString01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyUtils",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  int resId = ((int)  tolua_tonumber(tolua_S,2,0));
  {
   const char* tolua_ret = (const char*)  wyUtils::getString(resId);
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
tolua_lerror:
 return tolua_utils_wyUtils_getString00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: getString16 of class  wyUtils */
#ifndef TOLUA_DISABLE_tolua_utils_wyUtils_getString1600
static int tolua_utils_wyUtils_getString1600(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyUtils",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* fullName = ((const char*)  tolua_tostring(tolua_S,2,0));
  {
   const char16_t* tolua_ret = (const char16_t*)  wyUtils::getString16(fullName);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"const char16_t");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getString16'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getString16 of class  wyUtils */
#ifndef TOLUA_DISABLE_tolua_utils_wyUtils_getString1601
static int tolua_utils_wyUtils_getString1601(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyUtils",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  int resId = ((int)  tolua_tonumber(tolua_S,2,0));
  {
   const char16_t* tolua_ret = (const char16_t*)  wyUtils::getString16(resId);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"const char16_t");
  }
 }
 return 1;
tolua_lerror:
 return tolua_utils_wyUtils_getString1600(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: loadRaw of class  wyUtils */
#ifndef TOLUA_DISABLE_tolua_utils_wyUtils_loadRaw00
static int tolua_utils_wyUtils_loadRaw00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyUtils",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"FILE",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"size_t",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FILE* f = ((FILE*)  tolua_tousertype(tolua_S,2,0));
  size_t* outLen = ((size_t*)  tolua_tousertype(tolua_S,3,0));
  {
   char* tolua_ret = (char*)  wyUtils::loadRaw(f,outLen);
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'loadRaw'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: loadRaw of class  wyUtils */
#ifndef TOLUA_DISABLE_tolua_utils_wyUtils_loadRaw01
static int tolua_utils_wyUtils_loadRaw01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyUtils",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,3,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,4,"size_t",1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const char* path = ((const char*)  tolua_tostring(tolua_S,2,0));
  bool isFile = ((bool)  tolua_toboolean(tolua_S,3,0));
  size_t* outLen = ((size_t*)  tolua_tousertype(tolua_S,4,NULL));
  {
   char* tolua_ret = (char*)  wyUtils::loadRaw(path,isFile,outLen);
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
tolua_lerror:
 return tolua_utils_wyUtils_loadRaw00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: loadRaw of class  wyUtils */
#ifndef TOLUA_DISABLE_tolua_utils_wyUtils_loadRaw02
static int tolua_utils_wyUtils_loadRaw02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyUtils",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"size_t",1,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  int resId = ((int)  tolua_tonumber(tolua_S,2,0));
  size_t* outLen = ((size_t*)  tolua_tousertype(tolua_S,3,NULL));
  float outScale = ((float)  tolua_tonumber(tolua_S,4,NULL));
  {
   char* tolua_ret = (char*)  wyUtils::loadRaw(resId,outLen,&outScale);
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
   tolua_pushnumber(tolua_S,(lua_Number)outScale);
  }
 }
 return 2;
tolua_lerror:
 return tolua_utils_wyUtils_loadRaw01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: loadCString of class  wyUtils */
#ifndef TOLUA_DISABLE_tolua_utils_wyUtils_loadCString00
static int tolua_utils_wyUtils_loadCString00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyUtils",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  int resId = ((int)  tolua_tonumber(tolua_S,2,0));
  {
   char* tolua_ret = (char*)  wyUtils::loadCString(resId);
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'loadCString'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: loadCString of class  wyUtils */
#ifndef TOLUA_DISABLE_tolua_utils_wyUtils_loadCString01
static int tolua_utils_wyUtils_loadCString01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyUtils",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const char* path = ((const char*)  tolua_tostring(tolua_S,2,0));
  bool isFile = ((bool)  tolua_toboolean(tolua_S,3,0));
  {
   char* tolua_ret = (char*)  wyUtils::loadCString(path,isFile);
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
tolua_lerror:
 return tolua_utils_wyUtils_loadCString00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: getPVRSize of class  wyUtils */
#ifndef TOLUA_DISABLE_tolua_utils_wyUtils_getPVRSize00
static int tolua_utils_wyUtils_getPVRSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyUtils",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"size_t",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* data = ((const char*)  tolua_tostring(tolua_S,2,0));
  size_t length = *((size_t*)  tolua_tousertype(tolua_S,3,0));
  float w = ((float)  tolua_tonumber(tolua_S,4,0));
  float h = ((float)  tolua_tonumber(tolua_S,5,0));
  float scale = ((float)  tolua_tonumber(tolua_S,6,0));
  {
   bool tolua_ret = (bool)  wyUtils::getPVRSize(data,length,&w,&h,scale);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
   tolua_pushnumber(tolua_S,(lua_Number)w);
   tolua_pushnumber(tolua_S,(lua_Number)h);
  }
 }
 return 3;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getPVRSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getPVRSize of class  wyUtils */
#ifndef TOLUA_DISABLE_tolua_utils_wyUtils_getPVRSize01
static int tolua_utils_wyUtils_getPVRSize01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyUtils",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  int resId = ((int)  tolua_tonumber(tolua_S,2,0));
  float w = ((float)  tolua_tonumber(tolua_S,3,0));
  float h = ((float)  tolua_tonumber(tolua_S,4,0));
  float outScale = ((float)  tolua_tonumber(tolua_S,5,0));
  {
   bool tolua_ret = (bool)  wyUtils::getPVRSize(resId,&w,&h,&outScale);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
   tolua_pushnumber(tolua_S,(lua_Number)w);
   tolua_pushnumber(tolua_S,(lua_Number)h);
   tolua_pushnumber(tolua_S,(lua_Number)outScale);
  }
 }
 return 4;
tolua_lerror:
 return tolua_utils_wyUtils_getPVRSize00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: getPVRSize of class  wyUtils */
#ifndef TOLUA_DISABLE_tolua_utils_wyUtils_getPVRSize02
static int tolua_utils_wyUtils_getPVRSize02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyUtils",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"FILE",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  FILE* f = ((FILE*)  tolua_tousertype(tolua_S,2,0));
  float w = ((float)  tolua_tonumber(tolua_S,3,0));
  float h = ((float)  tolua_tonumber(tolua_S,4,0));
  float scale = ((float)  tolua_tonumber(tolua_S,5,0));
  {
   bool tolua_ret = (bool)  wyUtils::getPVRSize(f,&w,&h,scale);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
   tolua_pushnumber(tolua_S,(lua_Number)w);
   tolua_pushnumber(tolua_S,(lua_Number)h);
  }
 }
 return 3;
tolua_lerror:
 return tolua_utils_wyUtils_getPVRSize01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: getPVRSize of class  wyUtils */
#ifndef TOLUA_DISABLE_tolua_utils_wyUtils_getPVRSize03
static int tolua_utils_wyUtils_getPVRSize03(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyUtils",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const char* path = ((const char*)  tolua_tostring(tolua_S,2,0));
  bool isFile = ((bool)  tolua_toboolean(tolua_S,3,0));
  float w = ((float)  tolua_tonumber(tolua_S,4,0));
  float h = ((float)  tolua_tonumber(tolua_S,5,0));
  float scale = ((float)  tolua_tonumber(tolua_S,6,0));
  {
   bool tolua_ret = (bool)  wyUtils::getPVRSize(path,isFile,&w,&h,scale);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
   tolua_pushnumber(tolua_S,(lua_Number)w);
   tolua_pushnumber(tolua_S,(lua_Number)h);
  }
 }
 return 3;
tolua_lerror:
 return tolua_utils_wyUtils_getPVRSize02(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: convertPVRHeaderEndian of class  wyUtils */
#ifndef TOLUA_DISABLE_tolua_utils_wyUtils_convertPVRHeaderEndian00
static int tolua_utils_wyUtils_convertPVRHeaderEndian00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyUtils",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyPVRHeader",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyPVRHeader* header = ((wyPVRHeader*)  tolua_tousertype(tolua_S,2,0));
  {
   wyUtils::convertPVRHeaderEndian(header);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'convertPVRHeaderEndian'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: scalePVR of class  wyUtils */
#ifndef TOLUA_DISABLE_tolua_utils_wyUtils_scalePVR00
static int tolua_utils_wyUtils_scalePVR00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyUtils",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"wyPVRFormat",0,&tolua_err)) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyPVRFormat format = *((wyPVRFormat*)  tolua_tousertype(tolua_S,2,0));
  char* originData = ((char*)  tolua_tostring(tolua_S,3,0));
  int originWidth = ((int)  tolua_tonumber(tolua_S,4,0));
  int originHeight = ((int)  tolua_tonumber(tolua_S,5,0));
  float scale = ((float)  tolua_tonumber(tolua_S,6,0));
  {
   char* tolua_ret = (char*)  wyUtils::scalePVR(format,originData,originWidth,originHeight,scale);
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'scalePVR'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: canScalePVR of class  wyUtils */
#ifndef TOLUA_DISABLE_tolua_utils_wyUtils_canScalePVR00
static int tolua_utils_wyUtils_canScalePVR00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyUtils",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"wyPVRFormat",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyPVRFormat format = *((wyPVRFormat*)  tolua_tousertype(tolua_S,2,0));
  {
   bool tolua_ret = (bool)  wyUtils::canScalePVR(format);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'canScalePVR'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: scaleImage of class  wyUtils */
#ifndef TOLUA_DISABLE_tolua_utils_wyUtils_scaleImage00
static int tolua_utils_wyUtils_scaleImage00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyUtils",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  char* originData = ((char*)  tolua_tostring(tolua_S,2,0));
  int originWidth = ((int)  tolua_tonumber(tolua_S,3,0));
  int originHeight = ((int)  tolua_tonumber(tolua_S,4,0));
  float scaleX = ((float)  tolua_tonumber(tolua_S,5,0));
  float scaleY = ((float)  tolua_tonumber(tolua_S,6,0));
  {
   char* tolua_ret = (char*)  wyUtils::scaleImage(originData,originWidth,originHeight,scaleX,scaleY);
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'scaleImage'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: convertToGL of class  wyUtils */
#ifndef TOLUA_DISABLE_tolua_utils_wyUtils_convertToGL00
static int tolua_utils_wyUtils_convertToGL00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyUtils",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyPoint",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyPoint* p = ((wyPoint*)  tolua_tousertype(tolua_S,2,0));
  {
   wyUtils::convertToGL(p);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'convertToGL'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: convertToGL of class  wyUtils */
#ifndef TOLUA_DISABLE_tolua_utils_wyUtils_convertToGL01
static int tolua_utils_wyUtils_convertToGL01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyUtils",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
  {
   wyUtils::convertToGL(&x,&y);
   tolua_pushnumber(tolua_S,(lua_Number)x);
   tolua_pushnumber(tolua_S,(lua_Number)y);
  }
 }
 return 2;
tolua_lerror:
 return tolua_utils_wyUtils_convertToGL00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: currentTimeMillis of class  wyUtils */
#ifndef TOLUA_DISABLE_tolua_utils_wyUtils_currentTimeMillis00
static int tolua_utils_wyUtils_currentTimeMillis00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyUtils",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   int64_t tolua_ret = (int64_t)  wyUtils::currentTimeMillis();
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
 tolua_error(tolua_S,"#ferror in function 'currentTimeMillis'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: swap of class  wyUtils */
#ifndef TOLUA_DISABLE_tolua_utils_wyUtils_swap00
static int tolua_utils_wyUtils_swap00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyUtils",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float f = ((float)  tolua_tonumber(tolua_S,2,0));
  int index1 = ((int)  tolua_tonumber(tolua_S,3,0));
  int index2 = ((int)  tolua_tonumber(tolua_S,4,0));
  {
   wyUtils::swap(&f,index1,index2);
   tolua_pushnumber(tolua_S,(lua_Number)f);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'swap'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: binarySearch of class  wyUtils */
#ifndef TOLUA_DISABLE_tolua_utils_wyUtils_binarySearch00
static int tolua_utils_wyUtils_binarySearch00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyUtils",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"size_t",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  int a = ((int)  tolua_tonumber(tolua_S,2,0));
  size_t len = *((size_t*)  tolua_tousertype(tolua_S,3,0));
  int key = ((int)  tolua_tonumber(tolua_S,4,0));
  {
   int tolua_ret = (int)  wyUtils::binarySearch(&a,len,key);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
   tolua_pushnumber(tolua_S,(lua_Number)a);
  }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'binarySearch'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: encodeBase64 of class  wyUtils */
#ifndef TOLUA_DISABLE_tolua_utils_wyUtils_encodeBase6400
static int tolua_utils_wyUtils_encodeBase6400(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyUtils",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"size_t",0,&tolua_err)) ||
     !tolua_isusertype(tolua_S,4,"size_t",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* src = ((const char*)  tolua_tostring(tolua_S,2,0));
  size_t len = *((size_t*)  tolua_tousertype(tolua_S,3,0));
  size_t* out_len = ((size_t*)  tolua_tousertype(tolua_S,4,0));
  {
   char* tolua_ret = (char*)  wyUtils::encodeBase64(src,len,out_len);
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'encodeBase64'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: decodeBase64 of class  wyUtils */
#ifndef TOLUA_DISABLE_tolua_utils_wyUtils_decodeBase6400
static int tolua_utils_wyUtils_decodeBase6400(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyUtils",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"size_t",0,&tolua_err)) ||
     !tolua_isusertype(tolua_S,4,"size_t",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* enc = ((const char*)  tolua_tostring(tolua_S,2,0));
  size_t length = *((size_t*)  tolua_tousertype(tolua_S,3,0));
  size_t* retLen = ((size_t*)  tolua_tousertype(tolua_S,4,0));
  {
   char* tolua_ret = (char*)  wyUtils::decodeBase64(enc,length,retLen);
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'decodeBase64'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: gunzip of class  wyUtils */
#ifndef TOLUA_DISABLE_tolua_utils_wyUtils_gunzip00
static int tolua_utils_wyUtils_gunzip00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyUtils",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isstring(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  char* in = ((char*)  tolua_tostring(tolua_S,2,0));
  int inLength = ((int)  tolua_tonumber(tolua_S,3,0));
  char* out = ((char*)  tolua_tostring(tolua_S,4,0));
  {
   int tolua_ret = (int)  wyUtils::gunzip(in,inLength,&out);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
   tolua_pushstring(tolua_S,(const char*)out);
  }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'gunzip'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: replaceChar of class  wyUtils */
#ifndef TOLUA_DISABLE_tolua_utils_wyUtils_replaceChar00
static int tolua_utils_wyUtils_replaceChar00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyUtils",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* s = ((const char*)  tolua_tostring(tolua_S,2,0));
  char c = ((char)  tolua_tonumber(tolua_S,3,0));
  char sub = ((char)  tolua_tonumber(tolua_S,4,0));
  {
   const char* tolua_ret = (const char*)  wyUtils::replaceChar(s,c,sub);
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'replaceChar'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: readLine of class  wyUtils */
#ifndef TOLUA_DISABLE_tolua_utils_wyUtils_readLine00
static int tolua_utils_wyUtils_readLine00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyUtils",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  char* data = ((char*)  tolua_tostring(tolua_S,2,0));
  char* buf = ((char*)  tolua_tostring(tolua_S,3,0));
  {
   int tolua_ret = (int)  wyUtils::readLine(&data,buf);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
   tolua_pushstring(tolua_S,(const char*)data);
  }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'readLine'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: startsWith of class  wyUtils */
#ifndef TOLUA_DISABLE_tolua_utils_wyUtils_startsWith00
static int tolua_utils_wyUtils_startsWith00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyUtils",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* s = ((const char*)  tolua_tostring(tolua_S,2,0));
  const char* sub = ((const char*)  tolua_tostring(tolua_S,3,0));
  {
   bool tolua_ret = (bool)  wyUtils::startsWith(s,sub);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'startsWith'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: endsWith of class  wyUtils */
#ifndef TOLUA_DISABLE_tolua_utils_wyUtils_endsWith00
static int tolua_utils_wyUtils_endsWith00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyUtils",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* s = ((const char*)  tolua_tostring(tolua_S,2,0));
  const char* sub = ((const char*)  tolua_tostring(tolua_S,3,0));
  {
   bool tolua_ret = (bool)  wyUtils::endsWith(s,sub);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'endsWith'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: utf16toutf8 of class  wyUtils */
#ifndef TOLUA_DISABLE_tolua_utils_wyUtils_utf16toutf800
static int tolua_utils_wyUtils_utf16toutf800(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyUtils",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const char16_t",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char16_t* s16 = ((const char16_t*)  tolua_tousertype(tolua_S,2,0));
  {
   const char* tolua_ret = (const char*)  wyUtils::utf16toutf8(s16);
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'utf16toutf8'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: utf32toutf8 of class  wyUtils */
#ifndef TOLUA_DISABLE_tolua_utils_wyUtils_utf32toutf800
static int tolua_utils_wyUtils_utf32toutf800(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyUtils",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"char32_t",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  char32_t c = *((char32_t*)  tolua_tousertype(tolua_S,2,0));
  {
   int tolua_ret = (int)  wyUtils::utf32toutf8(c);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'utf32toutf8'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: toUTF16 of class  wyUtils */
#ifndef TOLUA_DISABLE_tolua_utils_wyUtils_toUTF1600
static int tolua_utils_wyUtils_toUTF1600(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyUtils",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* s8 = ((const char*)  tolua_tostring(tolua_S,2,0));
  {
   const char16_t* tolua_ret = (const char16_t*)  wyUtils::toUTF16(s8);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"const char16_t");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'toUTF16'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: strlen16 of class  wyUtils */
#ifndef TOLUA_DISABLE_tolua_utils_wyUtils_strlen1600
static int tolua_utils_wyUtils_strlen1600(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyUtils",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const char16_t",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char16_t* str = ((const char16_t*)  tolua_tousertype(tolua_S,2,0));
  {
   int tolua_ret = (int)  wyUtils::strlen16(str);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'strlen16'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: str16str of class  wyUtils */
#ifndef TOLUA_DISABLE_tolua_utils_wyUtils_str16str00
static int tolua_utils_wyUtils_str16str00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyUtils",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const char16_t",0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char16_t* str = ((const char16_t*)  tolua_tousertype(tolua_S,2,0));
  const char* search = ((const char*)  tolua_tostring(tolua_S,3,0));
  {
   const char16_t* tolua_ret = (const char16_t*)  wyUtils::str16str(str,search);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"const char16_t");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'str16str'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: strlen8 of class  wyUtils */
#ifndef TOLUA_DISABLE_tolua_utils_wyUtils_strlen800
static int tolua_utils_wyUtils_strlen800(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyUtils",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* s = ((const char*)  tolua_tostring(tolua_S,2,0));
  {
   int tolua_ret = (int)  wyUtils::strlen8(s);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'strlen8'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getUTF8Bytes of class  wyUtils */
#ifndef TOLUA_DISABLE_tolua_utils_wyUtils_getUTF8Bytes00
static int tolua_utils_wyUtils_getUTF8Bytes00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyUtils",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  unsigned char c = ((unsigned char)  tolua_tonumber(tolua_S,2,0));
  {
   int tolua_ret = (int)  wyUtils::getUTF8Bytes(c);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getUTF8Bytes'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: trim of class  wyUtils */
#ifndef TOLUA_DISABLE_tolua_utils_wyUtils_trim00
static int tolua_utils_wyUtils_trim00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyUtils",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  char* s = ((char*)  tolua_tostring(tolua_S,2,0));
  {
   int tolua_ret = (int)  wyUtils::trim(s);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'trim'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isEmpty of class  wyUtils */
#ifndef TOLUA_DISABLE_tolua_utils_wyUtils_isEmpty00
static int tolua_utils_wyUtils_isEmpty00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyUtils",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  char* s = ((char*)  tolua_tostring(tolua_S,2,0));
  {
   bool tolua_ret = (bool)  wyUtils::isEmpty(s);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isEmpty'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: copy of class  wyUtils */
#ifndef TOLUA_DISABLE_tolua_utils_wyUtils_copy00
static int tolua_utils_wyUtils_copy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyUtils",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* src = ((const char*)  tolua_tostring(tolua_S,2,0));
  {
   const char* tolua_ret = (const char*)  wyUtils::copy(src);
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'copy'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: copy of class  wyUtils */
#ifndef TOLUA_DISABLE_tolua_utils_wyUtils_copy01
static int tolua_utils_wyUtils_copy01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyUtils",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"size_t",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const char* src = ((const char*)  tolua_tostring(tolua_S,2,0));
  int start = ((int)  tolua_tonumber(tolua_S,3,0));
  size_t len = *((size_t*)  tolua_tousertype(tolua_S,4,0));
  {
   const char* tolua_ret = (const char*)  wyUtils::copy(src,start,len);
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
tolua_lerror:
 return tolua_utils_wyUtils_copy00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: strHash of class  wyUtils */
#ifndef TOLUA_DISABLE_tolua_utils_wyUtils_strHash00
static int tolua_utils_wyUtils_strHash00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyUtils",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* str = ((const char*)  tolua_tostring(tolua_S,2,0));
  {
   unsigned int tolua_ret = (unsigned int)  wyUtils::strHash(str);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'strHash'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: resolveDp of class  wyUtils */
#ifndef TOLUA_DISABLE_tolua_utils_wyUtils_resolveDp00
static int tolua_utils_wyUtils_resolveDp00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyUtils",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float dp = ((float)  tolua_tonumber(tolua_S,2,0));
  {
   float tolua_ret = (float)  wyUtils::resolveDp(dp);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'resolveDp'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: resolveSp of class  wyUtils */
#ifndef TOLUA_DISABLE_tolua_utils_wyUtils_resolveSp00
static int tolua_utils_wyUtils_resolveSp00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyUtils",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float sp = ((float)  tolua_tonumber(tolua_S,2,0));
  {
   float tolua_ret = (float)  wyUtils::resolveSp(sp);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'resolveSp'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: resolvePx of class  wyUtils */
#ifndef TOLUA_DISABLE_tolua_utils_wyUtils_resolvePx00
static int tolua_utils_wyUtils_resolvePx00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyUtils",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float px = ((float)  tolua_tonumber(tolua_S,2,0));
  {
   float tolua_ret = (float)  wyUtils::resolvePx(px);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'resolvePx'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: resolveRect of class  wyUtils */
#ifndef TOLUA_DISABLE_tolua_utils_wyUtils_resolveRect00
static int tolua_utils_wyUtils_resolveRect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyUtils",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"wyRect",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyRect rect = *((wyRect*)  tolua_tousertype(tolua_S,2,0));
  {
   wyRect tolua_ret = (wyRect)  wyUtils::resolveRect(rect);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((wyRect)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"wyRect");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(wyRect));
     tolua_pushusertype(tolua_S,tolua_obj,"wyRect");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'resolveRect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: resolvePoint of class  wyUtils */
#ifndef TOLUA_DISABLE_tolua_utils_wyUtils_resolvePoint00
static int tolua_utils_wyUtils_resolvePoint00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyUtils",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"wyPoint",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyPoint point = *((wyPoint*)  tolua_tousertype(tolua_S,2,0));
  {
   wyPoint tolua_ret = (wyPoint)  wyUtils::resolvePoint(point);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((wyPoint)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"wyPoint");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(wyPoint));
     tolua_pushusertype(tolua_S,tolua_obj,"wyPoint");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'resolvePoint'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: calculateTextSize of class  wyUtils */
#ifndef TOLUA_DISABLE_tolua_utils_wyUtils_calculateTextSize00
static int tolua_utils_wyUtils_calculateTextSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyUtils",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isstring(tolua_S,4,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,5,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* text = ((const char*)  tolua_tostring(tolua_S,2,0));
  float fontSize = ((float)  tolua_tonumber(tolua_S,3,0));
  const char* fontPath = ((const char*)  tolua_tostring(tolua_S,4,0));
  bool isFile = ((bool)  tolua_toboolean(tolua_S,5,false));
  float width = ((float)  tolua_tonumber(tolua_S,6,0));
  {
   wySize tolua_ret = (wySize)  wyUtils::calculateTextSize(text,fontSize,fontPath,isFile,width);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((wySize)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"wySize");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(wySize));
     tolua_pushusertype(tolua_S,tolua_obj,"wySize");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'calculateTextSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: calculateTextSize of class  wyUtils */
#ifndef TOLUA_DISABLE_tolua_utils_wyUtils_calculateTextSize01
static int tolua_utils_wyUtils_calculateTextSize01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyUtils",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isstring(tolua_S,5,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const char* text = ((const char*)  tolua_tostring(tolua_S,2,0));
  float fontSize = ((float)  tolua_tonumber(tolua_S,3,0));
  wyFontStyle style = ((wyFontStyle) (int)  tolua_tonumber(tolua_S,4,0));
  const char* fontName = ((const char*)  tolua_tostring(tolua_S,5,0));
  float width = ((float)  tolua_tonumber(tolua_S,6,0));
  {
   wySize tolua_ret = (wySize)  wyUtils::calculateTextSize(text,fontSize,style,fontName,width);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((wySize)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"wySize");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(wySize));
     tolua_pushusertype(tolua_S,tolua_obj,"wySize");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
tolua_lerror:
 return tolua_utils_wyUtils_calculateTextSize00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: createLabelBitmap of class  wyUtils */
#ifndef TOLUA_DISABLE_tolua_utils_wyUtils_createLabelBitmap00
static int tolua_utils_wyUtils_createLabelBitmap00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyUtils",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isstring(tolua_S,4,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,5,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,7,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,8,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* text = ((const char*)  tolua_tostring(tolua_S,2,0));
  float fontSize = ((float)  tolua_tonumber(tolua_S,3,0));
  const char* fontPath = ((const char*)  tolua_tostring(tolua_S,4,0));
  bool isFile = ((bool)  tolua_toboolean(tolua_S,5,false));
  float width = ((float)  tolua_tonumber(tolua_S,6,0));
  wyTexture2D::TextAlignment alignment = ((wyTexture2D::TextAlignment) (int)  tolua_tonumber(tolua_S,7,wyTexture2D::LEFT));
  {
   const char* tolua_ret = (const char*)  wyUtils::createLabelBitmap(text,fontSize,fontPath,isFile,width,alignment);
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'createLabelBitmap'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: createLabelBitmap of class  wyUtils */
#ifndef TOLUA_DISABLE_tolua_utils_wyUtils_createLabelBitmap01
static int tolua_utils_wyUtils_createLabelBitmap01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyUtils",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,1,&tolua_err) ||
     !tolua_isstring(tolua_S,5,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,7,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,8,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const char* text = ((const char*)  tolua_tostring(tolua_S,2,0));
  float fontSize = ((float)  tolua_tonumber(tolua_S,3,0));
  wyFontStyle style = ((wyFontStyle) (int)  tolua_tonumber(tolua_S,4,NORMAL));
  const char* fontName = ((const char*)  tolua_tostring(tolua_S,5,NULL));
  float width = ((float)  tolua_tonumber(tolua_S,6,0));
  wyTexture2D::TextAlignment alignment = ((wyTexture2D::TextAlignment) (int)  tolua_tonumber(tolua_S,7,wyTexture2D::LEFT));
  {
   const char* tolua_ret = (const char*)  wyUtils::createLabelBitmap(text,fontSize,style,fontName,width,alignment);
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
tolua_lerror:
 return tolua_utils_wyUtils_createLabelBitmap00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: makeScreenshot of class  wyUtils */
#ifndef TOLUA_DISABLE_tolua_utils_wyUtils_makeScreenshot00
static int tolua_utils_wyUtils_makeScreenshot00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyUtils",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* path = ((const char*)  tolua_tostring(tolua_S,2,0));
  {
   wyUtils::makeScreenshot(path);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'makeScreenshot'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: makeScreenshot of class  wyUtils */
#ifndef TOLUA_DISABLE_tolua_utils_wyUtils_makeScreenshot01
static int tolua_utils_wyUtils_makeScreenshot01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyUtils",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"wyRect",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const char* path = ((const char*)  tolua_tostring(tolua_S,2,0));
  wyRect rect = *((wyRect*)  tolua_tousertype(tolua_S,3,0));
  {
   wyUtils::makeScreenshot(path,rect);
  }
 }
 return 0;
tolua_lerror:
 return tolua_utils_wyUtils_makeScreenshot00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: getFileSize of class  wyUtils */
#ifndef TOLUA_DISABLE_tolua_utils_wyUtils_getFileSize00
static int tolua_utils_wyUtils_getFileSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyUtils",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"FILE",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FILE* f = ((FILE*)  tolua_tousertype(tolua_S,2,0));
  {
   int tolua_ret = (int)  wyUtils::getFileSize(f);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getFileSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getParentPath of class  wyUtils */
#ifndef TOLUA_DISABLE_tolua_utils_wyUtils_getParentPath00
static int tolua_utils_wyUtils_getParentPath00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyUtils",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* path = ((const char*)  tolua_tostring(tolua_S,2,0));
  {
   const char* tolua_ret = (const char*)  wyUtils::getParentPath(path);
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getParentPath'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isPathExistent of class  wyUtils */
#ifndef TOLUA_DISABLE_tolua_utils_wyUtils_isPathExistent00
static int tolua_utils_wyUtils_isPathExistent00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyUtils",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* path = ((const char*)  tolua_tostring(tolua_S,2,0));
  {
   bool tolua_ret = (bool)  wyUtils::isPathExistent(path);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isPathExistent'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: deleteFile of class  wyUtils */
#ifndef TOLUA_DISABLE_tolua_utils_wyUtils_deleteFile00
static int tolua_utils_wyUtils_deleteFile00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyUtils",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* path = ((const char*)  tolua_tostring(tolua_S,2,0));
  {
   bool tolua_ret = (bool)  wyUtils::deleteFile(path);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'deleteFile'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: createIntermediateFolders of class  wyUtils */
#ifndef TOLUA_DISABLE_tolua_utils_wyUtils_createIntermediateFolders00
static int tolua_utils_wyUtils_createIntermediateFolders00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyUtils",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* path = ((const char*)  tolua_tostring(tolua_S,2,0));
  {
   bool tolua_ret = (bool)  wyUtils::createIntermediateFolders(path);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'createIntermediateFolders'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: deleteLastPathComponent of class  wyUtils */
#ifndef TOLUA_DISABLE_tolua_utils_wyUtils_deleteLastPathComponent00
static int tolua_utils_wyUtils_deleteLastPathComponent00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyUtils",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* path = ((const char*)  tolua_tostring(tolua_S,2,0));
  {
   const char* tolua_ret = (const char*)  wyUtils::deleteLastPathComponent(path);
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'deleteLastPathComponent'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: appendPathComponent of class  wyUtils */
#ifndef TOLUA_DISABLE_tolua_utils_wyUtils_appendPathComponent00
static int tolua_utils_wyUtils_appendPathComponent00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyUtils",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* path = ((const char*)  tolua_tostring(tolua_S,2,0));
  const char* component = ((const char*)  tolua_tostring(tolua_S,3,0));
  {
   const char* tolua_ret = (const char*)  wyUtils::appendPathComponent(path,component);
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'appendPathComponent'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: lastPathComponent of class  wyUtils */
#ifndef TOLUA_DISABLE_tolua_utils_wyUtils_lastPathComponent00
static int tolua_utils_wyUtils_lastPathComponent00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyUtils",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* path = ((const char*)  tolua_tostring(tolua_S,2,0));
  {
   const char* tolua_ret = (const char*)  wyUtils::lastPathComponent(path);
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'lastPathComponent'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: mapLocalPath of class  wyUtils */
#ifndef TOLUA_DISABLE_tolua_utils_wyUtils_mapLocalPath00
static int tolua_utils_wyUtils_mapLocalPath00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyUtils",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* path = ((const char*)  tolua_tostring(tolua_S,2,0));
  {
   const char* tolua_ret = (const char*)  wyUtils::mapLocalPath(path);
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'mapLocalPath'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: mapAssetsPath of class  wyUtils */
#ifndef TOLUA_DISABLE_tolua_utils_wyUtils_mapAssetsPath00
static int tolua_utils_wyUtils_mapAssetsPath00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyUtils",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* path = ((const char*)  tolua_tostring(tolua_S,2,0));
  {
   const char* tolua_ret = (const char*)  wyUtils::mapAssetsPath(path);
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'mapAssetsPath'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: runOnGLThread of class  wyUtils */
#ifndef TOLUA_DISABLE_tolua_utils_wyUtils_runOnGLThread00
static int tolua_utils_wyUtils_runOnGLThread00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyUtils",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyRunnable",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyRunnable* runnable = ((wyRunnable*)  tolua_tousertype(tolua_S,2,0));
  {
   wyUtils::runOnGLThread(runnable);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'runOnGLThread'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: playVideo of class  wyUtils */
#ifndef TOLUA_DISABLE_tolua_utils_wyUtils_playVideo00
static int tolua_utils_wyUtils_playVideo00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyUtils",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  int resId = ((int)  tolua_tonumber(tolua_S,2,0));
  {
   wyUtils::playVideo(resId);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'playVideo'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: playVideo of class  wyUtils */
#ifndef TOLUA_DISABLE_tolua_utils_wyUtils_playVideo01
static int tolua_utils_wyUtils_playVideo01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyUtils",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,3,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const char* path = ((const char*)  tolua_tostring(tolua_S,2,0));
  bool isRemote = ((bool)  tolua_toboolean(tolua_S,3,false));
  {
   wyUtils::playVideo(path,isRemote);
  }
 }
 return 0;
tolua_lerror:
 return tolua_utils_wyUtils_playVideo00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: openUrl of class  wyUtils */
#ifndef TOLUA_DISABLE_tolua_utils_wyUtils_openUrl00
static int tolua_utils_wyUtils_openUrl00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyUtils",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* url = ((const char*)  tolua_tostring(tolua_S,2,0));
  {
   wyUtils::openUrl(url);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'openUrl'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  wyVerletPoint */
#ifndef TOLUA_DISABLE_tolua_utils_wyVerletPoint_new00
static int tolua_utils_wyVerletPoint_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyVerletPoint",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   wyVerletPoint* tolua_ret = (wyVerletPoint*)  Mtolua_new((wyVerletPoint)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyVerletPoint");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  wyVerletPoint */
#ifndef TOLUA_DISABLE_tolua_utils_wyVerletPoint_new00_local
static int tolua_utils_wyVerletPoint_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyVerletPoint",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   wyVerletPoint* tolua_ret = (wyVerletPoint*)  Mtolua_new((wyVerletPoint)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyVerletPoint");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  wyVerletPoint */
#ifndef TOLUA_DISABLE_tolua_utils_wyVerletPoint_delete00
static int tolua_utils_wyVerletPoint_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyVerletPoint",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyVerletPoint* self = (wyVerletPoint*)  tolua_tousertype(tolua_S,1,0);
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

/* method: setPosition of class  wyVerletPoint */
#ifndef TOLUA_DISABLE_tolua_utils_wyVerletPoint_setPosition00
static int tolua_utils_wyVerletPoint_setPosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyVerletPoint",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyVerletPoint* self = (wyVerletPoint*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setPosition'", NULL);
#endif
  {
   self->setPosition(x,y);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setPosition'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: update of class  wyVerletPoint */
#ifndef TOLUA_DISABLE_tolua_utils_wyVerletPoint_update00
static int tolua_utils_wyVerletPoint_update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyVerletPoint",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyVerletPoint* self = (wyVerletPoint*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'update'", NULL);
#endif
  {
   self->update();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'update'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: applyGravity of class  wyVerletPoint */
#ifndef TOLUA_DISABLE_tolua_utils_wyVerletPoint_applyGravity00
static int tolua_utils_wyVerletPoint_applyGravity00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyVerletPoint",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyVerletPoint* self = (wyVerletPoint*)  tolua_tousertype(tolua_S,1,0);
  float dt = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'applyGravity'", NULL);
#endif
  {
   self->applyGravity(dt);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'applyGravity'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setX of class  wyVerletPoint */
#ifndef TOLUA_DISABLE_tolua_utils_wyVerletPoint_setX00
static int tolua_utils_wyVerletPoint_setX00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyVerletPoint",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyVerletPoint* self = (wyVerletPoint*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setX'", NULL);
#endif
  {
   self->setX(x);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setX'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setY of class  wyVerletPoint */
#ifndef TOLUA_DISABLE_tolua_utils_wyVerletPoint_setY00
static int tolua_utils_wyVerletPoint_setY00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyVerletPoint",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyVerletPoint* self = (wyVerletPoint*)  tolua_tousertype(tolua_S,1,0);
  float y = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setY'", NULL);
#endif
  {
   self->setY(y);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setY'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getX of class  wyVerletPoint */
#ifndef TOLUA_DISABLE_tolua_utils_wyVerletPoint_getX00
static int tolua_utils_wyVerletPoint_getX00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyVerletPoint",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyVerletPoint* self = (wyVerletPoint*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getX'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getX();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getX'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getY of class  wyVerletPoint */
#ifndef TOLUA_DISABLE_tolua_utils_wyVerletPoint_getY00
static int tolua_utils_wyVerletPoint_getY00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyVerletPoint",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyVerletPoint* self = (wyVerletPoint*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getY'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getY();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getY'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: attenuate of class  wyVerletPoint */
#ifndef TOLUA_DISABLE_tolua_utils_wyVerletPoint_attenuate00
static int tolua_utils_wyVerletPoint_attenuate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyVerletPoint",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyVerletPoint* self = (wyVerletPoint*)  tolua_tousertype(tolua_S,1,0);
  float percent = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'attenuate'", NULL);
#endif
  {
   self->attenuate(percent);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'attenuate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: copy of class  wyVerletPoint */
#ifndef TOLUA_DISABLE_tolua_utils_wyVerletPoint_copy00
static int tolua_utils_wyVerletPoint_copy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyVerletPoint",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyVerletPoint* self = (wyVerletPoint*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'copy'", NULL);
#endif
  {
   wyVerletPoint* tolua_ret = (wyVerletPoint*)  self->copy();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyVerletPoint");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'copy'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  wyVerletRope */
#ifndef TOLUA_DISABLE_tolua_utils_wyVerletRope_new00
static int tolua_utils_wyVerletRope_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyVerletRope",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"wyPoint",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"wyPoint",0,&tolua_err)) ||
     !tolua_isusertype(tolua_S,4,"wyTexture2D",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyPoint a = *((wyPoint*)  tolua_tousertype(tolua_S,2,0));
  wyPoint b = *((wyPoint*)  tolua_tousertype(tolua_S,3,0));
  wyTexture2D* tex = ((wyTexture2D*)  tolua_tousertype(tolua_S,4,0));
  int length = ((int)  tolua_tonumber(tolua_S,5,0));
  {
   wyVerletRope* tolua_ret = (wyVerletRope*)  Mtolua_new((wyVerletRope)(a,b,tex,length));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyVerletRope");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  wyVerletRope */
#ifndef TOLUA_DISABLE_tolua_utils_wyVerletRope_new00_local
static int tolua_utils_wyVerletRope_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyVerletRope",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"wyPoint",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"wyPoint",0,&tolua_err)) ||
     !tolua_isusertype(tolua_S,4,"wyTexture2D",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyPoint a = *((wyPoint*)  tolua_tousertype(tolua_S,2,0));
  wyPoint b = *((wyPoint*)  tolua_tousertype(tolua_S,3,0));
  wyTexture2D* tex = ((wyTexture2D*)  tolua_tousertype(tolua_S,4,0));
  int length = ((int)  tolua_tonumber(tolua_S,5,0));
  {
   wyVerletRope* tolua_ret = (wyVerletRope*)  Mtolua_new((wyVerletRope)(a,b,tex,length));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyVerletRope");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  wyVerletRope */
#ifndef TOLUA_DISABLE_tolua_utils_wyVerletRope_delete00
static int tolua_utils_wyVerletRope_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyVerletRope",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyVerletRope* self = (wyVerletRope*)  tolua_tousertype(tolua_S,1,0);
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

/* method: reset of class  wyVerletRope */
#ifndef TOLUA_DISABLE_tolua_utils_wyVerletRope_reset00
static int tolua_utils_wyVerletRope_reset00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyVerletRope",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"wyPoint",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"wyPoint",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyVerletRope* self = (wyVerletRope*)  tolua_tousertype(tolua_S,1,0);
  wyPoint a = *((wyPoint*)  tolua_tousertype(tolua_S,2,0));
  wyPoint b = *((wyPoint*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'reset'", NULL);
#endif
  {
   self->reset(a,b);
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

/* method: update of class  wyVerletRope */
#ifndef TOLUA_DISABLE_tolua_utils_wyVerletRope_update00
static int tolua_utils_wyVerletRope_update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyVerletRope",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"wyPoint",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"wyPoint",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyVerletRope* self = (wyVerletRope*)  tolua_tousertype(tolua_S,1,0);
  wyPoint a = *((wyPoint*)  tolua_tousertype(tolua_S,2,0));
  wyPoint b = *((wyPoint*)  tolua_tousertype(tolua_S,3,0));
  float dt = ((float)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'update'", NULL);
#endif
  {
   self->update(a,b,dt);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'update'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getSticks of class  wyVerletRope */
#ifndef TOLUA_DISABLE_tolua_utils_wyVerletRope_getSticks00
static int tolua_utils_wyVerletRope_getSticks00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyVerletRope",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyVerletRope* self = (wyVerletRope*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getSticks'", NULL);
#endif
  {
   wyArray* tolua_ret = (wyArray*)  self->getSticks();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyArray");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getSticks'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getStickAt of class  wyVerletRope */
#ifndef TOLUA_DISABLE_tolua_utils_wyVerletRope_getStickAt00
static int tolua_utils_wyVerletRope_getStickAt00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyVerletRope",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyVerletRope* self = (wyVerletRope*)  tolua_tousertype(tolua_S,1,0);
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getStickAt'", NULL);
#endif
  {
   wyVerletStick* tolua_ret = (wyVerletStick*)  self->getStickAt(index);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyVerletStick");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getStickAt'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getStickCount of class  wyVerletRope */
#ifndef TOLUA_DISABLE_tolua_utils_wyVerletRope_getStickCount00
static int tolua_utils_wyVerletRope_getStickCount00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyVerletRope",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyVerletRope* self = (wyVerletRope*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getStickCount'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getStickCount();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getStickCount'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getPoints of class  wyVerletRope */
#ifndef TOLUA_DISABLE_tolua_utils_wyVerletRope_getPoints00
static int tolua_utils_wyVerletRope_getPoints00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyVerletRope",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyVerletRope* self = (wyVerletRope*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getPoints'", NULL);
#endif
  {
   wyArray* tolua_ret = (wyArray*)  self->getPoints();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyArray");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getPoints'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getPointAt of class  wyVerletRope */
#ifndef TOLUA_DISABLE_tolua_utils_wyVerletRope_getPointAt00
static int tolua_utils_wyVerletRope_getPointAt00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyVerletRope",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyVerletRope* self = (wyVerletRope*)  tolua_tousertype(tolua_S,1,0);
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getPointAt'", NULL);
#endif
  {
   wyVerletPoint* tolua_ret = (wyVerletPoint*)  self->getPointAt(index);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyVerletPoint");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getPointAt'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getPointCount of class  wyVerletRope */
#ifndef TOLUA_DISABLE_tolua_utils_wyVerletRope_getPointCount00
static int tolua_utils_wyVerletRope_getPointCount00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyVerletRope",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyVerletRope* self = (wyVerletRope*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getPointCount'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getPointCount();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getPointCount'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getCurrentLength of class  wyVerletRope */
#ifndef TOLUA_DISABLE_tolua_utils_wyVerletRope_getCurrentLength00
static int tolua_utils_wyVerletRope_getCurrentLength00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyVerletRope",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyVerletRope* self = (wyVerletRope*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getCurrentLength'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getCurrentLength();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getCurrentLength'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: rayCast of class  wyVerletRope */
#ifndef TOLUA_DISABLE_tolua_utils_wyVerletRope_rayCast00
static int tolua_utils_wyVerletRope_rayCast00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyVerletRope",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"wyPoint",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"wyPoint",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyVerletRope* self = (wyVerletRope*)  tolua_tousertype(tolua_S,1,0);
  wyPoint s = *((wyPoint*)  tolua_tousertype(tolua_S,2,0));
  wyPoint e = *((wyPoint*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'rayCast'", NULL);
#endif
  {
   int tolua_ret = (int)  self->rayCast(s,e);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'rayCast'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getColor of class  wyVerletRope */
#ifndef TOLUA_DISABLE_tolua_utils_wyVerletRope_getColor00
static int tolua_utils_wyVerletRope_getColor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyVerletRope",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyVerletRope* self = (wyVerletRope*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getColor'", NULL);
#endif
  {
   wyColor3B tolua_ret = (wyColor3B)  self->getColor();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((wyColor3B)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"wyColor3B");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(wyColor3B));
     tolua_pushusertype(tolua_S,tolua_obj,"wyColor3B");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getColor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setColor of class  wyVerletRope */
#ifndef TOLUA_DISABLE_tolua_utils_wyVerletRope_setColor00
static int tolua_utils_wyVerletRope_setColor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyVerletRope",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"wyColor3B",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyVerletRope* self = (wyVerletRope*)  tolua_tousertype(tolua_S,1,0);
  wyColor3B color = *((wyColor3B*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setColor'", NULL);
#endif
  {
   self->setColor(color);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setColor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setColor of class  wyVerletRope */
#ifndef TOLUA_DISABLE_tolua_utils_wyVerletRope_setColor01
static int tolua_utils_wyVerletRope_setColor01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyVerletRope",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"wyColor4B",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  wyVerletRope* self = (wyVerletRope*)  tolua_tousertype(tolua_S,1,0);
  wyColor4B color = *((wyColor4B*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setColor'", NULL);
#endif
  {
   self->setColor(color);
  }
 }
 return 0;
tolua_lerror:
 return tolua_utils_wyVerletRope_setColor00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: getAlpha of class  wyVerletRope */
#ifndef TOLUA_DISABLE_tolua_utils_wyVerletRope_getAlpha00
static int tolua_utils_wyVerletRope_getAlpha00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyVerletRope",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyVerletRope* self = (wyVerletRope*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getAlpha'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getAlpha();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getAlpha'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setAlpha of class  wyVerletRope */
#ifndef TOLUA_DISABLE_tolua_utils_wyVerletRope_setAlpha00
static int tolua_utils_wyVerletRope_setAlpha00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyVerletRope",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyVerletRope* self = (wyVerletRope*)  tolua_tousertype(tolua_S,1,0);
  int alpha = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setAlpha'", NULL);
#endif
  {
   self->setAlpha(alpha);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setAlpha'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getLength of class  wyVerletRope */
#ifndef TOLUA_DISABLE_tolua_utils_wyVerletRope_getLength00
static int tolua_utils_wyVerletRope_getLength00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyVerletRope",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyVerletRope* self = (wyVerletRope*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getLength'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getLength();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getLength'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: subRope of class  wyVerletRope */
#ifndef TOLUA_DISABLE_tolua_utils_wyVerletRope_subRope00
static int tolua_utils_wyVerletRope_subRope00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyVerletRope",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyVerletRope* self = (wyVerletRope*)  tolua_tousertype(tolua_S,1,0);
  int startPoint = ((int)  tolua_tonumber(tolua_S,2,0));
  int endPoint = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'subRope'", NULL);
#endif
  {
   wyVerletRope* tolua_ret = (wyVerletRope*)  self->subRope(startPoint,endPoint);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyVerletRope");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'subRope'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isStretched of class  wyVerletRope */
#ifndef TOLUA_DISABLE_tolua_utils_wyVerletRope_isStretched00
static int tolua_utils_wyVerletRope_isStretched00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyVerletRope",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyVerletRope* self = (wyVerletRope*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isStretched'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isStretched();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isStretched'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: changeLength of class  wyVerletRope */
#ifndef TOLUA_DISABLE_tolua_utils_wyVerletRope_changeLength00
static int tolua_utils_wyVerletRope_changeLength00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyVerletRope",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyVerletRope* self = (wyVerletRope*)  tolua_tousertype(tolua_S,1,0);
  float delta = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'changeLength'", NULL);
#endif
  {
   self->changeLength(delta);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'changeLength'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  wyVerletStick */
#ifndef TOLUA_DISABLE_tolua_utils_wyVerletStick_new00
static int tolua_utils_wyVerletStick_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyVerletStick",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyVerletPoint",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"wyVerletPoint",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyVerletPoint* a = ((wyVerletPoint*)  tolua_tousertype(tolua_S,2,0));
  wyVerletPoint* b = ((wyVerletPoint*)  tolua_tousertype(tolua_S,3,0));
  {
   wyVerletStick* tolua_ret = (wyVerletStick*)  Mtolua_new((wyVerletStick)(a,b));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyVerletStick");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  wyVerletStick */
#ifndef TOLUA_DISABLE_tolua_utils_wyVerletStick_new00_local
static int tolua_utils_wyVerletStick_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyVerletStick",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyVerletPoint",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"wyVerletPoint",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyVerletPoint* a = ((wyVerletPoint*)  tolua_tousertype(tolua_S,2,0));
  wyVerletPoint* b = ((wyVerletPoint*)  tolua_tousertype(tolua_S,3,0));
  {
   wyVerletStick* tolua_ret = (wyVerletStick*)  Mtolua_new((wyVerletStick)(a,b));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyVerletStick");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  wyVerletStick */
#ifndef TOLUA_DISABLE_tolua_utils_wyVerletStick_delete00
static int tolua_utils_wyVerletStick_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyVerletStick",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyVerletStick* self = (wyVerletStick*)  tolua_tousertype(tolua_S,1,0);
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

/* method: contract of class  wyVerletStick */
#ifndef TOLUA_DISABLE_tolua_utils_wyVerletStick_contract00
static int tolua_utils_wyVerletStick_contract00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyVerletStick",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyVerletStick* self = (wyVerletStick*)  tolua_tousertype(tolua_S,1,0);
  bool reverse = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'contract'", NULL);
#endif
  {
   self->contract(reverse);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'contract'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getPointA of class  wyVerletStick */
#ifndef TOLUA_DISABLE_tolua_utils_wyVerletStick_getPointA00
static int tolua_utils_wyVerletStick_getPointA00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyVerletStick",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyVerletStick* self = (wyVerletStick*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getPointA'", NULL);
#endif
  {
   wyVerletPoint* tolua_ret = (wyVerletPoint*)  self->getPointA();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyVerletPoint");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getPointA'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getPointB of class  wyVerletStick */
#ifndef TOLUA_DISABLE_tolua_utils_wyVerletStick_getPointB00
static int tolua_utils_wyVerletStick_getPointB00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyVerletStick",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyVerletStick* self = (wyVerletStick*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getPointB'", NULL);
#endif
  {
   wyVerletPoint* tolua_ret = (wyVerletPoint*)  self->getPointB();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyVerletPoint");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getPointB'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getLength of class  wyVerletStick */
#ifndef TOLUA_DISABLE_tolua_utils_wyVerletStick_getLength00
static int tolua_utils_wyVerletStick_getLength00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyVerletStick",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyVerletStick* self = (wyVerletStick*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getLength'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getLength();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getLength'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getCurrentLength of class  wyVerletStick */
#ifndef TOLUA_DISABLE_tolua_utils_wyVerletStick_getCurrentLength00
static int tolua_utils_wyVerletStick_getCurrentLength00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyVerletStick",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyVerletStick* self = (wyVerletStick*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getCurrentLength'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getCurrentLength();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getCurrentLength'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: key of class  wyZwoptexFrame */
#ifndef TOLUA_DISABLE_tolua_get_wyZwoptexFrame_key
static int tolua_get_wyZwoptexFrame_key(lua_State* tolua_S)
{
  wyZwoptexFrame* self = (wyZwoptexFrame*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'key'",NULL);
#endif
  tolua_pushstring(tolua_S,(const char*)self->key);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: rect of class  wyZwoptexFrame */
#ifndef TOLUA_DISABLE_tolua_get_wyZwoptexFrame_rect
static int tolua_get_wyZwoptexFrame_rect(lua_State* tolua_S)
{
  wyZwoptexFrame* self = (wyZwoptexFrame*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'rect'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->rect,"wyRect");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: rect of class  wyZwoptexFrame */
#ifndef TOLUA_DISABLE_tolua_set_wyZwoptexFrame_rect
static int tolua_set_wyZwoptexFrame_rect(lua_State* tolua_S)
{
  wyZwoptexFrame* self = (wyZwoptexFrame*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'rect'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"wyRect",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->rect = *((wyRect*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: sourceColorRect of class  wyZwoptexFrame */
#ifndef TOLUA_DISABLE_tolua_get_wyZwoptexFrame_sourceColorRect
static int tolua_get_wyZwoptexFrame_sourceColorRect(lua_State* tolua_S)
{
  wyZwoptexFrame* self = (wyZwoptexFrame*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'sourceColorRect'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->sourceColorRect,"wyRect");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: sourceColorRect of class  wyZwoptexFrame */
#ifndef TOLUA_DISABLE_tolua_set_wyZwoptexFrame_sourceColorRect
static int tolua_set_wyZwoptexFrame_sourceColorRect(lua_State* tolua_S)
{
  wyZwoptexFrame* self = (wyZwoptexFrame*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'sourceColorRect'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"wyRect",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->sourceColorRect = *((wyRect*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: offset of class  wyZwoptexFrame */
#ifndef TOLUA_DISABLE_tolua_get_wyZwoptexFrame_offset
static int tolua_get_wyZwoptexFrame_offset(lua_State* tolua_S)
{
  wyZwoptexFrame* self = (wyZwoptexFrame*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'offset'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->offset,"wyPoint");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: offset of class  wyZwoptexFrame */
#ifndef TOLUA_DISABLE_tolua_set_wyZwoptexFrame_offset
static int tolua_set_wyZwoptexFrame_offset(lua_State* tolua_S)
{
  wyZwoptexFrame* self = (wyZwoptexFrame*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'offset'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"wyPoint",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->offset = *((wyPoint*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: sourceSize of class  wyZwoptexFrame */
#ifndef TOLUA_DISABLE_tolua_get_wyZwoptexFrame_sourceSize
static int tolua_get_wyZwoptexFrame_sourceSize(lua_State* tolua_S)
{
  wyZwoptexFrame* self = (wyZwoptexFrame*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'sourceSize'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->sourceSize,"wySize");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: sourceSize of class  wyZwoptexFrame */
#ifndef TOLUA_DISABLE_tolua_set_wyZwoptexFrame_sourceSize
static int tolua_set_wyZwoptexFrame_sourceSize(lua_State* tolua_S)
{
  wyZwoptexFrame* self = (wyZwoptexFrame*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'sourceSize'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"wySize",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->sourceSize = *((wySize*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: rotated of class  wyZwoptexFrame */
#ifndef TOLUA_DISABLE_tolua_get_wyZwoptexFrame_rotated
static int tolua_get_wyZwoptexFrame_rotated(lua_State* tolua_S)
{
  wyZwoptexFrame* self = (wyZwoptexFrame*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'rotated'",NULL);
#endif
  tolua_pushboolean(tolua_S,(bool)self->rotated);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: rotated of class  wyZwoptexFrame */
#ifndef TOLUA_DISABLE_tolua_set_wyZwoptexFrame_rotated
static int tolua_set_wyZwoptexFrame_rotated(lua_State* tolua_S)
{
  wyZwoptexFrame* self = (wyZwoptexFrame*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'rotated'",NULL);
  if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->rotated = ((bool)  tolua_toboolean(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  wyZwoptexFrame */
#ifndef TOLUA_DISABLE_tolua_utils_wyZwoptexFrame_new00
static int tolua_utils_wyZwoptexFrame_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyZwoptexFrame",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   wyZwoptexFrame* tolua_ret = (wyZwoptexFrame*)  Mtolua_new((wyZwoptexFrame)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyZwoptexFrame");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  wyZwoptexFrame */
#ifndef TOLUA_DISABLE_tolua_utils_wyZwoptexFrame_new00_local
static int tolua_utils_wyZwoptexFrame_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyZwoptexFrame",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   wyZwoptexFrame* tolua_ret = (wyZwoptexFrame*)  Mtolua_new((wyZwoptexFrame)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyZwoptexFrame");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  wyZwoptexFrame */
#ifndef TOLUA_DISABLE_tolua_utils_wyZwoptexFrame_delete00
static int tolua_utils_wyZwoptexFrame_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyZwoptexFrame",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyZwoptexFrame* self = (wyZwoptexFrame*)  tolua_tousertype(tolua_S,1,0);
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

/* method: new of class  wyZwoptex */
#ifndef TOLUA_DISABLE_tolua_utils_wyZwoptex_new00
static int tolua_utils_wyZwoptex_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyZwoptex",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  int resId = ((int)  tolua_tonumber(tolua_S,2,0));
  {
   wyZwoptex* tolua_ret = (wyZwoptex*)  Mtolua_new((wyZwoptex)(resId));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyZwoptex");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  wyZwoptex */
#ifndef TOLUA_DISABLE_tolua_utils_wyZwoptex_new00_local
static int tolua_utils_wyZwoptex_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyZwoptex",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  int resId = ((int)  tolua_tonumber(tolua_S,2,0));
  {
   wyZwoptex* tolua_ret = (wyZwoptex*)  Mtolua_new((wyZwoptex)(resId));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyZwoptex");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  wyZwoptex */
#ifndef TOLUA_DISABLE_tolua_utils_wyZwoptex_new01
static int tolua_utils_wyZwoptex_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyZwoptex",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,3,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const char* path = ((const char*)  tolua_tostring(tolua_S,2,0));
  bool isFile = ((bool)  tolua_toboolean(tolua_S,3,false));
  {
   wyZwoptex* tolua_ret = (wyZwoptex*)  Mtolua_new((wyZwoptex)(path,isFile));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyZwoptex");
  }
 }
 return 1;
tolua_lerror:
 return tolua_utils_wyZwoptex_new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  wyZwoptex */
#ifndef TOLUA_DISABLE_tolua_utils_wyZwoptex_new01_local
static int tolua_utils_wyZwoptex_new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyZwoptex",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,3,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const char* path = ((const char*)  tolua_tostring(tolua_S,2,0));
  bool isFile = ((bool)  tolua_toboolean(tolua_S,3,false));
  {
   wyZwoptex* tolua_ret = (wyZwoptex*)  Mtolua_new((wyZwoptex)(path,isFile));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyZwoptex");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_utils_wyZwoptex_new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  wyZwoptex */
#ifndef TOLUA_DISABLE_tolua_utils_wyZwoptex_delete00
static int tolua_utils_wyZwoptex_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyZwoptex",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyZwoptex* self = (wyZwoptex*)  tolua_tousertype(tolua_S,1,0);
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

/* method: getFormat of class  wyZwoptex */
#ifndef TOLUA_DISABLE_tolua_utils_wyZwoptex_getFormat00
static int tolua_utils_wyZwoptex_getFormat00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyZwoptex",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyZwoptex* self = (wyZwoptex*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getFormat'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getFormat();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getFormat'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getSize of class  wyZwoptex */
#ifndef TOLUA_DISABLE_tolua_utils_wyZwoptex_getSize00
static int tolua_utils_wyZwoptex_getSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyZwoptex",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyZwoptex* self = (wyZwoptex*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getSize'", NULL);
#endif
  {
   wySize tolua_ret = (wySize)  self->getSize();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((wySize)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"wySize");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(wySize));
     tolua_pushusertype(tolua_S,tolua_obj,"wySize");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: addFrame of class  wyZwoptex */
#ifndef TOLUA_DISABLE_tolua_utils_wyZwoptex_addFrame00
static int tolua_utils_wyZwoptex_addFrame00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyZwoptex",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyZwoptexFrame",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyZwoptex* self = (wyZwoptex*)  tolua_tousertype(tolua_S,1,0);
  wyZwoptexFrame* frame = ((wyZwoptexFrame*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addFrame'", NULL);
#endif
  {
   self->addFrame(frame);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addFrame'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getFrame of class  wyZwoptex */
#ifndef TOLUA_DISABLE_tolua_utils_wyZwoptex_getFrame00
static int tolua_utils_wyZwoptex_getFrame00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyZwoptex",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyZwoptex* self = (wyZwoptex*)  tolua_tousertype(tolua_S,1,0);
  const char* key = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getFrame'", NULL);
#endif
  {
   wyZwoptexFrame* tolua_ret = (wyZwoptexFrame*)  self->getFrame(key);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyZwoptexFrame");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getFrame'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getSpriteFrame of class  wyZwoptex */
#ifndef TOLUA_DISABLE_tolua_utils_wyZwoptex_getSpriteFrame00
static int tolua_utils_wyZwoptex_getSpriteFrame00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyZwoptex",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyZwoptex* self = (wyZwoptex*)  tolua_tousertype(tolua_S,1,0);
  const char* key = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getSpriteFrame'", NULL);
#endif
  {
   wySpriteFrame* tolua_ret = (wySpriteFrame*)  self->getSpriteFrame(key);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wySpriteFrame");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getSpriteFrame'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getFrameRect of class  wyZwoptex */
#ifndef TOLUA_DISABLE_tolua_utils_wyZwoptex_getFrameRect00
static int tolua_utils_wyZwoptex_getFrameRect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyZwoptex",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyZwoptex* self = (wyZwoptex*)  tolua_tousertype(tolua_S,1,0);
  const char* key = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getFrameRect'", NULL);
#endif
  {
   wyRect tolua_ret = (wyRect)  self->getFrameRect(key);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((wyRect)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"wyRect");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(wyRect));
     tolua_pushusertype(tolua_S,tolua_obj,"wyRect");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getFrameRect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getFrameNames of class  wyZwoptex */
#ifndef TOLUA_DISABLE_tolua_utils_wyZwoptex_getFrameNames00
static int tolua_utils_wyZwoptex_getFrameNames00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyZwoptex",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"size_t",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyZwoptex* self = (wyZwoptex*)  tolua_tousertype(tolua_S,1,0);
  size_t* count = ((size_t*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getFrameNames'", NULL);
#endif
  {
   const char* tolua_ret = (const char*)  self->getFrameNames(count);
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getFrameNames'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getTexture of class  wyZwoptex */
#ifndef TOLUA_DISABLE_tolua_utils_wyZwoptex_getTexture00
static int tolua_utils_wyZwoptex_getTexture00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyZwoptex",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyZwoptex* self = (wyZwoptex*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getTexture'", NULL);
#endif
  {
   wyTexture2D* tolua_ret = (wyTexture2D*)  self->getTexture();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyTexture2D");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getTexture'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setTexture of class  wyZwoptex */
#ifndef TOLUA_DISABLE_tolua_utils_wyZwoptex_setTexture00
static int tolua_utils_wyZwoptex_setTexture00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyZwoptex",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyTexture2D",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyZwoptex* self = (wyZwoptex*)  tolua_tousertype(tolua_S,1,0);
  wyTexture2D* tex = ((wyTexture2D*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setTexture'", NULL);
#endif
  {
   self->setTexture(tex);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setTexture'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getInstance of class  wyZwoptexManager */
#ifndef TOLUA_DISABLE_tolua_utils_wyZwoptexManager_getInstance00
static int tolua_utils_wyZwoptexManager_getInstance00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyZwoptexManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   wyZwoptexManager* tolua_ret = (wyZwoptexManager*)  wyZwoptexManager::getInstance();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyZwoptexManager");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getInstance'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  wyZwoptexManager */
#ifndef TOLUA_DISABLE_tolua_utils_wyZwoptexManager_delete00
static int tolua_utils_wyZwoptexManager_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyZwoptexManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyZwoptexManager* self = (wyZwoptexManager*)  tolua_tousertype(tolua_S,1,0);
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

/* method: addZwoptex of class  wyZwoptexManager */
#ifndef TOLUA_DISABLE_tolua_utils_wyZwoptexManager_addZwoptex00
static int tolua_utils_wyZwoptexManager_addZwoptex00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyZwoptexManager",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,4,"wyTexture2D",1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyZwoptexManager* self = (wyZwoptexManager*)  tolua_tousertype(tolua_S,1,0);
  const char* name = ((const char*)  tolua_tostring(tolua_S,2,0));
  int resId = ((int)  tolua_tonumber(tolua_S,3,0));
  wyTexture2D* tex = ((wyTexture2D*)  tolua_tousertype(tolua_S,4,NULL));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addZwoptex'", NULL);
#endif
  {
   self->addZwoptex(name,resId,tex);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addZwoptex'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: addZwoptex of class  wyZwoptexManager */
#ifndef TOLUA_DISABLE_tolua_utils_wyZwoptexManager_addZwoptex01
static int tolua_utils_wyZwoptexManager_addZwoptex01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyZwoptexManager",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,4,1,&tolua_err) ||
     !tolua_isusertype(tolua_S,5,"wyTexture2D",1,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  wyZwoptexManager* self = (wyZwoptexManager*)  tolua_tousertype(tolua_S,1,0);
  const char* name = ((const char*)  tolua_tostring(tolua_S,2,0));
  const char* path = ((const char*)  tolua_tostring(tolua_S,3,0));
  bool isFile = ((bool)  tolua_toboolean(tolua_S,4,false));
  wyTexture2D* tex = ((wyTexture2D*)  tolua_tousertype(tolua_S,5,NULL));
  float inDensity = ((float)  tolua_tonumber(tolua_S,6,1.0f));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addZwoptex'", NULL);
#endif
  {
   self->addZwoptex(name,path,isFile,tex,inDensity);
  }
 }
 return 0;
tolua_lerror:
 return tolua_utils_wyZwoptexManager_addZwoptex00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: getZwoptex of class  wyZwoptexManager */
#ifndef TOLUA_DISABLE_tolua_utils_wyZwoptexManager_getZwoptex00
static int tolua_utils_wyZwoptexManager_getZwoptex00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyZwoptexManager",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyZwoptexManager* self = (wyZwoptexManager*)  tolua_tousertype(tolua_S,1,0);
  const char* name = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getZwoptex'", NULL);
#endif
  {
   wyZwoptex* tolua_ret = (wyZwoptex*)  self->getZwoptex(name);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyZwoptex");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getZwoptex'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: removeZwoptex of class  wyZwoptexManager */
#ifndef TOLUA_DISABLE_tolua_utils_wyZwoptexManager_removeZwoptex00
static int tolua_utils_wyZwoptexManager_removeZwoptex00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyZwoptexManager",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyZwoptexManager* self = (wyZwoptexManager*)  tolua_tousertype(tolua_S,1,0);
  const char* name = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'removeZwoptex'", NULL);
#endif
  {
   self->removeZwoptex(name);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'removeZwoptex'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: hasZwoptex of class  wyZwoptexManager */
#ifndef TOLUA_DISABLE_tolua_utils_wyZwoptexManager_hasZwoptex00
static int tolua_utils_wyZwoptexManager_hasZwoptex00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyZwoptexManager",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyZwoptexManager* self = (wyZwoptexManager*)  tolua_tousertype(tolua_S,1,0);
  const char* name = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'hasZwoptex'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->hasZwoptex(name);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'hasZwoptex'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getFrameNames of class  wyZwoptexManager */
#ifndef TOLUA_DISABLE_tolua_utils_wyZwoptexManager_getFrameNames00
static int tolua_utils_wyZwoptexManager_getFrameNames00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyZwoptexManager",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"size_t",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyZwoptexManager* self = (wyZwoptexManager*)  tolua_tousertype(tolua_S,1,0);
  const char* name = ((const char*)  tolua_tostring(tolua_S,2,0));
  size_t* count = ((size_t*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getFrameNames'", NULL);
#endif
  {
   const char* tolua_ret = (const char*)  self->getFrameNames(name,count);
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getFrameNames'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getFrameRect of class  wyZwoptexManager */
#ifndef TOLUA_DISABLE_tolua_utils_wyZwoptexManager_getFrameRect00
static int tolua_utils_wyZwoptexManager_getFrameRect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyZwoptexManager",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyZwoptexManager* self = (wyZwoptexManager*)  tolua_tousertype(tolua_S,1,0);
  const char* zwoptexName = ((const char*)  tolua_tostring(tolua_S,2,0));
  const char* frameName = ((const char*)  tolua_tostring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getFrameRect'", NULL);
#endif
  {
   wyRect tolua_ret = (wyRect)  self->getFrameRect(zwoptexName,frameName);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((wyRect)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"wyRect");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(wyRect));
     tolua_pushusertype(tolua_S,tolua_obj,"wyRect");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getFrameRect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getFrameRect of class  wyZwoptexManager */
#ifndef TOLUA_DISABLE_tolua_utils_wyZwoptexManager_getFrameRect01
static int tolua_utils_wyZwoptexManager_getFrameRect01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyZwoptexManager",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  wyZwoptexManager* self = (wyZwoptexManager*)  tolua_tousertype(tolua_S,1,0);
  const char* frameName = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getFrameRect'", NULL);
#endif
  {
   wyRect tolua_ret = (wyRect)  self->getFrameRect(frameName);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((wyRect)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"wyRect");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(wyRect));
     tolua_pushusertype(tolua_S,tolua_obj,"wyRect");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
tolua_lerror:
 return tolua_utils_wyZwoptexManager_getFrameRect00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: getZwoptexFrame of class  wyZwoptexManager */
#ifndef TOLUA_DISABLE_tolua_utils_wyZwoptexManager_getZwoptexFrame00
static int tolua_utils_wyZwoptexManager_getZwoptexFrame00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyZwoptexManager",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyZwoptexManager* self = (wyZwoptexManager*)  tolua_tousertype(tolua_S,1,0);
  const char* frameName = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getZwoptexFrame'", NULL);
#endif
  {
   wyZwoptexFrame* tolua_ret = (wyZwoptexFrame*)  self->getZwoptexFrame(frameName);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyZwoptexFrame");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getZwoptexFrame'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getZwoptexFrame of class  wyZwoptexManager */
#ifndef TOLUA_DISABLE_tolua_utils_wyZwoptexManager_getZwoptexFrame01
static int tolua_utils_wyZwoptexManager_getZwoptexFrame01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyZwoptexManager",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  wyZwoptexManager* self = (wyZwoptexManager*)  tolua_tousertype(tolua_S,1,0);
  const char* zwoptexName = ((const char*)  tolua_tostring(tolua_S,2,0));
  const char* frameName = ((const char*)  tolua_tostring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getZwoptexFrame'", NULL);
#endif
  {
   wyZwoptexFrame* tolua_ret = (wyZwoptexFrame*)  self->getZwoptexFrame(zwoptexName,frameName);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyZwoptexFrame");
  }
 }
 return 1;
tolua_lerror:
 return tolua_utils_wyZwoptexManager_getZwoptexFrame00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: getSpriteFrame of class  wyZwoptexManager */
#ifndef TOLUA_DISABLE_tolua_utils_wyZwoptexManager_getSpriteFrame00
static int tolua_utils_wyZwoptexManager_getSpriteFrame00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyZwoptexManager",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyZwoptexManager* self = (wyZwoptexManager*)  tolua_tousertype(tolua_S,1,0);
  const char* frameName = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getSpriteFrame'", NULL);
#endif
  {
   wySpriteFrame* tolua_ret = (wySpriteFrame*)  self->getSpriteFrame(frameName);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wySpriteFrame");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getSpriteFrame'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getSpriteFrame of class  wyZwoptexManager */
#ifndef TOLUA_DISABLE_tolua_utils_wyZwoptexManager_getSpriteFrame01
static int tolua_utils_wyZwoptexManager_getSpriteFrame01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyZwoptexManager",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  wyZwoptexManager* self = (wyZwoptexManager*)  tolua_tousertype(tolua_S,1,0);
  const char* zwoptexName = ((const char*)  tolua_tostring(tolua_S,2,0));
  const char* frameName = ((const char*)  tolua_tostring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getSpriteFrame'", NULL);
#endif
  {
   wySpriteFrame* tolua_ret = (wySpriteFrame*)  self->getSpriteFrame(zwoptexName,frameName);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wySpriteFrame");
  }
 }
 return 1;
tolua_lerror:
 return tolua_utils_wyZwoptexManager_getSpriteFrame00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: makeSprite of class  wyZwoptexManager */
#ifndef TOLUA_DISABLE_tolua_utils_wyZwoptexManager_makeSprite00
static int tolua_utils_wyZwoptexManager_makeSprite00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyZwoptexManager",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,4,"wyTexture2D",1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyZwoptexManager* self = (wyZwoptexManager*)  tolua_tousertype(tolua_S,1,0);
  const char* zwoptexName = ((const char*)  tolua_tostring(tolua_S,2,0));
  const char* frameName = ((const char*)  tolua_tostring(tolua_S,3,0));
  wyTexture2D* tex = ((wyTexture2D*)  tolua_tousertype(tolua_S,4,NULL));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'makeSprite'", NULL);
#endif
  {
   wySprite* tolua_ret = (wySprite*)  self->makeSprite(zwoptexName,frameName,tex);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wySprite");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'makeSprite'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: makeSprite of class  wyZwoptexManager */
#ifndef TOLUA_DISABLE_tolua_utils_wyZwoptexManager_makeSprite01
static int tolua_utils_wyZwoptexManager_makeSprite01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyZwoptexManager",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  wyZwoptexManager* self = (wyZwoptexManager*)  tolua_tousertype(tolua_S,1,0);
  const char* frameName = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'makeSprite'", NULL);
#endif
  {
   wySprite* tolua_ret = (wySprite*)  self->makeSprite(frameName);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wySprite");
  }
 }
 return 1;
tolua_lerror:
 return tolua_utils_wyZwoptexManager_makeSprite00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: makeSpriteEx of class  wyZwoptexManager */
#ifndef TOLUA_DISABLE_tolua_utils_wyZwoptexManager_makeSpriteEx00
static int tolua_utils_wyZwoptexManager_makeSpriteEx00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyZwoptexManager",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,4,"wyTexture2D",1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyZwoptexManager* self = (wyZwoptexManager*)  tolua_tousertype(tolua_S,1,0);
  const char* zwoptexName = ((const char*)  tolua_tostring(tolua_S,2,0));
  const char* frameName = ((const char*)  tolua_tostring(tolua_S,3,0));
  wyTexture2D* tex = ((wyTexture2D*)  tolua_tousertype(tolua_S,4,NULL));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'makeSpriteEx'", NULL);
#endif
  {
   wySpriteEx* tolua_ret = (wySpriteEx*)  self->makeSpriteEx(zwoptexName,frameName,tex);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wySpriteEx");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'makeSpriteEx'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: makeSpriteEx of class  wyZwoptexManager */
#ifndef TOLUA_DISABLE_tolua_utils_wyZwoptexManager_makeSpriteEx01
static int tolua_utils_wyZwoptexManager_makeSpriteEx01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyZwoptexManager",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  wyZwoptexManager* self = (wyZwoptexManager*)  tolua_tousertype(tolua_S,1,0);
  const char* frameName = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'makeSpriteEx'", NULL);
#endif
  {
   wySpriteEx* tolua_ret = (wySpriteEx*)  self->makeSpriteEx(frameName);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wySpriteEx");
  }
 }
 return 1;
tolua_lerror:
 return tolua_utils_wyZwoptexManager_makeSpriteEx00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: hasCamera of class  wyImagePicker */
#ifndef TOLUA_DISABLE_tolua_utils_wyImagePicker_hasCamera00
static int tolua_utils_wyImagePicker_hasCamera00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyImagePicker",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   bool tolua_ret = (bool)  wyImagePicker::hasCamera();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'hasCamera'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: hasFrontCamera of class  wyImagePicker */
#ifndef TOLUA_DISABLE_tolua_utils_wyImagePicker_hasFrontCamera00
static int tolua_utils_wyImagePicker_hasFrontCamera00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyImagePicker",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   bool tolua_ret = (bool)  wyImagePicker::hasFrontCamera();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'hasFrontCamera'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: pickFromCamera of class  wyImagePicker */
#ifndef TOLUA_DISABLE_tolua_utils_wyImagePicker_pickFromCamera00
static int tolua_utils_wyImagePicker_pickFromCamera00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyImagePicker",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyImagePickerCallback",0,&tolua_err) ||
     !tolua_isuserdata(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,6,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyImagePickerCallback* callback = ((wyImagePickerCallback*)  tolua_tousertype(tolua_S,2,0));
  void* data = ((void*)  tolua_touserdata(tolua_S,3,0));
  int w = ((int)  tolua_tonumber(tolua_S,4,0));
  int h = ((int)  tolua_tonumber(tolua_S,5,0));
  bool keepRatio = ((bool)  tolua_toboolean(tolua_S,6,true));
  {
   wyImagePicker::pickFromCamera(callback,data,w,h,keepRatio);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'pickFromCamera'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: pickFromFrontCamera of class  wyImagePicker */
#ifndef TOLUA_DISABLE_tolua_utils_wyImagePicker_pickFromFrontCamera00
static int tolua_utils_wyImagePicker_pickFromFrontCamera00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyImagePicker",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyImagePickerCallback",0,&tolua_err) ||
     !tolua_isuserdata(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,6,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyImagePickerCallback* callback = ((wyImagePickerCallback*)  tolua_tousertype(tolua_S,2,0));
  void* data = ((void*)  tolua_touserdata(tolua_S,3,0));
  int w = ((int)  tolua_tonumber(tolua_S,4,0));
  int h = ((int)  tolua_tonumber(tolua_S,5,0));
  bool keepRatio = ((bool)  tolua_toboolean(tolua_S,6,true));
  {
   wyImagePicker::pickFromFrontCamera(callback,data,w,h,keepRatio);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'pickFromFrontCamera'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: pickFromAlbum of class  wyImagePicker */
#ifndef TOLUA_DISABLE_tolua_utils_wyImagePicker_pickFromAlbum00
static int tolua_utils_wyImagePicker_pickFromAlbum00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyImagePicker",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyImagePickerCallback",0,&tolua_err) ||
     !tolua_isuserdata(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,6,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyImagePickerCallback* callback = ((wyImagePickerCallback*)  tolua_tousertype(tolua_S,2,0));
  void* data = ((void*)  tolua_touserdata(tolua_S,3,0));
  int w = ((int)  tolua_tonumber(tolua_S,4,0));
  int h = ((int)  tolua_tonumber(tolua_S,5,0));
  bool keepRatio = ((bool)  tolua_toboolean(tolua_S,6,true));
  {
   wyImagePicker::pickFromAlbum(callback,data,w,h,keepRatio);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'pickFromAlbum'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getNextPOT of class  wyMath */
#ifndef TOLUA_DISABLE_tolua_utils_wyMath_getNextPOT00
static int tolua_utils_wyMath_getNextPOT00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyMath",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  int x = ((int)  tolua_tonumber(tolua_S,2,0));
  {
   int tolua_ret = (int)  wyMath::getNextPOT(x);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getNextPOT'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: d2r of class  wyMath */
#ifndef TOLUA_DISABLE_tolua_utils_wyMath_d2r00
static int tolua_utils_wyMath_d2r00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyMath",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float degree = ((float)  tolua_tonumber(tolua_S,2,0));
  {
   float tolua_ret = (float)  wyMath::d2r(degree);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'd2r'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: r2d of class  wyMath */
#ifndef TOLUA_DISABLE_tolua_utils_wyMath_r2d00
static int tolua_utils_wyMath_r2d00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyMath",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float radian = ((float)  tolua_tonumber(tolua_S,2,0));
  {
   float tolua_ret = (float)  wyMath::r2d(radian);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'r2d'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: randMinusOneToOne of class  wyMath */
#ifndef TOLUA_DISABLE_tolua_utils_wyMath_randMinusOneToOne00
static int tolua_utils_wyMath_randMinusOneToOne00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyMath",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   float tolua_ret = (float)  wyMath::randMinusOneToOne();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'randMinusOneToOne'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: randMax of class  wyMath */
#ifndef TOLUA_DISABLE_tolua_utils_wyMath_randMax00
static int tolua_utils_wyMath_randMax00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyMath",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  int max = ((int)  tolua_tonumber(tolua_S,2,0));
  {
   int tolua_ret = (int)  wyMath::randMax(max);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'randMax'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isIntersected of class  wyMath */
#ifndef TOLUA_DISABLE_tolua_utils_wyMath_isIntersected00
static int tolua_utils_wyMath_isIntersected00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyMath",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"wyPoint",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"wyPoint",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"wyPoint",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,5,&tolua_err) || !tolua_isusertype(tolua_S,5,"wyPoint",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyPoint p1 = *((wyPoint*)  tolua_tousertype(tolua_S,2,0));
  wyPoint p2 = *((wyPoint*)  tolua_tousertype(tolua_S,3,0));
  wyPoint q1 = *((wyPoint*)  tolua_tousertype(tolua_S,4,0));
  wyPoint q2 = *((wyPoint*)  tolua_tousertype(tolua_S,5,0));
  {
   bool tolua_ret = (bool)  wyMath::isIntersected(p1,p2,q1,q2);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isIntersected'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: cyclic of class  wyMath */
#ifndef TOLUA_DISABLE_tolua_utils_wyMath_cyclic00
static int tolua_utils_wyMath_cyclic00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyMath",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float value = ((float)  tolua_tonumber(tolua_S,2,0));
  float period = ((float)  tolua_tonumber(tolua_S,3,0));
  {
   float tolua_ret = (float)  wyMath::cyclic(value,period);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'cyclic'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: cyclicDifference of class  wyMath */
#ifndef TOLUA_DISABLE_tolua_utils_wyMath_cyclicDifference00
static int tolua_utils_wyMath_cyclicDifference00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyMath",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float minuend = ((float)  tolua_tonumber(tolua_S,2,0));
  float subtrahend = ((float)  tolua_tonumber(tolua_S,3,0));
  float period = ((float)  tolua_tonumber(tolua_S,4,0));
  {
   float tolua_ret = (float)  wyMath::cyclicDifference(minuend,subtrahend,period);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'cyclicDifference'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_utils_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  tolua_constant(tolua_S,"wyTexture2D::LEFT",wyTexture2D::LEFT);
  tolua_constant(tolua_S,"wyTexture2D::CENTER",wyTexture2D::CENTER);
  tolua_constant(tolua_S,"wyTexture2D::RIGHT",wyTexture2D::RIGHT);
  tolua_constant(tolua_S,"NORMAL",NORMAL);
  tolua_constant(tolua_S,"BOLD",BOLD);
  tolua_constant(tolua_S,"ITALIC",ITALIC);
  tolua_constant(tolua_S,"BOLD_ITALIC",BOLD_ITALIC);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyAssetOutputStream","wyAssetOutputStream","wyObject",tolua_collect_wyAssetOutputStream);
  #else
  tolua_cclass(tolua_S,"wyAssetOutputStream","wyAssetOutputStream","wyObject",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyAssetOutputStream");
   tolua_function(tolua_S,"make",tolua_utils_wyAssetOutputStream_make00);
   tolua_function(tolua_S,"delete",tolua_utils_wyAssetOutputStream_delete00);
   tolua_function(tolua_S,"open",tolua_utils_wyAssetOutputStream_open00);
   tolua_function(tolua_S,"close",tolua_utils_wyAssetOutputStream_close00);
   tolua_function(tolua_S,"write",tolua_utils_wyAssetOutputStream_write00);
   tolua_function(tolua_S,"write",tolua_utils_wyAssetOutputStream_write01);
   tolua_function(tolua_S,"getPosition",tolua_utils_wyAssetOutputStream_getPosition00);
   tolua_function(tolua_S,"seek",tolua_utils_wyAssetOutputStream_seek00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyAssetInputStream","wyAssetInputStream","wyObject",tolua_collect_wyAssetInputStream);
  #else
  tolua_cclass(tolua_S,"wyAssetInputStream","wyAssetInputStream","wyObject",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyAssetInputStream");
   tolua_function(tolua_S,"make",tolua_utils_wyAssetInputStream_make00);
   tolua_function(tolua_S,"make",tolua_utils_wyAssetInputStream_make01);
   tolua_function(tolua_S,"delete",tolua_utils_wyAssetInputStream_delete00);
   tolua_function(tolua_S,"getBuffer",tolua_utils_wyAssetInputStream_getBuffer00);
   tolua_function(tolua_S,"getPosition",tolua_utils_wyAssetInputStream_getPosition00);
   tolua_function(tolua_S,"getLength",tolua_utils_wyAssetInputStream_getLength00);
   tolua_function(tolua_S,"available",tolua_utils_wyAssetInputStream_available00);
   tolua_function(tolua_S,"open",tolua_utils_wyAssetInputStream_open00);
   tolua_function(tolua_S,"close",tolua_utils_wyAssetInputStream_close00);
   tolua_function(tolua_S,"read",tolua_utils_wyAssetInputStream_read00);
   tolua_function(tolua_S,"readByte",tolua_utils_wyAssetInputStream_readByte00);
   tolua_function(tolua_S,"readShort",tolua_utils_wyAssetInputStream_readShort00);
   tolua_function(tolua_S,"readInt",tolua_utils_wyAssetInputStream_readInt00);
   tolua_function(tolua_S,"readInt64",tolua_utils_wyAssetInputStream_readInt6400);
   tolua_function(tolua_S,"seek",tolua_utils_wyAssetInputStream_seek00);
   tolua_function(tolua_S,"setBigEndian",tolua_utils_wyAssetInputStream_setBigEndian00);
   tolua_function(tolua_S,"isBigEndian",tolua_utils_wyAssetInputStream_isBigEndian00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"wyMD5","wyMD5","",NULL);
  tolua_beginmodule(tolua_S,"wyMD5");
   tolua_function(tolua_S,"md5",tolua_utils_wyMD5_md500);
   tolua_function(tolua_S,"md5",tolua_utils_wyMD5_md501);
  tolua_endmodule(tolua_S);
  tolua_function(tolua_S,"wyRecordTime",tolua_utils_wyRecordTime00);
  tolua_function(tolua_S,"wyOutputTime",tolua_utils_wyOutputTime00);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyRunnable","wyRunnable","wyObject",tolua_collect_wyRunnable);
  #else
  tolua_cclass(tolua_S,"wyRunnable","wyRunnable","wyObject",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyRunnable");
   tolua_function(tolua_S,"delete",tolua_utils_wyRunnable_delete00);
   tolua_function(tolua_S,"run",tolua_utils_wyRunnable_run00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyScroller","wyScroller","wyObject",tolua_collect_wyScroller);
  #else
  tolua_cclass(tolua_S,"wyScroller","wyScroller","wyObject",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyScroller");
   tolua_function(tolua_S,"make",tolua_utils_wyScroller_make00);
   tolua_function(tolua_S,"new",tolua_utils_wyScroller_new00);
   tolua_function(tolua_S,"new_local",tolua_utils_wyScroller_new00_local);
   tolua_function(tolua_S,".call",tolua_utils_wyScroller_new00_local);
   tolua_function(tolua_S,"delete",tolua_utils_wyScroller_delete00);
   tolua_function(tolua_S,"isFinished",tolua_utils_wyScroller_isFinished00);
   tolua_function(tolua_S,"forceFinished",tolua_utils_wyScroller_forceFinished00);
   tolua_function(tolua_S,"getDuration",tolua_utils_wyScroller_getDuration00);
   tolua_function(tolua_S,"getCurrX",tolua_utils_wyScroller_getCurrX00);
   tolua_function(tolua_S,"getCurrY",tolua_utils_wyScroller_getCurrY00);
   tolua_function(tolua_S,"getCurrVelocity",tolua_utils_wyScroller_getCurrVelocity00);
   tolua_function(tolua_S,"getStartX",tolua_utils_wyScroller_getStartX00);
   tolua_function(tolua_S,"getStartY",tolua_utils_wyScroller_getStartY00);
   tolua_function(tolua_S,"getFinalX",tolua_utils_wyScroller_getFinalX00);
   tolua_function(tolua_S,"getFinalY",tolua_utils_wyScroller_getFinalY00);
   tolua_function(tolua_S,"computeScrollOffset",tolua_utils_wyScroller_computeScrollOffset00);
   tolua_function(tolua_S,"startScroll",tolua_utils_wyScroller_startScroll00);
   tolua_function(tolua_S,"startScroll",tolua_utils_wyScroller_startScroll01);
   tolua_function(tolua_S,"fling",tolua_utils_wyScroller_fling00);
   tolua_function(tolua_S,"abortAnimation",tolua_utils_wyScroller_abortAnimation00);
   tolua_function(tolua_S,"extendDuration",tolua_utils_wyScroller_extendDuration00);
   tolua_function(tolua_S,"timePassed",tolua_utils_wyScroller_timePassed00);
   tolua_function(tolua_S,"setFinalX",tolua_utils_wyScroller_setFinalX00);
   tolua_function(tolua_S,"setFinalY",tolua_utils_wyScroller_setFinalY00);
   tolua_function(tolua_S,"setScrollFriction",tolua_utils_wyScroller_setScrollFriction00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyTargetSelector","wyTargetSelector","wyObject",tolua_collect_wyTargetSelector);
  #else
  tolua_cclass(tolua_S,"wyTargetSelector","wyTargetSelector","wyObject",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyTargetSelector");
   tolua_function(tolua_S,"make_v",tolua_utils_wyTargetSelector_make_v00);
   tolua_function(tolua_S,"make_i",tolua_utils_wyTargetSelector_make_i00);
   tolua_function(tolua_S,"make_f",tolua_utils_wyTargetSelector_make_f00);
   tolua_function(tolua_S,"make_p",tolua_utils_wyTargetSelector_make_p00);
   tolua_function(tolua_S,"delete",tolua_utils_wyTargetSelector_delete00);
   tolua_function(tolua_S,"setDelta",tolua_utils_wyTargetSelector_setDelta00);
   tolua_function(tolua_S,"invoke",tolua_utils_wyTargetSelector_invoke00);
   tolua_function(tolua_S,"getTarget",tolua_utils_wyTargetSelector_getTarget00);
   tolua_function(tolua_S,"getId",tolua_utils_wyTargetSelector_getId00);
   tolua_function(tolua_S,"setId",tolua_utils_wyTargetSelector_setId00);
   tolua_function(tolua_S,"getDelta",tolua_utils_wyTargetSelector_getDelta00);
  tolua_endmodule(tolua_S);
  tolua_function(tolua_S,"wyTargetSelectorEquals",tolua_utils_wyTargetSelectorEquals00);
  tolua_constant(tolua_S,"TGA_OK",TGA_OK);
  tolua_constant(tolua_S,"TGA_ERROR_FILE_OPEN",TGA_ERROR_FILE_OPEN);
  tolua_constant(tolua_S,"TGA_ERROR_READING_FILE",TGA_ERROR_READING_FILE);
  tolua_constant(tolua_S,"TGA_ERROR_INDEXED_COLOR",TGA_ERROR_INDEXED_COLOR);
  tolua_constant(tolua_S,"TGA_ERROR_MEMORY",TGA_ERROR_MEMORY);
  tolua_constant(tolua_S,"TGA_ERROR_COMPRESSED_FILE",TGA_ERROR_COMPRESSED_FILE);
  tolua_cclass(tolua_S,"wyTGA","wyTGA","",NULL);
  tolua_beginmodule(tolua_S,"wyTGA");
   tolua_variable(tolua_S,"status",tolua_get_wyTGA_status,tolua_set_wyTGA_status);
   tolua_variable(tolua_S,"type",tolua_get_wyTGA_type,tolua_set_wyTGA_type);
   tolua_variable(tolua_S,"pixelDepth",tolua_get_wyTGA_pixelDepth,tolua_set_wyTGA_pixelDepth);
   tolua_variable(tolua_S,"bytesPerPixel",tolua_get_wyTGA_bytesPerPixel,tolua_set_wyTGA_bytesPerPixel);
   tolua_variable(tolua_S,"width",tolua_get_wyTGA_width,tolua_set_wyTGA_width);
   tolua_variable(tolua_S,"height",tolua_get_wyTGA_height,tolua_set_wyTGA_height);
   tolua_variable(tolua_S,"imageData",tolua_get_wyTGA_imageData,tolua_set_wyTGA_imageData);
   tolua_variable(tolua_S,"flipped",tolua_get_wyTGA_flipped,tolua_set_wyTGA_flipped);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"wyTGALoader","wyTGALoader","",NULL);
  tolua_beginmodule(tolua_S,"wyTGALoader");
   tolua_function(tolua_S,"load",tolua_utils_wyTGALoader_load00);
   tolua_function(tolua_S,"load",tolua_utils_wyTGALoader_load01);
   tolua_function(tolua_S,"destroyTGA",tolua_utils_wyTGALoader_destroyTGA00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"wyBezierConfig","wyBezierConfig","",NULL);
  tolua_beginmodule(tolua_S,"wyBezierConfig");
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"wyQuad2D","wyQuad2D","",NULL);
  tolua_beginmodule(tolua_S,"wyQuad2D");
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"wyQuad3D","wyQuad3D","",NULL);
  tolua_beginmodule(tolua_S,"wyQuad3D");
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"wyColor4B","wyColor4B","",NULL);
  tolua_beginmodule(tolua_S,"wyColor4B");
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyRect","wyRect","",tolua_collect_wyRect);
  #else
  tolua_cclass(tolua_S,"wyRect","wyRect","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyRect");
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"wyAffineTransform","wyAffineTransform","",NULL);
  tolua_beginmodule(tolua_S,"wyAffineTransform");
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyPoint","wyPoint","",tolua_collect_wyPoint);
  #else
  tolua_cclass(tolua_S,"wyPoint","wyPoint","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyPoint");
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"wyKeyEvent","wyKeyEvent","",NULL);
  tolua_beginmodule(tolua_S,"wyKeyEvent");
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"wyMotionEvent","wyMotionEvent","",NULL);
  tolua_beginmodule(tolua_S,"wyMotionEvent");
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"wyUtils","wyUtils","",NULL);
  tolua_beginmodule(tolua_S,"wyUtils");
   tolua_function(tolua_S,"getResId",tolua_utils_wyUtils_getResId00);
   tolua_function(tolua_S,"getResId",tolua_utils_wyUtils_getResId01);
   tolua_function(tolua_S,"getString",tolua_utils_wyUtils_getString00);
   tolua_function(tolua_S,"getString",tolua_utils_wyUtils_getString01);
   tolua_function(tolua_S,"getString16",tolua_utils_wyUtils_getString1600);
   tolua_function(tolua_S,"getString16",tolua_utils_wyUtils_getString1601);
   tolua_function(tolua_S,"loadRaw",tolua_utils_wyUtils_loadRaw00);
   tolua_function(tolua_S,"loadRaw",tolua_utils_wyUtils_loadRaw01);
   tolua_function(tolua_S,"loadRaw",tolua_utils_wyUtils_loadRaw02);
   tolua_function(tolua_S,"loadCString",tolua_utils_wyUtils_loadCString00);
   tolua_function(tolua_S,"loadCString",tolua_utils_wyUtils_loadCString01);
   tolua_function(tolua_S,"getPVRSize",tolua_utils_wyUtils_getPVRSize00);
   tolua_function(tolua_S,"getPVRSize",tolua_utils_wyUtils_getPVRSize01);
   tolua_function(tolua_S,"getPVRSize",tolua_utils_wyUtils_getPVRSize02);
   tolua_function(tolua_S,"getPVRSize",tolua_utils_wyUtils_getPVRSize03);
   tolua_function(tolua_S,"convertPVRHeaderEndian",tolua_utils_wyUtils_convertPVRHeaderEndian00);
   tolua_function(tolua_S,"scalePVR",tolua_utils_wyUtils_scalePVR00);
   tolua_function(tolua_S,"canScalePVR",tolua_utils_wyUtils_canScalePVR00);
   tolua_function(tolua_S,"scaleImage",tolua_utils_wyUtils_scaleImage00);
   tolua_function(tolua_S,"convertToGL",tolua_utils_wyUtils_convertToGL00);
   tolua_function(tolua_S,"convertToGL",tolua_utils_wyUtils_convertToGL01);
   tolua_function(tolua_S,"currentTimeMillis",tolua_utils_wyUtils_currentTimeMillis00);
   tolua_function(tolua_S,"swap",tolua_utils_wyUtils_swap00);
   tolua_function(tolua_S,"binarySearch",tolua_utils_wyUtils_binarySearch00);
   tolua_function(tolua_S,"encodeBase64",tolua_utils_wyUtils_encodeBase6400);
   tolua_function(tolua_S,"decodeBase64",tolua_utils_wyUtils_decodeBase6400);
   tolua_function(tolua_S,"gunzip",tolua_utils_wyUtils_gunzip00);
   tolua_function(tolua_S,"replaceChar",tolua_utils_wyUtils_replaceChar00);
   tolua_function(tolua_S,"readLine",tolua_utils_wyUtils_readLine00);
   tolua_function(tolua_S,"startsWith",tolua_utils_wyUtils_startsWith00);
   tolua_function(tolua_S,"endsWith",tolua_utils_wyUtils_endsWith00);
   tolua_function(tolua_S,"utf16toutf8",tolua_utils_wyUtils_utf16toutf800);
   tolua_function(tolua_S,"utf32toutf8",tolua_utils_wyUtils_utf32toutf800);
   tolua_function(tolua_S,"toUTF16",tolua_utils_wyUtils_toUTF1600);
   tolua_function(tolua_S,"strlen16",tolua_utils_wyUtils_strlen1600);
   tolua_function(tolua_S,"str16str",tolua_utils_wyUtils_str16str00);
   tolua_function(tolua_S,"strlen8",tolua_utils_wyUtils_strlen800);
   tolua_function(tolua_S,"getUTF8Bytes",tolua_utils_wyUtils_getUTF8Bytes00);
   tolua_function(tolua_S,"trim",tolua_utils_wyUtils_trim00);
   tolua_function(tolua_S,"isEmpty",tolua_utils_wyUtils_isEmpty00);
   tolua_function(tolua_S,"copy",tolua_utils_wyUtils_copy00);
   tolua_function(tolua_S,"copy",tolua_utils_wyUtils_copy01);
   tolua_function(tolua_S,"strHash",tolua_utils_wyUtils_strHash00);
   tolua_function(tolua_S,"resolveDp",tolua_utils_wyUtils_resolveDp00);
   tolua_function(tolua_S,"resolveSp",tolua_utils_wyUtils_resolveSp00);
   tolua_function(tolua_S,"resolvePx",tolua_utils_wyUtils_resolvePx00);
   tolua_function(tolua_S,"resolveRect",tolua_utils_wyUtils_resolveRect00);
   tolua_function(tolua_S,"resolvePoint",tolua_utils_wyUtils_resolvePoint00);
   tolua_function(tolua_S,"calculateTextSize",tolua_utils_wyUtils_calculateTextSize00);
   tolua_function(tolua_S,"calculateTextSize",tolua_utils_wyUtils_calculateTextSize01);
   tolua_function(tolua_S,"createLabelBitmap",tolua_utils_wyUtils_createLabelBitmap00);
   tolua_function(tolua_S,"createLabelBitmap",tolua_utils_wyUtils_createLabelBitmap01);
   tolua_function(tolua_S,"makeScreenshot",tolua_utils_wyUtils_makeScreenshot00);
   tolua_function(tolua_S,"makeScreenshot",tolua_utils_wyUtils_makeScreenshot01);
   tolua_function(tolua_S,"getFileSize",tolua_utils_wyUtils_getFileSize00);
   tolua_function(tolua_S,"getParentPath",tolua_utils_wyUtils_getParentPath00);
   tolua_function(tolua_S,"isPathExistent",tolua_utils_wyUtils_isPathExistent00);
   tolua_function(tolua_S,"deleteFile",tolua_utils_wyUtils_deleteFile00);
   tolua_function(tolua_S,"createIntermediateFolders",tolua_utils_wyUtils_createIntermediateFolders00);
   tolua_function(tolua_S,"deleteLastPathComponent",tolua_utils_wyUtils_deleteLastPathComponent00);
   tolua_function(tolua_S,"appendPathComponent",tolua_utils_wyUtils_appendPathComponent00);
   tolua_function(tolua_S,"lastPathComponent",tolua_utils_wyUtils_lastPathComponent00);
   tolua_function(tolua_S,"mapLocalPath",tolua_utils_wyUtils_mapLocalPath00);
   tolua_function(tolua_S,"mapAssetsPath",tolua_utils_wyUtils_mapAssetsPath00);
   tolua_function(tolua_S,"runOnGLThread",tolua_utils_wyUtils_runOnGLThread00);
   tolua_function(tolua_S,"playVideo",tolua_utils_wyUtils_playVideo00);
   tolua_function(tolua_S,"playVideo",tolua_utils_wyUtils_playVideo01);
   tolua_function(tolua_S,"openUrl",tolua_utils_wyUtils_openUrl00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyVerletPoint","wyVerletPoint","wyObject",tolua_collect_wyVerletPoint);
  #else
  tolua_cclass(tolua_S,"wyVerletPoint","wyVerletPoint","wyObject",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyVerletPoint");
   tolua_function(tolua_S,"new",tolua_utils_wyVerletPoint_new00);
   tolua_function(tolua_S,"new_local",tolua_utils_wyVerletPoint_new00_local);
   tolua_function(tolua_S,".call",tolua_utils_wyVerletPoint_new00_local);
   tolua_function(tolua_S,"delete",tolua_utils_wyVerletPoint_delete00);
   tolua_function(tolua_S,"setPosition",tolua_utils_wyVerletPoint_setPosition00);
   tolua_function(tolua_S,"update",tolua_utils_wyVerletPoint_update00);
   tolua_function(tolua_S,"applyGravity",tolua_utils_wyVerletPoint_applyGravity00);
   tolua_function(tolua_S,"setX",tolua_utils_wyVerletPoint_setX00);
   tolua_function(tolua_S,"setY",tolua_utils_wyVerletPoint_setY00);
   tolua_function(tolua_S,"getX",tolua_utils_wyVerletPoint_getX00);
   tolua_function(tolua_S,"getY",tolua_utils_wyVerletPoint_getY00);
   tolua_function(tolua_S,"attenuate",tolua_utils_wyVerletPoint_attenuate00);
   tolua_function(tolua_S,"copy",tolua_utils_wyVerletPoint_copy00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyVerletRope","wyVerletRope","wyObject",tolua_collect_wyVerletRope);
  #else
  tolua_cclass(tolua_S,"wyVerletRope","wyVerletRope","wyObject",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyVerletRope");
   tolua_function(tolua_S,"new",tolua_utils_wyVerletRope_new00);
   tolua_function(tolua_S,"new_local",tolua_utils_wyVerletRope_new00_local);
   tolua_function(tolua_S,".call",tolua_utils_wyVerletRope_new00_local);
   tolua_function(tolua_S,"delete",tolua_utils_wyVerletRope_delete00);
   tolua_function(tolua_S,"reset",tolua_utils_wyVerletRope_reset00);
   tolua_function(tolua_S,"update",tolua_utils_wyVerletRope_update00);
   tolua_function(tolua_S,"getSticks",tolua_utils_wyVerletRope_getSticks00);
   tolua_function(tolua_S,"getStickAt",tolua_utils_wyVerletRope_getStickAt00);
   tolua_function(tolua_S,"getStickCount",tolua_utils_wyVerletRope_getStickCount00);
   tolua_function(tolua_S,"getPoints",tolua_utils_wyVerletRope_getPoints00);
   tolua_function(tolua_S,"getPointAt",tolua_utils_wyVerletRope_getPointAt00);
   tolua_function(tolua_S,"getPointCount",tolua_utils_wyVerletRope_getPointCount00);
   tolua_function(tolua_S,"getCurrentLength",tolua_utils_wyVerletRope_getCurrentLength00);
   tolua_function(tolua_S,"rayCast",tolua_utils_wyVerletRope_rayCast00);
   tolua_function(tolua_S,"getColor",tolua_utils_wyVerletRope_getColor00);
   tolua_function(tolua_S,"setColor",tolua_utils_wyVerletRope_setColor00);
   tolua_function(tolua_S,"setColor",tolua_utils_wyVerletRope_setColor01);
   tolua_function(tolua_S,"getAlpha",tolua_utils_wyVerletRope_getAlpha00);
   tolua_function(tolua_S,"setAlpha",tolua_utils_wyVerletRope_setAlpha00);
   tolua_function(tolua_S,"getLength",tolua_utils_wyVerletRope_getLength00);
   tolua_function(tolua_S,"subRope",tolua_utils_wyVerletRope_subRope00);
   tolua_function(tolua_S,"isStretched",tolua_utils_wyVerletRope_isStretched00);
   tolua_function(tolua_S,"changeLength",tolua_utils_wyVerletRope_changeLength00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyVerletStick","wyVerletStick","wyObject",tolua_collect_wyVerletStick);
  #else
  tolua_cclass(tolua_S,"wyVerletStick","wyVerletStick","wyObject",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyVerletStick");
   tolua_function(tolua_S,"new",tolua_utils_wyVerletStick_new00);
   tolua_function(tolua_S,"new_local",tolua_utils_wyVerletStick_new00_local);
   tolua_function(tolua_S,".call",tolua_utils_wyVerletStick_new00_local);
   tolua_function(tolua_S,"delete",tolua_utils_wyVerletStick_delete00);
   tolua_function(tolua_S,"contract",tolua_utils_wyVerletStick_contract00);
   tolua_function(tolua_S,"getPointA",tolua_utils_wyVerletStick_getPointA00);
   tolua_function(tolua_S,"getPointB",tolua_utils_wyVerletStick_getPointB00);
   tolua_function(tolua_S,"getLength",tolua_utils_wyVerletStick_getLength00);
   tolua_function(tolua_S,"getCurrentLength",tolua_utils_wyVerletStick_getCurrentLength00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyZwoptexFrame","wyZwoptexFrame","wyObject",tolua_collect_wyZwoptexFrame);
  #else
  tolua_cclass(tolua_S,"wyZwoptexFrame","wyZwoptexFrame","wyObject",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyZwoptexFrame");
   tolua_variable(tolua_S,"key",tolua_get_wyZwoptexFrame_key,NULL);
   tolua_variable(tolua_S,"rect",tolua_get_wyZwoptexFrame_rect,tolua_set_wyZwoptexFrame_rect);
   tolua_variable(tolua_S,"sourceColorRect",tolua_get_wyZwoptexFrame_sourceColorRect,tolua_set_wyZwoptexFrame_sourceColorRect);
   tolua_variable(tolua_S,"offset",tolua_get_wyZwoptexFrame_offset,tolua_set_wyZwoptexFrame_offset);
   tolua_variable(tolua_S,"sourceSize",tolua_get_wyZwoptexFrame_sourceSize,tolua_set_wyZwoptexFrame_sourceSize);
   tolua_variable(tolua_S,"rotated",tolua_get_wyZwoptexFrame_rotated,tolua_set_wyZwoptexFrame_rotated);
   tolua_function(tolua_S,"new",tolua_utils_wyZwoptexFrame_new00);
   tolua_function(tolua_S,"new_local",tolua_utils_wyZwoptexFrame_new00_local);
   tolua_function(tolua_S,".call",tolua_utils_wyZwoptexFrame_new00_local);
   tolua_function(tolua_S,"delete",tolua_utils_wyZwoptexFrame_delete00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyZwoptex","wyZwoptex","wyObject",tolua_collect_wyZwoptex);
  #else
  tolua_cclass(tolua_S,"wyZwoptex","wyZwoptex","wyObject",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyZwoptex");
   tolua_function(tolua_S,"new",tolua_utils_wyZwoptex_new00);
   tolua_function(tolua_S,"new_local",tolua_utils_wyZwoptex_new00_local);
   tolua_function(tolua_S,".call",tolua_utils_wyZwoptex_new00_local);
   tolua_function(tolua_S,"new",tolua_utils_wyZwoptex_new01);
   tolua_function(tolua_S,"new_local",tolua_utils_wyZwoptex_new01_local);
   tolua_function(tolua_S,".call",tolua_utils_wyZwoptex_new01_local);
   tolua_function(tolua_S,"delete",tolua_utils_wyZwoptex_delete00);
   tolua_function(tolua_S,"getFormat",tolua_utils_wyZwoptex_getFormat00);
   tolua_function(tolua_S,"getSize",tolua_utils_wyZwoptex_getSize00);
   tolua_function(tolua_S,"addFrame",tolua_utils_wyZwoptex_addFrame00);
   tolua_function(tolua_S,"getFrame",tolua_utils_wyZwoptex_getFrame00);
   tolua_function(tolua_S,"getSpriteFrame",tolua_utils_wyZwoptex_getSpriteFrame00);
   tolua_function(tolua_S,"getFrameRect",tolua_utils_wyZwoptex_getFrameRect00);
   tolua_function(tolua_S,"getFrameNames",tolua_utils_wyZwoptex_getFrameNames00);
   tolua_function(tolua_S,"getTexture",tolua_utils_wyZwoptex_getTexture00);
   tolua_function(tolua_S,"setTexture",tolua_utils_wyZwoptex_setTexture00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyZwoptexManager","wyZwoptexManager","wyObject",tolua_collect_wyZwoptexManager);
  #else
  tolua_cclass(tolua_S,"wyZwoptexManager","wyZwoptexManager","wyObject",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyZwoptexManager");
   tolua_function(tolua_S,"getInstance",tolua_utils_wyZwoptexManager_getInstance00);
   tolua_function(tolua_S,"delete",tolua_utils_wyZwoptexManager_delete00);
   tolua_function(tolua_S,"addZwoptex",tolua_utils_wyZwoptexManager_addZwoptex00);
   tolua_function(tolua_S,"addZwoptex",tolua_utils_wyZwoptexManager_addZwoptex01);
   tolua_function(tolua_S,"getZwoptex",tolua_utils_wyZwoptexManager_getZwoptex00);
   tolua_function(tolua_S,"removeZwoptex",tolua_utils_wyZwoptexManager_removeZwoptex00);
   tolua_function(tolua_S,"hasZwoptex",tolua_utils_wyZwoptexManager_hasZwoptex00);
   tolua_function(tolua_S,"getFrameNames",tolua_utils_wyZwoptexManager_getFrameNames00);
   tolua_function(tolua_S,"getFrameRect",tolua_utils_wyZwoptexManager_getFrameRect00);
   tolua_function(tolua_S,"getFrameRect",tolua_utils_wyZwoptexManager_getFrameRect01);
   tolua_function(tolua_S,"getZwoptexFrame",tolua_utils_wyZwoptexManager_getZwoptexFrame00);
   tolua_function(tolua_S,"getZwoptexFrame",tolua_utils_wyZwoptexManager_getZwoptexFrame01);
   tolua_function(tolua_S,"getSpriteFrame",tolua_utils_wyZwoptexManager_getSpriteFrame00);
   tolua_function(tolua_S,"getSpriteFrame",tolua_utils_wyZwoptexManager_getSpriteFrame01);
   tolua_function(tolua_S,"makeSprite",tolua_utils_wyZwoptexManager_makeSprite00);
   tolua_function(tolua_S,"makeSprite",tolua_utils_wyZwoptexManager_makeSprite01);
   tolua_function(tolua_S,"makeSpriteEx",tolua_utils_wyZwoptexManager_makeSpriteEx00);
   tolua_function(tolua_S,"makeSpriteEx",tolua_utils_wyZwoptexManager_makeSpriteEx01);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"wyImagePickerCallback","wyImagePickerCallback","",NULL);
  tolua_beginmodule(tolua_S,"wyImagePickerCallback");
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"wyImagePicker","wyImagePicker","",NULL);
  tolua_beginmodule(tolua_S,"wyImagePicker");
   tolua_function(tolua_S,"hasCamera",tolua_utils_wyImagePicker_hasCamera00);
   tolua_function(tolua_S,"hasFrontCamera",tolua_utils_wyImagePicker_hasFrontCamera00);
   tolua_function(tolua_S,"pickFromCamera",tolua_utils_wyImagePicker_pickFromCamera00);
   tolua_function(tolua_S,"pickFromFrontCamera",tolua_utils_wyImagePicker_pickFromFrontCamera00);
   tolua_function(tolua_S,"pickFromAlbum",tolua_utils_wyImagePicker_pickFromAlbum00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"wyMath","wyMath","",NULL);
  tolua_beginmodule(tolua_S,"wyMath");
   tolua_function(tolua_S,"getNextPOT",tolua_utils_wyMath_getNextPOT00);
   tolua_function(tolua_S,"d2r",tolua_utils_wyMath_d2r00);
   tolua_function(tolua_S,"r2d",tolua_utils_wyMath_r2d00);
   tolua_function(tolua_S,"randMinusOneToOne",tolua_utils_wyMath_randMinusOneToOne00);
   tolua_function(tolua_S,"randMax",tolua_utils_wyMath_randMax00);
   tolua_function(tolua_S,"isIntersected",tolua_utils_wyMath_isIntersected00);
   tolua_function(tolua_S,"cyclic",tolua_utils_wyMath_cyclic00);
   tolua_function(tolua_S,"cyclicDifference",tolua_utils_wyMath_cyclicDifference00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_utils (lua_State* tolua_S) {
 return tolua_utils_open(tolua_S);
};
#endif

