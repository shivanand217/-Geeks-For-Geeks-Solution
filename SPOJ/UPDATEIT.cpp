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
ll ar[10006];

int main() {
    fast;
    int t;
    cin>>t;
    ll n,u,l,r,val,q,indx;

    while(t--) {
        cin>>n>>u;
        for(int i=0; i<=n; i++) {
            ar[i] = 0LL;
        }

        while(u--) {
            cin>>l>>r>>val;
            ar[l] += val;
            ar[r+1] -= val;
        }

        ll sum = 0LL;
        cin>>q;

        for(int i=0;i<=n;i++){
            sum += ar[i];
            ar[i] = sum;
        }

        /**for(int i=0;i<=n;i++){
            cout<<ar[i]<<" ";
        } cout<<endl; **/

        while(q--) {
            cin>>indx;
            cout<<ar[indx]<<endl;
        }
    }

    return 0;
}
