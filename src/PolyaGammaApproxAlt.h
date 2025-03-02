#ifndef __POLYAGAMMAALT__
#define __POLYAGAMMAALT__

#include "simple_RNG_wrapper.h"
#include "truncated_norm.h"
#include "truncated_gamma.h"
#include "inverse_gaussian.h"
#include "PolyaGamma.h"

#include <cmath>
#include <vector>
#include <stdio.h>
#include <stdexcept>

// The numerical accuracy of __PI will affect your distribution.
// const double __PI = 3.141592653589793238462643383279502884197;
const double PISQ = __PI * __PI;
const double HALFPI = 0.5 * __PI;
// const double HALFPISQ = 0.5 * __PI * __PI;
// const double FOURPISQ = 4 * __PI * __PI;

const double trunc_schedule[] = { // seq(1,4,by=0.01) -> 301 entries.
0.64, 0.68, 0.72, 0.75, 0.78, 0.8, 0.83, 0.85, 0.87, 0.89, 
0.91, 0.93, 0.95, 0.96, 0.98,   1, 1.01, 1.03, 1.04, 1.06, 
1.07, 1.09,  1.1, 1.12, 1.13, 1.15, 1.16, 1.17, 1.19,  1.2,
1.21, 1.23, 1.24, 1.25, 1.26, 1.28, 1.29,  1.3, 1.32, 1.33,
1.34, 1.35, 1.36, 1.38, 1.39,  1.4, 1.41, 1.42, 1.44, 1.45, 
1.46, 1.47, 1.48,  1.5, 1.51, 1.52, 1.53, 1.54, 1.55, 1.57, 
1.58, 1.59,  1.6, 1.61, 1.62, 1.63, 1.65, 1.66, 1.67, 1.68, 
1.69,  1.7, 1.71, 1.72, 1.74, 1.75, 1.76, 1.77, 1.78, 1.79, 
1.8 , 1.81, 1.82, 1.84, 1.85, 1.86, 1.87, 1.88, 1.89, 1.9, 
1.91, 1.92, 1.93, 1.95, 1.96, 1.97, 1.98, 1.99,    2, 2.01, 
2.02, 2.03, 2.04, 2.05, 2.07, 2.08, 2.09,  2.1, 2.11, 2.12, 
2.13, 2.14, 2.15, 2.16, 2.17, 2.18, 2.19, 2.21, 2.22, 2.23, 
2.24, 2.25, 2.26, 2.27, 2.28, 2.29,  2.3, 2.31, 2.32, 2.33, 
2.35, 2.36, 2.37, 2.38, 2.39,  2.4, 2.41, 2.42, 2.43, 2.44, 
2.45, 2.46, 2.47, 2.48, 2.49, 2.51, 2.52, 2.53, 2.54, 2.55, 
2.56, 2.57, 2.58, 2.59,  2.6, 2.61, 2.62, 2.63, 2.64, 2.65, 
2.66, 2.68, 2.69,  2.7, 2.71, 2.72, 2.73, 2.74, 2.75, 2.76, 
2.77, 2.78, 2.79,  2.8, 2.81, 2.82, 2.83, 2.84, 2.85, 2.87, 
2.88, 2.89,  2.9, 2.91, 2.92, 2.93, 2.94, 2.95, 2.96, 2.97, 
2.98, 2.99,    3, 3.01, 3.02, 3.03, 3.04, 3.06, 3.07, 3.08, 
3.09,  3.1, 3.11, 3.12, 3.13, 3.14, 3.15, 3.16, 3.17, 3.18, 
3.19,  3.2, 3.21, 3.22, 3.23, 3.24, 3.25, 3.27, 3.28, 3.29, 
 3.3, 3.31, 3.32, 3.33, 3.34, 3.35, 3.36, 3.37, 3.38, 3.39, 
 3.4, 3.41, 3.42, 3.43, 3.44, 3.45, 3.46, 3.47, 3.49,  3.5, 
3.51, 3.52, 3.53, 3.54, 3.55, 3.56, 3.57, 3.58, 3.59,  3.6, 
3.61, 3.62, 3.63, 3.64, 3.65, 3.66, 3.67, 3.68, 3.69, 3.71, 
3.72, 3.73, 3.74, 3.75, 3.76, 3.77, 3.78, 3.79,  3.8, 3.81, 
3.82, 3.83, 3.84, 3.85, 3.86, 3.87, 3.88, 3.89,  3.9, 3.91, 
3.92, 3.93, 3.95, 3.96, 3.97, 3.98, 3.99,    4, 4.01, 4.02, 
4.03, 4.04, 4.05, 4.06, 4.07, 4.08, 4.09,  4.1, 4.11, 4.12, 4.13};

//------------------------------------------------------------------------------

class PolyaGammaApproxAlt
{

 public:

  // Draw.
  double draw(double h, double z, int max_inner=200);
  double draw_abridged(double h, double z, int max_inner=200);

  // Helper.
  double a_coef(int n, double x, double h);
  double a_coef_recursive(double n, double x, double h, double coef_h, double& gamma_nh_over_n);
  double g_tilde(double x, double h, double trunc);
  double pigauss(double x, double Z, double lambda);

  double rtigauss(double h, double z, double trunc);
  double w_left (double trunc, double h, double z);
  double w_right(double trunc, double h, double z);

};

// double rtinvchi2(double h, double trunc);

#endif
