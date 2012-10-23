/*
** Lua binding: opengl
** Generated automatically by tolua++-1.0.92 on Tue Oct 23 11:31:27 2012.
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

static int tolua_collect_wyRect (lua_State* tolua_S)
{
 wyRect* self = (wyRect*) tolua_tousertype(tolua_S,1,0);
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
 tolua_usertype(tolua_S,"kmMat4");
 tolua_usertype(tolua_S,"wyCamera");
 tolua_usertype(tolua_S,"wyFontStyle");
 tolua_usertype(tolua_S,"wyTexture2D");
 tolua_usertype(tolua_S,"size_t");
 tolua_usertype(tolua_S,"wyTextureManager");
 tolua_usertype(tolua_S,"wyColor4B");
 tolua_usertype(tolua_S,"wyBezierConfig");
 tolua_usertype(tolua_S,"wyGLTexture2D");
 tolua_usertype(tolua_S,"wyEventDispatcher");
 tolua_usertype(tolua_S,"wyObject");
 tolua_usertype(tolua_S,"wyColorFilter");
 tolua_usertype(tolua_S,"wyRect");
}

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

/* method: restoreCamera of class  wyCamera */
#ifndef TOLUA_DISABLE_tolua_opengl_wyCamera_restoreCamera00
static int tolua_opengl_wyCamera_restoreCamera00(lua_State* tolua_S)
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'restoreCamera'", NULL);
#endif
  {
   self->restoreCamera();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'restoreCamera'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: restoreProjection of class  wyCamera */
#ifndef TOLUA_DISABLE_tolua_opengl_wyCamera_restoreProjection00
static int tolua_opengl_wyCamera_restoreProjection00(lua_State* tolua_S)
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'restoreProjection'", NULL);
#endif
  {
   self->restoreProjection();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'restoreProjection'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: restoreViewport of class  wyCamera */
#ifndef TOLUA_DISABLE_tolua_opengl_wyCamera_restoreViewport00
static int tolua_opengl_wyCamera_restoreViewport00(lua_State* tolua_S)
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'restoreViewport'", NULL);
#endif
  {
   self->restoreViewport();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'restoreViewport'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getViewMatrix of class  wyCamera */
#ifndef TOLUA_DISABLE_tolua_opengl_wyCamera_getViewMatrix00
static int tolua_opengl_wyCamera_getViewMatrix00(lua_State* tolua_S)
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getViewMatrix'", NULL);
#endif
  {
   kmMat4* tolua_ret = (kmMat4*)  self->getViewMatrix();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"kmMat4");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getViewMatrix'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getProjectionMatrix of class  wyCamera */
#ifndef TOLUA_DISABLE_tolua_opengl_wyCamera_getProjectionMatrix00
static int tolua_opengl_wyCamera_getProjectionMatrix00(lua_State* tolua_S)
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getProjectionMatrix'", NULL);
#endif
  {
   kmMat4* tolua_ret = (kmMat4*)  self->getProjectionMatrix();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"kmMat4");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getProjectionMatrix'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getViewportRect of class  wyCamera */
#ifndef TOLUA_DISABLE_tolua_opengl_wyCamera_getViewportRect00
static int tolua_opengl_wyCamera_getViewportRect00(lua_State* tolua_S)
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getViewportRect'", NULL);
#endif
  {
   wyRect tolua_ret = (wyRect)  self->getViewportRect();
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
 tolua_error(tolua_S,"#ferror in function 'getViewportRect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setOrtho of class  wyCamera */
#ifndef TOLUA_DISABLE_tolua_opengl_wyCamera_setOrtho00
static int tolua_opengl_wyCamera_setOrtho00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyCamera",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,7,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,8,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyCamera* self = (wyCamera*)  tolua_tousertype(tolua_S,1,0);
  float l = ((float)  tolua_tonumber(tolua_S,2,0));
  float r = ((float)  tolua_tonumber(tolua_S,3,0));
  float b = ((float)  tolua_tonumber(tolua_S,4,0));
  float t = ((float)  tolua_tonumber(tolua_S,5,0));
  float near = ((float)  tolua_tonumber(tolua_S,6,0));
  float far = ((float)  tolua_tonumber(tolua_S,7,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setOrtho'", NULL);
#endif
  {
   self->setOrtho(l,r,b,t,near,far);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setOrtho'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setPerspective of class  wyCamera */
#ifndef TOLUA_DISABLE_tolua_opengl_wyCamera_setPerspective00
static int tolua_opengl_wyCamera_setPerspective00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyCamera",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
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
  wyCamera* self = (wyCamera*)  tolua_tousertype(tolua_S,1,0);
  float fovy = ((float)  tolua_tonumber(tolua_S,2,0));
  float widthRatio = ((float)  tolua_tonumber(tolua_S,3,0));
  float heightRatio = ((float)  tolua_tonumber(tolua_S,4,0));
  float near = ((float)  tolua_tonumber(tolua_S,5,0));
  float far = ((float)  tolua_tonumber(tolua_S,6,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setPerspective'", NULL);
#endif
  {
   self->setPerspective(fovy,widthRatio,heightRatio,near,far);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setPerspective'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getZEye of class  wyCamera */
#ifndef TOLUA_DISABLE_tolua_opengl_wyCamera_getZEye00
static int tolua_opengl_wyCamera_getZEye00(lua_State* tolua_S)
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getZEye'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getZEye();
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
  float e = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getEye'", NULL);
#endif
  {
   self->getEye(&e);
   tolua_pushnumber(tolua_S,(lua_Number)e);
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
  float c = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getCenter'", NULL);
#endif
  {
   self->getCenter(&c);
   tolua_pushnumber(tolua_S,(lua_Number)c);
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
  float u = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getUp'", NULL);
#endif
  {
   self->getUp(&u);
   tolua_pushnumber(tolua_S,(lua_Number)u);
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

/* method: setUseRelativeValue of class  wyCamera */
#ifndef TOLUA_DISABLE_tolua_opengl_wyCamera_setUseRelativeValue00
static int tolua_opengl_wyCamera_setUseRelativeValue00(lua_State* tolua_S)
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
  bool flag = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setUseRelativeValue'", NULL);
#endif
  {
   self->setUseRelativeValue(flag);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setUseRelativeValue'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setViewport of class  wyCamera */
#ifndef TOLUA_DISABLE_tolua_opengl_wyCamera_setViewport00
static int tolua_opengl_wyCamera_setViewport00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyCamera",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
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
  wyCamera* self = (wyCamera*)  tolua_tousertype(tolua_S,1,0);
  bool relative = ((bool)  tolua_toboolean(tolua_S,2,0));
  float x = ((float)  tolua_tonumber(tolua_S,3,0));
  float y = ((float)  tolua_tonumber(tolua_S,4,0));
  float w = ((float)  tolua_tonumber(tolua_S,5,0));
  float h = ((float)  tolua_tonumber(tolua_S,6,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setViewport'", NULL);
#endif
  {
   self->setViewport(relative,x,y,w,h);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setViewport'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: makeBMP of class  wyTexture2D */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTexture2D_makeBMP00
static int tolua_opengl_wyTexture2D_makeBMP00(lua_State* tolua_S)
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
   wyTexture2D* tolua_ret = (wyTexture2D*)  wyTexture2D::makeBMP(resId);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyTexture2D");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'makeBMP'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: makeBMP of class  wyTexture2D */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTexture2D_makeBMP01
static int tolua_opengl_wyTexture2D_makeBMP01(lua_State* tolua_S)
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
   wyTexture2D* tolua_ret = (wyTexture2D*)  wyTexture2D::makeBMP(resId,transparentColor);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyTexture2D");
  }
 }
 return 1;
tolua_lerror:
 return tolua_opengl_wyTexture2D_makeBMP00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: makeBMP of class  wyTexture2D */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTexture2D_makeBMP02
static int tolua_opengl_wyTexture2D_makeBMP02(lua_State* tolua_S)
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
   wyTexture2D* tolua_ret = (wyTexture2D*)  wyTexture2D::makeBMP(resId,transparentColor,format);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyTexture2D");
  }
 }
 return 1;
tolua_lerror:
 return tolua_opengl_wyTexture2D_makeBMP01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: makeBMP of class  wyTexture2D */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTexture2D_makeBMP03
static int tolua_opengl_wyTexture2D_makeBMP03(lua_State* tolua_S)
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
   wyTexture2D* tolua_ret = (wyTexture2D*)  wyTexture2D::makeBMP(assetPath);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyTexture2D");
  }
 }
 return 1;
tolua_lerror:
 return tolua_opengl_wyTexture2D_makeBMP02(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: makeBMP of class  wyTexture2D */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTexture2D_makeBMP04
static int tolua_opengl_wyTexture2D_makeBMP04(lua_State* tolua_S)
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
   wyTexture2D* tolua_ret = (wyTexture2D*)  wyTexture2D::makeBMP(assetPath,transparentColor);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyTexture2D");
  }
 }
 return 1;
tolua_lerror:
 return tolua_opengl_wyTexture2D_makeBMP03(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: makeBMP of class  wyTexture2D */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTexture2D_makeBMP05
static int tolua_opengl_wyTexture2D_makeBMP05(lua_State* tolua_S)
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
   wyTexture2D* tolua_ret = (wyTexture2D*)  wyTexture2D::makeBMP(assetPath,transparentColor,format);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyTexture2D");
  }
 }
 return 1;
tolua_lerror:
 return tolua_opengl_wyTexture2D_makeBMP04(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: makeBMP of class  wyTexture2D */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTexture2D_makeBMP06
static int tolua_opengl_wyTexture2D_makeBMP06(lua_State* tolua_S)
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
   wyTexture2D* tolua_ret = (wyTexture2D*)  wyTexture2D::makeBMP(assetPath,transparentColor,format,inDensity);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyTexture2D");
  }
 }
 return 1;
tolua_lerror:
 return tolua_opengl_wyTexture2D_makeBMP05(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: makeRawBMP of class  wyTexture2D */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTexture2D_makeRawBMP00
static int tolua_opengl_wyTexture2D_makeRawBMP00(lua_State* tolua_S)
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
   wyTexture2D* tolua_ret = (wyTexture2D*)  wyTexture2D::makeRawBMP(data,length);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyTexture2D");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'makeRawBMP'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: makeRawBMP of class  wyTexture2D */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTexture2D_makeRawBMP01
static int tolua_opengl_wyTexture2D_makeRawBMP01(lua_State* tolua_S)
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
   wyTexture2D* tolua_ret = (wyTexture2D*)  wyTexture2D::makeRawBMP(data,length,transparentColor);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyTexture2D");
  }
 }
 return 1;
tolua_lerror:
 return tolua_opengl_wyTexture2D_makeRawBMP00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: makeRawBMP of class  wyTexture2D */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTexture2D_makeRawBMP02
static int tolua_opengl_wyTexture2D_makeRawBMP02(lua_State* tolua_S)
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
   wyTexture2D* tolua_ret = (wyTexture2D*)  wyTexture2D::makeRawBMP(data,length,transparentColor,format);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyTexture2D");
  }
 }
 return 1;
tolua_lerror:
 return tolua_opengl_wyTexture2D_makeRawBMP01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: makeRawBMP of class  wyTexture2D */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTexture2D_makeRawBMP03
static int tolua_opengl_wyTexture2D_makeRawBMP03(lua_State* tolua_S)
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
   wyTexture2D* tolua_ret = (wyTexture2D*)  wyTexture2D::makeRawBMP(data,length,transparentColor,format,inDensity);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyTexture2D");
  }
 }
 return 1;
tolua_lerror:
 return tolua_opengl_wyTexture2D_makeRawBMP02(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: makeMemoryBMP of class  wyTexture2D */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTexture2D_makeMemoryBMP00
static int tolua_opengl_wyTexture2D_makeMemoryBMP00(lua_State* tolua_S)
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
   wyTexture2D* tolua_ret = (wyTexture2D*)  wyTexture2D::makeMemoryBMP(mfsName);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyTexture2D");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'makeMemoryBMP'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: makeMemoryBMP of class  wyTexture2D */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTexture2D_makeMemoryBMP01
static int tolua_opengl_wyTexture2D_makeMemoryBMP01(lua_State* tolua_S)
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
   wyTexture2D* tolua_ret = (wyTexture2D*)  wyTexture2D::makeMemoryBMP(mfsName,transparentColor);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyTexture2D");
  }
 }
 return 1;
tolua_lerror:
 return tolua_opengl_wyTexture2D_makeMemoryBMP00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: makeMemoryBMP of class  wyTexture2D */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTexture2D_makeMemoryBMP02
static int tolua_opengl_wyTexture2D_makeMemoryBMP02(lua_State* tolua_S)
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
   wyTexture2D* tolua_ret = (wyTexture2D*)  wyTexture2D::makeMemoryBMP(mfsName,transparentColor,format);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyTexture2D");
  }
 }
 return 1;
tolua_lerror:
 return tolua_opengl_wyTexture2D_makeMemoryBMP01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: makeMemoryBMP of class  wyTexture2D */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTexture2D_makeMemoryBMP03
static int tolua_opengl_wyTexture2D_makeMemoryBMP03(lua_State* tolua_S)
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
   wyTexture2D* tolua_ret = (wyTexture2D*)  wyTexture2D::makeMemoryBMP(mfsName,transparentColor,format,inDensity);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyTexture2D");
  }
 }
 return 1;
