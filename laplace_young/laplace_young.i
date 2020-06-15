[Mesh]
  type = GeneratedMesh
  dim = 2
  nx = 20
  ny = 20
[]

[Variables]
  [u]
  []
[]

[Kernels]
  [diffusion]
    type = LaplaceYoungDiffusion
    variable = u
  []
  [source]
    type = LaplaceYoungSource
    variable = u
    kappa = 0.9
  []
[]

[BCs]
  [all]
    type = ADNeumannBC
    variable = u
    value = 0.2
    boundary = "0 1 2 3"
  []
[]

[Executioner]
  type = Steady
  solve_type = NEWTON
  petsc_options_iname = '-pc_type'
  petsc_options_value = 'lu'
[]

[Outputs]
  exodus = true
[]
