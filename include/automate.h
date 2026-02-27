#pragma once
#include "lexer.h"
#include "symbole.h"
#include "etat.h"
#include <iostream>
#include "expr.h"

#include <stack>

class Symbole;
class Etat;
class Lexer;

class Automate {
public:
    Automate(Lexer* l) : lexer(l) {}
    void decalage(Symbole* s, Etat* e);
    void transitionsimple(Symbole* s, Etat* e);
    void reduction(int n, Symbole* s);
    bool analyse();
    Symbole* popSymbol();
    Symbole * popAndDestroySymbol();

    

private:
    std::stack<Symbole*> symbolstack;
    std::stack<Etat*>    statestack;
    Lexer* lexer = nullptr;
};
