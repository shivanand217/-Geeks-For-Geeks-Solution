// AUTHOR: SHIV ANAND
// LANGUAGE: CPP
// TIME COMPLEXITY : O(n)
// SPACE COMPLEXITY : O(1)

/** hashing **/

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

    for(int i=0; i<n; i++)
    {
        si(ar[i]);
    }

    int k;
    si(k);

    map<int,pair<int,int> > pp;
    pp[ar[0]] = {1,0};

    vector<int> ans;

    for(int i=1; i<n; i++)
    {
        if(pp[ar[i]].first > 0)
        {
            if(abs(pp[ar[i]].second - i) <= k)
            {
                ans.push_back(ar[i]);
                pp[ar[i]] = {1,i};
            }
        }
        else
        {
            pp[ar[i]] = {1,i};
        }
    }

    for(int i=0; i<ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }

    return 0;
}
