#include "DataStruct.h"

int gcd(int m,int n)
{
   int mc,mi,i;
   mc=m>n? m:n;
   mi=m<n? m:n;
   for(i=mi;i>0;i--)
   {
       if(mc%i==0&&mi%i==0)
         return i;
   }
}

//The four operations of fractions
fraction fplus(fraction a, fraction b)
{
    fraction c;
    int m,n,mc;
    m=a.n*b.d+a.d*b.n;
    n=a.d*b.n;
    mc=gcd(m,n);
    c.n=m/mc;
    c.d=n/mc;
    return c;
}

fraction fminus(fraction a, fraction b)
{
    fraction c;
    c.n=(a.n*b.d-b.n*a.d)/gcd((a.n*b.d- a.d*b.n), a.d*b.d);
    c.d=a.d*b.d/gcd((a.n*b.d- a.d*b.n), a.d*b.d);
    return c;
}

fraction fmulti(fraction a, fraction b)
{
    fraction c;
    c.n=a.n*b.n/gcd(a.n*b.n ,a.d*b.d);
    c.d=a.d*b.d/gcd(a.n*b.n ,a.d*b.d);
    return c;
}

fraction fdivis(fraction a, fraction b)
{
    fraction c;
    c.n=a.n*b.d/gcd(a.n*b.d ,a.d*b.n);
    c.d=a.d*b.n/gcd(a.n*b.d,a.d*b.n);
    return c;
}
