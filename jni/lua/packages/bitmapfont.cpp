/*
** Lua binding: bitmapfont
** Generated automatically by tolua++-1.0.92 on Wed Nov 23 22:12:25 2011.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_bitmapfont_open (lua_State* tolua_S);

#include "WiEngine.h"

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_wyColor3B (lua_State* tolua_S)
{
 wyColor3B* self = (wyColor3B*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyCharInfo (lua_State* tolua_S)
{
 wyCharInfo* self = (wyCharInfo*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyBitmapFontLabel (lua_State* tolua_S)
{
 wyBitmapFontLabel* self = (wyBitmapFontLabel*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"wyAngelCodeTXTFontLoader");
 tolua_usertype(tolua_S,"wyBitmapFont");
 tolua_usertype(tolua_S,"wyCharInfo");
 tolua_usertype(tolua_S,"wyTexture2D");
 tolua_usertype(tolua_S,"size_t");
 tolua_usertype(tolua_S,"wyColor3B");
 tolua_usertype(tolua_S,"wyHGEFontLoader");
 tolua_usertype(tolua_S,"wyColor4B");
 tolua_usertype(tolua_S,"wyNode");
 tolua_usertype(tolua_S,"wyRect");
 tolua_usertype(tolua_S,"wyBitmapFontLabel");
 tolua_usertype(tolua_S,"wyAngelCodeXMLFontLoader");
}

/* method: load of class  wyAngelCodeTXTFontLoader */
#ifndef TOLUA_DISABLE_tolua_bitmapfont_wyAngelCodeTXTFontLoader_load00
static int tolua_bitmapfont_wyAngelCodeTXTFontLoader_load00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyAngelCodeTXTFontLoader",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyBitmapFont",0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"size_t",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,5,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyBitmapFont* font = ((wyBitmapFont*)  tolua_tousertype(tolua_S,2,0));
  const char* data = ((const char*)  tolua_tostring(tolua_S,3,0));
  size_t length = *((size_t*)  tolua_tousertype(tolua_S,4,0));
  float resScale = ((float)  tolua_tonumber(tolua_S,5,1.f));
  {
   wyAngelCodeTXTFontLoader::load(font,data,length,resScale);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'load'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: load of class  wyAngelCodeXMLFontLoader */
#ifndef TOLUA_DISABLE_tolua_bitmapfont_wyAngelCodeXMLFontLoader_load00
static int tolua_bitmapfont_wyAngelCodeXMLFontLoader_load00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyAngelCodeXMLFontLoader",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyBitmapFont",0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"size_t",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,5,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyBitmapFont* font = ((wyBitmapFont*)  tolua_tousertype(tolua_S,2,0));
  const char* data = ((const char*)  tolua_tostring(tolua_S,3,0));
  size_t length = *((size_t*)  tolua_tousertype(tolua_S,4,0));
  float resScale = ((float)  tolua_tonumber(tolua_S,5,1.f));
  {
   wyAngelCodeXMLFontLoader::load(font,data,length,resScale);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'load'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  wyCharInfo */
#ifndef TOLUA_DISABLE_tolua_bitmapfont_wyCharInfo_new00
static int tolua_bitmapfont_wyCharInfo_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyCharInfo",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   wyCharInfo* tolua_ret = (wyCharInfo*)  Mtolua_new((wyCharInfo)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyCharInfo");
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

/* method: new_local of class  wyCharInfo */
#ifndef TOLUA_DISABLE_tolua_bitmapfont_wyCharInfo_new00_local
static int tolua_bitmapfont_wyCharInfo_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyCharInfo",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   wyCharInfo* tolua_ret = (wyCharInfo*)  Mtolua_new((wyCharInfo)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyCharInfo");
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

