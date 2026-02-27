#pragma once

#include <string>
#include "symbole.h"
#include "automate.h"
using namespace std;



class Etat3 : public Etat {
   public:
   Etat3(string name);
   Etat3();
   virtual ~Etat3();
   void print() const;
   bool transition(Automate & automate, Symbole * s);
   protected:
   string name;
};



