#include <iostream>
using namespace std;
class multPerechi;

class pereche
{
public:
    int a, b;
    pereche()
    {
        a=0;b=0;
    }
    pereche (const pereche &);
    pereche  &operator=(const pereche&);
    friend istream & operator>>(istream &, pereche &);
    friend ostream & operator<<(ostream &, pereche &);
    friend bool operator !=(const pereche &, const pereche &);
    friend bool operator ==(const pereche &, const pereche &);
    friend bool operator <(const pereche &, const pereche &);
    friend bool operator <=(const pereche &, const pereche &);
    friend multPerechi;
};

class nodP
{public:
    pereche info;
    nodP *next;
};

class multPerechi
{
public:
    int n;  ///numarul de prechi
    nodP *v=new nodP;
    multPerechi()
    {
        n=0;v=NULL;
    }
    multPerechi(const multPerechi &);   ///constructor de copiere
    ~multPerechi ()
    {
        delete v;
    }
    multPerechi  &operator=(const multPerechi&);
    void adaugareNodP ( pereche );
    friend istream & operator>>(istream &, multPerechi &);
    friend ostream & operator<<(ostream &, multPerechi &);
    friend bool operator !=(const multPerechi &, const multPerechi &);
    friend bool operator ==(const multPerechi &, const multPerechi &);
    friend bool operator <(const multPerechi &, const multPerechi &);
    friend bool operator <=(const multPerechi &, const multPerechi &);
};
