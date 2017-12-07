#include<bits/stdc++.h>
#define mp make_pair
#define ll long long
#define max3(a,b,c) max(a, max(b,c))
#define max4(a,b,c,d) max(a, max(b, max(c,d)))
#define pb push_back
#define si(x) scanf("%d",&x)
#define slli(x) scanf("%lld",&x)
#define pi(x) printf("%d",x)
#define sp() putchar(' ')
#define nl() putchar('\n')
#define mx5 100005
#define mx6 1000006
#define mx4 5004
#define rep(i,n) for(int i=0; i<n; i++)
#define fast std::ios::sync_with_stdio(false)
using namespace std;

int main() {

    fast;
    ll n,q,L,R,tmp;
    cin>>n>>q;
    vector<ll> a(n+10);
    vector<ll> P(n+10);
    for(int i=1; i<=n; i++) {
        cin>>tmp;
        a[i]=tmp;
        P[i]=0;
    }
    P[0] = 0;
    for(int i=1; i<=n; i++) {
        P[i]=P[i-1] + a[i];
    }
    /**for(int i=1;i<=n;i++) {
        cout<<P[i]<<" ";
    } cout<<endl;*/

    ll ans;

    while(q--) {
        cin>>L>>R;
        ans = P[R] - P[L-1];
        ans /= (R - L + 1);
        cout<<ans<<endl;
    }

    return 0;
}
