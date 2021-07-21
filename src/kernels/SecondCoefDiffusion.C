//* Alan Chavez
//* July 9 2021
//* Boise State University

#include "SecondCoefDiffusion.h"

registerMooseObject("chsplitApp", SecondCoefDiffusion);

InputParameters
SecondCoefDiffusion::validParams()
{
  InputParameters params = SecondCoefDiffusionBase<Real>::validParams();
  params.addClassDescription("Poisson EQ including material property");
  return params;
}

SecondCoefDiffusion::SecondCoefDiffusion(const InputParameters & parameters) : SecondCoefDiffusionBase<Real>(parameters) {}
