#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;

// to calculate mod inverse
ll modexp(ll x, ll y)
{
    if (y == 0)
        return 1;
    ll num = modexp(x, y/2) % mod;
    num = (num * num) % mod;
    if (y%2 == 0) return num;
    else return (x * num) % mod;
}

int main()
{
    ll n;
    cin >> n;
    ll arr[n];
    for(ll i = 0; i < n; i++)
    {
      cin >> arr[i];
      arr[i] %= mod;
    }
    ll qq;
    cin >> qq;
    while(qq--)
    {
      ll ind, ith;
      cin >> ind >> ith;
      ll ans = arr[ind - 1];
      ll count = 0;
      ll constant = ith;
      ll binomsum = 1;
      for(ll i = ind; i < n; i++)
      {
        if(constant - 1 == 0)
          break;
        binomsum = (binomsum * ((((constant - count)% mod) * modexp(count + 1, mod - 2)) % mod)) % mod;
        ans = (ans + (arr[i] * binomsum) % mod) % mod;
        count++;
      }
      cout << ans << endl;
    }
    return 0;
}

