//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: ROS_Controller_data.cpp
//
// Code generated for Simulink model 'ROS_Controller'.
//
// Model version                  : 1.24
// Simulink Coder version         : 8.9 (R2015b) 13-Aug-2015
// C/C++ source code generated on : Sun Apr 10 13:42:56 2016
//
// Target selection: ert.tlc
// Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "ROS_Controller.h"
#include "ROS_Controller_private.h"

// Block parameters (auto storage)
P_ROS_Controller_T ROS_Controller_P = {
  //  Variable: C_nuParams
  //  Referenced by: '<S9>/Constant3'

  { 0.0, 9.51, 0.0, -9.51, 0.0, 0.0, 0.0, -0.0, 0.0 },

  //  Variable: D
  //  Referenced by: '<S9>/Constant1'

  { 1.9599, 0.0, 0.0, 0.0, 1.9599, 0.0, 0.0, 0.0, 0.19599 },

  //  Variable: D_nuParams
  //  Referenced by: '<S9>/Constant2'

  { 7.0948, 0.0, 0.0, 0.0, 7.0948, 0.0, 0.0, 0.0, 0.70948000000000011 },

  //  Variable: InitialPos
  //  Referenced by: '<S9>/Integrator'

  { 0.0, 0.0, 0.0 },

  //  Variable: K2
  //  Referenced by: '<S9>/Gain'

  { 0.25, 0.0, 0.0, 0.0, 0.25, 0.0, 0.0, 0.0, 0.25 },

  //  Variable: K3
  //  Referenced by: '<S9>/Gain1'

  { 0.2, 0.0, 0.0, 0.0, 0.2, 0.0, 0.0, 0.0, 0.2 },

  //  Variable: K4
  //  Referenced by: '<S9>/Gain2'

  { 5.0, 0.0, 0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.5 },

  //  Variable: Kd
  //  Referenced by: '<S1>/Gain2'

  { 4.0, 0.0, 0.0, 0.0, 4.0, 0.0, 0.0, 0.0, 4.0 },

  //  Variable: Ki
  //  Referenced by: '<S1>/Gain1'

  { 0.01, 0.0, 0.0, 0.0, 0.01, 0.0, 0.0, 0.0, 0.01 },

  //  Variable: Kp
  //  Referenced by: '<S1>/Gain'

  { 1.5, 0.0, 0.0, 0.0, 1.5, 0.0, 0.0, 0.0, 1.5 },

  //  Variable: Sat2Low
  //  Referenced by: '<S5>/Saturation4'

  { -0.56, -0.56, -1.12 },

  //  Variable: Sat2Up
  //  Referenced by: '<S5>/Saturation4'

  { 0.56, 0.56, 1.12 },

  //  Variable: Tr
  //  Referenced by: '<S6>/Thrust allocation Matrix'

  { 0.0, 1.0, 0.13735, 0.86602540378443871, -0.49999999999999978, 0.13735,
    -0.86602540378443849, -0.50000000000000044, 0.13735 },

  //  Variable: invM
  //  Referenced by: '<S9>/Constant'

  { 0.10515247108307045, 0.0, 0.0, 0.0, 0.10515247108307045, 0.0, 0.0, 0.0,
    8.6206896551724128 },

  //  Variable: invT
  //  Referenced by: '<S9>/Gain3'

  { 10.0, 0.0, 0.0, 0.0, 10.0, 0.0, 0.0, 0.0, 10.0 },

  //  Variable: invThrustAloc
  //  Referenced by: '<S6>/Inverse thrust allocation Matrix'

  { -1.1102230246251565E-16, 0.577350269189626, -0.57735026918962562,
    0.66666666666666663, -0.33333333333333326, -0.33333333333333337,
    2.4268899405411966, 2.4268899405411961, 2.4268899405411966 },

  //  Variable: wni
  //  Referenced by: '<S5>/w_n'

  { 0.89442719099991586, 0.0, 0.0, 0.0, 0.89442719099991586, 0.0, 0.0, 0.0,
    1.0488088481701516 },

  //  Variable: wniCeta2
  //  Referenced by: '<S5>/ciwni'

  { 1.4310835055998654, 0.0, 0.0, 0.0, 1.4310835055998654, 0.0, 0.0, 0.0,
    1.6780941570722427 },

  //  Variable: wnisquared
  //  Referenced by:
  //    '<S5>/w_n1'
  //    '<S5>/w_n2'

  { 0.79999999999999993, 0.0, 0.0, 0.0, 0.79999999999999993, 0.0, 0.0, 0.0, 1.1
  },

  {
    0.0,                               // X
    0.0,                               // Y
    0.0                                // Z
  },                                   // Computed Parameter: Out1_Y0
                                       //  Referenced by: '<S15>/Out1'


  {
    0.0,                               // X
    0.0,                               // Y
    0.0                                // Z
  },                                   // Computed Parameter: Constant_Value
                                       //  Referenced by: '<S14>/Constant'


  {
    0.0,                               // X
    0.0,                               // Y
    0.0                                // Z
  },                                   // Computed Parameter: Out1_Y0_d
                                       //  Referenced by: '<S17>/Out1'


  {
    0.0,                               // X
    0.0,                               // Y
    0.0                                // Z
  },                                   // Computed Parameter: Constant_Value_k
                                       //  Referenced by: '<S16>/Constant'


  {
    0.0,                               // X
    0.0,                               // Y
    0.0                                // Z
  },                                   // Computed Parameter: Constant_Value_d
                                       //  Referenced by: '<S19>/Constant'

  -10.0,                               // Computed Parameter: TransferFcn5_A
                                       //  Referenced by: '<S6>/Transfer Fcn5'

  10.0,                                // Computed Parameter: TransferFcn5_C
                                       //  Referenced by: '<S6>/Transfer Fcn5'

  -10.0,                               // Computed Parameter: TransferFcn6_A
                                       //  Referenced by: '<S6>/Transfer Fcn6'

  10.0,                                // Computed Parameter: TransferFcn6_C
                                       //  Referenced by: '<S6>/Transfer Fcn6'

  -10.0,                               // Computed Parameter: TransferFcn7_A
                                       //  Referenced by: '<S6>/Transfer Fcn7'

  10.0,                                // Computed Parameter: TransferFcn7_C
                                       //  Referenced by: '<S6>/Transfer Fcn7'


  //  Expression: [0;0;0]
  //  Referenced by: '<S5>/Integrator2'

  { 0.0, 0.0, 0.0 },
  0.0,                                 // Expression: 0
                                       //  Referenced by: '<S9>/Integrator1'


  //  Expression: [0;0;0]
  //  Referenced by: '<S1>/Integrator1'

  { 0.0, 0.0, 0.0 },

  //  Expression: [1;1;1]
  //  Referenced by: '<S1>/Integrator1'

  { 1.0, 1.0, 1.0 },

  //  Expression: [-1;-1;-1]
  //  Referenced by: '<S1>/Integrator1'

  { -1.0, -1.0, -1.0 },
  0.0,                                 // Expression: 0
                                       //  Referenced by: '<S3>/Constant'


  //  Expression: [0;0;0]
  //  Referenced by: '<S9>/Integrator2'

  { 0.0, 0.0, 0.0 },
  0.0,                                 // Expression: 0
                                       //  Referenced by: '<S4>/Constant'


  //  Expression: [0;0;0]
  //  Referenced by: '<S5>/Integrator'

  { 0.0, 0.0, 0.0 },

  //  Expression: [0 ;0; 0]
  //  Referenced by: '<S5>/Integrator1'

  { 0.0, 0.0, 0.0 },
  4.0,                                 // Expression: 4
                                       //  Referenced by: '<S6>/Saturation5'

  -4.0,                                // Expression: -4
                                       //  Referenced by: '<S6>/Saturation5'

  4.0,                                 // Expression: 4
                                       //  Referenced by: '<S6>/Saturation6'

  -4.0,                                // Expression: -4
                                       //  Referenced by: '<S6>/Saturation6'

  4.0,                                 // Expression: 4
                                       //  Referenced by: '<S6>/Saturation7'

  -4.0                                 // Expression: -4
                                       //  Referenced by: '<S6>/Saturation7'

};

//
// File trailer for generated code.
//
// [EOF]
//
