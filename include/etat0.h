#pragma once

#include <string>
#include "etat.h"
#include "symbole.h"
#include "automate.h"
using namespace std;



class Etat0 : public Etat {
   public:
   Etat0(string name);
   Etat0();
   virtual ~Etat0();
   void print() const;
   bool transition(Automate & automate, Symbole * s);
   protected:
   string name;
};



