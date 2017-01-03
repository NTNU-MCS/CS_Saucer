//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: MotionControlCompile.h
//
// Code generated for Simulink model 'MotionControlCompile'.
//
// Model version                  : 1.79
// Simulink Coder version         : 8.9 (R2015b) 13-Aug-2015
// C/C++ source code generated on : Wed Jun 22 12:06:42 2016
//
// Target selection: ert.tlc
// Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_MotionControlCompile_h_
#define RTW_HEADER_MotionControlCompile_h_
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef MotionControlCompile_COMMON_INCLUDES_
# define MotionControlCompile_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "slros_initialize.h"
#endif                                 // MotionControlCompile_COMMON_INCLUDES_

#include "MotionControlCompile_types.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

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
  real_T MAPP3[62];
  real_T y[62];
  real_T x[62];
  real_T y_m[52];
  real_T x_c[52];
  real_T dv3[9];
  SL_Bus_MotionControlCompile_geometry_msgs_Vector3 In1;// '<S26>/In1'
  SL_Bus_MotionControlCompile_geometry_msgs_Vector3 In1_i;// '<S24>/In1'
  SL_Bus_MotionControlCompile_geometry_msgs_Vector3 BusAssignment3;// '<S14>/Bus Assignment3' 
  real_T Integrator2[3];               // '<S6>/Integrator2'
  real_T Gain1[3];                     // '<S1>/Gain1'
  real_T Product1[3];                  // '<S16>/Product1'
  real_T Sum1[3];                      // '<S16>/Sum1'
  real_T Sum4[3];                      // '<S16>/Sum4'
  real_T nframetobframe[3];            // '<S16>/{n} frame to {b} frame'
  real_T Sum2[3];                      // '<S1>/Sum2'
  real_T rtb_R_b[3];
  real_T dv0[3];
  real_T dv1[3];
  real_T dv2[3];
  char_T cv0[14];
  real_T X;
  real_T Y;
  real_T Z;
  real_T X_h;
  real_T Y_i;
  real_T Z_n;
  real_T Saturation4[3];               // '<S6>/Saturation4'
  real_T Sum3[3];                      // '<S6>/Sum3'
  real_T w_n[3];                       // '<S6>/w_n'
  real_T R[9];                         // '<S16>/MATLAB Function1'
  real_T R_t[9];                       // '<S16>/MATLAB Function'
  real_T R_k[9];                       // '<S1>/Rotation Matrix'
  real_T Gain[3];                      // '<S16>/Gain'
  real_T Gain1_c[3];                   // '<S16>/Gain1'
  real_T Com_Torque;
  real_T scale;
  real_T tmp;
  real_T r;
  real_T unnamed_idx_1;
  real_T unnamed_idx_2;
  real_T r_p;
  SL_Bus_MotionControlCompile_std_msgs_Float64 BusAssignment1;// '<S3>/Bus Assignment1' 
  SL_Bus_MotionControlCompile_std_msgs_Bool In1_h;// '<S34>/In1'
  int32_T low_i;
  int32_T low_ip1;
} B_MotionControlCompile_T;

