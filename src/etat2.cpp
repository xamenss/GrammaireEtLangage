#include "etat1.h"
#include "etat2.h"
#include "etat.h"
#include "symbole.h"
#include "automate.h"
#include <iostream>

// enum Identificateurs { OPENPAR, CLOSEPAR, PLUS, MULT, INT, FIN, ERREUR };

// const string Etiquettes[] = { "OPENPAR", "CLOSEPAR", "PLUS", "MULT", "INT", "FIN", "ERREUR" };

Etat2::Etat2(string name) : name(name) {
}

bool Etat1::transition(Automate & automate, Symbole * s) {
   switch (*s){
   case INT:
      automate.decalage(s, new Etat3);
      break;
   case OPENPAR:
      automate.decalage(s, new Etat2);
      break;
   case ERREUR:
      //automate.decalage(s, new Etat6);
      break;
   case default:
      cout<<"Erreur de syntaxe"<<endl;
      break;
   }
   return false;
}