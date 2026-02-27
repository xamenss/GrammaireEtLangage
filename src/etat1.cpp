#include "etat1.h"
#include "symbole.h"
#include "automate.h"
#include <iostream>

// enum Identificateurs { OPENPAR, CLOSEPAR, PLUS, MULT, INT, FIN, ERREUR };

// const string Etiquettes[] = { "OPENPAR", "CLOSEPAR", "PLUS", "MULT", "INT", "FIN", "ERREUR" };

Etat1::Etat1(string name) : name(name) {
}

bool Etat1::transition(Automate & automate, Symbole * s) {
   switch (*s){
   case PLUS:
      automate.decalage(s, new Etat4);
      break;
   case MULT:
      automate.decalage(s, new Etat5);
      break;
   case FIN:
      automate.decalage(s, new Etat10);
      break;
   case default:
      cout<<"Erreur de syntaxe"<<endl;
      break;
   }
   return false;
}