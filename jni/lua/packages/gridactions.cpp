/*
** Lua binding: gridactions
** Generated automatically by tolua++-1.0.92 on Sun Sep 25 18:24:12 2011.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_gridactions_open (lua_State* tolua_S);

#include "WiEngine.h"

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_wyShaky3D (lua_State* tolua_S)
{
 wyShaky3D* self = (wyShaky3D*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyWaves (lua_State* tolua_S)
{
 wyWaves* self = (wyWaves*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyLens3D (lua_State* tolua_S)
{
 wyLens3D* self = (wyLens3D*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyWaves3D (lua_State* tolua_S)
{
 wyWaves3D* self = (wyWaves3D*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyBottomLineShrinkOut (lua_State* tolua_S)
{
 wyBottomLineShrinkOut* self = (wyBottomLineShrinkOut*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyTiledGrid3DAction (lua_State* tolua_S)
{
 wyTiledGrid3DAction* self = (wyTiledGrid3DAction*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wySplitCols (lua_State* tolua_S)
{
 wySplitCols* self = (wySplitCols*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyWavesTiles3D (lua_State* tolua_S)
{
 wyWavesTiles3D* self = (wyWavesTiles3D*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyGridAction (lua_State* tolua_S)
{
 wyGridAction* self = (wyGridAction*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyGrid3DAction (lua_State* tolua_S)
{
 wyGrid3DAction* self = (wyGrid3DAction*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyLeftBottomTilesShrinkOut (lua_State* tolua_S)
{
 wyLeftBottomTilesShrinkOut* self = (wyLeftBottomTilesShrinkOut*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyShakyTiles3D (lua_State* tolua_S)
{
 wyShakyTiles3D* self = (wyShakyTiles3D*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyJumpTiles3D (lua_State* tolua_S)
{
 wyJumpTiles3D* self = (wyJumpTiles3D*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyRightLineShrinkOut (lua_State* tolua_S)
{
 wyRightLineShrinkOut* self = (wyRightLineShrinkOut*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyTurnOffTiles (lua_State* tolua_S)
{
 wyTurnOffTiles* self = (wyTurnOffTiles*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyRightTopTilesShrinkOut (lua_State* tolua_S)
{
 wyRightTopTilesShrinkOut* self = (wyRightTopTilesShrinkOut*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyTopLineShrinkOut (lua_State* tolua_S)
{
 wyTopLineShrinkOut* self = (wyTopLineShrinkOut*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyRipple3D (lua_State* tolua_S)
{
 wyRipple3D* self = (wyRipple3D*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyShuffleTiles (lua_State* tolua_S)
{
 wyShuffleTiles* self = (wyShuffleTiles*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyStopGrid (lua_State* tolua_S)
{
 wyStopGrid* self = (wyStopGrid*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyVertex3D (lua_State* tolua_S)
{
 wyVertex3D* self = (wyVertex3D*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wySuck (lua_State* tolua_S)
{
 wySuck* self = (wySuck*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyTopTilesShrinkOut (lua_State* tolua_S)
{
 wyTopTilesShrinkOut* self = (wyTopTilesShrinkOut*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyBottomTilesShrinkOut (lua_State* tolua_S)
{
 wyBottomTilesShrinkOut* self = (wyBottomTilesShrinkOut*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyGridFlipY (lua_State* tolua_S)
{
 wyGridFlipY* self = (wyGridFlipY*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyTwirl (lua_State* tolua_S)
{
 wyTwirl* self = (wyTwirl*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyGridFlipX (lua_State* tolua_S)
{
 wyGridFlipX* self = (wyGridFlipX*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyPageTurn3D (lua_State* tolua_S)
{
 wyPageTurn3D* self = (wyPageTurn3D*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyReuseGrid (lua_State* tolua_S)
{
 wyReuseGrid* self = (wyReuseGrid*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyQuad3D (lua_State* tolua_S)
{
 wyQuad3D* self = (wyQuad3D*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyLeftLineShrinkOut (lua_State* tolua_S)
{
 wyLeftLineShrinkOut* self = (wyLeftLineShrinkOut*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyShatteredTiles3D (lua_State* tolua_S)
{
 wyShatteredTiles3D* self = (wyShatteredTiles3D*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wySplitRows (lua_State* tolua_S)
{
 wySplitRows* self = (wySplitRows*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyLiquid (lua_State* tolua_S)
{
 wyLiquid* self = (wyLiquid*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"wyShaky3D");
 tolua_usertype(tolua_S,"wyWaves");
 tolua_usertype(tolua_S,"wyLens3D");
 tolua_usertype(tolua_S,"wyWaves3D");
 tolua_usertype(tolua_S,"wyBottomLineShrinkOut");
 tolua_usertype(tolua_S,"wyTiledGrid3DAction");
 tolua_usertype(tolua_S,"wySplitCols");
 tolua_usertype(tolua_S,"wyIntervalAction");
 tolua_usertype(tolua_S,"wyGridAction");
 tolua_usertype(tolua_S,"wyGrid3DAction");
 tolua_usertype(tolua_S,"wyLeftBottomTilesShrinkOut");
 tolua_usertype(tolua_S,"wyShakyTiles3D");
 tolua_usertype(tolua_S,"wyJumpTiles3D");
 tolua_usertype(tolua_S,"wyRightLineShrinkOut");
 tolua_usertype(tolua_S,"wyGridFlipY");
 tolua_usertype(tolua_S,"wyAction");
 tolua_usertype(tolua_S,"wyRightTopTilesShrinkOut");
 tolua_usertype(tolua_S,"wyReuseGrid");
 tolua_usertype(tolua_S,"wyPoint");
 tolua_usertype(tolua_S,"wyRipple3D");
 tolua_usertype(tolua_S,"wyTopLineShrinkOut");
 tolua_usertype(tolua_S,"wyShuffleTiles");
 tolua_usertype(tolua_S,"wyWavesTiles3D");
 tolua_usertype(tolua_S,"wyStopGrid");
 tolua_usertype(tolua_S,"wyTwirl");
 tolua_usertype(tolua_S,"wyTurnOffTiles");
 tolua_usertype(tolua_S,"wyVertex3D");
 tolua_usertype(tolua_S,"wyTile");
 tolua_usertype(tolua_S,"wySuck");
 tolua_usertype(tolua_S,"wyQuad3D");
 tolua_usertype(tolua_S,"wyTopTilesShrinkOut");
 tolua_usertype(tolua_S,"wyBottomTilesShrinkOut");
 tolua_usertype(tolua_S,"wyLeftLineShrinkOut");
 tolua_usertype(tolua_S,"wyBaseGrid");
 tolua_usertype(tolua_S,"wyGridFlipX");
 tolua_usertype(tolua_S,"wyPageTurn3D");
 tolua_usertype(tolua_S,"wyShatteredTiles3D");
 tolua_usertype(tolua_S,"wyDimension");
 tolua_usertype(tolua_S,"wyNode");
 tolua_usertype(tolua_S,"wyInstantAction");
 tolua_usertype(tolua_S,"wySplitRows");
 tolua_usertype(tolua_S,"wyLiquid");
}

/* method: make of class  wyBottomLineShrinkOut */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyBottomLineShrinkOut_make00
static int tolua_gridactions_wyBottomLineShrinkOut_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyBottomLineShrinkOut",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  int gridX = ((int)  tolua_tonumber(tolua_S,3,0));
  int gridY = ((int)  tolua_tonumber(tolua_S,4,0));
  {
   wyBottomLineShrinkOut* tolua_ret = (wyBottomLineShrinkOut*)  wyBottomLineShrinkOut::make(duration,gridX,gridY);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyBottomLineShrinkOut");
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

/* method: new of class  wyBottomLineShrinkOut */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyBottomLineShrinkOut_new00
static int tolua_gridactions_wyBottomLineShrinkOut_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyBottomLineShrinkOut",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  int gridX = ((int)  tolua_tonumber(tolua_S,3,0));
  int gridY = ((int)  tolua_tonumber(tolua_S,4,0));
  {
   wyBottomLineShrinkOut* tolua_ret = (wyBottomLineShrinkOut*)  Mtolua_new((wyBottomLineShrinkOut)(duration,gridX,gridY));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyBottomLineShrinkOut");
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

/* method: new_local of class  wyBottomLineShrinkOut */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyBottomLineShrinkOut_new00_local
static int tolua_gridactions_wyBottomLineShrinkOut_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyBottomLineShrinkOut",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  int gridX = ((int)  tolua_tonumber(tolua_S,3,0));
  int gridY = ((int)  tolua_tonumber(tolua_S,4,0));
  {
   wyBottomLineShrinkOut* tolua_ret = (wyBottomLineShrinkOut*)  Mtolua_new((wyBottomLineShrinkOut)(duration,gridX,gridY));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyBottomLineShrinkOut");
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

/* method: delete of class  wyBottomLineShrinkOut */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyBottomLineShrinkOut_delete00
static int tolua_gridactions_wyBottomLineShrinkOut_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyBottomLineShrinkOut",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyBottomLineShrinkOut* self = (wyBottomLineShrinkOut*)  tolua_tousertype(tolua_S,1,0);
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

/* method: copy of class  wyBottomLineShrinkOut */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyBottomLineShrinkOut_copy00
static int tolua_gridactions_wyBottomLineShrinkOut_copy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyBottomLineShrinkOut",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyBottomLineShrinkOut* self = (wyBottomLineShrinkOut*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'copy'", NULL);
#endif
  {
   wyAction* tolua_ret = (wyAction*)  self->copy();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyAction");
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

/* method: update of class  wyBottomLineShrinkOut */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyBottomLineShrinkOut_update00
static int tolua_gridactions_wyBottomLineShrinkOut_update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyBottomLineShrinkOut",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyBottomLineShrinkOut* self = (wyBottomLineShrinkOut*)  tolua_tousertype(tolua_S,1,0);
  float t = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'update'", NULL);
#endif
  {
   self->update(t);
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

/* method: make of class  wyBottomTilesShrinkOut */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyBottomTilesShrinkOut_make00
static int tolua_gridactions_wyBottomTilesShrinkOut_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyBottomTilesShrinkOut",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  int gridX = ((int)  tolua_tonumber(tolua_S,3,0));
  int gridY = ((int)  tolua_tonumber(tolua_S,4,0));
  {
   wyBottomTilesShrinkOut* tolua_ret = (wyBottomTilesShrinkOut*)  wyBottomTilesShrinkOut::make(duration,gridX,gridY);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyBottomTilesShrinkOut");
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

/* method: new of class  wyBottomTilesShrinkOut */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyBottomTilesShrinkOut_new00
static int tolua_gridactions_wyBottomTilesShrinkOut_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyBottomTilesShrinkOut",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  int gridX = ((int)  tolua_tonumber(tolua_S,3,0));
  int gridY = ((int)  tolua_tonumber(tolua_S,4,0));
  {
   wyBottomTilesShrinkOut* tolua_ret = (wyBottomTilesShrinkOut*)  Mtolua_new((wyBottomTilesShrinkOut)(duration,gridX,gridY));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyBottomTilesShrinkOut");
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

/* method: new_local of class  wyBottomTilesShrinkOut */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyBottomTilesShrinkOut_new00_local
static int tolua_gridactions_wyBottomTilesShrinkOut_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyBottomTilesShrinkOut",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  int gridX = ((int)  tolua_tonumber(tolua_S,3,0));
  int gridY = ((int)  tolua_tonumber(tolua_S,4,0));
  {
   wyBottomTilesShrinkOut* tolua_ret = (wyBottomTilesShrinkOut*)  Mtolua_new((wyBottomTilesShrinkOut)(duration,gridX,gridY));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyBottomTilesShrinkOut");
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

/* method: delete of class  wyBottomTilesShrinkOut */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyBottomTilesShrinkOut_delete00
static int tolua_gridactions_wyBottomTilesShrinkOut_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyBottomTilesShrinkOut",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyBottomTilesShrinkOut* self = (wyBottomTilesShrinkOut*)  tolua_tousertype(tolua_S,1,0);
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

/* method: copy of class  wyBottomTilesShrinkOut */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyBottomTilesShrinkOut_copy00
static int tolua_gridactions_wyBottomTilesShrinkOut_copy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyBottomTilesShrinkOut",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyBottomTilesShrinkOut* self = (wyBottomTilesShrinkOut*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'copy'", NULL);
#endif
  {
   wyAction* tolua_ret = (wyAction*)  self->copy();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyAction");
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

/* method: update of class  wyBottomTilesShrinkOut */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyBottomTilesShrinkOut_update00
static int tolua_gridactions_wyBottomTilesShrinkOut_update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyBottomTilesShrinkOut",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyBottomTilesShrinkOut* self = (wyBottomTilesShrinkOut*)  tolua_tousertype(tolua_S,1,0);
  float t = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'update'", NULL);
#endif
  {
   self->update(t);
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

/* method: new of class  wyGrid3DAction */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyGrid3DAction_new00
static int tolua_gridactions_wyGrid3DAction_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyGrid3DAction",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  float gridX = ((float)  tolua_tonumber(tolua_S,3,0));
  float gridY = ((float)  tolua_tonumber(tolua_S,4,0));
  {
   wyGrid3DAction* tolua_ret = (wyGrid3DAction*)  Mtolua_new((wyGrid3DAction)(duration,gridX,gridY));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyGrid3DAction");
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

/* method: new_local of class  wyGrid3DAction */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyGrid3DAction_new00_local
static int tolua_gridactions_wyGrid3DAction_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyGrid3DAction",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  float gridX = ((float)  tolua_tonumber(tolua_S,3,0));
  float gridY = ((float)  tolua_tonumber(tolua_S,4,0));
  {
   wyGrid3DAction* tolua_ret = (wyGrid3DAction*)  Mtolua_new((wyGrid3DAction)(duration,gridX,gridY));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyGrid3DAction");
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

/* method: delete of class  wyGrid3DAction */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyGrid3DAction_delete00
static int tolua_gridactions_wyGrid3DAction_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyGrid3DAction",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyGrid3DAction* self = (wyGrid3DAction*)  tolua_tousertype(tolua_S,1,0);
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

/* method: makeGrid of class  wyGrid3DAction */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyGrid3DAction_makeGrid00
static int tolua_gridactions_wyGrid3DAction_makeGrid00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyGrid3DAction",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyGrid3DAction* self = (wyGrid3DAction*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'makeGrid'", NULL);
#endif
  {
   wyBaseGrid* tolua_ret = (wyBaseGrid*)  self->makeGrid();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyBaseGrid");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'makeGrid'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isGridReusable of class  wyGrid3DAction */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyGrid3DAction_isGridReusable00
static int tolua_gridactions_wyGrid3DAction_isGridReusable00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyGrid3DAction",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyBaseGrid",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyGrid3DAction* self = (wyGrid3DAction*)  tolua_tousertype(tolua_S,1,0);
  wyBaseGrid* grid = ((wyBaseGrid*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isGridReusable'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isGridReusable(grid);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isGridReusable'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getVertex of class  wyGrid3DAction */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyGrid3DAction_getVertex00
static int tolua_gridactions_wyGrid3DAction_getVertex00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyGrid3DAction",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"wyDimension",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyGrid3DAction* self = (wyGrid3DAction*)  tolua_tousertype(tolua_S,1,0);
  wyDimension pos = *((wyDimension*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getVertex'", NULL);
#endif
  {
   wyVertex3D tolua_ret = (wyVertex3D)  self->getVertex(pos);
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
 tolua_error(tolua_S,"#ferror in function 'getVertex'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getOriginalVertex of class  wyGrid3DAction */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyGrid3DAction_getOriginalVertex00
static int tolua_gridactions_wyGrid3DAction_getOriginalVertex00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyGrid3DAction",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"wyDimension",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyGrid3DAction* self = (wyGrid3DAction*)  tolua_tousertype(tolua_S,1,0);
  wyDimension pos = *((wyDimension*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getOriginalVertex'", NULL);
#endif
  {
   wyVertex3D tolua_ret = (wyVertex3D)  self->getOriginalVertex(pos);
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
 tolua_error(tolua_S,"#ferror in function 'getOriginalVertex'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setVertex of class  wyGrid3DAction */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyGrid3DAction_setVertex00
static int tolua_gridactions_wyGrid3DAction_setVertex00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyGrid3DAction",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"wyDimension",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"wyVertex3D",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyGrid3DAction* self = (wyGrid3DAction*)  tolua_tousertype(tolua_S,1,0);
  wyDimension pos = *((wyDimension*)  tolua_tousertype(tolua_S,2,0));
  wyVertex3D vertex = *((wyVertex3D*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setVertex'", NULL);
#endif
  {
   self->setVertex(pos,vertex);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setVertex'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  wyGridAction */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyGridAction_delete00
static int tolua_gridactions_wyGridAction_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyGridAction",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyGridAction* self = (wyGridAction*)  tolua_tousertype(tolua_S,1,0);
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

/* method: makeGrid of class  wyGridAction */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyGridAction_makeGrid00
static int tolua_gridactions_wyGridAction_makeGrid00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyGridAction",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyGridAction* self = (wyGridAction*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'makeGrid'", NULL);
#endif
  {
   wyBaseGrid* tolua_ret = (wyBaseGrid*)  self->makeGrid();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyBaseGrid");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'makeGrid'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isGridReusable of class  wyGridAction */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyGridAction_isGridReusable00
static int tolua_gridactions_wyGridAction_isGridReusable00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyGridAction",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyBaseGrid",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyGridAction* self = (wyGridAction*)  tolua_tousertype(tolua_S,1,0);
  wyBaseGrid* grid = ((wyBaseGrid*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isGridReusable'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isGridReusable(grid);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isGridReusable'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: reverse of class  wyGridAction */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyGridAction_reverse00
static int tolua_gridactions_wyGridAction_reverse00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyGridAction",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyGridAction* self = (wyGridAction*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'reverse'", NULL);
#endif
  {
   wyAction* tolua_ret = (wyAction*)  self->reverse();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyAction");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'reverse'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: start of class  wyGridAction */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyGridAction_start00
static int tolua_gridactions_wyGridAction_start00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyGridAction",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyGridAction* self = (wyGridAction*)  tolua_tousertype(tolua_S,1,0);
  wyNode* target = ((wyNode*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'start'", NULL);
#endif
  {
   self->start(target);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'start'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setAmplitude of class  wyGridAction */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyGridAction_setAmplitude00
static int tolua_gridactions_wyGridAction_setAmplitude00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyGridAction",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyGridAction* self = (wyGridAction*)  tolua_tousertype(tolua_S,1,0);
  float amp = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setAmplitude'", NULL);
#endif
  {
   self->setAmplitude(amp);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setAmplitude'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setAmplitudeRate of class  wyGridAction */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyGridAction_setAmplitudeRate00
static int tolua_gridactions_wyGridAction_setAmplitudeRate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyGridAction",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyGridAction* self = (wyGridAction*)  tolua_tousertype(tolua_S,1,0);
  float ar = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setAmplitudeRate'", NULL);
#endif
  {
   self->setAmplitudeRate(ar);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setAmplitudeRate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getAmplitude of class  wyGridAction */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyGridAction_getAmplitude00
static int tolua_gridactions_wyGridAction_getAmplitude00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyGridAction",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyGridAction* self = (wyGridAction*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getAmplitude'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getAmplitude();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getAmplitude'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getAmplitudeRate of class  wyGridAction */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyGridAction_getAmplitudeRate00
static int tolua_gridactions_wyGridAction_getAmplitudeRate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyGridAction",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyGridAction* self = (wyGridAction*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getAmplitudeRate'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getAmplitudeRate();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getAmplitudeRate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getGridX of class  wyGridAction */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyGridAction_getGridX00
static int tolua_gridactions_wyGridAction_getGridX00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyGridAction",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyGridAction* self = (wyGridAction*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getGridX'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getGridX();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getGridX'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getGridY of class  wyGridAction */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyGridAction_getGridY00
static int tolua_gridactions_wyGridAction_getGridY00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyGridAction",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyGridAction* self = (wyGridAction*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getGridY'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getGridY();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getGridY'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: make of class  wyGridFlipX */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyGridFlipX_make00
static int tolua_gridactions_wyGridFlipX_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyGridFlipX",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  {
   wyGridFlipX* tolua_ret = (wyGridFlipX*)  wyGridFlipX::make(duration);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyGridFlipX");
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

/* method: new of class  wyGridFlipX */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyGridFlipX_new00
static int tolua_gridactions_wyGridFlipX_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyGridFlipX",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  {
   wyGridFlipX* tolua_ret = (wyGridFlipX*)  Mtolua_new((wyGridFlipX)(duration));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyGridFlipX");
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

/* method: new_local of class  wyGridFlipX */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyGridFlipX_new00_local
static int tolua_gridactions_wyGridFlipX_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyGridFlipX",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  {
   wyGridFlipX* tolua_ret = (wyGridFlipX*)  Mtolua_new((wyGridFlipX)(duration));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyGridFlipX");
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

/* method: delete of class  wyGridFlipX */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyGridFlipX_delete00
static int tolua_gridactions_wyGridFlipX_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyGridFlipX",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyGridFlipX* self = (wyGridFlipX*)  tolua_tousertype(tolua_S,1,0);
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

/* method: copy of class  wyGridFlipX */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyGridFlipX_copy00
static int tolua_gridactions_wyGridFlipX_copy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyGridFlipX",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyGridFlipX* self = (wyGridFlipX*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'copy'", NULL);
#endif
  {
   wyAction* tolua_ret = (wyAction*)  self->copy();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyAction");
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

/* method: update of class  wyGridFlipX */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyGridFlipX_update00
static int tolua_gridactions_wyGridFlipX_update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyGridFlipX",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyGridFlipX* self = (wyGridFlipX*)  tolua_tousertype(tolua_S,1,0);
  float t = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'update'", NULL);
#endif
  {
   self->update(t);
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

/* method: make of class  wyGridFlipY */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyGridFlipY_make00
static int tolua_gridactions_wyGridFlipY_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyGridFlipY",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  {
   wyGridFlipY* tolua_ret = (wyGridFlipY*)  wyGridFlipY::make(duration);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyGridFlipY");
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

/* method: new of class  wyGridFlipY */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyGridFlipY_new00
static int tolua_gridactions_wyGridFlipY_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyGridFlipY",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  {
   wyGridFlipY* tolua_ret = (wyGridFlipY*)  Mtolua_new((wyGridFlipY)(duration));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyGridFlipY");
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

/* method: new_local of class  wyGridFlipY */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyGridFlipY_new00_local
static int tolua_gridactions_wyGridFlipY_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyGridFlipY",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  {
   wyGridFlipY* tolua_ret = (wyGridFlipY*)  Mtolua_new((wyGridFlipY)(duration));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyGridFlipY");
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

/* method: delete of class  wyGridFlipY */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyGridFlipY_delete00
static int tolua_gridactions_wyGridFlipY_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyGridFlipY",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyGridFlipY* self = (wyGridFlipY*)  tolua_tousertype(tolua_S,1,0);
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

/* method: copy of class  wyGridFlipY */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyGridFlipY_copy00
static int tolua_gridactions_wyGridFlipY_copy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyGridFlipY",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyGridFlipY* self = (wyGridFlipY*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'copy'", NULL);
#endif
  {
   wyAction* tolua_ret = (wyAction*)  self->copy();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyAction");
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

/* method: update of class  wyGridFlipY */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyGridFlipY_update00
static int tolua_gridactions_wyGridFlipY_update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyGridFlipY",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyGridFlipY* self = (wyGridFlipY*)  tolua_tousertype(tolua_S,1,0);
  float t = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'update'", NULL);
#endif
  {
   self->update(t);
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

/* method: make of class  wyJumpTiles3D */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyJumpTiles3D_make00
static int tolua_gridactions_wyJumpTiles3D_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyJumpTiles3D",0,&tolua_err) ||
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
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  int gridX = ((int)  tolua_tonumber(tolua_S,3,0));
  int gridY = ((int)  tolua_tonumber(tolua_S,4,0));
  float amplitude = ((float)  tolua_tonumber(tolua_S,5,0));
  int jumps = ((int)  tolua_tonumber(tolua_S,6,0));
  {
   wyJumpTiles3D* tolua_ret = (wyJumpTiles3D*)  wyJumpTiles3D::make(duration,gridX,gridY,amplitude,jumps);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyJumpTiles3D");
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

/* method: new of class  wyJumpTiles3D */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyJumpTiles3D_new00
static int tolua_gridactions_wyJumpTiles3D_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyJumpTiles3D",0,&tolua_err) ||
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
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  int gridX = ((int)  tolua_tonumber(tolua_S,3,0));
  int gridY = ((int)  tolua_tonumber(tolua_S,4,0));
  float amplitude = ((float)  tolua_tonumber(tolua_S,5,0));
  int jumps = ((int)  tolua_tonumber(tolua_S,6,0));
  {
   wyJumpTiles3D* tolua_ret = (wyJumpTiles3D*)  Mtolua_new((wyJumpTiles3D)(duration,gridX,gridY,amplitude,jumps));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyJumpTiles3D");
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

/* method: new_local of class  wyJumpTiles3D */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyJumpTiles3D_new00_local
static int tolua_gridactions_wyJumpTiles3D_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyJumpTiles3D",0,&tolua_err) ||
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
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  int gridX = ((int)  tolua_tonumber(tolua_S,3,0));
  int gridY = ((int)  tolua_tonumber(tolua_S,4,0));
  float amplitude = ((float)  tolua_tonumber(tolua_S,5,0));
  int jumps = ((int)  tolua_tonumber(tolua_S,6,0));
  {
   wyJumpTiles3D* tolua_ret = (wyJumpTiles3D*)  Mtolua_new((wyJumpTiles3D)(duration,gridX,gridY,amplitude,jumps));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyJumpTiles3D");
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

/* method: delete of class  wyJumpTiles3D */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyJumpTiles3D_delete00
static int tolua_gridactions_wyJumpTiles3D_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyJumpTiles3D",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyJumpTiles3D* self = (wyJumpTiles3D*)  tolua_tousertype(tolua_S,1,0);
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

/* method: copy of class  wyJumpTiles3D */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyJumpTiles3D_copy00
static int tolua_gridactions_wyJumpTiles3D_copy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyJumpTiles3D",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyJumpTiles3D* self = (wyJumpTiles3D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'copy'", NULL);
#endif
  {
   wyAction* tolua_ret = (wyAction*)  self->copy();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyAction");
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

/* method: update of class  wyJumpTiles3D */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyJumpTiles3D_update00
static int tolua_gridactions_wyJumpTiles3D_update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyJumpTiles3D",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyJumpTiles3D* self = (wyJumpTiles3D*)  tolua_tousertype(tolua_S,1,0);
  float t = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'update'", NULL);
#endif
  {
   self->update(t);
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

/* method: make of class  wyLeftBottomTilesShrinkOut */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyLeftBottomTilesShrinkOut_make00
static int tolua_gridactions_wyLeftBottomTilesShrinkOut_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyLeftBottomTilesShrinkOut",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  int gridX = ((int)  tolua_tonumber(tolua_S,3,0));
  int gridY = ((int)  tolua_tonumber(tolua_S,4,0));
  {
   wyLeftBottomTilesShrinkOut* tolua_ret = (wyLeftBottomTilesShrinkOut*)  wyLeftBottomTilesShrinkOut::make(duration,gridX,gridY);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyLeftBottomTilesShrinkOut");
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

/* method: new of class  wyLeftBottomTilesShrinkOut */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyLeftBottomTilesShrinkOut_new00
static int tolua_gridactions_wyLeftBottomTilesShrinkOut_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyLeftBottomTilesShrinkOut",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  int gridX = ((int)  tolua_tonumber(tolua_S,3,0));
  int gridY = ((int)  tolua_tonumber(tolua_S,4,0));
  {
   wyLeftBottomTilesShrinkOut* tolua_ret = (wyLeftBottomTilesShrinkOut*)  Mtolua_new((wyLeftBottomTilesShrinkOut)(duration,gridX,gridY));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyLeftBottomTilesShrinkOut");
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

/* method: new_local of class  wyLeftBottomTilesShrinkOut */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyLeftBottomTilesShrinkOut_new00_local
static int tolua_gridactions_wyLeftBottomTilesShrinkOut_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyLeftBottomTilesShrinkOut",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  int gridX = ((int)  tolua_tonumber(tolua_S,3,0));
  int gridY = ((int)  tolua_tonumber(tolua_S,4,0));
  {
   wyLeftBottomTilesShrinkOut* tolua_ret = (wyLeftBottomTilesShrinkOut*)  Mtolua_new((wyLeftBottomTilesShrinkOut)(duration,gridX,gridY));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyLeftBottomTilesShrinkOut");
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

/* method: delete of class  wyLeftBottomTilesShrinkOut */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyLeftBottomTilesShrinkOut_delete00
static int tolua_gridactions_wyLeftBottomTilesShrinkOut_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyLeftBottomTilesShrinkOut",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyLeftBottomTilesShrinkOut* self = (wyLeftBottomTilesShrinkOut*)  tolua_tousertype(tolua_S,1,0);
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

/* method: copy of class  wyLeftBottomTilesShrinkOut */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyLeftBottomTilesShrinkOut_copy00
static int tolua_gridactions_wyLeftBottomTilesShrinkOut_copy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyLeftBottomTilesShrinkOut",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyLeftBottomTilesShrinkOut* self = (wyLeftBottomTilesShrinkOut*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'copy'", NULL);
#endif
  {
   wyAction* tolua_ret = (wyAction*)  self->copy();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyAction");
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

/* method: update of class  wyLeftBottomTilesShrinkOut */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyLeftBottomTilesShrinkOut_update00
static int tolua_gridactions_wyLeftBottomTilesShrinkOut_update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyLeftBottomTilesShrinkOut",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyLeftBottomTilesShrinkOut* self = (wyLeftBottomTilesShrinkOut*)  tolua_tousertype(tolua_S,1,0);
  float t = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'update'", NULL);
#endif
  {
   self->update(t);
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

/* method: make of class  wyLeftLineShrinkOut */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyLeftLineShrinkOut_make00
static int tolua_gridactions_wyLeftLineShrinkOut_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyLeftLineShrinkOut",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  int gridX = ((int)  tolua_tonumber(tolua_S,3,0));
  int gridY = ((int)  tolua_tonumber(tolua_S,4,0));
  {
   wyLeftLineShrinkOut* tolua_ret = (wyLeftLineShrinkOut*)  wyLeftLineShrinkOut::make(duration,gridX,gridY);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyLeftLineShrinkOut");
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

/* method: new of class  wyLeftLineShrinkOut */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyLeftLineShrinkOut_new00
static int tolua_gridactions_wyLeftLineShrinkOut_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyLeftLineShrinkOut",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  int gridX = ((int)  tolua_tonumber(tolua_S,3,0));
  int gridY = ((int)  tolua_tonumber(tolua_S,4,0));
  {
   wyLeftLineShrinkOut* tolua_ret = (wyLeftLineShrinkOut*)  Mtolua_new((wyLeftLineShrinkOut)(duration,gridX,gridY));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyLeftLineShrinkOut");
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

/* method: new_local of class  wyLeftLineShrinkOut */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyLeftLineShrinkOut_new00_local
static int tolua_gridactions_wyLeftLineShrinkOut_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyLeftLineShrinkOut",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  int gridX = ((int)  tolua_tonumber(tolua_S,3,0));
  int gridY = ((int)  tolua_tonumber(tolua_S,4,0));
  {
   wyLeftLineShrinkOut* tolua_ret = (wyLeftLineShrinkOut*)  Mtolua_new((wyLeftLineShrinkOut)(duration,gridX,gridY));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyLeftLineShrinkOut");
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

/* method: delete of class  wyLeftLineShrinkOut */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyLeftLineShrinkOut_delete00
static int tolua_gridactions_wyLeftLineShrinkOut_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyLeftLineShrinkOut",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyLeftLineShrinkOut* self = (wyLeftLineShrinkOut*)  tolua_tousertype(tolua_S,1,0);
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

/* method: copy of class  wyLeftLineShrinkOut */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyLeftLineShrinkOut_copy00
static int tolua_gridactions_wyLeftLineShrinkOut_copy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyLeftLineShrinkOut",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyLeftLineShrinkOut* self = (wyLeftLineShrinkOut*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'copy'", NULL);
#endif
  {
   wyAction* tolua_ret = (wyAction*)  self->copy();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyAction");
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

/* method: update of class  wyLeftLineShrinkOut */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyLeftLineShrinkOut_update00
static int tolua_gridactions_wyLeftLineShrinkOut_update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyLeftLineShrinkOut",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyLeftLineShrinkOut* self = (wyLeftLineShrinkOut*)  tolua_tousertype(tolua_S,1,0);
  float t = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'update'", NULL);
#endif
  {
   self->update(t);
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

/* method: make of class  wyLens3D */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyLens3D_make00
static int tolua_gridactions_wyLens3D_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyLens3D",0,&tolua_err) ||
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
     !tolua_isnoobj(tolua_S,12,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  int gridX = ((int)  tolua_tonumber(tolua_S,3,0));
  int gridY = ((int)  tolua_tonumber(tolua_S,4,0));
  float centerX = ((float)  tolua_tonumber(tolua_S,5,0));
  float centerY = ((float)  tolua_tonumber(tolua_S,6,0));
  float deltaX = ((float)  tolua_tonumber(tolua_S,7,0));
  float deltaY = ((float)  tolua_tonumber(tolua_S,8,0));
  float radius = ((float)  tolua_tonumber(tolua_S,9,0));
  float deltaRadius = ((float)  tolua_tonumber(tolua_S,10,0));
  float lensEffect = ((float)  tolua_tonumber(tolua_S,11,0));
  {
   wyLens3D* tolua_ret = (wyLens3D*)  wyLens3D::make(duration,gridX,gridY,centerX,centerY,deltaX,deltaY,radius,deltaRadius,lensEffect);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyLens3D");
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

/* method: new of class  wyLens3D */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyLens3D_new00
static int tolua_gridactions_wyLens3D_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyLens3D",0,&tolua_err) ||
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
     !tolua_isnoobj(tolua_S,12,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  int gridX = ((int)  tolua_tonumber(tolua_S,3,0));
  int gridY = ((int)  tolua_tonumber(tolua_S,4,0));
  float centerX = ((float)  tolua_tonumber(tolua_S,5,0));
  float centerY = ((float)  tolua_tonumber(tolua_S,6,0));
  float deltaX = ((float)  tolua_tonumber(tolua_S,7,0));
  float deltaY = ((float)  tolua_tonumber(tolua_S,8,0));
  float radius = ((float)  tolua_tonumber(tolua_S,9,0));
  float deltaRadius = ((float)  tolua_tonumber(tolua_S,10,0));
  float lensEffect = ((float)  tolua_tonumber(tolua_S,11,0));
  {
   wyLens3D* tolua_ret = (wyLens3D*)  Mtolua_new((wyLens3D)(duration,gridX,gridY,centerX,centerY,deltaX,deltaY,radius,deltaRadius,lensEffect));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyLens3D");
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

/* method: new_local of class  wyLens3D */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyLens3D_new00_local
static int tolua_gridactions_wyLens3D_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyLens3D",0,&tolua_err) ||
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
     !tolua_isnoobj(tolua_S,12,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  int gridX = ((int)  tolua_tonumber(tolua_S,3,0));
  int gridY = ((int)  tolua_tonumber(tolua_S,4,0));
  float centerX = ((float)  tolua_tonumber(tolua_S,5,0));
  float centerY = ((float)  tolua_tonumber(tolua_S,6,0));
  float deltaX = ((float)  tolua_tonumber(tolua_S,7,0));
  float deltaY = ((float)  tolua_tonumber(tolua_S,8,0));
  float radius = ((float)  tolua_tonumber(tolua_S,9,0));
  float deltaRadius = ((float)  tolua_tonumber(tolua_S,10,0));
  float lensEffect = ((float)  tolua_tonumber(tolua_S,11,0));
  {
   wyLens3D* tolua_ret = (wyLens3D*)  Mtolua_new((wyLens3D)(duration,gridX,gridY,centerX,centerY,deltaX,deltaY,radius,deltaRadius,lensEffect));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyLens3D");
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

/* method: delete of class  wyLens3D */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyLens3D_delete00
static int tolua_gridactions_wyLens3D_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyLens3D",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyLens3D* self = (wyLens3D*)  tolua_tousertype(tolua_S,1,0);
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

/* method: copy of class  wyLens3D */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyLens3D_copy00
static int tolua_gridactions_wyLens3D_copy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyLens3D",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyLens3D* self = (wyLens3D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'copy'", NULL);
#endif
  {
   wyAction* tolua_ret = (wyAction*)  self->copy();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyAction");
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

/* method: update of class  wyLens3D */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyLens3D_update00
static int tolua_gridactions_wyLens3D_update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyLens3D",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyLens3D* self = (wyLens3D*)  tolua_tousertype(tolua_S,1,0);
  float t = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'update'", NULL);
#endif
  {
   self->update(t);
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

/* method: make of class  wyLiquid */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyLiquid_make00
static int tolua_gridactions_wyLiquid_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyLiquid",0,&tolua_err) ||
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
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  int gridX = ((int)  tolua_tonumber(tolua_S,3,0));
  int gridY = ((int)  tolua_tonumber(tolua_S,4,0));
  float amplitude = ((float)  tolua_tonumber(tolua_S,5,0));
  float deltaAmplitude = ((float)  tolua_tonumber(tolua_S,6,0));
  float waves = ((float)  tolua_tonumber(tolua_S,7,0));
  {
   wyLiquid* tolua_ret = (wyLiquid*)  wyLiquid::make(duration,gridX,gridY,amplitude,deltaAmplitude,waves);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyLiquid");
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

/* method: new of class  wyLiquid */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyLiquid_new00
static int tolua_gridactions_wyLiquid_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyLiquid",0,&tolua_err) ||
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
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  int gridX = ((int)  tolua_tonumber(tolua_S,3,0));
  int gridY = ((int)  tolua_tonumber(tolua_S,4,0));
  float amplitude = ((float)  tolua_tonumber(tolua_S,5,0));
  float deltaAmplitude = ((float)  tolua_tonumber(tolua_S,6,0));
  float waves = ((float)  tolua_tonumber(tolua_S,7,0));
  {
   wyLiquid* tolua_ret = (wyLiquid*)  Mtolua_new((wyLiquid)(duration,gridX,gridY,amplitude,deltaAmplitude,waves));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyLiquid");
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

/* method: new_local of class  wyLiquid */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyLiquid_new00_local
static int tolua_gridactions_wyLiquid_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyLiquid",0,&tolua_err) ||
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
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  int gridX = ((int)  tolua_tonumber(tolua_S,3,0));
  int gridY = ((int)  tolua_tonumber(tolua_S,4,0));
  float amplitude = ((float)  tolua_tonumber(tolua_S,5,0));
  float deltaAmplitude = ((float)  tolua_tonumber(tolua_S,6,0));
  float waves = ((float)  tolua_tonumber(tolua_S,7,0));
  {
   wyLiquid* tolua_ret = (wyLiquid*)  Mtolua_new((wyLiquid)(duration,gridX,gridY,amplitude,deltaAmplitude,waves));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyLiquid");
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

/* method: delete of class  wyLiquid */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyLiquid_delete00
static int tolua_gridactions_wyLiquid_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyLiquid",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyLiquid* self = (wyLiquid*)  tolua_tousertype(tolua_S,1,0);
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

/* method: copy of class  wyLiquid */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyLiquid_copy00
static int tolua_gridactions_wyLiquid_copy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyLiquid",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyLiquid* self = (wyLiquid*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'copy'", NULL);
#endif
  {
   wyAction* tolua_ret = (wyAction*)  self->copy();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyAction");
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

/* method: update of class  wyLiquid */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyLiquid_update00
static int tolua_gridactions_wyLiquid_update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyLiquid",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyLiquid* self = (wyLiquid*)  tolua_tousertype(tolua_S,1,0);
  float t = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'update'", NULL);
#endif
  {
   self->update(t);
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

/* method: make of class  wyPageTurn3D */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyPageTurn3D_make00
static int tolua_gridactions_wyPageTurn3D_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyPageTurn3D",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  int gridX = ((int)  tolua_tonumber(tolua_S,3,0));
  int gridY = ((int)  tolua_tonumber(tolua_S,4,0));
  {
   wyPageTurn3D* tolua_ret = (wyPageTurn3D*)  wyPageTurn3D::make(duration,gridX,gridY);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyPageTurn3D");
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

/* method: new of class  wyPageTurn3D */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyPageTurn3D_new00
static int tolua_gridactions_wyPageTurn3D_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyPageTurn3D",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  int gridX = ((int)  tolua_tonumber(tolua_S,3,0));
  int gridY = ((int)  tolua_tonumber(tolua_S,4,0));
  {
   wyPageTurn3D* tolua_ret = (wyPageTurn3D*)  Mtolua_new((wyPageTurn3D)(duration,gridX,gridY));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyPageTurn3D");
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

/* method: new_local of class  wyPageTurn3D */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyPageTurn3D_new00_local
static int tolua_gridactions_wyPageTurn3D_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyPageTurn3D",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  int gridX = ((int)  tolua_tonumber(tolua_S,3,0));
  int gridY = ((int)  tolua_tonumber(tolua_S,4,0));
  {
   wyPageTurn3D* tolua_ret = (wyPageTurn3D*)  Mtolua_new((wyPageTurn3D)(duration,gridX,gridY));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyPageTurn3D");
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

/* method: delete of class  wyPageTurn3D */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyPageTurn3D_delete00
static int tolua_gridactions_wyPageTurn3D_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyPageTurn3D",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyPageTurn3D* self = (wyPageTurn3D*)  tolua_tousertype(tolua_S,1,0);
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

/* method: copy of class  wyPageTurn3D */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyPageTurn3D_copy00
static int tolua_gridactions_wyPageTurn3D_copy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyPageTurn3D",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyPageTurn3D* self = (wyPageTurn3D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'copy'", NULL);
#endif
  {
   wyAction* tolua_ret = (wyAction*)  self->copy();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyAction");
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

/* method: update of class  wyPageTurn3D */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyPageTurn3D_update00
static int tolua_gridactions_wyPageTurn3D_update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyPageTurn3D",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyPageTurn3D* self = (wyPageTurn3D*)  tolua_tousertype(tolua_S,1,0);
  float t = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'update'", NULL);
#endif
  {
   self->update(t);
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

/* method: make of class  wyReuseGrid */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyReuseGrid_make00
static int tolua_gridactions_wyReuseGrid_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyReuseGrid",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  int times = ((int)  tolua_tonumber(tolua_S,2,0));
  {
   wyReuseGrid* tolua_ret = (wyReuseGrid*)  wyReuseGrid::make(times);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyReuseGrid");
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

/* method: new of class  wyReuseGrid */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyReuseGrid_new00
static int tolua_gridactions_wyReuseGrid_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyReuseGrid",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  int times = ((int)  tolua_tonumber(tolua_S,2,0));
  {
   wyReuseGrid* tolua_ret = (wyReuseGrid*)  Mtolua_new((wyReuseGrid)(times));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyReuseGrid");
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

/* method: new_local of class  wyReuseGrid */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyReuseGrid_new00_local
static int tolua_gridactions_wyReuseGrid_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyReuseGrid",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  int times = ((int)  tolua_tonumber(tolua_S,2,0));
  {
   wyReuseGrid* tolua_ret = (wyReuseGrid*)  Mtolua_new((wyReuseGrid)(times));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyReuseGrid");
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

/* method: delete of class  wyReuseGrid */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyReuseGrid_delete00
static int tolua_gridactions_wyReuseGrid_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyReuseGrid",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyReuseGrid* self = (wyReuseGrid*)  tolua_tousertype(tolua_S,1,0);
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

/* method: copy of class  wyReuseGrid */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyReuseGrid_copy00
static int tolua_gridactions_wyReuseGrid_copy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyReuseGrid",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyReuseGrid* self = (wyReuseGrid*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'copy'", NULL);
#endif
  {
   wyAction* tolua_ret = (wyAction*)  self->copy();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyAction");
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

/* method: reverse of class  wyReuseGrid */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyReuseGrid_reverse00
static int tolua_gridactions_wyReuseGrid_reverse00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyReuseGrid",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyReuseGrid* self = (wyReuseGrid*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'reverse'", NULL);
#endif
  {
   wyAction* tolua_ret = (wyAction*)  self->reverse();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyAction");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'reverse'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: start of class  wyReuseGrid */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyReuseGrid_start00
static int tolua_gridactions_wyReuseGrid_start00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyReuseGrid",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyReuseGrid* self = (wyReuseGrid*)  tolua_tousertype(tolua_S,1,0);
  wyNode* target = ((wyNode*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'start'", NULL);
#endif
  {
   self->start(target);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'start'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: make of class  wyRightLineShrinkOut */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyRightLineShrinkOut_make00
static int tolua_gridactions_wyRightLineShrinkOut_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyRightLineShrinkOut",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  int gridX = ((int)  tolua_tonumber(tolua_S,3,0));
  int gridY = ((int)  tolua_tonumber(tolua_S,4,0));
  {
   wyRightLineShrinkOut* tolua_ret = (wyRightLineShrinkOut*)  wyRightLineShrinkOut::make(duration,gridX,gridY);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyRightLineShrinkOut");
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

/* method: new of class  wyRightLineShrinkOut */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyRightLineShrinkOut_new00
static int tolua_gridactions_wyRightLineShrinkOut_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyRightLineShrinkOut",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  int gridX = ((int)  tolua_tonumber(tolua_S,3,0));
  int gridY = ((int)  tolua_tonumber(tolua_S,4,0));
  {
   wyRightLineShrinkOut* tolua_ret = (wyRightLineShrinkOut*)  Mtolua_new((wyRightLineShrinkOut)(duration,gridX,gridY));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyRightLineShrinkOut");
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

/* method: new_local of class  wyRightLineShrinkOut */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyRightLineShrinkOut_new00_local
static int tolua_gridactions_wyRightLineShrinkOut_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyRightLineShrinkOut",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  int gridX = ((int)  tolua_tonumber(tolua_S,3,0));
  int gridY = ((int)  tolua_tonumber(tolua_S,4,0));
  {
   wyRightLineShrinkOut* tolua_ret = (wyRightLineShrinkOut*)  Mtolua_new((wyRightLineShrinkOut)(duration,gridX,gridY));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyRightLineShrinkOut");
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

/* method: delete of class  wyRightLineShrinkOut */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyRightLineShrinkOut_delete00
static int tolua_gridactions_wyRightLineShrinkOut_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyRightLineShrinkOut",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyRightLineShrinkOut* self = (wyRightLineShrinkOut*)  tolua_tousertype(tolua_S,1,0);
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

/* method: copy of class  wyRightLineShrinkOut */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyRightLineShrinkOut_copy00
static int tolua_gridactions_wyRightLineShrinkOut_copy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyRightLineShrinkOut",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyRightLineShrinkOut* self = (wyRightLineShrinkOut*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'copy'", NULL);
#endif
  {
   wyAction* tolua_ret = (wyAction*)  self->copy();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyAction");
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

/* method: update of class  wyRightLineShrinkOut */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyRightLineShrinkOut_update00
static int tolua_gridactions_wyRightLineShrinkOut_update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyRightLineShrinkOut",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyRightLineShrinkOut* self = (wyRightLineShrinkOut*)  tolua_tousertype(tolua_S,1,0);
  float t = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'update'", NULL);
#endif
  {
   self->update(t);
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

/* method: make of class  wyRightTopTilesShrinkOut */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyRightTopTilesShrinkOut_make00
static int tolua_gridactions_wyRightTopTilesShrinkOut_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyRightTopTilesShrinkOut",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  int gridX = ((int)  tolua_tonumber(tolua_S,3,0));
  int gridY = ((int)  tolua_tonumber(tolua_S,4,0));
  {
   wyRightTopTilesShrinkOut* tolua_ret = (wyRightTopTilesShrinkOut*)  wyRightTopTilesShrinkOut::make(duration,gridX,gridY);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyRightTopTilesShrinkOut");
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

/* method: new of class  wyRightTopTilesShrinkOut */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyRightTopTilesShrinkOut_new00
static int tolua_gridactions_wyRightTopTilesShrinkOut_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyRightTopTilesShrinkOut",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  int gridX = ((int)  tolua_tonumber(tolua_S,3,0));
  int gridY = ((int)  tolua_tonumber(tolua_S,4,0));
  {
   wyRightTopTilesShrinkOut* tolua_ret = (wyRightTopTilesShrinkOut*)  Mtolua_new((wyRightTopTilesShrinkOut)(duration,gridX,gridY));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyRightTopTilesShrinkOut");
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

/* method: new_local of class  wyRightTopTilesShrinkOut */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyRightTopTilesShrinkOut_new00_local
static int tolua_gridactions_wyRightTopTilesShrinkOut_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyRightTopTilesShrinkOut",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  int gridX = ((int)  tolua_tonumber(tolua_S,3,0));
  int gridY = ((int)  tolua_tonumber(tolua_S,4,0));
  {
   wyRightTopTilesShrinkOut* tolua_ret = (wyRightTopTilesShrinkOut*)  Mtolua_new((wyRightTopTilesShrinkOut)(duration,gridX,gridY));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyRightTopTilesShrinkOut");
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

/* method: delete of class  wyRightTopTilesShrinkOut */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyRightTopTilesShrinkOut_delete00
static int tolua_gridactions_wyRightTopTilesShrinkOut_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyRightTopTilesShrinkOut",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyRightTopTilesShrinkOut* self = (wyRightTopTilesShrinkOut*)  tolua_tousertype(tolua_S,1,0);
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

/* method: copy of class  wyRightTopTilesShrinkOut */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyRightTopTilesShrinkOut_copy00
static int tolua_gridactions_wyRightTopTilesShrinkOut_copy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyRightTopTilesShrinkOut",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyRightTopTilesShrinkOut* self = (wyRightTopTilesShrinkOut*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'copy'", NULL);
#endif
  {
   wyAction* tolua_ret = (wyAction*)  self->copy();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyAction");
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

/* method: update of class  wyRightTopTilesShrinkOut */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyRightTopTilesShrinkOut_update00
static int tolua_gridactions_wyRightTopTilesShrinkOut_update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyRightTopTilesShrinkOut",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyRightTopTilesShrinkOut* self = (wyRightTopTilesShrinkOut*)  tolua_tousertype(tolua_S,1,0);
  float t = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'update'", NULL);
#endif
  {
   self->update(t);
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

/* method: make of class  wyRipple3D */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyRipple3D_make00
static int tolua_gridactions_wyRipple3D_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyRipple3D",0,&tolua_err) ||
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
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  int gridX = ((int)  tolua_tonumber(tolua_S,3,0));
  int gridY = ((int)  tolua_tonumber(tolua_S,4,0));
  float centerX = ((float)  tolua_tonumber(tolua_S,5,0));
  float centerY = ((float)  tolua_tonumber(tolua_S,6,0));
  float deltaX = ((float)  tolua_tonumber(tolua_S,7,0));
  float deltaY = ((float)  tolua_tonumber(tolua_S,8,0));
  float radius = ((float)  tolua_tonumber(tolua_S,9,0));
  float deltaRadius = ((float)  tolua_tonumber(tolua_S,10,0));
  float amplitude = ((float)  tolua_tonumber(tolua_S,11,0));
  float deltaAmplitude = ((float)  tolua_tonumber(tolua_S,12,0));
  float waves = ((float)  tolua_tonumber(tolua_S,13,0));
  {
   wyRipple3D* tolua_ret = (wyRipple3D*)  wyRipple3D::make(duration,gridX,gridY,centerX,centerY,deltaX,deltaY,radius,deltaRadius,amplitude,deltaAmplitude,waves);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyRipple3D");
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

/* method: new of class  wyRipple3D */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyRipple3D_new00
static int tolua_gridactions_wyRipple3D_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyRipple3D",0,&tolua_err) ||
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
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  int gridX = ((int)  tolua_tonumber(tolua_S,3,0));
  int gridY = ((int)  tolua_tonumber(tolua_S,4,0));
  float centerX = ((float)  tolua_tonumber(tolua_S,5,0));
  float centerY = ((float)  tolua_tonumber(tolua_S,6,0));
  float deltaX = ((float)  tolua_tonumber(tolua_S,7,0));
  float deltaY = ((float)  tolua_tonumber(tolua_S,8,0));
  float radius = ((float)  tolua_tonumber(tolua_S,9,0));
  float deltaRadius = ((float)  tolua_tonumber(tolua_S,10,0));
  float amplitude = ((float)  tolua_tonumber(tolua_S,11,0));
  float deltaAmplitude = ((float)  tolua_tonumber(tolua_S,12,0));
  float waves = ((float)  tolua_tonumber(tolua_S,13,0));
  {
   wyRipple3D* tolua_ret = (wyRipple3D*)  Mtolua_new((wyRipple3D)(duration,gridX,gridY,centerX,centerY,deltaX,deltaY,radius,deltaRadius,amplitude,deltaAmplitude,waves));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyRipple3D");
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

/* method: new_local of class  wyRipple3D */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyRipple3D_new00_local
static int tolua_gridactions_wyRipple3D_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyRipple3D",0,&tolua_err) ||
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
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  int gridX = ((int)  tolua_tonumber(tolua_S,3,0));
  int gridY = ((int)  tolua_tonumber(tolua_S,4,0));
  float centerX = ((float)  tolua_tonumber(tolua_S,5,0));
  float centerY = ((float)  tolua_tonumber(tolua_S,6,0));
  float deltaX = ((float)  tolua_tonumber(tolua_S,7,0));
  float deltaY = ((float)  tolua_tonumber(tolua_S,8,0));
  float radius = ((float)  tolua_tonumber(tolua_S,9,0));
  float deltaRadius = ((float)  tolua_tonumber(tolua_S,10,0));
  float amplitude = ((float)  tolua_tonumber(tolua_S,11,0));
  float deltaAmplitude = ((float)  tolua_tonumber(tolua_S,12,0));
  float waves = ((float)  tolua_tonumber(tolua_S,13,0));
  {
   wyRipple3D* tolua_ret = (wyRipple3D*)  Mtolua_new((wyRipple3D)(duration,gridX,gridY,centerX,centerY,deltaX,deltaY,radius,deltaRadius,amplitude,deltaAmplitude,waves));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyRipple3D");
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

/* method: delete of class  wyRipple3D */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyRipple3D_delete00
static int tolua_gridactions_wyRipple3D_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyRipple3D",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyRipple3D* self = (wyRipple3D*)  tolua_tousertype(tolua_S,1,0);
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

/* method: copy of class  wyRipple3D */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyRipple3D_copy00
static int tolua_gridactions_wyRipple3D_copy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyRipple3D",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyRipple3D* self = (wyRipple3D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'copy'", NULL);
#endif
  {
   wyAction* tolua_ret = (wyAction*)  self->copy();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyAction");
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

/* method: update of class  wyRipple3D */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyRipple3D_update00
static int tolua_gridactions_wyRipple3D_update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyRipple3D",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyRipple3D* self = (wyRipple3D*)  tolua_tousertype(tolua_S,1,0);
  float t = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'update'", NULL);
#endif
  {
   self->update(t);
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

/* method: make of class  wyShaky3D */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyShaky3D_make00
static int tolua_gridactions_wyShaky3D_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyShaky3D",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,7,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,8,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  int gridX = ((int)  tolua_tonumber(tolua_S,3,0));
  int gridY = ((int)  tolua_tonumber(tolua_S,4,0));
  int range = ((int)  tolua_tonumber(tolua_S,5,0));
  int deltaRange = ((int)  tolua_tonumber(tolua_S,6,0));
  bool shakeZ = ((bool)  tolua_toboolean(tolua_S,7,0));
  {
   wyShaky3D* tolua_ret = (wyShaky3D*)  wyShaky3D::make(duration,gridX,gridY,range,deltaRange,shakeZ);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyShaky3D");
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

/* method: new of class  wyShaky3D */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyShaky3D_new00
static int tolua_gridactions_wyShaky3D_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyShaky3D",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,7,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,8,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  int gridX = ((int)  tolua_tonumber(tolua_S,3,0));
  int gridY = ((int)  tolua_tonumber(tolua_S,4,0));
  int range = ((int)  tolua_tonumber(tolua_S,5,0));
  int deltaRange = ((int)  tolua_tonumber(tolua_S,6,0));
  bool shakeZ = ((bool)  tolua_toboolean(tolua_S,7,0));
  {
   wyShaky3D* tolua_ret = (wyShaky3D*)  Mtolua_new((wyShaky3D)(duration,gridX,gridY,range,deltaRange,shakeZ));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyShaky3D");
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

/* method: new_local of class  wyShaky3D */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyShaky3D_new00_local
static int tolua_gridactions_wyShaky3D_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyShaky3D",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,7,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,8,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  int gridX = ((int)  tolua_tonumber(tolua_S,3,0));
  int gridY = ((int)  tolua_tonumber(tolua_S,4,0));
  int range = ((int)  tolua_tonumber(tolua_S,5,0));
  int deltaRange = ((int)  tolua_tonumber(tolua_S,6,0));
  bool shakeZ = ((bool)  tolua_toboolean(tolua_S,7,0));
  {
   wyShaky3D* tolua_ret = (wyShaky3D*)  Mtolua_new((wyShaky3D)(duration,gridX,gridY,range,deltaRange,shakeZ));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyShaky3D");
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

/* method: delete of class  wyShaky3D */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyShaky3D_delete00
static int tolua_gridactions_wyShaky3D_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyShaky3D",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyShaky3D* self = (wyShaky3D*)  tolua_tousertype(tolua_S,1,0);
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

/* method: copy of class  wyShaky3D */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyShaky3D_copy00
static int tolua_gridactions_wyShaky3D_copy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyShaky3D",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyShaky3D* self = (wyShaky3D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'copy'", NULL);
#endif
  {
   wyAction* tolua_ret = (wyAction*)  self->copy();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyAction");
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

/* method: update of class  wyShaky3D */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyShaky3D_update00
static int tolua_gridactions_wyShaky3D_update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyShaky3D",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyShaky3D* self = (wyShaky3D*)  tolua_tousertype(tolua_S,1,0);
  float t = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'update'", NULL);
#endif
  {
   self->update(t);
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

/* method: make of class  wyShakyTiles3D */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyShakyTiles3D_make00
static int tolua_gridactions_wyShakyTiles3D_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyShakyTiles3D",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,7,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,8,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  int gridX = ((int)  tolua_tonumber(tolua_S,3,0));
  int gridY = ((int)  tolua_tonumber(tolua_S,4,0));
  int range = ((int)  tolua_tonumber(tolua_S,5,0));
  int deltaRange = ((int)  tolua_tonumber(tolua_S,6,0));
  bool shakeZ = ((bool)  tolua_toboolean(tolua_S,7,0));
  {
   wyShakyTiles3D* tolua_ret = (wyShakyTiles3D*)  wyShakyTiles3D::make(duration,gridX,gridY,range,deltaRange,shakeZ);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyShakyTiles3D");
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

/* method: new of class  wyShakyTiles3D */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyShakyTiles3D_new00
static int tolua_gridactions_wyShakyTiles3D_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyShakyTiles3D",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,7,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,8,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  int gridX = ((int)  tolua_tonumber(tolua_S,3,0));
  int gridY = ((int)  tolua_tonumber(tolua_S,4,0));
  int range = ((int)  tolua_tonumber(tolua_S,5,0));
  int deltaRange = ((int)  tolua_tonumber(tolua_S,6,0));
  bool shakeZ = ((bool)  tolua_toboolean(tolua_S,7,0));
  {
   wyShakyTiles3D* tolua_ret = (wyShakyTiles3D*)  Mtolua_new((wyShakyTiles3D)(duration,gridX,gridY,range,deltaRange,shakeZ));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyShakyTiles3D");
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

/* method: new_local of class  wyShakyTiles3D */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyShakyTiles3D_new00_local
static int tolua_gridactions_wyShakyTiles3D_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyShakyTiles3D",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,7,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,8,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  int gridX = ((int)  tolua_tonumber(tolua_S,3,0));
  int gridY = ((int)  tolua_tonumber(tolua_S,4,0));
  int range = ((int)  tolua_tonumber(tolua_S,5,0));
  int deltaRange = ((int)  tolua_tonumber(tolua_S,6,0));
  bool shakeZ = ((bool)  tolua_toboolean(tolua_S,7,0));
  {
   wyShakyTiles3D* tolua_ret = (wyShakyTiles3D*)  Mtolua_new((wyShakyTiles3D)(duration,gridX,gridY,range,deltaRange,shakeZ));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyShakyTiles3D");
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

/* method: delete of class  wyShakyTiles3D */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyShakyTiles3D_delete00
static int tolua_gridactions_wyShakyTiles3D_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyShakyTiles3D",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyShakyTiles3D* self = (wyShakyTiles3D*)  tolua_tousertype(tolua_S,1,0);
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

/* method: copy of class  wyShakyTiles3D */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyShakyTiles3D_copy00
static int tolua_gridactions_wyShakyTiles3D_copy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyShakyTiles3D",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyShakyTiles3D* self = (wyShakyTiles3D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'copy'", NULL);
#endif
  {
   wyAction* tolua_ret = (wyAction*)  self->copy();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyAction");
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

/* method: update of class  wyShakyTiles3D */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyShakyTiles3D_update00
static int tolua_gridactions_wyShakyTiles3D_update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyShakyTiles3D",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyShakyTiles3D* self = (wyShakyTiles3D*)  tolua_tousertype(tolua_S,1,0);
  float t = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'update'", NULL);
#endif
  {
   self->update(t);
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

/* method: make of class  wyShatteredTiles3D */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyShatteredTiles3D_make00
static int tolua_gridactions_wyShatteredTiles3D_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyShatteredTiles3D",0,&tolua_err) ||
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
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  int gridX = ((int)  tolua_tonumber(tolua_S,3,0));
  int gridY = ((int)  tolua_tonumber(tolua_S,4,0));
  int range = ((int)  tolua_tonumber(tolua_S,5,0));
  bool shatterZ = ((bool)  tolua_toboolean(tolua_S,6,0));
  {
   wyShatteredTiles3D* tolua_ret = (wyShatteredTiles3D*)  wyShatteredTiles3D::make(duration,gridX,gridY,range,shatterZ);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyShatteredTiles3D");
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

/* method: new of class  wyShatteredTiles3D */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyShatteredTiles3D_new00
static int tolua_gridactions_wyShatteredTiles3D_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyShatteredTiles3D",0,&tolua_err) ||
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
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  int gridX = ((int)  tolua_tonumber(tolua_S,3,0));
  int gridY = ((int)  tolua_tonumber(tolua_S,4,0));
  int range = ((int)  tolua_tonumber(tolua_S,5,0));
  bool shatterZ = ((bool)  tolua_toboolean(tolua_S,6,0));
  {
   wyShatteredTiles3D* tolua_ret = (wyShatteredTiles3D*)  Mtolua_new((wyShatteredTiles3D)(duration,gridX,gridY,range,shatterZ));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyShatteredTiles3D");
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

/* method: new_local of class  wyShatteredTiles3D */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyShatteredTiles3D_new00_local
static int tolua_gridactions_wyShatteredTiles3D_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyShatteredTiles3D",0,&tolua_err) ||
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
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  int gridX = ((int)  tolua_tonumber(tolua_S,3,0));
  int gridY = ((int)  tolua_tonumber(tolua_S,4,0));
  int range = ((int)  tolua_tonumber(tolua_S,5,0));
  bool shatterZ = ((bool)  tolua_toboolean(tolua_S,6,0));
  {
   wyShatteredTiles3D* tolua_ret = (wyShatteredTiles3D*)  Mtolua_new((wyShatteredTiles3D)(duration,gridX,gridY,range,shatterZ));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyShatteredTiles3D");
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

/* method: delete of class  wyShatteredTiles3D */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyShatteredTiles3D_delete00
static int tolua_gridactions_wyShatteredTiles3D_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyShatteredTiles3D",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyShatteredTiles3D* self = (wyShatteredTiles3D*)  tolua_tousertype(tolua_S,1,0);
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

/* method: copy of class  wyShatteredTiles3D */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyShatteredTiles3D_copy00
static int tolua_gridactions_wyShatteredTiles3D_copy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyShatteredTiles3D",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyShatteredTiles3D* self = (wyShatteredTiles3D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'copy'", NULL);
#endif
  {
   wyAction* tolua_ret = (wyAction*)  self->copy();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyAction");
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

/* method: update of class  wyShatteredTiles3D */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyShatteredTiles3D_update00
static int tolua_gridactions_wyShatteredTiles3D_update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyShatteredTiles3D",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyShatteredTiles3D* self = (wyShatteredTiles3D*)  tolua_tousertype(tolua_S,1,0);
  float t = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'update'", NULL);
#endif
  {
   self->update(t);
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

/* get function: position of class  wyTile */
#ifndef TOLUA_DISABLE_tolua_get_wyTile_position
static int tolua_get_wyTile_position(lua_State* tolua_S)
{
  wyTile* self = (wyTile*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'position'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->position,"wyPoint");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: position of class  wyTile */
#ifndef TOLUA_DISABLE_tolua_set_wyTile_position
static int tolua_set_wyTile_position(lua_State* tolua_S)
{
  wyTile* self = (wyTile*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'position'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"wyPoint",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->position = *((wyPoint*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: startPosition of class  wyTile */
#ifndef TOLUA_DISABLE_tolua_get_wyTile_startPosition
static int tolua_get_wyTile_startPosition(lua_State* tolua_S)
{
  wyTile* self = (wyTile*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'startPosition'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->startPosition,"wyPoint");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: startPosition of class  wyTile */
#ifndef TOLUA_DISABLE_tolua_set_wyTile_startPosition
static int tolua_set_wyTile_startPosition(lua_State* tolua_S)
{
  wyTile* self = (wyTile*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'startPosition'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"wyPoint",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->startPosition = *((wyPoint*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: delta of class  wyTile */
#ifndef TOLUA_DISABLE_tolua_get_wyTile_delta
static int tolua_get_wyTile_delta(lua_State* tolua_S)
{
  wyTile* self = (wyTile*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'delta'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->delta,"wyDimension");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: delta of class  wyTile */
#ifndef TOLUA_DISABLE_tolua_set_wyTile_delta
static int tolua_set_wyTile_delta(lua_State* tolua_S)
{
  wyTile* self = (wyTile*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'delta'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"wyDimension",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->delta = *((wyDimension*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: make of class  wyShuffleTiles */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyShuffleTiles_make00
static int tolua_gridactions_wyShuffleTiles_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyShuffleTiles",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  int gridX = ((int)  tolua_tonumber(tolua_S,3,0));
  int gridY = ((int)  tolua_tonumber(tolua_S,4,0));
  {
   wyShuffleTiles* tolua_ret = (wyShuffleTiles*)  wyShuffleTiles::make(duration,gridX,gridY);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyShuffleTiles");
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

/* method: new of class  wyShuffleTiles */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyShuffleTiles_new00
static int tolua_gridactions_wyShuffleTiles_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyShuffleTiles",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  int gridX = ((int)  tolua_tonumber(tolua_S,3,0));
  int gridY = ((int)  tolua_tonumber(tolua_S,4,0));
  {
   wyShuffleTiles* tolua_ret = (wyShuffleTiles*)  Mtolua_new((wyShuffleTiles)(duration,gridX,gridY));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyShuffleTiles");
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

/* method: new_local of class  wyShuffleTiles */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyShuffleTiles_new00_local
static int tolua_gridactions_wyShuffleTiles_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyShuffleTiles",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  int gridX = ((int)  tolua_tonumber(tolua_S,3,0));
  int gridY = ((int)  tolua_tonumber(tolua_S,4,0));
  {
   wyShuffleTiles* tolua_ret = (wyShuffleTiles*)  Mtolua_new((wyShuffleTiles)(duration,gridX,gridY));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyShuffleTiles");
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

/* method: delete of class  wyShuffleTiles */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyShuffleTiles_delete00
static int tolua_gridactions_wyShuffleTiles_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyShuffleTiles",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyShuffleTiles* self = (wyShuffleTiles*)  tolua_tousertype(tolua_S,1,0);
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

/* method: copy of class  wyShuffleTiles */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyShuffleTiles_copy00
static int tolua_gridactions_wyShuffleTiles_copy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyShuffleTiles",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyShuffleTiles* self = (wyShuffleTiles*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'copy'", NULL);
#endif
  {
   wyAction* tolua_ret = (wyAction*)  self->copy();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyAction");
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

/* method: update of class  wyShuffleTiles */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyShuffleTiles_update00
static int tolua_gridactions_wyShuffleTiles_update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyShuffleTiles",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyShuffleTiles* self = (wyShuffleTiles*)  tolua_tousertype(tolua_S,1,0);
  float t = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'update'", NULL);
#endif
  {
   self->update(t);
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

/* method: start of class  wyShuffleTiles */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyShuffleTiles_start00
static int tolua_gridactions_wyShuffleTiles_start00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyShuffleTiles",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyShuffleTiles* self = (wyShuffleTiles*)  tolua_tousertype(tolua_S,1,0);
  wyNode* target = ((wyNode*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'start'", NULL);
#endif
  {
   self->start(target);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'start'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: make of class  wySplitCols */
#ifndef TOLUA_DISABLE_tolua_gridactions_wySplitCols_make00
static int tolua_gridactions_wySplitCols_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wySplitCols",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  int gridX = ((int)  tolua_tonumber(tolua_S,3,0));
  int gridY = ((int)  tolua_tonumber(tolua_S,4,0));
  {
   wySplitCols* tolua_ret = (wySplitCols*)  wySplitCols::make(duration,gridX,gridY);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wySplitCols");
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

/* method: new of class  wySplitCols */
#ifndef TOLUA_DISABLE_tolua_gridactions_wySplitCols_new00
static int tolua_gridactions_wySplitCols_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wySplitCols",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  int gridX = ((int)  tolua_tonumber(tolua_S,3,0));
  int gridY = ((int)  tolua_tonumber(tolua_S,4,0));
  {
   wySplitCols* tolua_ret = (wySplitCols*)  Mtolua_new((wySplitCols)(duration,gridX,gridY));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wySplitCols");
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

/* method: new_local of class  wySplitCols */
#ifndef TOLUA_DISABLE_tolua_gridactions_wySplitCols_new00_local
static int tolua_gridactions_wySplitCols_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wySplitCols",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  int gridX = ((int)  tolua_tonumber(tolua_S,3,0));
  int gridY = ((int)  tolua_tonumber(tolua_S,4,0));
  {
   wySplitCols* tolua_ret = (wySplitCols*)  Mtolua_new((wySplitCols)(duration,gridX,gridY));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wySplitCols");
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

/* method: delete of class  wySplitCols */
#ifndef TOLUA_DISABLE_tolua_gridactions_wySplitCols_delete00
static int tolua_gridactions_wySplitCols_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wySplitCols",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wySplitCols* self = (wySplitCols*)  tolua_tousertype(tolua_S,1,0);
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

/* method: copy of class  wySplitCols */
#ifndef TOLUA_DISABLE_tolua_gridactions_wySplitCols_copy00
static int tolua_gridactions_wySplitCols_copy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wySplitCols",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wySplitCols* self = (wySplitCols*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'copy'", NULL);
#endif
  {
   wyAction* tolua_ret = (wyAction*)  self->copy();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyAction");
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

/* method: update of class  wySplitCols */
#ifndef TOLUA_DISABLE_tolua_gridactions_wySplitCols_update00
static int tolua_gridactions_wySplitCols_update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wySplitCols",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wySplitCols* self = (wySplitCols*)  tolua_tousertype(tolua_S,1,0);
  float t = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'update'", NULL);
#endif
  {
   self->update(t);
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

/* method: make of class  wySplitRows */
#ifndef TOLUA_DISABLE_tolua_gridactions_wySplitRows_make00
static int tolua_gridactions_wySplitRows_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wySplitRows",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  int gridX = ((int)  tolua_tonumber(tolua_S,3,0));
  int gridY = ((int)  tolua_tonumber(tolua_S,4,0));
  {
   wySplitRows* tolua_ret = (wySplitRows*)  wySplitRows::make(duration,gridX,gridY);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wySplitRows");
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

/* method: new of class  wySplitRows */
#ifndef TOLUA_DISABLE_tolua_gridactions_wySplitRows_new00
static int tolua_gridactions_wySplitRows_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wySplitRows",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  int gridX = ((int)  tolua_tonumber(tolua_S,3,0));
  int gridY = ((int)  tolua_tonumber(tolua_S,4,0));
  {
   wySplitRows* tolua_ret = (wySplitRows*)  Mtolua_new((wySplitRows)(duration,gridX,gridY));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wySplitRows");
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

/* method: new_local of class  wySplitRows */
#ifndef TOLUA_DISABLE_tolua_gridactions_wySplitRows_new00_local
static int tolua_gridactions_wySplitRows_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wySplitRows",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  int gridX = ((int)  tolua_tonumber(tolua_S,3,0));
  int gridY = ((int)  tolua_tonumber(tolua_S,4,0));
  {
   wySplitRows* tolua_ret = (wySplitRows*)  Mtolua_new((wySplitRows)(duration,gridX,gridY));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wySplitRows");
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

/* method: delete of class  wySplitRows */
#ifndef TOLUA_DISABLE_tolua_gridactions_wySplitRows_delete00
static int tolua_gridactions_wySplitRows_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wySplitRows",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wySplitRows* self = (wySplitRows*)  tolua_tousertype(tolua_S,1,0);
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

/* method: copy of class  wySplitRows */
#ifndef TOLUA_DISABLE_tolua_gridactions_wySplitRows_copy00
static int tolua_gridactions_wySplitRows_copy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wySplitRows",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wySplitRows* self = (wySplitRows*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'copy'", NULL);
#endif
  {
   wyAction* tolua_ret = (wyAction*)  self->copy();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyAction");
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

/* method: update of class  wySplitRows */
#ifndef TOLUA_DISABLE_tolua_gridactions_wySplitRows_update00
static int tolua_gridactions_wySplitRows_update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wySplitRows",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wySplitRows* self = (wySplitRows*)  tolua_tousertype(tolua_S,1,0);
  float t = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'update'", NULL);
#endif
  {
   self->update(t);
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

/* method: make of class  wyStopGrid */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyStopGrid_make00
static int tolua_gridactions_wyStopGrid_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyStopGrid",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   wyStopGrid* tolua_ret = (wyStopGrid*)  wyStopGrid::make();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyStopGrid");
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

/* method: new of class  wyStopGrid */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyStopGrid_new00
static int tolua_gridactions_wyStopGrid_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyStopGrid",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   wyStopGrid* tolua_ret = (wyStopGrid*)  Mtolua_new((wyStopGrid)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyStopGrid");
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

/* method: new_local of class  wyStopGrid */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyStopGrid_new00_local
static int tolua_gridactions_wyStopGrid_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyStopGrid",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   wyStopGrid* tolua_ret = (wyStopGrid*)  Mtolua_new((wyStopGrid)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyStopGrid");
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

/* method: delete of class  wyStopGrid */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyStopGrid_delete00
static int tolua_gridactions_wyStopGrid_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyStopGrid",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyStopGrid* self = (wyStopGrid*)  tolua_tousertype(tolua_S,1,0);
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

/* method: copy of class  wyStopGrid */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyStopGrid_copy00
static int tolua_gridactions_wyStopGrid_copy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyStopGrid",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyStopGrid* self = (wyStopGrid*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'copy'", NULL);
#endif
  {
   wyAction* tolua_ret = (wyAction*)  self->copy();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyAction");
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

/* method: reverse of class  wyStopGrid */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyStopGrid_reverse00
static int tolua_gridactions_wyStopGrid_reverse00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyStopGrid",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyStopGrid* self = (wyStopGrid*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'reverse'", NULL);
#endif
  {
   wyAction* tolua_ret = (wyAction*)  self->reverse();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyAction");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'reverse'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: start of class  wyStopGrid */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyStopGrid_start00
static int tolua_gridactions_wyStopGrid_start00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyStopGrid",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyStopGrid* self = (wyStopGrid*)  tolua_tousertype(tolua_S,1,0);
  wyNode* target = ((wyNode*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'start'", NULL);
#endif
  {
   self->start(target);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'start'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  wyTiledGrid3DAction */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyTiledGrid3DAction_new00
static int tolua_gridactions_wyTiledGrid3DAction_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyTiledGrid3DAction",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  float gridX = ((float)  tolua_tonumber(tolua_S,3,0));
  float gridY = ((float)  tolua_tonumber(tolua_S,4,0));
  {
   wyTiledGrid3DAction* tolua_ret = (wyTiledGrid3DAction*)  Mtolua_new((wyTiledGrid3DAction)(duration,gridX,gridY));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyTiledGrid3DAction");
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

/* method: new_local of class  wyTiledGrid3DAction */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyTiledGrid3DAction_new00_local
static int tolua_gridactions_wyTiledGrid3DAction_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyTiledGrid3DAction",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  float gridX = ((float)  tolua_tonumber(tolua_S,3,0));
  float gridY = ((float)  tolua_tonumber(tolua_S,4,0));
  {
   wyTiledGrid3DAction* tolua_ret = (wyTiledGrid3DAction*)  Mtolua_new((wyTiledGrid3DAction)(duration,gridX,gridY));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyTiledGrid3DAction");
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

/* method: delete of class  wyTiledGrid3DAction */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyTiledGrid3DAction_delete00
static int tolua_gridactions_wyTiledGrid3DAction_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTiledGrid3DAction",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTiledGrid3DAction* self = (wyTiledGrid3DAction*)  tolua_tousertype(tolua_S,1,0);
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

/* method: makeGrid of class  wyTiledGrid3DAction */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyTiledGrid3DAction_makeGrid00
static int tolua_gridactions_wyTiledGrid3DAction_makeGrid00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTiledGrid3DAction",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTiledGrid3DAction* self = (wyTiledGrid3DAction*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'makeGrid'", NULL);
#endif
  {
   wyBaseGrid* tolua_ret = (wyBaseGrid*)  self->makeGrid();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyBaseGrid");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'makeGrid'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isGridReusable of class  wyTiledGrid3DAction */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyTiledGrid3DAction_isGridReusable00
static int tolua_gridactions_wyTiledGrid3DAction_isGridReusable00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTiledGrid3DAction",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyBaseGrid",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTiledGrid3DAction* self = (wyTiledGrid3DAction*)  tolua_tousertype(tolua_S,1,0);
  wyBaseGrid* grid = ((wyBaseGrid*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isGridReusable'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isGridReusable(grid);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isGridReusable'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getTile of class  wyTiledGrid3DAction */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyTiledGrid3DAction_getTile00
static int tolua_gridactions_wyTiledGrid3DAction_getTile00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTiledGrid3DAction",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"wyDimension",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTiledGrid3DAction* self = (wyTiledGrid3DAction*)  tolua_tousertype(tolua_S,1,0);
  wyDimension pos = *((wyDimension*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getTile'", NULL);
#endif
  {
   wyQuad3D tolua_ret = (wyQuad3D)  self->getTile(pos);
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
 tolua_error(tolua_S,"#ferror in function 'getTile'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getOriginalTile of class  wyTiledGrid3DAction */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyTiledGrid3DAction_getOriginalTile00
static int tolua_gridactions_wyTiledGrid3DAction_getOriginalTile00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTiledGrid3DAction",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"wyDimension",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTiledGrid3DAction* self = (wyTiledGrid3DAction*)  tolua_tousertype(tolua_S,1,0);
  wyDimension pos = *((wyDimension*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getOriginalTile'", NULL);
#endif
  {
   wyQuad3D tolua_ret = (wyQuad3D)  self->getOriginalTile(pos);
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
 tolua_error(tolua_S,"#ferror in function 'getOriginalTile'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setTile of class  wyTiledGrid3DAction */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyTiledGrid3DAction_setTile00
static int tolua_gridactions_wyTiledGrid3DAction_setTile00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTiledGrid3DAction",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"wyDimension",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"wyQuad3D",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTiledGrid3DAction* self = (wyTiledGrid3DAction*)  tolua_tousertype(tolua_S,1,0);
  wyDimension pos = *((wyDimension*)  tolua_tousertype(tolua_S,2,0));
  wyQuad3D coords = *((wyQuad3D*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setTile'", NULL);
#endif
  {
   self->setTile(pos,coords);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setTile'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: make of class  wyTopLineShrinkOut */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyTopLineShrinkOut_make00
static int tolua_gridactions_wyTopLineShrinkOut_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyTopLineShrinkOut",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  int gridX = ((int)  tolua_tonumber(tolua_S,3,0));
  int gridY = ((int)  tolua_tonumber(tolua_S,4,0));
  {
   wyTopLineShrinkOut* tolua_ret = (wyTopLineShrinkOut*)  wyTopLineShrinkOut::make(duration,gridX,gridY);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyTopLineShrinkOut");
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

/* method: new of class  wyTopLineShrinkOut */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyTopLineShrinkOut_new00
static int tolua_gridactions_wyTopLineShrinkOut_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyTopLineShrinkOut",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  int gridX = ((int)  tolua_tonumber(tolua_S,3,0));
  int gridY = ((int)  tolua_tonumber(tolua_S,4,0));
  {
   wyTopLineShrinkOut* tolua_ret = (wyTopLineShrinkOut*)  Mtolua_new((wyTopLineShrinkOut)(duration,gridX,gridY));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyTopLineShrinkOut");
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

/* method: new_local of class  wyTopLineShrinkOut */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyTopLineShrinkOut_new00_local
static int tolua_gridactions_wyTopLineShrinkOut_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyTopLineShrinkOut",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  int gridX = ((int)  tolua_tonumber(tolua_S,3,0));
  int gridY = ((int)  tolua_tonumber(tolua_S,4,0));
  {
   wyTopLineShrinkOut* tolua_ret = (wyTopLineShrinkOut*)  Mtolua_new((wyTopLineShrinkOut)(duration,gridX,gridY));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyTopLineShrinkOut");
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

/* method: delete of class  wyTopLineShrinkOut */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyTopLineShrinkOut_delete00
static int tolua_gridactions_wyTopLineShrinkOut_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTopLineShrinkOut",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTopLineShrinkOut* self = (wyTopLineShrinkOut*)  tolua_tousertype(tolua_S,1,0);
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

/* method: copy of class  wyTopLineShrinkOut */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyTopLineShrinkOut_copy00
static int tolua_gridactions_wyTopLineShrinkOut_copy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTopLineShrinkOut",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTopLineShrinkOut* self = (wyTopLineShrinkOut*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'copy'", NULL);
#endif
  {
   wyAction* tolua_ret = (wyAction*)  self->copy();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyAction");
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

/* method: update of class  wyTopLineShrinkOut */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyTopLineShrinkOut_update00
static int tolua_gridactions_wyTopLineShrinkOut_update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTopLineShrinkOut",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTopLineShrinkOut* self = (wyTopLineShrinkOut*)  tolua_tousertype(tolua_S,1,0);
  float t = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'update'", NULL);
#endif
  {
   self->update(t);
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

/* method: make of class  wyTopTilesShrinkOut */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyTopTilesShrinkOut_make00
static int tolua_gridactions_wyTopTilesShrinkOut_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyTopTilesShrinkOut",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  int gridX = ((int)  tolua_tonumber(tolua_S,3,0));
  int gridY = ((int)  tolua_tonumber(tolua_S,4,0));
  {
   wyTopTilesShrinkOut* tolua_ret = (wyTopTilesShrinkOut*)  wyTopTilesShrinkOut::make(duration,gridX,gridY);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyTopTilesShrinkOut");
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

/* method: new of class  wyTopTilesShrinkOut */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyTopTilesShrinkOut_new00
static int tolua_gridactions_wyTopTilesShrinkOut_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyTopTilesShrinkOut",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  int gridX = ((int)  tolua_tonumber(tolua_S,3,0));
  int gridY = ((int)  tolua_tonumber(tolua_S,4,0));
  {
   wyTopTilesShrinkOut* tolua_ret = (wyTopTilesShrinkOut*)  Mtolua_new((wyTopTilesShrinkOut)(duration,gridX,gridY));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyTopTilesShrinkOut");
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

/* method: new_local of class  wyTopTilesShrinkOut */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyTopTilesShrinkOut_new00_local
static int tolua_gridactions_wyTopTilesShrinkOut_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyTopTilesShrinkOut",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  int gridX = ((int)  tolua_tonumber(tolua_S,3,0));
  int gridY = ((int)  tolua_tonumber(tolua_S,4,0));
  {
   wyTopTilesShrinkOut* tolua_ret = (wyTopTilesShrinkOut*)  Mtolua_new((wyTopTilesShrinkOut)(duration,gridX,gridY));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyTopTilesShrinkOut");
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

/* method: delete of class  wyTopTilesShrinkOut */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyTopTilesShrinkOut_delete00
static int tolua_gridactions_wyTopTilesShrinkOut_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTopTilesShrinkOut",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTopTilesShrinkOut* self = (wyTopTilesShrinkOut*)  tolua_tousertype(tolua_S,1,0);
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

/* method: copy of class  wyTopTilesShrinkOut */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyTopTilesShrinkOut_copy00
static int tolua_gridactions_wyTopTilesShrinkOut_copy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTopTilesShrinkOut",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTopTilesShrinkOut* self = (wyTopTilesShrinkOut*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'copy'", NULL);
#endif
  {
   wyAction* tolua_ret = (wyAction*)  self->copy();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyAction");
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

/* method: update of class  wyTopTilesShrinkOut */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyTopTilesShrinkOut_update00
static int tolua_gridactions_wyTopTilesShrinkOut_update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTopTilesShrinkOut",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTopTilesShrinkOut* self = (wyTopTilesShrinkOut*)  tolua_tousertype(tolua_S,1,0);
  float t = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'update'", NULL);
#endif
  {
   self->update(t);
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

/* method: make of class  wyTurnOffTiles */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyTurnOffTiles_make00
static int tolua_gridactions_wyTurnOffTiles_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyTurnOffTiles",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  int gridX = ((int)  tolua_tonumber(tolua_S,3,0));
  int gridY = ((int)  tolua_tonumber(tolua_S,4,0));
  {
   wyTurnOffTiles* tolua_ret = (wyTurnOffTiles*)  wyTurnOffTiles::make(duration,gridX,gridY);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyTurnOffTiles");
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

/* method: new of class  wyTurnOffTiles */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyTurnOffTiles_new00
static int tolua_gridactions_wyTurnOffTiles_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyTurnOffTiles",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  int gridX = ((int)  tolua_tonumber(tolua_S,3,0));
  int gridY = ((int)  tolua_tonumber(tolua_S,4,0));
  {
   wyTurnOffTiles* tolua_ret = (wyTurnOffTiles*)  Mtolua_new((wyTurnOffTiles)(duration,gridX,gridY));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyTurnOffTiles");
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

/* method: new_local of class  wyTurnOffTiles */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyTurnOffTiles_new00_local
static int tolua_gridactions_wyTurnOffTiles_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyTurnOffTiles",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  int gridX = ((int)  tolua_tonumber(tolua_S,3,0));
  int gridY = ((int)  tolua_tonumber(tolua_S,4,0));
  {
   wyTurnOffTiles* tolua_ret = (wyTurnOffTiles*)  Mtolua_new((wyTurnOffTiles)(duration,gridX,gridY));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyTurnOffTiles");
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

/* method: delete of class  wyTurnOffTiles */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyTurnOffTiles_delete00
static int tolua_gridactions_wyTurnOffTiles_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTurnOffTiles",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTurnOffTiles* self = (wyTurnOffTiles*)  tolua_tousertype(tolua_S,1,0);
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

/* method: copy of class  wyTurnOffTiles */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyTurnOffTiles_copy00
static int tolua_gridactions_wyTurnOffTiles_copy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTurnOffTiles",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTurnOffTiles* self = (wyTurnOffTiles*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'copy'", NULL);
#endif
  {
   wyAction* tolua_ret = (wyAction*)  self->copy();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyAction");
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

/* method: start of class  wyTurnOffTiles */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyTurnOffTiles_start00
static int tolua_gridactions_wyTurnOffTiles_start00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTurnOffTiles",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTurnOffTiles* self = (wyTurnOffTiles*)  tolua_tousertype(tolua_S,1,0);
  wyNode* target = ((wyNode*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'start'", NULL);
#endif
  {
   self->start(target);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'start'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: update of class  wyTurnOffTiles */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyTurnOffTiles_update00
static int tolua_gridactions_wyTurnOffTiles_update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTurnOffTiles",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTurnOffTiles* self = (wyTurnOffTiles*)  tolua_tousertype(tolua_S,1,0);
  float t = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'update'", NULL);
#endif
  {
   self->update(t);
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

/* method: make of class  wyTwirl */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyTwirl_make00
static int tolua_gridactions_wyTwirl_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyTwirl",0,&tolua_err) ||
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
     !tolua_isnoobj(tolua_S,12,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  int gridX = ((int)  tolua_tonumber(tolua_S,3,0));
  int gridY = ((int)  tolua_tonumber(tolua_S,4,0));
  float centerX = ((float)  tolua_tonumber(tolua_S,5,0));
  float centerY = ((float)  tolua_tonumber(tolua_S,6,0));
  float deltaX = ((float)  tolua_tonumber(tolua_S,7,0));
  float deltaY = ((float)  tolua_tonumber(tolua_S,8,0));
  float amplitude = ((float)  tolua_tonumber(tolua_S,9,0));
  float deltaAmplitude = ((float)  tolua_tonumber(tolua_S,10,0));
  float twirls = ((float)  tolua_tonumber(tolua_S,11,0));
  {
   wyTwirl* tolua_ret = (wyTwirl*)  wyTwirl::make(duration,gridX,gridY,centerX,centerY,deltaX,deltaY,amplitude,deltaAmplitude,twirls);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyTwirl");
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

/* method: new of class  wyTwirl */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyTwirl_new00
static int tolua_gridactions_wyTwirl_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyTwirl",0,&tolua_err) ||
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
     !tolua_isnoobj(tolua_S,12,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  int gridX = ((int)  tolua_tonumber(tolua_S,3,0));
  int gridY = ((int)  tolua_tonumber(tolua_S,4,0));
  float centerX = ((float)  tolua_tonumber(tolua_S,5,0));
  float centerY = ((float)  tolua_tonumber(tolua_S,6,0));
  float deltaX = ((float)  tolua_tonumber(tolua_S,7,0));
  float deltaY = ((float)  tolua_tonumber(tolua_S,8,0));
  float amplitude = ((float)  tolua_tonumber(tolua_S,9,0));
  float deltaAmplitude = ((float)  tolua_tonumber(tolua_S,10,0));
  float twirls = ((float)  tolua_tonumber(tolua_S,11,0));
  {
   wyTwirl* tolua_ret = (wyTwirl*)  Mtolua_new((wyTwirl)(duration,gridX,gridY,centerX,centerY,deltaX,deltaY,amplitude,deltaAmplitude,twirls));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyTwirl");
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

/* method: new_local of class  wyTwirl */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyTwirl_new00_local
static int tolua_gridactions_wyTwirl_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyTwirl",0,&tolua_err) ||
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
     !tolua_isnoobj(tolua_S,12,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  int gridX = ((int)  tolua_tonumber(tolua_S,3,0));
  int gridY = ((int)  tolua_tonumber(tolua_S,4,0));
  float centerX = ((float)  tolua_tonumber(tolua_S,5,0));
  float centerY = ((float)  tolua_tonumber(tolua_S,6,0));
  float deltaX = ((float)  tolua_tonumber(tolua_S,7,0));
  float deltaY = ((float)  tolua_tonumber(tolua_S,8,0));
  float amplitude = ((float)  tolua_tonumber(tolua_S,9,0));
  float deltaAmplitude = ((float)  tolua_tonumber(tolua_S,10,0));
  float twirls = ((float)  tolua_tonumber(tolua_S,11,0));
  {
   wyTwirl* tolua_ret = (wyTwirl*)  Mtolua_new((wyTwirl)(duration,gridX,gridY,centerX,centerY,deltaX,deltaY,amplitude,deltaAmplitude,twirls));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyTwirl");
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

/* method: delete of class  wyTwirl */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyTwirl_delete00
static int tolua_gridactions_wyTwirl_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTwirl",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTwirl* self = (wyTwirl*)  tolua_tousertype(tolua_S,1,0);
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

/* method: copy of class  wyTwirl */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyTwirl_copy00
static int tolua_gridactions_wyTwirl_copy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTwirl",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTwirl* self = (wyTwirl*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'copy'", NULL);
#endif
  {
   wyAction* tolua_ret = (wyAction*)  self->copy();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyAction");
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

/* method: update of class  wyTwirl */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyTwirl_update00
static int tolua_gridactions_wyTwirl_update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTwirl",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTwirl* self = (wyTwirl*)  tolua_tousertype(tolua_S,1,0);
  float t = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'update'", NULL);
#endif
  {
   self->update(t);
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

/* method: make of class  wyWaves */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyWaves_make00
static int tolua_gridactions_wyWaves_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyWaves",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,7,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,8,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,9,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  int gridX = ((int)  tolua_tonumber(tolua_S,3,0));
  int gridY = ((int)  tolua_tonumber(tolua_S,4,0));
  float amplitude = ((float)  tolua_tonumber(tolua_S,5,0));
  int waves = ((int)  tolua_tonumber(tolua_S,6,0));
  bool vertical = ((bool)  tolua_toboolean(tolua_S,7,0));
  bool horizontal = ((bool)  tolua_toboolean(tolua_S,8,0));
  {
   wyWaves* tolua_ret = (wyWaves*)  wyWaves::make(duration,gridX,gridY,amplitude,waves,vertical,horizontal);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyWaves");
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

/* method: new of class  wyWaves */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyWaves_new00
static int tolua_gridactions_wyWaves_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyWaves",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,7,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,8,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,9,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  int gridX = ((int)  tolua_tonumber(tolua_S,3,0));
  int gridY = ((int)  tolua_tonumber(tolua_S,4,0));
  float amplitude = ((float)  tolua_tonumber(tolua_S,5,0));
  int waves = ((int)  tolua_tonumber(tolua_S,6,0));
  bool vertical = ((bool)  tolua_toboolean(tolua_S,7,0));
  bool horizontal = ((bool)  tolua_toboolean(tolua_S,8,0));
  {
   wyWaves* tolua_ret = (wyWaves*)  Mtolua_new((wyWaves)(duration,gridX,gridY,amplitude,waves,vertical,horizontal));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyWaves");
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

/* method: new_local of class  wyWaves */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyWaves_new00_local
static int tolua_gridactions_wyWaves_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyWaves",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,7,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,8,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,9,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  int gridX = ((int)  tolua_tonumber(tolua_S,3,0));
  int gridY = ((int)  tolua_tonumber(tolua_S,4,0));
  float amplitude = ((float)  tolua_tonumber(tolua_S,5,0));
  int waves = ((int)  tolua_tonumber(tolua_S,6,0));
  bool vertical = ((bool)  tolua_toboolean(tolua_S,7,0));
  bool horizontal = ((bool)  tolua_toboolean(tolua_S,8,0));
  {
   wyWaves* tolua_ret = (wyWaves*)  Mtolua_new((wyWaves)(duration,gridX,gridY,amplitude,waves,vertical,horizontal));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyWaves");
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

/* method: delete of class  wyWaves */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyWaves_delete00
static int tolua_gridactions_wyWaves_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyWaves",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyWaves* self = (wyWaves*)  tolua_tousertype(tolua_S,1,0);
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

/* method: copy of class  wyWaves */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyWaves_copy00
static int tolua_gridactions_wyWaves_copy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyWaves",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyWaves* self = (wyWaves*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'copy'", NULL);
#endif
  {
   wyAction* tolua_ret = (wyAction*)  self->copy();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyAction");
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

/* method: update of class  wyWaves */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyWaves_update00
static int tolua_gridactions_wyWaves_update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyWaves",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyWaves* self = (wyWaves*)  tolua_tousertype(tolua_S,1,0);
  float t = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'update'", NULL);
#endif
  {
   self->update(t);
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

/* method: make of class  wyWaves3D */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyWaves3D_make00
static int tolua_gridactions_wyWaves3D_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyWaves3D",0,&tolua_err) ||
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
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  int gridX = ((int)  tolua_tonumber(tolua_S,3,0));
  int gridY = ((int)  tolua_tonumber(tolua_S,4,0));
  float amplitude = ((float)  tolua_tonumber(tolua_S,5,0));
  int waves = ((int)  tolua_tonumber(tolua_S,6,0));
  {
   wyWaves3D* tolua_ret = (wyWaves3D*)  wyWaves3D::make(duration,gridX,gridY,amplitude,waves);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyWaves3D");
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

/* method: new of class  wyWaves3D */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyWaves3D_new00
static int tolua_gridactions_wyWaves3D_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyWaves3D",0,&tolua_err) ||
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
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  int gridX = ((int)  tolua_tonumber(tolua_S,3,0));
  int gridY = ((int)  tolua_tonumber(tolua_S,4,0));
  float amplitude = ((float)  tolua_tonumber(tolua_S,5,0));
  int waves = ((int)  tolua_tonumber(tolua_S,6,0));
  {
   wyWaves3D* tolua_ret = (wyWaves3D*)  Mtolua_new((wyWaves3D)(duration,gridX,gridY,amplitude,waves));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyWaves3D");
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

/* method: new_local of class  wyWaves3D */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyWaves3D_new00_local
static int tolua_gridactions_wyWaves3D_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyWaves3D",0,&tolua_err) ||
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
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  int gridX = ((int)  tolua_tonumber(tolua_S,3,0));
  int gridY = ((int)  tolua_tonumber(tolua_S,4,0));
  float amplitude = ((float)  tolua_tonumber(tolua_S,5,0));
  int waves = ((int)  tolua_tonumber(tolua_S,6,0));
  {
   wyWaves3D* tolua_ret = (wyWaves3D*)  Mtolua_new((wyWaves3D)(duration,gridX,gridY,amplitude,waves));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyWaves3D");
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

/* method: delete of class  wyWaves3D */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyWaves3D_delete00
static int tolua_gridactions_wyWaves3D_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyWaves3D",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyWaves3D* self = (wyWaves3D*)  tolua_tousertype(tolua_S,1,0);
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

/* method: copy of class  wyWaves3D */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyWaves3D_copy00
static int tolua_gridactions_wyWaves3D_copy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyWaves3D",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyWaves3D* self = (wyWaves3D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'copy'", NULL);
#endif
  {
   wyAction* tolua_ret = (wyAction*)  self->copy();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyAction");
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

/* method: update of class  wyWaves3D */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyWaves3D_update00
static int tolua_gridactions_wyWaves3D_update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyWaves3D",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyWaves3D* self = (wyWaves3D*)  tolua_tousertype(tolua_S,1,0);
  float t = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'update'", NULL);
#endif
  {
   self->update(t);
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

/* method: make of class  wyWavesTiles3D */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyWavesTiles3D_make00
static int tolua_gridactions_wyWavesTiles3D_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyWavesTiles3D",0,&tolua_err) ||
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
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  int gridX = ((int)  tolua_tonumber(tolua_S,3,0));
  int gridY = ((int)  tolua_tonumber(tolua_S,4,0));
  float amplitude = ((float)  tolua_tonumber(tolua_S,5,0));
  int waves = ((int)  tolua_tonumber(tolua_S,6,0));
  {
   wyWavesTiles3D* tolua_ret = (wyWavesTiles3D*)  wyWavesTiles3D::make(duration,gridX,gridY,amplitude,waves);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyWavesTiles3D");
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

/* method: new of class  wyWavesTiles3D */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyWavesTiles3D_new00
static int tolua_gridactions_wyWavesTiles3D_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyWavesTiles3D",0,&tolua_err) ||
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
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  int gridX = ((int)  tolua_tonumber(tolua_S,3,0));
  int gridY = ((int)  tolua_tonumber(tolua_S,4,0));
  float amplitude = ((float)  tolua_tonumber(tolua_S,5,0));
  int waves = ((int)  tolua_tonumber(tolua_S,6,0));
  {
   wyWavesTiles3D* tolua_ret = (wyWavesTiles3D*)  Mtolua_new((wyWavesTiles3D)(duration,gridX,gridY,amplitude,waves));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyWavesTiles3D");
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

/* method: new_local of class  wyWavesTiles3D */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyWavesTiles3D_new00_local
static int tolua_gridactions_wyWavesTiles3D_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyWavesTiles3D",0,&tolua_err) ||
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
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  int gridX = ((int)  tolua_tonumber(tolua_S,3,0));
  int gridY = ((int)  tolua_tonumber(tolua_S,4,0));
  float amplitude = ((float)  tolua_tonumber(tolua_S,5,0));
  int waves = ((int)  tolua_tonumber(tolua_S,6,0));
  {
   wyWavesTiles3D* tolua_ret = (wyWavesTiles3D*)  Mtolua_new((wyWavesTiles3D)(duration,gridX,gridY,amplitude,waves));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyWavesTiles3D");
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

/* method: delete of class  wyWavesTiles3D */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyWavesTiles3D_delete00
static int tolua_gridactions_wyWavesTiles3D_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyWavesTiles3D",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyWavesTiles3D* self = (wyWavesTiles3D*)  tolua_tousertype(tolua_S,1,0);
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

/* method: copy of class  wyWavesTiles3D */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyWavesTiles3D_copy00
static int tolua_gridactions_wyWavesTiles3D_copy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyWavesTiles3D",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyWavesTiles3D* self = (wyWavesTiles3D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'copy'", NULL);
#endif
  {
   wyAction* tolua_ret = (wyAction*)  self->copy();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyAction");
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

/* method: update of class  wyWavesTiles3D */
#ifndef TOLUA_DISABLE_tolua_gridactions_wyWavesTiles3D_update00
static int tolua_gridactions_wyWavesTiles3D_update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyWavesTiles3D",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyWavesTiles3D* self = (wyWavesTiles3D*)  tolua_tousertype(tolua_S,1,0);
  float t = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'update'", NULL);
#endif
  {
   self->update(t);
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

/* method: make of class  wySuck */
#ifndef TOLUA_DISABLE_tolua_gridactions_wySuck_make00
static int tolua_gridactions_wySuck_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wySuck",0,&tolua_err) ||
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
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  int gridX = ((int)  tolua_tonumber(tolua_S,3,0));
  int gridY = ((int)  tolua_tonumber(tolua_S,4,0));
  float positionX = ((float)  tolua_tonumber(tolua_S,5,0));
  float positionY = ((float)  tolua_tonumber(tolua_S,6,0));
  {
   wySuck* tolua_ret = (wySuck*)  wySuck::make(duration,gridX,gridY,positionX,positionY);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wySuck");
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

/* method: delete of class  wySuck */
#ifndef TOLUA_DISABLE_tolua_gridactions_wySuck_delete00
static int tolua_gridactions_wySuck_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wySuck",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wySuck* self = (wySuck*)  tolua_tousertype(tolua_S,1,0);
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

/* method: copy of class  wySuck */
#ifndef TOLUA_DISABLE_tolua_gridactions_wySuck_copy00
static int tolua_gridactions_wySuck_copy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wySuck",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wySuck* self = (wySuck*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'copy'", NULL);
#endif
  {
   wyAction* tolua_ret = (wyAction*)  self->copy();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyAction");
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

/* method: update of class  wySuck */
#ifndef TOLUA_DISABLE_tolua_gridactions_wySuck_update00
static int tolua_gridactions_wySuck_update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wySuck",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wySuck* self = (wySuck*)  tolua_tousertype(tolua_S,1,0);
  float t = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'update'", NULL);
#endif
  {
   self->update(t);
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

/* Open function */
TOLUA_API int tolua_gridactions_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyBottomLineShrinkOut","wyBottomLineShrinkOut","wyTiledGrid3DAction",tolua_collect_wyBottomLineShrinkOut);
  #else
  tolua_cclass(tolua_S,"wyBottomLineShrinkOut","wyBottomLineShrinkOut","wyTiledGrid3DAction",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyBottomLineShrinkOut");
   tolua_function(tolua_S,"make",tolua_gridactions_wyBottomLineShrinkOut_make00);
   tolua_function(tolua_S,"new",tolua_gridactions_wyBottomLineShrinkOut_new00);
   tolua_function(tolua_S,"new_local",tolua_gridactions_wyBottomLineShrinkOut_new00_local);
   tolua_function(tolua_S,".call",tolua_gridactions_wyBottomLineShrinkOut_new00_local);
   tolua_function(tolua_S,"delete",tolua_gridactions_wyBottomLineShrinkOut_delete00);
   tolua_function(tolua_S,"copy",tolua_gridactions_wyBottomLineShrinkOut_copy00);
   tolua_function(tolua_S,"update",tolua_gridactions_wyBottomLineShrinkOut_update00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyBottomTilesShrinkOut","wyBottomTilesShrinkOut","wyTiledGrid3DAction",tolua_collect_wyBottomTilesShrinkOut);
  #else
  tolua_cclass(tolua_S,"wyBottomTilesShrinkOut","wyBottomTilesShrinkOut","wyTiledGrid3DAction",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyBottomTilesShrinkOut");
   tolua_function(tolua_S,"make",tolua_gridactions_wyBottomTilesShrinkOut_make00);
   tolua_function(tolua_S,"new",tolua_gridactions_wyBottomTilesShrinkOut_new00);
   tolua_function(tolua_S,"new_local",tolua_gridactions_wyBottomTilesShrinkOut_new00_local);
   tolua_function(tolua_S,".call",tolua_gridactions_wyBottomTilesShrinkOut_new00_local);
   tolua_function(tolua_S,"delete",tolua_gridactions_wyBottomTilesShrinkOut_delete00);
   tolua_function(tolua_S,"copy",tolua_gridactions_wyBottomTilesShrinkOut_copy00);
   tolua_function(tolua_S,"update",tolua_gridactions_wyBottomTilesShrinkOut_update00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyGrid3DAction","wyGrid3DAction","wyGridAction",tolua_collect_wyGrid3DAction);
  #else
  tolua_cclass(tolua_S,"wyGrid3DAction","wyGrid3DAction","wyGridAction",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyGrid3DAction");
   tolua_function(tolua_S,"new",tolua_gridactions_wyGrid3DAction_new00);
   tolua_function(tolua_S,"new_local",tolua_gridactions_wyGrid3DAction_new00_local);
   tolua_function(tolua_S,".call",tolua_gridactions_wyGrid3DAction_new00_local);
   tolua_function(tolua_S,"delete",tolua_gridactions_wyGrid3DAction_delete00);
   tolua_function(tolua_S,"makeGrid",tolua_gridactions_wyGrid3DAction_makeGrid00);
   tolua_function(tolua_S,"isGridReusable",tolua_gridactions_wyGrid3DAction_isGridReusable00);
   tolua_function(tolua_S,"getVertex",tolua_gridactions_wyGrid3DAction_getVertex00);
   tolua_function(tolua_S,"getOriginalVertex",tolua_gridactions_wyGrid3DAction_getOriginalVertex00);
   tolua_function(tolua_S,"setVertex",tolua_gridactions_wyGrid3DAction_setVertex00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyGridAction","wyGridAction","wyIntervalAction",tolua_collect_wyGridAction);
  #else
  tolua_cclass(tolua_S,"wyGridAction","wyGridAction","wyIntervalAction",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyGridAction");
   tolua_function(tolua_S,"delete",tolua_gridactions_wyGridAction_delete00);
   tolua_function(tolua_S,"makeGrid",tolua_gridactions_wyGridAction_makeGrid00);
   tolua_function(tolua_S,"isGridReusable",tolua_gridactions_wyGridAction_isGridReusable00);
   tolua_function(tolua_S,"reverse",tolua_gridactions_wyGridAction_reverse00);
   tolua_function(tolua_S,"start",tolua_gridactions_wyGridAction_start00);
   tolua_function(tolua_S,"setAmplitude",tolua_gridactions_wyGridAction_setAmplitude00);
   tolua_function(tolua_S,"setAmplitudeRate",tolua_gridactions_wyGridAction_setAmplitudeRate00);
   tolua_function(tolua_S,"getAmplitude",tolua_gridactions_wyGridAction_getAmplitude00);
   tolua_function(tolua_S,"getAmplitudeRate",tolua_gridactions_wyGridAction_getAmplitudeRate00);
   tolua_function(tolua_S,"getGridX",tolua_gridactions_wyGridAction_getGridX00);
   tolua_function(tolua_S,"getGridY",tolua_gridactions_wyGridAction_getGridY00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyGridFlipX","wyGridFlipX","wyGrid3DAction",tolua_collect_wyGridFlipX);
  #else
  tolua_cclass(tolua_S,"wyGridFlipX","wyGridFlipX","wyGrid3DAction",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyGridFlipX");
   tolua_function(tolua_S,"make",tolua_gridactions_wyGridFlipX_make00);
   tolua_function(tolua_S,"new",tolua_gridactions_wyGridFlipX_new00);
   tolua_function(tolua_S,"new_local",tolua_gridactions_wyGridFlipX_new00_local);
   tolua_function(tolua_S,".call",tolua_gridactions_wyGridFlipX_new00_local);
   tolua_function(tolua_S,"delete",tolua_gridactions_wyGridFlipX_delete00);
   tolua_function(tolua_S,"copy",tolua_gridactions_wyGridFlipX_copy00);
   tolua_function(tolua_S,"update",tolua_gridactions_wyGridFlipX_update00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyGridFlipY","wyGridFlipY","wyGrid3DAction",tolua_collect_wyGridFlipY);
  #else
  tolua_cclass(tolua_S,"wyGridFlipY","wyGridFlipY","wyGrid3DAction",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyGridFlipY");
   tolua_function(tolua_S,"make",tolua_gridactions_wyGridFlipY_make00);
   tolua_function(tolua_S,"new",tolua_gridactions_wyGridFlipY_new00);
   tolua_function(tolua_S,"new_local",tolua_gridactions_wyGridFlipY_new00_local);
   tolua_function(tolua_S,".call",tolua_gridactions_wyGridFlipY_new00_local);
   tolua_function(tolua_S,"delete",tolua_gridactions_wyGridFlipY_delete00);
   tolua_function(tolua_S,"copy",tolua_gridactions_wyGridFlipY_copy00);
   tolua_function(tolua_S,"update",tolua_gridactions_wyGridFlipY_update00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyJumpTiles3D","wyJumpTiles3D","wyTiledGrid3DAction",tolua_collect_wyJumpTiles3D);
  #else
  tolua_cclass(tolua_S,"wyJumpTiles3D","wyJumpTiles3D","wyTiledGrid3DAction",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyJumpTiles3D");
   tolua_function(tolua_S,"make",tolua_gridactions_wyJumpTiles3D_make00);
   tolua_function(tolua_S,"new",tolua_gridactions_wyJumpTiles3D_new00);
   tolua_function(tolua_S,"new_local",tolua_gridactions_wyJumpTiles3D_new00_local);
   tolua_function(tolua_S,".call",tolua_gridactions_wyJumpTiles3D_new00_local);
   tolua_function(tolua_S,"delete",tolua_gridactions_wyJumpTiles3D_delete00);
   tolua_function(tolua_S,"copy",tolua_gridactions_wyJumpTiles3D_copy00);
   tolua_function(tolua_S,"update",tolua_gridactions_wyJumpTiles3D_update00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyLeftBottomTilesShrinkOut","wyLeftBottomTilesShrinkOut","wyTiledGrid3DAction",tolua_collect_wyLeftBottomTilesShrinkOut);
  #else
  tolua_cclass(tolua_S,"wyLeftBottomTilesShrinkOut","wyLeftBottomTilesShrinkOut","wyTiledGrid3DAction",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyLeftBottomTilesShrinkOut");
   tolua_function(tolua_S,"make",tolua_gridactions_wyLeftBottomTilesShrinkOut_make00);
   tolua_function(tolua_S,"new",tolua_gridactions_wyLeftBottomTilesShrinkOut_new00);
   tolua_function(tolua_S,"new_local",tolua_gridactions_wyLeftBottomTilesShrinkOut_new00_local);
   tolua_function(tolua_S,".call",tolua_gridactions_wyLeftBottomTilesShrinkOut_new00_local);
   tolua_function(tolua_S,"delete",tolua_gridactions_wyLeftBottomTilesShrinkOut_delete00);
   tolua_function(tolua_S,"copy",tolua_gridactions_wyLeftBottomTilesShrinkOut_copy00);
   tolua_function(tolua_S,"update",tolua_gridactions_wyLeftBottomTilesShrinkOut_update00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyLeftLineShrinkOut","wyLeftLineShrinkOut","wyTiledGrid3DAction",tolua_collect_wyLeftLineShrinkOut);
  #else
  tolua_cclass(tolua_S,"wyLeftLineShrinkOut","wyLeftLineShrinkOut","wyTiledGrid3DAction",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyLeftLineShrinkOut");
   tolua_function(tolua_S,"make",tolua_gridactions_wyLeftLineShrinkOut_make00);
   tolua_function(tolua_S,"new",tolua_gridactions_wyLeftLineShrinkOut_new00);
   tolua_function(tolua_S,"new_local",tolua_gridactions_wyLeftLineShrinkOut_new00_local);
   tolua_function(tolua_S,".call",tolua_gridactions_wyLeftLineShrinkOut_new00_local);
   tolua_function(tolua_S,"delete",tolua_gridactions_wyLeftLineShrinkOut_delete00);
   tolua_function(tolua_S,"copy",tolua_gridactions_wyLeftLineShrinkOut_copy00);
   tolua_function(tolua_S,"update",tolua_gridactions_wyLeftLineShrinkOut_update00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyLens3D","wyLens3D","wyGrid3DAction",tolua_collect_wyLens3D);
  #else
  tolua_cclass(tolua_S,"wyLens3D","wyLens3D","wyGrid3DAction",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyLens3D");
   tolua_function(tolua_S,"make",tolua_gridactions_wyLens3D_make00);
   tolua_function(tolua_S,"new",tolua_gridactions_wyLens3D_new00);
   tolua_function(tolua_S,"new_local",tolua_gridactions_wyLens3D_new00_local);
   tolua_function(tolua_S,".call",tolua_gridactions_wyLens3D_new00_local);
   tolua_function(tolua_S,"delete",tolua_gridactions_wyLens3D_delete00);
   tolua_function(tolua_S,"copy",tolua_gridactions_wyLens3D_copy00);
   tolua_function(tolua_S,"update",tolua_gridactions_wyLens3D_update00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyLiquid","wyLiquid","wyGrid3DAction",tolua_collect_wyLiquid);
  #else
  tolua_cclass(tolua_S,"wyLiquid","wyLiquid","wyGrid3DAction",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyLiquid");
   tolua_function(tolua_S,"make",tolua_gridactions_wyLiquid_make00);
   tolua_function(tolua_S,"new",tolua_gridactions_wyLiquid_new00);
   tolua_function(tolua_S,"new_local",tolua_gridactions_wyLiquid_new00_local);
   tolua_function(tolua_S,".call",tolua_gridactions_wyLiquid_new00_local);
   tolua_function(tolua_S,"delete",tolua_gridactions_wyLiquid_delete00);
   tolua_function(tolua_S,"copy",tolua_gridactions_wyLiquid_copy00);
   tolua_function(tolua_S,"update",tolua_gridactions_wyLiquid_update00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyPageTurn3D","wyPageTurn3D","wyGrid3DAction",tolua_collect_wyPageTurn3D);
  #else
  tolua_cclass(tolua_S,"wyPageTurn3D","wyPageTurn3D","wyGrid3DAction",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyPageTurn3D");
   tolua_function(tolua_S,"make",tolua_gridactions_wyPageTurn3D_make00);
   tolua_function(tolua_S,"new",tolua_gridactions_wyPageTurn3D_new00);
   tolua_function(tolua_S,"new_local",tolua_gridactions_wyPageTurn3D_new00_local);
   tolua_function(tolua_S,".call",tolua_gridactions_wyPageTurn3D_new00_local);
   tolua_function(tolua_S,"delete",tolua_gridactions_wyPageTurn3D_delete00);
   tolua_function(tolua_S,"copy",tolua_gridactions_wyPageTurn3D_copy00);
   tolua_function(tolua_S,"update",tolua_gridactions_wyPageTurn3D_update00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyReuseGrid","wyReuseGrid","wyInstantAction",tolua_collect_wyReuseGrid);
  #else
  tolua_cclass(tolua_S,"wyReuseGrid","wyReuseGrid","wyInstantAction",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyReuseGrid");
   tolua_function(tolua_S,"make",tolua_gridactions_wyReuseGrid_make00);
   tolua_function(tolua_S,"new",tolua_gridactions_wyReuseGrid_new00);
   tolua_function(tolua_S,"new_local",tolua_gridactions_wyReuseGrid_new00_local);
   tolua_function(tolua_S,".call",tolua_gridactions_wyReuseGrid_new00_local);
   tolua_function(tolua_S,"delete",tolua_gridactions_wyReuseGrid_delete00);
   tolua_function(tolua_S,"copy",tolua_gridactions_wyReuseGrid_copy00);
   tolua_function(tolua_S,"reverse",tolua_gridactions_wyReuseGrid_reverse00);
   tolua_function(tolua_S,"start",tolua_gridactions_wyReuseGrid_start00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyRightLineShrinkOut","wyRightLineShrinkOut","wyTiledGrid3DAction",tolua_collect_wyRightLineShrinkOut);
  #else
  tolua_cclass(tolua_S,"wyRightLineShrinkOut","wyRightLineShrinkOut","wyTiledGrid3DAction",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyRightLineShrinkOut");
   tolua_function(tolua_S,"make",tolua_gridactions_wyRightLineShrinkOut_make00);
   tolua_function(tolua_S,"new",tolua_gridactions_wyRightLineShrinkOut_new00);
   tolua_function(tolua_S,"new_local",tolua_gridactions_wyRightLineShrinkOut_new00_local);
   tolua_function(tolua_S,".call",tolua_gridactions_wyRightLineShrinkOut_new00_local);
   tolua_function(tolua_S,"delete",tolua_gridactions_wyRightLineShrinkOut_delete00);
   tolua_function(tolua_S,"copy",tolua_gridactions_wyRightLineShrinkOut_copy00);
   tolua_function(tolua_S,"update",tolua_gridactions_wyRightLineShrinkOut_update00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyRightTopTilesShrinkOut","wyRightTopTilesShrinkOut","wyTiledGrid3DAction",tolua_collect_wyRightTopTilesShrinkOut);
  #else
  tolua_cclass(tolua_S,"wyRightTopTilesShrinkOut","wyRightTopTilesShrinkOut","wyTiledGrid3DAction",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyRightTopTilesShrinkOut");
   tolua_function(tolua_S,"make",tolua_gridactions_wyRightTopTilesShrinkOut_make00);
   tolua_function(tolua_S,"new",tolua_gridactions_wyRightTopTilesShrinkOut_new00);
   tolua_function(tolua_S,"new_local",tolua_gridactions_wyRightTopTilesShrinkOut_new00_local);
   tolua_function(tolua_S,".call",tolua_gridactions_wyRightTopTilesShrinkOut_new00_local);
   tolua_function(tolua_S,"delete",tolua_gridactions_wyRightTopTilesShrinkOut_delete00);
   tolua_function(tolua_S,"copy",tolua_gridactions_wyRightTopTilesShrinkOut_copy00);
   tolua_function(tolua_S,"update",tolua_gridactions_wyRightTopTilesShrinkOut_update00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyRipple3D","wyRipple3D","wyGrid3DAction",tolua_collect_wyRipple3D);
  #else
  tolua_cclass(tolua_S,"wyRipple3D","wyRipple3D","wyGrid3DAction",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyRipple3D");
   tolua_function(tolua_S,"make",tolua_gridactions_wyRipple3D_make00);
   tolua_function(tolua_S,"new",tolua_gridactions_wyRipple3D_new00);
   tolua_function(tolua_S,"new_local",tolua_gridactions_wyRipple3D_new00_local);
   tolua_function(tolua_S,".call",tolua_gridactions_wyRipple3D_new00_local);
   tolua_function(tolua_S,"delete",tolua_gridactions_wyRipple3D_delete00);
   tolua_function(tolua_S,"copy",tolua_gridactions_wyRipple3D_copy00);
   tolua_function(tolua_S,"update",tolua_gridactions_wyRipple3D_update00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyShaky3D","wyShaky3D","wyGrid3DAction",tolua_collect_wyShaky3D);
  #else
  tolua_cclass(tolua_S,"wyShaky3D","wyShaky3D","wyGrid3DAction",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyShaky3D");
   tolua_function(tolua_S,"make",tolua_gridactions_wyShaky3D_make00);
   tolua_function(tolua_S,"new",tolua_gridactions_wyShaky3D_new00);
   tolua_function(tolua_S,"new_local",tolua_gridactions_wyShaky3D_new00_local);
   tolua_function(tolua_S,".call",tolua_gridactions_wyShaky3D_new00_local);
   tolua_function(tolua_S,"delete",tolua_gridactions_wyShaky3D_delete00);
   tolua_function(tolua_S,"copy",tolua_gridactions_wyShaky3D_copy00);
   tolua_function(tolua_S,"update",tolua_gridactions_wyShaky3D_update00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyShakyTiles3D","wyShakyTiles3D","wyTiledGrid3DAction",tolua_collect_wyShakyTiles3D);
  #else
  tolua_cclass(tolua_S,"wyShakyTiles3D","wyShakyTiles3D","wyTiledGrid3DAction",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyShakyTiles3D");
   tolua_function(tolua_S,"make",tolua_gridactions_wyShakyTiles3D_make00);
   tolua_function(tolua_S,"new",tolua_gridactions_wyShakyTiles3D_new00);
   tolua_function(tolua_S,"new_local",tolua_gridactions_wyShakyTiles3D_new00_local);
   tolua_function(tolua_S,".call",tolua_gridactions_wyShakyTiles3D_new00_local);
   tolua_function(tolua_S,"delete",tolua_gridactions_wyShakyTiles3D_delete00);
   tolua_function(tolua_S,"copy",tolua_gridactions_wyShakyTiles3D_copy00);
   tolua_function(tolua_S,"update",tolua_gridactions_wyShakyTiles3D_update00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyShatteredTiles3D","wyShatteredTiles3D","wyTiledGrid3DAction",tolua_collect_wyShatteredTiles3D);
  #else
  tolua_cclass(tolua_S,"wyShatteredTiles3D","wyShatteredTiles3D","wyTiledGrid3DAction",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyShatteredTiles3D");
   tolua_function(tolua_S,"make",tolua_gridactions_wyShatteredTiles3D_make00);
   tolua_function(tolua_S,"new",tolua_gridactions_wyShatteredTiles3D_new00);
   tolua_function(tolua_S,"new_local",tolua_gridactions_wyShatteredTiles3D_new00_local);
   tolua_function(tolua_S,".call",tolua_gridactions_wyShatteredTiles3D_new00_local);
   tolua_function(tolua_S,"delete",tolua_gridactions_wyShatteredTiles3D_delete00);
   tolua_function(tolua_S,"copy",tolua_gridactions_wyShatteredTiles3D_copy00);
   tolua_function(tolua_S,"update",tolua_gridactions_wyShatteredTiles3D_update00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"wyTile","wyTile","",NULL);
  tolua_beginmodule(tolua_S,"wyTile");
   tolua_variable(tolua_S,"position",tolua_get_wyTile_position,tolua_set_wyTile_position);
   tolua_variable(tolua_S,"startPosition",tolua_get_wyTile_startPosition,tolua_set_wyTile_startPosition);
   tolua_variable(tolua_S,"delta",tolua_get_wyTile_delta,tolua_set_wyTile_delta);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyShuffleTiles","wyShuffleTiles","wyTiledGrid3DAction",tolua_collect_wyShuffleTiles);
  #else
  tolua_cclass(tolua_S,"wyShuffleTiles","wyShuffleTiles","wyTiledGrid3DAction",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyShuffleTiles");
   tolua_function(tolua_S,"make",tolua_gridactions_wyShuffleTiles_make00);
   tolua_function(tolua_S,"new",tolua_gridactions_wyShuffleTiles_new00);
   tolua_function(tolua_S,"new_local",tolua_gridactions_wyShuffleTiles_new00_local);
   tolua_function(tolua_S,".call",tolua_gridactions_wyShuffleTiles_new00_local);
   tolua_function(tolua_S,"delete",tolua_gridactions_wyShuffleTiles_delete00);
   tolua_function(tolua_S,"copy",tolua_gridactions_wyShuffleTiles_copy00);
   tolua_function(tolua_S,"update",tolua_gridactions_wyShuffleTiles_update00);
   tolua_function(tolua_S,"start",tolua_gridactions_wyShuffleTiles_start00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wySplitCols","wySplitCols","wyTiledGrid3DAction",tolua_collect_wySplitCols);
  #else
  tolua_cclass(tolua_S,"wySplitCols","wySplitCols","wyTiledGrid3DAction",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wySplitCols");
   tolua_function(tolua_S,"make",tolua_gridactions_wySplitCols_make00);
   tolua_function(tolua_S,"new",tolua_gridactions_wySplitCols_new00);
   tolua_function(tolua_S,"new_local",tolua_gridactions_wySplitCols_new00_local);
   tolua_function(tolua_S,".call",tolua_gridactions_wySplitCols_new00_local);
   tolua_function(tolua_S,"delete",tolua_gridactions_wySplitCols_delete00);
   tolua_function(tolua_S,"copy",tolua_gridactions_wySplitCols_copy00);
   tolua_function(tolua_S,"update",tolua_gridactions_wySplitCols_update00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wySplitRows","wySplitRows","wyTiledGrid3DAction",tolua_collect_wySplitRows);
  #else
  tolua_cclass(tolua_S,"wySplitRows","wySplitRows","wyTiledGrid3DAction",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wySplitRows");
   tolua_function(tolua_S,"make",tolua_gridactions_wySplitRows_make00);
   tolua_function(tolua_S,"new",tolua_gridactions_wySplitRows_new00);
   tolua_function(tolua_S,"new_local",tolua_gridactions_wySplitRows_new00_local);
   tolua_function(tolua_S,".call",tolua_gridactions_wySplitRows_new00_local);
   tolua_function(tolua_S,"delete",tolua_gridactions_wySplitRows_delete00);
   tolua_function(tolua_S,"copy",tolua_gridactions_wySplitRows_copy00);
   tolua_function(tolua_S,"update",tolua_gridactions_wySplitRows_update00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyStopGrid","wyStopGrid","wyInstantAction",tolua_collect_wyStopGrid);
  #else
  tolua_cclass(tolua_S,"wyStopGrid","wyStopGrid","wyInstantAction",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyStopGrid");
   tolua_function(tolua_S,"make",tolua_gridactions_wyStopGrid_make00);
   tolua_function(tolua_S,"new",tolua_gridactions_wyStopGrid_new00);
   tolua_function(tolua_S,"new_local",tolua_gridactions_wyStopGrid_new00_local);
   tolua_function(tolua_S,".call",tolua_gridactions_wyStopGrid_new00_local);
   tolua_function(tolua_S,"delete",tolua_gridactions_wyStopGrid_delete00);
   tolua_function(tolua_S,"copy",tolua_gridactions_wyStopGrid_copy00);
   tolua_function(tolua_S,"reverse",tolua_gridactions_wyStopGrid_reverse00);
   tolua_function(tolua_S,"start",tolua_gridactions_wyStopGrid_start00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyTiledGrid3DAction","wyTiledGrid3DAction","wyGridAction",tolua_collect_wyTiledGrid3DAction);
  #else
  tolua_cclass(tolua_S,"wyTiledGrid3DAction","wyTiledGrid3DAction","wyGridAction",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyTiledGrid3DAction");
   tolua_function(tolua_S,"new",tolua_gridactions_wyTiledGrid3DAction_new00);
   tolua_function(tolua_S,"new_local",tolua_gridactions_wyTiledGrid3DAction_new00_local);
   tolua_function(tolua_S,".call",tolua_gridactions_wyTiledGrid3DAction_new00_local);
   tolua_function(tolua_S,"delete",tolua_gridactions_wyTiledGrid3DAction_delete00);
   tolua_function(tolua_S,"makeGrid",tolua_gridactions_wyTiledGrid3DAction_makeGrid00);
   tolua_function(tolua_S,"isGridReusable",tolua_gridactions_wyTiledGrid3DAction_isGridReusable00);
   tolua_function(tolua_S,"getTile",tolua_gridactions_wyTiledGrid3DAction_getTile00);
   tolua_function(tolua_S,"getOriginalTile",tolua_gridactions_wyTiledGrid3DAction_getOriginalTile00);
   tolua_function(tolua_S,"setTile",tolua_gridactions_wyTiledGrid3DAction_setTile00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyTopLineShrinkOut","wyTopLineShrinkOut","wyTiledGrid3DAction",tolua_collect_wyTopLineShrinkOut);
  #else
  tolua_cclass(tolua_S,"wyTopLineShrinkOut","wyTopLineShrinkOut","wyTiledGrid3DAction",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyTopLineShrinkOut");
   tolua_function(tolua_S,"make",tolua_gridactions_wyTopLineShrinkOut_make00);
   tolua_function(tolua_S,"new",tolua_gridactions_wyTopLineShrinkOut_new00);
   tolua_function(tolua_S,"new_local",tolua_gridactions_wyTopLineShrinkOut_new00_local);
   tolua_function(tolua_S,".call",tolua_gridactions_wyTopLineShrinkOut_new00_local);
   tolua_function(tolua_S,"delete",tolua_gridactions_wyTopLineShrinkOut_delete00);
   tolua_function(tolua_S,"copy",tolua_gridactions_wyTopLineShrinkOut_copy00);
   tolua_function(tolua_S,"update",tolua_gridactions_wyTopLineShrinkOut_update00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyTopTilesShrinkOut","wyTopTilesShrinkOut","wyTiledGrid3DAction",tolua_collect_wyTopTilesShrinkOut);
  #else
  tolua_cclass(tolua_S,"wyTopTilesShrinkOut","wyTopTilesShrinkOut","wyTiledGrid3DAction",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyTopTilesShrinkOut");
   tolua_function(tolua_S,"make",tolua_gridactions_wyTopTilesShrinkOut_make00);
   tolua_function(tolua_S,"new",tolua_gridactions_wyTopTilesShrinkOut_new00);
   tolua_function(tolua_S,"new_local",tolua_gridactions_wyTopTilesShrinkOut_new00_local);
   tolua_function(tolua_S,".call",tolua_gridactions_wyTopTilesShrinkOut_new00_local);
   tolua_function(tolua_S,"delete",tolua_gridactions_wyTopTilesShrinkOut_delete00);
   tolua_function(tolua_S,"copy",tolua_gridactions_wyTopTilesShrinkOut_copy00);
   tolua_function(tolua_S,"update",tolua_gridactions_wyTopTilesShrinkOut_update00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyTurnOffTiles","wyTurnOffTiles","wyTiledGrid3DAction",tolua_collect_wyTurnOffTiles);
  #else
  tolua_cclass(tolua_S,"wyTurnOffTiles","wyTurnOffTiles","wyTiledGrid3DAction",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyTurnOffTiles");
   tolua_function(tolua_S,"make",tolua_gridactions_wyTurnOffTiles_make00);
   tolua_function(tolua_S,"new",tolua_gridactions_wyTurnOffTiles_new00);
   tolua_function(tolua_S,"new_local",tolua_gridactions_wyTurnOffTiles_new00_local);
   tolua_function(tolua_S,".call",tolua_gridactions_wyTurnOffTiles_new00_local);
   tolua_function(tolua_S,"delete",tolua_gridactions_wyTurnOffTiles_delete00);
   tolua_function(tolua_S,"copy",tolua_gridactions_wyTurnOffTiles_copy00);
   tolua_function(tolua_S,"start",tolua_gridactions_wyTurnOffTiles_start00);
   tolua_function(tolua_S,"update",tolua_gridactions_wyTurnOffTiles_update00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyTwirl","wyTwirl","wyGrid3DAction",tolua_collect_wyTwirl);
  #else
  tolua_cclass(tolua_S,"wyTwirl","wyTwirl","wyGrid3DAction",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyTwirl");
   tolua_function(tolua_S,"make",tolua_gridactions_wyTwirl_make00);
   tolua_function(tolua_S,"new",tolua_gridactions_wyTwirl_new00);
   tolua_function(tolua_S,"new_local",tolua_gridactions_wyTwirl_new00_local);
   tolua_function(tolua_S,".call",tolua_gridactions_wyTwirl_new00_local);
   tolua_function(tolua_S,"delete",tolua_gridactions_wyTwirl_delete00);
   tolua_function(tolua_S,"copy",tolua_gridactions_wyTwirl_copy00);
   tolua_function(tolua_S,"update",tolua_gridactions_wyTwirl_update00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyWaves","wyWaves","wyGrid3DAction",tolua_collect_wyWaves);
  #else
  tolua_cclass(tolua_S,"wyWaves","wyWaves","wyGrid3DAction",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyWaves");
   tolua_function(tolua_S,"make",tolua_gridactions_wyWaves_make00);
   tolua_function(tolua_S,"new",tolua_gridactions_wyWaves_new00);
   tolua_function(tolua_S,"new_local",tolua_gridactions_wyWaves_new00_local);
   tolua_function(tolua_S,".call",tolua_gridactions_wyWaves_new00_local);
   tolua_function(tolua_S,"delete",tolua_gridactions_wyWaves_delete00);
   tolua_function(tolua_S,"copy",tolua_gridactions_wyWaves_copy00);
   tolua_function(tolua_S,"update",tolua_gridactions_wyWaves_update00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyWaves3D","wyWaves3D","wyGrid3DAction",tolua_collect_wyWaves3D);
  #else
  tolua_cclass(tolua_S,"wyWaves3D","wyWaves3D","wyGrid3DAction",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyWaves3D");
   tolua_function(tolua_S,"make",tolua_gridactions_wyWaves3D_make00);
   tolua_function(tolua_S,"new",tolua_gridactions_wyWaves3D_new00);
   tolua_function(tolua_S,"new_local",tolua_gridactions_wyWaves3D_new00_local);
   tolua_function(tolua_S,".call",tolua_gridactions_wyWaves3D_new00_local);
   tolua_function(tolua_S,"delete",tolua_gridactions_wyWaves3D_delete00);
   tolua_function(tolua_S,"copy",tolua_gridactions_wyWaves3D_copy00);
   tolua_function(tolua_S,"update",tolua_gridactions_wyWaves3D_update00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyWavesTiles3D","wyWavesTiles3D","wyTiledGrid3DAction",tolua_collect_wyWavesTiles3D);
  #else
  tolua_cclass(tolua_S,"wyWavesTiles3D","wyWavesTiles3D","wyTiledGrid3DAction",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyWavesTiles3D");
   tolua_function(tolua_S,"make",tolua_gridactions_wyWavesTiles3D_make00);
   tolua_function(tolua_S,"new",tolua_gridactions_wyWavesTiles3D_new00);
   tolua_function(tolua_S,"new_local",tolua_gridactions_wyWavesTiles3D_new00_local);
   tolua_function(tolua_S,".call",tolua_gridactions_wyWavesTiles3D_new00_local);
   tolua_function(tolua_S,"delete",tolua_gridactions_wyWavesTiles3D_delete00);
   tolua_function(tolua_S,"copy",tolua_gridactions_wyWavesTiles3D_copy00);
   tolua_function(tolua_S,"update",tolua_gridactions_wyWavesTiles3D_update00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wySuck","wySuck","wyGrid3DAction",tolua_collect_wySuck);
  #else
  tolua_cclass(tolua_S,"wySuck","wySuck","wyGrid3DAction",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wySuck");
   tolua_function(tolua_S,"make",tolua_gridactions_wySuck_make00);
   tolua_function(tolua_S,"delete",tolua_gridactions_wySuck_delete00);
   tolua_function(tolua_S,"copy",tolua_gridactions_wySuck_copy00);
   tolua_function(tolua_S,"update",tolua_gridactions_wySuck_update00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_gridactions (lua_State* tolua_S) {
 return tolua_gridactions_open(tolua_S);
};
#endif

