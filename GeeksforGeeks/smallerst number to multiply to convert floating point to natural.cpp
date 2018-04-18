// AUTHOR: SHIV ANAND
// LANGUAGE: CPP

/** we just have to calculate the gcd of num and denominator by converting the double into fraction
    then divide the denominator by the gcd to obtain the answer **/

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

int fast_pow(int x,int n)
{
    int result=1;
    while(n>0)
    {
        if(n % 2 ==1)
            result=(result * x)%mod;
        x=(x*x)%mod;
        n=n/2;
    }
    return result;
}

int gcd(int a,int b)
{
    if(a==0)
        return b;
    return gcd(b%a, a);
}

int lcm(int a,int b)
{
    int ans;
    ans = (a*b)/gcd(a,b);
    return ans;
}

int main()
{

    string s;
    cin>>s;

    bool  is_dot=false;

    int num=0;  int den;

    int count_after_dot = 0;

    for(int i=0; i<s.length(); i++)
    {
        if(s[i] != '.')
        {
            num = num*10 + (s[i]-'0');

            if(is_dot == true)
            {
                count_after_dot++;
            }
        }
        else
        {
            is_dot =true;
        }
    }

    if(is_dot == false)
    {
        cout<<1<<endl;
        return 0;
    }

    den = fast_pow(10,count_after_dot);
    int ans = den / gcd(num,den);

cout<<ans;

return 0;
}
