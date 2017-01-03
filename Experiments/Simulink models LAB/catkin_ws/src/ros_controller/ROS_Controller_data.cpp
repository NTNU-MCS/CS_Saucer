//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: ROS_Controller_data.cpp
//
// Code generated for Simulink model 'ROS_Controller'.
//
// Model version                  : 1.76
// Simulink Coder version         : 8.9 (R2015b) 13-Aug-2015
// C/C++ source code generated on : Fri Jun  3 22:05:53 2016
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
  //  Referenced by: '<S16>/Constant3'

  { 0.0, 9.51, 0.0, -9.51, 0.0, 0.0, 0.0, -0.0, 0.0 },

  //  Variable: D
  //  Referenced by: '<S16>/Constant1'

  { 1.9599, 0.0, 0.0, 0.0, 1.9599, 0.0, 0.0, 0.0, 0.19599 },

  //  Variable: D_nuParams
  //  Referenced by: '<S16>/Constant2'

  { 7.0948, 0.0, 0.0, 0.0, 7.0948, 0.0, 0.0, 0.0, 0.70948000000000011 },

  //  Variable: InitialPos
  //  Referenced by: '<S16>/Integrator'

  { 0.0, 0.0, 0.0 },

  //  Variable: K2
  //  Referenced by: '<S16>/Gain'

  { 0.25, 0.0, 0.0, 0.0, 0.25, 0.0, 0.0, 0.0, 0.25 },

  //  Variable: K3
  //  Referenced by: '<S16>/Gain1'

  { 0.2, 0.0, 0.0, 0.0, 0.2, 0.0, 0.0, 0.0, 0.2 },

  //  Variable: K4
  //  Referenced by: '<S16>/Gain2'

  { 5.0, 0.0, 0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.5 },

  //  Variable: Ki
  //  Referenced by: '<S1>/Gain1'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  //  Variable: MAPP1
  //  Referenced by: '<S2>/Constant3'

  { -2.5650440371340184, -2.4593518209949972, -2.3217576767436343,
    -2.1646822185194026, -2.0260533206379425, -1.892491073553906,
    -1.7672349440609383, -1.6416917400618876, -1.529461318733637,
    -1.3970673649131158, -1.2785501071173513, -1.1559459652463697,
    -1.0347048321828103, -0.93514068079028734, -0.84887455367769382,
    -0.76415615329683406, -0.676386098547964, -0.58809616757914873,
    -0.5194725065460607, -0.4708985955724812, -0.41047274458462268,
    -0.345810997381576, -0.27868626517495859, -0.22347322066174655,
    -0.18141775767674395, -0.14022661271125914, -0.1066593668174242,
    -0.082829802427993426, -0.053513449178766992, -0.034410378481313939,
    -0.0007581528207569625, 0.0007581528207569625, 0.034410378481313939,
    0.053513449178766992, 0.082829802427993426, 0.1066593668174242,
    0.14022661271125914, 0.18141775767674395, 0.22347322066174655,
    0.27868626517495859, 0.345810997381576, 0.41047274458462268,
    0.4708985955724812, 0.5194725065460607, 0.58809616757914873,
    0.676386098547964, 0.76415615329683406, 0.84887455367769382,
    0.93514068079028734, 1.0347048321828103, 1.1559459652463697,
    1.2785501071173513, 1.3970673649131158, 1.529461318733637,
    1.6416917400618876, 1.7672349440609383, 1.892491073553906,
    2.0260533206379425, 2.1646822185194026, 2.3217576767436343,
    2.4593518209949972, 2.5650440371340184 },

  //  Variable: MAPP2
  //  Referenced by: '<S2>/Constant1'

  { -2.2108671744822739, -2.1357188764579886, -1.963239466793617,
    -1.8187260176148539, -1.6812047131635344, -1.5452394667936205,
    -1.4136665079742872, -1.3072518447988575, -1.1700049988098062,
    -1.0763470602237564, -0.981201380623661, -0.88021542489883464,
    -0.77893073077838659, -0.68714234706022381, -0.61916543680076142,
    -0.53948988336110337, -0.45876743632468331, -0.390102356581766,
    -0.32101309212092416, -0.27917710069031143, -0.24677076886455637,
    -0.19890383242085244, -0.16348226612711259, -0.13117233991906732,
    -0.098309212092358988, -0.083152344679837828, 0.083152344679837828,
    0.098309212092358988, 0.13117233991906732, 0.16348226612711259,
    0.19890383242085244, 0.24677076886455637, 0.27917710069031143,
    0.32101309212092416, 0.390102356581766, 0.45876743632468331,
    0.53948988336110337, 0.61916543680076142, 0.68714234706022381,
    0.77893073077838659, 0.88021542489883464, 0.981201380623661,
    1.0763470602237564, 1.1700049988098062, 1.3072518447988575,
    1.4136665079742872, 1.5452394667936205, 1.6812047131635344,
    1.8187260176148539, 1.963239466793617, 2.1357188764579886,
    2.2108671744822739 },

  //  Variable: MAPP3
  //  Referenced by: '<S2>/Constant2'

  { 1.873909783384911, 1.7542742204237132, 1.6055924779814359,
    1.4681649607236393, 1.32012711259224, 1.2124670316591248, 1.1144770292787407,
    1.0025577243513468, 0.92865817662461358, 0.82687383956200866,
    0.7466581766246132, 0.66431516305641547, 0.57340418947869654,
    0.49106117591049714, 0.42230825993811, 0.34918805046417406,
    0.28611949535824777, 0.21147393477743362, 0.16797262556534107,
    0.11740633182575549, 0.074678647940966777, 0.03148226612711276,
    0.0074325160676029407, -0.0074325160676029407, -0.03148226612711276,
    -0.074678647940966777, -0.11740633182575549, -0.16797262556534107,
    -0.21147393477743362, -0.28611949535824777, -0.34918805046417406,
    -0.42230825993811, -0.49106117591049714, -0.57340418947869654,
    -0.66431516305641547, -0.7466581766246132, -0.82687383956200866,
    -0.92865817662461358, -1.0025577243513468, -1.1144770292787407,
    -1.2124670316591248, -1.32012711259224, -1.4681649607236393,
    -1.6055924779814359, -1.7542742204237132, -1.873909783384911 },

  //  Variable: Sat2Low
  //  Referenced by: '<S6>/Saturation4'

  { -0.56, -0.56, -1.12 },

  //  Variable: Sat2Up
  //  Referenced by: '<S6>/Saturation4'

  { 0.56, 0.56, 1.12 },

  //  Variable: Th1
  //  Referenced by: '<S2>/Constant4'

  { 43.0, 44.0, 45.0, 46.0, 47.0, 48.0, 49.0, 50.0, 51.0, 52.0, 53.0, 54.0, 55.0,
    56.0, 57.0, 58.0, 59.0, 60.0, 61.0, 62.0, 63.0, 64.0, 65.0, 66.0, 67.0, 68.0,
    69.0, 70.0, 71.0, 72.0, 73.0, 88.0, 89.0, 90.0, 91.0, 92.0, 93.0, 94.0, 95.0,
    96.0, 97.0, 98.0, 99.0, 100.0, 101.0, 102.0, 103.0, 104.0, 105.0, 106.0,
    107.0, 108.0, 109.0, 110.0, 111.0, 112.0, 113.0, 114.0, 115.0, 116.0, 117.0,
    118.0 },

  //  Variable: Th2
  //  Referenced by: '<S2>/Constant5'

  { 46.0, 47.0, 48.0, 49.0, 50.0, 51.0, 52.0, 53.0, 54.0, 55.0, 56.0, 57.0, 58.0,
    59.0, 60.0, 61.0, 62.0, 63.0, 64.0, 65.0, 66.0, 67.0, 68.0, 69.0, 70.0, 71.0,
    89.0, 90.0, 91.0, 92.0, 93.0, 94.0, 95.0, 96.0, 97.0, 98.0, 99.0, 100.0,
    101.0, 102.0, 103.0, 104.0, 105.0, 106.0, 107.0, 108.0, 109.0, 110.0, 111.0,
    112.0, 113.0, 114.0 },

  //  Variable: Th3
  //  Referenced by: '<S2>/Constant6'

  { 47.0, 48.0, 49.0, 50.0, 51.0, 52.0, 53.0, 54.0, 55.0, 56.0, 57.0, 58.0, 59.0,
    60.0, 61.0, 62.0, 63.0, 64.0, 65.0, 66.0, 67.0, 68.0, 69.0, 91.0, 92.0, 93.0,
    94.0, 95.0, 96.0, 97.0, 98.0, 99.0, 100.0, 101.0, 102.0, 103.0, 103.0, 104.0,
    105.0, 106.0, 107.0, 108.0, 109.0, 110.0, 111.0, 112.0 },

  //  Variable: Tr
  //  Referenced by: '<S7>/Thrust allocation Matrix'

  { 0.0, 1.0, 0.13735, 0.86602540378443871, -0.49999999999999978, 0.13735,
    -0.86602540378443849, -0.50000000000000044, 0.13735 },

  //  Variable: invM
  //  Referenced by: '<S16>/Constant'

  { 0.10515247108307045, 0.0, 0.0, 0.0, 0.10515247108307045, 0.0, 0.0, 0.0,
    8.6206896551724128 },

  //  Variable: invT
  //  Referenced by: '<S16>/Gain3'

  { 10.0, 0.0, 0.0, 0.0, 10.0, 0.0, 0.0, 0.0, 10.0 },

  //  Variable: invThrustAloc
  //  Referenced by: '<S7>/Inverse thrust allocation Matrix'

  { -2.2204460492503131E-16, 0.577350269189626, -0.57735026918962562,
    0.66666666666666652, -0.33333333333333326, -0.33333333333333337,
    2.426889940541197, 2.4268899405411961, 2.4268899405411966 },

  //  Variable: wni
  //  Referenced by: '<S6>/w_n'

  { 0.89442719099991586, 0.0, 0.0, 0.0, 0.89442719099991586, 0.0, 0.0, 0.0,
    1.0488088481701516 },

  //  Variable: wniCeta2
  //  Referenced by: '<S6>/ciwni'

  { 1.4310835055998654, 0.0, 0.0, 0.0, 1.4310835055998654, 0.0, 0.0, 0.0,
    1.6780941570722427 },

  //  Variable: wnisquared
  //  Referenced by:
  //    '<S6>/w_n1'
  //    '<S6>/w_n2'

  { 0.79999999999999993, 0.0, 0.0, 0.0, 0.79999999999999993, 0.0, 0.0, 0.0, 1.1
  },

  {
    0.0,                               // X
    0.0,                               // Y
    0.0                                // Z
  },                                   // Computed Parameter: Out1_Y0
                                       //  Referenced by: '<S24>/Out1'


  {
    0.0,                               // X
    0.0,                               // Y
    0.0                                // Z
  },                                   // Computed Parameter: Constant_Value
                                       //  Referenced by: '<S23>/Constant'


  {
    0.0,                               // X
    0.0,                               // Y
    0.0                                // Z
  },                                   // Computed Parameter: Out1_Y0_d
                                       //  Referenced by: '<S26>/Out1'


  {
    0.0,                               // X
    0.0,                               // Y
    0.0                                // Z
  },                                   // Computed Parameter: Constant_Value_k
                                       //  Referenced by: '<S25>/Constant'


  {
    0.0,                               // X
    0.0,                               // Y
    0.0                                // Z
  },                                   // Computed Parameter: Constant_Value_f
                                       //  Referenced by: '<S17>/Constant'


  //  Expression: zeros(3,1)
  //  Referenced by: '<S7>/Constant'

  { 0.0, 0.0, 0.0 },
  0.0,                                 // Expression: 0
                                       //  Referenced by: '<S16>/Integrator1'


  //  Expression: [0;0;0]
  //  Referenced by: '<S6>/Integrator2'

  { 0.0, 0.0, 0.0 },

  //  Expression: [.7 0 0 ;0 0.7 0;0 0 0.1]
  //  Referenced by: '<S1>/Gain2'

  { 0.7, 0.0, 0.0, 0.0, 0.7, 0.0, 0.0, 0.0, 0.1 },

  //  Expression: [0;0;0]
  //  Referenced by: '<S1>/Integrator1'

  { 0.0, 0.0, 0.0 },

  //  Expression: [1;1;1]
  //  Referenced by: '<S1>/Integrator1'

  { 1.0, 1.0, 1.0 },

  //  Expression: [-1;-1;-1]
  //  Referenced by: '<S1>/Integrator1'

  { -1.0, -1.0, -1.0 },

  //  Expression:  [1 0 0;0 1 0; 0 0 0.05]
  //  Referenced by: '<S1>/Gain'

  { 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.05 },
  0.4,                                 // Expression: 0.4
                                       //  Referenced by: '<S7>/Thrust Sat'


  //  Expression: [1;1;0.5]*3
  //  Referenced by: '<S7>/Gain'

  { 3.0, 3.0, 1.5 },
  1.0,                                 // Expression: 1
                                       //  Referenced by: '<S7>/Saturation1'

  -1.0,                                // Expression: -1
                                       //  Referenced by: '<S7>/Saturation1'

  1.0,                                 // Expression: 1
                                       //  Referenced by: '<S7>/Saturation2'

  -1.0,                                // Expression: -1
                                       //  Referenced by: '<S7>/Saturation2'

  0.05,                                // Expression: 0.05
                                       //  Referenced by: '<S7>/Saturation3'

  -0.05,                               // Expression: -0.05
                                       //  Referenced by: '<S7>/Saturation3'

  4.0,                                 // Expression: 4
                                       //  Referenced by: '<S7>/Saturation5'

  -4.0,                                // Expression: -4
                                       //  Referenced by: '<S7>/Saturation5'

  4.0,                                 // Expression: 4
                                       //  Referenced by: '<S7>/Saturation6'

  -4.0,                                // Expression: -4
                                       //  Referenced by: '<S7>/Saturation6'

  4.0,                                 // Expression: 4
                                       //  Referenced by: '<S7>/Saturation7'

  -4.0,                                // Expression: -4
                                       //  Referenced by: '<S7>/Saturation7'

  0.1,                                 // Expression: 0.1
                                       //  Referenced by: '<S2>/Constant7'

  0.0,                                 // Expression: 0
                                       //  Referenced by: '<S2>/Constant8'

  0.0,                                 // Expression: 0
                                       //  Referenced by: '<S2>/Constant9'


  //  Expression: [0;0;0]
  //  Referenced by: '<S16>/Integrator2'

  { 0.0, 0.0, 0.0 },

  //  Expression: [0;0;0]
  //  Referenced by: '<S6>/Integrator'

  { 0.0, 0.0, 0.0 },

  //  Expression: [0 ;0; 0]
  //  Referenced by: '<S6>/Integrator1'

  { 0.0, 0.0, 0.0 },
  0.047263,                            // Expression: 0.047263
                                       //  Referenced by: '<Root>/Pwm1'

  0.083578,                            // Expression: 0.083578
                                       //  Referenced by: '<Root>/PWm3'

  0.06542,                             // Expression: 0.06542
                                       //  Referenced by: '<Root>/PWm4'


  {
    0.0                                // Data
  },                                   // Computed Parameter: Constant_Value_hl
                                       //  Referenced by: '<S12>/Constant'


  {
    0U                                 // Data
  },                                   // Computed Parameter: Constant_Value_b
                                       //  Referenced by: '<S28>/Constant'


  {
    0U                                 // Data
  },                                   // Computed Parameter: Constant_Value_c
                                       //  Referenced by: '<S35>/Constant'


  {
    false                              // Data
  },                                   // Computed Parameter: Out1_Y0_p
                                       //  Referenced by: '<S34>/Out1'


  {
    false                              // Data
  },                                   // Computed Parameter: Constant_Value_j
                                       //  Referenced by: '<S33>/Constant'

  80U,                                 // Computed Parameter: Constant_Value_n
                                       //  Referenced by: '<S8>/Constant'

  80U,                                 // Computed Parameter: Constant1_Value
                                       //  Referenced by: '<S8>/Constant1'

  80U,                                 // Computed Parameter: Constant2_Value
                                       //  Referenced by: '<S8>/Constant2'

  0U,                                  // Computed Parameter: ManualSwitch_CurrentSetting
                                       //  Referenced by: '<S7>/Manual Switch'

  1U                                   // Computed Parameter: ManualSwitch1_CurrentSetting
                                       //  Referenced by: '<S2>/Manual Switch1'

};

//
// File trailer for generated code.
//
// [EOF]
//
