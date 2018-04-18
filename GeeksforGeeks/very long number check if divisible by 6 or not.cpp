// AUTHOR: SHIV ANAND
// LANGUAGE: CPP

/** we have give a very long number may not be stored in long long int check if divisible by 6 **/
/** for divisible by 6 must be divisible by 2 and 3 the we check for number is even then check sum of its digits divisible by 3 **/

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

bool solve(string s)
{
    bool even=false,by3 =false;
    int sum=0;

    if((s[s.length()-1] - '0') %  2 == 0)
    {
        even = true;
    }

    for(int i=0; i<s.length(); i++)
    {
        sum += (s[i]-'0');
    }

    if(even == false)
    {
        return false;
    }
    else
    {
        if(sum % 3 == 0)
        {
            by3 = true;
        }

        if(by3)
        {
            return true;
        }

        return false;
    }
}

int main()
{
string s;
cin>>s;

if(solve(s))
{
    cout<<"number is divisible by 6"<<endl;
}
else
{
    cout<<"number is not divisible by 6"<<endl;
}

return 0;
}