tolua_lerror:
 return tolua_opengl_wyTexture2D_makeMemoryBMP02(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: makeFileBMP of class  wyTexture2D */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTexture2D_makeFileBMP00
static int tolua_opengl_wyTexture2D_makeFileBMP00(lua_State* tolua_S)
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
   wyTexture2D* tolua_ret = (wyTexture2D*)  wyTexture2D::makeFileBMP(fsPath);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyTexture2D");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'makeFileBMP'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: makeFileBMP of class  wyTexture2D */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTexture2D_makeFileBMP01
static int tolua_opengl_wyTexture2D_makeFileBMP01(lua_State* tolua_S)
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
   wyTexture2D* tolua_ret = (wyTexture2D*)  wyTexture2D::makeFileBMP(fsPath,transparentColor);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyTexture2D");
  }
 }
 return 1;
tolua_lerror:
 return tolua_opengl_wyTexture2D_makeFileBMP00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: makeFileBMP of class  wyTexture2D */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTexture2D_makeFileBMP02
static int tolua_opengl_wyTexture2D_makeFileBMP02(lua_State* tolua_S)
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
   wyTexture2D* tolua_ret = (wyTexture2D*)  wyTexture2D::makeFileBMP(fsPath,transparentColor,format);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyTexture2D");
  }
 }
 return 1;
