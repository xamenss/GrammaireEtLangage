#pragma once

#include <string>
#include "etat.h"

using namespace std;

class Automate;
class Symbole;

class Etat4 : public Etat {
   public:
   Etat4(string name);
   Etat4(){};
   ~Etat4(){};
   void print() const;
   bool transition(Automate & automate, Symbole * s);
   protected:
   string name;
};



