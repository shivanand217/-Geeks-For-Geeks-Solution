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

map<ll,ll> lef,righ;
ll n,k,ans,arr[300010];

int main() {
    fast;
    cin>>n>>k;
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }

    for(int i=0; i<n; i++) {
        righ[arr[i]]++;
    }

    for(int i=0; i<n; i++) {
        ll k1=0 , k2 = 0;

        if(arr[i]%k == 0) {
            k1 = lef[arr[i] / k ];
        }

        righ[arr[i]]--;

        k2 = righ[arr[i]*k];

        ans += k1 * k2;

        lef[arr[i]]++;
    }
        cout<<ans<<endl;

    return 0;
}
