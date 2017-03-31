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

    if(s.length()<=3)
    {
        int k = stoi(s);

        if(k % 8 ==0)
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
        int k;
        k = stoi (s.substr(s.length()-3,3));

        if(k % 8 == 0)
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
