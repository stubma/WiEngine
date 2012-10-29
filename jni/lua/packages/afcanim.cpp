/*
** Lua binding: afcanim
** Generated automatically by tolua++-1.0.92 on Fri Oct 26 15:54:18 2012.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_afcanim_open (lua_State* tolua_S);

#include "WiEngine.h"

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_wySPX3Sprite (lua_State* tolua_S)
{
 wySPX3Sprite* self = (wySPX3Sprite*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyAFCFrame (lua_State* tolua_S)
{
 wyAFCFrame* self = (wyAFCFrame*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyAFCClip (lua_State* tolua_S)
{
 wyAFCClip* self = (wyAFCClip*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wySPX3FileData (lua_State* tolua_S)
{
 wySPX3FileData* self = (wySPX3FileData*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyPoint (lua_State* tolua_S)
{
 wyPoint* self = (wyPoint*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyAFCSprite (lua_State* tolua_S)
{
 wyAFCSprite* self = (wyAFCSprite*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wySPX3Frame (lua_State* tolua_S)
{
 wySPX3Frame* self = (wySPX3Frame*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyRect (lua_State* tolua_S)
{
 wyRect* self = (wyRect*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyMWSprite (lua_State* tolua_S)
{
 wyMWSprite* self = (wyMWSprite*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wySPXAction (lua_State* tolua_S)
{
 wySPXAction* self = (wySPXAction*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyArcticFileData (lua_State* tolua_S)
{
 wyArcticFileData* self = (wyArcticFileData*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyAFCAnimation (lua_State* tolua_S)
{
 wyAFCAnimation* self = (wyAFCAnimation*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wySPXFrame (lua_State* tolua_S)
{
 wySPXFrame* self = (wySPXFrame*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyColor3B (lua_State* tolua_S)
{
 wyColor3B* self = (wyColor3B*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wySPXFileData (lua_State* tolua_S)
{
 wySPXFileData* self = (wySPXFileData*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyAFCClipMapping (lua_State* tolua_S)
{
 wyAFCClipMapping* self = (wyAFCClipMapping*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyAuroraSprite (lua_State* tolua_S)
{
 wyAuroraSprite* self = (wyAuroraSprite*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyArcticSprite (lua_State* tolua_S)
{
 wyArcticSprite* self = (wyArcticSprite*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wySPX3TileSet (lua_State* tolua_S)
{
 wySPX3TileSet* self = (wySPX3TileSet*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wySPXSprite (lua_State* tolua_S)
{
 wySPXSprite* self = (wySPXSprite*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"wyArcticAnimationFrame");
 tolua_usertype(tolua_S,"wySPX3Sprite");
 tolua_usertype(tolua_S,"wyArcticAnimation");
 tolua_usertype(tolua_S,"wySPX3TileSet");
 tolua_usertype(tolua_S,"wySPXFrameTile");
 tolua_usertype(tolua_S,"wyArcticLoader");
 tolua_usertype(tolua_S,"wySPXSprite");
 tolua_usertype(tolua_S,"wySPXActionFrame");
 tolua_usertype(tolua_S,"wyAFCSpriteCallback");
 tolua_usertype(tolua_S,"wyArcticFrameModule");
 tolua_usertype(tolua_S,"wySPXTile");
 tolua_usertype(tolua_S,"wySPXFileData");
 tolua_usertype(tolua_S,"wySPX3Loader");
 tolua_usertype(tolua_S,"wyArcticModule");
 tolua_usertype(tolua_S,"wyRect");
 tolua_usertype(tolua_S,"wyAFCClip");
 tolua_usertype(tolua_S,"wyColor3B");
 tolua_usertype(tolua_S,"wySPX3FileData");
 tolua_usertype(tolua_S,"wyPoint");
 tolua_usertype(tolua_S,"wyAFCSprite");
 tolua_usertype(tolua_S,"wySPX3Action");
 tolua_usertype(tolua_S,"wySPX3Frame");
 tolua_usertype(tolua_S,"wyColor4B");
 tolua_usertype(tolua_S,"wyObject");
 tolua_usertype(tolua_S,"wyMWSprite");
 tolua_usertype(tolua_S,"wyAFCClipMapping");
 tolua_usertype(tolua_S,"wyAFCClipMappingRule");
 tolua_usertype(tolua_S,"wySPXAction");
 tolua_usertype(tolua_S,"wyAuroraSprite");
 tolua_usertype(tolua_S,"wyArcticFileData");
 tolua_usertype(tolua_S,"wySPX3Tile");
 tolua_usertype(tolua_S,"wyAFCAnimation");
 tolua_usertype(tolua_S,"wySPXReferencePoint");
 tolua_usertype(tolua_S,"wyArcticFrame");
 tolua_usertype(tolua_S,"wyAFCFrame");
 tolua_usertype(tolua_S,"wySPXCollision");
 tolua_usertype(tolua_S,"wySPXLoader");
 tolua_usertype(tolua_S,"wySPX3Patch");
 tolua_usertype(tolua_S,"wyNode");
 tolua_usertype(tolua_S,"wyArcticSprite");
 tolua_usertype(tolua_S,"wySPXFrame");
 tolua_usertype(tolua_S,"wyTexture2D");
}

/* method: delete of class  wyAFCAnimation */
#ifndef TOLUA_DISABLE_tolua_afcanim_wyAFCAnimation_delete00
static int tolua_afcanim_wyAFCAnimation_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAFCAnimation",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAFCAnimation* self = (wyAFCAnimation*)  tolua_tousertype(tolua_S,1,0);
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

/* method: make of class  wyAFCAnimation */
#ifndef TOLUA_DISABLE_tolua_afcanim_wyAFCAnimation_make00
static int tolua_afcanim_wyAFCAnimation_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyAFCAnimation",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   wyAFCAnimation* tolua_ret = (wyAFCAnimation*)  wyAFCAnimation::make();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyAFCAnimation");
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

