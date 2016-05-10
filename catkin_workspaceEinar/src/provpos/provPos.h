//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: provPos.h
//
// Code generated for Simulink model 'provPos'.
//
// Model version                  : 1.5
// Simulink Coder version         : 8.9 (R2015b) 13-Aug-2015
// C/C++ source code generated on : Mon Feb 15 16:41:50 2016
//
// Target selection: ert.tlc
// Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_provPos_h_
#define RTW_HEADER_provPos_h_
#include <string.h>
#include <stddef.h>
#ifndef provPos_COMMON_INCLUDES_
# define provPos_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "slros_initialize.h"
#endif                                 // provPos_COMMON_INCLUDES_

#include "provPos_types.h"

// Macros for accessing real-time model data structure
#ifndef rtmGetBlkStateChangeFlag
# define rtmGetBlkStateChangeFlag(rtm) ((rtm)->ModelData.blkStateChange)
#endif

#ifndef rtmSetBlkStateChangeFlag
# define rtmSetBlkStateChangeFlag(rtm, val) ((rtm)->ModelData.blkStateChange = (val))
#endif

#ifndef rtmGetContStateDisabled
# define rtmGetContStateDisabled(rtm)  ((rtm)->ModelData.contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
# define rtmSetContStateDisabled(rtm, val) ((rtm)->ModelData.contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
# define rtmGetContStates(rtm)         ((rtm)->ModelData.contStates)
#endif

#ifndef rtmSetContStates
# define rtmSetContStates(rtm, val)    ((rtm)->ModelData.contStates = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
# define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->ModelData.derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
# define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->ModelData.derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetIntgData
# define rtmGetIntgData(rtm)           ((rtm)->ModelData.intgData)
#endif

#ifndef rtmSetIntgData
# define rtmSetIntgData(rtm, val)      ((rtm)->ModelData.intgData = (val))
#endif

#ifndef rtmGetOdeF
# define rtmGetOdeF(rtm)               ((rtm)->ModelData.odeF)
#endif

#ifndef rtmSetOdeF
# define rtmSetOdeF(rtm, val)          ((rtm)->ModelData.odeF = (val))
#endif

#ifndef rtmGetOdeY
# define rtmGetOdeY(rtm)               ((rtm)->ModelData.odeY)
#endif

#ifndef rtmSetOdeY
# define rtmSetOdeY(rtm, val)          ((rtm)->ModelData.odeY = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
# define rtmGetPeriodicContStateIndices(rtm) ((rtm)->ModelData.periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
# define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->ModelData.periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
# define rtmGetPeriodicContStateRanges(rtm) ((rtm)->ModelData.periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
# define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->ModelData.periodicContStateRanges = (val))
#endif

#ifndef rtmGetZCCacheNeedsReset
# define rtmGetZCCacheNeedsReset(rtm)  ((rtm)->ModelData.zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
# define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->ModelData.zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetdX
# define rtmGetdX(rtm)                 ((rtm)->ModelData.derivs)
#endif

#ifndef rtmSetdX
# define rtmSetdX(rtm, val)            ((rtm)->ModelData.derivs = (val))
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

// Block signals (auto storage)
typedef struct {
  SL_Bus_provPos_std_msgs_Float64 In1; // '<S7>/In1'
} B_provPos_T;

// Block states (auto storage) for system '<Root>'
typedef struct {
  robotics_slros_internal_blo_d_T obj; // '<Root>/Get Parameter'
  void *SourceBlock_PWORK;             // '<S4>/SourceBlock'
  void *SinkBlock_PWORK;               // '<S3>/SinkBlock'
  void *SinkBlock_PWORK_j;             // '<S6>/SinkBlock'
  void *GetParameter_PWORK;            // '<Root>/Get Parameter'
  void *SetParameter_PWORK;            // '<Root>/Set Parameter'
  void *SetParameter1_PWORK;           // '<Root>/Set Parameter1'
  robotics_slros_internal_bl_de_T obj_g;// '<S3>/SinkBlock'
  robotics_slros_internal_bl_de_T obj_h;// '<S6>/SinkBlock'
  robotics_slros_internal_block_T obj_k;// '<Root>/Set Parameter'
  robotics_slros_internal_block_T obj_n;// '<Root>/Set Parameter1'
  robotics_slros_internal_b_del_T obj_gv;// '<S4>/SourceBlock'
  boolean_T objisempty;                // '<S4>/SourceBlock'
  boolean_T objisempty_o;              // '<S3>/SinkBlock'
  boolean_T objisempty_j;              // '<S6>/SinkBlock'
  boolean_T objisempty_b;              // '<Root>/Get Parameter'
  boolean_T objisempty_n;              // '<Root>/Set Parameter'
  boolean_T objisempty_bi;             // '<Root>/Set Parameter1'
} DW_provPos_T;

