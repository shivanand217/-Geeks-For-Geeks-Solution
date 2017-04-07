// AUTHOR: SHIV ANAND
// LANGUAGE: CPP

/** we take the smaller number between both two now for every number between 1 to smaller number we check for if it is common factor **/

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

int main()
{
    int x,y,k;
    cin>>x>>y>>k;

    int f = min(x,y);

    vector<int> v;
    v.push_back(1);

    for(int i=2; i<=f; i++)
    {
        if(x % i == 0 && y % i == 0)
        {
            v.push_back(i);
        }
    }

    cout<<v[k-1]<<endl;
return 0;
}
