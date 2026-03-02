#include "etat0.h"
#include "etat1.h"
#include "etat2.h"
#include "etat3.h"
#include "etat4.h"
#include "etat5.h"
#include "etat6.h"
#include "etat7.h"
#include "etat8.h"
#include "etat9.h"
#include "etat.h"
#include "symbole.h"
#include "automate.h"
#include <iostream>

// enum Identificateurs { OPENPAR, CLOSEPAR, PLUS, MULT, INT, FIN, EXPR };

// const string Etiquettes[] = { "OPENPAR", "CLOSEPAR", "PLUS", "MULT", "INT", "FIN", "EXPR" };

// Etat0::Etat0(string name) : name(name) {
// }

bool Etat0::transition(Automate & automate, Symbole * s) {
   cout<<"Etat0"<<endl;
   switch (*s){
   case INT: {
      automate.decalage(s, new Etat3);
      break;
   }
   case OPENPAR: {
      automate.decalage(s, new Etat2);
      break;
   }
   case EXPR: {
      automate.transitionsimple(s, new Etat1);
      break;
   }
   default: {
      cout<<"Erreur de syntaxe0"<<endl;
      automate.erreur_();
      break;
   }
   }
   return false;
}

void Etat0::print() const {
   cout<<"Etat 0"<<endl;
}