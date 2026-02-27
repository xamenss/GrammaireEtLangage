#include "automate.h"
#include <iostream>
#include <map>
#include <set>

using namespace std;

void Automate::decalage(Symbole* s, Etat* e) {
    symbolstack.push(s);
    statestack.push(e);
    lexer->Avancer();
}

void Automate::transitionsimple(Symbole* s, Etat* e) {
    symbolstack.push(s);
    statestack.push(e);
}

void Automate::reduction(int n, Symbole* s) {
    for (int i = 0; i < n; i++) {
        delete statestack.top();
        statestack.pop();
    }
    statestack.top()->transition(*this, s);
}

void Automate::fin_() {
    fin = true;
}

void Automate::erreur_() {
    erreur = true;
}


bool Automate::analyse() {
    bool finnn = false;
    while (!finnn && !erreur) {
        finnn = statestack.top()->transition(*this, lexer->Consulter());
    }
    return false;
}

Symbole * Automate::popSymbol() {
    if (symbolstack.empty()) {
        return nullptr;
    }
    Symbole* s = symbolstack.top();
    symbolstack.pop();
    return s;
}

Symbole * Automate::popAndDestroySymbol() {
    if (symbolstack.empty()) {
        return nullptr;
    }
    Symbole* s = symbolstack.top();
    symbolstack.pop();
    delete s;
    return nullptr;
}