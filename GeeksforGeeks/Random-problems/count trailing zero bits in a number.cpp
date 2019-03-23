// AUTHOR: SHIV ANAND
// LANGUAGE: CPP

#include<bits/stdc++.h>
#include<cstdio>
#include<cstdlib>
#define read(val) scanf("%d",&val);
#define print(val) printf("%d ",val);
#define scan(val) scanf("%lld",&val);
#define show(val) printf("%lld ",val);
#define rr(val) for(int i=0; i<val; i++)
#define ret return 0;
#define ll long long
using namespace std;

int count_trailing_zero_bits(int n)
{

    int cnt=0;

    while((n & (1)) == 0)
    {
        cnt++;
        n>>=1;
    }
    return cnt;
}

int main()
{

int n;
cin>>n;

int ans=count_trailing_zero_bits(n);
cout<<ans<<endl;

return 0;
}
