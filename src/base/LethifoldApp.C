#include "LethifoldApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

template<>
InputParameters validParams<LethifoldApp>()
{
  InputParameters params = validParams<MooseApp>();

  params.set<bool>("use_legacy_uo_initialization") = false;
  params.set<bool>("use_legacy_uo_aux_computation") = false;
  params.set<bool>("use_legacy_output_syntax") = false;

  return params;
}

LethifoldApp::LethifoldApp(InputParameters parameters) :
    MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  LethifoldApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  LethifoldApp::associateSyntax(_syntax, _action_factory);
}

LethifoldApp::~LethifoldApp()
{
}

// External entry point for dynamic application loading
extern "C" void LethifoldApp__registerApps() { LethifoldApp::registerApps(); }
void
LethifoldApp::registerApps()
{
  registerApp(LethifoldApp);
}

// External entry point for dynamic object registration
extern "C" void LethifoldApp__registerObjects(Factory & factory) { LethifoldApp::registerObjects(factory); }
void
LethifoldApp::registerObjects(Factory & factory)
{
}

// External entry point for dynamic syntax association
extern "C" void LethifoldApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory) { LethifoldApp::associateSyntax(syntax, action_factory); }
void
LethifoldApp::associateSyntax(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
}
