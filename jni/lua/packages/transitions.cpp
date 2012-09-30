/*
** Lua binding: transitions
** Generated automatically by tolua++-1.0.92 on Tue Jan 17 15:18:17 2012.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_transitions_open (lua_State* tolua_S);

#include "WiEngine.h"

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_wyFlipYTransition (lua_State* tolua_S)
{
 wyFlipYTransition* self = (wyFlipYTransition*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyZoomFlipAngularTransition (lua_State* tolua_S)
{
 wyZoomFlipAngularTransition* self = (wyZoomFlipAngularTransition*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wySuckTransition (lua_State* tolua_S)
{
 wySuckTransition* self = (wySuckTransition*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyLeftSlideInTransition (lua_State* tolua_S)
{
 wyLeftSlideInTransition* self = (wyLeftSlideInTransition*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wySplitColsTransition (lua_State* tolua_S)
{
 wySplitColsTransition* self = (wySplitColsTransition*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyJumpZoomTransition (lua_State* tolua_S)
{
 wyJumpZoomTransition* self = (wyJumpZoomTransition*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyPageTurn3DTransition (lua_State* tolua_S)
{
 wyPageTurn3DTransition* self = (wyPageTurn3DTransition*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyTransitionScene (lua_State* tolua_S)
{
 wyTransitionScene* self = (wyTransitionScene*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyRightSlideInTransition (lua_State* tolua_S)
{
 wyRightSlideInTransition* self = (wyRightSlideInTransition*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyRotateZoomTransition (lua_State* tolua_S)
{
 wyRotateZoomTransition* self = (wyRotateZoomTransition*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyShrinkGrowTransition (lua_State* tolua_S)
{
 wyShrinkGrowTransition* self = (wyShrinkGrowTransition*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyFlipXTransition (lua_State* tolua_S)
{
 wyFlipXTransition* self = (wyFlipXTransition*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyZoomFlipXTransition (lua_State* tolua_S)
{
 wyZoomFlipXTransition* self = (wyZoomFlipXTransition*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyRightTopTilesShrinkOutTransition (lua_State* tolua_S)
{
 wyRightTopTilesShrinkOutTransition* self = (wyRightTopTilesShrinkOutTransition*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyLeftPushInTransition (lua_State* tolua_S)
{
 wyLeftPushInTransition* self = (wyLeftPushInTransition*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyTurnOffTilesTransition (lua_State* tolua_S)
{
 wyTurnOffTilesTransition* self = (wyTurnOffTilesTransition*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyBottomPushInTransition (lua_State* tolua_S)
{
 wyBottomPushInTransition* self = (wyBottomPushInTransition*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyRadialCWTransition (lua_State* tolua_S)
{
 wyRadialCWTransition* self = (wyRadialCWTransition*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyBottomTilesShrinkOutTransition (lua_State* tolua_S)
{
 wyBottomTilesShrinkOutTransition* self = (wyBottomTilesShrinkOutTransition*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyZoomFlipYTransition (lua_State* tolua_S)
{
 wyZoomFlipYTransition* self = (wyZoomFlipYTransition*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyColorFadeTransition (lua_State* tolua_S)
{
 wyColorFadeTransition* self = (wyColorFadeTransition*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyTopTilesShrinkOutTransition (lua_State* tolua_S)
{
 wyTopTilesShrinkOutTransition* self = (wyTopTilesShrinkOutTransition*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyTopSlideInTransition (lua_State* tolua_S)
{
 wyTopSlideInTransition* self = (wyTopSlideInTransition*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyCrossFadeTransition (lua_State* tolua_S)
{
 wyCrossFadeTransition* self = (wyCrossFadeTransition*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyTopPushInTransition (lua_State* tolua_S)
{
 wyTopPushInTransition* self = (wyTopPushInTransition*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyLeftBottomTilesShrinkOutTransition (lua_State* tolua_S)
{
 wyLeftBottomTilesShrinkOutTransition* self = (wyLeftBottomTilesShrinkOutTransition*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyFlipAngularTransition (lua_State* tolua_S)
{
 wyFlipAngularTransition* self = (wyFlipAngularTransition*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wySplitRowsTransition (lua_State* tolua_S)
{
 wySplitRowsTransition* self = (wySplitRowsTransition*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyRightPushInTransition (lua_State* tolua_S)
{
 wyRightPushInTransition* self = (wyRightPushInTransition*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyBottomSlideInTransition (lua_State* tolua_S)
{
 wyBottomSlideInTransition* self = (wyBottomSlideInTransition*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyRadialCCWTransition (lua_State* tolua_S)
{
 wyRadialCCWTransition* self = (wyRadialCCWTransition*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"wyRightPushInTransition");
 tolua_usertype(tolua_S,"wyZoomFlipAngularTransition");
 tolua_usertype(tolua_S,"wyLeftSlideInTransition");
 tolua_usertype(tolua_S,"wyJumpZoomTransition");
 tolua_usertype(tolua_S,"wyTopTilesShrinkOutTransition");
 tolua_usertype(tolua_S,"wyRotateZoomTransition");
 tolua_usertype(tolua_S,"wyRadialCCWTransition");
 tolua_usertype(tolua_S,"wyLeftPushInTransition");
 tolua_usertype(tolua_S,"wyBottomPushInTransition");
 tolua_usertype(tolua_S,"wyRadialCWTransition");
 tolua_usertype(tolua_S,"wyBottomTilesShrinkOutTransition");
 tolua_usertype(tolua_S,"wyZoomFlipYTransition");
 tolua_usertype(tolua_S,"wyColorFadeTransition");
 tolua_usertype(tolua_S,"wyScene");
 tolua_usertype(tolua_S,"wyTopPushInTransition");
 tolua_usertype(tolua_S,"wySplitColsTransition");
 tolua_usertype(tolua_S,"wyPageTurn3DTransition");
 tolua_usertype(tolua_S,"wyColor3B");
 tolua_usertype(tolua_S,"wyRightSlideInTransition");
 tolua_usertype(tolua_S,"wySplitRowsTransition");
 tolua_usertype(tolua_S,"wyShrinkGrowTransition");
 tolua_usertype(tolua_S,"wyTopSlideInTransition");
 tolua_usertype(tolua_S,"wyZoomFlipXTransition");
 tolua_usertype(tolua_S,"wyRightTopTilesShrinkOutTransition");
 tolua_usertype(tolua_S,"wySuckTransition");
 tolua_usertype(tolua_S,"wyEaseAction");
 tolua_usertype(tolua_S,"wyCrossFadeTransition");
 tolua_usertype(tolua_S,"wyFlipYTransition");
 tolua_usertype(tolua_S,"wyLeftBottomTilesShrinkOutTransition");
 tolua_usertype(tolua_S,"wyFlipAngularTransition");
 tolua_usertype(tolua_S,"wyTurnOffTilesTransition");
 tolua_usertype(tolua_S,"wyFlipXTransition");
 tolua_usertype(tolua_S,"wyBottomSlideInTransition");
 tolua_usertype(tolua_S,"wyTransitionScene");
}

/* method: make of class  wyBottomPushInTransition */
#ifndef TOLUA_DISABLE_tolua_transitions_wyBottomPushInTransition_make00
static int tolua_transitions_wyBottomPushInTransition_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyBottomPushInTransition",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"wyScene",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  wyScene* inScene = ((wyScene*)  tolua_tousertype(tolua_S,3,0));
  {
   wyBottomPushInTransition* tolua_ret = (wyBottomPushInTransition*)  wyBottomPushInTransition::make(duration,inScene);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyBottomPushInTransition");
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

/* method: new of class  wyBottomPushInTransition */
#ifndef TOLUA_DISABLE_tolua_transitions_wyBottomPushInTransition_new00
static int tolua_transitions_wyBottomPushInTransition_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyBottomPushInTransition",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"wyScene",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  wyScene* inScene = ((wyScene*)  tolua_tousertype(tolua_S,3,0));
  {
   wyBottomPushInTransition* tolua_ret = (wyBottomPushInTransition*)  Mtolua_new((wyBottomPushInTransition)(duration,inScene));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyBottomPushInTransition");
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

/* method: new_local of class  wyBottomPushInTransition */
#ifndef TOLUA_DISABLE_tolua_transitions_wyBottomPushInTransition_new00_local
static int tolua_transitions_wyBottomPushInTransition_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyBottomPushInTransition",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"wyScene",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  wyScene* inScene = ((wyScene*)  tolua_tousertype(tolua_S,3,0));
  {
   wyBottomPushInTransition* tolua_ret = (wyBottomPushInTransition*)  Mtolua_new((wyBottomPushInTransition)(duration,inScene));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyBottomPushInTransition");
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

/* method: delete of class  wyBottomPushInTransition */
#ifndef TOLUA_DISABLE_tolua_transitions_wyBottomPushInTransition_delete00
static int tolua_transitions_wyBottomPushInTransition_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyBottomPushInTransition",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyBottomPushInTransition* self = (wyBottomPushInTransition*)  tolua_tousertype(tolua_S,1,0);
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

/* method: make of class  wyBottomSlideInTransition */
#ifndef TOLUA_DISABLE_tolua_transitions_wyBottomSlideInTransition_make00
static int tolua_transitions_wyBottomSlideInTransition_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyBottomSlideInTransition",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"wyScene",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  wyScene* inScene = ((wyScene*)  tolua_tousertype(tolua_S,3,0));
  {
   wyBottomSlideInTransition* tolua_ret = (wyBottomSlideInTransition*)  wyBottomSlideInTransition::make(duration,inScene);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyBottomSlideInTransition");
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

/* method: new of class  wyBottomSlideInTransition */
#ifndef TOLUA_DISABLE_tolua_transitions_wyBottomSlideInTransition_new00
static int tolua_transitions_wyBottomSlideInTransition_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyBottomSlideInTransition",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"wyScene",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  wyScene* inScene = ((wyScene*)  tolua_tousertype(tolua_S,3,0));
  {
   wyBottomSlideInTransition* tolua_ret = (wyBottomSlideInTransition*)  Mtolua_new((wyBottomSlideInTransition)(duration,inScene));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyBottomSlideInTransition");
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

/* method: new_local of class  wyBottomSlideInTransition */
#ifndef TOLUA_DISABLE_tolua_transitions_wyBottomSlideInTransition_new00_local
static int tolua_transitions_wyBottomSlideInTransition_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyBottomSlideInTransition",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"wyScene",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  wyScene* inScene = ((wyScene*)  tolua_tousertype(tolua_S,3,0));
  {
   wyBottomSlideInTransition* tolua_ret = (wyBottomSlideInTransition*)  Mtolua_new((wyBottomSlideInTransition)(duration,inScene));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyBottomSlideInTransition");
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

/* method: delete of class  wyBottomSlideInTransition */
#ifndef TOLUA_DISABLE_tolua_transitions_wyBottomSlideInTransition_delete00
static int tolua_transitions_wyBottomSlideInTransition_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyBottomSlideInTransition",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyBottomSlideInTransition* self = (wyBottomSlideInTransition*)  tolua_tousertype(tolua_S,1,0);
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

/* method: make of class  wyBottomTilesShrinkOutTransition */
#ifndef TOLUA_DISABLE_tolua_transitions_wyBottomTilesShrinkOutTransition_make00
static int tolua_transitions_wyBottomTilesShrinkOutTransition_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyBottomTilesShrinkOutTransition",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"wyScene",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  wyScene* inScene = ((wyScene*)  tolua_tousertype(tolua_S,3,0));
  int rows = ((int)  tolua_tonumber(tolua_S,4,0));
  int cols = ((int)  tolua_tonumber(tolua_S,5,0));
  {
   wyBottomTilesShrinkOutTransition* tolua_ret = (wyBottomTilesShrinkOutTransition*)  wyBottomTilesShrinkOutTransition::make(duration,inScene,rows,cols);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyBottomTilesShrinkOutTransition");
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

/* method: new of class  wyBottomTilesShrinkOutTransition */
#ifndef TOLUA_DISABLE_tolua_transitions_wyBottomTilesShrinkOutTransition_new00
static int tolua_transitions_wyBottomTilesShrinkOutTransition_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyBottomTilesShrinkOutTransition",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"wyScene",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  wyScene* inScene = ((wyScene*)  tolua_tousertype(tolua_S,3,0));
  int rows = ((int)  tolua_tonumber(tolua_S,4,0));
  int cols = ((int)  tolua_tonumber(tolua_S,5,0));
  {
   wyBottomTilesShrinkOutTransition* tolua_ret = (wyBottomTilesShrinkOutTransition*)  Mtolua_new((wyBottomTilesShrinkOutTransition)(duration,inScene,rows,cols));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyBottomTilesShrinkOutTransition");
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

/* method: new_local of class  wyBottomTilesShrinkOutTransition */
#ifndef TOLUA_DISABLE_tolua_transitions_wyBottomTilesShrinkOutTransition_new00_local
static int tolua_transitions_wyBottomTilesShrinkOutTransition_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyBottomTilesShrinkOutTransition",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"wyScene",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  wyScene* inScene = ((wyScene*)  tolua_tousertype(tolua_S,3,0));
  int rows = ((int)  tolua_tonumber(tolua_S,4,0));
  int cols = ((int)  tolua_tonumber(tolua_S,5,0));
  {
   wyBottomTilesShrinkOutTransition* tolua_ret = (wyBottomTilesShrinkOutTransition*)  Mtolua_new((wyBottomTilesShrinkOutTransition)(duration,inScene,rows,cols));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyBottomTilesShrinkOutTransition");
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

/* method: delete of class  wyBottomTilesShrinkOutTransition */
#ifndef TOLUA_DISABLE_tolua_transitions_wyBottomTilesShrinkOutTransition_delete00
static int tolua_transitions_wyBottomTilesShrinkOutTransition_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyBottomTilesShrinkOutTransition",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyBottomTilesShrinkOutTransition* self = (wyBottomTilesShrinkOutTransition*)  tolua_tousertype(tolua_S,1,0);
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

/* method: make of class  wyColorFadeTransition */
#ifndef TOLUA_DISABLE_tolua_transitions_wyColorFadeTransition_make00
static int tolua_transitions_wyColorFadeTransition_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyColorFadeTransition",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"wyScene",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"wyColor3B",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  wyScene* inScene = ((wyScene*)  tolua_tousertype(tolua_S,3,0));
  wyColor3B rgb = *((wyColor3B*)  tolua_tousertype(tolua_S,4,0));
  {
   wyColorFadeTransition* tolua_ret = (wyColorFadeTransition*)  wyColorFadeTransition::make(duration,inScene,rgb);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyColorFadeTransition");
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

/* method: new of class  wyColorFadeTransition */
#ifndef TOLUA_DISABLE_tolua_transitions_wyColorFadeTransition_new00
static int tolua_transitions_wyColorFadeTransition_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyColorFadeTransition",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"wyScene",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"wyColor3B",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  wyScene* inScene = ((wyScene*)  tolua_tousertype(tolua_S,3,0));
  wyColor3B rgb = *((wyColor3B*)  tolua_tousertype(tolua_S,4,0));
  {
   wyColorFadeTransition* tolua_ret = (wyColorFadeTransition*)  Mtolua_new((wyColorFadeTransition)(duration,inScene,rgb));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyColorFadeTransition");
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

/* method: new_local of class  wyColorFadeTransition */
#ifndef TOLUA_DISABLE_tolua_transitions_wyColorFadeTransition_new00_local
static int tolua_transitions_wyColorFadeTransition_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyColorFadeTransition",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"wyScene",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"wyColor3B",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  wyScene* inScene = ((wyScene*)  tolua_tousertype(tolua_S,3,0));
  wyColor3B rgb = *((wyColor3B*)  tolua_tousertype(tolua_S,4,0));
  {
   wyColorFadeTransition* tolua_ret = (wyColorFadeTransition*)  Mtolua_new((wyColorFadeTransition)(duration,inScene,rgb));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyColorFadeTransition");
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

/* method: delete of class  wyColorFadeTransition */
#ifndef TOLUA_DISABLE_tolua_transitions_wyColorFadeTransition_delete00
static int tolua_transitions_wyColorFadeTransition_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyColorFadeTransition",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyColorFadeTransition* self = (wyColorFadeTransition*)  tolua_tousertype(tolua_S,1,0);
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

/* method: make of class  wyCrossFadeTransition */
#ifndef TOLUA_DISABLE_tolua_transitions_wyCrossFadeTransition_make00
static int tolua_transitions_wyCrossFadeTransition_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyCrossFadeTransition",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"wyScene",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  wyScene* inScene = ((wyScene*)  tolua_tousertype(tolua_S,3,0));
  {
   wyCrossFadeTransition* tolua_ret = (wyCrossFadeTransition*)  wyCrossFadeTransition::make(duration,inScene);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyCrossFadeTransition");
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

/* method: new of class  wyCrossFadeTransition */
#ifndef TOLUA_DISABLE_tolua_transitions_wyCrossFadeTransition_new00
static int tolua_transitions_wyCrossFadeTransition_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyCrossFadeTransition",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"wyScene",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  wyScene* inScene = ((wyScene*)  tolua_tousertype(tolua_S,3,0));
  {
   wyCrossFadeTransition* tolua_ret = (wyCrossFadeTransition*)  Mtolua_new((wyCrossFadeTransition)(duration,inScene));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyCrossFadeTransition");
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

/* method: new_local of class  wyCrossFadeTransition */
#ifndef TOLUA_DISABLE_tolua_transitions_wyCrossFadeTransition_new00_local
static int tolua_transitions_wyCrossFadeTransition_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyCrossFadeTransition",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"wyScene",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  wyScene* inScene = ((wyScene*)  tolua_tousertype(tolua_S,3,0));
  {
   wyCrossFadeTransition* tolua_ret = (wyCrossFadeTransition*)  Mtolua_new((wyCrossFadeTransition)(duration,inScene));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyCrossFadeTransition");
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

/* method: delete of class  wyCrossFadeTransition */
#ifndef TOLUA_DISABLE_tolua_transitions_wyCrossFadeTransition_delete00
static int tolua_transitions_wyCrossFadeTransition_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyCrossFadeTransition",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyCrossFadeTransition* self = (wyCrossFadeTransition*)  tolua_tousertype(tolua_S,1,0);
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

/* method: make of class  wyFlipAngularTransition */
#ifndef TOLUA_DISABLE_tolua_transitions_wyFlipAngularTransition_make00
static int tolua_transitions_wyFlipAngularTransition_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyFlipAngularTransition",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"wyScene",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  wyScene* inScene = ((wyScene*)  tolua_tousertype(tolua_S,3,0));
  bool toLeft = ((bool)  tolua_toboolean(tolua_S,4,0));
  {
   wyFlipAngularTransition* tolua_ret = (wyFlipAngularTransition*)  wyFlipAngularTransition::make(duration,inScene,toLeft);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyFlipAngularTransition");
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

/* method: new of class  wyFlipAngularTransition */
#ifndef TOLUA_DISABLE_tolua_transitions_wyFlipAngularTransition_new00
static int tolua_transitions_wyFlipAngularTransition_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyFlipAngularTransition",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"wyScene",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  wyScene* inScene = ((wyScene*)  tolua_tousertype(tolua_S,3,0));
  bool toLeft = ((bool)  tolua_toboolean(tolua_S,4,0));
  {
   wyFlipAngularTransition* tolua_ret = (wyFlipAngularTransition*)  Mtolua_new((wyFlipAngularTransition)(duration,inScene,toLeft));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyFlipAngularTransition");
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

/* method: new_local of class  wyFlipAngularTransition */
#ifndef TOLUA_DISABLE_tolua_transitions_wyFlipAngularTransition_new00_local
static int tolua_transitions_wyFlipAngularTransition_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyFlipAngularTransition",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"wyScene",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  wyScene* inScene = ((wyScene*)  tolua_tousertype(tolua_S,3,0));
  bool toLeft = ((bool)  tolua_toboolean(tolua_S,4,0));
  {
   wyFlipAngularTransition* tolua_ret = (wyFlipAngularTransition*)  Mtolua_new((wyFlipAngularTransition)(duration,inScene,toLeft));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyFlipAngularTransition");
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

/* method: delete of class  wyFlipAngularTransition */
#ifndef TOLUA_DISABLE_tolua_transitions_wyFlipAngularTransition_delete00
static int tolua_transitions_wyFlipAngularTransition_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyFlipAngularTransition",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyFlipAngularTransition* self = (wyFlipAngularTransition*)  tolua_tousertype(tolua_S,1,0);
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

/* method: make of class  wyFlipXTransition */
#ifndef TOLUA_DISABLE_tolua_transitions_wyFlipXTransition_make00
static int tolua_transitions_wyFlipXTransition_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyFlipXTransition",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"wyScene",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  wyScene* inScene = ((wyScene*)  tolua_tousertype(tolua_S,3,0));
  bool toLeft = ((bool)  tolua_toboolean(tolua_S,4,0));
  {
   wyFlipXTransition* tolua_ret = (wyFlipXTransition*)  wyFlipXTransition::make(duration,inScene,toLeft);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyFlipXTransition");
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

/* method: new of class  wyFlipXTransition */
#ifndef TOLUA_DISABLE_tolua_transitions_wyFlipXTransition_new00
static int tolua_transitions_wyFlipXTransition_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyFlipXTransition",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"wyScene",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  wyScene* inScene = ((wyScene*)  tolua_tousertype(tolua_S,3,0));
  bool toLeft = ((bool)  tolua_toboolean(tolua_S,4,0));
  {
   wyFlipXTransition* tolua_ret = (wyFlipXTransition*)  Mtolua_new((wyFlipXTransition)(duration,inScene,toLeft));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyFlipXTransition");
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

/* method: new_local of class  wyFlipXTransition */
#ifndef TOLUA_DISABLE_tolua_transitions_wyFlipXTransition_new00_local
static int tolua_transitions_wyFlipXTransition_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyFlipXTransition",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"wyScene",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  wyScene* inScene = ((wyScene*)  tolua_tousertype(tolua_S,3,0));
  bool toLeft = ((bool)  tolua_toboolean(tolua_S,4,0));
  {
   wyFlipXTransition* tolua_ret = (wyFlipXTransition*)  Mtolua_new((wyFlipXTransition)(duration,inScene,toLeft));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyFlipXTransition");
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

/* method: delete of class  wyFlipXTransition */
#ifndef TOLUA_DISABLE_tolua_transitions_wyFlipXTransition_delete00
static int tolua_transitions_wyFlipXTransition_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyFlipXTransition",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyFlipXTransition* self = (wyFlipXTransition*)  tolua_tousertype(tolua_S,1,0);
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

/* method: make of class  wyFlipYTransition */
#ifndef TOLUA_DISABLE_tolua_transitions_wyFlipYTransition_make00
static int tolua_transitions_wyFlipYTransition_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyFlipYTransition",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"wyScene",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  wyScene* inScene = ((wyScene*)  tolua_tousertype(tolua_S,3,0));
  bool toTop = ((bool)  tolua_toboolean(tolua_S,4,0));
  {
   wyFlipYTransition* tolua_ret = (wyFlipYTransition*)  wyFlipYTransition::make(duration,inScene,toTop);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyFlipYTransition");
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

/* method: new of class  wyFlipYTransition */
#ifndef TOLUA_DISABLE_tolua_transitions_wyFlipYTransition_new00
static int tolua_transitions_wyFlipYTransition_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyFlipYTransition",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"wyScene",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  wyScene* inScene = ((wyScene*)  tolua_tousertype(tolua_S,3,0));
  bool toTop = ((bool)  tolua_toboolean(tolua_S,4,0));
  {
   wyFlipYTransition* tolua_ret = (wyFlipYTransition*)  Mtolua_new((wyFlipYTransition)(duration,inScene,toTop));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyFlipYTransition");
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

/* method: new_local of class  wyFlipYTransition */
#ifndef TOLUA_DISABLE_tolua_transitions_wyFlipYTransition_new00_local
static int tolua_transitions_wyFlipYTransition_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyFlipYTransition",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"wyScene",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  wyScene* inScene = ((wyScene*)  tolua_tousertype(tolua_S,3,0));
  bool toTop = ((bool)  tolua_toboolean(tolua_S,4,0));
  {
   wyFlipYTransition* tolua_ret = (wyFlipYTransition*)  Mtolua_new((wyFlipYTransition)(duration,inScene,toTop));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyFlipYTransition");
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

/* method: delete of class  wyFlipYTransition */
#ifndef TOLUA_DISABLE_tolua_transitions_wyFlipYTransition_delete00
static int tolua_transitions_wyFlipYTransition_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyFlipYTransition",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyFlipYTransition* self = (wyFlipYTransition*)  tolua_tousertype(tolua_S,1,0);
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

/* method: make of class  wyJumpZoomTransition */
#ifndef TOLUA_DISABLE_tolua_transitions_wyJumpZoomTransition_make00
static int tolua_transitions_wyJumpZoomTransition_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyJumpZoomTransition",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"wyScene",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  wyScene* inScene = ((wyScene*)  tolua_tousertype(tolua_S,3,0));
  {
   wyJumpZoomTransition* tolua_ret = (wyJumpZoomTransition*)  wyJumpZoomTransition::make(duration,inScene);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyJumpZoomTransition");
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

/* method: new of class  wyJumpZoomTransition */
#ifndef TOLUA_DISABLE_tolua_transitions_wyJumpZoomTransition_new00
static int tolua_transitions_wyJumpZoomTransition_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyJumpZoomTransition",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"wyScene",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  wyScene* inScene = ((wyScene*)  tolua_tousertype(tolua_S,3,0));
  {
   wyJumpZoomTransition* tolua_ret = (wyJumpZoomTransition*)  Mtolua_new((wyJumpZoomTransition)(duration,inScene));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyJumpZoomTransition");
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

/* method: new_local of class  wyJumpZoomTransition */
#ifndef TOLUA_DISABLE_tolua_transitions_wyJumpZoomTransition_new00_local
static int tolua_transitions_wyJumpZoomTransition_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyJumpZoomTransition",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"wyScene",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  wyScene* inScene = ((wyScene*)  tolua_tousertype(tolua_S,3,0));
  {
   wyJumpZoomTransition* tolua_ret = (wyJumpZoomTransition*)  Mtolua_new((wyJumpZoomTransition)(duration,inScene));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyJumpZoomTransition");
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

/* method: delete of class  wyJumpZoomTransition */
#ifndef TOLUA_DISABLE_tolua_transitions_wyJumpZoomTransition_delete00
static int tolua_transitions_wyJumpZoomTransition_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyJumpZoomTransition",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyJumpZoomTransition* self = (wyJumpZoomTransition*)  tolua_tousertype(tolua_S,1,0);
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

/* method: make of class  wyLeftBottomTilesShrinkOutTransition */
#ifndef TOLUA_DISABLE_tolua_transitions_wyLeftBottomTilesShrinkOutTransition_make00
static int tolua_transitions_wyLeftBottomTilesShrinkOutTransition_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyLeftBottomTilesShrinkOutTransition",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"wyScene",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  wyScene* inScene = ((wyScene*)  tolua_tousertype(tolua_S,3,0));
  int rows = ((int)  tolua_tonumber(tolua_S,4,0));
  int cols = ((int)  tolua_tonumber(tolua_S,5,0));
  {
   wyLeftBottomTilesShrinkOutTransition* tolua_ret = (wyLeftBottomTilesShrinkOutTransition*)  wyLeftBottomTilesShrinkOutTransition::make(duration,inScene,rows,cols);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyLeftBottomTilesShrinkOutTransition");
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

/* method: new of class  wyLeftBottomTilesShrinkOutTransition */
#ifndef TOLUA_DISABLE_tolua_transitions_wyLeftBottomTilesShrinkOutTransition_new00
static int tolua_transitions_wyLeftBottomTilesShrinkOutTransition_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyLeftBottomTilesShrinkOutTransition",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"wyScene",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  wyScene* inScene = ((wyScene*)  tolua_tousertype(tolua_S,3,0));
  int rows = ((int)  tolua_tonumber(tolua_S,4,0));
  int cols = ((int)  tolua_tonumber(tolua_S,5,0));
  {
   wyLeftBottomTilesShrinkOutTransition* tolua_ret = (wyLeftBottomTilesShrinkOutTransition*)  Mtolua_new((wyLeftBottomTilesShrinkOutTransition)(duration,inScene,rows,cols));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyLeftBottomTilesShrinkOutTransition");
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

/* method: new_local of class  wyLeftBottomTilesShrinkOutTransition */
#ifndef TOLUA_DISABLE_tolua_transitions_wyLeftBottomTilesShrinkOutTransition_new00_local
static int tolua_transitions_wyLeftBottomTilesShrinkOutTransition_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyLeftBottomTilesShrinkOutTransition",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"wyScene",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  wyScene* inScene = ((wyScene*)  tolua_tousertype(tolua_S,3,0));
  int rows = ((int)  tolua_tonumber(tolua_S,4,0));
  int cols = ((int)  tolua_tonumber(tolua_S,5,0));
  {
   wyLeftBottomTilesShrinkOutTransition* tolua_ret = (wyLeftBottomTilesShrinkOutTransition*)  Mtolua_new((wyLeftBottomTilesShrinkOutTransition)(duration,inScene,rows,cols));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyLeftBottomTilesShrinkOutTransition");
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

/* method: delete of class  wyLeftBottomTilesShrinkOutTransition */
#ifndef TOLUA_DISABLE_tolua_transitions_wyLeftBottomTilesShrinkOutTransition_delete00
static int tolua_transitions_wyLeftBottomTilesShrinkOutTransition_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyLeftBottomTilesShrinkOutTransition",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyLeftBottomTilesShrinkOutTransition* self = (wyLeftBottomTilesShrinkOutTransition*)  tolua_tousertype(tolua_S,1,0);
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

/* method: make of class  wyLeftPushInTransition */
#ifndef TOLUA_DISABLE_tolua_transitions_wyLeftPushInTransition_make00
static int tolua_transitions_wyLeftPushInTransition_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyLeftPushInTransition",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"wyScene",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  wyScene* inScene = ((wyScene*)  tolua_tousertype(tolua_S,3,0));
  {
   wyLeftPushInTransition* tolua_ret = (wyLeftPushInTransition*)  wyLeftPushInTransition::make(duration,inScene);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyLeftPushInTransition");
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

/* method: new of class  wyLeftPushInTransition */
#ifndef TOLUA_DISABLE_tolua_transitions_wyLeftPushInTransition_new00
static int tolua_transitions_wyLeftPushInTransition_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyLeftPushInTransition",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"wyScene",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  wyScene* inScene = ((wyScene*)  tolua_tousertype(tolua_S,3,0));
  {
   wyLeftPushInTransition* tolua_ret = (wyLeftPushInTransition*)  Mtolua_new((wyLeftPushInTransition)(duration,inScene));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyLeftPushInTransition");
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

/* method: new_local of class  wyLeftPushInTransition */
#ifndef TOLUA_DISABLE_tolua_transitions_wyLeftPushInTransition_new00_local
static int tolua_transitions_wyLeftPushInTransition_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyLeftPushInTransition",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"wyScene",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  wyScene* inScene = ((wyScene*)  tolua_tousertype(tolua_S,3,0));
  {
   wyLeftPushInTransition* tolua_ret = (wyLeftPushInTransition*)  Mtolua_new((wyLeftPushInTransition)(duration,inScene));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyLeftPushInTransition");
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

/* method: delete of class  wyLeftPushInTransition */
#ifndef TOLUA_DISABLE_tolua_transitions_wyLeftPushInTransition_delete00
static int tolua_transitions_wyLeftPushInTransition_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyLeftPushInTransition",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyLeftPushInTransition* self = (wyLeftPushInTransition*)  tolua_tousertype(tolua_S,1,0);
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

/* method: make of class  wyLeftSlideInTransition */
#ifndef TOLUA_DISABLE_tolua_transitions_wyLeftSlideInTransition_make00
static int tolua_transitions_wyLeftSlideInTransition_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyLeftSlideInTransition",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"wyScene",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  wyScene* inScene = ((wyScene*)  tolua_tousertype(tolua_S,3,0));
  {
   wyLeftSlideInTransition* tolua_ret = (wyLeftSlideInTransition*)  wyLeftSlideInTransition::make(duration,inScene);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyLeftSlideInTransition");
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

/* method: new of class  wyLeftSlideInTransition */
#ifndef TOLUA_DISABLE_tolua_transitions_wyLeftSlideInTransition_new00
static int tolua_transitions_wyLeftSlideInTransition_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyLeftSlideInTransition",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"wyScene",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  wyScene* inScene = ((wyScene*)  tolua_tousertype(tolua_S,3,0));
  {
   wyLeftSlideInTransition* tolua_ret = (wyLeftSlideInTransition*)  Mtolua_new((wyLeftSlideInTransition)(duration,inScene));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyLeftSlideInTransition");
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

/* method: new_local of class  wyLeftSlideInTransition */
#ifndef TOLUA_DISABLE_tolua_transitions_wyLeftSlideInTransition_new00_local
static int tolua_transitions_wyLeftSlideInTransition_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyLeftSlideInTransition",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"wyScene",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  wyScene* inScene = ((wyScene*)  tolua_tousertype(tolua_S,3,0));
  {
   wyLeftSlideInTransition* tolua_ret = (wyLeftSlideInTransition*)  Mtolua_new((wyLeftSlideInTransition)(duration,inScene));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyLeftSlideInTransition");
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

/* method: delete of class  wyLeftSlideInTransition */
#ifndef TOLUA_DISABLE_tolua_transitions_wyLeftSlideInTransition_delete00
static int tolua_transitions_wyLeftSlideInTransition_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyLeftSlideInTransition",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyLeftSlideInTransition* self = (wyLeftSlideInTransition*)  tolua_tousertype(tolua_S,1,0);
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

/* method: make of class  wyPageTurn3DTransition */
#ifndef TOLUA_DISABLE_tolua_transitions_wyPageTurn3DTransition_make00
static int tolua_transitions_wyPageTurn3DTransition_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyPageTurn3DTransition",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"wyScene",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  wyScene* inScene = ((wyScene*)  tolua_tousertype(tolua_S,3,0));
  {
   wyPageTurn3DTransition* tolua_ret = (wyPageTurn3DTransition*)  wyPageTurn3DTransition::make(duration,inScene);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyPageTurn3DTransition");
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

/* method: new of class  wyPageTurn3DTransition */
#ifndef TOLUA_DISABLE_tolua_transitions_wyPageTurn3DTransition_new00
static int tolua_transitions_wyPageTurn3DTransition_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyPageTurn3DTransition",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"wyScene",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  wyScene* inScene = ((wyScene*)  tolua_tousertype(tolua_S,3,0));
  {
   wyPageTurn3DTransition* tolua_ret = (wyPageTurn3DTransition*)  Mtolua_new((wyPageTurn3DTransition)(duration,inScene));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyPageTurn3DTransition");
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

/* method: new_local of class  wyPageTurn3DTransition */
#ifndef TOLUA_DISABLE_tolua_transitions_wyPageTurn3DTransition_new00_local
static int tolua_transitions_wyPageTurn3DTransition_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyPageTurn3DTransition",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"wyScene",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  wyScene* inScene = ((wyScene*)  tolua_tousertype(tolua_S,3,0));
  {
   wyPageTurn3DTransition* tolua_ret = (wyPageTurn3DTransition*)  Mtolua_new((wyPageTurn3DTransition)(duration,inScene));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyPageTurn3DTransition");
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

/* method: delete of class  wyPageTurn3DTransition */
#ifndef TOLUA_DISABLE_tolua_transitions_wyPageTurn3DTransition_delete00
static int tolua_transitions_wyPageTurn3DTransition_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyPageTurn3DTransition",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyPageTurn3DTransition* self = (wyPageTurn3DTransition*)  tolua_tousertype(tolua_S,1,0);
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

/* method: make of class  wyRadialCCWTransition */
#ifndef TOLUA_DISABLE_tolua_transitions_wyRadialCCWTransition_make00
static int tolua_transitions_wyRadialCCWTransition_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyRadialCCWTransition",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"wyScene",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  wyScene* inScene = ((wyScene*)  tolua_tousertype(tolua_S,3,0));
  {
   wyRadialCCWTransition* tolua_ret = (wyRadialCCWTransition*)  wyRadialCCWTransition::make(duration,inScene);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyRadialCCWTransition");
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

/* method: new of class  wyRadialCCWTransition */
#ifndef TOLUA_DISABLE_tolua_transitions_wyRadialCCWTransition_new00
static int tolua_transitions_wyRadialCCWTransition_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyRadialCCWTransition",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"wyScene",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  wyScene* inScene = ((wyScene*)  tolua_tousertype(tolua_S,3,0));
  {
   wyRadialCCWTransition* tolua_ret = (wyRadialCCWTransition*)  Mtolua_new((wyRadialCCWTransition)(duration,inScene));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyRadialCCWTransition");
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

/* method: new_local of class  wyRadialCCWTransition */
#ifndef TOLUA_DISABLE_tolua_transitions_wyRadialCCWTransition_new00_local
static int tolua_transitions_wyRadialCCWTransition_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyRadialCCWTransition",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"wyScene",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  wyScene* inScene = ((wyScene*)  tolua_tousertype(tolua_S,3,0));
  {
   wyRadialCCWTransition* tolua_ret = (wyRadialCCWTransition*)  Mtolua_new((wyRadialCCWTransition)(duration,inScene));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyRadialCCWTransition");
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

/* method: delete of class  wyRadialCCWTransition */
#ifndef TOLUA_DISABLE_tolua_transitions_wyRadialCCWTransition_delete00
static int tolua_transitions_wyRadialCCWTransition_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyRadialCCWTransition",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyRadialCCWTransition* self = (wyRadialCCWTransition*)  tolua_tousertype(tolua_S,1,0);
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

/* method: make of class  wyRadialCWTransition */
#ifndef TOLUA_DISABLE_tolua_transitions_wyRadialCWTransition_make00
static int tolua_transitions_wyRadialCWTransition_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyRadialCWTransition",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"wyScene",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  wyScene* inScene = ((wyScene*)  tolua_tousertype(tolua_S,3,0));
  {
   wyRadialCWTransition* tolua_ret = (wyRadialCWTransition*)  wyRadialCWTransition::make(duration,inScene);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyRadialCWTransition");
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

/* method: new of class  wyRadialCWTransition */
#ifndef TOLUA_DISABLE_tolua_transitions_wyRadialCWTransition_new00
static int tolua_transitions_wyRadialCWTransition_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyRadialCWTransition",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"wyScene",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  wyScene* inScene = ((wyScene*)  tolua_tousertype(tolua_S,3,0));
  {
   wyRadialCWTransition* tolua_ret = (wyRadialCWTransition*)  Mtolua_new((wyRadialCWTransition)(duration,inScene));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyRadialCWTransition");
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

/* method: new_local of class  wyRadialCWTransition */
#ifndef TOLUA_DISABLE_tolua_transitions_wyRadialCWTransition_new00_local
static int tolua_transitions_wyRadialCWTransition_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyRadialCWTransition",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"wyScene",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  wyScene* inScene = ((wyScene*)  tolua_tousertype(tolua_S,3,0));
  {
   wyRadialCWTransition* tolua_ret = (wyRadialCWTransition*)  Mtolua_new((wyRadialCWTransition)(duration,inScene));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyRadialCWTransition");
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

/* method: delete of class  wyRadialCWTransition */
#ifndef TOLUA_DISABLE_tolua_transitions_wyRadialCWTransition_delete00
static int tolua_transitions_wyRadialCWTransition_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyRadialCWTransition",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyRadialCWTransition* self = (wyRadialCWTransition*)  tolua_tousertype(tolua_S,1,0);
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

/* method: make of class  wyRightPushInTransition */
#ifndef TOLUA_DISABLE_tolua_transitions_wyRightPushInTransition_make00
static int tolua_transitions_wyRightPushInTransition_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyRightPushInTransition",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"wyScene",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  wyScene* inScene = ((wyScene*)  tolua_tousertype(tolua_S,3,0));
  {
   wyRightPushInTransition* tolua_ret = (wyRightPushInTransition*)  wyRightPushInTransition::make(duration,inScene);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyRightPushInTransition");
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

/* method: new of class  wyRightPushInTransition */
#ifndef TOLUA_DISABLE_tolua_transitions_wyRightPushInTransition_new00
static int tolua_transitions_wyRightPushInTransition_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyRightPushInTransition",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"wyScene",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  wyScene* inScene = ((wyScene*)  tolua_tousertype(tolua_S,3,0));
  {
   wyRightPushInTransition* tolua_ret = (wyRightPushInTransition*)  Mtolua_new((wyRightPushInTransition)(duration,inScene));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyRightPushInTransition");
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

/* method: new_local of class  wyRightPushInTransition */
#ifndef TOLUA_DISABLE_tolua_transitions_wyRightPushInTransition_new00_local
static int tolua_transitions_wyRightPushInTransition_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyRightPushInTransition",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"wyScene",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  wyScene* inScene = ((wyScene*)  tolua_tousertype(tolua_S,3,0));
  {
   wyRightPushInTransition* tolua_ret = (wyRightPushInTransition*)  Mtolua_new((wyRightPushInTransition)(duration,inScene));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyRightPushInTransition");
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

/* method: delete of class  wyRightPushInTransition */
#ifndef TOLUA_DISABLE_tolua_transitions_wyRightPushInTransition_delete00
static int tolua_transitions_wyRightPushInTransition_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyRightPushInTransition",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyRightPushInTransition* self = (wyRightPushInTransition*)  tolua_tousertype(tolua_S,1,0);
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

/* method: make of class  wyRightSlideInTransition */
#ifndef TOLUA_DISABLE_tolua_transitions_wyRightSlideInTransition_make00
static int tolua_transitions_wyRightSlideInTransition_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyRightSlideInTransition",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"wyScene",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  wyScene* inScene = ((wyScene*)  tolua_tousertype(tolua_S,3,0));
  {
   wyRightSlideInTransition* tolua_ret = (wyRightSlideInTransition*)  wyRightSlideInTransition::make(duration,inScene);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyRightSlideInTransition");
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

/* method: new of class  wyRightSlideInTransition */
#ifndef TOLUA_DISABLE_tolua_transitions_wyRightSlideInTransition_new00
static int tolua_transitions_wyRightSlideInTransition_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyRightSlideInTransition",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"wyScene",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  wyScene* inScene = ((wyScene*)  tolua_tousertype(tolua_S,3,0));
  {
   wyRightSlideInTransition* tolua_ret = (wyRightSlideInTransition*)  Mtolua_new((wyRightSlideInTransition)(duration,inScene));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyRightSlideInTransition");
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

/* method: new_local of class  wyRightSlideInTransition */
#ifndef TOLUA_DISABLE_tolua_transitions_wyRightSlideInTransition_new00_local
static int tolua_transitions_wyRightSlideInTransition_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyRightSlideInTransition",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"wyScene",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  wyScene* inScene = ((wyScene*)  tolua_tousertype(tolua_S,3,0));
  {
   wyRightSlideInTransition* tolua_ret = (wyRightSlideInTransition*)  Mtolua_new((wyRightSlideInTransition)(duration,inScene));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyRightSlideInTransition");
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

/* method: delete of class  wyRightSlideInTransition */
#ifndef TOLUA_DISABLE_tolua_transitions_wyRightSlideInTransition_delete00
static int tolua_transitions_wyRightSlideInTransition_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyRightSlideInTransition",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyRightSlideInTransition* self = (wyRightSlideInTransition*)  tolua_tousertype(tolua_S,1,0);
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

/* method: make of class  wyRightTopTilesShrinkOutTransition */
#ifndef TOLUA_DISABLE_tolua_transitions_wyRightTopTilesShrinkOutTransition_make00
static int tolua_transitions_wyRightTopTilesShrinkOutTransition_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyRightTopTilesShrinkOutTransition",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"wyScene",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  wyScene* inScene = ((wyScene*)  tolua_tousertype(tolua_S,3,0));
  int rows = ((int)  tolua_tonumber(tolua_S,4,0));
  int cols = ((int)  tolua_tonumber(tolua_S,5,0));
  {
   wyRightTopTilesShrinkOutTransition* tolua_ret = (wyRightTopTilesShrinkOutTransition*)  wyRightTopTilesShrinkOutTransition::make(duration,inScene,rows,cols);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyRightTopTilesShrinkOutTransition");
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

/* method: new of class  wyRightTopTilesShrinkOutTransition */
#ifndef TOLUA_DISABLE_tolua_transitions_wyRightTopTilesShrinkOutTransition_new00
static int tolua_transitions_wyRightTopTilesShrinkOutTransition_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyRightTopTilesShrinkOutTransition",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"wyScene",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  wyScene* inScene = ((wyScene*)  tolua_tousertype(tolua_S,3,0));
  int rows = ((int)  tolua_tonumber(tolua_S,4,0));
  int cols = ((int)  tolua_tonumber(tolua_S,5,0));
  {
   wyRightTopTilesShrinkOutTransition* tolua_ret = (wyRightTopTilesShrinkOutTransition*)  Mtolua_new((wyRightTopTilesShrinkOutTransition)(duration,inScene,rows,cols));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyRightTopTilesShrinkOutTransition");
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

/* method: new_local of class  wyRightTopTilesShrinkOutTransition */
#ifndef TOLUA_DISABLE_tolua_transitions_wyRightTopTilesShrinkOutTransition_new00_local
static int tolua_transitions_wyRightTopTilesShrinkOutTransition_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyRightTopTilesShrinkOutTransition",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"wyScene",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  wyScene* inScene = ((wyScene*)  tolua_tousertype(tolua_S,3,0));
  int rows = ((int)  tolua_tonumber(tolua_S,4,0));
  int cols = ((int)  tolua_tonumber(tolua_S,5,0));
  {
   wyRightTopTilesShrinkOutTransition* tolua_ret = (wyRightTopTilesShrinkOutTransition*)  Mtolua_new((wyRightTopTilesShrinkOutTransition)(duration,inScene,rows,cols));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyRightTopTilesShrinkOutTransition");
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

/* method: delete of class  wyRightTopTilesShrinkOutTransition */
#ifndef TOLUA_DISABLE_tolua_transitions_wyRightTopTilesShrinkOutTransition_delete00
static int tolua_transitions_wyRightTopTilesShrinkOutTransition_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyRightTopTilesShrinkOutTransition",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyRightTopTilesShrinkOutTransition* self = (wyRightTopTilesShrinkOutTransition*)  tolua_tousertype(tolua_S,1,0);
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

/* method: make of class  wyRotateZoomTransition */
#ifndef TOLUA_DISABLE_tolua_transitions_wyRotateZoomTransition_make00
static int tolua_transitions_wyRotateZoomTransition_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyRotateZoomTransition",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"wyScene",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  wyScene* inScene = ((wyScene*)  tolua_tousertype(tolua_S,3,0));
  {
   wyRotateZoomTransition* tolua_ret = (wyRotateZoomTransition*)  wyRotateZoomTransition::make(duration,inScene);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyRotateZoomTransition");
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

/* method: new of class  wyRotateZoomTransition */
#ifndef TOLUA_DISABLE_tolua_transitions_wyRotateZoomTransition_new00
static int tolua_transitions_wyRotateZoomTransition_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyRotateZoomTransition",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"wyScene",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  wyScene* inScene = ((wyScene*)  tolua_tousertype(tolua_S,3,0));
  {
   wyRotateZoomTransition* tolua_ret = (wyRotateZoomTransition*)  Mtolua_new((wyRotateZoomTransition)(duration,inScene));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyRotateZoomTransition");
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

/* method: new_local of class  wyRotateZoomTransition */
#ifndef TOLUA_DISABLE_tolua_transitions_wyRotateZoomTransition_new00_local
static int tolua_transitions_wyRotateZoomTransition_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyRotateZoomTransition",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"wyScene",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  wyScene* inScene = ((wyScene*)  tolua_tousertype(tolua_S,3,0));
  {
   wyRotateZoomTransition* tolua_ret = (wyRotateZoomTransition*)  Mtolua_new((wyRotateZoomTransition)(duration,inScene));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyRotateZoomTransition");
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

/* method: delete of class  wyRotateZoomTransition */
#ifndef TOLUA_DISABLE_tolua_transitions_wyRotateZoomTransition_delete00
static int tolua_transitions_wyRotateZoomTransition_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyRotateZoomTransition",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyRotateZoomTransition* self = (wyRotateZoomTransition*)  tolua_tousertype(tolua_S,1,0);
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

/* method: make of class  wyShrinkGrowTransition */
#ifndef TOLUA_DISABLE_tolua_transitions_wyShrinkGrowTransition_make00
static int tolua_transitions_wyShrinkGrowTransition_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyShrinkGrowTransition",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"wyScene",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  wyScene* inScene = ((wyScene*)  tolua_tousertype(tolua_S,3,0));
  {
   wyShrinkGrowTransition* tolua_ret = (wyShrinkGrowTransition*)  wyShrinkGrowTransition::make(duration,inScene);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyShrinkGrowTransition");
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

/* method: new of class  wyShrinkGrowTransition */
#ifndef TOLUA_DISABLE_tolua_transitions_wyShrinkGrowTransition_new00
static int tolua_transitions_wyShrinkGrowTransition_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyShrinkGrowTransition",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"wyScene",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  wyScene* inScene = ((wyScene*)  tolua_tousertype(tolua_S,3,0));
  {
   wyShrinkGrowTransition* tolua_ret = (wyShrinkGrowTransition*)  Mtolua_new((wyShrinkGrowTransition)(duration,inScene));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyShrinkGrowTransition");
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

/* method: new_local of class  wyShrinkGrowTransition */
#ifndef TOLUA_DISABLE_tolua_transitions_wyShrinkGrowTransition_new00_local
static int tolua_transitions_wyShrinkGrowTransition_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyShrinkGrowTransition",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"wyScene",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  wyScene* inScene = ((wyScene*)  tolua_tousertype(tolua_S,3,0));
  {
   wyShrinkGrowTransition* tolua_ret = (wyShrinkGrowTransition*)  Mtolua_new((wyShrinkGrowTransition)(duration,inScene));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyShrinkGrowTransition");
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

/* method: delete of class  wyShrinkGrowTransition */
#ifndef TOLUA_DISABLE_tolua_transitions_wyShrinkGrowTransition_delete00
static int tolua_transitions_wyShrinkGrowTransition_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyShrinkGrowTransition",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyShrinkGrowTransition* self = (wyShrinkGrowTransition*)  tolua_tousertype(tolua_S,1,0);
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

/* method: make of class  wySplitColsTransition */
#ifndef TOLUA_DISABLE_tolua_transitions_wySplitColsTransition_make00
static int tolua_transitions_wySplitColsTransition_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wySplitColsTransition",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"wyScene",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  wyScene* inScene = ((wyScene*)  tolua_tousertype(tolua_S,3,0));
  int cols = ((int)  tolua_tonumber(tolua_S,4,0));
  {
   wySplitColsTransition* tolua_ret = (wySplitColsTransition*)  wySplitColsTransition::make(duration,inScene,cols);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wySplitColsTransition");
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

/* method: new of class  wySplitColsTransition */
#ifndef TOLUA_DISABLE_tolua_transitions_wySplitColsTransition_new00
static int tolua_transitions_wySplitColsTransition_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wySplitColsTransition",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"wyScene",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  wyScene* inScene = ((wyScene*)  tolua_tousertype(tolua_S,3,0));
  int cols = ((int)  tolua_tonumber(tolua_S,4,0));
  {
   wySplitColsTransition* tolua_ret = (wySplitColsTransition*)  Mtolua_new((wySplitColsTransition)(duration,inScene,cols));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wySplitColsTransition");
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

/* method: new_local of class  wySplitColsTransition */
#ifndef TOLUA_DISABLE_tolua_transitions_wySplitColsTransition_new00_local
static int tolua_transitions_wySplitColsTransition_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wySplitColsTransition",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"wyScene",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  wyScene* inScene = ((wyScene*)  tolua_tousertype(tolua_S,3,0));
  int cols = ((int)  tolua_tonumber(tolua_S,4,0));
  {
   wySplitColsTransition* tolua_ret = (wySplitColsTransition*)  Mtolua_new((wySplitColsTransition)(duration,inScene,cols));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wySplitColsTransition");
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

/* method: delete of class  wySplitColsTransition */
#ifndef TOLUA_DISABLE_tolua_transitions_wySplitColsTransition_delete00
static int tolua_transitions_wySplitColsTransition_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wySplitColsTransition",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wySplitColsTransition* self = (wySplitColsTransition*)  tolua_tousertype(tolua_S,1,0);
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

/* method: make of class  wySplitRowsTransition */
#ifndef TOLUA_DISABLE_tolua_transitions_wySplitRowsTransition_make00
static int tolua_transitions_wySplitRowsTransition_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wySplitRowsTransition",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"wyScene",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  wyScene* inScene = ((wyScene*)  tolua_tousertype(tolua_S,3,0));
  int rows = ((int)  tolua_tonumber(tolua_S,4,0));
  {
   wySplitRowsTransition* tolua_ret = (wySplitRowsTransition*)  wySplitRowsTransition::make(duration,inScene,rows);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wySplitRowsTransition");
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

/* method: new of class  wySplitRowsTransition */
#ifndef TOLUA_DISABLE_tolua_transitions_wySplitRowsTransition_new00
static int tolua_transitions_wySplitRowsTransition_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wySplitRowsTransition",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"wyScene",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  wyScene* inScene = ((wyScene*)  tolua_tousertype(tolua_S,3,0));
  int rows = ((int)  tolua_tonumber(tolua_S,4,0));
  {
   wySplitRowsTransition* tolua_ret = (wySplitRowsTransition*)  Mtolua_new((wySplitRowsTransition)(duration,inScene,rows));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wySplitRowsTransition");
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

/* method: new_local of class  wySplitRowsTransition */
#ifndef TOLUA_DISABLE_tolua_transitions_wySplitRowsTransition_new00_local
static int tolua_transitions_wySplitRowsTransition_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wySplitRowsTransition",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"wyScene",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  wyScene* inScene = ((wyScene*)  tolua_tousertype(tolua_S,3,0));
  int rows = ((int)  tolua_tonumber(tolua_S,4,0));
  {
   wySplitRowsTransition* tolua_ret = (wySplitRowsTransition*)  Mtolua_new((wySplitRowsTransition)(duration,inScene,rows));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wySplitRowsTransition");
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

/* method: delete of class  wySplitRowsTransition */
#ifndef TOLUA_DISABLE_tolua_transitions_wySplitRowsTransition_delete00
static int tolua_transitions_wySplitRowsTransition_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wySplitRowsTransition",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wySplitRowsTransition* self = (wySplitRowsTransition*)  tolua_tousertype(tolua_S,1,0);
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

/* method: make of class  wyTopPushInTransition */
#ifndef TOLUA_DISABLE_tolua_transitions_wyTopPushInTransition_make00
static int tolua_transitions_wyTopPushInTransition_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyTopPushInTransition",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"wyScene",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  wyScene* inScene = ((wyScene*)  tolua_tousertype(tolua_S,3,0));
  {
   wyTopPushInTransition* tolua_ret = (wyTopPushInTransition*)  wyTopPushInTransition::make(duration,inScene);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyTopPushInTransition");
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

/* method: new of class  wyTopPushInTransition */
#ifndef TOLUA_DISABLE_tolua_transitions_wyTopPushInTransition_new00
static int tolua_transitions_wyTopPushInTransition_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyTopPushInTransition",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"wyScene",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  wyScene* inScene = ((wyScene*)  tolua_tousertype(tolua_S,3,0));
  {
   wyTopPushInTransition* tolua_ret = (wyTopPushInTransition*)  Mtolua_new((wyTopPushInTransition)(duration,inScene));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyTopPushInTransition");
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

/* method: new_local of class  wyTopPushInTransition */
#ifndef TOLUA_DISABLE_tolua_transitions_wyTopPushInTransition_new00_local
static int tolua_transitions_wyTopPushInTransition_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyTopPushInTransition",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"wyScene",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  wyScene* inScene = ((wyScene*)  tolua_tousertype(tolua_S,3,0));
  {
   wyTopPushInTransition* tolua_ret = (wyTopPushInTransition*)  Mtolua_new((wyTopPushInTransition)(duration,inScene));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyTopPushInTransition");
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

/* method: delete of class  wyTopPushInTransition */
#ifndef TOLUA_DISABLE_tolua_transitions_wyTopPushInTransition_delete00
static int tolua_transitions_wyTopPushInTransition_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTopPushInTransition",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTopPushInTransition* self = (wyTopPushInTransition*)  tolua_tousertype(tolua_S,1,0);
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

/* method: make of class  wyTopSlideInTransition */
#ifndef TOLUA_DISABLE_tolua_transitions_wyTopSlideInTransition_make00
static int tolua_transitions_wyTopSlideInTransition_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyTopSlideInTransition",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"wyScene",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  wyScene* inScene = ((wyScene*)  tolua_tousertype(tolua_S,3,0));
  {
   wyTopSlideInTransition* tolua_ret = (wyTopSlideInTransition*)  wyTopSlideInTransition::make(duration,inScene);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyTopSlideInTransition");
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

/* method: new of class  wyTopSlideInTransition */
#ifndef TOLUA_DISABLE_tolua_transitions_wyTopSlideInTransition_new00
static int tolua_transitions_wyTopSlideInTransition_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyTopSlideInTransition",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"wyScene",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  wyScene* inScene = ((wyScene*)  tolua_tousertype(tolua_S,3,0));
  {
   wyTopSlideInTransition* tolua_ret = (wyTopSlideInTransition*)  Mtolua_new((wyTopSlideInTransition)(duration,inScene));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyTopSlideInTransition");
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

/* method: new_local of class  wyTopSlideInTransition */
#ifndef TOLUA_DISABLE_tolua_transitions_wyTopSlideInTransition_new00_local
static int tolua_transitions_wyTopSlideInTransition_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyTopSlideInTransition",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"wyScene",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  wyScene* inScene = ((wyScene*)  tolua_tousertype(tolua_S,3,0));
  {
   wyTopSlideInTransition* tolua_ret = (wyTopSlideInTransition*)  Mtolua_new((wyTopSlideInTransition)(duration,inScene));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyTopSlideInTransition");
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

/* method: delete of class  wyTopSlideInTransition */
#ifndef TOLUA_DISABLE_tolua_transitions_wyTopSlideInTransition_delete00
static int tolua_transitions_wyTopSlideInTransition_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTopSlideInTransition",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTopSlideInTransition* self = (wyTopSlideInTransition*)  tolua_tousertype(tolua_S,1,0);
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

/* method: make of class  wyTopTilesShrinkOutTransition */
#ifndef TOLUA_DISABLE_tolua_transitions_wyTopTilesShrinkOutTransition_make00
static int tolua_transitions_wyTopTilesShrinkOutTransition_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyTopTilesShrinkOutTransition",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"wyScene",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  wyScene* inScene = ((wyScene*)  tolua_tousertype(tolua_S,3,0));
  int rows = ((int)  tolua_tonumber(tolua_S,4,0));
  int cols = ((int)  tolua_tonumber(tolua_S,5,0));
  {
   wyTopTilesShrinkOutTransition* tolua_ret = (wyTopTilesShrinkOutTransition*)  wyTopTilesShrinkOutTransition::make(duration,inScene,rows,cols);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyTopTilesShrinkOutTransition");
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

/* method: new of class  wyTopTilesShrinkOutTransition */
#ifndef TOLUA_DISABLE_tolua_transitions_wyTopTilesShrinkOutTransition_new00
static int tolua_transitions_wyTopTilesShrinkOutTransition_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyTopTilesShrinkOutTransition",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"wyScene",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  wyScene* inScene = ((wyScene*)  tolua_tousertype(tolua_S,3,0));
  int rows = ((int)  tolua_tonumber(tolua_S,4,0));
  int cols = ((int)  tolua_tonumber(tolua_S,5,0));
  {
   wyTopTilesShrinkOutTransition* tolua_ret = (wyTopTilesShrinkOutTransition*)  Mtolua_new((wyTopTilesShrinkOutTransition)(duration,inScene,rows,cols));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyTopTilesShrinkOutTransition");
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

/* method: new_local of class  wyTopTilesShrinkOutTransition */
#ifndef TOLUA_DISABLE_tolua_transitions_wyTopTilesShrinkOutTransition_new00_local
static int tolua_transitions_wyTopTilesShrinkOutTransition_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyTopTilesShrinkOutTransition",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"wyScene",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  wyScene* inScene = ((wyScene*)  tolua_tousertype(tolua_S,3,0));
  int rows = ((int)  tolua_tonumber(tolua_S,4,0));
  int cols = ((int)  tolua_tonumber(tolua_S,5,0));
  {
   wyTopTilesShrinkOutTransition* tolua_ret = (wyTopTilesShrinkOutTransition*)  Mtolua_new((wyTopTilesShrinkOutTransition)(duration,inScene,rows,cols));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyTopTilesShrinkOutTransition");
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

/* method: delete of class  wyTopTilesShrinkOutTransition */
#ifndef TOLUA_DISABLE_tolua_transitions_wyTopTilesShrinkOutTransition_delete00
static int tolua_transitions_wyTopTilesShrinkOutTransition_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTopTilesShrinkOutTransition",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTopTilesShrinkOutTransition* self = (wyTopTilesShrinkOutTransition*)  tolua_tousertype(tolua_S,1,0);
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

/* method: make of class  wyTransitionScene */
#ifndef TOLUA_DISABLE_tolua_transitions_wyTransitionScene_make00
static int tolua_transitions_wyTransitionScene_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyTransitionScene",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"wyScene",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  wyScene* inScene = ((wyScene*)  tolua_tousertype(tolua_S,3,0));
  {
   wyTransitionScene* tolua_ret = (wyTransitionScene*)  wyTransitionScene::make(duration,inScene);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyTransitionScene");
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

/* method: delete of class  wyTransitionScene */
#ifndef TOLUA_DISABLE_tolua_transitions_wyTransitionScene_delete00
static int tolua_transitions_wyTransitionScene_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTransitionScene",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTransitionScene* self = (wyTransitionScene*)  tolua_tousertype(tolua_S,1,0);
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

/* method: draw of class  wyTransitionScene */
#ifndef TOLUA_DISABLE_tolua_transitions_wyTransitionScene_draw00
static int tolua_transitions_wyTransitionScene_draw00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTransitionScene",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTransitionScene* self = (wyTransitionScene*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'draw'", NULL);
#endif
  {
   self->draw();
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

/* method: onEnter of class  wyTransitionScene */
#ifndef TOLUA_DISABLE_tolua_transitions_wyTransitionScene_onEnter00
static int tolua_transitions_wyTransitionScene_onEnter00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTransitionScene",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTransitionScene* self = (wyTransitionScene*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'onEnter'", NULL);
#endif
  {
   self->onEnter();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'onEnter'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: onExit of class  wyTransitionScene */
#ifndef TOLUA_DISABLE_tolua_transitions_wyTransitionScene_onExit00
static int tolua_transitions_wyTransitionScene_onExit00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTransitionScene",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTransitionScene* self = (wyTransitionScene*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'onExit'", NULL);
#endif
  {
   self->onExit();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'onExit'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isTransition of class  wyTransitionScene */
#ifndef TOLUA_DISABLE_tolua_transitions_wyTransitionScene_isTransition00
static int tolua_transitions_wyTransitionScene_isTransition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTransitionScene",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTransitionScene* self = (wyTransitionScene*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isTransition'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isTransition();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isTransition'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getInScene of class  wyTransitionScene */
#ifndef TOLUA_DISABLE_tolua_transitions_wyTransitionScene_getInScene00
static int tolua_transitions_wyTransitionScene_getInScene00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTransitionScene",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTransitionScene* self = (wyTransitionScene*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getInScene'", NULL);
#endif
  {
   wyScene* tolua_ret = (wyScene*)  self->getInScene();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyScene");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getInScene'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setInScene of class  wyTransitionScene */
#ifndef TOLUA_DISABLE_tolua_transitions_wyTransitionScene_setInScene00
static int tolua_transitions_wyTransitionScene_setInScene00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTransitionScene",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyScene",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTransitionScene* self = (wyTransitionScene*)  tolua_tousertype(tolua_S,1,0);
  wyScene* scene = ((wyScene*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setInScene'", NULL);
#endif
  {
   self->setInScene(scene);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setInScene'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getOutScene of class  wyTransitionScene */
#ifndef TOLUA_DISABLE_tolua_transitions_wyTransitionScene_getOutScene00
static int tolua_transitions_wyTransitionScene_getOutScene00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTransitionScene",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTransitionScene* self = (wyTransitionScene*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getOutScene'", NULL);
#endif
  {
   wyScene* tolua_ret = (wyScene*)  self->getOutScene();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyScene");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getOutScene'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setOutScene of class  wyTransitionScene */
#ifndef TOLUA_DISABLE_tolua_transitions_wyTransitionScene_setOutScene00
static int tolua_transitions_wyTransitionScene_setOutScene00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTransitionScene",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyScene",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTransitionScene* self = (wyTransitionScene*)  tolua_tousertype(tolua_S,1,0);
  wyScene* scene = ((wyScene*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setOutScene'", NULL);
#endif
  {
   self->setOutScene(scene);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setOutScene'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getDuration of class  wyTransitionScene */
#ifndef TOLUA_DISABLE_tolua_transitions_wyTransitionScene_getDuration00
static int tolua_transitions_wyTransitionScene_getDuration00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTransitionScene",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTransitionScene* self = (wyTransitionScene*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getDuration'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getDuration();
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

/* method: setInEaseAction of class  wyTransitionScene */
#ifndef TOLUA_DISABLE_tolua_transitions_wyTransitionScene_setInEaseAction00
static int tolua_transitions_wyTransitionScene_setInEaseAction00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTransitionScene",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyEaseAction",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTransitionScene* self = (wyTransitionScene*)  tolua_tousertype(tolua_S,1,0);
  wyEaseAction* inEase = ((wyEaseAction*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setInEaseAction'", NULL);
#endif
  {
   self->setInEaseAction(inEase);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setInEaseAction'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setOutEaseAction of class  wyTransitionScene */
#ifndef TOLUA_DISABLE_tolua_transitions_wyTransitionScene_setOutEaseAction00
static int tolua_transitions_wyTransitionScene_setOutEaseAction00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTransitionScene",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyEaseAction",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTransitionScene* self = (wyTransitionScene*)  tolua_tousertype(tolua_S,1,0);
  wyEaseAction* outEase = ((wyEaseAction*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setOutEaseAction'", NULL);
#endif
  {
   self->setOutEaseAction(outEase);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setOutEaseAction'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: make of class  wyTurnOffTilesTransition */
#ifndef TOLUA_DISABLE_tolua_transitions_wyTurnOffTilesTransition_make00
static int tolua_transitions_wyTurnOffTilesTransition_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyTurnOffTilesTransition",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"wyScene",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  wyScene* inScene = ((wyScene*)  tolua_tousertype(tolua_S,3,0));
  int rows = ((int)  tolua_tonumber(tolua_S,4,0));
  int cols = ((int)  tolua_tonumber(tolua_S,5,0));
  {
   wyTurnOffTilesTransition* tolua_ret = (wyTurnOffTilesTransition*)  wyTurnOffTilesTransition::make(duration,inScene,rows,cols);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyTurnOffTilesTransition");
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

/* method: new of class  wyTurnOffTilesTransition */
#ifndef TOLUA_DISABLE_tolua_transitions_wyTurnOffTilesTransition_new00
static int tolua_transitions_wyTurnOffTilesTransition_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyTurnOffTilesTransition",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"wyScene",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  wyScene* inScene = ((wyScene*)  tolua_tousertype(tolua_S,3,0));
  int rows = ((int)  tolua_tonumber(tolua_S,4,0));
  int cols = ((int)  tolua_tonumber(tolua_S,5,0));
  {
   wyTurnOffTilesTransition* tolua_ret = (wyTurnOffTilesTransition*)  Mtolua_new((wyTurnOffTilesTransition)(duration,inScene,rows,cols));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyTurnOffTilesTransition");
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

/* method: new_local of class  wyTurnOffTilesTransition */
#ifndef TOLUA_DISABLE_tolua_transitions_wyTurnOffTilesTransition_new00_local
static int tolua_transitions_wyTurnOffTilesTransition_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyTurnOffTilesTransition",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"wyScene",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  wyScene* inScene = ((wyScene*)  tolua_tousertype(tolua_S,3,0));
  int rows = ((int)  tolua_tonumber(tolua_S,4,0));
  int cols = ((int)  tolua_tonumber(tolua_S,5,0));
  {
   wyTurnOffTilesTransition* tolua_ret = (wyTurnOffTilesTransition*)  Mtolua_new((wyTurnOffTilesTransition)(duration,inScene,rows,cols));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyTurnOffTilesTransition");
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

/* method: delete of class  wyTurnOffTilesTransition */
#ifndef TOLUA_DISABLE_tolua_transitions_wyTurnOffTilesTransition_delete00
static int tolua_transitions_wyTurnOffTilesTransition_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTurnOffTilesTransition",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTurnOffTilesTransition* self = (wyTurnOffTilesTransition*)  tolua_tousertype(tolua_S,1,0);
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

/* method: make of class  wyZoomFlipAngularTransition */
#ifndef TOLUA_DISABLE_tolua_transitions_wyZoomFlipAngularTransition_make00
static int tolua_transitions_wyZoomFlipAngularTransition_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyZoomFlipAngularTransition",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"wyScene",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  wyScene* inScene = ((wyScene*)  tolua_tousertype(tolua_S,3,0));
  bool toLeft = ((bool)  tolua_toboolean(tolua_S,4,0));
  float scale = ((float)  tolua_tonumber(tolua_S,5,0));
  {
   wyZoomFlipAngularTransition* tolua_ret = (wyZoomFlipAngularTransition*)  wyZoomFlipAngularTransition::make(duration,inScene,toLeft,scale);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyZoomFlipAngularTransition");
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

/* method: new of class  wyZoomFlipAngularTransition */
#ifndef TOLUA_DISABLE_tolua_transitions_wyZoomFlipAngularTransition_new00
static int tolua_transitions_wyZoomFlipAngularTransition_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyZoomFlipAngularTransition",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"wyScene",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  wyScene* inScene = ((wyScene*)  tolua_tousertype(tolua_S,3,0));
  bool toLeft = ((bool)  tolua_toboolean(tolua_S,4,0));
  float scale = ((float)  tolua_tonumber(tolua_S,5,0));
  {
   wyZoomFlipAngularTransition* tolua_ret = (wyZoomFlipAngularTransition*)  Mtolua_new((wyZoomFlipAngularTransition)(duration,inScene,toLeft,scale));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyZoomFlipAngularTransition");
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

/* method: new_local of class  wyZoomFlipAngularTransition */
#ifndef TOLUA_DISABLE_tolua_transitions_wyZoomFlipAngularTransition_new00_local
static int tolua_transitions_wyZoomFlipAngularTransition_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyZoomFlipAngularTransition",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"wyScene",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  wyScene* inScene = ((wyScene*)  tolua_tousertype(tolua_S,3,0));
  bool toLeft = ((bool)  tolua_toboolean(tolua_S,4,0));
  float scale = ((float)  tolua_tonumber(tolua_S,5,0));
  {
   wyZoomFlipAngularTransition* tolua_ret = (wyZoomFlipAngularTransition*)  Mtolua_new((wyZoomFlipAngularTransition)(duration,inScene,toLeft,scale));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyZoomFlipAngularTransition");
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

/* method: delete of class  wyZoomFlipAngularTransition */
#ifndef TOLUA_DISABLE_tolua_transitions_wyZoomFlipAngularTransition_delete00
static int tolua_transitions_wyZoomFlipAngularTransition_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyZoomFlipAngularTransition",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyZoomFlipAngularTransition* self = (wyZoomFlipAngularTransition*)  tolua_tousertype(tolua_S,1,0);
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

/* method: make of class  wyZoomFlipXTransition */
#ifndef TOLUA_DISABLE_tolua_transitions_wyZoomFlipXTransition_make00
static int tolua_transitions_wyZoomFlipXTransition_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyZoomFlipXTransition",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"wyScene",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  wyScene* inScene = ((wyScene*)  tolua_tousertype(tolua_S,3,0));
  bool toLeft = ((bool)  tolua_toboolean(tolua_S,4,0));
  float scale = ((float)  tolua_tonumber(tolua_S,5,0));
  {
   wyZoomFlipXTransition* tolua_ret = (wyZoomFlipXTransition*)  wyZoomFlipXTransition::make(duration,inScene,toLeft,scale);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyZoomFlipXTransition");
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

/* method: new of class  wyZoomFlipXTransition */
#ifndef TOLUA_DISABLE_tolua_transitions_wyZoomFlipXTransition_new00
static int tolua_transitions_wyZoomFlipXTransition_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyZoomFlipXTransition",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"wyScene",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  wyScene* inScene = ((wyScene*)  tolua_tousertype(tolua_S,3,0));
  bool toLeft = ((bool)  tolua_toboolean(tolua_S,4,0));
  float scale = ((float)  tolua_tonumber(tolua_S,5,0));
  {
   wyZoomFlipXTransition* tolua_ret = (wyZoomFlipXTransition*)  Mtolua_new((wyZoomFlipXTransition)(duration,inScene,toLeft,scale));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyZoomFlipXTransition");
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

/* method: new_local of class  wyZoomFlipXTransition */
#ifndef TOLUA_DISABLE_tolua_transitions_wyZoomFlipXTransition_new00_local
static int tolua_transitions_wyZoomFlipXTransition_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyZoomFlipXTransition",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"wyScene",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  wyScene* inScene = ((wyScene*)  tolua_tousertype(tolua_S,3,0));
  bool toLeft = ((bool)  tolua_toboolean(tolua_S,4,0));
  float scale = ((float)  tolua_tonumber(tolua_S,5,0));
  {
   wyZoomFlipXTransition* tolua_ret = (wyZoomFlipXTransition*)  Mtolua_new((wyZoomFlipXTransition)(duration,inScene,toLeft,scale));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyZoomFlipXTransition");
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

/* method: delete of class  wyZoomFlipXTransition */
#ifndef TOLUA_DISABLE_tolua_transitions_wyZoomFlipXTransition_delete00
static int tolua_transitions_wyZoomFlipXTransition_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyZoomFlipXTransition",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyZoomFlipXTransition* self = (wyZoomFlipXTransition*)  tolua_tousertype(tolua_S,1,0);
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

/* method: make of class  wyZoomFlipYTransition */
#ifndef TOLUA_DISABLE_tolua_transitions_wyZoomFlipYTransition_make00
static int tolua_transitions_wyZoomFlipYTransition_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyZoomFlipYTransition",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"wyScene",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  wyScene* inScene = ((wyScene*)  tolua_tousertype(tolua_S,3,0));
  bool toTop = ((bool)  tolua_toboolean(tolua_S,4,0));
  float scale = ((float)  tolua_tonumber(tolua_S,5,0));
  {
   wyZoomFlipYTransition* tolua_ret = (wyZoomFlipYTransition*)  wyZoomFlipYTransition::make(duration,inScene,toTop,scale);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyZoomFlipYTransition");
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

/* method: new of class  wyZoomFlipYTransition */
#ifndef TOLUA_DISABLE_tolua_transitions_wyZoomFlipYTransition_new00
static int tolua_transitions_wyZoomFlipYTransition_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyZoomFlipYTransition",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"wyScene",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  wyScene* inScene = ((wyScene*)  tolua_tousertype(tolua_S,3,0));
  bool toTop = ((bool)  tolua_toboolean(tolua_S,4,0));
  float scale = ((float)  tolua_tonumber(tolua_S,5,0));
  {
   wyZoomFlipYTransition* tolua_ret = (wyZoomFlipYTransition*)  Mtolua_new((wyZoomFlipYTransition)(duration,inScene,toTop,scale));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyZoomFlipYTransition");
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

/* method: new_local of class  wyZoomFlipYTransition */
#ifndef TOLUA_DISABLE_tolua_transitions_wyZoomFlipYTransition_new00_local
static int tolua_transitions_wyZoomFlipYTransition_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyZoomFlipYTransition",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"wyScene",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  wyScene* inScene = ((wyScene*)  tolua_tousertype(tolua_S,3,0));
  bool toTop = ((bool)  tolua_toboolean(tolua_S,4,0));
  float scale = ((float)  tolua_tonumber(tolua_S,5,0));
  {
   wyZoomFlipYTransition* tolua_ret = (wyZoomFlipYTransition*)  Mtolua_new((wyZoomFlipYTransition)(duration,inScene,toTop,scale));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyZoomFlipYTransition");
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

/* method: delete of class  wyZoomFlipYTransition */
#ifndef TOLUA_DISABLE_tolua_transitions_wyZoomFlipYTransition_delete00
static int tolua_transitions_wyZoomFlipYTransition_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyZoomFlipYTransition",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyZoomFlipYTransition* self = (wyZoomFlipYTransition*)  tolua_tousertype(tolua_S,1,0);
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

/* method: make of class  wySuckTransition */
#ifndef TOLUA_DISABLE_tolua_transitions_wySuckTransition_make00
static int tolua_transitions_wySuckTransition_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wySuckTransition",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"wyScene",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  wyScene* inScene = ((wyScene*)  tolua_tousertype(tolua_S,3,0));
  float suckX = ((float)  tolua_tonumber(tolua_S,4,0));
  float suckY = ((float)  tolua_tonumber(tolua_S,5,0));
  {
   wySuckTransition* tolua_ret = (wySuckTransition*)  wySuckTransition::make(duration,inScene,suckX,suckY);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wySuckTransition");
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

/* method: delete of class  wySuckTransition */
#ifndef TOLUA_DISABLE_tolua_transitions_wySuckTransition_delete00
static int tolua_transitions_wySuckTransition_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wySuckTransition",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wySuckTransition* self = (wySuckTransition*)  tolua_tousertype(tolua_S,1,0);
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

/* Open function */
TOLUA_API int tolua_transitions_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyBottomPushInTransition","wyBottomPushInTransition","wyTransitionScene",tolua_collect_wyBottomPushInTransition);
  #else
  tolua_cclass(tolua_S,"wyBottomPushInTransition","wyBottomPushInTransition","wyTransitionScene",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyBottomPushInTransition");
   tolua_function(tolua_S,"make",tolua_transitions_wyBottomPushInTransition_make00);
   tolua_function(tolua_S,"new",tolua_transitions_wyBottomPushInTransition_new00);
   tolua_function(tolua_S,"new_local",tolua_transitions_wyBottomPushInTransition_new00_local);
   tolua_function(tolua_S,".call",tolua_transitions_wyBottomPushInTransition_new00_local);
   tolua_function(tolua_S,"delete",tolua_transitions_wyBottomPushInTransition_delete00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyBottomSlideInTransition","wyBottomSlideInTransition","wyTransitionScene",tolua_collect_wyBottomSlideInTransition);
  #else
  tolua_cclass(tolua_S,"wyBottomSlideInTransition","wyBottomSlideInTransition","wyTransitionScene",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyBottomSlideInTransition");
   tolua_function(tolua_S,"make",tolua_transitions_wyBottomSlideInTransition_make00);
   tolua_function(tolua_S,"new",tolua_transitions_wyBottomSlideInTransition_new00);
   tolua_function(tolua_S,"new_local",tolua_transitions_wyBottomSlideInTransition_new00_local);
   tolua_function(tolua_S,".call",tolua_transitions_wyBottomSlideInTransition_new00_local);
   tolua_function(tolua_S,"delete",tolua_transitions_wyBottomSlideInTransition_delete00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyBottomTilesShrinkOutTransition","wyBottomTilesShrinkOutTransition","wyTransitionScene",tolua_collect_wyBottomTilesShrinkOutTransition);
  #else
  tolua_cclass(tolua_S,"wyBottomTilesShrinkOutTransition","wyBottomTilesShrinkOutTransition","wyTransitionScene",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyBottomTilesShrinkOutTransition");
   tolua_function(tolua_S,"make",tolua_transitions_wyBottomTilesShrinkOutTransition_make00);
   tolua_function(tolua_S,"new",tolua_transitions_wyBottomTilesShrinkOutTransition_new00);
   tolua_function(tolua_S,"new_local",tolua_transitions_wyBottomTilesShrinkOutTransition_new00_local);
   tolua_function(tolua_S,".call",tolua_transitions_wyBottomTilesShrinkOutTransition_new00_local);
   tolua_function(tolua_S,"delete",tolua_transitions_wyBottomTilesShrinkOutTransition_delete00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyColorFadeTransition","wyColorFadeTransition","wyTransitionScene",tolua_collect_wyColorFadeTransition);
  #else
  tolua_cclass(tolua_S,"wyColorFadeTransition","wyColorFadeTransition","wyTransitionScene",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyColorFadeTransition");
   tolua_function(tolua_S,"make",tolua_transitions_wyColorFadeTransition_make00);
   tolua_function(tolua_S,"new",tolua_transitions_wyColorFadeTransition_new00);
   tolua_function(tolua_S,"new_local",tolua_transitions_wyColorFadeTransition_new00_local);
   tolua_function(tolua_S,".call",tolua_transitions_wyColorFadeTransition_new00_local);
   tolua_function(tolua_S,"delete",tolua_transitions_wyColorFadeTransition_delete00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyCrossFadeTransition","wyCrossFadeTransition","wyTransitionScene",tolua_collect_wyCrossFadeTransition);
  #else
  tolua_cclass(tolua_S,"wyCrossFadeTransition","wyCrossFadeTransition","wyTransitionScene",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyCrossFadeTransition");
   tolua_function(tolua_S,"make",tolua_transitions_wyCrossFadeTransition_make00);
   tolua_function(tolua_S,"new",tolua_transitions_wyCrossFadeTransition_new00);
   tolua_function(tolua_S,"new_local",tolua_transitions_wyCrossFadeTransition_new00_local);
   tolua_function(tolua_S,".call",tolua_transitions_wyCrossFadeTransition_new00_local);
   tolua_function(tolua_S,"delete",tolua_transitions_wyCrossFadeTransition_delete00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyFlipAngularTransition","wyFlipAngularTransition","wyTransitionScene",tolua_collect_wyFlipAngularTransition);
  #else
  tolua_cclass(tolua_S,"wyFlipAngularTransition","wyFlipAngularTransition","wyTransitionScene",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyFlipAngularTransition");
   tolua_function(tolua_S,"make",tolua_transitions_wyFlipAngularTransition_make00);
   tolua_function(tolua_S,"new",tolua_transitions_wyFlipAngularTransition_new00);
   tolua_function(tolua_S,"new_local",tolua_transitions_wyFlipAngularTransition_new00_local);
   tolua_function(tolua_S,".call",tolua_transitions_wyFlipAngularTransition_new00_local);
   tolua_function(tolua_S,"delete",tolua_transitions_wyFlipAngularTransition_delete00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyFlipXTransition","wyFlipXTransition","wyTransitionScene",tolua_collect_wyFlipXTransition);
  #else
  tolua_cclass(tolua_S,"wyFlipXTransition","wyFlipXTransition","wyTransitionScene",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyFlipXTransition");
   tolua_function(tolua_S,"make",tolua_transitions_wyFlipXTransition_make00);
   tolua_function(tolua_S,"new",tolua_transitions_wyFlipXTransition_new00);
   tolua_function(tolua_S,"new_local",tolua_transitions_wyFlipXTransition_new00_local);
   tolua_function(tolua_S,".call",tolua_transitions_wyFlipXTransition_new00_local);
   tolua_function(tolua_S,"delete",tolua_transitions_wyFlipXTransition_delete00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyFlipYTransition","wyFlipYTransition","wyTransitionScene",tolua_collect_wyFlipYTransition);
  #else
  tolua_cclass(tolua_S,"wyFlipYTransition","wyFlipYTransition","wyTransitionScene",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyFlipYTransition");
   tolua_function(tolua_S,"make",tolua_transitions_wyFlipYTransition_make00);
   tolua_function(tolua_S,"new",tolua_transitions_wyFlipYTransition_new00);
   tolua_function(tolua_S,"new_local",tolua_transitions_wyFlipYTransition_new00_local);
   tolua_function(tolua_S,".call",tolua_transitions_wyFlipYTransition_new00_local);
   tolua_function(tolua_S,"delete",tolua_transitions_wyFlipYTransition_delete00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyJumpZoomTransition","wyJumpZoomTransition","wyTransitionScene",tolua_collect_wyJumpZoomTransition);
  #else
  tolua_cclass(tolua_S,"wyJumpZoomTransition","wyJumpZoomTransition","wyTransitionScene",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyJumpZoomTransition");
   tolua_function(tolua_S,"make",tolua_transitions_wyJumpZoomTransition_make00);
   tolua_function(tolua_S,"new",tolua_transitions_wyJumpZoomTransition_new00);
   tolua_function(tolua_S,"new_local",tolua_transitions_wyJumpZoomTransition_new00_local);
   tolua_function(tolua_S,".call",tolua_transitions_wyJumpZoomTransition_new00_local);
   tolua_function(tolua_S,"delete",tolua_transitions_wyJumpZoomTransition_delete00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyLeftBottomTilesShrinkOutTransition","wyLeftBottomTilesShrinkOutTransition","wyTransitionScene",tolua_collect_wyLeftBottomTilesShrinkOutTransition);
  #else
  tolua_cclass(tolua_S,"wyLeftBottomTilesShrinkOutTransition","wyLeftBottomTilesShrinkOutTransition","wyTransitionScene",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyLeftBottomTilesShrinkOutTransition");
   tolua_function(tolua_S,"make",tolua_transitions_wyLeftBottomTilesShrinkOutTransition_make00);
   tolua_function(tolua_S,"new",tolua_transitions_wyLeftBottomTilesShrinkOutTransition_new00);
   tolua_function(tolua_S,"new_local",tolua_transitions_wyLeftBottomTilesShrinkOutTransition_new00_local);
   tolua_function(tolua_S,".call",tolua_transitions_wyLeftBottomTilesShrinkOutTransition_new00_local);
   tolua_function(tolua_S,"delete",tolua_transitions_wyLeftBottomTilesShrinkOutTransition_delete00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyLeftPushInTransition","wyLeftPushInTransition","wyTransitionScene",tolua_collect_wyLeftPushInTransition);
  #else
  tolua_cclass(tolua_S,"wyLeftPushInTransition","wyLeftPushInTransition","wyTransitionScene",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyLeftPushInTransition");
   tolua_function(tolua_S,"make",tolua_transitions_wyLeftPushInTransition_make00);
   tolua_function(tolua_S,"new",tolua_transitions_wyLeftPushInTransition_new00);
   tolua_function(tolua_S,"new_local",tolua_transitions_wyLeftPushInTransition_new00_local);
   tolua_function(tolua_S,".call",tolua_transitions_wyLeftPushInTransition_new00_local);
   tolua_function(tolua_S,"delete",tolua_transitions_wyLeftPushInTransition_delete00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyLeftSlideInTransition","wyLeftSlideInTransition","wyTransitionScene",tolua_collect_wyLeftSlideInTransition);
  #else
  tolua_cclass(tolua_S,"wyLeftSlideInTransition","wyLeftSlideInTransition","wyTransitionScene",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyLeftSlideInTransition");
   tolua_function(tolua_S,"make",tolua_transitions_wyLeftSlideInTransition_make00);
   tolua_function(tolua_S,"new",tolua_transitions_wyLeftSlideInTransition_new00);
   tolua_function(tolua_S,"new_local",tolua_transitions_wyLeftSlideInTransition_new00_local);
   tolua_function(tolua_S,".call",tolua_transitions_wyLeftSlideInTransition_new00_local);
   tolua_function(tolua_S,"delete",tolua_transitions_wyLeftSlideInTransition_delete00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyPageTurn3DTransition","wyPageTurn3DTransition","wyTransitionScene",tolua_collect_wyPageTurn3DTransition);
  #else
  tolua_cclass(tolua_S,"wyPageTurn3DTransition","wyPageTurn3DTransition","wyTransitionScene",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyPageTurn3DTransition");
   tolua_function(tolua_S,"make",tolua_transitions_wyPageTurn3DTransition_make00);
   tolua_function(tolua_S,"new",tolua_transitions_wyPageTurn3DTransition_new00);
   tolua_function(tolua_S,"new_local",tolua_transitions_wyPageTurn3DTransition_new00_local);
   tolua_function(tolua_S,".call",tolua_transitions_wyPageTurn3DTransition_new00_local);
   tolua_function(tolua_S,"delete",tolua_transitions_wyPageTurn3DTransition_delete00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyRadialCCWTransition","wyRadialCCWTransition","wyTransitionScene",tolua_collect_wyRadialCCWTransition);
  #else
  tolua_cclass(tolua_S,"wyRadialCCWTransition","wyRadialCCWTransition","wyTransitionScene",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyRadialCCWTransition");
   tolua_function(tolua_S,"make",tolua_transitions_wyRadialCCWTransition_make00);
   tolua_function(tolua_S,"new",tolua_transitions_wyRadialCCWTransition_new00);
   tolua_function(tolua_S,"new_local",tolua_transitions_wyRadialCCWTransition_new00_local);
   tolua_function(tolua_S,".call",tolua_transitions_wyRadialCCWTransition_new00_local);
   tolua_function(tolua_S,"delete",tolua_transitions_wyRadialCCWTransition_delete00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyRadialCWTransition","wyRadialCWTransition","wyRadialCCWTransition",tolua_collect_wyRadialCWTransition);
  #else
  tolua_cclass(tolua_S,"wyRadialCWTransition","wyRadialCWTransition","wyRadialCCWTransition",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyRadialCWTransition");
   tolua_function(tolua_S,"make",tolua_transitions_wyRadialCWTransition_make00);
   tolua_function(tolua_S,"new",tolua_transitions_wyRadialCWTransition_new00);
   tolua_function(tolua_S,"new_local",tolua_transitions_wyRadialCWTransition_new00_local);
   tolua_function(tolua_S,".call",tolua_transitions_wyRadialCWTransition_new00_local);
   tolua_function(tolua_S,"delete",tolua_transitions_wyRadialCWTransition_delete00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyRightPushInTransition","wyRightPushInTransition","wyTransitionScene",tolua_collect_wyRightPushInTransition);
  #else
  tolua_cclass(tolua_S,"wyRightPushInTransition","wyRightPushInTransition","wyTransitionScene",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyRightPushInTransition");
   tolua_function(tolua_S,"make",tolua_transitions_wyRightPushInTransition_make00);
   tolua_function(tolua_S,"new",tolua_transitions_wyRightPushInTransition_new00);
   tolua_function(tolua_S,"new_local",tolua_transitions_wyRightPushInTransition_new00_local);
   tolua_function(tolua_S,".call",tolua_transitions_wyRightPushInTransition_new00_local);
   tolua_function(tolua_S,"delete",tolua_transitions_wyRightPushInTransition_delete00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyRightSlideInTransition","wyRightSlideInTransition","wyTransitionScene",tolua_collect_wyRightSlideInTransition);
  #else
  tolua_cclass(tolua_S,"wyRightSlideInTransition","wyRightSlideInTransition","wyTransitionScene",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyRightSlideInTransition");
   tolua_function(tolua_S,"make",tolua_transitions_wyRightSlideInTransition_make00);
   tolua_function(tolua_S,"new",tolua_transitions_wyRightSlideInTransition_new00);
   tolua_function(tolua_S,"new_local",tolua_transitions_wyRightSlideInTransition_new00_local);
   tolua_function(tolua_S,".call",tolua_transitions_wyRightSlideInTransition_new00_local);
   tolua_function(tolua_S,"delete",tolua_transitions_wyRightSlideInTransition_delete00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyRightTopTilesShrinkOutTransition","wyRightTopTilesShrinkOutTransition","wyTransitionScene",tolua_collect_wyRightTopTilesShrinkOutTransition);
  #else
  tolua_cclass(tolua_S,"wyRightTopTilesShrinkOutTransition","wyRightTopTilesShrinkOutTransition","wyTransitionScene",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyRightTopTilesShrinkOutTransition");
   tolua_function(tolua_S,"make",tolua_transitions_wyRightTopTilesShrinkOutTransition_make00);
   tolua_function(tolua_S,"new",tolua_transitions_wyRightTopTilesShrinkOutTransition_new00);
   tolua_function(tolua_S,"new_local",tolua_transitions_wyRightTopTilesShrinkOutTransition_new00_local);
   tolua_function(tolua_S,".call",tolua_transitions_wyRightTopTilesShrinkOutTransition_new00_local);
   tolua_function(tolua_S,"delete",tolua_transitions_wyRightTopTilesShrinkOutTransition_delete00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyRotateZoomTransition","wyRotateZoomTransition","wyTransitionScene",tolua_collect_wyRotateZoomTransition);
  #else
  tolua_cclass(tolua_S,"wyRotateZoomTransition","wyRotateZoomTransition","wyTransitionScene",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyRotateZoomTransition");
   tolua_function(tolua_S,"make",tolua_transitions_wyRotateZoomTransition_make00);
   tolua_function(tolua_S,"new",tolua_transitions_wyRotateZoomTransition_new00);
   tolua_function(tolua_S,"new_local",tolua_transitions_wyRotateZoomTransition_new00_local);
   tolua_function(tolua_S,".call",tolua_transitions_wyRotateZoomTransition_new00_local);
   tolua_function(tolua_S,"delete",tolua_transitions_wyRotateZoomTransition_delete00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyShrinkGrowTransition","wyShrinkGrowTransition","wyTransitionScene",tolua_collect_wyShrinkGrowTransition);
  #else
  tolua_cclass(tolua_S,"wyShrinkGrowTransition","wyShrinkGrowTransition","wyTransitionScene",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyShrinkGrowTransition");
   tolua_function(tolua_S,"make",tolua_transitions_wyShrinkGrowTransition_make00);
   tolua_function(tolua_S,"new",tolua_transitions_wyShrinkGrowTransition_new00);
   tolua_function(tolua_S,"new_local",tolua_transitions_wyShrinkGrowTransition_new00_local);
   tolua_function(tolua_S,".call",tolua_transitions_wyShrinkGrowTransition_new00_local);
   tolua_function(tolua_S,"delete",tolua_transitions_wyShrinkGrowTransition_delete00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wySplitColsTransition","wySplitColsTransition","wyTransitionScene",tolua_collect_wySplitColsTransition);
  #else
  tolua_cclass(tolua_S,"wySplitColsTransition","wySplitColsTransition","wyTransitionScene",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wySplitColsTransition");
   tolua_function(tolua_S,"make",tolua_transitions_wySplitColsTransition_make00);
   tolua_function(tolua_S,"new",tolua_transitions_wySplitColsTransition_new00);
   tolua_function(tolua_S,"new_local",tolua_transitions_wySplitColsTransition_new00_local);
   tolua_function(tolua_S,".call",tolua_transitions_wySplitColsTransition_new00_local);
   tolua_function(tolua_S,"delete",tolua_transitions_wySplitColsTransition_delete00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wySplitRowsTransition","wySplitRowsTransition","wyTransitionScene",tolua_collect_wySplitRowsTransition);
  #else
  tolua_cclass(tolua_S,"wySplitRowsTransition","wySplitRowsTransition","wyTransitionScene",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wySplitRowsTransition");
   tolua_function(tolua_S,"make",tolua_transitions_wySplitRowsTransition_make00);
   tolua_function(tolua_S,"new",tolua_transitions_wySplitRowsTransition_new00);
   tolua_function(tolua_S,"new_local",tolua_transitions_wySplitRowsTransition_new00_local);
   tolua_function(tolua_S,".call",tolua_transitions_wySplitRowsTransition_new00_local);
   tolua_function(tolua_S,"delete",tolua_transitions_wySplitRowsTransition_delete00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyTopPushInTransition","wyTopPushInTransition","wyTransitionScene",tolua_collect_wyTopPushInTransition);
  #else
  tolua_cclass(tolua_S,"wyTopPushInTransition","wyTopPushInTransition","wyTransitionScene",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyTopPushInTransition");
   tolua_function(tolua_S,"make",tolua_transitions_wyTopPushInTransition_make00);
   tolua_function(tolua_S,"new",tolua_transitions_wyTopPushInTransition_new00);
   tolua_function(tolua_S,"new_local",tolua_transitions_wyTopPushInTransition_new00_local);
   tolua_function(tolua_S,".call",tolua_transitions_wyTopPushInTransition_new00_local);
   tolua_function(tolua_S,"delete",tolua_transitions_wyTopPushInTransition_delete00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyTopSlideInTransition","wyTopSlideInTransition","wyTransitionScene",tolua_collect_wyTopSlideInTransition);
  #else
  tolua_cclass(tolua_S,"wyTopSlideInTransition","wyTopSlideInTransition","wyTransitionScene",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyTopSlideInTransition");
   tolua_function(tolua_S,"make",tolua_transitions_wyTopSlideInTransition_make00);
   tolua_function(tolua_S,"new",tolua_transitions_wyTopSlideInTransition_new00);
   tolua_function(tolua_S,"new_local",tolua_transitions_wyTopSlideInTransition_new00_local);
   tolua_function(tolua_S,".call",tolua_transitions_wyTopSlideInTransition_new00_local);
   tolua_function(tolua_S,"delete",tolua_transitions_wyTopSlideInTransition_delete00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyTopTilesShrinkOutTransition","wyTopTilesShrinkOutTransition","wyTransitionScene",tolua_collect_wyTopTilesShrinkOutTransition);
  #else
  tolua_cclass(tolua_S,"wyTopTilesShrinkOutTransition","wyTopTilesShrinkOutTransition","wyTransitionScene",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyTopTilesShrinkOutTransition");
   tolua_function(tolua_S,"make",tolua_transitions_wyTopTilesShrinkOutTransition_make00);
   tolua_function(tolua_S,"new",tolua_transitions_wyTopTilesShrinkOutTransition_new00);
   tolua_function(tolua_S,"new_local",tolua_transitions_wyTopTilesShrinkOutTransition_new00_local);
   tolua_function(tolua_S,".call",tolua_transitions_wyTopTilesShrinkOutTransition_new00_local);
   tolua_function(tolua_S,"delete",tolua_transitions_wyTopTilesShrinkOutTransition_delete00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyTransitionScene","wyTransitionScene","wyScene",tolua_collect_wyTransitionScene);
  #else
  tolua_cclass(tolua_S,"wyTransitionScene","wyTransitionScene","wyScene",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyTransitionScene");
   tolua_function(tolua_S,"make",tolua_transitions_wyTransitionScene_make00);
   tolua_function(tolua_S,"delete",tolua_transitions_wyTransitionScene_delete00);
   tolua_function(tolua_S,"draw",tolua_transitions_wyTransitionScene_draw00);
   tolua_function(tolua_S,"onEnter",tolua_transitions_wyTransitionScene_onEnter00);
   tolua_function(tolua_S,"onExit",tolua_transitions_wyTransitionScene_onExit00);
   tolua_function(tolua_S,"isTransition",tolua_transitions_wyTransitionScene_isTransition00);
   tolua_function(tolua_S,"getInScene",tolua_transitions_wyTransitionScene_getInScene00);
   tolua_function(tolua_S,"setInScene",tolua_transitions_wyTransitionScene_setInScene00);
   tolua_function(tolua_S,"getOutScene",tolua_transitions_wyTransitionScene_getOutScene00);
   tolua_function(tolua_S,"setOutScene",tolua_transitions_wyTransitionScene_setOutScene00);
   tolua_function(tolua_S,"getDuration",tolua_transitions_wyTransitionScene_getDuration00);
   tolua_function(tolua_S,"setInEaseAction",tolua_transitions_wyTransitionScene_setInEaseAction00);
   tolua_function(tolua_S,"setOutEaseAction",tolua_transitions_wyTransitionScene_setOutEaseAction00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyTurnOffTilesTransition","wyTurnOffTilesTransition","wyTransitionScene",tolua_collect_wyTurnOffTilesTransition);
  #else
  tolua_cclass(tolua_S,"wyTurnOffTilesTransition","wyTurnOffTilesTransition","wyTransitionScene",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyTurnOffTilesTransition");
   tolua_function(tolua_S,"make",tolua_transitions_wyTurnOffTilesTransition_make00);
   tolua_function(tolua_S,"new",tolua_transitions_wyTurnOffTilesTransition_new00);
   tolua_function(tolua_S,"new_local",tolua_transitions_wyTurnOffTilesTransition_new00_local);
   tolua_function(tolua_S,".call",tolua_transitions_wyTurnOffTilesTransition_new00_local);
   tolua_function(tolua_S,"delete",tolua_transitions_wyTurnOffTilesTransition_delete00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyZoomFlipAngularTransition","wyZoomFlipAngularTransition","wyTransitionScene",tolua_collect_wyZoomFlipAngularTransition);
  #else
  tolua_cclass(tolua_S,"wyZoomFlipAngularTransition","wyZoomFlipAngularTransition","wyTransitionScene",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyZoomFlipAngularTransition");
   tolua_function(tolua_S,"make",tolua_transitions_wyZoomFlipAngularTransition_make00);
   tolua_function(tolua_S,"new",tolua_transitions_wyZoomFlipAngularTransition_new00);
   tolua_function(tolua_S,"new_local",tolua_transitions_wyZoomFlipAngularTransition_new00_local);
   tolua_function(tolua_S,".call",tolua_transitions_wyZoomFlipAngularTransition_new00_local);
   tolua_function(tolua_S,"delete",tolua_transitions_wyZoomFlipAngularTransition_delete00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyZoomFlipXTransition","wyZoomFlipXTransition","wyTransitionScene",tolua_collect_wyZoomFlipXTransition);
  #else
  tolua_cclass(tolua_S,"wyZoomFlipXTransition","wyZoomFlipXTransition","wyTransitionScene",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyZoomFlipXTransition");
   tolua_function(tolua_S,"make",tolua_transitions_wyZoomFlipXTransition_make00);
   tolua_function(tolua_S,"new",tolua_transitions_wyZoomFlipXTransition_new00);
   tolua_function(tolua_S,"new_local",tolua_transitions_wyZoomFlipXTransition_new00_local);
   tolua_function(tolua_S,".call",tolua_transitions_wyZoomFlipXTransition_new00_local);
   tolua_function(tolua_S,"delete",tolua_transitions_wyZoomFlipXTransition_delete00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyZoomFlipYTransition","wyZoomFlipYTransition","wyTransitionScene",tolua_collect_wyZoomFlipYTransition);
  #else
  tolua_cclass(tolua_S,"wyZoomFlipYTransition","wyZoomFlipYTransition","wyTransitionScene",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyZoomFlipYTransition");
   tolua_function(tolua_S,"make",tolua_transitions_wyZoomFlipYTransition_make00);
   tolua_function(tolua_S,"new",tolua_transitions_wyZoomFlipYTransition_new00);
   tolua_function(tolua_S,"new_local",tolua_transitions_wyZoomFlipYTransition_new00_local);
   tolua_function(tolua_S,".call",tolua_transitions_wyZoomFlipYTransition_new00_local);
   tolua_function(tolua_S,"delete",tolua_transitions_wyZoomFlipYTransition_delete00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wySuckTransition","wySuckTransition","wyTransitionScene",tolua_collect_wySuckTransition);
  #else
  tolua_cclass(tolua_S,"wySuckTransition","wySuckTransition","wyTransitionScene",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wySuckTransition");
   tolua_function(tolua_S,"make",tolua_transitions_wySuckTransition_make00);
   tolua_function(tolua_S,"delete",tolua_transitions_wySuckTransition_delete00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_transitions (lua_State* tolua_S) {
 return tolua_transitions_open(tolua_S);
};
#endif

