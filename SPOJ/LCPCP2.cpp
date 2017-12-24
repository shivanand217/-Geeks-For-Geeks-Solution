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

long long f(long long base,long long exp,long long mod2) {
    long long res=1LL;
    while(exp > 0) {
        if((exp&1)) {
            res = ((long long)res * base)%mod2;
        }
        exp /= 2;
        base = ((long long)base * base)%mod2;
    }
    return res;
}

int main() {
    int t;
    si(t);
    long long a,b,m,ans;
    for(int i=1; i<=t; i++) {
        slli(a), slli(b), slli(m);
        ans = f(a,b,m);
        ans %= m;
        printf("%d. %lld\n",i,ans);
    }
    return 0;
}
