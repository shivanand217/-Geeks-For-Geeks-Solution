// AUTHOR: SHIV ANAND
// LANGUAGE: CPP
// TIME COMPLEXITY : O(n)
// SPACE COMPLEXITY : O(n)

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

int n;

int main()
{
    si(n);
    int *ar = new int[n];

    for(int i=0; i<n; i++)
    {
        si(ar[i]);
    }

    // traversing the array from right side and updating the elements
    map<int, pair<int,int> > ma;

    for(int i=n-1; i>=0; i--)
    {
        if(ma[ar[i]].first > 0)
        {
            ma[ar[i]] = make_pair(ma[ar[i]].first+1, i);
        }
        else
        {
            ma[ar[i]] = {1,i};
        }
    }
    int ans;

    for(int i=0; i<n; i++)
    {
        if(ma[ar[i]].first > 1 )
        {
            ans = ar[i];break;
        }
    }

    cout<<ans<<endl;
    return 0;
}
