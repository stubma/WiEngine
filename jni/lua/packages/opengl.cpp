/*
** Lua binding: opengl
** Generated automatically by tolua++-1.0.92 on Tue Jan 15 13:50:51 2013.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_opengl_open (lua_State* tolua_S);

#include "WiEngine.h"

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_wyGLTexture2D (lua_State* tolua_S)
{
 wyGLTexture2D* self = (wyGLTexture2D*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyTextureAtlas (lua_State* tolua_S)
{
 wyTextureAtlas* self = (wyTextureAtlas*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyCamera (lua_State* tolua_S)
{
 wyCamera* self = (wyCamera*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyTexture2D (lua_State* tolua_S)
{
 wyTexture2D* self = (wyTexture2D*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyTextureManager (lua_State* tolua_S)
{
 wyTextureManager* self = (wyTextureManager*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"wyLagrangeConfig");
 tolua_usertype(tolua_S,"wyGLTexture2D");
 tolua_usertype(tolua_S,"wyCamera");
 tolua_usertype(tolua_S,"wyFontStyle");
 tolua_usertype(tolua_S,"wyTextureAtlas");
 tolua_usertype(tolua_S,"wyTextureManager");
 tolua_usertype(tolua_S,"wyTexture2D");
 tolua_usertype(tolua_S,"size_t");
 tolua_usertype(tolua_S,"wyQuad2D");
 tolua_usertype(tolua_S,"wyColor4B");
 tolua_usertype(tolua_S,"wyBezierConfig");
 tolua_usertype(tolua_S,"wyQuad3D");
 tolua_usertype(tolua_S,"wyEventDispatcher");
 tolua_usertype(tolua_S,"wyObject");
 tolua_usertype(tolua_S,"wyRect");
 tolua_usertype(tolua_S,"wyColorFilter");
}

/* method: getZEye of class  wyCamera */
#ifndef TOLUA_DISABLE_tolua_opengl_wyCamera_getZEye00
static int tolua_opengl_wyCamera_getZEye00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyCamera",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   float tolua_ret = (float)  wyCamera::getZEye();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getZEye'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: make of class  wyCamera */
#ifndef TOLUA_DISABLE_tolua_opengl_wyCamera_make00
static int tolua_opengl_wyCamera_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyCamera",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   wyCamera* tolua_ret = (wyCamera*)  wyCamera::make();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyCamera");
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

/* method: delete of class  wyCamera */
#ifndef TOLUA_DISABLE_tolua_opengl_wyCamera_delete00
static int tolua_opengl_wyCamera_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyCamera",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyCamera* self = (wyCamera*)  tolua_tousertype(tolua_S,1,0);
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

