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

Etat3::Etat3(string name) : name(name) {
}

bool Etat3::transition(Automate & automate, Symbole * s) {
   switch (*s){
   case PLUS:
      automate.reduction(5, s);
      break;
   case MULT:
      automate.reduction(5, s);
      break;
   case CLOSEPAR:
      automate.reduction(5, s);
      break;
   case FIN:
      automate.reduction(5, s);
      break;
   default:
      cout<<"Erreur de syntaxe"<<endl;
      break;
   }
   return false;
}