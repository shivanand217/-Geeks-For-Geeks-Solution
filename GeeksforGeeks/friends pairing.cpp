// AUTHOR: SHIV ANAND
// LANGUAGE: CPP

/** we follow a top down dp approach that
    nth person has two choice
    either he should remain single
    or he can pair up with any of the n-1 persons

    recursion approach is

dp[i] = dp[i-1] + (i-1)*dp[i-2];


but i am solving it without dp is sum all untill zero
sum += 1+(n-1) // 1 for a person remain single (n-1) for it can be paired with (n-1) other peoples
if we have to take care of ordered pair mean (i,j) and (j,i) are considered different then we should not decrement i
    or the answer will be simply
    n+ n*(n-1)

    **/

#include<bits/stdc++.h>
#define si(x) scanf("%d",&x)
#define slli(x) scanf("%lld",&x)
#define sli(x) scanf("%ld",&x)
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define ll long long
#define mod 1000000007
#define pfi(x) printf("%d\n",x)
#define pfli(x) printf("%ld\n",x)
#define pflli(x) printf("%lld\n",x)
#define lli long long int
#define ull unsigned long long int
using namespace std;

/*
void solve(int n)
{
    int dp[n+1];

}*/

int main()
{
    int n,x;
    si(n);

    int sum=0;

    while(n > 0)
    {
        sum+= 1+(n-1);

        n--;
    }

    cout<<sum<<endl;
   // solve(n);

return 0;
}
