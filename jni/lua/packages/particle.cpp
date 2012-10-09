/*
** Lua binding: particle
** Generated automatically by tolua++-1.0.92 on Thu Jan 12 22:02:23 2012.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_particle_open (lua_State* tolua_S);

#include "WiEngine.h"

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_wyPoint (lua_State* tolua_S)
{
 wyPoint* self = (wyPoint*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyParticleSystem (lua_State* tolua_S)
{
 wyParticleSystem* self = (wyParticleSystem*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyPointParticleSystem (lua_State* tolua_S)
{
 wyPointParticleSystem* self = (wyPointParticleSystem*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyQuadParticleSystem (lua_State* tolua_S)
{
 wyQuadParticleSystem* self = (wyQuadParticleSystem*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_wyBlendFunc (lua_State* tolua_S)
{
 wyBlendFunc* self = (wyBlendFunc*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"wyRect");
 tolua_usertype(tolua_S,"wyColor4F");
 tolua_usertype(tolua_S,"wyTexture2D");
 tolua_usertype(tolua_S,"wyQuadParticleSystem");
 tolua_usertype(tolua_S,"wyPoint");
 tolua_usertype(tolua_S,"wyPointParticleSystem");
 tolua_usertype(tolua_S,"wyParticleSystem");
 tolua_usertype(tolua_S,"wyNode");
 tolua_usertype(tolua_S,"wyParticle");
 tolua_usertype(tolua_S,"wyBlendFunc");
 tolua_usertype(tolua_S,"wyHGEParticleLoader");
 tolua_usertype(tolua_S,"wyParticleLoader");
}

/* method: load of class  wyHGEParticleLoader */
#ifndef TOLUA_DISABLE_tolua_particle_wyHGEParticleLoader_load00
static int tolua_particle_wyHGEParticleLoader_load00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyHGEParticleLoader",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,4,"wyTexture2D",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  int resId = ((int)  tolua_tonumber(tolua_S,2,0));
  int particleCount = ((int)  tolua_tonumber(tolua_S,3,0));
  wyTexture2D* tex = ((wyTexture2D*)  tolua_tousertype(tolua_S,4,0));
  {
   wyQuadParticleSystem* tolua_ret = (wyQuadParticleSystem*)  wyHGEParticleLoader::load(resId,particleCount,tex);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyQuadParticleSystem");
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

/* method: load of class  wyHGEParticleLoader */
#ifndef TOLUA_DISABLE_tolua_particle_wyHGEParticleLoader_load01
static int tolua_particle_wyHGEParticleLoader_load01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyHGEParticleLoader",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,4,"wyTexture2D",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,5,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const char* path = ((const char*)  tolua_tostring(tolua_S,2,0));
  int particleCount = ((int)  tolua_tonumber(tolua_S,3,0));
  wyTexture2D* tex = ((wyTexture2D*)  tolua_tousertype(tolua_S,4,0));
  bool isFile = ((bool)  tolua_toboolean(tolua_S,5,false));
  {
   wyQuadParticleSystem* tolua_ret = (wyQuadParticleSystem*)  wyHGEParticleLoader::load(path,particleCount,tex,isFile);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyQuadParticleSystem");
  }
 }
 return 1;
tolua_lerror:
 return tolua_particle_wyHGEParticleLoader_load00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* get function: pos of class  wyParticle */
