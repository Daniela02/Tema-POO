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
    multime A, B, E;
    f>>A;
    A.transformare();
    cout<<A;
    f>>B;
    B.transformare();
    cout<<B;
    E=(A+B);
    cout<<"A+B\n"<<E;
    E=(A*B);
    cout<<"A*B\n"<<E;
    E=(A-B);
    cout<<"A-B\n"<<E;
    bool x;
    x=(A==B);
    cout<<"A==B "<<x<<'\n';
    x=(A!=B);
    cout<<"A!=B "<<x<<'\n';
    x=(A<B);
    cout<<"A<B "<<x<<'\n';
    x=(A<=B);
    cout<<"A<=B "<<x<<'\n';
    A=B;
    cout<<A<<B<<'\n';
    multPerechi C, D;
    C=produsCartezian(A,B);
    D=produsCartezian(B,A);
    g<<C;
    g<<D;
    x=(C<D);
    cout<<"C<D "<<x<<'\n';
    x=(C==D);
    cout<<"C==D "<<x<<'\n';
    x=(C!=D);
    cout<<"C!=D "<<x<<'\n';
    x=(C<=D);
    cout<<"C<=D "<<x<<'\n';
    C=D;
    cout<<C<<D;
    f.close();
    g.close();
    return 0;
}
