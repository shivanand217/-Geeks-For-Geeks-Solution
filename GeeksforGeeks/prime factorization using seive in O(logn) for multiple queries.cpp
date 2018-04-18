// AUTHOR: SHIV ANAND
// LANGUAGE: CPP

/** we use the concept of smallest prime factors using seive in O(n*log(logn)) **/

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

const int maxn = 1e5+2;
int spf[maxn];

void seive()
{
    spf[1]=1;

    for(int i=2; i<maxn; i++)
    {
        spf[i]=i;
    }

    for(int i=4; i<maxn; i++)
    {
        spf[i]=2;
    }

    for(int i=3; i*i<=maxn; i++)
    {
        if(spf[i] == i)
        {
            for(int j=i*i ; j<=maxn; j+=i)
            {
                // check if previously not set
                if(spf[j] == j)
                {
                    spf[j] = i;
                }
            }
        }
    }
}

// now we calculate the prime factorization in O(logn)

/** in the worst case spf will always 2 hence time will be O(logn) **/
vector<int> prime_fact(int n)
{
    vector<int> ans;
    while(n!=1)
    {
        ans.push_back(spf[n]);
        n/=spf[n];
    }
    return ans;
}

int main()
{
    int n;
    scanf("%d", &n);

    seive();

    vector<int> ans = prime_fact(n);

    for(int i=0; i<ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }

    return 0;
}
