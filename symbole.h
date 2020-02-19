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
      virtual int getValeur();
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
      int getValeur() {return valeur;}
   protected:
      int valeur;
};

class Expression : public Symbole {
public :
    Expression(int val) : Symbole(EXPR), val(val) {}
    Expression(): Symbole(EXPR) {}
     ~Expression() { }
    virtual void Affiche();
protected:
    int val;
};

class ExprPlus : public Expression {
public :
    ExprPlus();
    ExprPlus(Symbole * s1, Symbole * s2) : s1(s1), s2(s2) {}
    ~ExprPlus() { }
    virtual void Affiche();

protected:
    Symbole * s1;
    Symbole * s2;
};

class ExprMult : public Expression {
public :
    ExprMult();
    ExprMult(Symbole * s1, Symbole * s2) : s1(s1), s2(s2) {}
    ~ExprMult() { }
    virtual void Affiche();
protected:
    Symbole * s1;
    Symbole * s2;
};



