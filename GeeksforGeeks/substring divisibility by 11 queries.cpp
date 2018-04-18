// AUTHOR: SHIV ANAND
// LANGUAGE: CPP

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

const int maxn = 1e3+2;

struct sum
{
    lli even_;
    lli odd_;
}calc[maxn];

void precompute(s)
{
    calc[0].even_ = 0;
    calc[0].odd_ = s[0]-'0';

    calc[1].even_ = s[1]-'0';
    calc[1].odd_ = calc[0].odd_;

    for(int i=2; i<s.length(); i++)
    {
        if(i & 1)
        {
            calc[i].even_ = calc[i-2].even_ + s[i]-'0';
            calc[i].odd_ = calc[i-1].odd_;
        }
        else
        {
            calc[i].even_ = calc[i-1].even_;
            calc[i].odd_ = calc[i-2].odd_ + s[i]-'0';
        }
    }
}

int main()
{
    string s;
    cin>>s;

    precompute(s);

    int query;
    int a,b;

    si(query);

    while(query--)
    {
        si(a);
        si(b);

        a--;b--;
        lli even_sum1,odd_sum1,even_sum2,odd_sum2;

        even_sum1 = calc[a].even_;
        odd_sum1 = calc[a].odd_;

        even_sum2 = calc[b].even_;
        odd_sum2 = calc[b].odd_;

        lli diff = abs(abs(even_sum1-even_sum2) -abs(odd_sum1-odd_sum2));
    }

    return 0;
}
