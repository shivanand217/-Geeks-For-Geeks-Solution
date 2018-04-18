// AUTHOR: SHIV ANAND
// LANGUAGE: CPP
// TIME COMPLEXITY : O(1)
// SPACE COMPLEXITY : O(maxn)

#include<bits/stdc++.h>
#include<cstdio>
#include<cstdlib>
#define read(val) scanf("%d",&val);
#define print(val) printf("%d ",val);
#define scan(val) scanf("%lld",&val);
#define show(val) printf("%lld ",val);
#define rr(val) for(int i=0; i<val; i++)
#define LL long long
#define mod 1000000007
using namespace std;

const int maxn = 105;
//int ar[maxn];

struct ones
{
    int cnt_ones;
    int val;
}ar[maxn];

int main()
{
    int n;
    read(n)int tmp;

    for(int i=0; i<n; i++)
    {
        read(tmp)
        ar[i].val=tmp;
        ar[i].cnt_ones=0;
    }

    for(int i=n-1; i>=0; i--)
    {
        if(ar[i].val == 1)
        {
            ar[i].cnt_ones=1;
        }
        ar[i].cnt_ones += ar[i+1].cnt_ones;
    }
    int passing_pairs=0;

    for(int i=0; i<n-1; i++)
    {
        if(ar[i].val == 0)
        {
            passing_pairs += ar[i+1].cnt_ones;
        }
    }

    cout<<passing_pairs<<endl;
    return 0;
}