tolua_lerror:
 return tolua_opengl_wyTexture2D_makeFileBMP01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: makeFileBMP of class  wyTexture2D */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTexture2D_makeFileBMP03
static int tolua_opengl_wyTexture2D_makeFileBMP03(lua_State* tolua_S)
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
   wyTexture2D* tolua_ret = (wyTexture2D*)  wyTexture2D::makeFileBMP(fsPath,transparentColor,format,inDensity);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyTexture2D");
  }
 }
 return 1;
tolua_lerror:
 return tolua_opengl_wyTexture2D_makeFileBMP02(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: makeJPG of class  wyTexture2D */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTexture2D_makeJPG00
static int tolua_opengl_wyTexture2D_makeJPG00(lua_State* tolua_S)
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
   wyTexture2D* tolua_ret = (wyTexture2D*)  wyTexture2D::makeJPG(resId);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyTexture2D");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'makeJPG'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: makeJPG of class  wyTexture2D */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTexture2D_makeJPG01
static int tolua_opengl_wyTexture2D_makeJPG01(lua_State* tolua_S)
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
   wyTexture2D* tolua_ret = (wyTexture2D*)  wyTexture2D::makeJPG(resId,transparentColor);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyTexture2D");
  }
 }
 return 1;
tolua_lerror:
 return tolua_opengl_wyTexture2D_makeJPG00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: makeJPG of class  wyTexture2D */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTexture2D_makeJPG02
static int tolua_opengl_wyTexture2D_makeJPG02(lua_State* tolua_S)
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
   wyTexture2D* tolua_ret = (wyTexture2D*)  wyTexture2D::makeJPG(resId,transparentColor,format);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyTexture2D");
  }
 }
 return 1;
tolua_lerror:
 return tolua_opengl_wyTexture2D_makeJPG01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: makeJPG of class  wyTexture2D */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTexture2D_makeJPG03