/* method: restore of class  wyCamera */
#ifndef TOLUA_DISABLE_tolua_opengl_wyCamera_restore00
static int tolua_opengl_wyCamera_restore00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyCamera",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyCamera* self = (wyCamera*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'restore'", NULL);
#endif
  {
   self->restore();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'restore'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: locate of class  wyCamera */
#ifndef TOLUA_DISABLE_tolua_opengl_wyCamera_locate00
static int tolua_opengl_wyCamera_locate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyCamera",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyCamera* self = (wyCamera*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'locate'", NULL);
#endif
  {
   self->locate();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'locate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setEye of class  wyCamera */
#ifndef TOLUA_DISABLE_tolua_opengl_wyCamera_setEye00
static int tolua_opengl_wyCamera_setEye00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyCamera",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyCamera* self = (wyCamera*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
  float z = ((float)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setEye'", NULL);
#endif
  {
   self->setEye(x,y,z);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setEye'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setCenter of class  wyCamera */
#ifndef TOLUA_DISABLE_tolua_opengl_wyCamera_setCenter00
static int tolua_opengl_wyCamera_setCenter00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyCamera",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyCamera* self = (wyCamera*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
  float z = ((float)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setCenter'", NULL);
#endif
  {
   self->setCenter(x,y,z);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setCenter'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setUp of class  wyCamera */
#ifndef TOLUA_DISABLE_tolua_opengl_wyCamera_setUp00
static int tolua_opengl_wyCamera_setUp00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyCamera",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyCamera* self = (wyCamera*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
  float z = ((float)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setUp'", NULL);
#endif
  {
   self->setUp(x,y,z);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setUp'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getEye of class  wyCamera */
#ifndef TOLUA_DISABLE_tolua_opengl_wyCamera_getEye00
static int tolua_opengl_wyCamera_getEye00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyCamera",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyCamera* self = (wyCamera*)  tolua_tousertype(tolua_S,1,0);
  float eye = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getEye'", NULL);
#endif
  {
   self->getEye(&eye);
   tolua_pushnumber(tolua_S,(lua_Number)eye);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getEye'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getCenter of class  wyCamera */
#ifndef TOLUA_DISABLE_tolua_opengl_wyCamera_getCenter00
static int tolua_opengl_wyCamera_getCenter00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyCamera",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyCamera* self = (wyCamera*)  tolua_tousertype(tolua_S,1,0);
  float center = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getCenter'", NULL);
#endif
  {
   self->getCenter(&center);
   tolua_pushnumber(tolua_S,(lua_Number)center);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getCenter'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getUp of class  wyCamera */
#ifndef TOLUA_DISABLE_tolua_opengl_wyCamera_getUp00
static int tolua_opengl_wyCamera_getUp00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyCamera",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyCamera* self = (wyCamera*)  tolua_tousertype(tolua_S,1,0);
  float up = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getUp'", NULL);
#endif
  {
   self->getUp(&up);
   tolua_pushnumber(tolua_S,(lua_Number)up);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getUp'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isDirty of class  wyCamera */
#ifndef TOLUA_DISABLE_tolua_opengl_wyCamera_isDirty00
static int tolua_opengl_wyCamera_isDirty00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyCamera",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyCamera* self = (wyCamera*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isDirty'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isDirty();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isDirty'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setDirty of class  wyCamera */
#ifndef TOLUA_DISABLE_tolua_opengl_wyCamera_setDirty00
static int tolua_opengl_wyCamera_setDirty00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyCamera",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyCamera* self = (wyCamera*)  tolua_tousertype(tolua_S,1,0);
  bool dirty = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setDirty'", NULL);
#endif
  {
   self->setDirty(dirty);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setDirty'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: make of class  wyTexture2D */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTexture2D_make00
static int tolua_opengl_wyTexture2D_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyTexture2D",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  int resId = ((int)  tolua_tonumber(tolua_S,2,0));
  {
   wyTexture2D* tolua_ret = (wyTexture2D*)  wyTexture2D::make(resId);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyTexture2D");
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

/* method: make of class  wyTexture2D */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTexture2D_make01
static int tolua_opengl_wyTexture2D_make01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyTexture2D",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  int resId = ((int)  tolua_tonumber(tolua_S,2,0));
  int transparentColor = ((int)  tolua_tonumber(tolua_S,3,0));
  {
   wyTexture2D* tolua_ret = (wyTexture2D*)  wyTexture2D::make(resId,transparentColor);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyTexture2D");
  }
 }
 return 1;
tolua_lerror:
 return tolua_opengl_wyTexture2D_make00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: make of class  wyTexture2D */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTexture2D_make02
static int tolua_opengl_wyTexture2D_make02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyTexture2D",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  int resId = ((int)  tolua_tonumber(tolua_S,2,0));
  int transparentColor = ((int)  tolua_tonumber(tolua_S,3,0));
  wyTexturePixelFormat format = ((wyTexturePixelFormat) (int)  tolua_tonumber(tolua_S,4,0));
  {
   wyTexture2D* tolua_ret = (wyTexture2D*)  wyTexture2D::make(resId,transparentColor,format);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyTexture2D");
  }
 }
 return 1;
tolua_lerror:
 return tolua_opengl_wyTexture2D_make01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: make of class  wyTexture2D */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTexture2D_make03
static int tolua_opengl_wyTexture2D_make03(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyTexture2D",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const char* assetPath = ((const char*)  tolua_tostring(tolua_S,2,0));
  {
   wyTexture2D* tolua_ret = (wyTexture2D*)  wyTexture2D::make(assetPath);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyTexture2D");
  }
 }
 return 1;
tolua_lerror:
 return tolua_opengl_wyTexture2D_make02(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: make of class  wyTexture2D */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTexture2D_make04
static int tolua_opengl_wyTexture2D_make04(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyTexture2D",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const char* assetPath = ((const char*)  tolua_tostring(tolua_S,2,0));
  int transparentColor = ((int)  tolua_tonumber(tolua_S,3,0));
  {
   wyTexture2D* tolua_ret = (wyTexture2D*)  wyTexture2D::make(assetPath,transparentColor);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyTexture2D");
  }
 }
 return 1;
tolua_lerror:
 return tolua_opengl_wyTexture2D_make03(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: make of class  wyTexture2D */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTexture2D_make05
static int tolua_opengl_wyTexture2D_make05(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyTexture2D",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const char* assetPath = ((const char*)  tolua_tostring(tolua_S,2,0));
  int transparentColor = ((int)  tolua_tonumber(tolua_S,3,0));
  wyTexturePixelFormat format = ((wyTexturePixelFormat) (int)  tolua_tonumber(tolua_S,4,0));
  {
   wyTexture2D* tolua_ret = (wyTexture2D*)  wyTexture2D::make(assetPath,transparentColor,format);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyTexture2D");
  }
 }
 return 1;
tolua_lerror:
 return tolua_opengl_wyTexture2D_make04(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: make of class  wyTexture2D */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTexture2D_make06
static int tolua_opengl_wyTexture2D_make06(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyTexture2D",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const char* assetPath = ((const char*)  tolua_tostring(tolua_S,2,0));
  int transparentColor = ((int)  tolua_tonumber(tolua_S,3,0));
  wyTexturePixelFormat format = ((wyTexturePixelFormat) (int)  tolua_tonumber(tolua_S,4,0));
  float inDensity = ((float)  tolua_tonumber(tolua_S,5,0));
  {
   wyTexture2D* tolua_ret = (wyTexture2D*)  wyTexture2D::make(assetPath,transparentColor,format,inDensity);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyTexture2D");
  }
 }
 return 1;
tolua_lerror:
 return tolua_opengl_wyTexture2D_make05(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: makeRaw of class  wyTexture2D */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTexture2D_makeRaw00
static int tolua_opengl_wyTexture2D_makeRaw00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyTexture2D",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"size_t",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* data = ((const char*)  tolua_tostring(tolua_S,2,0));
  size_t length = *((size_t*)  tolua_tousertype(tolua_S,3,0));
  {
   wyTexture2D* tolua_ret = (wyTexture2D*)  wyTexture2D::makeRaw(data,length);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyTexture2D");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'makeRaw'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: makeRaw of class  wyTexture2D */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTexture2D_makeRaw01
static int tolua_opengl_wyTexture2D_makeRaw01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyTexture2D",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"size_t",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const char* data = ((const char*)  tolua_tostring(tolua_S,2,0));
  size_t length = *((size_t*)  tolua_tousertype(tolua_S,3,0));
  int transparentColor = ((int)  tolua_tonumber(tolua_S,4,0));
  {
   wyTexture2D* tolua_ret = (wyTexture2D*)  wyTexture2D::makeRaw(data,length,transparentColor);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyTexture2D");
  }
 }
 return 1;
tolua_lerror:
 return tolua_opengl_wyTexture2D_makeRaw00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: makeRaw of class  wyTexture2D */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTexture2D_makeRaw02
static int tolua_opengl_wyTexture2D_makeRaw02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyTexture2D",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"size_t",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const char* data = ((const char*)  tolua_tostring(tolua_S,2,0));
  size_t length = *((size_t*)  tolua_tousertype(tolua_S,3,0));
  int transparentColor = ((int)  tolua_tonumber(tolua_S,4,0));
  wyTexturePixelFormat format = ((wyTexturePixelFormat) (int)  tolua_tonumber(tolua_S,5,0));
  {
   wyTexture2D* tolua_ret = (wyTexture2D*)  wyTexture2D::makeRaw(data,length,transparentColor,format);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyTexture2D");
  }
 }
 return 1;
tolua_lerror:
 return tolua_opengl_wyTexture2D_makeRaw01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: makeRaw of class  wyTexture2D */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTexture2D_makeRaw03
static int tolua_opengl_wyTexture2D_makeRaw03(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyTexture2D",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"size_t",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const char* data = ((const char*)  tolua_tostring(tolua_S,2,0));
  size_t length = *((size_t*)  tolua_tousertype(tolua_S,3,0));
  int transparentColor = ((int)  tolua_tonumber(tolua_S,4,0));
  wyTexturePixelFormat format = ((wyTexturePixelFormat) (int)  tolua_tonumber(tolua_S,5,0));
  float inDensity = ((float)  tolua_tonumber(tolua_S,6,0));
  {
   wyTexture2D* tolua_ret = (wyTexture2D*)  wyTexture2D::makeRaw(data,length,transparentColor,format,inDensity);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyTexture2D");
  }
 }
 return 1;
tolua_lerror:
 return tolua_opengl_wyTexture2D_makeRaw02(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: makeMemory of class  wyTexture2D */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTexture2D_makeMemory00
static int tolua_opengl_wyTexture2D_makeMemory00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyTexture2D",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* mfsName = ((const char*)  tolua_tostring(tolua_S,2,0));
  {
   wyTexture2D* tolua_ret = (wyTexture2D*)  wyTexture2D::makeMemory(mfsName);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyTexture2D");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'makeMemory'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: makeMemory of class  wyTexture2D */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTexture2D_makeMemory01
static int tolua_opengl_wyTexture2D_makeMemory01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyTexture2D",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const char* mfsName = ((const char*)  tolua_tostring(tolua_S,2,0));
  int transparentColor = ((int)  tolua_tonumber(tolua_S,3,0));
  {
   wyTexture2D* tolua_ret = (wyTexture2D*)  wyTexture2D::makeMemory(mfsName,transparentColor);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyTexture2D");
  }
 }
 return 1;
tolua_lerror:
 return tolua_opengl_wyTexture2D_makeMemory00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: makeMemory of class  wyTexture2D */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTexture2D_makeMemory02
static int tolua_opengl_wyTexture2D_makeMemory02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyTexture2D",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const char* mfsName = ((const char*)  tolua_tostring(tolua_S,2,0));
  int transparentColor = ((int)  tolua_tonumber(tolua_S,3,0));
  wyTexturePixelFormat format = ((wyTexturePixelFormat) (int)  tolua_tonumber(tolua_S,4,0));
  {
   wyTexture2D* tolua_ret = (wyTexture2D*)  wyTexture2D::makeMemory(mfsName,transparentColor,format);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyTexture2D");
  }
 }
 return 1;
tolua_lerror:
 return tolua_opengl_wyTexture2D_makeMemory01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: makeMemory of class  wyTexture2D */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTexture2D_makeMemory03
static int tolua_opengl_wyTexture2D_makeMemory03(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyTexture2D",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const char* mfsName = ((const char*)  tolua_tostring(tolua_S,2,0));
  int transparentColor = ((int)  tolua_tonumber(tolua_S,3,0));
  wyTexturePixelFormat format = ((wyTexturePixelFormat) (int)  tolua_tonumber(tolua_S,4,0));
  float inDensity = ((float)  tolua_tonumber(tolua_S,5,0));
  {
   wyTexture2D* tolua_ret = (wyTexture2D*)  wyTexture2D::makeMemory(mfsName,transparentColor,format,inDensity);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyTexture2D");
  }
 }
 return 1;
tolua_lerror:
 return tolua_opengl_wyTexture2D_makeMemory02(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: makeFile of class  wyTexture2D */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTexture2D_makeFile00
static int tolua_opengl_wyTexture2D_makeFile00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyTexture2D",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* fsPath = ((const char*)  tolua_tostring(tolua_S,2,0));
  {
   wyTexture2D* tolua_ret = (wyTexture2D*)  wyTexture2D::makeFile(fsPath);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyTexture2D");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'makeFile'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: makeFile of class  wyTexture2D */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTexture2D_makeFile01
static int tolua_opengl_wyTexture2D_makeFile01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyTexture2D",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const char* fsPath = ((const char*)  tolua_tostring(tolua_S,2,0));
  int transparentColor = ((int)  tolua_tonumber(tolua_S,3,0));
  {
   wyTexture2D* tolua_ret = (wyTexture2D*)  wyTexture2D::makeFile(fsPath,transparentColor);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyTexture2D");
  }
 }
 return 1;
tolua_lerror:
 return tolua_opengl_wyTexture2D_makeFile00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: makeFile of class  wyTexture2D */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTexture2D_makeFile02
static int tolua_opengl_wyTexture2D_makeFile02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyTexture2D",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const char* fsPath = ((const char*)  tolua_tostring(tolua_S,2,0));
  int transparentColor = ((int)  tolua_tonumber(tolua_S,3,0));
  wyTexturePixelFormat format = ((wyTexturePixelFormat) (int)  tolua_tonumber(tolua_S,4,0));
  {
   wyTexture2D* tolua_ret = (wyTexture2D*)  wyTexture2D::makeFile(fsPath,transparentColor,format);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyTexture2D");
  }
 }
 return 1;
tolua_lerror:
 return tolua_opengl_wyTexture2D_makeFile01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: makeFile of class  wyTexture2D */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTexture2D_makeFile03
static int tolua_opengl_wyTexture2D_makeFile03(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyTexture2D",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const char* fsPath = ((const char*)  tolua_tostring(tolua_S,2,0));
  int transparentColor = ((int)  tolua_tonumber(tolua_S,3,0));
  wyTexturePixelFormat format = ((wyTexturePixelFormat) (int)  tolua_tonumber(tolua_S,4,0));
  float inDensity = ((float)  tolua_tonumber(tolua_S,5,0));
  {
   wyTexture2D* tolua_ret = (wyTexture2D*)  wyTexture2D::makeFile(fsPath,transparentColor,format,inDensity);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyTexture2D");
  }
 }
 return 1;
tolua_lerror:
 return tolua_opengl_wyTexture2D_makeFile02(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: makeLabel of class  wyTexture2D */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTexture2D_makeLabel00
static int tolua_opengl_wyTexture2D_makeLabel00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyTexture2D",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isstring(tolua_S,4,1,&tolua_err) ||
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
  const char* fontPath = ((const char*)  tolua_tostring(tolua_S,4,NULL));
  bool isFile = ((bool)  tolua_toboolean(tolua_S,5,false));
  float width = ((float)  tolua_tonumber(tolua_S,6,0));
  wyTexture2D::TextAlignment alignment = ((wyTexture2D::TextAlignment) (int)  tolua_tonumber(tolua_S,7,wyTexture2D::LEFT));
  {
   wyTexture2D* tolua_ret = (wyTexture2D*)  wyTexture2D::makeLabel(text,fontSize,fontPath,isFile,width,alignment);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyTexture2D");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'makeLabel'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: makeLabel of class  wyTexture2D */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTexture2D_makeLabel01
static int tolua_opengl_wyTexture2D_makeLabel01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyTexture2D",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"wyFontStyle",0,&tolua_err)) ||
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
  wyFontStyle style = *((wyFontStyle*)  tolua_tousertype(tolua_S,4,0));
  const char* fontName = ((const char*)  tolua_tostring(tolua_S,5,NULL));
  float width = ((float)  tolua_tonumber(tolua_S,6,0));
  wyTexture2D::TextAlignment alignment = ((wyTexture2D::TextAlignment) (int)  tolua_tonumber(tolua_S,7,wyTexture2D::LEFT));
  {
   wyTexture2D* tolua_ret = (wyTexture2D*)  wyTexture2D::makeLabel(text,fontSize,style,fontName,width,alignment);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyTexture2D");
  }
 }
 return 1;
tolua_lerror:
 return tolua_opengl_wyTexture2D_makeLabel00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: makeGL of class  wyTexture2D */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTexture2D_makeGL00
static int tolua_opengl_wyTexture2D_makeGL00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyTexture2D",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  int texture = ((int)  tolua_tonumber(tolua_S,2,0));
  int w = ((int)  tolua_tonumber(tolua_S,3,0));
  int h = ((int)  tolua_tonumber(tolua_S,4,0));
  {
   wyTexture2D* tolua_ret = (wyTexture2D*)  wyTexture2D::makeGL(texture,w,h);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyTexture2D");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'makeGL'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: makeRaw8888 of class  wyTexture2D */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTexture2D_makeRaw888800
static int tolua_opengl_wyTexture2D_makeRaw888800(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyTexture2D",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* data = ((const char*)  tolua_tostring(tolua_S,2,0));
  int width = ((int)  tolua_tonumber(tolua_S,3,0));
  int height = ((int)  tolua_tonumber(tolua_S,4,0));
  {
   wyTexture2D* tolua_ret = (wyTexture2D*)  wyTexture2D::makeRaw8888(data,width,height);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyTexture2D");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'makeRaw8888'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: makeRaw8888 of class  wyTexture2D */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTexture2D_makeRaw888801
static int tolua_opengl_wyTexture2D_makeRaw888801(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyTexture2D",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const char* data = ((const char*)  tolua_tostring(tolua_S,2,0));
  int width = ((int)  tolua_tonumber(tolua_S,3,0));
  int height = ((int)  tolua_tonumber(tolua_S,4,0));
  wyTexturePixelFormat format = ((wyTexturePixelFormat) (int)  tolua_tonumber(tolua_S,5,0));
  {
   wyTexture2D* tolua_ret = (wyTexture2D*)  wyTexture2D::makeRaw8888(data,width,height,format);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyTexture2D");
  }
 }
 return 1;
tolua_lerror:
 return tolua_opengl_wyTexture2D_makeRaw888800(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  wyTexture2D */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTexture2D_new00
static int tolua_opengl_wyTexture2D_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyTexture2D",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   wyTexture2D* tolua_ret = (wyTexture2D*)  Mtolua_new((wyTexture2D)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyTexture2D");
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

/* method: new_local of class  wyTexture2D */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTexture2D_new00_local
static int tolua_opengl_wyTexture2D_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyTexture2D",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   wyTexture2D* tolua_ret = (wyTexture2D*)  Mtolua_new((wyTexture2D)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyTexture2D");
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

/* method: delete of class  wyTexture2D */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTexture2D_delete00
static int tolua_opengl_wyTexture2D_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTexture2D",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTexture2D* self = (wyTexture2D*)  tolua_tousertype(tolua_S,1,0);
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

/* method: load of class  wyTexture2D */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTexture2D_load00
static int tolua_opengl_wyTexture2D_load00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTexture2D",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTexture2D* self = (wyTexture2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'load'", NULL);
#endif
  {
   self->load();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'load'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: updateLabel of class  wyTexture2D */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTexture2D_updateLabel00
static int tolua_opengl_wyTexture2D_updateLabel00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTexture2D",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTexture2D* self = (wyTexture2D*)  tolua_tousertype(tolua_S,1,0);
  const char* text = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'updateLabel'", NULL);
#endif
  {
   self->updateLabel(text);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'updateLabel'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: updateLabel of class  wyTexture2D */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTexture2D_updateLabel01
static int tolua_opengl_wyTexture2D_updateLabel01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTexture2D",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isstring(tolua_S,4,1,&tolua_err) ||
     !tolua_isboolean(tolua_S,5,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,7,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,8,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  wyTexture2D* self = (wyTexture2D*)  tolua_tousertype(tolua_S,1,0);
  const char* text = ((const char*)  tolua_tostring(tolua_S,2,0));
  float fontSize = ((float)  tolua_tonumber(tolua_S,3,0));
  const char* fontPath = ((const char*)  tolua_tostring(tolua_S,4,NULL));
  bool isFile = ((bool)  tolua_toboolean(tolua_S,5,false));
  float lineWidth = ((float)  tolua_tonumber(tolua_S,6,0));
  wyTexture2D::TextAlignment alignment = ((wyTexture2D::TextAlignment) (int)  tolua_tonumber(tolua_S,7,wyTexture2D::LEFT));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'updateLabel'", NULL);
#endif
  {
   self->updateLabel(text,fontSize,fontPath,isFile,lineWidth,alignment);
  }
 }
 return 0;
tolua_lerror:
 return tolua_opengl_wyTexture2D_updateLabel00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: updateLabel of class  wyTexture2D */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTexture2D_updateLabel02
static int tolua_opengl_wyTexture2D_updateLabel02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTexture2D",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"wyFontStyle",0,&tolua_err)) ||
     !tolua_isstring(tolua_S,5,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,7,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,8,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  wyTexture2D* self = (wyTexture2D*)  tolua_tousertype(tolua_S,1,0);
  const char* text = ((const char*)  tolua_tostring(tolua_S,2,0));
  float fontSize = ((float)  tolua_tonumber(tolua_S,3,0));
  wyFontStyle style = *((wyFontStyle*)  tolua_tousertype(tolua_S,4,0));
  const char* fontName = ((const char*)  tolua_tostring(tolua_S,5,NULL));
  float lineWidth = ((float)  tolua_tonumber(tolua_S,6,0));
  wyTexture2D::TextAlignment alignment = ((wyTexture2D::TextAlignment) (int)  tolua_tonumber(tolua_S,7,wyTexture2D::LEFT));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'updateLabel'", NULL);
#endif
  {
   self->updateLabel(text,fontSize,style,fontName,lineWidth,alignment);
  }
 }
 return 0;
tolua_lerror:
 return tolua_opengl_wyTexture2D_updateLabel01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: setAntiAlias of class  wyTexture2D */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTexture2D_setAntiAlias00
static int tolua_opengl_wyTexture2D_setAntiAlias00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTexture2D",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTexture2D* self = (wyTexture2D*)  tolua_tousertype(tolua_S,1,0);
  bool on = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setAntiAlias'", NULL);
#endif
  {
   self->setAntiAlias(on);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setAntiAlias'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setRepeat of class  wyTexture2D */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTexture2D_setRepeat00
static int tolua_opengl_wyTexture2D_setRepeat00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTexture2D",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTexture2D* self = (wyTexture2D*)  tolua_tousertype(tolua_S,1,0);
  bool on = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setRepeat'", NULL);
#endif
  {
   self->setRepeat(on);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setRepeat'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setParameters of class  wyTexture2D */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTexture2D_setParameters00
static int tolua_opengl_wyTexture2D_setParameters00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTexture2D",0,&tolua_err) ||
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
  wyTexture2D* self = (wyTexture2D*)  tolua_tousertype(tolua_S,1,0);
  int min = ((int)  tolua_tonumber(tolua_S,2,0));
  int mag = ((int)  tolua_tonumber(tolua_S,3,0));
  int wrapS = ((int)  tolua_tonumber(tolua_S,4,0));
  int wrapT = ((int)  tolua_tonumber(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setParameters'", NULL);
#endif
  {
   self->setParameters(min,mag,wrapS,wrapT);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setParameters'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: applyParameters of class  wyTexture2D */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTexture2D_applyParameters00
static int tolua_opengl_wyTexture2D_applyParameters00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTexture2D",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTexture2D* self = (wyTexture2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'applyParameters'", NULL);
#endif
  {
   self->applyParameters();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'applyParameters'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: hasPremultipliedAlpha of class  wyTexture2D */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTexture2D_hasPremultipliedAlpha00
static int tolua_opengl_wyTexture2D_hasPremultipliedAlpha00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTexture2D",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTexture2D* self = (wyTexture2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'hasPremultipliedAlpha'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->hasPremultipliedAlpha();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'hasPremultipliedAlpha'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: draw of class  wyTexture2D */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTexture2D_draw00
static int tolua_opengl_wyTexture2D_draw00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTexture2D",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTexture2D* self = (wyTexture2D*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'draw'", NULL);
#endif
  {
   self->draw(x,y);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'draw'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: draw of class  wyTexture2D */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTexture2D_draw01
static int tolua_opengl_wyTexture2D_draw01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTexture2D",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,4,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  wyTexture2D* self = (wyTexture2D*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
  bool flipX = ((bool)  tolua_toboolean(tolua_S,4,0));
  bool flipY = ((bool)  tolua_toboolean(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'draw'", NULL);
#endif
  {
   self->draw(x,y,flipX,flipY);
  }
 }
 return 0;
tolua_lerror:
 return tolua_opengl_wyTexture2D_draw00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: draw of class  wyTexture2D */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTexture2D_draw02
static int tolua_opengl_wyTexture2D_draw02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTexture2D",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  wyTexture2D* self = (wyTexture2D*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
  float width = ((float)  tolua_tonumber(tolua_S,4,0));
  float height = ((float)  tolua_tonumber(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'draw'", NULL);
#endif
  {
   self->draw(x,y,width,height);
  }
 }
 return 0;
tolua_lerror:
 return tolua_opengl_wyTexture2D_draw01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: draw of class  wyTexture2D */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTexture2D_draw03
static int tolua_opengl_wyTexture2D_draw03(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTexture2D",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,6,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,7,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,8,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  wyTexture2D* self = (wyTexture2D*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
  float width = ((float)  tolua_tonumber(tolua_S,4,0));
  float height = ((float)  tolua_tonumber(tolua_S,5,0));
  bool flipX = ((bool)  tolua_toboolean(tolua_S,6,0));
  bool flipY = ((bool)  tolua_toboolean(tolua_S,7,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'draw'", NULL);
#endif
  {
   self->draw(x,y,width,height,flipX,flipY);
  }
 }
 return 0;
tolua_lerror:
 return tolua_opengl_wyTexture2D_draw02(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: draw of class  wyTexture2D */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTexture2D_draw04
static int tolua_opengl_wyTexture2D_draw04(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTexture2D",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,6,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,7,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,8,&tolua_err) || !tolua_isusertype(tolua_S,8,"wyRect",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,9,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  wyTexture2D* self = (wyTexture2D*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
  float width = ((float)  tolua_tonumber(tolua_S,4,0));
  float height = ((float)  tolua_tonumber(tolua_S,5,0));
  bool flipX = ((bool)  tolua_toboolean(tolua_S,6,0));
  bool flipY = ((bool)  tolua_toboolean(tolua_S,7,0));
  wyRect texRect = *((wyRect*)  tolua_tousertype(tolua_S,8,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'draw'", NULL);
#endif
  {
   self->draw(x,y,width,height,flipX,flipY,texRect);
  }
 }
 return 0;
tolua_lerror:
 return tolua_opengl_wyTexture2D_draw03(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: draw of class  wyTexture2D */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTexture2D_draw05
static int tolua_opengl_wyTexture2D_draw05(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTexture2D",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,6,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,7,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,8,&tolua_err) || !tolua_isusertype(tolua_S,8,"wyRect",0,&tolua_err)) ||
     !tolua_isboolean(tolua_S,9,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,10,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  wyTexture2D* self = (wyTexture2D*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
  float width = ((float)  tolua_tonumber(tolua_S,4,0));
  float height = ((float)  tolua_tonumber(tolua_S,5,0));
  bool flipX = ((bool)  tolua_toboolean(tolua_S,6,0));
  bool flipY = ((bool)  tolua_toboolean(tolua_S,7,0));
  wyRect texRect = *((wyRect*)  tolua_tousertype(tolua_S,8,0));
  bool rotatedZwoptex = ((bool)  tolua_toboolean(tolua_S,9,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'draw'", NULL);
#endif
  {
   self->draw(x,y,width,height,flipX,flipY,texRect,rotatedZwoptex);
  }
 }
 return 0;
tolua_lerror:
 return tolua_opengl_wyTexture2D_draw04(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: draw of class  wyTexture2D */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTexture2D_draw06
static int tolua_opengl_wyTexture2D_draw06(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTexture2D",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,7,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,8,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,9,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,10,&tolua_err) || !tolua_isusertype(tolua_S,10,"wyRect",0,&tolua_err)) ||
     !tolua_isboolean(tolua_S,11,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,12,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  wyTexture2D* self = (wyTexture2D*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
  float width = ((float)  tolua_tonumber(tolua_S,4,0));
  float height = ((float)  tolua_tonumber(tolua_S,5,0));
  float sourceWidth = ((float)  tolua_tonumber(tolua_S,6,0));
  float sourceHeight = ((float)  tolua_tonumber(tolua_S,7,0));
  bool flipX = ((bool)  tolua_toboolean(tolua_S,8,0));
  bool flipY = ((bool)  tolua_toboolean(tolua_S,9,0));
  wyRect texRect = *((wyRect*)  tolua_tousertype(tolua_S,10,0));
  bool rotatedZwoptex = ((bool)  tolua_toboolean(tolua_S,11,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'draw'", NULL);
#endif
  {
   self->draw(x,y,width,height,sourceWidth,sourceHeight,flipX,flipY,texRect,rotatedZwoptex);
  }
 }
 return 0;
tolua_lerror:
 return tolua_opengl_wyTexture2D_draw05(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: getWidth of class  wyTexture2D */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTexture2D_getWidth00
static int tolua_opengl_wyTexture2D_getWidth00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTexture2D",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTexture2D* self = (wyTexture2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getWidth'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getWidth();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getWidth'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getHeight of class  wyTexture2D */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTexture2D_getHeight00
static int tolua_opengl_wyTexture2D_getHeight00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTexture2D",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTexture2D* self = (wyTexture2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getHeight'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getHeight();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getHeight'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getPixelWidth of class  wyTexture2D */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTexture2D_getPixelWidth00
static int tolua_opengl_wyTexture2D_getPixelWidth00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTexture2D",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTexture2D* self = (wyTexture2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getPixelWidth'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getPixelWidth();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getPixelWidth'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getPixelHeight of class  wyTexture2D */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTexture2D_getPixelHeight00
static int tolua_opengl_wyTexture2D_getPixelHeight00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTexture2D",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTexture2D* self = (wyTexture2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getPixelHeight'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getPixelHeight();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getPixelHeight'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getWidthScale of class  wyTexture2D */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTexture2D_getWidthScale00
static int tolua_opengl_wyTexture2D_getWidthScale00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTexture2D",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTexture2D* self = (wyTexture2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getWidthScale'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getWidthScale();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getWidthScale'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getHeightScale of class  wyTexture2D */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTexture2D_getHeightScale00
static int tolua_opengl_wyTexture2D_getHeightScale00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTexture2D",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTexture2D* self = (wyTexture2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getHeightScale'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getHeightScale();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getHeightScale'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getTexture of class  wyTexture2D */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTexture2D_getTexture00
static int tolua_opengl_wyTexture2D_getTexture00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTexture2D",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTexture2D* self = (wyTexture2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getTexture'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getTexture();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
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

/* method: getText of class  wyTexture2D */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTexture2D_getText00
static int tolua_opengl_wyTexture2D_getText00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTexture2D",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTexture2D* self = (wyTexture2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getText'", NULL);
#endif
  {
   const char* tolua_ret = (const char*)  self->getText();
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getText'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getSource of class  wyTexture2D */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTexture2D_getSource00
static int tolua_opengl_wyTexture2D_getSource00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTexture2D",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTexture2D* self = (wyTexture2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getSource'", NULL);
#endif
  {
   wyTextureSource tolua_ret = (wyTextureSource)  self->getSource();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getSource'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isFlipY of class  wyTexture2D */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTexture2D_isFlipY00
static int tolua_opengl_wyTexture2D_isFlipY00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTexture2D",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTexture2D* self = (wyTexture2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isFlipY'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isFlipY();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isFlipY'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isFlipX of class  wyTexture2D */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTexture2D_isFlipX00
static int tolua_opengl_wyTexture2D_isFlipX00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTexture2D",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTexture2D* self = (wyTexture2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isFlipX'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isFlipX();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isFlipX'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setFlipX of class  wyTexture2D */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTexture2D_setFlipX00
static int tolua_opengl_wyTexture2D_setFlipX00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTexture2D",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTexture2D* self = (wyTexture2D*)  tolua_tousertype(tolua_S,1,0);
  bool flipX = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setFlipX'", NULL);
#endif
  {
   self->setFlipX(flipX);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setFlipX'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setFlipY of class  wyTexture2D */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTexture2D_setFlipY00
static int tolua_opengl_wyTexture2D_setFlipY00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTexture2D",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTexture2D* self = (wyTexture2D*)  tolua_tousertype(tolua_S,1,0);
  bool flipY = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setFlipY'", NULL);
#endif
  {
   self->setFlipY(flipY);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setFlipY'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: updateRaw of class  wyTexture2D */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTexture2D_updateRaw00
static int tolua_opengl_wyTexture2D_updateRaw00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTexture2D",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTexture2D* self = (wyTexture2D*)  tolua_tousertype(tolua_S,1,0);
  const char* raw = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'updateRaw'", NULL);
#endif
  {
   self->updateRaw(raw);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'updateRaw'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setColorFilter of class  wyTexture2D */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTexture2D_setColorFilter00
static int tolua_opengl_wyTexture2D_setColorFilter00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTexture2D",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyColorFilter",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTexture2D* self = (wyTexture2D*)  tolua_tousertype(tolua_S,1,0);
  wyColorFilter* filter = ((wyColorFilter*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setColorFilter'", NULL);
#endif
  {
   self->setColorFilter(filter);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setColorFilter'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: applyFilter of class  wyTexture2D */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTexture2D_applyFilter00
static int tolua_opengl_wyTexture2D_applyFilter00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTexture2D",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTexture2D* self = (wyTexture2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'applyFilter'", NULL);
#endif
  {
   self->applyFilter();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'applyFilter'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  wyGLTexture2D */
#ifndef TOLUA_DISABLE_tolua_opengl_wyGLTexture2D_delete00
static int tolua_opengl_wyGLTexture2D_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyGLTexture2D",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyGLTexture2D* self = (wyGLTexture2D*)  tolua_tousertype(tolua_S,1,0);
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

/* function: wyDrawPoint */
#ifndef TOLUA_DISABLE_tolua_opengl_wyDrawPoint00
static int tolua_opengl_wyDrawPoint00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float x = ((float)  tolua_tonumber(tolua_S,1,0));
  float y = ((float)  tolua_tonumber(tolua_S,2,0));
  {
   wyDrawPoint(x,y);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'wyDrawPoint'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: wyDrawPoints */
#ifndef TOLUA_DISABLE_tolua_opengl_wyDrawPoints00
static int tolua_opengl_wyDrawPoints00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"size_t",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float p = ((float)  tolua_tonumber(tolua_S,1,0));
  size_t length = *((size_t*)  tolua_tousertype(tolua_S,2,0));
  {
   wyDrawPoints(&p,length);
   tolua_pushnumber(tolua_S,(lua_Number)p);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'wyDrawPoints'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: wyDrawLine */
#ifndef TOLUA_DISABLE_tolua_opengl_wyDrawLine00
static int tolua_opengl_wyDrawLine00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float x1 = ((float)  tolua_tonumber(tolua_S,1,0));
  float y1 = ((float)  tolua_tonumber(tolua_S,2,0));
  float x2 = ((float)  tolua_tonumber(tolua_S,3,0));
  float y2 = ((float)  tolua_tonumber(tolua_S,4,0));
  {
   wyDrawLine(x1,y1,x2,y2);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'wyDrawLine'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: wyDrawPath */
#ifndef TOLUA_DISABLE_tolua_opengl_wyDrawPath00
static int tolua_opengl_wyDrawPath00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"size_t",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float points = ((float)  tolua_tonumber(tolua_S,1,0));
  size_t length = *((size_t*)  tolua_tousertype(tolua_S,2,0));
  {
   wyDrawPath(&points,length);
   tolua_pushnumber(tolua_S,(lua_Number)points);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'wyDrawPath'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: wyDrawDashPath */
#ifndef TOLUA_DISABLE_tolua_opengl_wyDrawDashPath00
static int tolua_opengl_wyDrawDashPath00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"size_t",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float points = ((float)  tolua_tonumber(tolua_S,1,0));
  size_t length = *((size_t*)  tolua_tousertype(tolua_S,2,0));
  float dashLength = ((float)  tolua_tonumber(tolua_S,3,0));
  {
   wyDrawDashPath(&points,length,dashLength);
   tolua_pushnumber(tolua_S,(lua_Number)points);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'wyDrawDashPath'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: wyDrawDashLine */
#ifndef TOLUA_DISABLE_tolua_opengl_wyDrawDashLine00
static int tolua_opengl_wyDrawDashLine00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
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
  float x1 = ((float)  tolua_tonumber(tolua_S,1,0));
  float y1 = ((float)  tolua_tonumber(tolua_S,2,0));
  float x2 = ((float)  tolua_tonumber(tolua_S,3,0));
  float y2 = ((float)  tolua_tonumber(tolua_S,4,0));
  float dashLength = ((float)  tolua_tonumber(tolua_S,5,0));
  {
   wyDrawDashLine(x1,y1,x2,y2,dashLength);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'wyDrawDashLine'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: wyDrawPoly */
#ifndef TOLUA_DISABLE_tolua_opengl_wyDrawPoly00
static int tolua_opengl_wyDrawPoly00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"size_t",0,&tolua_err)) ||
     !tolua_isboolean(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float p = ((float)  tolua_tonumber(tolua_S,1,0));
  size_t length = *((size_t*)  tolua_tousertype(tolua_S,2,0));
  bool close = ((bool)  tolua_toboolean(tolua_S,3,0));
  {
   wyDrawPoly(&p,length,close);
   tolua_pushnumber(tolua_S,(lua_Number)p);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'wyDrawPoly'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: wyDrawRect */
#ifndef TOLUA_DISABLE_tolua_opengl_wyDrawRect00
static int tolua_opengl_wyDrawRect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float p = ((float)  tolua_tonumber(tolua_S,1,0));
  {
   wyDrawRect(&p);
   tolua_pushnumber(tolua_S,(lua_Number)p);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'wyDrawRect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: wyDrawRect2 */
#ifndef TOLUA_DISABLE_tolua_opengl_wyDrawRect200
static int tolua_opengl_wyDrawRect200(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     (tolua_isvaluenil(tolua_S,1,&tolua_err) || !tolua_isusertype(tolua_S,1,"wyRect",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyRect* r = ((wyRect*)  tolua_tousertype(tolua_S,1,0));
  {
   wyDrawRect2(*r);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'wyDrawRect2'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: wyDrawCircle */
#ifndef TOLUA_DISABLE_tolua_opengl_wyDrawCircle00
static int tolua_opengl_wyDrawCircle00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,6,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float centerX = ((float)  tolua_tonumber(tolua_S,1,0));
  float centerY = ((float)  tolua_tonumber(tolua_S,2,0));
  float r = ((float)  tolua_tonumber(tolua_S,3,0));
  float radiusLineAngle = ((float)  tolua_tonumber(tolua_S,4,0));
  int segments = ((int)  tolua_tonumber(tolua_S,5,0));
  bool drawLineToCenter = ((bool)  tolua_toboolean(tolua_S,6,0));
  {
   wyDrawCircle(centerX,centerY,r,radiusLineAngle,segments,drawLineToCenter);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'wyDrawCircle'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: wyDrawBezier */
#ifndef TOLUA_DISABLE_tolua_opengl_wyDrawBezier00
static int tolua_opengl_wyDrawBezier00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     (tolua_isvaluenil(tolua_S,1,&tolua_err) || !tolua_isusertype(tolua_S,1,"wyBezierConfig",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyBezierConfig* c = ((wyBezierConfig*)  tolua_tousertype(tolua_S,1,0));
  int segments = ((int)  tolua_tonumber(tolua_S,2,0));
  {
   wyDrawBezier(*c,segments);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'wyDrawBezier'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: wyDrawLagrange */
#ifndef TOLUA_DISABLE_tolua_opengl_wyDrawLagrange00
static int tolua_opengl_wyDrawLagrange00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     (tolua_isvaluenil(tolua_S,1,&tolua_err) || !tolua_isusertype(tolua_S,1,"wyLagrangeConfig",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyLagrangeConfig* c = ((wyLagrangeConfig*)  tolua_tousertype(tolua_S,1,0));
  int segments = ((int)  tolua_tonumber(tolua_S,2,0));
  {
   wyDrawLagrange(*c,segments);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'wyDrawLagrange'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: wyDrawTexture */
#ifndef TOLUA_DISABLE_tolua_opengl_wyDrawTexture00
static int tolua_opengl_wyDrawTexture00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,7,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,8,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,9,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,10,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  int texture = ((int)  tolua_tonumber(tolua_S,1,0));
  float texW = ((float)  tolua_tonumber(tolua_S,2,0));
  float texH = ((float)  tolua_tonumber(tolua_S,3,0));
  float x = ((float)  tolua_tonumber(tolua_S,4,0));
  float y = ((float)  tolua_tonumber(tolua_S,5,0));
  float w = ((float)  tolua_tonumber(tolua_S,6,0));
  float h = ((float)  tolua_tonumber(tolua_S,7,0));
  bool flipX = ((bool)  tolua_toboolean(tolua_S,8,0));
  bool flipY = ((bool)  tolua_toboolean(tolua_S,9,0));
  {
   wyDrawTexture(texture,texW,texH,x,y,w,h,flipX,flipY);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'wyDrawTexture'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: wyDrawTexture2 */
#ifndef TOLUA_DISABLE_tolua_opengl_wyDrawTexture200
static int tolua_opengl_wyDrawTexture200(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"wyRect",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,7,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,8,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,9,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,10,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,11,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  int texture = ((int)  tolua_tonumber(tolua_S,1,0));
  wyRect texRect = *((wyRect*)  tolua_tousertype(tolua_S,2,0));
  float texW = ((float)  tolua_tonumber(tolua_S,3,0));
  float texH = ((float)  tolua_tonumber(tolua_S,4,0));
  float x = ((float)  tolua_tonumber(tolua_S,5,0));
  float y = ((float)  tolua_tonumber(tolua_S,6,0));
  float w = ((float)  tolua_tonumber(tolua_S,7,0));
  float h = ((float)  tolua_tonumber(tolua_S,8,0));
  bool flipX = ((bool)  tolua_toboolean(tolua_S,9,0));
  bool flipY = ((bool)  tolua_toboolean(tolua_S,10,0));
  {
   wyDrawTexture2(texture,texRect,texW,texH,x,y,w,h,flipX,flipY);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'wyDrawTexture2'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: wyDrawSolidPoly */
#ifndef TOLUA_DISABLE_tolua_opengl_wyDrawSolidPoly00
static int tolua_opengl_wyDrawSolidPoly00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"size_t",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"wyColor4B",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float p = ((float)  tolua_tonumber(tolua_S,1,0));
  size_t length = *((size_t*)  tolua_tousertype(tolua_S,2,0));
  wyColor4B color = *((wyColor4B*)  tolua_tousertype(tolua_S,3,0));
  {
   wyDrawSolidPoly(&p,length,color);
   tolua_pushnumber(tolua_S,(lua_Number)p);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'wyDrawSolidPoly'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: wyDrawSolidRect */
#ifndef TOLUA_DISABLE_tolua_opengl_wyDrawSolidRect00
static int tolua_opengl_wyDrawSolidRect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"wyColor4B",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float p = ((float)  tolua_tonumber(tolua_S,1,0));
  wyColor4B color = *((wyColor4B*)  tolua_tousertype(tolua_S,2,0));
  {
   wyDrawSolidRect(&p,color);
   tolua_pushnumber(tolua_S,(lua_Number)p);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'wyDrawSolidRect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getInstance of class  wyTextureManager */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTextureManager_getInstance00
static int tolua_opengl_wyTextureManager_getInstance00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyTextureManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   wyTextureManager* tolua_ret = (wyTextureManager*)  wyTextureManager::getInstance();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyTextureManager");
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

/* method: delete of class  wyTextureManager */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTextureManager_delete00
static int tolua_opengl_wyTextureManager_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTextureManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTextureManager* self = (wyTextureManager*)  tolua_tousertype(tolua_S,1,0);
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

/* method: removeAllTextures of class  wyTextureManager */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTextureManager_removeAllTextures00
static int tolua_opengl_wyTextureManager_removeAllTextures00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTextureManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTextureManager* self = (wyTextureManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'removeAllTextures'", NULL);
#endif
  {
   self->removeAllTextures();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'removeAllTextures'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: removeTexture of class  wyTextureManager */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTextureManager_removeTexture00
static int tolua_opengl_wyTextureManager_removeTexture00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTextureManager",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTextureManager* self = (wyTextureManager*)  tolua_tousertype(tolua_S,1,0);
  int resId = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'removeTexture'", NULL);
#endif
  {
   self->removeTexture(resId);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'removeTexture'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: removeTexture of class  wyTextureManager */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTextureManager_removeTexture01
static int tolua_opengl_wyTextureManager_removeTexture01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTextureManager",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  wyTextureManager* self = (wyTextureManager*)  tolua_tousertype(tolua_S,1,0);
  const char* name = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'removeTexture'", NULL);
#endif
  {
   self->removeTexture(name);
  }
 }
 return 0;
tolua_lerror:
 return tolua_opengl_wyTextureManager_removeTexture00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: removeTexture of class  wyTextureManager */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTextureManager_removeTexture02
static int tolua_opengl_wyTextureManager_removeTexture02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTextureManager",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyTexture2D",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,3,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  wyTextureManager* self = (wyTextureManager*)  tolua_tousertype(tolua_S,1,0);
  wyTexture2D* tex = ((wyTexture2D*)  tolua_tousertype(tolua_S,2,0));
  bool removeHandle = ((bool)  tolua_toboolean(tolua_S,3,false));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'removeTexture'", NULL);
#endif
  {
   self->removeTexture(tex,removeHandle);
  }
 }
 return 0;
tolua_lerror:
 return tolua_opengl_wyTextureManager_removeTexture01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: setTexturePixelFormat of class  wyTextureManager */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTextureManager_setTexturePixelFormat00
static int tolua_opengl_wyTextureManager_setTexturePixelFormat00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTextureManager",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTextureManager* self = (wyTextureManager*)  tolua_tousertype(tolua_S,1,0);
  wyTexturePixelFormat pixelFormat = ((wyTexturePixelFormat) (int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setTexturePixelFormat'", NULL);
#endif
  {
   self->setTexturePixelFormat(pixelFormat);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setTexturePixelFormat'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getTexturePixelFormat of class  wyTextureManager */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTextureManager_getTexturePixelFormat00
static int tolua_opengl_wyTextureManager_getTexturePixelFormat00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTextureManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTextureManager* self = (wyTextureManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getTexturePixelFormat'", NULL);
#endif
  {
   wyTexturePixelFormat tolua_ret = (wyTexturePixelFormat)  self->getTexturePixelFormat();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getTexturePixelFormat'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: make of class  wyTextureAtlas */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTextureAtlas_make00
static int tolua_opengl_wyTextureAtlas_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyTextureAtlas",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyTexture2D",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTexture2D* tex = ((wyTexture2D*)  tolua_tousertype(tolua_S,2,0));
  {
   wyTextureAtlas* tolua_ret = (wyTextureAtlas*)  wyTextureAtlas::make(tex);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyTextureAtlas");
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

/* method: new of class  wyTextureAtlas */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTextureAtlas_new00
static int tolua_opengl_wyTextureAtlas_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyTextureAtlas",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyTexture2D",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTexture2D* tex = ((wyTexture2D*)  tolua_tousertype(tolua_S,2,0));
  int capacity = ((int)  tolua_tonumber(tolua_S,3,ATLAS_DEFAULT_CAPACITY));
  {
   wyTextureAtlas* tolua_ret = (wyTextureAtlas*)  Mtolua_new((wyTextureAtlas)(tex,capacity));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyTextureAtlas");
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

/* method: new_local of class  wyTextureAtlas */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTextureAtlas_new00_local
static int tolua_opengl_wyTextureAtlas_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyTextureAtlas",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyTexture2D",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTexture2D* tex = ((wyTexture2D*)  tolua_tousertype(tolua_S,2,0));
  int capacity = ((int)  tolua_tonumber(tolua_S,3,ATLAS_DEFAULT_CAPACITY));
  {
   wyTextureAtlas* tolua_ret = (wyTextureAtlas*)  Mtolua_new((wyTextureAtlas)(tex,capacity));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyTextureAtlas");
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

/* method: delete of class  wyTextureAtlas */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTextureAtlas_delete00
static int tolua_opengl_wyTextureAtlas_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTextureAtlas",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTextureAtlas* self = (wyTextureAtlas*)  tolua_tousertype(tolua_S,1,0);
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

/* method: setTexture of class  wyTextureAtlas */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTextureAtlas_setTexture00
static int tolua_opengl_wyTextureAtlas_setTexture00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTextureAtlas",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyTexture2D",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTextureAtlas* self = (wyTextureAtlas*)  tolua_tousertype(tolua_S,1,0);
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

/* method: getTexture of class  wyTextureAtlas */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTextureAtlas_getTexture00
static int tolua_opengl_wyTextureAtlas_getTexture00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTextureAtlas",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTextureAtlas* self = (wyTextureAtlas*)  tolua_tousertype(tolua_S,1,0);
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

/* method: resizeCapacity of class  wyTextureAtlas */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTextureAtlas_resizeCapacity00
static int tolua_opengl_wyTextureAtlas_resizeCapacity00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTextureAtlas",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTextureAtlas* self = (wyTextureAtlas*)  tolua_tousertype(tolua_S,1,0);
  int newCapacity = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'resizeCapacity'", NULL);
#endif
  {
   self->resizeCapacity(newCapacity);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'resizeCapacity'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: removeAllQuads of class  wyTextureAtlas */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTextureAtlas_removeAllQuads00
static int tolua_opengl_wyTextureAtlas_removeAllQuads00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTextureAtlas",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTextureAtlas* self = (wyTextureAtlas*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'removeAllQuads'", NULL);
#endif
  {
   self->removeAllQuads();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'removeAllQuads'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getNextAvailableIndex of class  wyTextureAtlas */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTextureAtlas_getNextAvailableIndex00
static int tolua_opengl_wyTextureAtlas_getNextAvailableIndex00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTextureAtlas",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTextureAtlas* self = (wyTextureAtlas*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getNextAvailableIndex'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getNextAvailableIndex();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getNextAvailableIndex'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: updateQuad of class  wyTextureAtlas */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTextureAtlas_updateQuad00
static int tolua_opengl_wyTextureAtlas_updateQuad00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTextureAtlas",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"wyQuad2D",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"wyQuad3D",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTextureAtlas* self = (wyTextureAtlas*)  tolua_tousertype(tolua_S,1,0);
  wyQuad2D* quadT = ((wyQuad2D*)  tolua_tousertype(tolua_S,2,0));
  wyQuad3D* quadV = ((wyQuad3D*)  tolua_tousertype(tolua_S,3,0));
  int index = ((int)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'updateQuad'", NULL);
#endif
  {
   self->updateQuad(*quadT,*quadV,index);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'updateQuad'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: updateColor of class  wyTextureAtlas */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTextureAtlas_updateColor00
static int tolua_opengl_wyTextureAtlas_updateColor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTextureAtlas",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"wyColor4B",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTextureAtlas* self = (wyTextureAtlas*)  tolua_tousertype(tolua_S,1,0);
  wyColor4B color = *((wyColor4B*)  tolua_tousertype(tolua_S,2,0));
  int index = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'updateColor'", NULL);
#endif
  {
   self->updateColor(color,index);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'updateColor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: appendQuad of class  wyTextureAtlas */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTextureAtlas_appendQuad00
static int tolua_opengl_wyTextureAtlas_appendQuad00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTextureAtlas",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"wyQuad2D",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"wyQuad3D",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTextureAtlas* self = (wyTextureAtlas*)  tolua_tousertype(tolua_S,1,0);
  wyQuad2D* quadT = ((wyQuad2D*)  tolua_tousertype(tolua_S,2,0));
  wyQuad3D* quadV = ((wyQuad3D*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'appendQuad'", NULL);
#endif
  {
   int tolua_ret = (int)  self->appendQuad(*quadT,*quadV);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'appendQuad'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: insertQuad of class  wyTextureAtlas */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTextureAtlas_insertQuad00
static int tolua_opengl_wyTextureAtlas_insertQuad00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTextureAtlas",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"wyQuad2D",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"wyQuad3D",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTextureAtlas* self = (wyTextureAtlas*)  tolua_tousertype(tolua_S,1,0);
  wyQuad2D* quadT = ((wyQuad2D*)  tolua_tousertype(tolua_S,2,0));
  wyQuad3D* quadV = ((wyQuad3D*)  tolua_tousertype(tolua_S,3,0));
  int index = ((int)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'insertQuad'", NULL);
#endif
  {
   self->insertQuad(*quadT,*quadV,index);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'insertQuad'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: removeQuad of class  wyTextureAtlas */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTextureAtlas_removeQuad00
static int tolua_opengl_wyTextureAtlas_removeQuad00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTextureAtlas",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTextureAtlas* self = (wyTextureAtlas*)  tolua_tousertype(tolua_S,1,0);
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'removeQuad'", NULL);
#endif
  {
   self->removeQuad(index);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'removeQuad'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: removeQuads of class  wyTextureAtlas */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTextureAtlas_removeQuads00
static int tolua_opengl_wyTextureAtlas_removeQuads00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTextureAtlas",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTextureAtlas* self = (wyTextureAtlas*)  tolua_tousertype(tolua_S,1,0);
  int start = ((int)  tolua_tonumber(tolua_S,2,0));
  int count = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'removeQuads'", NULL);
#endif
  {
   self->removeQuads(start,count);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'removeQuads'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: copyTo of class  wyTextureAtlas */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTextureAtlas_copyTo00
static int tolua_opengl_wyTextureAtlas_copyTo00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTextureAtlas",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"wyTextureAtlas",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTextureAtlas* self = (wyTextureAtlas*)  tolua_tousertype(tolua_S,1,0);
  int from = ((int)  tolua_tonumber(tolua_S,2,0));
  wyTextureAtlas* destAtlas = ((wyTextureAtlas*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'copyTo'", NULL);
#endif
  {
   self->copyTo(from,destAtlas);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'copyTo'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: copyTo of class  wyTextureAtlas */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTextureAtlas_copyTo01
static int tolua_opengl_wyTextureAtlas_copyTo01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTextureAtlas",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"wyQuad2D",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,4,"wyQuad3D",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  wyTextureAtlas* self = (wyTextureAtlas*)  tolua_tousertype(tolua_S,1,0);
  int from = ((int)  tolua_tonumber(tolua_S,2,0));
  wyQuad2D* quadT = ((wyQuad2D*)  tolua_tousertype(tolua_S,3,0));
  wyQuad3D* quadV = ((wyQuad3D*)  tolua_tousertype(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'copyTo'", NULL);
#endif
  {
   self->copyTo(from,quadT,quadV);
  }
 }
 return 0;
tolua_lerror:
 return tolua_opengl_wyTextureAtlas_copyTo00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: drawOne of class  wyTextureAtlas */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTextureAtlas_drawOne00
static int tolua_opengl_wyTextureAtlas_drawOne00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTextureAtlas",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTextureAtlas* self = (wyTextureAtlas*)  tolua_tousertype(tolua_S,1,0);
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'drawOne'", NULL);
#endif
  {
   self->drawOne(index);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'drawOne'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: draw of class  wyTextureAtlas */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTextureAtlas_draw00
static int tolua_opengl_wyTextureAtlas_draw00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTextureAtlas",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTextureAtlas* self = (wyTextureAtlas*)  tolua_tousertype(tolua_S,1,0);
  int numOfQuads = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'draw'", NULL);
#endif
  {
   self->draw(numOfQuads);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'draw'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: drawRange of class  wyTextureAtlas */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTextureAtlas_drawRange00
static int tolua_opengl_wyTextureAtlas_drawRange00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTextureAtlas",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTextureAtlas* self = (wyTextureAtlas*)  tolua_tousertype(tolua_S,1,0);
  int start = ((int)  tolua_tonumber(tolua_S,2,0));
  int numOfQuads = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'drawRange'", NULL);
#endif
  {
   self->drawRange(start,numOfQuads);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'drawRange'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: drawAll of class  wyTextureAtlas */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTextureAtlas_drawAll00
static int tolua_opengl_wyTextureAtlas_drawAll00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTextureAtlas",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTextureAtlas* self = (wyTextureAtlas*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'drawAll'", NULL);
#endif
  {
   self->drawAll();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'drawAll'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getTotalQuads of class  wyTextureAtlas */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTextureAtlas_getTotalQuads00
static int tolua_opengl_wyTextureAtlas_getTotalQuads00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTextureAtlas",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTextureAtlas* self = (wyTextureAtlas*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getTotalQuads'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getTotalQuads();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getTotalQuads'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isWithColorArray of class  wyTextureAtlas */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTextureAtlas_isWithColorArray00
static int tolua_opengl_wyTextureAtlas_isWithColorArray00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTextureAtlas",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTextureAtlas* self = (wyTextureAtlas*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isWithColorArray'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isWithColorArray();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isWithColorArray'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getCapacity of class  wyTextureAtlas */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTextureAtlas_getCapacity00
static int tolua_opengl_wyTextureAtlas_getCapacity00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTextureAtlas",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTextureAtlas* self = (wyTextureAtlas*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getCapacity'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getCapacity();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getCapacity'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getPixelHeight of class  wyTextureAtlas */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTextureAtlas_getPixelHeight00
static int tolua_opengl_wyTextureAtlas_getPixelHeight00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTextureAtlas",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTextureAtlas* self = (wyTextureAtlas*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getPixelHeight'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getPixelHeight();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getPixelHeight'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getPixelWidth of class  wyTextureAtlas */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTextureAtlas_getPixelWidth00
static int tolua_opengl_wyTextureAtlas_getPixelWidth00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTextureAtlas",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTextureAtlas* self = (wyTextureAtlas*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getPixelWidth'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getPixelWidth();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getPixelWidth'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getWidth of class  wyTextureAtlas */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTextureAtlas_getWidth00
static int tolua_opengl_wyTextureAtlas_getWidth00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTextureAtlas",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTextureAtlas* self = (wyTextureAtlas*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getWidth'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getWidth();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getWidth'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getHeight of class  wyTextureAtlas */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTextureAtlas_getHeight00
static int tolua_opengl_wyTextureAtlas_getHeight00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTextureAtlas",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTextureAtlas* self = (wyTextureAtlas*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getHeight'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getHeight();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getHeight'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getWidthScale of class  wyTextureAtlas */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTextureAtlas_getWidthScale00
static int tolua_opengl_wyTextureAtlas_getWidthScale00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTextureAtlas",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTextureAtlas* self = (wyTextureAtlas*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getWidthScale'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getWidthScale();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getWidthScale'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getHeightScale of class  wyTextureAtlas */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTextureAtlas_getHeightScale00
static int tolua_opengl_wyTextureAtlas_getHeightScale00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTextureAtlas",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTextureAtlas* self = (wyTextureAtlas*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getHeightScale'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getHeightScale();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getHeightScale'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setColor of class  wyTextureAtlas */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTextureAtlas_setColor00
static int tolua_opengl_wyTextureAtlas_setColor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTextureAtlas",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"wyColor4B",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTextureAtlas* self = (wyTextureAtlas*)  tolua_tousertype(tolua_S,1,0);
  wyColor4B color = *((wyColor4B*)  tolua_tousertype(tolua_S,2,0));
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

/* method: reduceAlpha of class  wyTextureAtlas */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTextureAtlas_reduceAlpha00
static int tolua_opengl_wyTextureAtlas_reduceAlpha00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTextureAtlas",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTextureAtlas* self = (wyTextureAtlas*)  tolua_tousertype(tolua_S,1,0);
  float delta = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'reduceAlpha'", NULL);
#endif
  {
   self->reduceAlpha(delta);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'reduceAlpha'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_opengl_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  tolua_constant(tolua_S,"wyTexture2D::LEFT",wyTexture2D::LEFT);
  tolua_constant(tolua_S,"wyTexture2D::CENTER",wyTexture2D::CENTER);
  tolua_constant(tolua_S,"wyTexture2D::RIGHT",wyTexture2D::RIGHT);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyCamera","wyCamera","wyObject",tolua_collect_wyCamera);
  #else
  tolua_cclass(tolua_S,"wyCamera","wyCamera","wyObject",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyCamera");
   tolua_function(tolua_S,"getZEye",tolua_opengl_wyCamera_getZEye00);
   tolua_function(tolua_S,"make",tolua_opengl_wyCamera_make00);
   tolua_function(tolua_S,"delete",tolua_opengl_wyCamera_delete00);
   tolua_function(tolua_S,"restore",tolua_opengl_wyCamera_restore00);
   tolua_function(tolua_S,"locate",tolua_opengl_wyCamera_locate00);
   tolua_function(tolua_S,"setEye",tolua_opengl_wyCamera_setEye00);
   tolua_function(tolua_S,"setCenter",tolua_opengl_wyCamera_setCenter00);
   tolua_function(tolua_S,"setUp",tolua_opengl_wyCamera_setUp00);
   tolua_function(tolua_S,"getEye",tolua_opengl_wyCamera_getEye00);
   tolua_function(tolua_S,"getCenter",tolua_opengl_wyCamera_getCenter00);
   tolua_function(tolua_S,"getUp",tolua_opengl_wyCamera_getUp00);
   tolua_function(tolua_S,"isDirty",tolua_opengl_wyCamera_isDirty00);
   tolua_function(tolua_S,"setDirty",tolua_opengl_wyCamera_setDirty00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyTexture2D","wyTexture2D","wyObject",tolua_collect_wyTexture2D);
  #else
  tolua_cclass(tolua_S,"wyTexture2D","wyTexture2D","wyObject",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyTexture2D");
   tolua_function(tolua_S,"make",tolua_opengl_wyTexture2D_make00);
   tolua_function(tolua_S,"make",tolua_opengl_wyTexture2D_make01);
   tolua_function(tolua_S,"make",tolua_opengl_wyTexture2D_make02);
   tolua_function(tolua_S,"make",tolua_opengl_wyTexture2D_make03);
   tolua_function(tolua_S,"make",tolua_opengl_wyTexture2D_make04);
   tolua_function(tolua_S,"make",tolua_opengl_wyTexture2D_make05);
   tolua_function(tolua_S,"make",tolua_opengl_wyTexture2D_make06);
   tolua_function(tolua_S,"makeRaw",tolua_opengl_wyTexture2D_makeRaw00);
   tolua_function(tolua_S,"makeRaw",tolua_opengl_wyTexture2D_makeRaw01);
   tolua_function(tolua_S,"makeRaw",tolua_opengl_wyTexture2D_makeRaw02);
   tolua_function(tolua_S,"makeRaw",tolua_opengl_wyTexture2D_makeRaw03);
   tolua_function(tolua_S,"makeMemory",tolua_opengl_wyTexture2D_makeMemory00);
   tolua_function(tolua_S,"makeMemory",tolua_opengl_wyTexture2D_makeMemory01);
   tolua_function(tolua_S,"makeMemory",tolua_opengl_wyTexture2D_makeMemory02);
   tolua_function(tolua_S,"makeMemory",tolua_opengl_wyTexture2D_makeMemory03);
   tolua_function(tolua_S,"makeFile",tolua_opengl_wyTexture2D_makeFile00);
   tolua_function(tolua_S,"makeFile",tolua_opengl_wyTexture2D_makeFile01);
   tolua_function(tolua_S,"makeFile",tolua_opengl_wyTexture2D_makeFile02);
   tolua_function(tolua_S,"makeFile",tolua_opengl_wyTexture2D_makeFile03);
   tolua_function(tolua_S,"makeLabel",tolua_opengl_wyTexture2D_makeLabel00);
   tolua_function(tolua_S,"makeLabel",tolua_opengl_wyTexture2D_makeLabel01);
   tolua_function(tolua_S,"makeGL",tolua_opengl_wyTexture2D_makeGL00);
   tolua_function(tolua_S,"makeRaw8888",tolua_opengl_wyTexture2D_makeRaw888800);
   tolua_function(tolua_S,"makeRaw8888",tolua_opengl_wyTexture2D_makeRaw888801);
   tolua_function(tolua_S,"new",tolua_opengl_wyTexture2D_new00);
   tolua_function(tolua_S,"new_local",tolua_opengl_wyTexture2D_new00_local);
   tolua_function(tolua_S,".call",tolua_opengl_wyTexture2D_new00_local);
   tolua_function(tolua_S,"delete",tolua_opengl_wyTexture2D_delete00);
   tolua_function(tolua_S,"load",tolua_opengl_wyTexture2D_load00);
   tolua_function(tolua_S,"updateLabel",tolua_opengl_wyTexture2D_updateLabel00);
   tolua_function(tolua_S,"updateLabel",tolua_opengl_wyTexture2D_updateLabel01);
   tolua_function(tolua_S,"updateLabel",tolua_opengl_wyTexture2D_updateLabel02);
   tolua_function(tolua_S,"setAntiAlias",tolua_opengl_wyTexture2D_setAntiAlias00);
   tolua_function(tolua_S,"setRepeat",tolua_opengl_wyTexture2D_setRepeat00);
   tolua_function(tolua_S,"setParameters",tolua_opengl_wyTexture2D_setParameters00);
   tolua_function(tolua_S,"applyParameters",tolua_opengl_wyTexture2D_applyParameters00);
   tolua_function(tolua_S,"hasPremultipliedAlpha",tolua_opengl_wyTexture2D_hasPremultipliedAlpha00);
   tolua_function(tolua_S,"draw",tolua_opengl_wyTexture2D_draw00);
   tolua_function(tolua_S,"draw",tolua_opengl_wyTexture2D_draw01);
   tolua_function(tolua_S,"draw",tolua_opengl_wyTexture2D_draw02);
   tolua_function(tolua_S,"draw",tolua_opengl_wyTexture2D_draw03);
   tolua_function(tolua_S,"draw",tolua_opengl_wyTexture2D_draw04);
   tolua_function(tolua_S,"draw",tolua_opengl_wyTexture2D_draw05);
   tolua_function(tolua_S,"draw",tolua_opengl_wyTexture2D_draw06);
   tolua_function(tolua_S,"getWidth",tolua_opengl_wyTexture2D_getWidth00);
   tolua_function(tolua_S,"getHeight",tolua_opengl_wyTexture2D_getHeight00);
   tolua_function(tolua_S,"getPixelWidth",tolua_opengl_wyTexture2D_getPixelWidth00);
   tolua_function(tolua_S,"getPixelHeight",tolua_opengl_wyTexture2D_getPixelHeight00);
   tolua_function(tolua_S,"getWidthScale",tolua_opengl_wyTexture2D_getWidthScale00);
   tolua_function(tolua_S,"getHeightScale",tolua_opengl_wyTexture2D_getHeightScale00);
   tolua_function(tolua_S,"getTexture",tolua_opengl_wyTexture2D_getTexture00);
   tolua_function(tolua_S,"getText",tolua_opengl_wyTexture2D_getText00);
   tolua_function(tolua_S,"getSource",tolua_opengl_wyTexture2D_getSource00);
   tolua_function(tolua_S,"isFlipY",tolua_opengl_wyTexture2D_isFlipY00);
   tolua_function(tolua_S,"isFlipX",tolua_opengl_wyTexture2D_isFlipX00);
   tolua_function(tolua_S,"setFlipX",tolua_opengl_wyTexture2D_setFlipX00);
   tolua_function(tolua_S,"setFlipY",tolua_opengl_wyTexture2D_setFlipY00);
   tolua_function(tolua_S,"updateRaw",tolua_opengl_wyTexture2D_updateRaw00);
   tolua_function(tolua_S,"setColorFilter",tolua_opengl_wyTexture2D_setColorFilter00);
   tolua_function(tolua_S,"applyFilter",tolua_opengl_wyTexture2D_applyFilter00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"wyEventDispatcher","wyEventDispatcher","",NULL);
  tolua_beginmodule(tolua_S,"wyEventDispatcher");
  tolua_endmodule(tolua_S);
  tolua_constant(tolua_S,"SOURCE_INVALID",SOURCE_INVALID);
  tolua_constant(tolua_S,"SOURCE_IMG",SOURCE_IMG);
  tolua_constant(tolua_S,"SOURCE_LABEL",SOURCE_LABEL);
  tolua_constant(tolua_S,"SOURCE_OPENGL",SOURCE_OPENGL);
  tolua_constant(tolua_S,"WY_TEXTURE_PIXEL_FORMAT_RGBA8888",WY_TEXTURE_PIXEL_FORMAT_RGBA8888);
  tolua_constant(tolua_S,"WY_TEXTURE_PIXEL_FORMAT_RGB565",WY_TEXTURE_PIXEL_FORMAT_RGB565);
  tolua_constant(tolua_S,"WY_TEXTURE_PIXEL_FORMAT_RGBA4444",WY_TEXTURE_PIXEL_FORMAT_RGBA4444);
  tolua_constant(tolua_S,"WY_TEXTURE_PIXEL_FORMAT_RGBA5551",WY_TEXTURE_PIXEL_FORMAT_RGBA5551);
  tolua_constant(tolua_S,"WY_TEXTURE_PIXEL_FORMAT_A8",WY_TEXTURE_PIXEL_FORMAT_A8);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyGLTexture2D","wyGLTexture2D","wyObject",tolua_collect_wyGLTexture2D);
  #else
  tolua_cclass(tolua_S,"wyGLTexture2D","wyGLTexture2D","wyObject",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyGLTexture2D");
   tolua_function(tolua_S,"delete",tolua_opengl_wyGLTexture2D_delete00);
  tolua_endmodule(tolua_S);
  tolua_function(tolua_S,"wyDrawPoint",tolua_opengl_wyDrawPoint00);
  tolua_function(tolua_S,"wyDrawPoints",tolua_opengl_wyDrawPoints00);
  tolua_function(tolua_S,"wyDrawLine",tolua_opengl_wyDrawLine00);
  tolua_function(tolua_S,"wyDrawPath",tolua_opengl_wyDrawPath00);
  tolua_function(tolua_S,"wyDrawDashPath",tolua_opengl_wyDrawDashPath00);
  tolua_function(tolua_S,"wyDrawDashLine",tolua_opengl_wyDrawDashLine00);
  tolua_function(tolua_S,"wyDrawPoly",tolua_opengl_wyDrawPoly00);
  tolua_function(tolua_S,"wyDrawRect",tolua_opengl_wyDrawRect00);
  tolua_function(tolua_S,"wyDrawRect2",tolua_opengl_wyDrawRect200);
  tolua_function(tolua_S,"wyDrawCircle",tolua_opengl_wyDrawCircle00);
  tolua_function(tolua_S,"wyDrawBezier",tolua_opengl_wyDrawBezier00);
  tolua_function(tolua_S,"wyDrawLagrange",tolua_opengl_wyDrawLagrange00);
  tolua_function(tolua_S,"wyDrawTexture",tolua_opengl_wyDrawTexture00);
  tolua_function(tolua_S,"wyDrawTexture2",tolua_opengl_wyDrawTexture200);
  tolua_function(tolua_S,"wyDrawSolidPoly",tolua_opengl_wyDrawSolidPoly00);
  tolua_function(tolua_S,"wyDrawSolidRect",tolua_opengl_wyDrawSolidRect00);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyTextureManager","wyTextureManager","wyObject",tolua_collect_wyTextureManager);
  #else
  tolua_cclass(tolua_S,"wyTextureManager","wyTextureManager","wyObject",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyTextureManager");
   tolua_function(tolua_S,"getInstance",tolua_opengl_wyTextureManager_getInstance00);
   tolua_function(tolua_S,"delete",tolua_opengl_wyTextureManager_delete00);
   tolua_function(tolua_S,"removeAllTextures",tolua_opengl_wyTextureManager_removeAllTextures00);
   tolua_function(tolua_S,"removeTexture",tolua_opengl_wyTextureManager_removeTexture00);
   tolua_function(tolua_S,"removeTexture",tolua_opengl_wyTextureManager_removeTexture01);
   tolua_function(tolua_S,"removeTexture",tolua_opengl_wyTextureManager_removeTexture02);
   tolua_function(tolua_S,"setTexturePixelFormat",tolua_opengl_wyTextureManager_setTexturePixelFormat00);
   tolua_function(tolua_S,"getTexturePixelFormat",tolua_opengl_wyTextureManager_getTexturePixelFormat00);
  tolua_endmodule(tolua_S);
  tolua_constant(tolua_S,"ATLAS_DEFAULT_CAPACITY",ATLAS_DEFAULT_CAPACITY);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyTextureAtlas","wyTextureAtlas","wyObject",tolua_collect_wyTextureAtlas);
  #else
  tolua_cclass(tolua_S,"wyTextureAtlas","wyTextureAtlas","wyObject",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyTextureAtlas");
   tolua_function(tolua_S,"make",tolua_opengl_wyTextureAtlas_make00);
   tolua_function(tolua_S,"new",tolua_opengl_wyTextureAtlas_new00);
   tolua_function(tolua_S,"new_local",tolua_opengl_wyTextureAtlas_new00_local);
   tolua_function(tolua_S,".call",tolua_opengl_wyTextureAtlas_new00_local);
   tolua_function(tolua_S,"delete",tolua_opengl_wyTextureAtlas_delete00);
   tolua_function(tolua_S,"setTexture",tolua_opengl_wyTextureAtlas_setTexture00);
   tolua_function(tolua_S,"getTexture",tolua_opengl_wyTextureAtlas_getTexture00);
   tolua_function(tolua_S,"resizeCapacity",tolua_opengl_wyTextureAtlas_resizeCapacity00);
   tolua_function(tolua_S,"removeAllQuads",tolua_opengl_wyTextureAtlas_removeAllQuads00);
   tolua_function(tolua_S,"getNextAvailableIndex",tolua_opengl_wyTextureAtlas_getNextAvailableIndex00);
   tolua_function(tolua_S,"updateQuad",tolua_opengl_wyTextureAtlas_updateQuad00);
   tolua_function(tolua_S,"updateColor",tolua_opengl_wyTextureAtlas_updateColor00);
   tolua_function(tolua_S,"appendQuad",tolua_opengl_wyTextureAtlas_appendQuad00);
   tolua_function(tolua_S,"insertQuad",tolua_opengl_wyTextureAtlas_insertQuad00);
   tolua_function(tolua_S,"removeQuad",tolua_opengl_wyTextureAtlas_removeQuad00);
   tolua_function(tolua_S,"removeQuads",tolua_opengl_wyTextureAtlas_removeQuads00);
   tolua_function(tolua_S,"copyTo",tolua_opengl_wyTextureAtlas_copyTo00);
   tolua_function(tolua_S,"copyTo",tolua_opengl_wyTextureAtlas_copyTo01);
   tolua_function(tolua_S,"drawOne",tolua_opengl_wyTextureAtlas_drawOne00);
   tolua_function(tolua_S,"draw",tolua_opengl_wyTextureAtlas_draw00);
   tolua_function(tolua_S,"drawRange",tolua_opengl_wyTextureAtlas_drawRange00);
   tolua_function(tolua_S,"drawAll",tolua_opengl_wyTextureAtlas_drawAll00);
   tolua_function(tolua_S,"getTotalQuads",tolua_opengl_wyTextureAtlas_getTotalQuads00);
   tolua_function(tolua_S,"isWithColorArray",tolua_opengl_wyTextureAtlas_isWithColorArray00);
   tolua_function(tolua_S,"getCapacity",tolua_opengl_wyTextureAtlas_getCapacity00);
   tolua_function(tolua_S,"getPixelHeight",tolua_opengl_wyTextureAtlas_getPixelHeight00);
   tolua_function(tolua_S,"getPixelWidth",tolua_opengl_wyTextureAtlas_getPixelWidth00);
   tolua_function(tolua_S,"getWidth",tolua_opengl_wyTextureAtlas_getWidth00);
   tolua_function(tolua_S,"getHeight",tolua_opengl_wyTextureAtlas_getHeight00);
   tolua_function(tolua_S,"getWidthScale",tolua_opengl_wyTextureAtlas_getWidthScale00);
   tolua_function(tolua_S,"getHeightScale",tolua_opengl_wyTextureAtlas_getHeightScale00);
   tolua_function(tolua_S,"setColor",tolua_opengl_wyTextureAtlas_setColor00);
   tolua_function(tolua_S,"reduceAlpha",tolua_opengl_wyTextureAtlas_reduceAlpha00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_opengl (lua_State* tolua_S) {
 return tolua_opengl_open(tolua_S);
};
#endif

