#include "symbole.h"

class Expr : public Symbole {
    public:
        Expr(int v) : Symbole(EXPR), valeur(v) {};
        virtual ~Expr() {};
        int getValeur() const { return valeur; }
    protected:
        int valeur;
        
};