static int tolua_opengl_wyTexture2D_makeJPG03(lua_State* tolua_S)
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
   wyTexture2D* tolua_ret = (wyTexture2D*)  wyTexture2D::makeJPG(assetPath);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyTexture2D");
  }
 }
 return 1;
tolua_lerror:
 return tolua_opengl_wyTexture2D_makeJPG02(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: makeJPG of class  wyTexture2D */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTexture2D_makeJPG04
static int tolua_opengl_wyTexture2D_makeJPG04(lua_State* tolua_S)
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
   wyTexture2D* tolua_ret = (wyTexture2D*)  wyTexture2D::makeJPG(assetPath,transparentColor);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyTexture2D");
  }
 }
 return 1;
tolua_lerror:
 return tolua_opengl_wyTexture2D_makeJPG03(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: makeJPG of class  wyTexture2D */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTexture2D_makeJPG05
static int tolua_opengl_wyTexture2D_makeJPG05(lua_State* tolua_S)
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
   wyTexture2D* tolua_ret = (wyTexture2D*)  wyTexture2D::makeJPG(assetPath,transparentColor,format);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyTexture2D");
  }
 }
 return 1;
tolua_lerror:
 return tolua_opengl_wyTexture2D_makeJPG04(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: makeJPG of class  wyTexture2D */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTexture2D_makeJPG06
static int tolua_opengl_wyTexture2D_makeJPG06(lua_State* tolua_S)
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
   wyTexture2D* tolua_ret = (wyTexture2D*)  wyTexture2D::makeJPG(assetPath,transparentColor,format,inDensity);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyTexture2D");
  }
 }
 return 1;
tolua_lerror:
 return tolua_opengl_wyTexture2D_makeJPG05(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: makeRawJPG of class  wyTexture2D */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTexture2D_makeRawJPG00
static int tolua_opengl_wyTexture2D_makeRawJPG00(lua_State* tolua_S)
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
   wyTexture2D* tolua_ret = (wyTexture2D*)  wyTexture2D::makeRawJPG(data,length);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyTexture2D");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'makeRawJPG'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: makeRawJPG of class  wyTexture2D */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTexture2D_makeRawJPG01
static int tolua_opengl_wyTexture2D_makeRawJPG01(lua_State* tolua_S)
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
   wyTexture2D* tolua_ret = (wyTexture2D*)  wyTexture2D::makeRawJPG(data,length,transparentColor);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyTexture2D");
  }
 }
 return 1;
tolua_lerror:
 return tolua_opengl_wyTexture2D_makeRawJPG00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: makeRawJPG of class  wyTexture2D */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTexture2D_makeRawJPG02
static int tolua_opengl_wyTexture2D_makeRawJPG02(lua_State* tolua_S)
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
   wyTexture2D* tolua_ret = (wyTexture2D*)  wyTexture2D::makeRawJPG(data,length,transparentColor,format);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyTexture2D");
  }
 }
 return 1;
tolua_lerror:
 return tolua_opengl_wyTexture2D_makeRawJPG01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: makeRawJPG of class  wyTexture2D */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTexture2D_makeRawJPG03
static int tolua_opengl_wyTexture2D_makeRawJPG03(lua_State* tolua_S)
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
   wyTexture2D* tolua_ret = (wyTexture2D*)  wyTexture2D::makeRawJPG(data,length,transparentColor,format,inDensity);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyTexture2D");
  }
 }
 return 1;
tolua_lerror:
 return tolua_opengl_wyTexture2D_makeRawJPG02(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: makeMemoryJPG of class  wyTexture2D */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTexture2D_makeMemoryJPG00
static int tolua_opengl_wyTexture2D_makeMemoryJPG00(lua_State* tolua_S)
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
   wyTexture2D* tolua_ret = (wyTexture2D*)  wyTexture2D::makeMemoryJPG(mfsName);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyTexture2D");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'makeMemoryJPG'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: makeMemoryJPG of class  wyTexture2D */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTexture2D_makeMemoryJPG01
static int tolua_opengl_wyTexture2D_makeMemoryJPG01(lua_State* tolua_S)
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
   wyTexture2D* tolua_ret = (wyTexture2D*)  wyTexture2D::makeMemoryJPG(mfsName,transparentColor);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyTexture2D");
  }
 }
 return 1;
tolua_lerror:
 return tolua_opengl_wyTexture2D_makeMemoryJPG00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: makeMemoryJPG of class  wyTexture2D */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTexture2D_makeMemoryJPG02
static int tolua_opengl_wyTexture2D_makeMemoryJPG02(lua_State* tolua_S)
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
   wyTexture2D* tolua_ret = (wyTexture2D*)  wyTexture2D::makeMemoryJPG(mfsName,transparentColor,format);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyTexture2D");
  }
 }
 return 1;
tolua_lerror:
 return tolua_opengl_wyTexture2D_makeMemoryJPG01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: makeMemoryJPG of class  wyTexture2D */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTexture2D_makeMemoryJPG03
static int tolua_opengl_wyTexture2D_makeMemoryJPG03(lua_State* tolua_S)
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
   wyTexture2D* tolua_ret = (wyTexture2D*)  wyTexture2D::makeMemoryJPG(mfsName,transparentColor,format,inDensity);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyTexture2D");
  }
 }
 return 1;
