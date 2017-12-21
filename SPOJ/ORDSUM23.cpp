#include<bits/stdc++.h>
#define mp make_pair
#define ll long long
#define pb push_back
#define si(x) scanf("%d",&x)
#define slli(x) scanf("%lld",&x)
#define pi(x) printf("%d",x)
#define mx5 100005
#define mx6 1000006
#define mod 1000000007
#define rep(i,n) for(int i=0; i<n; i++)
#define fast std::ios::sync_with_stdio(false)
#define gc() getchar()
#define pc(x) putchar(x)
using namespace std;
ll dp[1000005];
int main() {
    int t;
    si(t);
    int n;
    dp[0]=dp[1]=0;
    dp[2]=dp[3]=1;
    for(int i=4; i<1000005; i++) {
        dp[i] = (dp[i-2]+dp[i-3])%mod;
    }
    while(t--) {
        si(n);
        printf("%lld\n",dp[n]);
    }
    return 0;
}
