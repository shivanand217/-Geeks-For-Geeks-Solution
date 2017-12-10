#include<bits/stdc++.h>
#define ss second
#define ff first
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
ll po_fa(ll base,ll exp) {
    ll res=1LL;
    while(exp > 0) {
        if((res&1)) {
            res = (res*base)%mod;
        }
        exp /= 2;
        base = (base*base)%mod;
    }
    return res;
}
int main() {
    fast;
    int t,n;
    cin>>t;
    string ans;
    while(t--) {
        ans = "";
        cin>>n;
        for(int i=0;i<n;i++) {
            ans += '0';
        }
        if(n == 0) {
            cout<<"0"<<endl;
            continue;
        }
        if(n <= 9) {
            ans += (n+'0');
            reverse(ans.begin(),ans.end());
            cout<<ans<<endl;
        } else {
            int k = n / 9;
            int p = n % 9;
            for(int i=0;i<k;i++) {
                ans += (9+'0');
            }
            if(p == 0) {
                reverse(ans.begin(),ans.end());
                cout<<ans<<endl;
            } else {
                ans += (p+'0');
                reverse(ans.begin(),ans.end());
                cout<<ans<<endl;
            }
        }
    }

    return 0;
}
