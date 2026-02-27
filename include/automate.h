#pragma once

#include <string>
using namespace std;

enum Identificateurs { OPENPAR, CLOSEPAR, PLUS, MULT, INT, FIN, ERREUR };

const string Etiquettes[] = { "OPENPAR", "CLOSEPAR", "PLUS", "MULT", "INT", "FIN", "ERREUR" };

class Automate {
   public:
      Automate() {  }
      virtual ~Automate() { }
      operator int() const { return ; }
      virtual void decalage(Symbole * s, Etat1 * e);

   protected:
};


