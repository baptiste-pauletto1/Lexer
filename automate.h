#ifndef AUTOMATE_H
#define AUTOMATE_H

#include "symbole.h"
#include "etat.h"
#include "lexer.h"
#include <stack>

class Automate
{
public:
    Automate(Lexer * l);
    void decalage(Symbole * s, Etat * e);
    void reduction(int n, Symbole * s);
    Symbole * popSymbol();
    void afficherPile();
    void popAndDestroySymbol();
    int getResultat();
    void setResultat(int val);
    void setVI(int val);
    void mult();
    void add();
    void lancer();

private:
    stack<Symbole*> pileSymboles;
    stack<Etat*> pileEtats;
    Lexer * lexer;
    int resultat;
    int variableIntermediaire;
};

#endif // AUTOMATE_H
