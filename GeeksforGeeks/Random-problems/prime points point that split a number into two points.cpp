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

int count_digits(int n)
{
    int c=0;

    while(n>0)
    {
        c++;
        n/=10;
    }
    return c;
}

bool check_prime(int n)
{
    // base case
    if(n<=1)
        return false;
    if(n<=3)
        return true;

    /** remove two case so that we can skip 5 numbers **/
    if(n % 2 == 0 || n% 3 == 0)
    {
        return false;
    }

    // check for prime
    for(int i=5; i*i<=n; i+=6)
    {
        if(n%i == 0 || n%(i+2) == 0)
        {
            return false;
        }
    }
    return true;
}

void solve(int n,int cnt)
{
  int i=1;

  int l =

}

int main()
{
    int n;
    read(n)

    int cnt = cnt_digits(n);

    solve(n,cnt);
    return 0;
}