// Block states (auto storage) for system '<Root>'
typedef struct {
  real_T TimeStampA;                   // '<S1>/Derivative'
  real_T LastUAtTimeA[3];              // '<S1>/Derivative'
  real_T TimeStampB;                   // '<S1>/Derivative'
  real_T LastUAtTimeB[3];              // '<S1>/Derivative'
  void *SinkBlock_PWORK;               // '<S39>/SinkBlock'
  void *SinkBlock_PWORK_m;             // '<S38>/SinkBlock'
  void *SinkBlock_PWORK_p;             // '<S37>/SinkBlock'
  void *SourceBlock_PWORK;             // '<S33>/SourceBlock'
  void *SinkBlock_PWORK_pj;            // '<S32>/SinkBlock'
  void *SinkBlock_PWORK_n;             // '<S31>/SinkBlock'
  void *SinkBlock_PWORK_i;             // '<S30>/SinkBlock'
  void *SourceBlock_PWORK_h;           // '<S25>/SourceBlock'
  void *SourceBlock_PWORK_f;           // '<S23>/SourceBlock'
  void *SinkBlock_PWORK_l;             // '<S15>/SinkBlock'
  void *SinkBlock_PWORK_d;             // '<S18>/SinkBlock'
  robotics_slros_internal_block_T obj; // '<S39>/SinkBlock'
  robotics_slros_internal_block_T obj_p;// '<S38>/SinkBlock'
  robotics_slros_internal_block_T obj_j;// '<S37>/SinkBlock'
  robotics_slros_internal_block_T obj_b;// '<S32>/SinkBlock'
  robotics_slros_internal_block_T obj_n;// '<S31>/SinkBlock'
  robotics_slros_internal_block_T obj_nl;// '<S30>/SinkBlock'
  robotics_slros_internal_block_T obj_g;// '<S15>/SinkBlock'
  robotics_slros_internal_block_T obj_m;// '<S18>/SinkBlock'
  robotics_slros_internal_blo_j_T obj_pd;// '<S33>/SourceBlock'
  robotics_slros_internal_blo_j_T obj_k;// '<S25>/SourceBlock'
  robotics_slros_internal_blo_j_T obj_o;// '<S23>/SourceBlock'
  boolean_T objisempty;                // '<S39>/SinkBlock'
  boolean_T objisempty_e;              // '<S38>/SinkBlock'
  boolean_T objisempty_f;              // '<S37>/SinkBlock'
  boolean_T objisempty_h;              // '<S33>/SourceBlock'
  boolean_T objisempty_j;              // '<S32>/SinkBlock'
  boolean_T objisempty_p;              // '<S31>/SinkBlock'
  boolean_T objisempty_je;             // '<S30>/SinkBlock'
  boolean_T objisempty_m;              // '<S25>/SourceBlock'
  boolean_T objisempty_i;              // '<S23>/SourceBlock'
  boolean_T objisempty_d;              // '<S15>/SinkBlock'
  boolean_T objisempty_fo;             // '<S18>/SinkBlock'
} DW_MotionControlCompile_T;

// Continuous states (auto storage)
typedef struct {
  real_T Integrator1_CSTATE[3];        // '<S16>/Integrator1'
  real_T Integrator_CSTATE[3];         // '<S16>/Integrator'
  real_T Integrator2_CSTATE[3];        // '<S6>/Integrator2'
  real_T Integrator1_CSTATE_d[3];      // '<S1>/Integrator1'
  real_T Integrator2_CSTATE_n[3];      // '<S16>/Integrator2'
  real_T Integrator_CSTATE_a[3];       // '<S6>/Integrator'
  real_T Integrator1_CSTATE_i[3];      // '<S6>/Integrator1'
} X_MotionControlCompile_T;

// State derivatives (auto storage)
typedef struct {
  real_T Integrator1_CSTATE[3];        // '<S16>/Integrator1'
  real_T Integrator_CSTATE[3];         // '<S16>/Integrator'
  real_T Integrator2_CSTATE[3];        // '<S6>/Integrator2'
  real_T Integrator1_CSTATE_d[3];      // '<S1>/Integrator1'
  real_T Integrator2_CSTATE_n[3];      // '<S16>/Integrator2'
  real_T Integrator_CSTATE_a[3];       // '<S6>/Integrator'
  real_T Integrator1_CSTATE_i[3];      // '<S6>/Integrator1'
} XDot_MotionControlCompile_T;

