/*
** Lua binding: events
** Generated automatically by tolua++-1.0.92 on Sat Jun 11 19:27:40 2011.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_events_open (lua_State* tolua_S);

#include "WiEngine.h"

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_wyEventDispatcher (lua_State* tolua_S)
{
 wyEventDispatcher* self = (wyEventDispatcher*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"wyRunnable");
 tolua_usertype(tolua_S,"wyPlatformKeyEvent");
 tolua_usertype(tolua_S,"wyEvent");
 tolua_usertype(tolua_S,"wyEventDispatcher");
 tolua_usertype(tolua_S,"wyObject");
 tolua_usertype(tolua_S,"wyNode");
 tolua_usertype(tolua_S,"wyPlatformMotionEvent");
}

/* method: getInstance of class  wyEventDispatcher */
#ifndef TOLUA_DISABLE_tolua_events_wyEventDispatcher_getInstance00
static int tolua_events_wyEventDispatcher_getInstance00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyEventDispatcher",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   wyEventDispatcher* tolua_ret = (wyEventDispatcher*)  wyEventDispatcher::getInstance();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyEventDispatcher");
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

/* method: delete of class  wyEventDispatcher */
#ifndef TOLUA_DISABLE_tolua_events_wyEventDispatcher_delete00
static int tolua_events_wyEventDispatcher_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyEventDispatcher",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyEventDispatcher* self = (wyEventDispatcher*)  tolua_tousertype(tolua_S,1,0);
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

