/*
** Lua binding: types
** Generated automatically by tolua++-1.0.92 on Tue Nov  6 15:08:46 2012.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_types_open (lua_State* tolua_S);

#include "WiEngine.h"

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_wyVertex3D (lua_State* tolua_S)
{
 wyVertex3D* self = (wyVertex3D*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wySize (lua_State* tolua_S)
{
 wySize* self = (wySize*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyColor4F (lua_State* tolua_S)
{
 wyColor4F* self = (wyColor4F*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyQuad3D (lua_State* tolua_S)
{
 wyQuad3D* self = (wyQuad3D*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyPoint (lua_State* tolua_S)
{
 wyPoint* self = (wyPoint*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyQuad2D (lua_State* tolua_S)
{
 wyQuad2D* self = (wyQuad2D*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyAffineTransform (lua_State* tolua_S)
{
 wyAffineTransform* self = (wyAffineTransform*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyDimension (lua_State* tolua_S)
{
 wyDimension* self = (wyDimension*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyColor4B (lua_State* tolua_S)
{
 wyColor4B* self = (wyColor4B*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyRect (lua_State* tolua_S)
{
 wyRect* self = (wyRect*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyColor3B (lua_State* tolua_S)
{
 wyColor3B* self = (wyColor3B*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyBlendFunc (lua_State* tolua_S)
{
 wyBlendFunc* self = (wyBlendFunc*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"wyLagrangeConfig");
 tolua_usertype(tolua_S,"wySize");
 tolua_usertype(tolua_S,"wyColor4F");
 tolua_usertype(tolua_S,"wyPoint");
 tolua_usertype(tolua_S,"wyKeyValueHash");
 tolua_usertype(tolua_S,"wyKeyEvent");
 tolua_usertype(tolua_S,"wyColor4B");
 tolua_usertype(tolua_S,"wyRect");
 tolua_usertype(tolua_S,"int64_t");
 tolua_usertype(tolua_S,"wyPVRHeader");
 tolua_usertype(tolua_S,"wyMotionEvent");
 tolua_usertype(tolua_S,"wyBezierConfig");
 tolua_usertype(tolua_S,"wyQuad2D");
 tolua_usertype(tolua_S,"wyVertex3D");
 tolua_usertype(tolua_S,"wyHypotrochoidConfig");
 tolua_usertype(tolua_S,"wyDimension");
 tolua_usertype(tolua_S,"wyColor3B");
 tolua_usertype(tolua_S,"wyBlendFunc");
 tolua_usertype(tolua_S,"wyAffineTransform");
 tolua_usertype(tolua_S,"wyQuad3D");
}

/* get function: wyaZero */
#ifndef TOLUA_DISABLE_tolua_get_wyaZero
static int tolua_get_wyaZero(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&wyaZero,"const wyAffineTransform");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: wyaIdentity */
#ifndef TOLUA_DISABLE_tolua_get_wyaIdentity
static int tolua_get_wyaIdentity(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&wyaIdentity,"const wyAffineTransform");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* function: wyaSetToRotation */
#ifndef TOLUA_DISABLE_tolua_types_wyaSetToRotation00
static int tolua_types_wyaSetToRotation00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAffineTransform",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAffineTransform* t = ((wyAffineTransform*)  tolua_tousertype(tolua_S,1,0));
  float angle = ((float)  tolua_tonumber(tolua_S,2,0));
  float px = ((float)  tolua_tonumber(tolua_S,3,0.f));
  float py = ((float)  tolua_tonumber(tolua_S,4,0.f));
  {
   wyaSetToRotation(t,angle,px,py);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'wyaSetToRotation'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: wyaMakeRotate */
#ifndef TOLUA_DISABLE_tolua_types_wyaMakeRotate00
static int tolua_types_wyaMakeRotate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float angle = ((float)  tolua_tonumber(tolua_S,1,0));
  float x = ((float)  tolua_tonumber(tolua_S,2,0.f));
  float y = ((float)  tolua_tonumber(tolua_S,3,0.f));
  {
   const wyAffineTransform tolua_ret = (const wyAffineTransform)  wyaMakeRotate(angle,x,y);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((wyAffineTransform)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"const wyAffineTransform");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(const wyAffineTransform));
     tolua_pushusertype(tolua_S,tolua_obj,"const wyAffineTransform");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'wyaMakeRotate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: wyaScale */
#ifndef TOLUA_DISABLE_tolua_types_wyaScale00
static int tolua_types_wyaScale00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAffineTransform",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAffineTransform* t = ((wyAffineTransform*)  tolua_tousertype(tolua_S,1,0));
  float scx = ((float)  tolua_tonumber(tolua_S,2,0));
  float scy = ((float)  tolua_tonumber(tolua_S,3,0));
  {
   wyaScale(t,scx,scy);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'wyaScale'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: wyaTranslate */
#ifndef TOLUA_DISABLE_tolua_types_wyaTranslate00
static int tolua_types_wyaTranslate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAffineTransform",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAffineTransform* t = ((wyAffineTransform*)  tolua_tousertype(tolua_S,1,0));
  float dx = ((float)  tolua_tonumber(tolua_S,2,0));
  float dy = ((float)  tolua_tonumber(tolua_S,3,0));
  {
   wyaTranslate(t,dx,dy);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'wyaTranslate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: wyaRotate */
#ifndef TOLUA_DISABLE_tolua_types_wyaRotate00
static int tolua_types_wyaRotate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAffineTransform",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAffineTransform* t = ((wyAffineTransform*)  tolua_tousertype(tolua_S,1,0));
  float angle = ((float)  tolua_tonumber(tolua_S,2,0));
  {
   wyaRotate(t,angle);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'wyaRotate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: wyaGetDeterminant */
#ifndef TOLUA_DISABLE_tolua_types_wyaGetDeterminant00
static int tolua_types_wyaGetDeterminant00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAffineTransform",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAffineTransform* t = ((wyAffineTransform*)  tolua_tousertype(tolua_S,1,0));
  {
   float tolua_ret = (float)  wyaGetDeterminant(t);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'wyaGetDeterminant'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: wyaSetToIdentity */
#ifndef TOLUA_DISABLE_tolua_types_wyaSetToIdentity00
static int tolua_types_wyaSetToIdentity00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAffineTransform",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAffineTransform* t = ((wyAffineTransform*)  tolua_tousertype(tolua_S,1,0));
  {
   wyaSetToIdentity(t);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'wyaSetToIdentity'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: wyaInverse */
#ifndef TOLUA_DISABLE_tolua_types_wyaInverse00
static int tolua_types_wyaInverse00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAffineTransform",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAffineTransform* t = ((wyAffineTransform*)  tolua_tousertype(tolua_S,1,0));
  {
   wyaInverse(t);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'wyaInverse'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: wyaTransformPoint */
#ifndef TOLUA_DISABLE_tolua_types_wyaTransformPoint00
static int tolua_types_wyaTransformPoint00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     (tolua_isvaluenil(tolua_S,1,&tolua_err) || !tolua_isusertype(tolua_S,1,"wyAffineTransform",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"wyPoint",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAffineTransform* t = ((wyAffineTransform*)  tolua_tousertype(tolua_S,1,0));
  wyPoint p = *((wyPoint*)  tolua_tousertype(tolua_S,2,0));
  {
   wyPoint tolua_ret = (wyPoint)  wyaTransformPoint(*t,p);
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
 tolua_error(tolua_S,"#ferror in function 'wyaTransformPoint'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: wyaTransformRect */
#ifndef TOLUA_DISABLE_tolua_types_wyaTransformRect00
static int tolua_types_wyaTransformRect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     (tolua_isvaluenil(tolua_S,1,&tolua_err) || !tolua_isusertype(tolua_S,1,"wyAffineTransform",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"wyRect",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAffineTransform* t = ((wyAffineTransform*)  tolua_tousertype(tolua_S,1,0));
  wyRect r = *((wyRect*)  tolua_tousertype(tolua_S,2,0));
  {
   wyRect tolua_ret = (wyRect)  wyaTransformRect(*t,r);
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
 tolua_error(tolua_S,"#ferror in function 'wyaTransformRect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: wyaMultiply */
#ifndef TOLUA_DISABLE_tolua_types_wyaMultiply00
static int tolua_types_wyaMultiply00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAffineTransform",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyAffineTransform",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAffineTransform* t1 = ((wyAffineTransform*)  tolua_tousertype(tolua_S,1,0));
  wyAffineTransform* t2 = ((wyAffineTransform*)  tolua_tousertype(tolua_S,2,0));
  {
   wyaMultiply(t1,t2);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'wyaMultiply'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: wyaConcat */
#ifndef TOLUA_DISABLE_tolua_types_wyaConcat00
static int tolua_types_wyaConcat00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAffineTransform",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyAffineTransform",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAffineTransform* t1 = ((wyAffineTransform*)  tolua_tousertype(tolua_S,1,0));
  wyAffineTransform* t2 = ((wyAffineTransform*)  tolua_tousertype(tolua_S,2,0));
  {
   wyaConcat(t1,t2);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'wyaConcat'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: wybfDefault */
#ifndef TOLUA_DISABLE_tolua_get_wybfDefault
static int tolua_get_wybfDefault(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&wybfDefault,"const wyBlendFunc");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* function: wybf */
#ifndef TOLUA_DISABLE_tolua_types_wybf00
static int tolua_types_wybf00(lua_State* tolua_S)
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
  int src = ((int)  tolua_tonumber(tolua_S,1,0));
  int dst = ((int)  tolua_tonumber(tolua_S,2,0));
  {
   wyBlendFunc tolua_ret = (wyBlendFunc)  wybf(src,dst);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((wyBlendFunc)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"wyBlendFunc");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(wyBlendFunc));
     tolua_pushusertype(tolua_S,tolua_obj,"wyBlendFunc");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'wybf'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: wyc3bWhite */
#ifndef TOLUA_DISABLE_tolua_get_wyc3bWhite
static int tolua_get_wyc3bWhite(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&wyc3bWhite,"const wyColor3B");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: wyc3bBlack */
#ifndef TOLUA_DISABLE_tolua_get_wyc3bBlack
static int tolua_get_wyc3bBlack(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&wyc3bBlack,"const wyColor3B");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: wyc3bRed */
#ifndef TOLUA_DISABLE_tolua_get_wyc3bRed
static int tolua_get_wyc3bRed(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&wyc3bRed,"const wyColor3B");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: wyc3bGray */
#ifndef TOLUA_DISABLE_tolua_get_wyc3bGray
static int tolua_get_wyc3bGray(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&wyc3bGray,"const wyColor3B");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* function: wyc3b */
#ifndef TOLUA_DISABLE_tolua_types_wyc3b00
static int tolua_types_wyc3b00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  unsigned char r = ((unsigned char)  tolua_tonumber(tolua_S,1,0));
  unsigned char g = ((unsigned char)  tolua_tonumber(tolua_S,2,0));
  unsigned char b = ((unsigned char)  tolua_tonumber(tolua_S,3,0));
  {
   wyColor3B tolua_ret = (wyColor3B)  wyc3b(r,g,b);
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
 tolua_error(tolua_S,"#ferror in function 'wyc3b'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: wyc3b2c4f */
#ifndef TOLUA_DISABLE_tolua_types_wyc3b2c4f00
static int tolua_types_wyc3b2c4f00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     (tolua_isvaluenil(tolua_S,1,&tolua_err) || !tolua_isusertype(tolua_S,1,"wyColor3B",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyColor3B* c = ((wyColor3B*)  tolua_tousertype(tolua_S,1,0));
  {
   wyColor4F tolua_ret = (wyColor4F)  wyc3b2c4f(*c);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((wyColor4F)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"wyColor4F");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(wyColor4F));
     tolua_pushusertype(tolua_S,tolua_obj,"wyColor4F");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'wyc3b2c4f'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: wyc4bWhite */
#ifndef TOLUA_DISABLE_tolua_get_wyc4bWhite
static int tolua_get_wyc4bWhite(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&wyc4bWhite,"const wyColor4B");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: wyc4bGray */
#ifndef TOLUA_DISABLE_tolua_get_wyc4bGray
static int tolua_get_wyc4bGray(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&wyc4bGray,"const wyColor4B");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: wyc4bBlue */
#ifndef TOLUA_DISABLE_tolua_get_wyc4bBlue
static int tolua_get_wyc4bBlue(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&wyc4bBlue,"const wyColor4B");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: wyc4bTransparent */
#ifndef TOLUA_DISABLE_tolua_get_wyc4bTransparent
static int tolua_get_wyc4bTransparent(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&wyc4bTransparent,"const wyColor4B");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* function: wyc4b */
#ifndef TOLUA_DISABLE_tolua_types_wyc4b00
static int tolua_types_wyc4b00(lua_State* tolua_S)
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
  unsigned char r = ((unsigned char)  tolua_tonumber(tolua_S,1,0));
  unsigned char g = ((unsigned char)  tolua_tonumber(tolua_S,2,0));
  unsigned char b = ((unsigned char)  tolua_tonumber(tolua_S,3,0));
  unsigned char a = ((unsigned char)  tolua_tonumber(tolua_S,4,0));
  {
   wyColor4B tolua_ret = (wyColor4B)  wyc4b(r,g,b,a);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((wyColor4B)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"wyColor4B");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(wyColor4B));
     tolua_pushusertype(tolua_S,tolua_obj,"wyColor4B");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'wyc4b'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: wyc4fWhite */
#ifndef TOLUA_DISABLE_tolua_get_wyc4fWhite
static int tolua_get_wyc4fWhite(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&wyc4fWhite,"const wyColor4F");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* function: wyc4f */
#ifndef TOLUA_DISABLE_tolua_types_wyc4f00
static int tolua_types_wyc4f00(lua_State* tolua_S)
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
  float r = ((float)  tolua_tonumber(tolua_S,1,0));
  float g = ((float)  tolua_tonumber(tolua_S,2,0));
  float b = ((float)  tolua_tonumber(tolua_S,3,0));
  float a = ((float)  tolua_tonumber(tolua_S,4,0));
  {
   wyColor4F tolua_ret = (wyColor4F)  wyc4f(r,g,b,a);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((wyColor4F)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"wyColor4F");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(wyColor4F));
     tolua_pushusertype(tolua_S,tolua_obj,"wyColor4F");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'wyc4f'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: wydZero */
#ifndef TOLUA_DISABLE_tolua_get_wydZero
static int tolua_get_wydZero(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&wydZero,"const wyDimension");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* function: wyd */
#ifndef TOLUA_DISABLE_tolua_types_wyd00
static int tolua_types_wyd00(lua_State* tolua_S)
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
  const int x = ((const int)  tolua_tonumber(tolua_S,1,0));
  const int y = ((const int)  tolua_tonumber(tolua_S,2,0));
  {
   wyDimension tolua_ret = (wyDimension)  wyd(x,y);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((wyDimension)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"wyDimension");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(wyDimension));
     tolua_pushusertype(tolua_S,tolua_obj,"wyDimension");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'wyd'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: wypZero */
#ifndef TOLUA_DISABLE_tolua_get_wypZero
static int tolua_get_wypZero(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&wypZero,"const wyPoint");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* function: wyp */
#ifndef TOLUA_DISABLE_tolua_types_wyp00
static int tolua_types_wyp00(lua_State* tolua_S)
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
   wyPoint tolua_ret = (wyPoint)  wyp(x,y);
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
 tolua_error(tolua_S,"#ferror in function 'wyp'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: wypFromString */
#ifndef TOLUA_DISABLE_tolua_types_wypFromString00
static int tolua_types_wypFromString00(lua_State* tolua_S)
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
  const char* s = ((const char*)  tolua_tostring(tolua_S,1,0));
  {
   wyPoint tolua_ret = (wyPoint)  wypFromString(s);
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
 tolua_error(tolua_S,"#ferror in function 'wypFromString'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: wypEquals */
#ifndef TOLUA_DISABLE_tolua_types_wypEquals00
static int tolua_types_wypEquals00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     (tolua_isvaluenil(tolua_S,1,&tolua_err) || !tolua_isusertype(tolua_S,1,"wyPoint",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"wyPoint",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyPoint p1 = *((wyPoint*)  tolua_tousertype(tolua_S,1,0));
  wyPoint p2 = *((wyPoint*)  tolua_tousertype(tolua_S,2,0));
  {
   bool tolua_ret = (bool)  wypEquals(p1,p2);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'wypEquals'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: wypToRadian */
#ifndef TOLUA_DISABLE_tolua_types_wypToRadian00
static int tolua_types_wypToRadian00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     (tolua_isvaluenil(tolua_S,1,&tolua_err) || !tolua_isusertype(tolua_S,1,"wyPoint",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyPoint v = *((wyPoint*)  tolua_tousertype(tolua_S,1,0));
  {
   float tolua_ret = (float)  wypToRadian(v);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'wypToRadian'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: wypMul */
#ifndef TOLUA_DISABLE_tolua_types_wypMul00
static int tolua_types_wypMul00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     (tolua_isvaluenil(tolua_S,1,&tolua_err) || !tolua_isusertype(tolua_S,1,"wyPoint",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"wyPoint",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyPoint p1 = *((wyPoint*)  tolua_tousertype(tolua_S,1,0));
  wyPoint p2 = *((wyPoint*)  tolua_tousertype(tolua_S,2,0));
  {
   wyPoint tolua_ret = (wyPoint)  wypMul(p1,p2);
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
 tolua_error(tolua_S,"#ferror in function 'wypMul'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: wypMul2 */
#ifndef TOLUA_DISABLE_tolua_types_wypMul200
static int tolua_types_wypMul200(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     (tolua_isvaluenil(tolua_S,1,&tolua_err) || !tolua_isusertype(tolua_S,1,"wyPoint",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyPoint p1 = *((wyPoint*)  tolua_tousertype(tolua_S,1,0));
  float s = ((float)  tolua_tonumber(tolua_S,2,0));
  {
   wyPoint tolua_ret = (wyPoint)  wypMul2(p1,s);
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
 tolua_error(tolua_S,"#ferror in function 'wypMul2'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: wypAdd */
#ifndef TOLUA_DISABLE_tolua_types_wypAdd00
static int tolua_types_wypAdd00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     (tolua_isvaluenil(tolua_S,1,&tolua_err) || !tolua_isusertype(tolua_S,1,"wyPoint",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"wyPoint",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyPoint p1 = *((wyPoint*)  tolua_tousertype(tolua_S,1,0));
  wyPoint p2 = *((wyPoint*)  tolua_tousertype(tolua_S,2,0));
  {
   wyPoint tolua_ret = (wyPoint)  wypAdd(p1,p2);
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
 tolua_error(tolua_S,"#ferror in function 'wypAdd'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: wypSub */
#ifndef TOLUA_DISABLE_tolua_types_wypSub00
static int tolua_types_wypSub00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     (tolua_isvaluenil(tolua_S,1,&tolua_err) || !tolua_isusertype(tolua_S,1,"wyPoint",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"wyPoint",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyPoint p1 = *((wyPoint*)  tolua_tousertype(tolua_S,1,0));
  wyPoint p2 = *((wyPoint*)  tolua_tousertype(tolua_S,2,0));
  {
   wyPoint tolua_ret = (wyPoint)  wypSub(p1,p2);
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
 tolua_error(tolua_S,"#ferror in function 'wypSub'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: wypMidpoint */
#ifndef TOLUA_DISABLE_tolua_types_wypMidpoint00
static int tolua_types_wypMidpoint00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     (tolua_isvaluenil(tolua_S,1,&tolua_err) || !tolua_isusertype(tolua_S,1,"wyPoint",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"wyPoint",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyPoint v1 = *((wyPoint*)  tolua_tousertype(tolua_S,1,0));
  wyPoint v2 = *((wyPoint*)  tolua_tousertype(tolua_S,2,0));
  {
   wyPoint tolua_ret = (wyPoint)  wypMidpoint(v1,v2);
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
 tolua_error(tolua_S,"#ferror in function 'wypMidpoint'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: wypDot */
#ifndef TOLUA_DISABLE_tolua_types_wypDot00
static int tolua_types_wypDot00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     (tolua_isvaluenil(tolua_S,1,&tolua_err) || !tolua_isusertype(tolua_S,1,"wyPoint",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"wyPoint",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyPoint v1 = *((wyPoint*)  tolua_tousertype(tolua_S,1,0));
  wyPoint v2 = *((wyPoint*)  tolua_tousertype(tolua_S,2,0));
  {
   float tolua_ret = (float)  wypDot(v1,v2);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'wypDot'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: wypCross */
#ifndef TOLUA_DISABLE_tolua_types_wypCross00
static int tolua_types_wypCross00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     (tolua_isvaluenil(tolua_S,1,&tolua_err) || !tolua_isusertype(tolua_S,1,"wyPoint",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"wyPoint",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyPoint v1 = *((wyPoint*)  tolua_tousertype(tolua_S,1,0));
  wyPoint v2 = *((wyPoint*)  tolua_tousertype(tolua_S,2,0));
  {
   float tolua_ret = (float)  wypCross(v1,v2);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'wypCross'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: wypPerp */
#ifndef TOLUA_DISABLE_tolua_types_wypPerp00
static int tolua_types_wypPerp00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     (tolua_isvaluenil(tolua_S,1,&tolua_err) || !tolua_isusertype(tolua_S,1,"wyPoint",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyPoint v = *((wyPoint*)  tolua_tousertype(tolua_S,1,0));
  {
   wyPoint tolua_ret = (wyPoint)  wypPerp(v);
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
 tolua_error(tolua_S,"#ferror in function 'wypPerp'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: wypReversePerp */
#ifndef TOLUA_DISABLE_tolua_types_wypReversePerp00
static int tolua_types_wypReversePerp00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     (tolua_isvaluenil(tolua_S,1,&tolua_err) || !tolua_isusertype(tolua_S,1,"wyPoint",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyPoint v = *((wyPoint*)  tolua_tousertype(tolua_S,1,0));
  {
   wyPoint tolua_ret = (wyPoint)  wypReversePerp(v);
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
 tolua_error(tolua_S,"#ferror in function 'wypReversePerp'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: wypLength */
#ifndef TOLUA_DISABLE_tolua_types_wypLength00
static int tolua_types_wypLength00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     (tolua_isvaluenil(tolua_S,1,&tolua_err) || !tolua_isusertype(tolua_S,1,"wyPoint",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyPoint v = *((wyPoint*)  tolua_tousertype(tolua_S,1,0));
  {
   float tolua_ret = (float)  wypLength(v);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'wypLength'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: wypLengthsq */
#ifndef TOLUA_DISABLE_tolua_types_wypLengthsq00
static int tolua_types_wypLengthsq00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     (tolua_isvaluenil(tolua_S,1,&tolua_err) || !tolua_isusertype(tolua_S,1,"wyPoint",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyPoint v = *((wyPoint*)  tolua_tousertype(tolua_S,1,0));
  {
   float tolua_ret = (float)  wypLengthsq(v);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'wypLengthsq'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: wypDistance */
#ifndef TOLUA_DISABLE_tolua_types_wypDistance00
static int tolua_types_wypDistance00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     (tolua_isvaluenil(tolua_S,1,&tolua_err) || !tolua_isusertype(tolua_S,1,"wyPoint",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"wyPoint",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyPoint v1 = *((wyPoint*)  tolua_tousertype(tolua_S,1,0));
  wyPoint v2 = *((wyPoint*)  tolua_tousertype(tolua_S,2,0));
  {
   float tolua_ret = (float)  wypDistance(v1,v2);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'wypDistance'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: wypNormalize */
#ifndef TOLUA_DISABLE_tolua_types_wypNormalize00
static int tolua_types_wypNormalize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     (tolua_isvaluenil(tolua_S,1,&tolua_err) || !tolua_isusertype(tolua_S,1,"wyPoint",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyPoint v = *((wyPoint*)  tolua_tousertype(tolua_S,1,0));
  {
   wyPoint tolua_ret = (wyPoint)  wypNormalize(v);
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
 tolua_error(tolua_S,"#ferror in function 'wypNormalize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: wypLerp */
#ifndef TOLUA_DISABLE_tolua_types_wypLerp00
static int tolua_types_wypLerp00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     (tolua_isvaluenil(tolua_S,1,&tolua_err) || !tolua_isusertype(tolua_S,1,"wyPoint",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"wyPoint",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyPoint a = *((wyPoint*)  tolua_tousertype(tolua_S,1,0));
  wyPoint b = *((wyPoint*)  tolua_tousertype(tolua_S,2,0));
  float alpha = ((float)  tolua_tonumber(tolua_S,3,0));
  {
   wyPoint tolua_ret = (wyPoint)  wypLerp(a,b,alpha);
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
 tolua_error(tolua_S,"#ferror in function 'wypLerp'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: wypRotateByAngle */
#ifndef TOLUA_DISABLE_tolua_types_wypRotateByAngle00
static int tolua_types_wypRotateByAngle00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     (tolua_isvaluenil(tolua_S,1,&tolua_err) || !tolua_isusertype(tolua_S,1,"wyPoint",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"wyPoint",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyPoint v = *((wyPoint*)  tolua_tousertype(tolua_S,1,0));
  wyPoint pivot = *((wyPoint*)  tolua_tousertype(tolua_S,2,0));
  float angle = ((float)  tolua_tonumber(tolua_S,3,0));
  {
   wyPoint tolua_ret = (wyPoint)  wypRotateByAngle(v,pivot,angle);
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
 tolua_error(tolua_S,"#ferror in function 'wypRotateByAngle'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: wypFuzzyEqual */
#ifndef TOLUA_DISABLE_tolua_types_wypFuzzyEqual00
static int tolua_types_wypFuzzyEqual00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     (tolua_isvaluenil(tolua_S,1,&tolua_err) || !tolua_isusertype(tolua_S,1,"wyPoint",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"wyPoint",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyPoint a = *((wyPoint*)  tolua_tousertype(tolua_S,1,0));
  wyPoint b = *((wyPoint*)  tolua_tousertype(tolua_S,2,0));
  float var = ((float)  tolua_tonumber(tolua_S,3,0));
  {
   bool tolua_ret = (bool)  wypFuzzyEqual(a,b,var);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'wypFuzzyEqual'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: wypLineIntersect */
#ifndef TOLUA_DISABLE_tolua_types_wypLineIntersect00
static int tolua_types_wypLineIntersect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     (tolua_isvaluenil(tolua_S,1,&tolua_err) || !tolua_isusertype(tolua_S,1,"wyPoint",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"wyPoint",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"wyPoint",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"wyPoint",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyPoint p1 = *((wyPoint*)  tolua_tousertype(tolua_S,1,0));
  wyPoint p2 = *((wyPoint*)  tolua_tousertype(tolua_S,2,0));
  wyPoint p3 = *((wyPoint*)  tolua_tousertype(tolua_S,3,0));
  wyPoint p4 = *((wyPoint*)  tolua_tousertype(tolua_S,4,0));
  float st = ((float)  tolua_tonumber(tolua_S,5,0));
  {
   bool tolua_ret = (bool)  wypLineIntersect(p1,p2,p3,p4,&st);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
   tolua_pushnumber(tolua_S,(lua_Number)st);
  }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'wypLineIntersect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: headerLength of class  wyPVRHeader */
#ifndef TOLUA_DISABLE_tolua_get_wyPVRHeader_headerLength
static int tolua_get_wyPVRHeader_headerLength(lua_State* tolua_S)
{
  wyPVRHeader* self = (wyPVRHeader*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'headerLength'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->headerLength);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: headerLength of class  wyPVRHeader */
#ifndef TOLUA_DISABLE_tolua_set_wyPVRHeader_headerLength
static int tolua_set_wyPVRHeader_headerLength(lua_State* tolua_S)
{
  wyPVRHeader* self = (wyPVRHeader*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'headerLength'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->headerLength = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: height of class  wyPVRHeader */
#ifndef TOLUA_DISABLE_tolua_get_wyPVRHeader_height
static int tolua_get_wyPVRHeader_height(lua_State* tolua_S)
{
  wyPVRHeader* self = (wyPVRHeader*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'height'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->height);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: height of class  wyPVRHeader */
#ifndef TOLUA_DISABLE_tolua_set_wyPVRHeader_height
static int tolua_set_wyPVRHeader_height(lua_State* tolua_S)
{
  wyPVRHeader* self = (wyPVRHeader*)  tolua_tousertype(tolua_S,1,0);
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

/* get function: width of class  wyPVRHeader */
#ifndef TOLUA_DISABLE_tolua_get_wyPVRHeader_width
static int tolua_get_wyPVRHeader_width(lua_State* tolua_S)
{
  wyPVRHeader* self = (wyPVRHeader*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'width'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->width);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: width of class  wyPVRHeader */
#ifndef TOLUA_DISABLE_tolua_set_wyPVRHeader_width
static int tolua_set_wyPVRHeader_width(lua_State* tolua_S)
{
  wyPVRHeader* self = (wyPVRHeader*)  tolua_tousertype(tolua_S,1,0);
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

/* get function: numMipmaps of class  wyPVRHeader */
#ifndef TOLUA_DISABLE_tolua_get_wyPVRHeader_numMipmaps
static int tolua_get_wyPVRHeader_numMipmaps(lua_State* tolua_S)
{
  wyPVRHeader* self = (wyPVRHeader*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'numMipmaps'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->numMipmaps);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: numMipmaps of class  wyPVRHeader */
#ifndef TOLUA_DISABLE_tolua_set_wyPVRHeader_numMipmaps
static int tolua_set_wyPVRHeader_numMipmaps(lua_State* tolua_S)
{
  wyPVRHeader* self = (wyPVRHeader*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'numMipmaps'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->numMipmaps = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: flags of class  wyPVRHeader */
#ifndef TOLUA_DISABLE_tolua_get_wyPVRHeader_flags
static int tolua_get_wyPVRHeader_flags(lua_State* tolua_S)
{
  wyPVRHeader* self = (wyPVRHeader*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'flags'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->flags);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: flags of class  wyPVRHeader */
#ifndef TOLUA_DISABLE_tolua_set_wyPVRHeader_flags
static int tolua_set_wyPVRHeader_flags(lua_State* tolua_S)
{
  wyPVRHeader* self = (wyPVRHeader*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'flags'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->flags = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: dataLength of class  wyPVRHeader */
#ifndef TOLUA_DISABLE_tolua_get_wyPVRHeader_dataLength
static int tolua_get_wyPVRHeader_dataLength(lua_State* tolua_S)
{
  wyPVRHeader* self = (wyPVRHeader*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'dataLength'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->dataLength);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: dataLength of class  wyPVRHeader */
#ifndef TOLUA_DISABLE_tolua_set_wyPVRHeader_dataLength
static int tolua_set_wyPVRHeader_dataLength(lua_State* tolua_S)
{
  wyPVRHeader* self = (wyPVRHeader*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'dataLength'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->dataLength = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: bpp of class  wyPVRHeader */
#ifndef TOLUA_DISABLE_tolua_get_wyPVRHeader_bpp
static int tolua_get_wyPVRHeader_bpp(lua_State* tolua_S)
{
  wyPVRHeader* self = (wyPVRHeader*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'bpp'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->bpp);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: bpp of class  wyPVRHeader */
#ifndef TOLUA_DISABLE_tolua_set_wyPVRHeader_bpp
static int tolua_set_wyPVRHeader_bpp(lua_State* tolua_S)
{
  wyPVRHeader* self = (wyPVRHeader*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'bpp'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->bpp = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: bitmaskRed of class  wyPVRHeader */
#ifndef TOLUA_DISABLE_tolua_get_wyPVRHeader_bitmaskRed
static int tolua_get_wyPVRHeader_bitmaskRed(lua_State* tolua_S)
{
  wyPVRHeader* self = (wyPVRHeader*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'bitmaskRed'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->bitmaskRed);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: bitmaskRed of class  wyPVRHeader */
#ifndef TOLUA_DISABLE_tolua_set_wyPVRHeader_bitmaskRed
static int tolua_set_wyPVRHeader_bitmaskRed(lua_State* tolua_S)
{
  wyPVRHeader* self = (wyPVRHeader*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'bitmaskRed'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->bitmaskRed = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: bitmaskGreen of class  wyPVRHeader */
#ifndef TOLUA_DISABLE_tolua_get_wyPVRHeader_bitmaskGreen
static int tolua_get_wyPVRHeader_bitmaskGreen(lua_State* tolua_S)
{
  wyPVRHeader* self = (wyPVRHeader*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'bitmaskGreen'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->bitmaskGreen);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: bitmaskGreen of class  wyPVRHeader */
#ifndef TOLUA_DISABLE_tolua_set_wyPVRHeader_bitmaskGreen
static int tolua_set_wyPVRHeader_bitmaskGreen(lua_State* tolua_S)
{
  wyPVRHeader* self = (wyPVRHeader*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'bitmaskGreen'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->bitmaskGreen = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: bitmaskBlue of class  wyPVRHeader */
#ifndef TOLUA_DISABLE_tolua_get_wyPVRHeader_bitmaskBlue
static int tolua_get_wyPVRHeader_bitmaskBlue(lua_State* tolua_S)
{
  wyPVRHeader* self = (wyPVRHeader*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'bitmaskBlue'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->bitmaskBlue);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: bitmaskBlue of class  wyPVRHeader */
#ifndef TOLUA_DISABLE_tolua_set_wyPVRHeader_bitmaskBlue
static int tolua_set_wyPVRHeader_bitmaskBlue(lua_State* tolua_S)
{
  wyPVRHeader* self = (wyPVRHeader*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'bitmaskBlue'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->bitmaskBlue = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: bitmaskAlpha of class  wyPVRHeader */
#ifndef TOLUA_DISABLE_tolua_get_wyPVRHeader_bitmaskAlpha
static int tolua_get_wyPVRHeader_bitmaskAlpha(lua_State* tolua_S)
{
  wyPVRHeader* self = (wyPVRHeader*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'bitmaskAlpha'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->bitmaskAlpha);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: bitmaskAlpha of class  wyPVRHeader */
#ifndef TOLUA_DISABLE_tolua_set_wyPVRHeader_bitmaskAlpha
static int tolua_set_wyPVRHeader_bitmaskAlpha(lua_State* tolua_S)
{
  wyPVRHeader* self = (wyPVRHeader*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'bitmaskAlpha'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->bitmaskAlpha = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: pvrTag of class  wyPVRHeader */
#ifndef TOLUA_DISABLE_tolua_get_wyPVRHeader_pvrTag
static int tolua_get_wyPVRHeader_pvrTag(lua_State* tolua_S)
{
  wyPVRHeader* self = (wyPVRHeader*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'pvrTag'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->pvrTag);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: pvrTag of class  wyPVRHeader */
#ifndef TOLUA_DISABLE_tolua_set_wyPVRHeader_pvrTag
static int tolua_set_wyPVRHeader_pvrTag(lua_State* tolua_S)
{
  wyPVRHeader* self = (wyPVRHeader*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'pvrTag'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->pvrTag = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: numSurfs of class  wyPVRHeader */
#ifndef TOLUA_DISABLE_tolua_get_wyPVRHeader_numSurfs
static int tolua_get_wyPVRHeader_numSurfs(lua_State* tolua_S)
{
  wyPVRHeader* self = (wyPVRHeader*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'numSurfs'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->numSurfs);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: numSurfs of class  wyPVRHeader */
#ifndef TOLUA_DISABLE_tolua_set_wyPVRHeader_numSurfs
static int tolua_set_wyPVRHeader_numSurfs(lua_State* tolua_S)
{
  wyPVRHeader* self = (wyPVRHeader*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'numSurfs'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->numSurfs = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: wyq2Zero */
#ifndef TOLUA_DISABLE_tolua_get_wyq2Zero
static int tolua_get_wyq2Zero(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&wyq2Zero,"const wyQuad2D");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* function: wyq2 */
#ifndef TOLUA_DISABLE_tolua_types_wyq200
static int tolua_types_wyq200(lua_State* tolua_S)
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
     !tolua_isnumber(tolua_S,8,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,9,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const float bl_x = ((const float)  tolua_tonumber(tolua_S,1,0));
  const float bl_y = ((const float)  tolua_tonumber(tolua_S,2,0));
  const float br_x = ((const float)  tolua_tonumber(tolua_S,3,0));
  const float br_y = ((const float)  tolua_tonumber(tolua_S,4,0));
  const float tl_x = ((const float)  tolua_tonumber(tolua_S,5,0));
  const float tl_y = ((const float)  tolua_tonumber(tolua_S,6,0));
  const float tr_x = ((const float)  tolua_tonumber(tolua_S,7,0));
  const float tr_y = ((const float)  tolua_tonumber(tolua_S,8,0));
  {
   wyQuad2D tolua_ret = (wyQuad2D)  wyq2(bl_x,bl_y,br_x,br_y,tl_x,tl_y,tr_x,tr_y);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((wyQuad2D)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"wyQuad2D");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(wyQuad2D));
     tolua_pushusertype(tolua_S,tolua_obj,"wyQuad2D");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'wyq2'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: wyq2Scale */
#ifndef TOLUA_DISABLE_tolua_types_wyq2Scale00
static int tolua_types_wyq2Scale00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     (tolua_isvaluenil(tolua_S,1,&tolua_err) || !tolua_isusertype(tolua_S,1,"wyQuad2D",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyQuad2D q = *((wyQuad2D*)  tolua_tousertype(tolua_S,1,0));
  float s = ((float)  tolua_tonumber(tolua_S,2,0));
  {
   wyQuad2D tolua_ret = (wyQuad2D)  wyq2Scale(q,s);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((wyQuad2D)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"wyQuad2D");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(wyQuad2D));
     tolua_pushusertype(tolua_S,tolua_obj,"wyQuad2D");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'wyq2Scale'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: wyq2Set */
#ifndef TOLUA_DISABLE_tolua_types_wyq2Set00
static int tolua_types_wyq2Set00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     (tolua_isvaluenil(tolua_S,1,&tolua_err) || !tolua_isusertype(tolua_S,1,"wyQuad2D",0,&tolua_err)) ||
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
  wyQuad2D* t = ((wyQuad2D*)  tolua_tousertype(tolua_S,1,0));
  const float bl_x = ((const float)  tolua_tonumber(tolua_S,2,0));
  const float bl_y = ((const float)  tolua_tonumber(tolua_S,3,0));
  const float br_x = ((const float)  tolua_tonumber(tolua_S,4,0));
  const float br_y = ((const float)  tolua_tonumber(tolua_S,5,0));
  const float tl_x = ((const float)  tolua_tonumber(tolua_S,6,0));
  const float tl_y = ((const float)  tolua_tonumber(tolua_S,7,0));
  const float tr_x = ((const float)  tolua_tonumber(tolua_S,8,0));
  const float tr_y = ((const float)  tolua_tonumber(tolua_S,9,0));
  {
   wyq2Set(*t,bl_x,bl_y,br_x,br_y,tl_x,tl_y,tr_x,tr_y);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'wyq2Set'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: wyq3Zero */
#ifndef TOLUA_DISABLE_tolua_get_wyq3Zero
static int tolua_get_wyq3Zero(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&wyq3Zero,"const wyQuad3D");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* function: wyq3 */
#ifndef TOLUA_DISABLE_tolua_types_wyq300
static int tolua_types_wyq300(lua_State* tolua_S)
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
     !tolua_isnumber(tolua_S,8,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,9,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,10,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,11,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,12,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,13,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const float bl_x = ((const float)  tolua_tonumber(tolua_S,1,0));
  const float bl_y = ((const float)  tolua_tonumber(tolua_S,2,0));
  const float bl_z = ((const float)  tolua_tonumber(tolua_S,3,0));
  const float br_x = ((const float)  tolua_tonumber(tolua_S,4,0));
  const float br_y = ((const float)  tolua_tonumber(tolua_S,5,0));
  const float br_z = ((const float)  tolua_tonumber(tolua_S,6,0));
  const float tl_x = ((const float)  tolua_tonumber(tolua_S,7,0));
  const float tl_y = ((const float)  tolua_tonumber(tolua_S,8,0));
  const float tl_z = ((const float)  tolua_tonumber(tolua_S,9,0));
  const float tr_x = ((const float)  tolua_tonumber(tolua_S,10,0));
  const float tr_y = ((const float)  tolua_tonumber(tolua_S,11,0));
  const float tr_z = ((const float)  tolua_tonumber(tolua_S,12,0));
  {
   wyQuad3D tolua_ret = (wyQuad3D)  wyq3(bl_x,bl_y,bl_z,br_x,br_y,br_z,tl_x,tl_y,tl_z,tr_x,tr_y,tr_z);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((wyQuad3D)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"wyQuad3D");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(wyQuad3D));
     tolua_pushusertype(tolua_S,tolua_obj,"wyQuad3D");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'wyq3'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: wyq3Scale */
#ifndef TOLUA_DISABLE_tolua_types_wyq3Scale00
static int tolua_types_wyq3Scale00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     (tolua_isvaluenil(tolua_S,1,&tolua_err) || !tolua_isusertype(tolua_S,1,"wyQuad3D",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyQuad3D q = *((wyQuad3D*)  tolua_tousertype(tolua_S,1,0));
  float s = ((float)  tolua_tonumber(tolua_S,2,0));
  {
   wyQuad3D tolua_ret = (wyQuad3D)  wyq3Scale(q,s);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((wyQuad3D)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"wyQuad3D");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(wyQuad3D));
     tolua_pushusertype(tolua_S,tolua_obj,"wyQuad3D");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'wyq3Scale'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: wyq3Set */
#ifndef TOLUA_DISABLE_tolua_types_wyq3Set00
static int tolua_types_wyq3Set00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     (tolua_isvaluenil(tolua_S,1,&tolua_err) || !tolua_isusertype(tolua_S,1,"wyQuad3D",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,7,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,8,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,9,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,10,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,11,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,12,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,13,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,14,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyQuad3D* v = ((wyQuad3D*)  tolua_tousertype(tolua_S,1,0));
  const float bl_x = ((const float)  tolua_tonumber(tolua_S,2,0));
  const float bl_y = ((const float)  tolua_tonumber(tolua_S,3,0));
  const float bl_z = ((const float)  tolua_tonumber(tolua_S,4,0));
  const float br_x = ((const float)  tolua_tonumber(tolua_S,5,0));
  const float br_y = ((const float)  tolua_tonumber(tolua_S,6,0));
  const float br_z = ((const float)  tolua_tonumber(tolua_S,7,0));
  const float tl_x = ((const float)  tolua_tonumber(tolua_S,8,0));
  const float tl_y = ((const float)  tolua_tonumber(tolua_S,9,0));
  const float tl_z = ((const float)  tolua_tonumber(tolua_S,10,0));
  const float tr_x = ((const float)  tolua_tonumber(tolua_S,11,0));
  const float tr_y = ((const float)  tolua_tonumber(tolua_S,12,0));
  const float tr_z = ((const float)  tolua_tonumber(tolua_S,13,0));
  {
   wyq3Set(*v,bl_x,bl_y,bl_z,br_x,br_y,br_z,tl_x,tl_y,tl_z,tr_x,tr_y,tr_z);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'wyq3Set'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: wyrZero */
#ifndef TOLUA_DISABLE_tolua_get_wyrZero
static int tolua_get_wyrZero(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&wyrZero,"const wyRect");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* function: wyr */
#ifndef TOLUA_DISABLE_tolua_types_wyr00
static int tolua_types_wyr00(lua_State* tolua_S)
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
  float x = ((float)  tolua_tonumber(tolua_S,1,0));
  float y = ((float)  tolua_tonumber(tolua_S,2,0));
  float w = ((float)  tolua_tonumber(tolua_S,3,0));
  float h = ((float)  tolua_tonumber(tolua_S,4,0));
  {
   wyRect tolua_ret = (wyRect)  wyr(x,y,w,h);
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
 tolua_error(tolua_S,"#ferror in function 'wyr'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: wyrFromString */
#ifndef TOLUA_DISABLE_tolua_types_wyrFromString00
static int tolua_types_wyrFromString00(lua_State* tolua_S)
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
  const char* s = ((const char*)  tolua_tostring(tolua_S,1,0));
  {
   wyRect tolua_ret = (wyRect)  wyrFromString(s);
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
 tolua_error(tolua_S,"#ferror in function 'wyrFromString'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: wyrEquals */
#ifndef TOLUA_DISABLE_tolua_types_wyrEquals00
static int tolua_types_wyrEquals00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     (tolua_isvaluenil(tolua_S,1,&tolua_err) || !tolua_isusertype(tolua_S,1,"wyRect",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"wyRect",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyRect* r1 = ((wyRect*)  tolua_tousertype(tolua_S,1,0));
  wyRect* r2 = ((wyRect*)  tolua_tousertype(tolua_S,2,0));
  {
   bool tolua_ret = (bool)  wyrEquals(*r1,*r2);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'wyrEquals'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: wyrContains */
#ifndef TOLUA_DISABLE_tolua_types_wyrContains00
static int tolua_types_wyrContains00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     (tolua_isvaluenil(tolua_S,1,&tolua_err) || !tolua_isusertype(tolua_S,1,"wyRect",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"wyPoint",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyRect* r1 = ((wyRect*)  tolua_tousertype(tolua_S,1,0));
  wyPoint p = *((wyPoint*)  tolua_tousertype(tolua_S,2,0));
  {
   bool tolua_ret = (bool)  wyrContains(*r1,p);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'wyrContains'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: wyrIsIntersect */
#ifndef TOLUA_DISABLE_tolua_types_wyrIsIntersect00
static int tolua_types_wyrIsIntersect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     (tolua_isvaluenil(tolua_S,1,&tolua_err) || !tolua_isusertype(tolua_S,1,"wyRect",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"wyRect",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyRect* r1 = ((wyRect*)  tolua_tousertype(tolua_S,1,0));
  wyRect* r2 = ((wyRect*)  tolua_tousertype(tolua_S,2,0));
  {
   bool tolua_ret = (bool)  wyrIsIntersect(*r1,*r2);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'wyrIsIntersect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: wysZero */
#ifndef TOLUA_DISABLE_tolua_get_wysZero
static int tolua_get_wysZero(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&wysZero,"const wySize");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* function: wys */
#ifndef TOLUA_DISABLE_tolua_types_wys00
static int tolua_types_wys00(lua_State* tolua_S)
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
  const float w = ((const float)  tolua_tonumber(tolua_S,1,0));
  const float h = ((const float)  tolua_tonumber(tolua_S,2,0));
  {
   wySize tolua_ret = (wySize)  wys(w,h);
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
 tolua_error(tolua_S,"#ferror in function 'wys'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: wysFromString */
#ifndef TOLUA_DISABLE_tolua_types_wysFromString00
static int tolua_types_wysFromString00(lua_State* tolua_S)
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
  const char* s = ((const char*)  tolua_tostring(tolua_S,1,0));
  {
   wySize tolua_ret = (wySize)  wysFromString(s);
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
 tolua_error(tolua_S,"#ferror in function 'wysFromString'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: isEqual */
#ifndef TOLUA_DISABLE_tolua_types_isEqual00
static int tolua_types_isEqual00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     (tolua_isvaluenil(tolua_S,1,&tolua_err) || !tolua_isusertype(tolua_S,1,"wySize",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"wySize",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wySize s1 = *((wySize*)  tolua_tousertype(tolua_S,1,0));
  wySize s2 = *((wySize*)  tolua_tousertype(tolua_S,2,0));
  {
   bool tolua_ret = (bool)  isEqual(s1,s2);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isEqual'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: x of class  wyPoint */
#ifndef TOLUA_DISABLE_tolua_get_wyPoint_x
static int tolua_get_wyPoint_x(lua_State* tolua_S)
{
  wyPoint* self = (wyPoint*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'x'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->x);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: x of class  wyPoint */
#ifndef TOLUA_DISABLE_tolua_set_wyPoint_x
static int tolua_set_wyPoint_x(lua_State* tolua_S)
{
  wyPoint* self = (wyPoint*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'x'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->x = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: y of class  wyPoint */
#ifndef TOLUA_DISABLE_tolua_get_wyPoint_y
static int tolua_get_wyPoint_y(lua_State* tolua_S)
{
  wyPoint* self = (wyPoint*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'y'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->y);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: y of class  wyPoint */
#ifndef TOLUA_DISABLE_tolua_set_wyPoint_y
static int tolua_set_wyPoint_y(lua_State* tolua_S)
{
  wyPoint* self = (wyPoint*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'y'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->y = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: x of class  wyDimension */
#ifndef TOLUA_DISABLE_tolua_get_wyDimension_x
static int tolua_get_wyDimension_x(lua_State* tolua_S)
{
  wyDimension* self = (wyDimension*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'x'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->x);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: x of class  wyDimension */
#ifndef TOLUA_DISABLE_tolua_set_wyDimension_x
static int tolua_set_wyDimension_x(lua_State* tolua_S)
{
  wyDimension* self = (wyDimension*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'x'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->x = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: y of class  wyDimension */
#ifndef TOLUA_DISABLE_tolua_get_wyDimension_y
static int tolua_get_wyDimension_y(lua_State* tolua_S)
{
  wyDimension* self = (wyDimension*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'y'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->y);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: y of class  wyDimension */
#ifndef TOLUA_DISABLE_tolua_set_wyDimension_y
static int tolua_set_wyDimension_y(lua_State* tolua_S)
{
  wyDimension* self = (wyDimension*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'y'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->y = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: width of class  wySize */
#ifndef TOLUA_DISABLE_tolua_get_wySize_width
static int tolua_get_wySize_width(lua_State* tolua_S)
{
  wySize* self = (wySize*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'width'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->width);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: width of class  wySize */
#ifndef TOLUA_DISABLE_tolua_set_wySize_width
static int tolua_set_wySize_width(lua_State* tolua_S)
{
  wySize* self = (wySize*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'width'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->width = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: height of class  wySize */
#ifndef TOLUA_DISABLE_tolua_get_wySize_height
static int tolua_get_wySize_height(lua_State* tolua_S)
{
  wySize* self = (wySize*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'height'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->height);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: height of class  wySize */
#ifndef TOLUA_DISABLE_tolua_set_wySize_height
static int tolua_set_wySize_height(lua_State* tolua_S)
{
  wySize* self = (wySize*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'height'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->height = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: x of class  wyRect */
#ifndef TOLUA_DISABLE_tolua_get_wyRect_x
static int tolua_get_wyRect_x(lua_State* tolua_S)
{
  wyRect* self = (wyRect*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'x'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->x);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: x of class  wyRect */
#ifndef TOLUA_DISABLE_tolua_set_wyRect_x
static int tolua_set_wyRect_x(lua_State* tolua_S)
{
  wyRect* self = (wyRect*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'x'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->x = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: y of class  wyRect */
#ifndef TOLUA_DISABLE_tolua_get_wyRect_y
static int tolua_get_wyRect_y(lua_State* tolua_S)
{
  wyRect* self = (wyRect*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'y'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->y);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: y of class  wyRect */
#ifndef TOLUA_DISABLE_tolua_set_wyRect_y
static int tolua_set_wyRect_y(lua_State* tolua_S)
{
  wyRect* self = (wyRect*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'y'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->y = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: width of class  wyRect */
#ifndef TOLUA_DISABLE_tolua_get_wyRect_width
static int tolua_get_wyRect_width(lua_State* tolua_S)
{
  wyRect* self = (wyRect*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'width'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->width);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: width of class  wyRect */
#ifndef TOLUA_DISABLE_tolua_set_wyRect_width
static int tolua_set_wyRect_width(lua_State* tolua_S)
{
  wyRect* self = (wyRect*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'width'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->width = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: height of class  wyRect */
#ifndef TOLUA_DISABLE_tolua_get_wyRect_height
static int tolua_get_wyRect_height(lua_State* tolua_S)
{
  wyRect* self = (wyRect*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'height'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->height);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: height of class  wyRect */
#ifndef TOLUA_DISABLE_tolua_set_wyRect_height
static int tolua_set_wyRect_height(lua_State* tolua_S)
{
  wyRect* self = (wyRect*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'height'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->height = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: x of class  wyVertex3D */
#ifndef TOLUA_DISABLE_tolua_get_wyVertex3D_x
static int tolua_get_wyVertex3D_x(lua_State* tolua_S)
{
  wyVertex3D* self = (wyVertex3D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'x'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->x);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: x of class  wyVertex3D */
#ifndef TOLUA_DISABLE_tolua_set_wyVertex3D_x
static int tolua_set_wyVertex3D_x(lua_State* tolua_S)
{
  wyVertex3D* self = (wyVertex3D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'x'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->x = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: y of class  wyVertex3D */
#ifndef TOLUA_DISABLE_tolua_get_wyVertex3D_y
static int tolua_get_wyVertex3D_y(lua_State* tolua_S)
{
  wyVertex3D* self = (wyVertex3D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'y'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->y);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: y of class  wyVertex3D */
#ifndef TOLUA_DISABLE_tolua_set_wyVertex3D_y
static int tolua_set_wyVertex3D_y(lua_State* tolua_S)
{
  wyVertex3D* self = (wyVertex3D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'y'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->y = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: z of class  wyVertex3D */
#ifndef TOLUA_DISABLE_tolua_get_wyVertex3D_z
static int tolua_get_wyVertex3D_z(lua_State* tolua_S)
{
  wyVertex3D* self = (wyVertex3D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'z'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->z);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: z of class  wyVertex3D */
#ifndef TOLUA_DISABLE_tolua_set_wyVertex3D_z
static int tolua_set_wyVertex3D_z(lua_State* tolua_S)
{
  wyVertex3D* self = (wyVertex3D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'z'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->z = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: bl_x of class  wyQuad3D */
#ifndef TOLUA_DISABLE_tolua_get_wyQuad3D_bl_x
static int tolua_get_wyQuad3D_bl_x(lua_State* tolua_S)
{
  wyQuad3D* self = (wyQuad3D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'bl_x'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->bl_x);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: bl_x of class  wyQuad3D */
#ifndef TOLUA_DISABLE_tolua_set_wyQuad3D_bl_x
static int tolua_set_wyQuad3D_bl_x(lua_State* tolua_S)
{
  wyQuad3D* self = (wyQuad3D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'bl_x'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->bl_x = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: bl_y of class  wyQuad3D */
#ifndef TOLUA_DISABLE_tolua_get_wyQuad3D_bl_y
static int tolua_get_wyQuad3D_bl_y(lua_State* tolua_S)
{
  wyQuad3D* self = (wyQuad3D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'bl_y'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->bl_y);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: bl_y of class  wyQuad3D */
#ifndef TOLUA_DISABLE_tolua_set_wyQuad3D_bl_y
static int tolua_set_wyQuad3D_bl_y(lua_State* tolua_S)
{
  wyQuad3D* self = (wyQuad3D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'bl_y'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->bl_y = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: bl_z of class  wyQuad3D */
#ifndef TOLUA_DISABLE_tolua_get_wyQuad3D_bl_z
static int tolua_get_wyQuad3D_bl_z(lua_State* tolua_S)
{
  wyQuad3D* self = (wyQuad3D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'bl_z'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->bl_z);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: bl_z of class  wyQuad3D */
#ifndef TOLUA_DISABLE_tolua_set_wyQuad3D_bl_z
static int tolua_set_wyQuad3D_bl_z(lua_State* tolua_S)
{
  wyQuad3D* self = (wyQuad3D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'bl_z'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->bl_z = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: br_x of class  wyQuad3D */
#ifndef TOLUA_DISABLE_tolua_get_wyQuad3D_br_x
static int tolua_get_wyQuad3D_br_x(lua_State* tolua_S)
{
  wyQuad3D* self = (wyQuad3D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'br_x'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->br_x);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: br_x of class  wyQuad3D */
#ifndef TOLUA_DISABLE_tolua_set_wyQuad3D_br_x
static int tolua_set_wyQuad3D_br_x(lua_State* tolua_S)
{
  wyQuad3D* self = (wyQuad3D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'br_x'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->br_x = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: br_y of class  wyQuad3D */
#ifndef TOLUA_DISABLE_tolua_get_wyQuad3D_br_y
static int tolua_get_wyQuad3D_br_y(lua_State* tolua_S)
{
  wyQuad3D* self = (wyQuad3D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'br_y'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->br_y);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: br_y of class  wyQuad3D */
#ifndef TOLUA_DISABLE_tolua_set_wyQuad3D_br_y
static int tolua_set_wyQuad3D_br_y(lua_State* tolua_S)
{
  wyQuad3D* self = (wyQuad3D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'br_y'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->br_y = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: br_z of class  wyQuad3D */
#ifndef TOLUA_DISABLE_tolua_get_wyQuad3D_br_z
static int tolua_get_wyQuad3D_br_z(lua_State* tolua_S)
{
  wyQuad3D* self = (wyQuad3D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'br_z'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->br_z);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: br_z of class  wyQuad3D */
#ifndef TOLUA_DISABLE_tolua_set_wyQuad3D_br_z
static int tolua_set_wyQuad3D_br_z(lua_State* tolua_S)
{
  wyQuad3D* self = (wyQuad3D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'br_z'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->br_z = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: tl_x of class  wyQuad3D */
#ifndef TOLUA_DISABLE_tolua_get_wyQuad3D_tl_x
static int tolua_get_wyQuad3D_tl_x(lua_State* tolua_S)
{
  wyQuad3D* self = (wyQuad3D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'tl_x'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->tl_x);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: tl_x of class  wyQuad3D */
#ifndef TOLUA_DISABLE_tolua_set_wyQuad3D_tl_x
static int tolua_set_wyQuad3D_tl_x(lua_State* tolua_S)
{
  wyQuad3D* self = (wyQuad3D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'tl_x'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->tl_x = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: tl_y of class  wyQuad3D */
#ifndef TOLUA_DISABLE_tolua_get_wyQuad3D_tl_y
static int tolua_get_wyQuad3D_tl_y(lua_State* tolua_S)
{
  wyQuad3D* self = (wyQuad3D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'tl_y'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->tl_y);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: tl_y of class  wyQuad3D */
#ifndef TOLUA_DISABLE_tolua_set_wyQuad3D_tl_y
static int tolua_set_wyQuad3D_tl_y(lua_State* tolua_S)
{
  wyQuad3D* self = (wyQuad3D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'tl_y'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->tl_y = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: tl_z of class  wyQuad3D */
#ifndef TOLUA_DISABLE_tolua_get_wyQuad3D_tl_z
static int tolua_get_wyQuad3D_tl_z(lua_State* tolua_S)
{
  wyQuad3D* self = (wyQuad3D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'tl_z'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->tl_z);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: tl_z of class  wyQuad3D */
#ifndef TOLUA_DISABLE_tolua_set_wyQuad3D_tl_z
static int tolua_set_wyQuad3D_tl_z(lua_State* tolua_S)
{
  wyQuad3D* self = (wyQuad3D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'tl_z'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->tl_z = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: tr_x of class  wyQuad3D */
#ifndef TOLUA_DISABLE_tolua_get_wyQuad3D_tr_x
static int tolua_get_wyQuad3D_tr_x(lua_State* tolua_S)
{
  wyQuad3D* self = (wyQuad3D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'tr_x'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->tr_x);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: tr_x of class  wyQuad3D */
#ifndef TOLUA_DISABLE_tolua_set_wyQuad3D_tr_x
static int tolua_set_wyQuad3D_tr_x(lua_State* tolua_S)
{
  wyQuad3D* self = (wyQuad3D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'tr_x'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->tr_x = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: tr_y of class  wyQuad3D */
#ifndef TOLUA_DISABLE_tolua_get_wyQuad3D_tr_y
static int tolua_get_wyQuad3D_tr_y(lua_State* tolua_S)
{
  wyQuad3D* self = (wyQuad3D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'tr_y'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->tr_y);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: tr_y of class  wyQuad3D */
#ifndef TOLUA_DISABLE_tolua_set_wyQuad3D_tr_y
static int tolua_set_wyQuad3D_tr_y(lua_State* tolua_S)
{
  wyQuad3D* self = (wyQuad3D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'tr_y'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->tr_y = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: tr_z of class  wyQuad3D */
#ifndef TOLUA_DISABLE_tolua_get_wyQuad3D_tr_z
static int tolua_get_wyQuad3D_tr_z(lua_State* tolua_S)
{
  wyQuad3D* self = (wyQuad3D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'tr_z'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->tr_z);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: tr_z of class  wyQuad3D */
#ifndef TOLUA_DISABLE_tolua_set_wyQuad3D_tr_z
static int tolua_set_wyQuad3D_tr_z(lua_State* tolua_S)
{
  wyQuad3D* self = (wyQuad3D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'tr_z'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->tr_z = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: bl_x of class  wyQuad2D */
#ifndef TOLUA_DISABLE_tolua_get_wyQuad2D_bl_x
static int tolua_get_wyQuad2D_bl_x(lua_State* tolua_S)
{
  wyQuad2D* self = (wyQuad2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'bl_x'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->bl_x);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: bl_x of class  wyQuad2D */
#ifndef TOLUA_DISABLE_tolua_set_wyQuad2D_bl_x
static int tolua_set_wyQuad2D_bl_x(lua_State* tolua_S)
{
  wyQuad2D* self = (wyQuad2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'bl_x'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->bl_x = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: bl_y of class  wyQuad2D */
#ifndef TOLUA_DISABLE_tolua_get_wyQuad2D_bl_y
static int tolua_get_wyQuad2D_bl_y(lua_State* tolua_S)
{
  wyQuad2D* self = (wyQuad2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'bl_y'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->bl_y);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: bl_y of class  wyQuad2D */
#ifndef TOLUA_DISABLE_tolua_set_wyQuad2D_bl_y
static int tolua_set_wyQuad2D_bl_y(lua_State* tolua_S)
{
  wyQuad2D* self = (wyQuad2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'bl_y'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->bl_y = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: br_x of class  wyQuad2D */
#ifndef TOLUA_DISABLE_tolua_get_wyQuad2D_br_x
static int tolua_get_wyQuad2D_br_x(lua_State* tolua_S)
{
  wyQuad2D* self = (wyQuad2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'br_x'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->br_x);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: br_x of class  wyQuad2D */
#ifndef TOLUA_DISABLE_tolua_set_wyQuad2D_br_x
static int tolua_set_wyQuad2D_br_x(lua_State* tolua_S)
{
  wyQuad2D* self = (wyQuad2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'br_x'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->br_x = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: br_y of class  wyQuad2D */
#ifndef TOLUA_DISABLE_tolua_get_wyQuad2D_br_y
static int tolua_get_wyQuad2D_br_y(lua_State* tolua_S)
{
  wyQuad2D* self = (wyQuad2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'br_y'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->br_y);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: br_y of class  wyQuad2D */
#ifndef TOLUA_DISABLE_tolua_set_wyQuad2D_br_y
static int tolua_set_wyQuad2D_br_y(lua_State* tolua_S)
{
  wyQuad2D* self = (wyQuad2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'br_y'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->br_y = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: tl_x of class  wyQuad2D */
#ifndef TOLUA_DISABLE_tolua_get_wyQuad2D_tl_x
static int tolua_get_wyQuad2D_tl_x(lua_State* tolua_S)
{
  wyQuad2D* self = (wyQuad2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'tl_x'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->tl_x);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: tl_x of class  wyQuad2D */
#ifndef TOLUA_DISABLE_tolua_set_wyQuad2D_tl_x
static int tolua_set_wyQuad2D_tl_x(lua_State* tolua_S)
{
  wyQuad2D* self = (wyQuad2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'tl_x'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->tl_x = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: tl_y of class  wyQuad2D */
#ifndef TOLUA_DISABLE_tolua_get_wyQuad2D_tl_y
static int tolua_get_wyQuad2D_tl_y(lua_State* tolua_S)
{
  wyQuad2D* self = (wyQuad2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'tl_y'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->tl_y);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: tl_y of class  wyQuad2D */
#ifndef TOLUA_DISABLE_tolua_set_wyQuad2D_tl_y
static int tolua_set_wyQuad2D_tl_y(lua_State* tolua_S)
{
  wyQuad2D* self = (wyQuad2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'tl_y'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->tl_y = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: tr_x of class  wyQuad2D */
#ifndef TOLUA_DISABLE_tolua_get_wyQuad2D_tr_x
static int tolua_get_wyQuad2D_tr_x(lua_State* tolua_S)
{
  wyQuad2D* self = (wyQuad2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'tr_x'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->tr_x);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: tr_x of class  wyQuad2D */
#ifndef TOLUA_DISABLE_tolua_set_wyQuad2D_tr_x
static int tolua_set_wyQuad2D_tr_x(lua_State* tolua_S)
{
  wyQuad2D* self = (wyQuad2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'tr_x'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->tr_x = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: tr_y of class  wyQuad2D */
#ifndef TOLUA_DISABLE_tolua_get_wyQuad2D_tr_y
static int tolua_get_wyQuad2D_tr_y(lua_State* tolua_S)
{
  wyQuad2D* self = (wyQuad2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'tr_y'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->tr_y);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: tr_y of class  wyQuad2D */
#ifndef TOLUA_DISABLE_tolua_set_wyQuad2D_tr_y
static int tolua_set_wyQuad2D_tr_y(lua_State* tolua_S)
{
  wyQuad2D* self = (wyQuad2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'tr_y'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->tr_y = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: a of class  wyAffineTransform */
#ifndef TOLUA_DISABLE_tolua_get_wyAffineTransform_a
static int tolua_get_wyAffineTransform_a(lua_State* tolua_S)
{
  wyAffineTransform* self = (wyAffineTransform*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'a'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->a);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: a of class  wyAffineTransform */
#ifndef TOLUA_DISABLE_tolua_set_wyAffineTransform_a
static int tolua_set_wyAffineTransform_a(lua_State* tolua_S)
{
  wyAffineTransform* self = (wyAffineTransform*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'a'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->a = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: b of class  wyAffineTransform */
#ifndef TOLUA_DISABLE_tolua_get_wyAffineTransform_b
static int tolua_get_wyAffineTransform_b(lua_State* tolua_S)
{
  wyAffineTransform* self = (wyAffineTransform*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'b'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->b);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: b of class  wyAffineTransform */
#ifndef TOLUA_DISABLE_tolua_set_wyAffineTransform_b
static int tolua_set_wyAffineTransform_b(lua_State* tolua_S)
{
  wyAffineTransform* self = (wyAffineTransform*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'b'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->b = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: c of class  wyAffineTransform */
#ifndef TOLUA_DISABLE_tolua_get_wyAffineTransform_c
static int tolua_get_wyAffineTransform_c(lua_State* tolua_S)
{
  wyAffineTransform* self = (wyAffineTransform*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'c'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->c);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: c of class  wyAffineTransform */
#ifndef TOLUA_DISABLE_tolua_set_wyAffineTransform_c
static int tolua_set_wyAffineTransform_c(lua_State* tolua_S)
{
  wyAffineTransform* self = (wyAffineTransform*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'c'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->c = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: d of class  wyAffineTransform */
#ifndef TOLUA_DISABLE_tolua_get_wyAffineTransform_d
static int tolua_get_wyAffineTransform_d(lua_State* tolua_S)
{
  wyAffineTransform* self = (wyAffineTransform*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'd'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->d);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: d of class  wyAffineTransform */
#ifndef TOLUA_DISABLE_tolua_set_wyAffineTransform_d
static int tolua_set_wyAffineTransform_d(lua_State* tolua_S)
{
  wyAffineTransform* self = (wyAffineTransform*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'd'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->d = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: tx of class  wyAffineTransform */
#ifndef TOLUA_DISABLE_tolua_get_wyAffineTransform_tx
static int tolua_get_wyAffineTransform_tx(lua_State* tolua_S)
{
  wyAffineTransform* self = (wyAffineTransform*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'tx'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->tx);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: tx of class  wyAffineTransform */
#ifndef TOLUA_DISABLE_tolua_set_wyAffineTransform_tx
static int tolua_set_wyAffineTransform_tx(lua_State* tolua_S)
{
  wyAffineTransform* self = (wyAffineTransform*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'tx'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->tx = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: ty of class  wyAffineTransform */
#ifndef TOLUA_DISABLE_tolua_get_wyAffineTransform_ty
static int tolua_get_wyAffineTransform_ty(lua_State* tolua_S)
{
  wyAffineTransform* self = (wyAffineTransform*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'ty'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->ty);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: ty of class  wyAffineTransform */
#ifndef TOLUA_DISABLE_tolua_set_wyAffineTransform_ty
static int tolua_set_wyAffineTransform_ty(lua_State* tolua_S)
{
  wyAffineTransform* self = (wyAffineTransform*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'ty'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->ty = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: src of class  wyBlendFunc */
#ifndef TOLUA_DISABLE_tolua_get_wyBlendFunc_src
static int tolua_get_wyBlendFunc_src(lua_State* tolua_S)
{
  wyBlendFunc* self = (wyBlendFunc*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'src'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->src);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: src of class  wyBlendFunc */
#ifndef TOLUA_DISABLE_tolua_set_wyBlendFunc_src
static int tolua_set_wyBlendFunc_src(lua_State* tolua_S)
{
  wyBlendFunc* self = (wyBlendFunc*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'src'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->src = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: dst of class  wyBlendFunc */
#ifndef TOLUA_DISABLE_tolua_get_wyBlendFunc_dst
static int tolua_get_wyBlendFunc_dst(lua_State* tolua_S)
{
  wyBlendFunc* self = (wyBlendFunc*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'dst'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->dst);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: dst of class  wyBlendFunc */
#ifndef TOLUA_DISABLE_tolua_set_wyBlendFunc_dst
static int tolua_set_wyBlendFunc_dst(lua_State* tolua_S)
{
  wyBlendFunc* self = (wyBlendFunc*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'dst'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->dst = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: r of class  wyColor3B */
#ifndef TOLUA_DISABLE_tolua_get_wyColor3B_unsigned_r
static int tolua_get_wyColor3B_unsigned_r(lua_State* tolua_S)
{
  wyColor3B* self = (wyColor3B*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'r'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->r);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: r of class  wyColor3B */
#ifndef TOLUA_DISABLE_tolua_set_wyColor3B_unsigned_r
static int tolua_set_wyColor3B_unsigned_r(lua_State* tolua_S)
{
  wyColor3B* self = (wyColor3B*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'r'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->r = ((unsigned char)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: g of class  wyColor3B */
#ifndef TOLUA_DISABLE_tolua_get_wyColor3B_unsigned_g
static int tolua_get_wyColor3B_unsigned_g(lua_State* tolua_S)
{
  wyColor3B* self = (wyColor3B*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'g'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->g);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: g of class  wyColor3B */
#ifndef TOLUA_DISABLE_tolua_set_wyColor3B_unsigned_g
static int tolua_set_wyColor3B_unsigned_g(lua_State* tolua_S)
{
  wyColor3B* self = (wyColor3B*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'g'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->g = ((unsigned char)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: b of class  wyColor3B */
#ifndef TOLUA_DISABLE_tolua_get_wyColor3B_unsigned_b
static int tolua_get_wyColor3B_unsigned_b(lua_State* tolua_S)
{
  wyColor3B* self = (wyColor3B*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'b'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->b);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: b of class  wyColor3B */
#ifndef TOLUA_DISABLE_tolua_set_wyColor3B_unsigned_b
static int tolua_set_wyColor3B_unsigned_b(lua_State* tolua_S)
{
  wyColor3B* self = (wyColor3B*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'b'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->b = ((unsigned char)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: r of class  wyColor4B */
#ifndef TOLUA_DISABLE_tolua_get_wyColor4B_unsigned_r
static int tolua_get_wyColor4B_unsigned_r(lua_State* tolua_S)
{
  wyColor4B* self = (wyColor4B*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'r'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->r);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: r of class  wyColor4B */
#ifndef TOLUA_DISABLE_tolua_set_wyColor4B_unsigned_r
static int tolua_set_wyColor4B_unsigned_r(lua_State* tolua_S)
{
  wyColor4B* self = (wyColor4B*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'r'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->r = ((unsigned char)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: g of class  wyColor4B */
#ifndef TOLUA_DISABLE_tolua_get_wyColor4B_unsigned_g
static int tolua_get_wyColor4B_unsigned_g(lua_State* tolua_S)
{
  wyColor4B* self = (wyColor4B*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'g'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->g);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: g of class  wyColor4B */
#ifndef TOLUA_DISABLE_tolua_set_wyColor4B_unsigned_g
static int tolua_set_wyColor4B_unsigned_g(lua_State* tolua_S)
{
  wyColor4B* self = (wyColor4B*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'g'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->g = ((unsigned char)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: b of class  wyColor4B */
#ifndef TOLUA_DISABLE_tolua_get_wyColor4B_unsigned_b
static int tolua_get_wyColor4B_unsigned_b(lua_State* tolua_S)
{
  wyColor4B* self = (wyColor4B*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'b'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->b);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: b of class  wyColor4B */
#ifndef TOLUA_DISABLE_tolua_set_wyColor4B_unsigned_b
static int tolua_set_wyColor4B_unsigned_b(lua_State* tolua_S)
{
  wyColor4B* self = (wyColor4B*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'b'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->b = ((unsigned char)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: a of class  wyColor4B */
#ifndef TOLUA_DISABLE_tolua_get_wyColor4B_unsigned_a
static int tolua_get_wyColor4B_unsigned_a(lua_State* tolua_S)
{
  wyColor4B* self = (wyColor4B*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'a'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->a);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: a of class  wyColor4B */
#ifndef TOLUA_DISABLE_tolua_set_wyColor4B_unsigned_a
static int tolua_set_wyColor4B_unsigned_a(lua_State* tolua_S)
{
  wyColor4B* self = (wyColor4B*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'a'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->a = ((unsigned char)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: r of class  wyColor4F */
#ifndef TOLUA_DISABLE_tolua_get_wyColor4F_r
static int tolua_get_wyColor4F_r(lua_State* tolua_S)
{
  wyColor4F* self = (wyColor4F*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'r'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->r);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: r of class  wyColor4F */
#ifndef TOLUA_DISABLE_tolua_set_wyColor4F_r
static int tolua_set_wyColor4F_r(lua_State* tolua_S)
{
  wyColor4F* self = (wyColor4F*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'r'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->r = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: g of class  wyColor4F */
#ifndef TOLUA_DISABLE_tolua_get_wyColor4F_g
static int tolua_get_wyColor4F_g(lua_State* tolua_S)
{
  wyColor4F* self = (wyColor4F*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'g'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->g);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: g of class  wyColor4F */
#ifndef TOLUA_DISABLE_tolua_set_wyColor4F_g
static int tolua_set_wyColor4F_g(lua_State* tolua_S)
{
  wyColor4F* self = (wyColor4F*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'g'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->g = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: b of class  wyColor4F */
#ifndef TOLUA_DISABLE_tolua_get_wyColor4F_b
static int tolua_get_wyColor4F_b(lua_State* tolua_S)
{
  wyColor4F* self = (wyColor4F*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'b'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->b);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: b of class  wyColor4F */
#ifndef TOLUA_DISABLE_tolua_set_wyColor4F_b
static int tolua_set_wyColor4F_b(lua_State* tolua_S)
{
  wyColor4F* self = (wyColor4F*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'b'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->b = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: a of class  wyColor4F */
#ifndef TOLUA_DISABLE_tolua_get_wyColor4F_a
static int tolua_get_wyColor4F_a(lua_State* tolua_S)
{
  wyColor4F* self = (wyColor4F*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'a'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->a);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: a of class  wyColor4F */
#ifndef TOLUA_DISABLE_tolua_set_wyColor4F_a
static int tolua_set_wyColor4F_a(lua_State* tolua_S)
{
  wyColor4F* self = (wyColor4F*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'a'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->a = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: startX of class  wyBezierConfig */
#ifndef TOLUA_DISABLE_tolua_get_wyBezierConfig_startX
static int tolua_get_wyBezierConfig_startX(lua_State* tolua_S)
{
  wyBezierConfig* self = (wyBezierConfig*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'startX'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->startX);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: startX of class  wyBezierConfig */
#ifndef TOLUA_DISABLE_tolua_set_wyBezierConfig_startX
static int tolua_set_wyBezierConfig_startX(lua_State* tolua_S)
{
  wyBezierConfig* self = (wyBezierConfig*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'startX'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->startX = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: startY of class  wyBezierConfig */
#ifndef TOLUA_DISABLE_tolua_get_wyBezierConfig_startY
static int tolua_get_wyBezierConfig_startY(lua_State* tolua_S)
{
  wyBezierConfig* self = (wyBezierConfig*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'startY'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->startY);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: startY of class  wyBezierConfig */
#ifndef TOLUA_DISABLE_tolua_set_wyBezierConfig_startY
static int tolua_set_wyBezierConfig_startY(lua_State* tolua_S)
{
  wyBezierConfig* self = (wyBezierConfig*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'startY'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->startY = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: endX of class  wyBezierConfig */
#ifndef TOLUA_DISABLE_tolua_get_wyBezierConfig_endX
static int tolua_get_wyBezierConfig_endX(lua_State* tolua_S)
{
  wyBezierConfig* self = (wyBezierConfig*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'endX'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->endX);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: endX of class  wyBezierConfig */
#ifndef TOLUA_DISABLE_tolua_set_wyBezierConfig_endX
static int tolua_set_wyBezierConfig_endX(lua_State* tolua_S)
{
  wyBezierConfig* self = (wyBezierConfig*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'endX'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->endX = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: endY of class  wyBezierConfig */
#ifndef TOLUA_DISABLE_tolua_get_wyBezierConfig_endY
static int tolua_get_wyBezierConfig_endY(lua_State* tolua_S)
{
  wyBezierConfig* self = (wyBezierConfig*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'endY'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->endY);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: endY of class  wyBezierConfig */
#ifndef TOLUA_DISABLE_tolua_set_wyBezierConfig_endY
static int tolua_set_wyBezierConfig_endY(lua_State* tolua_S)
{
  wyBezierConfig* self = (wyBezierConfig*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'endY'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->endY = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: cp1X of class  wyBezierConfig */
#ifndef TOLUA_DISABLE_tolua_get_wyBezierConfig_cp1X
static int tolua_get_wyBezierConfig_cp1X(lua_State* tolua_S)
{
  wyBezierConfig* self = (wyBezierConfig*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'cp1X'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->cp1X);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: cp1X of class  wyBezierConfig */
#ifndef TOLUA_DISABLE_tolua_set_wyBezierConfig_cp1X
static int tolua_set_wyBezierConfig_cp1X(lua_State* tolua_S)
{
  wyBezierConfig* self = (wyBezierConfig*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'cp1X'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->cp1X = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: cp1Y of class  wyBezierConfig */
#ifndef TOLUA_DISABLE_tolua_get_wyBezierConfig_cp1Y
static int tolua_get_wyBezierConfig_cp1Y(lua_State* tolua_S)
{
  wyBezierConfig* self = (wyBezierConfig*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'cp1Y'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->cp1Y);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: cp1Y of class  wyBezierConfig */
#ifndef TOLUA_DISABLE_tolua_set_wyBezierConfig_cp1Y
static int tolua_set_wyBezierConfig_cp1Y(lua_State* tolua_S)
{
  wyBezierConfig* self = (wyBezierConfig*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'cp1Y'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->cp1Y = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: cp2X of class  wyBezierConfig */
#ifndef TOLUA_DISABLE_tolua_get_wyBezierConfig_cp2X
static int tolua_get_wyBezierConfig_cp2X(lua_State* tolua_S)
{
  wyBezierConfig* self = (wyBezierConfig*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'cp2X'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->cp2X);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: cp2X of class  wyBezierConfig */
#ifndef TOLUA_DISABLE_tolua_set_wyBezierConfig_cp2X
static int tolua_set_wyBezierConfig_cp2X(lua_State* tolua_S)
{
  wyBezierConfig* self = (wyBezierConfig*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'cp2X'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->cp2X = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: cp2Y of class  wyBezierConfig */
#ifndef TOLUA_DISABLE_tolua_get_wyBezierConfig_cp2Y
static int tolua_get_wyBezierConfig_cp2Y(lua_State* tolua_S)
{
  wyBezierConfig* self = (wyBezierConfig*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'cp2Y'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->cp2Y);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: cp2Y of class  wyBezierConfig */
#ifndef TOLUA_DISABLE_tolua_set_wyBezierConfig_cp2Y
static int tolua_set_wyBezierConfig_cp2Y(lua_State* tolua_S)
{
  wyBezierConfig* self = (wyBezierConfig*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'cp2Y'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->cp2Y = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: cubic of class  wyLagrangeConfig */
#ifndef TOLUA_DISABLE_tolua_get_wyLagrangeConfig_cubic
static int tolua_get_wyLagrangeConfig_cubic(lua_State* tolua_S)
{
  wyLagrangeConfig* self = (wyLagrangeConfig*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'cubic'",NULL);
#endif
  tolua_pushboolean(tolua_S,(bool)self->cubic);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: cubic of class  wyLagrangeConfig */
#ifndef TOLUA_DISABLE_tolua_set_wyLagrangeConfig_cubic
static int tolua_set_wyLagrangeConfig_cubic(lua_State* tolua_S)
{
  wyLagrangeConfig* self = (wyLagrangeConfig*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'cubic'",NULL);
  if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->cubic = ((bool)  tolua_toboolean(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: startX of class  wyLagrangeConfig */
#ifndef TOLUA_DISABLE_tolua_get_wyLagrangeConfig_startX
static int tolua_get_wyLagrangeConfig_startX(lua_State* tolua_S)
{
  wyLagrangeConfig* self = (wyLagrangeConfig*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'startX'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->startX);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: startX of class  wyLagrangeConfig */
#ifndef TOLUA_DISABLE_tolua_set_wyLagrangeConfig_startX
static int tolua_set_wyLagrangeConfig_startX(lua_State* tolua_S)
{
  wyLagrangeConfig* self = (wyLagrangeConfig*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'startX'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->startX = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: startY of class  wyLagrangeConfig */
#ifndef TOLUA_DISABLE_tolua_get_wyLagrangeConfig_startY
static int tolua_get_wyLagrangeConfig_startY(lua_State* tolua_S)
{
  wyLagrangeConfig* self = (wyLagrangeConfig*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'startY'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->startY);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: startY of class  wyLagrangeConfig */
#ifndef TOLUA_DISABLE_tolua_set_wyLagrangeConfig_startY
static int tolua_set_wyLagrangeConfig_startY(lua_State* tolua_S)
{
  wyLagrangeConfig* self = (wyLagrangeConfig*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'startY'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->startY = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: endX of class  wyLagrangeConfig */
#ifndef TOLUA_DISABLE_tolua_get_wyLagrangeConfig_endX
static int tolua_get_wyLagrangeConfig_endX(lua_State* tolua_S)
{
  wyLagrangeConfig* self = (wyLagrangeConfig*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'endX'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->endX);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: endX of class  wyLagrangeConfig */
#ifndef TOLUA_DISABLE_tolua_set_wyLagrangeConfig_endX
static int tolua_set_wyLagrangeConfig_endX(lua_State* tolua_S)
{
  wyLagrangeConfig* self = (wyLagrangeConfig*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'endX'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->endX = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: endY of class  wyLagrangeConfig */
#ifndef TOLUA_DISABLE_tolua_get_wyLagrangeConfig_endY
static int tolua_get_wyLagrangeConfig_endY(lua_State* tolua_S)
{
  wyLagrangeConfig* self = (wyLagrangeConfig*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'endY'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->endY);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: endY of class  wyLagrangeConfig */
#ifndef TOLUA_DISABLE_tolua_set_wyLagrangeConfig_endY
static int tolua_set_wyLagrangeConfig_endY(lua_State* tolua_S)
{
  wyLagrangeConfig* self = (wyLagrangeConfig*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'endY'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->endY = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: cp1X of class  wyLagrangeConfig */
#ifndef TOLUA_DISABLE_tolua_get_wyLagrangeConfig_cp1X
static int tolua_get_wyLagrangeConfig_cp1X(lua_State* tolua_S)
{
  wyLagrangeConfig* self = (wyLagrangeConfig*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'cp1X'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->cp1X);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: cp1X of class  wyLagrangeConfig */
#ifndef TOLUA_DISABLE_tolua_set_wyLagrangeConfig_cp1X
static int tolua_set_wyLagrangeConfig_cp1X(lua_State* tolua_S)
{
  wyLagrangeConfig* self = (wyLagrangeConfig*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'cp1X'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->cp1X = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: cp1Y of class  wyLagrangeConfig */
#ifndef TOLUA_DISABLE_tolua_get_wyLagrangeConfig_cp1Y
static int tolua_get_wyLagrangeConfig_cp1Y(lua_State* tolua_S)
{
  wyLagrangeConfig* self = (wyLagrangeConfig*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'cp1Y'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->cp1Y);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: cp1Y of class  wyLagrangeConfig */
#ifndef TOLUA_DISABLE_tolua_set_wyLagrangeConfig_cp1Y
static int tolua_set_wyLagrangeConfig_cp1Y(lua_State* tolua_S)
{
  wyLagrangeConfig* self = (wyLagrangeConfig*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'cp1Y'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->cp1Y = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: cp2X of class  wyLagrangeConfig */
#ifndef TOLUA_DISABLE_tolua_get_wyLagrangeConfig_cp2X
static int tolua_get_wyLagrangeConfig_cp2X(lua_State* tolua_S)
{
  wyLagrangeConfig* self = (wyLagrangeConfig*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'cp2X'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->cp2X);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: cp2X of class  wyLagrangeConfig */
#ifndef TOLUA_DISABLE_tolua_set_wyLagrangeConfig_cp2X
static int tolua_set_wyLagrangeConfig_cp2X(lua_State* tolua_S)
{
  wyLagrangeConfig* self = (wyLagrangeConfig*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'cp2X'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->cp2X = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: cp2Y of class  wyLagrangeConfig */
#ifndef TOLUA_DISABLE_tolua_get_wyLagrangeConfig_cp2Y
static int tolua_get_wyLagrangeConfig_cp2Y(lua_State* tolua_S)
{
  wyLagrangeConfig* self = (wyLagrangeConfig*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'cp2Y'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->cp2Y);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: cp2Y of class  wyLagrangeConfig */
#ifndef TOLUA_DISABLE_tolua_set_wyLagrangeConfig_cp2Y
static int tolua_set_wyLagrangeConfig_cp2Y(lua_State* tolua_S)
{
  wyLagrangeConfig* self = (wyLagrangeConfig*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'cp2Y'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->cp2Y = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: t0 of class  wyLagrangeConfig */
#ifndef TOLUA_DISABLE_tolua_get_wyLagrangeConfig_t0
static int tolua_get_wyLagrangeConfig_t0(lua_State* tolua_S)
{
  wyLagrangeConfig* self = (wyLagrangeConfig*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 't0'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->t0);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: t0 of class  wyLagrangeConfig */
#ifndef TOLUA_DISABLE_tolua_set_wyLagrangeConfig_t0
static int tolua_set_wyLagrangeConfig_t0(lua_State* tolua_S)
{
  wyLagrangeConfig* self = (wyLagrangeConfig*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 't0'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->t0 = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: t1 of class  wyLagrangeConfig */
#ifndef TOLUA_DISABLE_tolua_get_wyLagrangeConfig_t1
static int tolua_get_wyLagrangeConfig_t1(lua_State* tolua_S)
{
  wyLagrangeConfig* self = (wyLagrangeConfig*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 't1'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->t1);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: t1 of class  wyLagrangeConfig */
#ifndef TOLUA_DISABLE_tolua_set_wyLagrangeConfig_t1
static int tolua_set_wyLagrangeConfig_t1(lua_State* tolua_S)
{
  wyLagrangeConfig* self = (wyLagrangeConfig*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 't1'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->t1 = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: t2 of class  wyLagrangeConfig */
#ifndef TOLUA_DISABLE_tolua_get_wyLagrangeConfig_t2
static int tolua_get_wyLagrangeConfig_t2(lua_State* tolua_S)
{
  wyLagrangeConfig* self = (wyLagrangeConfig*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 't2'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->t2);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: t2 of class  wyLagrangeConfig */
#ifndef TOLUA_DISABLE_tolua_set_wyLagrangeConfig_t2
static int tolua_set_wyLagrangeConfig_t2(lua_State* tolua_S)
{
  wyLagrangeConfig* self = (wyLagrangeConfig*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 't2'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->t2 = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: t3 of class  wyLagrangeConfig */
#ifndef TOLUA_DISABLE_tolua_get_wyLagrangeConfig_t3
static int tolua_get_wyLagrangeConfig_t3(lua_State* tolua_S)
{
  wyLagrangeConfig* self = (wyLagrangeConfig*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 't3'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->t3);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: t3 of class  wyLagrangeConfig */
#ifndef TOLUA_DISABLE_tolua_set_wyLagrangeConfig_t3
static int tolua_set_wyLagrangeConfig_t3(lua_State* tolua_S)
{
  wyLagrangeConfig* self = (wyLagrangeConfig*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 't3'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->t3 = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: R of class  wyHypotrochoidConfig */
#ifndef TOLUA_DISABLE_tolua_get_wyHypotrochoidConfig_R
static int tolua_get_wyHypotrochoidConfig_R(lua_State* tolua_S)
{
  wyHypotrochoidConfig* self = (wyHypotrochoidConfig*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'R'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->R);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: R of class  wyHypotrochoidConfig */
#ifndef TOLUA_DISABLE_tolua_set_wyHypotrochoidConfig_R
static int tolua_set_wyHypotrochoidConfig_R(lua_State* tolua_S)
{
  wyHypotrochoidConfig* self = (wyHypotrochoidConfig*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'R'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->R = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: r of class  wyHypotrochoidConfig */
#ifndef TOLUA_DISABLE_tolua_get_wyHypotrochoidConfig_r
static int tolua_get_wyHypotrochoidConfig_r(lua_State* tolua_S)
{
  wyHypotrochoidConfig* self = (wyHypotrochoidConfig*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'r'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->r);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: r of class  wyHypotrochoidConfig */
#ifndef TOLUA_DISABLE_tolua_set_wyHypotrochoidConfig_r
static int tolua_set_wyHypotrochoidConfig_r(lua_State* tolua_S)
{
  wyHypotrochoidConfig* self = (wyHypotrochoidConfig*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'r'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->r = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: d of class  wyHypotrochoidConfig */
#ifndef TOLUA_DISABLE_tolua_get_wyHypotrochoidConfig_d
static int tolua_get_wyHypotrochoidConfig_d(lua_State* tolua_S)
{
  wyHypotrochoidConfig* self = (wyHypotrochoidConfig*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'd'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->d);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: d of class  wyHypotrochoidConfig */
#ifndef TOLUA_DISABLE_tolua_set_wyHypotrochoidConfig_d
static int tolua_set_wyHypotrochoidConfig_d(lua_State* tolua_S)
{
  wyHypotrochoidConfig* self = (wyHypotrochoidConfig*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'd'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->d = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: startAngle of class  wyHypotrochoidConfig */
#ifndef TOLUA_DISABLE_tolua_get_wyHypotrochoidConfig_startAngle
static int tolua_get_wyHypotrochoidConfig_startAngle(lua_State* tolua_S)
{
  wyHypotrochoidConfig* self = (wyHypotrochoidConfig*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'startAngle'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->startAngle);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: startAngle of class  wyHypotrochoidConfig */
#ifndef TOLUA_DISABLE_tolua_set_wyHypotrochoidConfig_startAngle
static int tolua_set_wyHypotrochoidConfig_startAngle(lua_State* tolua_S)
{
  wyHypotrochoidConfig* self = (wyHypotrochoidConfig*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'startAngle'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->startAngle = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: endAngle of class  wyHypotrochoidConfig */
#ifndef TOLUA_DISABLE_tolua_get_wyHypotrochoidConfig_endAngle
static int tolua_get_wyHypotrochoidConfig_endAngle(lua_State* tolua_S)
{
  wyHypotrochoidConfig* self = (wyHypotrochoidConfig*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'endAngle'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->endAngle);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: endAngle of class  wyHypotrochoidConfig */
#ifndef TOLUA_DISABLE_tolua_set_wyHypotrochoidConfig_endAngle
static int tolua_set_wyHypotrochoidConfig_endAngle(lua_State* tolua_S)
{
  wyHypotrochoidConfig* self = (wyHypotrochoidConfig*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'endAngle'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->endAngle = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: centreX of class  wyHypotrochoidConfig */
#ifndef TOLUA_DISABLE_tolua_get_wyHypotrochoidConfig_centreX
static int tolua_get_wyHypotrochoidConfig_centreX(lua_State* tolua_S)
{
  wyHypotrochoidConfig* self = (wyHypotrochoidConfig*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'centreX'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->centreX);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: centreX of class  wyHypotrochoidConfig */
#ifndef TOLUA_DISABLE_tolua_set_wyHypotrochoidConfig_centreX
static int tolua_set_wyHypotrochoidConfig_centreX(lua_State* tolua_S)
{
  wyHypotrochoidConfig* self = (wyHypotrochoidConfig*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'centreX'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->centreX = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: centreY of class  wyHypotrochoidConfig */
#ifndef TOLUA_DISABLE_tolua_get_wyHypotrochoidConfig_centreY
static int tolua_get_wyHypotrochoidConfig_centreY(lua_State* tolua_S)
{
  wyHypotrochoidConfig* self = (wyHypotrochoidConfig*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'centreY'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->centreY);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: centreY of class  wyHypotrochoidConfig */
#ifndef TOLUA_DISABLE_tolua_set_wyHypotrochoidConfig_centreY
static int tolua_set_wyHypotrochoidConfig_centreY(lua_State* tolua_S)
{
  wyHypotrochoidConfig* self = (wyHypotrochoidConfig*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'centreY'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->centreY = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: deltaAngle of class  wyHypotrochoidConfig */
#ifndef TOLUA_DISABLE_tolua_get_wyHypotrochoidConfig_deltaAngle
static int tolua_get_wyHypotrochoidConfig_deltaAngle(lua_State* tolua_S)
{
  wyHypotrochoidConfig* self = (wyHypotrochoidConfig*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'deltaAngle'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->deltaAngle);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: deltaAngle of class  wyHypotrochoidConfig */
#ifndef TOLUA_DISABLE_tolua_set_wyHypotrochoidConfig_deltaAngle
static int tolua_set_wyHypotrochoidConfig_deltaAngle(lua_State* tolua_S)
{
  wyHypotrochoidConfig* self = (wyHypotrochoidConfig*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'deltaAngle'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->deltaAngle = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: temp1 of class  wyHypotrochoidConfig */
#ifndef TOLUA_DISABLE_tolua_get_wyHypotrochoidConfig_temp1
static int tolua_get_wyHypotrochoidConfig_temp1(lua_State* tolua_S)
{
  wyHypotrochoidConfig* self = (wyHypotrochoidConfig*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'temp1'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->temp1);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: temp1 of class  wyHypotrochoidConfig */
#ifndef TOLUA_DISABLE_tolua_set_wyHypotrochoidConfig_temp1
static int tolua_set_wyHypotrochoidConfig_temp1(lua_State* tolua_S)
{
  wyHypotrochoidConfig* self = (wyHypotrochoidConfig*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'temp1'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->temp1 = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: temp2 of class  wyHypotrochoidConfig */
#ifndef TOLUA_DISABLE_tolua_get_wyHypotrochoidConfig_temp2
static int tolua_get_wyHypotrochoidConfig_temp2(lua_State* tolua_S)
{
  wyHypotrochoidConfig* self = (wyHypotrochoidConfig*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'temp2'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->temp2);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: temp2 of class  wyHypotrochoidConfig */
#ifndef TOLUA_DISABLE_tolua_set_wyHypotrochoidConfig_temp2
static int tolua_set_wyHypotrochoidConfig_temp2(lua_State* tolua_S)
{
  wyHypotrochoidConfig* self = (wyHypotrochoidConfig*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'temp2'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->temp2 = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: key of class  wyKeyValueHash */
#ifndef TOLUA_DISABLE_tolua_get_wyKeyValueHash_key
static int tolua_get_wyKeyValueHash_key(lua_State* tolua_S)
{
  wyKeyValueHash* self = (wyKeyValueHash*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'key'",NULL);
#endif
  tolua_pushstring(tolua_S,(const char*)self->key);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: key of class  wyKeyValueHash */
#ifndef TOLUA_DISABLE_tolua_set_wyKeyValueHash_key
static int tolua_set_wyKeyValueHash_key(lua_State* tolua_S)
{
  wyKeyValueHash* self = (wyKeyValueHash*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'key'",NULL);
  if (!tolua_isstring(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->key = ((char*)  tolua_tostring(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: value of class  wyKeyValueHash */
#ifndef TOLUA_DISABLE_tolua_get_wyKeyValueHash_value
static int tolua_get_wyKeyValueHash_value(lua_State* tolua_S)
{
  wyKeyValueHash* self = (wyKeyValueHash*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'value'",NULL);
#endif
  tolua_pushstring(tolua_S,(const char*)self->value);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: value of class  wyKeyValueHash */
#ifndef TOLUA_DISABLE_tolua_set_wyKeyValueHash_value
static int tolua_set_wyKeyValueHash_value(lua_State* tolua_S)
{
  wyKeyValueHash* self = (wyKeyValueHash*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'value'",NULL);
  if (!tolua_isstring(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->value = ((char*)  tolua_tostring(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: keyCode of class  wyKeyEvent */
#ifndef TOLUA_DISABLE_tolua_get_wyKeyEvent_keyCode
static int tolua_get_wyKeyEvent_keyCode(lua_State* tolua_S)
{
  wyKeyEvent* self = (wyKeyEvent*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'keyCode'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->keyCode);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: keyCode of class  wyKeyEvent */
#ifndef TOLUA_DISABLE_tolua_set_wyKeyEvent_keyCode
static int tolua_set_wyKeyEvent_keyCode(lua_State* tolua_S)
{
  wyKeyEvent* self = (wyKeyEvent*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'keyCode'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->keyCode = ((wyKeyCode) (int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: repeatCount of class  wyKeyEvent */
#ifndef TOLUA_DISABLE_tolua_get_wyKeyEvent_repeatCount
static int tolua_get_wyKeyEvent_repeatCount(lua_State* tolua_S)
{
  wyKeyEvent* self = (wyKeyEvent*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'repeatCount'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->repeatCount);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: repeatCount of class  wyKeyEvent */
#ifndef TOLUA_DISABLE_tolua_set_wyKeyEvent_repeatCount
static int tolua_set_wyKeyEvent_repeatCount(lua_State* tolua_S)
{
  wyKeyEvent* self = (wyKeyEvent*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'repeatCount'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->repeatCount = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: eventTime of class  wyKeyEvent */
#ifndef TOLUA_DISABLE_tolua_get_wyKeyEvent_eventTime
static int tolua_get_wyKeyEvent_eventTime(lua_State* tolua_S)
{
  wyKeyEvent* self = (wyKeyEvent*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'eventTime'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->eventTime,"int64_t");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: eventTime of class  wyKeyEvent */
#ifndef TOLUA_DISABLE_tolua_set_wyKeyEvent_eventTime
static int tolua_set_wyKeyEvent_eventTime(lua_State* tolua_S)
{
  wyKeyEvent* self = (wyKeyEvent*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'eventTime'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"int64_t",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->eventTime = *((int64_t*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: downTime of class  wyKeyEvent */
#ifndef TOLUA_DISABLE_tolua_get_wyKeyEvent_downTime
static int tolua_get_wyKeyEvent_downTime(lua_State* tolua_S)
{
  wyKeyEvent* self = (wyKeyEvent*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'downTime'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->downTime,"int64_t");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: downTime of class  wyKeyEvent */
#ifndef TOLUA_DISABLE_tolua_set_wyKeyEvent_downTime
static int tolua_set_wyKeyEvent_downTime(lua_State* tolua_S)
{
  wyKeyEvent* self = (wyKeyEvent*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'downTime'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"int64_t",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->downTime = *((int64_t*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: pointerCount of class  wyMotionEvent */
#ifndef TOLUA_DISABLE_tolua_get_wyMotionEvent_pointerCount
static int tolua_get_wyMotionEvent_pointerCount(lua_State* tolua_S)
{
  wyMotionEvent* self = (wyMotionEvent*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'pointerCount'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->pointerCount);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: pointerCount of class  wyMotionEvent */
#ifndef TOLUA_DISABLE_tolua_set_wyMotionEvent_pointerCount
static int tolua_set_wyMotionEvent_pointerCount(lua_State* tolua_S)
{
  wyMotionEvent* self = (wyMotionEvent*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'pointerCount'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->pointerCount = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: pid of class  wyMotionEvent */
#ifndef TOLUA_DISABLE_tolua_get_types_wyMotionEvent_pid
static int tolua_get_types_wyMotionEvent_pid(lua_State* tolua_S)
{
 int tolua_index;
  wyMotionEvent* self;
 lua_pushstring(tolua_S,".self");
 lua_rawget(tolua_S,1);
 self = (wyMotionEvent*)  lua_touserdata(tolua_S,-1);
#ifndef TOLUA_RELEASE
 {
  tolua_Error tolua_err;
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in array indexing.",&tolua_err);
 }
#endif
 tolua_index = (int)tolua_tonumber(tolua_S,2,0);
#ifndef TOLUA_RELEASE
 if (tolua_index<0 || tolua_index>=5)
  tolua_error(tolua_S,"array indexing out of range.",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->pid[tolua_index]);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: pid of class  wyMotionEvent */
#ifndef TOLUA_DISABLE_tolua_set_types_wyMotionEvent_pid
static int tolua_set_types_wyMotionEvent_pid(lua_State* tolua_S)
{
 int tolua_index;
  wyMotionEvent* self;
 lua_pushstring(tolua_S,".self");
 lua_rawget(tolua_S,1);
 self = (wyMotionEvent*)  lua_touserdata(tolua_S,-1);
#ifndef TOLUA_RELEASE
 {
  tolua_Error tolua_err;
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in array indexing.",&tolua_err);
 }
#endif
 tolua_index = (int)tolua_tonumber(tolua_S,2,0);
#ifndef TOLUA_RELEASE
 if (tolua_index<0 || tolua_index>=5)
  tolua_error(tolua_S,"array indexing out of range.",NULL);
#endif
  self->pid[tolua_index] = ((int)  tolua_tonumber(tolua_S,3,0));
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: x of class  wyMotionEvent */
#ifndef TOLUA_DISABLE_tolua_get_types_wyMotionEvent_x
static int tolua_get_types_wyMotionEvent_x(lua_State* tolua_S)
{
 int tolua_index;
  wyMotionEvent* self;
 lua_pushstring(tolua_S,".self");
 lua_rawget(tolua_S,1);
 self = (wyMotionEvent*)  lua_touserdata(tolua_S,-1);
#ifndef TOLUA_RELEASE
 {
  tolua_Error tolua_err;
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in array indexing.",&tolua_err);
 }
#endif
 tolua_index = (int)tolua_tonumber(tolua_S,2,0);
#ifndef TOLUA_RELEASE
 if (tolua_index<0 || tolua_index>=5)
  tolua_error(tolua_S,"array indexing out of range.",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->x[tolua_index]);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: x of class  wyMotionEvent */
#ifndef TOLUA_DISABLE_tolua_set_types_wyMotionEvent_x
static int tolua_set_types_wyMotionEvent_x(lua_State* tolua_S)
{
 int tolua_index;
  wyMotionEvent* self;
 lua_pushstring(tolua_S,".self");
 lua_rawget(tolua_S,1);
 self = (wyMotionEvent*)  lua_touserdata(tolua_S,-1);
#ifndef TOLUA_RELEASE
 {
  tolua_Error tolua_err;
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in array indexing.",&tolua_err);
 }
#endif
 tolua_index = (int)tolua_tonumber(tolua_S,2,0);
#ifndef TOLUA_RELEASE
 if (tolua_index<0 || tolua_index>=5)
  tolua_error(tolua_S,"array indexing out of range.",NULL);
#endif
  self->x[tolua_index] = ((float)  tolua_tonumber(tolua_S,3,0));
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: y of class  wyMotionEvent */
#ifndef TOLUA_DISABLE_tolua_get_types_wyMotionEvent_y
static int tolua_get_types_wyMotionEvent_y(lua_State* tolua_S)
{
 int tolua_index;
  wyMotionEvent* self;
 lua_pushstring(tolua_S,".self");
 lua_rawget(tolua_S,1);
 self = (wyMotionEvent*)  lua_touserdata(tolua_S,-1);
#ifndef TOLUA_RELEASE
 {
  tolua_Error tolua_err;
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in array indexing.",&tolua_err);
 }
#endif
 tolua_index = (int)tolua_tonumber(tolua_S,2,0);
#ifndef TOLUA_RELEASE
 if (tolua_index<0 || tolua_index>=5)
  tolua_error(tolua_S,"array indexing out of range.",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->y[tolua_index]);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: y of class  wyMotionEvent */
#ifndef TOLUA_DISABLE_tolua_set_types_wyMotionEvent_y
static int tolua_set_types_wyMotionEvent_y(lua_State* tolua_S)
{
 int tolua_index;
  wyMotionEvent* self;
 lua_pushstring(tolua_S,".self");
 lua_rawget(tolua_S,1);
 self = (wyMotionEvent*)  lua_touserdata(tolua_S,-1);
#ifndef TOLUA_RELEASE
 {
  tolua_Error tolua_err;
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in array indexing.",&tolua_err);
 }
#endif
 tolua_index = (int)tolua_tonumber(tolua_S,2,0);
#ifndef TOLUA_RELEASE
 if (tolua_index<0 || tolua_index>=5)
  tolua_error(tolua_S,"array indexing out of range.",NULL);
#endif
  self->y[tolua_index] = ((float)  tolua_tonumber(tolua_S,3,0));
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: eventTime of class  wyMotionEvent */
#ifndef TOLUA_DISABLE_tolua_get_wyMotionEvent_eventTime
static int tolua_get_wyMotionEvent_eventTime(lua_State* tolua_S)
{
  wyMotionEvent* self = (wyMotionEvent*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'eventTime'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->eventTime,"int64_t");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: eventTime of class  wyMotionEvent */
#ifndef TOLUA_DISABLE_tolua_set_wyMotionEvent_eventTime
static int tolua_set_wyMotionEvent_eventTime(lua_State* tolua_S)
{
  wyMotionEvent* self = (wyMotionEvent*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'eventTime'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"int64_t",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->eventTime = *((int64_t*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: wyvZero */
#ifndef TOLUA_DISABLE_tolua_get_wyvZero
static int tolua_get_wyvZero(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&wyvZero,"const wyVertex3D");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* function: wyv */
#ifndef TOLUA_DISABLE_tolua_types_wyv00
static int tolua_types_wyv00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const float x = ((const float)  tolua_tonumber(tolua_S,1,0));
  const float y = ((const float)  tolua_tonumber(tolua_S,2,0));
  const float z = ((const float)  tolua_tonumber(tolua_S,3,0));
  {
   wyVertex3D tolua_ret = (wyVertex3D)  wyv(x,y,z);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((wyVertex3D)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"wyVertex3D");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(wyVertex3D));
     tolua_pushusertype(tolua_S,tolua_obj,"wyVertex3D");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'wyv'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_types_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,1);
 tolua_beginmodule(tolua_S,NULL);
  tolua_constant(tolua_S,"ZERO",ZERO);
  tolua_variable(tolua_S,"wyaZero",tolua_get_wyaZero,NULL);
  tolua_variable(tolua_S,"wyaIdentity",tolua_get_wyaIdentity,NULL);
  tolua_function(tolua_S,"wyaSetToRotation",tolua_types_wyaSetToRotation00);
  tolua_function(tolua_S,"wyaMakeRotate",tolua_types_wyaMakeRotate00);
  tolua_function(tolua_S,"wyaScale",tolua_types_wyaScale00);
  tolua_function(tolua_S,"wyaTranslate",tolua_types_wyaTranslate00);
  tolua_function(tolua_S,"wyaRotate",tolua_types_wyaRotate00);
  tolua_function(tolua_S,"wyaGetDeterminant",tolua_types_wyaGetDeterminant00);
  tolua_function(tolua_S,"wyaSetToIdentity",tolua_types_wyaSetToIdentity00);
  tolua_function(tolua_S,"wyaInverse",tolua_types_wyaInverse00);
  tolua_function(tolua_S,"wyaTransformPoint",tolua_types_wyaTransformPoint00);
  tolua_function(tolua_S,"wyaTransformRect",tolua_types_wyaTransformRect00);
  tolua_function(tolua_S,"wyaMultiply",tolua_types_wyaMultiply00);
  tolua_function(tolua_S,"wyaConcat",tolua_types_wyaConcat00);
  tolua_constant(tolua_S,"DEFAULT_BLEND_SRC",DEFAULT_BLEND_SRC);
  tolua_constant(tolua_S,"DEFAULT_BLEND_DST",DEFAULT_BLEND_DST);
  tolua_variable(tolua_S,"wybfDefault",tolua_get_wybfDefault,NULL);
  tolua_function(tolua_S,"wybf",tolua_types_wybf00);
  tolua_variable(tolua_S,"wyc3bWhite",tolua_get_wyc3bWhite,NULL);
  tolua_variable(tolua_S,"wyc3bBlack",tolua_get_wyc3bBlack,NULL);
  tolua_variable(tolua_S,"wyc3bRed",tolua_get_wyc3bRed,NULL);
  tolua_variable(tolua_S,"wyc3bGray",tolua_get_wyc3bGray,NULL);
  tolua_function(tolua_S,"wyc3b",tolua_types_wyc3b00);
  tolua_function(tolua_S,"wyc3b2c4f",tolua_types_wyc3b2c4f00);
  tolua_variable(tolua_S,"wyc4bWhite",tolua_get_wyc4bWhite,NULL);
  tolua_variable(tolua_S,"wyc4bGray",tolua_get_wyc4bGray,NULL);
  tolua_variable(tolua_S,"wyc4bBlue",tolua_get_wyc4bBlue,NULL);
  tolua_variable(tolua_S,"wyc4bTransparent",tolua_get_wyc4bTransparent,NULL);
  tolua_function(tolua_S,"wyc4b",tolua_types_wyc4b00);
  tolua_variable(tolua_S,"wyc4fWhite",tolua_get_wyc4fWhite,NULL);
  tolua_function(tolua_S,"wyc4f",tolua_types_wyc4f00);
  tolua_variable(tolua_S,"wydZero",tolua_get_wydZero,NULL);
  tolua_function(tolua_S,"wyd",tolua_types_wyd00);
  tolua_variable(tolua_S,"wypZero",tolua_get_wypZero,NULL);
  tolua_function(tolua_S,"wyp",tolua_types_wyp00);
  tolua_function(tolua_S,"wypFromString",tolua_types_wypFromString00);
  tolua_function(tolua_S,"wypEquals",tolua_types_wypEquals00);
  tolua_function(tolua_S,"wypToRadian",tolua_types_wypToRadian00);
  tolua_function(tolua_S,"wypMul",tolua_types_wypMul00);
  tolua_function(tolua_S,"wypMul2",tolua_types_wypMul200);
  tolua_function(tolua_S,"wypAdd",tolua_types_wypAdd00);
  tolua_function(tolua_S,"wypSub",tolua_types_wypSub00);
  tolua_function(tolua_S,"wypMidpoint",tolua_types_wypMidpoint00);
  tolua_function(tolua_S,"wypDot",tolua_types_wypDot00);
  tolua_function(tolua_S,"wypCross",tolua_types_wypCross00);
  tolua_function(tolua_S,"wypPerp",tolua_types_wypPerp00);
  tolua_function(tolua_S,"wypReversePerp",tolua_types_wypReversePerp00);
  tolua_function(tolua_S,"wypLength",tolua_types_wypLength00);
  tolua_function(tolua_S,"wypLengthsq",tolua_types_wypLengthsq00);
  tolua_function(tolua_S,"wypDistance",tolua_types_wypDistance00);
  tolua_function(tolua_S,"wypNormalize",tolua_types_wypNormalize00);
  tolua_function(tolua_S,"wypLerp",tolua_types_wypLerp00);
  tolua_function(tolua_S,"wypRotateByAngle",tolua_types_wypRotateByAngle00);
  tolua_function(tolua_S,"wypFuzzyEqual",tolua_types_wypFuzzyEqual00);
  tolua_function(tolua_S,"wypLineIntersect",tolua_types_wypLineIntersect00);
  tolua_constant(tolua_S,"PVR_TEXTURE_FLAG_TYPE_MASK",PVR_TEXTURE_FLAG_TYPE_MASK);
  tolua_constant(tolua_S,"PVR_TEXTURE_FLAG_FLIPPED_MASK",PVR_TEXTURE_FLAG_FLIPPED_MASK);
  tolua_constant(tolua_S,"PVR_RGBA_4444",PVR_RGBA_4444);
  tolua_constant(tolua_S,"PVR_RGBA_5551",PVR_RGBA_5551);
  tolua_constant(tolua_S,"PVR_RGBA_8888",PVR_RGBA_8888);
  tolua_constant(tolua_S,"PVR_RGB_565",PVR_RGB_565);
  tolua_constant(tolua_S,"PVR_RGB_555",PVR_RGB_555);
  tolua_constant(tolua_S,"PVR_RGB_888",PVR_RGB_888);
  tolua_constant(tolua_S,"PVR_I_8",PVR_I_8);
  tolua_constant(tolua_S,"PVR_AI_88",PVR_AI_88);
  tolua_constant(tolua_S,"PVR_PVRTC_2",PVR_PVRTC_2);
  tolua_constant(tolua_S,"PVR_PVRTC_4",PVR_PVRTC_4);
  tolua_constant(tolua_S,"PVR_BGRA_8888",PVR_BGRA_8888);
  tolua_constant(tolua_S,"PVR_A_8",PVR_A_8);
  tolua_constant(tolua_S,"PVR_INDEX_TEXTURE_FORMAT",PVR_INDEX_TEXTURE_FORMAT);
  tolua_constant(tolua_S,"PVR_INDEX_INTERNAL_FORMAT",PVR_INDEX_INTERNAL_FORMAT);
  tolua_constant(tolua_S,"PVR_INDEX_OPENGL_FORMAT",PVR_INDEX_OPENGL_FORMAT);
  tolua_constant(tolua_S,"PVR_INDEX_OPENGL_TYPE",PVR_INDEX_OPENGL_TYPE);
  tolua_constant(tolua_S,"PVR_INDEX_BPP",PVR_INDEX_BPP);
  tolua_constant(tolua_S,"PVR_INDEX_COMPRESSED",PVR_INDEX_COMPRESSED);
  tolua_cclass(tolua_S,"wyPVRHeader","wyPVRHeader","",NULL);
  tolua_beginmodule(tolua_S,"wyPVRHeader");
   tolua_variable(tolua_S,"headerLength",tolua_get_wyPVRHeader_headerLength,tolua_set_wyPVRHeader_headerLength);
   tolua_variable(tolua_S,"height",tolua_get_wyPVRHeader_height,tolua_set_wyPVRHeader_height);
   tolua_variable(tolua_S,"width",tolua_get_wyPVRHeader_width,tolua_set_wyPVRHeader_width);
   tolua_variable(tolua_S,"numMipmaps",tolua_get_wyPVRHeader_numMipmaps,tolua_set_wyPVRHeader_numMipmaps);
   tolua_variable(tolua_S,"flags",tolua_get_wyPVRHeader_flags,tolua_set_wyPVRHeader_flags);
   tolua_variable(tolua_S,"dataLength",tolua_get_wyPVRHeader_dataLength,tolua_set_wyPVRHeader_dataLength);
   tolua_variable(tolua_S,"bpp",tolua_get_wyPVRHeader_bpp,tolua_set_wyPVRHeader_bpp);
   tolua_variable(tolua_S,"bitmaskRed",tolua_get_wyPVRHeader_bitmaskRed,tolua_set_wyPVRHeader_bitmaskRed);
   tolua_variable(tolua_S,"bitmaskGreen",tolua_get_wyPVRHeader_bitmaskGreen,tolua_set_wyPVRHeader_bitmaskGreen);
   tolua_variable(tolua_S,"bitmaskBlue",tolua_get_wyPVRHeader_bitmaskBlue,tolua_set_wyPVRHeader_bitmaskBlue);
   tolua_variable(tolua_S,"bitmaskAlpha",tolua_get_wyPVRHeader_bitmaskAlpha,tolua_set_wyPVRHeader_bitmaskAlpha);
   tolua_variable(tolua_S,"pvrTag",tolua_get_wyPVRHeader_pvrTag,tolua_set_wyPVRHeader_pvrTag);
   tolua_variable(tolua_S,"numSurfs",tolua_get_wyPVRHeader_numSurfs,tolua_set_wyPVRHeader_numSurfs);
  tolua_endmodule(tolua_S);
  tolua_variable(tolua_S,"wyq2Zero",tolua_get_wyq2Zero,NULL);
  tolua_function(tolua_S,"wyq2",tolua_types_wyq200);
  tolua_function(tolua_S,"wyq2Scale",tolua_types_wyq2Scale00);
  tolua_function(tolua_S,"wyq2Set",tolua_types_wyq2Set00);
  tolua_variable(tolua_S,"wyq3Zero",tolua_get_wyq3Zero,NULL);
  tolua_function(tolua_S,"wyq3",tolua_types_wyq300);
  tolua_function(tolua_S,"wyq3Scale",tolua_types_wyq3Scale00);
  tolua_function(tolua_S,"wyq3Set",tolua_types_wyq3Set00);
  tolua_variable(tolua_S,"wyrZero",tolua_get_wyrZero,NULL);
  tolua_function(tolua_S,"wyr",tolua_types_wyr00);
  tolua_function(tolua_S,"wyrFromString",tolua_types_wyrFromString00);
  tolua_function(tolua_S,"wyrEquals",tolua_types_wyrEquals00);
  tolua_function(tolua_S,"wyrContains",tolua_types_wyrContains00);
  tolua_function(tolua_S,"wyrIsIntersect",tolua_types_wyrIsIntersect00);
  tolua_variable(tolua_S,"wysZero",tolua_get_wysZero,NULL);
  tolua_function(tolua_S,"wys",tolua_types_wys00);
  tolua_function(tolua_S,"wysFromString",tolua_types_wysFromString00);
  tolua_function(tolua_S,"isEqual",tolua_types_isEqual00);
  tolua_constant(tolua_S,"FLT_EPSILON",FLT_EPSILON);
  tolua_constant(tolua_S,"GOLDEN_MEAN",GOLDEN_MEAN);
  tolua_constant(tolua_S,"MAX_FLOAT",MAX_FLOAT);
  tolua_constant(tolua_S,"MAX_INT",MAX_INT);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyPoint","wyPoint","",tolua_collect_wyPoint);
  #else
  tolua_cclass(tolua_S,"wyPoint","wyPoint","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyPoint");
   tolua_variable(tolua_S,"x",tolua_get_wyPoint_x,tolua_set_wyPoint_x);
   tolua_variable(tolua_S,"y",tolua_get_wyPoint_y,tolua_set_wyPoint_y);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyDimension","wyDimension","",tolua_collect_wyDimension);
  #else
  tolua_cclass(tolua_S,"wyDimension","wyDimension","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyDimension");
   tolua_variable(tolua_S,"x",tolua_get_wyDimension_x,tolua_set_wyDimension_x);
   tolua_variable(tolua_S,"y",tolua_get_wyDimension_y,tolua_set_wyDimension_y);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wySize","wySize","",tolua_collect_wySize);
  #else
  tolua_cclass(tolua_S,"wySize","wySize","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wySize");
   tolua_variable(tolua_S,"width",tolua_get_wySize_width,tolua_set_wySize_width);
   tolua_variable(tolua_S,"height",tolua_get_wySize_height,tolua_set_wySize_height);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyRect","wyRect","",tolua_collect_wyRect);
  #else
  tolua_cclass(tolua_S,"wyRect","wyRect","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyRect");
   tolua_variable(tolua_S,"x",tolua_get_wyRect_x,tolua_set_wyRect_x);
   tolua_variable(tolua_S,"y",tolua_get_wyRect_y,tolua_set_wyRect_y);
   tolua_variable(tolua_S,"width",tolua_get_wyRect_width,tolua_set_wyRect_width);
   tolua_variable(tolua_S,"height",tolua_get_wyRect_height,tolua_set_wyRect_height);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyVertex3D","wyVertex3D","",tolua_collect_wyVertex3D);
  #else
  tolua_cclass(tolua_S,"wyVertex3D","wyVertex3D","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyVertex3D");
   tolua_variable(tolua_S,"x",tolua_get_wyVertex3D_x,tolua_set_wyVertex3D_x);
   tolua_variable(tolua_S,"y",tolua_get_wyVertex3D_y,tolua_set_wyVertex3D_y);
   tolua_variable(tolua_S,"z",tolua_get_wyVertex3D_z,tolua_set_wyVertex3D_z);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyQuad3D","wyQuad3D","",tolua_collect_wyQuad3D);
  #else
  tolua_cclass(tolua_S,"wyQuad3D","wyQuad3D","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyQuad3D");
   tolua_variable(tolua_S,"bl_x",tolua_get_wyQuad3D_bl_x,tolua_set_wyQuad3D_bl_x);
   tolua_variable(tolua_S,"bl_y",tolua_get_wyQuad3D_bl_y,tolua_set_wyQuad3D_bl_y);
   tolua_variable(tolua_S,"bl_z",tolua_get_wyQuad3D_bl_z,tolua_set_wyQuad3D_bl_z);
   tolua_variable(tolua_S,"br_x",tolua_get_wyQuad3D_br_x,tolua_set_wyQuad3D_br_x);
   tolua_variable(tolua_S,"br_y",tolua_get_wyQuad3D_br_y,tolua_set_wyQuad3D_br_y);
   tolua_variable(tolua_S,"br_z",tolua_get_wyQuad3D_br_z,tolua_set_wyQuad3D_br_z);
   tolua_variable(tolua_S,"tl_x",tolua_get_wyQuad3D_tl_x,tolua_set_wyQuad3D_tl_x);
   tolua_variable(tolua_S,"tl_y",tolua_get_wyQuad3D_tl_y,tolua_set_wyQuad3D_tl_y);
   tolua_variable(tolua_S,"tl_z",tolua_get_wyQuad3D_tl_z,tolua_set_wyQuad3D_tl_z);
   tolua_variable(tolua_S,"tr_x",tolua_get_wyQuad3D_tr_x,tolua_set_wyQuad3D_tr_x);
   tolua_variable(tolua_S,"tr_y",tolua_get_wyQuad3D_tr_y,tolua_set_wyQuad3D_tr_y);
   tolua_variable(tolua_S,"tr_z",tolua_get_wyQuad3D_tr_z,tolua_set_wyQuad3D_tr_z);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyQuad2D","wyQuad2D","",tolua_collect_wyQuad2D);
  #else
  tolua_cclass(tolua_S,"wyQuad2D","wyQuad2D","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyQuad2D");
   tolua_variable(tolua_S,"bl_x",tolua_get_wyQuad2D_bl_x,tolua_set_wyQuad2D_bl_x);
   tolua_variable(tolua_S,"bl_y",tolua_get_wyQuad2D_bl_y,tolua_set_wyQuad2D_bl_y);
   tolua_variable(tolua_S,"br_x",tolua_get_wyQuad2D_br_x,tolua_set_wyQuad2D_br_x);
   tolua_variable(tolua_S,"br_y",tolua_get_wyQuad2D_br_y,tolua_set_wyQuad2D_br_y);
   tolua_variable(tolua_S,"tl_x",tolua_get_wyQuad2D_tl_x,tolua_set_wyQuad2D_tl_x);
   tolua_variable(tolua_S,"tl_y",tolua_get_wyQuad2D_tl_y,tolua_set_wyQuad2D_tl_y);
   tolua_variable(tolua_S,"tr_x",tolua_get_wyQuad2D_tr_x,tolua_set_wyQuad2D_tr_x);
   tolua_variable(tolua_S,"tr_y",tolua_get_wyQuad2D_tr_y,tolua_set_wyQuad2D_tr_y);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyAffineTransform","wyAffineTransform","",tolua_collect_wyAffineTransform);
  #else
  tolua_cclass(tolua_S,"wyAffineTransform","wyAffineTransform","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyAffineTransform");
   tolua_variable(tolua_S,"a",tolua_get_wyAffineTransform_a,tolua_set_wyAffineTransform_a);
   tolua_variable(tolua_S,"b",tolua_get_wyAffineTransform_b,tolua_set_wyAffineTransform_b);
   tolua_variable(tolua_S,"c",tolua_get_wyAffineTransform_c,tolua_set_wyAffineTransform_c);
   tolua_variable(tolua_S,"d",tolua_get_wyAffineTransform_d,tolua_set_wyAffineTransform_d);
   tolua_variable(tolua_S,"tx",tolua_get_wyAffineTransform_tx,tolua_set_wyAffineTransform_tx);
   tolua_variable(tolua_S,"ty",tolua_get_wyAffineTransform_ty,tolua_set_wyAffineTransform_ty);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyBlendFunc","wyBlendFunc","",tolua_collect_wyBlendFunc);
  #else
  tolua_cclass(tolua_S,"wyBlendFunc","wyBlendFunc","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyBlendFunc");
   tolua_variable(tolua_S,"src",tolua_get_wyBlendFunc_src,tolua_set_wyBlendFunc_src);
   tolua_variable(tolua_S,"dst",tolua_get_wyBlendFunc_dst,tolua_set_wyBlendFunc_dst);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyColor3B","wyColor3B","",tolua_collect_wyColor3B);
  #else
  tolua_cclass(tolua_S,"wyColor3B","wyColor3B","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyColor3B");
   tolua_variable(tolua_S,"r",tolua_get_wyColor3B_unsigned_r,tolua_set_wyColor3B_unsigned_r);
   tolua_variable(tolua_S,"g",tolua_get_wyColor3B_unsigned_g,tolua_set_wyColor3B_unsigned_g);
   tolua_variable(tolua_S,"b",tolua_get_wyColor3B_unsigned_b,tolua_set_wyColor3B_unsigned_b);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyColor4B","wyColor4B","",tolua_collect_wyColor4B);
  #else
  tolua_cclass(tolua_S,"wyColor4B","wyColor4B","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyColor4B");
   tolua_variable(tolua_S,"r",tolua_get_wyColor4B_unsigned_r,tolua_set_wyColor4B_unsigned_r);
   tolua_variable(tolua_S,"g",tolua_get_wyColor4B_unsigned_g,tolua_set_wyColor4B_unsigned_g);
   tolua_variable(tolua_S,"b",tolua_get_wyColor4B_unsigned_b,tolua_set_wyColor4B_unsigned_b);
   tolua_variable(tolua_S,"a",tolua_get_wyColor4B_unsigned_a,tolua_set_wyColor4B_unsigned_a);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyColor4F","wyColor4F","",tolua_collect_wyColor4F);
  #else
  tolua_cclass(tolua_S,"wyColor4F","wyColor4F","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyColor4F");
   tolua_variable(tolua_S,"r",tolua_get_wyColor4F_r,tolua_set_wyColor4F_r);
   tolua_variable(tolua_S,"g",tolua_get_wyColor4F_g,tolua_set_wyColor4F_g);
   tolua_variable(tolua_S,"b",tolua_get_wyColor4F_b,tolua_set_wyColor4F_b);
   tolua_variable(tolua_S,"a",tolua_get_wyColor4F_a,tolua_set_wyColor4F_a);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"wyBezierConfig","wyBezierConfig","",NULL);
  tolua_beginmodule(tolua_S,"wyBezierConfig");
   tolua_variable(tolua_S,"startX",tolua_get_wyBezierConfig_startX,tolua_set_wyBezierConfig_startX);
   tolua_variable(tolua_S,"startY",tolua_get_wyBezierConfig_startY,tolua_set_wyBezierConfig_startY);
   tolua_variable(tolua_S,"endX",tolua_get_wyBezierConfig_endX,tolua_set_wyBezierConfig_endX);
   tolua_variable(tolua_S,"endY",tolua_get_wyBezierConfig_endY,tolua_set_wyBezierConfig_endY);
   tolua_variable(tolua_S,"cp1X",tolua_get_wyBezierConfig_cp1X,tolua_set_wyBezierConfig_cp1X);
   tolua_variable(tolua_S,"cp1Y",tolua_get_wyBezierConfig_cp1Y,tolua_set_wyBezierConfig_cp1Y);
   tolua_variable(tolua_S,"cp2X",tolua_get_wyBezierConfig_cp2X,tolua_set_wyBezierConfig_cp2X);
   tolua_variable(tolua_S,"cp2Y",tolua_get_wyBezierConfig_cp2Y,tolua_set_wyBezierConfig_cp2Y);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"wyLagrangeConfig","wyLagrangeConfig","",NULL);
  tolua_beginmodule(tolua_S,"wyLagrangeConfig");
   tolua_variable(tolua_S,"cubic",tolua_get_wyLagrangeConfig_cubic,tolua_set_wyLagrangeConfig_cubic);
   tolua_variable(tolua_S,"startX",tolua_get_wyLagrangeConfig_startX,tolua_set_wyLagrangeConfig_startX);
   tolua_variable(tolua_S,"startY",tolua_get_wyLagrangeConfig_startY,tolua_set_wyLagrangeConfig_startY);
   tolua_variable(tolua_S,"endX",tolua_get_wyLagrangeConfig_endX,tolua_set_wyLagrangeConfig_endX);
   tolua_variable(tolua_S,"endY",tolua_get_wyLagrangeConfig_endY,tolua_set_wyLagrangeConfig_endY);
   tolua_variable(tolua_S,"cp1X",tolua_get_wyLagrangeConfig_cp1X,tolua_set_wyLagrangeConfig_cp1X);
   tolua_variable(tolua_S,"cp1Y",tolua_get_wyLagrangeConfig_cp1Y,tolua_set_wyLagrangeConfig_cp1Y);
   tolua_variable(tolua_S,"cp2X",tolua_get_wyLagrangeConfig_cp2X,tolua_set_wyLagrangeConfig_cp2X);
   tolua_variable(tolua_S,"cp2Y",tolua_get_wyLagrangeConfig_cp2Y,tolua_set_wyLagrangeConfig_cp2Y);
   tolua_variable(tolua_S,"t0",tolua_get_wyLagrangeConfig_t0,tolua_set_wyLagrangeConfig_t0);
   tolua_variable(tolua_S,"t1",tolua_get_wyLagrangeConfig_t1,tolua_set_wyLagrangeConfig_t1);
   tolua_variable(tolua_S,"t2",tolua_get_wyLagrangeConfig_t2,tolua_set_wyLagrangeConfig_t2);
   tolua_variable(tolua_S,"t3",tolua_get_wyLagrangeConfig_t3,tolua_set_wyLagrangeConfig_t3);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"wyHypotrochoidConfig","wyHypotrochoidConfig","",NULL);
  tolua_beginmodule(tolua_S,"wyHypotrochoidConfig");
   tolua_variable(tolua_S,"R",tolua_get_wyHypotrochoidConfig_R,tolua_set_wyHypotrochoidConfig_R);
   tolua_variable(tolua_S,"r",tolua_get_wyHypotrochoidConfig_r,tolua_set_wyHypotrochoidConfig_r);
   tolua_variable(tolua_S,"d",tolua_get_wyHypotrochoidConfig_d,tolua_set_wyHypotrochoidConfig_d);
   tolua_variable(tolua_S,"startAngle",tolua_get_wyHypotrochoidConfig_startAngle,tolua_set_wyHypotrochoidConfig_startAngle);
   tolua_variable(tolua_S,"endAngle",tolua_get_wyHypotrochoidConfig_endAngle,tolua_set_wyHypotrochoidConfig_endAngle);
   tolua_variable(tolua_S,"centreX",tolua_get_wyHypotrochoidConfig_centreX,tolua_set_wyHypotrochoidConfig_centreX);
   tolua_variable(tolua_S,"centreY",tolua_get_wyHypotrochoidConfig_centreY,tolua_set_wyHypotrochoidConfig_centreY);
   tolua_variable(tolua_S,"deltaAngle",tolua_get_wyHypotrochoidConfig_deltaAngle,tolua_set_wyHypotrochoidConfig_deltaAngle);
   tolua_variable(tolua_S,"temp1",tolua_get_wyHypotrochoidConfig_temp1,tolua_set_wyHypotrochoidConfig_temp1);
   tolua_variable(tolua_S,"temp2",tolua_get_wyHypotrochoidConfig_temp2,tolua_set_wyHypotrochoidConfig_temp2);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"wyKeyValueHash","wyKeyValueHash","",NULL);
  tolua_beginmodule(tolua_S,"wyKeyValueHash");
   tolua_variable(tolua_S,"key",tolua_get_wyKeyValueHash_key,tolua_set_wyKeyValueHash_key);
   tolua_variable(tolua_S,"value",tolua_get_wyKeyValueHash_value,tolua_set_wyKeyValueHash_value);
  tolua_endmodule(tolua_S);
  tolua_constant(tolua_S,"NORMAL",NORMAL);
  tolua_constant(tolua_S,"BOLD",BOLD);
  tolua_constant(tolua_S,"ITALIC",ITALIC);
  tolua_constant(tolua_S,"BOLD_ITALIC",BOLD_ITALIC);
  tolua_constant(tolua_S,"UNKNOWN_PLIST_TAG",UNKNOWN_PLIST_TAG);
  tolua_constant(tolua_S,"DOCUMENT",DOCUMENT);
  tolua_constant(tolua_S,"TAG_PLIST",TAG_PLIST);
  tolua_constant(tolua_S,"TAG_DICT",TAG_DICT);
  tolua_constant(tolua_S,"TAG_KEY",TAG_KEY);
  tolua_constant(tolua_S,"TAG_REAL",TAG_REAL);
  tolua_constant(tolua_S,"TAG_STRING",TAG_STRING);
  tolua_constant(tolua_S,"TAG_INTEGER",TAG_INTEGER);
  tolua_constant(tolua_S,"TAG_TRUE",TAG_TRUE);
  tolua_constant(tolua_S,"TAG_FALSE",TAG_FALSE);
  tolua_constant(tolua_S,"TAG_ARRAY",TAG_ARRAY);
  tolua_constant(tolua_S,"KEYCODE_UNKNOWN",KEYCODE_UNKNOWN);
  tolua_constant(tolua_S,"KEYCODE_SOFT_LEFT",KEYCODE_SOFT_LEFT);
  tolua_constant(tolua_S,"KEYCODE_SOFT_RIGHT",KEYCODE_SOFT_RIGHT);
  tolua_constant(tolua_S,"KEYCODE_HOME",KEYCODE_HOME);
  tolua_constant(tolua_S,"KEYCODE_BACK",KEYCODE_BACK);
  tolua_constant(tolua_S,"KEYCODE_CALL",KEYCODE_CALL);
  tolua_constant(tolua_S,"KEYCODE_ENDCALL",KEYCODE_ENDCALL);
  tolua_constant(tolua_S,"KEYCODE_0",KEYCODE_0);
  tolua_constant(tolua_S,"KEYCODE_1",KEYCODE_1);
  tolua_constant(tolua_S,"KEYCODE_2",KEYCODE_2);
  tolua_constant(tolua_S,"KEYCODE_3",KEYCODE_3);
  tolua_constant(tolua_S,"KEYCODE_4",KEYCODE_4);
  tolua_constant(tolua_S,"KEYCODE_5",KEYCODE_5);
  tolua_constant(tolua_S,"KEYCODE_6",KEYCODE_6);
  tolua_constant(tolua_S,"KEYCODE_7",KEYCODE_7);
  tolua_constant(tolua_S,"KEYCODE_8",KEYCODE_8);
  tolua_constant(tolua_S,"KEYCODE_9",KEYCODE_9);
  tolua_constant(tolua_S,"KEYCODE_STAR",KEYCODE_STAR);
  tolua_constant(tolua_S,"KEYCODE_POUND",KEYCODE_POUND);
  tolua_constant(tolua_S,"KEYCODE_DPAD_UP",KEYCODE_DPAD_UP);
  tolua_constant(tolua_S,"KEYCODE_DPAD_DOWN",KEYCODE_DPAD_DOWN);
  tolua_constant(tolua_S,"KEYCODE_DPAD_LEFT",KEYCODE_DPAD_LEFT);
  tolua_constant(tolua_S,"KEYCODE_DPAD_RIGHT",KEYCODE_DPAD_RIGHT);
  tolua_constant(tolua_S,"KEYCODE_DPAD_CENTER",KEYCODE_DPAD_CENTER);
  tolua_constant(tolua_S,"KEYCODE_VOLUME_UP",KEYCODE_VOLUME_UP);
  tolua_constant(tolua_S,"KEYCODE_VOLUME_DOWN",KEYCODE_VOLUME_DOWN);
  tolua_constant(tolua_S,"KEYCODE_POWER",KEYCODE_POWER);
  tolua_constant(tolua_S,"KEYCODE_CAMERA",KEYCODE_CAMERA);
  tolua_constant(tolua_S,"KEYCODE_CLEAR",KEYCODE_CLEAR);
  tolua_constant(tolua_S,"KEYCODE_A",KEYCODE_A);
  tolua_constant(tolua_S,"KEYCODE_B",KEYCODE_B);
  tolua_constant(tolua_S,"KEYCODE_C",KEYCODE_C);
  tolua_constant(tolua_S,"KEYCODE_D",KEYCODE_D);
  tolua_constant(tolua_S,"KEYCODE_E",KEYCODE_E);
  tolua_constant(tolua_S,"KEYCODE_F",KEYCODE_F);
  tolua_constant(tolua_S,"KEYCODE_G",KEYCODE_G);
  tolua_constant(tolua_S,"KEYCODE_H",KEYCODE_H);
  tolua_constant(tolua_S,"KEYCODE_I",KEYCODE_I);
  tolua_constant(tolua_S,"KEYCODE_J",KEYCODE_J);
  tolua_constant(tolua_S,"KEYCODE_K",KEYCODE_K);
  tolua_constant(tolua_S,"KEYCODE_L",KEYCODE_L);
  tolua_constant(tolua_S,"KEYCODE_M",KEYCODE_M);
  tolua_constant(tolua_S,"KEYCODE_N",KEYCODE_N);
  tolua_constant(tolua_S,"KEYCODE_O",KEYCODE_O);
  tolua_constant(tolua_S,"KEYCODE_P",KEYCODE_P);
  tolua_constant(tolua_S,"KEYCODE_Q",KEYCODE_Q);
  tolua_constant(tolua_S,"KEYCODE_R",KEYCODE_R);
  tolua_constant(tolua_S,"KEYCODE_S",KEYCODE_S);
  tolua_constant(tolua_S,"KEYCODE_T",KEYCODE_T);
  tolua_constant(tolua_S,"KEYCODE_U",KEYCODE_U);
  tolua_constant(tolua_S,"KEYCODE_V",KEYCODE_V);
  tolua_constant(tolua_S,"KEYCODE_W",KEYCODE_W);
  tolua_constant(tolua_S,"KEYCODE_X",KEYCODE_X);
  tolua_constant(tolua_S,"KEYCODE_Y",KEYCODE_Y);
  tolua_constant(tolua_S,"KEYCODE_Z",KEYCODE_Z);
  tolua_constant(tolua_S,"KEYCODE_COMMA",KEYCODE_COMMA);
  tolua_constant(tolua_S,"KEYCODE_PERIOD",KEYCODE_PERIOD);
  tolua_constant(tolua_S,"KEYCODE_ALT_LEFT",KEYCODE_ALT_LEFT);
  tolua_constant(tolua_S,"KEYCODE_ALT_RIGHT",KEYCODE_ALT_RIGHT);
  tolua_constant(tolua_S,"KEYCODE_SHIFT_LEFT",KEYCODE_SHIFT_LEFT);
  tolua_constant(tolua_S,"KEYCODE_SHIFT_RIGHT",KEYCODE_SHIFT_RIGHT);
  tolua_constant(tolua_S,"KEYCODE_TAB",KEYCODE_TAB);
  tolua_constant(tolua_S,"KEYCODE_SPACE",KEYCODE_SPACE);
  tolua_constant(tolua_S,"KEYCODE_SYM",KEYCODE_SYM);
  tolua_constant(tolua_S,"KEYCODE_EXPLORER",KEYCODE_EXPLORER);
  tolua_constant(tolua_S,"KEYCODE_ENVELOPE",KEYCODE_ENVELOPE);
  tolua_constant(tolua_S,"KEYCODE_ENTER",KEYCODE_ENTER);
  tolua_constant(tolua_S,"KEYCODE_DEL",KEYCODE_DEL);
  tolua_constant(tolua_S,"KEYCODE_GRAVE",KEYCODE_GRAVE);
  tolua_constant(tolua_S,"KEYCODE_MINUS",KEYCODE_MINUS);
  tolua_constant(tolua_S,"KEYCODE_EQUALS",KEYCODE_EQUALS);
  tolua_constant(tolua_S,"KEYCODE_LEFT_BRACKET",KEYCODE_LEFT_BRACKET);
  tolua_constant(tolua_S,"KEYCODE_RIGHT_BRACKET",KEYCODE_RIGHT_BRACKET);
  tolua_constant(tolua_S,"KEYCODE_BACKSLASH",KEYCODE_BACKSLASH);
  tolua_constant(tolua_S,"KEYCODE_SEMICOLON",KEYCODE_SEMICOLON);
  tolua_constant(tolua_S,"KEYCODE_APOSTROPHE",KEYCODE_APOSTROPHE);
  tolua_constant(tolua_S,"KEYCODE_SLASH",KEYCODE_SLASH);
  tolua_constant(tolua_S,"KEYCODE_AT",KEYCODE_AT);
  tolua_constant(tolua_S,"KEYCODE_NUM",KEYCODE_NUM);
  tolua_constant(tolua_S,"KEYCODE_HEADSETHOOK",KEYCODE_HEADSETHOOK);
  tolua_constant(tolua_S,"KEYCODE_FOCUS",KEYCODE_FOCUS);
  tolua_constant(tolua_S,"KEYCODE_PLUS",KEYCODE_PLUS);
  tolua_constant(tolua_S,"KEYCODE_MENU",KEYCODE_MENU);
  tolua_constant(tolua_S,"KEYCODE_NOTIFICATION",KEYCODE_NOTIFICATION);
  tolua_constant(tolua_S,"KEYCODE_SEARCH",KEYCODE_SEARCH);
  tolua_constant(tolua_S,"KEYCODE_MEDIA_PLAY_PAUSE",KEYCODE_MEDIA_PLAY_PAUSE);
  tolua_constant(tolua_S,"KEYCODE_MEDIA_STOP",KEYCODE_MEDIA_STOP);
  tolua_constant(tolua_S,"KEYCODE_MEDIA_NEXT",KEYCODE_MEDIA_NEXT);
  tolua_constant(tolua_S,"KEYCODE_MEDIA_PREVIOUS",KEYCODE_MEDIA_PREVIOUS);
  tolua_constant(tolua_S,"KEYCODE_MEDIA_REWIND",KEYCODE_MEDIA_REWIND);
  tolua_constant(tolua_S,"KEYCODE_MEDIA_FAST_FORWARD",KEYCODE_MEDIA_FAST_FORWARD);
  tolua_constant(tolua_S,"KEYCODE_MUTE",KEYCODE_MUTE);
  tolua_constant(tolua_S,"KEYCODE_PAGE_UP",KEYCODE_PAGE_UP);
  tolua_constant(tolua_S,"KEYCODE_PAGE_DOWN",KEYCODE_PAGE_DOWN);
  tolua_constant(tolua_S,"KEYCODE_PICTSYMBOLS",KEYCODE_PICTSYMBOLS);
  tolua_constant(tolua_S,"KEYCODE_SWITCH_CHARSET",KEYCODE_SWITCH_CHARSET);
  tolua_cclass(tolua_S,"wyKeyEvent","wyKeyEvent","",NULL);
  tolua_beginmodule(tolua_S,"wyKeyEvent");
   tolua_variable(tolua_S,"keyCode",tolua_get_wyKeyEvent_keyCode,tolua_set_wyKeyEvent_keyCode);
   tolua_variable(tolua_S,"repeatCount",tolua_get_wyKeyEvent_repeatCount,tolua_set_wyKeyEvent_repeatCount);
   tolua_variable(tolua_S,"eventTime",tolua_get_wyKeyEvent_eventTime,tolua_set_wyKeyEvent_eventTime);
   tolua_variable(tolua_S,"downTime",tolua_get_wyKeyEvent_downTime,tolua_set_wyKeyEvent_downTime);
  tolua_endmodule(tolua_S);
  tolua_constant(tolua_S,"ACTION_MASK",ACTION_MASK);
  tolua_constant(tolua_S,"ACTION_POINTER_ID_MASK",ACTION_POINTER_ID_MASK);
  tolua_constant(tolua_S,"ACTION_POINTER_ID_SHIFT",ACTION_POINTER_ID_SHIFT);
  tolua_cclass(tolua_S,"wyMotionEvent","wyMotionEvent","",NULL);
  tolua_beginmodule(tolua_S,"wyMotionEvent");
   tolua_variable(tolua_S,"pointerCount",tolua_get_wyMotionEvent_pointerCount,tolua_set_wyMotionEvent_pointerCount);
   tolua_array(tolua_S,"pid",tolua_get_types_wyMotionEvent_pid,tolua_set_types_wyMotionEvent_pid);
   tolua_array(tolua_S,"x",tolua_get_types_wyMotionEvent_x,tolua_set_types_wyMotionEvent_x);
   tolua_array(tolua_S,"y",tolua_get_types_wyMotionEvent_y,tolua_set_types_wyMotionEvent_y);
   tolua_variable(tolua_S,"eventTime",tolua_get_wyMotionEvent_eventTime,tolua_set_wyMotionEvent_eventTime);
  tolua_endmodule(tolua_S);
  tolua_variable(tolua_S,"wyvZero",tolua_get_wyvZero,NULL);
  tolua_function(tolua_S,"wyv",tolua_types_wyv00);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_types (lua_State* tolua_S) {
 return tolua_types_open(tolua_S);
};
#endif