// State disabled
typedef struct {
  boolean_T Integrator1_CSTATE[3];     // '<S16>/Integrator1'
  boolean_T Integrator_CSTATE[3];      // '<S16>/Integrator'
  boolean_T Integrator2_CSTATE[3];     // '<S6>/Integrator2'
  boolean_T Integrator1_CSTATE_d[3];   // '<S1>/Integrator1'
  boolean_T Integrator2_CSTATE_n[3];   // '<S16>/Integrator2'
  boolean_T Integrator_CSTATE_a[3];    // '<S6>/Integrator'
  boolean_T Integrator1_CSTATE_i[3];   // '<S6>/Integrator1'
} XDis_MotionControlCompile_T;

#ifndef ODE3_INTG
#define ODE3_INTG

// ODE3 Integration Data
typedef struct {
  real_T *y;                           // output
  real_T *f[3];                        // derivatives
} ODE3_IntgData;

#endif

// Parameters (auto storage)
struct P_MotionControlCompile_T_ {
  real_T C_nuParams[9];                // Variable: C_nuParams
                                       //  Referenced by: '<S16>/Constant3'

  real_T D[9];                         // Variable: D
                                       //  Referenced by: '<S16>/Constant1'

  real_T D_nuParams[9];                // Variable: D_nuParams
                                       //  Referenced by: '<S16>/Constant2'

  real_T InitialPos[3];                // Variable: InitialPos
                                       //  Referenced by: '<S16>/Integrator'

  real_T K2[9];                        // Variable: K2
                                       //  Referenced by: '<S16>/Gain'

  real_T K3[9];                        // Variable: K3
                                       //  Referenced by: '<S16>/Gain1'

  real_T K4[9];                        // Variable: K4
                                       //  Referenced by: '<S16>/Gain2'

  real_T Ki[9];                        // Variable: Ki
                                       //  Referenced by: '<S1>/Gain1'

  real_T MAPP1[62];                    // Variable: MAPP1
                                       //  Referenced by: '<S2>/Constant3'

  real_T MAPP2[52];                    // Variable: MAPP2
                                       //  Referenced by: '<S2>/Constant1'

  real_T MAPP3[46];                    // Variable: MAPP3
                                       //  Referenced by: '<S2>/Constant2'

  real_T Sat2Low[3];                   // Variable: Sat2Low
                                       //  Referenced by: '<S6>/Saturation4'

  real_T Sat2Up[3];                    // Variable: Sat2Up
                                       //  Referenced by: '<S6>/Saturation4'

  real_T Th1[62];                      // Variable: Th1
                                       //  Referenced by: '<S2>/Constant4'

  real_T Th2[52];                      // Variable: Th2
                                       //  Referenced by: '<S2>/Constant5'

  real_T Th3[46];                      // Variable: Th3
                                       //  Referenced by: '<S2>/Constant6'

  real_T Tr[9];                        // Variable: Tr
                                       //  Referenced by: '<S7>/Thrust allocation Matrix'

  real_T invM[9];                      // Variable: invM
                                       //  Referenced by: '<S16>/Constant'

  real_T invT[9];                      // Variable: invT
                                       //  Referenced by: '<S16>/Gain3'

  real_T invThrustAloc[9];             // Variable: invThrustAloc
                                       //  Referenced by: '<S7>/Inverse thrust allocation Matrix'

  real_T wni[9];                       // Variable: wni
                                       //  Referenced by: '<S6>/w_n'

  real_T wniCeta2[9];                  // Variable: wniCeta2
                                       //  Referenced by: '<S6>/ciwni'

  real_T wnisquared[9];                // Variable: wnisquared
                                       //  Referenced by:
                                       //    '<S6>/w_n1'
                                       //    '<S6>/w_n2'

  SL_Bus_MotionControlCompile_geometry_msgs_Vector3 Out1_Y0;// Computed Parameter: Out1_Y0
                                                            //  Referenced by: '<S24>/Out1'

  SL_Bus_MotionControlCompile_geometry_msgs_Vector3 Constant_Value;// Computed Parameter: Constant_Value
                                                                   //  Referenced by: '<S23>/Constant'

