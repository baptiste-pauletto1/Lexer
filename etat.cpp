#include "etat.h"
#include "symbole.h"
#include "automate.h"
#include <iostream>
using namespace std;


Etat::Etat(string name):name(name) {}

Etat::Etat() {}

Etat::~Etat() {}


bool Etat0::transition(Automate & automateCopain, Symbole *s){
    switch (*s) {
    case INT:
        automateCopain.decalage(s, new Etat3);
        break;
    case OPENPAR:
        automateCopain.decalage(s, new Etat2);
        break;
    case EXPR:
        automateCopain.decalage(s, new Etat1);
        break;
    default:
        //automateCopain.decalage(new Symbole(ERREUR),nullptr);
        //return true;
        break;
    }
    return false;
}

bool Etat1::transition(Automate & automateCopain, Symbole *s){
    switch (*s) {
    case PLUS:
        automateCopain.decalage(s, new Etat4);
        break;
    case MULT:
        automateCopain.decalage(s,new Etat5);
        break;
    case FIN:
        return true;
        break;
    default:
        //automateCopain.decalage(new Symbole(ERREUR),nullptr);
        //return true;
        break;
    }
    return false;
}

bool Etat2::transition(Automate & automateCopain, Symbole *s){
    switch (*s) {
    case INT:
        automateCopain.decalage(s, new Etat3);
        break;
    case OPENPAR:
        automateCopain.decalage(s, new Etat2);
        break;
    case EXPR:
        automateCopain.decalage(s, new Etat6);
        break;
    default:
        //automateCopain.decalage(new Symbole(ERREUR),nullptr);
        //return true;
        break;
    }
    return false;
}

bool Etat3::transition(Automate & automateCopain, Symbole *s){
    Symbole * a;
    int couilles;
    switch (*s) {
    case CLOSEPAR:
    case FIN:
    case MULT:
    case PLUS:
        a = (Entier *) automateCopain.popSymbol();
        couilles = a->getValeur();
        automateCopain.getResultat() == 0 ? automateCopain.setResultat(couilles)
                                          : automateCopain.setVI(couilles);
        automateCopain.reduction(1,new Expression());
        break;
    default:
        //automateCopain.decalage(new Symbole(ERREUR),nullptr);
        //return true;
        break;
    }
    return false;
}

bool Etat4::transition(Automate & automateCopain, Symbole *s){
    switch (*s) {
    case INT:
        automateCopain.decalage(s, new Etat3);
        break;
    case OPENPAR:
        automateCopain.decalage(s, new Etat2);
        break;
    case EXPR:
        automateCopain.decalage(s, new Etat7);
        break;
    default:
        //automateCopain.decalage(new Symbole(ERREUR),nullptr);
        //return true;
        break;
    }
    return false;
}

bool Etat5::transition(Automate & automateCopain, Symbole *s){
    switch (*s) {
    case INT:
        automateCopain.decalage(s, new Etat3);
        break;
    case OPENPAR:
        automateCopain.decalage(s, new Etat2);
        break;
    case EXPR:
        automateCopain.decalage(s, new Etat8);
        break;
    default:
        //automateCopain.decalage(new Symbole(ERREUR),nullptr);
        //return true;
        break;
    }
    return false;
}

bool Etat6::transition(Automate & automateCopain, Symbole *s){
    switch (*s) {
    case PLUS:
        automateCopain.decalage(s, new Etat4);
        break;
    case MULT:
        automateCopain.decalage(s,new Etat5);
        break;
    case CLOSEPAR:
        automateCopain.decalage(s,new Etat9);
        break;
    default:
        //automateCopain.decalage(new Symbole(ERREUR),nullptr);
        //return true;
        break;
    }
    return false;
}

bool Etat7::transition(Automate & automateCopain, Symbole *s){
    Expression * s1;
    Expression * s2;
    switch (*s) {
    case MULT:
        automateCopain.decalage(s, new Etat5);
        break;
    case CLOSEPAR:
    case FIN:
    case PLUS:
        s1 = (Expression *) automateCopain.popSymbol();
        automateCopain.popAndDestroySymbol();
        s2 = (Expression *) automateCopain.popSymbol();
        automateCopain.reduction(3,new ExprPlus(s1,s2));
        automateCopain.add();
        break;
    default:
        //automateCopain.decalage(new Symbole(ERREUR),nullptr);
        //return true;
        break;
    }
    return false;
}

bool Etat8::transition(Automate & automateCopain, Symbole *s){
    Expression * s1;
    Expression * s2;
    switch (*s) {
    case MULT:
    case CLOSEPAR:
    case FIN:
    case PLUS:
        s1 = (Expression *) automateCopain.popSymbol();
        automateCopain.popAndDestroySymbol();
        s2 = (Expression *) automateCopain.popSymbol();
        automateCopain.reduction(3,new ExprMult(s1,s2));
        automateCopain.mult();
        break;
    default:
        //automateCopain.decalage(new Symbole(ERREUR),nullptr);
        //return true;
        break;
    }
    return false;
}

bool Etat9::transition(Automate & automateCopain, Symbole *s){
    Expression * s1;
    switch (*s) {
    case MULT:
    case CLOSEPAR:
    case FIN:
    case PLUS:
        automateCopain.popAndDestroySymbol();
        s1 = (Expression *) automateCopain.popSymbol();
        automateCopain.popAndDestroySymbol();
        automateCopain.reduction(3,s1);
        break;
    default:
        //automateCopain.decalage(new Symbole(ERREUR),nullptr);
        //return true;
        break;
    }
    return false;
}
