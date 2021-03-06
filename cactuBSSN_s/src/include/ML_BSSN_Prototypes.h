/*@@
   @header  ML_BSSN_Prototypes.h
   @author  Automatically generated by CreateFunctionBindings.pl
   @desc
            Prototypes for overloaded functions used by this thorn
   @enddesc
  @@*/


#ifndef _ML_BSSN_PROTOTYPES_H_
#define _ML_BSSN_PROTOTYPES_H_  1

#ifdef CCODE
#ifdef __cplusplus
extern "C" {
#endif

CCTK_INT Boundary_SelectGroupForBC(const CCTK_POINTER_TO_CONST GH ,
 const CCTK_INT faces ,
 const CCTK_INT boundary_width ,
 const CCTK_INT table_handle ,
 CCTK_STRING group_name, CCTK_STRING bc_name);

CCTK_INT Boundary_SelectVarForBC(const CCTK_POINTER_TO_CONST GH ,
 const CCTK_INT faces ,
 const CCTK_INT boundary_width ,
 const CCTK_INT table_handle ,
 CCTK_STRING var_name, CCTK_STRING bc_name);

void Diff_coeff(const CCTK_POINTER_TO_CONST cctkGH ,
 const CCTK_INT dir ,
 const CCTK_INT nsize ,
 CCTK_INT* imin ,
 CCTK_INT* imax ,
 CCTK_REAL* q ,
 const CCTK_INT table_handle);

CCTK_INT MoLRegisterEvolved(const CCTK_INT EvolvedIndex ,
 const CCTK_INT RHSIndex);

CCTK_INT MultiPatch_GetMap(const CCTK_POINTER_TO_CONST cctkGH);

#ifdef __cplusplus
}
#endif
#endif /* CCODE */

#ifdef FCODE
#ifdef F90CODE
#define DECLARE_ML_BSSN_FUNCTIONS _DECLARE_CCTK_FUNCTIONS \
  interface &&\
     CCTK_INT function Boundary_SelectGroupForBC (GH, faces, boundary_width, table_handle, group_name, bc_name) &&\
       implicit none &&\
       CCTK_POINTER_TO_CONST GH &&\
       CCTK_INT faces &&\
       CCTK_INT boundary_width &&\
       CCTK_INT table_handle &&\
       character(*) group_name &&\
       character(*) bc_name &&\
     end function Boundary_SelectGroupForBC &&\
  end interface &&\
  interface &&\
     CCTK_INT function Boundary_SelectVarForBC (GH, faces, boundary_width, table_handle, var_name, bc_name) &&\
       implicit none &&\
       CCTK_POINTER_TO_CONST GH &&\
       CCTK_INT faces &&\
       CCTK_INT boundary_width &&\
       CCTK_INT table_handle &&\
       character(*) var_name &&\
       character(*) bc_name &&\
     end function Boundary_SelectVarForBC &&\
  end interface &&\
  interface &&\
     subroutine Diff_coeff (cctkGH, dir, nsize, imin, imax, q, table_handle) &&\
       implicit none &&\
       CCTK_POINTER_TO_CONST cctkGH &&\
       CCTK_INT dir &&\
       CCTK_INT nsize &&\
       CCTK_INT imin(*) &&\
       CCTK_INT imax(*) &&\
       CCTK_REAL q(*) &&\
       CCTK_INT table_handle &&\
     end subroutine Diff_coeff &&\
  end interface &&\
  interface &&\
     CCTK_INT function MoLRegisterEvolved (EvolvedIndex, RHSIndex) &&\
       implicit none &&\
       CCTK_INT EvolvedIndex &&\
       CCTK_INT RHSIndex &&\
     end function MoLRegisterEvolved &&\
  end interface &&\
  interface &&\
     CCTK_INT function MultiPatch_GetMap (cctkGH) &&\
       implicit none &&\
       CCTK_POINTER_TO_CONST cctkGH &&\
     end function MultiPatch_GetMap &&\
  end interface &&\

#else /* ! F90CODE */

#define DECLARE_ML_BSSN_FUNCTIONS _DECLARE_CCTK_FUNCTIONS \
  external Boundary_SelectGroupForBC &&\
  CCTK_INT Boundary_SelectGroupForBC &&\
  external Boundary_SelectVarForBC &&\
  CCTK_INT Boundary_SelectVarForBC &&\
  external Diff_coeff &&\
  external MoLRegisterEvolved &&\
  CCTK_INT MoLRegisterEvolved &&\
  external MultiPatch_GetMap &&\
  CCTK_INT MultiPatch_GetMap &&\

#endif /* ! F90CODE */
#endif /* FCODE */

#endif

