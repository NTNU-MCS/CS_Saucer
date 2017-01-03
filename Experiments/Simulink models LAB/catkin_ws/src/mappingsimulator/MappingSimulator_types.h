//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: MappingSimulator_types.h
//
// Code generated for Simulink model 'MappingSimulator'.
//
// Model version                  : 1.130
// Simulink Coder version         : 8.9 (R2015b) 13-Aug-2015
// C/C++ source code generated on : Wed Jun 22 14:54:41 2016
//
// Target selection: ert.tlc
// Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_MappingSimulator_types_h_
#define RTW_HEADER_MappingSimulator_types_h_
#include "rtwtypes.h"
#ifndef _DEFINED_TYPEDEF_FOR_SL_Bus_ROSVariableLengthArrayInfo_
#define _DEFINED_TYPEDEF_FOR_SL_Bus_ROSVariableLengthArrayInfo_

typedef struct {
  uint32_T CurrentLength;
  uint32_T ReceivedLength;
} SL_Bus_ROSVariableLengthArrayInfo;

#endif

#ifndef _DEFINED_TYPEDEF_FOR_SL_Bus_MappingSimulator_ros_time_Time_
#define _DEFINED_TYPEDEF_FOR_SL_Bus_MappingSimulator_ros_time_Time_

typedef struct {
  int32_T Sec;
  int32_T Nsec;
} SL_Bus_MappingSimulator_ros_time_Time;

#endif

#ifndef _DEFINED_TYPEDEF_FOR_SL_Bus_MappingSimulator_std_msgs_Header_
#define _DEFINED_TYPEDEF_FOR_SL_Bus_MappingSimulator_std_msgs_Header_

typedef struct {
  uint32_T Seq;
  uint8_T FrameId[128];
  SL_Bus_ROSVariableLengthArrayInfo FrameId_SL_Info;
  SL_Bus_MappingSimulator_ros_time_Time Stamp;
} SL_Bus_MappingSimulator_std_msgs_Header;

#endif

#ifndef _DEFINED_TYPEDEF_FOR_SL_Bus_MappingSimulator_geometry_msgs_Point_
#define _DEFINED_TYPEDEF_FOR_SL_Bus_MappingSimulator_geometry_msgs_Point_

typedef struct {
  real_T X;
  real_T Y;
  real_T Z;
} SL_Bus_MappingSimulator_geometry_msgs_Point;

#endif

#ifndef _DEFINED_TYPEDEF_FOR_SL_Bus_MappingSimulator_geometry_msgs_Quaternion_
#define _DEFINED_TYPEDEF_FOR_SL_Bus_MappingSimulator_geometry_msgs_Quaternion_

typedef struct {
  real_T X;
  real_T Y;
  real_T Z;
  real_T W;
} SL_Bus_MappingSimulator_geometry_msgs_Quaternion;

#endif

#ifndef _DEFINED_TYPEDEF_FOR_SL_Bus_MappingSimulator_geometry_msgs_Pose_
#define _DEFINED_TYPEDEF_FOR_SL_Bus_MappingSimulator_geometry_msgs_Pose_

typedef struct {
  SL_Bus_MappingSimulator_geometry_msgs_Point Position;
  SL_Bus_MappingSimulator_geometry_msgs_Quaternion Orientation;
} SL_Bus_MappingSimulator_geometry_msgs_Pose;

#endif

#ifndef _DEFINED_TYPEDEF_FOR_SL_Bus_MappingSimulator_nav_msgs_MapMetaData_
#define _DEFINED_TYPEDEF_FOR_SL_Bus_MappingSimulator_nav_msgs_MapMetaData_

typedef struct {
  real32_T Resolution;
  uint32_T Width;
  uint32_T Height;
  SL_Bus_MappingSimulator_ros_time_Time MapLoadTime;
  SL_Bus_MappingSimulator_geometry_msgs_Pose Origin;
} SL_Bus_MappingSimulator_nav_msgs_MapMetaData;

#endif

#ifndef _DEFINED_TYPEDEF_FOR_SL_Bus_MappingSimulator_nav_msgs_OccupancyGrid_
#define _DEFINED_TYPEDEF_FOR_SL_Bus_MappingSimulator_nav_msgs_OccupancyGrid_

typedef struct {
  int8_T Data[65536];
  SL_Bus_ROSVariableLengthArrayInfo Data_SL_Info;
  SL_Bus_MappingSimulator_std_msgs_Header Header;
  SL_Bus_MappingSimulator_nav_msgs_MapMetaData Info;
} SL_Bus_MappingSimulator_nav_msgs_OccupancyGrid;

#endif

#ifndef _DEFINED_TYPEDEF_FOR_SL_Bus_MappingSimulator_std_msgs_Float64_
#define _DEFINED_TYPEDEF_FOR_SL_Bus_MappingSimulator_std_msgs_Float64_

typedef struct {
  real_T Data;
} SL_Bus_MappingSimulator_std_msgs_Float64;

#endif

#ifndef _DEFINED_TYPEDEF_FOR_SL_Bus_MappingSimulator_geometry_msgs_Vector3_
#define _DEFINED_TYPEDEF_FOR_SL_Bus_MappingSimulator_geometry_msgs_Vector3_

typedef struct {
  real_T X;
  real_T Y;
  real_T Z;
} SL_Bus_MappingSimulator_geometry_msgs_Vector3;

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

#ifndef typedef_robotics_slros_internal_blo_f_T
#define typedef_robotics_slros_internal_blo_f_T

typedef struct tag_saG5948SFTrUFnIbVUb0TZH robotics_slros_internal_blo_f_T;

#endif                                 //typedef_robotics_slros_internal_blo_f_T

#ifndef typedef_struct_T_MappingSimulator_T
#define typedef_struct_T_MappingSimulator_T

typedef struct {
  char_T f0[4];
} struct_T_MappingSimulator_T;

#endif                                 //typedef_struct_T_MappingSimulator_T

#ifndef typedef_struct_T_MappingSimulator_f_T
#define typedef_struct_T_MappingSimulator_f_T

typedef struct {
  char_T f0[8];
} struct_T_MappingSimulator_f_T;

#endif                                 //typedef_struct_T_MappingSimulator_f_T

#ifndef typedef_struct_T_MappingSimulator_fv_T
#define typedef_struct_T_MappingSimulator_fv_T

typedef struct {
  char_T f0[7];
} struct_T_MappingSimulator_fv_T;

#endif                                 //typedef_struct_T_MappingSimulator_fv_T

#ifndef typedef_struct_T_MappingSimulator_fvu_T
#define typedef_struct_T_MappingSimulator_fvu_T

typedef struct {
  char_T f0[8];
  char_T f1[7];
  char_T f2[6];
} struct_T_MappingSimulator_fvu_T;

#endif                                 //typedef_struct_T_MappingSimulator_fvu_T

// Parameters (auto storage)
typedef struct P_MappingSimulator_T_ P_MappingSimulator_T;

// Forward declaration for rtModel
typedef struct tag_RTM_MappingSimulator_T RT_MODEL_MappingSimulator_T;

#endif                                 // RTW_HEADER_MappingSimulator_types_h_

//
// File trailer for generated code.
//
// [EOF]
//
