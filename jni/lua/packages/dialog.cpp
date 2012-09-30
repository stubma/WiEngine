/*
** Lua binding: dialog
** Generated automatically by tolua++-1.0.92 on Wed Feb 15 12:21:28 2012.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_dialog_open (lua_State* tolua_S);

#include "WiEngine.h"

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_wyDialog (lua_State* tolua_S)
{
 wyDialog* self = (wyDialog*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyDialogTransition (lua_State* tolua_S)
{
 wyDialogTransition* self = (wyDialogTransition*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyDialogPopupTransition (lua_State* tolua_S)
{
 wyDialogPopupTransition* self = (wyDialogPopupTransition*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"wyDialog");
 tolua_usertype(tolua_S,"wyMotionEvent");
 tolua_usertype(tolua_S,"wyTargetSelector");
 tolua_usertype(tolua_S,"wyDialogTransition");
 tolua_usertype(tolua_S,"wyColorLayer");
 tolua_usertype(tolua_S,"wyKeyEvent");
 tolua_usertype(tolua_S,"wyNode");
 tolua_usertype(tolua_S,"wyObject");
 tolua_usertype(tolua_S,"wyDialogPopupTransition");
}

/* method: delete of class  wyDialog */
#ifndef TOLUA_DISABLE_tolua_dialog_wyDialog_delete00
static int tolua_dialog_wyDialog_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyDialog",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyDialog* self = (wyDialog*)  tolua_tousertype(tolua_S,1,0);
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

/* method: make of class  wyDialog */
#ifndef TOLUA_DISABLE_tolua_dialog_wyDialog_make00
static int tolua_dialog_wyDialog_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyDialog",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   wyDialog* tolua_ret = (wyDialog*)  wyDialog::make();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyDialog");
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

