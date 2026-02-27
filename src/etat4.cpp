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

Etat4::Etat4(string name) : name(name) {
}

bool Etat4::transition(Automate & automate, Symbole * s) {
   switch (*s){
   case INT:
      automate.decalage(s, new Etat4);
      break;
   case OPENPAR:
      automate.decalage(s, new Etat2);
      break;
   case ERREUR:
      //automate.decalage(s, new Etat6);
      break;
   default:
      cout<<"Erreur de syntaxe"<<endl;
      break;
   }
   return false;
}