//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "workshop_exampleTestApp.h"
#include "workshop_exampleApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

InputParameters
workshop_exampleTestApp::validParams()
{
  InputParameters params = workshop_exampleApp::validParams();
  return params;
}

workshop_exampleTestApp::workshop_exampleTestApp(InputParameters parameters) : MooseApp(parameters)
{
  workshop_exampleTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

workshop_exampleTestApp::~workshop_exampleTestApp() {}

void
workshop_exampleTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  workshop_exampleApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"workshop_exampleTestApp"});
    Registry::registerActionsTo(af, {"workshop_exampleTestApp"});
  }
}

void
workshop_exampleTestApp::registerApps()
{
  registerApp(workshop_exampleApp);
  registerApp(workshop_exampleTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
workshop_exampleTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  workshop_exampleTestApp::registerAll(f, af, s);
}
extern "C" void
workshop_exampleTestApp__registerApps()
{
  workshop_exampleTestApp::registerApps();
}
