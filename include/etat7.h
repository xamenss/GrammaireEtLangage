#pragma once

#include <string>
#include "etat.h"
class Automate;
class Symbole;
using namespace std;



class Etat7 : public Etat {
   public:
   Etat7(string name);
   Etat7();
   virtual ~Etat7();
   void print() const;
   bool transition(Automate & automate, Symbole * s);
   protected:
   string name;
};



