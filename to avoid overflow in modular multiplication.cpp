#include<bits/stdc++.h>
using namespace std;
#define long long ll

ll multmod(ll a, ll b, ll mod)
{
    ll res = 0;
    a = a % mod;
    while(b > 0)
    {
        // if b is odd add a
        if(b & 1)
        {
            res = (res+a)%mod;
        }

        a = (a*2)%mod;

        b/=2;
    }
    return res%mod;
}

int main()
{
    ll a = 9223372036854775807, b = 9223372036854775807;
   cout << mulmod(a, b, 100000000000);
   return 0;
}
