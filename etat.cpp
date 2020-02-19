#include "etat.h"
#include "symbole.h"
#include "automate.h"

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
    default:
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
        automateCopain.accepter(); // à voir
        // return true;
        break;
    default:
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
    default:
        break;
    }
    return false;
}

bool Etat3::transition(Automate & automateCopain, Symbole *s){
    switch (*s) {
    case MULT:
    case CLOSEPAR:
    case FIN:
    case PLUS:
        automateCopain.reduction(5,s);
        break;
    default:
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
    default:
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
    default:
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
        break;
    }
    return false;
}

bool Etat7::transition(Automate & automateCopain, Symbole *s){
    switch (*s) {
    case MULT:
        automateCopain.decalage(s, new Etat5);
        break;
    case CLOSEPAR:
    case FIN:
    case PLUS:
        automateCopain.reduction(2,s);
        break;
    default:
        break;
    }
    return false;
}

bool Etat8::transition(Automate & automateCopain, Symbole *s){
    switch (*s) {
    case MULT:
    case CLOSEPAR:
    case FIN:
    case PLUS:
        automateCopain.reduction(3,s);
        break;
    default:
        break;
    }
    return false;
}

bool Etat9::transition(Automate & automateCopain, Symbole *s){
    switch (*s) {
    case MULT:
    case CLOSEPAR:
    case FIN:
    case PLUS:
        automateCopain.reduction(4,s);
        break;
    default:
        break;
    }
    return false;
}