tolua_lerror:
 return tolua_opengl_wyTexture2D_makeMemoryJPG02(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: makeFileJPG of class  wyTexture2D */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTexture2D_makeFileJPG00
static int tolua_opengl_wyTexture2D_makeFileJPG00(lua_State* tolua_S)
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
   wyTexture2D* tolua_ret = (wyTexture2D*)  wyTexture2D::makeFileJPG(fsPath);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyTexture2D");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'makeFileJPG'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: makeFileJPG of class  wyTexture2D */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTexture2D_makeFileJPG01
static int tolua_opengl_wyTexture2D_makeFileJPG01(lua_State* tolua_S)
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
   wyTexture2D* tolua_ret = (wyTexture2D*)  wyTexture2D::makeFileJPG(fsPath,transparentColor);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyTexture2D");
  }
 }
 return 1;
tolua_lerror:
 return tolua_opengl_wyTexture2D_makeFileJPG00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: makeFileJPG of class  wyTexture2D */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTexture2D_makeFileJPG02
static int tolua_opengl_wyTexture2D_makeFileJPG02(lua_State* tolua_S)
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
   wyTexture2D* tolua_ret = (wyTexture2D*)  wyTexture2D::makeFileJPG(fsPath,transparentColor,format);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyTexture2D");
  }
 }
 return 1;
tolua_lerror:
 return tolua_opengl_wyTexture2D_makeFileJPG01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: makeFileJPG of class  wyTexture2D */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTexture2D_makeFileJPG03
static int tolua_opengl_wyTexture2D_makeFileJPG03(lua_State* tolua_S)
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
   wyTexture2D* tolua_ret = (wyTexture2D*)  wyTexture2D::makeFileJPG(fsPath,transparentColor,format,inDensity);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyTexture2D");
  }
 }
 return 1;
tolua_lerror:
 return tolua_opengl_wyTexture2D_makeFileJPG02(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: makePNG of class  wyTexture2D */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTexture2D_makePNG00
static int tolua_opengl_wyTexture2D_makePNG00(lua_State* tolua_S)
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
   wyTexture2D* tolua_ret = (wyTexture2D*)  wyTexture2D::makePNG(resId);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyTexture2D");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'makePNG'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: makePNG of class  wyTexture2D */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTexture2D_makePNG01
static int tolua_opengl_wyTexture2D_makePNG01(lua_State* tolua_S)
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
  wyTexturePixelFormat format = ((wyTexturePixelFormat) (int)  tolua_tonumber(tolua_S,3,0));
  {
   wyTexture2D* tolua_ret = (wyTexture2D*)  wyTexture2D::makePNG(resId,format);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyTexture2D");
  }
 }
 return 1;
tolua_lerror:
 return tolua_opengl_wyTexture2D_makePNG00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: makePNG of class  wyTexture2D */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTexture2D_makePNG02
static int tolua_opengl_wyTexture2D_makePNG02(lua_State* tolua_S)
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
   wyTexture2D* tolua_ret = (wyTexture2D*)  wyTexture2D::makePNG(assetPath);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyTexture2D");
  }
 }
 return 1;
tolua_lerror:
 return tolua_opengl_wyTexture2D_makePNG01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: makePNG of class  wyTexture2D */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTexture2D_makePNG03
static int tolua_opengl_wyTexture2D_makePNG03(lua_State* tolua_S)
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
  wyTexturePixelFormat format = ((wyTexturePixelFormat) (int)  tolua_tonumber(tolua_S,3,0));
  {
   wyTexture2D* tolua_ret = (wyTexture2D*)  wyTexture2D::makePNG(assetPath,format);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyTexture2D");
  }
 }
 return 1;
tolua_lerror:
 return tolua_opengl_wyTexture2D_makePNG02(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: makePNG of class  wyTexture2D */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTexture2D_makePNG04
static int tolua_opengl_wyTexture2D_makePNG04(lua_State* tolua_S)
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
  wyTexturePixelFormat format = ((wyTexturePixelFormat) (int)  tolua_tonumber(tolua_S,3,0));
  float inDensity = ((float)  tolua_tonumber(tolua_S,4,0));
  {
   wyTexture2D* tolua_ret = (wyTexture2D*)  wyTexture2D::makePNG(assetPath,format,inDensity);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyTexture2D");
  }
 }
 return 1;
tolua_lerror:
 return tolua_opengl_wyTexture2D_makePNG03(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: makeRawPNG of class  wyTexture2D */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTexture2D_makeRawPNG00
static int tolua_opengl_wyTexture2D_makeRawPNG00(lua_State* tolua_S)
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
   wyTexture2D* tolua_ret = (wyTexture2D*)  wyTexture2D::makeRawPNG(data,length);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyTexture2D");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'makeRawPNG'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: makeRawPNG of class  wyTexture2D */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTexture2D_makeRawPNG01
static int tolua_opengl_wyTexture2D_makeRawPNG01(lua_State* tolua_S)
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
  wyTexturePixelFormat format = ((wyTexturePixelFormat) (int)  tolua_tonumber(tolua_S,4,0));
  {
   wyTexture2D* tolua_ret = (wyTexture2D*)  wyTexture2D::makeRawPNG(data,length,format);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyTexture2D");
  }
 }
 return 1;
tolua_lerror:
 return tolua_opengl_wyTexture2D_makeRawPNG00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: makeRawPNG of class  wyTexture2D */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTexture2D_makeRawPNG02
static int tolua_opengl_wyTexture2D_makeRawPNG02(lua_State* tolua_S)
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
  wyTexturePixelFormat format = ((wyTexturePixelFormat) (int)  tolua_tonumber(tolua_S,4,0));
  float inDensity = ((float)  tolua_tonumber(tolua_S,5,0));
  {
   wyTexture2D* tolua_ret = (wyTexture2D*)  wyTexture2D::makeRawPNG(data,length,format,inDensity);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyTexture2D");
  }
 }
 return 1;
