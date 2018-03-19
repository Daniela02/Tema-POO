#include <iostream>
#include "multime.h"
#include "pereche.h"
#include <fstream>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");
multPerechi produsCartezian(multime A, multime B)
{
    multPerechi P;
    nod *c=new nod;
    nod *d=new nod;
    pereche x;
    c=A.v;
    while(c)
    {
        d=B.v;
        while(d)
        {
            x.a=c->info;
            x.b=d->info;
            P.adaugareNodP(x);
            P.n++;
            d=d->next;
        }
        c=c->next;
    }
    return P;
}
int main()
{
    multime A, B;
    f>>A;
    A.transformare();
    f>>B;
    B.transformare();
    multPerechi C, D;
    C=produsCartezian(A,B);
    D=produsCartezian(B,A);
    g<<C;
    g<<D;
    //bool x=C<D;
    //cout<<x;
    f.close();
    g.close();
    return 0;
}
