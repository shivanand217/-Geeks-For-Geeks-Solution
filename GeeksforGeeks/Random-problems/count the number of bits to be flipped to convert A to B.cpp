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

int count_(int A,int B)
{

// take the xor first
int c = A^B;
int cnt=0;
// then count the number of set bits in that xor
while(c>0)
{
    if((c&1) == 1)
    {
        cnt++;
    }
    c>>=1;
}

return ans;
}

int main()
{
int A,B;
cin>>A>>B;

int ans=count_(A,B);

cout<<ans<<endl;return 0;

}
