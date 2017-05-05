// AUTHOR: SHIV ANAND
// LANGUAGE: CPP
// TIME COMPLEXITY : O(n)
// SPACE COMPLEXITY : O(1)

/** linear time **/

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
    int n;
    si(n);

    for(int i=0 ;i<n; i++)
    {
        si(ar[i]);
    }
    int curr1,curr3;

    for(int i=0; i<n-1 ; i++)
    {
        if(i == 0)
        {
            curr1 = ar[i];
            ar[i] = ar[i] * ar[i+1];
        }
        else
        {
                curr3 = ar[i];
                ar[i] = curr1 * ar[i+1];
                curr1 = curr3;
        }
    }

    ar[n-1] = ar[n-1] * curr1;

    for(int i=0; i<n ;i++)
    {
        cout<<ar[i]<<" ";
    }

    return 0;
}
