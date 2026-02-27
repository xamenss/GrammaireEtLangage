#pragma once

#include <string>
#include "etat.h"
#include "symbole.h"
#include "automate.h"
using namespace std;



class Etat4 : public Etat {
   public:
   Etat4(string name);
   Etat4();
   virtual ~Etat4();
   void print() const;
   bool transition(Automate & automate, Symbole * s);
   protected:
   string name;
};