/* method: keyDown of class  wyDialog */
#ifndef TOLUA_DISABLE_tolua_dialog_wyDialog_keyDown00
static int tolua_dialog_wyDialog_keyDown00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyDialog",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"wyKeyEvent",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyDialog* self = (wyDialog*)  tolua_tousertype(tolua_S,1,0);
  wyKeyEvent* event = ((wyKeyEvent*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'keyDown'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->keyDown(*event);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'keyDown'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: keyUp of class  wyDialog */
#ifndef TOLUA_DISABLE_tolua_dialog_wyDialog_keyUp00
static int tolua_dialog_wyDialog_keyUp00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyDialog",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"wyKeyEvent",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyDialog* self = (wyDialog*)  tolua_tousertype(tolua_S,1,0);
  wyKeyEvent* event = ((wyKeyEvent*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'keyUp'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->keyUp(*event);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'keyUp'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: keyMultiple of class  wyDialog */
#ifndef TOLUA_DISABLE_tolua_dialog_wyDialog_keyMultiple00
static int tolua_dialog_wyDialog_keyMultiple00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyDialog",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"wyKeyEvent",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyDialog* self = (wyDialog*)  tolua_tousertype(tolua_S,1,0);
  wyKeyEvent* event = ((wyKeyEvent*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'keyMultiple'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->keyMultiple(*event);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'keyMultiple'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: touchesBegan of class  wyDialog */
#ifndef TOLUA_DISABLE_tolua_dialog_wyDialog_touchesBegan00
static int tolua_dialog_wyDialog_touchesBegan00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyDialog",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"wyMotionEvent",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyDialog* self = (wyDialog*)  tolua_tousertype(tolua_S,1,0);
  wyMotionEvent* e = ((wyMotionEvent*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'touchesBegan'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->touchesBegan(*e);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'touchesBegan'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: touchesMoved of class  wyDialog */
#ifndef TOLUA_DISABLE_tolua_dialog_wyDialog_touchesMoved00
static int tolua_dialog_wyDialog_touchesMoved00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyDialog",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"wyMotionEvent",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyDialog* self = (wyDialog*)  tolua_tousertype(tolua_S,1,0);
  wyMotionEvent* e = ((wyMotionEvent*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'touchesMoved'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->touchesMoved(*e);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'touchesMoved'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: touchesEnded of class  wyDialog */
#ifndef TOLUA_DISABLE_tolua_dialog_wyDialog_touchesEnded00
static int tolua_dialog_wyDialog_touchesEnded00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyDialog",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"wyMotionEvent",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyDialog* self = (wyDialog*)  tolua_tousertype(tolua_S,1,0);
  wyMotionEvent* e = ((wyMotionEvent*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'touchesEnded'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->touchesEnded(*e);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'touchesEnded'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: touchesCancelled of class  wyDialog */
#ifndef TOLUA_DISABLE_tolua_dialog_wyDialog_touchesCancelled00
static int tolua_dialog_wyDialog_touchesCancelled00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyDialog",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"wyMotionEvent",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyDialog* self = (wyDialog*)  tolua_tousertype(tolua_S,1,0);
  wyMotionEvent* e = ((wyMotionEvent*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'touchesCancelled'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->touchesCancelled(*e);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'touchesCancelled'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: touchesPointerBegan of class  wyDialog */
#ifndef TOLUA_DISABLE_tolua_dialog_wyDialog_touchesPointerBegan00
static int tolua_dialog_wyDialog_touchesPointerBegan00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyDialog",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"wyMotionEvent",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyDialog* self = (wyDialog*)  tolua_tousertype(tolua_S,1,0);
  wyMotionEvent* e = ((wyMotionEvent*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'touchesPointerBegan'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->touchesPointerBegan(*e);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'touchesPointerBegan'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: touchesPointerEnded of class  wyDialog */
#ifndef TOLUA_DISABLE_tolua_dialog_wyDialog_touchesPointerEnded00
static int tolua_dialog_wyDialog_touchesPointerEnded00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyDialog",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"wyMotionEvent",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyDialog* self = (wyDialog*)  tolua_tousertype(tolua_S,1,0);
  wyMotionEvent* e = ((wyMotionEvent*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'touchesPointerEnded'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->touchesPointerEnded(*e);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'touchesPointerEnded'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  wyDialog */
#ifndef TOLUA_DISABLE_tolua_dialog_wyDialog_create00
static int tolua_dialog_wyDialog_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyDialog",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyDialog* self = (wyDialog*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'create'", NULL);
#endif
  {
   wyDialog* tolua_ret = (wyDialog*)  self->create();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyDialog");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'create'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: show of class  wyDialog */
#ifndef TOLUA_DISABLE_tolua_dialog_wyDialog_show00
static int tolua_dialog_wyDialog_show00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyDialog",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyDialog* self = (wyDialog*)  tolua_tousertype(tolua_S,1,0);
  bool withAnimation = ((bool)  tolua_toboolean(tolua_S,2,true));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'show'", NULL);
#endif
  {
   wyDialog* tolua_ret = (wyDialog*)  self->show(withAnimation);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyDialog");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'show'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: dismiss of class  wyDialog */
#ifndef TOLUA_DISABLE_tolua_dialog_wyDialog_dismiss00
static int tolua_dialog_wyDialog_dismiss00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyDialog",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyDialog* self = (wyDialog*)  tolua_tousertype(tolua_S,1,0);
  bool withAnimation = ((bool)  tolua_toboolean(tolua_S,2,true));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'dismiss'", NULL);
#endif
  {
   self->dismiss(withAnimation);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'dismiss'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setBackground of class  wyDialog */
#ifndef TOLUA_DISABLE_tolua_dialog_wyDialog_setBackground00
static int tolua_dialog_wyDialog_setBackground00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyDialog",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyDialog* self = (wyDialog*)  tolua_tousertype(tolua_S,1,0);
  wyNode* bg = ((wyNode*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setBackground'", NULL);
#endif
  {
   wyDialog* tolua_ret = (wyDialog*)  self->setBackground(bg);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyDialog");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setBackground'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getBackground of class  wyDialog */
#ifndef TOLUA_DISABLE_tolua_dialog_wyDialog_getBackground00
static int tolua_dialog_wyDialog_getBackground00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyDialog",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyDialog* self = (wyDialog*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getBackground'", NULL);
#endif
  {
   wyNode* tolua_ret = (wyNode*)  self->getBackground();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyNode");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getBackground'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setBackgroundPadding of class  wyDialog */
#ifndef TOLUA_DISABLE_tolua_dialog_wyDialog_setBackgroundPadding00
static int tolua_dialog_wyDialog_setBackgroundPadding00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyDialog",0,&tolua_err) ||
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
  wyDialog* self = (wyDialog*)  tolua_tousertype(tolua_S,1,0);
  float left = ((float)  tolua_tonumber(tolua_S,2,0));
  float top = ((float)  tolua_tonumber(tolua_S,3,0));
  float right = ((float)  tolua_tonumber(tolua_S,4,0));
  float bottom = ((float)  tolua_tonumber(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setBackgroundPadding'", NULL);
#endif
  {
   wyDialog* tolua_ret = (wyDialog*)  self->setBackgroundPadding(left,top,right,bottom);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyDialog");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setBackgroundPadding'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setTitle of class  wyDialog */
#ifndef TOLUA_DISABLE_tolua_dialog_wyDialog_setTitle00
static int tolua_dialog_wyDialog_setTitle00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyDialog",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyDialog* self = (wyDialog*)  tolua_tousertype(tolua_S,1,0);
  wyNode* title = ((wyNode*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setTitle'", NULL);
#endif
  {
   wyDialog* tolua_ret = (wyDialog*)  self->setTitle(title);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyDialog");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setTitle'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setContent of class  wyDialog */
#ifndef TOLUA_DISABLE_tolua_dialog_wyDialog_setContent00
static int tolua_dialog_wyDialog_setContent00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyDialog",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyDialog* self = (wyDialog*)  tolua_tousertype(tolua_S,1,0);
  wyNode* content = ((wyNode*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setContent'", NULL);
#endif
  {
   wyDialog* tolua_ret = (wyDialog*)  self->setContent(content);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyDialog");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setContent'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: addButton of class  wyDialog */
#ifndef TOLUA_DISABLE_tolua_dialog_wyDialog_addButton00
static int tolua_dialog_wyDialog_addButton00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyDialog",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyNode",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"wyNode",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,4,"wyTargetSelector",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyDialog* self = (wyDialog*)  tolua_tousertype(tolua_S,1,0);
  wyNode* button = ((wyNode*)  tolua_tousertype(tolua_S,2,0));
  wyNode* label = ((wyNode*)  tolua_tousertype(tolua_S,3,0));
  wyTargetSelector* sel = ((wyTargetSelector*)  tolua_tousertype(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addButton'", NULL);
#endif
  {
   wyDialog* tolua_ret = (wyDialog*)  self->addButton(button,label,sel);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyDialog");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addButton'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: addTwoColumnsButton of class  wyDialog */
#ifndef TOLUA_DISABLE_tolua_dialog_wyDialog_addTwoColumnsButton00
static int tolua_dialog_wyDialog_addTwoColumnsButton00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyDialog",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyNode",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"wyNode",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,4,"wyTargetSelector",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,5,"wyNode",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,6,"wyNode",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,7,"wyTargetSelector",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,8,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyDialog* self = (wyDialog*)  tolua_tousertype(tolua_S,1,0);
  wyNode* button1 = ((wyNode*)  tolua_tousertype(tolua_S,2,0));
  wyNode* label1 = ((wyNode*)  tolua_tousertype(tolua_S,3,0));
  wyTargetSelector* sel1 = ((wyTargetSelector*)  tolua_tousertype(tolua_S,4,0));
  wyNode* button2 = ((wyNode*)  tolua_tousertype(tolua_S,5,0));
  wyNode* label2 = ((wyNode*)  tolua_tousertype(tolua_S,6,0));
  wyTargetSelector* sel2 = ((wyTargetSelector*)  tolua_tousertype(tolua_S,7,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addTwoColumnsButton'", NULL);
#endif
  {
   wyDialog* tolua_ret = (wyDialog*)  self->addTwoColumnsButton(button1,label1,sel1,button2,label2,sel2);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyDialog");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addTwoColumnsButton'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setTransition of class  wyDialog */
#ifndef TOLUA_DISABLE_tolua_dialog_wyDialog_setTransition00
static int tolua_dialog_wyDialog_setTransition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyDialog",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyDialogTransition",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyDialog* self = (wyDialog*)  tolua_tousertype(tolua_S,1,0);
  wyDialogTransition* t = ((wyDialogTransition*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setTransition'", NULL);
#endif
  {
   wyDialog* tolua_ret = (wyDialog*)  self->setTransition(t);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyDialog");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setTransition'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setBackKeyEquivalentButtonIndex of class  wyDialog */
#ifndef TOLUA_DISABLE_tolua_dialog_wyDialog_setBackKeyEquivalentButtonIndex00
static int tolua_dialog_wyDialog_setBackKeyEquivalentButtonIndex00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyDialog",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyDialog* self = (wyDialog*)  tolua_tousertype(tolua_S,1,0);
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setBackKeyEquivalentButtonIndex'", NULL);
#endif
  {
   wyDialog* tolua_ret = (wyDialog*)  self->setBackKeyEquivalentButtonIndex(index);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyDialog");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setBackKeyEquivalentButtonIndex'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  wyDialogTransition */
#ifndef TOLUA_DISABLE_tolua_dialog_wyDialogTransition_delete00
static int tolua_dialog_wyDialogTransition_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyDialogTransition",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyDialogTransition* self = (wyDialogTransition*)  tolua_tousertype(tolua_S,1,0);
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

/* method: applyIn of class  wyDialogTransition */
#ifndef TOLUA_DISABLE_tolua_dialog_wyDialogTransition_applyIn00
static int tolua_dialog_wyDialogTransition_applyIn00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyDialogTransition",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyDialog",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyDialogTransition* self = (wyDialogTransition*)  tolua_tousertype(tolua_S,1,0);
  wyDialog* dialog = ((wyDialog*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'applyIn'", NULL);
#endif
  {
   self->applyIn(dialog);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'applyIn'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: applyOut of class  wyDialogTransition */
#ifndef TOLUA_DISABLE_tolua_dialog_wyDialogTransition_applyOut00
static int tolua_dialog_wyDialogTransition_applyOut00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyDialogTransition",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyDialog",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyDialogTransition* self = (wyDialogTransition*)  tolua_tousertype(tolua_S,1,0);
  wyDialog* dialog = ((wyDialog*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'applyOut'", NULL);
#endif
  {
   self->applyOut(dialog);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'applyOut'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  wyDialogPopupTransition */
#ifndef TOLUA_DISABLE_tolua_dialog_wyDialogPopupTransition_delete00
static int tolua_dialog_wyDialogPopupTransition_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyDialogPopupTransition",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyDialogPopupTransition* self = (wyDialogPopupTransition*)  tolua_tousertype(tolua_S,1,0);
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

/* method: make of class  wyDialogPopupTransition */
#ifndef TOLUA_DISABLE_tolua_dialog_wyDialogPopupTransition_make00
static int tolua_dialog_wyDialogPopupTransition_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyDialogPopupTransition",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   wyDialogPopupTransition* tolua_ret = (wyDialogPopupTransition*)  wyDialogPopupTransition::make();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyDialogPopupTransition");
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

/* method: applyIn of class  wyDialogPopupTransition */
#ifndef TOLUA_DISABLE_tolua_dialog_wyDialogPopupTransition_applyIn00
static int tolua_dialog_wyDialogPopupTransition_applyIn00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyDialogPopupTransition",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyDialog",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyDialogPopupTransition* self = (wyDialogPopupTransition*)  tolua_tousertype(tolua_S,1,0);
  wyDialog* dialog = ((wyDialog*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'applyIn'", NULL);
#endif
  {
   self->applyIn(dialog);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'applyIn'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_dialog_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyDialog","wyDialog","wyColorLayer",tolua_collect_wyDialog);
  #else
  tolua_cclass(tolua_S,"wyDialog","wyDialog","wyColorLayer",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyDialog");
   tolua_function(tolua_S,"delete",tolua_dialog_wyDialog_delete00);
   tolua_function(tolua_S,"make",tolua_dialog_wyDialog_make00);
   tolua_function(tolua_S,"keyDown",tolua_dialog_wyDialog_keyDown00);
   tolua_function(tolua_S,"keyUp",tolua_dialog_wyDialog_keyUp00);
   tolua_function(tolua_S,"keyMultiple",tolua_dialog_wyDialog_keyMultiple00);
   tolua_function(tolua_S,"touchesBegan",tolua_dialog_wyDialog_touchesBegan00);
   tolua_function(tolua_S,"touchesMoved",tolua_dialog_wyDialog_touchesMoved00);
   tolua_function(tolua_S,"touchesEnded",tolua_dialog_wyDialog_touchesEnded00);
   tolua_function(tolua_S,"touchesCancelled",tolua_dialog_wyDialog_touchesCancelled00);
   tolua_function(tolua_S,"touchesPointerBegan",tolua_dialog_wyDialog_touchesPointerBegan00);
   tolua_function(tolua_S,"touchesPointerEnded",tolua_dialog_wyDialog_touchesPointerEnded00);
   tolua_function(tolua_S,"create",tolua_dialog_wyDialog_create00);
   tolua_function(tolua_S,"show",tolua_dialog_wyDialog_show00);
   tolua_function(tolua_S,"dismiss",tolua_dialog_wyDialog_dismiss00);
   tolua_function(tolua_S,"setBackground",tolua_dialog_wyDialog_setBackground00);
   tolua_function(tolua_S,"getBackground",tolua_dialog_wyDialog_getBackground00);
   tolua_function(tolua_S,"setBackgroundPadding",tolua_dialog_wyDialog_setBackgroundPadding00);
   tolua_function(tolua_S,"setTitle",tolua_dialog_wyDialog_setTitle00);
   tolua_function(tolua_S,"setContent",tolua_dialog_wyDialog_setContent00);
   tolua_function(tolua_S,"addButton",tolua_dialog_wyDialog_addButton00);
   tolua_function(tolua_S,"addTwoColumnsButton",tolua_dialog_wyDialog_addTwoColumnsButton00);
   tolua_function(tolua_S,"setTransition",tolua_dialog_wyDialog_setTransition00);
   tolua_function(tolua_S,"setBackKeyEquivalentButtonIndex",tolua_dialog_wyDialog_setBackKeyEquivalentButtonIndex00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyDialogTransition","wyDialogTransition","wyObject",tolua_collect_wyDialogTransition);
  #else
  tolua_cclass(tolua_S,"wyDialogTransition","wyDialogTransition","wyObject",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyDialogTransition");
   tolua_function(tolua_S,"delete",tolua_dialog_wyDialogTransition_delete00);
   tolua_function(tolua_S,"applyIn",tolua_dialog_wyDialogTransition_applyIn00);
   tolua_function(tolua_S,"applyOut",tolua_dialog_wyDialogTransition_applyOut00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyDialogPopupTransition","wyDialogPopupTransition","wyDialogTransition",tolua_collect_wyDialogPopupTransition);
  #else
  tolua_cclass(tolua_S,"wyDialogPopupTransition","wyDialogPopupTransition","wyDialogTransition",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyDialogPopupTransition");
   tolua_function(tolua_S,"delete",tolua_dialog_wyDialogPopupTransition_delete00);
   tolua_function(tolua_S,"make",tolua_dialog_wyDialogPopupTransition_make00);
   tolua_function(tolua_S,"applyIn",tolua_dialog_wyDialogPopupTransition_applyIn00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_dialog (lua_State* tolua_S) {
 return tolua_dialog_open(tolua_S);
};
#endif

