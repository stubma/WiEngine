/*
** Lua binding: easeactions
** Generated automatically by tolua++-1.0.92 on Sat Jun 11 19:26:05 2011.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_easeactions_open (lua_State* tolua_S);

#include "WiEngine.h"

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_wyEaseBackInOut (lua_State* tolua_S)
{
 wyEaseBackInOut* self = (wyEaseBackInOut*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyEaseSineIn (lua_State* tolua_S)
{
 wyEaseSineIn* self = (wyEaseSineIn*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyEaseBounce (lua_State* tolua_S)
{
 wyEaseBounce* self = (wyEaseBounce*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyEaseBounceInOut (lua_State* tolua_S)
{
 wyEaseBounceInOut* self = (wyEaseBounceInOut*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyEaseBackIn (lua_State* tolua_S)
{
 wyEaseBackIn* self = (wyEaseBackIn*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyEaseExponentialIn (lua_State* tolua_S)
{
 wyEaseExponentialIn* self = (wyEaseExponentialIn*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyEaseElastic (lua_State* tolua_S)
{
 wyEaseElastic* self = (wyEaseElastic*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyEaseBackOut (lua_State* tolua_S)
{
 wyEaseBackOut* self = (wyEaseBackOut*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyEaseBounceOut (lua_State* tolua_S)
{
 wyEaseBounceOut* self = (wyEaseBounceOut*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyEaseElasticIn (lua_State* tolua_S)
{
 wyEaseElasticIn* self = (wyEaseElasticIn*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyEaseSineOut (lua_State* tolua_S)
{
 wyEaseSineOut* self = (wyEaseSineOut*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyEaseElasticInOut (lua_State* tolua_S)
{
 wyEaseElasticInOut* self = (wyEaseElasticInOut*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyEaseRateAction (lua_State* tolua_S)
{
 wyEaseRateAction* self = (wyEaseRateAction*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyEaseAction (lua_State* tolua_S)
{
 wyEaseAction* self = (wyEaseAction*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyEaseSineInOut (lua_State* tolua_S)
{
 wyEaseSineInOut* self = (wyEaseSineInOut*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyEaseOut (lua_State* tolua_S)
{
 wyEaseOut* self = (wyEaseOut*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyEaseIn (lua_State* tolua_S)
{
 wyEaseIn* self = (wyEaseIn*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyEaseBounceIn (lua_State* tolua_S)
{
 wyEaseBounceIn* self = (wyEaseBounceIn*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyEaseExponentialInOut (lua_State* tolua_S)
{
 wyEaseExponentialInOut* self = (wyEaseExponentialInOut*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyEaseInOut (lua_State* tolua_S)
{
 wyEaseInOut* self = (wyEaseInOut*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyEaseExponentialOut (lua_State* tolua_S)
{
 wyEaseExponentialOut* self = (wyEaseExponentialOut*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyEaseElasticOut (lua_State* tolua_S)
{
 wyEaseElasticOut* self = (wyEaseElasticOut*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"wyAction");
 tolua_usertype(tolua_S,"wyEaseSineIn");
 tolua_usertype(tolua_S,"wyEaseBounce");
 tolua_usertype(tolua_S,"wyEaseBounceInOut");
 tolua_usertype(tolua_S,"wyEaseBackIn");
 tolua_usertype(tolua_S,"wyEaseExponentialIn");
 tolua_usertype(tolua_S,"wyEaseElastic");
 tolua_usertype(tolua_S,"wyEaseBackOut");
 tolua_usertype(tolua_S,"wyEaseBounceOut");
 tolua_usertype(tolua_S,"wyEaseElasticIn");
 tolua_usertype(tolua_S,"wyEaseSineOut");
 tolua_usertype(tolua_S,"wyEaseElasticInOut");
 tolua_usertype(tolua_S,"wyEaseExponentialInOut");
 tolua_usertype(tolua_S,"wyIntervalAction");
 tolua_usertype(tolua_S,"wyEaseRateAction");
 tolua_usertype(tolua_S,"wyEaseOut");
 tolua_usertype(tolua_S,"wyEaseAction");
 tolua_usertype(tolua_S,"wyEaseSineInOut");
 tolua_usertype(tolua_S,"wyEaseIn");
 tolua_usertype(tolua_S,"wyEaseExponentialOut");
 tolua_usertype(tolua_S,"wyEaseBounceIn");
 tolua_usertype(tolua_S,"wyNode");
 tolua_usertype(tolua_S,"wyEaseInOut");
 tolua_usertype(tolua_S,"wyEaseElasticOut");
 tolua_usertype(tolua_S,"wyEaseBackInOut");
}

/* method: new of class  wyEaseAction */
#ifndef TOLUA_DISABLE_tolua_easeactions_wyEaseAction_new00
static int tolua_easeactions_wyEaseAction_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyEaseAction",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyIntervalAction",1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyIntervalAction* wrapped = ((wyIntervalAction*)  tolua_tousertype(tolua_S,2,NULL));
  {
   wyEaseAction* tolua_ret = (wyEaseAction*)  Mtolua_new((wyEaseAction)(wrapped));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyEaseAction");
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

/* method: new_local of class  wyEaseAction */
#ifndef TOLUA_DISABLE_tolua_easeactions_wyEaseAction_new00_local
static int tolua_easeactions_wyEaseAction_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyEaseAction",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyIntervalAction",1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyIntervalAction* wrapped = ((wyIntervalAction*)  tolua_tousertype(tolua_S,2,NULL));
  {
   wyEaseAction* tolua_ret = (wyEaseAction*)  Mtolua_new((wyEaseAction)(wrapped));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyEaseAction");
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

/* method: delete of class  wyEaseAction */
#ifndef TOLUA_DISABLE_tolua_easeactions_wyEaseAction_delete00
static int tolua_easeactions_wyEaseAction_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyEaseAction",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyEaseAction* self = (wyEaseAction*)  tolua_tousertype(tolua_S,1,0);
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

/* method: start of class  wyEaseAction */
#ifndef TOLUA_DISABLE_tolua_easeactions_wyEaseAction_start00
static int tolua_easeactions_wyEaseAction_start00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyEaseAction",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyEaseAction* self = (wyEaseAction*)  tolua_tousertype(tolua_S,1,0);
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

/* method: stop of class  wyEaseAction */
#ifndef TOLUA_DISABLE_tolua_easeactions_wyEaseAction_stop00
static int tolua_easeactions_wyEaseAction_stop00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyEaseAction",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyEaseAction* self = (wyEaseAction*)  tolua_tousertype(tolua_S,1,0);
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

/* method: setWrappedAction of class  wyEaseAction */
#ifndef TOLUA_DISABLE_tolua_easeactions_wyEaseAction_setWrappedAction00
static int tolua_easeactions_wyEaseAction_setWrappedAction00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyEaseAction",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyIntervalAction",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyEaseAction* self = (wyEaseAction*)  tolua_tousertype(tolua_S,1,0);
  wyIntervalAction* wrapped = ((wyIntervalAction*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setWrappedAction'", NULL);
#endif
  {
   self->setWrappedAction(wrapped);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setWrappedAction'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: make of class  wyEaseBackIn */
#ifndef TOLUA_DISABLE_tolua_easeactions_wyEaseBackIn_make00
static int tolua_easeactions_wyEaseBackIn_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyEaseBackIn",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyIntervalAction",1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyIntervalAction* wrapped = ((wyIntervalAction*)  tolua_tousertype(tolua_S,2,NULL));
  {
   wyEaseBackIn* tolua_ret = (wyEaseBackIn*)  wyEaseBackIn::make(wrapped);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyEaseBackIn");
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

/* method: new of class  wyEaseBackIn */
#ifndef TOLUA_DISABLE_tolua_easeactions_wyEaseBackIn_new00
static int tolua_easeactions_wyEaseBackIn_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyEaseBackIn",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyIntervalAction",1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyIntervalAction* wrapped = ((wyIntervalAction*)  tolua_tousertype(tolua_S,2,NULL));
  {
   wyEaseBackIn* tolua_ret = (wyEaseBackIn*)  Mtolua_new((wyEaseBackIn)(wrapped));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyEaseBackIn");
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

/* method: new_local of class  wyEaseBackIn */
#ifndef TOLUA_DISABLE_tolua_easeactions_wyEaseBackIn_new00_local
static int tolua_easeactions_wyEaseBackIn_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyEaseBackIn",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyIntervalAction",1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyIntervalAction* wrapped = ((wyIntervalAction*)  tolua_tousertype(tolua_S,2,NULL));
  {
   wyEaseBackIn* tolua_ret = (wyEaseBackIn*)  Mtolua_new((wyEaseBackIn)(wrapped));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyEaseBackIn");
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

/* method: delete of class  wyEaseBackIn */
#ifndef TOLUA_DISABLE_tolua_easeactions_wyEaseBackIn_delete00
static int tolua_easeactions_wyEaseBackIn_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyEaseBackIn",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyEaseBackIn* self = (wyEaseBackIn*)  tolua_tousertype(tolua_S,1,0);
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

/* method: copy of class  wyEaseBackIn */
#ifndef TOLUA_DISABLE_tolua_easeactions_wyEaseBackIn_copy00
static int tolua_easeactions_wyEaseBackIn_copy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyEaseBackIn",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyEaseBackIn* self = (wyEaseBackIn*)  tolua_tousertype(tolua_S,1,0);
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

/* method: reverse of class  wyEaseBackIn */
#ifndef TOLUA_DISABLE_tolua_easeactions_wyEaseBackIn_reverse00
static int tolua_easeactions_wyEaseBackIn_reverse00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyEaseBackIn",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyEaseBackIn* self = (wyEaseBackIn*)  tolua_tousertype(tolua_S,1,0);
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

/* method: update of class  wyEaseBackIn */
#ifndef TOLUA_DISABLE_tolua_easeactions_wyEaseBackIn_update00
static int tolua_easeactions_wyEaseBackIn_update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyEaseBackIn",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyEaseBackIn* self = (wyEaseBackIn*)  tolua_tousertype(tolua_S,1,0);
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

/* method: make of class  wyEaseBackInOut */
#ifndef TOLUA_DISABLE_tolua_easeactions_wyEaseBackInOut_make00
static int tolua_easeactions_wyEaseBackInOut_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyEaseBackInOut",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyIntervalAction",1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyIntervalAction* wrapped = ((wyIntervalAction*)  tolua_tousertype(tolua_S,2,NULL));
  {
   wyEaseBackInOut* tolua_ret = (wyEaseBackInOut*)  wyEaseBackInOut::make(wrapped);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyEaseBackInOut");
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

/* method: new of class  wyEaseBackInOut */
#ifndef TOLUA_DISABLE_tolua_easeactions_wyEaseBackInOut_new00
static int tolua_easeactions_wyEaseBackInOut_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyEaseBackInOut",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyIntervalAction",1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyIntervalAction* wrapped = ((wyIntervalAction*)  tolua_tousertype(tolua_S,2,NULL));
  {
   wyEaseBackInOut* tolua_ret = (wyEaseBackInOut*)  Mtolua_new((wyEaseBackInOut)(wrapped));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyEaseBackInOut");
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

/* method: new_local of class  wyEaseBackInOut */
#ifndef TOLUA_DISABLE_tolua_easeactions_wyEaseBackInOut_new00_local
static int tolua_easeactions_wyEaseBackInOut_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyEaseBackInOut",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyIntervalAction",1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyIntervalAction* wrapped = ((wyIntervalAction*)  tolua_tousertype(tolua_S,2,NULL));
  {
   wyEaseBackInOut* tolua_ret = (wyEaseBackInOut*)  Mtolua_new((wyEaseBackInOut)(wrapped));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyEaseBackInOut");
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

/* method: delete of class  wyEaseBackInOut */
#ifndef TOLUA_DISABLE_tolua_easeactions_wyEaseBackInOut_delete00
static int tolua_easeactions_wyEaseBackInOut_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyEaseBackInOut",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyEaseBackInOut* self = (wyEaseBackInOut*)  tolua_tousertype(tolua_S,1,0);
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

/* method: copy of class  wyEaseBackInOut */
#ifndef TOLUA_DISABLE_tolua_easeactions_wyEaseBackInOut_copy00
static int tolua_easeactions_wyEaseBackInOut_copy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyEaseBackInOut",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyEaseBackInOut* self = (wyEaseBackInOut*)  tolua_tousertype(tolua_S,1,0);
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

/* method: reverse of class  wyEaseBackInOut */
#ifndef TOLUA_DISABLE_tolua_easeactions_wyEaseBackInOut_reverse00
static int tolua_easeactions_wyEaseBackInOut_reverse00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyEaseBackInOut",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyEaseBackInOut* self = (wyEaseBackInOut*)  tolua_tousertype(tolua_S,1,0);
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

/* method: update of class  wyEaseBackInOut */
#ifndef TOLUA_DISABLE_tolua_easeactions_wyEaseBackInOut_update00
static int tolua_easeactions_wyEaseBackInOut_update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyEaseBackInOut",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyEaseBackInOut* self = (wyEaseBackInOut*)  tolua_tousertype(tolua_S,1,0);
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

/* method: make of class  wyEaseBackOut */
#ifndef TOLUA_DISABLE_tolua_easeactions_wyEaseBackOut_make00
static int tolua_easeactions_wyEaseBackOut_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyEaseBackOut",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyIntervalAction",1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyIntervalAction* wrapped = ((wyIntervalAction*)  tolua_tousertype(tolua_S,2,NULL));
  {
   wyEaseBackOut* tolua_ret = (wyEaseBackOut*)  wyEaseBackOut::make(wrapped);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyEaseBackOut");
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

/* method: new of class  wyEaseBackOut */
#ifndef TOLUA_DISABLE_tolua_easeactions_wyEaseBackOut_new00
static int tolua_easeactions_wyEaseBackOut_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyEaseBackOut",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyIntervalAction",1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyIntervalAction* wrapped = ((wyIntervalAction*)  tolua_tousertype(tolua_S,2,NULL));
  {
   wyEaseBackOut* tolua_ret = (wyEaseBackOut*)  Mtolua_new((wyEaseBackOut)(wrapped));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyEaseBackOut");
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

/* method: new_local of class  wyEaseBackOut */
#ifndef TOLUA_DISABLE_tolua_easeactions_wyEaseBackOut_new00_local
static int tolua_easeactions_wyEaseBackOut_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyEaseBackOut",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyIntervalAction",1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyIntervalAction* wrapped = ((wyIntervalAction*)  tolua_tousertype(tolua_S,2,NULL));
  {
   wyEaseBackOut* tolua_ret = (wyEaseBackOut*)  Mtolua_new((wyEaseBackOut)(wrapped));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyEaseBackOut");
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

/* method: delete of class  wyEaseBackOut */
#ifndef TOLUA_DISABLE_tolua_easeactions_wyEaseBackOut_delete00
static int tolua_easeactions_wyEaseBackOut_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyEaseBackOut",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyEaseBackOut* self = (wyEaseBackOut*)  tolua_tousertype(tolua_S,1,0);
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

/* method: copy of class  wyEaseBackOut */
#ifndef TOLUA_DISABLE_tolua_easeactions_wyEaseBackOut_copy00
static int tolua_easeactions_wyEaseBackOut_copy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyEaseBackOut",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyEaseBackOut* self = (wyEaseBackOut*)  tolua_tousertype(tolua_S,1,0);
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

/* method: reverse of class  wyEaseBackOut */
#ifndef TOLUA_DISABLE_tolua_easeactions_wyEaseBackOut_reverse00
static int tolua_easeactions_wyEaseBackOut_reverse00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyEaseBackOut",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyEaseBackOut* self = (wyEaseBackOut*)  tolua_tousertype(tolua_S,1,0);
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

/* method: update of class  wyEaseBackOut */
#ifndef TOLUA_DISABLE_tolua_easeactions_wyEaseBackOut_update00
static int tolua_easeactions_wyEaseBackOut_update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyEaseBackOut",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyEaseBackOut* self = (wyEaseBackOut*)  tolua_tousertype(tolua_S,1,0);
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

/* method: new of class  wyEaseBounce */
#ifndef TOLUA_DISABLE_tolua_easeactions_wyEaseBounce_new00
static int tolua_easeactions_wyEaseBounce_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyEaseBounce",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyIntervalAction",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyIntervalAction* wrapped = ((wyIntervalAction*)  tolua_tousertype(tolua_S,2,0));
  {
   wyEaseBounce* tolua_ret = (wyEaseBounce*)  Mtolua_new((wyEaseBounce)(wrapped));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyEaseBounce");
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

/* method: new_local of class  wyEaseBounce */
#ifndef TOLUA_DISABLE_tolua_easeactions_wyEaseBounce_new00_local
static int tolua_easeactions_wyEaseBounce_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyEaseBounce",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyIntervalAction",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyIntervalAction* wrapped = ((wyIntervalAction*)  tolua_tousertype(tolua_S,2,0));
  {
   wyEaseBounce* tolua_ret = (wyEaseBounce*)  Mtolua_new((wyEaseBounce)(wrapped));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyEaseBounce");
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

/* method: delete of class  wyEaseBounce */
#ifndef TOLUA_DISABLE_tolua_easeactions_wyEaseBounce_delete00
static int tolua_easeactions_wyEaseBounce_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyEaseBounce",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyEaseBounce* self = (wyEaseBounce*)  tolua_tousertype(tolua_S,1,0);
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

/* method: make of class  wyEaseBounceIn */
#ifndef TOLUA_DISABLE_tolua_easeactions_wyEaseBounceIn_make00
static int tolua_easeactions_wyEaseBounceIn_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyEaseBounceIn",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyIntervalAction",1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyIntervalAction* wrapped = ((wyIntervalAction*)  tolua_tousertype(tolua_S,2,NULL));
  {
   wyEaseBounceIn* tolua_ret = (wyEaseBounceIn*)  wyEaseBounceIn::make(wrapped);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyEaseBounceIn");
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

/* method: new of class  wyEaseBounceIn */
#ifndef TOLUA_DISABLE_tolua_easeactions_wyEaseBounceIn_new00
static int tolua_easeactions_wyEaseBounceIn_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyEaseBounceIn",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyIntervalAction",1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyIntervalAction* wrapped = ((wyIntervalAction*)  tolua_tousertype(tolua_S,2,NULL));
  {
   wyEaseBounceIn* tolua_ret = (wyEaseBounceIn*)  Mtolua_new((wyEaseBounceIn)(wrapped));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyEaseBounceIn");
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

/* method: new_local of class  wyEaseBounceIn */
#ifndef TOLUA_DISABLE_tolua_easeactions_wyEaseBounceIn_new00_local
static int tolua_easeactions_wyEaseBounceIn_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyEaseBounceIn",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyIntervalAction",1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyIntervalAction* wrapped = ((wyIntervalAction*)  tolua_tousertype(tolua_S,2,NULL));
  {
   wyEaseBounceIn* tolua_ret = (wyEaseBounceIn*)  Mtolua_new((wyEaseBounceIn)(wrapped));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyEaseBounceIn");
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

/* method: delete of class  wyEaseBounceIn */
#ifndef TOLUA_DISABLE_tolua_easeactions_wyEaseBounceIn_delete00
static int tolua_easeactions_wyEaseBounceIn_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyEaseBounceIn",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyEaseBounceIn* self = (wyEaseBounceIn*)  tolua_tousertype(tolua_S,1,0);
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

/* method: copy of class  wyEaseBounceIn */
#ifndef TOLUA_DISABLE_tolua_easeactions_wyEaseBounceIn_copy00
static int tolua_easeactions_wyEaseBounceIn_copy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyEaseBounceIn",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyEaseBounceIn* self = (wyEaseBounceIn*)  tolua_tousertype(tolua_S,1,0);
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

/* method: reverse of class  wyEaseBounceIn */
#ifndef TOLUA_DISABLE_tolua_easeactions_wyEaseBounceIn_reverse00
static int tolua_easeactions_wyEaseBounceIn_reverse00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyEaseBounceIn",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyEaseBounceIn* self = (wyEaseBounceIn*)  tolua_tousertype(tolua_S,1,0);
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

/* method: update of class  wyEaseBounceIn */
#ifndef TOLUA_DISABLE_tolua_easeactions_wyEaseBounceIn_update00
static int tolua_easeactions_wyEaseBounceIn_update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyEaseBounceIn",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyEaseBounceIn* self = (wyEaseBounceIn*)  tolua_tousertype(tolua_S,1,0);
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

/* method: make of class  wyEaseBounceInOut */
#ifndef TOLUA_DISABLE_tolua_easeactions_wyEaseBounceInOut_make00
static int tolua_easeactions_wyEaseBounceInOut_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyEaseBounceInOut",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyIntervalAction",1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyIntervalAction* wrapped = ((wyIntervalAction*)  tolua_tousertype(tolua_S,2,NULL));
  {
   wyEaseBounceInOut* tolua_ret = (wyEaseBounceInOut*)  wyEaseBounceInOut::make(wrapped);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyEaseBounceInOut");
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

/* method: new of class  wyEaseBounceInOut */
#ifndef TOLUA_DISABLE_tolua_easeactions_wyEaseBounceInOut_new00
static int tolua_easeactions_wyEaseBounceInOut_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyEaseBounceInOut",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyIntervalAction",1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyIntervalAction* wrapped = ((wyIntervalAction*)  tolua_tousertype(tolua_S,2,NULL));
  {
   wyEaseBounceInOut* tolua_ret = (wyEaseBounceInOut*)  Mtolua_new((wyEaseBounceInOut)(wrapped));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyEaseBounceInOut");
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

/* method: new_local of class  wyEaseBounceInOut */
#ifndef TOLUA_DISABLE_tolua_easeactions_wyEaseBounceInOut_new00_local
static int tolua_easeactions_wyEaseBounceInOut_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyEaseBounceInOut",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyIntervalAction",1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyIntervalAction* wrapped = ((wyIntervalAction*)  tolua_tousertype(tolua_S,2,NULL));
  {
   wyEaseBounceInOut* tolua_ret = (wyEaseBounceInOut*)  Mtolua_new((wyEaseBounceInOut)(wrapped));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyEaseBounceInOut");
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

/* method: delete of class  wyEaseBounceInOut */
#ifndef TOLUA_DISABLE_tolua_easeactions_wyEaseBounceInOut_delete00
static int tolua_easeactions_wyEaseBounceInOut_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyEaseBounceInOut",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyEaseBounceInOut* self = (wyEaseBounceInOut*)  tolua_tousertype(tolua_S,1,0);
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

/* method: copy of class  wyEaseBounceInOut */
#ifndef TOLUA_DISABLE_tolua_easeactions_wyEaseBounceInOut_copy00
static int tolua_easeactions_wyEaseBounceInOut_copy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyEaseBounceInOut",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyEaseBounceInOut* self = (wyEaseBounceInOut*)  tolua_tousertype(tolua_S,1,0);
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

/* method: reverse of class  wyEaseBounceInOut */
#ifndef TOLUA_DISABLE_tolua_easeactions_wyEaseBounceInOut_reverse00
static int tolua_easeactions_wyEaseBounceInOut_reverse00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyEaseBounceInOut",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyEaseBounceInOut* self = (wyEaseBounceInOut*)  tolua_tousertype(tolua_S,1,0);
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

/* method: update of class  wyEaseBounceInOut */
#ifndef TOLUA_DISABLE_tolua_easeactions_wyEaseBounceInOut_update00
static int tolua_easeactions_wyEaseBounceInOut_update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyEaseBounceInOut",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyEaseBounceInOut* self = (wyEaseBounceInOut*)  tolua_tousertype(tolua_S,1,0);
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

/* method: make of class  wyEaseBounceOut */
#ifndef TOLUA_DISABLE_tolua_easeactions_wyEaseBounceOut_make00
static int tolua_easeactions_wyEaseBounceOut_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyEaseBounceOut",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyIntervalAction",1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyIntervalAction* wrapped = ((wyIntervalAction*)  tolua_tousertype(tolua_S,2,NULL));
  {
   wyEaseBounceOut* tolua_ret = (wyEaseBounceOut*)  wyEaseBounceOut::make(wrapped);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyEaseBounceOut");
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

/* method: new of class  wyEaseBounceOut */
#ifndef TOLUA_DISABLE_tolua_easeactions_wyEaseBounceOut_new00
static int tolua_easeactions_wyEaseBounceOut_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyEaseBounceOut",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyIntervalAction",1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyIntervalAction* wrapped = ((wyIntervalAction*)  tolua_tousertype(tolua_S,2,NULL));
  {
   wyEaseBounceOut* tolua_ret = (wyEaseBounceOut*)  Mtolua_new((wyEaseBounceOut)(wrapped));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyEaseBounceOut");
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

/* method: new_local of class  wyEaseBounceOut */
#ifndef TOLUA_DISABLE_tolua_easeactions_wyEaseBounceOut_new00_local
static int tolua_easeactions_wyEaseBounceOut_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyEaseBounceOut",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyIntervalAction",1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyIntervalAction* wrapped = ((wyIntervalAction*)  tolua_tousertype(tolua_S,2,NULL));
  {
   wyEaseBounceOut* tolua_ret = (wyEaseBounceOut*)  Mtolua_new((wyEaseBounceOut)(wrapped));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyEaseBounceOut");
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

/* method: delete of class  wyEaseBounceOut */
#ifndef TOLUA_DISABLE_tolua_easeactions_wyEaseBounceOut_delete00
static int tolua_easeactions_wyEaseBounceOut_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyEaseBounceOut",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyEaseBounceOut* self = (wyEaseBounceOut*)  tolua_tousertype(tolua_S,1,0);
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

/* method: copy of class  wyEaseBounceOut */
#ifndef TOLUA_DISABLE_tolua_easeactions_wyEaseBounceOut_copy00
static int tolua_easeactions_wyEaseBounceOut_copy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyEaseBounceOut",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyEaseBounceOut* self = (wyEaseBounceOut*)  tolua_tousertype(tolua_S,1,0);
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

/* method: reverse of class  wyEaseBounceOut */
#ifndef TOLUA_DISABLE_tolua_easeactions_wyEaseBounceOut_reverse00
static int tolua_easeactions_wyEaseBounceOut_reverse00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyEaseBounceOut",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyEaseBounceOut* self = (wyEaseBounceOut*)  tolua_tousertype(tolua_S,1,0);
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

/* method: update of class  wyEaseBounceOut */
#ifndef TOLUA_DISABLE_tolua_easeactions_wyEaseBounceOut_update00
static int tolua_easeactions_wyEaseBounceOut_update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyEaseBounceOut",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyEaseBounceOut* self = (wyEaseBounceOut*)  tolua_tousertype(tolua_S,1,0);
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

/* method: new of class  wyEaseElastic */
#ifndef TOLUA_DISABLE_tolua_easeactions_wyEaseElastic_new00
static int tolua_easeactions_wyEaseElastic_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyEaseElastic",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"wyIntervalAction",1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float period = ((float)  tolua_tonumber(tolua_S,2,0));
  wyIntervalAction* wrapped = ((wyIntervalAction*)  tolua_tousertype(tolua_S,3,NULL));
  {
   wyEaseElastic* tolua_ret = (wyEaseElastic*)  Mtolua_new((wyEaseElastic)(period,wrapped));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyEaseElastic");
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

/* method: new_local of class  wyEaseElastic */
#ifndef TOLUA_DISABLE_tolua_easeactions_wyEaseElastic_new00_local
static int tolua_easeactions_wyEaseElastic_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyEaseElastic",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"wyIntervalAction",1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float period = ((float)  tolua_tonumber(tolua_S,2,0));
  wyIntervalAction* wrapped = ((wyIntervalAction*)  tolua_tousertype(tolua_S,3,NULL));
  {
   wyEaseElastic* tolua_ret = (wyEaseElastic*)  Mtolua_new((wyEaseElastic)(period,wrapped));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyEaseElastic");
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

/* method: delete of class  wyEaseElastic */
#ifndef TOLUA_DISABLE_tolua_easeactions_wyEaseElastic_delete00
static int tolua_easeactions_wyEaseElastic_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyEaseElastic",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyEaseElastic* self = (wyEaseElastic*)  tolua_tousertype(tolua_S,1,0);
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

/* method: make of class  wyEaseElasticIn */
#ifndef TOLUA_DISABLE_tolua_easeactions_wyEaseElasticIn_make00
static int tolua_easeactions_wyEaseElasticIn_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyEaseElasticIn",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"wyIntervalAction",1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float period = ((float)  tolua_tonumber(tolua_S,2,0));
  wyIntervalAction* wrapped = ((wyIntervalAction*)  tolua_tousertype(tolua_S,3,NULL));
  {
   wyEaseElasticIn* tolua_ret = (wyEaseElasticIn*)  wyEaseElasticIn::make(period,wrapped);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyEaseElasticIn");
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

/* method: new of class  wyEaseElasticIn */
#ifndef TOLUA_DISABLE_tolua_easeactions_wyEaseElasticIn_new00
static int tolua_easeactions_wyEaseElasticIn_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyEaseElasticIn",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"wyIntervalAction",1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float period = ((float)  tolua_tonumber(tolua_S,2,0));
  wyIntervalAction* wrapped = ((wyIntervalAction*)  tolua_tousertype(tolua_S,3,NULL));
  {
   wyEaseElasticIn* tolua_ret = (wyEaseElasticIn*)  Mtolua_new((wyEaseElasticIn)(period,wrapped));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyEaseElasticIn");
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

/* method: new_local of class  wyEaseElasticIn */
#ifndef TOLUA_DISABLE_tolua_easeactions_wyEaseElasticIn_new00_local
static int tolua_easeactions_wyEaseElasticIn_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyEaseElasticIn",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"wyIntervalAction",1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float period = ((float)  tolua_tonumber(tolua_S,2,0));
  wyIntervalAction* wrapped = ((wyIntervalAction*)  tolua_tousertype(tolua_S,3,NULL));
  {
   wyEaseElasticIn* tolua_ret = (wyEaseElasticIn*)  Mtolua_new((wyEaseElasticIn)(period,wrapped));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyEaseElasticIn");
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

/* method: delete of class  wyEaseElasticIn */
#ifndef TOLUA_DISABLE_tolua_easeactions_wyEaseElasticIn_delete00
static int tolua_easeactions_wyEaseElasticIn_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyEaseElasticIn",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyEaseElasticIn* self = (wyEaseElasticIn*)  tolua_tousertype(tolua_S,1,0);
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

/* method: copy of class  wyEaseElasticIn */
#ifndef TOLUA_DISABLE_tolua_easeactions_wyEaseElasticIn_copy00
static int tolua_easeactions_wyEaseElasticIn_copy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyEaseElasticIn",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyEaseElasticIn* self = (wyEaseElasticIn*)  tolua_tousertype(tolua_S,1,0);
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

/* method: reverse of class  wyEaseElasticIn */
#ifndef TOLUA_DISABLE_tolua_easeactions_wyEaseElasticIn_reverse00
static int tolua_easeactions_wyEaseElasticIn_reverse00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyEaseElasticIn",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyEaseElasticIn* self = (wyEaseElasticIn*)  tolua_tousertype(tolua_S,1,0);
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

/* method: update of class  wyEaseElasticIn */
#ifndef TOLUA_DISABLE_tolua_easeactions_wyEaseElasticIn_update00
static int tolua_easeactions_wyEaseElasticIn_update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyEaseElasticIn",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyEaseElasticIn* self = (wyEaseElasticIn*)  tolua_tousertype(tolua_S,1,0);
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

/* method: make of class  wyEaseElasticInOut */
#ifndef TOLUA_DISABLE_tolua_easeactions_wyEaseElasticInOut_make00
static int tolua_easeactions_wyEaseElasticInOut_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyEaseElasticInOut",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"wyIntervalAction",1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float period = ((float)  tolua_tonumber(tolua_S,2,0));
  wyIntervalAction* wrapped = ((wyIntervalAction*)  tolua_tousertype(tolua_S,3,NULL));
  {
   wyEaseElasticInOut* tolua_ret = (wyEaseElasticInOut*)  wyEaseElasticInOut::make(period,wrapped);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyEaseElasticInOut");
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

/* method: new of class  wyEaseElasticInOut */
#ifndef TOLUA_DISABLE_tolua_easeactions_wyEaseElasticInOut_new00
static int tolua_easeactions_wyEaseElasticInOut_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyEaseElasticInOut",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"wyIntervalAction",1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float period = ((float)  tolua_tonumber(tolua_S,2,0));
  wyIntervalAction* wrapped = ((wyIntervalAction*)  tolua_tousertype(tolua_S,3,NULL));
  {
   wyEaseElasticInOut* tolua_ret = (wyEaseElasticInOut*)  Mtolua_new((wyEaseElasticInOut)(period,wrapped));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyEaseElasticInOut");
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

/* method: new_local of class  wyEaseElasticInOut */
#ifndef TOLUA_DISABLE_tolua_easeactions_wyEaseElasticInOut_new00_local
static int tolua_easeactions_wyEaseElasticInOut_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyEaseElasticInOut",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"wyIntervalAction",1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float period = ((float)  tolua_tonumber(tolua_S,2,0));
  wyIntervalAction* wrapped = ((wyIntervalAction*)  tolua_tousertype(tolua_S,3,NULL));
  {
   wyEaseElasticInOut* tolua_ret = (wyEaseElasticInOut*)  Mtolua_new((wyEaseElasticInOut)(period,wrapped));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyEaseElasticInOut");
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

/* method: delete of class  wyEaseElasticInOut */
#ifndef TOLUA_DISABLE_tolua_easeactions_wyEaseElasticInOut_delete00
static int tolua_easeactions_wyEaseElasticInOut_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyEaseElasticInOut",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyEaseElasticInOut* self = (wyEaseElasticInOut*)  tolua_tousertype(tolua_S,1,0);
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

/* method: copy of class  wyEaseElasticInOut */
#ifndef TOLUA_DISABLE_tolua_easeactions_wyEaseElasticInOut_copy00
static int tolua_easeactions_wyEaseElasticInOut_copy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyEaseElasticInOut",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyEaseElasticInOut* self = (wyEaseElasticInOut*)  tolua_tousertype(tolua_S,1,0);
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

/* method: reverse of class  wyEaseElasticInOut */
#ifndef TOLUA_DISABLE_tolua_easeactions_wyEaseElasticInOut_reverse00
static int tolua_easeactions_wyEaseElasticInOut_reverse00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyEaseElasticInOut",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyEaseElasticInOut* self = (wyEaseElasticInOut*)  tolua_tousertype(tolua_S,1,0);
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

/* method: update of class  wyEaseElasticInOut */
#ifndef TOLUA_DISABLE_tolua_easeactions_wyEaseElasticInOut_update00
static int tolua_easeactions_wyEaseElasticInOut_update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyEaseElasticInOut",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyEaseElasticInOut* self = (wyEaseElasticInOut*)  tolua_tousertype(tolua_S,1,0);
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

/* method: make of class  wyEaseElasticOut */
#ifndef TOLUA_DISABLE_tolua_easeactions_wyEaseElasticOut_make00
static int tolua_easeactions_wyEaseElasticOut_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyEaseElasticOut",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"wyIntervalAction",1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float period = ((float)  tolua_tonumber(tolua_S,2,0));
  wyIntervalAction* wrapped = ((wyIntervalAction*)  tolua_tousertype(tolua_S,3,NULL));
  {
   wyEaseElasticOut* tolua_ret = (wyEaseElasticOut*)  wyEaseElasticOut::make(period,wrapped);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyEaseElasticOut");
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

/* method: new of class  wyEaseElasticOut */
#ifndef TOLUA_DISABLE_tolua_easeactions_wyEaseElasticOut_new00
static int tolua_easeactions_wyEaseElasticOut_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyEaseElasticOut",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"wyIntervalAction",1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float period = ((float)  tolua_tonumber(tolua_S,2,0));
  wyIntervalAction* wrapped = ((wyIntervalAction*)  tolua_tousertype(tolua_S,3,NULL));
  {
   wyEaseElasticOut* tolua_ret = (wyEaseElasticOut*)  Mtolua_new((wyEaseElasticOut)(period,wrapped));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyEaseElasticOut");
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

/* method: new_local of class  wyEaseElasticOut */
#ifndef TOLUA_DISABLE_tolua_easeactions_wyEaseElasticOut_new00_local
static int tolua_easeactions_wyEaseElasticOut_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyEaseElasticOut",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"wyIntervalAction",1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float period = ((float)  tolua_tonumber(tolua_S,2,0));
  wyIntervalAction* wrapped = ((wyIntervalAction*)  tolua_tousertype(tolua_S,3,NULL));
  {
   wyEaseElasticOut* tolua_ret = (wyEaseElasticOut*)  Mtolua_new((wyEaseElasticOut)(period,wrapped));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyEaseElasticOut");
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

/* method: delete of class  wyEaseElasticOut */
#ifndef TOLUA_DISABLE_tolua_easeactions_wyEaseElasticOut_delete00
static int tolua_easeactions_wyEaseElasticOut_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyEaseElasticOut",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyEaseElasticOut* self = (wyEaseElasticOut*)  tolua_tousertype(tolua_S,1,0);
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

/* method: copy of class  wyEaseElasticOut */
#ifndef TOLUA_DISABLE_tolua_easeactions_wyEaseElasticOut_copy00
static int tolua_easeactions_wyEaseElasticOut_copy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyEaseElasticOut",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyEaseElasticOut* self = (wyEaseElasticOut*)  tolua_tousertype(tolua_S,1,0);
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

/* method: reverse of class  wyEaseElasticOut */
#ifndef TOLUA_DISABLE_tolua_easeactions_wyEaseElasticOut_reverse00
static int tolua_easeactions_wyEaseElasticOut_reverse00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyEaseElasticOut",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyEaseElasticOut* self = (wyEaseElasticOut*)  tolua_tousertype(tolua_S,1,0);
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

/* method: update of class  wyEaseElasticOut */
#ifndef TOLUA_DISABLE_tolua_easeactions_wyEaseElasticOut_update00
static int tolua_easeactions_wyEaseElasticOut_update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyEaseElasticOut",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyEaseElasticOut* self = (wyEaseElasticOut*)  tolua_tousertype(tolua_S,1,0);
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

/* method: make of class  wyEaseExponentialIn */
#ifndef TOLUA_DISABLE_tolua_easeactions_wyEaseExponentialIn_make00
static int tolua_easeactions_wyEaseExponentialIn_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyEaseExponentialIn",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyIntervalAction",1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyIntervalAction* wrapped = ((wyIntervalAction*)  tolua_tousertype(tolua_S,2,NULL));
  {
   wyEaseExponentialIn* tolua_ret = (wyEaseExponentialIn*)  wyEaseExponentialIn::make(wrapped);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyEaseExponentialIn");
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

/* method: new of class  wyEaseExponentialIn */
#ifndef TOLUA_DISABLE_tolua_easeactions_wyEaseExponentialIn_new00
static int tolua_easeactions_wyEaseExponentialIn_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyEaseExponentialIn",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyIntervalAction",1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyIntervalAction* wrapped = ((wyIntervalAction*)  tolua_tousertype(tolua_S,2,NULL));
  {
   wyEaseExponentialIn* tolua_ret = (wyEaseExponentialIn*)  Mtolua_new((wyEaseExponentialIn)(wrapped));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyEaseExponentialIn");
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

/* method: new_local of class  wyEaseExponentialIn */
#ifndef TOLUA_DISABLE_tolua_easeactions_wyEaseExponentialIn_new00_local
static int tolua_easeactions_wyEaseExponentialIn_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyEaseExponentialIn",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyIntervalAction",1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyIntervalAction* wrapped = ((wyIntervalAction*)  tolua_tousertype(tolua_S,2,NULL));
  {
   wyEaseExponentialIn* tolua_ret = (wyEaseExponentialIn*)  Mtolua_new((wyEaseExponentialIn)(wrapped));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyEaseExponentialIn");
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

/* method: delete of class  wyEaseExponentialIn */
#ifndef TOLUA_DISABLE_tolua_easeactions_wyEaseExponentialIn_delete00
static int tolua_easeactions_wyEaseExponentialIn_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyEaseExponentialIn",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyEaseExponentialIn* self = (wyEaseExponentialIn*)  tolua_tousertype(tolua_S,1,0);
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

/* method: copy of class  wyEaseExponentialIn */
#ifndef TOLUA_DISABLE_tolua_easeactions_wyEaseExponentialIn_copy00
static int tolua_easeactions_wyEaseExponentialIn_copy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyEaseExponentialIn",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyEaseExponentialIn* self = (wyEaseExponentialIn*)  tolua_tousertype(tolua_S,1,0);
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

/* method: reverse of class  wyEaseExponentialIn */
#ifndef TOLUA_DISABLE_tolua_easeactions_wyEaseExponentialIn_reverse00
static int tolua_easeactions_wyEaseExponentialIn_reverse00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyEaseExponentialIn",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyEaseExponentialIn* self = (wyEaseExponentialIn*)  tolua_tousertype(tolua_S,1,0);
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

/* method: update of class  wyEaseExponentialIn */
#ifndef TOLUA_DISABLE_tolua_easeactions_wyEaseExponentialIn_update00
static int tolua_easeactions_wyEaseExponentialIn_update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyEaseExponentialIn",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyEaseExponentialIn* self = (wyEaseExponentialIn*)  tolua_tousertype(tolua_S,1,0);
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

/* method: make of class  wyEaseExponentialInOut */
#ifndef TOLUA_DISABLE_tolua_easeactions_wyEaseExponentialInOut_make00
static int tolua_easeactions_wyEaseExponentialInOut_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyEaseExponentialInOut",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyIntervalAction",1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyIntervalAction* wrapped = ((wyIntervalAction*)  tolua_tousertype(tolua_S,2,NULL));
  {
   wyEaseExponentialInOut* tolua_ret = (wyEaseExponentialInOut*)  wyEaseExponentialInOut::make(wrapped);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyEaseExponentialInOut");
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

/* method: new of class  wyEaseExponentialInOut */
#ifndef TOLUA_DISABLE_tolua_easeactions_wyEaseExponentialInOut_new00
static int tolua_easeactions_wyEaseExponentialInOut_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyEaseExponentialInOut",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyIntervalAction",1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyIntervalAction* wrapped = ((wyIntervalAction*)  tolua_tousertype(tolua_S,2,NULL));
  {
   wyEaseExponentialInOut* tolua_ret = (wyEaseExponentialInOut*)  Mtolua_new((wyEaseExponentialInOut)(wrapped));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyEaseExponentialInOut");
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

/* method: new_local of class  wyEaseExponentialInOut */
#ifndef TOLUA_DISABLE_tolua_easeactions_wyEaseExponentialInOut_new00_local
static int tolua_easeactions_wyEaseExponentialInOut_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyEaseExponentialInOut",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyIntervalAction",1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyIntervalAction* wrapped = ((wyIntervalAction*)  tolua_tousertype(tolua_S,2,NULL));
  {
   wyEaseExponentialInOut* tolua_ret = (wyEaseExponentialInOut*)  Mtolua_new((wyEaseExponentialInOut)(wrapped));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyEaseExponentialInOut");
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

/* method: delete of class  wyEaseExponentialInOut */
#ifndef TOLUA_DISABLE_tolua_easeactions_wyEaseExponentialInOut_delete00
static int tolua_easeactions_wyEaseExponentialInOut_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyEaseExponentialInOut",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyEaseExponentialInOut* self = (wyEaseExponentialInOut*)  tolua_tousertype(tolua_S,1,0);
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

/* method: copy of class  wyEaseExponentialInOut */
#ifndef TOLUA_DISABLE_tolua_easeactions_wyEaseExponentialInOut_copy00
static int tolua_easeactions_wyEaseExponentialInOut_copy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyEaseExponentialInOut",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyEaseExponentialInOut* self = (wyEaseExponentialInOut*)  tolua_tousertype(tolua_S,1,0);
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

/* method: reverse of class  wyEaseExponentialInOut */
#ifndef TOLUA_DISABLE_tolua_easeactions_wyEaseExponentialInOut_reverse00
static int tolua_easeactions_wyEaseExponentialInOut_reverse00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyEaseExponentialInOut",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyEaseExponentialInOut* self = (wyEaseExponentialInOut*)  tolua_tousertype(tolua_S,1,0);
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

/* method: update of class  wyEaseExponentialInOut */
#ifndef TOLUA_DISABLE_tolua_easeactions_wyEaseExponentialInOut_update00
static int tolua_easeactions_wyEaseExponentialInOut_update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyEaseExponentialInOut",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyEaseExponentialInOut* self = (wyEaseExponentialInOut*)  tolua_tousertype(tolua_S,1,0);
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

/* method: make of class  wyEaseExponentialOut */
#ifndef TOLUA_DISABLE_tolua_easeactions_wyEaseExponentialOut_make00
static int tolua_easeactions_wyEaseExponentialOut_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyEaseExponentialOut",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyIntervalAction",1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyIntervalAction* wrapped = ((wyIntervalAction*)  tolua_tousertype(tolua_S,2,NULL));
  {
   wyEaseExponentialOut* tolua_ret = (wyEaseExponentialOut*)  wyEaseExponentialOut::make(wrapped);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyEaseExponentialOut");
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

/* method: new of class  wyEaseExponentialOut */
#ifndef TOLUA_DISABLE_tolua_easeactions_wyEaseExponentialOut_new00
static int tolua_easeactions_wyEaseExponentialOut_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyEaseExponentialOut",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyIntervalAction",1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyIntervalAction* wrapped = ((wyIntervalAction*)  tolua_tousertype(tolua_S,2,NULL));
  {
   wyEaseExponentialOut* tolua_ret = (wyEaseExponentialOut*)  Mtolua_new((wyEaseExponentialOut)(wrapped));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyEaseExponentialOut");
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

/* method: new_local of class  wyEaseExponentialOut */
#ifndef TOLUA_DISABLE_tolua_easeactions_wyEaseExponentialOut_new00_local
static int tolua_easeactions_wyEaseExponentialOut_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyEaseExponentialOut",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyIntervalAction",1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyIntervalAction* wrapped = ((wyIntervalAction*)  tolua_tousertype(tolua_S,2,NULL));
  {
   wyEaseExponentialOut* tolua_ret = (wyEaseExponentialOut*)  Mtolua_new((wyEaseExponentialOut)(wrapped));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyEaseExponentialOut");
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

/* method: delete of class  wyEaseExponentialOut */
#ifndef TOLUA_DISABLE_tolua_easeactions_wyEaseExponentialOut_delete00
static int tolua_easeactions_wyEaseExponentialOut_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyEaseExponentialOut",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyEaseExponentialOut* self = (wyEaseExponentialOut*)  tolua_tousertype(tolua_S,1,0);
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

/* method: copy of class  wyEaseExponentialOut */
#ifndef TOLUA_DISABLE_tolua_easeactions_wyEaseExponentialOut_copy00
static int tolua_easeactions_wyEaseExponentialOut_copy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyEaseExponentialOut",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyEaseExponentialOut* self = (wyEaseExponentialOut*)  tolua_tousertype(tolua_S,1,0);
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

/* method: reverse of class  wyEaseExponentialOut */
#ifndef TOLUA_DISABLE_tolua_easeactions_wyEaseExponentialOut_reverse00
static int tolua_easeactions_wyEaseExponentialOut_reverse00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyEaseExponentialOut",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyEaseExponentialOut* self = (wyEaseExponentialOut*)  tolua_tousertype(tolua_S,1,0);
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

/* method: update of class  wyEaseExponentialOut */
#ifndef TOLUA_DISABLE_tolua_easeactions_wyEaseExponentialOut_update00
static int tolua_easeactions_wyEaseExponentialOut_update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyEaseExponentialOut",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyEaseExponentialOut* self = (wyEaseExponentialOut*)  tolua_tousertype(tolua_S,1,0);
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

/* method: make of class  wyEaseIn */
#ifndef TOLUA_DISABLE_tolua_easeactions_wyEaseIn_make00
static int tolua_easeactions_wyEaseIn_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyEaseIn",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"wyIntervalAction",1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float rate = ((float)  tolua_tonumber(tolua_S,2,0));
  wyIntervalAction* wrapped = ((wyIntervalAction*)  tolua_tousertype(tolua_S,3,NULL));
  {
   wyEaseIn* tolua_ret = (wyEaseIn*)  wyEaseIn::make(rate,wrapped);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyEaseIn");
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

/* method: new of class  wyEaseIn */
#ifndef TOLUA_DISABLE_tolua_easeactions_wyEaseIn_new00
static int tolua_easeactions_wyEaseIn_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyEaseIn",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"wyIntervalAction",1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float rate = ((float)  tolua_tonumber(tolua_S,2,0));
  wyIntervalAction* wrapped = ((wyIntervalAction*)  tolua_tousertype(tolua_S,3,NULL));
  {
   wyEaseIn* tolua_ret = (wyEaseIn*)  Mtolua_new((wyEaseIn)(rate,wrapped));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyEaseIn");
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

/* method: new_local of class  wyEaseIn */
#ifndef TOLUA_DISABLE_tolua_easeactions_wyEaseIn_new00_local
static int tolua_easeactions_wyEaseIn_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyEaseIn",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"wyIntervalAction",1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float rate = ((float)  tolua_tonumber(tolua_S,2,0));
  wyIntervalAction* wrapped = ((wyIntervalAction*)  tolua_tousertype(tolua_S,3,NULL));
  {
   wyEaseIn* tolua_ret = (wyEaseIn*)  Mtolua_new((wyEaseIn)(rate,wrapped));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyEaseIn");
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

/* method: delete of class  wyEaseIn */
#ifndef TOLUA_DISABLE_tolua_easeactions_wyEaseIn_delete00
static int tolua_easeactions_wyEaseIn_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyEaseIn",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyEaseIn* self = (wyEaseIn*)  tolua_tousertype(tolua_S,1,0);
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

/* method: copy of class  wyEaseIn */
#ifndef TOLUA_DISABLE_tolua_easeactions_wyEaseIn_copy00
static int tolua_easeactions_wyEaseIn_copy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyEaseIn",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyEaseIn* self = (wyEaseIn*)  tolua_tousertype(tolua_S,1,0);
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

/* method: reverse of class  wyEaseIn */
#ifndef TOLUA_DISABLE_tolua_easeactions_wyEaseIn_reverse00
static int tolua_easeactions_wyEaseIn_reverse00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyEaseIn",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyEaseIn* self = (wyEaseIn*)  tolua_tousertype(tolua_S,1,0);
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

/* method: update of class  wyEaseIn */
#ifndef TOLUA_DISABLE_tolua_easeactions_wyEaseIn_update00
static int tolua_easeactions_wyEaseIn_update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyEaseIn",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyEaseIn* self = (wyEaseIn*)  tolua_tousertype(tolua_S,1,0);
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

/* method: make of class  wyEaseInOut */
#ifndef TOLUA_DISABLE_tolua_easeactions_wyEaseInOut_make00
static int tolua_easeactions_wyEaseInOut_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyEaseInOut",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"wyIntervalAction",1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float rate = ((float)  tolua_tonumber(tolua_S,2,0));
  wyIntervalAction* wrapped = ((wyIntervalAction*)  tolua_tousertype(tolua_S,3,NULL));
  {
   wyEaseInOut* tolua_ret = (wyEaseInOut*)  wyEaseInOut::make(rate,wrapped);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyEaseInOut");
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

/* method: new of class  wyEaseInOut */
#ifndef TOLUA_DISABLE_tolua_easeactions_wyEaseInOut_new00
static int tolua_easeactions_wyEaseInOut_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyEaseInOut",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"wyIntervalAction",1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float rate = ((float)  tolua_tonumber(tolua_S,2,0));
  wyIntervalAction* wrapped = ((wyIntervalAction*)  tolua_tousertype(tolua_S,3,NULL));
  {
   wyEaseInOut* tolua_ret = (wyEaseInOut*)  Mtolua_new((wyEaseInOut)(rate,wrapped));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyEaseInOut");
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

/* method: new_local of class  wyEaseInOut */
#ifndef TOLUA_DISABLE_tolua_easeactions_wyEaseInOut_new00_local
static int tolua_easeactions_wyEaseInOut_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyEaseInOut",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"wyIntervalAction",1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float rate = ((float)  tolua_tonumber(tolua_S,2,0));
  wyIntervalAction* wrapped = ((wyIntervalAction*)  tolua_tousertype(tolua_S,3,NULL));
  {
   wyEaseInOut* tolua_ret = (wyEaseInOut*)  Mtolua_new((wyEaseInOut)(rate,wrapped));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyEaseInOut");
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

/* method: delete of class  wyEaseInOut */
#ifndef TOLUA_DISABLE_tolua_easeactions_wyEaseInOut_delete00
static int tolua_easeactions_wyEaseInOut_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyEaseInOut",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyEaseInOut* self = (wyEaseInOut*)  tolua_tousertype(tolua_S,1,0);
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

/* method: copy of class  wyEaseInOut */
#ifndef TOLUA_DISABLE_tolua_easeactions_wyEaseInOut_copy00
static int tolua_easeactions_wyEaseInOut_copy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyEaseInOut",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyEaseInOut* self = (wyEaseInOut*)  tolua_tousertype(tolua_S,1,0);
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

/* method: reverse of class  wyEaseInOut */
#ifndef TOLUA_DISABLE_tolua_easeactions_wyEaseInOut_reverse00
static int tolua_easeactions_wyEaseInOut_reverse00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyEaseInOut",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyEaseInOut* self = (wyEaseInOut*)  tolua_tousertype(tolua_S,1,0);
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

/* method: update of class  wyEaseInOut */
#ifndef TOLUA_DISABLE_tolua_easeactions_wyEaseInOut_update00
static int tolua_easeactions_wyEaseInOut_update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyEaseInOut",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyEaseInOut* self = (wyEaseInOut*)  tolua_tousertype(tolua_S,1,0);
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

/* method: make of class  wyEaseOut */
#ifndef TOLUA_DISABLE_tolua_easeactions_wyEaseOut_make00
static int tolua_easeactions_wyEaseOut_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyEaseOut",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"wyIntervalAction",1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float rate = ((float)  tolua_tonumber(tolua_S,2,0));
  wyIntervalAction* wrapped = ((wyIntervalAction*)  tolua_tousertype(tolua_S,3,NULL));
  {
   wyEaseOut* tolua_ret = (wyEaseOut*)  wyEaseOut::make(rate,wrapped);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyEaseOut");
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

/* method: new of class  wyEaseOut */
#ifndef TOLUA_DISABLE_tolua_easeactions_wyEaseOut_new00
static int tolua_easeactions_wyEaseOut_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyEaseOut",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"wyIntervalAction",1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float rate = ((float)  tolua_tonumber(tolua_S,2,0));
  wyIntervalAction* wrapped = ((wyIntervalAction*)  tolua_tousertype(tolua_S,3,NULL));
  {
   wyEaseOut* tolua_ret = (wyEaseOut*)  Mtolua_new((wyEaseOut)(rate,wrapped));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyEaseOut");
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

/* method: new_local of class  wyEaseOut */
#ifndef TOLUA_DISABLE_tolua_easeactions_wyEaseOut_new00_local
static int tolua_easeactions_wyEaseOut_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyEaseOut",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"wyIntervalAction",1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float rate = ((float)  tolua_tonumber(tolua_S,2,0));
  wyIntervalAction* wrapped = ((wyIntervalAction*)  tolua_tousertype(tolua_S,3,NULL));
  {
   wyEaseOut* tolua_ret = (wyEaseOut*)  Mtolua_new((wyEaseOut)(rate,wrapped));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyEaseOut");
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

/* method: delete of class  wyEaseOut */
#ifndef TOLUA_DISABLE_tolua_easeactions_wyEaseOut_delete00
static int tolua_easeactions_wyEaseOut_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyEaseOut",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyEaseOut* self = (wyEaseOut*)  tolua_tousertype(tolua_S,1,0);
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

/* method: copy of class  wyEaseOut */
#ifndef TOLUA_DISABLE_tolua_easeactions_wyEaseOut_copy00
static int tolua_easeactions_wyEaseOut_copy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyEaseOut",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyEaseOut* self = (wyEaseOut*)  tolua_tousertype(tolua_S,1,0);
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

/* method: reverse of class  wyEaseOut */
#ifndef TOLUA_DISABLE_tolua_easeactions_wyEaseOut_reverse00
static int tolua_easeactions_wyEaseOut_reverse00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyEaseOut",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyEaseOut* self = (wyEaseOut*)  tolua_tousertype(tolua_S,1,0);
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

/* method: update of class  wyEaseOut */
#ifndef TOLUA_DISABLE_tolua_easeactions_wyEaseOut_update00
static int tolua_easeactions_wyEaseOut_update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyEaseOut",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyEaseOut* self = (wyEaseOut*)  tolua_tousertype(tolua_S,1,0);
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

/* method: new of class  wyEaseRateAction */
#ifndef TOLUA_DISABLE_tolua_easeactions_wyEaseRateAction_new00
static int tolua_easeactions_wyEaseRateAction_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyEaseRateAction",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"wyIntervalAction",1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float rate = ((float)  tolua_tonumber(tolua_S,2,0));
  wyIntervalAction* wrapped = ((wyIntervalAction*)  tolua_tousertype(tolua_S,3,NULL));
  {
   wyEaseRateAction* tolua_ret = (wyEaseRateAction*)  Mtolua_new((wyEaseRateAction)(rate,wrapped));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyEaseRateAction");
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

/* method: new_local of class  wyEaseRateAction */
#ifndef TOLUA_DISABLE_tolua_easeactions_wyEaseRateAction_new00_local
static int tolua_easeactions_wyEaseRateAction_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyEaseRateAction",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"wyIntervalAction",1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float rate = ((float)  tolua_tonumber(tolua_S,2,0));
  wyIntervalAction* wrapped = ((wyIntervalAction*)  tolua_tousertype(tolua_S,3,NULL));
  {
   wyEaseRateAction* tolua_ret = (wyEaseRateAction*)  Mtolua_new((wyEaseRateAction)(rate,wrapped));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyEaseRateAction");
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

/* method: delete of class  wyEaseRateAction */
#ifndef TOLUA_DISABLE_tolua_easeactions_wyEaseRateAction_delete00
static int tolua_easeactions_wyEaseRateAction_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyEaseRateAction",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyEaseRateAction* self = (wyEaseRateAction*)  tolua_tousertype(tolua_S,1,0);
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

/* method: make of class  wyEaseSineIn */
#ifndef TOLUA_DISABLE_tolua_easeactions_wyEaseSineIn_make00
static int tolua_easeactions_wyEaseSineIn_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyEaseSineIn",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyIntervalAction",1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyIntervalAction* wrapped = ((wyIntervalAction*)  tolua_tousertype(tolua_S,2,NULL));
  {
   wyEaseSineIn* tolua_ret = (wyEaseSineIn*)  wyEaseSineIn::make(wrapped);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyEaseSineIn");
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

/* method: new of class  wyEaseSineIn */
#ifndef TOLUA_DISABLE_tolua_easeactions_wyEaseSineIn_new00
static int tolua_easeactions_wyEaseSineIn_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyEaseSineIn",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyIntervalAction",1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyIntervalAction* wrapped = ((wyIntervalAction*)  tolua_tousertype(tolua_S,2,NULL));
  {
   wyEaseSineIn* tolua_ret = (wyEaseSineIn*)  Mtolua_new((wyEaseSineIn)(wrapped));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyEaseSineIn");
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

/* method: new_local of class  wyEaseSineIn */
#ifndef TOLUA_DISABLE_tolua_easeactions_wyEaseSineIn_new00_local
static int tolua_easeactions_wyEaseSineIn_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyEaseSineIn",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyIntervalAction",1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyIntervalAction* wrapped = ((wyIntervalAction*)  tolua_tousertype(tolua_S,2,NULL));
  {
   wyEaseSineIn* tolua_ret = (wyEaseSineIn*)  Mtolua_new((wyEaseSineIn)(wrapped));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyEaseSineIn");
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

/* method: delete of class  wyEaseSineIn */
#ifndef TOLUA_DISABLE_tolua_easeactions_wyEaseSineIn_delete00
static int tolua_easeactions_wyEaseSineIn_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyEaseSineIn",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyEaseSineIn* self = (wyEaseSineIn*)  tolua_tousertype(tolua_S,1,0);
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

/* method: copy of class  wyEaseSineIn */
#ifndef TOLUA_DISABLE_tolua_easeactions_wyEaseSineIn_copy00
static int tolua_easeactions_wyEaseSineIn_copy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyEaseSineIn",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyEaseSineIn* self = (wyEaseSineIn*)  tolua_tousertype(tolua_S,1,0);
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

/* method: reverse of class  wyEaseSineIn */
#ifndef TOLUA_DISABLE_tolua_easeactions_wyEaseSineIn_reverse00
static int tolua_easeactions_wyEaseSineIn_reverse00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyEaseSineIn",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyEaseSineIn* self = (wyEaseSineIn*)  tolua_tousertype(tolua_S,1,0);
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

/* method: update of class  wyEaseSineIn */
#ifndef TOLUA_DISABLE_tolua_easeactions_wyEaseSineIn_update00
static int tolua_easeactions_wyEaseSineIn_update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyEaseSineIn",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyEaseSineIn* self = (wyEaseSineIn*)  tolua_tousertype(tolua_S,1,0);
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

/* method: make of class  wyEaseSineInOut */
#ifndef TOLUA_DISABLE_tolua_easeactions_wyEaseSineInOut_make00
static int tolua_easeactions_wyEaseSineInOut_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyEaseSineInOut",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyIntervalAction",1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyIntervalAction* wrapped = ((wyIntervalAction*)  tolua_tousertype(tolua_S,2,NULL));
  {
   wyEaseSineInOut* tolua_ret = (wyEaseSineInOut*)  wyEaseSineInOut::make(wrapped);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyEaseSineInOut");
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

/* method: new of class  wyEaseSineInOut */
#ifndef TOLUA_DISABLE_tolua_easeactions_wyEaseSineInOut_new00
static int tolua_easeactions_wyEaseSineInOut_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyEaseSineInOut",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyIntervalAction",1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyIntervalAction* wrapped = ((wyIntervalAction*)  tolua_tousertype(tolua_S,2,NULL));
  {
   wyEaseSineInOut* tolua_ret = (wyEaseSineInOut*)  Mtolua_new((wyEaseSineInOut)(wrapped));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyEaseSineInOut");
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

/* method: new_local of class  wyEaseSineInOut */
#ifndef TOLUA_DISABLE_tolua_easeactions_wyEaseSineInOut_new00_local
static int tolua_easeactions_wyEaseSineInOut_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyEaseSineInOut",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyIntervalAction",1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyIntervalAction* wrapped = ((wyIntervalAction*)  tolua_tousertype(tolua_S,2,NULL));
  {
   wyEaseSineInOut* tolua_ret = (wyEaseSineInOut*)  Mtolua_new((wyEaseSineInOut)(wrapped));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyEaseSineInOut");
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

/* method: delete of class  wyEaseSineInOut */
#ifndef TOLUA_DISABLE_tolua_easeactions_wyEaseSineInOut_delete00
static int tolua_easeactions_wyEaseSineInOut_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyEaseSineInOut",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyEaseSineInOut* self = (wyEaseSineInOut*)  tolua_tousertype(tolua_S,1,0);
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

/* method: copy of class  wyEaseSineInOut */
#ifndef TOLUA_DISABLE_tolua_easeactions_wyEaseSineInOut_copy00
static int tolua_easeactions_wyEaseSineInOut_copy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyEaseSineInOut",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyEaseSineInOut* self = (wyEaseSineInOut*)  tolua_tousertype(tolua_S,1,0);
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

/* method: reverse of class  wyEaseSineInOut */
#ifndef TOLUA_DISABLE_tolua_easeactions_wyEaseSineInOut_reverse00
static int tolua_easeactions_wyEaseSineInOut_reverse00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyEaseSineInOut",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyEaseSineInOut* self = (wyEaseSineInOut*)  tolua_tousertype(tolua_S,1,0);
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

/* method: update of class  wyEaseSineInOut */
#ifndef TOLUA_DISABLE_tolua_easeactions_wyEaseSineInOut_update00
static int tolua_easeactions_wyEaseSineInOut_update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyEaseSineInOut",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyEaseSineInOut* self = (wyEaseSineInOut*)  tolua_tousertype(tolua_S,1,0);
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

/* method: make of class  wyEaseSineOut */
#ifndef TOLUA_DISABLE_tolua_easeactions_wyEaseSineOut_make00
static int tolua_easeactions_wyEaseSineOut_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyEaseSineOut",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyIntervalAction",1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyIntervalAction* wrapped = ((wyIntervalAction*)  tolua_tousertype(tolua_S,2,NULL));
  {
   wyEaseSineOut* tolua_ret = (wyEaseSineOut*)  wyEaseSineOut::make(wrapped);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyEaseSineOut");
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

/* method: new of class  wyEaseSineOut */
#ifndef TOLUA_DISABLE_tolua_easeactions_wyEaseSineOut_new00
static int tolua_easeactions_wyEaseSineOut_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyEaseSineOut",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyIntervalAction",1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyIntervalAction* wrapped = ((wyIntervalAction*)  tolua_tousertype(tolua_S,2,NULL));
  {
   wyEaseSineOut* tolua_ret = (wyEaseSineOut*)  Mtolua_new((wyEaseSineOut)(wrapped));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyEaseSineOut");
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

/* method: new_local of class  wyEaseSineOut */
#ifndef TOLUA_DISABLE_tolua_easeactions_wyEaseSineOut_new00_local
static int tolua_easeactions_wyEaseSineOut_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyEaseSineOut",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyIntervalAction",1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyIntervalAction* wrapped = ((wyIntervalAction*)  tolua_tousertype(tolua_S,2,NULL));
  {
   wyEaseSineOut* tolua_ret = (wyEaseSineOut*)  Mtolua_new((wyEaseSineOut)(wrapped));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyEaseSineOut");
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

/* method: delete of class  wyEaseSineOut */
#ifndef TOLUA_DISABLE_tolua_easeactions_wyEaseSineOut_delete00
static int tolua_easeactions_wyEaseSineOut_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyEaseSineOut",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyEaseSineOut* self = (wyEaseSineOut*)  tolua_tousertype(tolua_S,1,0);
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

/* method: copy of class  wyEaseSineOut */
#ifndef TOLUA_DISABLE_tolua_easeactions_wyEaseSineOut_copy00
static int tolua_easeactions_wyEaseSineOut_copy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyEaseSineOut",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyEaseSineOut* self = (wyEaseSineOut*)  tolua_tousertype(tolua_S,1,0);
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

/* method: reverse of class  wyEaseSineOut */
#ifndef TOLUA_DISABLE_tolua_easeactions_wyEaseSineOut_reverse00
static int tolua_easeactions_wyEaseSineOut_reverse00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyEaseSineOut",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyEaseSineOut* self = (wyEaseSineOut*)  tolua_tousertype(tolua_S,1,0);
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

/* method: update of class  wyEaseSineOut */
#ifndef TOLUA_DISABLE_tolua_easeactions_wyEaseSineOut_update00
static int tolua_easeactions_wyEaseSineOut_update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyEaseSineOut",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyEaseSineOut* self = (wyEaseSineOut*)  tolua_tousertype(tolua_S,1,0);
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
TOLUA_API int tolua_easeactions_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyEaseAction","wyEaseAction","wyIntervalAction",tolua_collect_wyEaseAction);
  #else
  tolua_cclass(tolua_S,"wyEaseAction","wyEaseAction","wyIntervalAction",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyEaseAction");
   tolua_function(tolua_S,"new",tolua_easeactions_wyEaseAction_new00);
   tolua_function(tolua_S,"new_local",tolua_easeactions_wyEaseAction_new00_local);
   tolua_function(tolua_S,".call",tolua_easeactions_wyEaseAction_new00_local);
   tolua_function(tolua_S,"delete",tolua_easeactions_wyEaseAction_delete00);
   tolua_function(tolua_S,"start",tolua_easeactions_wyEaseAction_start00);
   tolua_function(tolua_S,"stop",tolua_easeactions_wyEaseAction_stop00);
   tolua_function(tolua_S,"setWrappedAction",tolua_easeactions_wyEaseAction_setWrappedAction00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyEaseBackIn","wyEaseBackIn","wyEaseAction",tolua_collect_wyEaseBackIn);
  #else
  tolua_cclass(tolua_S,"wyEaseBackIn","wyEaseBackIn","wyEaseAction",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyEaseBackIn");
   tolua_function(tolua_S,"make",tolua_easeactions_wyEaseBackIn_make00);
   tolua_function(tolua_S,"new",tolua_easeactions_wyEaseBackIn_new00);
   tolua_function(tolua_S,"new_local",tolua_easeactions_wyEaseBackIn_new00_local);
   tolua_function(tolua_S,".call",tolua_easeactions_wyEaseBackIn_new00_local);
   tolua_function(tolua_S,"delete",tolua_easeactions_wyEaseBackIn_delete00);
   tolua_function(tolua_S,"copy",tolua_easeactions_wyEaseBackIn_copy00);
   tolua_function(tolua_S,"reverse",tolua_easeactions_wyEaseBackIn_reverse00);
   tolua_function(tolua_S,"update",tolua_easeactions_wyEaseBackIn_update00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyEaseBackInOut","wyEaseBackInOut","wyEaseAction",tolua_collect_wyEaseBackInOut);
  #else
  tolua_cclass(tolua_S,"wyEaseBackInOut","wyEaseBackInOut","wyEaseAction",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyEaseBackInOut");
   tolua_function(tolua_S,"make",tolua_easeactions_wyEaseBackInOut_make00);
   tolua_function(tolua_S,"new",tolua_easeactions_wyEaseBackInOut_new00);
   tolua_function(tolua_S,"new_local",tolua_easeactions_wyEaseBackInOut_new00_local);
   tolua_function(tolua_S,".call",tolua_easeactions_wyEaseBackInOut_new00_local);
   tolua_function(tolua_S,"delete",tolua_easeactions_wyEaseBackInOut_delete00);
   tolua_function(tolua_S,"copy",tolua_easeactions_wyEaseBackInOut_copy00);
   tolua_function(tolua_S,"reverse",tolua_easeactions_wyEaseBackInOut_reverse00);
   tolua_function(tolua_S,"update",tolua_easeactions_wyEaseBackInOut_update00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyEaseBackOut","wyEaseBackOut","wyEaseAction",tolua_collect_wyEaseBackOut);
  #else
  tolua_cclass(tolua_S,"wyEaseBackOut","wyEaseBackOut","wyEaseAction",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyEaseBackOut");
   tolua_function(tolua_S,"make",tolua_easeactions_wyEaseBackOut_make00);
   tolua_function(tolua_S,"new",tolua_easeactions_wyEaseBackOut_new00);
   tolua_function(tolua_S,"new_local",tolua_easeactions_wyEaseBackOut_new00_local);
   tolua_function(tolua_S,".call",tolua_easeactions_wyEaseBackOut_new00_local);
   tolua_function(tolua_S,"delete",tolua_easeactions_wyEaseBackOut_delete00);
   tolua_function(tolua_S,"copy",tolua_easeactions_wyEaseBackOut_copy00);
   tolua_function(tolua_S,"reverse",tolua_easeactions_wyEaseBackOut_reverse00);
   tolua_function(tolua_S,"update",tolua_easeactions_wyEaseBackOut_update00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyEaseBounce","wyEaseBounce","wyEaseAction",tolua_collect_wyEaseBounce);
  #else
  tolua_cclass(tolua_S,"wyEaseBounce","wyEaseBounce","wyEaseAction",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyEaseBounce");
   tolua_function(tolua_S,"new",tolua_easeactions_wyEaseBounce_new00);
   tolua_function(tolua_S,"new_local",tolua_easeactions_wyEaseBounce_new00_local);
   tolua_function(tolua_S,".call",tolua_easeactions_wyEaseBounce_new00_local);
   tolua_function(tolua_S,"delete",tolua_easeactions_wyEaseBounce_delete00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyEaseBounceIn","wyEaseBounceIn","wyEaseBounce",tolua_collect_wyEaseBounceIn);
  #else
  tolua_cclass(tolua_S,"wyEaseBounceIn","wyEaseBounceIn","wyEaseBounce",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyEaseBounceIn");
   tolua_function(tolua_S,"make",tolua_easeactions_wyEaseBounceIn_make00);
   tolua_function(tolua_S,"new",tolua_easeactions_wyEaseBounceIn_new00);
   tolua_function(tolua_S,"new_local",tolua_easeactions_wyEaseBounceIn_new00_local);
   tolua_function(tolua_S,".call",tolua_easeactions_wyEaseBounceIn_new00_local);
   tolua_function(tolua_S,"delete",tolua_easeactions_wyEaseBounceIn_delete00);
   tolua_function(tolua_S,"copy",tolua_easeactions_wyEaseBounceIn_copy00);
   tolua_function(tolua_S,"reverse",tolua_easeactions_wyEaseBounceIn_reverse00);
   tolua_function(tolua_S,"update",tolua_easeactions_wyEaseBounceIn_update00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyEaseBounceInOut","wyEaseBounceInOut","wyEaseBounce",tolua_collect_wyEaseBounceInOut);
  #else
  tolua_cclass(tolua_S,"wyEaseBounceInOut","wyEaseBounceInOut","wyEaseBounce",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyEaseBounceInOut");
   tolua_function(tolua_S,"make",tolua_easeactions_wyEaseBounceInOut_make00);
   tolua_function(tolua_S,"new",tolua_easeactions_wyEaseBounceInOut_new00);
   tolua_function(tolua_S,"new_local",tolua_easeactions_wyEaseBounceInOut_new00_local);
   tolua_function(tolua_S,".call",tolua_easeactions_wyEaseBounceInOut_new00_local);
   tolua_function(tolua_S,"delete",tolua_easeactions_wyEaseBounceInOut_delete00);
   tolua_function(tolua_S,"copy",tolua_easeactions_wyEaseBounceInOut_copy00);
   tolua_function(tolua_S,"reverse",tolua_easeactions_wyEaseBounceInOut_reverse00);
   tolua_function(tolua_S,"update",tolua_easeactions_wyEaseBounceInOut_update00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyEaseBounceOut","wyEaseBounceOut","wyEaseBounce",tolua_collect_wyEaseBounceOut);
  #else
  tolua_cclass(tolua_S,"wyEaseBounceOut","wyEaseBounceOut","wyEaseBounce",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyEaseBounceOut");
   tolua_function(tolua_S,"make",tolua_easeactions_wyEaseBounceOut_make00);
   tolua_function(tolua_S,"new",tolua_easeactions_wyEaseBounceOut_new00);
   tolua_function(tolua_S,"new_local",tolua_easeactions_wyEaseBounceOut_new00_local);
   tolua_function(tolua_S,".call",tolua_easeactions_wyEaseBounceOut_new00_local);
   tolua_function(tolua_S,"delete",tolua_easeactions_wyEaseBounceOut_delete00);
   tolua_function(tolua_S,"copy",tolua_easeactions_wyEaseBounceOut_copy00);
   tolua_function(tolua_S,"reverse",tolua_easeactions_wyEaseBounceOut_reverse00);
   tolua_function(tolua_S,"update",tolua_easeactions_wyEaseBounceOut_update00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyEaseElastic","wyEaseElastic","wyEaseAction",tolua_collect_wyEaseElastic);
  #else
  tolua_cclass(tolua_S,"wyEaseElastic","wyEaseElastic","wyEaseAction",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyEaseElastic");
   tolua_function(tolua_S,"new",tolua_easeactions_wyEaseElastic_new00);
   tolua_function(tolua_S,"new_local",tolua_easeactions_wyEaseElastic_new00_local);
   tolua_function(tolua_S,".call",tolua_easeactions_wyEaseElastic_new00_local);
   tolua_function(tolua_S,"delete",tolua_easeactions_wyEaseElastic_delete00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyEaseElasticIn","wyEaseElasticIn","wyEaseElastic",tolua_collect_wyEaseElasticIn);
  #else
  tolua_cclass(tolua_S,"wyEaseElasticIn","wyEaseElasticIn","wyEaseElastic",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyEaseElasticIn");
   tolua_function(tolua_S,"make",tolua_easeactions_wyEaseElasticIn_make00);
   tolua_function(tolua_S,"new",tolua_easeactions_wyEaseElasticIn_new00);
   tolua_function(tolua_S,"new_local",tolua_easeactions_wyEaseElasticIn_new00_local);
   tolua_function(tolua_S,".call",tolua_easeactions_wyEaseElasticIn_new00_local);
   tolua_function(tolua_S,"delete",tolua_easeactions_wyEaseElasticIn_delete00);
   tolua_function(tolua_S,"copy",tolua_easeactions_wyEaseElasticIn_copy00);
   tolua_function(tolua_S,"reverse",tolua_easeactions_wyEaseElasticIn_reverse00);
   tolua_function(tolua_S,"update",tolua_easeactions_wyEaseElasticIn_update00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyEaseElasticInOut","wyEaseElasticInOut","wyEaseElastic",tolua_collect_wyEaseElasticInOut);
  #else
  tolua_cclass(tolua_S,"wyEaseElasticInOut","wyEaseElasticInOut","wyEaseElastic",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyEaseElasticInOut");
   tolua_function(tolua_S,"make",tolua_easeactions_wyEaseElasticInOut_make00);
   tolua_function(tolua_S,"new",tolua_easeactions_wyEaseElasticInOut_new00);
   tolua_function(tolua_S,"new_local",tolua_easeactions_wyEaseElasticInOut_new00_local);
   tolua_function(tolua_S,".call",tolua_easeactions_wyEaseElasticInOut_new00_local);
   tolua_function(tolua_S,"delete",tolua_easeactions_wyEaseElasticInOut_delete00);
   tolua_function(tolua_S,"copy",tolua_easeactions_wyEaseElasticInOut_copy00);
   tolua_function(tolua_S,"reverse",tolua_easeactions_wyEaseElasticInOut_reverse00);
   tolua_function(tolua_S,"update",tolua_easeactions_wyEaseElasticInOut_update00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyEaseElasticOut","wyEaseElasticOut","wyEaseElastic",tolua_collect_wyEaseElasticOut);
  #else
  tolua_cclass(tolua_S,"wyEaseElasticOut","wyEaseElasticOut","wyEaseElastic",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyEaseElasticOut");
   tolua_function(tolua_S,"make",tolua_easeactions_wyEaseElasticOut_make00);
   tolua_function(tolua_S,"new",tolua_easeactions_wyEaseElasticOut_new00);
   tolua_function(tolua_S,"new_local",tolua_easeactions_wyEaseElasticOut_new00_local);
   tolua_function(tolua_S,".call",tolua_easeactions_wyEaseElasticOut_new00_local);
   tolua_function(tolua_S,"delete",tolua_easeactions_wyEaseElasticOut_delete00);
   tolua_function(tolua_S,"copy",tolua_easeactions_wyEaseElasticOut_copy00);
   tolua_function(tolua_S,"reverse",tolua_easeactions_wyEaseElasticOut_reverse00);
   tolua_function(tolua_S,"update",tolua_easeactions_wyEaseElasticOut_update00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyEaseExponentialIn","wyEaseExponentialIn","wyEaseAction",tolua_collect_wyEaseExponentialIn);
  #else
  tolua_cclass(tolua_S,"wyEaseExponentialIn","wyEaseExponentialIn","wyEaseAction",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyEaseExponentialIn");
   tolua_function(tolua_S,"make",tolua_easeactions_wyEaseExponentialIn_make00);
   tolua_function(tolua_S,"new",tolua_easeactions_wyEaseExponentialIn_new00);
   tolua_function(tolua_S,"new_local",tolua_easeactions_wyEaseExponentialIn_new00_local);
   tolua_function(tolua_S,".call",tolua_easeactions_wyEaseExponentialIn_new00_local);
   tolua_function(tolua_S,"delete",tolua_easeactions_wyEaseExponentialIn_delete00);
   tolua_function(tolua_S,"copy",tolua_easeactions_wyEaseExponentialIn_copy00);
   tolua_function(tolua_S,"reverse",tolua_easeactions_wyEaseExponentialIn_reverse00);
   tolua_function(tolua_S,"update",tolua_easeactions_wyEaseExponentialIn_update00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyEaseExponentialInOut","wyEaseExponentialInOut","wyEaseAction",tolua_collect_wyEaseExponentialInOut);
  #else
  tolua_cclass(tolua_S,"wyEaseExponentialInOut","wyEaseExponentialInOut","wyEaseAction",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyEaseExponentialInOut");
   tolua_function(tolua_S,"make",tolua_easeactions_wyEaseExponentialInOut_make00);
   tolua_function(tolua_S,"new",tolua_easeactions_wyEaseExponentialInOut_new00);
   tolua_function(tolua_S,"new_local",tolua_easeactions_wyEaseExponentialInOut_new00_local);
   tolua_function(tolua_S,".call",tolua_easeactions_wyEaseExponentialInOut_new00_local);
   tolua_function(tolua_S,"delete",tolua_easeactions_wyEaseExponentialInOut_delete00);
   tolua_function(tolua_S,"copy",tolua_easeactions_wyEaseExponentialInOut_copy00);
   tolua_function(tolua_S,"reverse",tolua_easeactions_wyEaseExponentialInOut_reverse00);
   tolua_function(tolua_S,"update",tolua_easeactions_wyEaseExponentialInOut_update00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyEaseExponentialOut","wyEaseExponentialOut","wyEaseAction",tolua_collect_wyEaseExponentialOut);
  #else
  tolua_cclass(tolua_S,"wyEaseExponentialOut","wyEaseExponentialOut","wyEaseAction",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyEaseExponentialOut");
   tolua_function(tolua_S,"make",tolua_easeactions_wyEaseExponentialOut_make00);
   tolua_function(tolua_S,"new",tolua_easeactions_wyEaseExponentialOut_new00);
   tolua_function(tolua_S,"new_local",tolua_easeactions_wyEaseExponentialOut_new00_local);
   tolua_function(tolua_S,".call",tolua_easeactions_wyEaseExponentialOut_new00_local);
   tolua_function(tolua_S,"delete",tolua_easeactions_wyEaseExponentialOut_delete00);
   tolua_function(tolua_S,"copy",tolua_easeactions_wyEaseExponentialOut_copy00);
   tolua_function(tolua_S,"reverse",tolua_easeactions_wyEaseExponentialOut_reverse00);
   tolua_function(tolua_S,"update",tolua_easeactions_wyEaseExponentialOut_update00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyEaseIn","wyEaseIn","wyEaseRateAction",tolua_collect_wyEaseIn);
  #else
  tolua_cclass(tolua_S,"wyEaseIn","wyEaseIn","wyEaseRateAction",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyEaseIn");
   tolua_function(tolua_S,"make",tolua_easeactions_wyEaseIn_make00);
   tolua_function(tolua_S,"new",tolua_easeactions_wyEaseIn_new00);
   tolua_function(tolua_S,"new_local",tolua_easeactions_wyEaseIn_new00_local);
   tolua_function(tolua_S,".call",tolua_easeactions_wyEaseIn_new00_local);
   tolua_function(tolua_S,"delete",tolua_easeactions_wyEaseIn_delete00);
   tolua_function(tolua_S,"copy",tolua_easeactions_wyEaseIn_copy00);
   tolua_function(tolua_S,"reverse",tolua_easeactions_wyEaseIn_reverse00);
   tolua_function(tolua_S,"update",tolua_easeactions_wyEaseIn_update00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyEaseInOut","wyEaseInOut","wyEaseRateAction",tolua_collect_wyEaseInOut);
  #else
  tolua_cclass(tolua_S,"wyEaseInOut","wyEaseInOut","wyEaseRateAction",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyEaseInOut");
   tolua_function(tolua_S,"make",tolua_easeactions_wyEaseInOut_make00);
   tolua_function(tolua_S,"new",tolua_easeactions_wyEaseInOut_new00);
   tolua_function(tolua_S,"new_local",tolua_easeactions_wyEaseInOut_new00_local);
   tolua_function(tolua_S,".call",tolua_easeactions_wyEaseInOut_new00_local);
   tolua_function(tolua_S,"delete",tolua_easeactions_wyEaseInOut_delete00);
   tolua_function(tolua_S,"copy",tolua_easeactions_wyEaseInOut_copy00);
   tolua_function(tolua_S,"reverse",tolua_easeactions_wyEaseInOut_reverse00);
   tolua_function(tolua_S,"update",tolua_easeactions_wyEaseInOut_update00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyEaseOut","wyEaseOut","wyEaseRateAction",tolua_collect_wyEaseOut);
  #else
  tolua_cclass(tolua_S,"wyEaseOut","wyEaseOut","wyEaseRateAction",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyEaseOut");
   tolua_function(tolua_S,"make",tolua_easeactions_wyEaseOut_make00);
   tolua_function(tolua_S,"new",tolua_easeactions_wyEaseOut_new00);
   tolua_function(tolua_S,"new_local",tolua_easeactions_wyEaseOut_new00_local);
   tolua_function(tolua_S,".call",tolua_easeactions_wyEaseOut_new00_local);
   tolua_function(tolua_S,"delete",tolua_easeactions_wyEaseOut_delete00);
   tolua_function(tolua_S,"copy",tolua_easeactions_wyEaseOut_copy00);
   tolua_function(tolua_S,"reverse",tolua_easeactions_wyEaseOut_reverse00);
   tolua_function(tolua_S,"update",tolua_easeactions_wyEaseOut_update00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyEaseRateAction","wyEaseRateAction","wyEaseAction",tolua_collect_wyEaseRateAction);
  #else
  tolua_cclass(tolua_S,"wyEaseRateAction","wyEaseRateAction","wyEaseAction",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyEaseRateAction");
   tolua_function(tolua_S,"new",tolua_easeactions_wyEaseRateAction_new00);
   tolua_function(tolua_S,"new_local",tolua_easeactions_wyEaseRateAction_new00_local);
   tolua_function(tolua_S,".call",tolua_easeactions_wyEaseRateAction_new00_local);
   tolua_function(tolua_S,"delete",tolua_easeactions_wyEaseRateAction_delete00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyEaseSineIn","wyEaseSineIn","wyEaseAction",tolua_collect_wyEaseSineIn);
  #else
  tolua_cclass(tolua_S,"wyEaseSineIn","wyEaseSineIn","wyEaseAction",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyEaseSineIn");
   tolua_function(tolua_S,"make",tolua_easeactions_wyEaseSineIn_make00);
   tolua_function(tolua_S,"new",tolua_easeactions_wyEaseSineIn_new00);
   tolua_function(tolua_S,"new_local",tolua_easeactions_wyEaseSineIn_new00_local);
   tolua_function(tolua_S,".call",tolua_easeactions_wyEaseSineIn_new00_local);
   tolua_function(tolua_S,"delete",tolua_easeactions_wyEaseSineIn_delete00);
   tolua_function(tolua_S,"copy",tolua_easeactions_wyEaseSineIn_copy00);
   tolua_function(tolua_S,"reverse",tolua_easeactions_wyEaseSineIn_reverse00);
   tolua_function(tolua_S,"update",tolua_easeactions_wyEaseSineIn_update00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyEaseSineInOut","wyEaseSineInOut","wyEaseAction",tolua_collect_wyEaseSineInOut);
  #else
  tolua_cclass(tolua_S,"wyEaseSineInOut","wyEaseSineInOut","wyEaseAction",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyEaseSineInOut");
   tolua_function(tolua_S,"make",tolua_easeactions_wyEaseSineInOut_make00);
   tolua_function(tolua_S,"new",tolua_easeactions_wyEaseSineInOut_new00);
   tolua_function(tolua_S,"new_local",tolua_easeactions_wyEaseSineInOut_new00_local);
   tolua_function(tolua_S,".call",tolua_easeactions_wyEaseSineInOut_new00_local);
   tolua_function(tolua_S,"delete",tolua_easeactions_wyEaseSineInOut_delete00);
   tolua_function(tolua_S,"copy",tolua_easeactions_wyEaseSineInOut_copy00);
   tolua_function(tolua_S,"reverse",tolua_easeactions_wyEaseSineInOut_reverse00);
   tolua_function(tolua_S,"update",tolua_easeactions_wyEaseSineInOut_update00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyEaseSineOut","wyEaseSineOut","wyEaseAction",tolua_collect_wyEaseSineOut);
  #else
  tolua_cclass(tolua_S,"wyEaseSineOut","wyEaseSineOut","wyEaseAction",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyEaseSineOut");
   tolua_function(tolua_S,"make",tolua_easeactions_wyEaseSineOut_make00);
   tolua_function(tolua_S,"new",tolua_easeactions_wyEaseSineOut_new00);
   tolua_function(tolua_S,"new_local",tolua_easeactions_wyEaseSineOut_new00_local);
   tolua_function(tolua_S,".call",tolua_easeactions_wyEaseSineOut_new00_local);
   tolua_function(tolua_S,"delete",tolua_easeactions_wyEaseSineOut_delete00);
   tolua_function(tolua_S,"copy",tolua_easeactions_wyEaseSineOut_copy00);
   tolua_function(tolua_S,"reverse",tolua_easeactions_wyEaseSineOut_reverse00);
   tolua_function(tolua_S,"update",tolua_easeactions_wyEaseSineOut_update00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_easeactions (lua_State* tolua_S) {
 return tolua_easeactions_open(tolua_S);
};
#endif

