/*
** Lua binding: grid
** Generated automatically by tolua++-1.0.92 on Tue Jul 10 10:51:54 2012.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_grid_open (lua_State* tolua_S);

#include "WiEngine.h"

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_wyVertex3D (lua_State* tolua_S)
{
 wyVertex3D* self = (wyVertex3D*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyGrabber (lua_State* tolua_S)
{
 wyGrabber* self = (wyGrabber*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_GLenum (lua_State* tolua_S)
{
 GLenum* self = (GLenum*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyQuad3D (lua_State* tolua_S)
{
 wyQuad3D* self = (wyQuad3D*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyGrid3D (lua_State* tolua_S)
{
 wyGrid3D* self = (wyGrid3D*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyTiledGrid3D (lua_State* tolua_S)
{
 wyTiledGrid3D* self = (wyTiledGrid3D*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyBaseGrid (lua_State* tolua_S)
{
 wyBaseGrid* self = (wyBaseGrid*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"wyVertex3D");
 tolua_usertype(tolua_S,"GLenum");
 tolua_usertype(tolua_S,"wyTiledGrid3D");
 tolua_usertype(tolua_S,"wyBaseGrid");
 tolua_usertype(tolua_S,"wyQuad3D");
 tolua_usertype(tolua_S,"wyGrid3D");
 tolua_usertype(tolua_S,"wyNode");
 tolua_usertype(tolua_S,"wyObject");
 tolua_usertype(tolua_S,"wyDimension");
 tolua_usertype(tolua_S,"wyGrabber");
}

/* method: delete of class  wyBaseGrid */
#ifndef TOLUA_DISABLE_tolua_grid_wyBaseGrid_delete00
static int tolua_grid_wyBaseGrid_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyBaseGrid",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyBaseGrid* self = (wyBaseGrid*)  tolua_tousertype(tolua_S,1,0);
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

