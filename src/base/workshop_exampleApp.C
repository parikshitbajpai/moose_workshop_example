#include "workshop_exampleApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
workshop_exampleApp::validParams()
{
  InputParameters params = MooseApp::validParams();

  // Do not use legacy DirichletBC, that is, set DirichletBC default for preset = true
  params.set<bool>("use_legacy_dirichlet_bc") = false;

  return params;
}

workshop_exampleApp::workshop_exampleApp(InputParameters parameters) : MooseApp(parameters)
{
  workshop_exampleApp::registerAll(_factory, _action_factory, _syntax);
}

workshop_exampleApp::~workshop_exampleApp() {}

void
workshop_exampleApp::registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ModulesApp::registerAll(f, af, s);
  Registry::registerObjectsTo(f, {"workshop_exampleApp"});
  Registry::registerActionsTo(af, {"workshop_exampleApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
workshop_exampleApp::registerApps()
{
  registerApp(workshop_exampleApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
workshop_exampleApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  workshop_exampleApp::registerAll(f, af, s);
}
extern "C" void
workshop_exampleApp__registerApps()
{
  workshop_exampleApp::registerApps();
}
