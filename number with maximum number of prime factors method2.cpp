// AUTHOR: SHIV ANAND
// LANGUAGE: CPP
// TIME COMPLEXITY : O()
// SPACE COMPLEXITY : O()

/** method is simple generate all the prime numbers before n and keep multiplying consequetive primes untill the product is less than n **/

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

const int maxn = 1e5+2;
int prime[maxn];

void seive()
{
memset(prime,true,sizeof(prime));

prime[0]=prime[1]=false;

for(int i=2; i*i<maxn; i++)
{


if(prime[i]){
for(int j=i*i; j<maxn ; j+=i*i)
{

  prime[j] = false;

}}

}

}


int main()
{
seive();

int n;
read(n)

int pro=1;
int count_ = 0;

int number_;

// we generated all the primes
for(int i=2; i<=n; i++ )
{
    if(prime[i])
    {
        if((pro * i) <= n)
        {
            pro*=i;
            count_++;
        }
        else
        {
            break;
        }
    }
}

cout<<pro<<endl;
return 0;

}
