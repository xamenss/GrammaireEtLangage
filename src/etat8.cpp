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

Etat8::Etat8(string name) : name(name) {
}

bool Etat8::transition(Automate & automate, Symbole * s) {
   switch (*s){
   case PLUS: {
      Expr * s1 = (Expr*) automate.popSymbol();
      automate.popAndDestroySymbol();
      Expr * s2 = (Expr*) automate.popSymbol();
      int valeur = s1->getValeur() * s2->getValeur();
      Expr * s3 = new Expr(valeur);
      automate.reduction(3, s3);
      break;
   }
   case MULT: {
      Expr * s1 = (Expr*) automate.popSymbol();
      automate.popAndDestroySymbol();
      Expr * s2 = (Expr*) automate.popSymbol();
      int valeur = s1->getValeur() * s2->getValeur();
      Expr * s3 = new Expr(valeur);
      automate.reduction(3, s3);
      break;
   }
   case CLOSEPAR: {
      Expr * s1 = (Expr*) automate.popSymbol();
      automate.popAndDestroySymbol();
      Expr * s2 = (Expr*) automate.popSymbol();
      int valeur = s1->getValeur() * s2->getValeur();
      Expr * s3 = new Expr(valeur);
      automate.reduction(3, s3);
      break;
   }
   case FIN: {
      Expr * s1 = (Expr*) automate.popSymbol();
      automate.popAndDestroySymbol();
      Expr * s2 = (Expr*) automate.popSymbol();
      int valeur = s1->getValeur() * s2->getValeur();
      Expr * s3 = new Expr(valeur);
      automate.reduction(3, s3);
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