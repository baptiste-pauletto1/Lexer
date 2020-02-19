#include "automate.h"
#include <iostream>
using namespace std;

Automate::Automate(Lexer * l){
    resultat,variableIntermediaire = 0;
    lexer = l;
    Etat0 * etatDepart = new Etat0();
    pileEtats.push(etatDepart);
}

void Automate::decalage(Symbole *s, Etat *e){
    pileSymboles.push(s);
    pileEtats.push(e);
    if(s->estTerminal()){
        lexer->Avancer();
    }
}

void Automate::reduction(int n, Symbole * s){
    for(int i=0; i<n ; i++){
        delete(pileEtats.top());
        pileEtats.pop();
    }
    afficherPile();
    pileEtats.top()->transition(*this,s);
}

void Automate::afficherPile(){
    stack<Etat *> pileCopie1 = pileEtats;
    stack<Symbole *> pileCopie2 = pileSymboles;
    cout << endl << "PILE ETATS : " << endl;
    while(!pileCopie1.empty()){
       cout << pileCopie1.top()->afficheNom();
       cout << ",";
        pileCopie1.pop();
    }
    cout << endl << "PILE SYMBOLES : " << endl;
    while(!pileCopie2.empty()){
        pileCopie2.top()->Affiche();
        cout << ",";
        pileCopie2.pop();
    }
}

Symbole * Automate::popSymbol(){
    Symbole * s = this->pileSymboles.top();
    pileSymboles.pop();
    return s;
}

void Automate::popAndDestroySymbol(){
    pileSymboles.pop();
}

void Automate::setResultat(int val){
    resultat = val;
}

void Automate::setVI(int val){
    variableIntermediaire = val;
}

void Automate::mult(){
    resultat = resultat*variableIntermediaire;
    variableIntermediaire = 0;
}

void Automate::add(){
    resultat = resultat+variableIntermediaire;
    variableIntermediaire = 0;
}

int Automate::getResultat(){
    return resultat;
}


void Automate::lancer(){
    bool verif = false;
    //Avancer dans les états
    Symbole * s;
    while(!verif) {
        s=lexer->Consulter();
        afficherPile();
        verif = pileEtats.top()->transition(*this, s);
    }
    cout<<"Le résultat : " << resultat <<endl;
    //Le résultat sur la pile des symboles affiché
    //pileSymboles.top()->Affiche();
}
