// AUTHOR: SHIV ANAND
// LANGUAGE: CPP

/** last two digits divisible by 4 **/

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

int t;

if(s.length() == 1)
{
    if((s[0] - '0') % 4 == 0)
    {
        cout<<"yes"<<endl;
    }
    else
    {
        cout<<"no"<<endl;
    }
}


else{
t = (s[s.length()-2] - '0') *10 + (s[s.length()-1]-'0');

if(t % 4 == 0)
{
    cout<<"yes"<<endl;
}
else
{
    cout<<"no"<<endl;
}

}


return 0;
}

