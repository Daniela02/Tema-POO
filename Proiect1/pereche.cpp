#include <iostream>
#include "pereche.h"
using namespace std;


pereche:: pereche (const pereche &P)    ///constructor de copiere
{
        a=P.a;b=P.b;
}
istream & operator>>(istream &in, pereche &P)
{
    in>>P.a>>P.b;
    return in;
}
ostream & operator<<(ostream &out, pereche &P)
{
    out<<P.a<<" "<<P.b<<"\n";
    return out;
}
pereche &pereche :: operator=(const pereche &P)
{
    if(this==&P)
        return *this;
    a=P.a;
    b=P.b;
    return *this;
}
bool operator ==(const pereche &M, const pereche &P)
{
    if(M.a==P.a && M.b==P.b)    return 1;
    return 0;
}
bool operator !=(const pereche &M, const pereche &P)
{
    if(M.a==P.a && M.b==P.b)    return 0;
    return 1;
}
bool operator <(const pereche &M, const pereche &P)
{
    if(M.a<P.a || M.a==P.a && M.b<P.b)
        return 1;
    return 0;
}
bool operator <=(const pereche &M, const pereche &P)
{
    if(M<P || M==P)
        return 1;
    return 0;
}


void multPerechi::adaugareNodP (pereche x)
{
    nodP *q=new nodP;
    q->info=x;
    q->next=this->v;
    this->v=q;
}
multPerechi::multPerechi(const multPerechi &M) ///constructorul de copiere
{
    n=M.n;
    nodP *c=new nodP;
    c=M.v;
    v=NULL;
    n=0;
    while(c)
    {
        adaugareNodP(c->info);
        c=c->next;
        n++;
    }
}
istream & operator>>(istream &in, multPerechi &M)
{
    in>>M.n;
    int i;
    pereche x;
    for(i=1;i<=M.n;i++)
    {
        in>>x;
        M.adaugareNodP(x);
    }
    return in;
}
ostream & operator<<(ostream &out, multPerechi &M)
{
    out<<M.n<<'\n';
    nodP *c=new nodP;
    c=M.v;
    while(c)
    {
        out<<c->info;
        c=c->next;
    }
    out<<'\n';
    return out;
}
multPerechi& multPerechi :: operator=(const multPerechi &M)
{
    if(this==&M)
        return *this;
    if(v) delete v;
    nodP *d=new nodP;
    d=M.v;
    v=NULL;
    n=M.n;
    for(int i=1;i<=n;i++)
    {
        this->adaugareNodP(d->info);
        d=d->next;
    }
    return *this;
}
bool operator ==(const multPerechi &M, const multPerechi &P)
{
    if(M.n!=P.n)
        return 0;
    nodP *c=new nodP;
    nodP *d=new nodP;
    c=M.v;
    while(c)
    {
        d=P.v;
        int ok=1;
        while(d && ok)
        {
            if(c->info==d->info)
                ok=0;
            d=d->next;
        }
        if(ok==1)
            return 0;
        c=c->next;
    }
    return 1;
}
bool operator !=(const multPerechi &M, const multPerechi &P)
{
    if(M==P)
        return 0;
    return 1;
}
bool operator <(const multPerechi &A, const multPerechi &B)
{
    nodP *c;
    nodP *d;
    int nr=0;
    c=new nodP;
    d=new nodP;
    c=A.v;
    while(c)
    {
        d=B.v;
        int ok=0;
        while(d && !ok)
        {
            if(d->info==c->info)
                ok=1, nr++;
            d=d->next;
        }
        if(!ok)
            return 0;
        c=c->next;
    }
    if(nr==B.n)
        return 0;
    return 1;
}
bool operator <=(const multPerechi &A, const multPerechi &B)
{
    if(A<B || A==B)
        return 1;
    return 0;
}
