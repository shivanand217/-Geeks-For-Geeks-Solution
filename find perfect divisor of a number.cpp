// AUTHOR: SHIV ANAND
// LANGUAGE: CPP

/** perfect divisor of a number is obtained by seive **/

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
int perfect_divisor[maxn];

int count_perfect_divisor()
{

for(int i=1; i*i<maxn; i++)
{
    for(int j=i*i; j<maxn; j+=i*i)
    {
        perfect_divisor[j]++;
    }
}

}

int obtain_perfect_divisor(int n)
{
    return perfect_divisor[n];
}

int main()
{
    count_perfect_divisor();

int n;
read(n)

int ans = obtain_perfect_divisor(n);

cout<<ans<<endl;

return 0;
}
