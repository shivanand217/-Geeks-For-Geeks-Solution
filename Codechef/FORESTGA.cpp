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

/** approach : binary search **/

ll R[100005];
ll H[100005];

int main() {
    fast;
    ll N,W,L;
    cin>>N>>W>>L;

    for(ll i=1; i<=N; i++) {
        cin>>H[i]>>R[i];
    }

    ll low=0LL, high=1000000000000000000LL, mid;
    ll ans;

    while(low < high) {

        mid = (low) + (high - low)/2;
        ans = 0LL;

        for(ll i=1; i <= N; i++){
            if( H[i] + mid * R[i] >= L ) {
                ans += H[i] + mid * R[i];
            }
            if ( ans >= W ){
                break;
            }
        }

        if( ans >= W ) {
            high = mid;
        } else {
            low = mid + 1;
        }

    }

    cout<<high<<endl;
    return 0;
}
