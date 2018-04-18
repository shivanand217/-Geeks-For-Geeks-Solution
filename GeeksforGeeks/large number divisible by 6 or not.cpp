// AUTHOR: SHIV ANAND
// LANGUAGE: CPP

/** should be divisible by both 2 and 3 **/

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

bool by3=false;
bool by2= false;

// for checking for three check if sum % 3 == 0

if((s[i] - '0') % 2 == 0)
{
    by2 = true;
}

int sum=0;

for(int i=0; i<s.length(); i++)
{
    sum+=(s[i]-'0');


}

if(sum% 3 == 0)
{
    by3 =true;
}

if(by2 && by3)
{
    cout<<"yes"<<endl;
}
else
{
    cout<<"no"<<endl;
}

return 0;
}
