/*
** Lua binding: astar
** Generated automatically by tolua++-1.0.92 on Sat Jun 11 19:17:34 2011.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_astar_open (lua_State* tolua_S);

#include "WiEngine.h"

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_wyAStar (lua_State* tolua_S)
{
 wyAStar* self = (wyAStar*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyHexagonAStarMap (lua_State* tolua_S)
{
 wyHexagonAStarMap* self = (wyHexagonAStarMap*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyAStarTile (lua_State* tolua_S)
{
 wyAStarTile* self = (wyAStarTile*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyAStarMap (lua_State* tolua_S)
{
 wyAStarMap* self = (wyAStarMap*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyRectAStarMap (lua_State* tolua_S)
{
 wyRectAStarMap* self = (wyRectAStarMap*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyAStarStep (lua_State* tolua_S)
{
 wyAStarStep* self = (wyAStarStep*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"wyAStar");
 tolua_usertype(tolua_S,"wyHexagonAStarMap");
 tolua_usertype(tolua_S,"wyAStarTile");
 tolua_usertype(tolua_S,"wyAStarMap");
 tolua_usertype(tolua_S,"wyArray");
 tolua_usertype(tolua_S,"wyObject");
 tolua_usertype(tolua_S,"wyRectAStarMap");
 tolua_usertype(tolua_S,"wyAStarStep");
}

/* method: new of class  wyAStar */
#ifndef TOLUA_DISABLE_tolua_astar_wyAStar_new00
static int tolua_astar_wyAStar_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyAStar",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyAStarMap",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAStarMap* mapdata = ((wyAStarMap*)  tolua_tousertype(tolua_S,2,0));
  {
   wyAStar* tolua_ret = (wyAStar*)  Mtolua_new((wyAStar)(mapdata));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyAStar");
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

/* method: new_local of class  wyAStar */
#ifndef TOLUA_DISABLE_tolua_astar_wyAStar_new00_local
static int tolua_astar_wyAStar_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyAStar",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyAStarMap",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAStarMap* mapdata = ((wyAStarMap*)  tolua_tousertype(tolua_S,2,0));
  {
   wyAStar* tolua_ret = (wyAStar*)  Mtolua_new((wyAStar)(mapdata));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyAStar");
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

/* method: delete of class  wyAStar */
#ifndef TOLUA_DISABLE_tolua_astar_wyAStar_delete00
static int tolua_astar_wyAStar_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAStar",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAStar* self = (wyAStar*)  tolua_tousertype(tolua_S,1,0);
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

/* method: getPath of class  wyAStar */
#ifndef TOLUA_DISABLE_tolua_astar_wyAStar_getPath00
static int tolua_astar_wyAStar_getPath00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAStar",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAStar* self = (wyAStar*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getPath'", NULL);
#endif
  {
   wyArray* tolua_ret = (wyArray*)  self->getPath();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyArray");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getPath'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: findPath of class  wyAStar */
#ifndef TOLUA_DISABLE_tolua_astar_wyAStar_findPath00
static int tolua_astar_wyAStar_findPath00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAStar",0,&tolua_err) ||
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
  wyAStar* self = (wyAStar*)  tolua_tousertype(tolua_S,1,0);
  int startx = ((int)  tolua_tonumber(tolua_S,2,0));
  int starty = ((int)  tolua_tonumber(tolua_S,3,0));
  int endx = ((int)  tolua_tonumber(tolua_S,4,0));
  int endy = ((int)  tolua_tonumber(tolua_S,5,0));
  bool ignoreBlock = ((bool)  tolua_toboolean(tolua_S,6,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'findPath'", NULL);
#endif
  {
   int tolua_ret = (int)  self->findPath(startx,starty,endx,endy,ignoreBlock);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'findPath'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getAStarMap of class  wyAStar */
#ifndef TOLUA_DISABLE_tolua_astar_wyAStar_getAStarMap00
static int tolua_astar_wyAStar_getAStarMap00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAStar",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAStar* self = (wyAStar*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getAStarMap'", NULL);
#endif
  {
   wyAStarMap* tolua_ret = (wyAStarMap*)  self->getAStarMap();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyAStarMap");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getAStarMap'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: heuristic of class  wyAStar */
#ifndef TOLUA_DISABLE_tolua_astar_wyAStar_heuristic00
static int tolua_astar_wyAStar_heuristic00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAStar",0,&tolua_err) ||
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
  wyAStar* self = (wyAStar*)  tolua_tousertype(tolua_S,1,0);
  int startx = ((int)  tolua_tonumber(tolua_S,2,0));
  int starty = ((int)  tolua_tonumber(tolua_S,3,0));
  int endx = ((int)  tolua_tonumber(tolua_S,4,0));
  int endy = ((int)  tolua_tonumber(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'heuristic'", NULL);
#endif
  {
   float tolua_ret = (float)  self->heuristic(startx,starty,endx,endy);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'heuristic'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  wyAStarMap */
#ifndef TOLUA_DISABLE_tolua_astar_wyAStarMap_delete00
static int tolua_astar_wyAStarMap_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAStarMap",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAStarMap* self = (wyAStarMap*)  tolua_tousertype(tolua_S,1,0);
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

/* method: getTileCount of class  wyAStarMap */
#ifndef TOLUA_DISABLE_tolua_astar_wyAStarMap_getTileCount00
static int tolua_astar_wyAStarMap_getTileCount00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAStarMap",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAStarMap* self = (wyAStarMap*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getTileCount'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getTileCount();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getTileCount'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: blockTile of class  wyAStarMap */
#ifndef TOLUA_DISABLE_tolua_astar_wyAStarMap_blockTile00
static int tolua_astar_wyAStarMap_blockTile00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAStarMap",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAStarMap* self = (wyAStarMap*)  tolua_tousertype(tolua_S,1,0);
  int x = ((int)  tolua_tonumber(tolua_S,2,0));
  int y = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'blockTile'", NULL);
#endif
  {
   self->blockTile(x,y);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'blockTile'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: freeTile of class  wyAStarMap */
#ifndef TOLUA_DISABLE_tolua_astar_wyAStarMap_freeTile00
static int tolua_astar_wyAStarMap_freeTile00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAStarMap",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAStarMap* self = (wyAStarMap*)  tolua_tousertype(tolua_S,1,0);
  int x = ((int)  tolua_tonumber(tolua_S,2,0));
  int y = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'freeTile'", NULL);
#endif
  {
   self->freeTile(x,y);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'freeTile'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isBlockedAt of class  wyAStarMap */
#ifndef TOLUA_DISABLE_tolua_astar_wyAStarMap_isBlockedAt00
static int tolua_astar_wyAStarMap_isBlockedAt00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAStarMap",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAStarMap* self = (wyAStarMap*)  tolua_tousertype(tolua_S,1,0);
  int x = ((int)  tolua_tonumber(tolua_S,2,0));
  int y = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isBlockedAt'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isBlockedAt(x,y);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isBlockedAt'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getTileAt of class  wyAStarMap */
#ifndef TOLUA_DISABLE_tolua_astar_wyAStarMap_getTileAt00
static int tolua_astar_wyAStarMap_getTileAt00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAStarMap",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAStarMap* self = (wyAStarMap*)  tolua_tousertype(tolua_S,1,0);
  int x = ((int)  tolua_tonumber(tolua_S,2,0));
  int y = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getTileAt'", NULL);
#endif
  {
   wyAStarTile* tolua_ret = (wyAStarTile*)  self->getTileAt(x,y);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyAStarTile");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getTileAt'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isValidTile of class  wyAStarMap */
#ifndef TOLUA_DISABLE_tolua_astar_wyAStarMap_isValidTile00
static int tolua_astar_wyAStarMap_isValidTile00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAStarMap",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAStarMap* self = (wyAStarMap*)  tolua_tousertype(tolua_S,1,0);
  int x = ((int)  tolua_tonumber(tolua_S,2,0));
  int y = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isValidTile'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isValidTile(x,y);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isValidTile'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getStepG of class  wyAStarMap */
#ifndef TOLUA_DISABLE_tolua_astar_wyAStarMap_getStepG00
static int tolua_astar_wyAStarMap_getStepG00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAStarMap",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyAStarTile",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"wyAStarTile",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAStarMap* self = (wyAStarMap*)  tolua_tousertype(tolua_S,1,0);
  wyAStarTile* t1 = ((wyAStarTile*)  tolua_tousertype(tolua_S,2,0));
  wyAStarTile* t2 = ((wyAStarTile*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getStepG'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getStepG(t1,t2);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getStepG'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  wyAStarStep */
#ifndef TOLUA_DISABLE_tolua_astar_wyAStarStep_new00
static int tolua_astar_wyAStarStep_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyAStarStep",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  int x = ((int)  tolua_tonumber(tolua_S,2,0));
  int y = ((int)  tolua_tonumber(tolua_S,3,0));
  {
   wyAStarStep* tolua_ret = (wyAStarStep*)  Mtolua_new((wyAStarStep)(x,y));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyAStarStep");
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

/* method: new_local of class  wyAStarStep */
#ifndef TOLUA_DISABLE_tolua_astar_wyAStarStep_new00_local
static int tolua_astar_wyAStarStep_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyAStarStep",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  int x = ((int)  tolua_tonumber(tolua_S,2,0));
  int y = ((int)  tolua_tonumber(tolua_S,3,0));
  {
   wyAStarStep* tolua_ret = (wyAStarStep*)  Mtolua_new((wyAStarStep)(x,y));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyAStarStep");
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

/* method: delete of class  wyAStarStep */
#ifndef TOLUA_DISABLE_tolua_astar_wyAStarStep_delete00
static int tolua_astar_wyAStarStep_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAStarStep",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAStarStep* self = (wyAStarStep*)  tolua_tousertype(tolua_S,1,0);
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

/* method: setX of class  wyAStarStep */
#ifndef TOLUA_DISABLE_tolua_astar_wyAStarStep_setX00
static int tolua_astar_wyAStarStep_setX00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAStarStep",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAStarStep* self = (wyAStarStep*)  tolua_tousertype(tolua_S,1,0);
  int x = ((int)  tolua_tonumber(tolua_S,2,0));
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

/* method: getX of class  wyAStarStep */
#ifndef TOLUA_DISABLE_tolua_astar_wyAStarStep_getX00
static int tolua_astar_wyAStarStep_getX00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAStarStep",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAStarStep* self = (wyAStarStep*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getX'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getX();
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

/* method: setY of class  wyAStarStep */
#ifndef TOLUA_DISABLE_tolua_astar_wyAStarStep_setY00
static int tolua_astar_wyAStarStep_setY00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAStarStep",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAStarStep* self = (wyAStarStep*)  tolua_tousertype(tolua_S,1,0);
  int y = ((int)  tolua_tonumber(tolua_S,2,0));
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

/* method: getY of class  wyAStarStep */
#ifndef TOLUA_DISABLE_tolua_astar_wyAStarStep_getY00
static int tolua_astar_wyAStarStep_getY00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAStarStep",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAStarStep* self = (wyAStarStep*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getY'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getY();
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

/* method: setF of class  wyAStarStep */
#ifndef TOLUA_DISABLE_tolua_astar_wyAStarStep_setF00
static int tolua_astar_wyAStarStep_setF00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAStarStep",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAStarStep* self = (wyAStarStep*)  tolua_tousertype(tolua_S,1,0);
  float f = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setF'", NULL);
#endif
  {
   self->setF(f);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setF'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getF of class  wyAStarStep */
#ifndef TOLUA_DISABLE_tolua_astar_wyAStarStep_getF00
static int tolua_astar_wyAStarStep_getF00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAStarStep",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAStarStep* self = (wyAStarStep*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getF'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getF();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getF'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setH of class  wyAStarStep */
#ifndef TOLUA_DISABLE_tolua_astar_wyAStarStep_setH00
static int tolua_astar_wyAStarStep_setH00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAStarStep",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAStarStep* self = (wyAStarStep*)  tolua_tousertype(tolua_S,1,0);
  float h = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setH'", NULL);
#endif
  {
   self->setH(h);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setH'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getH of class  wyAStarStep */
#ifndef TOLUA_DISABLE_tolua_astar_wyAStarStep_getH00
static int tolua_astar_wyAStarStep_getH00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAStarStep",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAStarStep* self = (wyAStarStep*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getH'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getH();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getH'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setG of class  wyAStarStep */
#ifndef TOLUA_DISABLE_tolua_astar_wyAStarStep_setG00
static int tolua_astar_wyAStarStep_setG00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAStarStep",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAStarStep* self = (wyAStarStep*)  tolua_tousertype(tolua_S,1,0);
  float g = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setG'", NULL);
#endif
  {
   self->setG(g);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setG'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getG of class  wyAStarStep */
#ifndef TOLUA_DISABLE_tolua_astar_wyAStarStep_getG00
static int tolua_astar_wyAStarStep_getG00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAStarStep",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAStarStep* self = (wyAStarStep*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getG'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getG();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getG'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setParent of class  wyAStarStep */
#ifndef TOLUA_DISABLE_tolua_astar_wyAStarStep_setParent00
static int tolua_astar_wyAStarStep_setParent00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAStarStep",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyAStarStep",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAStarStep* self = (wyAStarStep*)  tolua_tousertype(tolua_S,1,0);
  wyAStarStep* node = ((wyAStarStep*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setParent'", NULL);
#endif
  {
   self->setParent(node);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setParent'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getParent of class  wyAStarStep */
#ifndef TOLUA_DISABLE_tolua_astar_wyAStarStep_getParent00
static int tolua_astar_wyAStarStep_getParent00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAStarStep",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAStarStep* self = (wyAStarStep*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getParent'", NULL);
#endif
  {
   wyAStarStep* tolua_ret = (wyAStarStep*)  self->getParent();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyAStarStep");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getParent'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  wyAStarTile */
#ifndef TOLUA_DISABLE_tolua_astar_wyAStarTile_new00
static int tolua_astar_wyAStarTile_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyAStarTile",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  int type = ((int)  tolua_tonumber(tolua_S,2,0));
  int x = ((int)  tolua_tonumber(tolua_S,3,0));
  int y = ((int)  tolua_tonumber(tolua_S,4,0));
  {
   wyAStarTile* tolua_ret = (wyAStarTile*)  Mtolua_new((wyAStarTile)(type,x,y));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyAStarTile");
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

/* method: new_local of class  wyAStarTile */
#ifndef TOLUA_DISABLE_tolua_astar_wyAStarTile_new00_local
static int tolua_astar_wyAStarTile_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyAStarTile",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  int type = ((int)  tolua_tonumber(tolua_S,2,0));
  int x = ((int)  tolua_tonumber(tolua_S,3,0));
  int y = ((int)  tolua_tonumber(tolua_S,4,0));
  {
   wyAStarTile* tolua_ret = (wyAStarTile*)  Mtolua_new((wyAStarTile)(type,x,y));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyAStarTile");
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

/* method: delete of class  wyAStarTile */
#ifndef TOLUA_DISABLE_tolua_astar_wyAStarTile_delete00
static int tolua_astar_wyAStarTile_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAStarTile",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAStarTile* self = (wyAStarTile*)  tolua_tousertype(tolua_S,1,0);
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

/* method: getGRate of class  wyAStarTile */
#ifndef TOLUA_DISABLE_tolua_astar_wyAStarTile_getGRate00
static int tolua_astar_wyAStarTile_getGRate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAStarTile",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAStarTile* self = (wyAStarTile*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getGRate'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getGRate();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getGRate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setGRate of class  wyAStarTile */
#ifndef TOLUA_DISABLE_tolua_astar_wyAStarTile_setGRate00
static int tolua_astar_wyAStarTile_setGRate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAStarTile",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAStarTile* self = (wyAStarTile*)  tolua_tousertype(tolua_S,1,0);
  float gRate = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setGRate'", NULL);
#endif
  {
   self->setGRate(gRate);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setGRate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getX of class  wyAStarTile */
#ifndef TOLUA_DISABLE_tolua_astar_wyAStarTile_getX00
static int tolua_astar_wyAStarTile_getX00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAStarTile",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAStarTile* self = (wyAStarTile*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getX'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getX();
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

/* method: getY of class  wyAStarTile */
#ifndef TOLUA_DISABLE_tolua_astar_wyAStarTile_getY00
static int tolua_astar_wyAStarTile_getY00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAStarTile",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAStarTile* self = (wyAStarTile*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getY'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getY();
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

/* method: getType of class  wyAStarTile */
#ifndef TOLUA_DISABLE_tolua_astar_wyAStarTile_getType00
static int tolua_astar_wyAStarTile_getType00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAStarTile",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAStarTile* self = (wyAStarTile*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getType'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getType();
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

/* method: setType of class  wyAStarTile */
#ifndef TOLUA_DISABLE_tolua_astar_wyAStarTile_setType00
static int tolua_astar_wyAStarTile_setType00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAStarTile",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAStarTile* self = (wyAStarTile*)  tolua_tousertype(tolua_S,1,0);
  int type = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setType'", NULL);
#endif
  {
   self->setType(type);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setType'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isBlocked of class  wyAStarTile */
#ifndef TOLUA_DISABLE_tolua_astar_wyAStarTile_isBlocked00
static int tolua_astar_wyAStarTile_isBlocked00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAStarTile",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAStarTile* self = (wyAStarTile*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isBlocked'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isBlocked();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isBlocked'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isFree of class  wyAStarTile */
#ifndef TOLUA_DISABLE_tolua_astar_wyAStarTile_isFree00
static int tolua_astar_wyAStarTile_isFree00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAStarTile",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAStarTile* self = (wyAStarTile*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isFree'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isFree();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isFree'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: pushChild of class  wyAStarTile */
#ifndef TOLUA_DISABLE_tolua_astar_wyAStarTile_pushChild00
static int tolua_astar_wyAStarTile_pushChild00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAStarTile",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyAStarTile",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAStarTile* self = (wyAStarTile*)  tolua_tousertype(tolua_S,1,0);
  wyAStarTile* tile = ((wyAStarTile*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'pushChild'", NULL);
#endif
  {
   self->pushChild(tile);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'pushChild'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getChilds of class  wyAStarTile */
#ifndef TOLUA_DISABLE_tolua_astar_wyAStarTile_getChilds00
static int tolua_astar_wyAStarTile_getChilds00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAStarTile",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAStarTile* self = (wyAStarTile*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getChilds'", NULL);
#endif
  {
   wyArray* tolua_ret = (wyArray*)  self->getChilds();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyArray");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getChilds'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  wyHexagonAStarMap */
#ifndef TOLUA_DISABLE_tolua_astar_wyHexagonAStarMap_new00
static int tolua_astar_wyHexagonAStarMap_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyHexagonAStarMap",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  int width = ((int)  tolua_tonumber(tolua_S,2,0));
  int height = ((int)  tolua_tonumber(tolua_S,3,0));
  {
   wyHexagonAStarMap* tolua_ret = (wyHexagonAStarMap*)  Mtolua_new((wyHexagonAStarMap)(width,height));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyHexagonAStarMap");
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

/* method: new_local of class  wyHexagonAStarMap */
#ifndef TOLUA_DISABLE_tolua_astar_wyHexagonAStarMap_new00_local
static int tolua_astar_wyHexagonAStarMap_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyHexagonAStarMap",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  int width = ((int)  tolua_tonumber(tolua_S,2,0));
  int height = ((int)  tolua_tonumber(tolua_S,3,0));
  {
   wyHexagonAStarMap* tolua_ret = (wyHexagonAStarMap*)  Mtolua_new((wyHexagonAStarMap)(width,height));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyHexagonAStarMap");
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

/* method: delete of class  wyHexagonAStarMap */
#ifndef TOLUA_DISABLE_tolua_astar_wyHexagonAStarMap_delete00
static int tolua_astar_wyHexagonAStarMap_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyHexagonAStarMap",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyHexagonAStarMap* self = (wyHexagonAStarMap*)  tolua_tousertype(tolua_S,1,0);
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

/* method: isValidTile of class  wyHexagonAStarMap */
#ifndef TOLUA_DISABLE_tolua_astar_wyHexagonAStarMap_isValidTile00
static int tolua_astar_wyHexagonAStarMap_isValidTile00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyHexagonAStarMap",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyHexagonAStarMap* self = (wyHexagonAStarMap*)  tolua_tousertype(tolua_S,1,0);
  int x = ((int)  tolua_tonumber(tolua_S,2,0));
  int y = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isValidTile'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isValidTile(x,y);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isValidTile'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getStepG of class  wyHexagonAStarMap */
#ifndef TOLUA_DISABLE_tolua_astar_wyHexagonAStarMap_getStepG00
static int tolua_astar_wyHexagonAStarMap_getStepG00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyHexagonAStarMap",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyAStarTile",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"wyAStarTile",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyHexagonAStarMap* self = (wyHexagonAStarMap*)  tolua_tousertype(tolua_S,1,0);
  wyAStarTile* t1 = ((wyAStarTile*)  tolua_tousertype(tolua_S,2,0));
  wyAStarTile* t2 = ((wyAStarTile*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getStepG'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getStepG(t1,t2);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getStepG'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  wyRectAStarMap */
#ifndef TOLUA_DISABLE_tolua_astar_wyRectAStarMap_new00
static int tolua_astar_wyRectAStarMap_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyRectAStarMap",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  int width = ((int)  tolua_tonumber(tolua_S,2,0));
  int height = ((int)  tolua_tonumber(tolua_S,3,0));
  bool isAllowDiagonal = ((bool)  tolua_toboolean(tolua_S,4,0));
  {
   wyRectAStarMap* tolua_ret = (wyRectAStarMap*)  Mtolua_new((wyRectAStarMap)(width,height,isAllowDiagonal));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyRectAStarMap");
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

/* method: new_local of class  wyRectAStarMap */
#ifndef TOLUA_DISABLE_tolua_astar_wyRectAStarMap_new00_local
static int tolua_astar_wyRectAStarMap_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyRectAStarMap",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  int width = ((int)  tolua_tonumber(tolua_S,2,0));
  int height = ((int)  tolua_tonumber(tolua_S,3,0));
  bool isAllowDiagonal = ((bool)  tolua_toboolean(tolua_S,4,0));
  {
   wyRectAStarMap* tolua_ret = (wyRectAStarMap*)  Mtolua_new((wyRectAStarMap)(width,height,isAllowDiagonal));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyRectAStarMap");
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

/* method: delete of class  wyRectAStarMap */
#ifndef TOLUA_DISABLE_tolua_astar_wyRectAStarMap_delete00
static int tolua_astar_wyRectAStarMap_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyRectAStarMap",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyRectAStarMap* self = (wyRectAStarMap*)  tolua_tousertype(tolua_S,1,0);
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

/* method: isValidTile of class  wyRectAStarMap */
#ifndef TOLUA_DISABLE_tolua_astar_wyRectAStarMap_isValidTile00
static int tolua_astar_wyRectAStarMap_isValidTile00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyRectAStarMap",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyRectAStarMap* self = (wyRectAStarMap*)  tolua_tousertype(tolua_S,1,0);
  int x = ((int)  tolua_tonumber(tolua_S,2,0));
  int y = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isValidTile'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isValidTile(x,y);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isValidTile'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getStepG of class  wyRectAStarMap */
#ifndef TOLUA_DISABLE_tolua_astar_wyRectAStarMap_getStepG00
static int tolua_astar_wyRectAStarMap_getStepG00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyRectAStarMap",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyAStarTile",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"wyAStarTile",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyRectAStarMap* self = (wyRectAStarMap*)  tolua_tousertype(tolua_S,1,0);
  wyAStarTile* t1 = ((wyAStarTile*)  tolua_tousertype(tolua_S,2,0));
  wyAStarTile* t2 = ((wyAStarTile*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getStepG'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getStepG(t1,t2);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getStepG'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_astar_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyAStar","wyAStar","wyObject",tolua_collect_wyAStar);
  #else
  tolua_cclass(tolua_S,"wyAStar","wyAStar","wyObject",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyAStar");
   tolua_function(tolua_S,"new",tolua_astar_wyAStar_new00);
   tolua_function(tolua_S,"new_local",tolua_astar_wyAStar_new00_local);
   tolua_function(tolua_S,".call",tolua_astar_wyAStar_new00_local);
   tolua_function(tolua_S,"delete",tolua_astar_wyAStar_delete00);
   tolua_function(tolua_S,"getPath",tolua_astar_wyAStar_getPath00);
   tolua_function(tolua_S,"findPath",tolua_astar_wyAStar_findPath00);
   tolua_function(tolua_S,"getAStarMap",tolua_astar_wyAStar_getAStarMap00);
   tolua_function(tolua_S,"heuristic",tolua_astar_wyAStar_heuristic00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyAStarMap","wyAStarMap","wyObject",tolua_collect_wyAStarMap);
  #else
  tolua_cclass(tolua_S,"wyAStarMap","wyAStarMap","wyObject",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyAStarMap");
   tolua_function(tolua_S,"delete",tolua_astar_wyAStarMap_delete00);
   tolua_function(tolua_S,"getTileCount",tolua_astar_wyAStarMap_getTileCount00);
   tolua_function(tolua_S,"blockTile",tolua_astar_wyAStarMap_blockTile00);
   tolua_function(tolua_S,"freeTile",tolua_astar_wyAStarMap_freeTile00);
   tolua_function(tolua_S,"isBlockedAt",tolua_astar_wyAStarMap_isBlockedAt00);
   tolua_function(tolua_S,"getTileAt",tolua_astar_wyAStarMap_getTileAt00);
   tolua_function(tolua_S,"isValidTile",tolua_astar_wyAStarMap_isValidTile00);
   tolua_function(tolua_S,"getStepG",tolua_astar_wyAStarMap_getStepG00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyAStarStep","wyAStarStep","wyObject",tolua_collect_wyAStarStep);
  #else
  tolua_cclass(tolua_S,"wyAStarStep","wyAStarStep","wyObject",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyAStarStep");
   tolua_function(tolua_S,"new",tolua_astar_wyAStarStep_new00);
   tolua_function(tolua_S,"new_local",tolua_astar_wyAStarStep_new00_local);
   tolua_function(tolua_S,".call",tolua_astar_wyAStarStep_new00_local);
   tolua_function(tolua_S,"delete",tolua_astar_wyAStarStep_delete00);
   tolua_function(tolua_S,"setX",tolua_astar_wyAStarStep_setX00);
   tolua_function(tolua_S,"getX",tolua_astar_wyAStarStep_getX00);
   tolua_function(tolua_S,"setY",tolua_astar_wyAStarStep_setY00);
   tolua_function(tolua_S,"getY",tolua_astar_wyAStarStep_getY00);
   tolua_function(tolua_S,"setF",tolua_astar_wyAStarStep_setF00);
   tolua_function(tolua_S,"getF",tolua_astar_wyAStarStep_getF00);
   tolua_function(tolua_S,"setH",tolua_astar_wyAStarStep_setH00);
   tolua_function(tolua_S,"getH",tolua_astar_wyAStarStep_getH00);
   tolua_function(tolua_S,"setG",tolua_astar_wyAStarStep_setG00);
   tolua_function(tolua_S,"getG",tolua_astar_wyAStarStep_getG00);
   tolua_function(tolua_S,"setParent",tolua_astar_wyAStarStep_setParent00);
   tolua_function(tolua_S,"getParent",tolua_astar_wyAStarStep_getParent00);
  tolua_endmodule(tolua_S);
  tolua_constant(tolua_S,"TILE_FREE",TILE_FREE);
  tolua_constant(tolua_S,"TILE_BLOCKED",TILE_BLOCKED);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyAStarTile","wyAStarTile","wyObject",tolua_collect_wyAStarTile);
  #else
  tolua_cclass(tolua_S,"wyAStarTile","wyAStarTile","wyObject",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyAStarTile");
   tolua_function(tolua_S,"new",tolua_astar_wyAStarTile_new00);
   tolua_function(tolua_S,"new_local",tolua_astar_wyAStarTile_new00_local);
   tolua_function(tolua_S,".call",tolua_astar_wyAStarTile_new00_local);
   tolua_function(tolua_S,"delete",tolua_astar_wyAStarTile_delete00);
   tolua_function(tolua_S,"getGRate",tolua_astar_wyAStarTile_getGRate00);
   tolua_function(tolua_S,"setGRate",tolua_astar_wyAStarTile_setGRate00);
   tolua_function(tolua_S,"getX",tolua_astar_wyAStarTile_getX00);
   tolua_function(tolua_S,"getY",tolua_astar_wyAStarTile_getY00);
   tolua_function(tolua_S,"getType",tolua_astar_wyAStarTile_getType00);
   tolua_function(tolua_S,"setType",tolua_astar_wyAStarTile_setType00);
   tolua_function(tolua_S,"isBlocked",tolua_astar_wyAStarTile_isBlocked00);
   tolua_function(tolua_S,"isFree",tolua_astar_wyAStarTile_isFree00);
   tolua_function(tolua_S,"pushChild",tolua_astar_wyAStarTile_pushChild00);
   tolua_function(tolua_S,"getChilds",tolua_astar_wyAStarTile_getChilds00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyHexagonAStarMap","wyHexagonAStarMap","wyAStarMap",tolua_collect_wyHexagonAStarMap);
  #else
  tolua_cclass(tolua_S,"wyHexagonAStarMap","wyHexagonAStarMap","wyAStarMap",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyHexagonAStarMap");
   tolua_function(tolua_S,"new",tolua_astar_wyHexagonAStarMap_new00);
   tolua_function(tolua_S,"new_local",tolua_astar_wyHexagonAStarMap_new00_local);
   tolua_function(tolua_S,".call",tolua_astar_wyHexagonAStarMap_new00_local);
   tolua_function(tolua_S,"delete",tolua_astar_wyHexagonAStarMap_delete00);
   tolua_function(tolua_S,"isValidTile",tolua_astar_wyHexagonAStarMap_isValidTile00);
   tolua_function(tolua_S,"getStepG",tolua_astar_wyHexagonAStarMap_getStepG00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyRectAStarMap","wyRectAStarMap","wyAStarMap",tolua_collect_wyRectAStarMap);
  #else
  tolua_cclass(tolua_S,"wyRectAStarMap","wyRectAStarMap","wyAStarMap",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyRectAStarMap");
   tolua_function(tolua_S,"new",tolua_astar_wyRectAStarMap_new00);
   tolua_function(tolua_S,"new_local",tolua_astar_wyRectAStarMap_new00_local);
   tolua_function(tolua_S,".call",tolua_astar_wyRectAStarMap_new00_local);
   tolua_function(tolua_S,"delete",tolua_astar_wyRectAStarMap_delete00);
   tolua_function(tolua_S,"isValidTile",tolua_astar_wyRectAStarMap_isValidTile00);
   tolua_function(tolua_S,"getStepG",tolua_astar_wyRectAStarMap_getStepG00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_astar (lua_State* tolua_S) {
 return tolua_astar_open(tolua_S);
};
#endif

