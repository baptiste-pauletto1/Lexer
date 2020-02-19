#pragma once

#include <string>
using namespace std;

enum Identificateurs { OPENPAR, CLOSEPAR, PLUS, MULT, INT, FIN, EXPR, ERREUR };

const string Etiquettes[] = { "OPENPAR", "CLOSEPAR", "PLUS", "MULT", "INT", "FIN", "EXPR", "ERREUR" };

class Symbole {
   public:
      Symbole(int i) : ident(i) {  }
      virtual ~Symbole() { }
      operator int() const { return ident; }
      bool estTerminal();
      virtual void Affiche();

   protected:
      int ident;
};

class Entier : public Symbole {
   public:
      Entier(int v) : Symbole(INT), valeur(v) { }
      ~Entier() { }
      virtual void Affiche();
   protected:
      int valeur;
};

class Expression : public Symbole {
public :
    Expression(): Symbole(EXPR) {}
    ~Expression() {}
    virtual void Affiche();
};

class OpenPar : public Symbole {
public :
    OpenPar(): Symbole(OPENPAR) {}
    ~OpenPar() {}
    virtual void Affiche();
};

class ClosePar : public Symbole {
public :
    ClosePar(): Symbole(CLOSEPAR) {}
    ~ClosePar() {}
    virtual void Affiche();
};

class Plus : public Symbole {
public :
    Plus(): Symbole(PLUS) {}
    ~Plus() {}
    virtual void Affiche();
};

class Mult : public Symbole {
public :
    Mult(): Symbole(MULT) {}
    ~Mult() {}
    virtual void Affiche();
};

class Fin : public Symbole {
public :
    Fin(): Symbole(FIN) {}
    ~Fin() {}
    virtual void Affiche();
};

class Erreur : public Symbole {
public :
    Erreur(): Symbole(ERREUR) {}
    ~Erreur() {}
    virtual void Affiche();
};

