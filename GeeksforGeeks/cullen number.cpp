// AUTHOR: SHIV ANAND
// LANGUAGE: CPP

/** cullen number can be represented in the form of pow(2,n)*n+1 **/

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

int get_cullen_number(int n)
{
    int ans= (1<<n)*n+1;
    return ans;
}

int main()
{
    int n;
    read(n)

    int ans = get_cullen_number(n);
    cout<<ans<<endl;
    return 0;
}
