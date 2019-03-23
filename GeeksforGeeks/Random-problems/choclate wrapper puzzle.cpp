// AUTHOR: SHIV ANAND
// LANGUAGE: CPP
// TIME COMPLEXITY : O()
// SPACE COMPLEXITY : O()

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
    int money,price,wrap;

    read(money)
    read(price)
    read(wrap)

    int curr = money/price;
    if(curr == 0)
    {
        cout<<"0"<<endl;return 0;
    }

    int total=0;
    total+=curr;

    int wrapper;

    while(1)
    {
        wrapper = curr;

        curr = wrapper / wrap;
        if(curr == 0)break;
        total+= curr ;
    }

    cout<<total<<endl;
    return 0;
}
