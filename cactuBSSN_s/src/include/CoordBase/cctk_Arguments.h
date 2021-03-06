#ifndef CCTK_ARGUMENTS_H_
#define CCTK_ARGUMENTS_H_ 1
/*@@
   @header  cctk_Arguments.h
   @author  Automatically generated by GridFuncStuff.pl
   @desc
            Defines the CCTK_ARGUMENTS macro for all thorns
   @enddesc
 @@*/


#include "CoordBase_Arguments.h"
/* get the CCTK datatype definitions */
#include "cctk_Types.h"

#ifdef CCODE
#include "cGH.h"
#include "cctki_GroupsOnGH.h"
#define PASS_GROUPSIZE(group, dir)  CCTKGROUPNUM_##group >= 0 ? \
                                    CCTK_ArrayGroupSizeI(GH, dir, CCTKGROUPNUM_##group) : &_cctk_zero

#define PASS_GROUPLEN(thorn, group) CCTKGROUPNUM_##group >= 0 ? \
                                    CCTKi_GroupLengthAsPointer(#thorn "::" #group) : &_cctk_zero

#define PASS_REFERENCE(var, level)  CCTKARGNUM_##var >= 0 ? \
                                    GH->data[CCTKARGNUM_##var][level] : 0

#define CCTK_ARGUMENTS COORDBASE_CARGUMENTS
#define _CCTK_ARGUMENTS _CCTK_CARGUMENTS
#define DECLARE_CCTK_ARGUMENTS DECLARE_COORDBASE_CARGUMENTS
#endif

#ifdef FCODE
#define CCTK_ARGUMENTS COORDBASE_FARGUMENTS
#define _CCTK_ARGUMENTS _CCTK_FARGUMENTS
#define DECLARE_CCTK_ARGUMENTS DECLARE_COORDBASE_FARGUMENTS
#endif

#define CCTK_FARGUMENTS COORDBASE_FARGUMENTS
#define DECLARE_CCTK_FARGUMENTS DECLARE_COORDBASE_FARGUMENTS
#define CCTK_CARGUMENTS COORDBASE_CARGUMENTS
#define DECLARE_CCTK_CARGUMENTS DECLARE_COORDBASE_CARGUMENTS
#endif

