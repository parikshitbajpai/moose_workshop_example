#pragma once

// Including the "ADKernel" Kernel here so we can extend it
#include "ADKernel.h"

/**
 * Computes the residual contribution: K / mu * grad_u * grad_phi.
 *
 * We are inheriting from ADKernel instead of from ADKernel because
 * the grad_u * grad_phi is already coded and all that is
 * needed is to specialize that calculation by multiplying by K / mu.
 */
class DarcyPressure : public ADKernel
{
public:
  static InputParameters validParams();

  DarcyPressure(const InputParameters & parameters);

protected:
  /// ADKernelGrad objects must override precomputeQpResidual
  virtual ADReal computeQpResidual() override;

  /// References to be set from input file
  const Real & _permeability;
  const Real & _viscosity;
};
