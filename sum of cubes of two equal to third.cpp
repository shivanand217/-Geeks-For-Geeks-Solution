// AUTHOR: SHIV ANAND
// LANGUAGE: CPP
// TIME COMPLEXITY : O(n^(1/3))

/** in this we discuss a O(n^(1/3)) approach**/

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

const int maxn = 1e2+2;
int ar[maxn];

int main()
{
    int n;
    si(n);

    int k = pow(n, 1.0/3.0);

    for(int i=1; i<=k; i++)
    {
        ar[i] = (((i*i)%mod)*(i%mod));
    }

    int l=1, r=k;

    while(l < r)
    {
        if(ar[l] + ar[r] < n)
        {
            l++;
        }
        else if(ar[l] + ar[r] > n)
        {
            r--;
        }
        else
        {
            cout<<l<<" "<<r<<endl;
            l++;r--;
        }
    }

return 0;
}
