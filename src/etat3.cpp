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

// Etat3::Etat3(string name) : name(name) {
// }

bool Etat3::transition(Automate & automate, Symbole * s) {
   // cout<<"Etat3:"<<endl;
   // cout<<"sa:" << s->getEtiquette()<<endl;
   switch (*s){
      
   case PLUS: {
      Symbole * s1 =  automate.popSymbol();
      int valeur =((Entier*) s1)->getValeur();
      cout << valeur << endl;
      Expr * s3 = new Expr(valeur);
      automate.reduction(1, s3);
      break;
   }
   case MULT: {
      Symbole * s1 =  automate.popSymbol();
      int valeur =((Entier*) s1)->getValeur();
       cout << valeur << endl;
      Expr * s3 = new Expr(valeur);
      automate.reduction(1, s3);
      break;
   }
   case CLOSEPAR: {
      Symbole * s1 =  automate.popSymbol();
      int valeur =((Entier*) s1)->getValeur();
      Expr * s3 = new Expr(valeur);
      automate.reduction(1, s3);
      break;
   }
   case FIN: {
      Symbole * s1 =  automate.popSymbol();
      int valeur =((Entier*) s1)->getValeur();
      Expr * s3 = new Expr(valeur);
      automate.reduction(1, s3);
      break;
   }
   default: {
      cout<<"Erreur de syntaxe3"<<endl;
      automate.erreur_();
      break;
   }
   }
   return false;
}