/* get function: word of class  wyCharInfo */
#ifndef TOLUA_DISABLE_tolua_get_wyCharInfo_word
static int tolua_get_wyCharInfo_word(lua_State* tolua_S)
{
  wyCharInfo* self = (wyCharInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'word'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->word);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: word of class  wyCharInfo */
#ifndef TOLUA_DISABLE_tolua_set_wyCharInfo_word
static int tolua_set_wyCharInfo_word(lua_State* tolua_S)
{
  wyCharInfo* self = (wyCharInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'word'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->word = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: left of class  wyCharInfo */
#ifndef TOLUA_DISABLE_tolua_get_wyCharInfo_left
static int tolua_get_wyCharInfo_left(lua_State* tolua_S)
{
  wyCharInfo* self = (wyCharInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'left'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->left);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: left of class  wyCharInfo */
#ifndef TOLUA_DISABLE_tolua_set_wyCharInfo_left
static int tolua_set_wyCharInfo_left(lua_State* tolua_S)
{
  wyCharInfo* self = (wyCharInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'left'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->left = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: right of class  wyCharInfo */
#ifndef TOLUA_DISABLE_tolua_get_wyCharInfo_right
static int tolua_get_wyCharInfo_right(lua_State* tolua_S)
{
  wyCharInfo* self = (wyCharInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'right'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->right);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: right of class  wyCharInfo */
#ifndef TOLUA_DISABLE_tolua_set_wyCharInfo_right
static int tolua_set_wyCharInfo_right(lua_State* tolua_S)
{
  wyCharInfo* self = (wyCharInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'right'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->right = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: top of class  wyCharInfo */
#ifndef TOLUA_DISABLE_tolua_get_wyCharInfo_top
static int tolua_get_wyCharInfo_top(lua_State* tolua_S)
{
  wyCharInfo* self = (wyCharInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'top'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->top);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: top of class  wyCharInfo */
#ifndef TOLUA_DISABLE_tolua_set_wyCharInfo_top
static int tolua_set_wyCharInfo_top(lua_State* tolua_S)
{
  wyCharInfo* self = (wyCharInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'top'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->top = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: page of class  wyCharInfo */
#ifndef TOLUA_DISABLE_tolua_get_wyCharInfo_page
static int tolua_get_wyCharInfo_page(lua_State* tolua_S)
{
  wyCharInfo* self = (wyCharInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'page'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->page);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: page of class  wyCharInfo */
#ifndef TOLUA_DISABLE_tolua_set_wyCharInfo_page
static int tolua_set_wyCharInfo_page(lua_State* tolua_S)
{
  wyCharInfo* self = (wyCharInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'page'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->page = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: texRect of class  wyCharInfo */
#ifndef TOLUA_DISABLE_tolua_get_wyCharInfo_texRect
static int tolua_get_wyCharInfo_texRect(lua_State* tolua_S)
{
  wyCharInfo* self = (wyCharInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'texRect'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->texRect,"wyRect");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: texRect of class  wyCharInfo */
#ifndef TOLUA_DISABLE_tolua_set_wyCharInfo_texRect
static int tolua_set_wyCharInfo_texRect(lua_State* tolua_S)
{
  wyCharInfo* self = (wyCharInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'texRect'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"wyRect",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->texRect = *((wyRect*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: loadFont of class  wyBitmapFont */
#ifndef TOLUA_DISABLE_tolua_bitmapfont_wyBitmapFont_loadFont00
static int tolua_bitmapfont_wyBitmapFont_loadFont00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyBitmapFont",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  int resId = ((int)  tolua_tonumber(tolua_S,2,0));
  wyBitmapFontFormat format = ((wyBitmapFontFormat) (int)  tolua_tonumber(tolua_S,3,BFF_HGE));
  {
   wyBitmapFont* tolua_ret = (wyBitmapFont*)  wyBitmapFont::loadFont(resId,format);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyBitmapFont");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'loadFont'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: loadFont of class  wyBitmapFont */
#ifndef TOLUA_DISABLE_tolua_bitmapfont_wyBitmapFont_loadFont01
static int tolua_bitmapfont_wyBitmapFont_loadFont01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyBitmapFont",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,3,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const char* path = ((const char*)  tolua_tostring(tolua_S,2,0));
  bool isFile = ((bool)  tolua_toboolean(tolua_S,3,false));
  wyBitmapFontFormat format = ((wyBitmapFontFormat) (int)  tolua_tonumber(tolua_S,4,BFF_HGE));
  {
   wyBitmapFont* tolua_ret = (wyBitmapFont*)  wyBitmapFont::loadFont(path,isFile,format);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyBitmapFont");
  }
 }
 return 1;
tolua_lerror:
 return tolua_bitmapfont_wyBitmapFont_loadFont00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: unloadFont of class  wyBitmapFont */
#ifndef TOLUA_DISABLE_tolua_bitmapfont_wyBitmapFont_unloadFont00
static int tolua_bitmapfont_wyBitmapFont_unloadFont00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyBitmapFont",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyBitmapFont",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyBitmapFont* font = ((wyBitmapFont*)  tolua_tousertype(tolua_S,2,0));
  {
   wyBitmapFont::unloadFont(font);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'unloadFont'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: unloadAll of class  wyBitmapFont */
#ifndef TOLUA_DISABLE_tolua_bitmapfont_wyBitmapFont_unloadAll00
static int tolua_bitmapfont_wyBitmapFont_unloadAll00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyBitmapFont",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   wyBitmapFont::unloadAll();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'unloadAll'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: addTexture of class  wyBitmapFont */
#ifndef TOLUA_DISABLE_tolua_bitmapfont_wyBitmapFont_addTexture00
static int tolua_bitmapfont_wyBitmapFont_addTexture00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyBitmapFont",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyTexture2D",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyBitmapFont* self = (wyBitmapFont*)  tolua_tousertype(tolua_S,1,0);
  wyTexture2D* tex = ((wyTexture2D*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addTexture'", NULL);
#endif
  {
   self->addTexture(tex);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addTexture'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getTexture of class  wyBitmapFont */
#ifndef TOLUA_DISABLE_tolua_bitmapfont_wyBitmapFont_getTexture00
static int tolua_bitmapfont_wyBitmapFont_getTexture00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyBitmapFont",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyBitmapFont* self = (wyBitmapFont*)  tolua_tousertype(tolua_S,1,0);
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getTexture'", NULL);
#endif
  {
   wyTexture2D* tolua_ret = (wyTexture2D*)  self->getTexture(index);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyTexture2D");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getTexture'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getCharInfo of class  wyBitmapFont */
#ifndef TOLUA_DISABLE_tolua_bitmapfont_wyBitmapFont_getCharInfo00
static int tolua_bitmapfont_wyBitmapFont_getCharInfo00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyBitmapFont",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyBitmapFont* self = (wyBitmapFont*)  tolua_tousertype(tolua_S,1,0);
  int wc = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getCharInfo'", NULL);
#endif
  {
   wyCharInfo* tolua_ret = (wyCharInfo*)  self->getCharInfo(wc);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyCharInfo");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getCharInfo'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getResId of class  wyBitmapFont */
#ifndef TOLUA_DISABLE_tolua_bitmapfont_wyBitmapFont_getResId00
static int tolua_bitmapfont_wyBitmapFont_getResId00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyBitmapFont",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyBitmapFont* self = (wyBitmapFont*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getResId'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getResId();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getResId'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getHash of class  wyBitmapFont */
#ifndef TOLUA_DISABLE_tolua_bitmapfont_wyBitmapFont_getHash00
static int tolua_bitmapfont_wyBitmapFont_getHash00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyBitmapFont",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyBitmapFont* self = (wyBitmapFont*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getHash'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getHash();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getHash'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isFile of class  wyBitmapFont */
#ifndef TOLUA_DISABLE_tolua_bitmapfont_wyBitmapFont_isFile00
static int tolua_bitmapfont_wyBitmapFont_isFile00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyBitmapFont",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyBitmapFont* self = (wyBitmapFont*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isFile'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isFile();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isFile'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getPath of class  wyBitmapFont */
#ifndef TOLUA_DISABLE_tolua_bitmapfont_wyBitmapFont_getPath00
static int tolua_bitmapfont_wyBitmapFont_getPath00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyBitmapFont",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyBitmapFont* self = (wyBitmapFont*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getPath'", NULL);
#endif
  {
   const char* tolua_ret = (const char*)  self->getPath();
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
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

/* method: addCharInfo of class  wyBitmapFont */
#ifndef TOLUA_DISABLE_tolua_bitmapfont_wyBitmapFont_addCharInfo00
static int tolua_bitmapfont_wyBitmapFont_addCharInfo00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyBitmapFont",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyCharInfo",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyBitmapFont* self = (wyBitmapFont*)  tolua_tousertype(tolua_S,1,0);
  wyCharInfo* ci = ((wyCharInfo*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addCharInfo'", NULL);
#endif
  {
   self->addCharInfo(ci);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addCharInfo'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getLineHeight of class  wyBitmapFont */
#ifndef TOLUA_DISABLE_tolua_bitmapfont_wyBitmapFont_getLineHeight00
static int tolua_bitmapfont_wyBitmapFont_getLineHeight00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyBitmapFont",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyBitmapFont* self = (wyBitmapFont*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getLineHeight'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getLineHeight();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getLineHeight'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setLineHeight of class  wyBitmapFont */
#ifndef TOLUA_DISABLE_tolua_bitmapfont_wyBitmapFont_setLineHeight00
static int tolua_bitmapfont_wyBitmapFont_setLineHeight00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyBitmapFont",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyBitmapFont* self = (wyBitmapFont*)  tolua_tousertype(tolua_S,1,0);
  float height = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setLineHeight'", NULL);
#endif
  {
   self->setLineHeight(height);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setLineHeight'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: make of class  wyBitmapFontLabel */
#ifndef TOLUA_DISABLE_tolua_bitmapfont_wyBitmapFontLabel_make00
static int tolua_bitmapfont_wyBitmapFontLabel_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyBitmapFontLabel",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyBitmapFont",0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyBitmapFont* font = ((wyBitmapFont*)  tolua_tousertype(tolua_S,2,0));
  const char* text = ((const char*)  tolua_tostring(tolua_S,3,0));
  {
   wyBitmapFontLabel* tolua_ret = (wyBitmapFontLabel*)  wyBitmapFontLabel::make(font,text);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyBitmapFontLabel");
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

/* method: new of class  wyBitmapFontLabel */
#ifndef TOLUA_DISABLE_tolua_bitmapfont_wyBitmapFontLabel_new00
static int tolua_bitmapfont_wyBitmapFontLabel_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyBitmapFontLabel",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyBitmapFont",0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyBitmapFont* font = ((wyBitmapFont*)  tolua_tousertype(tolua_S,2,0));
  const char* text = ((const char*)  tolua_tostring(tolua_S,3,0));
  {
   wyBitmapFontLabel* tolua_ret = (wyBitmapFontLabel*)  Mtolua_new((wyBitmapFontLabel)(font,text));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyBitmapFontLabel");
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

/* method: new_local of class  wyBitmapFontLabel */
#ifndef TOLUA_DISABLE_tolua_bitmapfont_wyBitmapFontLabel_new00_local
static int tolua_bitmapfont_wyBitmapFontLabel_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyBitmapFontLabel",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyBitmapFont",0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyBitmapFont* font = ((wyBitmapFont*)  tolua_tousertype(tolua_S,2,0));
  const char* text = ((const char*)  tolua_tostring(tolua_S,3,0));
  {
   wyBitmapFontLabel* tolua_ret = (wyBitmapFontLabel*)  Mtolua_new((wyBitmapFontLabel)(font,text));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyBitmapFontLabel");
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

/* method: delete of class  wyBitmapFontLabel */
#ifndef TOLUA_DISABLE_tolua_bitmapfont_wyBitmapFontLabel_delete00
static int tolua_bitmapfont_wyBitmapFontLabel_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyBitmapFontLabel",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyBitmapFontLabel* self = (wyBitmapFontLabel*)  tolua_tousertype(tolua_S,1,0);
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

/* method: draw of class  wyBitmapFontLabel */
#ifndef TOLUA_DISABLE_tolua_bitmapfont_wyBitmapFontLabel_draw00
static int tolua_bitmapfont_wyBitmapFontLabel_draw00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyBitmapFontLabel",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyBitmapFontLabel* self = (wyBitmapFontLabel*)  tolua_tousertype(tolua_S,1,0);
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

/* method: setText of class  wyBitmapFontLabel */
#ifndef TOLUA_DISABLE_tolua_bitmapfont_wyBitmapFontLabel_setText00
static int tolua_bitmapfont_wyBitmapFontLabel_setText00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyBitmapFontLabel",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyBitmapFontLabel* self = (wyBitmapFontLabel*)  tolua_tousertype(tolua_S,1,0);
  const char* text = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setText'", NULL);
#endif
  {
   self->setText(text);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setText'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getText of class  wyBitmapFontLabel */
#ifndef TOLUA_DISABLE_tolua_bitmapfont_wyBitmapFontLabel_getText00
static int tolua_bitmapfont_wyBitmapFontLabel_getText00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyBitmapFontLabel",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyBitmapFontLabel* self = (wyBitmapFontLabel*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getText'", NULL);
#endif
  {
   const char* tolua_ret = (const char*)  self->getText();
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getText'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setFont of class  wyBitmapFontLabel */
#ifndef TOLUA_DISABLE_tolua_bitmapfont_wyBitmapFontLabel_setFont00
static int tolua_bitmapfont_wyBitmapFontLabel_setFont00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyBitmapFontLabel",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyBitmapFont",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyBitmapFontLabel* self = (wyBitmapFontLabel*)  tolua_tousertype(tolua_S,1,0);
  wyBitmapFont* font = ((wyBitmapFont*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setFont'", NULL);
#endif
  {
   self->setFont(font);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setFont'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getFont of class  wyBitmapFontLabel */
#ifndef TOLUA_DISABLE_tolua_bitmapfont_wyBitmapFontLabel_getFont00
static int tolua_bitmapfont_wyBitmapFontLabel_getFont00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyBitmapFontLabel",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyBitmapFontLabel* self = (wyBitmapFontLabel*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getFont'", NULL);
#endif
  {
   wyBitmapFont* tolua_ret = (wyBitmapFont*)  self->getFont();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyBitmapFont");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getFont'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setColor of class  wyBitmapFontLabel */
#ifndef TOLUA_DISABLE_tolua_bitmapfont_wyBitmapFontLabel_setColor00
static int tolua_bitmapfont_wyBitmapFontLabel_setColor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyBitmapFontLabel",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"wyColor4B",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyBitmapFontLabel* self = (wyBitmapFontLabel*)  tolua_tousertype(tolua_S,1,0);
  wyColor4B color = *((wyColor4B*)  tolua_tousertype(tolua_S,2,0));
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

/* method: setColor of class  wyBitmapFontLabel */
#ifndef TOLUA_DISABLE_tolua_bitmapfont_wyBitmapFontLabel_setColor01
static int tolua_bitmapfont_wyBitmapFontLabel_setColor01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyBitmapFontLabel",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"wyColor3B",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  wyBitmapFontLabel* self = (wyBitmapFontLabel*)  tolua_tousertype(tolua_S,1,0);
  wyColor3B color = *((wyColor3B*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setColor'", NULL);
#endif
  {
   self->setColor(color);
  }
 }
 return 0;
tolua_lerror:
 return tolua_bitmapfont_wyBitmapFontLabel_setColor00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: getColor of class  wyBitmapFontLabel */
#ifndef TOLUA_DISABLE_tolua_bitmapfont_wyBitmapFontLabel_getColor00
static int tolua_bitmapfont_wyBitmapFontLabel_getColor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyBitmapFontLabel",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyBitmapFontLabel* self = (wyBitmapFontLabel*)  tolua_tousertype(tolua_S,1,0);
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

/* method: getAlpha of class  wyBitmapFontLabel */
#ifndef TOLUA_DISABLE_tolua_bitmapfont_wyBitmapFontLabel_getAlpha00
static int tolua_bitmapfont_wyBitmapFontLabel_getAlpha00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyBitmapFontLabel",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyBitmapFontLabel* self = (wyBitmapFontLabel*)  tolua_tousertype(tolua_S,1,0);
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

/* method: setAlpha of class  wyBitmapFontLabel */
#ifndef TOLUA_DISABLE_tolua_bitmapfont_wyBitmapFontLabel_setAlpha00
static int tolua_bitmapfont_wyBitmapFontLabel_setAlpha00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyBitmapFontLabel",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyBitmapFontLabel* self = (wyBitmapFontLabel*)  tolua_tousertype(tolua_S,1,0);
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

/* method: setSpaceWidth of class  wyBitmapFontLabel */
#ifndef TOLUA_DISABLE_tolua_bitmapfont_wyBitmapFontLabel_setSpaceWidth00
static int tolua_bitmapfont_wyBitmapFontLabel_setSpaceWidth00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyBitmapFontLabel",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyBitmapFontLabel* self = (wyBitmapFontLabel*)  tolua_tousertype(tolua_S,1,0);
  float w = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setSpaceWidth'", NULL);
#endif
  {
   self->setSpaceWidth(w);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setSpaceWidth'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getSpaceWidth of class  wyBitmapFontLabel */
#ifndef TOLUA_DISABLE_tolua_bitmapfont_wyBitmapFontLabel_getSpaceWidth00
static int tolua_bitmapfont_wyBitmapFontLabel_getSpaceWidth00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyBitmapFontLabel",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyBitmapFontLabel* self = (wyBitmapFontLabel*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getSpaceWidth'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getSpaceWidth();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getSpaceWidth'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setTabSize of class  wyBitmapFontLabel */
#ifndef TOLUA_DISABLE_tolua_bitmapfont_wyBitmapFontLabel_setTabSize00
static int tolua_bitmapfont_wyBitmapFontLabel_setTabSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyBitmapFontLabel",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyBitmapFontLabel* self = (wyBitmapFontLabel*)  tolua_tousertype(tolua_S,1,0);
  int tabSize = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setTabSize'", NULL);
#endif
  {
   self->setTabSize(tabSize);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setTabSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getTabSize of class  wyBitmapFontLabel */
#ifndef TOLUA_DISABLE_tolua_bitmapfont_wyBitmapFontLabel_getTabSize00
static int tolua_bitmapfont_wyBitmapFontLabel_getTabSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyBitmapFontLabel",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyBitmapFontLabel* self = (wyBitmapFontLabel*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getTabSize'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getTabSize();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getTabSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setLineWidth of class  wyBitmapFontLabel */
#ifndef TOLUA_DISABLE_tolua_bitmapfont_wyBitmapFontLabel_setLineWidth00
static int tolua_bitmapfont_wyBitmapFontLabel_setLineWidth00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyBitmapFontLabel",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyBitmapFontLabel* self = (wyBitmapFontLabel*)  tolua_tousertype(tolua_S,1,0);
  float width = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setLineWidth'", NULL);
#endif
  {
   self->setLineWidth(width);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setLineWidth'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getLineWidth of class  wyBitmapFontLabel */
#ifndef TOLUA_DISABLE_tolua_bitmapfont_wyBitmapFontLabel_getLineWidth00
static int tolua_bitmapfont_wyBitmapFontLabel_getLineWidth00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyBitmapFontLabel",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyBitmapFontLabel* self = (wyBitmapFontLabel*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getLineWidth'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getLineWidth();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getLineWidth'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getLineHeight of class  wyBitmapFontLabel */
#ifndef TOLUA_DISABLE_tolua_bitmapfont_wyBitmapFontLabel_getLineHeight00
static int tolua_bitmapfont_wyBitmapFontLabel_getLineHeight00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyBitmapFontLabel",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyBitmapFontLabel* self = (wyBitmapFontLabel*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getLineHeight'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getLineHeight();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getLineHeight'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setLineHeight of class  wyBitmapFontLabel */
#ifndef TOLUA_DISABLE_tolua_bitmapfont_wyBitmapFontLabel_setLineHeight00
static int tolua_bitmapfont_wyBitmapFontLabel_setLineHeight00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyBitmapFontLabel",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyBitmapFontLabel* self = (wyBitmapFontLabel*)  tolua_tousertype(tolua_S,1,0);
  float height = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setLineHeight'", NULL);
#endif
  {
   self->setLineHeight(height);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setLineHeight'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: load of class  wyHGEFontLoader */
#ifndef TOLUA_DISABLE_tolua_bitmapfont_wyHGEFontLoader_load00
static int tolua_bitmapfont_wyHGEFontLoader_load00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyHGEFontLoader",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyBitmapFont",0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"size_t",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,5,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyBitmapFont* font = ((wyBitmapFont*)  tolua_tousertype(tolua_S,2,0));
  const char* data = ((const char*)  tolua_tostring(tolua_S,3,0));
  size_t length = *((size_t*)  tolua_tousertype(tolua_S,4,0));
  float resScale = ((float)  tolua_tonumber(tolua_S,5,1.f));
  {
   wyHGEFontLoader::load(font,data,length,resScale);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'load'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_bitmapfont_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  tolua_cclass(tolua_S,"wyAngelCodeTXTFontLoader","wyAngelCodeTXTFontLoader","",NULL);
  tolua_beginmodule(tolua_S,"wyAngelCodeTXTFontLoader");
   tolua_function(tolua_S,"load",tolua_bitmapfont_wyAngelCodeTXTFontLoader_load00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"wyAngelCodeXMLFontLoader","wyAngelCodeXMLFontLoader","",NULL);
  tolua_beginmodule(tolua_S,"wyAngelCodeXMLFontLoader");
   tolua_function(tolua_S,"load",tolua_bitmapfont_wyAngelCodeXMLFontLoader_load00);
  tolua_endmodule(tolua_S);
  tolua_constant(tolua_S,"BFF_HGE",BFF_HGE);
  tolua_constant(tolua_S,"BFF_ANGELCODE_TXT",BFF_ANGELCODE_TXT);
  tolua_constant(tolua_S,"BFF_ANGELCODE_XML",BFF_ANGELCODE_XML);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyCharInfo","wyCharInfo","",tolua_collect_wyCharInfo);
  #else
  tolua_cclass(tolua_S,"wyCharInfo","wyCharInfo","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyCharInfo");
   tolua_function(tolua_S,"new",tolua_bitmapfont_wyCharInfo_new00);
   tolua_function(tolua_S,"new_local",tolua_bitmapfont_wyCharInfo_new00_local);
   tolua_function(tolua_S,".call",tolua_bitmapfont_wyCharInfo_new00_local);
   tolua_variable(tolua_S,"word",tolua_get_wyCharInfo_word,tolua_set_wyCharInfo_word);
   tolua_variable(tolua_S,"left",tolua_get_wyCharInfo_left,tolua_set_wyCharInfo_left);
   tolua_variable(tolua_S,"right",tolua_get_wyCharInfo_right,tolua_set_wyCharInfo_right);
   tolua_variable(tolua_S,"top",tolua_get_wyCharInfo_top,tolua_set_wyCharInfo_top);
   tolua_variable(tolua_S,"page",tolua_get_wyCharInfo_page,tolua_set_wyCharInfo_page);
   tolua_variable(tolua_S,"texRect",tolua_get_wyCharInfo_texRect,tolua_set_wyCharInfo_texRect);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"wyBitmapFont","wyBitmapFont","",NULL);
  tolua_beginmodule(tolua_S,"wyBitmapFont");
   tolua_function(tolua_S,"loadFont",tolua_bitmapfont_wyBitmapFont_loadFont00);
   tolua_function(tolua_S,"loadFont",tolua_bitmapfont_wyBitmapFont_loadFont01);
   tolua_function(tolua_S,"unloadFont",tolua_bitmapfont_wyBitmapFont_unloadFont00);
   tolua_function(tolua_S,"unloadAll",tolua_bitmapfont_wyBitmapFont_unloadAll00);
   tolua_function(tolua_S,"addTexture",tolua_bitmapfont_wyBitmapFont_addTexture00);
   tolua_function(tolua_S,"getTexture",tolua_bitmapfont_wyBitmapFont_getTexture00);
   tolua_function(tolua_S,"getCharInfo",tolua_bitmapfont_wyBitmapFont_getCharInfo00);
   tolua_function(tolua_S,"getResId",tolua_bitmapfont_wyBitmapFont_getResId00);
   tolua_function(tolua_S,"getHash",tolua_bitmapfont_wyBitmapFont_getHash00);
   tolua_function(tolua_S,"isFile",tolua_bitmapfont_wyBitmapFont_isFile00);
   tolua_function(tolua_S,"getPath",tolua_bitmapfont_wyBitmapFont_getPath00);
   tolua_function(tolua_S,"addCharInfo",tolua_bitmapfont_wyBitmapFont_addCharInfo00);
   tolua_function(tolua_S,"getLineHeight",tolua_bitmapfont_wyBitmapFont_getLineHeight00);
   tolua_function(tolua_S,"setLineHeight",tolua_bitmapfont_wyBitmapFont_setLineHeight00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyBitmapFontLabel","wyBitmapFontLabel","wyNode",tolua_collect_wyBitmapFontLabel);
  #else
  tolua_cclass(tolua_S,"wyBitmapFontLabel","wyBitmapFontLabel","wyNode",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyBitmapFontLabel");
   tolua_function(tolua_S,"make",tolua_bitmapfont_wyBitmapFontLabel_make00);
   tolua_function(tolua_S,"new",tolua_bitmapfont_wyBitmapFontLabel_new00);
   tolua_function(tolua_S,"new_local",tolua_bitmapfont_wyBitmapFontLabel_new00_local);
   tolua_function(tolua_S,".call",tolua_bitmapfont_wyBitmapFontLabel_new00_local);
   tolua_function(tolua_S,"delete",tolua_bitmapfont_wyBitmapFontLabel_delete00);
   tolua_function(tolua_S,"draw",tolua_bitmapfont_wyBitmapFontLabel_draw00);
   tolua_function(tolua_S,"setText",tolua_bitmapfont_wyBitmapFontLabel_setText00);
   tolua_function(tolua_S,"getText",tolua_bitmapfont_wyBitmapFontLabel_getText00);
   tolua_function(tolua_S,"setFont",tolua_bitmapfont_wyBitmapFontLabel_setFont00);
   tolua_function(tolua_S,"getFont",tolua_bitmapfont_wyBitmapFontLabel_getFont00);
   tolua_function(tolua_S,"setColor",tolua_bitmapfont_wyBitmapFontLabel_setColor00);
   tolua_function(tolua_S,"setColor",tolua_bitmapfont_wyBitmapFontLabel_setColor01);
   tolua_function(tolua_S,"getColor",tolua_bitmapfont_wyBitmapFontLabel_getColor00);
   tolua_function(tolua_S,"getAlpha",tolua_bitmapfont_wyBitmapFontLabel_getAlpha00);
   tolua_function(tolua_S,"setAlpha",tolua_bitmapfont_wyBitmapFontLabel_setAlpha00);
   tolua_function(tolua_S,"setSpaceWidth",tolua_bitmapfont_wyBitmapFontLabel_setSpaceWidth00);
   tolua_function(tolua_S,"getSpaceWidth",tolua_bitmapfont_wyBitmapFontLabel_getSpaceWidth00);
   tolua_function(tolua_S,"setTabSize",tolua_bitmapfont_wyBitmapFontLabel_setTabSize00);
   tolua_function(tolua_S,"getTabSize",tolua_bitmapfont_wyBitmapFontLabel_getTabSize00);
   tolua_function(tolua_S,"setLineWidth",tolua_bitmapfont_wyBitmapFontLabel_setLineWidth00);
   tolua_function(tolua_S,"getLineWidth",tolua_bitmapfont_wyBitmapFontLabel_getLineWidth00);
   tolua_function(tolua_S,"getLineHeight",tolua_bitmapfont_wyBitmapFontLabel_getLineHeight00);
   tolua_function(tolua_S,"setLineHeight",tolua_bitmapfont_wyBitmapFontLabel_setLineHeight00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"wyHGEFontLoader","wyHGEFontLoader","",NULL);
  tolua_beginmodule(tolua_S,"wyHGEFontLoader");
   tolua_function(tolua_S,"load",tolua_bitmapfont_wyHGEFontLoader_load00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_bitmapfont (lua_State* tolua_S) {
 return tolua_bitmapfont_open(tolua_S);
};
#endif

