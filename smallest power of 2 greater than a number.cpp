// AUTHOR: SHIV ANAND
// LANGUAGE: CPP
// COMPLEXITY: O(log n)

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

/** works only for 32 bit integers **/

void solve(int n)
{

int shift=0;

while(n > 0)
{
    shift++;
    n>>=1;
}

int ans=1;

ans <<=shift;
cout<<ans<<endl;

}

int main()
{
int n;
cin>>n;

solve(n);
return 0;
}
