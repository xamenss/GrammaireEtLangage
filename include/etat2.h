#pragma once

#include <string>
#include "etat.h"

using namespace std;
class Automate;
class Symbole;


class Etat2 : public Etat {
   public:
   Etat2(string name);
   Etat2();
   virtual ~Etat2();
   void print() const;
   bool transition(Automate & automate, Symbole * s);
   protected:
   string name;
};



