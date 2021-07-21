//* Alan Chavez & Nathan Sundquist
//* 29 June 2021
//* Magnetic Potential Custom Kernel
//*
//* Kernel helps calculate magnetic potential using the
//* Magnetization Saturation
//*
//*

#include "NewCoefDiffusion.h"

InputParameters
NewCoefDiffusion::validParams()
{
  InputParameters params = Kernel::validParams();
//  params.addParam<Real>("coef", 0.0, "Diffusion coefficient");
//  params.addParam<FunctionName>("function",
//                                "If provided, the diffusion coefficient will be coef + "
//                                "this function.  This is useful for temporally or "
//                                "spatially varying diffusivities");
  params.addClassDescription("Kernel for diffusion with diffusivity = coef + function");
  params.addRequiredParam<MaterialPropertyName>("m", "Base name of the Magnetization Saturation defined in a DertivativeParsedMaterial");
  return params;
}

NewCoefDiffusion::NewCoefDiffusion(const InputParameters & parameters)
  : DerivativeMaterialInterface<JvarMapKernelInterface<Kernel>>(parameters),
//    _coef(getParam<Real>("coef")),
//    _func(parameters.isParamValid("function") ? &getFunction("function") : NULL),
    _m(getMaterialProperty<Real>("m"))
// {
//  for (unsigned int i = 0; i < _n_args; ++i)
//    _dmobdarg[i] = &getMaterialPropertyDerivative<T>(_m_name, i);
// }


{
}

Real
NewCoefDiffusion::computeQpResidual()
{
//  Real diffusivity = _coef;

//  if (_func)
//    diffusivity += _func->value(_t, _q_point[_qp]);

  return _grad_test[_i][_qp] * -_grad_u[_qp] - _m[_qp]*_grad_test[_i][_qp];
}

Real
NewCoefDiffusion::computeQpJacobian()
{
//  Real diffusivity = _coef;

//  if (_func)
//    diffusivity += _func->value(_t, _q_point[_qp]);

  return _grad_test[_i][_qp] * -_grad_phi[_j][_qp] - _m[_qp]*_grad_test[_i][_qp];
}
