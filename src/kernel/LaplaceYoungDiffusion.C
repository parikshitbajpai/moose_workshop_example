#include "LaplaceYoungDiffusion.h"

registerMooseObject("workshop_exampleApp", LaplaceYoungDiffusion);

InputParameters
LaplaceYoungDiffusion::validParams()
{
  auto params = ADKernelGrad::validParams();
  params.addClassDescription(
      "Compute the diffusion term for Laplace Young equation: "
      "$-\\nabla \\cdot \\left ( k \\left(u\\right) \\nabla u \\right) + \\kappa u = 0$");
  return params;
}

LaplaceYoungDiffusion::LaplaceYoungDiffusion(const InputParameters & parameters)
  : ADKernelGrad(parameters)
{
}

ADRealVectorValue
LaplaceYoungDiffusion::precomputeQpResidual()
{
  ADReal k = 1. / std::sqrt(1 + _grad_u[_qp] * _grad_u[_qp]);
  return k * _grad_u[_qp];
}
