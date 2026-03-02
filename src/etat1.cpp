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

// Etat1::Etat1() : name(name) {
// }

bool Etat1::transition(Automate & automate, Symbole * s) {
   // cout<<"Etat1"<<endl;
   // cout<<"sa:" << s->getEtiquette()<<endl;
   switch (*s){
   case PLUS: {
      automate.decalage(s, new Etat4);
      break;
   }
   case MULT: {
      automate.decalage(s, new Etat5);
      break;
   }
   case FIN: {
      cout<<"Expression correcte" << endl;
      automate.fin_();
      return true;
      break;
   }
   default: {
      cout<<"Erreur de syntaxe"<<endl;
      automate.erreur_();
      break;
   }
   }
   return false;
}

void Etat1::print() const {
   cout<<"Etat 1"<<endl;
}