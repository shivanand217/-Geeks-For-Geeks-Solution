// AUTHOR: SHIV ANAND
// LANGUAGE: CPP
// TIME COMPLEXITY : O(n)
// SPACE COMPLEXITY : O(1)

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

vector<int> graph[maxn];
int depen[maxn];

int main()
{
    int n;
    raed(n)

    int a,b;
    memset(depen,0,sizeof(depen));

    for(int i=0; i<n-1; i++)
    {
        read(a)
        read(b)

        graph[a].push_back(b);
    }
    // dependencies sum
    int sum=0;
    for(int i=0; i<n-1; i++)
    {
        sum+=graph[i].size();
    }
    cout<<sum<<endl;
    return 0;
}
