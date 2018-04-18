// AUTHOR: SHIV ANAND
// LANGUAGE: CPP

/** number which can be written of the form pow(2,k-1) we have to generate all such number less than x **/

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

vector<int> v;
const int maxn =1e5+2;
int prime[maxn];

void seive(int x)
{
    memset(prime, 1, sizeof(prime));

    prime[0]=prime[1]=0;

    for(int i=2; i*i <=x; i++)
    {
        if(prime[i])
        {
            for(int j=i*2; j<=x; j+=i)
            {
                prime[j] = 0;
            }
        }
    }
}

int main()
{
int x;
read(x)

seive(x);

// remove all the powers of 2

if(x<=3)
{
    cout<<"0"<<endl;return 0;
}

int i=0;

int count_ = 0;
int tmp =x ;

if( tmp&1 )
{
    count_-=1;
}

tmp >>=1;
i++;

int val;

while(tmp > 0)
{
    val = fast_pow(2,i);

    if(prime[val-1])
    {
        v.push_back(val-1);
    }

    tmp>>=1;
    i++;
}

cout<<v.size()<<endl;

for(int i=0; i<v.size(); i++)
{
    cout<<v[i]<<" ";
}
return 0;
}