  SL_Bus_MotionControlCompile_geometry_msgs_Vector3 Out1_Y0_d;// Computed Parameter: Out1_Y0_d
                                                              //  Referenced by: '<S26>/Out1'

  SL_Bus_MotionControlCompile_geometry_msgs_Vector3 Constant_Value_k;// Computed Parameter: Constant_Value_k
                                                                     //  Referenced by: '<S25>/Constant'

  SL_Bus_MotionControlCompile_geometry_msgs_Vector3 Constant_Value_f;// Computed Parameter: Constant_Value_f
                                                                     //  Referenced by: '<S17>/Constant'

  real_T Constant_Value_h[3];          // Expression: zeros(3,1)
                                       //  Referenced by: '<S7>/Constant'

  real_T Integrator1_IC;               // Expression: 0
                                       //  Referenced by: '<S16>/Integrator1'

  real_T Integrator2_IC[3];            // Expression: [0;0;0]
                                       //  Referenced by: '<S6>/Integrator2'

  real_T Gain2_Gain[9];                // Expression: [.7 0 0 ;0 0.7 0;0 0 0.1]
                                       //  Referenced by: '<S1>/Gain2'

  real_T Integrator1_IC_h[3];          // Expression: [0;0;0]
                                       //  Referenced by: '<S1>/Integrator1'

  real_T Integrator1_UpperSat[3];      // Expression: [1;1;1]
                                       //  Referenced by: '<S1>/Integrator1'

  real_T Integrator1_LowerSat[3];      // Expression: [-1;-1;-1]
                                       //  Referenced by: '<S1>/Integrator1'

  real_T Gain_Gain[9];                 // Expression:  [1 0 0;0 1 0; 0 0 0.05]
                                       //  Referenced by: '<S1>/Gain'

  real_T ThrustSat_Value;              // Expression: 0.4
                                       //  Referenced by: '<S7>/Thrust Sat'

  real_T Gain_Gain_b[3];               // Expression: [1;1;0.5]*3
                                       //  Referenced by: '<S7>/Gain'

  real_T Saturation1_UpperSat;         // Expression: 1
                                       //  Referenced by: '<S7>/Saturation1'

  real_T Saturation1_LowerSat;         // Expression: -1
                                       //  Referenced by: '<S7>/Saturation1'

  real_T Saturation2_UpperSat;         // Expression: 1
                                       //  Referenced by: '<S7>/Saturation2'

  real_T Saturation2_LowerSat;         // Expression: -1
                                       //  Referenced by: '<S7>/Saturation2'

  real_T Saturation3_UpperSat;         // Expression: 0.05
                                       //  Referenced by: '<S7>/Saturation3'

  real_T Saturation3_LowerSat;         // Expression: -0.05
                                       //  Referenced by: '<S7>/Saturation3'

  real_T Saturation5_UpperSat;         // Expression: 4
                                       //  Referenced by: '<S7>/Saturation5'

  real_T Saturation5_LowerSat;         // Expression: -4
                                       //  Referenced by: '<S7>/Saturation5'

  real_T Saturation6_UpperSat;         // Expression: 4
                                       //  Referenced by: '<S7>/Saturation6'

  real_T Saturation6_LowerSat;         // Expression: -4
                                       //  Referenced by: '<S7>/Saturation6'

  real_T Saturation7_UpperSat;         // Expression: 4
                                       //  Referenced by: '<S7>/Saturation7'

  real_T Saturation7_LowerSat;         // Expression: -4
                                       //  Referenced by: '<S7>/Saturation7'

  real_T Constant7_Value;              // Expression: 0.1
                                       //  Referenced by: '<S2>/Constant7'

  real_T Constant8_Value;              // Expression: 0
                                       //  Referenced by: '<S2>/Constant8'

  real_T Constant9_Value;              // Expression: 0
                                       //  Referenced by: '<S2>/Constant9'

