#ifndef LETHIFOLDAPP_H
#define LETHIFOLDAPP_H

#include "MooseApp.h"

class LethifoldApp;

template<>
InputParameters validParams<LethifoldApp>();

class LethifoldApp : public MooseApp
{
public:
  LethifoldApp(InputParameters parameters);
  virtual ~LethifoldApp();

  static void registerApps();
  static void registerObjects(Factory & factory);
  static void associateSyntax(Syntax & syntax, ActionFactory & action_factory);
};

#endif /* LETHIFOLDAPP_H */
