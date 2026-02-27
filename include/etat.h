#pragma once

#include <string>
#include "symbole.h"
#include "automate.h"

using namespace std;


class Etat {
   public:
   Etat(string name);
   Etat();
   virtual ~Etat();
   void print() const;
   virtual bool transition(Automate & automate, Symbole * s) = 0;
   protected:
   string name;
};



