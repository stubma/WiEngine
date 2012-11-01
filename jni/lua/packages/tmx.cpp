/*
** Lua binding: tmx
** Generated automatically by tolua++-1.0.92 on Wed Oct 17 11:05:02 2012.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_tmx_open (lua_State* tolua_S);

#include "WiEngine.h"

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_wyPoint (lua_State* tolua_S)
{
 wyPoint* self = (wyPoint*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyTMXLayer (lua_State* tolua_S)
{
 wyTMXLayer* self = (wyTMXLayer*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyTMXObjectGroup (lua_State* tolua_S)
{
 wyTMXObjectGroup* self = (wyTMXObjectGroup*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyDimension (lua_State* tolua_S)
{
 wyDimension* self = (wyDimension*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyRect (lua_State* tolua_S)
{
 wyRect* self = (wyRect*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyTMXObject (lua_State* tolua_S)
{
 wyTMXObject* self = (wyTMXObject*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyTMXTileMap (lua_State* tolua_S)
{
 wyTMXTileMap* self = (wyTMXTileMap*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"wyTileSetInfo");
 tolua_usertype(tolua_S,"wyTMXObjectGroup");
 tolua_usertype(tolua_S,"wySpriteBatchNode");
 tolua_usertype(tolua_S,"wyPointList");
 tolua_usertype(tolua_S,"wyPoint");
 tolua_usertype(tolua_S,"wyLayerInfo");
 tolua_usertype(tolua_S,"wyArray");
 tolua_usertype(tolua_S,"wyRect");
 tolua_usertype(tolua_S,"wyTMXLoader");
 tolua_usertype(tolua_S,"wyMapInfo");
 tolua_usertype(tolua_S,"wyTMXObject");
 tolua_usertype(tolua_S,"wyTileHash");
 tolua_usertype(tolua_S,"wyTMXTileMap");
 tolua_usertype(tolua_S,"wySpriteEx");
 tolua_usertype(tolua_S,"wyHashSet");
 tolua_usertype(tolua_S,"wyDimension");
 tolua_usertype(tolua_S,"wyNode");
 tolua_usertype(tolua_S,"wyTMXLayer");
 tolua_usertype(tolua_S,"wyTexture2D");
 tolua_usertype(tolua_S,"wyObject");
}

/* method: delete of class  wyTMXObject */
#ifndef TOLUA_DISABLE_tolua_tmx_wyTMXObject_delete00
static int tolua_tmx_wyTMXObject_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTMXObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTMXObject* self = (wyTMXObject*)  tolua_tousertype(tolua_S,1,0);
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

/* method: make of class  wyTMXObject */
#ifndef TOLUA_DISABLE_tolua_tmx_wyTMXObject_make00
static int tolua_tmx_wyTMXObject_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyTMXObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   wyTMXObject* tolua_ret = (wyTMXObject*)  wyTMXObject::make();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyTMXObject");
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

/* method: getProperty of class  wyTMXObject */
#ifndef TOLUA_DISABLE_tolua_tmx_wyTMXObject_getProperty00
static int tolua_tmx_wyTMXObject_getProperty00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTMXObject",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTMXObject* self = (wyTMXObject*)  tolua_tousertype(tolua_S,1,0);
  const char* key = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getProperty'", NULL);
