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

Etat9::Etat9(string name) : name(name) {
}

bool Etat9::transition(Automate & automate, Symbole * s) {
   switch (*s){
   case PLUS: {
      automate.popAndDestroySymbol();
      Expr * s1 = (Expr*) automate.popSymbol();
      Symbole * s2 = automate.popAndDestroySymbol();
      Expr * s3 = (Expr*) automate.popSymbol();
      automate.popAndDestroySymbol();
      int valeur;
      if (s2->getEtiquette() == "PLUS") {
         valeur = s1->getValeur() + s3->getValeur();
      } else if (s2->getEtiquette() == "MULT") {
         valeur = s1->getValeur() * s3->getValeur();
      } else {
         cout<<"Erreur de syntaxe"<<endl;
         automate.erreur_();
         return false;
      }
      Expr * s4 = new Expr(valeur);
      automate.reduction(5, s4);
      break;
   }
   case MULT: {
      automate.popAndDestroySymbol();
      Expr * s1 = (Expr*) automate.popSymbol();
      Symbole * s2 = automate.popAndDestroySymbol();
      Expr * s3 = (Expr*) automate.popSymbol();
      automate.popAndDestroySymbol();
      int valeur;
      if (s2->getEtiquette() == "PLUS") {
         valeur = s1->getValeur() + s3->getValeur();
      } else if (s2->getEtiquette() == "MULT") {
         valeur = s1->getValeur() * s3->getValeur();
      } else {
         cout<<"Erreur de syntaxe"<<endl;
         automate.erreur_();
         return false;
      }
      Expr * s4 = new Expr(valeur);
      automate.reduction(5, s4);
      break;
   }
   case CLOSEPAR: {
      automate.popAndDestroySymbol();
      Symbole * s1 = automate.popSymbol();
      if (s1->getEtiquette() == "EXPR") {
         Symbole * s2 = automate.popSymbol();
         Expr * s3 = (Expr*) automate.popSymbol();
         automate.popAndDestroySymbol();
         int valeur;
         if (s2->getEtiquette() == "PLUS") {
            valeur = s1->getValeur() + s3->getValeur();
         } else if (s2->getEtiquette() == "MULT") {
            valeur = s1->getValeur() * s3->getValeur();
         } else {
            cout<<"Erreur de syntaxe"<<endl;
            automate.erreur_();
            return false;
         }
         Expr * s4 = new Expr(valeur);
         automate.reduction(5, s4);



      } else if (s1->getEtiquette() == "INT") {
         valeur = ((Entier*) s1)->getValeur();
         Expr * s5 = new Expr(valeur);
         automate.popAndDestroySymbol();
         automate.reduction(3, s5);
         
      } else {
         cout<<"Erreur de syntaxe"<<endl;
         automate.erreur_();
         return false;
      }
      break;
   }
   case FIN: {
      automate.popAndDestroySymbol();
      Expr * s1 = (Expr*) automate.popSymbol();
      Symbole * s2 = automate.popAndDestroySymbol();
      Expr * s3 = (Expr*) automate.popSymbol();
      automate.popAndDestroySymbol();
      int valeur;
      if (s2->getEtiquette() == "PLUS") {
         valeur = s1->getValeur() + s3->getValeur();
      } else if (s2->getEtiquette() == "MULT") {
         valeur = s1->getValeur() * s3->getValeur();
      } else {
         cout<<"Erreur de syntaxe"<<endl;
         automate.erreur_();
         return false;
      }
      Expr * s4 = new Expr(valeur);
      automate.reduction(5, s4);
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