#include <bits/stdc++.h>
#define mp make_pair
#define ll long long
#define pb push_back
#define ss second
#define ff first
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

const int mxx = 10005;
// special value of infinity to take for getting rid of overflows
const int inf = 0x3f3f3f3f;

long long solve(long long n,long long r) {
    long long ans = 1LL;
    r = min(r, n-r);
    for(long long i=0; i < r; i++) {
        ans = (ans * (n - i)) / (i+1);
    }
    return ans;
}

int main() {
    long long n,r;
    int t;
    slli(t);

    long long ans;
    while(t--) {
        slli(n),slli(r);
        long long rem = n - r;
        ans = solve(rem + r - 1LL , r - 1);
        printf("%lld\n", ans);
    }

    return 0;
}
