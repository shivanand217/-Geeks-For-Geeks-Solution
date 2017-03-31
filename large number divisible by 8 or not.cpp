// AUTHOR: SHIV ANAND
// LANGUAGE: CPP

/** last three digit shoul be divisible by 8 **/

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

if(s.length() < 3)
{
    if(s.length() == 1)
    {
        t = (s[0]-'0');

        if(t == 8)
        {
            cout<<"yes"<<endl;return 0;
        }
        else
        {
            cout<<"no"<<endl;return 0;
        }
    }
    else {
        t = (s[0]- '0' )*10 + (s[1]-'0');

        if(t % 8 == 0)
        {
            cout<<"yes"<<endl;return 0;
        }
        else
        {
            cout<<"no"<<endl;return 0;
        }
    }
}
else
{

    t = (s[s.length()-3] - '0')*100 + (s[s.length()-2] - '0')*10 + (s[s.length()-1] - '0');

    if(t % 8 == 0)
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
