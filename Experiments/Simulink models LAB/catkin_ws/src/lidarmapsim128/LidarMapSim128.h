//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: LidarMapSim128.h
//
// Code generated for Simulink model 'LidarMapSim128'.
//
// Model version                  : 1.113
// Simulink Coder version         : 8.9 (R2015b) 13-Aug-2015
// C/C++ source code generated on : Sun May 15 17:26:15 2016
//
// Target selection: ert.tlc
// Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_LidarMapSim128_h_
#define RTW_HEADER_LidarMapSim128_h_
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef LidarMapSim128_COMMON_INCLUDES_
# define LidarMapSim128_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "slros_initialize.h"
#endif                                 // LidarMapSim128_COMMON_INCLUDES_

#include "LidarMapSim128_types.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

// Block signals (auto storage)
typedef struct {
  int32_T f_data[65536];
  SL_Bus_LidarMapSim128_nav_msgs_OccupancyGrid In1;// '<S11>/In1'
  SL_Bus_LidarMapSim128_nav_msgs_OccupancyGrid varargout_2;
  SL_Bus_LidarMapSim128_nav_msgs_OccupancyGrid BusAssignment1;// '<Root>/Bus Assignment1' 
  int8_T y[65536];                     // '<Root>/2Vector'
  int8_T y_o[65536];                   // '<Root>/2Matrix'
  real_T RREG[361];
  int16_T d_data[361];
  int8_T rtb_y_o_m[256];
  SL_Bus_LidarMapSim128_geometry_msgs_Vector3 In1_i;// '<S13>/In1'
  SL_Bus_LidarMapSim128_geometry_msgs_Vector3 varargout_2_c;
} B_LidarMapSim128_T;

// Block states (auto storage) for system '<Root>'
typedef struct {
  void *SourceBlock_PWORK;             // '<S12>/SourceBlock'
  void *SourceBlock_PWORK_c;           // '<S9>/SourceBlock'
  void *SinkBlock_PWORK;               // '<S8>/SinkBlock'
  void *SinkBlock_PWORK_c;             // '<S7>/SinkBlock'
  robotics_slros_internal_block_T obj; // '<S8>/SinkBlock'
  robotics_slros_internal_block_T obj_e;// '<S7>/SinkBlock'
  robotics_slros_internal_blo_c_T obj_f;// '<S12>/SourceBlock'
  robotics_slros_internal_blo_c_T obj_m;// '<S9>/SourceBlock'
  boolean_T objisempty;                // '<S12>/SourceBlock'
  boolean_T objisempty_l;              // '<S9>/SourceBlock'
  boolean_T objisempty_k;              // '<S8>/SinkBlock'
  boolean_T objisempty_kk;             // '<S7>/SinkBlock'
} DW_LidarMapSim128_T;

// Parameters (auto storage)
struct P_LidarMapSim128_T_ {
  int8_T REFMAP[65536];                // Variable: REFMAP
                                       //  Referenced by: '<Root>/Constant'

  SL_Bus_LidarMapSim128_nav_msgs_OccupancyGrid Out1_Y0;// Computed Parameter: Out1_Y0
                                                       //  Referenced by: '<S11>/Out1'

  SL_Bus_LidarMapSim128_nav_msgs_OccupancyGrid Constant_Value;// Computed Parameter: Constant_Value
                                                              //  Referenced by: '<S9>/Constant'

  SL_Bus_LidarMapSim128_nav_msgs_OccupancyGrid Constant_Value_b;// Computed Parameter: Constant_Value_b
                                                                //  Referenced by: '<S3>/Constant'

  SL_Bus_LidarMapSim128_geometry_msgs_Vector3 Out1_Y0_e;// Computed Parameter: Out1_Y0_e
                                                        //  Referenced by: '<S13>/Out1'

  SL_Bus_LidarMapSim128_geometry_msgs_Vector3 Constant_Value_c;// Computed Parameter: Constant_Value_c
                                                               //  Referenced by: '<S12>/Constant'

  real_T Gain_Gain;                    // Expression: -1
                                       //  Referenced by: '<S10>/Gain'

  real_T Constant_Value_be;            // Expression: 0
                                       //  Referenced by: '<S10>/Constant'

  SL_Bus_LidarMapSim128_std_msgs_Float64 Constant_Value_g;// Computed Parameter: Constant_Value_g
                                                          //  Referenced by: '<S4>/Constant'

};

// Real-time Model Data Structure
struct tag_RTM_LidarMapSim128_T {
  const char_T *errorStatus;
};

// Block parameters (auto storage)
#ifdef __cplusplus

extern "C" {

#endif

  extern P_LidarMapSim128_T LidarMapSim128_P;

#ifdef __cplusplus

}
#endif

// Block signals (auto storage)
extern B_LidarMapSim128_T LidarMapSim128_B;

// Block states (auto storage)
extern DW_LidarMapSim128_T LidarMapSim128_DW;

#ifdef __cplusplus

extern "C" {

#endif

#ifdef __cplusplus

}
#endif

#ifdef __cplusplus

extern "C" {

#endif

  // Model entry point functions
  extern void LidarMapSim128_initialize(void);
  extern void LidarMapSim128_step(void);
  extern void LidarMapSim128_terminate(void);

#ifdef __cplusplus

}
#endif

// Real-time Model object
#ifdef __cplusplus

extern "C" {

#endif

  extern RT_MODEL_LidarMapSim128_T *const LidarMapSim128_M;

#ifdef __cplusplus

}
#endif

//-
//  The generated code includes comments that allow you to trace directly
//  back to the appropriate location in the model.  The basic format
//  is <system>/block_name, where system is the system number (uniquely
//  assigned by Simulink) and block_name is the name of the block.
//
//  Use the MATLAB hilite_system command to trace the generated code back
//  to the model.  For example,
//
//  hilite_system('<S3>')    - opens system 3
//  hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'LidarMapSim128'
//  '<S1>'   : 'LidarMapSim128/2Matrix'
//  '<S2>'   : 'LidarMapSim128/2Vector'
//  '<S3>'   : 'LidarMapSim128/Blank Message1'
//  '<S4>'   : 'LidarMapSim128/Blank Message2'
//  '<S5>'   : 'LidarMapSim128/Lidar Dont See Wall'
//  '<S6>'   : 'LidarMapSim128/LidarUpdate2'
//  '<S7>'   : 'LidarMapSim128/Publish1'
//  '<S8>'   : 'LidarMapSim128/Publish2'
//  '<S9>'   : 'LidarMapSim128/Subscribe'
//  '<S10>'  : 'LidarMapSim128/Subsystem'
//  '<S11>'  : 'LidarMapSim128/Subscribe/Enabled Subsystem'
//  '<S12>'  : 'LidarMapSim128/Subsystem/Subscribe2'
//  '<S13>'  : 'LidarMapSim128/Subsystem/Subscribe2/Enabled Subsystem'

#endif                                 // RTW_HEADER_LidarMapSim128_h_

//
// File trailer for generated code.
//
// [EOF]
//
