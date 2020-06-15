#include "LaplaceYoungSource.h"

registerMooseObject("workshop_exampleApp", LaplaceYoungSource);

InputParameters
LaplaceYoungSource::validParams()
{
  auto params = ADKernelValue::validParams();
  params.addParam<Real>("kappa", 1, "The coefficient $\\kappa$ of source term");
  params.addClassDescription(
      "Compute the source term for Laplace Young equation: "
      "$-\\nabla \\cdot \\left ( k \\left(u\\right) \\nabla u \\right) + \\kappa u = 0$");
  return params;
}

LaplaceYoungSource::LaplaceYoungSource(const InputParameters & parameters)
  : ADKernelValue(parameters), _kappa(getParam<Real>("kappa"))
{
}

ADReal
LaplaceYoungSource::precomputeQpResidual()
{
  return _kappa * _u[_qp];
}
