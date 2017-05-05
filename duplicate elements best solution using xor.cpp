// AUTHOR: SHIV ANAND
// LANGUAGE: CPP
// TIME COMPLEXITY : O(n)
// SPACE COMPLEXITY : O(1)

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
#define fo_r(i,n) for(int i=0; i<n; i++)
using namespace std;

int ar[102];

int main()
{
    int xor_ = 0;
    int n;

    si(n);

    for(int i=0; i<n; i++){

        si(ar[i]);

    }

    for(int i=0; i<n; i++)
    {
        xor_ = xor_ ^ ar[i];
    }

    cout<<xor_<<endl;

    return 0;
}