tolua_lerror:
 return tolua_opengl_wyTexture2D_makeRawPNG01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: makeMemoryPNG of class  wyTexture2D */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTexture2D_makeMemoryPNG00
static int tolua_opengl_wyTexture2D_makeMemoryPNG00(lua_State* tolua_S)
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
   wyTexture2D* tolua_ret = (wyTexture2D*)  wyTexture2D::makeMemoryPNG(mfsName);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyTexture2D");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'makeMemoryPNG'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: makeMemoryPNG of class  wyTexture2D */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTexture2D_makeMemoryPNG01
static int tolua_opengl_wyTexture2D_makeMemoryPNG01(lua_State* tolua_S)
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
  wyTexturePixelFormat format = ((wyTexturePixelFormat) (int)  tolua_tonumber(tolua_S,3,0));
  {
   wyTexture2D* tolua_ret = (wyTexture2D*)  wyTexture2D::makeMemoryPNG(mfsName,format);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyTexture2D");
  }
 }
 return 1;
tolua_lerror:
 return tolua_opengl_wyTexture2D_makeMemoryPNG00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: makeMemoryPNG of class  wyTexture2D */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTexture2D_makeMemoryPNG02
static int tolua_opengl_wyTexture2D_makeMemoryPNG02(lua_State* tolua_S)
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
  wyTexturePixelFormat format = ((wyTexturePixelFormat) (int)  tolua_tonumber(tolua_S,3,0));
  float inDensity = ((float)  tolua_tonumber(tolua_S,4,0));
  {
   wyTexture2D* tolua_ret = (wyTexture2D*)  wyTexture2D::makeMemoryPNG(mfsName,format,inDensity);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyTexture2D");
  }
 }
 return 1;
tolua_lerror:
 return tolua_opengl_wyTexture2D_makeMemoryPNG01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: makeFilePNG of class  wyTexture2D */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTexture2D_makeFilePNG00
static int tolua_opengl_wyTexture2D_makeFilePNG00(lua_State* tolua_S)
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
   wyTexture2D* tolua_ret = (wyTexture2D*)  wyTexture2D::makeFilePNG(fsPath);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyTexture2D");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'makeFilePNG'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: makeFilePNG of class  wyTexture2D */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTexture2D_makeFilePNG01
static int tolua_opengl_wyTexture2D_makeFilePNG01(lua_State* tolua_S)
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
  wyTexturePixelFormat format = ((wyTexturePixelFormat) (int)  tolua_tonumber(tolua_S,3,0));
  {
   wyTexture2D* tolua_ret = (wyTexture2D*)  wyTexture2D::makeFilePNG(fsPath,format);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyTexture2D");
  }
 }
 return 1;
tolua_lerror:
 return tolua_opengl_wyTexture2D_makeFilePNG00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: makeFilePNG of class  wyTexture2D */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTexture2D_makeFilePNG02
static int tolua_opengl_wyTexture2D_makeFilePNG02(lua_State* tolua_S)
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
  wyTexturePixelFormat format = ((wyTexturePixelFormat) (int)  tolua_tonumber(tolua_S,3,0));
  float inDensity = ((float)  tolua_tonumber(tolua_S,4,0));
  {
   wyTexture2D* tolua_ret = (wyTexture2D*)  wyTexture2D::makeFilePNG(fsPath,format,inDensity);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyTexture2D");
  }
 }
 return 1;
tolua_lerror:
 return tolua_opengl_wyTexture2D_makeFilePNG01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: makePVR of class  wyTexture2D */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTexture2D_makePVR00
static int tolua_opengl_wyTexture2D_makePVR00(lua_State* tolua_S)
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
   wyTexture2D* tolua_ret = (wyTexture2D*)  wyTexture2D::makePVR(resId);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyTexture2D");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'makePVR'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: makePVR of class  wyTexture2D */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTexture2D_makePVR01
static int tolua_opengl_wyTexture2D_makePVR01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyTexture2D",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const char* assetPath = ((const char*)  tolua_tostring(tolua_S,2,0));
  float inDensity = ((float)  tolua_tonumber(tolua_S,3,0));
  {
   wyTexture2D* tolua_ret = (wyTexture2D*)  wyTexture2D::makePVR(assetPath,inDensity);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyTexture2D");
  }
 }
 return 1;
tolua_lerror:
 return tolua_opengl_wyTexture2D_makePVR00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: makeRawPVR of class  wyTexture2D */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTexture2D_makeRawPVR00