/* method: blit of class  wyBaseGrid */
#ifndef TOLUA_DISABLE_tolua_grid_wyBaseGrid_blit00
static int tolua_grid_wyBaseGrid_blit00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyBaseGrid",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyBaseGrid* self = (wyBaseGrid*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'blit'", NULL);
#endif
  {
   self->blit();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'blit'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: reuse of class  wyBaseGrid */
#ifndef TOLUA_DISABLE_tolua_grid_wyBaseGrid_reuse00
static int tolua_grid_wyBaseGrid_reuse00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyBaseGrid",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyBaseGrid* self = (wyBaseGrid*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'reuse'", NULL);
#endif
  {
   self->reuse();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'reuse'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: beforeDraw of class  wyBaseGrid */
#ifndef TOLUA_DISABLE_tolua_grid_wyBaseGrid_beforeDraw00
static int tolua_grid_wyBaseGrid_beforeDraw00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyBaseGrid",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyBaseGrid* self = (wyBaseGrid*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'beforeDraw'", NULL);
#endif
  {
   self->beforeDraw();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'beforeDraw'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: afterDraw of class  wyBaseGrid */
#ifndef TOLUA_DISABLE_tolua_grid_wyBaseGrid_afterDraw00
static int tolua_grid_wyBaseGrid_afterDraw00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyBaseGrid",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyBaseGrid* self = (wyBaseGrid*)  tolua_tousertype(tolua_S,1,0);
  wyNode* node = ((wyNode*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'afterDraw'", NULL);
#endif
  {
   self->afterDraw(node);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'afterDraw'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: addReuseCount of class  wyBaseGrid */
#ifndef TOLUA_DISABLE_tolua_grid_wyBaseGrid_addReuseCount00
static int tolua_grid_wyBaseGrid_addReuseCount00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyBaseGrid",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyBaseGrid* self = (wyBaseGrid*)  tolua_tousertype(tolua_S,1,0);
  int add = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addReuseCount'", NULL);
#endif
  {
   self->addReuseCount(add);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addReuseCount'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isReuseGrid of class  wyBaseGrid */
#ifndef TOLUA_DISABLE_tolua_grid_wyBaseGrid_isReuseGrid00
static int tolua_grid_wyBaseGrid_isReuseGrid00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyBaseGrid",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyBaseGrid* self = (wyBaseGrid*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isReuseGrid'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isReuseGrid();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isReuseGrid'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setActive of class  wyBaseGrid */
#ifndef TOLUA_DISABLE_tolua_grid_wyBaseGrid_setActive00
static int tolua_grid_wyBaseGrid_setActive00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyBaseGrid",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyBaseGrid* self = (wyBaseGrid*)  tolua_tousertype(tolua_S,1,0);
  bool flag = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setActive'", NULL);
#endif
  {
   self->setActive(flag);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setActive'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isActive of class  wyBaseGrid */
#ifndef TOLUA_DISABLE_tolua_grid_wyBaseGrid_isActive00
static int tolua_grid_wyBaseGrid_isActive00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyBaseGrid",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyBaseGrid* self = (wyBaseGrid*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isActive'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isActive();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isActive'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getStepWidth of class  wyBaseGrid */
#ifndef TOLUA_DISABLE_tolua_grid_wyBaseGrid_getStepWidth00
static int tolua_grid_wyBaseGrid_getStepWidth00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyBaseGrid",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyBaseGrid* self = (wyBaseGrid*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getStepWidth'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getStepWidth();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getStepWidth'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getStepHeight of class  wyBaseGrid */
#ifndef TOLUA_DISABLE_tolua_grid_wyBaseGrid_getStepHeight00
static int tolua_grid_wyBaseGrid_getStepHeight00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyBaseGrid",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyBaseGrid* self = (wyBaseGrid*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getStepHeight'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getStepHeight();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getStepHeight'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getGridX of class  wyBaseGrid */
#ifndef TOLUA_DISABLE_tolua_grid_wyBaseGrid_getGridX00
static int tolua_grid_wyBaseGrid_getGridX00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyBaseGrid",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyBaseGrid* self = (wyBaseGrid*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getGridX'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getGridX();
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

/* method: getGridY of class  wyBaseGrid */
#ifndef TOLUA_DISABLE_tolua_grid_wyBaseGrid_getGridY00
static int tolua_grid_wyBaseGrid_getGridY00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyBaseGrid",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyBaseGrid* self = (wyBaseGrid*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getGridY'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getGridY();
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

/* method: setGridX of class  wyBaseGrid */
#ifndef TOLUA_DISABLE_tolua_grid_wyBaseGrid_setGridX00
static int tolua_grid_wyBaseGrid_setGridX00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyBaseGrid",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyBaseGrid* self = (wyBaseGrid*)  tolua_tousertype(tolua_S,1,0);
  int x = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setGridX'", NULL);
#endif
  {
   self->setGridX(x);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setGridX'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setGridY of class  wyBaseGrid */
#ifndef TOLUA_DISABLE_tolua_grid_wyBaseGrid_setGridY00
static int tolua_grid_wyBaseGrid_setGridY00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyBaseGrid",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyBaseGrid* self = (wyBaseGrid*)  tolua_tousertype(tolua_S,1,0);
  int y = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setGridY'", NULL);
#endif
  {
   self->setGridY(y);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setGridY'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: make of class  wyGrabber */
#ifndef TOLUA_DISABLE_tolua_grid_wyGrabber_make00
static int tolua_grid_wyGrabber_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyGrabber",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   wyGrabber* tolua_ret = (wyGrabber*)  wyGrabber::make();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyGrabber");
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

/* method: make of class  wyGrabber */
#ifndef TOLUA_DISABLE_tolua_grid_wyGrabber_make01
static int tolua_grid_wyGrabber_make01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyGrabber",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  int width = ((int)  tolua_tonumber(tolua_S,2,0));
  int height = ((int)  tolua_tonumber(tolua_S,3,0));
  {
   wyGrabber* tolua_ret = (wyGrabber*)  wyGrabber::make(width,height);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyGrabber");
  }
 }
 return 1;
tolua_lerror:
 return tolua_grid_wyGrabber_make00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  wyGrabber */
#ifndef TOLUA_DISABLE_tolua_grid_wyGrabber_delete00
static int tolua_grid_wyGrabber_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyGrabber",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyGrabber* self = (wyGrabber*)  tolua_tousertype(tolua_S,1,0);
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

/* method: grab of class  wyGrabber */
#ifndef TOLUA_DISABLE_tolua_grid_wyGrabber_grab00
static int tolua_grid_wyGrabber_grab00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyGrabber",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyGrabber* self = (wyGrabber*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'grab'", NULL);
#endif
  {
   GLenum tolua_ret = (GLenum)  self->grab();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((GLenum)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"GLenum");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(GLenum));
     tolua_pushusertype(tolua_S,tolua_obj,"GLenum");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'grab'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: beforeRender of class  wyGrabber */
#ifndef TOLUA_DISABLE_tolua_grid_wyGrabber_beforeRender00
static int tolua_grid_wyGrabber_beforeRender00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyGrabber",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyGrabber* self = (wyGrabber*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'beforeRender'", NULL);
#endif
  {
   self->beforeRender();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'beforeRender'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: afterRender of class  wyGrabber */
#ifndef TOLUA_DISABLE_tolua_grid_wyGrabber_afterRender00
static int tolua_grid_wyGrabber_afterRender00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyGrabber",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyGrabber* self = (wyGrabber*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'afterRender'", NULL);
#endif
  {
   self->afterRender();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'afterRender'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: releaseBuffer of class  wyGrabber */
#ifndef TOLUA_DISABLE_tolua_grid_wyGrabber_releaseBuffer00
static int tolua_grid_wyGrabber_releaseBuffer00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyGrabber",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyGrabber* self = (wyGrabber*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'releaseBuffer'", NULL);
#endif
  {
   self->releaseBuffer();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'releaseBuffer'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: make of class  wyGrid3D */
#ifndef TOLUA_DISABLE_tolua_grid_wyGrid3D_make00
static int tolua_grid_wyGrid3D_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyGrid3D",0,&tolua_err) ||
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
  float w = ((float)  tolua_tonumber(tolua_S,2,0));
  float h = ((float)  tolua_tonumber(tolua_S,3,0));
  int c = ((int)  tolua_tonumber(tolua_S,4,0));
  int r = ((int)  tolua_tonumber(tolua_S,5,0));
  {
   wyGrid3D* tolua_ret = (wyGrid3D*)  wyGrid3D::make(w,h,c,r);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyGrid3D");
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

/* method: delete of class  wyGrid3D */
#ifndef TOLUA_DISABLE_tolua_grid_wyGrid3D_delete00
static int tolua_grid_wyGrid3D_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyGrid3D",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyGrid3D* self = (wyGrid3D*)  tolua_tousertype(tolua_S,1,0);
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

/* method: blit of class  wyGrid3D */
#ifndef TOLUA_DISABLE_tolua_grid_wyGrid3D_blit00
static int tolua_grid_wyGrid3D_blit00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyGrid3D",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyGrid3D* self = (wyGrid3D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'blit'", NULL);
#endif
  {
   self->blit();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'blit'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: reuse of class  wyGrid3D */
#ifndef TOLUA_DISABLE_tolua_grid_wyGrid3D_reuse00
static int tolua_grid_wyGrid3D_reuse00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyGrid3D",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyGrid3D* self = (wyGrid3D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'reuse'", NULL);
#endif
  {
   self->reuse();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'reuse'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setVertex of class  wyGrid3D */
#ifndef TOLUA_DISABLE_tolua_grid_wyGrid3D_setVertex00
static int tolua_grid_wyGrid3D_setVertex00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyGrid3D",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"wyDimension",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"wyVertex3D",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyGrid3D* self = (wyGrid3D*)  tolua_tousertype(tolua_S,1,0);
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

/* method: getVertex of class  wyGrid3D */
#ifndef TOLUA_DISABLE_tolua_grid_wyGrid3D_getVertex00
static int tolua_grid_wyGrid3D_getVertex00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyGrid3D",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"wyDimension",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyGrid3D* self = (wyGrid3D*)  tolua_tousertype(tolua_S,1,0);
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

/* method: getOriginalVertex of class  wyGrid3D */
#ifndef TOLUA_DISABLE_tolua_grid_wyGrid3D_getOriginalVertex00
static int tolua_grid_wyGrid3D_getOriginalVertex00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyGrid3D",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"wyDimension",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyGrid3D* self = (wyGrid3D*)  tolua_tousertype(tolua_S,1,0);
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

/* method: make of class  wyTiledGrid3D */
#ifndef TOLUA_DISABLE_tolua_grid_wyTiledGrid3D_make00
static int tolua_grid_wyTiledGrid3D_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyTiledGrid3D",0,&tolua_err) ||
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
  float w = ((float)  tolua_tonumber(tolua_S,2,0));
  float h = ((float)  tolua_tonumber(tolua_S,3,0));
  int c = ((int)  tolua_tonumber(tolua_S,4,0));
  int r = ((int)  tolua_tonumber(tolua_S,5,0));
  {
   wyTiledGrid3D* tolua_ret = (wyTiledGrid3D*)  wyTiledGrid3D::make(w,h,c,r);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyTiledGrid3D");
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

/* method: delete of class  wyTiledGrid3D */
#ifndef TOLUA_DISABLE_tolua_grid_wyTiledGrid3D_delete00
static int tolua_grid_wyTiledGrid3D_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTiledGrid3D",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTiledGrid3D* self = (wyTiledGrid3D*)  tolua_tousertype(tolua_S,1,0);
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

/* method: blit of class  wyTiledGrid3D */
#ifndef TOLUA_DISABLE_tolua_grid_wyTiledGrid3D_blit00
static int tolua_grid_wyTiledGrid3D_blit00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTiledGrid3D",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTiledGrid3D* self = (wyTiledGrid3D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'blit'", NULL);
#endif
  {
   self->blit();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'blit'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: reuse of class  wyTiledGrid3D */
#ifndef TOLUA_DISABLE_tolua_grid_wyTiledGrid3D_reuse00
static int tolua_grid_wyTiledGrid3D_reuse00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTiledGrid3D",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTiledGrid3D* self = (wyTiledGrid3D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'reuse'", NULL);
#endif
  {
   self->reuse();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'reuse'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setTile of class  wyTiledGrid3D */
#ifndef TOLUA_DISABLE_tolua_grid_wyTiledGrid3D_setTile00
static int tolua_grid_wyTiledGrid3D_setTile00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTiledGrid3D",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"wyDimension",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"wyQuad3D",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTiledGrid3D* self = (wyTiledGrid3D*)  tolua_tousertype(tolua_S,1,0);
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

/* method: getTile of class  wyTiledGrid3D */
#ifndef TOLUA_DISABLE_tolua_grid_wyTiledGrid3D_getTile00
static int tolua_grid_wyTiledGrid3D_getTile00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTiledGrid3D",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"wyDimension",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTiledGrid3D* self = (wyTiledGrid3D*)  tolua_tousertype(tolua_S,1,0);
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

/* method: getOriginalTile of class  wyTiledGrid3D */
#ifndef TOLUA_DISABLE_tolua_grid_wyTiledGrid3D_getOriginalTile00
static int tolua_grid_wyTiledGrid3D_getOriginalTile00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyTiledGrid3D",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"wyDimension",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyTiledGrid3D* self = (wyTiledGrid3D*)  tolua_tousertype(tolua_S,1,0);
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

/* Open function */
TOLUA_API int tolua_grid_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  tolua_cclass(tolua_S,"wyNode","wyNode","",NULL);
  tolua_beginmodule(tolua_S,"wyNode");
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyBaseGrid","wyBaseGrid","wyObject",tolua_collect_wyBaseGrid);
  #else
  tolua_cclass(tolua_S,"wyBaseGrid","wyBaseGrid","wyObject",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyBaseGrid");
   tolua_function(tolua_S,"delete",tolua_grid_wyBaseGrid_delete00);
   tolua_function(tolua_S,"blit",tolua_grid_wyBaseGrid_blit00);
   tolua_function(tolua_S,"reuse",tolua_grid_wyBaseGrid_reuse00);
   tolua_function(tolua_S,"beforeDraw",tolua_grid_wyBaseGrid_beforeDraw00);
   tolua_function(tolua_S,"afterDraw",tolua_grid_wyBaseGrid_afterDraw00);
   tolua_function(tolua_S,"addReuseCount",tolua_grid_wyBaseGrid_addReuseCount00);
   tolua_function(tolua_S,"isReuseGrid",tolua_grid_wyBaseGrid_isReuseGrid00);
   tolua_function(tolua_S,"setActive",tolua_grid_wyBaseGrid_setActive00);
   tolua_function(tolua_S,"isActive",tolua_grid_wyBaseGrid_isActive00);
   tolua_function(tolua_S,"getStepWidth",tolua_grid_wyBaseGrid_getStepWidth00);
   tolua_function(tolua_S,"getStepHeight",tolua_grid_wyBaseGrid_getStepHeight00);
   tolua_function(tolua_S,"getGridX",tolua_grid_wyBaseGrid_getGridX00);
   tolua_function(tolua_S,"getGridY",tolua_grid_wyBaseGrid_getGridY00);
   tolua_function(tolua_S,"setGridX",tolua_grid_wyBaseGrid_setGridX00);
   tolua_function(tolua_S,"setGridY",tolua_grid_wyBaseGrid_setGridY00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyGrabber","wyGrabber","wyObject",tolua_collect_wyGrabber);
  #else
  tolua_cclass(tolua_S,"wyGrabber","wyGrabber","wyObject",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyGrabber");
   tolua_function(tolua_S,"make",tolua_grid_wyGrabber_make00);
   tolua_function(tolua_S,"make",tolua_grid_wyGrabber_make01);
   tolua_function(tolua_S,"delete",tolua_grid_wyGrabber_delete00);
   tolua_function(tolua_S,"grab",tolua_grid_wyGrabber_grab00);
   tolua_function(tolua_S,"beforeRender",tolua_grid_wyGrabber_beforeRender00);
   tolua_function(tolua_S,"afterRender",tolua_grid_wyGrabber_afterRender00);
   tolua_function(tolua_S,"releaseBuffer",tolua_grid_wyGrabber_releaseBuffer00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyGrid3D","wyGrid3D","wyBaseGrid",tolua_collect_wyGrid3D);
  #else
  tolua_cclass(tolua_S,"wyGrid3D","wyGrid3D","wyBaseGrid",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyGrid3D");
   tolua_function(tolua_S,"make",tolua_grid_wyGrid3D_make00);
   tolua_function(tolua_S,"delete",tolua_grid_wyGrid3D_delete00);
   tolua_function(tolua_S,"blit",tolua_grid_wyGrid3D_blit00);
   tolua_function(tolua_S,"reuse",tolua_grid_wyGrid3D_reuse00);
   tolua_function(tolua_S,"setVertex",tolua_grid_wyGrid3D_setVertex00);
   tolua_function(tolua_S,"getVertex",tolua_grid_wyGrid3D_getVertex00);
   tolua_function(tolua_S,"getOriginalVertex",tolua_grid_wyGrid3D_getOriginalVertex00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyTiledGrid3D","wyTiledGrid3D","wyBaseGrid",tolua_collect_wyTiledGrid3D);
  #else
  tolua_cclass(tolua_S,"wyTiledGrid3D","wyTiledGrid3D","wyBaseGrid",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyTiledGrid3D");
   tolua_function(tolua_S,"make",tolua_grid_wyTiledGrid3D_make00);
   tolua_function(tolua_S,"delete",tolua_grid_wyTiledGrid3D_delete00);
   tolua_function(tolua_S,"blit",tolua_grid_wyTiledGrid3D_blit00);
   tolua_function(tolua_S,"reuse",tolua_grid_wyTiledGrid3D_reuse00);
   tolua_function(tolua_S,"setTile",tolua_grid_wyTiledGrid3D_setTile00);
   tolua_function(tolua_S,"getTile",tolua_grid_wyTiledGrid3D_getTile00);
   tolua_function(tolua_S,"getOriginalTile",tolua_grid_wyTiledGrid3D_getOriginalTile00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_grid (lua_State* tolua_S) {
 return tolua_grid_open(tolua_S);
};
#endif

