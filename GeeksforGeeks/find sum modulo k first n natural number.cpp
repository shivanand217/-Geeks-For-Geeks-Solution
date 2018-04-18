// AUTHOR: SHIV ANAND
// LANGUAGE: CPP

/** Given two integer N ans K, the task is to find sum of modulo K of first N natural numbers i.e 1%K + 2%K + .... + N%K. **/

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
    int n,k;
    read(n)
    read(k)

int i=0;

if(n % k != 0)
{

while(n % k!=0)
{
    n -=1;
    i++;
}

}

    int t = n/k;

    int sum=0;

    for(int i=1; i<k; i++)
    {
        sum+= t*i;
    }

    if(i > 0)
    {
        while(i>0)
        {
            n++;

            sum += n%k;
            i--;
        }
    }

    cout<<sum<<endl;

return 0;
}
