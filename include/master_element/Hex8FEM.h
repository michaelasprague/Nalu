/*------------------------------------------------------------------------*/
/*  Copyright 2014 Sandia Corporation.                                    */
/*  This software is released under the license detailed                  */
/*  in the file, LICENSE, which is located in the top-level Nalu          */
/*  directory structure                                                   */
/*------------------------------------------------------------------------*/


#ifndef Hex8FEM_h
#define Hex8FEM_h

#include<master_element/MasterElement.h>

namespace sierra{
namespace nalu{

// Hex 8 FEM; -1.0 : 1.0 range
class Hex8FEM : public MasterElement
{
public:

  Hex8FEM();
  virtual ~Hex8FEM();

  void grad_op(
    const int nelem,
    const double *coords,
    double *gradop,
    double *deriv,
    double *det_j,
    double * error );

  void face_grad_op(
    const int nelem,
    const int face_ordinal,
    const double *coords,
    double *gradop,
    double *det_j,
    double *error);

  void general_shape_fcn(
    const int numIp,
    const double *isoParCoord,
    double *shpfc);

  void shape_fcn(
    double *shpfc);

private:

  void hex8_fem_shape_fcn(
    const int  &numIp,
    const double *isoParCoord,
    double *shpfc);

  void hex8_fem_derivative(
    const int npt, const double* par_coord,
    double* deriv);

};
    
} // namespace nalu
} // namespace Sierra

#endif
