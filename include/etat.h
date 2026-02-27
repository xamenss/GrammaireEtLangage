#pragma once

#include <string>


using namespace std;
class Automate;
class Symbole;

class Etat {
   public:
   Etat(string name);
   Etat() = default;
   virtual ~Etat() = default;
   void print() const;
   virtual bool transition(Automate & automate, Symbole * s) = 0;
   protected:
   string name;
};



