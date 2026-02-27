#pragma once

#include <string>
#include "etat.h"
#include "symbole.h"
#include "automate.h"
using namespace std;



class Etat6 : public Etat {
   public:
   Etat6(string name);
   Etat6();
   virtual ~Etat6();
   void print() const;
   bool transition(Automate & automate, Symbole * s);
   protected:
   string name;
};



