#pragma once

#include <string>
#include "etat.h"

using namespace std;

class Automate;
class Symbole;

class Etat5 : public Etat {
   public:
   Etat5(string name);
   Etat5();
   virtual ~Etat5();
   void print() const;
   bool transition(Automate & automate, Symbole * s);
   protected:
   string name;
};



