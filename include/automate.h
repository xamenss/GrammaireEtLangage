#pragma once
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
#include "lexer.h"
#include "symbole.h"
#include "etat.h"
#include <iostream>

#include <stack>

class Symbole;
class Etat;
class Lexer;

class Automate {
public:
Automate(Lexer* l) : lexer(l) {statestack.push(new Etat0);}
    void decalage(Symbole* s, Etat* e);
    void transitionsimple(Symbole* s, Etat* e);
    void reduction(int n, Symbole* s);
    void fin_();
    void erreur_();
    bool analyse();

private:
    std::stack<Symbole*> symbolstack;
    std::stack<Etat*>    statestack;
    Lexer* lexer = nullptr;
    bool fin = false;
    bool erreur = false;
};
