// AUTHOR: SHIV ANAND
// LANGUAGE: CPP

/** last digit is either 0 or 5 **/

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

if(s[s.length()-1] == '0' || s[s.length()-1] == '5')
{
    cout<<"yes"<<endl;
}
else
{
    cout<<"no"<<endl;
}

return 0;
}
