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
int ar[maxn];
int n;

int main()
{
read(n)

for(int i=0; i<n; i++)
{
    read(ar[i])
}

int x;
read(x)

int floor_el = INT_MIN;
int ceil_el = INT_MAX;

for(int i=0; i<n; i++)
{
    if(ar[i]!=x)
    {
        if(ar[i]<x)
        {
            if(ar[i]>floor_el)
                floor_el = ar[i];
        }
        else
        {
            if(ar[i] < ceil_el)
                ceil_el = ar[i];
        }
    }
}

cout<<floor_el<<" "<<ceil_el<<endl;

return 0;
}
