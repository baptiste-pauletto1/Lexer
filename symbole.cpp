#include "symbole.h"
#include <iostream>

void Symbole::Affiche() {
   cout<<Etiquettes[ident];
}

void Entier::Affiche() {
   Symbole::Affiche();
   cout<<"("<<valeur<<")";
}

void Expression::Affiche() {
   Symbole::Affiche();
}

void ExprPlus::Affiche() {
   Symbole::Affiche();
}

void ExprMult::Affiche() {
   Symbole::Affiche();
}

bool Symbole::estTerminal(){
    return ( this->ident == 6 ? false : true );
}

int Symbole::getValeur(){
    return 0;
}

