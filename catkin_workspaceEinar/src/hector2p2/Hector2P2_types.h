//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: Hector2P2_types.h
//
// Code generated for Simulink model 'Hector2P2'.
//
// Model version                  : 1.66
// Simulink Coder version         : 8.9 (R2015b) 13-Aug-2015
// C/C++ source code generated on : Tue Apr 19 10:15:10 2016
//
// Target selection: ert.tlc
// Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_Hector2P2_types_h_
#define RTW_HEADER_Hector2P2_types_h_
#include "rtwtypes.h"
#ifndef _DEFINED_TYPEDEF_FOR_SL_Bus_Hector2P2_geometry_msgs_Point_
#define _DEFINED_TYPEDEF_FOR_SL_Bus_Hector2P2_geometry_msgs_Point_

typedef struct {
  real_T X;
  real_T Y;
  real_T Z;
} SL_Bus_Hector2P2_geometry_msgs_Point;

#endif

#ifndef _DEFINED_TYPEDEF_FOR_SL_Bus_Hector2P2_geometry_msgs_Vector3_
#define _DEFINED_TYPEDEF_FOR_SL_Bus_Hector2P2_geometry_msgs_Vector3_

typedef struct {
  real_T X;
  real_T Y;
  real_T Z;
} SL_Bus_Hector2P2_geometry_msgs_Vector3;

#endif

#ifndef _DEFINED_TYPEDEF_FOR_SL_Bus_ROSVariableLengthArrayInfo_
#define _DEFINED_TYPEDEF_FOR_SL_Bus_ROSVariableLengthArrayInfo_

typedef struct {
  uint32_T CurrentLength;
  uint32_T ReceivedLength;
} SL_Bus_ROSVariableLengthArrayInfo;

#endif

#ifndef _DEFINED_TYPEDEF_FOR_SL_Bus_Hector2P2_ros_time_Time_
#define _DEFINED_TYPEDEF_FOR_SL_Bus_Hector2P2_ros_time_Time_

typedef struct {
  int32_T Sec;
  int32_T Nsec;
} SL_Bus_Hector2P2_ros_time_Time;

#endif

#ifndef _DEFINED_TYPEDEF_FOR_SL_Bus_Hector2P2_std_msgs_Header_
#define _DEFINED_TYPEDEF_FOR_SL_Bus_Hector2P2_std_msgs_Header_

typedef struct {
  uint32_T Seq;
  uint8_T FrameId[128];
  SL_Bus_ROSVariableLengthArrayInfo FrameId_SL_Info;
  SL_Bus_Hector2P2_ros_time_Time Stamp;
} SL_Bus_Hector2P2_std_msgs_Header;

#endif

#ifndef _DEFINED_TYPEDEF_FOR_SL_Bus_Hector2P2_geometry_msgs_Quaternion_
#define _DEFINED_TYPEDEF_FOR_SL_Bus_Hector2P2_geometry_msgs_Quaternion_

typedef struct {
  real_T X;
  real_T Y;
  real_T Z;
  real_T W;
} SL_Bus_Hector2P2_geometry_msgs_Quaternion;

#endif

#ifndef _DEFINED_TYPEDEF_FOR_SL_Bus_Hector2P2_geometry_msgs_Pose_
#define _DEFINED_TYPEDEF_FOR_SL_Bus_Hector2P2_geometry_msgs_Pose_

typedef struct {
  SL_Bus_Hector2P2_geometry_msgs_Point Position;
  SL_Bus_Hector2P2_geometry_msgs_Quaternion Orientation;
} SL_Bus_Hector2P2_geometry_msgs_Pose;

#endif

#ifndef _DEFINED_TYPEDEF_FOR_SL_Bus_Hector2P2_geometry_msgs_PoseWithCovariance_
#define _DEFINED_TYPEDEF_FOR_SL_Bus_Hector2P2_geometry_msgs_PoseWithCovariance_

typedef struct {
  real_T Covariance[36];
  SL_Bus_Hector2P2_geometry_msgs_Pose Pose;
} SL_Bus_Hector2P2_geometry_msgs_PoseWithCovariance;

#endif

#ifndef _DEFINED_TYPEDEF_FOR_SL_Bus_Hector2P2_geometry_msgs_PoseWithCovarianceStamped_
#define _DEFINED_TYPEDEF_FOR_SL_Bus_Hector2P2_geometry_msgs_PoseWithCovarianceStamped_

typedef struct {
  SL_Bus_Hector2P2_std_msgs_Header Header;
  SL_Bus_Hector2P2_geometry_msgs_PoseWithCovariance Pose;
} SL_Bus_Hector2P2_geometry_msgs_PoseWithCovarianceStamped;

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

#ifndef typedef_struct_T_Hector2P2_T
#define typedef_struct_T_Hector2P2_T

typedef struct {
  char_T f0[4];
} struct_T_Hector2P2_T;

#endif                                 //typedef_struct_T_Hector2P2_T

#ifndef typedef_struct_T_Hector2P2_e_T
#define typedef_struct_T_Hector2P2_e_T

typedef struct {
  char_T f0[8];
} struct_T_Hector2P2_e_T;

#endif                                 //typedef_struct_T_Hector2P2_e_T

#ifndef typedef_struct_T_Hector2P2_eo_T
#define typedef_struct_T_Hector2P2_eo_T

typedef struct {
  char_T f0[7];
} struct_T_Hector2P2_eo_T;

#endif                                 //typedef_struct_T_Hector2P2_eo_T

#ifndef typedef_struct_T_Hector2P2_eos_T
#define typedef_struct_T_Hector2P2_eos_T

typedef struct {
  char_T f0[8];
  char_T f1[7];
  char_T f2[6];
} struct_T_Hector2P2_eos_T;

#endif                                 //typedef_struct_T_Hector2P2_eos_T

// Parameters (auto storage)
typedef struct P_Hector2P2_T_ P_Hector2P2_T;

// Forward declaration for rtModel
typedef struct tag_RTM_Hector2P2_T RT_MODEL_Hector2P2_T;

#endif                                 // RTW_HEADER_Hector2P2_types_h_

//
// File trailer for generated code.
//
// [EOF]
//