  real_T Integrator2_IC_j[3];          // Expression: [0;0;0]
                                       //  Referenced by: '<S16>/Integrator2'

  real_T Integrator_IC[3];             // Expression: [0;0;0]
                                       //  Referenced by: '<S6>/Integrator'

  real_T Integrator1_IC_e[3];          // Expression: [0 ;0; 0]
                                       //  Referenced by: '<S6>/Integrator1'

  real_T Pwm1_Value;                   // Expression: 0.047263
                                       //  Referenced by: '<Root>/Pwm1'

  real_T PWm3_Value;                   // Expression: 0.083578
                                       //  Referenced by: '<Root>/PWm3'

  real_T PWm4_Value;                   // Expression: 0.06542
                                       //  Referenced by: '<Root>/PWm4'

  SL_Bus_MotionControlCompile_std_msgs_Float64 Constant_Value_hl;// Computed Parameter: Constant_Value_hl
                                                                 //  Referenced by: '<S12>/Constant'

  SL_Bus_MotionControlCompile_std_msgs_UInt16 Constant_Value_b;// Computed Parameter: Constant_Value_b
                                                               //  Referenced by: '<S28>/Constant'

  SL_Bus_MotionControlCompile_std_msgs_UInt16 Constant_Value_c;// Computed Parameter: Constant_Value_c
                                                               //  Referenced by: '<S35>/Constant'

  SL_Bus_MotionControlCompile_std_msgs_Bool Out1_Y0_p;// Computed Parameter: Out1_Y0_p
                                                      //  Referenced by: '<S34>/Out1'

  SL_Bus_MotionControlCompile_std_msgs_Bool Constant_Value_j;// Computed Parameter: Constant_Value_j
                                                             //  Referenced by: '<S33>/Constant'

  uint16_T Constant_Value_n;           // Computed Parameter: Constant_Value_n
                                       //  Referenced by: '<S8>/Constant'

  uint16_T Constant1_Value;            // Computed Parameter: Constant1_Value
                                       //  Referenced by: '<S8>/Constant1'

  uint16_T Constant2_Value;            // Computed Parameter: Constant2_Value
                                       //  Referenced by: '<S8>/Constant2'

  uint8_T ManualSwitch_CurrentSetting; // Computed Parameter: ManualSwitch_CurrentSetting
                                       //  Referenced by: '<S7>/Manual Switch'

  uint8_T ManualSwitch1_CurrentSetting;// Computed Parameter: ManualSwitch1_CurrentSetting
                                       //  Referenced by: '<S2>/Manual Switch1'

};

// Real-time Model Data Structure
struct tag_RTM_MotionControlCompile_T {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;

  //
  //  ModelData:
  //  The following substructure contains information regarding
  //  the data used in the model.

  struct {
    X_MotionControlCompile_T *contStates;
    int_T *periodicContStateIndices;
    real_T *periodicContStateRanges;
    real_T *derivs;
    boolean_T *contStateDisabled;
    boolean_T zCCacheNeedsReset;
    boolean_T derivCacheNeedsReset;
    boolean_T blkStateChange;
    real_T odeY[21];
    real_T odeF[3][21];
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

  extern P_MotionControlCompile_T MotionControlCompile_P;

#ifdef __cplusplus

}
#endif

// Block signals (auto storage)
extern B_MotionControlCompile_T MotionControlCompile_B;

// Continuous states (auto storage)
extern X_MotionControlCompile_T MotionControlCompile_X;

// Block states (auto storage)
extern DW_MotionControlCompile_T MotionControlCompile_DW;

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
  extern void MotionControlCompile_initialize(void);
  extern void MotionControlCompile_step(void);
  extern void MotionControlCompile_terminate(void);

#ifdef __cplusplus

}
#endif

// Real-time Model object
#ifdef __cplusplus