/* method: getFrameCount of class  wyAFCAnimation */
#ifndef TOLUA_DISABLE_tolua_afcanim_wyAFCAnimation_getFrameCount00
static int tolua_afcanim_wyAFCAnimation_getFrameCount00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAFCAnimation",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAFCAnimation* self = (wyAFCAnimation*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getFrameCount'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getFrameCount();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getFrameCount'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: addFrame of class  wyAFCAnimation */
#ifndef TOLUA_DISABLE_tolua_afcanim_wyAFCAnimation_addFrame00
static int tolua_afcanim_wyAFCAnimation_addFrame00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAFCAnimation",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyAFCFrame",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAFCAnimation* self = (wyAFCAnimation*)  tolua_tousertype(tolua_S,1,0);
  wyAFCFrame* f = ((wyAFCFrame*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addFrame'", NULL);
#endif
  {
   self->addFrame(f);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addFrame'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getFrameAt of class  wyAFCAnimation */
#ifndef TOLUA_DISABLE_tolua_afcanim_wyAFCAnimation_getFrameAt00
static int tolua_afcanim_wyAFCAnimation_getFrameAt00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAFCAnimation",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAFCAnimation* self = (wyAFCAnimation*)  tolua_tousertype(tolua_S,1,0);
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getFrameAt'", NULL);
#endif
  {
   wyAFCFrame* tolua_ret = (wyAFCFrame*)  self->getFrameAt(index);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyAFCFrame");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getFrameAt'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  wyAFCClip */
#ifndef TOLUA_DISABLE_tolua_afcanim_wyAFCClip_delete00
static int tolua_afcanim_wyAFCClip_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAFCClip",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAFCClip* self = (wyAFCClip*)  tolua_tousertype(tolua_S,1,0);
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

/* method: make of class  wyAFCClip */
#ifndef TOLUA_DISABLE_tolua_afcanim_wyAFCClip_make00
static int tolua_afcanim_wyAFCClip_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyAFCClip",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   wyAFCClip* tolua_ret = (wyAFCClip*)  wyAFCClip::make();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyAFCClip");
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

/* method: getType of class  wyAFCClip */
#ifndef TOLUA_DISABLE_tolua_afcanim_wyAFCClip_getType00
static int tolua_afcanim_wyAFCClip_getType00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAFCClip",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAFCClip* self = (wyAFCClip*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getType'", NULL);
#endif
  {
   wyAFCClipType tolua_ret = (wyAFCClipType)  self->getType();
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

/* method: setType of class  wyAFCClip */
#ifndef TOLUA_DISABLE_tolua_afcanim_wyAFCClip_setType00
static int tolua_afcanim_wyAFCClip_setType00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAFCClip",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAFCClip* self = (wyAFCClip*)  tolua_tousertype(tolua_S,1,0);
  wyAFCClipType type = ((wyAFCClipType) (int)  tolua_tonumber(tolua_S,2,0));
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

/* method: delete of class  wyAFCFrame */
#ifndef TOLUA_DISABLE_tolua_afcanim_wyAFCFrame_delete00
static int tolua_afcanim_wyAFCFrame_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAFCFrame",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAFCFrame* self = (wyAFCFrame*)  tolua_tousertype(tolua_S,1,0);
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

/* method: make of class  wyAFCFrame */
#ifndef TOLUA_DISABLE_tolua_afcanim_wyAFCFrame_make00
static int tolua_afcanim_wyAFCFrame_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyAFCFrame",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   wyAFCFrame* tolua_ret = (wyAFCFrame*)  wyAFCFrame::make();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyAFCFrame");
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

/* method: getClipCount of class  wyAFCFrame */
#ifndef TOLUA_DISABLE_tolua_afcanim_wyAFCFrame_getClipCount00
static int tolua_afcanim_wyAFCFrame_getClipCount00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAFCFrame",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAFCFrame* self = (wyAFCFrame*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getClipCount'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getClipCount();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getClipCount'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getClipCount of class  wyAFCFrame */
#ifndef TOLUA_DISABLE_tolua_afcanim_wyAFCFrame_getClipCount01
static int tolua_afcanim_wyAFCFrame_getClipCount01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAFCFrame",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  wyAFCFrame* self = (wyAFCFrame*)  tolua_tousertype(tolua_S,1,0);
  wyAFCClipType type = ((wyAFCClipType) (int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getClipCount'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getClipCount(type);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
tolua_lerror:
 return tolua_afcanim_wyAFCFrame_getClipCount00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: addClip of class  wyAFCFrame */
#ifndef TOLUA_DISABLE_tolua_afcanim_wyAFCFrame_addClip00
static int tolua_afcanim_wyAFCFrame_addClip00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAFCFrame",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyAFCClip",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAFCFrame* self = (wyAFCFrame*)  tolua_tousertype(tolua_S,1,0);
  wyAFCClip* clip = ((wyAFCClip*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addClip'", NULL);
#endif
  {
   self->addClip(clip);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addClip'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getClipAt of class  wyAFCFrame */
#ifndef TOLUA_DISABLE_tolua_afcanim_wyAFCFrame_getClipAt00
static int tolua_afcanim_wyAFCFrame_getClipAt00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAFCFrame",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAFCFrame* self = (wyAFCFrame*)  tolua_tousertype(tolua_S,1,0);
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getClipAt'", NULL);
#endif
  {
   wyAFCClip* tolua_ret = (wyAFCClip*)  self->getClipAt(index);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyAFCClip");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getClipAt'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getClipAt of class  wyAFCFrame */
#ifndef TOLUA_DISABLE_tolua_afcanim_wyAFCFrame_getClipAt01
static int tolua_afcanim_wyAFCFrame_getClipAt01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAFCFrame",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  wyAFCFrame* self = (wyAFCFrame*)  tolua_tousertype(tolua_S,1,0);
  wyAFCClipType type = ((wyAFCClipType) (int)  tolua_tonumber(tolua_S,2,0));
  int index = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getClipAt'", NULL);
#endif
  {
   wyAFCClip* tolua_ret = (wyAFCClip*)  self->getClipAt(type,index);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyAFCClip");
  }
 }
 return 1;
tolua_lerror:
 return tolua_afcanim_wyAFCFrame_getClipAt00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: setDelay of class  wyAFCFrame */
#ifndef TOLUA_DISABLE_tolua_afcanim_wyAFCFrame_setDelay00
static int tolua_afcanim_wyAFCFrame_setDelay00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAFCFrame",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAFCFrame* self = (wyAFCFrame*)  tolua_tousertype(tolua_S,1,0);
  float delay = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setDelay'", NULL);
#endif
  {
   self->setDelay(delay);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setDelay'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getDelay of class  wyAFCFrame */
#ifndef TOLUA_DISABLE_tolua_afcanim_wyAFCFrame_getDelay00
static int tolua_afcanim_wyAFCFrame_getDelay00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAFCFrame",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAFCFrame* self = (wyAFCFrame*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getDelay'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getDelay();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getDelay'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getIncrementation of class  wyAFCFrame */
#ifndef TOLUA_DISABLE_tolua_afcanim_wyAFCFrame_getIncrementation00
static int tolua_afcanim_wyAFCFrame_getIncrementation00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAFCFrame",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAFCFrame* self = (wyAFCFrame*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getIncrementation'", NULL);
#endif
  {
   wyPoint tolua_ret = (wyPoint)  self->getIncrementation();
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
 tolua_error(tolua_S,"#ferror in function 'getIncrementation'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setIncrementation of class  wyAFCFrame */
#ifndef TOLUA_DISABLE_tolua_afcanim_wyAFCFrame_setIncrementation00
static int tolua_afcanim_wyAFCFrame_setIncrementation00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAFCFrame",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"wyPoint",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAFCFrame* self = (wyAFCFrame*)  tolua_tousertype(tolua_S,1,0);
  wyPoint inc = *((wyPoint*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setIncrementation'", NULL);
#endif
  {
   self->setIncrementation(inc);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setIncrementation'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isFlipX of class  wyAFCFrame */
#ifndef TOLUA_DISABLE_tolua_afcanim_wyAFCFrame_isFlipX00
static int tolua_afcanim_wyAFCFrame_isFlipX00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAFCFrame",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAFCFrame* self = (wyAFCFrame*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isFlipX'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isFlipX();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isFlipX'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setFlipX of class  wyAFCFrame */
#ifndef TOLUA_DISABLE_tolua_afcanim_wyAFCFrame_setFlipX00
static int tolua_afcanim_wyAFCFrame_setFlipX00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAFCFrame",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAFCFrame* self = (wyAFCFrame*)  tolua_tousertype(tolua_S,1,0);
  bool flag = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setFlipX'", NULL);
#endif
  {
   self->setFlipX(flag);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setFlipX'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isFlipY of class  wyAFCFrame */
#ifndef TOLUA_DISABLE_tolua_afcanim_wyAFCFrame_isFlipY00
static int tolua_afcanim_wyAFCFrame_isFlipY00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAFCFrame",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAFCFrame* self = (wyAFCFrame*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isFlipY'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isFlipY();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isFlipY'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setFlipY of class  wyAFCFrame */
#ifndef TOLUA_DISABLE_tolua_afcanim_wyAFCFrame_setFlipY00
static int tolua_afcanim_wyAFCFrame_setFlipY00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAFCFrame",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAFCFrame* self = (wyAFCFrame*)  tolua_tousertype(tolua_S,1,0);
  bool flag = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setFlipY'", NULL);
#endif
  {
   self->setFlipY(flag);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setFlipY'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: make of class  wyMWSprite */
#ifndef TOLUA_DISABLE_tolua_afcanim_wyMWSprite_make00
static int tolua_afcanim_wyMWSprite_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyMWSprite",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,4,"wyTexture2D",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  int mwResId = ((int)  tolua_tonumber(tolua_S,2,0));
  int animIndex = ((int)  tolua_tonumber(tolua_S,3,0));
  wyTexture2D* tex = ((wyTexture2D*)  tolua_tousertype(tolua_S,4,0));
  int count = ((int)  tolua_tonumber(tolua_S,5,0));
  {
   wyMWSprite* tolua_ret = (wyMWSprite*)  wyMWSprite::make(mwResId,animIndex,&tex,count);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyMWSprite");
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

/* method: make of class  wyMWSprite */
#ifndef TOLUA_DISABLE_tolua_afcanim_wyMWSprite_make01
static int tolua_afcanim_wyMWSprite_make01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyMWSprite",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,5,"wyTexture2D",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const char* path = ((const char*)  tolua_tostring(tolua_S,2,0));
  bool isFile = ((bool)  tolua_toboolean(tolua_S,3,0));
  int animIndex = ((int)  tolua_tonumber(tolua_S,4,0));
  wyTexture2D* tex = ((wyTexture2D*)  tolua_tousertype(tolua_S,5,0));
  int count = ((int)  tolua_tonumber(tolua_S,6,0));
  {
   wyMWSprite* tolua_ret = (wyMWSprite*)  wyMWSprite::make(path,isFile,animIndex,&tex,count);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyMWSprite");
    tolua_pushusertype(tolua_S,(void*)tex,"wyTexture2D");
  }
 }
 return 2;
tolua_lerror:
 return tolua_afcanim_wyMWSprite_make00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  wyMWSprite */
#ifndef TOLUA_DISABLE_tolua_afcanim_wyMWSprite_delete00
static int tolua_afcanim_wyMWSprite_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyMWSprite",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyMWSprite* self = (wyMWSprite*)  tolua_tousertype(tolua_S,1,0);
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

/* method: getAnimationAt of class  wyMWSprite */
#ifndef TOLUA_DISABLE_tolua_afcanim_wyMWSprite_getAnimationAt00
static int tolua_afcanim_wyMWSprite_getAnimationAt00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyMWSprite",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyMWSprite* self = (wyMWSprite*)  tolua_tousertype(tolua_S,1,0);
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getAnimationAt'", NULL);
#endif
  {
   wyAFCAnimation* tolua_ret = (wyAFCAnimation*)  self->getAnimationAt(index);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyAFCAnimation");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getAnimationAt'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getAnimationCount of class  wyMWSprite */
#ifndef TOLUA_DISABLE_tolua_afcanim_wyMWSprite_getAnimationCount00
static int tolua_afcanim_wyMWSprite_getAnimationCount00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyMWSprite",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyMWSprite* self = (wyMWSprite*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getAnimationCount'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getAnimationCount();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getAnimationCount'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getImageCount of class  wyMWSprite */
#ifndef TOLUA_DISABLE_tolua_afcanim_wyMWSprite_getImageCount00
static int tolua_afcanim_wyMWSprite_getImageCount00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyMWSprite",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyMWSprite* self = (wyMWSprite*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getImageCount'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getImageCount();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getImageCount'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: index of class  wySPXActionFrame */
#ifndef TOLUA_DISABLE_tolua_get_wySPXActionFrame_index
static int tolua_get_wySPXActionFrame_index(lua_State* tolua_S)
{
  wySPXActionFrame* self = (wySPXActionFrame*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'index'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->index);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: index of class  wySPXActionFrame */
#ifndef TOLUA_DISABLE_tolua_set_wySPXActionFrame_index
static int tolua_set_wySPXActionFrame_index(lua_State* tolua_S)
{
  wySPXActionFrame* self = (wySPXActionFrame*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'index'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->index = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: duration of class  wySPXActionFrame */
#ifndef TOLUA_DISABLE_tolua_get_wySPXActionFrame_duration
static int tolua_get_wySPXActionFrame_duration(lua_State* tolua_S)
{
  wySPXActionFrame* self = (wySPXActionFrame*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'duration'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->duration);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: duration of class  wySPXActionFrame */
#ifndef TOLUA_DISABLE_tolua_set_wySPXActionFrame_duration
static int tolua_set_wySPXActionFrame_duration(lua_State* tolua_S)
{
  wySPXActionFrame* self = (wySPXActionFrame*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'duration'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->duration = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_transform of class  wySPXAction */
#ifndef TOLUA_DISABLE_tolua_get_wySPXAction_m_transform
static int tolua_get_wySPXAction_m_transform(lua_State* tolua_S)
{
  wySPXAction* self = (wySPXAction*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_transform'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->m_transform);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_transform of class  wySPXAction */
#ifndef TOLUA_DISABLE_tolua_set_wySPXAction_m_transform
static int tolua_set_wySPXAction_m_transform(lua_State* tolua_S)
{
  wySPXAction* self = (wySPXAction*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_transform'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_transform = ((wySPXTransform) (int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_frameCount of class  wySPXAction */
#ifndef TOLUA_DISABLE_tolua_get_wySPXAction_m_frameCount
static int tolua_get_wySPXAction_m_frameCount(lua_State* tolua_S)
{
  wySPXAction* self = (wySPXAction*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_frameCount'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->m_frameCount);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_frameCount of class  wySPXAction */
#ifndef TOLUA_DISABLE_tolua_set_wySPXAction_m_frameCount
static int tolua_set_wySPXAction_m_frameCount(lua_State* tolua_S)
{
  wySPXAction* self = (wySPXAction*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_frameCount'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_frameCount = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_maxFrameTile of class  wySPXAction */
#ifndef TOLUA_DISABLE_tolua_get_wySPXAction_m_maxFrameTile
static int tolua_get_wySPXAction_m_maxFrameTile(lua_State* tolua_S)
{
  wySPXAction* self = (wySPXAction*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_maxFrameTile'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->m_maxFrameTile);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_maxFrameTile of class  wySPXAction */
#ifndef TOLUA_DISABLE_tolua_set_wySPXAction_m_maxFrameTile
static int tolua_set_wySPXAction_m_maxFrameTile(lua_State* tolua_S)
{
  wySPXAction* self = (wySPXAction*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_maxFrameTile'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_maxFrameTile = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_frames of class  wySPXAction */
#ifndef TOLUA_DISABLE_tolua_get_wySPXAction_m_frames_ptr
static int tolua_get_wySPXAction_m_frames_ptr(lua_State* tolua_S)
{
  wySPXAction* self = (wySPXAction*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_frames'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->m_frames,"wySPXActionFrame");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_frames of class  wySPXAction */
#ifndef TOLUA_DISABLE_tolua_set_wySPXAction_m_frames_ptr
static int tolua_set_wySPXAction_m_frames_ptr(lua_State* tolua_S)
{
  wySPXAction* self = (wySPXAction*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_frames'",NULL);
  if (!tolua_isusertype(tolua_S,2,"wySPXActionFrame",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_frames = ((wySPXActionFrame*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  wySPXAction */
#ifndef TOLUA_DISABLE_tolua_afcanim_wySPXAction_delete00
static int tolua_afcanim_wySPXAction_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wySPXAction",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wySPXAction* self = (wySPXAction*)  tolua_tousertype(tolua_S,1,0);
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

/* get function: x of class  wySPXTile */
#ifndef TOLUA_DISABLE_tolua_get_wySPXTile_x
static int tolua_get_wySPXTile_x(lua_State* tolua_S)
{
  wySPXTile* self = (wySPXTile*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'x'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->x);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: x of class  wySPXTile */
#ifndef TOLUA_DISABLE_tolua_set_wySPXTile_x
static int tolua_set_wySPXTile_x(lua_State* tolua_S)
{
  wySPXTile* self = (wySPXTile*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'x'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->x = ((short)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: y of class  wySPXTile */
#ifndef TOLUA_DISABLE_tolua_get_wySPXTile_y
static int tolua_get_wySPXTile_y(lua_State* tolua_S)
{
  wySPXTile* self = (wySPXTile*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'y'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->y);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: y of class  wySPXTile */
#ifndef TOLUA_DISABLE_tolua_set_wySPXTile_y
static int tolua_set_wySPXTile_y(lua_State* tolua_S)
{
  wySPXTile* self = (wySPXTile*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'y'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->y = ((short)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: w of class  wySPXTile */
#ifndef TOLUA_DISABLE_tolua_get_wySPXTile_w
static int tolua_get_wySPXTile_w(lua_State* tolua_S)
{
  wySPXTile* self = (wySPXTile*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'w'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->w);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: w of class  wySPXTile */
#ifndef TOLUA_DISABLE_tolua_set_wySPXTile_w
static int tolua_set_wySPXTile_w(lua_State* tolua_S)
{
  wySPXTile* self = (wySPXTile*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'w'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->w = ((short)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: h of class  wySPXTile */
#ifndef TOLUA_DISABLE_tolua_get_wySPXTile_h
static int tolua_get_wySPXTile_h(lua_State* tolua_S)
{
  wySPXTile* self = (wySPXTile*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'h'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->h);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: h of class  wySPXTile */
#ifndef TOLUA_DISABLE_tolua_set_wySPXTile_h
static int tolua_set_wySPXTile_h(lua_State* tolua_S)
{
  wySPXTile* self = (wySPXTile*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'h'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->h = ((short)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_tileCount of class  wySPXFileData */
#ifndef TOLUA_DISABLE_tolua_get_wySPXFileData_m_tileCount
static int tolua_get_wySPXFileData_m_tileCount(lua_State* tolua_S)
{
  wySPXFileData* self = (wySPXFileData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_tileCount'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->m_tileCount);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_tileCount of class  wySPXFileData */
#ifndef TOLUA_DISABLE_tolua_set_wySPXFileData_m_tileCount
static int tolua_set_wySPXFileData_m_tileCount(lua_State* tolua_S)
{
  wySPXFileData* self = (wySPXFileData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_tileCount'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_tileCount = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_frameCount of class  wySPXFileData */
#ifndef TOLUA_DISABLE_tolua_get_wySPXFileData_m_frameCount
static int tolua_get_wySPXFileData_m_frameCount(lua_State* tolua_S)
{
  wySPXFileData* self = (wySPXFileData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_frameCount'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->m_frameCount);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_frameCount of class  wySPXFileData */
#ifndef TOLUA_DISABLE_tolua_set_wySPXFileData_m_frameCount
static int tolua_set_wySPXFileData_m_frameCount(lua_State* tolua_S)
{
  wySPXFileData* self = (wySPXFileData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_frameCount'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_frameCount = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_actionCount of class  wySPXFileData */
#ifndef TOLUA_DISABLE_tolua_get_wySPXFileData_m_actionCount
static int tolua_get_wySPXFileData_m_actionCount(lua_State* tolua_S)
{
  wySPXFileData* self = (wySPXFileData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_actionCount'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->m_actionCount);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_actionCount of class  wySPXFileData */
#ifndef TOLUA_DISABLE_tolua_set_wySPXFileData_m_actionCount
static int tolua_set_wySPXFileData_m_actionCount(lua_State* tolua_S)
{
  wySPXFileData* self = (wySPXFileData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_actionCount'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_actionCount = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_tiles of class  wySPXFileData */
#ifndef TOLUA_DISABLE_tolua_get_wySPXFileData_m_tiles_ptr
static int tolua_get_wySPXFileData_m_tiles_ptr(lua_State* tolua_S)
{
  wySPXFileData* self = (wySPXFileData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_tiles'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->m_tiles,"wySPXTile");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_tiles of class  wySPXFileData */
#ifndef TOLUA_DISABLE_tolua_set_wySPXFileData_m_tiles_ptr
static int tolua_set_wySPXFileData_m_tiles_ptr(lua_State* tolua_S)
{
  wySPXFileData* self = (wySPXFileData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_tiles'",NULL);
  if (!tolua_isusertype(tolua_S,2,"wySPXTile",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_tiles = ((wySPXTile*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  wySPXFileData */
#ifndef TOLUA_DISABLE_tolua_afcanim_wySPXFileData_delete00
static int tolua_afcanim_wySPXFileData_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wySPXFileData",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wySPXFileData* self = (wySPXFileData*)  tolua_tousertype(tolua_S,1,0);
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

/* method: make of class  wySPXFileData */
#ifndef TOLUA_DISABLE_tolua_afcanim_wySPXFileData_make00
static int tolua_afcanim_wySPXFileData_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wySPXFileData",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   wySPXFileData* tolua_ret = (wySPXFileData*)  wySPXFileData::make();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wySPXFileData");
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

/* method: getFrameAt of class  wySPXFileData */
#ifndef TOLUA_DISABLE_tolua_afcanim_wySPXFileData_getFrameAt00
static int tolua_afcanim_wySPXFileData_getFrameAt00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wySPXFileData",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wySPXFileData* self = (wySPXFileData*)  tolua_tousertype(tolua_S,1,0);
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getFrameAt'", NULL);
#endif
  {
   wySPXFrame* tolua_ret = (wySPXFrame*)  self->getFrameAt(index);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wySPXFrame");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getFrameAt'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getActionAt of class  wySPXFileData */
#ifndef TOLUA_DISABLE_tolua_afcanim_wySPXFileData_getActionAt00
static int tolua_afcanim_wySPXFileData_getActionAt00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wySPXFileData",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wySPXFileData* self = (wySPXFileData*)  tolua_tousertype(tolua_S,1,0);
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getActionAt'", NULL);
#endif
  {
   wySPXAction* tolua_ret = (wySPXAction*)  self->getActionAt(index);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wySPXAction");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getActionAt'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: index of class  wySPXFrameTile */
#ifndef TOLUA_DISABLE_tolua_get_wySPXFrameTile_index
static int tolua_get_wySPXFrameTile_index(lua_State* tolua_S)
{
  wySPXFrameTile* self = (wySPXFrameTile*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'index'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->index);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: index of class  wySPXFrameTile */
#ifndef TOLUA_DISABLE_tolua_set_wySPXFrameTile_index
static int tolua_set_wySPXFrameTile_index(lua_State* tolua_S)
{
  wySPXFrameTile* self = (wySPXFrameTile*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'index'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->index = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: x of class  wySPXFrameTile */
#ifndef TOLUA_DISABLE_tolua_get_wySPXFrameTile_x
static int tolua_get_wySPXFrameTile_x(lua_State* tolua_S)
{
  wySPXFrameTile* self = (wySPXFrameTile*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'x'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->x);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: x of class  wySPXFrameTile */
#ifndef TOLUA_DISABLE_tolua_set_wySPXFrameTile_x
static int tolua_set_wySPXFrameTile_x(lua_State* tolua_S)
{
  wySPXFrameTile* self = (wySPXFrameTile*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'x'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->x = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: y of class  wySPXFrameTile */
#ifndef TOLUA_DISABLE_tolua_get_wySPXFrameTile_y
static int tolua_get_wySPXFrameTile_y(lua_State* tolua_S)
{
  wySPXFrameTile* self = (wySPXFrameTile*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'y'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->y);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: y of class  wySPXFrameTile */
#ifndef TOLUA_DISABLE_tolua_set_wySPXFrameTile_y
static int tolua_set_wySPXFrameTile_y(lua_State* tolua_S)
{
  wySPXFrameTile* self = (wySPXFrameTile*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'y'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->y = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: transform of class  wySPXFrameTile */
#ifndef TOLUA_DISABLE_tolua_get_wySPXFrameTile_transform
static int tolua_get_wySPXFrameTile_transform(lua_State* tolua_S)
{
  wySPXFrameTile* self = (wySPXFrameTile*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'transform'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->transform);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: transform of class  wySPXFrameTile */
#ifndef TOLUA_DISABLE_tolua_set_wySPXFrameTile_transform
static int tolua_set_wySPXFrameTile_transform(lua_State* tolua_S)
{
  wySPXFrameTile* self = (wySPXFrameTile*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'transform'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->transform = ((wySPXTransform) (int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: x of class  wySPXCollision */
#ifndef TOLUA_DISABLE_tolua_get_wySPXCollision_x
static int tolua_get_wySPXCollision_x(lua_State* tolua_S)
{
  wySPXCollision* self = (wySPXCollision*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'x'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->x);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: x of class  wySPXCollision */
#ifndef TOLUA_DISABLE_tolua_set_wySPXCollision_x
static int tolua_set_wySPXCollision_x(lua_State* tolua_S)
{
  wySPXCollision* self = (wySPXCollision*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'x'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->x = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: y of class  wySPXCollision */
#ifndef TOLUA_DISABLE_tolua_get_wySPXCollision_y
static int tolua_get_wySPXCollision_y(lua_State* tolua_S)
{
  wySPXCollision* self = (wySPXCollision*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'y'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->y);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: y of class  wySPXCollision */
#ifndef TOLUA_DISABLE_tolua_set_wySPXCollision_y
static int tolua_set_wySPXCollision_y(lua_State* tolua_S)
{
  wySPXCollision* self = (wySPXCollision*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'y'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->y = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: width of class  wySPXCollision */
#ifndef TOLUA_DISABLE_tolua_get_wySPXCollision_width
static int tolua_get_wySPXCollision_width(lua_State* tolua_S)
{
  wySPXCollision* self = (wySPXCollision*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'width'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->width);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: width of class  wySPXCollision */
#ifndef TOLUA_DISABLE_tolua_set_wySPXCollision_width
static int tolua_set_wySPXCollision_width(lua_State* tolua_S)
{
  wySPXCollision* self = (wySPXCollision*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'width'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->width = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: height of class  wySPXCollision */
#ifndef TOLUA_DISABLE_tolua_get_wySPXCollision_height
static int tolua_get_wySPXCollision_height(lua_State* tolua_S)
{
  wySPXCollision* self = (wySPXCollision*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'height'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->height);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: height of class  wySPXCollision */
#ifndef TOLUA_DISABLE_tolua_set_wySPXCollision_height
static int tolua_set_wySPXCollision_height(lua_State* tolua_S)
{
  wySPXCollision* self = (wySPXCollision*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'height'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->height = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: x of class  wySPXReferencePoint */
#ifndef TOLUA_DISABLE_tolua_get_wySPXReferencePoint_x
static int tolua_get_wySPXReferencePoint_x(lua_State* tolua_S)
{
  wySPXReferencePoint* self = (wySPXReferencePoint*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'x'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->x);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: x of class  wySPXReferencePoint */
#ifndef TOLUA_DISABLE_tolua_set_wySPXReferencePoint_x
static int tolua_set_wySPXReferencePoint_x(lua_State* tolua_S)
{
  wySPXReferencePoint* self = (wySPXReferencePoint*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'x'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->x = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: y of class  wySPXReferencePoint */
#ifndef TOLUA_DISABLE_tolua_get_wySPXReferencePoint_y
static int tolua_get_wySPXReferencePoint_y(lua_State* tolua_S)
{
  wySPXReferencePoint* self = (wySPXReferencePoint*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'y'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->y);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: y of class  wySPXReferencePoint */
#ifndef TOLUA_DISABLE_tolua_set_wySPXReferencePoint_y
static int tolua_set_wySPXReferencePoint_y(lua_State* tolua_S)
{
  wySPXReferencePoint* self = (wySPXReferencePoint*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'y'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->y = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_width of class  wySPXFrame */
#ifndef TOLUA_DISABLE_tolua_get_wySPXFrame_m_width
static int tolua_get_wySPXFrame_m_width(lua_State* tolua_S)
{
  wySPXFrame* self = (wySPXFrame*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_width'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->m_width);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_width of class  wySPXFrame */
#ifndef TOLUA_DISABLE_tolua_set_wySPXFrame_m_width
static int tolua_set_wySPXFrame_m_width(lua_State* tolua_S)
{
  wySPXFrame* self = (wySPXFrame*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_width'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_width = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_height of class  wySPXFrame */
#ifndef TOLUA_DISABLE_tolua_get_wySPXFrame_m_height
static int tolua_get_wySPXFrame_m_height(lua_State* tolua_S)
{
  wySPXFrame* self = (wySPXFrame*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_height'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->m_height);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_height of class  wySPXFrame */
#ifndef TOLUA_DISABLE_tolua_set_wySPXFrame_m_height
static int tolua_set_wySPXFrame_m_height(lua_State* tolua_S)
{
  wySPXFrame* self = (wySPXFrame*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_height'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_height = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_frameTileCount of class  wySPXFrame */
#ifndef TOLUA_DISABLE_tolua_get_wySPXFrame_m_frameTileCount
static int tolua_get_wySPXFrame_m_frameTileCount(lua_State* tolua_S)
{
  wySPXFrame* self = (wySPXFrame*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_frameTileCount'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->m_frameTileCount);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_frameTileCount of class  wySPXFrame */
#ifndef TOLUA_DISABLE_tolua_set_wySPXFrame_m_frameTileCount
static int tolua_set_wySPXFrame_m_frameTileCount(lua_State* tolua_S)
{
  wySPXFrame* self = (wySPXFrame*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_frameTileCount'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_frameTileCount = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_collisionCount of class  wySPXFrame */
#ifndef TOLUA_DISABLE_tolua_get_wySPXFrame_m_collisionCount
static int tolua_get_wySPXFrame_m_collisionCount(lua_State* tolua_S)
{
  wySPXFrame* self = (wySPXFrame*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_collisionCount'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->m_collisionCount);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_collisionCount of class  wySPXFrame */
#ifndef TOLUA_DISABLE_tolua_set_wySPXFrame_m_collisionCount
static int tolua_set_wySPXFrame_m_collisionCount(lua_State* tolua_S)
{
  wySPXFrame* self = (wySPXFrame*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_collisionCount'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_collisionCount = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_referencePointCount of class  wySPXFrame */
#ifndef TOLUA_DISABLE_tolua_get_wySPXFrame_m_referencePointCount
static int tolua_get_wySPXFrame_m_referencePointCount(lua_State* tolua_S)
{
  wySPXFrame* self = (wySPXFrame*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_referencePointCount'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->m_referencePointCount);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_referencePointCount of class  wySPXFrame */
#ifndef TOLUA_DISABLE_tolua_set_wySPXFrame_m_referencePointCount
static int tolua_set_wySPXFrame_m_referencePointCount(lua_State* tolua_S)
{
  wySPXFrame* self = (wySPXFrame*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_referencePointCount'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_referencePointCount = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_tiles of class  wySPXFrame */
#ifndef TOLUA_DISABLE_tolua_get_wySPXFrame_m_tiles_ptr
static int tolua_get_wySPXFrame_m_tiles_ptr(lua_State* tolua_S)
{
  wySPXFrame* self = (wySPXFrame*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_tiles'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->m_tiles,"wySPXFrameTile");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_tiles of class  wySPXFrame */
#ifndef TOLUA_DISABLE_tolua_set_wySPXFrame_m_tiles_ptr
static int tolua_set_wySPXFrame_m_tiles_ptr(lua_State* tolua_S)
{
  wySPXFrame* self = (wySPXFrame*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_tiles'",NULL);
  if (!tolua_isusertype(tolua_S,2,"wySPXFrameTile",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_tiles = ((wySPXFrameTile*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_collisions of class  wySPXFrame */
#ifndef TOLUA_DISABLE_tolua_get_wySPXFrame_m_collisions_ptr
static int tolua_get_wySPXFrame_m_collisions_ptr(lua_State* tolua_S)
{
  wySPXFrame* self = (wySPXFrame*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_collisions'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->m_collisions,"wySPXCollision");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_collisions of class  wySPXFrame */
#ifndef TOLUA_DISABLE_tolua_set_wySPXFrame_m_collisions_ptr
static int tolua_set_wySPXFrame_m_collisions_ptr(lua_State* tolua_S)
{
  wySPXFrame* self = (wySPXFrame*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_collisions'",NULL);
  if (!tolua_isusertype(tolua_S,2,"wySPXCollision",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_collisions = ((wySPXCollision*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_refPoints of class  wySPXFrame */
#ifndef TOLUA_DISABLE_tolua_get_wySPXFrame_m_refPoints_ptr
static int tolua_get_wySPXFrame_m_refPoints_ptr(lua_State* tolua_S)
{
  wySPXFrame* self = (wySPXFrame*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_refPoints'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->m_refPoints,"wySPXReferencePoint");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_refPoints of class  wySPXFrame */
#ifndef TOLUA_DISABLE_tolua_set_wySPXFrame_m_refPoints_ptr
static int tolua_set_wySPXFrame_m_refPoints_ptr(lua_State* tolua_S)
{
  wySPXFrame* self = (wySPXFrame*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_refPoints'",NULL);
  if (!tolua_isusertype(tolua_S,2,"wySPXReferencePoint",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_refPoints = ((wySPXReferencePoint*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  wySPXFrame */
#ifndef TOLUA_DISABLE_tolua_afcanim_wySPXFrame_delete00
static int tolua_afcanim_wySPXFrame_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wySPXFrame",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wySPXFrame* self = (wySPXFrame*)  tolua_tousertype(tolua_S,1,0);
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

/* method: load of class  wySPXLoader */
#ifndef TOLUA_DISABLE_tolua_afcanim_wySPXLoader_load00
static int tolua_afcanim_wySPXLoader_load00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wySPXLoader",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  int spxResId = ((int)  tolua_tonumber(tolua_S,2,0));
  {
   wySPXFileData* tolua_ret = (wySPXFileData*)  wySPXLoader::load(spxResId);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wySPXFileData");
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

/* method: load of class  wySPXLoader */
#ifndef TOLUA_DISABLE_tolua_afcanim_wySPXLoader_load01
static int tolua_afcanim_wySPXLoader_load01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wySPXLoader",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,3,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const char* spxPath = ((const char*)  tolua_tostring(tolua_S,2,0));
  bool isFile = ((bool)  tolua_toboolean(tolua_S,3,false));
  {
   wySPXFileData* tolua_ret = (wySPXFileData*)  wySPXLoader::load(spxPath,isFile);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wySPXFileData");
  }
 }
 return 1;
tolua_lerror:
 return tolua_afcanim_wySPXLoader_load00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: loadMemory of class  wySPXLoader */
#ifndef TOLUA_DISABLE_tolua_afcanim_wySPXLoader_loadMemory00
static int tolua_afcanim_wySPXLoader_loadMemory00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wySPXLoader",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* mfsName = ((const char*)  tolua_tostring(tolua_S,2,0));
  {
   wySPXFileData* tolua_ret = (wySPXFileData*)  wySPXLoader::loadMemory(mfsName);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wySPXFileData");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'loadMemory'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  wySPXSprite */
#ifndef TOLUA_DISABLE_tolua_afcanim_wySPXSprite_delete00
static int tolua_afcanim_wySPXSprite_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wySPXSprite",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wySPXSprite* self = (wySPXSprite*)  tolua_tousertype(tolua_S,1,0);
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

/* method: make of class  wySPXSprite */
#ifndef TOLUA_DISABLE_tolua_afcanim_wySPXSprite_make00
static int tolua_afcanim_wySPXSprite_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wySPXSprite",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"wyTexture2D",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  int spxResId = ((int)  tolua_tonumber(tolua_S,2,0));
  wyTexture2D* tex = ((wyTexture2D*)  tolua_tousertype(tolua_S,3,0));
  int actionIndex = ((int)  tolua_tonumber(tolua_S,4,0));
  {
   wySPXSprite* tolua_ret = (wySPXSprite*)  wySPXSprite::make(spxResId,tex,actionIndex);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wySPXSprite");
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

/* method: make of class  wySPXSprite */
#ifndef TOLUA_DISABLE_tolua_afcanim_wySPXSprite_make01
static int tolua_afcanim_wySPXSprite_make01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wySPXSprite",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,3,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,4,"wyTexture2D",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const char* spxPath = ((const char*)  tolua_tostring(tolua_S,2,0));
  bool isFile = ((bool)  tolua_toboolean(tolua_S,3,0));
  wyTexture2D* tex = ((wyTexture2D*)  tolua_tousertype(tolua_S,4,0));
  int actionIndex = ((int)  tolua_tonumber(tolua_S,5,0));
  {
   wySPXSprite* tolua_ret = (wySPXSprite*)  wySPXSprite::make(spxPath,isFile,tex,actionIndex);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wySPXSprite");
  }
 }
 return 1;
tolua_lerror:
 return tolua_afcanim_wySPXSprite_make00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: getAnimationAt of class  wySPXSprite */
#ifndef TOLUA_DISABLE_tolua_afcanim_wySPXSprite_getAnimationAt00
static int tolua_afcanim_wySPXSprite_getAnimationAt00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wySPXSprite",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wySPXSprite* self = (wySPXSprite*)  tolua_tousertype(tolua_S,1,0);
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getAnimationAt'", NULL);
#endif
  {
   wyAFCAnimation* tolua_ret = (wyAFCAnimation*)  self->getAnimationAt(index);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyAFCAnimation");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getAnimationAt'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getAnimationCount of class  wySPXSprite */
#ifndef TOLUA_DISABLE_tolua_afcanim_wySPXSprite_getAnimationCount00
static int tolua_afcanim_wySPXSprite_getAnimationCount00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wySPXSprite",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wySPXSprite* self = (wySPXSprite*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getAnimationCount'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getAnimationCount();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getAnimationCount'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getImageCount of class  wySPXSprite */
#ifndef TOLUA_DISABLE_tolua_afcanim_wySPXSprite_getImageCount00
static int tolua_afcanim_wySPXSprite_getImageCount00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wySPXSprite",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wySPXSprite* self = (wySPXSprite*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getImageCount'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getImageCount();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getImageCount'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: x of class  wyArcticModule */
#ifndef TOLUA_DISABLE_tolua_get_wyArcticModule_x
static int tolua_get_wyArcticModule_x(lua_State* tolua_S)
{
  wyArcticModule* self = (wyArcticModule*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'x'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->x);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: x of class  wyArcticModule */
#ifndef TOLUA_DISABLE_tolua_set_wyArcticModule_x
static int tolua_set_wyArcticModule_x(lua_State* tolua_S)
{
  wyArcticModule* self = (wyArcticModule*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'x'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->x = ((short)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: y of class  wyArcticModule */
#ifndef TOLUA_DISABLE_tolua_get_wyArcticModule_y
static int tolua_get_wyArcticModule_y(lua_State* tolua_S)
{
  wyArcticModule* self = (wyArcticModule*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'y'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->y);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: y of class  wyArcticModule */
#ifndef TOLUA_DISABLE_tolua_set_wyArcticModule_y
static int tolua_set_wyArcticModule_y(lua_State* tolua_S)
{
  wyArcticModule* self = (wyArcticModule*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'y'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->y = ((short)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: w of class  wyArcticModule */
#ifndef TOLUA_DISABLE_tolua_get_wyArcticModule_w
static int tolua_get_wyArcticModule_w(lua_State* tolua_S)
{
  wyArcticModule* self = (wyArcticModule*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'w'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->w);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: w of class  wyArcticModule */
#ifndef TOLUA_DISABLE_tolua_set_wyArcticModule_w
static int tolua_set_wyArcticModule_w(lua_State* tolua_S)
{
  wyArcticModule* self = (wyArcticModule*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'w'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->w = ((short)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: h of class  wyArcticModule */
#ifndef TOLUA_DISABLE_tolua_get_wyArcticModule_h
static int tolua_get_wyArcticModule_h(lua_State* tolua_S)
{
  wyArcticModule* self = (wyArcticModule*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'h'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->h);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: h of class  wyArcticModule */
#ifndef TOLUA_DISABLE_tolua_set_wyArcticModule_h
static int tolua_set_wyArcticModule_h(lua_State* tolua_S)
{
  wyArcticModule* self = (wyArcticModule*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'h'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->h = ((short)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: index of class  wyArcticFrameModule */
#ifndef TOLUA_DISABLE_tolua_get_wyArcticFrameModule_index
static int tolua_get_wyArcticFrameModule_index(lua_State* tolua_S)
{
  wyArcticFrameModule* self = (wyArcticFrameModule*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'index'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->index);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: index of class  wyArcticFrameModule */
#ifndef TOLUA_DISABLE_tolua_set_wyArcticFrameModule_index
static int tolua_set_wyArcticFrameModule_index(lua_State* tolua_S)
{
  wyArcticFrameModule* self = (wyArcticFrameModule*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'index'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->index = ((short)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: x of class  wyArcticFrameModule */
#ifndef TOLUA_DISABLE_tolua_get_wyArcticFrameModule_x
static int tolua_get_wyArcticFrameModule_x(lua_State* tolua_S)
{
  wyArcticFrameModule* self = (wyArcticFrameModule*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'x'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->x);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: x of class  wyArcticFrameModule */
#ifndef TOLUA_DISABLE_tolua_set_wyArcticFrameModule_x
static int tolua_set_wyArcticFrameModule_x(lua_State* tolua_S)
{
  wyArcticFrameModule* self = (wyArcticFrameModule*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'x'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->x = ((short)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: y of class  wyArcticFrameModule */
#ifndef TOLUA_DISABLE_tolua_get_wyArcticFrameModule_y
static int tolua_get_wyArcticFrameModule_y(lua_State* tolua_S)
{
  wyArcticFrameModule* self = (wyArcticFrameModule*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'y'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->y);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: y of class  wyArcticFrameModule */
#ifndef TOLUA_DISABLE_tolua_set_wyArcticFrameModule_y
static int tolua_set_wyArcticFrameModule_y(lua_State* tolua_S)
{
  wyArcticFrameModule* self = (wyArcticFrameModule*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'y'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->y = ((short)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: flags of class  wyArcticFrameModule */
#ifndef TOLUA_DISABLE_tolua_get_wyArcticFrameModule_unsigned_flags
static int tolua_get_wyArcticFrameModule_unsigned_flags(lua_State* tolua_S)
{
  wyArcticFrameModule* self = (wyArcticFrameModule*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'flags'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->flags);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: flags of class  wyArcticFrameModule */
#ifndef TOLUA_DISABLE_tolua_set_wyArcticFrameModule_unsigned_flags
static int tolua_set_wyArcticFrameModule_unsigned_flags(lua_State* tolua_S)
{
  wyArcticFrameModule* self = (wyArcticFrameModule*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'flags'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->flags = ((unsigned char)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: moduleCount of class  wyArcticFrame */
#ifndef TOLUA_DISABLE_tolua_get_wyArcticFrame_moduleCount
static int tolua_get_wyArcticFrame_moduleCount(lua_State* tolua_S)
{
  wyArcticFrame* self = (wyArcticFrame*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'moduleCount'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->moduleCount);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: moduleCount of class  wyArcticFrame */
#ifndef TOLUA_DISABLE_tolua_set_wyArcticFrame_moduleCount
static int tolua_set_wyArcticFrame_moduleCount(lua_State* tolua_S)
{
  wyArcticFrame* self = (wyArcticFrame*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'moduleCount'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->moduleCount = ((short)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: firstModuleIndex of class  wyArcticFrame */
#ifndef TOLUA_DISABLE_tolua_get_wyArcticFrame_firstModuleIndex
static int tolua_get_wyArcticFrame_firstModuleIndex(lua_State* tolua_S)
{
  wyArcticFrame* self = (wyArcticFrame*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'firstModuleIndex'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->firstModuleIndex);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: firstModuleIndex of class  wyArcticFrame */
#ifndef TOLUA_DISABLE_tolua_set_wyArcticFrame_firstModuleIndex
static int tolua_set_wyArcticFrame_firstModuleIndex(lua_State* tolua_S)
{
  wyArcticFrame* self = (wyArcticFrame*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'firstModuleIndex'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->firstModuleIndex = ((short)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: index of class  wyArcticAnimationFrame */
#ifndef TOLUA_DISABLE_tolua_get_wyArcticAnimationFrame_index
static int tolua_get_wyArcticAnimationFrame_index(lua_State* tolua_S)
{
  wyArcticAnimationFrame* self = (wyArcticAnimationFrame*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'index'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->index);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: index of class  wyArcticAnimationFrame */
#ifndef TOLUA_DISABLE_tolua_set_wyArcticAnimationFrame_index
static int tolua_set_wyArcticAnimationFrame_index(lua_State* tolua_S)
{
  wyArcticAnimationFrame* self = (wyArcticAnimationFrame*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'index'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->index = ((short)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: delay of class  wyArcticAnimationFrame */
#ifndef TOLUA_DISABLE_tolua_get_wyArcticAnimationFrame_delay
static int tolua_get_wyArcticAnimationFrame_delay(lua_State* tolua_S)
{
  wyArcticAnimationFrame* self = (wyArcticAnimationFrame*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'delay'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->delay);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: delay of class  wyArcticAnimationFrame */
#ifndef TOLUA_DISABLE_tolua_set_wyArcticAnimationFrame_delay
static int tolua_set_wyArcticAnimationFrame_delay(lua_State* tolua_S)
{
  wyArcticAnimationFrame* self = (wyArcticAnimationFrame*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'delay'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->delay = ((short)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: offsetX of class  wyArcticAnimationFrame */
#ifndef TOLUA_DISABLE_tolua_get_wyArcticAnimationFrame_offsetX
static int tolua_get_wyArcticAnimationFrame_offsetX(lua_State* tolua_S)
{
  wyArcticAnimationFrame* self = (wyArcticAnimationFrame*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'offsetX'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->offsetX);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: offsetX of class  wyArcticAnimationFrame */
#ifndef TOLUA_DISABLE_tolua_set_wyArcticAnimationFrame_offsetX
static int tolua_set_wyArcticAnimationFrame_offsetX(lua_State* tolua_S)
{
  wyArcticAnimationFrame* self = (wyArcticAnimationFrame*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'offsetX'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->offsetX = ((short)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: offsetY of class  wyArcticAnimationFrame */
#ifndef TOLUA_DISABLE_tolua_get_wyArcticAnimationFrame_offsetY
static int tolua_get_wyArcticAnimationFrame_offsetY(lua_State* tolua_S)
{
  wyArcticAnimationFrame* self = (wyArcticAnimationFrame*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'offsetY'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->offsetY);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: offsetY of class  wyArcticAnimationFrame */
#ifndef TOLUA_DISABLE_tolua_set_wyArcticAnimationFrame_offsetY
static int tolua_set_wyArcticAnimationFrame_offsetY(lua_State* tolua_S)
{
  wyArcticAnimationFrame* self = (wyArcticAnimationFrame*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'offsetY'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->offsetY = ((short)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: flags of class  wyArcticAnimationFrame */
#ifndef TOLUA_DISABLE_tolua_get_wyArcticAnimationFrame_unsigned_flags
static int tolua_get_wyArcticAnimationFrame_unsigned_flags(lua_State* tolua_S)
{
  wyArcticAnimationFrame* self = (wyArcticAnimationFrame*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'flags'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->flags);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: flags of class  wyArcticAnimationFrame */
#ifndef TOLUA_DISABLE_tolua_set_wyArcticAnimationFrame_unsigned_flags
static int tolua_set_wyArcticAnimationFrame_unsigned_flags(lua_State* tolua_S)
{
  wyArcticAnimationFrame* self = (wyArcticAnimationFrame*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'flags'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->flags = ((unsigned char)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: frameCount of class  wyArcticAnimation */
#ifndef TOLUA_DISABLE_tolua_get_wyArcticAnimation_frameCount
static int tolua_get_wyArcticAnimation_frameCount(lua_State* tolua_S)
{
  wyArcticAnimation* self = (wyArcticAnimation*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'frameCount'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->frameCount);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: frameCount of class  wyArcticAnimation */
#ifndef TOLUA_DISABLE_tolua_set_wyArcticAnimation_frameCount
static int tolua_set_wyArcticAnimation_frameCount(lua_State* tolua_S)
{
  wyArcticAnimation* self = (wyArcticAnimation*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'frameCount'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->frameCount = ((short)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: firstFrameIndex of class  wyArcticAnimation */
#ifndef TOLUA_DISABLE_tolua_get_wyArcticAnimation_firstFrameIndex
static int tolua_get_wyArcticAnimation_firstFrameIndex(lua_State* tolua_S)
{
  wyArcticAnimation* self = (wyArcticAnimation*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'firstFrameIndex'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->firstFrameIndex);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: firstFrameIndex of class  wyArcticAnimation */
#ifndef TOLUA_DISABLE_tolua_set_wyArcticAnimation_firstFrameIndex
static int tolua_set_wyArcticAnimation_firstFrameIndex(lua_State* tolua_S)
{
  wyArcticAnimation* self = (wyArcticAnimation*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'firstFrameIndex'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->firstFrameIndex = ((short)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_version of class  wyArcticFileData */
#ifndef TOLUA_DISABLE_tolua_get_wyArcticFileData_m_version
static int tolua_get_wyArcticFileData_m_version(lua_State* tolua_S)
{
  wyArcticFileData* self = (wyArcticFileData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_version'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->m_version);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_version of class  wyArcticFileData */
#ifndef TOLUA_DISABLE_tolua_set_wyArcticFileData_m_version
static int tolua_set_wyArcticFileData_m_version(lua_State* tolua_S)
{
  wyArcticFileData* self = (wyArcticFileData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_version'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_version = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_flags of class  wyArcticFileData */
#ifndef TOLUA_DISABLE_tolua_get_wyArcticFileData_m_flags
static int tolua_get_wyArcticFileData_m_flags(lua_State* tolua_S)
{
  wyArcticFileData* self = (wyArcticFileData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_flags'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->m_flags);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_flags of class  wyArcticFileData */
#ifndef TOLUA_DISABLE_tolua_set_wyArcticFileData_m_flags
static int tolua_set_wyArcticFileData_m_flags(lua_State* tolua_S)
{
  wyArcticFileData* self = (wyArcticFileData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_flags'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_flags = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_moduleCount of class  wyArcticFileData */
#ifndef TOLUA_DISABLE_tolua_get_wyArcticFileData_m_moduleCount
static int tolua_get_wyArcticFileData_m_moduleCount(lua_State* tolua_S)
{
  wyArcticFileData* self = (wyArcticFileData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_moduleCount'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->m_moduleCount);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_moduleCount of class  wyArcticFileData */
#ifndef TOLUA_DISABLE_tolua_set_wyArcticFileData_m_moduleCount
static int tolua_set_wyArcticFileData_m_moduleCount(lua_State* tolua_S)
{
  wyArcticFileData* self = (wyArcticFileData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_moduleCount'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_moduleCount = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_modules of class  wyArcticFileData */
#ifndef TOLUA_DISABLE_tolua_get_wyArcticFileData_m_modules_ptr
static int tolua_get_wyArcticFileData_m_modules_ptr(lua_State* tolua_S)
{
  wyArcticFileData* self = (wyArcticFileData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_modules'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->m_modules,"wyArcticModule");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_modules of class  wyArcticFileData */
#ifndef TOLUA_DISABLE_tolua_set_wyArcticFileData_m_modules_ptr
static int tolua_set_wyArcticFileData_m_modules_ptr(lua_State* tolua_S)
{
  wyArcticFileData* self = (wyArcticFileData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_modules'",NULL);
  if (!tolua_isusertype(tolua_S,2,"wyArcticModule",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_modules = ((wyArcticModule*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_frameModuleCount of class  wyArcticFileData */
#ifndef TOLUA_DISABLE_tolua_get_wyArcticFileData_m_frameModuleCount
static int tolua_get_wyArcticFileData_m_frameModuleCount(lua_State* tolua_S)
{
  wyArcticFileData* self = (wyArcticFileData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_frameModuleCount'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->m_frameModuleCount);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_frameModuleCount of class  wyArcticFileData */
#ifndef TOLUA_DISABLE_tolua_set_wyArcticFileData_m_frameModuleCount
static int tolua_set_wyArcticFileData_m_frameModuleCount(lua_State* tolua_S)
{
  wyArcticFileData* self = (wyArcticFileData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_frameModuleCount'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_frameModuleCount = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_frameModules of class  wyArcticFileData */
#ifndef TOLUA_DISABLE_tolua_get_wyArcticFileData_m_frameModules_ptr
static int tolua_get_wyArcticFileData_m_frameModules_ptr(lua_State* tolua_S)
{
  wyArcticFileData* self = (wyArcticFileData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_frameModules'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->m_frameModules,"wyArcticFrameModule");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_frameModules of class  wyArcticFileData */
#ifndef TOLUA_DISABLE_tolua_set_wyArcticFileData_m_frameModules_ptr
static int tolua_set_wyArcticFileData_m_frameModules_ptr(lua_State* tolua_S)
{
  wyArcticFileData* self = (wyArcticFileData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_frameModules'",NULL);
  if (!tolua_isusertype(tolua_S,2,"wyArcticFrameModule",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_frameModules = ((wyArcticFrameModule*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_frameCount of class  wyArcticFileData */
#ifndef TOLUA_DISABLE_tolua_get_wyArcticFileData_m_frameCount
static int tolua_get_wyArcticFileData_m_frameCount(lua_State* tolua_S)
{
  wyArcticFileData* self = (wyArcticFileData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_frameCount'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->m_frameCount);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_frameCount of class  wyArcticFileData */
#ifndef TOLUA_DISABLE_tolua_set_wyArcticFileData_m_frameCount
static int tolua_set_wyArcticFileData_m_frameCount(lua_State* tolua_S)
{
  wyArcticFileData* self = (wyArcticFileData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_frameCount'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_frameCount = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_frames of class  wyArcticFileData */
#ifndef TOLUA_DISABLE_tolua_get_wyArcticFileData_m_frames_ptr
static int tolua_get_wyArcticFileData_m_frames_ptr(lua_State* tolua_S)
{
  wyArcticFileData* self = (wyArcticFileData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_frames'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->m_frames,"wyArcticFrame");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_frames of class  wyArcticFileData */
#ifndef TOLUA_DISABLE_tolua_set_wyArcticFileData_m_frames_ptr
static int tolua_set_wyArcticFileData_m_frames_ptr(lua_State* tolua_S)
{
  wyArcticFileData* self = (wyArcticFileData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_frames'",NULL);
  if (!tolua_isusertype(tolua_S,2,"wyArcticFrame",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_frames = ((wyArcticFrame*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_animationFrameCount of class  wyArcticFileData */
#ifndef TOLUA_DISABLE_tolua_get_wyArcticFileData_m_animationFrameCount
static int tolua_get_wyArcticFileData_m_animationFrameCount(lua_State* tolua_S)
{
  wyArcticFileData* self = (wyArcticFileData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_animationFrameCount'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->m_animationFrameCount);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_animationFrameCount of class  wyArcticFileData */
#ifndef TOLUA_DISABLE_tolua_set_wyArcticFileData_m_animationFrameCount
static int tolua_set_wyArcticFileData_m_animationFrameCount(lua_State* tolua_S)
{
  wyArcticFileData* self = (wyArcticFileData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_animationFrameCount'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_animationFrameCount = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_animationFrames of class  wyArcticFileData */
#ifndef TOLUA_DISABLE_tolua_get_wyArcticFileData_m_animationFrames_ptr
static int tolua_get_wyArcticFileData_m_animationFrames_ptr(lua_State* tolua_S)
{
  wyArcticFileData* self = (wyArcticFileData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_animationFrames'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->m_animationFrames,"wyArcticAnimationFrame");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_animationFrames of class  wyArcticFileData */
#ifndef TOLUA_DISABLE_tolua_set_wyArcticFileData_m_animationFrames_ptr
static int tolua_set_wyArcticFileData_m_animationFrames_ptr(lua_State* tolua_S)
{
  wyArcticFileData* self = (wyArcticFileData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_animationFrames'",NULL);
  if (!tolua_isusertype(tolua_S,2,"wyArcticAnimationFrame",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_animationFrames = ((wyArcticAnimationFrame*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_animationCount of class  wyArcticFileData */
#ifndef TOLUA_DISABLE_tolua_get_wyArcticFileData_m_animationCount
static int tolua_get_wyArcticFileData_m_animationCount(lua_State* tolua_S)
{
  wyArcticFileData* self = (wyArcticFileData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_animationCount'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->m_animationCount);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_animationCount of class  wyArcticFileData */
#ifndef TOLUA_DISABLE_tolua_set_wyArcticFileData_m_animationCount
static int tolua_set_wyArcticFileData_m_animationCount(lua_State* tolua_S)
{
  wyArcticFileData* self = (wyArcticFileData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_animationCount'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_animationCount = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_animations of class  wyArcticFileData */
#ifndef TOLUA_DISABLE_tolua_get_wyArcticFileData_m_animations_ptr
static int tolua_get_wyArcticFileData_m_animations_ptr(lua_State* tolua_S)
{
  wyArcticFileData* self = (wyArcticFileData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_animations'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->m_animations,"wyArcticAnimation");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_animations of class  wyArcticFileData */
#ifndef TOLUA_DISABLE_tolua_set_wyArcticFileData_m_animations_ptr
static int tolua_set_wyArcticFileData_m_animations_ptr(lua_State* tolua_S)
{
  wyArcticFileData* self = (wyArcticFileData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_animations'",NULL);
  if (!tolua_isusertype(tolua_S,2,"wyArcticAnimation",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_animations = ((wyArcticAnimation*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  wyArcticFileData */
#ifndef TOLUA_DISABLE_tolua_afcanim_wyArcticFileData_delete00
static int tolua_afcanim_wyArcticFileData_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyArcticFileData",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyArcticFileData* self = (wyArcticFileData*)  tolua_tousertype(tolua_S,1,0);
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

/* method: make of class  wyArcticFileData */
#ifndef TOLUA_DISABLE_tolua_afcanim_wyArcticFileData_make00
static int tolua_afcanim_wyArcticFileData_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyArcticFileData",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   wyArcticFileData* tolua_ret = (wyArcticFileData*)  wyArcticFileData::make();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyArcticFileData");
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

/* method: load of class  wyArcticLoader */
#ifndef TOLUA_DISABLE_tolua_afcanim_wyArcticLoader_load00
static int tolua_afcanim_wyArcticLoader_load00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyArcticLoader",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  int asResId = ((int)  tolua_tonumber(tolua_S,2,0));
  {
   wyArcticFileData* tolua_ret = (wyArcticFileData*)  wyArcticLoader::load(asResId);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyArcticFileData");
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

/* method: load of class  wyArcticLoader */
#ifndef TOLUA_DISABLE_tolua_afcanim_wyArcticLoader_load01
static int tolua_afcanim_wyArcticLoader_load01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyArcticLoader",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,3,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const char* asPath = ((const char*)  tolua_tostring(tolua_S,2,0));
  bool isFile = ((bool)  tolua_toboolean(tolua_S,3,false));
  {
   wyArcticFileData* tolua_ret = (wyArcticFileData*)  wyArcticLoader::load(asPath,isFile);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyArcticFileData");
  }
 }
 return 1;
tolua_lerror:
 return tolua_afcanim_wyArcticLoader_load00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: loadMemory of class  wyArcticLoader */
#ifndef TOLUA_DISABLE_tolua_afcanim_wyArcticLoader_loadMemory00
static int tolua_afcanim_wyArcticLoader_loadMemory00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyArcticLoader",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* mfsName = ((const char*)  tolua_tostring(tolua_S,2,0));
  {
   wyArcticFileData* tolua_ret = (wyArcticFileData*)  wyArcticLoader::loadMemory(mfsName);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyArcticFileData");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'loadMemory'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  wyArcticSprite */
#ifndef TOLUA_DISABLE_tolua_afcanim_wyArcticSprite_delete00
static int tolua_afcanim_wyArcticSprite_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyArcticSprite",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyArcticSprite* self = (wyArcticSprite*)  tolua_tousertype(tolua_S,1,0);
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

/* method: make of class  wyArcticSprite */
#ifndef TOLUA_DISABLE_tolua_afcanim_wyArcticSprite_make00
static int tolua_afcanim_wyArcticSprite_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyArcticSprite",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,4,"wyTexture2D",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  int asResId = ((int)  tolua_tonumber(tolua_S,2,0));
  int animIndex = ((int)  tolua_tonumber(tolua_S,3,0));
  wyTexture2D* tex = ((wyTexture2D*)  tolua_tousertype(tolua_S,4,0));
  int count = ((int)  tolua_tonumber(tolua_S,5,0));
  {
   wyArcticSprite* tolua_ret = (wyArcticSprite*)  wyArcticSprite::make(asResId,animIndex,&tex,count);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyArcticSprite");
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

/* method: make of class  wyArcticSprite */
#ifndef TOLUA_DISABLE_tolua_afcanim_wyArcticSprite_make01
static int tolua_afcanim_wyArcticSprite_make01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyArcticSprite",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,5,"wyTexture2D",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const char* path = ((const char*)  tolua_tostring(tolua_S,2,0));
  bool isFile = ((bool)  tolua_toboolean(tolua_S,3,0));
  int animIndex = ((int)  tolua_tonumber(tolua_S,4,0));
  wyTexture2D* tex = ((wyTexture2D*)  tolua_tousertype(tolua_S,5,0));
  int count = ((int)  tolua_tonumber(tolua_S,6,0));
  {
   wyArcticSprite* tolua_ret = (wyArcticSprite*)  wyArcticSprite::make(path,isFile,animIndex,&tex,count);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyArcticSprite");
    tolua_pushusertype(tolua_S,(void*)tex,"wyTexture2D");
  }
 }
 return 2;
tolua_lerror:
 return tolua_afcanim_wyArcticSprite_make00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: getAnimationAt of class  wyArcticSprite */
#ifndef TOLUA_DISABLE_tolua_afcanim_wyArcticSprite_getAnimationAt00
static int tolua_afcanim_wyArcticSprite_getAnimationAt00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyArcticSprite",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyArcticSprite* self = (wyArcticSprite*)  tolua_tousertype(tolua_S,1,0);
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getAnimationAt'", NULL);
#endif
  {
   wyAFCAnimation* tolua_ret = (wyAFCAnimation*)  self->getAnimationAt(index);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyAFCAnimation");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getAnimationAt'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getAnimationCount of class  wyArcticSprite */
#ifndef TOLUA_DISABLE_tolua_afcanim_wyArcticSprite_getAnimationCount00
static int tolua_afcanim_wyArcticSprite_getAnimationCount00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyArcticSprite",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyArcticSprite* self = (wyArcticSprite*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getAnimationCount'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getAnimationCount();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getAnimationCount'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getImageCount of class  wyArcticSprite */
#ifndef TOLUA_DISABLE_tolua_afcanim_wyArcticSprite_getImageCount00
static int tolua_afcanim_wyArcticSprite_getImageCount00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyArcticSprite",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyArcticSprite* self = (wyArcticSprite*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getImageCount'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getImageCount();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getImageCount'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_version of class  wySPX3FileData */
#ifndef TOLUA_DISABLE_tolua_get_wySPX3FileData_m_version
static int tolua_get_wySPX3FileData_m_version(lua_State* tolua_S)
{
  wySPX3FileData* self = (wySPX3FileData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_version'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->m_version);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_version of class  wySPX3FileData */
#ifndef TOLUA_DISABLE_tolua_set_wySPX3FileData_m_version
static int tolua_set_wySPX3FileData_m_version(lua_State* tolua_S)
{
  wySPX3FileData* self = (wySPX3FileData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_version'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_version = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_tileSetCount of class  wySPX3FileData */
#ifndef TOLUA_DISABLE_tolua_get_wySPX3FileData_m_tileSetCount
static int tolua_get_wySPX3FileData_m_tileSetCount(lua_State* tolua_S)
{
  wySPX3FileData* self = (wySPX3FileData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_tileSetCount'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->m_tileSetCount);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_tileSetCount of class  wySPX3FileData */
#ifndef TOLUA_DISABLE_tolua_set_wySPX3FileData_m_tileSetCount
static int tolua_set_wySPX3FileData_m_tileSetCount(lua_State* tolua_S)
{
  wySPX3FileData* self = (wySPX3FileData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_tileSetCount'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_tileSetCount = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_frameCount of class  wySPX3FileData */
#ifndef TOLUA_DISABLE_tolua_get_wySPX3FileData_m_frameCount
static int tolua_get_wySPX3FileData_m_frameCount(lua_State* tolua_S)
{
  wySPX3FileData* self = (wySPX3FileData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_frameCount'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->m_frameCount);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_frameCount of class  wySPX3FileData */
#ifndef TOLUA_DISABLE_tolua_set_wySPX3FileData_m_frameCount
static int tolua_set_wySPX3FileData_m_frameCount(lua_State* tolua_S)
{
  wySPX3FileData* self = (wySPX3FileData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_frameCount'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_frameCount = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_actionCount of class  wySPX3FileData */
#ifndef TOLUA_DISABLE_tolua_get_wySPX3FileData_m_actionCount
static int tolua_get_wySPX3FileData_m_actionCount(lua_State* tolua_S)
{
  wySPX3FileData* self = (wySPX3FileData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_actionCount'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->m_actionCount);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_actionCount of class  wySPX3FileData */
#ifndef TOLUA_DISABLE_tolua_set_wySPX3FileData_m_actionCount
static int tolua_set_wySPX3FileData_m_actionCount(lua_State* tolua_S)
{
  wySPX3FileData* self = (wySPX3FileData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_actionCount'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_actionCount = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  wySPX3FileData */
#ifndef TOLUA_DISABLE_tolua_afcanim_wySPX3FileData_delete00
static int tolua_afcanim_wySPX3FileData_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wySPX3FileData",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wySPX3FileData* self = (wySPX3FileData*)  tolua_tousertype(tolua_S,1,0);
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

/* method: make of class  wySPX3FileData */
#ifndef TOLUA_DISABLE_tolua_afcanim_wySPX3FileData_make00
static int tolua_afcanim_wySPX3FileData_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wySPX3FileData",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   wySPX3FileData* tolua_ret = (wySPX3FileData*)  wySPX3FileData::make();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wySPX3FileData");
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

/* method: getTileSetAt of class  wySPX3FileData */
#ifndef TOLUA_DISABLE_tolua_afcanim_wySPX3FileData_getTileSetAt00
static int tolua_afcanim_wySPX3FileData_getTileSetAt00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wySPX3FileData",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wySPX3FileData* self = (wySPX3FileData*)  tolua_tousertype(tolua_S,1,0);
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getTileSetAt'", NULL);
#endif
  {
   wySPX3TileSet* tolua_ret = (wySPX3TileSet*)  self->getTileSetAt(index);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wySPX3TileSet");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getTileSetAt'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getFrameAt of class  wySPX3FileData */
#ifndef TOLUA_DISABLE_tolua_afcanim_wySPX3FileData_getFrameAt00
static int tolua_afcanim_wySPX3FileData_getFrameAt00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wySPX3FileData",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wySPX3FileData* self = (wySPX3FileData*)  tolua_tousertype(tolua_S,1,0);
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getFrameAt'", NULL);
#endif
  {
   wySPX3Frame* tolua_ret = (wySPX3Frame*)  self->getFrameAt(index);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wySPX3Frame");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getFrameAt'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getActionAt of class  wySPX3FileData */
#ifndef TOLUA_DISABLE_tolua_afcanim_wySPX3FileData_getActionAt00
static int tolua_afcanim_wySPX3FileData_getActionAt00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wySPX3FileData",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wySPX3FileData* self = (wySPX3FileData*)  tolua_tousertype(tolua_S,1,0);
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getActionAt'", NULL);
#endif
  {
   wySPX3Action* tolua_ret = (wySPX3Action*)  self->getActionAt(index);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wySPX3Action");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getActionAt'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: type of class  wySPX3Patch */
#ifndef TOLUA_DISABLE_tolua_get_wySPX3Patch_type
static int tolua_get_wySPX3Patch_type(lua_State* tolua_S)
{
  wySPX3Patch* self = (wySPX3Patch*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'type'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->type);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: type of class  wySPX3Patch */
#ifndef TOLUA_DISABLE_tolua_set_wySPX3Patch_type
static int tolua_set_wySPX3Patch_type(lua_State* tolua_S)
{
  wySPX3Patch* self = (wySPX3Patch*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'type'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->type = ((wySPX3PatchType) (int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_flags of class  wySPX3Frame */
#ifndef TOLUA_DISABLE_tolua_get_wySPX3Frame_m_flags
static int tolua_get_wySPX3Frame_m_flags(lua_State* tolua_S)
{
  wySPX3Frame* self = (wySPX3Frame*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_flags'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->m_flags);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_flags of class  wySPX3Frame */
#ifndef TOLUA_DISABLE_tolua_set_wySPX3Frame_m_flags
static int tolua_set_wySPX3Frame_m_flags(lua_State* tolua_S)
{
  wySPX3Frame* self = (wySPX3Frame*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_flags'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_flags = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_rect of class  wySPX3Frame */
#ifndef TOLUA_DISABLE_tolua_get_wySPX3Frame_m_rect
static int tolua_get_wySPX3Frame_m_rect(lua_State* tolua_S)
{
  wySPX3Frame* self = (wySPX3Frame*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_rect'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->m_rect,"wySPX3Tile");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_rect of class  wySPX3Frame */
#ifndef TOLUA_DISABLE_tolua_set_wySPX3Frame_m_rect
static int tolua_set_wySPX3Frame_m_rect(lua_State* tolua_S)
{
  wySPX3Frame* self = (wySPX3Frame*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_rect'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"wySPX3Tile",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_rect = *((wySPX3Tile*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_patchCount of class  wySPX3Frame */
#ifndef TOLUA_DISABLE_tolua_get_wySPX3Frame_m_patchCount
static int tolua_get_wySPX3Frame_m_patchCount(lua_State* tolua_S)
{
  wySPX3Frame* self = (wySPX3Frame*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_patchCount'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->m_patchCount);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_patchCount of class  wySPX3Frame */
#ifndef TOLUA_DISABLE_tolua_set_wySPX3Frame_m_patchCount
static int tolua_set_wySPX3Frame_m_patchCount(lua_State* tolua_S)
{
  wySPX3Frame* self = (wySPX3Frame*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_patchCount'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_patchCount = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_patches of class  wySPX3Frame */
#ifndef TOLUA_DISABLE_tolua_get_wySPX3Frame_m_patches_ptr
static int tolua_get_wySPX3Frame_m_patches_ptr(lua_State* tolua_S)
{
  wySPX3Frame* self = (wySPX3Frame*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_patches'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->m_patches,"wySPX3Patch");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_patches of class  wySPX3Frame */
#ifndef TOLUA_DISABLE_tolua_set_wySPX3Frame_m_patches_ptr
static int tolua_set_wySPX3Frame_m_patches_ptr(lua_State* tolua_S)
{
  wySPX3Frame* self = (wySPX3Frame*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_patches'",NULL);
  if (!tolua_isusertype(tolua_S,2,"wySPX3Patch",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_patches = ((wySPX3Patch*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_collisionCount of class  wySPX3Frame */
#ifndef TOLUA_DISABLE_tolua_get_wySPX3Frame_m_collisionCount
static int tolua_get_wySPX3Frame_m_collisionCount(lua_State* tolua_S)
{
  wySPX3Frame* self = (wySPX3Frame*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_collisionCount'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->m_collisionCount);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_collisionCount of class  wySPX3Frame */
#ifndef TOLUA_DISABLE_tolua_set_wySPX3Frame_m_collisionCount
static int tolua_set_wySPX3Frame_m_collisionCount(lua_State* tolua_S)
{
  wySPX3Frame* self = (wySPX3Frame*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_collisionCount'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_collisionCount = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_collisionRects of class  wySPX3Frame */
#ifndef TOLUA_DISABLE_tolua_get_wySPX3Frame_m_collisionRects_ptr
static int tolua_get_wySPX3Frame_m_collisionRects_ptr(lua_State* tolua_S)
{
  wySPX3Frame* self = (wySPX3Frame*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_collisionRects'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->m_collisionRects,"wySPX3Tile");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_collisionRects of class  wySPX3Frame */
#ifndef TOLUA_DISABLE_tolua_set_wySPX3Frame_m_collisionRects_ptr
static int tolua_set_wySPX3Frame_m_collisionRects_ptr(lua_State* tolua_S)
{
  wySPX3Frame* self = (wySPX3Frame*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_collisionRects'",NULL);
  if (!tolua_isusertype(tolua_S,2,"wySPX3Tile",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_collisionRects = ((wySPX3Tile*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  wySPX3Frame */
#ifndef TOLUA_DISABLE_tolua_afcanim_wySPX3Frame_delete00
static int tolua_afcanim_wySPX3Frame_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wySPX3Frame",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wySPX3Frame* self = (wySPX3Frame*)  tolua_tousertype(tolua_S,1,0);
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

/* method: make of class  wySPX3Frame */
#ifndef TOLUA_DISABLE_tolua_afcanim_wySPX3Frame_make00
static int tolua_afcanim_wySPX3Frame_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wySPX3Frame",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   wySPX3Frame* tolua_ret = (wySPX3Frame*)  wySPX3Frame::make();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wySPX3Frame");
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

/* method: load of class  wySPX3Loader */
#ifndef TOLUA_DISABLE_tolua_afcanim_wySPX3Loader_load00
static int tolua_afcanim_wySPX3Loader_load00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wySPX3Loader",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  int spxResId = ((int)  tolua_tonumber(tolua_S,2,0));
  {
   wySPX3FileData* tolua_ret = (wySPX3FileData*)  wySPX3Loader::load(spxResId);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wySPX3FileData");
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

/* method: load of class  wySPX3Loader */
#ifndef TOLUA_DISABLE_tolua_afcanim_wySPX3Loader_load01
static int tolua_afcanim_wySPX3Loader_load01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wySPX3Loader",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,3,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const char* spxPath = ((const char*)  tolua_tostring(tolua_S,2,0));
  bool isFile = ((bool)  tolua_toboolean(tolua_S,3,false));
  {
   wySPX3FileData* tolua_ret = (wySPX3FileData*)  wySPX3Loader::load(spxPath,isFile);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wySPX3FileData");
  }
 }
 return 1;
tolua_lerror:
 return tolua_afcanim_wySPX3Loader_load00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: loadMemory of class  wySPX3Loader */
#ifndef TOLUA_DISABLE_tolua_afcanim_wySPX3Loader_loadMemory00
static int tolua_afcanim_wySPX3Loader_loadMemory00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wySPX3Loader",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* mfsName = ((const char*)  tolua_tostring(tolua_S,2,0));
  {
   wySPX3FileData* tolua_ret = (wySPX3FileData*)  wySPX3Loader::loadMemory(mfsName);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wySPX3FileData");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'loadMemory'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  wySPX3Sprite */
#ifndef TOLUA_DISABLE_tolua_afcanim_wySPX3Sprite_delete00
static int tolua_afcanim_wySPX3Sprite_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wySPX3Sprite",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wySPX3Sprite* self = (wySPX3Sprite*)  tolua_tousertype(tolua_S,1,0);
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

/* method: make of class  wySPX3Sprite */
#ifndef TOLUA_DISABLE_tolua_afcanim_wySPX3Sprite_make00
static int tolua_afcanim_wySPX3Sprite_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wySPX3Sprite",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,4,"wyTexture2D",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  int spxResId = ((int)  tolua_tonumber(tolua_S,2,0));
  int actionIndex = ((int)  tolua_tonumber(tolua_S,3,0));
  wyTexture2D* tex = ((wyTexture2D*)  tolua_tousertype(tolua_S,4,0));
  int count = ((int)  tolua_tonumber(tolua_S,5,0));
  {
   wySPX3Sprite* tolua_ret = (wySPX3Sprite*)  wySPX3Sprite::make(spxResId,actionIndex,&tex,count);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wySPX3Sprite");
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

/* method: make of class  wySPX3Sprite */
#ifndef TOLUA_DISABLE_tolua_afcanim_wySPX3Sprite_make01
static int tolua_afcanim_wySPX3Sprite_make01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wySPX3Sprite",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,5,"wyTexture2D",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const char* spxPath = ((const char*)  tolua_tostring(tolua_S,2,0));
  bool isFile = ((bool)  tolua_toboolean(tolua_S,3,0));
  int actionIndex = ((int)  tolua_tonumber(tolua_S,4,0));
  wyTexture2D* tex = ((wyTexture2D*)  tolua_tousertype(tolua_S,5,0));
  int count = ((int)  tolua_tonumber(tolua_S,6,0));
  {
   wySPX3Sprite* tolua_ret = (wySPX3Sprite*)  wySPX3Sprite::make(spxPath,isFile,actionIndex,&tex,count);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wySPX3Sprite");
    tolua_pushusertype(tolua_S,(void*)tex,"wyTexture2D");
  }
 }
 return 2;
tolua_lerror:
 return tolua_afcanim_wySPX3Sprite_make00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: getAnimationAt of class  wySPX3Sprite */
#ifndef TOLUA_DISABLE_tolua_afcanim_wySPX3Sprite_getAnimationAt00
static int tolua_afcanim_wySPX3Sprite_getAnimationAt00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wySPX3Sprite",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wySPX3Sprite* self = (wySPX3Sprite*)  tolua_tousertype(tolua_S,1,0);
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getAnimationAt'", NULL);
#endif
  {
   wyAFCAnimation* tolua_ret = (wyAFCAnimation*)  self->getAnimationAt(index);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyAFCAnimation");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getAnimationAt'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getAnimationCount of class  wySPX3Sprite */
#ifndef TOLUA_DISABLE_tolua_afcanim_wySPX3Sprite_getAnimationCount00
static int tolua_afcanim_wySPX3Sprite_getAnimationCount00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wySPX3Sprite",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wySPX3Sprite* self = (wySPX3Sprite*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getAnimationCount'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getAnimationCount();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getAnimationCount'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getImageCount of class  wySPX3Sprite */
#ifndef TOLUA_DISABLE_tolua_afcanim_wySPX3Sprite_getImageCount00
static int tolua_afcanim_wySPX3Sprite_getImageCount00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wySPX3Sprite",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wySPX3Sprite* self = (wySPX3Sprite*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getImageCount'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getImageCount();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getImageCount'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: x1 of class  wySPX3Tile */
#ifndef TOLUA_DISABLE_tolua_get_wySPX3Tile_x1
static int tolua_get_wySPX3Tile_x1(lua_State* tolua_S)
{
  wySPX3Tile* self = (wySPX3Tile*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'x1'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->x1);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: x1 of class  wySPX3Tile */
#ifndef TOLUA_DISABLE_tolua_set_wySPX3Tile_x1
static int tolua_set_wySPX3Tile_x1(lua_State* tolua_S)
{
  wySPX3Tile* self = (wySPX3Tile*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'x1'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->x1 = ((short)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: y1 of class  wySPX3Tile */
#ifndef TOLUA_DISABLE_tolua_get_wySPX3Tile_y1
static int tolua_get_wySPX3Tile_y1(lua_State* tolua_S)
{
  wySPX3Tile* self = (wySPX3Tile*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'y1'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->y1);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: y1 of class  wySPX3Tile */
#ifndef TOLUA_DISABLE_tolua_set_wySPX3Tile_y1
static int tolua_set_wySPX3Tile_y1(lua_State* tolua_S)
{
  wySPX3Tile* self = (wySPX3Tile*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'y1'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->y1 = ((short)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: x2 of class  wySPX3Tile */
#ifndef TOLUA_DISABLE_tolua_get_wySPX3Tile_x2
static int tolua_get_wySPX3Tile_x2(lua_State* tolua_S)
{
  wySPX3Tile* self = (wySPX3Tile*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'x2'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->x2);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: x2 of class  wySPX3Tile */
#ifndef TOLUA_DISABLE_tolua_set_wySPX3Tile_x2
static int tolua_set_wySPX3Tile_x2(lua_State* tolua_S)
{
  wySPX3Tile* self = (wySPX3Tile*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'x2'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->x2 = ((short)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: y2 of class  wySPX3Tile */
#ifndef TOLUA_DISABLE_tolua_get_wySPX3Tile_y2
static int tolua_get_wySPX3Tile_y2(lua_State* tolua_S)
{
  wySPX3Tile* self = (wySPX3Tile*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'y2'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->y2);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: y2 of class  wySPX3Tile */
#ifndef TOLUA_DISABLE_tolua_set_wySPX3Tile_y2
static int tolua_set_wySPX3Tile_y2(lua_State* tolua_S)
{
  wySPX3Tile* self = (wySPX3Tile*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'y2'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->y2 = ((short)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: left of class  wySPX3Tile */
#ifndef TOLUA_DISABLE_tolua_afcanim_wySPX3Tile_left00
static int tolua_afcanim_wySPX3Tile_left00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wySPX3Tile",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wySPX3Tile* self = (wySPX3Tile*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'left'", NULL);
#endif
  {
   short tolua_ret = (short)  self->left();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'left'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: bottom of class  wySPX3Tile */
#ifndef TOLUA_DISABLE_tolua_afcanim_wySPX3Tile_bottom00
static int tolua_afcanim_wySPX3Tile_bottom00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wySPX3Tile",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wySPX3Tile* self = (wySPX3Tile*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'bottom'", NULL);
#endif
  {
   short tolua_ret = (short)  self->bottom();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'bottom'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: right of class  wySPX3Tile */
#ifndef TOLUA_DISABLE_tolua_afcanim_wySPX3Tile_right00
static int tolua_afcanim_wySPX3Tile_right00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wySPX3Tile",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wySPX3Tile* self = (wySPX3Tile*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'right'", NULL);
#endif
  {
   short tolua_ret = (short)  self->right();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'right'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: top of class  wySPX3Tile */
#ifndef TOLUA_DISABLE_tolua_afcanim_wySPX3Tile_top00
static int tolua_afcanim_wySPX3Tile_top00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wySPX3Tile",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wySPX3Tile* self = (wySPX3Tile*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'top'", NULL);
#endif
  {
   short tolua_ret = (short)  self->top();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'top'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: width of class  wySPX3Tile */
#ifndef TOLUA_DISABLE_tolua_afcanim_wySPX3Tile_width00
static int tolua_afcanim_wySPX3Tile_width00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wySPX3Tile",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wySPX3Tile* self = (wySPX3Tile*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'width'", NULL);
#endif
  {
   short tolua_ret = (short)  self->width();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'width'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: height of class  wySPX3Tile */
#ifndef TOLUA_DISABLE_tolua_afcanim_wySPX3Tile_height00
static int tolua_afcanim_wySPX3Tile_height00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wySPX3Tile",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wySPX3Tile* self = (wySPX3Tile*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'height'", NULL);
#endif
  {
   short tolua_ret = (short)  self->height();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'height'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_mode of class  wySPX3TileSet */
#ifndef TOLUA_DISABLE_tolua_get_wySPX3TileSet_m_mode
static int tolua_get_wySPX3TileSet_m_mode(lua_State* tolua_S)
{
  wySPX3TileSet* self = (wySPX3TileSet*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_mode'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->m_mode);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_mode of class  wySPX3TileSet */
#ifndef TOLUA_DISABLE_tolua_set_wySPX3TileSet_m_mode
static int tolua_set_wySPX3TileSet_m_mode(lua_State* tolua_S)
{
  wySPX3TileSet* self = (wySPX3TileSet*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_mode'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_mode = ((wySPX3TileSetMode) (int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_imageIndex of class  wySPX3TileSet */
#ifndef TOLUA_DISABLE_tolua_get_wySPX3TileSet_m_imageIndex
static int tolua_get_wySPX3TileSet_m_imageIndex(lua_State* tolua_S)
{
  wySPX3TileSet* self = (wySPX3TileSet*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_imageIndex'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->m_imageIndex);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_imageIndex of class  wySPX3TileSet */
#ifndef TOLUA_DISABLE_tolua_set_wySPX3TileSet_m_imageIndex
static int tolua_set_wySPX3TileSet_m_imageIndex(lua_State* tolua_S)
{
  wySPX3TileSet* self = (wySPX3TileSet*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_imageIndex'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_imageIndex = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_tileWidth of class  wySPX3TileSet */
#ifndef TOLUA_DISABLE_tolua_get_wySPX3TileSet_m_tileWidth
static int tolua_get_wySPX3TileSet_m_tileWidth(lua_State* tolua_S)
{
  wySPX3TileSet* self = (wySPX3TileSet*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_tileWidth'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->m_tileWidth);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_tileWidth of class  wySPX3TileSet */
#ifndef TOLUA_DISABLE_tolua_set_wySPX3TileSet_m_tileWidth
static int tolua_set_wySPX3TileSet_m_tileWidth(lua_State* tolua_S)
{
  wySPX3TileSet* self = (wySPX3TileSet*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_tileWidth'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_tileWidth = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_tileHeight of class  wySPX3TileSet */
#ifndef TOLUA_DISABLE_tolua_get_wySPX3TileSet_m_tileHeight
static int tolua_get_wySPX3TileSet_m_tileHeight(lua_State* tolua_S)
{
  wySPX3TileSet* self = (wySPX3TileSet*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_tileHeight'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->m_tileHeight);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_tileHeight of class  wySPX3TileSet */
#ifndef TOLUA_DISABLE_tolua_set_wySPX3TileSet_m_tileHeight
static int tolua_set_wySPX3TileSet_m_tileHeight(lua_State* tolua_S)
{
  wySPX3TileSet* self = (wySPX3TileSet*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_tileHeight'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_tileHeight = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_tileColumns of class  wySPX3TileSet */
#ifndef TOLUA_DISABLE_tolua_get_wySPX3TileSet_m_tileColumns
static int tolua_get_wySPX3TileSet_m_tileColumns(lua_State* tolua_S)
{
  wySPX3TileSet* self = (wySPX3TileSet*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_tileColumns'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->m_tileColumns);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_tileColumns of class  wySPX3TileSet */
#ifndef TOLUA_DISABLE_tolua_set_wySPX3TileSet_m_tileColumns
static int tolua_set_wySPX3TileSet_m_tileColumns(lua_State* tolua_S)
{
  wySPX3TileSet* self = (wySPX3TileSet*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_tileColumns'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_tileColumns = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_tileRows of class  wySPX3TileSet */
#ifndef TOLUA_DISABLE_tolua_get_wySPX3TileSet_m_tileRows
static int tolua_get_wySPX3TileSet_m_tileRows(lua_State* tolua_S)
{
  wySPX3TileSet* self = (wySPX3TileSet*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_tileRows'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->m_tileRows);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_tileRows of class  wySPX3TileSet */
#ifndef TOLUA_DISABLE_tolua_set_wySPX3TileSet_m_tileRows
static int tolua_set_wySPX3TileSet_m_tileRows(lua_State* tolua_S)
{
  wySPX3TileSet* self = (wySPX3TileSet*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_tileRows'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_tileRows = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_tileCount of class  wySPX3TileSet */
#ifndef TOLUA_DISABLE_tolua_get_wySPX3TileSet_m_tileCount
static int tolua_get_wySPX3TileSet_m_tileCount(lua_State* tolua_S)
{
  wySPX3TileSet* self = (wySPX3TileSet*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_tileCount'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->m_tileCount);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_tileCount of class  wySPX3TileSet */
#ifndef TOLUA_DISABLE_tolua_set_wySPX3TileSet_m_tileCount
static int tolua_set_wySPX3TileSet_m_tileCount(lua_State* tolua_S)
{
  wySPX3TileSet* self = (wySPX3TileSet*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_tileCount'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_tileCount = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_tiles of class  wySPX3TileSet */
#ifndef TOLUA_DISABLE_tolua_get_wySPX3TileSet_m_tiles_ptr
static int tolua_get_wySPX3TileSet_m_tiles_ptr(lua_State* tolua_S)
{
  wySPX3TileSet* self = (wySPX3TileSet*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_tiles'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->m_tiles,"wySPX3Tile");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_tiles of class  wySPX3TileSet */
#ifndef TOLUA_DISABLE_tolua_set_wySPX3TileSet_m_tiles_ptr
static int tolua_set_wySPX3TileSet_m_tiles_ptr(lua_State* tolua_S)
{
  wySPX3TileSet* self = (wySPX3TileSet*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_tiles'",NULL);
  if (!tolua_isusertype(tolua_S,2,"wySPX3Tile",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_tiles = ((wySPX3Tile*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  wySPX3TileSet */
#ifndef TOLUA_DISABLE_tolua_afcanim_wySPX3TileSet_delete00
static int tolua_afcanim_wySPX3TileSet_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wySPX3TileSet",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wySPX3TileSet* self = (wySPX3TileSet*)  tolua_tousertype(tolua_S,1,0);
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

/* method: make of class  wySPX3TileSet */
#ifndef TOLUA_DISABLE_tolua_afcanim_wySPX3TileSet_make00
static int tolua_afcanim_wySPX3TileSet_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wySPX3TileSet",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   wySPX3TileSet* tolua_ret = (wySPX3TileSet*)  wySPX3TileSet::make();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wySPX3TileSet");
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

/* method: delete of class  wyAuroraSprite */
#ifndef TOLUA_DISABLE_tolua_afcanim_wyAuroraSprite_delete00
static int tolua_afcanim_wyAuroraSprite_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAuroraSprite",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAuroraSprite* self = (wyAuroraSprite*)  tolua_tousertype(tolua_S,1,0);
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

/* method: make of class  wyAuroraSprite */
#ifndef TOLUA_DISABLE_tolua_afcanim_wyAuroraSprite_make00
static int tolua_afcanim_wyAuroraSprite_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyAuroraSprite",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,4,"wyTexture2D",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  int bsResId = ((int)  tolua_tonumber(tolua_S,2,0));
  int animIndex = ((int)  tolua_tonumber(tolua_S,3,0));
  wyTexture2D* tex = ((wyTexture2D*)  tolua_tousertype(tolua_S,4,0));
  int count = ((int)  tolua_tonumber(tolua_S,5,0));
  {
   wyAuroraSprite* tolua_ret = (wyAuroraSprite*)  wyAuroraSprite::make(bsResId,animIndex,&tex,count);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyAuroraSprite");
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

/* method: make of class  wyAuroraSprite */
#ifndef TOLUA_DISABLE_tolua_afcanim_wyAuroraSprite_make01
static int tolua_afcanim_wyAuroraSprite_make01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyAuroraSprite",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,5,"wyTexture2D",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const char* path = ((const char*)  tolua_tostring(tolua_S,2,0));
  bool isFile = ((bool)  tolua_toboolean(tolua_S,3,0));
  int animIndex = ((int)  tolua_tonumber(tolua_S,4,0));
  wyTexture2D* tex = ((wyTexture2D*)  tolua_tousertype(tolua_S,5,0));
  int count = ((int)  tolua_tonumber(tolua_S,6,0));
  {
   wyAuroraSprite* tolua_ret = (wyAuroraSprite*)  wyAuroraSprite::make(path,isFile,animIndex,&tex,count);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyAuroraSprite");
    tolua_pushusertype(tolua_S,(void*)tex,"wyTexture2D");
  }
 }
 return 2;
tolua_lerror:
 return tolua_afcanim_wyAuroraSprite_make00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: getAnimationAt of class  wyAuroraSprite */
#ifndef TOLUA_DISABLE_tolua_afcanim_wyAuroraSprite_getAnimationAt00
static int tolua_afcanim_wyAuroraSprite_getAnimationAt00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAuroraSprite",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAuroraSprite* self = (wyAuroraSprite*)  tolua_tousertype(tolua_S,1,0);
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getAnimationAt'", NULL);
#endif
  {
   wyAFCAnimation* tolua_ret = (wyAFCAnimation*)  self->getAnimationAt(index);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyAFCAnimation");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getAnimationAt'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getAnimationCount of class  wyAuroraSprite */
#ifndef TOLUA_DISABLE_tolua_afcanim_wyAuroraSprite_getAnimationCount00
static int tolua_afcanim_wyAuroraSprite_getAnimationCount00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAuroraSprite",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAuroraSprite* self = (wyAuroraSprite*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getAnimationCount'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getAnimationCount();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getAnimationCount'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getImageCount of class  wyAuroraSprite */
#ifndef TOLUA_DISABLE_tolua_afcanim_wyAuroraSprite_getImageCount00
static int tolua_afcanim_wyAuroraSprite_getImageCount00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAuroraSprite",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAuroraSprite* self = (wyAuroraSprite*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getImageCount'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getImageCount();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getImageCount'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  wyAFCClipMapping */
#ifndef TOLUA_DISABLE_tolua_afcanim_wyAFCClipMapping_delete00
static int tolua_afcanim_wyAFCClipMapping_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAFCClipMapping",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAFCClipMapping* self = (wyAFCClipMapping*)  tolua_tousertype(tolua_S,1,0);
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

/* method: make of class  wyAFCClipMapping */
#ifndef TOLUA_DISABLE_tolua_afcanim_wyAFCClipMapping_make00
static int tolua_afcanim_wyAFCClipMapping_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyAFCClipMapping",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  int tag = ((int)  tolua_tonumber(tolua_S,2,0));
  {
   wyAFCClipMapping* tolua_ret = (wyAFCClipMapping*)  wyAFCClipMapping::make(tag);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyAFCClipMapping");
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

/* method: makeAurora of class  wyAFCClipMapping */
#ifndef TOLUA_DISABLE_tolua_afcanim_wyAFCClipMapping_makeAurora00
static int tolua_afcanim_wyAFCClipMapping_makeAurora00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyAFCClipMapping",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  int tag = ((int)  tolua_tonumber(tolua_S,2,0));
  int ammId = ((int)  tolua_tonumber(tolua_S,3,0));
  {
   wyAFCClipMapping* tolua_ret = (wyAFCClipMapping*)  wyAFCClipMapping::makeAurora(tag,ammId);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyAFCClipMapping");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'makeAurora'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: makeAurora of class  wyAFCClipMapping */
#ifndef TOLUA_DISABLE_tolua_afcanim_wyAFCClipMapping_makeAurora01
static int tolua_afcanim_wyAFCClipMapping_makeAurora01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyAFCClipMapping",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,4,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  int tag = ((int)  tolua_tonumber(tolua_S,2,0));
  const char* ammPath = ((const char*)  tolua_tostring(tolua_S,3,0));
  bool isFile = ((bool)  tolua_toboolean(tolua_S,4,false));
  {
   wyAFCClipMapping* tolua_ret = (wyAFCClipMapping*)  wyAFCClipMapping::makeAurora(tag,ammPath,isFile);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyAFCClipMapping");
  }
 }
 return 1;
tolua_lerror:
 return tolua_afcanim_wyAFCClipMapping_makeAurora00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: makeMemoryAurora of class  wyAFCClipMapping */
#ifndef TOLUA_DISABLE_tolua_afcanim_wyAFCClipMapping_makeMemoryAurora00
static int tolua_afcanim_wyAFCClipMapping_makeMemoryAurora00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyAFCClipMapping",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  int tag = ((int)  tolua_tonumber(tolua_S,2,0));
  const char* mfsName = ((const char*)  tolua_tostring(tolua_S,3,0));
  {
   wyAFCClipMapping* tolua_ret = (wyAFCClipMapping*)  wyAFCClipMapping::makeMemoryAurora(tag,mfsName);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyAFCClipMapping");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'makeMemoryAurora'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: mapClip of class  wyAFCClipMapping */
#ifndef TOLUA_DISABLE_tolua_afcanim_wyAFCClipMapping_mapClip00
static int tolua_afcanim_wyAFCClipMapping_mapClip00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAFCClipMapping",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAFCClipMapping* self = (wyAFCClipMapping*)  tolua_tousertype(tolua_S,1,0);
  int fromClipIndex = ((int)  tolua_tonumber(tolua_S,2,0));
  int toClipIndex = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'mapClip'", NULL);
#endif
  {
   self->mapClip(fromClipIndex,toClipIndex);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'mapClip'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: mapClip of class  wyAFCClipMapping */
#ifndef TOLUA_DISABLE_tolua_afcanim_wyAFCClipMapping_mapClip01
static int tolua_afcanim_wyAFCClipMapping_mapClip01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAFCClipMapping",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  wyAFCClipMapping* self = (wyAFCClipMapping*)  tolua_tousertype(tolua_S,1,0);
  int fromClipIndex = ((int)  tolua_tonumber(tolua_S,2,0));
  int externalFileDataId = ((int)  tolua_tonumber(tolua_S,3,0));
  int toClipIndex = ((int)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'mapClip'", NULL);
#endif
  {
   self->mapClip(fromClipIndex,externalFileDataId,toClipIndex);
  }
 }
 return 0;
tolua_lerror:
 return tolua_afcanim_wyAFCClipMapping_mapClip00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: mapClip of class  wyAFCClipMapping */
#ifndef TOLUA_DISABLE_tolua_afcanim_wyAFCClipMapping_mapClip02
static int tolua_afcanim_wyAFCClipMapping_mapClip02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAFCClipMapping",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"wyTexture2D",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"wyPoint",1,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,5,&tolua_err) || !tolua_isusertype(tolua_S,5,"wyRect",1,&tolua_err)) ||
     !tolua_isboolean(tolua_S,6,1,&tolua_err) ||
     !tolua_isboolean(tolua_S,7,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,8,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  wyAFCClipMapping* self = (wyAFCClipMapping*)  tolua_tousertype(tolua_S,1,0);
  int fromClipIndex = ((int)  tolua_tonumber(tolua_S,2,0));
  wyTexture2D* tex = ((wyTexture2D*)  tolua_tousertype(tolua_S,3,0));
  wyPoint pos = *((wyPoint*)  tolua_tousertype(tolua_S,4,(void*)&(const wyPoint)wypZero));
  wyRect texRect = *((wyRect*)  tolua_tousertype(tolua_S,5,(void*)&(const wyRect)wyrZero));
  bool flipX = ((bool)  tolua_toboolean(tolua_S,6,false));
  bool flipY = ((bool)  tolua_toboolean(tolua_S,7,false));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'mapClip'", NULL);
#endif
  {
   self->mapClip(fromClipIndex,tex,pos,texRect,flipX,flipY);
  }
 }
 return 0;
tolua_lerror:
 return tolua_afcanim_wyAFCClipMapping_mapClip01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: getTag of class  wyAFCClipMapping */
#ifndef TOLUA_DISABLE_tolua_afcanim_wyAFCClipMapping_getTag00
static int tolua_afcanim_wyAFCClipMapping_getTag00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAFCClipMapping",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAFCClipMapping* self = (wyAFCClipMapping*)  tolua_tousertype(tolua_S,1,0);
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

/* method: findRule of class  wyAFCClipMapping */
#ifndef TOLUA_DISABLE_tolua_afcanim_wyAFCClipMapping_findRule00
static int tolua_afcanim_wyAFCClipMapping_findRule00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAFCClipMapping",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAFCClipMapping* self = (wyAFCClipMapping*)  tolua_tousertype(tolua_S,1,0);
  int sourceClipIndex = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'findRule'", NULL);
#endif
  {
   wyAFCClipMappingRule* tolua_ret = (wyAFCClipMappingRule*)  self->findRule(sourceClipIndex);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyAFCClipMappingRule");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'findRule'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  wyAFCSprite */
#ifndef TOLUA_DISABLE_tolua_afcanim_wyAFCSprite_delete00
static int tolua_afcanim_wyAFCSprite_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAFCSprite",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAFCSprite* self = (wyAFCSprite*)  tolua_tousertype(tolua_S,1,0);
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

/* method: getAlpha of class  wyAFCSprite */
#ifndef TOLUA_DISABLE_tolua_afcanim_wyAFCSprite_getAlpha00
static int tolua_afcanim_wyAFCSprite_getAlpha00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAFCSprite",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAFCSprite* self = (wyAFCSprite*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getAlpha'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getAlpha();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getAlpha'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setAlpha of class  wyAFCSprite */
#ifndef TOLUA_DISABLE_tolua_afcanim_wyAFCSprite_setAlpha00
static int tolua_afcanim_wyAFCSprite_setAlpha00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAFCSprite",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAFCSprite* self = (wyAFCSprite*)  tolua_tousertype(tolua_S,1,0);
  int alpha = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setAlpha'", NULL);
#endif
  {
   self->setAlpha(alpha);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setAlpha'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getColor of class  wyAFCSprite */
#ifndef TOLUA_DISABLE_tolua_afcanim_wyAFCSprite_getColor00
static int tolua_afcanim_wyAFCSprite_getColor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAFCSprite",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAFCSprite* self = (wyAFCSprite*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getColor'", NULL);
#endif
  {
   wyColor3B tolua_ret = (wyColor3B)  self->getColor();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((wyColor3B)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"wyColor3B");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(wyColor3B));
     tolua_pushusertype(tolua_S,tolua_obj,"wyColor3B");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
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

/* method: setColor of class  wyAFCSprite */
#ifndef TOLUA_DISABLE_tolua_afcanim_wyAFCSprite_setColor00
static int tolua_afcanim_wyAFCSprite_setColor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAFCSprite",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"wyColor3B",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAFCSprite* self = (wyAFCSprite*)  tolua_tousertype(tolua_S,1,0);
  wyColor3B color = *((wyColor3B*)  tolua_tousertype(tolua_S,2,0));
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

/* method: setColor of class  wyAFCSprite */
#ifndef TOLUA_DISABLE_tolua_afcanim_wyAFCSprite_setColor01
static int tolua_afcanim_wyAFCSprite_setColor01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAFCSprite",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"wyColor4B",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  wyAFCSprite* self = (wyAFCSprite*)  tolua_tousertype(tolua_S,1,0);
  wyColor4B color = *((wyColor4B*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setColor'", NULL);
#endif
  {
   self->setColor(color);
  }
 }
 return 0;
tolua_lerror:
 return tolua_afcanim_wyAFCSprite_setColor00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: addChild of class  wyAFCSprite */
#ifndef TOLUA_DISABLE_tolua_afcanim_wyAFCSprite_addChild00
static int tolua_afcanim_wyAFCSprite_addChild00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAFCSprite",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyNode",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAFCSprite* self = (wyAFCSprite*)  tolua_tousertype(tolua_S,1,0);
  wyNode* child = ((wyNode*)  tolua_tousertype(tolua_S,2,0));
  int z = ((int)  tolua_tonumber(tolua_S,3,0));
  int tag = ((int)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addChild'", NULL);
#endif
  {
   self->addChild(child,z,tag);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addChild'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getAnimationAt of class  wyAFCSprite */
#ifndef TOLUA_DISABLE_tolua_afcanim_wyAFCSprite_getAnimationAt00
static int tolua_afcanim_wyAFCSprite_getAnimationAt00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAFCSprite",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAFCSprite* self = (wyAFCSprite*)  tolua_tousertype(tolua_S,1,0);
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getAnimationAt'", NULL);
#endif
  {
   wyAFCAnimation* tolua_ret = (wyAFCAnimation*)  self->getAnimationAt(index);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyAFCAnimation");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getAnimationAt'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getAnimationCount of class  wyAFCSprite */
#ifndef TOLUA_DISABLE_tolua_afcanim_wyAFCSprite_getAnimationCount00
static int tolua_afcanim_wyAFCSprite_getAnimationCount00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAFCSprite",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAFCSprite* self = (wyAFCSprite*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getAnimationCount'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getAnimationCount();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getAnimationCount'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getImageCount of class  wyAFCSprite */
#ifndef TOLUA_DISABLE_tolua_afcanim_wyAFCSprite_getImageCount00
static int tolua_afcanim_wyAFCSprite_getImageCount00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAFCSprite",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAFCSprite* self = (wyAFCSprite*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getImageCount'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getImageCount();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getImageCount'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: playAnimation of class  wyAFCSprite */
#ifndef TOLUA_DISABLE_tolua_afcanim_wyAFCSprite_playAnimation00
static int tolua_afcanim_wyAFCSprite_playAnimation00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAFCSprite",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"wyAFCClipMapping",1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAFCSprite* self = (wyAFCSprite*)  tolua_tousertype(tolua_S,1,0);
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
  wyAFCClipMapping* mapping = ((wyAFCClipMapping*)  tolua_tousertype(tolua_S,3,NULL));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'playAnimation'", NULL);
#endif
  {
   self->playAnimation(index,mapping);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'playAnimation'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: playAnimation of class  wyAFCSprite */
#ifndef TOLUA_DISABLE_tolua_afcanim_wyAFCSprite_playAnimation01
static int tolua_afcanim_wyAFCSprite_playAnimation01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAFCSprite",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  wyAFCSprite* self = (wyAFCSprite*)  tolua_tousertype(tolua_S,1,0);
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
  int mappingTag = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'playAnimation'", NULL);
#endif
  {
   self->playAnimation(index,mappingTag);
  }
 }
 return 0;
tolua_lerror:
 return tolua_afcanim_wyAFCSprite_playAnimation00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: setFrameIndex of class  wyAFCSprite */
#ifndef TOLUA_DISABLE_tolua_afcanim_wyAFCSprite_setFrameIndex00
static int tolua_afcanim_wyAFCSprite_setFrameIndex00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAFCSprite",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAFCSprite* self = (wyAFCSprite*)  tolua_tousertype(tolua_S,1,0);
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setFrameIndex'", NULL);
#endif
  {
   self->setFrameIndex(index);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setFrameIndex'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: tick of class  wyAFCSprite */
#ifndef TOLUA_DISABLE_tolua_afcanim_wyAFCSprite_tick00
static int tolua_afcanim_wyAFCSprite_tick00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAFCSprite",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAFCSprite* self = (wyAFCSprite*)  tolua_tousertype(tolua_S,1,0);
  float delta = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'tick'", NULL);
#endif
  {
   self->tick(delta);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'tick'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setIgnoreFrameOffset of class  wyAFCSprite */
#ifndef TOLUA_DISABLE_tolua_afcanim_wyAFCSprite_setIgnoreFrameOffset00
static int tolua_afcanim_wyAFCSprite_setIgnoreFrameOffset00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAFCSprite",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAFCSprite* self = (wyAFCSprite*)  tolua_tousertype(tolua_S,1,0);
  bool flag = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setIgnoreFrameOffset'", NULL);
#endif
  {
   self->setIgnoreFrameOffset(flag);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setIgnoreFrameOffset'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isIgnoreFrameOffset of class  wyAFCSprite */
#ifndef TOLUA_DISABLE_tolua_afcanim_wyAFCSprite_isIgnoreFrameOffset00
static int tolua_afcanim_wyAFCSprite_isIgnoreFrameOffset00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAFCSprite",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAFCSprite* self = (wyAFCSprite*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isIgnoreFrameOffset'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isIgnoreFrameOffset();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isIgnoreFrameOffset'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getFrameOffset of class  wyAFCSprite */
#ifndef TOLUA_DISABLE_tolua_afcanim_wyAFCSprite_getFrameOffset00
static int tolua_afcanim_wyAFCSprite_getFrameOffset00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAFCSprite",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAFCSprite* self = (wyAFCSprite*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getFrameOffset'", NULL);
#endif
  {
   wyPoint tolua_ret = (wyPoint)  self->getFrameOffset();
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
 tolua_error(tolua_S,"#ferror in function 'getFrameOffset'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setAFCSpriteCallback of class  wyAFCSprite */
#ifndef TOLUA_DISABLE_tolua_afcanim_wyAFCSprite_setAFCSpriteCallback00
static int tolua_afcanim_wyAFCSprite_setAFCSpriteCallback00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAFCSprite",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyAFCSpriteCallback",0,&tolua_err) ||
     !tolua_isuserdata(tolua_S,3,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAFCSprite* self = (wyAFCSprite*)  tolua_tousertype(tolua_S,1,0);
  wyAFCSpriteCallback* callback = ((wyAFCSpriteCallback*)  tolua_tousertype(tolua_S,2,0));
  void* data = ((void*)  tolua_touserdata(tolua_S,3,NULL));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setAFCSpriteCallback'", NULL);
#endif
  {
   self->setAFCSpriteCallback(callback,data);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setAFCSpriteCallback'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getCurrentAnimationIndex of class  wyAFCSprite */
#ifndef TOLUA_DISABLE_tolua_afcanim_wyAFCSprite_getCurrentAnimationIndex00
static int tolua_afcanim_wyAFCSprite_getCurrentAnimationIndex00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAFCSprite",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAFCSprite* self = (wyAFCSprite*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getCurrentAnimationIndex'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getCurrentAnimationIndex();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getCurrentAnimationIndex'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getCurrentFrame of class  wyAFCSprite */
#ifndef TOLUA_DISABLE_tolua_afcanim_wyAFCSprite_getCurrentFrame00
static int tolua_afcanim_wyAFCSprite_getCurrentFrame00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAFCSprite",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAFCSprite* self = (wyAFCSprite*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getCurrentFrame'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getCurrentFrame();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getCurrentFrame'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getFrameCount of class  wyAFCSprite */
#ifndef TOLUA_DISABLE_tolua_afcanim_wyAFCSprite_getFrameCount00
static int tolua_afcanim_wyAFCSprite_getFrameCount00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAFCSprite",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAFCSprite* self = (wyAFCSprite*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getFrameCount'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getFrameCount();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getFrameCount'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isReverse of class  wyAFCSprite */
#ifndef TOLUA_DISABLE_tolua_afcanim_wyAFCSprite_isReverse00
static int tolua_afcanim_wyAFCSprite_isReverse00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAFCSprite",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAFCSprite* self = (wyAFCSprite*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isReverse'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isReverse();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isReverse'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setReverse of class  wyAFCSprite */
#ifndef TOLUA_DISABLE_tolua_afcanim_wyAFCSprite_setReverse00
static int tolua_afcanim_wyAFCSprite_setReverse00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAFCSprite",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAFCSprite* self = (wyAFCSprite*)  tolua_tousertype(tolua_S,1,0);
  bool flag = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setReverse'", NULL);
#endif
  {
   self->setReverse(flag);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setReverse'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getLoopCount of class  wyAFCSprite */
#ifndef TOLUA_DISABLE_tolua_afcanim_wyAFCSprite_getLoopCount00
static int tolua_afcanim_wyAFCSprite_getLoopCount00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAFCSprite",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAFCSprite* self = (wyAFCSprite*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getLoopCount'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getLoopCount();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getLoopCount'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setLoopCount of class  wyAFCSprite */
#ifndef TOLUA_DISABLE_tolua_afcanim_wyAFCSprite_setLoopCount00
static int tolua_afcanim_wyAFCSprite_setLoopCount00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAFCSprite",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAFCSprite* self = (wyAFCSprite*)  tolua_tousertype(tolua_S,1,0);
  int loop = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setLoopCount'", NULL);
#endif
  {
   self->setLoopCount(loop);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setLoopCount'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isAnimationEnded of class  wyAFCSprite */
#ifndef TOLUA_DISABLE_tolua_afcanim_wyAFCSprite_isAnimationEnded00
static int tolua_afcanim_wyAFCSprite_isAnimationEnded00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAFCSprite",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAFCSprite* self = (wyAFCSprite*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isAnimationEnded'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isAnimationEnded();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isAnimationEnded'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isFlipX of class  wyAFCSprite */
#ifndef TOLUA_DISABLE_tolua_afcanim_wyAFCSprite_isFlipX00
static int tolua_afcanim_wyAFCSprite_isFlipX00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAFCSprite",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAFCSprite* self = (wyAFCSprite*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isFlipX'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isFlipX();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isFlipX'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setFlipX of class  wyAFCSprite */
#ifndef TOLUA_DISABLE_tolua_afcanim_wyAFCSprite_setFlipX00
static int tolua_afcanim_wyAFCSprite_setFlipX00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAFCSprite",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAFCSprite* self = (wyAFCSprite*)  tolua_tousertype(tolua_S,1,0);
  bool flipX = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setFlipX'", NULL);
#endif
  {
   self->setFlipX(flipX);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setFlipX'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isFlipY of class  wyAFCSprite */
#ifndef TOLUA_DISABLE_tolua_afcanim_wyAFCSprite_isFlipY00
static int tolua_afcanim_wyAFCSprite_isFlipY00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAFCSprite",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAFCSprite* self = (wyAFCSprite*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isFlipY'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isFlipY();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isFlipY'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setFlipY of class  wyAFCSprite */
#ifndef TOLUA_DISABLE_tolua_afcanim_wyAFCSprite_setFlipY00
static int tolua_afcanim_wyAFCSprite_setFlipY00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAFCSprite",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAFCSprite* self = (wyAFCSprite*)  tolua_tousertype(tolua_S,1,0);
  bool flipY = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setFlipY'", NULL);
#endif
  {
   self->setFlipY(flipY);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setFlipY'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setPaused of class  wyAFCSprite */
#ifndef TOLUA_DISABLE_tolua_afcanim_wyAFCSprite_setPaused00
static int tolua_afcanim_wyAFCSprite_setPaused00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAFCSprite",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAFCSprite* self = (wyAFCSprite*)  tolua_tousertype(tolua_S,1,0);
  bool flag = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setPaused'", NULL);
#endif
  {
   self->setPaused(flag);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setPaused'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isPaused of class  wyAFCSprite */
#ifndef TOLUA_DISABLE_tolua_afcanim_wyAFCSprite_isPaused00
static int tolua_afcanim_wyAFCSprite_isPaused00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAFCSprite",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAFCSprite* self = (wyAFCSprite*)  tolua_tousertype(tolua_S,1,0);
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

/* method: getUnitInterval of class  wyAFCSprite */
#ifndef TOLUA_DISABLE_tolua_afcanim_wyAFCSprite_getUnitInterval00
static int tolua_afcanim_wyAFCSprite_getUnitInterval00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAFCSprite",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAFCSprite* self = (wyAFCSprite*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getUnitInterval'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getUnitInterval();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getUnitInterval'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setUnitInterval of class  wyAFCSprite */
#ifndef TOLUA_DISABLE_tolua_afcanim_wyAFCSprite_setUnitInterval00
static int tolua_afcanim_wyAFCSprite_setUnitInterval00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAFCSprite",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAFCSprite* self = (wyAFCSprite*)  tolua_tousertype(tolua_S,1,0);
  float interval = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setUnitInterval'", NULL);
#endif
  {
   self->setUnitInterval(interval);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setUnitInterval'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isForceTickMode of class  wyAFCSprite */
#ifndef TOLUA_DISABLE_tolua_afcanim_wyAFCSprite_isForceTickMode00
static int tolua_afcanim_wyAFCSprite_isForceTickMode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAFCSprite",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAFCSprite* self = (wyAFCSprite*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isForceTickMode'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isForceTickMode();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isForceTickMode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setForceTickMode of class  wyAFCSprite */
#ifndef TOLUA_DISABLE_tolua_afcanim_wyAFCSprite_setForceTickMode00
static int tolua_afcanim_wyAFCSprite_setForceTickMode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAFCSprite",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAFCSprite* self = (wyAFCSprite*)  tolua_tousertype(tolua_S,1,0);
  bool flag = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setForceTickMode'", NULL);
#endif
  {
   self->setForceTickMode(flag);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setForceTickMode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getCurrentAnimationData of class  wyAFCSprite */
#ifndef TOLUA_DISABLE_tolua_afcanim_wyAFCSprite_getCurrentAnimationData00
static int tolua_afcanim_wyAFCSprite_getCurrentAnimationData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAFCSprite",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAFCSprite* self = (wyAFCSprite*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getCurrentAnimationData'", NULL);
#endif
  {
   wyAFCAnimation* tolua_ret = (wyAFCAnimation*)  self->getCurrentAnimationData();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyAFCAnimation");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getCurrentAnimationData'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getCollisionRect of class  wyAFCSprite */
#ifndef TOLUA_DISABLE_tolua_afcanim_wyAFCSprite_getCollisionRect00
static int tolua_afcanim_wyAFCSprite_getCollisionRect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAFCSprite",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAFCSprite* self = (wyAFCSprite*)  tolua_tousertype(tolua_S,1,0);
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getCollisionRect'", NULL);
#endif
  {
   wyRect tolua_ret = (wyRect)  self->getCollisionRect(index);
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
 tolua_error(tolua_S,"#ferror in function 'getCollisionRect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getCollisionRectRelativeToParent of class  wyAFCSprite */
#ifndef TOLUA_DISABLE_tolua_afcanim_wyAFCSprite_getCollisionRectRelativeToParent00
static int tolua_afcanim_wyAFCSprite_getCollisionRectRelativeToParent00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAFCSprite",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAFCSprite* self = (wyAFCSprite*)  tolua_tousertype(tolua_S,1,0);
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getCollisionRectRelativeToParent'", NULL);
#endif
  {
   wyRect tolua_ret = (wyRect)  self->getCollisionRectRelativeToParent(index);
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
 tolua_error(tolua_S,"#ferror in function 'getCollisionRectRelativeToParent'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getCollisionRectRelativeToWorld of class  wyAFCSprite */
#ifndef TOLUA_DISABLE_tolua_afcanim_wyAFCSprite_getCollisionRectRelativeToWorld00
static int tolua_afcanim_wyAFCSprite_getCollisionRectRelativeToWorld00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAFCSprite",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAFCSprite* self = (wyAFCSprite*)  tolua_tousertype(tolua_S,1,0);
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getCollisionRectRelativeToWorld'", NULL);
#endif
  {
   wyRect tolua_ret = (wyRect)  self->getCollisionRectRelativeToWorld(index);
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
 tolua_error(tolua_S,"#ferror in function 'getCollisionRectRelativeToWorld'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getFrameRect of class  wyAFCSprite */
#ifndef TOLUA_DISABLE_tolua_afcanim_wyAFCSprite_getFrameRect00
static int tolua_afcanim_wyAFCSprite_getFrameRect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAFCSprite",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAFCSprite* self = (wyAFCSprite*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getFrameRect'", NULL);
#endif
  {
   wyRect tolua_ret = (wyRect)  self->getFrameRect();
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
 tolua_error(tolua_S,"#ferror in function 'getFrameRect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getFrameRectRelativeToParent of class  wyAFCSprite */
#ifndef TOLUA_DISABLE_tolua_afcanim_wyAFCSprite_getFrameRectRelativeToParent00
static int tolua_afcanim_wyAFCSprite_getFrameRectRelativeToParent00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAFCSprite",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAFCSprite* self = (wyAFCSprite*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getFrameRectRelativeToParent'", NULL);
#endif
  {
   wyRect tolua_ret = (wyRect)  self->getFrameRectRelativeToParent();
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
 tolua_error(tolua_S,"#ferror in function 'getFrameRectRelativeToParent'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getFrameRectRelativeToWorld of class  wyAFCSprite */
#ifndef TOLUA_DISABLE_tolua_afcanim_wyAFCSprite_getFrameRectRelativeToWorld00
static int tolua_afcanim_wyAFCSprite_getFrameRectRelativeToWorld00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAFCSprite",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAFCSprite* self = (wyAFCSprite*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getFrameRectRelativeToWorld'", NULL);
#endif
  {
   wyRect tolua_ret = (wyRect)  self->getFrameRectRelativeToWorld();
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
 tolua_error(tolua_S,"#ferror in function 'getFrameRectRelativeToWorld'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setDebugDrawFrameRect of class  wyAFCSprite */
#ifndef TOLUA_DISABLE_tolua_afcanim_wyAFCSprite_setDebugDrawFrameRect00
static int tolua_afcanim_wyAFCSprite_setDebugDrawFrameRect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAFCSprite",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAFCSprite* self = (wyAFCSprite*)  tolua_tousertype(tolua_S,1,0);
  bool flag = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setDebugDrawFrameRect'", NULL);
#endif
  {
   self->setDebugDrawFrameRect(flag);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setDebugDrawFrameRect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setDebugDrawCollisionRect of class  wyAFCSprite */
#ifndef TOLUA_DISABLE_tolua_afcanim_wyAFCSprite_setDebugDrawCollisionRect00
static int tolua_afcanim_wyAFCSprite_setDebugDrawCollisionRect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAFCSprite",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAFCSprite* self = (wyAFCSprite*)  tolua_tousertype(tolua_S,1,0);
  bool flag = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setDebugDrawCollisionRect'", NULL);
#endif
  {
   self->setDebugDrawCollisionRect(flag);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setDebugDrawCollisionRect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: addClipMapping of class  wyAFCSprite */
#ifndef TOLUA_DISABLE_tolua_afcanim_wyAFCSprite_addClipMapping00
static int tolua_afcanim_wyAFCSprite_addClipMapping00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAFCSprite",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyAFCClipMapping",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAFCSprite* self = (wyAFCSprite*)  tolua_tousertype(tolua_S,1,0);
  wyAFCClipMapping* mapping = ((wyAFCClipMapping*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addClipMapping'", NULL);
#endif
  {
   self->addClipMapping(mapping);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addClipMapping'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: removeClipMappingByTag of class  wyAFCSprite */
#ifndef TOLUA_DISABLE_tolua_afcanim_wyAFCSprite_removeClipMappingByTag00
static int tolua_afcanim_wyAFCSprite_removeClipMappingByTag00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAFCSprite",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAFCSprite* self = (wyAFCSprite*)  tolua_tousertype(tolua_S,1,0);
  int tag = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'removeClipMappingByTag'", NULL);
#endif
  {
   self->removeClipMappingByTag(tag);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'removeClipMappingByTag'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getClipMappingByTag of class  wyAFCSprite */
#ifndef TOLUA_DISABLE_tolua_afcanim_wyAFCSprite_getClipMappingByTag00
static int tolua_afcanim_wyAFCSprite_getClipMappingByTag00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyAFCSprite",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyAFCSprite* self = (wyAFCSprite*)  tolua_tousertype(tolua_S,1,0);
  int tag = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getClipMappingByTag'", NULL);
#endif
  {
   wyAFCClipMapping* tolua_ret = (wyAFCClipMapping*)  self->getClipMappingByTag(tag);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyAFCClipMapping");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getClipMappingByTag'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_afcanim_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyAFCAnimation","wyAFCAnimation","wyObject",tolua_collect_wyAFCAnimation);
  #else
  tolua_cclass(tolua_S,"wyAFCAnimation","wyAFCAnimation","wyObject",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyAFCAnimation");
   tolua_function(tolua_S,"delete",tolua_afcanim_wyAFCAnimation_delete00);
   tolua_function(tolua_S,"make",tolua_afcanim_wyAFCAnimation_make00);
   tolua_function(tolua_S,"getFrameCount",tolua_afcanim_wyAFCAnimation_getFrameCount00);
   tolua_function(tolua_S,"addFrame",tolua_afcanim_wyAFCAnimation_addFrame00);
   tolua_function(tolua_S,"getFrameAt",tolua_afcanim_wyAFCAnimation_getFrameAt00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyAFCClip","wyAFCClip","wyObject",tolua_collect_wyAFCClip);
  #else
  tolua_cclass(tolua_S,"wyAFCClip","wyAFCClip","wyObject",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyAFCClip");
   tolua_function(tolua_S,"delete",tolua_afcanim_wyAFCClip_delete00);
   tolua_function(tolua_S,"make",tolua_afcanim_wyAFCClip_make00);
   tolua_function(tolua_S,"getType",tolua_afcanim_wyAFCClip_getType00);
   tolua_function(tolua_S,"setType",tolua_afcanim_wyAFCClip_setType00);
  tolua_endmodule(tolua_S);
  tolua_constant(tolua_S,"AFC_CLIP_IMAGE",AFC_CLIP_IMAGE);
  tolua_constant(tolua_S,"AFC_CLIP_ELLIPSE",AFC_CLIP_ELLIPSE);
  tolua_constant(tolua_S,"AFC_CLIP_LINE",AFC_CLIP_LINE);
  tolua_constant(tolua_S,"AFC_CLIP_RECT",AFC_CLIP_RECT);
  tolua_constant(tolua_S,"AFC_CLIP_ROUNDRECT",AFC_CLIP_ROUNDRECT);
  tolua_constant(tolua_S,"AFC_CLIP_COLLISION_RECT",AFC_CLIP_COLLISION_RECT);
  tolua_constant(tolua_S,"AFC_CLIP_POINT",AFC_CLIP_POINT);
  tolua_constant(tolua_S,"AFC_CLIP_TRIANGLE",AFC_CLIP_TRIANGLE);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyAFCFrame","wyAFCFrame","wyObject",tolua_collect_wyAFCFrame);
  #else
  tolua_cclass(tolua_S,"wyAFCFrame","wyAFCFrame","wyObject",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyAFCFrame");
   tolua_function(tolua_S,"delete",tolua_afcanim_wyAFCFrame_delete00);
   tolua_function(tolua_S,"make",tolua_afcanim_wyAFCFrame_make00);
   tolua_function(tolua_S,"getClipCount",tolua_afcanim_wyAFCFrame_getClipCount00);
   tolua_function(tolua_S,"getClipCount",tolua_afcanim_wyAFCFrame_getClipCount01);
   tolua_function(tolua_S,"addClip",tolua_afcanim_wyAFCFrame_addClip00);
   tolua_function(tolua_S,"getClipAt",tolua_afcanim_wyAFCFrame_getClipAt00);
   tolua_function(tolua_S,"getClipAt",tolua_afcanim_wyAFCFrame_getClipAt01);
   tolua_function(tolua_S,"setDelay",tolua_afcanim_wyAFCFrame_setDelay00);
   tolua_function(tolua_S,"getDelay",tolua_afcanim_wyAFCFrame_getDelay00);
   tolua_function(tolua_S,"getIncrementation",tolua_afcanim_wyAFCFrame_getIncrementation00);
   tolua_function(tolua_S,"setIncrementation",tolua_afcanim_wyAFCFrame_setIncrementation00);
   tolua_function(tolua_S,"isFlipX",tolua_afcanim_wyAFCFrame_isFlipX00);
   tolua_function(tolua_S,"setFlipX",tolua_afcanim_wyAFCFrame_setFlipX00);
   tolua_function(tolua_S,"isFlipY",tolua_afcanim_wyAFCFrame_isFlipY00);
   tolua_function(tolua_S,"setFlipY",tolua_afcanim_wyAFCFrame_setFlipY00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyMWSprite","wyMWSprite","wyAFCSprite",tolua_collect_wyMWSprite);
  #else
  tolua_cclass(tolua_S,"wyMWSprite","wyMWSprite","wyAFCSprite",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyMWSprite");
   tolua_function(tolua_S,"make",tolua_afcanim_wyMWSprite_make00);
   tolua_function(tolua_S,"make",tolua_afcanim_wyMWSprite_make01);
   tolua_function(tolua_S,"delete",tolua_afcanim_wyMWSprite_delete00);
   tolua_function(tolua_S,"getAnimationAt",tolua_afcanim_wyMWSprite_getAnimationAt00);
   tolua_function(tolua_S,"getAnimationCount",tolua_afcanim_wyMWSprite_getAnimationCount00);
   tolua_function(tolua_S,"getImageCount",tolua_afcanim_wyMWSprite_getImageCount00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"wySPXActionFrame","wySPXActionFrame","",NULL);
  tolua_beginmodule(tolua_S,"wySPXActionFrame");
   tolua_variable(tolua_S,"index",tolua_get_wySPXActionFrame_index,tolua_set_wySPXActionFrame_index);
   tolua_variable(tolua_S,"duration",tolua_get_wySPXActionFrame_duration,tolua_set_wySPXActionFrame_duration);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wySPXAction","wySPXAction","wyObject",tolua_collect_wySPXAction);
  #else
  tolua_cclass(tolua_S,"wySPXAction","wySPXAction","wyObject",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wySPXAction");
   tolua_variable(tolua_S,"m_transform",tolua_get_wySPXAction_m_transform,tolua_set_wySPXAction_m_transform);
   tolua_variable(tolua_S,"m_frameCount",tolua_get_wySPXAction_m_frameCount,tolua_set_wySPXAction_m_frameCount);
   tolua_variable(tolua_S,"m_maxFrameTile",tolua_get_wySPXAction_m_maxFrameTile,tolua_set_wySPXAction_m_maxFrameTile);
   tolua_variable(tolua_S,"m_frames",tolua_get_wySPXAction_m_frames_ptr,tolua_set_wySPXAction_m_frames_ptr);
   tolua_function(tolua_S,"delete",tolua_afcanim_wySPXAction_delete00);
  tolua_endmodule(tolua_S);
  tolua_constant(tolua_S,"SPX_TRANS_NONE",SPX_TRANS_NONE);
  tolua_constant(tolua_S,"SPX_TRANS_MIRROR_ROT180",SPX_TRANS_MIRROR_ROT180);
  tolua_constant(tolua_S,"SPX_TRANS_MIRROR",SPX_TRANS_MIRROR);
  tolua_constant(tolua_S,"SPX_TRANS_ROT180",SPX_TRANS_ROT180);
  tolua_constant(tolua_S,"SPX_TRANS_MIRROR_ROT270",SPX_TRANS_MIRROR_ROT270);
  tolua_constant(tolua_S,"SPX_TRANS_ROT90",SPX_TRANS_ROT90);
  tolua_constant(tolua_S,"SPX_TRANS_ROT270",SPX_TRANS_ROT270);
  tolua_constant(tolua_S,"SPX_TRANS_MIRROR_ROT90",SPX_TRANS_MIRROR_ROT90);
  tolua_cclass(tolua_S,"wySPXTile","wySPXTile","",NULL);
  tolua_beginmodule(tolua_S,"wySPXTile");
   tolua_variable(tolua_S,"x",tolua_get_wySPXTile_x,tolua_set_wySPXTile_x);
   tolua_variable(tolua_S,"y",tolua_get_wySPXTile_y,tolua_set_wySPXTile_y);
   tolua_variable(tolua_S,"w",tolua_get_wySPXTile_w,tolua_set_wySPXTile_w);
   tolua_variable(tolua_S,"h",tolua_get_wySPXTile_h,tolua_set_wySPXTile_h);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wySPXFileData","wySPXFileData","wyObject",tolua_collect_wySPXFileData);
  #else
  tolua_cclass(tolua_S,"wySPXFileData","wySPXFileData","wyObject",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wySPXFileData");
   tolua_variable(tolua_S,"m_tileCount",tolua_get_wySPXFileData_m_tileCount,tolua_set_wySPXFileData_m_tileCount);
   tolua_variable(tolua_S,"m_frameCount",tolua_get_wySPXFileData_m_frameCount,tolua_set_wySPXFileData_m_frameCount);
   tolua_variable(tolua_S,"m_actionCount",tolua_get_wySPXFileData_m_actionCount,tolua_set_wySPXFileData_m_actionCount);
   tolua_variable(tolua_S,"m_tiles",tolua_get_wySPXFileData_m_tiles_ptr,tolua_set_wySPXFileData_m_tiles_ptr);
   tolua_function(tolua_S,"delete",tolua_afcanim_wySPXFileData_delete00);
   tolua_function(tolua_S,"make",tolua_afcanim_wySPXFileData_make00);
   tolua_function(tolua_S,"getFrameAt",tolua_afcanim_wySPXFileData_getFrameAt00);
   tolua_function(tolua_S,"getActionAt",tolua_afcanim_wySPXFileData_getActionAt00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"wySPXFrameTile","wySPXFrameTile","",NULL);
  tolua_beginmodule(tolua_S,"wySPXFrameTile");
   tolua_variable(tolua_S,"index",tolua_get_wySPXFrameTile_index,tolua_set_wySPXFrameTile_index);
   tolua_variable(tolua_S,"x",tolua_get_wySPXFrameTile_x,tolua_set_wySPXFrameTile_x);
   tolua_variable(tolua_S,"y",tolua_get_wySPXFrameTile_y,tolua_set_wySPXFrameTile_y);
   tolua_variable(tolua_S,"transform",tolua_get_wySPXFrameTile_transform,tolua_set_wySPXFrameTile_transform);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"wySPXCollision","wySPXCollision","",NULL);
  tolua_beginmodule(tolua_S,"wySPXCollision");
   tolua_variable(tolua_S,"x",tolua_get_wySPXCollision_x,tolua_set_wySPXCollision_x);
   tolua_variable(tolua_S,"y",tolua_get_wySPXCollision_y,tolua_set_wySPXCollision_y);
   tolua_variable(tolua_S,"width",tolua_get_wySPXCollision_width,tolua_set_wySPXCollision_width);
   tolua_variable(tolua_S,"height",tolua_get_wySPXCollision_height,tolua_set_wySPXCollision_height);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"wySPXReferencePoint","wySPXReferencePoint","",NULL);
  tolua_beginmodule(tolua_S,"wySPXReferencePoint");
   tolua_variable(tolua_S,"x",tolua_get_wySPXReferencePoint_x,tolua_set_wySPXReferencePoint_x);
   tolua_variable(tolua_S,"y",tolua_get_wySPXReferencePoint_y,tolua_set_wySPXReferencePoint_y);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wySPXFrame","wySPXFrame","wyObject",tolua_collect_wySPXFrame);
  #else
  tolua_cclass(tolua_S,"wySPXFrame","wySPXFrame","wyObject",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wySPXFrame");
   tolua_variable(tolua_S,"m_width",tolua_get_wySPXFrame_m_width,tolua_set_wySPXFrame_m_width);
   tolua_variable(tolua_S,"m_height",tolua_get_wySPXFrame_m_height,tolua_set_wySPXFrame_m_height);
   tolua_variable(tolua_S,"m_frameTileCount",tolua_get_wySPXFrame_m_frameTileCount,tolua_set_wySPXFrame_m_frameTileCount);
   tolua_variable(tolua_S,"m_collisionCount",tolua_get_wySPXFrame_m_collisionCount,tolua_set_wySPXFrame_m_collisionCount);
   tolua_variable(tolua_S,"m_referencePointCount",tolua_get_wySPXFrame_m_referencePointCount,tolua_set_wySPXFrame_m_referencePointCount);
   tolua_variable(tolua_S,"m_tiles",tolua_get_wySPXFrame_m_tiles_ptr,tolua_set_wySPXFrame_m_tiles_ptr);
   tolua_variable(tolua_S,"m_collisions",tolua_get_wySPXFrame_m_collisions_ptr,tolua_set_wySPXFrame_m_collisions_ptr);
   tolua_variable(tolua_S,"m_refPoints",tolua_get_wySPXFrame_m_refPoints_ptr,tolua_set_wySPXFrame_m_refPoints_ptr);
   tolua_function(tolua_S,"delete",tolua_afcanim_wySPXFrame_delete00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"wySPXLoader","wySPXLoader","",NULL);
  tolua_beginmodule(tolua_S,"wySPXLoader");
   tolua_function(tolua_S,"load",tolua_afcanim_wySPXLoader_load00);
   tolua_function(tolua_S,"load",tolua_afcanim_wySPXLoader_load01);
   tolua_function(tolua_S,"loadMemory",tolua_afcanim_wySPXLoader_loadMemory00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wySPXSprite","wySPXSprite","wyAFCSprite",tolua_collect_wySPXSprite);
  #else
  tolua_cclass(tolua_S,"wySPXSprite","wySPXSprite","wyAFCSprite",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wySPXSprite");
   tolua_function(tolua_S,"delete",tolua_afcanim_wySPXSprite_delete00);
   tolua_function(tolua_S,"make",tolua_afcanim_wySPXSprite_make00);
   tolua_function(tolua_S,"make",tolua_afcanim_wySPXSprite_make01);
   tolua_function(tolua_S,"getAnimationAt",tolua_afcanim_wySPXSprite_getAnimationAt00);
   tolua_function(tolua_S,"getAnimationCount",tolua_afcanim_wySPXSprite_getAnimationCount00);
   tolua_function(tolua_S,"getImageCount",tolua_afcanim_wySPXSprite_getImageCount00);
  tolua_endmodule(tolua_S);
  tolua_constant(tolua_S,"AS_IMAGE_MODULES",AS_IMAGE_MODULES);
  tolua_constant(tolua_S,"AS_PNG_CRC",AS_PNG_CRC);
  tolua_constant(tolua_S,"AS_KEEP_PAL",AS_KEEP_PAL);
  tolua_constant(tolua_S,"AS_TRANSP_FIRST",AS_TRANSP_FIRST);
  tolua_constant(tolua_S,"AS_TRANSP_LAST",AS_TRANSP_LAST);
  tolua_constant(tolua_S,"AS_IMAGE_ALPHA",AS_IMAGE_ALPHA);
  tolua_constant(tolua_S,"AS_MODULES",AS_MODULES);
  tolua_constant(tolua_S,"AS_MODULES_WH_SHORT",AS_MODULES_WH_SHORT);
  tolua_constant(tolua_S,"AS_MODULES_IMG",AS_MODULES_IMG);
  tolua_constant(tolua_S,"AS_MODULES_XY",AS_MODULES_XY);
  tolua_constant(tolua_S,"AS_MODULES_XY_SHORT",AS_MODULES_XY_SHORT);
  tolua_constant(tolua_S,"AS_FRAMES",AS_FRAMES);
  tolua_constant(tolua_S,"AS_FM_OFF_SHORT",AS_FM_OFF_SHORT);
  tolua_constant(tolua_S,"AS_FM_NUM_SHORT",AS_FM_NUM_SHORT);
  tolua_constant(tolua_S,"AS_FRAME_RC",AS_FRAME_RC);
  tolua_constant(tolua_S,"AS_FRAME_COL_RC",AS_FRAME_COL_RC);
  tolua_constant(tolua_S,"AS_ANIMS",AS_ANIMS);
  tolua_constant(tolua_S,"AS_AF_OFF_SHORT",AS_AF_OFF_SHORT);
  tolua_constant(tolua_S,"AS_AF_NUM_SHORT",AS_AF_NUM_SHORT);
  tolua_cclass(tolua_S,"wyArcticModule","wyArcticModule","",NULL);
  tolua_beginmodule(tolua_S,"wyArcticModule");
   tolua_variable(tolua_S,"x",tolua_get_wyArcticModule_x,tolua_set_wyArcticModule_x);
   tolua_variable(tolua_S,"y",tolua_get_wyArcticModule_y,tolua_set_wyArcticModule_y);
   tolua_variable(tolua_S,"w",tolua_get_wyArcticModule_w,tolua_set_wyArcticModule_w);
   tolua_variable(tolua_S,"h",tolua_get_wyArcticModule_h,tolua_set_wyArcticModule_h);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"wyArcticFrameModule","wyArcticFrameModule","",NULL);
  tolua_beginmodule(tolua_S,"wyArcticFrameModule");
   tolua_variable(tolua_S,"index",tolua_get_wyArcticFrameModule_index,tolua_set_wyArcticFrameModule_index);
   tolua_variable(tolua_S,"x",tolua_get_wyArcticFrameModule_x,tolua_set_wyArcticFrameModule_x);
   tolua_variable(tolua_S,"y",tolua_get_wyArcticFrameModule_y,tolua_set_wyArcticFrameModule_y);
   tolua_variable(tolua_S,"flags",tolua_get_wyArcticFrameModule_unsigned_flags,tolua_set_wyArcticFrameModule_unsigned_flags);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"wyArcticFrame","wyArcticFrame","",NULL);
  tolua_beginmodule(tolua_S,"wyArcticFrame");
   tolua_variable(tolua_S,"moduleCount",tolua_get_wyArcticFrame_moduleCount,tolua_set_wyArcticFrame_moduleCount);
   tolua_variable(tolua_S,"firstModuleIndex",tolua_get_wyArcticFrame_firstModuleIndex,tolua_set_wyArcticFrame_firstModuleIndex);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"wyArcticAnimationFrame","wyArcticAnimationFrame","",NULL);
  tolua_beginmodule(tolua_S,"wyArcticAnimationFrame");
   tolua_variable(tolua_S,"index",tolua_get_wyArcticAnimationFrame_index,tolua_set_wyArcticAnimationFrame_index);
   tolua_variable(tolua_S,"delay",tolua_get_wyArcticAnimationFrame_delay,tolua_set_wyArcticAnimationFrame_delay);
   tolua_variable(tolua_S,"offsetX",tolua_get_wyArcticAnimationFrame_offsetX,tolua_set_wyArcticAnimationFrame_offsetX);
   tolua_variable(tolua_S,"offsetY",tolua_get_wyArcticAnimationFrame_offsetY,tolua_set_wyArcticAnimationFrame_offsetY);
   tolua_variable(tolua_S,"flags",tolua_get_wyArcticAnimationFrame_unsigned_flags,tolua_set_wyArcticAnimationFrame_unsigned_flags);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"wyArcticAnimation","wyArcticAnimation","",NULL);
  tolua_beginmodule(tolua_S,"wyArcticAnimation");
   tolua_variable(tolua_S,"frameCount",tolua_get_wyArcticAnimation_frameCount,tolua_set_wyArcticAnimation_frameCount);
   tolua_variable(tolua_S,"firstFrameIndex",tolua_get_wyArcticAnimation_firstFrameIndex,tolua_set_wyArcticAnimation_firstFrameIndex);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyArcticFileData","wyArcticFileData","wyObject",tolua_collect_wyArcticFileData);
  #else
  tolua_cclass(tolua_S,"wyArcticFileData","wyArcticFileData","wyObject",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyArcticFileData");
   tolua_variable(tolua_S,"m_version",tolua_get_wyArcticFileData_m_version,tolua_set_wyArcticFileData_m_version);
   tolua_variable(tolua_S,"m_flags",tolua_get_wyArcticFileData_m_flags,tolua_set_wyArcticFileData_m_flags);
   tolua_variable(tolua_S,"m_moduleCount",tolua_get_wyArcticFileData_m_moduleCount,tolua_set_wyArcticFileData_m_moduleCount);
   tolua_variable(tolua_S,"m_modules",tolua_get_wyArcticFileData_m_modules_ptr,tolua_set_wyArcticFileData_m_modules_ptr);
   tolua_variable(tolua_S,"m_frameModuleCount",tolua_get_wyArcticFileData_m_frameModuleCount,tolua_set_wyArcticFileData_m_frameModuleCount);
   tolua_variable(tolua_S,"m_frameModules",tolua_get_wyArcticFileData_m_frameModules_ptr,tolua_set_wyArcticFileData_m_frameModules_ptr);
   tolua_variable(tolua_S,"m_frameCount",tolua_get_wyArcticFileData_m_frameCount,tolua_set_wyArcticFileData_m_frameCount);
   tolua_variable(tolua_S,"m_frames",tolua_get_wyArcticFileData_m_frames_ptr,tolua_set_wyArcticFileData_m_frames_ptr);
   tolua_variable(tolua_S,"m_animationFrameCount",tolua_get_wyArcticFileData_m_animationFrameCount,tolua_set_wyArcticFileData_m_animationFrameCount);
   tolua_variable(tolua_S,"m_animationFrames",tolua_get_wyArcticFileData_m_animationFrames_ptr,tolua_set_wyArcticFileData_m_animationFrames_ptr);
   tolua_variable(tolua_S,"m_animationCount",tolua_get_wyArcticFileData_m_animationCount,tolua_set_wyArcticFileData_m_animationCount);
   tolua_variable(tolua_S,"m_animations",tolua_get_wyArcticFileData_m_animations_ptr,tolua_set_wyArcticFileData_m_animations_ptr);
   tolua_function(tolua_S,"delete",tolua_afcanim_wyArcticFileData_delete00);
   tolua_function(tolua_S,"make",tolua_afcanim_wyArcticFileData_make00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"wyArcticLoader","wyArcticLoader","",NULL);
  tolua_beginmodule(tolua_S,"wyArcticLoader");
   tolua_function(tolua_S,"load",tolua_afcanim_wyArcticLoader_load00);
   tolua_function(tolua_S,"load",tolua_afcanim_wyArcticLoader_load01);
   tolua_function(tolua_S,"loadMemory",tolua_afcanim_wyArcticLoader_loadMemory00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyArcticSprite","wyArcticSprite","wyAFCSprite",tolua_collect_wyArcticSprite);
  #else
  tolua_cclass(tolua_S,"wyArcticSprite","wyArcticSprite","wyAFCSprite",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyArcticSprite");
   tolua_function(tolua_S,"delete",tolua_afcanim_wyArcticSprite_delete00);
   tolua_function(tolua_S,"make",tolua_afcanim_wyArcticSprite_make00);
   tolua_function(tolua_S,"make",tolua_afcanim_wyArcticSprite_make01);
   tolua_function(tolua_S,"getAnimationAt",tolua_afcanim_wyArcticSprite_getAnimationAt00);
   tolua_function(tolua_S,"getAnimationCount",tolua_afcanim_wyArcticSprite_getAnimationCount00);
   tolua_function(tolua_S,"getImageCount",tolua_afcanim_wyArcticSprite_getImageCount00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"wySPX3Action","wySPX3Action","wyObject",NULL);
  tolua_beginmodule(tolua_S,"wySPX3Action");
  tolua_endmodule(tolua_S);
  tolua_constant(tolua_S,"SPX_DELAY",SPX_DELAY);
  tolua_constant(tolua_S,"SPX_NODELAY",SPX_NODELAY);
  tolua_constant(tolua_S,"SPX_TILE_INDEX",SPX_TILE_INDEX);
  tolua_constant(tolua_S,"SPX_TILE_CLIP",SPX_TILE_CLIP);
  tolua_constant(tolua_S,"SPX_PATCH_TILE",SPX_PATCH_TILE);
  tolua_constant(tolua_S,"SPX_PATCH_SHAPE",SPX_PATCH_SHAPE);
  tolua_constant(tolua_S,"SPX_POINT",SPX_POINT);
  tolua_constant(tolua_S,"SPX_LINE",SPX_LINE);
  tolua_constant(tolua_S,"SPX_RECT",SPX_RECT);
  tolua_constant(tolua_S,"SPX_TRIANGLE",SPX_TRIANGLE);
  tolua_constant(tolua_S,"SPX_POLYGON",SPX_POLYGON);
  tolua_constant(tolua_S,"SPX_ELLIPSE",SPX_ELLIPSE);
  tolua_constant(tolua_S,"SPX_ROUNDRECT",SPX_ROUNDRECT);
  tolua_constant(tolua_S,"SPX_ARC",SPX_ARC);
  tolua_constant(tolua_S,"SPX_PIE",SPX_PIE);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wySPX3FileData","wySPX3FileData","wyObject",tolua_collect_wySPX3FileData);
  #else
  tolua_cclass(tolua_S,"wySPX3FileData","wySPX3FileData","wyObject",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wySPX3FileData");
   tolua_variable(tolua_S,"m_version",tolua_get_wySPX3FileData_m_version,tolua_set_wySPX3FileData_m_version);
   tolua_variable(tolua_S,"m_tileSetCount",tolua_get_wySPX3FileData_m_tileSetCount,tolua_set_wySPX3FileData_m_tileSetCount);
   tolua_variable(tolua_S,"m_frameCount",tolua_get_wySPX3FileData_m_frameCount,tolua_set_wySPX3FileData_m_frameCount);
   tolua_variable(tolua_S,"m_actionCount",tolua_get_wySPX3FileData_m_actionCount,tolua_set_wySPX3FileData_m_actionCount);
   tolua_function(tolua_S,"delete",tolua_afcanim_wySPX3FileData_delete00);
   tolua_function(tolua_S,"make",tolua_afcanim_wySPX3FileData_make00);
   tolua_function(tolua_S,"getTileSetAt",tolua_afcanim_wySPX3FileData_getTileSetAt00);
   tolua_function(tolua_S,"getFrameAt",tolua_afcanim_wySPX3FileData_getFrameAt00);
   tolua_function(tolua_S,"getActionAt",tolua_afcanim_wySPX3FileData_getActionAt00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"wySPX3Patch","wySPX3Patch","",NULL);
  tolua_beginmodule(tolua_S,"wySPX3Patch");
   tolua_variable(tolua_S,"type",tolua_get_wySPX3Patch_type,tolua_set_wySPX3Patch_type);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wySPX3Frame","wySPX3Frame","wyObject",tolua_collect_wySPX3Frame);
  #else
  tolua_cclass(tolua_S,"wySPX3Frame","wySPX3Frame","wyObject",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wySPX3Frame");
   tolua_variable(tolua_S,"m_flags",tolua_get_wySPX3Frame_m_flags,tolua_set_wySPX3Frame_m_flags);
   tolua_variable(tolua_S,"m_rect",tolua_get_wySPX3Frame_m_rect,tolua_set_wySPX3Frame_m_rect);
   tolua_variable(tolua_S,"m_patchCount",tolua_get_wySPX3Frame_m_patchCount,tolua_set_wySPX3Frame_m_patchCount);
   tolua_variable(tolua_S,"m_patches",tolua_get_wySPX3Frame_m_patches_ptr,tolua_set_wySPX3Frame_m_patches_ptr);
   tolua_variable(tolua_S,"m_collisionCount",tolua_get_wySPX3Frame_m_collisionCount,tolua_set_wySPX3Frame_m_collisionCount);
   tolua_variable(tolua_S,"m_collisionRects",tolua_get_wySPX3Frame_m_collisionRects_ptr,tolua_set_wySPX3Frame_m_collisionRects_ptr);
   tolua_function(tolua_S,"delete",tolua_afcanim_wySPX3Frame_delete00);
   tolua_function(tolua_S,"make",tolua_afcanim_wySPX3Frame_make00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"wySPX3Loader","wySPX3Loader","",NULL);
  tolua_beginmodule(tolua_S,"wySPX3Loader");
   tolua_function(tolua_S,"load",tolua_afcanim_wySPX3Loader_load00);
   tolua_function(tolua_S,"load",tolua_afcanim_wySPX3Loader_load01);
   tolua_function(tolua_S,"loadMemory",tolua_afcanim_wySPX3Loader_loadMemory00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wySPX3Sprite","wySPX3Sprite","wyAFCSprite",tolua_collect_wySPX3Sprite);
  #else
  tolua_cclass(tolua_S,"wySPX3Sprite","wySPX3Sprite","wyAFCSprite",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wySPX3Sprite");
   tolua_function(tolua_S,"delete",tolua_afcanim_wySPX3Sprite_delete00);
   tolua_function(tolua_S,"make",tolua_afcanim_wySPX3Sprite_make00);
   tolua_function(tolua_S,"make",tolua_afcanim_wySPX3Sprite_make01);
   tolua_function(tolua_S,"getAnimationAt",tolua_afcanim_wySPX3Sprite_getAnimationAt00);
   tolua_function(tolua_S,"getAnimationCount",tolua_afcanim_wySPX3Sprite_getAnimationCount00);
   tolua_function(tolua_S,"getImageCount",tolua_afcanim_wySPX3Sprite_getImageCount00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"wySPX3Tile","wySPX3Tile","",NULL);
  tolua_beginmodule(tolua_S,"wySPX3Tile");
   tolua_variable(tolua_S,"x1",tolua_get_wySPX3Tile_x1,tolua_set_wySPX3Tile_x1);
   tolua_variable(tolua_S,"y1",tolua_get_wySPX3Tile_y1,tolua_set_wySPX3Tile_y1);
   tolua_variable(tolua_S,"x2",tolua_get_wySPX3Tile_x2,tolua_set_wySPX3Tile_x2);
   tolua_variable(tolua_S,"y2",tolua_get_wySPX3Tile_y2,tolua_set_wySPX3Tile_y2);
   tolua_function(tolua_S,"left",tolua_afcanim_wySPX3Tile_left00);
   tolua_function(tolua_S,"bottom",tolua_afcanim_wySPX3Tile_bottom00);
   tolua_function(tolua_S,"right",tolua_afcanim_wySPX3Tile_right00);
   tolua_function(tolua_S,"top",tolua_afcanim_wySPX3Tile_top00);
   tolua_function(tolua_S,"width",tolua_afcanim_wySPX3Tile_width00);
   tolua_function(tolua_S,"height",tolua_afcanim_wySPX3Tile_height00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wySPX3TileSet","wySPX3TileSet","wyObject",tolua_collect_wySPX3TileSet);
  #else
  tolua_cclass(tolua_S,"wySPX3TileSet","wySPX3TileSet","wyObject",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wySPX3TileSet");
   tolua_variable(tolua_S,"m_mode",tolua_get_wySPX3TileSet_m_mode,tolua_set_wySPX3TileSet_m_mode);
   tolua_variable(tolua_S,"m_imageIndex",tolua_get_wySPX3TileSet_m_imageIndex,tolua_set_wySPX3TileSet_m_imageIndex);
   tolua_variable(tolua_S,"m_tileWidth",tolua_get_wySPX3TileSet_m_tileWidth,tolua_set_wySPX3TileSet_m_tileWidth);
   tolua_variable(tolua_S,"m_tileHeight",tolua_get_wySPX3TileSet_m_tileHeight,tolua_set_wySPX3TileSet_m_tileHeight);
   tolua_variable(tolua_S,"m_tileColumns",tolua_get_wySPX3TileSet_m_tileColumns,tolua_set_wySPX3TileSet_m_tileColumns);
   tolua_variable(tolua_S,"m_tileRows",tolua_get_wySPX3TileSet_m_tileRows,tolua_set_wySPX3TileSet_m_tileRows);
   tolua_variable(tolua_S,"m_tileCount",tolua_get_wySPX3TileSet_m_tileCount,tolua_set_wySPX3TileSet_m_tileCount);
   tolua_variable(tolua_S,"m_tiles",tolua_get_wySPX3TileSet_m_tiles_ptr,tolua_set_wySPX3TileSet_m_tiles_ptr);
   tolua_function(tolua_S,"delete",tolua_afcanim_wySPX3TileSet_delete00);
   tolua_function(tolua_S,"make",tolua_afcanim_wySPX3TileSet_make00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyAuroraSprite","wyAuroraSprite","wyAFCSprite",tolua_collect_wyAuroraSprite);
  #else
  tolua_cclass(tolua_S,"wyAuroraSprite","wyAuroraSprite","wyAFCSprite",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyAuroraSprite");
   tolua_function(tolua_S,"delete",tolua_afcanim_wyAuroraSprite_delete00);
   tolua_function(tolua_S,"make",tolua_afcanim_wyAuroraSprite_make00);
   tolua_function(tolua_S,"make",tolua_afcanim_wyAuroraSprite_make01);
   tolua_function(tolua_S,"getAnimationAt",tolua_afcanim_wyAuroraSprite_getAnimationAt00);
   tolua_function(tolua_S,"getAnimationCount",tolua_afcanim_wyAuroraSprite_getAnimationCount00);
   tolua_function(tolua_S,"getImageCount",tolua_afcanim_wyAuroraSprite_getImageCount00);
  tolua_endmodule(tolua_S);
  tolua_constant(tolua_S,"AFC_CMR_INTERNAL_CLIP",AFC_CMR_INTERNAL_CLIP);
  tolua_constant(tolua_S,"AFC_CMR_EXTERNAL_CLIP",AFC_CMR_EXTERNAL_CLIP);
  tolua_constant(tolua_S,"AFC_CMR_EXTERNAL_ATLAS",AFC_CMR_EXTERNAL_ATLAS);
  tolua_cclass(tolua_S,"wyAFCClipMappingRule","wyAFCClipMappingRule","",NULL);
  tolua_beginmodule(tolua_S,"wyAFCClipMappingRule");
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyAFCClipMapping","wyAFCClipMapping","wyObject",tolua_collect_wyAFCClipMapping);
  #else
  tolua_cclass(tolua_S,"wyAFCClipMapping","wyAFCClipMapping","wyObject",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyAFCClipMapping");
   tolua_function(tolua_S,"delete",tolua_afcanim_wyAFCClipMapping_delete00);
   tolua_function(tolua_S,"make",tolua_afcanim_wyAFCClipMapping_make00);
   tolua_function(tolua_S,"makeAurora",tolua_afcanim_wyAFCClipMapping_makeAurora00);
   tolua_function(tolua_S,"makeAurora",tolua_afcanim_wyAFCClipMapping_makeAurora01);
   tolua_function(tolua_S,"makeMemoryAurora",tolua_afcanim_wyAFCClipMapping_makeMemoryAurora00);
   tolua_function(tolua_S,"mapClip",tolua_afcanim_wyAFCClipMapping_mapClip00);
   tolua_function(tolua_S,"mapClip",tolua_afcanim_wyAFCClipMapping_mapClip01);
   tolua_function(tolua_S,"mapClip",tolua_afcanim_wyAFCClipMapping_mapClip02);
   tolua_function(tolua_S,"getTag",tolua_afcanim_wyAFCClipMapping_getTag00);
   tolua_function(tolua_S,"findRule",tolua_afcanim_wyAFCClipMapping_findRule00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"wyAFCSpriteCallback","wyAFCSpriteCallback","",NULL);
  tolua_beginmodule(tolua_S,"wyAFCSpriteCallback");
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyAFCSprite","wyAFCSprite","wyNode",tolua_collect_wyAFCSprite);
  #else
  tolua_cclass(tolua_S,"wyAFCSprite","wyAFCSprite","wyNode",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyAFCSprite");
   tolua_function(tolua_S,"delete",tolua_afcanim_wyAFCSprite_delete00);
   tolua_function(tolua_S,"getAlpha",tolua_afcanim_wyAFCSprite_getAlpha00);
   tolua_function(tolua_S,"setAlpha",tolua_afcanim_wyAFCSprite_setAlpha00);
   tolua_function(tolua_S,"getColor",tolua_afcanim_wyAFCSprite_getColor00);
   tolua_function(tolua_S,"setColor",tolua_afcanim_wyAFCSprite_setColor00);
   tolua_function(tolua_S,"setColor",tolua_afcanim_wyAFCSprite_setColor01);
   tolua_function(tolua_S,"addChild",tolua_afcanim_wyAFCSprite_addChild00);
   tolua_function(tolua_S,"getAnimationAt",tolua_afcanim_wyAFCSprite_getAnimationAt00);
   tolua_function(tolua_S,"getAnimationCount",tolua_afcanim_wyAFCSprite_getAnimationCount00);
   tolua_function(tolua_S,"getImageCount",tolua_afcanim_wyAFCSprite_getImageCount00);
   tolua_function(tolua_S,"playAnimation",tolua_afcanim_wyAFCSprite_playAnimation00);
   tolua_function(tolua_S,"playAnimation",tolua_afcanim_wyAFCSprite_playAnimation01);
   tolua_function(tolua_S,"setFrameIndex",tolua_afcanim_wyAFCSprite_setFrameIndex00);
   tolua_function(tolua_S,"tick",tolua_afcanim_wyAFCSprite_tick00);
   tolua_function(tolua_S,"setIgnoreFrameOffset",tolua_afcanim_wyAFCSprite_setIgnoreFrameOffset00);
   tolua_function(tolua_S,"isIgnoreFrameOffset",tolua_afcanim_wyAFCSprite_isIgnoreFrameOffset00);
   tolua_function(tolua_S,"getFrameOffset",tolua_afcanim_wyAFCSprite_getFrameOffset00);
   tolua_function(tolua_S,"setAFCSpriteCallback",tolua_afcanim_wyAFCSprite_setAFCSpriteCallback00);
   tolua_function(tolua_S,"getCurrentAnimationIndex",tolua_afcanim_wyAFCSprite_getCurrentAnimationIndex00);
   tolua_function(tolua_S,"getCurrentFrame",tolua_afcanim_wyAFCSprite_getCurrentFrame00);
   tolua_function(tolua_S,"getFrameCount",tolua_afcanim_wyAFCSprite_getFrameCount00);
   tolua_function(tolua_S,"isReverse",tolua_afcanim_wyAFCSprite_isReverse00);
   tolua_function(tolua_S,"setReverse",tolua_afcanim_wyAFCSprite_setReverse00);
   tolua_function(tolua_S,"getLoopCount",tolua_afcanim_wyAFCSprite_getLoopCount00);
   tolua_function(tolua_S,"setLoopCount",tolua_afcanim_wyAFCSprite_setLoopCount00);
   tolua_function(tolua_S,"isAnimationEnded",tolua_afcanim_wyAFCSprite_isAnimationEnded00);
   tolua_function(tolua_S,"isFlipX",tolua_afcanim_wyAFCSprite_isFlipX00);
   tolua_function(tolua_S,"setFlipX",tolua_afcanim_wyAFCSprite_setFlipX00);
   tolua_function(tolua_S,"isFlipY",tolua_afcanim_wyAFCSprite_isFlipY00);
   tolua_function(tolua_S,"setFlipY",tolua_afcanim_wyAFCSprite_setFlipY00);
   tolua_function(tolua_S,"setPaused",tolua_afcanim_wyAFCSprite_setPaused00);
   tolua_function(tolua_S,"isPaused",tolua_afcanim_wyAFCSprite_isPaused00);
   tolua_function(tolua_S,"getUnitInterval",tolua_afcanim_wyAFCSprite_getUnitInterval00);
   tolua_function(tolua_S,"setUnitInterval",tolua_afcanim_wyAFCSprite_setUnitInterval00);
   tolua_function(tolua_S,"isForceTickMode",tolua_afcanim_wyAFCSprite_isForceTickMode00);
   tolua_function(tolua_S,"setForceTickMode",tolua_afcanim_wyAFCSprite_setForceTickMode00);
   tolua_function(tolua_S,"getCurrentAnimationData",tolua_afcanim_wyAFCSprite_getCurrentAnimationData00);
   tolua_function(tolua_S,"getCollisionRect",tolua_afcanim_wyAFCSprite_getCollisionRect00);
   tolua_function(tolua_S,"getCollisionRectRelativeToParent",tolua_afcanim_wyAFCSprite_getCollisionRectRelativeToParent00);
   tolua_function(tolua_S,"getCollisionRectRelativeToWorld",tolua_afcanim_wyAFCSprite_getCollisionRectRelativeToWorld00);
   tolua_function(tolua_S,"getFrameRect",tolua_afcanim_wyAFCSprite_getFrameRect00);
   tolua_function(tolua_S,"getFrameRectRelativeToParent",tolua_afcanim_wyAFCSprite_getFrameRectRelativeToParent00);
   tolua_function(tolua_S,"getFrameRectRelativeToWorld",tolua_afcanim_wyAFCSprite_getFrameRectRelativeToWorld00);
   tolua_function(tolua_S,"setDebugDrawFrameRect",tolua_afcanim_wyAFCSprite_setDebugDrawFrameRect00);
   tolua_function(tolua_S,"setDebugDrawCollisionRect",tolua_afcanim_wyAFCSprite_setDebugDrawCollisionRect00);
   tolua_function(tolua_S,"addClipMapping",tolua_afcanim_wyAFCSprite_addClipMapping00);
   tolua_function(tolua_S,"removeClipMappingByTag",tolua_afcanim_wyAFCSprite_removeClipMappingByTag00);
   tolua_function(tolua_S,"getClipMappingByTag",tolua_afcanim_wyAFCSprite_getClipMappingByTag00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_afcanim (lua_State* tolua_S) {
 return tolua_afcanim_open(tolua_S);
};
#endif

