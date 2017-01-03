//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: etasetget256Discretized2_types.h
//
// Code generated for Simulink model 'etasetget256Discretized2'.
//
// Model version                  : 1.123
// Simulink Coder version         : 8.9 (R2015b) 13-Aug-2015
// C/C++ source code generated on : Sun May 15 17:08:03 2016
//
// Target selection: ert.tlc
// Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_etasetget256Discretized2_types_h_
#define RTW_HEADER_etasetget256Discretized2_types_h_
#include "rtwtypes.h"
#ifndef _DEFINED_TYPEDEF_FOR_SL_Bus_etasetget256Discretized2_geometry_msgs_Point_
#define _DEFINED_TYPEDEF_FOR_SL_Bus_etasetget256Discretized2_geometry_msgs_Point_

typedef struct {
  real_T X;
  real_T Y;
  real_T Z;
} SL_Bus_etasetget256Discretized2_geometry_msgs_Point;

#endif

#ifndef _DEFINED_TYPEDEF_FOR_SL_Bus_etasetget256Discretized2_geometry_msgs_Vector3_
#define _DEFINED_TYPEDEF_FOR_SL_Bus_etasetget256Discretized2_geometry_msgs_Vector3_

typedef struct {
  real_T X;
  real_T Y;
  real_T Z;
} SL_Bus_etasetget256Discretized2_geometry_msgs_Vector3;

#endif

#ifndef _DEFINED_TYPEDEF_FOR_SL_Bus_ROSVariableLengthArrayInfo_
#define _DEFINED_TYPEDEF_FOR_SL_Bus_ROSVariableLengthArrayInfo_

typedef struct {
  uint32_T CurrentLength;
  uint32_T ReceivedLength;
} SL_Bus_ROSVariableLengthArrayInfo;

#endif

#ifndef _DEFINED_TYPEDEF_FOR_SL_Bus_etasetget256Discretized2_MultiArrayDimension_ni5sxo_
#define _DEFINED_TYPEDEF_FOR_SL_Bus_etasetget256Discretized2_MultiArrayDimension_ni5sxo_

typedef struct {
  uint8_T Label[256];
  SL_Bus_ROSVariableLengthArrayInfo Label_SL_Info;
  uint32_T Size;
  uint32_T Stride;
} SL_Bus_etasetget256Discretized2_MultiArrayDimension_ni5sxo;

#endif

#ifndef _DEFINED_TYPEDEF_FOR_SL_Bus_etasetget256Discretized2_std_msgs_MultiArrayLayout_
#define _DEFINED_TYPEDEF_FOR_SL_Bus_etasetget256Discretized2_std_msgs_MultiArrayLayout_

typedef struct {
  uint32_T DataOffset;
  SL_Bus_etasetget256Discretized2_MultiArrayDimension_ni5sxo Dim[16];
  SL_Bus_ROSVariableLengthArrayInfo Dim_SL_Info;
} SL_Bus_etasetget256Discretized2_std_msgs_MultiArrayLayout;

#endif

#ifndef _DEFINED_TYPEDEF_FOR_SL_Bus_etasetget256Discretized2_std_msgs_Float32MultiArray_
#define _DEFINED_TYPEDEF_FOR_SL_Bus_etasetget256Discretized2_std_msgs_Float32MultiArray_

typedef struct {
  real32_T Data[256];
  SL_Bus_ROSVariableLengthArrayInfo Data_SL_Info;
  SL_Bus_etasetget256Discretized2_std_msgs_MultiArrayLayout Layout;
} SL_Bus_etasetget256Discretized2_std_msgs_Float32MultiArray;

#endif

#ifndef _DEFINED_TYPEDEF_FOR_SL_Bus_etasetget256Discretized2_std_msgs_Float64_
#define _DEFINED_TYPEDEF_FOR_SL_Bus_etasetget256Discretized2_std_msgs_Float64_

typedef struct {
  real_T Data;
} SL_Bus_etasetget256Discretized2_std_msgs_Float64;

#endif

#ifndef struct_tag_saG5948SFTrUFnIbVUb0TZH
#define struct_tag_saG5948SFTrUFnIbVUb0TZH

struct tag_saG5948SFTrUFnIbVUb0TZH
{
  int32_T isInitialized;
};

#endif                                 //struct_tag_saG5948SFTrUFnIbVUb0TZH

#ifndef typedef_robotics_slros_internal_block_T
#define typedef_robotics_slros_internal_block_T

typedef struct tag_saG5948SFTrUFnIbVUb0TZH robotics_slros_internal_block_T;

#endif                                 //typedef_robotics_slros_internal_block_T

#ifndef struct_tag_saG5948SFTrUFnIbVUb0TZH
#define struct_tag_saG5948SFTrUFnIbVUb0TZH

struct tag_saG5948SFTrUFnIbVUb0TZH
{
  int32_T isInitialized;
};

#endif                                 //struct_tag_saG5948SFTrUFnIbVUb0TZH

#ifndef typedef_robotics_slros_internal_blo_p_T
#define typedef_robotics_slros_internal_blo_p_T

typedef struct tag_saG5948SFTrUFnIbVUb0TZH robotics_slros_internal_blo_p_T;

#endif                                 //typedef_robotics_slros_internal_blo_p_T

#ifndef typedef_struct_T_etasetget256Discreti_T
#define typedef_struct_T_etasetget256Discreti_T

typedef struct {
  char_T f0[4];
} struct_T_etasetget256Discreti_T;

#endif                                 //typedef_struct_T_etasetget256Discreti_T

#ifndef typedef_struct_T_etasetget256Discre_p_T
#define typedef_struct_T_etasetget256Discre_p_T

typedef struct {
  char_T f0[8];
} struct_T_etasetget256Discre_p_T;

#endif                                 //typedef_struct_T_etasetget256Discre_p_T

#ifndef typedef_struct_T_etasetget256Discr_p4_T
#define typedef_struct_T_etasetget256Discr_p4_T

typedef struct {
  char_T f0[7];
} struct_T_etasetget256Discr_p4_T;

#endif                                 //typedef_struct_T_etasetget256Discr_p4_T

#ifndef typedef_struct_T_etasetget256Disc_p41_T
#define typedef_struct_T_etasetget256Disc_p41_T

typedef struct {
  char_T f0[8];
  char_T f1[7];
  char_T f2[6];
} struct_T_etasetget256Disc_p41_T;

#endif                                 //typedef_struct_T_etasetget256Disc_p41_T

// Parameters (auto storage)
typedef struct P_etasetget256Discretized2_T_ P_etasetget256Discretized2_T;

// Forward declaration for rtModel
typedef struct tag_RTM_etasetget256Discretiz_T RT_MODEL_etasetget256Discreti_T;

#endif                                 // RTW_HEADER_etasetget256Discretized2_types_h_ 

//
// File trailer for generated code.
//
// [EOF]
//
