#pragma once

#include <string>
#include "symbole.h"
#include "automate.h"
using namespace std;

enum Identificateurs { OPENPAR, CLOSEPAR, PLUS, MULT, INT, FIN, ERREUR };

const string Etiquettes[] = { "OPENPAR", "CLOSEPAR", "PLUS", "MULT", "INT", "FIN", "ERREUR" };

class Etat1 {
   public:
   Etat1(string name);
   virtual ~Etat1();
   void print() const;
   virtual bool transition(Automate & automate, Symbole * s) = 0;
   protected:
   string name;
};



