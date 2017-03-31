// AUTHOR: SHIV ANAND
// LANGUAGE: CPP

/** same as 3 if sum of digits is divisible by 9
    **/

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

bool method(string s)
{

    int t=0;
    for(int i=0; i<s.length(); i++)
    {
        t+= (s[i]-'0');
    }
    return (t % 9 == 0);
}

int main()
{

string s;
cin>>s;

if(method(s))
{
    cout<<"yes"<<endl;
}
else
{
    cout<<"no"<<endl;
}

return 0;
}
