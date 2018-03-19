#include <iostream>
using namespace std;
class nod
{public:
    int info;
    nod *next;
};
class multime
{
public:
    int n;  ///numarul de elemente
    nod*v=new nod;
    multime()
    {
        n=0;v=NULL;
    }
    multime(const multime &);
    ~multime()
    {
        delete v;
    }
    void transformare();
    void  adaugareNod (int );
    void eliminareNod(int );
    friend istream & operator>>(istream &, multime &);
    friend ostream & operator<<(ostream &, multime &);
    multime & operator=(const multime &);
    friend multime operator+(const multime &, const multime &); ///reuniune
    friend multime operator*(const multime &, const multime &); ///intersectie
    friend multime operator-(const multime &, const multime &); ///diferenta
    friend bool operator ==(const multime &, const multime &);
    friend bool operator !=(const multime &, const multime &);
    friend bool operator <(const multime &, const multime &);   ///definesc A<B daca A inlcus in B
    friend bool operator <=(const multime &, const multime &);
};
