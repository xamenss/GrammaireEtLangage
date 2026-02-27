#pragma once

#include <string>
#include "etat.h"
#include "symbole.h"
#include "automate.h"
using namespace std;



class Etat9 : public Etat {
   public:
   Etat9(string name);
   Etat9();
   virtual ~Etat9();
   void print() const;
   bool transition(Automate & automate, Symbole * s);
   protected:
   string name;
};



