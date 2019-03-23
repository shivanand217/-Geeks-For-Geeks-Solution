#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// returns (a*b)%c
ll mulmod(ll a,ll b,ll c)
{
    // base case if b==0, return 0
    if (b==0)
        return 0;

    // Divide the problem into 2 parts
    ll s = mulmod(a, b/2, c);

    // If b is odd, return
    // (a+(2*a)*((b-1)/2))%c
    if (b%2==1)
        return (a%c+2*(s%c)) % c;

    // If b is odd, return
    // ((2*a)*(b/2))%c
    else
        return (2*(s%c)) % c;
}

// Driver code
int main()
{
    ll a = 1000000000007, b = 10000000000005;
    ll c = 1000000000000003;
    printf("%lld\n", mulmod(a, b, c));
    return 0;
}