#endif
  {
   const char* tolua_ret = (const char*)  self->getProperty(key);
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getProperty'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: addProperty of class  wyTMXObject */
#ifndef TOLUA_DISABLE_tolua_tmx_wyTMXObject_addProperty00
static int tolua_tmx_wyTMXObject_addProperty00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTMXObject",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTMXObject* self = (wyTMXObject*)  tolua_tousertype(tolua_S,1,0);
  const char* key = ((const char*)  tolua_tostring(tolua_S,2,0));
  const char* value = ((const char*)  tolua_tostring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addProperty'", NULL);
#endif
  {
   self->addProperty(key,value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addProperty'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getType of class  wyTMXObject */
#ifndef TOLUA_DISABLE_tolua_tmx_wyTMXObject_getType00
static int tolua_tmx_wyTMXObject_getType00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTMXObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTMXObject* self = (wyTMXObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getType'", NULL);
#endif
  {
   wyTMXObject::Type tolua_ret = (wyTMXObject::Type)  self->getType();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getType'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getPoints of class  wyTMXObject */
#ifndef TOLUA_DISABLE_tolua_tmx_wyTMXObject_getPoints00
static int tolua_tmx_wyTMXObject_getPoints00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTMXObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTMXObject* self = (wyTMXObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getPoints'", NULL);
#endif
  {
   wyPointList& tolua_ret = (wyPointList&)  self->getPoints();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"wyPointList");
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

/* get function: name of class  wyLayerInfo */
#ifndef TOLUA_DISABLE_tolua_get_wyLayerInfo_name
static int tolua_get_wyLayerInfo_name(lua_State* tolua_S)
{
  wyLayerInfo* self = (wyLayerInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'name'",NULL);
#endif
  tolua_pushstring(tolua_S,(const char*)self->name);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: name of class  wyLayerInfo */
#ifndef TOLUA_DISABLE_tolua_set_wyLayerInfo_name
static int tolua_set_wyLayerInfo_name(lua_State* tolua_S)
{
  wyLayerInfo* self = (wyLayerInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'name'",NULL);
  if (!tolua_isstring(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->name = ((char*)  tolua_tostring(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: layerWidth of class  wyLayerInfo */
#ifndef TOLUA_DISABLE_tolua_get_wyLayerInfo_layerWidth
static int tolua_get_wyLayerInfo_layerWidth(lua_State* tolua_S)
{
  wyLayerInfo* self = (wyLayerInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'layerWidth'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->layerWidth);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: layerWidth of class  wyLayerInfo */
#ifndef TOLUA_DISABLE_tolua_set_wyLayerInfo_layerWidth
static int tolua_set_wyLayerInfo_layerWidth(lua_State* tolua_S)
{
  wyLayerInfo* self = (wyLayerInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'layerWidth'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->layerWidth = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: layerHeight of class  wyLayerInfo */
#ifndef TOLUA_DISABLE_tolua_get_wyLayerInfo_layerHeight
static int tolua_get_wyLayerInfo_layerHeight(lua_State* tolua_S)
{
  wyLayerInfo* self = (wyLayerInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'layerHeight'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->layerHeight);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: layerHeight of class  wyLayerInfo */
#ifndef TOLUA_DISABLE_tolua_set_wyLayerInfo_layerHeight
static int tolua_set_wyLayerInfo_layerHeight(lua_State* tolua_S)
{
  wyLayerInfo* self = (wyLayerInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'layerHeight'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->layerHeight = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: tiles of class  wyLayerInfo */
#ifndef TOLUA_DISABLE_tolua_get_wyLayerInfo_tiles
static int tolua_get_wyLayerInfo_tiles(lua_State* tolua_S)
{
  wyLayerInfo* self = (wyLayerInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'tiles'",NULL);
#endif
  tolua_pushuserdata(tolua_S,(void*)self->tiles);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: tiles of class  wyLayerInfo */
#ifndef TOLUA_DISABLE_tolua_set_wyLayerInfo_tiles
static int tolua_set_wyLayerInfo_tiles(lua_State* tolua_S)
{
  wyLayerInfo* self = (wyLayerInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'tiles'",NULL);
  if (!tolua_isuserdata(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->tiles = ((int*)  tolua_touserdata(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: visible of class  wyLayerInfo */
#ifndef TOLUA_DISABLE_tolua_get_wyLayerInfo_visible
static int tolua_get_wyLayerInfo_visible(lua_State* tolua_S)
{
  wyLayerInfo* self = (wyLayerInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'visible'",NULL);
#endif
  tolua_pushboolean(tolua_S,(bool)self->visible);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: visible of class  wyLayerInfo */
#ifndef TOLUA_DISABLE_tolua_set_wyLayerInfo_visible
static int tolua_set_wyLayerInfo_visible(lua_State* tolua_S)
{
  wyLayerInfo* self = (wyLayerInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'visible'",NULL);
  if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->visible = ((bool)  tolua_toboolean(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: alpha of class  wyLayerInfo */
#ifndef TOLUA_DISABLE_tolua_get_wyLayerInfo_alpha
static int tolua_get_wyLayerInfo_alpha(lua_State* tolua_S)
{
  wyLayerInfo* self = (wyLayerInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'alpha'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->alpha);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: alpha of class  wyLayerInfo */
#ifndef TOLUA_DISABLE_tolua_set_wyLayerInfo_alpha
static int tolua_set_wyLayerInfo_alpha(lua_State* tolua_S)
{
  wyLayerInfo* self = (wyLayerInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'alpha'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->alpha = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: minGid of class  wyLayerInfo */
#ifndef TOLUA_DISABLE_tolua_get_wyLayerInfo_minGid
static int tolua_get_wyLayerInfo_minGid(lua_State* tolua_S)
{
  wyLayerInfo* self = (wyLayerInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'minGid'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->minGid);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: minGid of class  wyLayerInfo */
#ifndef TOLUA_DISABLE_tolua_set_wyLayerInfo_minGid
static int tolua_set_wyLayerInfo_minGid(lua_State* tolua_S)
{
  wyLayerInfo* self = (wyLayerInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'minGid'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->minGid = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: maxGid of class  wyLayerInfo */
#ifndef TOLUA_DISABLE_tolua_get_wyLayerInfo_maxGid
static int tolua_get_wyLayerInfo_maxGid(lua_State* tolua_S)
{
  wyLayerInfo* self = (wyLayerInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'maxGid'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->maxGid);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: maxGid of class  wyLayerInfo */
#ifndef TOLUA_DISABLE_tolua_set_wyLayerInfo_maxGid
static int tolua_set_wyLayerInfo_maxGid(lua_State* tolua_S)
{
  wyLayerInfo* self = (wyLayerInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'maxGid'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->maxGid = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: properties of class  wyLayerInfo */
#ifndef TOLUA_DISABLE_tolua_get_wyLayerInfo_properties_ptr
static int tolua_get_wyLayerInfo_properties_ptr(lua_State* tolua_S)
{
  wyLayerInfo* self = (wyLayerInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'properties'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->properties,"wyHashSet");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: properties of class  wyLayerInfo */
#ifndef TOLUA_DISABLE_tolua_set_wyLayerInfo_properties_ptr
static int tolua_set_wyLayerInfo_properties_ptr(lua_State* tolua_S)
{
  wyLayerInfo* self = (wyLayerInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'properties'",NULL);
  if (!tolua_isusertype(tolua_S,2,"wyHashSet",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->properties = ((wyHashSet*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: offsetX of class  wyLayerInfo */
#ifndef TOLUA_DISABLE_tolua_get_wyLayerInfo_offsetX
static int tolua_get_wyLayerInfo_offsetX(lua_State* tolua_S)
{
  wyLayerInfo* self = (wyLayerInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'offsetX'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->offsetX);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: offsetX of class  wyLayerInfo */
#ifndef TOLUA_DISABLE_tolua_set_wyLayerInfo_offsetX
static int tolua_set_wyLayerInfo_offsetX(lua_State* tolua_S)
{
  wyLayerInfo* self = (wyLayerInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'offsetX'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->offsetX = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: offsetY of class  wyLayerInfo */
#ifndef TOLUA_DISABLE_tolua_get_wyLayerInfo_offsetY
static int tolua_get_wyLayerInfo_offsetY(lua_State* tolua_S)
{
  wyLayerInfo* self = (wyLayerInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'offsetY'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->offsetY);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: offsetY of class  wyLayerInfo */
#ifndef TOLUA_DISABLE_tolua_set_wyLayerInfo_offsetY
static int tolua_set_wyLayerInfo_offsetY(lua_State* tolua_S)
{
  wyLayerInfo* self = (wyLayerInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'offsetY'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->offsetY = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* function: wyLayerInfoNew */
#ifndef TOLUA_DISABLE_tolua_tmx_wyLayerInfoNew00
static int tolua_tmx_wyLayerInfoNew00(lua_State* tolua_S)
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
   wyLayerInfo* tolua_ret = (wyLayerInfo*)  wyLayerInfoNew();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyLayerInfo");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'wyLayerInfoNew'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: wyLayerInfoDestroy */
#ifndef TOLUA_DISABLE_tolua_tmx_wyLayerInfoDestroy00
static int tolua_tmx_wyLayerInfoDestroy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyLayerInfo",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyLayerInfo* info = ((wyLayerInfo*)  tolua_tousertype(tolua_S,1,0));
  {
   wyLayerInfoDestroy(info);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'wyLayerInfoDestroy'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: wyLayerInfoAddProperty */
#ifndef TOLUA_DISABLE_tolua_tmx_wyLayerInfoAddProperty00
static int tolua_tmx_wyLayerInfoAddProperty00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyLayerInfo",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyLayerInfo* info = ((wyLayerInfo*)  tolua_tousertype(tolua_S,1,0));
  const char* key = ((const char*)  tolua_tostring(tolua_S,2,0));
  const char* value = ((const char*)  tolua_tostring(tolua_S,3,0));
  {
   wyLayerInfoAddProperty(info,key,value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'wyLayerInfoAddProperty'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: wyLayerInfoGetProperty */
#ifndef TOLUA_DISABLE_tolua_tmx_wyLayerInfoGetProperty00
static int tolua_tmx_wyLayerInfoGetProperty00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyLayerInfo",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyLayerInfo* info = ((wyLayerInfo*)  tolua_tousertype(tolua_S,1,0));
  const char* name = ((const char*)  tolua_tostring(tolua_S,2,0));
  {
   char* tolua_ret = (char*)  wyLayerInfoGetProperty(info,name);
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'wyLayerInfoGetProperty'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: gid of class  wyTileHash */
#ifndef TOLUA_DISABLE_tolua_get_wyTileHash_gid
static int tolua_get_wyTileHash_gid(lua_State* tolua_S)
{
  wyTileHash* self = (wyTileHash*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'gid'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->gid);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: gid of class  wyTileHash */
#ifndef TOLUA_DISABLE_tolua_set_wyTileHash_gid
static int tolua_set_wyTileHash_gid(lua_State* tolua_S)
{
  wyTileHash* self = (wyTileHash*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'gid'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->gid = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: properties of class  wyTileHash */
#ifndef TOLUA_DISABLE_tolua_get_wyTileHash_properties_ptr
static int tolua_get_wyTileHash_properties_ptr(lua_State* tolua_S)
{
  wyTileHash* self = (wyTileHash*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'properties'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->properties,"wyHashSet");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: properties of class  wyTileHash */
#ifndef TOLUA_DISABLE_tolua_set_wyTileHash_properties_ptr
static int tolua_set_wyTileHash_properties_ptr(lua_State* tolua_S)
{
  wyTileHash* self = (wyTileHash*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'properties'",NULL);
  if (!tolua_isusertype(tolua_S,2,"wyHashSet",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->properties = ((wyHashSet*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: filename of class  wyMapInfo */
#ifndef TOLUA_DISABLE_tolua_get_wyMapInfo_filename
static int tolua_get_wyMapInfo_filename(lua_State* tolua_S)
{
  wyMapInfo* self = (wyMapInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'filename'",NULL);
#endif
  tolua_pushstring(tolua_S,(const char*)self->filename);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: filename of class  wyMapInfo */
#ifndef TOLUA_DISABLE_tolua_set_wyMapInfo_filename
static int tolua_set_wyMapInfo_filename(lua_State* tolua_S)
{
  wyMapInfo* self = (wyMapInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'filename'",NULL);
  if (!tolua_isstring(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->filename = ((char*)  tolua_tostring(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: orientation of class  wyMapInfo */
#ifndef TOLUA_DISABLE_tolua_get_wyMapInfo_orientation
static int tolua_get_wyMapInfo_orientation(lua_State* tolua_S)
{
  wyMapInfo* self = (wyMapInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'orientation'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->orientation);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: orientation of class  wyMapInfo */
#ifndef TOLUA_DISABLE_tolua_set_wyMapInfo_orientation
static int tolua_set_wyMapInfo_orientation(lua_State* tolua_S)
{
  wyMapInfo* self = (wyMapInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'orientation'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->orientation = ((wyTMXOrientation) (int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: mapWidth of class  wyMapInfo */
#ifndef TOLUA_DISABLE_tolua_get_wyMapInfo_mapWidth
static int tolua_get_wyMapInfo_mapWidth(lua_State* tolua_S)
{
  wyMapInfo* self = (wyMapInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mapWidth'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->mapWidth);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: mapWidth of class  wyMapInfo */
#ifndef TOLUA_DISABLE_tolua_set_wyMapInfo_mapWidth
static int tolua_set_wyMapInfo_mapWidth(lua_State* tolua_S)
{
  wyMapInfo* self = (wyMapInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mapWidth'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->mapWidth = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: mapHeight of class  wyMapInfo */
#ifndef TOLUA_DISABLE_tolua_get_wyMapInfo_mapHeight
static int tolua_get_wyMapInfo_mapHeight(lua_State* tolua_S)
{
  wyMapInfo* self = (wyMapInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mapHeight'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->mapHeight);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: mapHeight of class  wyMapInfo */
#ifndef TOLUA_DISABLE_tolua_set_wyMapInfo_mapHeight
static int tolua_set_wyMapInfo_mapHeight(lua_State* tolua_S)
{
  wyMapInfo* self = (wyMapInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mapHeight'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->mapHeight = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: tileWidth of class  wyMapInfo */
#ifndef TOLUA_DISABLE_tolua_get_wyMapInfo_tileWidth
static int tolua_get_wyMapInfo_tileWidth(lua_State* tolua_S)
{
  wyMapInfo* self = (wyMapInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'tileWidth'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->tileWidth);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: tileWidth of class  wyMapInfo */
#ifndef TOLUA_DISABLE_tolua_set_wyMapInfo_tileWidth
static int tolua_set_wyMapInfo_tileWidth(lua_State* tolua_S)
{
  wyMapInfo* self = (wyMapInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'tileWidth'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->tileWidth = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: tileHeight of class  wyMapInfo */
#ifndef TOLUA_DISABLE_tolua_get_wyMapInfo_tileHeight
static int tolua_get_wyMapInfo_tileHeight(lua_State* tolua_S)
{
  wyMapInfo* self = (wyMapInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'tileHeight'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->tileHeight);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: tileHeight of class  wyMapInfo */
#ifndef TOLUA_DISABLE_tolua_set_wyMapInfo_tileHeight
static int tolua_set_wyMapInfo_tileHeight(lua_State* tolua_S)
{
  wyMapInfo* self = (wyMapInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'tileHeight'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->tileHeight = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: layers of class  wyMapInfo */
#ifndef TOLUA_DISABLE_tolua_get_wyMapInfo_layers_ptr
static int tolua_get_wyMapInfo_layers_ptr(lua_State* tolua_S)
{
  wyMapInfo* self = (wyMapInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'layers'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->layers,"wyArray");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: layers of class  wyMapInfo */
#ifndef TOLUA_DISABLE_tolua_set_wyMapInfo_layers_ptr
static int tolua_set_wyMapInfo_layers_ptr(lua_State* tolua_S)
{
  wyMapInfo* self = (wyMapInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'layers'",NULL);
  if (!tolua_isusertype(tolua_S,2,"wyArray",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->layers = ((wyArray*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: tilesets of class  wyMapInfo */
#ifndef TOLUA_DISABLE_tolua_get_wyMapInfo_tilesets_ptr
static int tolua_get_wyMapInfo_tilesets_ptr(lua_State* tolua_S)
{
  wyMapInfo* self = (wyMapInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'tilesets'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->tilesets,"wyArray");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: tilesets of class  wyMapInfo */
#ifndef TOLUA_DISABLE_tolua_set_wyMapInfo_tilesets_ptr
static int tolua_set_wyMapInfo_tilesets_ptr(lua_State* tolua_S)
{
  wyMapInfo* self = (wyMapInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'tilesets'",NULL);
  if (!tolua_isusertype(tolua_S,2,"wyArray",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->tilesets = ((wyArray*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: objectGroups of class  wyMapInfo */
#ifndef TOLUA_DISABLE_tolua_get_wyMapInfo_objectGroups_ptr
static int tolua_get_wyMapInfo_objectGroups_ptr(lua_State* tolua_S)
{
  wyMapInfo* self = (wyMapInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'objectGroups'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->objectGroups,"wyArray");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: objectGroups of class  wyMapInfo */
#ifndef TOLUA_DISABLE_tolua_set_wyMapInfo_objectGroups_ptr
static int tolua_set_wyMapInfo_objectGroups_ptr(lua_State* tolua_S)
{
  wyMapInfo* self = (wyMapInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'objectGroups'",NULL);
  if (!tolua_isusertype(tolua_S,2,"wyArray",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->objectGroups = ((wyArray*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: properties of class  wyMapInfo */
#ifndef TOLUA_DISABLE_tolua_get_wyMapInfo_properties_ptr
static int tolua_get_wyMapInfo_properties_ptr(lua_State* tolua_S)
{
  wyMapInfo* self = (wyMapInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'properties'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->properties,"wyHashSet");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: properties of class  wyMapInfo */
#ifndef TOLUA_DISABLE_tolua_set_wyMapInfo_properties_ptr
static int tolua_set_wyMapInfo_properties_ptr(lua_State* tolua_S)
{
  wyMapInfo* self = (wyMapInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'properties'",NULL);
  if (!tolua_isusertype(tolua_S,2,"wyHashSet",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->properties = ((wyHashSet*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: tileProperties of class  wyMapInfo */
#ifndef TOLUA_DISABLE_tolua_get_wyMapInfo_tileProperties_ptr
static int tolua_get_wyMapInfo_tileProperties_ptr(lua_State* tolua_S)
{
  wyMapInfo* self = (wyMapInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'tileProperties'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->tileProperties,"wyHashSet");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: tileProperties of class  wyMapInfo */
#ifndef TOLUA_DISABLE_tolua_set_wyMapInfo_tileProperties_ptr
static int tolua_set_wyMapInfo_tileProperties_ptr(lua_State* tolua_S)
{
  wyMapInfo* self = (wyMapInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'tileProperties'",NULL);
  if (!tolua_isusertype(tolua_S,2,"wyHashSet",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->tileProperties = ((wyHashSet*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* function: wyMapInfoNew */
#ifndef TOLUA_DISABLE_tolua_tmx_wyMapInfoNew00
static int tolua_tmx_wyMapInfoNew00(lua_State* tolua_S)
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
   wyMapInfo* tolua_ret = (wyMapInfo*)  wyMapInfoNew();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyMapInfo");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'wyMapInfoNew'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: wyMapInfoDestroy */
#ifndef TOLUA_DISABLE_tolua_tmx_wyMapInfoDestroy00
static int tolua_tmx_wyMapInfoDestroy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyMapInfo",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyMapInfo* info = ((wyMapInfo*)  tolua_tousertype(tolua_S,1,0));
  {
   wyMapInfoDestroy(info);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'wyMapInfoDestroy'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: wyMapInfoAddProperty */
#ifndef TOLUA_DISABLE_tolua_tmx_wyMapInfoAddProperty00
static int tolua_tmx_wyMapInfoAddProperty00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyMapInfo",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyMapInfo* info = ((wyMapInfo*)  tolua_tousertype(tolua_S,1,0));
  const char* key = ((const char*)  tolua_tostring(tolua_S,2,0));
  const char* value = ((const char*)  tolua_tostring(tolua_S,3,0));
  {
   wyMapInfoAddProperty(info,key,value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'wyMapInfoAddProperty'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: wyMapInfoGetProperty */
#ifndef TOLUA_DISABLE_tolua_tmx_wyMapInfoGetProperty00
static int tolua_tmx_wyMapInfoGetProperty00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyMapInfo",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyMapInfo* info = ((wyMapInfo*)  tolua_tousertype(tolua_S,1,0));
  const char* name = ((const char*)  tolua_tostring(tolua_S,2,0));
  {
   char* tolua_ret = (char*)  wyMapInfoGetProperty(info,name);
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'wyMapInfoGetProperty'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: wyMapInfoNewTileProperties */
#ifndef TOLUA_DISABLE_tolua_tmx_wyMapInfoNewTileProperties00
static int tolua_tmx_wyMapInfoNewTileProperties00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyMapInfo",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyMapInfo* info = ((wyMapInfo*)  tolua_tousertype(tolua_S,1,0));
  int gid = ((int)  tolua_tonumber(tolua_S,2,0));
  {
   wyMapInfoNewTileProperties(info,gid);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'wyMapInfoNewTileProperties'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: wyMapInfoGetTileProperty */
#ifndef TOLUA_DISABLE_tolua_tmx_wyMapInfoGetTileProperty00
static int tolua_tmx_wyMapInfoGetTileProperty00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyMapInfo",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyMapInfo* info = ((wyMapInfo*)  tolua_tousertype(tolua_S,1,0));
  int gid = ((int)  tolua_tonumber(tolua_S,2,0));
  const char* key = ((const char*)  tolua_tostring(tolua_S,3,0));
  {
   char* tolua_ret = (char*)  wyMapInfoGetTileProperty(info,gid,key);
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'wyMapInfoGetTileProperty'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: wyMapInfoAddTileProperty */
#ifndef TOLUA_DISABLE_tolua_tmx_wyMapInfoAddTileProperty00
static int tolua_tmx_wyMapInfoAddTileProperty00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyMapInfo",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isstring(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyMapInfo* info = ((wyMapInfo*)  tolua_tousertype(tolua_S,1,0));
  int gid = ((int)  tolua_tonumber(tolua_S,2,0));
  const char* key = ((const char*)  tolua_tostring(tolua_S,3,0));
  const char* value = ((const char*)  tolua_tostring(tolua_S,4,0));
  {
   wyMapInfoAddTileProperty(info,gid,key,value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'wyMapInfoAddTileProperty'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  wyTMXObjectGroup */
#ifndef TOLUA_DISABLE_tolua_tmx_wyTMXObjectGroup_delete00
static int tolua_tmx_wyTMXObjectGroup_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTMXObjectGroup",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTMXObjectGroup* self = (wyTMXObjectGroup*)  tolua_tousertype(tolua_S,1,0);
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

/* method: make of class  wyTMXObjectGroup */
#ifndef TOLUA_DISABLE_tolua_tmx_wyTMXObjectGroup_make00
static int tolua_tmx_wyTMXObjectGroup_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyTMXObjectGroup",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   wyTMXObjectGroup* tolua_ret = (wyTMXObjectGroup*)  wyTMXObjectGroup::make();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyTMXObjectGroup");
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

/* method: addProperty of class  wyTMXObjectGroup */
#ifndef TOLUA_DISABLE_tolua_tmx_wyTMXObjectGroup_addProperty00
static int tolua_tmx_wyTMXObjectGroup_addProperty00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTMXObjectGroup",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTMXObjectGroup* self = (wyTMXObjectGroup*)  tolua_tousertype(tolua_S,1,0);
  const char* key = ((const char*)  tolua_tostring(tolua_S,2,0));
  const char* value = ((const char*)  tolua_tostring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addProperty'", NULL);
#endif
  {
   self->addProperty(key,value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addProperty'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getProperty of class  wyTMXObjectGroup */
#ifndef TOLUA_DISABLE_tolua_tmx_wyTMXObjectGroup_getProperty00
static int tolua_tmx_wyTMXObjectGroup_getProperty00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTMXObjectGroup",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTMXObjectGroup* self = (wyTMXObjectGroup*)  tolua_tousertype(tolua_S,1,0);
  const char* name = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getProperty'", NULL);
#endif
  {
   char* tolua_ret = (char*)  self->getProperty(name);
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getProperty'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: newObject of class  wyTMXObjectGroup */
#ifndef TOLUA_DISABLE_tolua_tmx_wyTMXObjectGroup_newObject00
static int tolua_tmx_wyTMXObjectGroup_newObject00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTMXObjectGroup",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTMXObjectGroup* self = (wyTMXObjectGroup*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'newObject'", NULL);
#endif
  {
   wyTMXObject* tolua_ret = (wyTMXObject*)  self->newObject();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyTMXObject");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'newObject'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getObject of class  wyTMXObjectGroup */
#ifndef TOLUA_DISABLE_tolua_tmx_wyTMXObjectGroup_getObject00
static int tolua_tmx_wyTMXObjectGroup_getObject00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTMXObjectGroup",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTMXObjectGroup* self = (wyTMXObjectGroup*)  tolua_tousertype(tolua_S,1,0);
  const char* name = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getObject'", NULL);
#endif
  {
   wyTMXObject* tolua_ret = (wyTMXObject*)  self->getObject(name);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyTMXObject");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getObject'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getObjectAt of class  wyTMXObjectGroup */
#ifndef TOLUA_DISABLE_tolua_tmx_wyTMXObjectGroup_getObjectAt00
static int tolua_tmx_wyTMXObjectGroup_getObjectAt00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTMXObjectGroup",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTMXObjectGroup* self = (wyTMXObjectGroup*)  tolua_tousertype(tolua_S,1,0);
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getObjectAt'", NULL);
#endif
  {
   wyTMXObject* tolua_ret = (wyTMXObject*)  self->getObjectAt(index);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyTMXObject");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getObjectAt'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getObjectCount of class  wyTMXObjectGroup */
#ifndef TOLUA_DISABLE_tolua_tmx_wyTMXObjectGroup_getObjectCount00
static int tolua_tmx_wyTMXObjectGroup_getObjectCount00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTMXObjectGroup",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTMXObjectGroup* self = (wyTMXObjectGroup*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getObjectCount'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getObjectCount();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getObjectCount'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: addObjectProperty of class  wyTMXObjectGroup */
#ifndef TOLUA_DISABLE_tolua_tmx_wyTMXObjectGroup_addObjectProperty00
static int tolua_tmx_wyTMXObjectGroup_addObjectProperty00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTMXObjectGroup",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyTMXObject",0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isstring(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTMXObjectGroup* self = (wyTMXObjectGroup*)  tolua_tousertype(tolua_S,1,0);
  wyTMXObject* object = ((wyTMXObject*)  tolua_tousertype(tolua_S,2,0));
  const char* key = ((const char*)  tolua_tostring(tolua_S,3,0));
  const char* value = ((const char*)  tolua_tostring(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addObjectProperty'", NULL);
#endif
  {
   self->addObjectProperty(object,key,value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addObjectProperty'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getObjectProperty of class  wyTMXObjectGroup */
#ifndef TOLUA_DISABLE_tolua_tmx_wyTMXObjectGroup_getObjectProperty00
static int tolua_tmx_wyTMXObjectGroup_getObjectProperty00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTMXObjectGroup",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyTMXObject",0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTMXObjectGroup* self = (wyTMXObjectGroup*)  tolua_tousertype(tolua_S,1,0);
  wyTMXObject* object = ((wyTMXObject*)  tolua_tousertype(tolua_S,2,0));
  const char* key = ((const char*)  tolua_tostring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getObjectProperty'", NULL);
#endif
  {
   char* tolua_ret = (char*)  self->getObjectProperty(object,key);
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getObjectProperty'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setName of class  wyTMXObjectGroup */
#ifndef TOLUA_DISABLE_tolua_tmx_wyTMXObjectGroup_setName00
static int tolua_tmx_wyTMXObjectGroup_setName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTMXObjectGroup",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTMXObjectGroup* self = (wyTMXObjectGroup*)  tolua_tousertype(tolua_S,1,0);
  const char* name = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setName'", NULL);
#endif
  {
   self->setName(name);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getName of class  wyTMXObjectGroup */
#ifndef TOLUA_DISABLE_tolua_tmx_wyTMXObjectGroup_getName00
static int tolua_tmx_wyTMXObjectGroup_getName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTMXObjectGroup",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTMXObjectGroup* self = (wyTMXObjectGroup*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getName'", NULL);
#endif
  {
   const char* tolua_ret = (const char*)  self->getName();
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setOffsetX of class  wyTMXObjectGroup */
#ifndef TOLUA_DISABLE_tolua_tmx_wyTMXObjectGroup_setOffsetX00
static int tolua_tmx_wyTMXObjectGroup_setOffsetX00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTMXObjectGroup",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTMXObjectGroup* self = (wyTMXObjectGroup*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setOffsetX'", NULL);
#endif
  {
   self->setOffsetX(x);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setOffsetX'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getOffsetX of class  wyTMXObjectGroup */
#ifndef TOLUA_DISABLE_tolua_tmx_wyTMXObjectGroup_getOffsetX00
static int tolua_tmx_wyTMXObjectGroup_getOffsetX00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTMXObjectGroup",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTMXObjectGroup* self = (wyTMXObjectGroup*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getOffsetX'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getOffsetX();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getOffsetX'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setOffsetY of class  wyTMXObjectGroup */
#ifndef TOLUA_DISABLE_tolua_tmx_wyTMXObjectGroup_setOffsetY00
static int tolua_tmx_wyTMXObjectGroup_setOffsetY00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTMXObjectGroup",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTMXObjectGroup* self = (wyTMXObjectGroup*)  tolua_tousertype(tolua_S,1,0);
  float y = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setOffsetY'", NULL);
#endif
  {
   self->setOffsetY(y);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setOffsetY'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getOffsetY of class  wyTMXObjectGroup */
#ifndef TOLUA_DISABLE_tolua_tmx_wyTMXObjectGroup_getOffsetY00
static int tolua_tmx_wyTMXObjectGroup_getOffsetY00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTMXObjectGroup",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTMXObjectGroup* self = (wyTMXObjectGroup*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getOffsetY'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getOffsetY();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getOffsetY'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setColor of class  wyTMXObjectGroup */
#ifndef TOLUA_DISABLE_tolua_tmx_wyTMXObjectGroup_setColor00
static int tolua_tmx_wyTMXObjectGroup_setColor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTMXObjectGroup",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTMXObjectGroup* self = (wyTMXObjectGroup*)  tolua_tousertype(tolua_S,1,0);
  int color = ((int)  tolua_tonumber(tolua_S,2,0));
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

/* method: getColor of class  wyTMXObjectGroup */
#ifndef TOLUA_DISABLE_tolua_tmx_wyTMXObjectGroup_getColor00
static int tolua_tmx_wyTMXObjectGroup_getColor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTMXObjectGroup",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTMXObjectGroup* self = (wyTMXObjectGroup*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getColor'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getColor();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
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

/* method: getOpacity of class  wyTMXObjectGroup */
#ifndef TOLUA_DISABLE_tolua_tmx_wyTMXObjectGroup_getOpacity00
static int tolua_tmx_wyTMXObjectGroup_getOpacity00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTMXObjectGroup",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTMXObjectGroup* self = (wyTMXObjectGroup*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getOpacity'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getOpacity();
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

/* method: setOpacity of class  wyTMXObjectGroup */
#ifndef TOLUA_DISABLE_tolua_tmx_wyTMXObjectGroup_setOpacity00
static int tolua_tmx_wyTMXObjectGroup_setOpacity00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTMXObjectGroup",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTMXObjectGroup* self = (wyTMXObjectGroup*)  tolua_tousertype(tolua_S,1,0);
  float opacity = ((float)  tolua_tonumber(tolua_S,2,0));
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

/* get function: name of class  wyTileSetInfo */
#ifndef TOLUA_DISABLE_tolua_get_wyTileSetInfo_name
static int tolua_get_wyTileSetInfo_name(lua_State* tolua_S)
{
  wyTileSetInfo* self = (wyTileSetInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'name'",NULL);
#endif
  tolua_pushstring(tolua_S,(const char*)self->name);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: firstGid of class  wyTileSetInfo */
#ifndef TOLUA_DISABLE_tolua_get_wyTileSetInfo_firstGid
static int tolua_get_wyTileSetInfo_firstGid(lua_State* tolua_S)
{
  wyTileSetInfo* self = (wyTileSetInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'firstGid'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->firstGid);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: firstGid of class  wyTileSetInfo */
#ifndef TOLUA_DISABLE_tolua_set_wyTileSetInfo_firstGid
static int tolua_set_wyTileSetInfo_firstGid(lua_State* tolua_S)
{
  wyTileSetInfo* self = (wyTileSetInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'firstGid'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->firstGid = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: tileWidth of class  wyTileSetInfo */
#ifndef TOLUA_DISABLE_tolua_get_wyTileSetInfo_tileWidth
static int tolua_get_wyTileSetInfo_tileWidth(lua_State* tolua_S)
{
  wyTileSetInfo* self = (wyTileSetInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'tileWidth'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->tileWidth);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: tileWidth of class  wyTileSetInfo */
#ifndef TOLUA_DISABLE_tolua_set_wyTileSetInfo_tileWidth
static int tolua_set_wyTileSetInfo_tileWidth(lua_State* tolua_S)
{
  wyTileSetInfo* self = (wyTileSetInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'tileWidth'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->tileWidth = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: tileHeight of class  wyTileSetInfo */
#ifndef TOLUA_DISABLE_tolua_get_wyTileSetInfo_tileHeight
static int tolua_get_wyTileSetInfo_tileHeight(lua_State* tolua_S)
{
  wyTileSetInfo* self = (wyTileSetInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'tileHeight'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->tileHeight);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: tileHeight of class  wyTileSetInfo */
#ifndef TOLUA_DISABLE_tolua_set_wyTileSetInfo_tileHeight
static int tolua_set_wyTileSetInfo_tileHeight(lua_State* tolua_S)
{
  wyTileSetInfo* self = (wyTileSetInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'tileHeight'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->tileHeight = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: spacing of class  wyTileSetInfo */
#ifndef TOLUA_DISABLE_tolua_get_wyTileSetInfo_spacing
static int tolua_get_wyTileSetInfo_spacing(lua_State* tolua_S)
{
  wyTileSetInfo* self = (wyTileSetInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'spacing'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->spacing);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: spacing of class  wyTileSetInfo */
#ifndef TOLUA_DISABLE_tolua_set_wyTileSetInfo_spacing
static int tolua_set_wyTileSetInfo_spacing(lua_State* tolua_S)
{
  wyTileSetInfo* self = (wyTileSetInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'spacing'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->spacing = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: margin of class  wyTileSetInfo */
#ifndef TOLUA_DISABLE_tolua_get_wyTileSetInfo_margin
static int tolua_get_wyTileSetInfo_margin(lua_State* tolua_S)
{
  wyTileSetInfo* self = (wyTileSetInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'margin'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->margin);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: margin of class  wyTileSetInfo */
#ifndef TOLUA_DISABLE_tolua_set_wyTileSetInfo_margin
static int tolua_set_wyTileSetInfo_margin(lua_State* tolua_S)
{
  wyTileSetInfo* self = (wyTileSetInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'margin'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->margin = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: sourceImageId of class  wyTileSetInfo */
#ifndef TOLUA_DISABLE_tolua_get_wyTileSetInfo_sourceImageId
static int tolua_get_wyTileSetInfo_sourceImageId(lua_State* tolua_S)
{
  wyTileSetInfo* self = (wyTileSetInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'sourceImageId'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->sourceImageId);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: sourceImageId of class  wyTileSetInfo */
#ifndef TOLUA_DISABLE_tolua_set_wyTileSetInfo_sourceImageId
static int tolua_set_wyTileSetInfo_sourceImageId(lua_State* tolua_S)
{
  wyTileSetInfo* self = (wyTileSetInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'sourceImageId'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->sourceImageId = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: sourceImagePath of class  wyTileSetInfo */
#ifndef TOLUA_DISABLE_tolua_get_wyTileSetInfo_sourceImagePath
static int tolua_get_wyTileSetInfo_sourceImagePath(lua_State* tolua_S)
{
  wyTileSetInfo* self = (wyTileSetInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'sourceImagePath'",NULL);
#endif
  tolua_pushstring(tolua_S,(const char*)self->sourceImagePath);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: sourceImageIsFile of class  wyTileSetInfo */
#ifndef TOLUA_DISABLE_tolua_get_wyTileSetInfo_sourceImageIsFile
static int tolua_get_wyTileSetInfo_sourceImageIsFile(lua_State* tolua_S)
{
  wyTileSetInfo* self = (wyTileSetInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'sourceImageIsFile'",NULL);
#endif
  tolua_pushboolean(tolua_S,(bool)self->sourceImageIsFile);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: sourceImageIsFile of class  wyTileSetInfo */
#ifndef TOLUA_DISABLE_tolua_set_wyTileSetInfo_sourceImageIsFile
static int tolua_set_wyTileSetInfo_sourceImageIsFile(lua_State* tolua_S)
{
  wyTileSetInfo* self = (wyTileSetInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'sourceImageIsFile'",NULL);
  if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->sourceImageIsFile = ((bool)  tolua_toboolean(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: imageWidth of class  wyTileSetInfo */
#ifndef TOLUA_DISABLE_tolua_get_wyTileSetInfo_imageWidth
static int tolua_get_wyTileSetInfo_imageWidth(lua_State* tolua_S)
{
  wyTileSetInfo* self = (wyTileSetInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'imageWidth'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->imageWidth);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: imageWidth of class  wyTileSetInfo */
#ifndef TOLUA_DISABLE_tolua_set_wyTileSetInfo_imageWidth
static int tolua_set_wyTileSetInfo_imageWidth(lua_State* tolua_S)
{
  wyTileSetInfo* self = (wyTileSetInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'imageWidth'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->imageWidth = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: imageHeight of class  wyTileSetInfo */
#ifndef TOLUA_DISABLE_tolua_get_wyTileSetInfo_imageHeight
static int tolua_get_wyTileSetInfo_imageHeight(lua_State* tolua_S)
{
  wyTileSetInfo* self = (wyTileSetInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'imageHeight'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->imageHeight);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: imageHeight of class  wyTileSetInfo */
#ifndef TOLUA_DISABLE_tolua_set_wyTileSetInfo_imageHeight
static int tolua_set_wyTileSetInfo_imageHeight(lua_State* tolua_S)
{
  wyTileSetInfo* self = (wyTileSetInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'imageHeight'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->imageHeight = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* function: wyTileSetInfoNew */
#ifndef TOLUA_DISABLE_tolua_tmx_wyTileSetInfoNew00
static int tolua_tmx_wyTileSetInfoNew00(lua_State* tolua_S)
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
   wyTileSetInfo* tolua_ret = (wyTileSetInfo*)  wyTileSetInfoNew();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyTileSetInfo");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'wyTileSetInfoNew'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: wyTileSetInfoDestroy */
#ifndef TOLUA_DISABLE_tolua_tmx_wyTileSetInfoDestroy00
static int tolua_tmx_wyTileSetInfoDestroy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTileSetInfo",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTileSetInfo* info = ((wyTileSetInfo*)  tolua_tousertype(tolua_S,1,0));
  {
   wyTileSetInfoDestroy(info);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'wyTileSetInfoDestroy'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: wyTileSetInfoGetRect */
#ifndef TOLUA_DISABLE_tolua_tmx_wyTileSetInfoGetRect00
static int tolua_tmx_wyTileSetInfoGetRect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTileSetInfo",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTileSetInfo* info = ((wyTileSetInfo*)  tolua_tousertype(tolua_S,1,0));
  int gid = ((int)  tolua_tonumber(tolua_S,2,0));
  {
   wyRect tolua_ret = (wyRect)  wyTileSetInfoGetRect(info,gid);
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
 tolua_error(tolua_S,"#ferror in function 'wyTileSetInfoGetRect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: wyTileSetInfoCopy */
#ifndef TOLUA_DISABLE_tolua_tmx_wyTileSetInfoCopy00
static int tolua_tmx_wyTileSetInfoCopy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTileSetInfo",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTileSetInfo* info = ((wyTileSetInfo*)  tolua_tousertype(tolua_S,1,0));
  {
   wyTileSetInfo* tolua_ret = (wyTileSetInfo*)  wyTileSetInfoCopy(info);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyTileSetInfo");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'wyTileSetInfoCopy'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: make of class  wyTMXTileMap */
#ifndef TOLUA_DISABLE_tolua_tmx_wyTMXTileMap_make00
static int tolua_tmx_wyTMXTileMap_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyTMXTileMap",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"wyTexture2D",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  int resId = ((int)  tolua_tonumber(tolua_S,2,0));
  wyTexture2D* tex = ((wyTexture2D*)  tolua_tousertype(tolua_S,3,0));
  int texCount = ((int)  tolua_tonumber(tolua_S,4,0));
  {
   wyTMXTileMap* tolua_ret = (wyTMXTileMap*)  wyTMXTileMap::make(resId,&tex,texCount);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyTMXTileMap");
    tolua_pushusertype(tolua_S,(void*)tex,"wyTexture2D");
  }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'make'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: make of class  wyTMXTileMap */
#ifndef TOLUA_DISABLE_tolua_tmx_wyTMXTileMap_make01
static int tolua_tmx_wyTMXTileMap_make01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyTMXTileMap",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,3,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,4,"wyTexture2D",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const char* path = ((const char*)  tolua_tostring(tolua_S,2,0));
  bool isFile = ((bool)  tolua_toboolean(tolua_S,3,0));
  wyTexture2D* tex = ((wyTexture2D*)  tolua_tousertype(tolua_S,4,0));
  int texCount = ((int)  tolua_tonumber(tolua_S,5,0));
  {
   wyTMXTileMap* tolua_ret = (wyTMXTileMap*)  wyTMXTileMap::make(path,isFile,&tex,texCount);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyTMXTileMap");
    tolua_pushusertype(tolua_S,(void*)tex,"wyTexture2D");
  }
 }
 return 2;
tolua_lerror:
 return tolua_tmx_wyTMXTileMap_make00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  wyTMXTileMap */
#ifndef TOLUA_DISABLE_tolua_tmx_wyTMXTileMap_delete00
static int tolua_tmx_wyTMXTileMap_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTMXTileMap",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTMXTileMap* self = (wyTMXTileMap*)  tolua_tousertype(tolua_S,1,0);
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

/* method: getLayer of class  wyTMXTileMap */
#ifndef TOLUA_DISABLE_tolua_tmx_wyTMXTileMap_getLayer00
static int tolua_tmx_wyTMXTileMap_getLayer00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTMXTileMap",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTMXTileMap* self = (wyTMXTileMap*)  tolua_tousertype(tolua_S,1,0);
  const char* name = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getLayer'", NULL);
#endif
  {
   wyTMXLayer* tolua_ret = (wyTMXLayer*)  self->getLayer(name);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyTMXLayer");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getLayer'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getLayerAt of class  wyTMXTileMap */
#ifndef TOLUA_DISABLE_tolua_tmx_wyTMXTileMap_getLayerAt00
static int tolua_tmx_wyTMXTileMap_getLayerAt00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTMXTileMap",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTMXTileMap* self = (wyTMXTileMap*)  tolua_tousertype(tolua_S,1,0);
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getLayerAt'", NULL);
#endif
  {
   wyTMXLayer* tolua_ret = (wyTMXLayer*)  self->getLayerAt(index);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyTMXLayer");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getLayerAt'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getObjectGroup of class  wyTMXTileMap */
#ifndef TOLUA_DISABLE_tolua_tmx_wyTMXTileMap_getObjectGroup00
static int tolua_tmx_wyTMXTileMap_getObjectGroup00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTMXTileMap",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTMXTileMap* self = (wyTMXTileMap*)  tolua_tousertype(tolua_S,1,0);
  const char* name = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getObjectGroup'", NULL);
#endif
  {
   wyTMXObjectGroup* tolua_ret = (wyTMXObjectGroup*)  self->getObjectGroup(name);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyTMXObjectGroup");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getObjectGroup'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getProperty of class  wyTMXTileMap */
#ifndef TOLUA_DISABLE_tolua_tmx_wyTMXTileMap_getProperty00
static int tolua_tmx_wyTMXTileMap_getProperty00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTMXTileMap",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTMXTileMap* self = (wyTMXTileMap*)  tolua_tousertype(tolua_S,1,0);
  const char* name = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getProperty'", NULL);
#endif
  {
   char* tolua_ret = (char*)  self->getProperty(name);
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getProperty'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getTileProperty of class  wyTMXTileMap */
#ifndef TOLUA_DISABLE_tolua_tmx_wyTMXTileMap_getTileProperty00
static int tolua_tmx_wyTMXTileMap_getTileProperty00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTMXTileMap",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTMXTileMap* self = (wyTMXTileMap*)  tolua_tousertype(tolua_S,1,0);
  int gid = ((int)  tolua_tonumber(tolua_S,2,0));
  const char* name = ((const char*)  tolua_tostring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getTileProperty'", NULL);
#endif
  {
   char* tolua_ret = (char*)  self->getTileProperty(gid,name);
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getTileProperty'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getMapWidth of class  wyTMXTileMap */
#ifndef TOLUA_DISABLE_tolua_tmx_wyTMXTileMap_getMapWidth00
static int tolua_tmx_wyTMXTileMap_getMapWidth00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTMXTileMap",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTMXTileMap* self = (wyTMXTileMap*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getMapWidth'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getMapWidth();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getMapWidth'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getMapHeight of class  wyTMXTileMap */
#ifndef TOLUA_DISABLE_tolua_tmx_wyTMXTileMap_getMapHeight00
static int tolua_tmx_wyTMXTileMap_getMapHeight00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTMXTileMap",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTMXTileMap* self = (wyTMXTileMap*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getMapHeight'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getMapHeight();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getMapHeight'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getTileWidth of class  wyTMXTileMap */
#ifndef TOLUA_DISABLE_tolua_tmx_wyTMXTileMap_getTileWidth00
static int tolua_tmx_wyTMXTileMap_getTileWidth00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTMXTileMap",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTMXTileMap* self = (wyTMXTileMap*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getTileWidth'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getTileWidth();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getTileWidth'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getTileHeight of class  wyTMXTileMap */
#ifndef TOLUA_DISABLE_tolua_tmx_wyTMXTileMap_getTileHeight00
static int tolua_tmx_wyTMXTileMap_getTileHeight00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTMXTileMap",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTMXTileMap* self = (wyTMXTileMap*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getTileHeight'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getTileHeight();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getTileHeight'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getOrientation of class  wyTMXTileMap */
#ifndef TOLUA_DISABLE_tolua_tmx_wyTMXTileMap_getOrientation00
static int tolua_tmx_wyTMXTileMap_getOrientation00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTMXTileMap",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTMXTileMap* self = (wyTMXTileMap*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getOrientation'", NULL);
#endif
  {
   wyTMXOrientation tolua_ret = (wyTMXOrientation)  self->getOrientation();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getOrientation'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: make of class  wyTMXLayer */
#ifndef TOLUA_DISABLE_tolua_tmx_wyTMXLayer_make00
static int tolua_tmx_wyTMXLayer_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyTMXLayer",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"wyMapInfo",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  int layerIndex = ((int)  tolua_tonumber(tolua_S,2,0));
  wyMapInfo* mapInfo = ((wyMapInfo*)  tolua_tousertype(tolua_S,3,0));
  {
   wyTMXLayer* tolua_ret = (wyTMXLayer*)  wyTMXLayer::make(layerIndex,mapInfo);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyTMXLayer");
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

/* method: delete of class  wyTMXLayer */
#ifndef TOLUA_DISABLE_tolua_tmx_wyTMXLayer_delete00
static int tolua_tmx_wyTMXLayer_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTMXLayer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTMXLayer* self = (wyTMXLayer*)  tolua_tousertype(tolua_S,1,0);
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

/* method: removeTile of class  wyTMXLayer */
#ifndef TOLUA_DISABLE_tolua_tmx_wyTMXLayer_removeTile00
static int tolua_tmx_wyTMXLayer_removeTile00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTMXLayer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wySpriteEx",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTMXLayer* self = (wyTMXLayer*)  tolua_tousertype(tolua_S,1,0);
  wySpriteEx* sprite = ((wySpriteEx*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'removeTile'", NULL);
#endif
  {
   self->removeTile(sprite);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'removeTile'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getProperty of class  wyTMXLayer */
#ifndef TOLUA_DISABLE_tolua_tmx_wyTMXLayer_getProperty00
static int tolua_tmx_wyTMXLayer_getProperty00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTMXLayer",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTMXLayer* self = (wyTMXLayer*)  tolua_tousertype(tolua_S,1,0);
  const char* key = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getProperty'", NULL);
#endif
  {
   char* tolua_ret = (char*)  self->getProperty(key);
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getProperty'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getLayerWidth of class  wyTMXLayer */
#ifndef TOLUA_DISABLE_tolua_tmx_wyTMXLayer_getLayerWidth00
static int tolua_tmx_wyTMXLayer_getLayerWidth00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTMXLayer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTMXLayer* self = (wyTMXLayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getLayerWidth'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getLayerWidth();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getLayerWidth'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getLayerHeight of class  wyTMXLayer */
#ifndef TOLUA_DISABLE_tolua_tmx_wyTMXLayer_getLayerHeight00
static int tolua_tmx_wyTMXLayer_getLayerHeight00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTMXLayer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTMXLayer* self = (wyTMXLayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getLayerHeight'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getLayerHeight();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getLayerHeight'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getTileWidth of class  wyTMXLayer */
#ifndef TOLUA_DISABLE_tolua_tmx_wyTMXLayer_getTileWidth00
static int tolua_tmx_wyTMXLayer_getTileWidth00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTMXLayer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTMXLayer* self = (wyTMXLayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getTileWidth'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getTileWidth();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getTileWidth'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getTileHeight of class  wyTMXLayer */
#ifndef TOLUA_DISABLE_tolua_tmx_wyTMXLayer_getTileHeight00
static int tolua_tmx_wyTMXLayer_getTileHeight00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTMXLayer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTMXLayer* self = (wyTMXLayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getTileHeight'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getTileHeight();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getTileHeight'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getTileCoordinateAt of class  wyTMXLayer */
#ifndef TOLUA_DISABLE_tolua_tmx_wyTMXLayer_getTileCoordinateAt00
static int tolua_tmx_wyTMXLayer_getTileCoordinateAt00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTMXLayer",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTMXLayer* self = (wyTMXLayer*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getTileCoordinateAt'", NULL);
#endif
  {
   wyDimension tolua_ret = (wyDimension)  self->getTileCoordinateAt(x,y);
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
 tolua_error(tolua_S,"#ferror in function 'getTileCoordinateAt'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: tileAt of class  wyTMXLayer */
#ifndef TOLUA_DISABLE_tolua_tmx_wyTMXLayer_tileAt00
static int tolua_tmx_wyTMXLayer_tileAt00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTMXLayer",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTMXLayer* self = (wyTMXLayer*)  tolua_tousertype(tolua_S,1,0);
  int x = ((int)  tolua_tonumber(tolua_S,2,0));
  int y = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'tileAt'", NULL);
#endif
  {
   wySpriteEx* tolua_ret = (wySpriteEx*)  self->tileAt(x,y);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wySpriteEx");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'tileAt'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getGidAt of class  wyTMXLayer */
#ifndef TOLUA_DISABLE_tolua_tmx_wyTMXLayer_getGidAt00
static int tolua_tmx_wyTMXLayer_getGidAt00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTMXLayer",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTMXLayer* self = (wyTMXLayer*)  tolua_tousertype(tolua_S,1,0);
  int x = ((int)  tolua_tonumber(tolua_S,2,0));
  int y = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getGidAt'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getGidAt(x,y);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getGidAt'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getGids of class  wyTMXLayer */
#ifndef TOLUA_DISABLE_tolua_tmx_wyTMXLayer_getGids00
static int tolua_tmx_wyTMXLayer_getGids00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTMXLayer",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTMXLayer* self = (wyTMXLayer*)  tolua_tousertype(tolua_S,1,0);
  bool copy = ((bool)  tolua_toboolean(tolua_S,2,false));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getGids'", NULL);
#endif
  {
   void* tolua_ret = (void*)  self->getGids(copy);
   tolua_pushuserdata(tolua_S,(void*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getGids'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: removeTileAt of class  wyTMXLayer */
#ifndef TOLUA_DISABLE_tolua_tmx_wyTMXLayer_removeTileAt00
static int tolua_tmx_wyTMXLayer_removeTileAt00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTMXLayer",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTMXLayer* self = (wyTMXLayer*)  tolua_tousertype(tolua_S,1,0);
  int x = ((int)  tolua_tonumber(tolua_S,2,0));
  int y = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'removeTileAt'", NULL);
#endif
  {
   self->removeTileAt(x,y);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'removeTileAt'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setTileAt of class  wyTMXLayer */
#ifndef TOLUA_DISABLE_tolua_tmx_wyTMXLayer_setTileAt00
static int tolua_tmx_wyTMXLayer_setTileAt00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTMXLayer",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTMXLayer* self = (wyTMXLayer*)  tolua_tousertype(tolua_S,1,0);
  int gid = ((int)  tolua_tonumber(tolua_S,2,0));
  int x = ((int)  tolua_tonumber(tolua_S,3,0));
  int y = ((int)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setTileAt'", NULL);
#endif
  {
   self->setTileAt(gid,x,y);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setTileAt'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: updateTileAt of class  wyTMXLayer */
#ifndef TOLUA_DISABLE_tolua_tmx_wyTMXLayer_updateTileAt00
static int tolua_tmx_wyTMXLayer_updateTileAt00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTMXLayer",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTMXLayer* self = (wyTMXLayer*)  tolua_tousertype(tolua_S,1,0);
  int gid = ((int)  tolua_tonumber(tolua_S,2,0));
  int x = ((int)  tolua_tonumber(tolua_S,3,0));
  int y = ((int)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'updateTileAt'", NULL);
#endif
  {
   self->updateTileAt(gid,x,y);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'updateTileAt'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getPositionAt of class  wyTMXLayer */
#ifndef TOLUA_DISABLE_tolua_tmx_wyTMXLayer_getPositionAt00
static int tolua_tmx_wyTMXLayer_getPositionAt00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTMXLayer",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTMXLayer* self = (wyTMXLayer*)  tolua_tousertype(tolua_S,1,0);
  int x = ((int)  tolua_tonumber(tolua_S,2,0));
  int y = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getPositionAt'", NULL);
#endif
  {
   wyPoint tolua_ret = (wyPoint)  self->getPositionAt(x,y);
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
 tolua_error(tolua_S,"#ferror in function 'getPositionAt'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: load of class  wyTMXLoader */
#ifndef TOLUA_DISABLE_tolua_tmx_wyTMXLoader_load00
static int tolua_tmx_wyTMXLoader_load00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyTMXLoader",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  int resId = ((int)  tolua_tonumber(tolua_S,2,0));
  {
   wyMapInfo* tolua_ret = (wyMapInfo*)  wyTMXLoader::load(resId);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyMapInfo");
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

/* method: load of class  wyTMXLoader */
#ifndef TOLUA_DISABLE_tolua_tmx_wyTMXLoader_load01
static int tolua_tmx_wyTMXLoader_load01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyTMXLoader",0,&tolua_err) ||
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
   wyMapInfo* tolua_ret = (wyMapInfo*)  wyTMXLoader::load(path,isFile);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyMapInfo");
  }
 }
 return 1;
tolua_lerror:
 return tolua_tmx_wyTMXLoader_load00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_tmx_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyTMXObject","wyTMXObject","wyObject",tolua_collect_wyTMXObject);
  #else
  tolua_cclass(tolua_S,"wyTMXObject","wyTMXObject","wyObject",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyTMXObject");
   tolua_constant(tolua_S,"NORMAL",wyTMXObject::NORMAL);
   tolua_constant(tolua_S,"POLYGON",wyTMXObject::POLYGON);
   tolua_constant(tolua_S,"POLYLINE",wyTMXObject::POLYLINE);
   tolua_function(tolua_S,"delete",tolua_tmx_wyTMXObject_delete00);
   tolua_function(tolua_S,"make",tolua_tmx_wyTMXObject_make00);
   tolua_function(tolua_S,"getProperty",tolua_tmx_wyTMXObject_getProperty00);
   tolua_function(tolua_S,"addProperty",tolua_tmx_wyTMXObject_addProperty00);
   tolua_function(tolua_S,"getType",tolua_tmx_wyTMXObject_getType00);
   tolua_function(tolua_S,"getPoints",tolua_tmx_wyTMXObject_getPoints00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"wyLayerInfo","wyLayerInfo","",NULL);
  tolua_beginmodule(tolua_S,"wyLayerInfo");
   tolua_variable(tolua_S,"name",tolua_get_wyLayerInfo_name,tolua_set_wyLayerInfo_name);
   tolua_variable(tolua_S,"layerWidth",tolua_get_wyLayerInfo_layerWidth,tolua_set_wyLayerInfo_layerWidth);
   tolua_variable(tolua_S,"layerHeight",tolua_get_wyLayerInfo_layerHeight,tolua_set_wyLayerInfo_layerHeight);
   tolua_variable(tolua_S,"tiles",tolua_get_wyLayerInfo_tiles,tolua_set_wyLayerInfo_tiles);
   tolua_variable(tolua_S,"visible",tolua_get_wyLayerInfo_visible,tolua_set_wyLayerInfo_visible);
   tolua_variable(tolua_S,"alpha",tolua_get_wyLayerInfo_alpha,tolua_set_wyLayerInfo_alpha);
   tolua_variable(tolua_S,"minGid",tolua_get_wyLayerInfo_minGid,tolua_set_wyLayerInfo_minGid);
   tolua_variable(tolua_S,"maxGid",tolua_get_wyLayerInfo_maxGid,tolua_set_wyLayerInfo_maxGid);
   tolua_variable(tolua_S,"properties",tolua_get_wyLayerInfo_properties_ptr,tolua_set_wyLayerInfo_properties_ptr);
   tolua_variable(tolua_S,"offsetX",tolua_get_wyLayerInfo_offsetX,tolua_set_wyLayerInfo_offsetX);
   tolua_variable(tolua_S,"offsetY",tolua_get_wyLayerInfo_offsetY,tolua_set_wyLayerInfo_offsetY);
  tolua_endmodule(tolua_S);
  tolua_function(tolua_S,"wyLayerInfoNew",tolua_tmx_wyLayerInfoNew00);
  tolua_function(tolua_S,"wyLayerInfoDestroy",tolua_tmx_wyLayerInfoDestroy00);
  tolua_function(tolua_S,"wyLayerInfoAddProperty",tolua_tmx_wyLayerInfoAddProperty00);
  tolua_function(tolua_S,"wyLayerInfoGetProperty",tolua_tmx_wyLayerInfoGetProperty00);
  tolua_constant(tolua_S,"ORIENTATION_ORTHOGONAL",ORIENTATION_ORTHOGONAL);
  tolua_constant(tolua_S,"ORIENTATION_ISOMETRIC",ORIENTATION_ISOMETRIC);
  tolua_constant(tolua_S,"ORIENTATION_HEXAGONAL",ORIENTATION_HEXAGONAL);
  tolua_cclass(tolua_S,"wyTileHash","wyTileHash","",NULL);
  tolua_beginmodule(tolua_S,"wyTileHash");
   tolua_variable(tolua_S,"gid",tolua_get_wyTileHash_gid,tolua_set_wyTileHash_gid);
   tolua_variable(tolua_S,"properties",tolua_get_wyTileHash_properties_ptr,tolua_set_wyTileHash_properties_ptr);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"wyMapInfo","wyMapInfo","",NULL);
  tolua_beginmodule(tolua_S,"wyMapInfo");
   tolua_variable(tolua_S,"filename",tolua_get_wyMapInfo_filename,tolua_set_wyMapInfo_filename);
   tolua_variable(tolua_S,"orientation",tolua_get_wyMapInfo_orientation,tolua_set_wyMapInfo_orientation);
   tolua_variable(tolua_S,"mapWidth",tolua_get_wyMapInfo_mapWidth,tolua_set_wyMapInfo_mapWidth);
   tolua_variable(tolua_S,"mapHeight",tolua_get_wyMapInfo_mapHeight,tolua_set_wyMapInfo_mapHeight);
   tolua_variable(tolua_S,"tileWidth",tolua_get_wyMapInfo_tileWidth,tolua_set_wyMapInfo_tileWidth);
   tolua_variable(tolua_S,"tileHeight",tolua_get_wyMapInfo_tileHeight,tolua_set_wyMapInfo_tileHeight);
   tolua_variable(tolua_S,"layers",tolua_get_wyMapInfo_layers_ptr,tolua_set_wyMapInfo_layers_ptr);
   tolua_variable(tolua_S,"tilesets",tolua_get_wyMapInfo_tilesets_ptr,tolua_set_wyMapInfo_tilesets_ptr);
   tolua_variable(tolua_S,"objectGroups",tolua_get_wyMapInfo_objectGroups_ptr,tolua_set_wyMapInfo_objectGroups_ptr);
   tolua_variable(tolua_S,"properties",tolua_get_wyMapInfo_properties_ptr,tolua_set_wyMapInfo_properties_ptr);
   tolua_variable(tolua_S,"tileProperties",tolua_get_wyMapInfo_tileProperties_ptr,tolua_set_wyMapInfo_tileProperties_ptr);
  tolua_endmodule(tolua_S);
  tolua_function(tolua_S,"wyMapInfoNew",tolua_tmx_wyMapInfoNew00);
  tolua_function(tolua_S,"wyMapInfoDestroy",tolua_tmx_wyMapInfoDestroy00);
  tolua_function(tolua_S,"wyMapInfoAddProperty",tolua_tmx_wyMapInfoAddProperty00);
  tolua_function(tolua_S,"wyMapInfoGetProperty",tolua_tmx_wyMapInfoGetProperty00);
  tolua_function(tolua_S,"wyMapInfoNewTileProperties",tolua_tmx_wyMapInfoNewTileProperties00);
  tolua_function(tolua_S,"wyMapInfoGetTileProperty",tolua_tmx_wyMapInfoGetTileProperty00);
  tolua_function(tolua_S,"wyMapInfoAddTileProperty",tolua_tmx_wyMapInfoAddTileProperty00);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyTMXObjectGroup","wyTMXObjectGroup","wyObject",tolua_collect_wyTMXObjectGroup);
  #else
  tolua_cclass(tolua_S,"wyTMXObjectGroup","wyTMXObjectGroup","wyObject",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyTMXObjectGroup");
   tolua_function(tolua_S,"delete",tolua_tmx_wyTMXObjectGroup_delete00);
   tolua_function(tolua_S,"make",tolua_tmx_wyTMXObjectGroup_make00);
   tolua_function(tolua_S,"addProperty",tolua_tmx_wyTMXObjectGroup_addProperty00);
   tolua_function(tolua_S,"getProperty",tolua_tmx_wyTMXObjectGroup_getProperty00);
   tolua_function(tolua_S,"newObject",tolua_tmx_wyTMXObjectGroup_newObject00);
   tolua_function(tolua_S,"getObject",tolua_tmx_wyTMXObjectGroup_getObject00);
   tolua_function(tolua_S,"getObjectAt",tolua_tmx_wyTMXObjectGroup_getObjectAt00);
   tolua_function(tolua_S,"getObjectCount",tolua_tmx_wyTMXObjectGroup_getObjectCount00);
   tolua_function(tolua_S,"addObjectProperty",tolua_tmx_wyTMXObjectGroup_addObjectProperty00);
   tolua_function(tolua_S,"getObjectProperty",tolua_tmx_wyTMXObjectGroup_getObjectProperty00);
   tolua_function(tolua_S,"setName",tolua_tmx_wyTMXObjectGroup_setName00);
   tolua_function(tolua_S,"getName",tolua_tmx_wyTMXObjectGroup_getName00);
   tolua_function(tolua_S,"setOffsetX",tolua_tmx_wyTMXObjectGroup_setOffsetX00);
   tolua_function(tolua_S,"getOffsetX",tolua_tmx_wyTMXObjectGroup_getOffsetX00);
   tolua_function(tolua_S,"setOffsetY",tolua_tmx_wyTMXObjectGroup_setOffsetY00);
   tolua_function(tolua_S,"getOffsetY",tolua_tmx_wyTMXObjectGroup_getOffsetY00);
   tolua_function(tolua_S,"setColor",tolua_tmx_wyTMXObjectGroup_setColor00);
   tolua_function(tolua_S,"getColor",tolua_tmx_wyTMXObjectGroup_getColor00);
   tolua_function(tolua_S,"getOpacity",tolua_tmx_wyTMXObjectGroup_getOpacity00);
   tolua_function(tolua_S,"setOpacity",tolua_tmx_wyTMXObjectGroup_setOpacity00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"wyTileSetInfo","wyTileSetInfo","",NULL);
  tolua_beginmodule(tolua_S,"wyTileSetInfo");
   tolua_variable(tolua_S,"name",tolua_get_wyTileSetInfo_name,NULL);
   tolua_variable(tolua_S,"firstGid",tolua_get_wyTileSetInfo_firstGid,tolua_set_wyTileSetInfo_firstGid);
   tolua_variable(tolua_S,"tileWidth",tolua_get_wyTileSetInfo_tileWidth,tolua_set_wyTileSetInfo_tileWidth);
   tolua_variable(tolua_S,"tileHeight",tolua_get_wyTileSetInfo_tileHeight,tolua_set_wyTileSetInfo_tileHeight);
   tolua_variable(tolua_S,"spacing",tolua_get_wyTileSetInfo_spacing,tolua_set_wyTileSetInfo_spacing);
   tolua_variable(tolua_S,"margin",tolua_get_wyTileSetInfo_margin,tolua_set_wyTileSetInfo_margin);
   tolua_variable(tolua_S,"sourceImageId",tolua_get_wyTileSetInfo_sourceImageId,tolua_set_wyTileSetInfo_sourceImageId);
   tolua_variable(tolua_S,"sourceImagePath",tolua_get_wyTileSetInfo_sourceImagePath,NULL);
   tolua_variable(tolua_S,"sourceImageIsFile",tolua_get_wyTileSetInfo_sourceImageIsFile,tolua_set_wyTileSetInfo_sourceImageIsFile);
   tolua_variable(tolua_S,"imageWidth",tolua_get_wyTileSetInfo_imageWidth,tolua_set_wyTileSetInfo_imageWidth);
   tolua_variable(tolua_S,"imageHeight",tolua_get_wyTileSetInfo_imageHeight,tolua_set_wyTileSetInfo_imageHeight);
  tolua_endmodule(tolua_S);
  tolua_function(tolua_S,"wyTileSetInfoNew",tolua_tmx_wyTileSetInfoNew00);
  tolua_function(tolua_S,"wyTileSetInfoDestroy",tolua_tmx_wyTileSetInfoDestroy00);
  tolua_function(tolua_S,"wyTileSetInfoGetRect",tolua_tmx_wyTileSetInfoGetRect00);
  tolua_function(tolua_S,"wyTileSetInfoCopy",tolua_tmx_wyTileSetInfoCopy00);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyTMXTileMap","wyTMXTileMap","wyNode",tolua_collect_wyTMXTileMap);
  #else
  tolua_cclass(tolua_S,"wyTMXTileMap","wyTMXTileMap","wyNode",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyTMXTileMap");
   tolua_function(tolua_S,"make",tolua_tmx_wyTMXTileMap_make00);
   tolua_function(tolua_S,"make",tolua_tmx_wyTMXTileMap_make01);
   tolua_function(tolua_S,"delete",tolua_tmx_wyTMXTileMap_delete00);
   tolua_function(tolua_S,"getLayer",tolua_tmx_wyTMXTileMap_getLayer00);
   tolua_function(tolua_S,"getLayerAt",tolua_tmx_wyTMXTileMap_getLayerAt00);
   tolua_function(tolua_S,"getObjectGroup",tolua_tmx_wyTMXTileMap_getObjectGroup00);
   tolua_function(tolua_S,"getProperty",tolua_tmx_wyTMXTileMap_getProperty00);
   tolua_function(tolua_S,"getTileProperty",tolua_tmx_wyTMXTileMap_getTileProperty00);
   tolua_function(tolua_S,"getMapWidth",tolua_tmx_wyTMXTileMap_getMapWidth00);
   tolua_function(tolua_S,"getMapHeight",tolua_tmx_wyTMXTileMap_getMapHeight00);
   tolua_function(tolua_S,"getTileWidth",tolua_tmx_wyTMXTileMap_getTileWidth00);
   tolua_function(tolua_S,"getTileHeight",tolua_tmx_wyTMXTileMap_getTileHeight00);
   tolua_function(tolua_S,"getOrientation",tolua_tmx_wyTMXTileMap_getOrientation00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyTMXLayer","wyTMXLayer","wySpriteBatchNode",tolua_collect_wyTMXLayer);
  #else
  tolua_cclass(tolua_S,"wyTMXLayer","wyTMXLayer","wySpriteBatchNode",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyTMXLayer");
   tolua_function(tolua_S,"make",tolua_tmx_wyTMXLayer_make00);
   tolua_function(tolua_S,"delete",tolua_tmx_wyTMXLayer_delete00);
   tolua_function(tolua_S,"removeTile",tolua_tmx_wyTMXLayer_removeTile00);
   tolua_function(tolua_S,"getProperty",tolua_tmx_wyTMXLayer_getProperty00);
   tolua_function(tolua_S,"getLayerWidth",tolua_tmx_wyTMXLayer_getLayerWidth00);
   tolua_function(tolua_S,"getLayerHeight",tolua_tmx_wyTMXLayer_getLayerHeight00);
   tolua_function(tolua_S,"getTileWidth",tolua_tmx_wyTMXLayer_getTileWidth00);
   tolua_function(tolua_S,"getTileHeight",tolua_tmx_wyTMXLayer_getTileHeight00);
   tolua_function(tolua_S,"getTileCoordinateAt",tolua_tmx_wyTMXLayer_getTileCoordinateAt00);
   tolua_function(tolua_S,"tileAt",tolua_tmx_wyTMXLayer_tileAt00);
   tolua_function(tolua_S,"getGidAt",tolua_tmx_wyTMXLayer_getGidAt00);
   tolua_function(tolua_S,"getGids",tolua_tmx_wyTMXLayer_getGids00);
   tolua_function(tolua_S,"removeTileAt",tolua_tmx_wyTMXLayer_removeTileAt00);
   tolua_function(tolua_S,"setTileAt",tolua_tmx_wyTMXLayer_setTileAt00);
   tolua_function(tolua_S,"updateTileAt",tolua_tmx_wyTMXLayer_updateTileAt00);
   tolua_function(tolua_S,"getPositionAt",tolua_tmx_wyTMXLayer_getPositionAt00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"wyTMXLoader","wyTMXLoader","",NULL);
  tolua_beginmodule(tolua_S,"wyTMXLoader");
   tolua_function(tolua_S,"load",tolua_tmx_wyTMXLoader_load00);
   tolua_function(tolua_S,"load",tolua_tmx_wyTMXLoader_load01);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_tmx (lua_State* tolua_S) {
 return tolua_tmx_open(tolua_S);
};
#endif

