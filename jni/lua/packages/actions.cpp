/*
** Lua binding: actions
** Generated automatically by tolua++-1.0.92 on Tue Nov  6 14:58:56 2012.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_actions_open (lua_State* tolua_S);

#include "WiEngine.h"

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_wySpawn (lua_State* tolua_S)
{
 wySpawn* self = (wySpawn*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyDelayTime (lua_State* tolua_S)
{
 wyDelayTime* self = (wyDelayTime*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyJumpTo (lua_State* tolua_S)
{
 wyJumpTo* self = (wyJumpTo*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyProgressTo (lua_State* tolua_S)
{
 wyProgressTo* self = (wyProgressTo*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyPlace (lua_State* tolua_S)
{
 wyPlace* self = (wyPlace*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyShow (lua_State* tolua_S)
{
 wyShow* self = (wyShow*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyFadeOut (lua_State* tolua_S)
{
 wyFadeOut* self = (wyFadeOut*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyFollow (lua_State* tolua_S)
{
 wyFollow* self = (wyFollow*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyBezier (lua_State* tolua_S)
{
 wyBezier* self = (wyBezier*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyProgressBy (lua_State* tolua_S)
{
 wyProgressBy* self = (wyProgressBy*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyRotateBy (lua_State* tolua_S)
{
 wyRotateBy* self = (wyRotateBy*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyCallFunc (lua_State* tolua_S)
{
 wyCallFunc* self = (wyCallFunc*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wySequence (lua_State* tolua_S)
{
 wySequence* self = (wySequence*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyToggleVisibility (lua_State* tolua_S)
{
 wyToggleVisibility* self = (wyToggleVisibility*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wySkewTo (lua_State* tolua_S)
{
 wySkewTo* self = (wySkewTo*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyRotateTo (lua_State* tolua_S)
{
 wyRotateTo* self = (wyRotateTo*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyPoint (lua_State* tolua_S)
{
 wyPoint* self = (wyPoint*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyOrbitCamera (lua_State* tolua_S)
{
 wyOrbitCamera* self = (wyOrbitCamera*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyTintTo (lua_State* tolua_S)
{
 wyTintTo* self = (wyTintTo*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wySkewBy (lua_State* tolua_S)
{
 wySkewBy* self = (wySkewBy*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyHypotrochoid (lua_State* tolua_S)
{
 wyHypotrochoid* self = (wyHypotrochoid*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyMoveBy (lua_State* tolua_S)
{
 wyMoveBy* self = (wyMoveBy*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyMoveByAngle (lua_State* tolua_S)
{
 wyMoveByAngle* self = (wyMoveByAngle*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyMoveByPath (lua_State* tolua_S)
{
 wyMoveByPath* self = (wyMoveByPath*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyLagrange (lua_State* tolua_S)
{
 wyLagrange* self = (wyLagrange*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyFadeTo (lua_State* tolua_S)
{
 wyFadeTo* self = (wyFadeTo*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyTintBy (lua_State* tolua_S)
{
 wyTintBy* self = (wyTintBy*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyReverseTime (lua_State* tolua_S)
{
 wyReverseTime* self = (wyReverseTime*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyBlink (lua_State* tolua_S)
{
 wyBlink* self = (wyBlink*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyJumpBy (lua_State* tolua_S)
{
 wyJumpBy* self = (wyJumpBy*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wySpeed (lua_State* tolua_S)
{
 wySpeed* self = (wySpeed*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyHide (lua_State* tolua_S)
{
 wyHide* self = (wyHide*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyAnimate (lua_State* tolua_S)
{
 wyAnimate* self = (wyAnimate*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyFadeIn (lua_State* tolua_S)
{
 wyFadeIn* self = (wyFadeIn*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyShake (lua_State* tolua_S)
{
 wyShake* self = (wyShake*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyRepeat (lua_State* tolua_S)
{
 wyRepeat* self = (wyRepeat*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyScaleBy (lua_State* tolua_S)
{
 wyScaleBy* self = (wyScaleBy*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyMoveTo (lua_State* tolua_S)
{
 wyMoveTo* self = (wyMoveTo*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyScaleTo (lua_State* tolua_S)
{
 wyScaleTo* self = (wyScaleTo*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyRepeatForever (lua_State* tolua_S)
{
 wyRepeatForever* self = (wyRepeatForever*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"wyLagrangeConfig");
 tolua_usertype(tolua_S,"wyJumpBy");
 tolua_usertype(tolua_S,"wyDelayTime");
 tolua_usertype(tolua_S,"wyJumpTo");
 tolua_usertype(tolua_S,"wyProgressTo");
 tolua_usertype(tolua_S,"wyPlace");
 tolua_usertype(tolua_S,"wyAnimate");
 tolua_usertype(tolua_S,"wyFadeOut");
 tolua_usertype(tolua_S,"wyFollow");
 tolua_usertype(tolua_S,"wyCameraAction");
 tolua_usertype(tolua_S,"wyAnimation");
 tolua_usertype(tolua_S,"wyBezier");
 tolua_usertype(tolua_S,"wyRect");
 tolua_usertype(tolua_S,"wyProgressBy");
 tolua_usertype(tolua_S,"wyHypotrochoidConfig");
 tolua_usertype(tolua_S,"wySkewBy");
 tolua_usertype(tolua_S,"wyInstantAction");
 tolua_usertype(tolua_S,"wyNode");
 tolua_usertype(tolua_S,"wyActionCallback");
 tolua_usertype(tolua_S,"wyRotateBy");
 tolua_usertype(tolua_S,"wyObject");
 tolua_usertype(tolua_S,"wyCallFunc");
 tolua_usertype(tolua_S,"wyFadeTo");
 tolua_usertype(tolua_S,"wyHypotrochoid");
 tolua_usertype(tolua_S,"wyAction");
 tolua_usertype(tolua_S,"wyToggleVisibility");
 tolua_usertype(tolua_S,"wyTargetSelector");
 tolua_usertype(tolua_S,"wySkewTo");
 tolua_usertype(tolua_S,"wyMoveByPath");
 tolua_usertype(tolua_S,"wyRotateTo");
 tolua_usertype(tolua_S,"wyPoint");
 tolua_usertype(tolua_S,"wyOrbitCamera");
 tolua_usertype(tolua_S,"wyTintTo");
 tolua_usertype(tolua_S,"wySpeed");
 tolua_usertype(tolua_S,"wyFiniteTimeAction");
 tolua_usertype(tolua_S,"wyMoveBy");
 tolua_usertype(tolua_S,"wyMoveByAngle");
 tolua_usertype(tolua_S,"wyTintBy");
 tolua_usertype(tolua_S,"wyLagrange");
 tolua_usertype(tolua_S,"wySpawn");
 tolua_usertype(tolua_S,"wyShow");
 tolua_usertype(tolua_S,"wyBezierConfig");
 tolua_usertype(tolua_S,"wyBlink");
 tolua_usertype(tolua_S,"wyShake");
 tolua_usertype(tolua_S,"wySequence");
 tolua_usertype(tolua_S,"wyScaleTo");
 tolua_usertype(tolua_S,"wyIntervalAction");
 tolua_usertype(tolua_S,"wyHide");
 tolua_usertype(tolua_S,"wyFadeIn");
 tolua_usertype(tolua_S,"wyRepeat");
 tolua_usertype(tolua_S,"wyScaleBy");
 tolua_usertype(tolua_S,"wyMoveTo");
 tolua_usertype(tolua_S,"wyReverseTime");
 tolua_usertype(tolua_S,"wyRepeatForever");
}

/* method: make of class  wyAnimate */
#ifndef TOLUA_DISABLE_tolua_actions_wyAnimate_make00
static int tolua_actions_wyAnimate_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyAnimate",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyAnimation",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,3,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAnimation* anim = ((wyAnimation*)  tolua_tousertype(tolua_S,2,0));
  bool fillAfter = ((bool)  tolua_toboolean(tolua_S,3,false));
  {
   wyAnimate* tolua_ret = (wyAnimate*)  wyAnimate::make(anim,fillAfter);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyAnimate");
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

/* method: delete of class  wyAnimate */
#ifndef TOLUA_DISABLE_tolua_actions_wyAnimate_delete00
static int tolua_actions_wyAnimate_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAnimate",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAnimate* self = (wyAnimate*)  tolua_tousertype(tolua_S,1,0);
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

/* method: copy of class  wyAnimate */
#ifndef TOLUA_DISABLE_tolua_actions_wyAnimate_copy00
static int tolua_actions_wyAnimate_copy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAnimate",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAnimate* self = (wyAnimate*)  tolua_tousertype(tolua_S,1,0);
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

/* method: reverse of class  wyAnimate */
#ifndef TOLUA_DISABLE_tolua_actions_wyAnimate_reverse00
static int tolua_actions_wyAnimate_reverse00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAnimate",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAnimate* self = (wyAnimate*)  tolua_tousertype(tolua_S,1,0);
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

/* method: start of class  wyAnimate */
#ifndef TOLUA_DISABLE_tolua_actions_wyAnimate_start00
static int tolua_actions_wyAnimate_start00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAnimate",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAnimate* self = (wyAnimate*)  tolua_tousertype(tolua_S,1,0);
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

/* method: stop of class  wyAnimate */
#ifndef TOLUA_DISABLE_tolua_actions_wyAnimate_stop00
static int tolua_actions_wyAnimate_stop00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAnimate",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAnimate* self = (wyAnimate*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'stop'", NULL);
#endif
  {
   self->stop();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'stop'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: update of class  wyAnimate */
#ifndef TOLUA_DISABLE_tolua_actions_wyAnimate_update00
static int tolua_actions_wyAnimate_update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAnimate",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAnimate* self = (wyAnimate*)  tolua_tousertype(tolua_S,1,0);
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

/* method: make of class  wyBezier */
#ifndef TOLUA_DISABLE_tolua_actions_wyBezier_make00
static int tolua_actions_wyBezier_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyBezier",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"wyBezierConfig",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  wyBezierConfig config = *((wyBezierConfig*)  tolua_tousertype(tolua_S,3,0));
  {
   wyBezier* tolua_ret = (wyBezier*)  wyBezier::make(duration,config);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyBezier");
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

/* method: delete of class  wyBezier */
#ifndef TOLUA_DISABLE_tolua_actions_wyBezier_delete00
static int tolua_actions_wyBezier_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyBezier",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyBezier* self = (wyBezier*)  tolua_tousertype(tolua_S,1,0);
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

/* method: copy of class  wyBezier */
#ifndef TOLUA_DISABLE_tolua_actions_wyBezier_copy00
static int tolua_actions_wyBezier_copy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyBezier",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyBezier* self = (wyBezier*)  tolua_tousertype(tolua_S,1,0);
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

/* method: reverse of class  wyBezier */
#ifndef TOLUA_DISABLE_tolua_actions_wyBezier_reverse00
static int tolua_actions_wyBezier_reverse00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyBezier",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyBezier* self = (wyBezier*)  tolua_tousertype(tolua_S,1,0);
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

/* method: start of class  wyBezier */
#ifndef TOLUA_DISABLE_tolua_actions_wyBezier_start00
static int tolua_actions_wyBezier_start00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyBezier",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyBezier* self = (wyBezier*)  tolua_tousertype(tolua_S,1,0);
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

/* method: update of class  wyBezier */
#ifndef TOLUA_DISABLE_tolua_actions_wyBezier_update00
static int tolua_actions_wyBezier_update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyBezier",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyBezier* self = (wyBezier*)  tolua_tousertype(tolua_S,1,0);
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

/* method: setAutoRotate of class  wyBezier */
#ifndef TOLUA_DISABLE_tolua_actions_wyBezier_setAutoRotate00
static int tolua_actions_wyBezier_setAutoRotate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyBezier",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyBezier* self = (wyBezier*)  tolua_tousertype(tolua_S,1,0);
  bool flag = ((bool)  tolua_toboolean(tolua_S,2,0));
  float angleDelta = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setAutoRotate'", NULL);
#endif
  {
   self->setAutoRotate(flag,angleDelta);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setAutoRotate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setPinPoint of class  wyBezier */
#ifndef TOLUA_DISABLE_tolua_actions_wyBezier_setPinPoint00
static int tolua_actions_wyBezier_setPinPoint00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyBezier",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"wyPoint",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyBezier* self = (wyBezier*)  tolua_tousertype(tolua_S,1,0);
  wyPoint p = *((wyPoint*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setPinPoint'", NULL);
#endif
  {
   self->setPinPoint(p);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setPinPoint'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setPinPoint of class  wyBezier */
#ifndef TOLUA_DISABLE_tolua_actions_wyBezier_setPinPoint01
static int tolua_actions_wyBezier_setPinPoint01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyBezier",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  wyBezier* self = (wyBezier*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setPinPoint'", NULL);
#endif
  {
   self->setPinPoint(x,y);
  }
 }
 return 0;
tolua_lerror:
 return tolua_actions_wyBezier_setPinPoint00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: getPinPoint of class  wyBezier */
#ifndef TOLUA_DISABLE_tolua_actions_wyBezier_getPinPoint00
static int tolua_actions_wyBezier_getPinPoint00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyBezier",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyBezier* self = (wyBezier*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getPinPoint'", NULL);
#endif
  {
   wyPoint tolua_ret = (wyPoint)  self->getPinPoint();
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
 tolua_error(tolua_S,"#ferror in function 'getPinPoint'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: clearPinPoint of class  wyBezier */
#ifndef TOLUA_DISABLE_tolua_actions_wyBezier_clearPinPoint00
static int tolua_actions_wyBezier_clearPinPoint00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyBezier",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyBezier* self = (wyBezier*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'clearPinPoint'", NULL);
#endif
  {
   self->clearPinPoint();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'clearPinPoint'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setPinAngleDelta of class  wyBezier */
#ifndef TOLUA_DISABLE_tolua_actions_wyBezier_setPinAngleDelta00
static int tolua_actions_wyBezier_setPinAngleDelta00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyBezier",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyBezier* self = (wyBezier*)  tolua_tousertype(tolua_S,1,0);
  float delta = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setPinAngleDelta'", NULL);
#endif
  {
   self->setPinAngleDelta(delta);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setPinAngleDelta'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getPinAngleDelta of class  wyBezier */
#ifndef TOLUA_DISABLE_tolua_actions_wyBezier_getPinAngleDelta00
static int tolua_actions_wyBezier_getPinAngleDelta00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyBezier",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyBezier* self = (wyBezier*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getPinAngleDelta'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getPinAngleDelta();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getPinAngleDelta'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: make of class  wyBlink */
#ifndef TOLUA_DISABLE_tolua_actions_wyBlink_make00
static int tolua_actions_wyBlink_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyBlink",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  float times = ((float)  tolua_tonumber(tolua_S,3,0));
  {
   wyBlink* tolua_ret = (wyBlink*)  wyBlink::make(duration,times);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyBlink");
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

/* method: delete of class  wyBlink */
#ifndef TOLUA_DISABLE_tolua_actions_wyBlink_delete00
static int tolua_actions_wyBlink_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyBlink",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyBlink* self = (wyBlink*)  tolua_tousertype(tolua_S,1,0);
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

/* method: copy of class  wyBlink */
#ifndef TOLUA_DISABLE_tolua_actions_wyBlink_copy00
static int tolua_actions_wyBlink_copy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyBlink",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyBlink* self = (wyBlink*)  tolua_tousertype(tolua_S,1,0);
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

/* method: reverse of class  wyBlink */
#ifndef TOLUA_DISABLE_tolua_actions_wyBlink_reverse00
static int tolua_actions_wyBlink_reverse00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyBlink",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyBlink* self = (wyBlink*)  tolua_tousertype(tolua_S,1,0);
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

/* method: update of class  wyBlink */
#ifndef TOLUA_DISABLE_tolua_actions_wyBlink_update00
static int tolua_actions_wyBlink_update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyBlink",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyBlink* self = (wyBlink*)  tolua_tousertype(tolua_S,1,0);
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

/* method: stop of class  wyBlink */
#ifndef TOLUA_DISABLE_tolua_actions_wyBlink_stop00
static int tolua_actions_wyBlink_stop00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyBlink",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyBlink* self = (wyBlink*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'stop'", NULL);
#endif
  {
   self->stop();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'stop'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: make of class  wyCallFunc */
#ifndef TOLUA_DISABLE_tolua_actions_wyCallFunc_make00
static int tolua_actions_wyCallFunc_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyCallFunc",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyTargetSelector",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTargetSelector* ts = ((wyTargetSelector*)  tolua_tousertype(tolua_S,2,0));
  {
   wyCallFunc* tolua_ret = (wyCallFunc*)  wyCallFunc::make(ts);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyCallFunc");
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

/* method: delete of class  wyCallFunc */
#ifndef TOLUA_DISABLE_tolua_actions_wyCallFunc_delete00
static int tolua_actions_wyCallFunc_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyCallFunc",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyCallFunc* self = (wyCallFunc*)  tolua_tousertype(tolua_S,1,0);
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

/* method: copy of class  wyCallFunc */
#ifndef TOLUA_DISABLE_tolua_actions_wyCallFunc_copy00
static int tolua_actions_wyCallFunc_copy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyCallFunc",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyCallFunc* self = (wyCallFunc*)  tolua_tousertype(tolua_S,1,0);
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

/* method: reverse of class  wyCallFunc */
#ifndef TOLUA_DISABLE_tolua_actions_wyCallFunc_reverse00
static int tolua_actions_wyCallFunc_reverse00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyCallFunc",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyCallFunc* self = (wyCallFunc*)  tolua_tousertype(tolua_S,1,0);
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

/* method: start of class  wyCallFunc */
#ifndef TOLUA_DISABLE_tolua_actions_wyCallFunc_start00
static int tolua_actions_wyCallFunc_start00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyCallFunc",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyCallFunc* self = (wyCallFunc*)  tolua_tousertype(tolua_S,1,0);
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

/* method: reverse of class  wyCameraAction */
#ifndef TOLUA_DISABLE_tolua_actions_wyCameraAction_reverse00
static int tolua_actions_wyCameraAction_reverse00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyCameraAction",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyCameraAction* self = (wyCameraAction*)  tolua_tousertype(tolua_S,1,0);
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

/* method: start of class  wyCameraAction */
#ifndef TOLUA_DISABLE_tolua_actions_wyCameraAction_start00
static int tolua_actions_wyCameraAction_start00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyCameraAction",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyCameraAction* self = (wyCameraAction*)  tolua_tousertype(tolua_S,1,0);
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

/* method: make of class  wyDelayTime */
#ifndef TOLUA_DISABLE_tolua_actions_wyDelayTime_make00
static int tolua_actions_wyDelayTime_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyDelayTime",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  {
   wyDelayTime* tolua_ret = (wyDelayTime*)  wyDelayTime::make(duration);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyDelayTime");
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

/* method: delete of class  wyDelayTime */
#ifndef TOLUA_DISABLE_tolua_actions_wyDelayTime_delete00
static int tolua_actions_wyDelayTime_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyDelayTime",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyDelayTime* self = (wyDelayTime*)  tolua_tousertype(tolua_S,1,0);
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

/* method: copy of class  wyDelayTime */
#ifndef TOLUA_DISABLE_tolua_actions_wyDelayTime_copy00
static int tolua_actions_wyDelayTime_copy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyDelayTime",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyDelayTime* self = (wyDelayTime*)  tolua_tousertype(tolua_S,1,0);
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

/* method: reverse of class  wyDelayTime */
#ifndef TOLUA_DISABLE_tolua_actions_wyDelayTime_reverse00
static int tolua_actions_wyDelayTime_reverse00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyDelayTime",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyDelayTime* self = (wyDelayTime*)  tolua_tousertype(tolua_S,1,0);
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

/* method: make of class  wyFadeIn */
#ifndef TOLUA_DISABLE_tolua_actions_wyFadeIn_make00
static int tolua_actions_wyFadeIn_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyFadeIn",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,3,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  bool includeChildren = ((bool)  tolua_toboolean(tolua_S,3,false));
  {
   wyFadeIn* tolua_ret = (wyFadeIn*)  wyFadeIn::make(duration,includeChildren);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyFadeIn");
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

/* method: delete of class  wyFadeIn */
#ifndef TOLUA_DISABLE_tolua_actions_wyFadeIn_delete00
static int tolua_actions_wyFadeIn_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyFadeIn",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyFadeIn* self = (wyFadeIn*)  tolua_tousertype(tolua_S,1,0);
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

/* method: copy of class  wyFadeIn */
#ifndef TOLUA_DISABLE_tolua_actions_wyFadeIn_copy00
static int tolua_actions_wyFadeIn_copy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyFadeIn",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyFadeIn* self = (wyFadeIn*)  tolua_tousertype(tolua_S,1,0);
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

/* method: reverse of class  wyFadeIn */
#ifndef TOLUA_DISABLE_tolua_actions_wyFadeIn_reverse00
static int tolua_actions_wyFadeIn_reverse00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyFadeIn",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyFadeIn* self = (wyFadeIn*)  tolua_tousertype(tolua_S,1,0);
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

/* method: update of class  wyFadeIn */
#ifndef TOLUA_DISABLE_tolua_actions_wyFadeIn_update00
static int tolua_actions_wyFadeIn_update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyFadeIn",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyFadeIn* self = (wyFadeIn*)  tolua_tousertype(tolua_S,1,0);
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

/* method: make of class  wyFadeOut */
#ifndef TOLUA_DISABLE_tolua_actions_wyFadeOut_make00
static int tolua_actions_wyFadeOut_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyFadeOut",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,3,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  bool includeChildren = ((bool)  tolua_toboolean(tolua_S,3,false));
  {
   wyFadeOut* tolua_ret = (wyFadeOut*)  wyFadeOut::make(duration,includeChildren);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyFadeOut");
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

/* method: delete of class  wyFadeOut */
#ifndef TOLUA_DISABLE_tolua_actions_wyFadeOut_delete00
static int tolua_actions_wyFadeOut_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyFadeOut",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyFadeOut* self = (wyFadeOut*)  tolua_tousertype(tolua_S,1,0);
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

/* method: copy of class  wyFadeOut */
#ifndef TOLUA_DISABLE_tolua_actions_wyFadeOut_copy00
static int tolua_actions_wyFadeOut_copy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyFadeOut",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyFadeOut* self = (wyFadeOut*)  tolua_tousertype(tolua_S,1,0);
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

/* method: reverse of class  wyFadeOut */
#ifndef TOLUA_DISABLE_tolua_actions_wyFadeOut_reverse00
static int tolua_actions_wyFadeOut_reverse00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyFadeOut",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyFadeOut* self = (wyFadeOut*)  tolua_tousertype(tolua_S,1,0);
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

/* method: update of class  wyFadeOut */
#ifndef TOLUA_DISABLE_tolua_actions_wyFadeOut_update00
static int tolua_actions_wyFadeOut_update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyFadeOut",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyFadeOut* self = (wyFadeOut*)  tolua_tousertype(tolua_S,1,0);
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

/* method: make of class  wyFadeTo */
#ifndef TOLUA_DISABLE_tolua_actions_wyFadeTo_make00
static int tolua_actions_wyFadeTo_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyFadeTo",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,5,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  int fromAlpha = ((int)  tolua_tonumber(tolua_S,3,0));
  int toAlpha = ((int)  tolua_tonumber(tolua_S,4,0));
  bool includeChildren = ((bool)  tolua_toboolean(tolua_S,5,false));
  {
   wyFadeTo* tolua_ret = (wyFadeTo*)  wyFadeTo::make(duration,fromAlpha,toAlpha,includeChildren);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyFadeTo");
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

/* method: delete of class  wyFadeTo */
#ifndef TOLUA_DISABLE_tolua_actions_wyFadeTo_delete00
static int tolua_actions_wyFadeTo_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyFadeTo",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyFadeTo* self = (wyFadeTo*)  tolua_tousertype(tolua_S,1,0);
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

/* method: copy of class  wyFadeTo */
#ifndef TOLUA_DISABLE_tolua_actions_wyFadeTo_copy00
static int tolua_actions_wyFadeTo_copy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyFadeTo",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyFadeTo* self = (wyFadeTo*)  tolua_tousertype(tolua_S,1,0);
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

/* method: reverse of class  wyFadeTo */
#ifndef TOLUA_DISABLE_tolua_actions_wyFadeTo_reverse00
static int tolua_actions_wyFadeTo_reverse00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyFadeTo",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyFadeTo* self = (wyFadeTo*)  tolua_tousertype(tolua_S,1,0);
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

/* method: update of class  wyFadeTo */
#ifndef TOLUA_DISABLE_tolua_actions_wyFadeTo_update00
static int tolua_actions_wyFadeTo_update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyFadeTo",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyFadeTo* self = (wyFadeTo*)  tolua_tousertype(tolua_S,1,0);
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

/* method: start of class  wyFiniteTimeAction */
#ifndef TOLUA_DISABLE_tolua_actions_wyFiniteTimeAction_start00
static int tolua_actions_wyFiniteTimeAction_start00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyFiniteTimeAction",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyFiniteTimeAction* self = (wyFiniteTimeAction*)  tolua_tousertype(tolua_S,1,0);
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

/* method: getDuration of class  wyFiniteTimeAction */
#ifndef TOLUA_DISABLE_tolua_actions_wyFiniteTimeAction_getDuration00
static int tolua_actions_wyFiniteTimeAction_getDuration00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyFiniteTimeAction",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyFiniteTimeAction* self = (wyFiniteTimeAction*)  tolua_tousertype(tolua_S,1,0);
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

/* method: setDuration of class  wyFiniteTimeAction */
#ifndef TOLUA_DISABLE_tolua_actions_wyFiniteTimeAction_setDuration00
static int tolua_actions_wyFiniteTimeAction_setDuration00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyFiniteTimeAction",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyFiniteTimeAction* self = (wyFiniteTimeAction*)  tolua_tousertype(tolua_S,1,0);
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setDuration'", NULL);
#endif
  {
   self->setDuration(duration);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setDuration'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getElapsed of class  wyFiniteTimeAction */
#ifndef TOLUA_DISABLE_tolua_actions_wyFiniteTimeAction_getElapsed00
static int tolua_actions_wyFiniteTimeAction_getElapsed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyFiniteTimeAction",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyFiniteTimeAction* self = (wyFiniteTimeAction*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getElapsed'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getElapsed();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getElapsed'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setElapsed of class  wyFiniteTimeAction */
#ifndef TOLUA_DISABLE_tolua_actions_wyFiniteTimeAction_setElapsed00
static int tolua_actions_wyFiniteTimeAction_setElapsed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyFiniteTimeAction",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyFiniteTimeAction* self = (wyFiniteTimeAction*)  tolua_tousertype(tolua_S,1,0);
  float e = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setElapsed'", NULL);
#endif
  {
   self->setElapsed(e);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setElapsed'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: make of class  wyHide */
#ifndef TOLUA_DISABLE_tolua_actions_wyHide_make00
static int tolua_actions_wyHide_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyHide",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   wyHide* tolua_ret = (wyHide*)  wyHide::make();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyHide");
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

/* method: delete of class  wyHide */
#ifndef TOLUA_DISABLE_tolua_actions_wyHide_delete00
static int tolua_actions_wyHide_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyHide",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyHide* self = (wyHide*)  tolua_tousertype(tolua_S,1,0);
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

/* method: copy of class  wyHide */
#ifndef TOLUA_DISABLE_tolua_actions_wyHide_copy00
static int tolua_actions_wyHide_copy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyHide",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyHide* self = (wyHide*)  tolua_tousertype(tolua_S,1,0);
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

/* method: reverse of class  wyHide */
#ifndef TOLUA_DISABLE_tolua_actions_wyHide_reverse00
static int tolua_actions_wyHide_reverse00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyHide",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyHide* self = (wyHide*)  tolua_tousertype(tolua_S,1,0);
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

/* method: start of class  wyHide */
#ifndef TOLUA_DISABLE_tolua_actions_wyHide_start00
static int tolua_actions_wyHide_start00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyHide",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyHide* self = (wyHide*)  tolua_tousertype(tolua_S,1,0);
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

/* method: start of class  wyIntervalAction */
#ifndef TOLUA_DISABLE_tolua_actions_wyIntervalAction_start00
static int tolua_actions_wyIntervalAction_start00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyIntervalAction",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyIntervalAction* self = (wyIntervalAction*)  tolua_tousertype(tolua_S,1,0);
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

/* method: step of class  wyIntervalAction */
#ifndef TOLUA_DISABLE_tolua_actions_wyIntervalAction_step00
static int tolua_actions_wyIntervalAction_step00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyIntervalAction",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyIntervalAction* self = (wyIntervalAction*)  tolua_tousertype(tolua_S,1,0);
  float t = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'step'", NULL);
#endif
  {
   self->step(t);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'step'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isDone of class  wyIntervalAction */
#ifndef TOLUA_DISABLE_tolua_actions_wyIntervalAction_isDone00
static int tolua_actions_wyIntervalAction_isDone00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyIntervalAction",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyIntervalAction* self = (wyIntervalAction*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isDone'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isDone();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isDone'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: make of class  wyJumpBy */
#ifndef TOLUA_DISABLE_tolua_actions_wyJumpBy_make00
static int tolua_actions_wyJumpBy_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyJumpBy",0,&tolua_err) ||
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
  float x = ((float)  tolua_tonumber(tolua_S,3,0));
  float y = ((float)  tolua_tonumber(tolua_S,4,0));
  float height = ((float)  tolua_tonumber(tolua_S,5,0));
  int jumps = ((int)  tolua_tonumber(tolua_S,6,0));
  {
   wyJumpBy* tolua_ret = (wyJumpBy*)  wyJumpBy::make(duration,x,y,height,jumps);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyJumpBy");
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

/* method: delete of class  wyJumpBy */
#ifndef TOLUA_DISABLE_tolua_actions_wyJumpBy_delete00
static int tolua_actions_wyJumpBy_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyJumpBy",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyJumpBy* self = (wyJumpBy*)  tolua_tousertype(tolua_S,1,0);
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

/* method: copy of class  wyJumpBy */
#ifndef TOLUA_DISABLE_tolua_actions_wyJumpBy_copy00
static int tolua_actions_wyJumpBy_copy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyJumpBy",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyJumpBy* self = (wyJumpBy*)  tolua_tousertype(tolua_S,1,0);
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

/* method: reverse of class  wyJumpBy */
#ifndef TOLUA_DISABLE_tolua_actions_wyJumpBy_reverse00
static int tolua_actions_wyJumpBy_reverse00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyJumpBy",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyJumpBy* self = (wyJumpBy*)  tolua_tousertype(tolua_S,1,0);
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

/* method: start of class  wyJumpBy */
#ifndef TOLUA_DISABLE_tolua_actions_wyJumpBy_start00
static int tolua_actions_wyJumpBy_start00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyJumpBy",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyJumpBy* self = (wyJumpBy*)  tolua_tousertype(tolua_S,1,0);
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

/* method: update of class  wyJumpBy */
#ifndef TOLUA_DISABLE_tolua_actions_wyJumpBy_update00
static int tolua_actions_wyJumpBy_update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyJumpBy",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyJumpBy* self = (wyJumpBy*)  tolua_tousertype(tolua_S,1,0);
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

/* method: make of class  wyJumpTo */
#ifndef TOLUA_DISABLE_tolua_actions_wyJumpTo_make00
static int tolua_actions_wyJumpTo_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyJumpTo",0,&tolua_err) ||
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
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  float startX = ((float)  tolua_tonumber(tolua_S,3,0));
  float startY = ((float)  tolua_tonumber(tolua_S,4,0));
  float endX = ((float)  tolua_tonumber(tolua_S,5,0));
  float endY = ((float)  tolua_tonumber(tolua_S,6,0));
  float height = ((float)  tolua_tonumber(tolua_S,7,0));
  int jumps = ((int)  tolua_tonumber(tolua_S,8,0));
  {
   wyJumpTo* tolua_ret = (wyJumpTo*)  wyJumpTo::make(duration,startX,startY,endX,endY,height,jumps);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyJumpTo");
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

/* method: delete of class  wyJumpTo */
#ifndef TOLUA_DISABLE_tolua_actions_wyJumpTo_delete00
static int tolua_actions_wyJumpTo_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyJumpTo",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyJumpTo* self = (wyJumpTo*)  tolua_tousertype(tolua_S,1,0);
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

/* method: copy of class  wyJumpTo */
#ifndef TOLUA_DISABLE_tolua_actions_wyJumpTo_copy00
static int tolua_actions_wyJumpTo_copy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyJumpTo",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyJumpTo* self = (wyJumpTo*)  tolua_tousertype(tolua_S,1,0);
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

/* method: reverse of class  wyJumpTo */
#ifndef TOLUA_DISABLE_tolua_actions_wyJumpTo_reverse00
static int tolua_actions_wyJumpTo_reverse00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyJumpTo",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyJumpTo* self = (wyJumpTo*)  tolua_tousertype(tolua_S,1,0);
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

/* method: update of class  wyJumpTo */
#ifndef TOLUA_DISABLE_tolua_actions_wyJumpTo_update00
static int tolua_actions_wyJumpTo_update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyJumpTo",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyJumpTo* self = (wyJumpTo*)  tolua_tousertype(tolua_S,1,0);
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

/* method: make of class  wyMoveBy */
#ifndef TOLUA_DISABLE_tolua_actions_wyMoveBy_make00
static int tolua_actions_wyMoveBy_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyMoveBy",0,&tolua_err) ||
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
  float x = ((float)  tolua_tonumber(tolua_S,3,0));
  float y = ((float)  tolua_tonumber(tolua_S,4,0));
  {
   wyMoveBy* tolua_ret = (wyMoveBy*)  wyMoveBy::make(duration,x,y);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyMoveBy");
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

/* method: delete of class  wyMoveBy */
#ifndef TOLUA_DISABLE_tolua_actions_wyMoveBy_delete00
static int tolua_actions_wyMoveBy_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyMoveBy",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyMoveBy* self = (wyMoveBy*)  tolua_tousertype(tolua_S,1,0);
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

/* method: copy of class  wyMoveBy */
#ifndef TOLUA_DISABLE_tolua_actions_wyMoveBy_copy00
static int tolua_actions_wyMoveBy_copy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyMoveBy",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyMoveBy* self = (wyMoveBy*)  tolua_tousertype(tolua_S,1,0);
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

/* method: reverse of class  wyMoveBy */
#ifndef TOLUA_DISABLE_tolua_actions_wyMoveBy_reverse00
static int tolua_actions_wyMoveBy_reverse00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyMoveBy",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyMoveBy* self = (wyMoveBy*)  tolua_tousertype(tolua_S,1,0);
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

/* method: start of class  wyMoveBy */
#ifndef TOLUA_DISABLE_tolua_actions_wyMoveBy_start00
static int tolua_actions_wyMoveBy_start00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyMoveBy",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyMoveBy* self = (wyMoveBy*)  tolua_tousertype(tolua_S,1,0);
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

/* method: update of class  wyMoveBy */
#ifndef TOLUA_DISABLE_tolua_actions_wyMoveBy_update00
static int tolua_actions_wyMoveBy_update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyMoveBy",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyMoveBy* self = (wyMoveBy*)  tolua_tousertype(tolua_S,1,0);
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

/* method: setPinPoint of class  wyMoveBy */
#ifndef TOLUA_DISABLE_tolua_actions_wyMoveBy_setPinPoint00
static int tolua_actions_wyMoveBy_setPinPoint00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyMoveBy",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"wyPoint",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyMoveBy* self = (wyMoveBy*)  tolua_tousertype(tolua_S,1,0);
  wyPoint p = *((wyPoint*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setPinPoint'", NULL);
#endif
  {
   self->setPinPoint(p);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setPinPoint'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setPinPoint of class  wyMoveBy */
#ifndef TOLUA_DISABLE_tolua_actions_wyMoveBy_setPinPoint01
static int tolua_actions_wyMoveBy_setPinPoint01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyMoveBy",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  wyMoveBy* self = (wyMoveBy*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setPinPoint'", NULL);
#endif
  {
   self->setPinPoint(x,y);
  }
 }
 return 0;
tolua_lerror:
 return tolua_actions_wyMoveBy_setPinPoint00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: getPinPoint of class  wyMoveBy */
#ifndef TOLUA_DISABLE_tolua_actions_wyMoveBy_getPinPoint00
static int tolua_actions_wyMoveBy_getPinPoint00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyMoveBy",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyMoveBy* self = (wyMoveBy*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getPinPoint'", NULL);
#endif
  {
   wyPoint tolua_ret = (wyPoint)  self->getPinPoint();
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
 tolua_error(tolua_S,"#ferror in function 'getPinPoint'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: clearPinPoint of class  wyMoveBy */
#ifndef TOLUA_DISABLE_tolua_actions_wyMoveBy_clearPinPoint00
static int tolua_actions_wyMoveBy_clearPinPoint00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyMoveBy",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyMoveBy* self = (wyMoveBy*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'clearPinPoint'", NULL);
#endif
  {
   self->clearPinPoint();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'clearPinPoint'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setPinAngleDelta of class  wyMoveBy */
#ifndef TOLUA_DISABLE_tolua_actions_wyMoveBy_setPinAngleDelta00
static int tolua_actions_wyMoveBy_setPinAngleDelta00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyMoveBy",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyMoveBy* self = (wyMoveBy*)  tolua_tousertype(tolua_S,1,0);
  float delta = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setPinAngleDelta'", NULL);
#endif
  {
   self->setPinAngleDelta(delta);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setPinAngleDelta'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getPinAngleDelta of class  wyMoveBy */
#ifndef TOLUA_DISABLE_tolua_actions_wyMoveBy_getPinAngleDelta00
static int tolua_actions_wyMoveBy_getPinAngleDelta00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyMoveBy",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyMoveBy* self = (wyMoveBy*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getPinAngleDelta'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getPinAngleDelta();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getPinAngleDelta'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: make of class  wyMoveByAngle */
#ifndef TOLUA_DISABLE_tolua_actions_wyMoveByAngle_make00
static int tolua_actions_wyMoveByAngle_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyMoveByAngle",0,&tolua_err) ||
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
  int degree = ((int)  tolua_tonumber(tolua_S,3,0));
  int velocity = ((int)  tolua_tonumber(tolua_S,4,0));
  {
   wyMoveByAngle* tolua_ret = (wyMoveByAngle*)  wyMoveByAngle::make(duration,degree,velocity);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyMoveByAngle");
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

/* method: delete of class  wyMoveByAngle */
#ifndef TOLUA_DISABLE_tolua_actions_wyMoveByAngle_delete00
static int tolua_actions_wyMoveByAngle_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyMoveByAngle",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyMoveByAngle* self = (wyMoveByAngle*)  tolua_tousertype(tolua_S,1,0);
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

/* method: copy of class  wyMoveByAngle */
#ifndef TOLUA_DISABLE_tolua_actions_wyMoveByAngle_copy00
static int tolua_actions_wyMoveByAngle_copy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyMoveByAngle",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyMoveByAngle* self = (wyMoveByAngle*)  tolua_tousertype(tolua_S,1,0);
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

/* method: reverse of class  wyMoveByAngle */
#ifndef TOLUA_DISABLE_tolua_actions_wyMoveByAngle_reverse00
static int tolua_actions_wyMoveByAngle_reverse00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyMoveByAngle",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyMoveByAngle* self = (wyMoveByAngle*)  tolua_tousertype(tolua_S,1,0);
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

/* method: start of class  wyMoveByAngle */
#ifndef TOLUA_DISABLE_tolua_actions_wyMoveByAngle_start00
static int tolua_actions_wyMoveByAngle_start00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyMoveByAngle",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyMoveByAngle* self = (wyMoveByAngle*)  tolua_tousertype(tolua_S,1,0);
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

/* method: update of class  wyMoveByAngle */
#ifndef TOLUA_DISABLE_tolua_actions_wyMoveByAngle_update00
static int tolua_actions_wyMoveByAngle_update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyMoveByAngle",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyMoveByAngle* self = (wyMoveByAngle*)  tolua_tousertype(tolua_S,1,0);
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

/* method: setPinPoint of class  wyMoveByAngle */
#ifndef TOLUA_DISABLE_tolua_actions_wyMoveByAngle_setPinPoint00
static int tolua_actions_wyMoveByAngle_setPinPoint00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyMoveByAngle",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"wyPoint",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyMoveByAngle* self = (wyMoveByAngle*)  tolua_tousertype(tolua_S,1,0);
  wyPoint p = *((wyPoint*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setPinPoint'", NULL);
#endif
  {
   self->setPinPoint(p);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setPinPoint'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setPinPoint of class  wyMoveByAngle */
#ifndef TOLUA_DISABLE_tolua_actions_wyMoveByAngle_setPinPoint01
static int tolua_actions_wyMoveByAngle_setPinPoint01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyMoveByAngle",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  wyMoveByAngle* self = (wyMoveByAngle*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setPinPoint'", NULL);
#endif
  {
   self->setPinPoint(x,y);
  }
 }
 return 0;
tolua_lerror:
 return tolua_actions_wyMoveByAngle_setPinPoint00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: getPinPoint of class  wyMoveByAngle */
#ifndef TOLUA_DISABLE_tolua_actions_wyMoveByAngle_getPinPoint00
static int tolua_actions_wyMoveByAngle_getPinPoint00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyMoveByAngle",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyMoveByAngle* self = (wyMoveByAngle*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getPinPoint'", NULL);
#endif
  {
   wyPoint tolua_ret = (wyPoint)  self->getPinPoint();
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
 tolua_error(tolua_S,"#ferror in function 'getPinPoint'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: clearPinPoint of class  wyMoveByAngle */
#ifndef TOLUA_DISABLE_tolua_actions_wyMoveByAngle_clearPinPoint00
static int tolua_actions_wyMoveByAngle_clearPinPoint00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyMoveByAngle",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyMoveByAngle* self = (wyMoveByAngle*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'clearPinPoint'", NULL);
#endif
  {
   self->clearPinPoint();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'clearPinPoint'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setPinAngleDelta of class  wyMoveByAngle */
#ifndef TOLUA_DISABLE_tolua_actions_wyMoveByAngle_setPinAngleDelta00
static int tolua_actions_wyMoveByAngle_setPinAngleDelta00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyMoveByAngle",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyMoveByAngle* self = (wyMoveByAngle*)  tolua_tousertype(tolua_S,1,0);
  float delta = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setPinAngleDelta'", NULL);
#endif
  {
   self->setPinAngleDelta(delta);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setPinAngleDelta'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getPinAngleDelta of class  wyMoveByAngle */
#ifndef TOLUA_DISABLE_tolua_actions_wyMoveByAngle_getPinAngleDelta00
static int tolua_actions_wyMoveByAngle_getPinAngleDelta00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyMoveByAngle",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyMoveByAngle* self = (wyMoveByAngle*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getPinAngleDelta'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getPinAngleDelta();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getPinAngleDelta'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: make of class  wyMoveTo */
#ifndef TOLUA_DISABLE_tolua_actions_wyMoveTo_make00
static int tolua_actions_wyMoveTo_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyMoveTo",0,&tolua_err) ||
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
  float startX = ((float)  tolua_tonumber(tolua_S,3,0));
  float startY = ((float)  tolua_tonumber(tolua_S,4,0));
  float endX = ((float)  tolua_tonumber(tolua_S,5,0));
  float endY = ((float)  tolua_tonumber(tolua_S,6,0));
  {
   wyMoveTo* tolua_ret = (wyMoveTo*)  wyMoveTo::make(duration,startX,startY,endX,endY);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyMoveTo");
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

/* method: delete of class  wyMoveTo */
#ifndef TOLUA_DISABLE_tolua_actions_wyMoveTo_delete00
static int tolua_actions_wyMoveTo_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyMoveTo",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyMoveTo* self = (wyMoveTo*)  tolua_tousertype(tolua_S,1,0);
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

/* method: copy of class  wyMoveTo */
#ifndef TOLUA_DISABLE_tolua_actions_wyMoveTo_copy00
static int tolua_actions_wyMoveTo_copy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyMoveTo",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyMoveTo* self = (wyMoveTo*)  tolua_tousertype(tolua_S,1,0);
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

/* method: reverse of class  wyMoveTo */
#ifndef TOLUA_DISABLE_tolua_actions_wyMoveTo_reverse00
static int tolua_actions_wyMoveTo_reverse00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyMoveTo",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyMoveTo* self = (wyMoveTo*)  tolua_tousertype(tolua_S,1,0);
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

/* method: update of class  wyMoveTo */
#ifndef TOLUA_DISABLE_tolua_actions_wyMoveTo_update00
static int tolua_actions_wyMoveTo_update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyMoveTo",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyMoveTo* self = (wyMoveTo*)  tolua_tousertype(tolua_S,1,0);
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

/* method: setPinPoint of class  wyMoveTo */
#ifndef TOLUA_DISABLE_tolua_actions_wyMoveTo_setPinPoint00
static int tolua_actions_wyMoveTo_setPinPoint00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyMoveTo",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"wyPoint",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyMoveTo* self = (wyMoveTo*)  tolua_tousertype(tolua_S,1,0);
  wyPoint p = *((wyPoint*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setPinPoint'", NULL);
#endif
  {
   self->setPinPoint(p);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setPinPoint'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setPinPoint of class  wyMoveTo */
#ifndef TOLUA_DISABLE_tolua_actions_wyMoveTo_setPinPoint01
static int tolua_actions_wyMoveTo_setPinPoint01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyMoveTo",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  wyMoveTo* self = (wyMoveTo*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setPinPoint'", NULL);
#endif
  {
   self->setPinPoint(x,y);
  }
 }
 return 0;
tolua_lerror:
 return tolua_actions_wyMoveTo_setPinPoint00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: getPinPoint of class  wyMoveTo */
#ifndef TOLUA_DISABLE_tolua_actions_wyMoveTo_getPinPoint00
static int tolua_actions_wyMoveTo_getPinPoint00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyMoveTo",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyMoveTo* self = (wyMoveTo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getPinPoint'", NULL);
#endif
  {
   wyPoint tolua_ret = (wyPoint)  self->getPinPoint();
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
 tolua_error(tolua_S,"#ferror in function 'getPinPoint'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: clearPinPoint of class  wyMoveTo */
#ifndef TOLUA_DISABLE_tolua_actions_wyMoveTo_clearPinPoint00
static int tolua_actions_wyMoveTo_clearPinPoint00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyMoveTo",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyMoveTo* self = (wyMoveTo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'clearPinPoint'", NULL);
#endif
  {
   self->clearPinPoint();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'clearPinPoint'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setPinAngleDelta of class  wyMoveTo */
#ifndef TOLUA_DISABLE_tolua_actions_wyMoveTo_setPinAngleDelta00
static int tolua_actions_wyMoveTo_setPinAngleDelta00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyMoveTo",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyMoveTo* self = (wyMoveTo*)  tolua_tousertype(tolua_S,1,0);
  float delta = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setPinAngleDelta'", NULL);
#endif
  {
   self->setPinAngleDelta(delta);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setPinAngleDelta'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getPinAngleDelta of class  wyMoveTo */
#ifndef TOLUA_DISABLE_tolua_actions_wyMoveTo_getPinAngleDelta00
static int tolua_actions_wyMoveTo_getPinAngleDelta00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyMoveTo",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyMoveTo* self = (wyMoveTo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getPinAngleDelta'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getPinAngleDelta();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getPinAngleDelta'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: make of class  wyOrbitCamera */
#ifndef TOLUA_DISABLE_tolua_actions_wyOrbitCamera_make00
static int tolua_actions_wyOrbitCamera_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyOrbitCamera",0,&tolua_err) ||
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
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  float r = ((float)  tolua_tonumber(tolua_S,3,0));
  float dr = ((float)  tolua_tonumber(tolua_S,4,0));
  float z = ((float)  tolua_tonumber(tolua_S,5,0));
  float dz = ((float)  tolua_tonumber(tolua_S,6,0));
  float x = ((float)  tolua_tonumber(tolua_S,7,0));
  float dx = ((float)  tolua_tonumber(tolua_S,8,0));
  {
   wyOrbitCamera* tolua_ret = (wyOrbitCamera*)  wyOrbitCamera::make(duration,r,dr,z,dz,x,dx);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyOrbitCamera");
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

/* method: delete of class  wyOrbitCamera */
#ifndef TOLUA_DISABLE_tolua_actions_wyOrbitCamera_delete00
static int tolua_actions_wyOrbitCamera_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyOrbitCamera",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyOrbitCamera* self = (wyOrbitCamera*)  tolua_tousertype(tolua_S,1,0);
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

/* method: copy of class  wyOrbitCamera */
#ifndef TOLUA_DISABLE_tolua_actions_wyOrbitCamera_copy00
static int tolua_actions_wyOrbitCamera_copy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyOrbitCamera",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyOrbitCamera* self = (wyOrbitCamera*)  tolua_tousertype(tolua_S,1,0);
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

/* method: start of class  wyOrbitCamera */
#ifndef TOLUA_DISABLE_tolua_actions_wyOrbitCamera_start00
static int tolua_actions_wyOrbitCamera_start00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyOrbitCamera",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyOrbitCamera* self = (wyOrbitCamera*)  tolua_tousertype(tolua_S,1,0);
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

/* method: update of class  wyOrbitCamera */
#ifndef TOLUA_DISABLE_tolua_actions_wyOrbitCamera_update00
static int tolua_actions_wyOrbitCamera_update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyOrbitCamera",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyOrbitCamera* self = (wyOrbitCamera*)  tolua_tousertype(tolua_S,1,0);
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

/* method: make of class  wyPlace */
#ifndef TOLUA_DISABLE_tolua_actions_wyPlace_make00
static int tolua_actions_wyPlace_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyPlace",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
  {
   wyPlace* tolua_ret = (wyPlace*)  wyPlace::make(x,y);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyPlace");
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

/* method: delete of class  wyPlace */
#ifndef TOLUA_DISABLE_tolua_actions_wyPlace_delete00
static int tolua_actions_wyPlace_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyPlace",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyPlace* self = (wyPlace*)  tolua_tousertype(tolua_S,1,0);
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

/* method: copy of class  wyPlace */
#ifndef TOLUA_DISABLE_tolua_actions_wyPlace_copy00
static int tolua_actions_wyPlace_copy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyPlace",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyPlace* self = (wyPlace*)  tolua_tousertype(tolua_S,1,0);
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

/* method: reverse of class  wyPlace */
#ifndef TOLUA_DISABLE_tolua_actions_wyPlace_reverse00
static int tolua_actions_wyPlace_reverse00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyPlace",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyPlace* self = (wyPlace*)  tolua_tousertype(tolua_S,1,0);
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

/* method: start of class  wyPlace */
#ifndef TOLUA_DISABLE_tolua_actions_wyPlace_start00
static int tolua_actions_wyPlace_start00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyPlace",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyPlace* self = (wyPlace*)  tolua_tousertype(tolua_S,1,0);
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

/* method: make of class  wyProgressBy */
#ifndef TOLUA_DISABLE_tolua_actions_wyProgressBy_make00
static int tolua_actions_wyProgressBy_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyProgressBy",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  float deltaPercents = ((float)  tolua_tonumber(tolua_S,3,0));
  {
   wyProgressBy* tolua_ret = (wyProgressBy*)  wyProgressBy::make(duration,deltaPercents);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyProgressBy");
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

/* method: delete of class  wyProgressBy */
#ifndef TOLUA_DISABLE_tolua_actions_wyProgressBy_delete00
static int tolua_actions_wyProgressBy_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyProgressBy",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyProgressBy* self = (wyProgressBy*)  tolua_tousertype(tolua_S,1,0);
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

/* method: copy of class  wyProgressBy */
#ifndef TOLUA_DISABLE_tolua_actions_wyProgressBy_copy00
static int tolua_actions_wyProgressBy_copy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyProgressBy",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyProgressBy* self = (wyProgressBy*)  tolua_tousertype(tolua_S,1,0);
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

/* method: reverse of class  wyProgressBy */
#ifndef TOLUA_DISABLE_tolua_actions_wyProgressBy_reverse00
static int tolua_actions_wyProgressBy_reverse00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyProgressBy",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyProgressBy* self = (wyProgressBy*)  tolua_tousertype(tolua_S,1,0);
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

/* method: start of class  wyProgressBy */
#ifndef TOLUA_DISABLE_tolua_actions_wyProgressBy_start00
static int tolua_actions_wyProgressBy_start00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyProgressBy",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyProgressBy* self = (wyProgressBy*)  tolua_tousertype(tolua_S,1,0);
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

/* method: update of class  wyProgressBy */
#ifndef TOLUA_DISABLE_tolua_actions_wyProgressBy_update00
static int tolua_actions_wyProgressBy_update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyProgressBy",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyProgressBy* self = (wyProgressBy*)  tolua_tousertype(tolua_S,1,0);
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

/* method: make of class  wyProgressTo */
#ifndef TOLUA_DISABLE_tolua_actions_wyProgressTo_make00
static int tolua_actions_wyProgressTo_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyProgressTo",0,&tolua_err) ||
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
  float from = ((float)  tolua_tonumber(tolua_S,3,0));
  float to = ((float)  tolua_tonumber(tolua_S,4,0));
  {
   wyProgressTo* tolua_ret = (wyProgressTo*)  wyProgressTo::make(duration,from,to);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyProgressTo");
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

/* method: delete of class  wyProgressTo */
#ifndef TOLUA_DISABLE_tolua_actions_wyProgressTo_delete00
static int tolua_actions_wyProgressTo_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyProgressTo",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyProgressTo* self = (wyProgressTo*)  tolua_tousertype(tolua_S,1,0);
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

/* method: copy of class  wyProgressTo */
#ifndef TOLUA_DISABLE_tolua_actions_wyProgressTo_copy00
static int tolua_actions_wyProgressTo_copy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyProgressTo",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyProgressTo* self = (wyProgressTo*)  tolua_tousertype(tolua_S,1,0);
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

/* method: reverse of class  wyProgressTo */
#ifndef TOLUA_DISABLE_tolua_actions_wyProgressTo_reverse00
static int tolua_actions_wyProgressTo_reverse00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyProgressTo",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyProgressTo* self = (wyProgressTo*)  tolua_tousertype(tolua_S,1,0);
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

/* method: update of class  wyProgressTo */
#ifndef TOLUA_DISABLE_tolua_actions_wyProgressTo_update00
static int tolua_actions_wyProgressTo_update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyProgressTo",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyProgressTo* self = (wyProgressTo*)  tolua_tousertype(tolua_S,1,0);
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

/* method: make of class  wyRepeat */
#ifndef TOLUA_DISABLE_tolua_actions_wyRepeat_make00
static int tolua_actions_wyRepeat_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyRepeat",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyFiniteTimeAction",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyFiniteTimeAction* other = ((wyFiniteTimeAction*)  tolua_tousertype(tolua_S,2,0));
  int times = ((int)  tolua_tonumber(tolua_S,3,0));
  {
   wyRepeat* tolua_ret = (wyRepeat*)  wyRepeat::make(other,times);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyRepeat");
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

/* method: delete of class  wyRepeat */
#ifndef TOLUA_DISABLE_tolua_actions_wyRepeat_delete00
static int tolua_actions_wyRepeat_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyRepeat",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyRepeat* self = (wyRepeat*)  tolua_tousertype(tolua_S,1,0);
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

/* method: copy of class  wyRepeat */
#ifndef TOLUA_DISABLE_tolua_actions_wyRepeat_copy00
static int tolua_actions_wyRepeat_copy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyRepeat",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyRepeat* self = (wyRepeat*)  tolua_tousertype(tolua_S,1,0);
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

/* method: reverse of class  wyRepeat */
#ifndef TOLUA_DISABLE_tolua_actions_wyRepeat_reverse00
static int tolua_actions_wyRepeat_reverse00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyRepeat",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyRepeat* self = (wyRepeat*)  tolua_tousertype(tolua_S,1,0);
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

/* method: start of class  wyRepeat */
#ifndef TOLUA_DISABLE_tolua_actions_wyRepeat_start00
static int tolua_actions_wyRepeat_start00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyRepeat",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyRepeat* self = (wyRepeat*)  tolua_tousertype(tolua_S,1,0);
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

/* method: stop of class  wyRepeat */
#ifndef TOLUA_DISABLE_tolua_actions_wyRepeat_stop00
static int tolua_actions_wyRepeat_stop00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyRepeat",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyRepeat* self = (wyRepeat*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'stop'", NULL);
#endif
  {
   self->stop();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'stop'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: update of class  wyRepeat */
#ifndef TOLUA_DISABLE_tolua_actions_wyRepeat_update00
static int tolua_actions_wyRepeat_update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyRepeat",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyRepeat* self = (wyRepeat*)  tolua_tousertype(tolua_S,1,0);
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

/* method: isDone of class  wyRepeat */
#ifndef TOLUA_DISABLE_tolua_actions_wyRepeat_isDone00
static int tolua_actions_wyRepeat_isDone00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyRepeat",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyRepeat* self = (wyRepeat*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isDone'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isDone();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isDone'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: make of class  wyRepeatForever */
#ifndef TOLUA_DISABLE_tolua_actions_wyRepeatForever_make00
static int tolua_actions_wyRepeatForever_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyRepeatForever",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyIntervalAction",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyIntervalAction* other = ((wyIntervalAction*)  tolua_tousertype(tolua_S,2,0));
  {
   wyRepeatForever* tolua_ret = (wyRepeatForever*)  wyRepeatForever::make(other);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyRepeatForever");
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

/* method: delete of class  wyRepeatForever */
#ifndef TOLUA_DISABLE_tolua_actions_wyRepeatForever_delete00
static int tolua_actions_wyRepeatForever_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyRepeatForever",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyRepeatForever* self = (wyRepeatForever*)  tolua_tousertype(tolua_S,1,0);
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

/* method: copy of class  wyRepeatForever */
#ifndef TOLUA_DISABLE_tolua_actions_wyRepeatForever_copy00
static int tolua_actions_wyRepeatForever_copy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyRepeatForever",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyRepeatForever* self = (wyRepeatForever*)  tolua_tousertype(tolua_S,1,0);
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

/* method: reverse of class  wyRepeatForever */
#ifndef TOLUA_DISABLE_tolua_actions_wyRepeatForever_reverse00
static int tolua_actions_wyRepeatForever_reverse00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyRepeatForever",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyRepeatForever* self = (wyRepeatForever*)  tolua_tousertype(tolua_S,1,0);
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

/* method: start of class  wyRepeatForever */
#ifndef TOLUA_DISABLE_tolua_actions_wyRepeatForever_start00
static int tolua_actions_wyRepeatForever_start00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyRepeatForever",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyRepeatForever* self = (wyRepeatForever*)  tolua_tousertype(tolua_S,1,0);
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

/* method: stop of class  wyRepeatForever */
#ifndef TOLUA_DISABLE_tolua_actions_wyRepeatForever_stop00
static int tolua_actions_wyRepeatForever_stop00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyRepeatForever",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyRepeatForever* self = (wyRepeatForever*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'stop'", NULL);
#endif
  {
   self->stop();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'stop'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: step of class  wyRepeatForever */
#ifndef TOLUA_DISABLE_tolua_actions_wyRepeatForever_step00
static int tolua_actions_wyRepeatForever_step00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyRepeatForever",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyRepeatForever* self = (wyRepeatForever*)  tolua_tousertype(tolua_S,1,0);
  float t = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'step'", NULL);
#endif
  {
   self->step(t);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'step'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: update of class  wyRepeatForever */
#ifndef TOLUA_DISABLE_tolua_actions_wyRepeatForever_update00
static int tolua_actions_wyRepeatForever_update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyRepeatForever",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyRepeatForever* self = (wyRepeatForever*)  tolua_tousertype(tolua_S,1,0);
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

/* method: isDone of class  wyRepeatForever */
#ifndef TOLUA_DISABLE_tolua_actions_wyRepeatForever_isDone00
static int tolua_actions_wyRepeatForever_isDone00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyRepeatForever",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyRepeatForever* self = (wyRepeatForever*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isDone'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isDone();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isDone'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: make of class  wyReverseTime */
#ifndef TOLUA_DISABLE_tolua_actions_wyReverseTime_make00
static int tolua_actions_wyReverseTime_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyReverseTime",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyFiniteTimeAction",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyFiniteTimeAction* other = ((wyFiniteTimeAction*)  tolua_tousertype(tolua_S,2,0));
  {
   wyReverseTime* tolua_ret = (wyReverseTime*)  wyReverseTime::make(other);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyReverseTime");
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

/* method: delete of class  wyReverseTime */
#ifndef TOLUA_DISABLE_tolua_actions_wyReverseTime_delete00
static int tolua_actions_wyReverseTime_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyReverseTime",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyReverseTime* self = (wyReverseTime*)  tolua_tousertype(tolua_S,1,0);
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

/* method: copy of class  wyReverseTime */
#ifndef TOLUA_DISABLE_tolua_actions_wyReverseTime_copy00
static int tolua_actions_wyReverseTime_copy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyReverseTime",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyReverseTime* self = (wyReverseTime*)  tolua_tousertype(tolua_S,1,0);
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

/* method: reverse of class  wyReverseTime */
#ifndef TOLUA_DISABLE_tolua_actions_wyReverseTime_reverse00
static int tolua_actions_wyReverseTime_reverse00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyReverseTime",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyReverseTime* self = (wyReverseTime*)  tolua_tousertype(tolua_S,1,0);
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

/* method: start of class  wyReverseTime */
#ifndef TOLUA_DISABLE_tolua_actions_wyReverseTime_start00
static int tolua_actions_wyReverseTime_start00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyReverseTime",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyReverseTime* self = (wyReverseTime*)  tolua_tousertype(tolua_S,1,0);
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

/* method: stop of class  wyReverseTime */
#ifndef TOLUA_DISABLE_tolua_actions_wyReverseTime_stop00
static int tolua_actions_wyReverseTime_stop00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyReverseTime",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyReverseTime* self = (wyReverseTime*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'stop'", NULL);
#endif
  {
   self->stop();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'stop'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: update of class  wyReverseTime */
#ifndef TOLUA_DISABLE_tolua_actions_wyReverseTime_update00
static int tolua_actions_wyReverseTime_update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyReverseTime",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyReverseTime* self = (wyReverseTime*)  tolua_tousertype(tolua_S,1,0);
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

/* method: make of class  wyRotateBy */
#ifndef TOLUA_DISABLE_tolua_actions_wyRotateBy_make00
static int tolua_actions_wyRotateBy_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyRotateBy",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  float angle = ((float)  tolua_tonumber(tolua_S,3,0));
  {
   wyRotateBy* tolua_ret = (wyRotateBy*)  wyRotateBy::make(duration,angle);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyRotateBy");
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

/* method: delete of class  wyRotateBy */
#ifndef TOLUA_DISABLE_tolua_actions_wyRotateBy_delete00
static int tolua_actions_wyRotateBy_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyRotateBy",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyRotateBy* self = (wyRotateBy*)  tolua_tousertype(tolua_S,1,0);
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

/* method: copy of class  wyRotateBy */
#ifndef TOLUA_DISABLE_tolua_actions_wyRotateBy_copy00
static int tolua_actions_wyRotateBy_copy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyRotateBy",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyRotateBy* self = (wyRotateBy*)  tolua_tousertype(tolua_S,1,0);
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

/* method: reverse of class  wyRotateBy */
#ifndef TOLUA_DISABLE_tolua_actions_wyRotateBy_reverse00
static int tolua_actions_wyRotateBy_reverse00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyRotateBy",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyRotateBy* self = (wyRotateBy*)  tolua_tousertype(tolua_S,1,0);
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

/* method: start of class  wyRotateBy */
#ifndef TOLUA_DISABLE_tolua_actions_wyRotateBy_start00
static int tolua_actions_wyRotateBy_start00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyRotateBy",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyRotateBy* self = (wyRotateBy*)  tolua_tousertype(tolua_S,1,0);
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

/* method: update of class  wyRotateBy */
#ifndef TOLUA_DISABLE_tolua_actions_wyRotateBy_update00
static int tolua_actions_wyRotateBy_update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyRotateBy",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyRotateBy* self = (wyRotateBy*)  tolua_tousertype(tolua_S,1,0);
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

/* method: make of class  wyRotateTo */
#ifndef TOLUA_DISABLE_tolua_actions_wyRotateTo_make00
static int tolua_actions_wyRotateTo_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyRotateTo",0,&tolua_err) ||
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
  float startAngle = ((float)  tolua_tonumber(tolua_S,3,0));
  float endAngle = ((float)  tolua_tonumber(tolua_S,4,0));
  {
   wyRotateTo* tolua_ret = (wyRotateTo*)  wyRotateTo::make(duration,startAngle,endAngle);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyRotateTo");
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

/* method: delete of class  wyRotateTo */
#ifndef TOLUA_DISABLE_tolua_actions_wyRotateTo_delete00
static int tolua_actions_wyRotateTo_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyRotateTo",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyRotateTo* self = (wyRotateTo*)  tolua_tousertype(tolua_S,1,0);
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

/* method: copy of class  wyRotateTo */
#ifndef TOLUA_DISABLE_tolua_actions_wyRotateTo_copy00
static int tolua_actions_wyRotateTo_copy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyRotateTo",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyRotateTo* self = (wyRotateTo*)  tolua_tousertype(tolua_S,1,0);
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

/* method: reverse of class  wyRotateTo */
#ifndef TOLUA_DISABLE_tolua_actions_wyRotateTo_reverse00
static int tolua_actions_wyRotateTo_reverse00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyRotateTo",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyRotateTo* self = (wyRotateTo*)  tolua_tousertype(tolua_S,1,0);
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

/* method: update of class  wyRotateTo */
#ifndef TOLUA_DISABLE_tolua_actions_wyRotateTo_update00
static int tolua_actions_wyRotateTo_update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyRotateTo",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyRotateTo* self = (wyRotateTo*)  tolua_tousertype(tolua_S,1,0);
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

/* method: make of class  wyScaleBy */
#ifndef TOLUA_DISABLE_tolua_actions_wyScaleBy_make00
static int tolua_actions_wyScaleBy_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyScaleBy",0,&tolua_err) ||
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
  float scaleX = ((float)  tolua_tonumber(tolua_S,3,0));
  float scaleY = ((float)  tolua_tonumber(tolua_S,4,0));
  {
   wyScaleBy* tolua_ret = (wyScaleBy*)  wyScaleBy::make(duration,scaleX,scaleY);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyScaleBy");
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

/* method: make of class  wyScaleBy */
#ifndef TOLUA_DISABLE_tolua_actions_wyScaleBy_make01
static int tolua_actions_wyScaleBy_make01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyScaleBy",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  float scale = ((float)  tolua_tonumber(tolua_S,3,0));
  {
   wyScaleBy* tolua_ret = (wyScaleBy*)  wyScaleBy::make(duration,scale);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyScaleBy");
  }
 }
 return 1;
tolua_lerror:
 return tolua_actions_wyScaleBy_make00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  wyScaleBy */
#ifndef TOLUA_DISABLE_tolua_actions_wyScaleBy_delete00
static int tolua_actions_wyScaleBy_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyScaleBy",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyScaleBy* self = (wyScaleBy*)  tolua_tousertype(tolua_S,1,0);
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

/* method: copy of class  wyScaleBy */
#ifndef TOLUA_DISABLE_tolua_actions_wyScaleBy_copy00
static int tolua_actions_wyScaleBy_copy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyScaleBy",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyScaleBy* self = (wyScaleBy*)  tolua_tousertype(tolua_S,1,0);
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

/* method: reverse of class  wyScaleBy */
#ifndef TOLUA_DISABLE_tolua_actions_wyScaleBy_reverse00
static int tolua_actions_wyScaleBy_reverse00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyScaleBy",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyScaleBy* self = (wyScaleBy*)  tolua_tousertype(tolua_S,1,0);
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

/* method: start of class  wyScaleBy */
#ifndef TOLUA_DISABLE_tolua_actions_wyScaleBy_start00
static int tolua_actions_wyScaleBy_start00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyScaleBy",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyScaleBy* self = (wyScaleBy*)  tolua_tousertype(tolua_S,1,0);
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

/* method: update of class  wyScaleBy */
#ifndef TOLUA_DISABLE_tolua_actions_wyScaleBy_update00
static int tolua_actions_wyScaleBy_update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyScaleBy",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyScaleBy* self = (wyScaleBy*)  tolua_tousertype(tolua_S,1,0);
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

/* method: make of class  wyScaleTo */
#ifndef TOLUA_DISABLE_tolua_actions_wyScaleTo_make00
static int tolua_actions_wyScaleTo_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyScaleTo",0,&tolua_err) ||
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
  float startScaleX = ((float)  tolua_tonumber(tolua_S,3,0));
  float startScaleY = ((float)  tolua_tonumber(tolua_S,4,0));
  float endScaleX = ((float)  tolua_tonumber(tolua_S,5,0));
  float endScaleY = ((float)  tolua_tonumber(tolua_S,6,0));
  {
   wyScaleTo* tolua_ret = (wyScaleTo*)  wyScaleTo::make(duration,startScaleX,startScaleY,endScaleX,endScaleY);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyScaleTo");
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

/* method: make of class  wyScaleTo */
#ifndef TOLUA_DISABLE_tolua_actions_wyScaleTo_make01
static int tolua_actions_wyScaleTo_make01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyScaleTo",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  float startScale = ((float)  tolua_tonumber(tolua_S,3,0));
  float endScale = ((float)  tolua_tonumber(tolua_S,4,0));
  {
   wyScaleTo* tolua_ret = (wyScaleTo*)  wyScaleTo::make(duration,startScale,endScale);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyScaleTo");
  }
 }
 return 1;
tolua_lerror:
 return tolua_actions_wyScaleTo_make00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  wyScaleTo */
#ifndef TOLUA_DISABLE_tolua_actions_wyScaleTo_delete00
static int tolua_actions_wyScaleTo_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyScaleTo",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyScaleTo* self = (wyScaleTo*)  tolua_tousertype(tolua_S,1,0);
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

/* method: copy of class  wyScaleTo */
#ifndef TOLUA_DISABLE_tolua_actions_wyScaleTo_copy00
static int tolua_actions_wyScaleTo_copy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyScaleTo",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyScaleTo* self = (wyScaleTo*)  tolua_tousertype(tolua_S,1,0);
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

/* method: reverse of class  wyScaleTo */
#ifndef TOLUA_DISABLE_tolua_actions_wyScaleTo_reverse00
static int tolua_actions_wyScaleTo_reverse00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyScaleTo",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyScaleTo* self = (wyScaleTo*)  tolua_tousertype(tolua_S,1,0);
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

/* method: update of class  wyScaleTo */
#ifndef TOLUA_DISABLE_tolua_actions_wyScaleTo_update00
static int tolua_actions_wyScaleTo_update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyScaleTo",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyScaleTo* self = (wyScaleTo*)  tolua_tousertype(tolua_S,1,0);
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

/* method: delete of class  wySequence */
#ifndef TOLUA_DISABLE_tolua_actions_wySequence_delete00
static int tolua_actions_wySequence_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wySequence",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wySequence* self = (wySequence*)  tolua_tousertype(tolua_S,1,0);
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

/* method: copy of class  wySequence */
#ifndef TOLUA_DISABLE_tolua_actions_wySequence_copy00
static int tolua_actions_wySequence_copy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wySequence",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wySequence* self = (wySequence*)  tolua_tousertype(tolua_S,1,0);
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

/* method: reverse of class  wySequence */
#ifndef TOLUA_DISABLE_tolua_actions_wySequence_reverse00
static int tolua_actions_wySequence_reverse00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wySequence",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wySequence* self = (wySequence*)  tolua_tousertype(tolua_S,1,0);
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

/* method: start of class  wySequence */
#ifndef TOLUA_DISABLE_tolua_actions_wySequence_start00
static int tolua_actions_wySequence_start00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wySequence",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wySequence* self = (wySequence*)  tolua_tousertype(tolua_S,1,0);
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

/* method: stop of class  wySequence */
#ifndef TOLUA_DISABLE_tolua_actions_wySequence_stop00
static int tolua_actions_wySequence_stop00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wySequence",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wySequence* self = (wySequence*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'stop'", NULL);
#endif
  {
   self->stop();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'stop'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: update of class  wySequence */
#ifndef TOLUA_DISABLE_tolua_actions_wySequence_update00
static int tolua_actions_wySequence_update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wySequence",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wySequence* self = (wySequence*)  tolua_tousertype(tolua_S,1,0);
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

/* method: make of class  wyShake */
#ifndef TOLUA_DISABLE_tolua_actions_wyShake_make00
static int tolua_actions_wyShake_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyShake",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  float radius = ((float)  tolua_tonumber(tolua_S,3,0));
  {
   wyShake* tolua_ret = (wyShake*)  wyShake::make(duration,radius);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyShake");
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

/* method: delete of class  wyShake */
#ifndef TOLUA_DISABLE_tolua_actions_wyShake_delete00
static int tolua_actions_wyShake_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyShake",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyShake* self = (wyShake*)  tolua_tousertype(tolua_S,1,0);
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

/* method: copy of class  wyShake */
#ifndef TOLUA_DISABLE_tolua_actions_wyShake_copy00
static int tolua_actions_wyShake_copy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyShake",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyShake* self = (wyShake*)  tolua_tousertype(tolua_S,1,0);
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

/* method: reverse of class  wyShake */
#ifndef TOLUA_DISABLE_tolua_actions_wyShake_reverse00
static int tolua_actions_wyShake_reverse00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyShake",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyShake* self = (wyShake*)  tolua_tousertype(tolua_S,1,0);
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

/* method: update of class  wyShake */
#ifndef TOLUA_DISABLE_tolua_actions_wyShake_update00
static int tolua_actions_wyShake_update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyShake",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyShake* self = (wyShake*)  tolua_tousertype(tolua_S,1,0);
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

/* method: start of class  wyShake */
#ifndef TOLUA_DISABLE_tolua_actions_wyShake_start00
static int tolua_actions_wyShake_start00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyShake",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyShake* self = (wyShake*)  tolua_tousertype(tolua_S,1,0);
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

/* method: make of class  wyShow */
#ifndef TOLUA_DISABLE_tolua_actions_wyShow_make00
static int tolua_actions_wyShow_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyShow",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   wyShow* tolua_ret = (wyShow*)  wyShow::make();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyShow");
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

/* method: delete of class  wyShow */
#ifndef TOLUA_DISABLE_tolua_actions_wyShow_delete00
static int tolua_actions_wyShow_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyShow",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyShow* self = (wyShow*)  tolua_tousertype(tolua_S,1,0);
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

/* method: copy of class  wyShow */
#ifndef TOLUA_DISABLE_tolua_actions_wyShow_copy00
static int tolua_actions_wyShow_copy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyShow",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyShow* self = (wyShow*)  tolua_tousertype(tolua_S,1,0);
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

/* method: reverse of class  wyShow */
#ifndef TOLUA_DISABLE_tolua_actions_wyShow_reverse00
static int tolua_actions_wyShow_reverse00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyShow",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyShow* self = (wyShow*)  tolua_tousertype(tolua_S,1,0);
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

/* method: start of class  wyShow */
#ifndef TOLUA_DISABLE_tolua_actions_wyShow_start00
static int tolua_actions_wyShow_start00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyShow",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyShow* self = (wyShow*)  tolua_tousertype(tolua_S,1,0);
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

/* method: make of class  wySpawn */
#ifndef TOLUA_DISABLE_tolua_actions_wySpawn_make00
static int tolua_actions_wySpawn_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wySpawn",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyFiniteTimeAction",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"wyFiniteTimeAction",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyFiniteTimeAction* one = ((wyFiniteTimeAction*)  tolua_tousertype(tolua_S,2,0));
  wyFiniteTimeAction* two = ((wyFiniteTimeAction*)  tolua_tousertype(tolua_S,3,0));
  {
   wySpawn* tolua_ret = (wySpawn*)  wySpawn::make(one,two);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wySpawn");
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

/* method: delete of class  wySpawn */
#ifndef TOLUA_DISABLE_tolua_actions_wySpawn_delete00
static int tolua_actions_wySpawn_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wySpawn",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wySpawn* self = (wySpawn*)  tolua_tousertype(tolua_S,1,0);
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

/* method: copy of class  wySpawn */
#ifndef TOLUA_DISABLE_tolua_actions_wySpawn_copy00
static int tolua_actions_wySpawn_copy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wySpawn",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wySpawn* self = (wySpawn*)  tolua_tousertype(tolua_S,1,0);
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

/* method: reverse of class  wySpawn */
#ifndef TOLUA_DISABLE_tolua_actions_wySpawn_reverse00
static int tolua_actions_wySpawn_reverse00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wySpawn",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wySpawn* self = (wySpawn*)  tolua_tousertype(tolua_S,1,0);
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

/* method: start of class  wySpawn */
#ifndef TOLUA_DISABLE_tolua_actions_wySpawn_start00
static int tolua_actions_wySpawn_start00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wySpawn",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wySpawn* self = (wySpawn*)  tolua_tousertype(tolua_S,1,0);
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

/* method: stop of class  wySpawn */
#ifndef TOLUA_DISABLE_tolua_actions_wySpawn_stop00
static int tolua_actions_wySpawn_stop00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wySpawn",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wySpawn* self = (wySpawn*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'stop'", NULL);
#endif
  {
   self->stop();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'stop'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: update of class  wySpawn */
#ifndef TOLUA_DISABLE_tolua_actions_wySpawn_update00
static int tolua_actions_wySpawn_update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wySpawn",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wySpawn* self = (wySpawn*)  tolua_tousertype(tolua_S,1,0);
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

/* method: make of class  wySpeed */
#ifndef TOLUA_DISABLE_tolua_actions_wySpeed_make00
static int tolua_actions_wySpeed_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wySpeed",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyAction",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAction* other = ((wyAction*)  tolua_tousertype(tolua_S,2,0));
  float speed = ((float)  tolua_tonumber(tolua_S,3,0));
  {
   wySpeed* tolua_ret = (wySpeed*)  wySpeed::make(other,speed);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wySpeed");
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

/* method: delete of class  wySpeed */
#ifndef TOLUA_DISABLE_tolua_actions_wySpeed_delete00
static int tolua_actions_wySpeed_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wySpeed",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wySpeed* self = (wySpeed*)  tolua_tousertype(tolua_S,1,0);
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

/* method: copy of class  wySpeed */
#ifndef TOLUA_DISABLE_tolua_actions_wySpeed_copy00
static int tolua_actions_wySpeed_copy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wySpeed",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wySpeed* self = (wySpeed*)  tolua_tousertype(tolua_S,1,0);
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

/* method: reverse of class  wySpeed */
#ifndef TOLUA_DISABLE_tolua_actions_wySpeed_reverse00
static int tolua_actions_wySpeed_reverse00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wySpeed",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wySpeed* self = (wySpeed*)  tolua_tousertype(tolua_S,1,0);
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

/* method: start of class  wySpeed */
#ifndef TOLUA_DISABLE_tolua_actions_wySpeed_start00
static int tolua_actions_wySpeed_start00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wySpeed",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wySpeed* self = (wySpeed*)  tolua_tousertype(tolua_S,1,0);
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

/* method: stop of class  wySpeed */
#ifndef TOLUA_DISABLE_tolua_actions_wySpeed_stop00
static int tolua_actions_wySpeed_stop00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wySpeed",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wySpeed* self = (wySpeed*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'stop'", NULL);
#endif
  {
   self->stop();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'stop'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: step of class  wySpeed */
#ifndef TOLUA_DISABLE_tolua_actions_wySpeed_step00
static int tolua_actions_wySpeed_step00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wySpeed",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wySpeed* self = (wySpeed*)  tolua_tousertype(tolua_S,1,0);
  float t = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'step'", NULL);
#endif
  {
   self->step(t);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'step'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: update of class  wySpeed */
#ifndef TOLUA_DISABLE_tolua_actions_wySpeed_update00
static int tolua_actions_wySpeed_update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wySpeed",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wySpeed* self = (wySpeed*)  tolua_tousertype(tolua_S,1,0);
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

/* method: isDone of class  wySpeed */
#ifndef TOLUA_DISABLE_tolua_actions_wySpeed_isDone00
static int tolua_actions_wySpeed_isDone00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wySpeed",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wySpeed* self = (wySpeed*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isDone'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isDone();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isDone'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getSpeed of class  wySpeed */
#ifndef TOLUA_DISABLE_tolua_actions_wySpeed_getSpeed00
static int tolua_actions_wySpeed_getSpeed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wySpeed",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wySpeed* self = (wySpeed*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getSpeed'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getSpeed();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getSpeed'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setSpeed of class  wySpeed */
#ifndef TOLUA_DISABLE_tolua_actions_wySpeed_setSpeed00
static int tolua_actions_wySpeed_setSpeed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wySpeed",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wySpeed* self = (wySpeed*)  tolua_tousertype(tolua_S,1,0);
  float speed = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setSpeed'", NULL);
#endif
  {
   self->setSpeed(speed);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setSpeed'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: make of class  wyTintBy */
#ifndef TOLUA_DISABLE_tolua_actions_wyTintBy_make00
static int tolua_actions_wyTintBy_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyTintBy",0,&tolua_err) ||
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
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  int r = ((int)  tolua_tonumber(tolua_S,3,0));
  int g = ((int)  tolua_tonumber(tolua_S,4,0));
  int b = ((int)  tolua_tonumber(tolua_S,5,0));
  {
   wyTintBy* tolua_ret = (wyTintBy*)  wyTintBy::make(duration,r,g,b);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyTintBy");
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

/* method: delete of class  wyTintBy */
#ifndef TOLUA_DISABLE_tolua_actions_wyTintBy_delete00
static int tolua_actions_wyTintBy_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTintBy",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTintBy* self = (wyTintBy*)  tolua_tousertype(tolua_S,1,0);
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

/* method: copy of class  wyTintBy */
#ifndef TOLUA_DISABLE_tolua_actions_wyTintBy_copy00
static int tolua_actions_wyTintBy_copy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTintBy",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTintBy* self = (wyTintBy*)  tolua_tousertype(tolua_S,1,0);
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

/* method: reverse of class  wyTintBy */
#ifndef TOLUA_DISABLE_tolua_actions_wyTintBy_reverse00
static int tolua_actions_wyTintBy_reverse00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTintBy",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTintBy* self = (wyTintBy*)  tolua_tousertype(tolua_S,1,0);
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

/* method: start of class  wyTintBy */
#ifndef TOLUA_DISABLE_tolua_actions_wyTintBy_start00
static int tolua_actions_wyTintBy_start00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTintBy",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTintBy* self = (wyTintBy*)  tolua_tousertype(tolua_S,1,0);
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

/* method: update of class  wyTintBy */
#ifndef TOLUA_DISABLE_tolua_actions_wyTintBy_update00
static int tolua_actions_wyTintBy_update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTintBy",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTintBy* self = (wyTintBy*)  tolua_tousertype(tolua_S,1,0);
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

/* method: make of class  wyTintTo */
#ifndef TOLUA_DISABLE_tolua_actions_wyTintTo_make00
static int tolua_actions_wyTintTo_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyTintTo",0,&tolua_err) ||
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
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  int fromR = ((int)  tolua_tonumber(tolua_S,3,0));
  int fromG = ((int)  tolua_tonumber(tolua_S,4,0));
  int fromB = ((int)  tolua_tonumber(tolua_S,5,0));
  int toR = ((int)  tolua_tonumber(tolua_S,6,0));
  int toG = ((int)  tolua_tonumber(tolua_S,7,0));
  int toB = ((int)  tolua_tonumber(tolua_S,8,0));
  {
   wyTintTo* tolua_ret = (wyTintTo*)  wyTintTo::make(duration,fromR,fromG,fromB,toR,toG,toB);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyTintTo");
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

/* method: delete of class  wyTintTo */
#ifndef TOLUA_DISABLE_tolua_actions_wyTintTo_delete00
static int tolua_actions_wyTintTo_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTintTo",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTintTo* self = (wyTintTo*)  tolua_tousertype(tolua_S,1,0);
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

/* method: copy of class  wyTintTo */
#ifndef TOLUA_DISABLE_tolua_actions_wyTintTo_copy00
static int tolua_actions_wyTintTo_copy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTintTo",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTintTo* self = (wyTintTo*)  tolua_tousertype(tolua_S,1,0);
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

/* method: reverse of class  wyTintTo */
#ifndef TOLUA_DISABLE_tolua_actions_wyTintTo_reverse00
static int tolua_actions_wyTintTo_reverse00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTintTo",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTintTo* self = (wyTintTo*)  tolua_tousertype(tolua_S,1,0);
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

/* method: update of class  wyTintTo */
#ifndef TOLUA_DISABLE_tolua_actions_wyTintTo_update00
static int tolua_actions_wyTintTo_update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTintTo",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTintTo* self = (wyTintTo*)  tolua_tousertype(tolua_S,1,0);
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

/* method: make of class  wyToggleVisibility */
#ifndef TOLUA_DISABLE_tolua_actions_wyToggleVisibility_make00
static int tolua_actions_wyToggleVisibility_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyToggleVisibility",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   wyToggleVisibility* tolua_ret = (wyToggleVisibility*)  wyToggleVisibility::make();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyToggleVisibility");
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

/* method: delete of class  wyToggleVisibility */
#ifndef TOLUA_DISABLE_tolua_actions_wyToggleVisibility_delete00
static int tolua_actions_wyToggleVisibility_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyToggleVisibility",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyToggleVisibility* self = (wyToggleVisibility*)  tolua_tousertype(tolua_S,1,0);
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

/* method: copy of class  wyToggleVisibility */
#ifndef TOLUA_DISABLE_tolua_actions_wyToggleVisibility_copy00
static int tolua_actions_wyToggleVisibility_copy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyToggleVisibility",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyToggleVisibility* self = (wyToggleVisibility*)  tolua_tousertype(tolua_S,1,0);
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

/* method: reverse of class  wyToggleVisibility */
#ifndef TOLUA_DISABLE_tolua_actions_wyToggleVisibility_reverse00
static int tolua_actions_wyToggleVisibility_reverse00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyToggleVisibility",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyToggleVisibility* self = (wyToggleVisibility*)  tolua_tousertype(tolua_S,1,0);
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

/* method: start of class  wyToggleVisibility */
#ifndef TOLUA_DISABLE_tolua_actions_wyToggleVisibility_start00
static int tolua_actions_wyToggleVisibility_start00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyToggleVisibility",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyToggleVisibility* self = (wyToggleVisibility*)  tolua_tousertype(tolua_S,1,0);
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

/* method: make of class  wyLagrange */
#ifndef TOLUA_DISABLE_tolua_actions_wyLagrange_make00
static int tolua_actions_wyLagrange_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyLagrange",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"wyLagrangeConfig",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  wyLagrangeConfig config = *((wyLagrangeConfig*)  tolua_tousertype(tolua_S,3,0));
  {
   wyLagrange* tolua_ret = (wyLagrange*)  wyLagrange::make(duration,config);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyLagrange");
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

/* method: delete of class  wyLagrange */
#ifndef TOLUA_DISABLE_tolua_actions_wyLagrange_delete00
static int tolua_actions_wyLagrange_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyLagrange",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyLagrange* self = (wyLagrange*)  tolua_tousertype(tolua_S,1,0);
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

/* method: copy of class  wyLagrange */
#ifndef TOLUA_DISABLE_tolua_actions_wyLagrange_copy00
static int tolua_actions_wyLagrange_copy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyLagrange",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyLagrange* self = (wyLagrange*)  tolua_tousertype(tolua_S,1,0);
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

/* method: reverse of class  wyLagrange */
#ifndef TOLUA_DISABLE_tolua_actions_wyLagrange_reverse00
static int tolua_actions_wyLagrange_reverse00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyLagrange",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyLagrange* self = (wyLagrange*)  tolua_tousertype(tolua_S,1,0);
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

/* method: update of class  wyLagrange */
#ifndef TOLUA_DISABLE_tolua_actions_wyLagrange_update00
static int tolua_actions_wyLagrange_update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyLagrange",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyLagrange* self = (wyLagrange*)  tolua_tousertype(tolua_S,1,0);
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

/* method: setAutoRotate of class  wyLagrange */
#ifndef TOLUA_DISABLE_tolua_actions_wyLagrange_setAutoRotate00
static int tolua_actions_wyLagrange_setAutoRotate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyLagrange",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyLagrange* self = (wyLagrange*)  tolua_tousertype(tolua_S,1,0);
  bool flag = ((bool)  tolua_toboolean(tolua_S,2,0));
  float angleDelta = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setAutoRotate'", NULL);
#endif
  {
   self->setAutoRotate(flag,angleDelta);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setAutoRotate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setPinPoint of class  wyLagrange */
#ifndef TOLUA_DISABLE_tolua_actions_wyLagrange_setPinPoint00
static int tolua_actions_wyLagrange_setPinPoint00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyLagrange",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"wyPoint",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyLagrange* self = (wyLagrange*)  tolua_tousertype(tolua_S,1,0);
  wyPoint p = *((wyPoint*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setPinPoint'", NULL);
#endif
  {
   self->setPinPoint(p);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setPinPoint'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setPinPoint of class  wyLagrange */
#ifndef TOLUA_DISABLE_tolua_actions_wyLagrange_setPinPoint01
static int tolua_actions_wyLagrange_setPinPoint01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyLagrange",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  wyLagrange* self = (wyLagrange*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setPinPoint'", NULL);
#endif
  {
   self->setPinPoint(x,y);
  }
 }
 return 0;
tolua_lerror:
 return tolua_actions_wyLagrange_setPinPoint00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: getPinPoint of class  wyLagrange */
#ifndef TOLUA_DISABLE_tolua_actions_wyLagrange_getPinPoint00
static int tolua_actions_wyLagrange_getPinPoint00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyLagrange",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyLagrange* self = (wyLagrange*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getPinPoint'", NULL);
#endif
  {
   wyPoint tolua_ret = (wyPoint)  self->getPinPoint();
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
 tolua_error(tolua_S,"#ferror in function 'getPinPoint'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: clearPinPoint of class  wyLagrange */
#ifndef TOLUA_DISABLE_tolua_actions_wyLagrange_clearPinPoint00
static int tolua_actions_wyLagrange_clearPinPoint00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyLagrange",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyLagrange* self = (wyLagrange*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'clearPinPoint'", NULL);
#endif
  {
   self->clearPinPoint();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'clearPinPoint'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setPinAngleDelta of class  wyLagrange */
#ifndef TOLUA_DISABLE_tolua_actions_wyLagrange_setPinAngleDelta00
static int tolua_actions_wyLagrange_setPinAngleDelta00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyLagrange",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyLagrange* self = (wyLagrange*)  tolua_tousertype(tolua_S,1,0);
  float delta = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setPinAngleDelta'", NULL);
#endif
  {
   self->setPinAngleDelta(delta);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setPinAngleDelta'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getPinAngleDelta of class  wyLagrange */
#ifndef TOLUA_DISABLE_tolua_actions_wyLagrange_getPinAngleDelta00
static int tolua_actions_wyLagrange_getPinAngleDelta00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyLagrange",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyLagrange* self = (wyLagrange*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getPinAngleDelta'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getPinAngleDelta();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getPinAngleDelta'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: make of class  wyMoveByPath */
#ifndef TOLUA_DISABLE_tolua_actions_wyMoveByPath_make00
static int tolua_actions_wyMoveByPath_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyMoveByPath",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   wyMoveByPath* tolua_ret = (wyMoveByPath*)  wyMoveByPath::make();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyMoveByPath");
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

/* method: delete of class  wyMoveByPath */
#ifndef TOLUA_DISABLE_tolua_actions_wyMoveByPath_delete00
static int tolua_actions_wyMoveByPath_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyMoveByPath",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyMoveByPath* self = (wyMoveByPath*)  tolua_tousertype(tolua_S,1,0);
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

/* method: copy of class  wyMoveByPath */
#ifndef TOLUA_DISABLE_tolua_actions_wyMoveByPath_copy00
static int tolua_actions_wyMoveByPath_copy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyMoveByPath",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyMoveByPath* self = (wyMoveByPath*)  tolua_tousertype(tolua_S,1,0);
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

/* method: reverse of class  wyMoveByPath */
#ifndef TOLUA_DISABLE_tolua_actions_wyMoveByPath_reverse00
static int tolua_actions_wyMoveByPath_reverse00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyMoveByPath",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyMoveByPath* self = (wyMoveByPath*)  tolua_tousertype(tolua_S,1,0);
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

/* method: start of class  wyMoveByPath */
#ifndef TOLUA_DISABLE_tolua_actions_wyMoveByPath_start00
static int tolua_actions_wyMoveByPath_start00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyMoveByPath",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyMoveByPath* self = (wyMoveByPath*)  tolua_tousertype(tolua_S,1,0);
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

/* method: update of class  wyMoveByPath */
#ifndef TOLUA_DISABLE_tolua_actions_wyMoveByPath_update00
static int tolua_actions_wyMoveByPath_update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyMoveByPath",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyMoveByPath* self = (wyMoveByPath*)  tolua_tousertype(tolua_S,1,0);
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

/* method: addPoint of class  wyMoveByPath */
#ifndef TOLUA_DISABLE_tolua_actions_wyMoveByPath_addPoint00
static int tolua_actions_wyMoveByPath_addPoint00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyMoveByPath",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyMoveByPath* self = (wyMoveByPath*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
  float duration = ((float)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addPoint'", NULL);
#endif
  {
   self->addPoint(x,y,duration);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addPoint'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getPointCount of class  wyMoveByPath */
#ifndef TOLUA_DISABLE_tolua_actions_wyMoveByPath_getPointCount00
static int tolua_actions_wyMoveByPath_getPointCount00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyMoveByPath",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyMoveByPath* self = (wyMoveByPath*)  tolua_tousertype(tolua_S,1,0);
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

/* method: getPoints of class  wyMoveByPath */
#ifndef TOLUA_DISABLE_tolua_actions_wyMoveByPath_getPoints00
static int tolua_actions_wyMoveByPath_getPoints00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyMoveByPath",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyMoveByPath* self = (wyMoveByPath*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getPoints'", NULL);
#endif
  {
   void* tolua_ret = (void*)  self->getPoints();
   tolua_pushuserdata(tolua_S,(void*)tolua_ret);
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

/* method: setAutoRotate of class  wyMoveByPath */
#ifndef TOLUA_DISABLE_tolua_actions_wyMoveByPath_setAutoRotate00
static int tolua_actions_wyMoveByPath_setAutoRotate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyMoveByPath",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyMoveByPath* self = (wyMoveByPath*)  tolua_tousertype(tolua_S,1,0);
  bool flag = ((bool)  tolua_toboolean(tolua_S,2,0));
  float angleDelta = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setAutoRotate'", NULL);
#endif
  {
   self->setAutoRotate(flag,angleDelta);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setAutoRotate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setPinPoint of class  wyMoveByPath */
#ifndef TOLUA_DISABLE_tolua_actions_wyMoveByPath_setPinPoint00
static int tolua_actions_wyMoveByPath_setPinPoint00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyMoveByPath",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"wyPoint",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyMoveByPath* self = (wyMoveByPath*)  tolua_tousertype(tolua_S,1,0);
  wyPoint p = *((wyPoint*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setPinPoint'", NULL);
#endif
  {
   self->setPinPoint(p);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setPinPoint'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setPinPoint of class  wyMoveByPath */
#ifndef TOLUA_DISABLE_tolua_actions_wyMoveByPath_setPinPoint01
static int tolua_actions_wyMoveByPath_setPinPoint01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyMoveByPath",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  wyMoveByPath* self = (wyMoveByPath*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setPinPoint'", NULL);
#endif
  {
   self->setPinPoint(x,y);
  }
 }
 return 0;
tolua_lerror:
 return tolua_actions_wyMoveByPath_setPinPoint00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: getPinPoint of class  wyMoveByPath */
#ifndef TOLUA_DISABLE_tolua_actions_wyMoveByPath_getPinPoint00
static int tolua_actions_wyMoveByPath_getPinPoint00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyMoveByPath",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyMoveByPath* self = (wyMoveByPath*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getPinPoint'", NULL);
#endif
  {
   wyPoint tolua_ret = (wyPoint)  self->getPinPoint();
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
 tolua_error(tolua_S,"#ferror in function 'getPinPoint'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: clearPinPoint of class  wyMoveByPath */
#ifndef TOLUA_DISABLE_tolua_actions_wyMoveByPath_clearPinPoint00
static int tolua_actions_wyMoveByPath_clearPinPoint00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyMoveByPath",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyMoveByPath* self = (wyMoveByPath*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'clearPinPoint'", NULL);
#endif
  {
   self->clearPinPoint();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'clearPinPoint'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setPinAngleDelta of class  wyMoveByPath */
#ifndef TOLUA_DISABLE_tolua_actions_wyMoveByPath_setPinAngleDelta00
static int tolua_actions_wyMoveByPath_setPinAngleDelta00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyMoveByPath",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyMoveByPath* self = (wyMoveByPath*)  tolua_tousertype(tolua_S,1,0);
  float delta = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setPinAngleDelta'", NULL);
#endif
  {
   self->setPinAngleDelta(delta);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setPinAngleDelta'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getPinAngleDelta of class  wyMoveByPath */
#ifndef TOLUA_DISABLE_tolua_actions_wyMoveByPath_getPinAngleDelta00
static int tolua_actions_wyMoveByPath_getPinAngleDelta00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyMoveByPath",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyMoveByPath* self = (wyMoveByPath*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getPinAngleDelta'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getPinAngleDelta();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getPinAngleDelta'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: make of class  wyFollow */
#ifndef TOLUA_DISABLE_tolua_actions_wyFollow_make00
static int tolua_actions_wyFollow_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyFollow",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyNode",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"wyRect",1,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyNode* fNode = ((wyNode*)  tolua_tousertype(tolua_S,2,0));
  wyRect worldBoundary = *((wyRect*)  tolua_tousertype(tolua_S,3,(void*)&(const wyRect)wyrZero));
  {
   wyFollow* tolua_ret = (wyFollow*)  wyFollow::make(fNode,worldBoundary);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyFollow");
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

/* method: delete of class  wyFollow */
#ifndef TOLUA_DISABLE_tolua_actions_wyFollow_delete00
static int tolua_actions_wyFollow_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyFollow",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyFollow* self = (wyFollow*)  tolua_tousertype(tolua_S,1,0);
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

/* method: step of class  wyFollow */
#ifndef TOLUA_DISABLE_tolua_actions_wyFollow_step00
static int tolua_actions_wyFollow_step00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyFollow",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyFollow* self = (wyFollow*)  tolua_tousertype(tolua_S,1,0);
  float t = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'step'", NULL);
#endif
  {
   self->step(t);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'step'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isDone of class  wyFollow */
#ifndef TOLUA_DISABLE_tolua_actions_wyFollow_isDone00
static int tolua_actions_wyFollow_isDone00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyFollow",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyFollow* self = (wyFollow*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isDone'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isDone();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isDone'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: make of class  wyHypotrochoid */
#ifndef TOLUA_DISABLE_tolua_actions_wyHypotrochoid_make00
static int tolua_actions_wyHypotrochoid_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyHypotrochoid",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"wyHypotrochoidConfig",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  wyHypotrochoidConfig c = *((wyHypotrochoidConfig*)  tolua_tousertype(tolua_S,3,0));
  {
   wyHypotrochoid* tolua_ret = (wyHypotrochoid*)  wyHypotrochoid::make(duration,c);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyHypotrochoid");
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

/* method: delete of class  wyHypotrochoid */
#ifndef TOLUA_DISABLE_tolua_actions_wyHypotrochoid_delete00
static int tolua_actions_wyHypotrochoid_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyHypotrochoid",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyHypotrochoid* self = (wyHypotrochoid*)  tolua_tousertype(tolua_S,1,0);
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

/* method: copy of class  wyHypotrochoid */
#ifndef TOLUA_DISABLE_tolua_actions_wyHypotrochoid_copy00
static int tolua_actions_wyHypotrochoid_copy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyHypotrochoid",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyHypotrochoid* self = (wyHypotrochoid*)  tolua_tousertype(tolua_S,1,0);
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

/* method: update of class  wyHypotrochoid */
#ifndef TOLUA_DISABLE_tolua_actions_wyHypotrochoid_update00
static int tolua_actions_wyHypotrochoid_update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyHypotrochoid",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyHypotrochoid* self = (wyHypotrochoid*)  tolua_tousertype(tolua_S,1,0);
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

/* method: setAutoRotate of class  wyHypotrochoid */
#ifndef TOLUA_DISABLE_tolua_actions_wyHypotrochoid_setAutoRotate00
static int tolua_actions_wyHypotrochoid_setAutoRotate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyHypotrochoid",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyHypotrochoid* self = (wyHypotrochoid*)  tolua_tousertype(tolua_S,1,0);
  bool flag = ((bool)  tolua_toboolean(tolua_S,2,0));
  float angleDelta = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setAutoRotate'", NULL);
#endif
  {
   self->setAutoRotate(flag,angleDelta);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setAutoRotate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setPinPoint of class  wyHypotrochoid */
#ifndef TOLUA_DISABLE_tolua_actions_wyHypotrochoid_setPinPoint00
static int tolua_actions_wyHypotrochoid_setPinPoint00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyHypotrochoid",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"wyPoint",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyHypotrochoid* self = (wyHypotrochoid*)  tolua_tousertype(tolua_S,1,0);
  wyPoint p = *((wyPoint*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setPinPoint'", NULL);
#endif
  {
   self->setPinPoint(p);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setPinPoint'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setPinPoint of class  wyHypotrochoid */
#ifndef TOLUA_DISABLE_tolua_actions_wyHypotrochoid_setPinPoint01
static int tolua_actions_wyHypotrochoid_setPinPoint01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyHypotrochoid",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  wyHypotrochoid* self = (wyHypotrochoid*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setPinPoint'", NULL);
#endif
  {
   self->setPinPoint(x,y);
  }
 }
 return 0;
tolua_lerror:
 return tolua_actions_wyHypotrochoid_setPinPoint00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: getPinPoint of class  wyHypotrochoid */
#ifndef TOLUA_DISABLE_tolua_actions_wyHypotrochoid_getPinPoint00
static int tolua_actions_wyHypotrochoid_getPinPoint00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyHypotrochoid",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyHypotrochoid* self = (wyHypotrochoid*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getPinPoint'", NULL);
#endif
  {
   wyPoint tolua_ret = (wyPoint)  self->getPinPoint();
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
 tolua_error(tolua_S,"#ferror in function 'getPinPoint'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: clearPinPoint of class  wyHypotrochoid */
#ifndef TOLUA_DISABLE_tolua_actions_wyHypotrochoid_clearPinPoint00
static int tolua_actions_wyHypotrochoid_clearPinPoint00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyHypotrochoid",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyHypotrochoid* self = (wyHypotrochoid*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'clearPinPoint'", NULL);
#endif
  {
   self->clearPinPoint();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'clearPinPoint'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setPinAngleDelta of class  wyHypotrochoid */
#ifndef TOLUA_DISABLE_tolua_actions_wyHypotrochoid_setPinAngleDelta00
static int tolua_actions_wyHypotrochoid_setPinAngleDelta00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyHypotrochoid",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyHypotrochoid* self = (wyHypotrochoid*)  tolua_tousertype(tolua_S,1,0);
  float delta = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setPinAngleDelta'", NULL);
#endif
  {
   self->setPinAngleDelta(delta);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setPinAngleDelta'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getPinAngleDelta of class  wyHypotrochoid */
#ifndef TOLUA_DISABLE_tolua_actions_wyHypotrochoid_getPinAngleDelta00
static int tolua_actions_wyHypotrochoid_getPinAngleDelta00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyHypotrochoid",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyHypotrochoid* self = (wyHypotrochoid*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getPinAngleDelta'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getPinAngleDelta();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getPinAngleDelta'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: copy of class  wyAction */
#ifndef TOLUA_DISABLE_tolua_actions_wyAction_copy00
static int tolua_actions_wyAction_copy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAction",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAction* self = (wyAction*)  tolua_tousertype(tolua_S,1,0);
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

/* method: reverse of class  wyAction */
#ifndef TOLUA_DISABLE_tolua_actions_wyAction_reverse00
static int tolua_actions_wyAction_reverse00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAction",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAction* self = (wyAction*)  tolua_tousertype(tolua_S,1,0);
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

/* method: start of class  wyAction */
#ifndef TOLUA_DISABLE_tolua_actions_wyAction_start00
static int tolua_actions_wyAction_start00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAction",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAction* self = (wyAction*)  tolua_tousertype(tolua_S,1,0);
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

/* method: stop of class  wyAction */
#ifndef TOLUA_DISABLE_tolua_actions_wyAction_stop00
static int tolua_actions_wyAction_stop00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAction",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAction* self = (wyAction*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'stop'", NULL);
#endif
  {
   self->stop();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'stop'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: step of class  wyAction */
#ifndef TOLUA_DISABLE_tolua_actions_wyAction_step00
static int tolua_actions_wyAction_step00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAction",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAction* self = (wyAction*)  tolua_tousertype(tolua_S,1,0);
  float t = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'step'", NULL);
#endif
  {
   self->step(t);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'step'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: update of class  wyAction */
#ifndef TOLUA_DISABLE_tolua_actions_wyAction_update00
static int tolua_actions_wyAction_update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAction",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAction* self = (wyAction*)  tolua_tousertype(tolua_S,1,0);
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

/* method: isDone of class  wyAction */
#ifndef TOLUA_DISABLE_tolua_actions_wyAction_isDone00
static int tolua_actions_wyAction_isDone00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAction",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAction* self = (wyAction*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isDone'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isDone();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isDone'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setCallback of class  wyAction */
#ifndef TOLUA_DISABLE_tolua_actions_wyAction_setCallback00
static int tolua_actions_wyAction_setCallback00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAction",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyActionCallback",0,&tolua_err) ||
     !tolua_isuserdata(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAction* self = (wyAction*)  tolua_tousertype(tolua_S,1,0);
  wyActionCallback* callback = ((wyActionCallback*)  tolua_tousertype(tolua_S,2,0));
  void* data = ((void*)  tolua_touserdata(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setCallback'", NULL);
#endif
  {
   self->setCallback(callback,data);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setCallback'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setTag of class  wyAction */
#ifndef TOLUA_DISABLE_tolua_actions_wyAction_setTag00
static int tolua_actions_wyAction_setTag00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAction",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAction* self = (wyAction*)  tolua_tousertype(tolua_S,1,0);
  int tag = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setTag'", NULL);
#endif
  {
   self->setTag(tag);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setTag'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getTag of class  wyAction */
#ifndef TOLUA_DISABLE_tolua_actions_wyAction_getTag00
static int tolua_actions_wyAction_getTag00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAction",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAction* self = (wyAction*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getTag'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getTag();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getTag'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getTarget of class  wyAction */
#ifndef TOLUA_DISABLE_tolua_actions_wyAction_getTarget00
static int tolua_actions_wyAction_getTarget00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAction",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAction* self = (wyAction*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getTarget'", NULL);
#endif
  {
   wyNode* tolua_ret = (wyNode*)  self->getTarget();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyNode");
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

/* method: isRunning of class  wyAction */
#ifndef TOLUA_DISABLE_tolua_actions_wyAction_isRunning00
static int tolua_actions_wyAction_isRunning00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAction",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAction* self = (wyAction*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isRunning'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isRunning();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isRunning'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getParent of class  wyAction */
#ifndef TOLUA_DISABLE_tolua_actions_wyAction_getParent00
static int tolua_actions_wyAction_getParent00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAction",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAction* self = (wyAction*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getParent'", NULL);
#endif
  {
   wyAction* tolua_ret = (wyAction*)  self->getParent();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyAction");
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

/* method: setParent of class  wyAction */
#ifndef TOLUA_DISABLE_tolua_actions_wyAction_setParent00
static int tolua_actions_wyAction_setParent00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAction",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyAction",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAction* self = (wyAction*)  tolua_tousertype(tolua_S,1,0);
  wyAction* parent = ((wyAction*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setParent'", NULL);
#endif
  {
   self->setParent(parent);
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

/* method: isPaused of class  wyAction */
#ifndef TOLUA_DISABLE_tolua_actions_wyAction_isPaused00
static int tolua_actions_wyAction_isPaused00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAction",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAction* self = (wyAction*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isPaused'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isPaused();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isPaused'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: make of class  wySkewBy */
#ifndef TOLUA_DISABLE_tolua_actions_wySkewBy_make00
static int tolua_actions_wySkewBy_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wySkewBy",0,&tolua_err) ||
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
  float skewX = ((float)  tolua_tonumber(tolua_S,3,0));
  float skewY = ((float)  tolua_tonumber(tolua_S,4,0));
  {
   wySkewBy* tolua_ret = (wySkewBy*)  wySkewBy::make(duration,skewX,skewY);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wySkewBy");
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

/* method: delete of class  wySkewBy */
#ifndef TOLUA_DISABLE_tolua_actions_wySkewBy_delete00
static int tolua_actions_wySkewBy_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wySkewBy",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wySkewBy* self = (wySkewBy*)  tolua_tousertype(tolua_S,1,0);
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

/* method: copy of class  wySkewBy */
#ifndef TOLUA_DISABLE_tolua_actions_wySkewBy_copy00
static int tolua_actions_wySkewBy_copy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wySkewBy",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wySkewBy* self = (wySkewBy*)  tolua_tousertype(tolua_S,1,0);
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

/* method: reverse of class  wySkewBy */
#ifndef TOLUA_DISABLE_tolua_actions_wySkewBy_reverse00
static int tolua_actions_wySkewBy_reverse00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wySkewBy",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wySkewBy* self = (wySkewBy*)  tolua_tousertype(tolua_S,1,0);
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

/* method: start of class  wySkewBy */
#ifndef TOLUA_DISABLE_tolua_actions_wySkewBy_start00
static int tolua_actions_wySkewBy_start00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wySkewBy",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wySkewBy* self = (wySkewBy*)  tolua_tousertype(tolua_S,1,0);
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

/* method: update of class  wySkewBy */
#ifndef TOLUA_DISABLE_tolua_actions_wySkewBy_update00
static int tolua_actions_wySkewBy_update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wySkewBy",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wySkewBy* self = (wySkewBy*)  tolua_tousertype(tolua_S,1,0);
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

/* method: make of class  wySkewTo */
#ifndef TOLUA_DISABLE_tolua_actions_wySkewTo_make00
static int tolua_actions_wySkewTo_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wySkewTo",0,&tolua_err) ||
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
  float startSkewX = ((float)  tolua_tonumber(tolua_S,3,0));
  float endSkewX = ((float)  tolua_tonumber(tolua_S,4,0));
  float startSkewY = ((float)  tolua_tonumber(tolua_S,5,0));
  float endSkewY = ((float)  tolua_tonumber(tolua_S,6,0));
  {
   wySkewTo* tolua_ret = (wySkewTo*)  wySkewTo::make(duration,startSkewX,endSkewX,startSkewY,endSkewY);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wySkewTo");
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

/* method: delete of class  wySkewTo */
#ifndef TOLUA_DISABLE_tolua_actions_wySkewTo_delete00
static int tolua_actions_wySkewTo_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wySkewTo",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wySkewTo* self = (wySkewTo*)  tolua_tousertype(tolua_S,1,0);
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

/* method: copy of class  wySkewTo */
#ifndef TOLUA_DISABLE_tolua_actions_wySkewTo_copy00
static int tolua_actions_wySkewTo_copy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wySkewTo",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wySkewTo* self = (wySkewTo*)  tolua_tousertype(tolua_S,1,0);
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

/* method: reverse of class  wySkewTo */
#ifndef TOLUA_DISABLE_tolua_actions_wySkewTo_reverse00
static int tolua_actions_wySkewTo_reverse00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wySkewTo",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wySkewTo* self = (wySkewTo*)  tolua_tousertype(tolua_S,1,0);
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

/* method: update of class  wySkewTo */
#ifndef TOLUA_DISABLE_tolua_actions_wySkewTo_update00
static int tolua_actions_wySkewTo_update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wySkewTo",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wySkewTo* self = (wySkewTo*)  tolua_tousertype(tolua_S,1,0);
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
TOLUA_API int tolua_actions_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyAnimate","wyAnimate","wyIntervalAction",tolua_collect_wyAnimate);
  #else
  tolua_cclass(tolua_S,"wyAnimate","wyAnimate","wyIntervalAction",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyAnimate");
   tolua_function(tolua_S,"make",tolua_actions_wyAnimate_make00);
   tolua_function(tolua_S,"delete",tolua_actions_wyAnimate_delete00);
   tolua_function(tolua_S,"copy",tolua_actions_wyAnimate_copy00);
   tolua_function(tolua_S,"reverse",tolua_actions_wyAnimate_reverse00);
   tolua_function(tolua_S,"start",tolua_actions_wyAnimate_start00);
   tolua_function(tolua_S,"stop",tolua_actions_wyAnimate_stop00);
   tolua_function(tolua_S,"update",tolua_actions_wyAnimate_update00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyBezier","wyBezier","wyIntervalAction",tolua_collect_wyBezier);
  #else
  tolua_cclass(tolua_S,"wyBezier","wyBezier","wyIntervalAction",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyBezier");
   tolua_function(tolua_S,"make",tolua_actions_wyBezier_make00);
   tolua_function(tolua_S,"delete",tolua_actions_wyBezier_delete00);
   tolua_function(tolua_S,"copy",tolua_actions_wyBezier_copy00);
   tolua_function(tolua_S,"reverse",tolua_actions_wyBezier_reverse00);
   tolua_function(tolua_S,"start",tolua_actions_wyBezier_start00);
   tolua_function(tolua_S,"update",tolua_actions_wyBezier_update00);
   tolua_function(tolua_S,"setAutoRotate",tolua_actions_wyBezier_setAutoRotate00);
   tolua_function(tolua_S,"setPinPoint",tolua_actions_wyBezier_setPinPoint00);
   tolua_function(tolua_S,"setPinPoint",tolua_actions_wyBezier_setPinPoint01);
   tolua_function(tolua_S,"getPinPoint",tolua_actions_wyBezier_getPinPoint00);
   tolua_function(tolua_S,"clearPinPoint",tolua_actions_wyBezier_clearPinPoint00);
   tolua_function(tolua_S,"setPinAngleDelta",tolua_actions_wyBezier_setPinAngleDelta00);
   tolua_function(tolua_S,"getPinAngleDelta",tolua_actions_wyBezier_getPinAngleDelta00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyBlink","wyBlink","wyIntervalAction",tolua_collect_wyBlink);
  #else
  tolua_cclass(tolua_S,"wyBlink","wyBlink","wyIntervalAction",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyBlink");
   tolua_function(tolua_S,"make",tolua_actions_wyBlink_make00);
   tolua_function(tolua_S,"delete",tolua_actions_wyBlink_delete00);
   tolua_function(tolua_S,"copy",tolua_actions_wyBlink_copy00);
   tolua_function(tolua_S,"reverse",tolua_actions_wyBlink_reverse00);
   tolua_function(tolua_S,"update",tolua_actions_wyBlink_update00);
   tolua_function(tolua_S,"stop",tolua_actions_wyBlink_stop00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyCallFunc","wyCallFunc","wyInstantAction",tolua_collect_wyCallFunc);
  #else
  tolua_cclass(tolua_S,"wyCallFunc","wyCallFunc","wyInstantAction",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyCallFunc");
   tolua_function(tolua_S,"make",tolua_actions_wyCallFunc_make00);
   tolua_function(tolua_S,"delete",tolua_actions_wyCallFunc_delete00);
   tolua_function(tolua_S,"copy",tolua_actions_wyCallFunc_copy00);
   tolua_function(tolua_S,"reverse",tolua_actions_wyCallFunc_reverse00);
   tolua_function(tolua_S,"start",tolua_actions_wyCallFunc_start00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"wyCameraAction","wyCameraAction","wyIntervalAction",NULL);
  tolua_beginmodule(tolua_S,"wyCameraAction");
   tolua_function(tolua_S,"reverse",tolua_actions_wyCameraAction_reverse00);
   tolua_function(tolua_S,"start",tolua_actions_wyCameraAction_start00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyDelayTime","wyDelayTime","wyIntervalAction",tolua_collect_wyDelayTime);
  #else
  tolua_cclass(tolua_S,"wyDelayTime","wyDelayTime","wyIntervalAction",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyDelayTime");
   tolua_function(tolua_S,"make",tolua_actions_wyDelayTime_make00);
   tolua_function(tolua_S,"delete",tolua_actions_wyDelayTime_delete00);
   tolua_function(tolua_S,"copy",tolua_actions_wyDelayTime_copy00);
   tolua_function(tolua_S,"reverse",tolua_actions_wyDelayTime_reverse00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyFadeIn","wyFadeIn","wyIntervalAction",tolua_collect_wyFadeIn);
  #else
  tolua_cclass(tolua_S,"wyFadeIn","wyFadeIn","wyIntervalAction",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyFadeIn");
   tolua_function(tolua_S,"make",tolua_actions_wyFadeIn_make00);
   tolua_function(tolua_S,"delete",tolua_actions_wyFadeIn_delete00);
   tolua_function(tolua_S,"copy",tolua_actions_wyFadeIn_copy00);
   tolua_function(tolua_S,"reverse",tolua_actions_wyFadeIn_reverse00);
   tolua_function(tolua_S,"update",tolua_actions_wyFadeIn_update00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyFadeOut","wyFadeOut","wyIntervalAction",tolua_collect_wyFadeOut);
  #else
  tolua_cclass(tolua_S,"wyFadeOut","wyFadeOut","wyIntervalAction",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyFadeOut");
   tolua_function(tolua_S,"make",tolua_actions_wyFadeOut_make00);
   tolua_function(tolua_S,"delete",tolua_actions_wyFadeOut_delete00);
   tolua_function(tolua_S,"copy",tolua_actions_wyFadeOut_copy00);
   tolua_function(tolua_S,"reverse",tolua_actions_wyFadeOut_reverse00);
   tolua_function(tolua_S,"update",tolua_actions_wyFadeOut_update00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyFadeTo","wyFadeTo","wyIntervalAction",tolua_collect_wyFadeTo);
  #else
  tolua_cclass(tolua_S,"wyFadeTo","wyFadeTo","wyIntervalAction",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyFadeTo");
   tolua_function(tolua_S,"make",tolua_actions_wyFadeTo_make00);
   tolua_function(tolua_S,"delete",tolua_actions_wyFadeTo_delete00);
   tolua_function(tolua_S,"copy",tolua_actions_wyFadeTo_copy00);
   tolua_function(tolua_S,"reverse",tolua_actions_wyFadeTo_reverse00);
   tolua_function(tolua_S,"update",tolua_actions_wyFadeTo_update00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"wyFiniteTimeAction","wyFiniteTimeAction","wyAction",NULL);
  tolua_beginmodule(tolua_S,"wyFiniteTimeAction");
   tolua_function(tolua_S,"start",tolua_actions_wyFiniteTimeAction_start00);
   tolua_function(tolua_S,"getDuration",tolua_actions_wyFiniteTimeAction_getDuration00);
   tolua_function(tolua_S,"setDuration",tolua_actions_wyFiniteTimeAction_setDuration00);
   tolua_function(tolua_S,"getElapsed",tolua_actions_wyFiniteTimeAction_getElapsed00);
   tolua_function(tolua_S,"setElapsed",tolua_actions_wyFiniteTimeAction_setElapsed00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyHide","wyHide","wyInstantAction",tolua_collect_wyHide);
  #else
  tolua_cclass(tolua_S,"wyHide","wyHide","wyInstantAction",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyHide");
   tolua_function(tolua_S,"make",tolua_actions_wyHide_make00);
   tolua_function(tolua_S,"delete",tolua_actions_wyHide_delete00);
   tolua_function(tolua_S,"copy",tolua_actions_wyHide_copy00);
   tolua_function(tolua_S,"reverse",tolua_actions_wyHide_reverse00);
   tolua_function(tolua_S,"start",tolua_actions_wyHide_start00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"wyInstantAction","wyInstantAction","wyFiniteTimeAction",NULL);
  tolua_beginmodule(tolua_S,"wyInstantAction");
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"wyIntervalAction","wyIntervalAction","wyFiniteTimeAction",NULL);
  tolua_beginmodule(tolua_S,"wyIntervalAction");
   tolua_function(tolua_S,"start",tolua_actions_wyIntervalAction_start00);
   tolua_function(tolua_S,"step",tolua_actions_wyIntervalAction_step00);
   tolua_function(tolua_S,"isDone",tolua_actions_wyIntervalAction_isDone00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyJumpBy","wyJumpBy","wyIntervalAction",tolua_collect_wyJumpBy);
  #else
  tolua_cclass(tolua_S,"wyJumpBy","wyJumpBy","wyIntervalAction",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyJumpBy");
   tolua_function(tolua_S,"make",tolua_actions_wyJumpBy_make00);
   tolua_function(tolua_S,"delete",tolua_actions_wyJumpBy_delete00);
   tolua_function(tolua_S,"copy",tolua_actions_wyJumpBy_copy00);
   tolua_function(tolua_S,"reverse",tolua_actions_wyJumpBy_reverse00);
   tolua_function(tolua_S,"start",tolua_actions_wyJumpBy_start00);
   tolua_function(tolua_S,"update",tolua_actions_wyJumpBy_update00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyJumpTo","wyJumpTo","wyIntervalAction",tolua_collect_wyJumpTo);
  #else
  tolua_cclass(tolua_S,"wyJumpTo","wyJumpTo","wyIntervalAction",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyJumpTo");
   tolua_function(tolua_S,"make",tolua_actions_wyJumpTo_make00);
   tolua_function(tolua_S,"delete",tolua_actions_wyJumpTo_delete00);
   tolua_function(tolua_S,"copy",tolua_actions_wyJumpTo_copy00);
   tolua_function(tolua_S,"reverse",tolua_actions_wyJumpTo_reverse00);
   tolua_function(tolua_S,"update",tolua_actions_wyJumpTo_update00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyMoveBy","wyMoveBy","wyIntervalAction",tolua_collect_wyMoveBy);
  #else
  tolua_cclass(tolua_S,"wyMoveBy","wyMoveBy","wyIntervalAction",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyMoveBy");
   tolua_function(tolua_S,"make",tolua_actions_wyMoveBy_make00);
   tolua_function(tolua_S,"delete",tolua_actions_wyMoveBy_delete00);
   tolua_function(tolua_S,"copy",tolua_actions_wyMoveBy_copy00);
   tolua_function(tolua_S,"reverse",tolua_actions_wyMoveBy_reverse00);
   tolua_function(tolua_S,"start",tolua_actions_wyMoveBy_start00);
   tolua_function(tolua_S,"update",tolua_actions_wyMoveBy_update00);
   tolua_function(tolua_S,"setPinPoint",tolua_actions_wyMoveBy_setPinPoint00);
   tolua_function(tolua_S,"setPinPoint",tolua_actions_wyMoveBy_setPinPoint01);
   tolua_function(tolua_S,"getPinPoint",tolua_actions_wyMoveBy_getPinPoint00);
   tolua_function(tolua_S,"clearPinPoint",tolua_actions_wyMoveBy_clearPinPoint00);
   tolua_function(tolua_S,"setPinAngleDelta",tolua_actions_wyMoveBy_setPinAngleDelta00);
   tolua_function(tolua_S,"getPinAngleDelta",tolua_actions_wyMoveBy_getPinAngleDelta00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyMoveByAngle","wyMoveByAngle","wyIntervalAction",tolua_collect_wyMoveByAngle);
  #else
  tolua_cclass(tolua_S,"wyMoveByAngle","wyMoveByAngle","wyIntervalAction",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyMoveByAngle");
   tolua_function(tolua_S,"make",tolua_actions_wyMoveByAngle_make00);
   tolua_function(tolua_S,"delete",tolua_actions_wyMoveByAngle_delete00);
   tolua_function(tolua_S,"copy",tolua_actions_wyMoveByAngle_copy00);
   tolua_function(tolua_S,"reverse",tolua_actions_wyMoveByAngle_reverse00);
   tolua_function(tolua_S,"start",tolua_actions_wyMoveByAngle_start00);
   tolua_function(tolua_S,"update",tolua_actions_wyMoveByAngle_update00);
   tolua_function(tolua_S,"setPinPoint",tolua_actions_wyMoveByAngle_setPinPoint00);
   tolua_function(tolua_S,"setPinPoint",tolua_actions_wyMoveByAngle_setPinPoint01);
   tolua_function(tolua_S,"getPinPoint",tolua_actions_wyMoveByAngle_getPinPoint00);
   tolua_function(tolua_S,"clearPinPoint",tolua_actions_wyMoveByAngle_clearPinPoint00);
   tolua_function(tolua_S,"setPinAngleDelta",tolua_actions_wyMoveByAngle_setPinAngleDelta00);
   tolua_function(tolua_S,"getPinAngleDelta",tolua_actions_wyMoveByAngle_getPinAngleDelta00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyMoveTo","wyMoveTo","wyIntervalAction",tolua_collect_wyMoveTo);
  #else
  tolua_cclass(tolua_S,"wyMoveTo","wyMoveTo","wyIntervalAction",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyMoveTo");
   tolua_function(tolua_S,"make",tolua_actions_wyMoveTo_make00);
   tolua_function(tolua_S,"delete",tolua_actions_wyMoveTo_delete00);
   tolua_function(tolua_S,"copy",tolua_actions_wyMoveTo_copy00);
   tolua_function(tolua_S,"reverse",tolua_actions_wyMoveTo_reverse00);
   tolua_function(tolua_S,"update",tolua_actions_wyMoveTo_update00);
   tolua_function(tolua_S,"setPinPoint",tolua_actions_wyMoveTo_setPinPoint00);
   tolua_function(tolua_S,"setPinPoint",tolua_actions_wyMoveTo_setPinPoint01);
   tolua_function(tolua_S,"getPinPoint",tolua_actions_wyMoveTo_getPinPoint00);
   tolua_function(tolua_S,"clearPinPoint",tolua_actions_wyMoveTo_clearPinPoint00);
   tolua_function(tolua_S,"setPinAngleDelta",tolua_actions_wyMoveTo_setPinAngleDelta00);
   tolua_function(tolua_S,"getPinAngleDelta",tolua_actions_wyMoveTo_getPinAngleDelta00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyOrbitCamera","wyOrbitCamera","wyCameraAction",tolua_collect_wyOrbitCamera);
  #else
  tolua_cclass(tolua_S,"wyOrbitCamera","wyOrbitCamera","wyCameraAction",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyOrbitCamera");
   tolua_function(tolua_S,"make",tolua_actions_wyOrbitCamera_make00);
   tolua_function(tolua_S,"delete",tolua_actions_wyOrbitCamera_delete00);
   tolua_function(tolua_S,"copy",tolua_actions_wyOrbitCamera_copy00);
   tolua_function(tolua_S,"start",tolua_actions_wyOrbitCamera_start00);
   tolua_function(tolua_S,"update",tolua_actions_wyOrbitCamera_update00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyPlace","wyPlace","wyInstantAction",tolua_collect_wyPlace);
  #else
  tolua_cclass(tolua_S,"wyPlace","wyPlace","wyInstantAction",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyPlace");
   tolua_function(tolua_S,"make",tolua_actions_wyPlace_make00);
   tolua_function(tolua_S,"delete",tolua_actions_wyPlace_delete00);
   tolua_function(tolua_S,"copy",tolua_actions_wyPlace_copy00);
   tolua_function(tolua_S,"reverse",tolua_actions_wyPlace_reverse00);
   tolua_function(tolua_S,"start",tolua_actions_wyPlace_start00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyProgressBy","wyProgressBy","wyIntervalAction",tolua_collect_wyProgressBy);
  #else
  tolua_cclass(tolua_S,"wyProgressBy","wyProgressBy","wyIntervalAction",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyProgressBy");
   tolua_function(tolua_S,"make",tolua_actions_wyProgressBy_make00);
   tolua_function(tolua_S,"delete",tolua_actions_wyProgressBy_delete00);
   tolua_function(tolua_S,"copy",tolua_actions_wyProgressBy_copy00);
   tolua_function(tolua_S,"reverse",tolua_actions_wyProgressBy_reverse00);
   tolua_function(tolua_S,"start",tolua_actions_wyProgressBy_start00);
   tolua_function(tolua_S,"update",tolua_actions_wyProgressBy_update00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyProgressTo","wyProgressTo","wyIntervalAction",tolua_collect_wyProgressTo);
  #else
  tolua_cclass(tolua_S,"wyProgressTo","wyProgressTo","wyIntervalAction",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyProgressTo");
   tolua_function(tolua_S,"make",tolua_actions_wyProgressTo_make00);
   tolua_function(tolua_S,"delete",tolua_actions_wyProgressTo_delete00);
   tolua_function(tolua_S,"copy",tolua_actions_wyProgressTo_copy00);
   tolua_function(tolua_S,"reverse",tolua_actions_wyProgressTo_reverse00);
   tolua_function(tolua_S,"update",tolua_actions_wyProgressTo_update00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyRepeat","wyRepeat","wyIntervalAction",tolua_collect_wyRepeat);
  #else
  tolua_cclass(tolua_S,"wyRepeat","wyRepeat","wyIntervalAction",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyRepeat");
   tolua_function(tolua_S,"make",tolua_actions_wyRepeat_make00);
   tolua_function(tolua_S,"delete",tolua_actions_wyRepeat_delete00);
   tolua_function(tolua_S,"copy",tolua_actions_wyRepeat_copy00);
   tolua_function(tolua_S,"reverse",tolua_actions_wyRepeat_reverse00);
   tolua_function(tolua_S,"start",tolua_actions_wyRepeat_start00);
   tolua_function(tolua_S,"stop",tolua_actions_wyRepeat_stop00);
   tolua_function(tolua_S,"update",tolua_actions_wyRepeat_update00);
   tolua_function(tolua_S,"isDone",tolua_actions_wyRepeat_isDone00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyRepeatForever","wyRepeatForever","wyAction",tolua_collect_wyRepeatForever);
  #else
  tolua_cclass(tolua_S,"wyRepeatForever","wyRepeatForever","wyAction",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyRepeatForever");
   tolua_function(tolua_S,"make",tolua_actions_wyRepeatForever_make00);
   tolua_function(tolua_S,"delete",tolua_actions_wyRepeatForever_delete00);
   tolua_function(tolua_S,"copy",tolua_actions_wyRepeatForever_copy00);
   tolua_function(tolua_S,"reverse",tolua_actions_wyRepeatForever_reverse00);
   tolua_function(tolua_S,"start",tolua_actions_wyRepeatForever_start00);
   tolua_function(tolua_S,"stop",tolua_actions_wyRepeatForever_stop00);
   tolua_function(tolua_S,"step",tolua_actions_wyRepeatForever_step00);
   tolua_function(tolua_S,"update",tolua_actions_wyRepeatForever_update00);
   tolua_function(tolua_S,"isDone",tolua_actions_wyRepeatForever_isDone00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyReverseTime","wyReverseTime","wyIntervalAction",tolua_collect_wyReverseTime);
  #else
  tolua_cclass(tolua_S,"wyReverseTime","wyReverseTime","wyIntervalAction",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyReverseTime");
   tolua_function(tolua_S,"make",tolua_actions_wyReverseTime_make00);
   tolua_function(tolua_S,"delete",tolua_actions_wyReverseTime_delete00);
   tolua_function(tolua_S,"copy",tolua_actions_wyReverseTime_copy00);
   tolua_function(tolua_S,"reverse",tolua_actions_wyReverseTime_reverse00);
   tolua_function(tolua_S,"start",tolua_actions_wyReverseTime_start00);
   tolua_function(tolua_S,"stop",tolua_actions_wyReverseTime_stop00);
   tolua_function(tolua_S,"update",tolua_actions_wyReverseTime_update00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyRotateBy","wyRotateBy","wyIntervalAction",tolua_collect_wyRotateBy);
  #else
  tolua_cclass(tolua_S,"wyRotateBy","wyRotateBy","wyIntervalAction",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyRotateBy");
   tolua_function(tolua_S,"make",tolua_actions_wyRotateBy_make00);
   tolua_function(tolua_S,"delete",tolua_actions_wyRotateBy_delete00);
   tolua_function(tolua_S,"copy",tolua_actions_wyRotateBy_copy00);
   tolua_function(tolua_S,"reverse",tolua_actions_wyRotateBy_reverse00);
   tolua_function(tolua_S,"start",tolua_actions_wyRotateBy_start00);
   tolua_function(tolua_S,"update",tolua_actions_wyRotateBy_update00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyRotateTo","wyRotateTo","wyIntervalAction",tolua_collect_wyRotateTo);
  #else
  tolua_cclass(tolua_S,"wyRotateTo","wyRotateTo","wyIntervalAction",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyRotateTo");
   tolua_function(tolua_S,"make",tolua_actions_wyRotateTo_make00);
   tolua_function(tolua_S,"delete",tolua_actions_wyRotateTo_delete00);
   tolua_function(tolua_S,"copy",tolua_actions_wyRotateTo_copy00);
   tolua_function(tolua_S,"reverse",tolua_actions_wyRotateTo_reverse00);
   tolua_function(tolua_S,"update",tolua_actions_wyRotateTo_update00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyScaleBy","wyScaleBy","wyIntervalAction",tolua_collect_wyScaleBy);
  #else
  tolua_cclass(tolua_S,"wyScaleBy","wyScaleBy","wyIntervalAction",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyScaleBy");
   tolua_function(tolua_S,"make",tolua_actions_wyScaleBy_make00);
   tolua_function(tolua_S,"make",tolua_actions_wyScaleBy_make01);
   tolua_function(tolua_S,"delete",tolua_actions_wyScaleBy_delete00);
   tolua_function(tolua_S,"copy",tolua_actions_wyScaleBy_copy00);
   tolua_function(tolua_S,"reverse",tolua_actions_wyScaleBy_reverse00);
   tolua_function(tolua_S,"start",tolua_actions_wyScaleBy_start00);
   tolua_function(tolua_S,"update",tolua_actions_wyScaleBy_update00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyScaleTo","wyScaleTo","wyIntervalAction",tolua_collect_wyScaleTo);
  #else
  tolua_cclass(tolua_S,"wyScaleTo","wyScaleTo","wyIntervalAction",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyScaleTo");
   tolua_function(tolua_S,"make",tolua_actions_wyScaleTo_make00);
   tolua_function(tolua_S,"make",tolua_actions_wyScaleTo_make01);
   tolua_function(tolua_S,"delete",tolua_actions_wyScaleTo_delete00);
   tolua_function(tolua_S,"copy",tolua_actions_wyScaleTo_copy00);
   tolua_function(tolua_S,"reverse",tolua_actions_wyScaleTo_reverse00);
   tolua_function(tolua_S,"update",tolua_actions_wyScaleTo_update00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wySequence","wySequence","wyIntervalAction",tolua_collect_wySequence);
  #else
  tolua_cclass(tolua_S,"wySequence","wySequence","wyIntervalAction",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wySequence");
   tolua_function(tolua_S,"delete",tolua_actions_wySequence_delete00);
   tolua_function(tolua_S,"copy",tolua_actions_wySequence_copy00);
   tolua_function(tolua_S,"reverse",tolua_actions_wySequence_reverse00);
   tolua_function(tolua_S,"start",tolua_actions_wySequence_start00);
   tolua_function(tolua_S,"stop",tolua_actions_wySequence_stop00);
   tolua_function(tolua_S,"update",tolua_actions_wySequence_update00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyShake","wyShake","wyIntervalAction",tolua_collect_wyShake);
  #else
  tolua_cclass(tolua_S,"wyShake","wyShake","wyIntervalAction",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyShake");
   tolua_function(tolua_S,"make",tolua_actions_wyShake_make00);
   tolua_function(tolua_S,"delete",tolua_actions_wyShake_delete00);
   tolua_function(tolua_S,"copy",tolua_actions_wyShake_copy00);
   tolua_function(tolua_S,"reverse",tolua_actions_wyShake_reverse00);
   tolua_function(tolua_S,"update",tolua_actions_wyShake_update00);
   tolua_function(tolua_S,"start",tolua_actions_wyShake_start00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyShow","wyShow","wyInstantAction",tolua_collect_wyShow);
  #else
  tolua_cclass(tolua_S,"wyShow","wyShow","wyInstantAction",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyShow");
   tolua_function(tolua_S,"make",tolua_actions_wyShow_make00);
   tolua_function(tolua_S,"delete",tolua_actions_wyShow_delete00);
   tolua_function(tolua_S,"copy",tolua_actions_wyShow_copy00);
   tolua_function(tolua_S,"reverse",tolua_actions_wyShow_reverse00);
   tolua_function(tolua_S,"start",tolua_actions_wyShow_start00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wySpawn","wySpawn","wyIntervalAction",tolua_collect_wySpawn);
  #else
  tolua_cclass(tolua_S,"wySpawn","wySpawn","wyIntervalAction",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wySpawn");
   tolua_function(tolua_S,"make",tolua_actions_wySpawn_make00);
   tolua_function(tolua_S,"delete",tolua_actions_wySpawn_delete00);
   tolua_function(tolua_S,"copy",tolua_actions_wySpawn_copy00);
   tolua_function(tolua_S,"reverse",tolua_actions_wySpawn_reverse00);
   tolua_function(tolua_S,"start",tolua_actions_wySpawn_start00);
   tolua_function(tolua_S,"stop",tolua_actions_wySpawn_stop00);
   tolua_function(tolua_S,"update",tolua_actions_wySpawn_update00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wySpeed","wySpeed","wyAction",tolua_collect_wySpeed);
  #else
  tolua_cclass(tolua_S,"wySpeed","wySpeed","wyAction",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wySpeed");
   tolua_function(tolua_S,"make",tolua_actions_wySpeed_make00);
   tolua_function(tolua_S,"delete",tolua_actions_wySpeed_delete00);
   tolua_function(tolua_S,"copy",tolua_actions_wySpeed_copy00);
   tolua_function(tolua_S,"reverse",tolua_actions_wySpeed_reverse00);
   tolua_function(tolua_S,"start",tolua_actions_wySpeed_start00);
   tolua_function(tolua_S,"stop",tolua_actions_wySpeed_stop00);
   tolua_function(tolua_S,"step",tolua_actions_wySpeed_step00);
   tolua_function(tolua_S,"update",tolua_actions_wySpeed_update00);
   tolua_function(tolua_S,"isDone",tolua_actions_wySpeed_isDone00);
   tolua_function(tolua_S,"getSpeed",tolua_actions_wySpeed_getSpeed00);
   tolua_function(tolua_S,"setSpeed",tolua_actions_wySpeed_setSpeed00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyTintBy","wyTintBy","wyIntervalAction",tolua_collect_wyTintBy);
  #else
  tolua_cclass(tolua_S,"wyTintBy","wyTintBy","wyIntervalAction",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyTintBy");
   tolua_function(tolua_S,"make",tolua_actions_wyTintBy_make00);
   tolua_function(tolua_S,"delete",tolua_actions_wyTintBy_delete00);
   tolua_function(tolua_S,"copy",tolua_actions_wyTintBy_copy00);
   tolua_function(tolua_S,"reverse",tolua_actions_wyTintBy_reverse00);
   tolua_function(tolua_S,"start",tolua_actions_wyTintBy_start00);
   tolua_function(tolua_S,"update",tolua_actions_wyTintBy_update00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyTintTo","wyTintTo","wyIntervalAction",tolua_collect_wyTintTo);
  #else
  tolua_cclass(tolua_S,"wyTintTo","wyTintTo","wyIntervalAction",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyTintTo");
   tolua_function(tolua_S,"make",tolua_actions_wyTintTo_make00);
   tolua_function(tolua_S,"delete",tolua_actions_wyTintTo_delete00);
   tolua_function(tolua_S,"copy",tolua_actions_wyTintTo_copy00);
   tolua_function(tolua_S,"reverse",tolua_actions_wyTintTo_reverse00);
   tolua_function(tolua_S,"update",tolua_actions_wyTintTo_update00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyToggleVisibility","wyToggleVisibility","wyInstantAction",tolua_collect_wyToggleVisibility);
  #else
  tolua_cclass(tolua_S,"wyToggleVisibility","wyToggleVisibility","wyInstantAction",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyToggleVisibility");
   tolua_function(tolua_S,"make",tolua_actions_wyToggleVisibility_make00);
   tolua_function(tolua_S,"delete",tolua_actions_wyToggleVisibility_delete00);
   tolua_function(tolua_S,"copy",tolua_actions_wyToggleVisibility_copy00);
   tolua_function(tolua_S,"reverse",tolua_actions_wyToggleVisibility_reverse00);
   tolua_function(tolua_S,"start",tolua_actions_wyToggleVisibility_start00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyLagrange","wyLagrange","wyIntervalAction",tolua_collect_wyLagrange);
  #else
  tolua_cclass(tolua_S,"wyLagrange","wyLagrange","wyIntervalAction",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyLagrange");
   tolua_function(tolua_S,"make",tolua_actions_wyLagrange_make00);
   tolua_function(tolua_S,"delete",tolua_actions_wyLagrange_delete00);
   tolua_function(tolua_S,"copy",tolua_actions_wyLagrange_copy00);
   tolua_function(tolua_S,"reverse",tolua_actions_wyLagrange_reverse00);
   tolua_function(tolua_S,"update",tolua_actions_wyLagrange_update00);
   tolua_function(tolua_S,"setAutoRotate",tolua_actions_wyLagrange_setAutoRotate00);
   tolua_function(tolua_S,"setPinPoint",tolua_actions_wyLagrange_setPinPoint00);
   tolua_function(tolua_S,"setPinPoint",tolua_actions_wyLagrange_setPinPoint01);
   tolua_function(tolua_S,"getPinPoint",tolua_actions_wyLagrange_getPinPoint00);
   tolua_function(tolua_S,"clearPinPoint",tolua_actions_wyLagrange_clearPinPoint00);
   tolua_function(tolua_S,"setPinAngleDelta",tolua_actions_wyLagrange_setPinAngleDelta00);
   tolua_function(tolua_S,"getPinAngleDelta",tolua_actions_wyLagrange_getPinAngleDelta00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyMoveByPath","wyMoveByPath","wyIntervalAction",tolua_collect_wyMoveByPath);
  #else
  tolua_cclass(tolua_S,"wyMoveByPath","wyMoveByPath","wyIntervalAction",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyMoveByPath");
   tolua_function(tolua_S,"make",tolua_actions_wyMoveByPath_make00);
   tolua_function(tolua_S,"delete",tolua_actions_wyMoveByPath_delete00);
   tolua_function(tolua_S,"copy",tolua_actions_wyMoveByPath_copy00);
   tolua_function(tolua_S,"reverse",tolua_actions_wyMoveByPath_reverse00);
   tolua_function(tolua_S,"start",tolua_actions_wyMoveByPath_start00);
   tolua_function(tolua_S,"update",tolua_actions_wyMoveByPath_update00);
   tolua_function(tolua_S,"addPoint",tolua_actions_wyMoveByPath_addPoint00);
   tolua_function(tolua_S,"getPointCount",tolua_actions_wyMoveByPath_getPointCount00);
   tolua_function(tolua_S,"getPoints",tolua_actions_wyMoveByPath_getPoints00);
   tolua_function(tolua_S,"setAutoRotate",tolua_actions_wyMoveByPath_setAutoRotate00);
   tolua_function(tolua_S,"setPinPoint",tolua_actions_wyMoveByPath_setPinPoint00);
   tolua_function(tolua_S,"setPinPoint",tolua_actions_wyMoveByPath_setPinPoint01);
   tolua_function(tolua_S,"getPinPoint",tolua_actions_wyMoveByPath_getPinPoint00);
   tolua_function(tolua_S,"clearPinPoint",tolua_actions_wyMoveByPath_clearPinPoint00);
   tolua_function(tolua_S,"setPinAngleDelta",tolua_actions_wyMoveByPath_setPinAngleDelta00);
   tolua_function(tolua_S,"getPinAngleDelta",tolua_actions_wyMoveByPath_getPinAngleDelta00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyFollow","wyFollow","wyAction",tolua_collect_wyFollow);
  #else
  tolua_cclass(tolua_S,"wyFollow","wyFollow","wyAction",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyFollow");
   tolua_function(tolua_S,"make",tolua_actions_wyFollow_make00);
   tolua_function(tolua_S,"delete",tolua_actions_wyFollow_delete00);
   tolua_function(tolua_S,"step",tolua_actions_wyFollow_step00);
   tolua_function(tolua_S,"isDone",tolua_actions_wyFollow_isDone00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyHypotrochoid","wyHypotrochoid","wyIntervalAction",tolua_collect_wyHypotrochoid);
  #else
  tolua_cclass(tolua_S,"wyHypotrochoid","wyHypotrochoid","wyIntervalAction",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyHypotrochoid");
   tolua_function(tolua_S,"make",tolua_actions_wyHypotrochoid_make00);
   tolua_function(tolua_S,"delete",tolua_actions_wyHypotrochoid_delete00);
   tolua_function(tolua_S,"copy",tolua_actions_wyHypotrochoid_copy00);
   tolua_function(tolua_S,"update",tolua_actions_wyHypotrochoid_update00);
   tolua_function(tolua_S,"setAutoRotate",tolua_actions_wyHypotrochoid_setAutoRotate00);
   tolua_function(tolua_S,"setPinPoint",tolua_actions_wyHypotrochoid_setPinPoint00);
   tolua_function(tolua_S,"setPinPoint",tolua_actions_wyHypotrochoid_setPinPoint01);
   tolua_function(tolua_S,"getPinPoint",tolua_actions_wyHypotrochoid_getPinPoint00);
   tolua_function(tolua_S,"clearPinPoint",tolua_actions_wyHypotrochoid_clearPinPoint00);
   tolua_function(tolua_S,"setPinAngleDelta",tolua_actions_wyHypotrochoid_setPinAngleDelta00);
   tolua_function(tolua_S,"getPinAngleDelta",tolua_actions_wyHypotrochoid_getPinAngleDelta00);
  tolua_endmodule(tolua_S);
  tolua_constant(tolua_S,"WY_ACTION_INVALID_TAG",WY_ACTION_INVALID_TAG);
  tolua_cclass(tolua_S,"wyAction","wyAction","wyObject",NULL);
  tolua_beginmodule(tolua_S,"wyAction");
   tolua_function(tolua_S,"copy",tolua_actions_wyAction_copy00);
   tolua_function(tolua_S,"reverse",tolua_actions_wyAction_reverse00);
   tolua_function(tolua_S,"start",tolua_actions_wyAction_start00);
   tolua_function(tolua_S,"stop",tolua_actions_wyAction_stop00);
   tolua_function(tolua_S,"step",tolua_actions_wyAction_step00);
   tolua_function(tolua_S,"update",tolua_actions_wyAction_update00);
   tolua_function(tolua_S,"isDone",tolua_actions_wyAction_isDone00);
   tolua_function(tolua_S,"setCallback",tolua_actions_wyAction_setCallback00);
   tolua_function(tolua_S,"setTag",tolua_actions_wyAction_setTag00);
   tolua_function(tolua_S,"getTag",tolua_actions_wyAction_getTag00);
   tolua_function(tolua_S,"getTarget",tolua_actions_wyAction_getTarget00);
   tolua_function(tolua_S,"isRunning",tolua_actions_wyAction_isRunning00);
   tolua_function(tolua_S,"getParent",tolua_actions_wyAction_getParent00);
   tolua_function(tolua_S,"setParent",tolua_actions_wyAction_setParent00);
   tolua_function(tolua_S,"isPaused",tolua_actions_wyAction_isPaused00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"wyActionCallback","wyActionCallback","",NULL);
  tolua_beginmodule(tolua_S,"wyActionCallback");
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"wyNode","wyNode","",NULL);
  tolua_beginmodule(tolua_S,"wyNode");
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wySkewBy","wySkewBy","wyIntervalAction",tolua_collect_wySkewBy);
  #else
  tolua_cclass(tolua_S,"wySkewBy","wySkewBy","wyIntervalAction",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wySkewBy");
   tolua_function(tolua_S,"make",tolua_actions_wySkewBy_make00);
   tolua_function(tolua_S,"delete",tolua_actions_wySkewBy_delete00);
   tolua_function(tolua_S,"copy",tolua_actions_wySkewBy_copy00);
   tolua_function(tolua_S,"reverse",tolua_actions_wySkewBy_reverse00);
   tolua_function(tolua_S,"start",tolua_actions_wySkewBy_start00);
   tolua_function(tolua_S,"update",tolua_actions_wySkewBy_update00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wySkewTo","wySkewTo","wyIntervalAction",tolua_collect_wySkewTo);
  #else
  tolua_cclass(tolua_S,"wySkewTo","wySkewTo","wyIntervalAction",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wySkewTo");
   tolua_function(tolua_S,"make",tolua_actions_wySkewTo_make00);
   tolua_function(tolua_S,"delete",tolua_actions_wySkewTo_delete00);
   tolua_function(tolua_S,"copy",tolua_actions_wySkewTo_copy00);
   tolua_function(tolua_S,"reverse",tolua_actions_wySkewTo_reverse00);
   tolua_function(tolua_S,"update",tolua_actions_wySkewTo_update00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_actions (lua_State* tolua_S) {
 return tolua_actions_open(tolua_S);
};
#endif

