#include<bits/stdc++.h>
#define si(x) scanf("%d",&x)
#define slli(x) scanf("%lld",&x)
#define sli(x) scanf("%ld",&x)
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define ll long long
#define mod 1000000007
#define pfi(x) printf("%d\n",x)
#define pfli(x) printf("%ld\n",x)
#define pflli(x) printf("%lld\n",x)
#define lli long long int
#define ull unsigned long long int
using namespace std;

const int maxn =1e5+2;
ll ar[maxn];

ll gcd(ll a, ll b)
{
    if(b == 0)
    {
        return a;
    }
    return gcd(b, a%b);
}

int main()
{
    int n,k;
    si(n);
    si(k);

    ll km = 100000000000LL;

    for(int i=0; i<n; i++)
    {
        slli(ar[i]);
        km = min(km, ar[i]);
    }

    bool ans = true;
    ll req = 0;

    //cout<<km<<endl;

    for(int i=0; i<n; i++)
    {
       if(ar[i] != km)
       {
            if(abs(ar[i] - km) % k != 0)
            {
                ans = false;break;
            }
            else
            {
                //cout<<"yes"<<endl;
                req += (abs(ar[i]-km)/k);
            }
       }
    }

    if(ans == false)
    {
        printf("-1\n");
    }
    else
    {
        printf("%lld\n", req);
    }


return 0;
}
