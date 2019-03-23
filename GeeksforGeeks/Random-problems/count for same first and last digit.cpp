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

void solve(int l, int r)
{
    int count_1 = 0,count_2=0;

if((l/10) == 0)
{
    count_1 += l;
}
if((r/10) == 0)
{
    count_2 += r;
}
if(count_1 == 0)
{
count_1 += (l/10) + 9;

}
if(count_2 == 0)
{
count_2 += (r/10) + 9;
}

cout<<count_1<<" "<<count_2<<endl;

    int tmp = l;
    int first_dig,last_dig;

// for first number
if((l/10) != 0)
{
    first_dig = tmp % 10;
    while(tmp > 0)
    {
        if((tmp/10) == 0)
        {
            last_dig = tmp;break;
        }
        tmp/=10;
    }

if(first_dig > last_dig)
{
    count_1 -=1;
}
}

tmp = r;

if((r/10) != 0)
{
first_dig = tmp % 10;
    while(tmp > 0)
    {
        if((tmp/10) == 0)
        {
            last_dig = tmp;break;
        }
        tmp/=10;
    }

    if(first_dig > last_dig)
    {
        count_2 -=1;
    }
}

int ans = count_2 - count_1;

if(l <= 9 )
{
    ans += (9-l);
}

cout<<ans<<endl;
}


int main()
{
int l,r;
read(l)
read(r)

if(r < l)
{
    cout<<"not possible"<<endl;
}
else
{
    solve(l,r);
}

return 0;
}

