//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: Q2PAll_types.h
//
// Code generated for Simulink model 'Q2PAll'.
//
// Model version                  : 1.66
// Simulink Coder version         : 8.9 (R2015b) 13-Aug-2015
// C/C++ source code generated on : Wed Apr 20 14:43:07 2016
//
// Target selection: ert.tlc
// Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_Q2PAll_types_h_
#define RTW_HEADER_Q2PAll_types_h_
#include "rtwtypes.h"
#ifndef _DEFINED_TYPEDEF_FOR_SL_Bus_ROSVariableLengthArrayInfo_
#define _DEFINED_TYPEDEF_FOR_SL_Bus_ROSVariableLengthArrayInfo_

typedef struct {
  uint32_T CurrentLength;
  uint32_T ReceivedLength;
} SL_Bus_ROSVariableLengthArrayInfo;

#endif

#ifndef _DEFINED_TYPEDEF_FOR_SL_Bus_Q2PAll_ros_time_Time_
#define _DEFINED_TYPEDEF_FOR_SL_Bus_Q2PAll_ros_time_Time_

typedef struct {
  int32_T Sec;
  int32_T Nsec;
} SL_Bus_Q2PAll_ros_time_Time;

#endif

#ifndef _DEFINED_TYPEDEF_FOR_SL_Bus_Q2PAll_std_msgs_Header_
#define _DEFINED_TYPEDEF_FOR_SL_Bus_Q2PAll_std_msgs_Header_

typedef struct {
  uint32_T Seq;
  uint8_T FrameId[128];
  SL_Bus_ROSVariableLengthArrayInfo FrameId_SL_Info;
  SL_Bus_Q2PAll_ros_time_Time Stamp;
} SL_Bus_Q2PAll_std_msgs_Header;

#endif

#ifndef _DEFINED_TYPEDEF_FOR_SL_Bus_Q2PAll_geometry_msgs_Point_
#define _DEFINED_TYPEDEF_FOR_SL_Bus_Q2PAll_geometry_msgs_Point_

typedef struct {
  real_T X;
  real_T Y;
  real_T Z;
} SL_Bus_Q2PAll_geometry_msgs_Point;

#endif

#ifndef _DEFINED_TYPEDEF_FOR_SL_Bus_Q2PAll_geometry_msgs_Quaternion_
#define _DEFINED_TYPEDEF_FOR_SL_Bus_Q2PAll_geometry_msgs_Quaternion_

typedef struct {
  real_T X;
  real_T Y;
  real_T Z;
  real_T W;
} SL_Bus_Q2PAll_geometry_msgs_Quaternion;

#endif

#ifndef _DEFINED_TYPEDEF_FOR_SL_Bus_Q2PAll_qualisys_Marker_
#define _DEFINED_TYPEDEF_FOR_SL_Bus_Q2PAll_qualisys_Marker_

typedef struct {
  uint8_T Name[128];
  SL_Bus_ROSVariableLengthArrayInfo Name_SL_Info;
  uint8_T SubjectName[128];
  SL_Bus_ROSVariableLengthArrayInfo SubjectName_SL_Info;
  boolean_T Occluded;
  SL_Bus_Q2PAll_geometry_msgs_Point Position;
} SL_Bus_Q2PAll_qualisys_Marker;

#endif

#ifndef _DEFINED_TYPEDEF_FOR_SL_Bus_Q2PAll_qualisys_Subject_
#define _DEFINED_TYPEDEF_FOR_SL_Bus_Q2PAll_qualisys_Subject_

typedef struct {
  uint8_T Name[128];
  SL_Bus_ROSVariableLengthArrayInfo Name_SL_Info;
  boolean_T Occluded;
  SL_Bus_Q2PAll_std_msgs_Header Header;
  SL_Bus_Q2PAll_geometry_msgs_Point Position;
  SL_Bus_Q2PAll_geometry_msgs_Quaternion Orientation;
  SL_Bus_Q2PAll_qualisys_Marker Markers[16];
  SL_Bus_ROSVariableLengthArrayInfo Markers_SL_Info;
} SL_Bus_Q2PAll_qualisys_Subject;

#endif

#ifndef _DEFINED_TYPEDEF_FOR_SL_Bus_Q2PAll_geometry_msgs_Vector3_
#define _DEFINED_TYPEDEF_FOR_SL_Bus_Q2PAll_geometry_msgs_Vector3_

typedef struct {
  real_T X;
  real_T Y;
  real_T Z;
} SL_Bus_Q2PAll_geometry_msgs_Vector3;

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

#ifndef typedef_robotics_slros_internal_blo_e_T
#define typedef_robotics_slros_internal_blo_e_T

typedef struct tag_saG5948SFTrUFnIbVUb0TZH robotics_slros_internal_blo_e_T;

#endif                                 //typedef_robotics_slros_internal_blo_e_T

#ifndef typedef_struct_T_Q2PAll_T
#define typedef_struct_T_Q2PAll_T

typedef struct {
  char_T f0[4];
} struct_T_Q2PAll_T;

#endif                                 //typedef_struct_T_Q2PAll_T

#ifndef typedef_struct_T_Q2PAll_e_T
#define typedef_struct_T_Q2PAll_e_T

typedef struct {
  char_T f0[8];
} struct_T_Q2PAll_e_T;

#endif                                 //typedef_struct_T_Q2PAll_e_T

#ifndef typedef_struct_T_Q2PAll_el_T
#define typedef_struct_T_Q2PAll_el_T

typedef struct {
  char_T f0[7];
} struct_T_Q2PAll_el_T;

#endif                                 //typedef_struct_T_Q2PAll_el_T

#ifndef typedef_struct_T_Q2PAll_el0_T
#define typedef_struct_T_Q2PAll_el0_T

typedef struct {
  char_T f0[8];
  char_T f1[7];
  char_T f2[6];
} struct_T_Q2PAll_el0_T;

#endif                                 //typedef_struct_T_Q2PAll_el0_T

// Parameters (auto storage)
typedef struct P_Q2PAll_T_ P_Q2PAll_T;

// Forward declaration for rtModel
typedef struct tag_RTM_Q2PAll_T RT_MODEL_Q2PAll_T;

#endif                                 // RTW_HEADER_Q2PAll_types_h_

//
// File trailer for generated code.
//
// [EOF]
//
