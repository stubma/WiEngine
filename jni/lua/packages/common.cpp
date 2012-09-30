/*
** Lua binding: common
** Generated automatically by tolua++-1.0.92 on Tue Jan  3 14:12:10 2012.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_common_open (lua_State* tolua_S);

#include "WiEngine.h"

/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"wyDevice");
}

/* get function: scaleMode of class  wyDevice */
#ifndef TOLUA_DISABLE_tolua_get_wyDevice_scaleMode
static int tolua_get_wyDevice_scaleMode(lua_State* tolua_S)
{
  tolua_pushnumber(tolua_S,(lua_Number)wyDevice::scaleMode);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: scaleMode of class  wyDevice */
#ifndef TOLUA_DISABLE_tolua_set_wyDevice_scaleMode
static int tolua_set_wyDevice_scaleMode(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  wyDevice::scaleMode = ((wyScaleMode) (int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: density of class  wyDevice */
#ifndef TOLUA_DISABLE_tolua_get_wyDevice_density
static int tolua_get_wyDevice_density(lua_State* tolua_S)
{
  tolua_pushnumber(tolua_S,(lua_Number)wyDevice::density);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: density of class  wyDevice */
#ifndef TOLUA_DISABLE_tolua_set_wyDevice_density
static int tolua_set_wyDevice_density(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  wyDevice::density = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: scaledDensity of class  wyDevice */
#ifndef TOLUA_DISABLE_tolua_get_wyDevice_scaledDensity
static int tolua_get_wyDevice_scaledDensity(lua_State* tolua_S)
{
  tolua_pushnumber(tolua_S,(lua_Number)wyDevice::scaledDensity);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: scaledDensity of class  wyDevice */
#ifndef TOLUA_DISABLE_tolua_set_wyDevice_scaledDensity
static int tolua_set_wyDevice_scaledDensity(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  wyDevice::scaledDensity = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: defaultInDensity of class  wyDevice */
#ifndef TOLUA_DISABLE_tolua_get_wyDevice_defaultInDensity
static int tolua_get_wyDevice_defaultInDensity(lua_State* tolua_S)
{
  tolua_pushnumber(tolua_S,(lua_Number)wyDevice::defaultInDensity);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: defaultInDensity of class  wyDevice */
#ifndef TOLUA_DISABLE_tolua_set_wyDevice_defaultInDensity
static int tolua_set_wyDevice_defaultInDensity(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  wyDevice::defaultInDensity = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: apiLevel of class  wyDevice */
#ifndef TOLUA_DISABLE_tolua_get_wyDevice_apiLevel
static int tolua_get_wyDevice_apiLevel(lua_State* tolua_S)
{
  tolua_pushnumber(tolua_S,(lua_Number)wyDevice::apiLevel);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: apiLevel of class  wyDevice */
#ifndef TOLUA_DISABLE_tolua_set_wyDevice_apiLevel
static int tolua_set_wyDevice_apiLevel(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  wyDevice::apiLevel = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: maxTextureSize of class  wyDevice */
#ifndef TOLUA_DISABLE_tolua_get_wyDevice_maxTextureSize
static int tolua_get_wyDevice_maxTextureSize(lua_State* tolua_S)
{
  tolua_pushnumber(tolua_S,(lua_Number)wyDevice::maxTextureSize);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: maxTextureSize of class  wyDevice */
#ifndef TOLUA_DISABLE_tolua_set_wyDevice_maxTextureSize
static int tolua_set_wyDevice_maxTextureSize(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  wyDevice::maxTextureSize = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: baseWidth of class  wyDevice */
#ifndef TOLUA_DISABLE_tolua_get_wyDevice_baseWidth
static int tolua_get_wyDevice_baseWidth(lua_State* tolua_S)
{
  tolua_pushnumber(tolua_S,(lua_Number)wyDevice::baseWidth);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: baseWidth of class  wyDevice */
#ifndef TOLUA_DISABLE_tolua_set_wyDevice_baseWidth
static int tolua_set_wyDevice_baseWidth(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  wyDevice::baseWidth = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: baseHeight of class  wyDevice */
#ifndef TOLUA_DISABLE_tolua_get_wyDevice_baseHeight
static int tolua_get_wyDevice_baseHeight(lua_State* tolua_S)
{
  tolua_pushnumber(tolua_S,(lua_Number)wyDevice::baseHeight);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: baseHeight of class  wyDevice */
#ifndef TOLUA_DISABLE_tolua_set_wyDevice_baseHeight
static int tolua_set_wyDevice_baseHeight(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  wyDevice::baseHeight = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: baseScaleX of class  wyDevice */
#ifndef TOLUA_DISABLE_tolua_get_wyDevice_baseScaleX
static int tolua_get_wyDevice_baseScaleX(lua_State* tolua_S)
{
  tolua_pushnumber(tolua_S,(lua_Number)wyDevice::baseScaleX);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: baseScaleX of class  wyDevice */
#ifndef TOLUA_DISABLE_tolua_set_wyDevice_baseScaleX
static int tolua_set_wyDevice_baseScaleX(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  wyDevice::baseScaleX = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: baseScaleY of class  wyDevice */
#ifndef TOLUA_DISABLE_tolua_get_wyDevice_baseScaleY
static int tolua_get_wyDevice_baseScaleY(lua_State* tolua_S)
{
  tolua_pushnumber(tolua_S,(lua_Number)wyDevice::baseScaleY);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: baseScaleY of class  wyDevice */
#ifndef TOLUA_DISABLE_tolua_set_wyDevice_baseScaleY
static int tolua_set_wyDevice_baseScaleY(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  wyDevice::baseScaleY = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: winWidth of class  wyDevice */
#ifndef TOLUA_DISABLE_tolua_get_wyDevice_winWidth
static int tolua_get_wyDevice_winWidth(lua_State* tolua_S)
{
  tolua_pushnumber(tolua_S,(lua_Number)wyDevice::winWidth);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: winWidth of class  wyDevice */
#ifndef TOLUA_DISABLE_tolua_set_wyDevice_winWidth
static int tolua_set_wyDevice_winWidth(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  wyDevice::winWidth = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: winHeight of class  wyDevice */
#ifndef TOLUA_DISABLE_tolua_get_wyDevice_winHeight
static int tolua_get_wyDevice_winHeight(lua_State* tolua_S)
{
  tolua_pushnumber(tolua_S,(lua_Number)wyDevice::winHeight);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: winHeight of class  wyDevice */
#ifndef TOLUA_DISABLE_tolua_set_wyDevice_winHeight
static int tolua_set_wyDevice_winHeight(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  wyDevice::winHeight = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: realWidth of class  wyDevice */
#ifndef TOLUA_DISABLE_tolua_get_wyDevice_realWidth
static int tolua_get_wyDevice_realWidth(lua_State* tolua_S)
{
  tolua_pushnumber(tolua_S,(lua_Number)wyDevice::realWidth);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: realWidth of class  wyDevice */
#ifndef TOLUA_DISABLE_tolua_set_wyDevice_realWidth
static int tolua_set_wyDevice_realWidth(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  wyDevice::realWidth = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: realHeight of class  wyDevice */
#ifndef TOLUA_DISABLE_tolua_get_wyDevice_realHeight
static int tolua_get_wyDevice_realHeight(lua_State* tolua_S)
{
  tolua_pushnumber(tolua_S,(lua_Number)wyDevice::realHeight);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: realHeight of class  wyDevice */
#ifndef TOLUA_DISABLE_tolua_set_wyDevice_realHeight
static int tolua_set_wyDevice_realHeight(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  wyDevice::realHeight = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: getLanguage of class  wyDevice */
#ifndef TOLUA_DISABLE_tolua_common_wyDevice_getLanguage00
static int tolua_common_wyDevice_getLanguage00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyDevice",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   const char* tolua_ret = (const char*)  wyDevice::getLanguage();
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getLanguage'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getCountry of class  wyDevice */
#ifndef TOLUA_DISABLE_tolua_common_wyDevice_getCountry00
static int tolua_common_wyDevice_getCountry00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyDevice",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   const char* tolua_ret = (const char*)  wyDevice::getCountry();
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getCountry'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getDeviceId of class  wyDevice */
#ifndef TOLUA_DISABLE_tolua_common_wyDevice_getDeviceId00
static int tolua_common_wyDevice_getDeviceId00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyDevice",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   const char* tolua_ret = (const char*)  wyDevice::getDeviceId();
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getDeviceId'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_common_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  tolua_constant(tolua_S,"DENSITY_LDPI",DENSITY_LDPI);
  tolua_constant(tolua_S,"DENSITY_MDPI",DENSITY_MDPI);
  tolua_constant(tolua_S,"DENSITY_HDPI",DENSITY_HDPI);
  tolua_constant(tolua_S,"SCALE_MODE_BY_DENSITY",SCALE_MODE_BY_DENSITY);
  tolua_constant(tolua_S,"SCALE_MODE_BASE_SIZE_FIT_XY",SCALE_MODE_BASE_SIZE_FIT_XY);
  tolua_cclass(tolua_S,"wyDevice","wyDevice","",NULL);
  tolua_beginmodule(tolua_S,"wyDevice");
   tolua_variable(tolua_S,"scaleMode",tolua_get_wyDevice_scaleMode,tolua_set_wyDevice_scaleMode);
   tolua_variable(tolua_S,"density",tolua_get_wyDevice_density,tolua_set_wyDevice_density);
   tolua_variable(tolua_S,"scaledDensity",tolua_get_wyDevice_scaledDensity,tolua_set_wyDevice_scaledDensity);
   tolua_variable(tolua_S,"defaultInDensity",tolua_get_wyDevice_defaultInDensity,tolua_set_wyDevice_defaultInDensity);
   tolua_variable(tolua_S,"apiLevel",tolua_get_wyDevice_apiLevel,tolua_set_wyDevice_apiLevel);
   tolua_variable(tolua_S,"maxTextureSize",tolua_get_wyDevice_maxTextureSize,tolua_set_wyDevice_maxTextureSize);
   tolua_variable(tolua_S,"baseWidth",tolua_get_wyDevice_baseWidth,tolua_set_wyDevice_baseWidth);
   tolua_variable(tolua_S,"baseHeight",tolua_get_wyDevice_baseHeight,tolua_set_wyDevice_baseHeight);
   tolua_variable(tolua_S,"baseScaleX",tolua_get_wyDevice_baseScaleX,tolua_set_wyDevice_baseScaleX);
   tolua_variable(tolua_S,"baseScaleY",tolua_get_wyDevice_baseScaleY,tolua_set_wyDevice_baseScaleY);
   tolua_variable(tolua_S,"winWidth",tolua_get_wyDevice_winWidth,tolua_set_wyDevice_winWidth);
   tolua_variable(tolua_S,"winHeight",tolua_get_wyDevice_winHeight,tolua_set_wyDevice_winHeight);
   tolua_variable(tolua_S,"realWidth",tolua_get_wyDevice_realWidth,tolua_set_wyDevice_realWidth);
   tolua_variable(tolua_S,"realHeight",tolua_get_wyDevice_realHeight,tolua_set_wyDevice_realHeight);
   tolua_function(tolua_S,"getLanguage",tolua_common_wyDevice_getLanguage00);
   tolua_function(tolua_S,"getCountry",tolua_common_wyDevice_getCountry00);
   tolua_function(tolua_S,"getDeviceId",tolua_common_wyDevice_getDeviceId00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_common (lua_State* tolua_S) {
 return tolua_common_open(tolua_S);
};
#endif

