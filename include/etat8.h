#pragma once

#include <string>
#include "etat.h"
class Automate;
class Symbole;
using namespace std;



class Etat8 : public Etat {
   public:
   Etat8(string name);
   Etat8(){};
   virtual ~Etat8();
   void print() const;
   bool transition(Automate & automate, Symbole * s);
   protected:
   string name;
};



