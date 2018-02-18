#include <bits/stdc++.h>

#define mp make_pair
#define ll long long
#define pb push_back

#define ss second
#define ff first
#define si(x) scanf("%d",&x)
#define slli(x) scanf("%lld",&x)
#define pi(x) printf("%d",x)
#define plli(x) printf("%lld",x)

#define mx5 100005
#define mx6 1000006
#define mod 1000000007

#define w(x) while(x)
#define FOR(n) for(int i=0; i<n; i++)
#define fast std::ios::sync_with_stdio(false)
#define gc() getchar()
#define pc() putchar('\n')

using namespace std;

typedef pair<int,int> pii;

const int mxx = 200005;
// special value of infinity to take for getting rid of overflows
const int inf = 0x3f3f3f3f;

/******************* Problem Code *****************/
ll t;
int n;

ll minn(ll a, ll b) {
    if(a < b)return a;
    else return b;
}
ll num_divisor(ll x) {
    ll sq = sqrt(x);
    ll c=0;
    for(ll i = 1; i <= sq; i++) {
        if(x%i == 0){
            c+=2;
            if(i == (x/i))
                c-=1;
        }
    }
    return c;
}
int main() {
    fast;
    int t;
    ll n;
    si(t);
    FOR(t) {
        slli(n);
        ll ans = LLONG_MAX;
        w(1) {
            ll p = num_divisor(n);
            ans = minn( ans , n*p );
            if(p <= 2)
                break;
            n++;
        }
        plli(ans);
        pc();
    }
    return 0;
}
