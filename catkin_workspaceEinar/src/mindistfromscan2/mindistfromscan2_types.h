//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: mindistfromscan2_types.h
//
// Code generated for Simulink model 'mindistfromscan2'.
//
// Model version                  : 1.109
// Simulink Coder version         : 8.9 (R2015b) 13-Aug-2015
// C/C++ source code generated on : Fri May  6 18:33:58 2016
//
// Target selection: ert.tlc
// Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_mindistfromscan2_types_h_
#define RTW_HEADER_mindistfromscan2_types_h_
#include "rtwtypes.h"
#ifndef _DEFINED_TYPEDEF_FOR_SL_Bus_mindistfromscan2_std_msgs_Float32_
#define _DEFINED_TYPEDEF_FOR_SL_Bus_mindistfromscan2_std_msgs_Float32_

typedef struct {
  real32_T Data;
} SL_Bus_mindistfromscan2_std_msgs_Float32;

#endif

#ifndef _DEFINED_TYPEDEF_FOR_SL_Bus_mindistfromscan2_std_msgs_Float64_
#define _DEFINED_TYPEDEF_FOR_SL_Bus_mindistfromscan2_std_msgs_Float64_

typedef struct {
  real_T Data;
} SL_Bus_mindistfromscan2_std_msgs_Float64;

#endif

#ifndef _DEFINED_TYPEDEF_FOR_SL_Bus_ROSVariableLengthArrayInfo_
#define _DEFINED_TYPEDEF_FOR_SL_Bus_ROSVariableLengthArrayInfo_

typedef struct {
  uint32_T CurrentLength;
  uint32_T ReceivedLength;
} SL_Bus_ROSVariableLengthArrayInfo;

#endif

#ifndef _DEFINED_TYPEDEF_FOR_SL_Bus_mindistfromscan2_ros_time_Time_
#define _DEFINED_TYPEDEF_FOR_SL_Bus_mindistfromscan2_ros_time_Time_

typedef struct {
  int32_T Sec;
  int32_T Nsec;
} SL_Bus_mindistfromscan2_ros_time_Time;

#endif

#ifndef _DEFINED_TYPEDEF_FOR_SL_Bus_mindistfromscan2_std_msgs_Header_
#define _DEFINED_TYPEDEF_FOR_SL_Bus_mindistfromscan2_std_msgs_Header_

typedef struct {
  uint32_T Seq;
  uint8_T FrameId[128];
  SL_Bus_ROSVariableLengthArrayInfo FrameId_SL_Info;
  SL_Bus_mindistfromscan2_ros_time_Time Stamp;
} SL_Bus_mindistfromscan2_std_msgs_Header;

#endif

#ifndef _DEFINED_TYPEDEF_FOR_SL_Bus_mindistfromscan2_sensor_msgs_LaserScan_
#define _DEFINED_TYPEDEF_FOR_SL_Bus_mindistfromscan2_sensor_msgs_LaserScan_

typedef struct {
  real32_T AngleMin;
  real32_T AngleMax;
  real32_T AngleIncrement;
  real32_T TimeIncrement;
  real32_T ScanTime;
  real32_T RangeMin;
  real32_T RangeMax;
  real32_T Ranges[360];
  SL_Bus_ROSVariableLengthArrayInfo Ranges_SL_Info;
  real32_T Intensities[360];
  SL_Bus_ROSVariableLengthArrayInfo Intensities_SL_Info;
  SL_Bus_mindistfromscan2_std_msgs_Header Header;
} SL_Bus_mindistfromscan2_sensor_msgs_LaserScan;

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

#ifndef typedef_robotics_slros_internal_blo_j_T
#define typedef_robotics_slros_internal_blo_j_T

typedef struct tag_saG5948SFTrUFnIbVUb0TZH robotics_slros_internal_blo_j_T;

#endif                                 //typedef_robotics_slros_internal_blo_j_T

#ifndef typedef_struct_T_mindistfromscan2_T
#define typedef_struct_T_mindistfromscan2_T

typedef struct {
  char_T f0[4];
} struct_T_mindistfromscan2_T;

#endif                                 //typedef_struct_T_mindistfromscan2_T

#ifndef typedef_struct_T_mindistfromscan2_j_T
#define typedef_struct_T_mindistfromscan2_j_T

typedef struct {
  char_T f0[8];
} struct_T_mindistfromscan2_j_T;

#endif                                 //typedef_struct_T_mindistfromscan2_j_T

#ifndef typedef_struct_T_mindistfromscan2_jw_T
#define typedef_struct_T_mindistfromscan2_jw_T

typedef struct {
  char_T f0[7];
} struct_T_mindistfromscan2_jw_T;

#endif                                 //typedef_struct_T_mindistfromscan2_jw_T

#ifndef typedef_struct_T_mindistfromscan2_jw1_T
#define typedef_struct_T_mindistfromscan2_jw1_T

typedef struct {
  char_T f0[8];
  char_T f1[7];
  char_T f2[6];
} struct_T_mindistfromscan2_jw1_T;

#endif                                 //typedef_struct_T_mindistfromscan2_jw1_T

// Parameters (auto storage)
typedef struct P_mindistfromscan2_T_ P_mindistfromscan2_T;

// Forward declaration for rtModel
typedef struct tag_RTM_mindistfromscan2_T RT_MODEL_mindistfromscan2_T;

#endif                                 // RTW_HEADER_mindistfromscan2_types_h_

//
// File trailer for generated code.
//
// [EOF]
//