extern "C" {

#endif

  extern RT_MODEL_MotionControlCompile_T *const MotionControlCompile_M;

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
//  '<Root>' : 'MotionControlCompile'
//  '<S1>'   : 'MotionControlCompile/DPcontroller'
//  '<S2>'   : 'MotionControlCompile/EINAR2180MAP1'
//  '<S3>'   : 'MotionControlCompile/NonlinearPassiveObs'
//  '<S4>'   : 'MotionControlCompile/Subsystem'
//  '<S5>'   : 'MotionControlCompile/Subsystem1'
//  '<S6>'   : 'MotionControlCompile/ThirdOrderFossen 1'
//  '<S7>'   : 'MotionControlCompile/ThrustDynamics'
//  '<S8>'   : 'MotionControlCompile/UOUT'
//  '<S9>'   : 'MotionControlCompile/aout'
//  '<S10>'  : 'MotionControlCompile/DPcontroller/Rotation Matrix'
//  '<S11>'  : 'MotionControlCompile/EINAR2180MAP1/PWM-Mapping'
//  '<S12>'  : 'MotionControlCompile/NonlinearPassiveObs/Blank Message1'
//  '<S13>'  : 'MotionControlCompile/NonlinearPassiveObs/MATLAB Function'
//  '<S14>'  : 'MotionControlCompile/NonlinearPassiveObs/NuOut'
//  '<S15>'  : 'MotionControlCompile/NonlinearPassiveObs/Publish1'
//  '<S16>'  : 'MotionControlCompile/NonlinearPassiveObs/Subsystem'
//  '<S17>'  : 'MotionControlCompile/NonlinearPassiveObs/NuOut/Blank Message1'
//  '<S18>'  : 'MotionControlCompile/NonlinearPassiveObs/NuOut/Publish3'
//  '<S19>'  : 'MotionControlCompile/NonlinearPassiveObs/Subsystem/Correalis matrix'
//  '<S20>'  : 'MotionControlCompile/NonlinearPassiveObs/Subsystem/Dampening matrix'
//  '<S21>'  : 'MotionControlCompile/NonlinearPassiveObs/Subsystem/MATLAB Function'
//  '<S22>'  : 'MotionControlCompile/NonlinearPassiveObs/Subsystem/MATLAB Function1'
//  '<S23>'  : 'MotionControlCompile/Subsystem/Subscribe2'
//  '<S24>'  : 'MotionControlCompile/Subsystem/Subscribe2/Enabled Subsystem'
//  '<S25>'  : 'MotionControlCompile/Subsystem1/Subscribe2'
//  '<S26>'  : 'MotionControlCompile/Subsystem1/Subscribe2/Enabled Subsystem'
//  '<S27>'  : 'MotionControlCompile/ThrustDynamics/Torque Saturation'
//  '<S28>'  : 'MotionControlCompile/UOUT/Blank Message1'
//  '<S29>'  : 'MotionControlCompile/UOUT/Calibrate'
//  '<S30>'  : 'MotionControlCompile/UOUT/Publish1'
//  '<S31>'  : 'MotionControlCompile/UOUT/Publish2'
//  '<S32>'  : 'MotionControlCompile/UOUT/Publish3'
//  '<S33>'  : 'MotionControlCompile/UOUT/Subscribe2'
//  '<S34>'  : 'MotionControlCompile/UOUT/Subscribe2/Enabled Subsystem'
//  '<S35>'  : 'MotionControlCompile/aout/Blank Message1'
//  '<S36>'  : 'MotionControlCompile/aout/PWM2Map180 '
//  '<S37>'  : 'MotionControlCompile/aout/Publish1'
//  '<S38>'  : 'MotionControlCompile/aout/Publish2'
//  '<S39>'  : 'MotionControlCompile/aout/Publish3'

#endif                                 // RTW_HEADER_MotionControlCompile_h_

//
// File trailer for generated code.
//
// [EOF]
//
