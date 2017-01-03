//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: Path2SetPoint_types.h
//
// Code generated for Simulink model 'Path2SetPoint'.
//
// Model version                  : 1.127
// Simulink Coder version         : 8.9 (R2015b) 13-Aug-2015
// C/C++ source code generated on : Wed Jun 22 12:52:02 2016
//
// Target selection: ert.tlc
// Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_Path2SetPoint_types_h_
#define RTW_HEADER_Path2SetPoint_types_h_
#include "rtwtypes.h"
#ifndef _DEFINED_TYPEDEF_FOR_SL_Bus_Path2SetPoint_geometry_msgs_Vector3_
#define _DEFINED_TYPEDEF_FOR_SL_Bus_Path2SetPoint_geometry_msgs_Vector3_

typedef struct {
  real_T X;
  real_T Y;
  real_T Z;
} SL_Bus_Path2SetPoint_geometry_msgs_Vector3;

#endif

#ifndef _DEFINED_TYPEDEF_FOR_SL_Bus_ROSVariableLengthArrayInfo_
#define _DEFINED_TYPEDEF_FOR_SL_Bus_ROSVariableLengthArrayInfo_

typedef struct {
  uint32_T CurrentLength;
  uint32_T ReceivedLength;
} SL_Bus_ROSVariableLengthArrayInfo;

#endif

#ifndef _DEFINED_TYPEDEF_FOR_SL_Bus_Path2SetPoint_std_msgs_MultiArrayDimension_
#define _DEFINED_TYPEDEF_FOR_SL_Bus_Path2SetPoint_std_msgs_MultiArrayDimension_

typedef struct {
  uint8_T Label[256];
  SL_Bus_ROSVariableLengthArrayInfo Label_SL_Info;
  uint32_T Size;
  uint32_T Stride;
} SL_Bus_Path2SetPoint_std_msgs_MultiArrayDimension;

#endif

#ifndef _DEFINED_TYPEDEF_FOR_SL_Bus_Path2SetPoint_std_msgs_MultiArrayLayout_
#define _DEFINED_TYPEDEF_FOR_SL_Bus_Path2SetPoint_std_msgs_MultiArrayLayout_

typedef struct {
  uint32_T DataOffset;
  SL_Bus_Path2SetPoint_std_msgs_MultiArrayDimension Dim[16];
  SL_Bus_ROSVariableLengthArrayInfo Dim_SL_Info;
} SL_Bus_Path2SetPoint_std_msgs_MultiArrayLayout;

#endif

#ifndef _DEFINED_TYPEDEF_FOR_SL_Bus_Path2SetPoint_std_msgs_Float32MultiArray_
#define _DEFINED_TYPEDEF_FOR_SL_Bus_Path2SetPoint_std_msgs_Float32MultiArray_

typedef struct {
  real32_T Data[256];
  SL_Bus_ROSVariableLengthArrayInfo Data_SL_Info;
  SL_Bus_Path2SetPoint_std_msgs_MultiArrayLayout Layout;
} SL_Bus_Path2SetPoint_std_msgs_Float32MultiArray;

#endif

#ifndef _DEFINED_TYPEDEF_FOR_SL_Bus_Path2SetPoint_std_msgs_Float64_
#define _DEFINED_TYPEDEF_FOR_SL_Bus_Path2SetPoint_std_msgs_Float64_

typedef struct {
  real_T Data;
} SL_Bus_Path2SetPoint_std_msgs_Float64;

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

#ifndef typedef_robotics_slros_internal_blo_c_T
#define typedef_robotics_slros_internal_blo_c_T

typedef struct tag_saG5948SFTrUFnIbVUb0TZH robotics_slros_internal_blo_c_T;

#endif                                 //typedef_robotics_slros_internal_blo_c_T

#ifndef typedef_struct_T_Path2SetPoint_T
#define typedef_struct_T_Path2SetPoint_T

typedef struct {
  char_T f0[4];
} struct_T_Path2SetPoint_T;

#endif                                 //typedef_struct_T_Path2SetPoint_T

#ifndef typedef_struct_T_Path2SetPoint_c_T
#define typedef_struct_T_Path2SetPoint_c_T

typedef struct {
  char_T f0[8];
} struct_T_Path2SetPoint_c_T;

#endif                                 //typedef_struct_T_Path2SetPoint_c_T

#ifndef typedef_struct_T_Path2SetPoint_cc_T
#define typedef_struct_T_Path2SetPoint_cc_T

typedef struct {
  char_T f0[7];
} struct_T_Path2SetPoint_cc_T;

#endif                                 //typedef_struct_T_Path2SetPoint_cc_T

#ifndef typedef_struct_T_Path2SetPoint_ccm_T
#define typedef_struct_T_Path2SetPoint_ccm_T

typedef struct {
  char_T f0[8];
  char_T f1[7];
  char_T f2[6];
} struct_T_Path2SetPoint_ccm_T;

#endif                                 //typedef_struct_T_Path2SetPoint_ccm_T

// Parameters (auto storage)
typedef struct P_Path2SetPoint_T_ P_Path2SetPoint_T;

// Forward declaration for rtModel
typedef struct tag_RTM_Path2SetPoint_T RT_MODEL_Path2SetPoint_T;

#endif                                 // RTW_HEADER_Path2SetPoint_types_h_

//
// File trailer for generated code.
//
// [EOF]
//
