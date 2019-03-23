// AUTHOR: SHIV ANAND
// LANGUAGE: CPP

/** algorithm is simple:
    if both a and b is zero
        gcd(a,b) = 0
    if a is even b is odd
        gcd(a,b) = gcd(a/2,b)
    reverse
        gcd(a,b) = gcd(a,b/2)
    gcd(a,0)=a gcd(0,b) = b
    both even
    gcd(a,b) = 2*gcd(a/2, b/2)

    if both are odd
        gcd(a,b) = gcd(abs(a-b)/2, b)

repeat steps until a=b or until a=0
**/


#include<bits/stdc++.h>
#include<cstdio>
#include<cstdlib>
#define si(x) scanf("%d",&x)
#define slli(x) scanf("%lld",&x)
#define sli(x) scanf("%ld",&x)
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define LL long long
#define mod 1000000007
#define pfi(x) printf("%d\n",x)
#define pfli(x) printf("%ld\n",x)
#define pflli(x) printf("%lld\n",x)
#define lli long long int
#define ull unsigned long long int
using namespace std;

int gcd(int a, int b)
{
    /* GCD(0, b) == b; GCD(a,0) == a, GCD(0,0) == 0 */
    if (a == 0)
        return b;
    if (b == 0)
        return a;

    /*Finding K, where K is the greatest power of 2
      that divides both a and b. */
    int k;
    for (k = 0; ((a | b) & 1) == 0; ++k)
    {
        a >>= 1;
        b >>= 1;
    }

    /* Dividing a by 2 until a becomes odd */
    while ((a & 1) == 0)
        a >>= 1;

    /* From here on, 'a' is always odd. */
    do
    {
        /* If b is even, remove all factor of 2 in b */
        while ((b & 1) == 0)
            b >>= 1;

        /* Now a and b are both odd. Swap if necessary
           so a <= b, then set b = b - a (which is even).*/
        if (a > b)
            swap(a, b);   // Swap u and v.

        b = (b - a);
    }   while (b != 0);

    /* restore common factors of 2 */
    return a << k;
}


int main()
{
    int a,b;
    si(a);si(b);


    int ans = gcd(a,b);
    cout<<ans<<endl;

    return 0;
}