// Continuous states (auto storage)
typedef struct {
  real_T Integrator_CSTATE;            // '<Root>/Integrator'
} X_provPos_T;

// State derivatives (auto storage)
typedef struct {
  real_T Integrator_CSTATE;            // '<Root>/Integrator'
} XDot_provPos_T;

// State disabled
typedef struct {
  boolean_T Integrator_CSTATE;         // '<Root>/Integrator'
} XDis_provPos_T;

#ifndef ODE3_INTG
#define ODE3_INTG

// ODE3 Integration Data
typedef struct {
  real_T *y;                           // output
  real_T *f[3];                        // derivatives
} ODE3_IntgData;

#endif

// Parameters (auto storage)
struct P_provPos_T_ {
  real_T GetParameter_SampleTime;      // Expression: SampleTime
                                       //  Referenced by: '<Root>/Get Parameter'

  real_T Integrator_IC;                // Expression: 0
                                       //  Referenced by: '<Root>/Integrator'

  real_T Constant_Value;               // Expression: 1
                                       //  Referenced by: '<Root>/Constant'

  real_T Kp1_Value;                    // Expression: 1
                                       //  Referenced by: '<Root>/Kp1'

  real_T Kp2_Value;                    // Expression: 2
                                       //  Referenced by: '<Root>/Kp2'

  SL_Bus_provPos_std_msgs_Float64 Constant_Value_d;// Computed Parameter: Constant_Value_d
                                                   //  Referenced by: '<S5>/Constant'

  SL_Bus_provPos_std_msgs_Float64 Out1_Y0;// Computed Parameter: Out1_Y0
                                          //  Referenced by: '<S7>/Out1'

  SL_Bus_provPos_std_msgs_Float64 Constant_Value_h;// Computed Parameter: Constant_Value_h
                                                   //  Referenced by: '<S4>/Constant'

  SL_Bus_provPos_std_msgs_Float64 Constant_Value_e;// Computed Parameter: Constant_Value_e
                                                   //  Referenced by: '<S1>/Constant'

};

// Real-time Model Data Structure
struct tag_RTM_provPos_T {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;

  //
  //  ModelData:
  //  The following substructure contains information regarding
  //  the data used in the model.

  struct {
    X_provPos_T *contStates;
    int_T *periodicContStateIndices;
    real_T *periodicContStateRanges;
    real_T *derivs;
    boolean_T *contStateDisabled;
    boolean_T zCCacheNeedsReset;
    boolean_T derivCacheNeedsReset;
    boolean_T blkStateChange;
    real_T odeY[1];
    real_T odeF[3][1];
    ODE3_IntgData intgData;
  } ModelData;

  //
  //  Sizes:
  //  The following substructure contains sizes information
  //  for many of the model attributes such as inputs, outputs,
  //  dwork, sample times, etc.

  struct {
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

  //
  //  Timing:
  //  The following substructure contains information regarding
  //  the timing information for the model.

  struct {
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

// Block parameters (auto storage)
#ifdef __cplusplus

extern "C" {

#endif

  extern P_provPos_T provPos_P;

#ifdef __cplusplus

}
#endif

// Block signals (auto storage)
extern B_provPos_T provPos_B;

// Continuous states (auto storage)
extern X_provPos_T provPos_X;

// Block states (auto storage)
extern DW_provPos_T provPos_DW;

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
  extern void provPos_initialize(void);
  extern void provPos_step(void);
  extern void provPos_terminate(void);

#ifdef __cplusplus

}
#endif

// Real-time Model object
#ifdef __cplusplus

extern "C" {

#endif

  extern RT_MODEL_provPos_T *const provPos_M;

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
//  '<Root>' : 'provPos'
//  '<S1>'   : 'provPos/Blank Message'
//  '<S2>'   : 'provPos/Out'
//  '<S3>'   : 'provPos/Publish'
//  '<S4>'   : 'provPos/Subscribe'
//  '<S5>'   : 'provPos/Out/Blank Message'
//  '<S6>'   : 'provPos/Out/Publish'
//  '<S7>'   : 'provPos/Subscribe/Enabled Subsystem'

#endif                                 // RTW_HEADER_provPos_h_

//
// File trailer for generated code.
//
// [EOF]
//
