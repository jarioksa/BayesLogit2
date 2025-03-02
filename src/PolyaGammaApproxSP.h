// -*- mode: c++; -*-

#ifndef __POLYAGAMMAAPPROXSP__
#define __POLYAGAMMAAPPROXSP__


#include "simple_RNG_wrapper.h"
#include "truncated_norm.h"
#include "truncated_gamma.h"
#include "inverse_gaussian.h"
#include "PolyaGamma.h"

#include <cmath>
#include <vector>
#include <stdio.h>
#include <stdexcept>


// Function and derivative.
struct FD {
  double val;
  double der;
};

struct Line {
  double slope;
  double icept;
};


// PolyaGamma approximation by SP.
class PolyaGammaApproxSP
{

public:

  int draw(double& d, double h, double z, int max_iter=200);

protected:

  // Helper.
  
  double w_left (double trunc, double h, double z);
  double w_right(double trunc, double h, double z);

  void   delta_func(double x, double z  , FD& delta);
  double phi_func  (double x, double mid, FD& phi);
  
  double tangent_to_eta(double x, double z, double mid, Line& tl);

  double sp_approx(double x, double n, double z);

  double cos_rt(double v);

  // YV yv;

  double rtigauss(double mu, double lambda, double trunc);
  double y_func(double v); // y = tan(sqrt(v)) / sqrt(v);

};

//------------------------------------------------------------------------------

// double v_secant(double y, double vb, double va, double tol=1e-8, int maxiter=100);
// double v_func(double y);

#endif
