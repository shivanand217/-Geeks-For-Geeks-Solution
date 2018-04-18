// AUTHOR: SHIV ANAND
// LANGUAGE: CPP

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

/** logic behind this is (x+y)%m = ((x%m) + (y%m)) % m
    we first take (a mod m) then we reapeat this procedure b-1 times and every time take mod to be safe from overflow **/

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

unsigned long long int a_mod_m(string s, int m)
{
    unsigned long long int number = 0;

    for(unsigned long long int i=0; i<s.length(); i++ )
    {
        number = (number *10 + (s[i]-'0'));
        number %= m;
    }

    return number;
}

unsigned long long int power_of_a_ka_b_mod_m(string s, int b, int mod_)
{
    unsigned long long int k = a_mod_m(s,mod_);
    unsigned long long int mul = k;

    // now multiply k b times
    for(int i=1; i<b; i++)
    {
        mul = (mul*k)%mod_;
    }

    return mul;
}



int main()
{
    string s = "987584345091051645734583954832576";
    unsigned long long int b = 3;//mod_
    unsigned long long int mod_ = 11;

    cout<<power_of_a_ka_b_mod_m(s, b, mod_)<<endl;
    return 0;

}