static int tolua_opengl_wyTexture2D_makeRawPVR00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyTexture2D",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"size_t",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,4,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* data = ((const char*)  tolua_tostring(tolua_S,2,0));
  size_t length = *((size_t*)  tolua_tousertype(tolua_S,3,0));
  float inDensity = ((float)  tolua_tonumber(tolua_S,4,0));
  {
   wyTexture2D* tolua_ret = (wyTexture2D*)  wyTexture2D::makeRawPVR(data,length,inDensity);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyTexture2D");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'makeRawPVR'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: makeMemoryPVR of class  wyTexture2D */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTexture2D_makeMemoryPVR00
static int tolua_opengl_wyTexture2D_makeMemoryPVR00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyTexture2D",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* mfsName = ((const char*)  tolua_tostring(tolua_S,2,0));
  float inDensity = ((float)  tolua_tonumber(tolua_S,3,0));
  {
   wyTexture2D* tolua_ret = (wyTexture2D*)  wyTexture2D::makeMemoryPVR(mfsName,inDensity);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyTexture2D");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'makeMemoryPVR'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: makeFilePVR of class  wyTexture2D */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTexture2D_makeFilePVR00
static int tolua_opengl_wyTexture2D_makeFilePVR00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyTexture2D",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* fsPath = ((const char*)  tolua_tostring(tolua_S,2,0));
  float inDensity = ((float)  tolua_tonumber(tolua_S,3,0));
  {
   wyTexture2D* tolua_ret = (wyTexture2D*)  wyTexture2D::makeFilePVR(fsPath,inDensity);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyTexture2D");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'makeFilePVR'.",&tolua_err);
 return 0;
#endif
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

/* method: makeRaw of class  wyTexture2D */
#ifndef TOLUA_DISABLE_tolua_opengl_wyTexture2D_makeRaw00
static int tolua_opengl_wyTexture2D_makeRaw00(lua_State* tolua_S)
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
   wyTexture2D* tolua_ret = (wyTexture2D*)  wyTexture2D::makeRaw(data,width,height);
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
   wyTexture2D* tolua_ret = (wyTexture2D*)  wyTexture2D::makeRaw(data,width,height,format);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyTexture2D");
  }
 }
 return 1;
