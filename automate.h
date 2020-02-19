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
    void accepter();
    void lancer();

private:
    stack<Symbole*> pileSymboles;
    stack<Etat*> pileEtats;
    Lexer * lexer;
};

#endif // AUTOMATE_H
