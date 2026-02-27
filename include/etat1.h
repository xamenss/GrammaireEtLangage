#pragma once

#include <string>
#include "etat.h"

using namespace std;
class Automate;
class Symbole;


class Etat1 : public Etat {
   public:
   Etat1(string name);
   Etat1(){};
   virtual ~Etat1();
   void print() const;
   bool transition(Automate & automate, Symbole * s);
   protected:
   string name;
};



