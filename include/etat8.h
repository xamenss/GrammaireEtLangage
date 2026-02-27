#pragma once

#include <string>
#include "etat.h"
#include "symbole.h"
#include "automate.h"
using namespace std;



class Etat8 : public Etat {
   public:
   Etat8(string name);
   Etat8();
   virtual ~Etat8();
   void print() const;
   bool transition(Automate & automate, Symbole * s);
   protected:
   string name;
};



