/*
** Lua binding: filters
** Generated automatically by tolua++-1.0.92 on Fri Nov  9 13:12:01 2012.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_filters_open (lua_State* tolua_S);

#include "WiEngine.h"

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_wyColorMatrix (lua_State* tolua_S)
{
 wyColorMatrix* self = (wyColorMatrix*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyColorMatrixColorFilter (lua_State* tolua_S)
{
 wyColorMatrixColorFilter* self = (wyColorMatrixColorFilter*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyAreaColorFilter (lua_State* tolua_S)
{
 wyAreaColorFilter* self = (wyAreaColorFilter*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyCombineColorFilter (lua_State* tolua_S)
{
 wyCombineColorFilter* self = (wyCombineColorFilter*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyColorFilter (lua_State* tolua_S)
{
 wyColorFilter* self = (wyColorFilter*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyLightingColorFilter (lua_State* tolua_S)
{
 wyLightingColorFilter* self = (wyLightingColorFilter*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyCustomColorFilter (lua_State* tolua_S)
{
 wyCustomColorFilter* self = (wyCustomColorFilter*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyMappingColorFilter (lua_State* tolua_S)
{
 wyMappingColorFilter* self = (wyMappingColorFilter*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyDropShadowColorFilter (lua_State* tolua_S)
{
 wyDropShadowColorFilter* self = (wyDropShadowColorFilter*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyEmbossColorFilter (lua_State* tolua_S)
{
 wyEmbossColorFilter* self = (wyEmbossColorFilter*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyBlurColorFilter (lua_State* tolua_S)
{
 wyBlurColorFilter* self = (wyBlurColorFilter*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyGlowColorFilter (lua_State* tolua_S)
{
 wyGlowColorFilter* self = (wyGlowColorFilter*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"wyColorMatrix");
 tolua_usertype(tolua_S,"wyCustomColorFilter");
 tolua_usertype(tolua_S,"wyBlurColorFilter");
 tolua_usertype(tolua_S,"wyColorMatrixColorFilter");
 tolua_usertype(tolua_S,"wyAreaColorFilter");
 tolua_usertype(tolua_S,"wyCombineColorFilter");
 tolua_usertype(tolua_S,"wyColorFilter");
 tolua_usertype(tolua_S,"wyLightingColorFilter");
 tolua_usertype(tolua_S,"wyDropShadowColorFilter");
 tolua_usertype(tolua_S,"wyColor3B");
 tolua_usertype(tolua_S,"wyMappingColorFilter");
 tolua_usertype(tolua_S,"wyEmbossColorFilter");
 tolua_usertype(tolua_S,"wyObject");
 tolua_usertype(tolua_S,"wyColorFilterDelegate");
 tolua_usertype(tolua_S,"wyGlowColorFilter");
}

/* method: delete of class  wyColorFilter */
#ifndef TOLUA_DISABLE_tolua_filters_wyColorFilter_delete00
static int tolua_filters_wyColorFilter_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyColorFilter",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyColorFilter* self = (wyColorFilter*)  tolua_tousertype(tolua_S,1,0);
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

/* method: delete of class  wyColorMatrix */
#ifndef TOLUA_DISABLE_tolua_filters_wyColorMatrix_delete00
static int tolua_filters_wyColorMatrix_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyColorMatrix",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyColorMatrix* self = (wyColorMatrix*)  tolua_tousertype(tolua_S,1,0);
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

/* method: make of class  wyColorMatrix */
#ifndef TOLUA_DISABLE_tolua_filters_wyColorMatrix_make00
static int tolua_filters_wyColorMatrix_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyColorMatrix",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   wyColorMatrix* tolua_ret = (wyColorMatrix*)  wyColorMatrix::make();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyColorMatrix");
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

/* method: make of class  wyColorMatrix */
#ifndef TOLUA_DISABLE_tolua_filters_wyColorMatrix_make01
static int tolua_filters_wyColorMatrix_make01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyColorMatrix",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  float m = ((float)  tolua_tonumber(tolua_S,2,0));
  {
   wyColorMatrix* tolua_ret = (wyColorMatrix*)  wyColorMatrix::make(&m);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyColorMatrix");
   tolua_pushnumber(tolua_S,(lua_Number)m);
  }
 }
 return 2;
tolua_lerror:
 return tolua_filters_wyColorMatrix_make00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: reset of class  wyColorMatrix */
#ifndef TOLUA_DISABLE_tolua_filters_wyColorMatrix_reset00
static int tolua_filters_wyColorMatrix_reset00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyColorMatrix",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyColorMatrix* self = (wyColorMatrix*)  tolua_tousertype(tolua_S,1,0);
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