#ifndef TOLUA_DISABLE_tolua_get_wyParticle_pos
static int tolua_get_wyParticle_pos(lua_State* tolua_S)
{
  wyParticle* self = (wyParticle*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'pos'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->pos,"wyPoint");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: pos of class  wyParticle */
#ifndef TOLUA_DISABLE_tolua_set_wyParticle_pos
static int tolua_set_wyParticle_pos(lua_State* tolua_S)
{
  wyParticle* self = (wyParticle*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'pos'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"wyPoint",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->pos = *((wyPoint*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: startPos of class  wyParticle */
#ifndef TOLUA_DISABLE_tolua_get_wyParticle_startPos
static int tolua_get_wyParticle_startPos(lua_State* tolua_S)
{
  wyParticle* self = (wyParticle*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'startPos'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->startPos,"wyPoint");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: startPos of class  wyParticle */
#ifndef TOLUA_DISABLE_tolua_set_wyParticle_startPos
static int tolua_set_wyParticle_startPos(lua_State* tolua_S)
{
  wyParticle* self = (wyParticle*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'startPos'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"wyPoint",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->startPos = *((wyPoint*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: color of class  wyParticle */
#ifndef TOLUA_DISABLE_tolua_get_wyParticle_color
static int tolua_get_wyParticle_color(lua_State* tolua_S)
{
  wyParticle* self = (wyParticle*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'color'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->color,"wyColor4F");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: color of class  wyParticle */
#ifndef TOLUA_DISABLE_tolua_set_wyParticle_color
static int tolua_set_wyParticle_color(lua_State* tolua_S)
{
  wyParticle* self = (wyParticle*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'color'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"wyColor4F",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->color = *((wyColor4F*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: deltaColor of class  wyParticle */
#ifndef TOLUA_DISABLE_tolua_get_wyParticle_deltaColor
static int tolua_get_wyParticle_deltaColor(lua_State* tolua_S)
{
  wyParticle* self = (wyParticle*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'deltaColor'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->deltaColor,"wyColor4F");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: deltaColor of class  wyParticle */
#ifndef TOLUA_DISABLE_tolua_set_wyParticle_deltaColor
static int tolua_set_wyParticle_deltaColor(lua_State* tolua_S)
{
  wyParticle* self = (wyParticle*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'deltaColor'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"wyColor4F",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->deltaColor = *((wyColor4F*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: size of class  wyParticle */
#ifndef TOLUA_DISABLE_tolua_get_wyParticle_size
static int tolua_get_wyParticle_size(lua_State* tolua_S)
{
  wyParticle* self = (wyParticle*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'size'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->size);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: size of class  wyParticle */
#ifndef TOLUA_DISABLE_tolua_set_wyParticle_size
static int tolua_set_wyParticle_size(lua_State* tolua_S)
{
  wyParticle* self = (wyParticle*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'size'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->size = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: deltaSize of class  wyParticle */
#ifndef TOLUA_DISABLE_tolua_get_wyParticle_deltaSize
static int tolua_get_wyParticle_deltaSize(lua_State* tolua_S)
{
  wyParticle* self = (wyParticle*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'deltaSize'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->deltaSize);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: deltaSize of class  wyParticle */
#ifndef TOLUA_DISABLE_tolua_set_wyParticle_deltaSize
static int tolua_set_wyParticle_deltaSize(lua_State* tolua_S)
{
  wyParticle* self = (wyParticle*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'deltaSize'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->deltaSize = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: rotation of class  wyParticle */
#ifndef TOLUA_DISABLE_tolua_get_wyParticle_rotation
static int tolua_get_wyParticle_rotation(lua_State* tolua_S)
{
  wyParticle* self = (wyParticle*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'rotation'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->rotation);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: rotation of class  wyParticle */
#ifndef TOLUA_DISABLE_tolua_set_wyParticle_rotation
static int tolua_set_wyParticle_rotation(lua_State* tolua_S)
{
  wyParticle* self = (wyParticle*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'rotation'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->rotation = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: deltaRotation of class  wyParticle */
#ifndef TOLUA_DISABLE_tolua_get_wyParticle_deltaRotation
static int tolua_get_wyParticle_deltaRotation(lua_State* tolua_S)
{
  wyParticle* self = (wyParticle*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'deltaRotation'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->deltaRotation);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: deltaRotation of class  wyParticle */
#ifndef TOLUA_DISABLE_tolua_set_wyParticle_deltaRotation
static int tolua_set_wyParticle_deltaRotation(lua_State* tolua_S)
{
  wyParticle* self = (wyParticle*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'deltaRotation'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->deltaRotation = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: timeToLive of class  wyParticle */
#ifndef TOLUA_DISABLE_tolua_get_wyParticle_timeToLive
static int tolua_get_wyParticle_timeToLive(lua_State* tolua_S)
{
  wyParticle* self = (wyParticle*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'timeToLive'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->timeToLive);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: timeToLive of class  wyParticle */
#ifndef TOLUA_DISABLE_tolua_set_wyParticle_timeToLive
static int tolua_set_wyParticle_timeToLive(lua_State* tolua_S)
{
  wyParticle* self = (wyParticle*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'timeToLive'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->timeToLive = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: direction of class  wyParticle */
#ifndef TOLUA_DISABLE_tolua_get_wyParticle_direction
static int tolua_get_wyParticle_direction(lua_State* tolua_S)
{
  wyParticle* self = (wyParticle*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'direction'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->direction,"wyPoint");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: direction of class  wyParticle */
#ifndef TOLUA_DISABLE_tolua_set_wyParticle_direction
static int tolua_set_wyParticle_direction(lua_State* tolua_S)
{
  wyParticle* self = (wyParticle*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'direction'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"wyPoint",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->direction = *((wyPoint*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: radialAccel of class  wyParticle */
#ifndef TOLUA_DISABLE_tolua_get_wyParticle_radialAccel
static int tolua_get_wyParticle_radialAccel(lua_State* tolua_S)
{
  wyParticle* self = (wyParticle*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'radialAccel'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->radialAccel);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: radialAccel of class  wyParticle */
#ifndef TOLUA_DISABLE_tolua_set_wyParticle_radialAccel
static int tolua_set_wyParticle_radialAccel(lua_State* tolua_S)
{
  wyParticle* self = (wyParticle*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'radialAccel'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->radialAccel = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: tangentialAccel of class  wyParticle */
#ifndef TOLUA_DISABLE_tolua_get_wyParticle_tangentialAccel
static int tolua_get_wyParticle_tangentialAccel(lua_State* tolua_S)
{
  wyParticle* self = (wyParticle*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'tangentialAccel'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->tangentialAccel);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: tangentialAccel of class  wyParticle */
#ifndef TOLUA_DISABLE_tolua_set_wyParticle_tangentialAccel
static int tolua_set_wyParticle_tangentialAccel(lua_State* tolua_S)
{
  wyParticle* self = (wyParticle*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'tangentialAccel'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->tangentialAccel = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: radian of class  wyParticle */
#ifndef TOLUA_DISABLE_tolua_get_wyParticle_radian
static int tolua_get_wyParticle_radian(lua_State* tolua_S)
{
  wyParticle* self = (wyParticle*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'radian'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->radian);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: radian of class  wyParticle */
#ifndef TOLUA_DISABLE_tolua_set_wyParticle_radian
static int tolua_set_wyParticle_radian(lua_State* tolua_S)
{
  wyParticle* self = (wyParticle*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'radian'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->radian = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: radianPerSecond of class  wyParticle */
#ifndef TOLUA_DISABLE_tolua_get_wyParticle_radianPerSecond
static int tolua_get_wyParticle_radianPerSecond(lua_State* tolua_S)
{
  wyParticle* self = (wyParticle*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'radianPerSecond'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->radianPerSecond);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: radianPerSecond of class  wyParticle */
#ifndef TOLUA_DISABLE_tolua_set_wyParticle_radianPerSecond
static int tolua_set_wyParticle_radianPerSecond(lua_State* tolua_S)
{
  wyParticle* self = (wyParticle*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'radianPerSecond'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->radianPerSecond = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: radius of class  wyParticle */
#ifndef TOLUA_DISABLE_tolua_get_wyParticle_radius
static int tolua_get_wyParticle_radius(lua_State* tolua_S)
{
  wyParticle* self = (wyParticle*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'radius'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->radius);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: radius of class  wyParticle */
#ifndef TOLUA_DISABLE_tolua_set_wyParticle_radius
static int tolua_set_wyParticle_radius(lua_State* tolua_S)
{
  wyParticle* self = (wyParticle*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'radius'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->radius = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: deltaRadius of class  wyParticle */
#ifndef TOLUA_DISABLE_tolua_get_wyParticle_deltaRadius
static int tolua_get_wyParticle_deltaRadius(lua_State* tolua_S)
{
  wyParticle* self = (wyParticle*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'deltaRadius'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->deltaRadius);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: deltaRadius of class  wyParticle */
#ifndef TOLUA_DISABLE_tolua_set_wyParticle_deltaRadius
static int tolua_set_wyParticle_deltaRadius(lua_State* tolua_S)
{
  wyParticle* self = (wyParticle*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'deltaRadius'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->deltaRadius = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* function: wyParticleNew */
#ifndef TOLUA_DISABLE_tolua_particle_wyParticleNew00
static int tolua_particle_wyParticleNew00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   wyParticle* tolua_ret = (wyParticle*)  wyParticleNew();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyParticle");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'wyParticleNew'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: load of class  wyParticleLoader */
#ifndef TOLUA_DISABLE_tolua_particle_wyParticleLoader_load00
static int tolua_particle_wyParticleLoader_load00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyParticleLoader",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  int resId = ((int)  tolua_tonumber(tolua_S,2,0));
  {
   wyQuadParticleSystem* tolua_ret = (wyQuadParticleSystem*)  wyParticleLoader::load(resId);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyQuadParticleSystem");
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

/* method: load of class  wyParticleLoader */
#ifndef TOLUA_DISABLE_tolua_particle_wyParticleLoader_load01
static int tolua_particle_wyParticleLoader_load01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyParticleLoader",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,3,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const char* path = ((const char*)  tolua_tostring(tolua_S,2,0));
  bool isFile = ((bool)  tolua_toboolean(tolua_S,3,false));
  {
   wyQuadParticleSystem* tolua_ret = (wyQuadParticleSystem*)  wyParticleLoader::load(path,isFile);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyQuadParticleSystem");
  }
 }
 return 1;
tolua_lerror:
 return tolua_particle_wyParticleLoader_load00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  wyParticleSystem */
#ifndef TOLUA_DISABLE_tolua_particle_wyParticleSystem_delete00
static int tolua_particle_wyParticleSystem_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyParticleSystem",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyParticleSystem* self = (wyParticleSystem*)  tolua_tousertype(tolua_S,1,0);
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

/* method: setPosition of class  wyParticleSystem */
#ifndef TOLUA_DISABLE_tolua_particle_wyParticleSystem_setPosition00
static int tolua_particle_wyParticleSystem_setPosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyParticleSystem",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyParticleSystem* self = (wyParticleSystem*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setPosition'", NULL);
#endif
  {
   self->setPosition(x,y);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setPosition'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getBlendFunc of class  wyParticleSystem */
#ifndef TOLUA_DISABLE_tolua_particle_wyParticleSystem_getBlendFunc00
static int tolua_particle_wyParticleSystem_getBlendFunc00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyParticleSystem",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyParticleSystem* self = (wyParticleSystem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getBlendFunc'", NULL);
#endif
  {
   wyBlendFunc tolua_ret = (wyBlendFunc)  self->getBlendFunc();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((wyBlendFunc)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"wyBlendFunc");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(wyBlendFunc));
     tolua_pushusertype(tolua_S,tolua_obj,"wyBlendFunc");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getBlendFunc'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setBlendFunc of class  wyParticleSystem */
#ifndef TOLUA_DISABLE_tolua_particle_wyParticleSystem_setBlendFunc00
static int tolua_particle_wyParticleSystem_setBlendFunc00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyParticleSystem",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"wyBlendFunc",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyParticleSystem* self = (wyParticleSystem*)  tolua_tousertype(tolua_S,1,0);
  wyBlendFunc func = *((wyBlendFunc*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setBlendFunc'", NULL);
#endif
  {
   self->setBlendFunc(func);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setBlendFunc'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getTexture of class  wyParticleSystem */
#ifndef TOLUA_DISABLE_tolua_particle_wyParticleSystem_getTexture00
static int tolua_particle_wyParticleSystem_getTexture00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyParticleSystem",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyParticleSystem* self = (wyParticleSystem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getTexture'", NULL);
#endif
  {
   wyTexture2D* tolua_ret = (wyTexture2D*)  self->getTexture();
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

/* method: setTexture of class  wyParticleSystem */
#ifndef TOLUA_DISABLE_tolua_particle_wyParticleSystem_setTexture00
static int tolua_particle_wyParticleSystem_setTexture00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyParticleSystem",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyTexture2D",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyParticleSystem* self = (wyParticleSystem*)  tolua_tousertype(tolua_S,1,0);
  wyTexture2D* tex = ((wyTexture2D*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setTexture'", NULL);
#endif
  {
   self->setTexture(tex);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setTexture'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: resetSystem of class  wyParticleSystem */
#ifndef TOLUA_DISABLE_tolua_particle_wyParticleSystem_resetSystem00
static int tolua_particle_wyParticleSystem_resetSystem00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyParticleSystem",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyParticleSystem* self = (wyParticleSystem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'resetSystem'", NULL);
#endif
  {
   self->resetSystem();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'resetSystem'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: stopSystem of class  wyParticleSystem */
#ifndef TOLUA_DISABLE_tolua_particle_wyParticleSystem_stopSystem00
static int tolua_particle_wyParticleSystem_stopSystem00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyParticleSystem",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyParticleSystem* self = (wyParticleSystem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'stopSystem'", NULL);
#endif
  {
   self->stopSystem();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'stopSystem'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setBlendAdditive of class  wyParticleSystem */
#ifndef TOLUA_DISABLE_tolua_particle_wyParticleSystem_setBlendAdditive00
static int tolua_particle_wyParticleSystem_setBlendAdditive00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyParticleSystem",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyParticleSystem* self = (wyParticleSystem*)  tolua_tousertype(tolua_S,1,0);
  bool additive = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setBlendAdditive'", NULL);
#endif
  {
   self->setBlendAdditive(additive);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setBlendAdditive'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isBlendAdditive of class  wyParticleSystem */
#ifndef TOLUA_DISABLE_tolua_particle_wyParticleSystem_isBlendAdditive00
static int tolua_particle_wyParticleSystem_isBlendAdditive00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyParticleSystem",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyParticleSystem* self = (wyParticleSystem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isBlendAdditive'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isBlendAdditive();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isBlendAdditive'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setParticlePositionVariance of class  wyParticleSystem */
#ifndef TOLUA_DISABLE_tolua_particle_wyParticleSystem_setParticlePositionVariance00
static int tolua_particle_wyParticleSystem_setParticlePositionVariance00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyParticleSystem",0,&tolua_err) ||
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
  wyParticleSystem* self = (wyParticleSystem*)  tolua_tousertype(tolua_S,1,0);
  float baseX = ((float)  tolua_tonumber(tolua_S,2,0));
  float baseY = ((float)  tolua_tonumber(tolua_S,3,0));
  float varianceX = ((float)  tolua_tonumber(tolua_S,4,0));
  float varianceY = ((float)  tolua_tonumber(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setParticlePositionVariance'", NULL);
#endif
  {
   self->setParticlePositionVariance(baseX,baseY,varianceX,varianceY);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setParticlePositionVariance'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setDirectionAngleVariance of class  wyParticleSystem */
#ifndef TOLUA_DISABLE_tolua_particle_wyParticleSystem_setDirectionAngleVariance00
static int tolua_particle_wyParticleSystem_setDirectionAngleVariance00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyParticleSystem",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyParticleSystem* self = (wyParticleSystem*)  tolua_tousertype(tolua_S,1,0);
  float base = ((float)  tolua_tonumber(tolua_S,2,0));
  float variance = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setDirectionAngleVariance'", NULL);
#endif
  {
   self->setDirectionAngleVariance(base,variance);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setDirectionAngleVariance'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setStartSizeVariance of class  wyParticleSystem */
#ifndef TOLUA_DISABLE_tolua_particle_wyParticleSystem_setStartSizeVariance00
static int tolua_particle_wyParticleSystem_setStartSizeVariance00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyParticleSystem",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyParticleSystem* self = (wyParticleSystem*)  tolua_tousertype(tolua_S,1,0);
  float base = ((float)  tolua_tonumber(tolua_S,2,0));
  float variance = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setStartSizeVariance'", NULL);
#endif
  {
   self->setStartSizeVariance(base,variance);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setStartSizeVariance'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setEndSizeVariance of class  wyParticleSystem */
#ifndef TOLUA_DISABLE_tolua_particle_wyParticleSystem_setEndSizeVariance00
static int tolua_particle_wyParticleSystem_setEndSizeVariance00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyParticleSystem",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyParticleSystem* self = (wyParticleSystem*)  tolua_tousertype(tolua_S,1,0);
  float base = ((float)  tolua_tonumber(tolua_S,2,0));
  float variance = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setEndSizeVariance'", NULL);
#endif
  {
   self->setEndSizeVariance(base,variance);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setEndSizeVariance'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setLifeVariance of class  wyParticleSystem */
#ifndef TOLUA_DISABLE_tolua_particle_wyParticleSystem_setLifeVariance00
static int tolua_particle_wyParticleSystem_setLifeVariance00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyParticleSystem",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyParticleSystem* self = (wyParticleSystem*)  tolua_tousertype(tolua_S,1,0);
  float base = ((float)  tolua_tonumber(tolua_S,2,0));
  float variance = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setLifeVariance'", NULL);
#endif
  {
   self->setLifeVariance(base,variance);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setLifeVariance'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setStartColorVariance of class  wyParticleSystem */
#ifndef TOLUA_DISABLE_tolua_particle_wyParticleSystem_setStartColorVariance00
static int tolua_particle_wyParticleSystem_setStartColorVariance00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyParticleSystem",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,7,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,8,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,9,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,10,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyParticleSystem* self = (wyParticleSystem*)  tolua_tousertype(tolua_S,1,0);
  float baseR = ((float)  tolua_tonumber(tolua_S,2,0));
  float baseG = ((float)  tolua_tonumber(tolua_S,3,0));
  float baseB = ((float)  tolua_tonumber(tolua_S,4,0));
  float baseA = ((float)  tolua_tonumber(tolua_S,5,0));
  float varR = ((float)  tolua_tonumber(tolua_S,6,0));
  float varG = ((float)  tolua_tonumber(tolua_S,7,0));
  float varB = ((float)  tolua_tonumber(tolua_S,8,0));
  float varA = ((float)  tolua_tonumber(tolua_S,9,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setStartColorVariance'", NULL);
#endif
  {
   self->setStartColorVariance(baseR,baseG,baseB,baseA,varR,varG,varB,varA);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setStartColorVariance'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setEndColorVariance of class  wyParticleSystem */
#ifndef TOLUA_DISABLE_tolua_particle_wyParticleSystem_setEndColorVariance00
static int tolua_particle_wyParticleSystem_setEndColorVariance00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyParticleSystem",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,7,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,8,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,9,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,10,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyParticleSystem* self = (wyParticleSystem*)  tolua_tousertype(tolua_S,1,0);
  float baseR = ((float)  tolua_tonumber(tolua_S,2,0));
  float baseG = ((float)  tolua_tonumber(tolua_S,3,0));
  float baseB = ((float)  tolua_tonumber(tolua_S,4,0));
  float baseA = ((float)  tolua_tonumber(tolua_S,5,0));
  float varR = ((float)  tolua_tonumber(tolua_S,6,0));
  float varG = ((float)  tolua_tonumber(tolua_S,7,0));
  float varB = ((float)  tolua_tonumber(tolua_S,8,0));
  float varA = ((float)  tolua_tonumber(tolua_S,9,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setEndColorVariance'", NULL);
#endif
  {
   self->setEndColorVariance(baseR,baseG,baseB,baseA,varR,varG,varB,varA);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setEndColorVariance'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setStartSpinVariance of class  wyParticleSystem */
#ifndef TOLUA_DISABLE_tolua_particle_wyParticleSystem_setStartSpinVariance00
static int tolua_particle_wyParticleSystem_setStartSpinVariance00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyParticleSystem",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyParticleSystem* self = (wyParticleSystem*)  tolua_tousertype(tolua_S,1,0);
  float base = ((float)  tolua_tonumber(tolua_S,2,0));
  float variance = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setStartSpinVariance'", NULL);
#endif
  {
   self->setStartSpinVariance(base,variance);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setStartSpinVariance'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setEndSpinVariance of class  wyParticleSystem */
#ifndef TOLUA_DISABLE_tolua_particle_wyParticleSystem_setEndSpinVariance00
static int tolua_particle_wyParticleSystem_setEndSpinVariance00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyParticleSystem",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyParticleSystem* self = (wyParticleSystem*)  tolua_tousertype(tolua_S,1,0);
  float base = ((float)  tolua_tonumber(tolua_S,2,0));
  float variance = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setEndSpinVariance'", NULL);
#endif
  {
   self->setEndSpinVariance(base,variance);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setEndSpinVariance'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setSpeedVariance of class  wyParticleSystem */
#ifndef TOLUA_DISABLE_tolua_particle_wyParticleSystem_setSpeedVariance00
static int tolua_particle_wyParticleSystem_setSpeedVariance00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyParticleSystem",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyParticleSystem* self = (wyParticleSystem*)  tolua_tousertype(tolua_S,1,0);
  float base = ((float)  tolua_tonumber(tolua_S,2,0));
  float variance = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setSpeedVariance'", NULL);
#endif
  {
   self->setSpeedVariance(base,variance);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setSpeedVariance'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setParticleGravity of class  wyParticleSystem */
#ifndef TOLUA_DISABLE_tolua_particle_wyParticleSystem_setParticleGravity00
static int tolua_particle_wyParticleSystem_setParticleGravity00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyParticleSystem",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyParticleSystem* self = (wyParticleSystem*)  tolua_tousertype(tolua_S,1,0);
  float gravityX = ((float)  tolua_tonumber(tolua_S,2,0));
  float gravityY = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setParticleGravity'", NULL);
#endif
  {
   self->setParticleGravity(gravityX,gravityY);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setParticleGravity'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setTangentialAccelerationVariance of class  wyParticleSystem */
#ifndef TOLUA_DISABLE_tolua_particle_wyParticleSystem_setTangentialAccelerationVariance00
static int tolua_particle_wyParticleSystem_setTangentialAccelerationVariance00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyParticleSystem",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyParticleSystem* self = (wyParticleSystem*)  tolua_tousertype(tolua_S,1,0);
  float base = ((float)  tolua_tonumber(tolua_S,2,0));
  float variance = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setTangentialAccelerationVariance'", NULL);
#endif
  {
   self->setTangentialAccelerationVariance(base,variance);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setTangentialAccelerationVariance'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setRadialAccelerationVariance of class  wyParticleSystem */
#ifndef TOLUA_DISABLE_tolua_particle_wyParticleSystem_setRadialAccelerationVariance00
static int tolua_particle_wyParticleSystem_setRadialAccelerationVariance00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyParticleSystem",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyParticleSystem* self = (wyParticleSystem*)  tolua_tousertype(tolua_S,1,0);
  float base = ((float)  tolua_tonumber(tolua_S,2,0));
  float variance = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setRadialAccelerationVariance'", NULL);
#endif
  {
   self->setRadialAccelerationVariance(base,variance);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setRadialAccelerationVariance'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setStartRadiusVariance of class  wyParticleSystem */
#ifndef TOLUA_DISABLE_tolua_particle_wyParticleSystem_setStartRadiusVariance00
static int tolua_particle_wyParticleSystem_setStartRadiusVariance00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyParticleSystem",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyParticleSystem* self = (wyParticleSystem*)  tolua_tousertype(tolua_S,1,0);
  float base = ((float)  tolua_tonumber(tolua_S,2,0));
  float variance = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setStartRadiusVariance'", NULL);
#endif
  {
   self->setStartRadiusVariance(base,variance);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setStartRadiusVariance'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setEndRadiusVariance of class  wyParticleSystem */
#ifndef TOLUA_DISABLE_tolua_particle_wyParticleSystem_setEndRadiusVariance00
static int tolua_particle_wyParticleSystem_setEndRadiusVariance00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyParticleSystem",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyParticleSystem* self = (wyParticleSystem*)  tolua_tousertype(tolua_S,1,0);
  float base = ((float)  tolua_tonumber(tolua_S,2,0));
  float variance = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setEndRadiusVariance'", NULL);
#endif
  {
   self->setEndRadiusVariance(base,variance);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setEndRadiusVariance'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setRotationVariance of class  wyParticleSystem */
#ifndef TOLUA_DISABLE_tolua_particle_wyParticleSystem_setRotationVariance00
static int tolua_particle_wyParticleSystem_setRotationVariance00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyParticleSystem",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyParticleSystem* self = (wyParticleSystem*)  tolua_tousertype(tolua_S,1,0);
  float base = ((float)  tolua_tonumber(tolua_S,2,0));
  float variance = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setRotationVariance'", NULL);
#endif
  {
   self->setRotationVariance(base,variance);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setRotationVariance'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getParticleGravity of class  wyParticleSystem */
#ifndef TOLUA_DISABLE_tolua_particle_wyParticleSystem_getParticleGravity00
static int tolua_particle_wyParticleSystem_getParticleGravity00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyParticleSystem",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyParticleSystem* self = (wyParticleSystem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getParticleGravity'", NULL);
#endif
  {
   wyPoint tolua_ret = (wyPoint)  self->getParticleGravity();
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
 tolua_error(tolua_S,"#ferror in function 'getParticleGravity'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setDuration of class  wyParticleSystem */
#ifndef TOLUA_DISABLE_tolua_particle_wyParticleSystem_setDuration00
static int tolua_particle_wyParticleSystem_setDuration00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyParticleSystem",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyParticleSystem* self = (wyParticleSystem*)  tolua_tousertype(tolua_S,1,0);
  float d = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setDuration'", NULL);
#endif
  {
   self->setDuration(d);
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

/* method: getDuration of class  wyParticleSystem */
#ifndef TOLUA_DISABLE_tolua_particle_wyParticleSystem_getDuration00
static int tolua_particle_wyParticleSystem_getDuration00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyParticleSystem",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyParticleSystem* self = (wyParticleSystem*)  tolua_tousertype(tolua_S,1,0);
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

/* method: getCenterOfGravity of class  wyParticleSystem */
#ifndef TOLUA_DISABLE_tolua_particle_wyParticleSystem_getCenterOfGravity00
static int tolua_particle_wyParticleSystem_getCenterOfGravity00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyParticleSystem",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyParticleSystem* self = (wyParticleSystem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getCenterOfGravity'", NULL);
#endif
  {
   wyPoint tolua_ret = (wyPoint)  self->getCenterOfGravity();
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
 tolua_error(tolua_S,"#ferror in function 'getCenterOfGravity'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isAutoRemoveOnFinish of class  wyParticleSystem */
#ifndef TOLUA_DISABLE_tolua_particle_wyParticleSystem_isAutoRemoveOnFinish00
static int tolua_particle_wyParticleSystem_isAutoRemoveOnFinish00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyParticleSystem",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyParticleSystem* self = (wyParticleSystem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isAutoRemoveOnFinish'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isAutoRemoveOnFinish();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isAutoRemoveOnFinish'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setAutoRemoveOnFinish of class  wyParticleSystem */
#ifndef TOLUA_DISABLE_tolua_particle_wyParticleSystem_setAutoRemoveOnFinish00
static int tolua_particle_wyParticleSystem_setAutoRemoveOnFinish00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyParticleSystem",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyParticleSystem* self = (wyParticleSystem*)  tolua_tousertype(tolua_S,1,0);
  bool flag = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setAutoRemoveOnFinish'", NULL);
#endif
  {
   self->setAutoRemoveOnFinish(flag);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setAutoRemoveOnFinish'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getEmissionRate of class  wyParticleSystem */
#ifndef TOLUA_DISABLE_tolua_particle_wyParticleSystem_getEmissionRate00
static int tolua_particle_wyParticleSystem_getEmissionRate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyParticleSystem",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyParticleSystem* self = (wyParticleSystem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getEmissionRate'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getEmissionRate();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getEmissionRate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setEmissionRate of class  wyParticleSystem */
#ifndef TOLUA_DISABLE_tolua_particle_wyParticleSystem_setEmissionRate00
static int tolua_particle_wyParticleSystem_setEmissionRate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyParticleSystem",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyParticleSystem* self = (wyParticleSystem*)  tolua_tousertype(tolua_S,1,0);
  float rate = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setEmissionRate'", NULL);
#endif
  {
   self->setEmissionRate(rate);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setEmissionRate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getLife of class  wyParticleSystem */
#ifndef TOLUA_DISABLE_tolua_particle_wyParticleSystem_getLife00
static int tolua_particle_wyParticleSystem_getLife00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyParticleSystem",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyParticleSystem* self = (wyParticleSystem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getLife'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getLife();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getLife'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getEmitterMode of class  wyParticleSystem */
#ifndef TOLUA_DISABLE_tolua_particle_wyParticleSystem_getEmitterMode00
static int tolua_particle_wyParticleSystem_getEmitterMode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyParticleSystem",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyParticleSystem* self = (wyParticleSystem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getEmitterMode'", NULL);
#endif
  {
   wyParticleSystemMode tolua_ret = (wyParticleSystemMode)  self->getEmitterMode();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getEmitterMode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setEmitterMode of class  wyParticleSystem */
#ifndef TOLUA_DISABLE_tolua_particle_wyParticleSystem_setEmitterMode00
static int tolua_particle_wyParticleSystem_setEmitterMode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyParticleSystem",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyParticleSystem* self = (wyParticleSystem*)  tolua_tousertype(tolua_S,1,0);
  wyParticleSystemMode mode = ((wyParticleSystemMode) (int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setEmitterMode'", NULL);
#endif
  {
   self->setEmitterMode(mode);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setEmitterMode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getPositionType of class  wyParticleSystem */
#ifndef TOLUA_DISABLE_tolua_particle_wyParticleSystem_getPositionType00
static int tolua_particle_wyParticleSystem_getPositionType00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyParticleSystem",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyParticleSystem* self = (wyParticleSystem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getPositionType'", NULL);
#endif
  {
   wyParticleSystemPositionType tolua_ret = (wyParticleSystemPositionType)  self->getPositionType();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getPositionType'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setPositionType of class  wyParticleSystem */
#ifndef TOLUA_DISABLE_tolua_particle_wyParticleSystem_setPositionType00
static int tolua_particle_wyParticleSystem_setPositionType00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyParticleSystem",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyParticleSystem* self = (wyParticleSystem*)  tolua_tousertype(tolua_S,1,0);
  wyParticleSystemPositionType type = ((wyParticleSystemPositionType) (int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setPositionType'", NULL);
#endif
  {
   self->setPositionType(type);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setPositionType'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getParticleCount of class  wyParticleSystem */
#ifndef TOLUA_DISABLE_tolua_particle_wyParticleSystem_getParticleCount00
static int tolua_particle_wyParticleSystem_getParticleCount00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyParticleSystem",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyParticleSystem* self = (wyParticleSystem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getParticleCount'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getParticleCount();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getParticleCount'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getMaxParticles of class  wyParticleSystem */
#ifndef TOLUA_DISABLE_tolua_particle_wyParticleSystem_getMaxParticles00
static int tolua_particle_wyParticleSystem_getMaxParticles00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyParticleSystem",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyParticleSystem* self = (wyParticleSystem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getMaxParticles'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getMaxParticles();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getMaxParticles'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  wyPointParticleSystem */
#ifndef TOLUA_DISABLE_tolua_particle_wyPointParticleSystem_new00
static int tolua_particle_wyPointParticleSystem_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyPointParticleSystem",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  int numberOfParticles = ((int)  tolua_tonumber(tolua_S,2,0));
  {
   wyPointParticleSystem* tolua_ret = (wyPointParticleSystem*)  Mtolua_new((wyPointParticleSystem)(numberOfParticles));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyPointParticleSystem");
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

/* method: new_local of class  wyPointParticleSystem */
#ifndef TOLUA_DISABLE_tolua_particle_wyPointParticleSystem_new00_local
static int tolua_particle_wyPointParticleSystem_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyPointParticleSystem",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  int numberOfParticles = ((int)  tolua_tonumber(tolua_S,2,0));
  {
   wyPointParticleSystem* tolua_ret = (wyPointParticleSystem*)  Mtolua_new((wyPointParticleSystem)(numberOfParticles));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyPointParticleSystem");
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

/* method: delete of class  wyPointParticleSystem */
#ifndef TOLUA_DISABLE_tolua_particle_wyPointParticleSystem_delete00
static int tolua_particle_wyPointParticleSystem_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyPointParticleSystem",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyPointParticleSystem* self = (wyPointParticleSystem*)  tolua_tousertype(tolua_S,1,0);
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

/* method: draw of class  wyPointParticleSystem */
#ifndef TOLUA_DISABLE_tolua_particle_wyPointParticleSystem_draw00
static int tolua_particle_wyPointParticleSystem_draw00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyPointParticleSystem",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyPointParticleSystem* self = (wyPointParticleSystem*)  tolua_tousertype(tolua_S,1,0);
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

/* method: new of class  wyQuadParticleSystem */
#ifndef TOLUA_DISABLE_tolua_particle_wyQuadParticleSystem_new00
static int tolua_particle_wyQuadParticleSystem_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyQuadParticleSystem",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  int numberOfParticles = ((int)  tolua_tonumber(tolua_S,2,0));
  {
   wyQuadParticleSystem* tolua_ret = (wyQuadParticleSystem*)  Mtolua_new((wyQuadParticleSystem)(numberOfParticles));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyQuadParticleSystem");
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

/* method: new_local of class  wyQuadParticleSystem */
#ifndef TOLUA_DISABLE_tolua_particle_wyQuadParticleSystem_new00_local
static int tolua_particle_wyQuadParticleSystem_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"wyQuadParticleSystem",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  int numberOfParticles = ((int)  tolua_tonumber(tolua_S,2,0));
  {
   wyQuadParticleSystem* tolua_ret = (wyQuadParticleSystem*)  Mtolua_new((wyQuadParticleSystem)(numberOfParticles));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wyQuadParticleSystem");
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

/* method: delete of class  wyQuadParticleSystem */
#ifndef TOLUA_DISABLE_tolua_particle_wyQuadParticleSystem_delete00
static int tolua_particle_wyQuadParticleSystem_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyQuadParticleSystem",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyQuadParticleSystem* self = (wyQuadParticleSystem*)  tolua_tousertype(tolua_S,1,0);
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

/* method: draw of class  wyQuadParticleSystem */
#ifndef TOLUA_DISABLE_tolua_particle_wyQuadParticleSystem_draw00
static int tolua_particle_wyQuadParticleSystem_draw00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyQuadParticleSystem",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyQuadParticleSystem* self = (wyQuadParticleSystem*)  tolua_tousertype(tolua_S,1,0);
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

/* method: setTexture of class  wyQuadParticleSystem */
#ifndef TOLUA_DISABLE_tolua_particle_wyQuadParticleSystem_setTexture00
static int tolua_particle_wyQuadParticleSystem_setTexture00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyQuadParticleSystem",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyTexture2D",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  wyQuadParticleSystem* self = (wyQuadParticleSystem*)  tolua_tousertype(tolua_S,1,0);
  wyTexture2D* tex = ((wyTexture2D*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setTexture'", NULL);
#endif
  {
   self->setTexture(tex);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setTexture'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setTexture of class  wyQuadParticleSystem */
#ifndef TOLUA_DISABLE_tolua_particle_wyQuadParticleSystem_setTexture01
static int tolua_particle_wyQuadParticleSystem_setTexture01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"wyQuadParticleSystem",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wyTexture2D",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"wyRect",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  wyQuadParticleSystem* self = (wyQuadParticleSystem*)  tolua_tousertype(tolua_S,1,0);
  wyTexture2D* tex = ((wyTexture2D*)  tolua_tousertype(tolua_S,2,0));
  wyRect rect = *((wyRect*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setTexture'", NULL);
#endif
  {
   self->setTexture(tex,rect);
  }
 }
 return 0;
tolua_lerror:
 return tolua_particle_wyQuadParticleSystem_setTexture00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_particle_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  tolua_cclass(tolua_S,"wyHGEParticleLoader","wyHGEParticleLoader","",NULL);
  tolua_beginmodule(tolua_S,"wyHGEParticleLoader");
   tolua_function(tolua_S,"load",tolua_particle_wyHGEParticleLoader_load00);
   tolua_function(tolua_S,"load",tolua_particle_wyHGEParticleLoader_load01);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"wyParticle","wyParticle","",NULL);
  tolua_beginmodule(tolua_S,"wyParticle");
   tolua_variable(tolua_S,"pos",tolua_get_wyParticle_pos,tolua_set_wyParticle_pos);
   tolua_variable(tolua_S,"startPos",tolua_get_wyParticle_startPos,tolua_set_wyParticle_startPos);
   tolua_variable(tolua_S,"color",tolua_get_wyParticle_color,tolua_set_wyParticle_color);
   tolua_variable(tolua_S,"deltaColor",tolua_get_wyParticle_deltaColor,tolua_set_wyParticle_deltaColor);
   tolua_variable(tolua_S,"size",tolua_get_wyParticle_size,tolua_set_wyParticle_size);
   tolua_variable(tolua_S,"deltaSize",tolua_get_wyParticle_deltaSize,tolua_set_wyParticle_deltaSize);
   tolua_variable(tolua_S,"rotation",tolua_get_wyParticle_rotation,tolua_set_wyParticle_rotation);
   tolua_variable(tolua_S,"deltaRotation",tolua_get_wyParticle_deltaRotation,tolua_set_wyParticle_deltaRotation);
   tolua_variable(tolua_S,"timeToLive",tolua_get_wyParticle_timeToLive,tolua_set_wyParticle_timeToLive);
   tolua_variable(tolua_S,"direction",tolua_get_wyParticle_direction,tolua_set_wyParticle_direction);
   tolua_variable(tolua_S,"radialAccel",tolua_get_wyParticle_radialAccel,tolua_set_wyParticle_radialAccel);
   tolua_variable(tolua_S,"tangentialAccel",tolua_get_wyParticle_tangentialAccel,tolua_set_wyParticle_tangentialAccel);
   tolua_variable(tolua_S,"radian",tolua_get_wyParticle_radian,tolua_set_wyParticle_radian);
   tolua_variable(tolua_S,"radianPerSecond",tolua_get_wyParticle_radianPerSecond,tolua_set_wyParticle_radianPerSecond);
   tolua_variable(tolua_S,"radius",tolua_get_wyParticle_radius,tolua_set_wyParticle_radius);
   tolua_variable(tolua_S,"deltaRadius",tolua_get_wyParticle_deltaRadius,tolua_set_wyParticle_deltaRadius);
  tolua_endmodule(tolua_S);
  tolua_function(tolua_S,"wyParticleNew",tolua_particle_wyParticleNew00);
  tolua_cclass(tolua_S,"wyParticleLoader","wyParticleLoader","",NULL);
  tolua_beginmodule(tolua_S,"wyParticleLoader");
   tolua_function(tolua_S,"load",tolua_particle_wyParticleLoader_load00);
   tolua_function(tolua_S,"load",tolua_particle_wyParticleLoader_load01);
  tolua_endmodule(tolua_S);
  tolua_constant(tolua_S,"PARTICLE_DURATION_INFINITY",PARTICLE_DURATION_INFINITY);
  tolua_constant(tolua_S,"PARTICLE_START_SIZE_EQUAL_TO_END_SIZE",PARTICLE_START_SIZE_EQUAL_TO_END_SIZE);
  tolua_constant(tolua_S,"PARTICLE_START_RADIUS_EQUAL_TO_END_RADIUS",PARTICLE_START_RADIUS_EQUAL_TO_END_RADIUS);
  tolua_constant(tolua_S,"GRAVITY",GRAVITY);
  tolua_constant(tolua_S,"RADIUS",RADIUS);
  tolua_constant(tolua_S,"FREE",FREE);
  tolua_constant(tolua_S,"GROUPED",GROUPED);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyParticleSystem","wyParticleSystem","wyNode",tolua_collect_wyParticleSystem);
  #else
  tolua_cclass(tolua_S,"wyParticleSystem","wyParticleSystem","wyNode",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyParticleSystem");
   tolua_function(tolua_S,"delete",tolua_particle_wyParticleSystem_delete00);
   tolua_function(tolua_S,"setPosition",tolua_particle_wyParticleSystem_setPosition00);
   tolua_function(tolua_S,"getBlendFunc",tolua_particle_wyParticleSystem_getBlendFunc00);
   tolua_function(tolua_S,"setBlendFunc",tolua_particle_wyParticleSystem_setBlendFunc00);
   tolua_function(tolua_S,"getTexture",tolua_particle_wyParticleSystem_getTexture00);
   tolua_function(tolua_S,"setTexture",tolua_particle_wyParticleSystem_setTexture00);
   tolua_function(tolua_S,"resetSystem",tolua_particle_wyParticleSystem_resetSystem00);
   tolua_function(tolua_S,"stopSystem",tolua_particle_wyParticleSystem_stopSystem00);
   tolua_function(tolua_S,"setBlendAdditive",tolua_particle_wyParticleSystem_setBlendAdditive00);
   tolua_function(tolua_S,"isBlendAdditive",tolua_particle_wyParticleSystem_isBlendAdditive00);
   tolua_function(tolua_S,"setParticlePositionVariance",tolua_particle_wyParticleSystem_setParticlePositionVariance00);
   tolua_function(tolua_S,"setDirectionAngleVariance",tolua_particle_wyParticleSystem_setDirectionAngleVariance00);
   tolua_function(tolua_S,"setStartSizeVariance",tolua_particle_wyParticleSystem_setStartSizeVariance00);
   tolua_function(tolua_S,"setEndSizeVariance",tolua_particle_wyParticleSystem_setEndSizeVariance00);
   tolua_function(tolua_S,"setLifeVariance",tolua_particle_wyParticleSystem_setLifeVariance00);
   tolua_function(tolua_S,"setStartColorVariance",tolua_particle_wyParticleSystem_setStartColorVariance00);
   tolua_function(tolua_S,"setEndColorVariance",tolua_particle_wyParticleSystem_setEndColorVariance00);
   tolua_function(tolua_S,"setStartSpinVariance",tolua_particle_wyParticleSystem_setStartSpinVariance00);
   tolua_function(tolua_S,"setEndSpinVariance",tolua_particle_wyParticleSystem_setEndSpinVariance00);
   tolua_function(tolua_S,"setSpeedVariance",tolua_particle_wyParticleSystem_setSpeedVariance00);
   tolua_function(tolua_S,"setParticleGravity",tolua_particle_wyParticleSystem_setParticleGravity00);
   tolua_function(tolua_S,"setTangentialAccelerationVariance",tolua_particle_wyParticleSystem_setTangentialAccelerationVariance00);
   tolua_function(tolua_S,"setRadialAccelerationVariance",tolua_particle_wyParticleSystem_setRadialAccelerationVariance00);
   tolua_function(tolua_S,"setStartRadiusVariance",tolua_particle_wyParticleSystem_setStartRadiusVariance00);
   tolua_function(tolua_S,"setEndRadiusVariance",tolua_particle_wyParticleSystem_setEndRadiusVariance00);
   tolua_function(tolua_S,"setRotationVariance",tolua_particle_wyParticleSystem_setRotationVariance00);
   tolua_function(tolua_S,"getParticleGravity",tolua_particle_wyParticleSystem_getParticleGravity00);
   tolua_function(tolua_S,"setDuration",tolua_particle_wyParticleSystem_setDuration00);
   tolua_function(tolua_S,"getDuration",tolua_particle_wyParticleSystem_getDuration00);
   tolua_function(tolua_S,"getCenterOfGravity",tolua_particle_wyParticleSystem_getCenterOfGravity00);
   tolua_function(tolua_S,"isAutoRemoveOnFinish",tolua_particle_wyParticleSystem_isAutoRemoveOnFinish00);
   tolua_function(tolua_S,"setAutoRemoveOnFinish",tolua_particle_wyParticleSystem_setAutoRemoveOnFinish00);
   tolua_function(tolua_S,"getEmissionRate",tolua_particle_wyParticleSystem_getEmissionRate00);
   tolua_function(tolua_S,"setEmissionRate",tolua_particle_wyParticleSystem_setEmissionRate00);
   tolua_function(tolua_S,"getLife",tolua_particle_wyParticleSystem_getLife00);
   tolua_function(tolua_S,"getEmitterMode",tolua_particle_wyParticleSystem_getEmitterMode00);
   tolua_function(tolua_S,"setEmitterMode",tolua_particle_wyParticleSystem_setEmitterMode00);
   tolua_function(tolua_S,"getPositionType",tolua_particle_wyParticleSystem_getPositionType00);
   tolua_function(tolua_S,"setPositionType",tolua_particle_wyParticleSystem_setPositionType00);
   tolua_function(tolua_S,"getParticleCount",tolua_particle_wyParticleSystem_getParticleCount00);
   tolua_function(tolua_S,"getMaxParticles",tolua_particle_wyParticleSystem_getMaxParticles00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyPointParticleSystem","wyPointParticleSystem","wyParticleSystem",tolua_collect_wyPointParticleSystem);
  #else
  tolua_cclass(tolua_S,"wyPointParticleSystem","wyPointParticleSystem","wyParticleSystem",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyPointParticleSystem");
   tolua_function(tolua_S,"new",tolua_particle_wyPointParticleSystem_new00);
   tolua_function(tolua_S,"new_local",tolua_particle_wyPointParticleSystem_new00_local);
   tolua_function(tolua_S,".call",tolua_particle_wyPointParticleSystem_new00_local);
   tolua_function(tolua_S,"delete",tolua_particle_wyPointParticleSystem_delete00);
   tolua_function(tolua_S,"draw",tolua_particle_wyPointParticleSystem_draw00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"wyQuadParticleSystem","wyQuadParticleSystem","wyParticleSystem",tolua_collect_wyQuadParticleSystem);
  #else
  tolua_cclass(tolua_S,"wyQuadParticleSystem","wyQuadParticleSystem","wyParticleSystem",NULL);
  #endif
  tolua_beginmodule(tolua_S,"wyQuadParticleSystem");
   tolua_function(tolua_S,"new",tolua_particle_wyQuadParticleSystem_new00);
   tolua_function(tolua_S,"new_local",tolua_particle_wyQuadParticleSystem_new00_local);
   tolua_function(tolua_S,".call",tolua_particle_wyQuadParticleSystem_new00_local);
   tolua_function(tolua_S,"delete",tolua_particle_wyQuadParticleSystem_delete00);
   tolua_function(tolua_S,"draw",tolua_particle_wyQuadParticleSystem_draw00);
   tolua_function(tolua_S,"setTexture",tolua_particle_wyQuadParticleSystem_setTexture00);
   tolua_function(tolua_S,"setTexture",tolua_particle_wyQuadParticleSystem_setTexture01);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_particle (lua_State* tolua_S) {
 return tolua_particle_open(tolua_S);
};
#endif

