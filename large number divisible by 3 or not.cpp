// AUTHOR: SHIV ANAND
// LANGUAGE: CPP

/** sum of digits divisible by 3 **/

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

string s;
cin>>s;

int sum=0;

for(int i=0; i<s.length(); i++)
{
    sum+=s[i] - '0';
}

if(sum % 3 == 0)
{
    cout<<"yes"<<endl;
}
else
{
    cout<<"no"<<endl;
}

return 0;
}