tolua_lerror:
 return tolua_opengl_wyTexture2D_makeRaw00(tolua_S);
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
  tolua_cclass(tolua_S,"wyCamera","wyCamera","wyObject",NULL);
  tolua_beginmodule(tolua_S,"wyCamera");
   tolua_function(tolua_S,"make",tolua_opengl_wyCamera_make00);
   tolua_function(tolua_S,"restoreCamera",tolua_opengl_wyCamera_restoreCamera00);
   tolua_function(tolua_S,"restoreProjection",tolua_opengl_wyCamera_restoreProjection00);
   tolua_function(tolua_S,"restoreViewport",tolua_opengl_wyCamera_restoreViewport00);
   tolua_function(tolua_S,"getViewMatrix",tolua_opengl_wyCamera_getViewMatrix00);
   tolua_function(tolua_S,"getProjectionMatrix",tolua_opengl_wyCamera_getProjectionMatrix00);
   tolua_function(tolua_S,"getViewportRect",tolua_opengl_wyCamera_getViewportRect00);
   tolua_function(tolua_S,"setOrtho",tolua_opengl_wyCamera_setOrtho00);
   tolua_function(tolua_S,"setPerspective",tolua_opengl_wyCamera_setPerspective00);
   tolua_function(tolua_S,"getZEye",tolua_opengl_wyCamera_getZEye00);
   tolua_function(tolua_S,"getEye",tolua_opengl_wyCamera_getEye00);
   tolua_function(tolua_S,"setEye",tolua_opengl_wyCamera_setEye00);
   tolua_function(tolua_S,"getCenter",tolua_opengl_wyCamera_getCenter00);
   tolua_function(tolua_S,"setCenter",tolua_opengl_wyCamera_setCenter00);
   tolua_function(tolua_S,"getUp",tolua_opengl_wyCamera_getUp00);
   tolua_function(tolua_S,"setUp",tolua_opengl_wyCamera_setUp00);
   tolua_function(tolua_S,"setUseRelativeValue",tolua_opengl_wyCamera_setUseRelativeValue00);
   tolua_function(tolua_S,"setViewport",tolua_opengl_wyCamera_setViewport00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyTexture2D","wyTexture2D","wyObject",tolua_collect_wyTexture2D);
  #else
  tolua_cclass(tolua_S,"wyTexture2D","wyTexture2D","wyObject",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyTexture2D");
   tolua_function(tolua_S,"makeBMP",tolua_opengl_wyTexture2D_makeBMP00);
   tolua_function(tolua_S,"makeBMP",tolua_opengl_wyTexture2D_makeBMP01);
   tolua_function(tolua_S,"makeBMP",tolua_opengl_wyTexture2D_makeBMP02);
   tolua_function(tolua_S,"makeBMP",tolua_opengl_wyTexture2D_makeBMP03);
   tolua_function(tolua_S,"makeBMP",tolua_opengl_wyTexture2D_makeBMP04);
   tolua_function(tolua_S,"makeBMP",tolua_opengl_wyTexture2D_makeBMP05);
   tolua_function(tolua_S,"makeBMP",tolua_opengl_wyTexture2D_makeBMP06);
   tolua_function(tolua_S,"makeRawBMP",tolua_opengl_wyTexture2D_makeRawBMP00);
   tolua_function(tolua_S,"makeRawBMP",tolua_opengl_wyTexture2D_makeRawBMP01);
   tolua_function(tolua_S,"makeRawBMP",tolua_opengl_wyTexture2D_makeRawBMP02);
   tolua_function(tolua_S,"makeRawBMP",tolua_opengl_wyTexture2D_makeRawBMP03);
   tolua_function(tolua_S,"makeMemoryBMP",tolua_opengl_wyTexture2D_makeMemoryBMP00);
   tolua_function(tolua_S,"makeMemoryBMP",tolua_opengl_wyTexture2D_makeMemoryBMP01);
   tolua_function(tolua_S,"makeMemoryBMP",tolua_opengl_wyTexture2D_makeMemoryBMP02);
   tolua_function(tolua_S,"makeMemoryBMP",tolua_opengl_wyTexture2D_makeMemoryBMP03);
   tolua_function(tolua_S,"makeFileBMP",tolua_opengl_wyTexture2D_makeFileBMP00);
   tolua_function(tolua_S,"makeFileBMP",tolua_opengl_wyTexture2D_makeFileBMP01);
   tolua_function(tolua_S,"makeFileBMP",tolua_opengl_wyTexture2D_makeFileBMP02);
   tolua_function(tolua_S,"makeFileBMP",tolua_opengl_wyTexture2D_makeFileBMP03);
   tolua_function(tolua_S,"makeJPG",tolua_opengl_wyTexture2D_makeJPG00);
   tolua_function(tolua_S,"makeJPG",tolua_opengl_wyTexture2D_makeJPG01);
   tolua_function(tolua_S,"makeJPG",tolua_opengl_wyTexture2D_makeJPG02);
   tolua_function(tolua_S,"makeJPG",tolua_opengl_wyTexture2D_makeJPG03);
   tolua_function(tolua_S,"makeJPG",tolua_opengl_wyTexture2D_makeJPG04);
   tolua_function(tolua_S,"makeJPG",tolua_opengl_wyTexture2D_makeJPG05);
   tolua_function(tolua_S,"makeJPG",tolua_opengl_wyTexture2D_makeJPG06);
   tolua_function(tolua_S,"makeRawJPG",tolua_opengl_wyTexture2D_makeRawJPG00);
   tolua_function(tolua_S,"makeRawJPG",tolua_opengl_wyTexture2D_makeRawJPG01);
   tolua_function(tolua_S,"makeRawJPG",tolua_opengl_wyTexture2D_makeRawJPG02);
   tolua_function(tolua_S,"makeRawJPG",tolua_opengl_wyTexture2D_makeRawJPG03);
   tolua_function(tolua_S,"makeMemoryJPG",tolua_opengl_wyTexture2D_makeMemoryJPG00);
   tolua_function(tolua_S,"makeMemoryJPG",tolua_opengl_wyTexture2D_makeMemoryJPG01);
   tolua_function(tolua_S,"makeMemoryJPG",tolua_opengl_wyTexture2D_makeMemoryJPG02);
   tolua_function(tolua_S,"makeMemoryJPG",tolua_opengl_wyTexture2D_makeMemoryJPG03);
   tolua_function(tolua_S,"makeFileJPG",tolua_opengl_wyTexture2D_makeFileJPG00);
   tolua_function(tolua_S,"makeFileJPG",tolua_opengl_wyTexture2D_makeFileJPG01);
   tolua_function(tolua_S,"makeFileJPG",tolua_opengl_wyTexture2D_makeFileJPG02);
   tolua_function(tolua_S,"makeFileJPG",tolua_opengl_wyTexture2D_makeFileJPG03);
   tolua_function(tolua_S,"makePNG",tolua_opengl_wyTexture2D_makePNG00);
   tolua_function(tolua_S,"makePNG",tolua_opengl_wyTexture2D_makePNG01);
   tolua_function(tolua_S,"makePNG",tolua_opengl_wyTexture2D_makePNG02);
   tolua_function(tolua_S,"makePNG",tolua_opengl_wyTexture2D_makePNG03);
   tolua_function(tolua_S,"makePNG",tolua_opengl_wyTexture2D_makePNG04);
   tolua_function(tolua_S,"makeRawPNG",tolua_opengl_wyTexture2D_makeRawPNG00);
   tolua_function(tolua_S,"makeRawPNG",tolua_opengl_wyTexture2D_makeRawPNG01);
   tolua_function(tolua_S,"makeRawPNG",tolua_opengl_wyTexture2D_makeRawPNG02);
   tolua_function(tolua_S,"makeMemoryPNG",tolua_opengl_wyTexture2D_makeMemoryPNG00);
   tolua_function(tolua_S,"makeMemoryPNG",tolua_opengl_wyTexture2D_makeMemoryPNG01);
   tolua_function(tolua_S,"makeMemoryPNG",tolua_opengl_wyTexture2D_makeMemoryPNG02);
   tolua_function(tolua_S,"makeFilePNG",tolua_opengl_wyTexture2D_makeFilePNG00);
   tolua_function(tolua_S,"makeFilePNG",tolua_opengl_wyTexture2D_makeFilePNG01);
   tolua_function(tolua_S,"makeFilePNG",tolua_opengl_wyTexture2D_makeFilePNG02);
   tolua_function(tolua_S,"makePVR",tolua_opengl_wyTexture2D_makePVR00);
   tolua_function(tolua_S,"makePVR",tolua_opengl_wyTexture2D_makePVR01);
   tolua_function(tolua_S,"makeRawPVR",tolua_opengl_wyTexture2D_makeRawPVR00);
   tolua_function(tolua_S,"makeMemoryPVR",tolua_opengl_wyTexture2D_makeMemoryPVR00);
   tolua_function(tolua_S,"makeFilePVR",tolua_opengl_wyTexture2D_makeFilePVR00);
   tolua_function(tolua_S,"makeLabel",tolua_opengl_wyTexture2D_makeLabel00);
   tolua_function(tolua_S,"makeLabel",tolua_opengl_wyTexture2D_makeLabel01);
   tolua_function(tolua_S,"makeGL",tolua_opengl_wyTexture2D_makeGL00);
   tolua_function(tolua_S,"makeRaw",tolua_opengl_wyTexture2D_makeRaw00);
   tolua_function(tolua_S,"makeRaw",tolua_opengl_wyTexture2D_makeRaw01);
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
  tolua_constant(tolua_S,"SOURCE_JPG",SOURCE_JPG);
  tolua_constant(tolua_S,"SOURCE_PNG",SOURCE_PNG);
  tolua_constant(tolua_S,"SOURCE_PVR",SOURCE_PVR);
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
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_opengl (lua_State* tolua_S) {
 return tolua_opengl_open(tolua_S);
};
#endif

