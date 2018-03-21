#include <iostream>
#include "multime.h"
using namespace std;

void multime:: adaugareNod (int x)
{
    nod *q=new nod;
    q->info=x;
    q->next=this->v;
    this->v=q;
}
void multime ::eliminareNod(int x)
{
    nod *c=new nod;
    nod *d=new nod;
    if(v->info==x)
    {
        d=v;
        v=v->next;
    }
    else
    {
        c=v;
        while(c->next->info!=x)
            c=c->next;
        d=c->next;
        c->next=d->next;
    }
    delete d;
}
void multime:: transformare()
{
    nod *c=new nod;
    c=v;
    nod *d=new nod;
    nod *e=new nod;
    while(c)
    {
        e=c;
        d=c->next;
        while(d)
            if(d->info==c->info)
               {
                   nod *F=new nod;
                   F=d;
                   d=d->next;
                   e->next=d;
                   F->next=NULL;
                   delete F;
                   n--;
               }
            else
            {
                 d=d->next;
                 e=e->next;
            }
        c=c->next;
    }
}
multime:: multime (const multime &M) ///constructor de copiere
 {
    n=M.n;
    nod *c=new nod;
    c=M.v;
    v=NULL;
    n=0;
    while(c)
    {
        adaugareNod(c->info);
        c=c->next;
        n++;
    }
}
istream &operator>>(istream &in, multime &M)
{
    int n=M.n;
    if(n==0)
    {
        in>>M.n;
        int i, x;
        for(i=1;i<=M.n;i++)
        {
            in>>x;
            M.adaugareNod(x);
        }
    }
    else
    {
        int i, x;
        in>>M.n;
        nod *c=new nod;
        c=M.v;
        for(i=1;i<=M.n;i++)
        {
            in>>x;
            if(i<=n)
                c->info=x, c=c->next;
            else
                M.adaugareNod(x);
        }
    }
    return in;
}
ostream &operator<<(ostream &out, multime &M)
{
    out<<M.n<<"\n";
    nod *c=new nod;
    c=M.v;
    while(c)
    {
        out<<c->info<<" ";
        c=c->next;
    }
    out<<"\n";
    return out;
}
multime& multime :: operator=(const multime &M)
{
    if(this==&M)
        return *this;
    if(v) delete v;
    nod *d=new nod;
    d=M.v;
    v=NULL;
    n=M.n;
    for(int i=1;i<=n;i++)
    {
        this->adaugareNod(d->info);
        d=d->next;
    }
    return *this;
}
multime operator+(const multime &M, const multime &P)   ///reuniune
{
    multime rez, c1;
    rez=M;
    c1=P;
    nod *c=new nod;
    c=rez.v;
    while(c->next!=NULL)
        c=c->next;
    c->next=c1.v;
    rez.n+=P.n;
    rez.transformare();
    return rez;
}
multime operator*(const multime &M, const multime &P)   ///intersectie
{
    multime rez;
    nod *c=new nod;
    nod *d=new nod;
    c=M.v;
    while(c)
    {
        d=P.v;
        while(d && c)
        {
            if(d->info==c->info)
            {
                rez.adaugareNod( d->info);
                rez.n++;
                d=d->next;
                c=c->next;
            }
            else
                d=d->next;
        }
        if(c)
            c=c->next;
    }
    return rez;
}
multime operator-(const multime &M, const multime &P)   ///diferenta
{
    multime rez, in;
    in=M*P;
    rez=M;
    nod *d=new nod;
    d=in.v;
    while(d)
    {
        rez.eliminareNod(d->info);
        d=d->next;
    }
    rez.n-=in.n;
    return rez;
}
bool operator ==(const multime &M, const multime &P)
{
    if(M.n!=P.n)
        return 0;
    nod *c=new nod;
    nod *d=new nod;
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
bool operator !=(const multime &M, const multime &P)
{
    if(M==P)
        return 0;
    return 1;
}
bool operator <(const multime &A, const multime &B)
{
    nod *c;
    nod *d;
    int nr=0;
    c=new nod;
    d=new nod;
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
bool operator <=(const multime &A, const multime &B)
{
    if(A<B || A==B)
        return 1;
    return 0;
}
