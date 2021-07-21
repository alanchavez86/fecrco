//* Alan Chavez
//* July 9, 2021
//* Boise State University

#pragma once

#include "SecondCoefDiffusionBase.h"

class SecondCoefDiffusion : public SecondCoefDiffusionBase<Real>
{
public:
  static InputParameters validParams();

  SecondCoefDiffusion(const InputParameters & parameters);
};
