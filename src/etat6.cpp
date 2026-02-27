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

// enum Identificateurs { OPENPAR, CLOSEPAR, PLUS, MULT, INT, FIN, ERREUR };

// const string Etiquettes[] = { "OPENPAR", "CLOSEPAR", "PLUS", "MULT", "INT", "FIN", "ERREUR" };

Etat6::Etat6(string name) : name(name) {
}

bool Etat6::transition(Automate & automate, Symbole * s) {
   switch (*s){
   case PLUS:
      automate.decalage(s, new Etat4);
      break;
   case MULT:
      automate.decalage(s, new Etat5);
      break;
   case CLOSEPAR:
      automate.decalage(s, new Etat9);
      break;
   
   default:
      cout<<"Erreur de syntaxe"<<endl;
      automate.erreur_();
      break;
   }
   return false;
}