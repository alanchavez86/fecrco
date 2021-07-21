//* Alan Chavez
//* 29 June 2021
//* Magnetic Potential Custom Kernel
#pragma once

#include "Kernel.h"
#include "JvarMapInterface.h"
#include "DerivativeMaterialInterface.h"


template <typename T>
class SecondCoefDiffusionBase : public DerivativeMaterialInterface<JvarMapKernelInterface<Kernel>>
{
public:
  static InputParameters validParams();

  SecondCoefDiffusionBase(const InputParameters & parameters);

protected:
  virtual Real computeQpResidual();
  virtual Real computeQpJacobian();
  virtual Real computeQpWJacobian();
  virtual Real computeQpOffDiagJacobian(unsigned int jvar);

  const MaterialPropertyName _m_name;
  const MaterialProperty<T> & _m;

  std::vector<const MaterialProperty<T> *> _dmobdarg;
};

template <typename T>
SecondCoefDiffusionBase<T>::SecondCoefDiffusionBase(const InputParameters & parameters)
  : DerivativeMaterialInterface<JvarMapKernelInterface<Kernel>>(parameters),
    _m_name(getParam<MaterialPropertyName>("m_name")),
    _m(getMaterialProperty<T>("m_name"))
{
}

template <typename T>
Real
SecondCoefDiffusionBase<T>::computeQpResidual()
{
  return _grad_test[_i][_qp] * -_grad_u[_qp] - _m[_qp]*_grad_test[_i][_qp];
}

template <typename T>
Real
SecondCoefDiffusionBase<T>::computeQpJacobian()
{
  return _grad_test[_i][_qp] * -_grad_phi[_j][_qp] - _m[_qp]*_grad_test[_i][_qp];
}

template <typename T>
InputParameters
SecondCoefDiffusionBase<T>::validParams()
{
  InputParameters params = Kernel::validParams();
  params.addClassDescription("Magnetic Potential with Magnetization Saturation Input");
  params.addParam<MaterialPropertyName>("m_name", "m","magnetization saturation used in the kernel");

  return params;
}
