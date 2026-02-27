#pragma once

#include "symbole.h"
#include "etat.h"
#include <iostream>

using namespace std;

enum Identificateurs { OPENPAR, CLOSEPAR, PLUS, MULT, INT, FIN, ERREUR };

const string Etiquettes[] = { "OPENPAR", "CLOSEPAR", "PLUS", "MULT", "INT", "FIN", "ERREUR" };

class Automate {
   public:
      Automate() {  }
      virtual ~Automate() { }
      operator int() const { return ; }
      virtual void decalage(Symbole * s, Etat * e);
      virtual void reduction(int n, Symbole * s);

   protected:
};