/* method: getMatrix of class  wyColorMatrix */
#ifndef TOLUA_DISABLE_tolua_filters_wyColorMatrix_getMatrix00
static int tolua_filters_wyColorMatrix_getMatrix00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyColorMatrix",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyColorMatrix* self = (wyColorMatrix*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getMatrix'", NULL);
#endif
  {
   void* tolua_ret = (void*)  self->getMatrix();
   tolua_pushuserdata(tolua_S,(void*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getMatrix'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setMatrix of class  wyColorMatrix */
#ifndef TOLUA_DISABLE_tolua_filters_wyColorMatrix_setMatrix00
static int tolua_filters_wyColorMatrix_setMatrix00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyColorMatrix",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyColorMatrix",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyColorMatrix* self = (wyColorMatrix*)  tolua_tousertype(tolua_S,1,0);
  wyColorMatrix* m = ((wyColorMatrix*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setMatrix'", NULL);
#endif
  {
   self->setMatrix(m);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setMatrix'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setMatrix of class  wyColorMatrix */
#ifndef TOLUA_DISABLE_tolua_filters_wyColorMatrix_setMatrix01
static int tolua_filters_wyColorMatrix_setMatrix01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyColorMatrix",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  wyColorMatrix* self = (wyColorMatrix*)  tolua_tousertype(tolua_S,1,0);
  float m = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setMatrix'", NULL);
#endif
  {
   self->setMatrix(&m);
   tolua_pushnumber(tolua_S,(lua_Number)m);
  }
 }
 return 1;
tolua_lerror:
 return tolua_filters_wyColorMatrix_setMatrix00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: setScale of class  wyColorMatrix */
#ifndef TOLUA_DISABLE_tolua_filters_wyColorMatrix_setScale00
static int tolua_filters_wyColorMatrix_setScale00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyColorMatrix",0,&tolua_err) ||
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
  wyColorMatrix* self = (wyColorMatrix*)  tolua_tousertype(tolua_S,1,0);
  float rScale = ((float)  tolua_tonumber(tolua_S,2,0));
  float gScale = ((float)  tolua_tonumber(tolua_S,3,0));
  float bScale = ((float)  tolua_tonumber(tolua_S,4,0));
  float aScale = ((float)  tolua_tonumber(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setScale'", NULL);
#endif
  {
   self->setScale(rScale,gScale,bScale,aScale);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setScale'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setRotate of class  wyColorMatrix */
#ifndef TOLUA_DISABLE_tolua_filters_wyColorMatrix_setRotate00
static int tolua_filters_wyColorMatrix_setRotate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyColorMatrix",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyColorMatrix* self = (wyColorMatrix*)  tolua_tousertype(tolua_S,1,0);
  int axis = ((int)  tolua_tonumber(tolua_S,2,0));
  float degrees = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setRotate'", NULL);
#endif
  {
   self->setRotate(axis,degrees);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setRotate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setConcat of class  wyColorMatrix */
#ifndef TOLUA_DISABLE_tolua_filters_wyColorMatrix_setConcat00
static int tolua_filters_wyColorMatrix_setConcat00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyColorMatrix",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyColorMatrix",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"wyColorMatrix",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyColorMatrix* self = (wyColorMatrix*)  tolua_tousertype(tolua_S,1,0);
  wyColorMatrix* matA = ((wyColorMatrix*)  tolua_tousertype(tolua_S,2,0));
  wyColorMatrix* matB = ((wyColorMatrix*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setConcat'", NULL);
#endif
  {
   self->setConcat(matA,matB);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setConcat'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: preConcat of class  wyColorMatrix */
#ifndef TOLUA_DISABLE_tolua_filters_wyColorMatrix_preConcat00
static int tolua_filters_wyColorMatrix_preConcat00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyColorMatrix",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyColorMatrix",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyColorMatrix* self = (wyColorMatrix*)  tolua_tousertype(tolua_S,1,0);
  wyColorMatrix* prematrix = ((wyColorMatrix*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'preConcat'", NULL);
#endif
  {
   self->preConcat(prematrix);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'preConcat'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: postConcat of class  wyColorMatrix */
#ifndef TOLUA_DISABLE_tolua_filters_wyColorMatrix_postConcat00
static int tolua_filters_wyColorMatrix_postConcat00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyColorMatrix",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyColorMatrix",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyColorMatrix* self = (wyColorMatrix*)  tolua_tousertype(tolua_S,1,0);
  wyColorMatrix* postmatrix = ((wyColorMatrix*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'postConcat'", NULL);
#endif
  {
   self->postConcat(postmatrix);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'postConcat'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setSaturation of class  wyColorMatrix */
#ifndef TOLUA_DISABLE_tolua_filters_wyColorMatrix_setSaturation00
static int tolua_filters_wyColorMatrix_setSaturation00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyColorMatrix",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyColorMatrix* self = (wyColorMatrix*)  tolua_tousertype(tolua_S,1,0);
  float sat = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setSaturation'", NULL);
#endif
  {
   self->setSaturation(sat);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setSaturation'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setRGB2YUV of class  wyColorMatrix */
#ifndef TOLUA_DISABLE_tolua_filters_wyColorMatrix_setRGB2YUV00
static int tolua_filters_wyColorMatrix_setRGB2YUV00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyColorMatrix",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyColorMatrix* self = (wyColorMatrix*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setRGB2YUV'", NULL);
#endif
  {
   self->setRGB2YUV();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setRGB2YUV'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setYUV2RGB of class  wyColorMatrix */
#ifndef TOLUA_DISABLE_tolua_filters_wyColorMatrix_setYUV2RGB00
static int tolua_filters_wyColorMatrix_setYUV2RGB00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyColorMatrix",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyColorMatrix* self = (wyColorMatrix*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setYUV2RGB'", NULL);
#endif
  {
   self->setYUV2RGB();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setYUV2RGB'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setNegative of class  wyColorMatrix */
#ifndef TOLUA_DISABLE_tolua_filters_wyColorMatrix_setNegative00
static int tolua_filters_wyColorMatrix_setNegative00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyColorMatrix",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyColorMatrix* self = (wyColorMatrix*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setNegative'", NULL);
#endif
  {
   self->setNegative();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setNegative'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  wyColorMatrixColorFilter */
#ifndef TOLUA_DISABLE_tolua_filters_wyColorMatrixColorFilter_delete00
static int tolua_filters_wyColorMatrixColorFilter_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyColorMatrixColorFilter",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyColorMatrixColorFilter* self = (wyColorMatrixColorFilter*)  tolua_tousertype(tolua_S,1,0);
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

/* method: make of class  wyColorMatrixColorFilter */
#ifndef TOLUA_DISABLE_tolua_filters_wyColorMatrixColorFilter_make00
static int tolua_filters_wyColorMatrixColorFilter_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyColorMatrixColorFilter",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyColorMatrix",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyColorMatrix* m = ((wyColorMatrix*)  tolua_tousertype(tolua_S,2,0));
  {
   wyColorMatrixColorFilter* tolua_ret = (wyColorMatrixColorFilter*)  wyColorMatrixColorFilter::make(m);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyColorMatrixColorFilter");
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

/* method: apply of class  wyColorMatrixColorFilter */
#ifndef TOLUA_DISABLE_tolua_filters_wyColorMatrixColorFilter_apply00
static int tolua_filters_wyColorMatrixColorFilter_apply00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyColorMatrixColorFilter",0,&tolua_err) ||
     !tolua_isuserdata(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyColorMatrixColorFilter* self = (wyColorMatrixColorFilter*)  tolua_tousertype(tolua_S,1,0);
  void* data = ((void*)  tolua_touserdata(tolua_S,2,0));
  int width = ((int)  tolua_tonumber(tolua_S,3,0));
  int height = ((int)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'apply'", NULL);
#endif
  {
   self->apply(data,width,height);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'apply'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  wyLightingColorFilter */
#ifndef TOLUA_DISABLE_tolua_filters_wyLightingColorFilter_delete00
static int tolua_filters_wyLightingColorFilter_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyLightingColorFilter",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyLightingColorFilter* self = (wyLightingColorFilter*)  tolua_tousertype(tolua_S,1,0);
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

/* method: make of class  wyLightingColorFilter */
#ifndef TOLUA_DISABLE_tolua_filters_wyLightingColorFilter_make00
static int tolua_filters_wyLightingColorFilter_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyLightingColorFilter",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  int mul = ((int)  tolua_tonumber(tolua_S,2,0));
  int add = ((int)  tolua_tonumber(tolua_S,3,0));
  {
   wyLightingColorFilter* tolua_ret = (wyLightingColorFilter*)  wyLightingColorFilter::make(mul,add);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyLightingColorFilter");
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

/* method: apply of class  wyLightingColorFilter */
#ifndef TOLUA_DISABLE_tolua_filters_wyLightingColorFilter_apply00
static int tolua_filters_wyLightingColorFilter_apply00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyLightingColorFilter",0,&tolua_err) ||
     !tolua_isuserdata(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyLightingColorFilter* self = (wyLightingColorFilter*)  tolua_tousertype(tolua_S,1,0);
  void* data = ((void*)  tolua_touserdata(tolua_S,2,0));
  int width = ((int)  tolua_tonumber(tolua_S,3,0));
  int height = ((int)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'apply'", NULL);
#endif
  {
   self->apply(data,width,height);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'apply'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  wyMappingColorFilter */
#ifndef TOLUA_DISABLE_tolua_filters_wyMappingColorFilter_delete00
static int tolua_filters_wyMappingColorFilter_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyMappingColorFilter",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyMappingColorFilter* self = (wyMappingColorFilter*)  tolua_tousertype(tolua_S,1,0);
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

/* method: make of class  wyMappingColorFilter */
#ifndef TOLUA_DISABLE_tolua_filters_wyMappingColorFilter_make00
static int tolua_filters_wyMappingColorFilter_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyMappingColorFilter",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   wyMappingColorFilter* tolua_ret = (wyMappingColorFilter*)  wyMappingColorFilter::make();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyMappingColorFilter");
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

/* method: apply of class  wyMappingColorFilter */
#ifndef TOLUA_DISABLE_tolua_filters_wyMappingColorFilter_apply00
static int tolua_filters_wyMappingColorFilter_apply00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyMappingColorFilter",0,&tolua_err) ||
     !tolua_isuserdata(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyMappingColorFilter* self = (wyMappingColorFilter*)  tolua_tousertype(tolua_S,1,0);
  void* data = ((void*)  tolua_touserdata(tolua_S,2,0));
  int width = ((int)  tolua_tonumber(tolua_S,3,0));
  int height = ((int)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'apply'", NULL);
#endif
  {
   self->apply(data,width,height);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'apply'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: mapColor of class  wyMappingColorFilter */
#ifndef TOLUA_DISABLE_tolua_filters_wyMappingColorFilter_mapColor00
static int tolua_filters_wyMappingColorFilter_mapColor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyMappingColorFilter",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyMappingColorFilter* self = (wyMappingColorFilter*)  tolua_tousertype(tolua_S,1,0);
  int from = ((int)  tolua_tonumber(tolua_S,2,0));
  int to = ((int)  tolua_tonumber(tolua_S,3,0));
  int fromMask = ((int)  tolua_tonumber(tolua_S,4,0x00ffffff));
  int toMask = ((int)  tolua_tonumber(tolua_S,5,0x00ffffff));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'mapColor'", NULL);
#endif
  {
   self->mapColor(from,to,fromMask,toMask);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'mapColor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: unmapColor of class  wyMappingColorFilter */
#ifndef TOLUA_DISABLE_tolua_filters_wyMappingColorFilter_unmapColor00
static int tolua_filters_wyMappingColorFilter_unmapColor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyMappingColorFilter",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyMappingColorFilter* self = (wyMappingColorFilter*)  tolua_tousertype(tolua_S,1,0);
  int from = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'unmapColor'", NULL);
#endif
  {
   self->unmapColor(from);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'unmapColor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  wyCombineColorFilter */
#ifndef TOLUA_DISABLE_tolua_filters_wyCombineColorFilter_delete00
static int tolua_filters_wyCombineColorFilter_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyCombineColorFilter",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyCombineColorFilter* self = (wyCombineColorFilter*)  tolua_tousertype(tolua_S,1,0);
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

/* method: addFilter of class  wyCombineColorFilter */
#ifndef TOLUA_DISABLE_tolua_filters_wyCombineColorFilter_addFilter00
static int tolua_filters_wyCombineColorFilter_addFilter00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyCombineColorFilter",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyColorFilter",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyCombineColorFilter* self = (wyCombineColorFilter*)  tolua_tousertype(tolua_S,1,0);
  wyColorFilter* filter = ((wyColorFilter*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addFilter'", NULL);
#endif
  {
   self->addFilter(filter);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addFilter'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: apply of class  wyCombineColorFilter */
#ifndef TOLUA_DISABLE_tolua_filters_wyCombineColorFilter_apply00
static int tolua_filters_wyCombineColorFilter_apply00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyCombineColorFilter",0,&tolua_err) ||
     !tolua_isuserdata(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyCombineColorFilter* self = (wyCombineColorFilter*)  tolua_tousertype(tolua_S,1,0);
  void* data = ((void*)  tolua_touserdata(tolua_S,2,0));
  int width = ((int)  tolua_tonumber(tolua_S,3,0));
  int height = ((int)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'apply'", NULL);
#endif
  {
   self->apply(data,width,height);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'apply'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  wyEmbossColorFilter */
#ifndef TOLUA_DISABLE_tolua_filters_wyEmbossColorFilter_delete00
static int tolua_filters_wyEmbossColorFilter_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyEmbossColorFilter",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyEmbossColorFilter* self = (wyEmbossColorFilter*)  tolua_tousertype(tolua_S,1,0);
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

/* method: make of class  wyEmbossColorFilter */
#ifndef TOLUA_DISABLE_tolua_filters_wyEmbossColorFilter_make00
static int tolua_filters_wyEmbossColorFilter_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyEmbossColorFilter",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  unsigned int grayLevel = ((unsigned int)  tolua_tonumber(tolua_S,2,128));
  {
   wyEmbossColorFilter* tolua_ret = (wyEmbossColorFilter*)  wyEmbossColorFilter::make(grayLevel);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyEmbossColorFilter");
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

/* method: apply of class  wyEmbossColorFilter */
#ifndef TOLUA_DISABLE_tolua_filters_wyEmbossColorFilter_apply00
static int tolua_filters_wyEmbossColorFilter_apply00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyEmbossColorFilter",0,&tolua_err) ||
     !tolua_isuserdata(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyEmbossColorFilter* self = (wyEmbossColorFilter*)  tolua_tousertype(tolua_S,1,0);
  void* data = ((void*)  tolua_touserdata(tolua_S,2,0));
  int width = ((int)  tolua_tonumber(tolua_S,3,0));
  int height = ((int)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'apply'", NULL);
#endif
  {
   self->apply(data,width,height);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'apply'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setGrayLevel of class  wyEmbossColorFilter */
#ifndef TOLUA_DISABLE_tolua_filters_wyEmbossColorFilter_setGrayLevel00
static int tolua_filters_wyEmbossColorFilter_setGrayLevel00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyEmbossColorFilter",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyEmbossColorFilter* self = (wyEmbossColorFilter*)  tolua_tousertype(tolua_S,1,0);
  unsigned int grayLevel = ((unsigned int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setGrayLevel'", NULL);
#endif
  {
   self->setGrayLevel(grayLevel);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setGrayLevel'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getGrayLevel of class  wyEmbossColorFilter */
#ifndef TOLUA_DISABLE_tolua_filters_wyEmbossColorFilter_getGrayLevel00
static int tolua_filters_wyEmbossColorFilter_getGrayLevel00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyEmbossColorFilter",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyEmbossColorFilter* self = (wyEmbossColorFilter*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getGrayLevel'", NULL);
#endif
  {
   unsigned int tolua_ret = (unsigned int)  self->getGrayLevel();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getGrayLevel'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  wyBlurColorFilter */
#ifndef TOLUA_DISABLE_tolua_filters_wyBlurColorFilter_delete00
static int tolua_filters_wyBlurColorFilter_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyBlurColorFilter",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyBlurColorFilter* self = (wyBlurColorFilter*)  tolua_tousertype(tolua_S,1,0);
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

/* method: make of class  wyBlurColorFilter */
#ifndef TOLUA_DISABLE_tolua_filters_wyBlurColorFilter_make00
static int tolua_filters_wyBlurColorFilter_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyBlurColorFilter",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  int radius = ((int)  tolua_tonumber(tolua_S,2,0));
  {
   wyBlurColorFilter* tolua_ret = (wyBlurColorFilter*)  wyBlurColorFilter::make(radius);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyBlurColorFilter");
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

/* method: apply of class  wyBlurColorFilter */
#ifndef TOLUA_DISABLE_tolua_filters_wyBlurColorFilter_apply00
static int tolua_filters_wyBlurColorFilter_apply00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyBlurColorFilter",0,&tolua_err) ||
     !tolua_isuserdata(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyBlurColorFilter* self = (wyBlurColorFilter*)  tolua_tousertype(tolua_S,1,0);
  void* data = ((void*)  tolua_touserdata(tolua_S,2,0));
  int width = ((int)  tolua_tonumber(tolua_S,3,0));
  int height = ((int)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'apply'", NULL);
#endif
  {
   self->apply(data,width,height);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'apply'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setRadius of class  wyBlurColorFilter */
#ifndef TOLUA_DISABLE_tolua_filters_wyBlurColorFilter_setRadius00
static int tolua_filters_wyBlurColorFilter_setRadius00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyBlurColorFilter",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyBlurColorFilter* self = (wyBlurColorFilter*)  tolua_tousertype(tolua_S,1,0);
  int radius = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setRadius'", NULL);
#endif
  {
   self->setRadius(radius);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setRadius'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getRadius of class  wyBlurColorFilter */
#ifndef TOLUA_DISABLE_tolua_filters_wyBlurColorFilter_getRadius00
static int tolua_filters_wyBlurColorFilter_getRadius00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyBlurColorFilter",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyBlurColorFilter* self = (wyBlurColorFilter*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getRadius'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getRadius();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getRadius'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  wyGlowColorFilter */
#ifndef TOLUA_DISABLE_tolua_filters_wyGlowColorFilter_delete00
static int tolua_filters_wyGlowColorFilter_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyGlowColorFilter",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyGlowColorFilter* self = (wyGlowColorFilter*)  tolua_tousertype(tolua_S,1,0);
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

/* method: make of class  wyGlowColorFilter */
#ifndef TOLUA_DISABLE_tolua_filters_wyGlowColorFilter_make00
static int tolua_filters_wyGlowColorFilter_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyGlowColorFilter",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"wyColor3B",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyColor3B color = *((wyColor3B*)  tolua_tousertype(tolua_S,2,0));
  int radius = ((int)  tolua_tonumber(tolua_S,3,0));
  int highlightRadius = ((int)  tolua_tonumber(tolua_S,4,0));
  int opacity = ((int)  tolua_tonumber(tolua_S,5,0));
  {
   wyGlowColorFilter* tolua_ret = (wyGlowColorFilter*)  wyGlowColorFilter::make(color,radius,highlightRadius,opacity);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyGlowColorFilter");
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

/* method: apply of class  wyGlowColorFilter */
#ifndef TOLUA_DISABLE_tolua_filters_wyGlowColorFilter_apply00
static int tolua_filters_wyGlowColorFilter_apply00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyGlowColorFilter",0,&tolua_err) ||
     !tolua_isuserdata(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyGlowColorFilter* self = (wyGlowColorFilter*)  tolua_tousertype(tolua_S,1,0);
  void* data = ((void*)  tolua_touserdata(tolua_S,2,0));
  int width = ((int)  tolua_tonumber(tolua_S,3,0));
  int height = ((int)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'apply'", NULL);
#endif
  {
   self->apply(data,width,height);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'apply'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setRadius of class  wyGlowColorFilter */
#ifndef TOLUA_DISABLE_tolua_filters_wyGlowColorFilter_setRadius00
static int tolua_filters_wyGlowColorFilter_setRadius00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyGlowColorFilter",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyGlowColorFilter* self = (wyGlowColorFilter*)  tolua_tousertype(tolua_S,1,0);
  int radius = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setRadius'", NULL);
#endif
  {
   self->setRadius(radius);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setRadius'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getRadius of class  wyGlowColorFilter */
#ifndef TOLUA_DISABLE_tolua_filters_wyGlowColorFilter_getRadius00
static int tolua_filters_wyGlowColorFilter_getRadius00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyGlowColorFilter",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyGlowColorFilter* self = (wyGlowColorFilter*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getRadius'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getRadius();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getRadius'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setOpacity of class  wyGlowColorFilter */
#ifndef TOLUA_DISABLE_tolua_filters_wyGlowColorFilter_setOpacity00
static int tolua_filters_wyGlowColorFilter_setOpacity00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyGlowColorFilter",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyGlowColorFilter* self = (wyGlowColorFilter*)  tolua_tousertype(tolua_S,1,0);
  int opacity = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setOpacity'", NULL);
#endif
  {
   self->setOpacity(opacity);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setOpacity'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getOpacity of class  wyGlowColorFilter */
#ifndef TOLUA_DISABLE_tolua_filters_wyGlowColorFilter_getOpacity00
static int tolua_filters_wyGlowColorFilter_getOpacity00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyGlowColorFilter",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyGlowColorFilter* self = (wyGlowColorFilter*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getOpacity'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getOpacity();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getOpacity'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setHighlightRadius of class  wyGlowColorFilter */
#ifndef TOLUA_DISABLE_tolua_filters_wyGlowColorFilter_setHighlightRadius00
static int tolua_filters_wyGlowColorFilter_setHighlightRadius00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyGlowColorFilter",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyGlowColorFilter* self = (wyGlowColorFilter*)  tolua_tousertype(tolua_S,1,0);
  int highlightRadius = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setHighlightRadius'", NULL);
#endif
  {
   self->setHighlightRadius(highlightRadius);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setHighlightRadius'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getHighlightRadius of class  wyGlowColorFilter */
#ifndef TOLUA_DISABLE_tolua_filters_wyGlowColorFilter_getHighlightRadius00
static int tolua_filters_wyGlowColorFilter_getHighlightRadius00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyGlowColorFilter",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyGlowColorFilter* self = (wyGlowColorFilter*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getHighlightRadius'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getHighlightRadius();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getHighlightRadius'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  wyDropShadowColorFilter */
#ifndef TOLUA_DISABLE_tolua_filters_wyDropShadowColorFilter_delete00
static int tolua_filters_wyDropShadowColorFilter_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyDropShadowColorFilter",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyDropShadowColorFilter* self = (wyDropShadowColorFilter*)  tolua_tousertype(tolua_S,1,0);
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

/* method: make of class  wyDropShadowColorFilter */
#ifndef TOLUA_DISABLE_tolua_filters_wyDropShadowColorFilter_make00
static int tolua_filters_wyDropShadowColorFilter_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyDropShadowColorFilter",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"wyColor3B",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyColor3B color = *((wyColor3B*)  tolua_tousertype(tolua_S,2,0));
  int radius = ((int)  tolua_tonumber(tolua_S,3,0));
  int highlightRadius = ((int)  tolua_tonumber(tolua_S,4,0));
  int opacity = ((int)  tolua_tonumber(tolua_S,5,0));
  {
   wyDropShadowColorFilter* tolua_ret = (wyDropShadowColorFilter*)  wyDropShadowColorFilter::make(color,radius,highlightRadius,opacity);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyDropShadowColorFilter");
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

/* method: apply of class  wyDropShadowColorFilter */
#ifndef TOLUA_DISABLE_tolua_filters_wyDropShadowColorFilter_apply00
static int tolua_filters_wyDropShadowColorFilter_apply00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyDropShadowColorFilter",0,&tolua_err) ||
     !tolua_isuserdata(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyDropShadowColorFilter* self = (wyDropShadowColorFilter*)  tolua_tousertype(tolua_S,1,0);
  void* data = ((void*)  tolua_touserdata(tolua_S,2,0));
  int width = ((int)  tolua_tonumber(tolua_S,3,0));
  int height = ((int)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'apply'", NULL);
#endif
  {
   self->apply(data,width,height);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'apply'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setRadius of class  wyDropShadowColorFilter */
#ifndef TOLUA_DISABLE_tolua_filters_wyDropShadowColorFilter_setRadius00
static int tolua_filters_wyDropShadowColorFilter_setRadius00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyDropShadowColorFilter",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyDropShadowColorFilter* self = (wyDropShadowColorFilter*)  tolua_tousertype(tolua_S,1,0);
  int radius = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setRadius'", NULL);
#endif
  {
   self->setRadius(radius);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setRadius'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getRadius of class  wyDropShadowColorFilter */
#ifndef TOLUA_DISABLE_tolua_filters_wyDropShadowColorFilter_getRadius00
static int tolua_filters_wyDropShadowColorFilter_getRadius00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyDropShadowColorFilter",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyDropShadowColorFilter* self = (wyDropShadowColorFilter*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getRadius'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getRadius();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getRadius'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setOpacity of class  wyDropShadowColorFilter */
#ifndef TOLUA_DISABLE_tolua_filters_wyDropShadowColorFilter_setOpacity00
static int tolua_filters_wyDropShadowColorFilter_setOpacity00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyDropShadowColorFilter",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyDropShadowColorFilter* self = (wyDropShadowColorFilter*)  tolua_tousertype(tolua_S,1,0);
  int opacity = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setOpacity'", NULL);
#endif
  {
   self->setOpacity(opacity);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setOpacity'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getOpacity of class  wyDropShadowColorFilter */
#ifndef TOLUA_DISABLE_tolua_filters_wyDropShadowColorFilter_getOpacity00
static int tolua_filters_wyDropShadowColorFilter_getOpacity00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyDropShadowColorFilter",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyDropShadowColorFilter* self = (wyDropShadowColorFilter*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getOpacity'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getOpacity();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getOpacity'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setHighlightRadius of class  wyDropShadowColorFilter */
#ifndef TOLUA_DISABLE_tolua_filters_wyDropShadowColorFilter_setHighlightRadius00
static int tolua_filters_wyDropShadowColorFilter_setHighlightRadius00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyDropShadowColorFilter",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyDropShadowColorFilter* self = (wyDropShadowColorFilter*)  tolua_tousertype(tolua_S,1,0);
  int highlightRadius = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setHighlightRadius'", NULL);
#endif
  {
   self->setHighlightRadius(highlightRadius);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setHighlightRadius'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getHighlightRadius of class  wyDropShadowColorFilter */
#ifndef TOLUA_DISABLE_tolua_filters_wyDropShadowColorFilter_getHighlightRadius00
static int tolua_filters_wyDropShadowColorFilter_getHighlightRadius00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyDropShadowColorFilter",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyDropShadowColorFilter* self = (wyDropShadowColorFilter*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getHighlightRadius'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getHighlightRadius();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getHighlightRadius'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  wyAreaColorFilter */
#ifndef TOLUA_DISABLE_tolua_filters_wyAreaColorFilter_delete00
static int tolua_filters_wyAreaColorFilter_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAreaColorFilter",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAreaColorFilter* self = (wyAreaColorFilter*)  tolua_tousertype(tolua_S,1,0);
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

/* method: make of class  wyAreaColorFilter */
#ifndef TOLUA_DISABLE_tolua_filters_wyAreaColorFilter_make00
static int tolua_filters_wyAreaColorFilter_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyAreaColorFilter",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   wyAreaColorFilter* tolua_ret = (wyAreaColorFilter*)  wyAreaColorFilter::make();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyAreaColorFilter");
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

/* method: apply of class  wyAreaColorFilter */
#ifndef TOLUA_DISABLE_tolua_filters_wyAreaColorFilter_apply00
static int tolua_filters_wyAreaColorFilter_apply00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAreaColorFilter",0,&tolua_err) ||
     !tolua_isuserdata(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAreaColorFilter* self = (wyAreaColorFilter*)  tolua_tousertype(tolua_S,1,0);
  void* data = ((void*)  tolua_touserdata(tolua_S,2,0));
  int width = ((int)  tolua_tonumber(tolua_S,3,0));
  int height = ((int)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'apply'", NULL);
#endif
  {
   self->apply(data,width,height);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'apply'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: mapPoint of class  wyAreaColorFilter */
#ifndef TOLUA_DISABLE_tolua_filters_wyAreaColorFilter_mapPoint00
static int tolua_filters_wyAreaColorFilter_mapPoint00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAreaColorFilter",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,7,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,8,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAreaColorFilter* self = (wyAreaColorFilter*)  tolua_tousertype(tolua_S,1,0);
  int x = ((int)  tolua_tonumber(tolua_S,2,0));
  int y = ((int)  tolua_tonumber(tolua_S,3,0));
  int from = ((int)  tolua_tonumber(tolua_S,4,0));
  int to = ((int)  tolua_tonumber(tolua_S,5,0));
  int fromMask = ((int)  tolua_tonumber(tolua_S,6,0x00ffffff));
  int toMask = ((int)  tolua_tonumber(tolua_S,7,0x00ffffff));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'mapPoint'", NULL);
#endif
  {
   self->mapPoint(x,y,from,to,fromMask,toMask);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'mapPoint'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: removePoint of class  wyAreaColorFilter */
#ifndef TOLUA_DISABLE_tolua_filters_wyAreaColorFilter_removePoint00
static int tolua_filters_wyAreaColorFilter_removePoint00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAreaColorFilter",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAreaColorFilter* self = (wyAreaColorFilter*)  tolua_tousertype(tolua_S,1,0);
  int x = ((int)  tolua_tonumber(tolua_S,2,0));
  int y = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'removePoint'", NULL);
#endif
  {
   self->removePoint(x,y);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'removePoint'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: mapLine of class  wyAreaColorFilter */
#ifndef TOLUA_DISABLE_tolua_filters_wyAreaColorFilter_mapLine00
static int tolua_filters_wyAreaColorFilter_mapLine00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAreaColorFilter",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,7,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,8,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,9,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,10,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAreaColorFilter* self = (wyAreaColorFilter*)  tolua_tousertype(tolua_S,1,0);
  int x1 = ((int)  tolua_tonumber(tolua_S,2,0));
  int y1 = ((int)  tolua_tonumber(tolua_S,3,0));
  int x2 = ((int)  tolua_tonumber(tolua_S,4,0));
  int y2 = ((int)  tolua_tonumber(tolua_S,5,0));
  int from = ((int)  tolua_tonumber(tolua_S,6,0));
  int to = ((int)  tolua_tonumber(tolua_S,7,0));
  int fromMask = ((int)  tolua_tonumber(tolua_S,8,0x00ffffff));
  int toMask = ((int)  tolua_tonumber(tolua_S,9,0x00ffffff));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'mapLine'", NULL);
#endif
  {
   self->mapLine(x1,y1,x2,y2,from,to,fromMask,toMask);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'mapLine'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: removeLine of class  wyAreaColorFilter */
#ifndef TOLUA_DISABLE_tolua_filters_wyAreaColorFilter_removeLine00
static int tolua_filters_wyAreaColorFilter_removeLine00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAreaColorFilter",0,&tolua_err) ||
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
  wyAreaColorFilter* self = (wyAreaColorFilter*)  tolua_tousertype(tolua_S,1,0);
  int x1 = ((int)  tolua_tonumber(tolua_S,2,0));
  int y1 = ((int)  tolua_tonumber(tolua_S,3,0));
  int x2 = ((int)  tolua_tonumber(tolua_S,4,0));
  int y2 = ((int)  tolua_tonumber(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'removeLine'", NULL);
#endif
  {
   self->removeLine(x1,y1,x2,y2);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'removeLine'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: mapRect of class  wyAreaColorFilter */
#ifndef TOLUA_DISABLE_tolua_filters_wyAreaColorFilter_mapRect00
static int tolua_filters_wyAreaColorFilter_mapRect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAreaColorFilter",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,7,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,8,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,9,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,10,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAreaColorFilter* self = (wyAreaColorFilter*)  tolua_tousertype(tolua_S,1,0);
  int x = ((int)  tolua_tonumber(tolua_S,2,0));
  int y = ((int)  tolua_tonumber(tolua_S,3,0));
  int w = ((int)  tolua_tonumber(tolua_S,4,0));
  int h = ((int)  tolua_tonumber(tolua_S,5,0));
  int from = ((int)  tolua_tonumber(tolua_S,6,0));
  int to = ((int)  tolua_tonumber(tolua_S,7,0));
  int fromMask = ((int)  tolua_tonumber(tolua_S,8,0x00ffffff));
  int toMask = ((int)  tolua_tonumber(tolua_S,9,0x00ffffff));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'mapRect'", NULL);
#endif
  {
   self->mapRect(x,y,w,h,from,to,fromMask,toMask);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'mapRect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: removeRect of class  wyAreaColorFilter */
#ifndef TOLUA_DISABLE_tolua_filters_wyAreaColorFilter_removeRect00
static int tolua_filters_wyAreaColorFilter_removeRect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAreaColorFilter",0,&tolua_err) ||
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
  wyAreaColorFilter* self = (wyAreaColorFilter*)  tolua_tousertype(tolua_S,1,0);
  int x = ((int)  tolua_tonumber(tolua_S,2,0));
  int y = ((int)  tolua_tonumber(tolua_S,3,0));
  int w = ((int)  tolua_tonumber(tolua_S,4,0));
  int h = ((int)  tolua_tonumber(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'removeRect'", NULL);
#endif
  {
   self->removeRect(x,y,w,h);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'removeRect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: mapCircle of class  wyAreaColorFilter */
#ifndef TOLUA_DISABLE_tolua_filters_wyAreaColorFilter_mapCircle00
static int tolua_filters_wyAreaColorFilter_mapCircle00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAreaColorFilter",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,7,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,8,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,9,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAreaColorFilter* self = (wyAreaColorFilter*)  tolua_tousertype(tolua_S,1,0);
  int centerX = ((int)  tolua_tonumber(tolua_S,2,0));
  int centerY = ((int)  tolua_tonumber(tolua_S,3,0));
  int radius = ((int)  tolua_tonumber(tolua_S,4,0));
  int from = ((int)  tolua_tonumber(tolua_S,5,0));
  int to = ((int)  tolua_tonumber(tolua_S,6,0));
  int fromMask = ((int)  tolua_tonumber(tolua_S,7,0x00ffffff));
  int toMask = ((int)  tolua_tonumber(tolua_S,8,0x00ffffff));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'mapCircle'", NULL);
#endif
  {
   self->mapCircle(centerX,centerY,radius,from,to,fromMask,toMask);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'mapCircle'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: removeCircle of class  wyAreaColorFilter */
#ifndef TOLUA_DISABLE_tolua_filters_wyAreaColorFilter_removeCircle00
static int tolua_filters_wyAreaColorFilter_removeCircle00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAreaColorFilter",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAreaColorFilter* self = (wyAreaColorFilter*)  tolua_tousertype(tolua_S,1,0);
  int centerX = ((int)  tolua_tonumber(tolua_S,2,0));
  int centerY = ((int)  tolua_tonumber(tolua_S,3,0));
  int radius = ((int)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'removeCircle'", NULL);
#endif
  {
   self->removeCircle(centerX,centerY,radius);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'removeCircle'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  wyCustomColorFilter */
#ifndef TOLUA_DISABLE_tolua_filters_wyCustomColorFilter_delete00
static int tolua_filters_wyCustomColorFilter_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyCustomColorFilter",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyCustomColorFilter* self = (wyCustomColorFilter*)  tolua_tousertype(tolua_S,1,0);
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

/* method: make of class  wyCustomColorFilter */
#ifndef TOLUA_DISABLE_tolua_filters_wyCustomColorFilter_make00
static int tolua_filters_wyCustomColorFilter_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyCustomColorFilter",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyColorFilterDelegate",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyColorFilterDelegate* delegate = ((wyColorFilterDelegate*)  tolua_tousertype(tolua_S,2,0));
  {
   wyCustomColorFilter* tolua_ret = (wyCustomColorFilter*)  wyCustomColorFilter::make(delegate);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyCustomColorFilter");
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

/* method: apply of class  wyCustomColorFilter */
#ifndef TOLUA_DISABLE_tolua_filters_wyCustomColorFilter_apply00
static int tolua_filters_wyCustomColorFilter_apply00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyCustomColorFilter",0,&tolua_err) ||
     !tolua_isuserdata(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyCustomColorFilter* self = (wyCustomColorFilter*)  tolua_tousertype(tolua_S,1,0);
  void* data = ((void*)  tolua_touserdata(tolua_S,2,0));
  int width = ((int)  tolua_tonumber(tolua_S,3,0));
  int height = ((int)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'apply'", NULL);
#endif
  {
   self->apply(data,width,height);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'apply'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setDelegate of class  wyCustomColorFilter */
#ifndef TOLUA_DISABLE_tolua_filters_wyCustomColorFilter_setDelegate00
static int tolua_filters_wyCustomColorFilter_setDelegate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyCustomColorFilter",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyColorFilterDelegate",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyCustomColorFilter* self = (wyCustomColorFilter*)  tolua_tousertype(tolua_S,1,0);
  wyColorFilterDelegate* delegate = ((wyColorFilterDelegate*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setDelegate'", NULL);
#endif
  {
   self->setDelegate(delegate);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setDelegate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_filters_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyColorFilter","wyColorFilter","wyObject",tolua_collect_wyColorFilter);
  #else
  tolua_cclass(tolua_S,"wyColorFilter","wyColorFilter","wyObject",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyColorFilter");
   tolua_function(tolua_S,"delete",tolua_filters_wyColorFilter_delete00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyColorMatrix","wyColorMatrix","wyObject",tolua_collect_wyColorMatrix);
  #else
  tolua_cclass(tolua_S,"wyColorMatrix","wyColorMatrix","wyObject",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyColorMatrix");
   tolua_function(tolua_S,"delete",tolua_filters_wyColorMatrix_delete00);
   tolua_function(tolua_S,"make",tolua_filters_wyColorMatrix_make00);
   tolua_function(tolua_S,"make",tolua_filters_wyColorMatrix_make01);
   tolua_function(tolua_S,"reset",tolua_filters_wyColorMatrix_reset00);
   tolua_function(tolua_S,"getMatrix",tolua_filters_wyColorMatrix_getMatrix00);
   tolua_function(tolua_S,"setMatrix",tolua_filters_wyColorMatrix_setMatrix00);
   tolua_function(tolua_S,"setMatrix",tolua_filters_wyColorMatrix_setMatrix01);
   tolua_function(tolua_S,"setScale",tolua_filters_wyColorMatrix_setScale00);
   tolua_function(tolua_S,"setRotate",tolua_filters_wyColorMatrix_setRotate00);
   tolua_function(tolua_S,"setConcat",tolua_filters_wyColorMatrix_setConcat00);
   tolua_function(tolua_S,"preConcat",tolua_filters_wyColorMatrix_preConcat00);
   tolua_function(tolua_S,"postConcat",tolua_filters_wyColorMatrix_postConcat00);
   tolua_function(tolua_S,"setSaturation",tolua_filters_wyColorMatrix_setSaturation00);
   tolua_function(tolua_S,"setRGB2YUV",tolua_filters_wyColorMatrix_setRGB2YUV00);
   tolua_function(tolua_S,"setYUV2RGB",tolua_filters_wyColorMatrix_setYUV2RGB00);
   tolua_function(tolua_S,"setNegative",tolua_filters_wyColorMatrix_setNegative00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyColorMatrixColorFilter","wyColorMatrixColorFilter","wyColorFilter",tolua_collect_wyColorMatrixColorFilter);
  #else
  tolua_cclass(tolua_S,"wyColorMatrixColorFilter","wyColorMatrixColorFilter","wyColorFilter",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyColorMatrixColorFilter");
   tolua_function(tolua_S,"delete",tolua_filters_wyColorMatrixColorFilter_delete00);
   tolua_function(tolua_S,"make",tolua_filters_wyColorMatrixColorFilter_make00);
   tolua_function(tolua_S,"apply",tolua_filters_wyColorMatrixColorFilter_apply00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyLightingColorFilter","wyLightingColorFilter","wyColorFilter",tolua_collect_wyLightingColorFilter);
  #else
  tolua_cclass(tolua_S,"wyLightingColorFilter","wyLightingColorFilter","wyColorFilter",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyLightingColorFilter");
   tolua_function(tolua_S,"delete",tolua_filters_wyLightingColorFilter_delete00);
   tolua_function(tolua_S,"make",tolua_filters_wyLightingColorFilter_make00);
   tolua_function(tolua_S,"apply",tolua_filters_wyLightingColorFilter_apply00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyMappingColorFilter","wyMappingColorFilter","wyColorFilter",tolua_collect_wyMappingColorFilter);
  #else
  tolua_cclass(tolua_S,"wyMappingColorFilter","wyMappingColorFilter","wyColorFilter",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyMappingColorFilter");
   tolua_function(tolua_S,"delete",tolua_filters_wyMappingColorFilter_delete00);
   tolua_function(tolua_S,"make",tolua_filters_wyMappingColorFilter_make00);
   tolua_function(tolua_S,"apply",tolua_filters_wyMappingColorFilter_apply00);
   tolua_function(tolua_S,"mapColor",tolua_filters_wyMappingColorFilter_mapColor00);
   tolua_function(tolua_S,"unmapColor",tolua_filters_wyMappingColorFilter_unmapColor00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyCombineColorFilter","wyCombineColorFilter","wyColorFilter",tolua_collect_wyCombineColorFilter);
  #else
  tolua_cclass(tolua_S,"wyCombineColorFilter","wyCombineColorFilter","wyColorFilter",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyCombineColorFilter");
   tolua_function(tolua_S,"delete",tolua_filters_wyCombineColorFilter_delete00);
   tolua_function(tolua_S,"addFilter",tolua_filters_wyCombineColorFilter_addFilter00);
   tolua_function(tolua_S,"apply",tolua_filters_wyCombineColorFilter_apply00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyEmbossColorFilter","wyEmbossColorFilter","wyColorFilter",tolua_collect_wyEmbossColorFilter);
  #else
  tolua_cclass(tolua_S,"wyEmbossColorFilter","wyEmbossColorFilter","wyColorFilter",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyEmbossColorFilter");
   tolua_function(tolua_S,"delete",tolua_filters_wyEmbossColorFilter_delete00);
   tolua_function(tolua_S,"make",tolua_filters_wyEmbossColorFilter_make00);
   tolua_function(tolua_S,"apply",tolua_filters_wyEmbossColorFilter_apply00);
   tolua_function(tolua_S,"setGrayLevel",tolua_filters_wyEmbossColorFilter_setGrayLevel00);
   tolua_function(tolua_S,"getGrayLevel",tolua_filters_wyEmbossColorFilter_getGrayLevel00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyBlurColorFilter","wyBlurColorFilter","wyColorFilter",tolua_collect_wyBlurColorFilter);
  #else
  tolua_cclass(tolua_S,"wyBlurColorFilter","wyBlurColorFilter","wyColorFilter",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyBlurColorFilter");
   tolua_function(tolua_S,"delete",tolua_filters_wyBlurColorFilter_delete00);
   tolua_function(tolua_S,"make",tolua_filters_wyBlurColorFilter_make00);
   tolua_function(tolua_S,"apply",tolua_filters_wyBlurColorFilter_apply00);
   tolua_function(tolua_S,"setRadius",tolua_filters_wyBlurColorFilter_setRadius00);
   tolua_function(tolua_S,"getRadius",tolua_filters_wyBlurColorFilter_getRadius00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyGlowColorFilter","wyGlowColorFilter","wyColorFilter",tolua_collect_wyGlowColorFilter);
  #else
  tolua_cclass(tolua_S,"wyGlowColorFilter","wyGlowColorFilter","wyColorFilter",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyGlowColorFilter");
   tolua_function(tolua_S,"delete",tolua_filters_wyGlowColorFilter_delete00);
   tolua_function(tolua_S,"make",tolua_filters_wyGlowColorFilter_make00);
   tolua_function(tolua_S,"apply",tolua_filters_wyGlowColorFilter_apply00);
   tolua_function(tolua_S,"setRadius",tolua_filters_wyGlowColorFilter_setRadius00);
   tolua_function(tolua_S,"getRadius",tolua_filters_wyGlowColorFilter_getRadius00);
   tolua_function(tolua_S,"setOpacity",tolua_filters_wyGlowColorFilter_setOpacity00);
   tolua_function(tolua_S,"getOpacity",tolua_filters_wyGlowColorFilter_getOpacity00);
   tolua_function(tolua_S,"setHighlightRadius",tolua_filters_wyGlowColorFilter_setHighlightRadius00);
   tolua_function(tolua_S,"getHighlightRadius",tolua_filters_wyGlowColorFilter_getHighlightRadius00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyDropShadowColorFilter","wyDropShadowColorFilter","wyColorFilter",tolua_collect_wyDropShadowColorFilter);
  #else
  tolua_cclass(tolua_S,"wyDropShadowColorFilter","wyDropShadowColorFilter","wyColorFilter",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyDropShadowColorFilter");
   tolua_function(tolua_S,"delete",tolua_filters_wyDropShadowColorFilter_delete00);
   tolua_function(tolua_S,"make",tolua_filters_wyDropShadowColorFilter_make00);
   tolua_function(tolua_S,"apply",tolua_filters_wyDropShadowColorFilter_apply00);
   tolua_function(tolua_S,"setRadius",tolua_filters_wyDropShadowColorFilter_setRadius00);
   tolua_function(tolua_S,"getRadius",tolua_filters_wyDropShadowColorFilter_getRadius00);
   tolua_function(tolua_S,"setOpacity",tolua_filters_wyDropShadowColorFilter_setOpacity00);
   tolua_function(tolua_S,"getOpacity",tolua_filters_wyDropShadowColorFilter_getOpacity00);
   tolua_function(tolua_S,"setHighlightRadius",tolua_filters_wyDropShadowColorFilter_setHighlightRadius00);
   tolua_function(tolua_S,"getHighlightRadius",tolua_filters_wyDropShadowColorFilter_getHighlightRadius00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyAreaColorFilter","wyAreaColorFilter","wyColorFilter",tolua_collect_wyAreaColorFilter);
  #else
  tolua_cclass(tolua_S,"wyAreaColorFilter","wyAreaColorFilter","wyColorFilter",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyAreaColorFilter");
   tolua_function(tolua_S,"delete",tolua_filters_wyAreaColorFilter_delete00);
   tolua_function(tolua_S,"make",tolua_filters_wyAreaColorFilter_make00);
   tolua_function(tolua_S,"apply",tolua_filters_wyAreaColorFilter_apply00);
   tolua_function(tolua_S,"mapPoint",tolua_filters_wyAreaColorFilter_mapPoint00);
   tolua_function(tolua_S,"removePoint",tolua_filters_wyAreaColorFilter_removePoint00);
   tolua_function(tolua_S,"mapLine",tolua_filters_wyAreaColorFilter_mapLine00);
   tolua_function(tolua_S,"removeLine",tolua_filters_wyAreaColorFilter_removeLine00);
   tolua_function(tolua_S,"mapRect",tolua_filters_wyAreaColorFilter_mapRect00);
   tolua_function(tolua_S,"removeRect",tolua_filters_wyAreaColorFilter_removeRect00);
   tolua_function(tolua_S,"mapCircle",tolua_filters_wyAreaColorFilter_mapCircle00);
   tolua_function(tolua_S,"removeCircle",tolua_filters_wyAreaColorFilter_removeCircle00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"wyColorFilterDelegate","wyColorFilterDelegate","",NULL);
  tolua_beginmodule(tolua_S,"wyColorFilterDelegate");
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyCustomColorFilter","wyCustomColorFilter","wyColorFilter",tolua_collect_wyCustomColorFilter);
  #else
  tolua_cclass(tolua_S,"wyCustomColorFilter","wyCustomColorFilter","wyColorFilter",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyCustomColorFilter");
   tolua_function(tolua_S,"delete",tolua_filters_wyCustomColorFilter_delete00);
   tolua_function(tolua_S,"make",tolua_filters_wyCustomColorFilter_make00);
   tolua_function(tolua_S,"apply",tolua_filters_wyCustomColorFilter_apply00);
   tolua_function(tolua_S,"setDelegate",tolua_filters_wyCustomColorFilter_setDelegate00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_filters (lua_State* tolua_S) {
 return tolua_filters_open(tolua_S);
};
#endif

