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

typedef pair<int,int> pii;

const int mxx = 10000007;
// special value of infinity to take for getting rid of overflows
const int inf = 0x3f3f3f3f;

/******************* Problem Code *****************/
bool prime[10000007];
vector<ll> a,b;
void seive() {
    memset(prime,false,sizeof(prime));
    prime[0] = prime[1] = true;
    for(ll i=2; i*i <= mxx; i++) {
        if( prime[i] == false ) {
            for(ll j =2*i; j <= mxx; j+=i ) {
                prime[j]=true;
            }
        }
    }
    for( ll i=2; i<=mxx; i++ ) {
        if(prime[i] == false) {
            a.push_back(i);
        }
    }
    int pos;
    for(int i = 0; i<a.size(); i++) {
        pos=i+1;
        if(prime[pos] == false) {
            b.push_back(a[i]);
        }
    }
}
int main() {
    seive();
    int t;
    scanf("%d",&t);
    ll n,m;
    while(t--) {
        scanf("%lld %lld\n", &n, &m);
        ll ans = (b[n-1]*b[m-1])%mod;
        printf("%lld\n", ans);
    }
    return 0;
}
