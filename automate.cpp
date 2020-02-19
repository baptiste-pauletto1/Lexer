#include "automate.h"
#include <iostream>
using namespace std;

Automate::Automate(Lexer * l) : lexer(l) {}

void Automate::decalage(Symbole *s, Etat *e){
    pileSymboles.push(s);
    pileEtats.push(e);
    if(s->estTerminal()){
        lexer->Avancer();
    }
}

void Automate::reduction(int n, Symbole * s){
    for(int i (0); i<n ; i++){
        delete(pileEtats.top());
        pileEtats.pop();
    }
    pileEtats.top()->transition(*this,s);
}

void Automate::accepter(){
    cout << "TIÉ LA FAMILLE" << endl;
}
