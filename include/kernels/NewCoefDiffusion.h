//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html

#pragma once

#include "Kernel.h"
#include "Function.h"
#include "DerivativeMaterialInterface.h"

class NewCoefDiffusion : public Kernel
{
public:
  static InputParameters validParams();

  NewCoefDiffusion(const InputParameters & parameters);

protected:
  virtual Real computeQpResidual();
  virtual Real computeQpJacobian();

private:
//  const Real _coef;
//  const Function * const _func
  const MaterialProperty<Real> & _m;
};
