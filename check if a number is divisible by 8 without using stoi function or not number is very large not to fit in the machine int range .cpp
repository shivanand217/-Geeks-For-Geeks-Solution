// AUTHOR: SHIV ANAND
// LANGUAGE: CPP

/** for a number to be divisible by 8 if and only if the last three digit of the number is divisible by 8 **/

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

    int third_last,second_last,last;

    if(s.length() == 1)
    {
        last = s[0]-'0';
        if(last == 8){cout<<"yes"<<endl;}
        else
        {
            cout<<"no"<<endl;
        }
    }
    else if(s.length() == 2)
    {
        last = s[s.length()-1]-'0';
        second_last = s[s.length()-1]-'0';

        if(((second_last*10 + last) % 8) == 0 )
        {
            cout<<"yes"<<endl;
        }
        else
        {
            cout<<"no"<<endl;
        }
    }
    else
    {
        last = s[s.length()-1];
        second_last = s[s.length()-2];
        third_last = s[s.length()-3];

        if((third_last*100 + second_last*10+ last)%8 == 0)
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

