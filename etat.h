#ifndef ETAT_H
#define ETAT_H

#include <string>
#include "symbole.h"
using namespace std;

class Automate;

class Etat
{
public:
    Etat(string name);
    Etat();
    virtual ~Etat();
    virtual bool transition(Automate & automateCopain,
                            Symbole * s) = 0;
protected:
    string name;
};

class Etat0 : public Etat
{
public:
    Etat0() {}
    ~Etat0() {}
    bool transition(Automate & automateCopain, Symbole * s);
};


class Etat1 : public Etat
{
public:
    Etat1() {}
    ~Etat1() {}
    bool transition(Automate & automateCopain, Symbole * s);
};

class Etat2 : public Etat
{
public:
    Etat2() {}
    ~Etat2() {}
    bool transition(Automate & automateCopain, Symbole * s);
};

class Etat3 : public Etat
{
public:
    Etat3() {}
    ~Etat3() {}
    bool transition(Automate & automateCopain, Symbole * s);
};

class Etat4 : public Etat
{
public:
    Etat4() {}
    ~Etat4() {}
    bool transition(Automate & automateCopain, Symbole * s);
};

class Etat5 : public Etat
{
public:
    Etat5() {}
    ~Etat5() {}
    bool transition(Automate & automateCopain, Symbole * s);
};

class Etat6 : public Etat
{
public:
    Etat6() {}
    ~Etat6() {}
    bool transition(Automate & automateCopain, Symbole * s);
};

class Etat7 : public Etat
{
public:
    Etat7() {}
    ~Etat7() {}
    bool transition(Automate & automateCopain, Symbole * s);
};

class Etat8 : public Etat
{
public:
    Etat8() {}
    ~Etat8() {}
    bool transition(Automate & automateCopain, Symbole * s);
};

class Etat9 : public Etat
{
public:
    Etat9() {}
    ~Etat9() {}
    bool transition(Automate & automateCopain, Symbole * s);
};

#endif // ETAT_H
