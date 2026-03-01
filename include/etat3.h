#pragma once

#include <string>
#include "etat.h"

using namespace std;
class Automate;
class Symbole;


class Etat3 : public Etat {
   public:
   Etat3(string name);
   Etat3(){};
   ~Etat3(){};
   void print() const;
   bool transition(Automate & automate, Symbole * s);
   protected:
   string name;
};