/* method: processEventsLocked of class  wyEventDispatcher */
#ifndef TOLUA_DISABLE_tolua_events_wyEventDispatcher_processEventsLocked00
static int tolua_events_wyEventDispatcher_processEventsLocked00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyEventDispatcher",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyEventDispatcher* self = (wyEventDispatcher*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'processEventsLocked'", NULL);
#endif
  {
   self->processEventsLocked();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'processEventsLocked'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: hasAccelHandlers of class  wyEventDispatcher */
#ifndef TOLUA_DISABLE_tolua_events_wyEventDispatcher_hasAccelHandlers00
static int tolua_events_wyEventDispatcher_hasAccelHandlers00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyEventDispatcher",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyEventDispatcher* self = (wyEventDispatcher*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'hasAccelHandlers'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->hasAccelHandlers();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'hasAccelHandlers'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setDispatchEvent of class  wyEventDispatcher */
#ifndef TOLUA_DISABLE_tolua_events_wyEventDispatcher_setDispatchEvent00
static int tolua_events_wyEventDispatcher_setDispatchEvent00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyEventDispatcher",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyEventDispatcher* self = (wyEventDispatcher*)  tolua_tousertype(tolua_S,1,0);
  bool flag = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setDispatchEvent'", NULL);
#endif
  {
   self->setDispatchEvent(flag);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setDispatchEvent'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getDispatchEvent of class  wyEventDispatcher */
#ifndef TOLUA_DISABLE_tolua_events_wyEventDispatcher_getDispatchEvent00
static int tolua_events_wyEventDispatcher_getDispatchEvent00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyEventDispatcher",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyEventDispatcher* self = (wyEventDispatcher*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getDispatchEvent'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->getDispatchEvent();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getDispatchEvent'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: wyKeyDown of class  wyEventDispatcher */
#ifndef TOLUA_DISABLE_tolua_events_wyEventDispatcher_wyKeyDown00
static int tolua_events_wyEventDispatcher_wyKeyDown00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyEventDispatcher",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"wyPlatformKeyEvent",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyEventDispatcher* self = (wyEventDispatcher*)  tolua_tousertype(tolua_S,1,0);
  wyPlatformKeyEvent event = *((wyPlatformKeyEvent*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'wyKeyDown'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->wyKeyDown(event);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'wyKeyDown'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: wyKeyUp of class  wyEventDispatcher */
#ifndef TOLUA_DISABLE_tolua_events_wyEventDispatcher_wyKeyUp00
static int tolua_events_wyEventDispatcher_wyKeyUp00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyEventDispatcher",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"wyPlatformKeyEvent",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyEventDispatcher* self = (wyEventDispatcher*)  tolua_tousertype(tolua_S,1,0);
  wyPlatformKeyEvent event = *((wyPlatformKeyEvent*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'wyKeyUp'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->wyKeyUp(event);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'wyKeyUp'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: wyKeyMultiple of class  wyEventDispatcher */
#ifndef TOLUA_DISABLE_tolua_events_wyEventDispatcher_wyKeyMultiple00
static int tolua_events_wyEventDispatcher_wyKeyMultiple00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyEventDispatcher",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"wyPlatformKeyEvent",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyEventDispatcher* self = (wyEventDispatcher*)  tolua_tousertype(tolua_S,1,0);
  wyPlatformKeyEvent event = *((wyPlatformKeyEvent*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'wyKeyMultiple'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->wyKeyMultiple(event);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'wyKeyMultiple'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: wyTouchesBegan of class  wyEventDispatcher */
#ifndef TOLUA_DISABLE_tolua_events_wyEventDispatcher_wyTouchesBegan00
static int tolua_events_wyEventDispatcher_wyTouchesBegan00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyEventDispatcher",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"wyPlatformMotionEvent",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyEventDispatcher* self = (wyEventDispatcher*)  tolua_tousertype(tolua_S,1,0);
  wyPlatformMotionEvent event = *((wyPlatformMotionEvent*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'wyTouchesBegan'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->wyTouchesBegan(event);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'wyTouchesBegan'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: wyTouchesMoved of class  wyEventDispatcher */
#ifndef TOLUA_DISABLE_tolua_events_wyEventDispatcher_wyTouchesMoved00
static int tolua_events_wyEventDispatcher_wyTouchesMoved00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyEventDispatcher",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"wyPlatformMotionEvent",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyEventDispatcher* self = (wyEventDispatcher*)  tolua_tousertype(tolua_S,1,0);
  wyPlatformMotionEvent event = *((wyPlatformMotionEvent*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'wyTouchesMoved'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->wyTouchesMoved(event);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'wyTouchesMoved'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: wyTouchesEnded of class  wyEventDispatcher */
#ifndef TOLUA_DISABLE_tolua_events_wyEventDispatcher_wyTouchesEnded00
static int tolua_events_wyEventDispatcher_wyTouchesEnded00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyEventDispatcher",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"wyPlatformMotionEvent",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyEventDispatcher* self = (wyEventDispatcher*)  tolua_tousertype(tolua_S,1,0);
  wyPlatformMotionEvent event = *((wyPlatformMotionEvent*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'wyTouchesEnded'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->wyTouchesEnded(event);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'wyTouchesEnded'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: wyTouchesCancelled of class  wyEventDispatcher */
#ifndef TOLUA_DISABLE_tolua_events_wyEventDispatcher_wyTouchesCancelled00
static int tolua_events_wyEventDispatcher_wyTouchesCancelled00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyEventDispatcher",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"wyPlatformMotionEvent",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyEventDispatcher* self = (wyEventDispatcher*)  tolua_tousertype(tolua_S,1,0);
  wyPlatformMotionEvent event = *((wyPlatformMotionEvent*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'wyTouchesCancelled'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->wyTouchesCancelled(event);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'wyTouchesCancelled'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: wyTouchesPointerBegan of class  wyEventDispatcher */
#ifndef TOLUA_DISABLE_tolua_events_wyEventDispatcher_wyTouchesPointerBegan00
static int tolua_events_wyEventDispatcher_wyTouchesPointerBegan00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyEventDispatcher",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"wyPlatformMotionEvent",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyEventDispatcher* self = (wyEventDispatcher*)  tolua_tousertype(tolua_S,1,0);
  wyPlatformMotionEvent event = *((wyPlatformMotionEvent*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'wyTouchesPointerBegan'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->wyTouchesPointerBegan(event);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'wyTouchesPointerBegan'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: wyTouchesPointerEnded of class  wyEventDispatcher */
#ifndef TOLUA_DISABLE_tolua_events_wyEventDispatcher_wyTouchesPointerEnded00
static int tolua_events_wyEventDispatcher_wyTouchesPointerEnded00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyEventDispatcher",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"wyPlatformMotionEvent",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyEventDispatcher* self = (wyEventDispatcher*)  tolua_tousertype(tolua_S,1,0);
  wyPlatformMotionEvent event = *((wyPlatformMotionEvent*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'wyTouchesPointerEnded'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->wyTouchesPointerEnded(event);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'wyTouchesPointerEnded'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: wyOnDoubleTap of class  wyEventDispatcher */
#ifndef TOLUA_DISABLE_tolua_events_wyEventDispatcher_wyOnDoubleTap00
static int tolua_events_wyEventDispatcher_wyOnDoubleTap00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyEventDispatcher",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"wyPlatformMotionEvent",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyEventDispatcher* self = (wyEventDispatcher*)  tolua_tousertype(tolua_S,1,0);
  wyPlatformMotionEvent event = *((wyPlatformMotionEvent*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'wyOnDoubleTap'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->wyOnDoubleTap(event);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'wyOnDoubleTap'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: wyOnDoubleTapEvent of class  wyEventDispatcher */
#ifndef TOLUA_DISABLE_tolua_events_wyEventDispatcher_wyOnDoubleTapEvent00
static int tolua_events_wyEventDispatcher_wyOnDoubleTapEvent00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyEventDispatcher",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"wyPlatformMotionEvent",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyEventDispatcher* self = (wyEventDispatcher*)  tolua_tousertype(tolua_S,1,0);
  wyPlatformMotionEvent event = *((wyPlatformMotionEvent*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'wyOnDoubleTapEvent'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->wyOnDoubleTapEvent(event);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'wyOnDoubleTapEvent'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: wyOnSingleTapConfirmed of class  wyEventDispatcher */
#ifndef TOLUA_DISABLE_tolua_events_wyEventDispatcher_wyOnSingleTapConfirmed00
static int tolua_events_wyEventDispatcher_wyOnSingleTapConfirmed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyEventDispatcher",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"wyPlatformMotionEvent",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyEventDispatcher* self = (wyEventDispatcher*)  tolua_tousertype(tolua_S,1,0);
  wyPlatformMotionEvent event = *((wyPlatformMotionEvent*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'wyOnSingleTapConfirmed'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->wyOnSingleTapConfirmed(event);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'wyOnSingleTapConfirmed'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: wyOnDown of class  wyEventDispatcher */
#ifndef TOLUA_DISABLE_tolua_events_wyEventDispatcher_wyOnDown00
static int tolua_events_wyEventDispatcher_wyOnDown00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyEventDispatcher",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"wyPlatformMotionEvent",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyEventDispatcher* self = (wyEventDispatcher*)  tolua_tousertype(tolua_S,1,0);
  wyPlatformMotionEvent event = *((wyPlatformMotionEvent*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'wyOnDown'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->wyOnDown(event);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'wyOnDown'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: wyOnFling of class  wyEventDispatcher */
#ifndef TOLUA_DISABLE_tolua_events_wyEventDispatcher_wyOnFling00
static int tolua_events_wyEventDispatcher_wyOnFling00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyEventDispatcher",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"wyPlatformMotionEvent",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"wyPlatformMotionEvent",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyEventDispatcher* self = (wyEventDispatcher*)  tolua_tousertype(tolua_S,1,0);
  wyPlatformMotionEvent e1 = *((wyPlatformMotionEvent*)  tolua_tousertype(tolua_S,2,0));
  wyPlatformMotionEvent e2 = *((wyPlatformMotionEvent*)  tolua_tousertype(tolua_S,3,0));
  float velocityX = ((float)  tolua_tonumber(tolua_S,4,0));
  float velocityY = ((float)  tolua_tonumber(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'wyOnFling'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->wyOnFling(e1,e2,velocityX,velocityY);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'wyOnFling'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: wyOnLongPress of class  wyEventDispatcher */
#ifndef TOLUA_DISABLE_tolua_events_wyEventDispatcher_wyOnLongPress00
static int tolua_events_wyEventDispatcher_wyOnLongPress00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyEventDispatcher",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"wyPlatformMotionEvent",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyEventDispatcher* self = (wyEventDispatcher*)  tolua_tousertype(tolua_S,1,0);
  wyPlatformMotionEvent event = *((wyPlatformMotionEvent*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'wyOnLongPress'", NULL);
#endif
  {
   self->wyOnLongPress(event);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'wyOnLongPress'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: wyOnScroll of class  wyEventDispatcher */
#ifndef TOLUA_DISABLE_tolua_events_wyEventDispatcher_wyOnScroll00
static int tolua_events_wyEventDispatcher_wyOnScroll00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyEventDispatcher",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"wyPlatformMotionEvent",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"wyPlatformMotionEvent",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyEventDispatcher* self = (wyEventDispatcher*)  tolua_tousertype(tolua_S,1,0);
  wyPlatformMotionEvent e1 = *((wyPlatformMotionEvent*)  tolua_tousertype(tolua_S,2,0));
  wyPlatformMotionEvent e2 = *((wyPlatformMotionEvent*)  tolua_tousertype(tolua_S,3,0));
  float distanceX = ((float)  tolua_tonumber(tolua_S,4,0));
  float distanceY = ((float)  tolua_tonumber(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'wyOnScroll'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->wyOnScroll(e1,e2,distanceX,distanceY);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'wyOnScroll'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: wyOnShowPress of class  wyEventDispatcher */
#ifndef TOLUA_DISABLE_tolua_events_wyEventDispatcher_wyOnShowPress00
static int tolua_events_wyEventDispatcher_wyOnShowPress00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyEventDispatcher",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"wyPlatformMotionEvent",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyEventDispatcher* self = (wyEventDispatcher*)  tolua_tousertype(tolua_S,1,0);
  wyPlatformMotionEvent event = *((wyPlatformMotionEvent*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'wyOnShowPress'", NULL);
#endif
  {
   self->wyOnShowPress(event);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'wyOnShowPress'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: wyOnSingleTapUp of class  wyEventDispatcher */
#ifndef TOLUA_DISABLE_tolua_events_wyEventDispatcher_wyOnSingleTapUp00
static int tolua_events_wyEventDispatcher_wyOnSingleTapUp00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyEventDispatcher",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"wyPlatformMotionEvent",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyEventDispatcher* self = (wyEventDispatcher*)  tolua_tousertype(tolua_S,1,0);
  wyPlatformMotionEvent event = *((wyPlatformMotionEvent*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'wyOnSingleTapUp'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->wyOnSingleTapUp(event);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'wyOnSingleTapUp'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: queueKeyEventLocked of class  wyEventDispatcher */
#ifndef TOLUA_DISABLE_tolua_events_wyEventDispatcher_queueKeyEventLocked00
static int tolua_events_wyEventDispatcher_queueKeyEventLocked00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyEventDispatcher",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"wyPlatformKeyEvent",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyEventDispatcher* self = (wyEventDispatcher*)  tolua_tousertype(tolua_S,1,0);
  wyEventType type = ((wyEventType) (int)  tolua_tonumber(tolua_S,2,0));
  wyPlatformKeyEvent pe = *((wyPlatformKeyEvent*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'queueKeyEventLocked'", NULL);
#endif
  {
   self->queueKeyEventLocked(type,pe);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'queueKeyEventLocked'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: queueEventLocked of class  wyEventDispatcher */
#ifndef TOLUA_DISABLE_tolua_events_wyEventDispatcher_queueEventLocked00
static int tolua_events_wyEventDispatcher_queueEventLocked00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyEventDispatcher",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"wyPlatformMotionEvent",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyEventDispatcher* self = (wyEventDispatcher*)  tolua_tousertype(tolua_S,1,0);
  wyEventType type = ((wyEventType) (int)  tolua_tonumber(tolua_S,2,0));
  wyPlatformMotionEvent pe = *((wyPlatformMotionEvent*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'queueEventLocked'", NULL);
#endif
  {
   self->queueEventLocked(type,pe);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'queueEventLocked'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: queueEventLocked of class  wyEventDispatcher */
#ifndef TOLUA_DISABLE_tolua_events_wyEventDispatcher_queueEventLocked01
static int tolua_events_wyEventDispatcher_queueEventLocked01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyEventDispatcher",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"wyPlatformMotionEvent",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"wyPlatformMotionEvent",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  wyEventDispatcher* self = (wyEventDispatcher*)  tolua_tousertype(tolua_S,1,0);
  wyEventType type = ((wyEventType) (int)  tolua_tonumber(tolua_S,2,0));
  wyPlatformMotionEvent pe1 = *((wyPlatformMotionEvent*)  tolua_tousertype(tolua_S,3,0));
  wyPlatformMotionEvent pe2 = *((wyPlatformMotionEvent*)  tolua_tousertype(tolua_S,4,0));
  float vx = ((float)  tolua_tonumber(tolua_S,5,0));
  float vy = ((float)  tolua_tonumber(tolua_S,6,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'queueEventLocked'", NULL);
#endif
  {
   self->queueEventLocked(type,pe1,pe2,vx,vy);
  }
 }
 return 0;
tolua_lerror:
 return tolua_events_wyEventDispatcher_queueEventLocked00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: queueEventLocked of class  wyEventDispatcher */
#ifndef TOLUA_DISABLE_tolua_events_wyEventDispatcher_queueEventLocked02
static int tolua_events_wyEventDispatcher_queueEventLocked02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyEventDispatcher",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  wyEventDispatcher* self = (wyEventDispatcher*)  tolua_tousertype(tolua_S,1,0);
  float accelX = ((float)  tolua_tonumber(tolua_S,2,0));
  float accelY = ((float)  tolua_tonumber(tolua_S,3,0));
  float accelZ = ((float)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'queueEventLocked'", NULL);
#endif
  {
   self->queueEventLocked(accelX,accelY,accelZ);
  }
 }
 return 0;
tolua_lerror:
 return tolua_events_wyEventDispatcher_queueEventLocked01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: queueRunnableLocked of class  wyEventDispatcher */
#ifndef TOLUA_DISABLE_tolua_events_wyEventDispatcher_queueRunnableLocked00
static int tolua_events_wyEventDispatcher_queueRunnableLocked00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyEventDispatcher",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyRunnable",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyEventDispatcher* self = (wyEventDispatcher*)  tolua_tousertype(tolua_S,1,0);
  wyRunnable* runnable = ((wyRunnable*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'queueRunnableLocked'", NULL);
#endif
  {
   self->queueRunnableLocked(runnable);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'queueRunnableLocked'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: addKeyHandlerLocked of class  wyEventDispatcher */
#ifndef TOLUA_DISABLE_tolua_events_wyEventDispatcher_addKeyHandlerLocked00
static int tolua_events_wyEventDispatcher_addKeyHandlerLocked00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyEventDispatcher",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyNode",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyEventDispatcher* self = (wyEventDispatcher*)  tolua_tousertype(tolua_S,1,0);
  wyNode* node = ((wyNode*)  tolua_tousertype(tolua_S,2,0));
  int priority = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addKeyHandlerLocked'", NULL);
#endif
  {
   self->addKeyHandlerLocked(node,priority);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addKeyHandlerLocked'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: addAccelHandlerLocked of class  wyEventDispatcher */
#ifndef TOLUA_DISABLE_tolua_events_wyEventDispatcher_addAccelHandlerLocked00
static int tolua_events_wyEventDispatcher_addAccelHandlerLocked00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyEventDispatcher",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyNode",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyEventDispatcher* self = (wyEventDispatcher*)  tolua_tousertype(tolua_S,1,0);
  wyNode* node = ((wyNode*)  tolua_tousertype(tolua_S,2,0));
  int priority = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addAccelHandlerLocked'", NULL);
#endif
  {
   self->addAccelHandlerLocked(node,priority);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addAccelHandlerLocked'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: addTouchHandlerLocked of class  wyEventDispatcher */
#ifndef TOLUA_DISABLE_tolua_events_wyEventDispatcher_addTouchHandlerLocked00
static int tolua_events_wyEventDispatcher_addTouchHandlerLocked00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyEventDispatcher",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyNode",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyEventDispatcher* self = (wyEventDispatcher*)  tolua_tousertype(tolua_S,1,0);
  wyNode* node = ((wyNode*)  tolua_tousertype(tolua_S,2,0));
  int priority = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addTouchHandlerLocked'", NULL);
#endif
  {
   self->addTouchHandlerLocked(node,priority);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addTouchHandlerLocked'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: addDoubleTapHandlerLocked of class  wyEventDispatcher */
#ifndef TOLUA_DISABLE_tolua_events_wyEventDispatcher_addDoubleTapHandlerLocked00
static int tolua_events_wyEventDispatcher_addDoubleTapHandlerLocked00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyEventDispatcher",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyNode",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyEventDispatcher* self = (wyEventDispatcher*)  tolua_tousertype(tolua_S,1,0);
  wyNode* node = ((wyNode*)  tolua_tousertype(tolua_S,2,0));
  int priority = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addDoubleTapHandlerLocked'", NULL);
#endif
  {
   self->addDoubleTapHandlerLocked(node,priority);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addDoubleTapHandlerLocked'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: addGestureHandlerLocked of class  wyEventDispatcher */
#ifndef TOLUA_DISABLE_tolua_events_wyEventDispatcher_addGestureHandlerLocked00
static int tolua_events_wyEventDispatcher_addGestureHandlerLocked00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyEventDispatcher",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyNode",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyEventDispatcher* self = (wyEventDispatcher*)  tolua_tousertype(tolua_S,1,0);
  wyNode* node = ((wyNode*)  tolua_tousertype(tolua_S,2,0));
  int priority = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addGestureHandlerLocked'", NULL);
#endif
  {
   self->addGestureHandlerLocked(node,priority);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addGestureHandlerLocked'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: removeKeyHandlerLocked of class  wyEventDispatcher */
#ifndef TOLUA_DISABLE_tolua_events_wyEventDispatcher_removeKeyHandlerLocked00
static int tolua_events_wyEventDispatcher_removeKeyHandlerLocked00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyEventDispatcher",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyEventDispatcher* self = (wyEventDispatcher*)  tolua_tousertype(tolua_S,1,0);
  wyNode* node = ((wyNode*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'removeKeyHandlerLocked'", NULL);
#endif
  {
   self->removeKeyHandlerLocked(node);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'removeKeyHandlerLocked'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: removeAccelHandlerLocked of class  wyEventDispatcher */
#ifndef TOLUA_DISABLE_tolua_events_wyEventDispatcher_removeAccelHandlerLocked00
static int tolua_events_wyEventDispatcher_removeAccelHandlerLocked00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyEventDispatcher",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyEventDispatcher* self = (wyEventDispatcher*)  tolua_tousertype(tolua_S,1,0);
  wyNode* node = ((wyNode*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'removeAccelHandlerLocked'", NULL);
#endif
  {
   self->removeAccelHandlerLocked(node);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'removeAccelHandlerLocked'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: removeTouchHandlerLocked of class  wyEventDispatcher */
#ifndef TOLUA_DISABLE_tolua_events_wyEventDispatcher_removeTouchHandlerLocked00
static int tolua_events_wyEventDispatcher_removeTouchHandlerLocked00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyEventDispatcher",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyEventDispatcher* self = (wyEventDispatcher*)  tolua_tousertype(tolua_S,1,0);
  wyNode* node = ((wyNode*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'removeTouchHandlerLocked'", NULL);
#endif
  {
   self->removeTouchHandlerLocked(node);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'removeTouchHandlerLocked'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: removeDoubleTapHandlerLocked of class  wyEventDispatcher */
#ifndef TOLUA_DISABLE_tolua_events_wyEventDispatcher_removeDoubleTapHandlerLocked00
static int tolua_events_wyEventDispatcher_removeDoubleTapHandlerLocked00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyEventDispatcher",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyEventDispatcher* self = (wyEventDispatcher*)  tolua_tousertype(tolua_S,1,0);
  wyNode* node = ((wyNode*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'removeDoubleTapHandlerLocked'", NULL);
#endif
  {
   self->removeDoubleTapHandlerLocked(node);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'removeDoubleTapHandlerLocked'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: removeGestureHandlerLocked of class  wyEventDispatcher */
#ifndef TOLUA_DISABLE_tolua_events_wyEventDispatcher_removeGestureHandlerLocked00
static int tolua_events_wyEventDispatcher_removeGestureHandlerLocked00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyEventDispatcher",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyEventDispatcher* self = (wyEventDispatcher*)  tolua_tousertype(tolua_S,1,0);
  wyNode* node = ((wyNode*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'removeGestureHandlerLocked'", NULL);
#endif
  {
   self->removeGestureHandlerLocked(node);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'removeGestureHandlerLocked'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: removeAllHandlersLocked of class  wyEventDispatcher */
#ifndef TOLUA_DISABLE_tolua_events_wyEventDispatcher_removeAllHandlersLocked00
static int tolua_events_wyEventDispatcher_removeAllHandlersLocked00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyEventDispatcher",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyEventDispatcher* self = (wyEventDispatcher*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'removeAllHandlersLocked'", NULL);
#endif
  {
   self->removeAllHandlersLocked();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'removeAllHandlersLocked'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setKeyHandlerPriorityLocked of class  wyEventDispatcher */
#ifndef TOLUA_DISABLE_tolua_events_wyEventDispatcher_setKeyHandlerPriorityLocked00
static int tolua_events_wyEventDispatcher_setKeyHandlerPriorityLocked00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyEventDispatcher",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyNode",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyEventDispatcher* self = (wyEventDispatcher*)  tolua_tousertype(tolua_S,1,0);
  wyNode* node = ((wyNode*)  tolua_tousertype(tolua_S,2,0));
  int priority = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setKeyHandlerPriorityLocked'", NULL);
#endif
  {
   self->setKeyHandlerPriorityLocked(node,priority);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setKeyHandlerPriorityLocked'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setAccelHandlerPriorityLocked of class  wyEventDispatcher */
#ifndef TOLUA_DISABLE_tolua_events_wyEventDispatcher_setAccelHandlerPriorityLocked00
static int tolua_events_wyEventDispatcher_setAccelHandlerPriorityLocked00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyEventDispatcher",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyNode",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyEventDispatcher* self = (wyEventDispatcher*)  tolua_tousertype(tolua_S,1,0);
  wyNode* node = ((wyNode*)  tolua_tousertype(tolua_S,2,0));
  int priority = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setAccelHandlerPriorityLocked'", NULL);
#endif
  {
   self->setAccelHandlerPriorityLocked(node,priority);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setAccelHandlerPriorityLocked'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setTouchHandlerPriorityLocked of class  wyEventDispatcher */
#ifndef TOLUA_DISABLE_tolua_events_wyEventDispatcher_setTouchHandlerPriorityLocked00
static int tolua_events_wyEventDispatcher_setTouchHandlerPriorityLocked00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyEventDispatcher",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyNode",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyEventDispatcher* self = (wyEventDispatcher*)  tolua_tousertype(tolua_S,1,0);
  wyNode* node = ((wyNode*)  tolua_tousertype(tolua_S,2,0));
  int priority = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setTouchHandlerPriorityLocked'", NULL);
#endif
  {
   self->setTouchHandlerPriorityLocked(node,priority);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setTouchHandlerPriorityLocked'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setDoubleTapHandlerPriorityLocked of class  wyEventDispatcher */
#ifndef TOLUA_DISABLE_tolua_events_wyEventDispatcher_setDoubleTapHandlerPriorityLocked00
static int tolua_events_wyEventDispatcher_setDoubleTapHandlerPriorityLocked00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyEventDispatcher",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyNode",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyEventDispatcher* self = (wyEventDispatcher*)  tolua_tousertype(tolua_S,1,0);
  wyNode* node = ((wyNode*)  tolua_tousertype(tolua_S,2,0));
  int priority = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setDoubleTapHandlerPriorityLocked'", NULL);
#endif
  {
   self->setDoubleTapHandlerPriorityLocked(node,priority);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setDoubleTapHandlerPriorityLocked'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setGestureHandlerPriorityLocked of class  wyEventDispatcher */
#ifndef TOLUA_DISABLE_tolua_events_wyEventDispatcher_setGestureHandlerPriorityLocked00
static int tolua_events_wyEventDispatcher_setGestureHandlerPriorityLocked00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyEventDispatcher",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyNode",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyEventDispatcher* self = (wyEventDispatcher*)  tolua_tousertype(tolua_S,1,0);
  wyNode* node = ((wyNode*)  tolua_tousertype(tolua_S,2,0));
  int priority = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setGestureHandlerPriorityLocked'", NULL);
#endif
  {
   self->setGestureHandlerPriorityLocked(node,priority);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setGestureHandlerPriorityLocked'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: wyAccelerometerChanged of class  wyEventDispatcher */
#ifndef TOLUA_DISABLE_tolua_events_wyEventDispatcher_wyAccelerometerChanged00
static int tolua_events_wyEventDispatcher_wyAccelerometerChanged00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyEventDispatcher",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyEventDispatcher* self = (wyEventDispatcher*)  tolua_tousertype(tolua_S,1,0);
  float accelX = ((float)  tolua_tonumber(tolua_S,2,0));
  float accelY = ((float)  tolua_tonumber(tolua_S,3,0));
  float accelZ = ((float)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'wyAccelerometerChanged'", NULL);
#endif
  {
   self->wyAccelerometerChanged(accelX,accelY,accelZ);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'wyAccelerometerChanged'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_events_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  tolua_constant(tolua_S,"ET_ACCELEROMETER",ET_ACCELEROMETER);
  tolua_constant(tolua_S,"ET_TOUCH_BEGAN",ET_TOUCH_BEGAN);
  tolua_constant(tolua_S,"ET_TOUCH_MOVED",ET_TOUCH_MOVED);
  tolua_constant(tolua_S,"ET_TOUCH_ENDED",ET_TOUCH_ENDED);
  tolua_constant(tolua_S,"ET_TOUCH_CANCELLED",ET_TOUCH_CANCELLED);
  tolua_constant(tolua_S,"ET_TOUCH_POINTER_BEGAN",ET_TOUCH_POINTER_BEGAN);
  tolua_constant(tolua_S,"ET_TOUCH_POINTER_END",ET_TOUCH_POINTER_END);
  tolua_constant(tolua_S,"ET_KEY_DOWN",ET_KEY_DOWN);
  tolua_constant(tolua_S,"ET_KEY_UP",ET_KEY_UP);
  tolua_constant(tolua_S,"ET_KEY_MULTIPLE",ET_KEY_MULTIPLE);
  tolua_constant(tolua_S,"ET_DOUBLE_TAP",ET_DOUBLE_TAP);
  tolua_constant(tolua_S,"ET_DOUBLE_TAP_EVENT",ET_DOUBLE_TAP_EVENT);
  tolua_constant(tolua_S,"ET_SINGLE_TAP_CONFIRMED",ET_SINGLE_TAP_CONFIRMED);
  tolua_constant(tolua_S,"ET_ON_DOWN",ET_ON_DOWN);
  tolua_constant(tolua_S,"ET_ON_FLING",ET_ON_FLING);
  tolua_constant(tolua_S,"ET_ON_SCROLL",ET_ON_SCROLL);
  tolua_constant(tolua_S,"ET_ON_LONG_PRESS",ET_ON_LONG_PRESS);
  tolua_constant(tolua_S,"ET_ON_SHOW_PRESS",ET_ON_SHOW_PRESS);
  tolua_constant(tolua_S,"ET_ON_SINGLE_TAP_UP",ET_ON_SINGLE_TAP_UP);
  tolua_constant(tolua_S,"ET_LOAD_TEXTURE",ET_LOAD_TEXTURE);
  tolua_constant(tolua_S,"ET_DELETE_TEXTURE",ET_DELETE_TEXTURE);
  tolua_constant(tolua_S,"ET_RUNNABLE",ET_RUNNABLE);
  tolua_cclass(tolua_S,"wyEvent","wyEvent","",NULL);
  tolua_beginmodule(tolua_S,"wyEvent");
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyEventDispatcher","wyEventDispatcher","wyObject",tolua_collect_wyEventDispatcher);
  #else
  tolua_cclass(tolua_S,"wyEventDispatcher","wyEventDispatcher","wyObject",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyEventDispatcher");
   tolua_function(tolua_S,"getInstance",tolua_events_wyEventDispatcher_getInstance00);
   tolua_function(tolua_S,"delete",tolua_events_wyEventDispatcher_delete00);
   tolua_function(tolua_S,"processEventsLocked",tolua_events_wyEventDispatcher_processEventsLocked00);
   tolua_function(tolua_S,"hasAccelHandlers",tolua_events_wyEventDispatcher_hasAccelHandlers00);
   tolua_function(tolua_S,"setDispatchEvent",tolua_events_wyEventDispatcher_setDispatchEvent00);
   tolua_function(tolua_S,"getDispatchEvent",tolua_events_wyEventDispatcher_getDispatchEvent00);
   tolua_function(tolua_S,"wyKeyDown",tolua_events_wyEventDispatcher_wyKeyDown00);
   tolua_function(tolua_S,"wyKeyUp",tolua_events_wyEventDispatcher_wyKeyUp00);
   tolua_function(tolua_S,"wyKeyMultiple",tolua_events_wyEventDispatcher_wyKeyMultiple00);
   tolua_function(tolua_S,"wyTouchesBegan",tolua_events_wyEventDispatcher_wyTouchesBegan00);
   tolua_function(tolua_S,"wyTouchesMoved",tolua_events_wyEventDispatcher_wyTouchesMoved00);
   tolua_function(tolua_S,"wyTouchesEnded",tolua_events_wyEventDispatcher_wyTouchesEnded00);
   tolua_function(tolua_S,"wyTouchesCancelled",tolua_events_wyEventDispatcher_wyTouchesCancelled00);
   tolua_function(tolua_S,"wyTouchesPointerBegan",tolua_events_wyEventDispatcher_wyTouchesPointerBegan00);
   tolua_function(tolua_S,"wyTouchesPointerEnded",tolua_events_wyEventDispatcher_wyTouchesPointerEnded00);
   tolua_function(tolua_S,"wyOnDoubleTap",tolua_events_wyEventDispatcher_wyOnDoubleTap00);
   tolua_function(tolua_S,"wyOnDoubleTapEvent",tolua_events_wyEventDispatcher_wyOnDoubleTapEvent00);
   tolua_function(tolua_S,"wyOnSingleTapConfirmed",tolua_events_wyEventDispatcher_wyOnSingleTapConfirmed00);
   tolua_function(tolua_S,"wyOnDown",tolua_events_wyEventDispatcher_wyOnDown00);
   tolua_function(tolua_S,"wyOnFling",tolua_events_wyEventDispatcher_wyOnFling00);
   tolua_function(tolua_S,"wyOnLongPress",tolua_events_wyEventDispatcher_wyOnLongPress00);
   tolua_function(tolua_S,"wyOnScroll",tolua_events_wyEventDispatcher_wyOnScroll00);
   tolua_function(tolua_S,"wyOnShowPress",tolua_events_wyEventDispatcher_wyOnShowPress00);
   tolua_function(tolua_S,"wyOnSingleTapUp",tolua_events_wyEventDispatcher_wyOnSingleTapUp00);
   tolua_function(tolua_S,"queueKeyEventLocked",tolua_events_wyEventDispatcher_queueKeyEventLocked00);
   tolua_function(tolua_S,"queueEventLocked",tolua_events_wyEventDispatcher_queueEventLocked00);
   tolua_function(tolua_S,"queueEventLocked",tolua_events_wyEventDispatcher_queueEventLocked01);
   tolua_function(tolua_S,"queueEventLocked",tolua_events_wyEventDispatcher_queueEventLocked02);
   tolua_function(tolua_S,"queueRunnableLocked",tolua_events_wyEventDispatcher_queueRunnableLocked00);
   tolua_function(tolua_S,"addKeyHandlerLocked",tolua_events_wyEventDispatcher_addKeyHandlerLocked00);
   tolua_function(tolua_S,"addAccelHandlerLocked",tolua_events_wyEventDispatcher_addAccelHandlerLocked00);
   tolua_function(tolua_S,"addTouchHandlerLocked",tolua_events_wyEventDispatcher_addTouchHandlerLocked00);
   tolua_function(tolua_S,"addDoubleTapHandlerLocked",tolua_events_wyEventDispatcher_addDoubleTapHandlerLocked00);
   tolua_function(tolua_S,"addGestureHandlerLocked",tolua_events_wyEventDispatcher_addGestureHandlerLocked00);
   tolua_function(tolua_S,"removeKeyHandlerLocked",tolua_events_wyEventDispatcher_removeKeyHandlerLocked00);
   tolua_function(tolua_S,"removeAccelHandlerLocked",tolua_events_wyEventDispatcher_removeAccelHandlerLocked00);
   tolua_function(tolua_S,"removeTouchHandlerLocked",tolua_events_wyEventDispatcher_removeTouchHandlerLocked00);
   tolua_function(tolua_S,"removeDoubleTapHandlerLocked",tolua_events_wyEventDispatcher_removeDoubleTapHandlerLocked00);
   tolua_function(tolua_S,"removeGestureHandlerLocked",tolua_events_wyEventDispatcher_removeGestureHandlerLocked00);
   tolua_function(tolua_S,"removeAllHandlersLocked",tolua_events_wyEventDispatcher_removeAllHandlersLocked00);
   tolua_function(tolua_S,"setKeyHandlerPriorityLocked",tolua_events_wyEventDispatcher_setKeyHandlerPriorityLocked00);
   tolua_function(tolua_S,"setAccelHandlerPriorityLocked",tolua_events_wyEventDispatcher_setAccelHandlerPriorityLocked00);
   tolua_function(tolua_S,"setTouchHandlerPriorityLocked",tolua_events_wyEventDispatcher_setTouchHandlerPriorityLocked00);
   tolua_function(tolua_S,"setDoubleTapHandlerPriorityLocked",tolua_events_wyEventDispatcher_setDoubleTapHandlerPriorityLocked00);
   tolua_function(tolua_S,"setGestureHandlerPriorityLocked",tolua_events_wyEventDispatcher_setGestureHandlerPriorityLocked00);
   tolua_function(tolua_S,"wyAccelerometerChanged",tolua_events_wyEventDispatcher_wyAccelerometerChanged00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_events (lua_State* tolua_S) {
 return tolua_events_open(tolua_S);
};
#endif

