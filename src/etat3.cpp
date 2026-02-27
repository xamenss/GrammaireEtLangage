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

Etat3::Etat3(string name) : name(name) {
}

bool Etat3::transition(Automate & automate, Symbole * s) {
   switch (*s){
   case PLUS:
      Expr * s1 = (Expr*) automate.popSymbol();
      automate.popAndDestroySymbol();
      Expr * s2 = (Expr*) automate.popSymbol();
      int valeur = s1->getValeur() + s2->getValeur();
      Expr * s3 = new Expr(valeur);
      automate.reduction(3, s3);
      break;
   case MULT:
      Expr * s1 = (Expr*) automate.popSymbol();
      automate.popAndDestroySymbol();
      Expr * s2 = (Expr*) automate.popSymbol();
      int valeur = s1->getValeur() * s2->getValeur();
      Expr * s3 = new Expr(valeur);
      automate.reduction(3, s3);
      break;
   case CLOSEPAR:
      automate.popAndDestroySymbol();
      Expr * s1 = (Expr*) automate.popSymbol();
      Symbole * s2 = automate.popAndDestroySymbol();
      Expr * s3 = (Expr*) automate.popSymbol();
      automate.popAndDestroySymbol();
      int valeur;
      if (s2->getEtiquette() == PLUS) {
         valeur = s1->getValeur() + s3->getValeur();
      } else if (s2->getEtiquette() == MULT) {
         valeur = s1->getValeur() * s3->getValeur();
      } else {
         cout<<"Erreur de syntaxe"<<endl;
         automate.erreur_();
         return false;
      }
      Expr * s4 = new Expr(valeur);
      automate.reduction(5, s4);
      break;
   case FIN:
      automate.popAndDestroySymbol();
      automate.reduction(1, new Expr(0));
      break;
   default:
      cout<<"Erreur de syntaxe"<<endl;
      automate.erreur_();
      break;
   }
   return false;
}