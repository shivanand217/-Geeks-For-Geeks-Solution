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

const int mxx = 100001;
// special value of infinity to take for getting rid of overflows
const int inf = 0x3f3f3f3f;

/******************* Problem Code *****************/

ll s(ll n) {
    ll sum = 0LL;

    while(n) {
        sum += ( n%10 );
        n /= 10;
    }
    return sum;
}

ll solve( ll n, ll m ) {
    ll lo = 1;
    ll hi = n;
    ll mid,sum,temp = -1;
    while( lo <= hi ) {
        mid = ( lo + (hi - lo)/2 );
        sum = s(mid);
        if(mid - sum >= m) {
            temp = mid;
            hi = mid-1;
        } else {
            lo = mid+1;
        }
    }
    if( temp == -1 ) {
        return 0;
    } else {
        return (n - temp + 1);
    }
}

int main() {

    fast;
    int t;
    cin>>t;
    ll n,m;
    ll ans;

    while( t-- ) {
        cin>>n>>m;
        ans = solve(n, m);
        cout<<ans<<endl;
    }

    return 0;
}
