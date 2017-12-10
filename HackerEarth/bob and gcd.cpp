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
#define maxx 500
using namespace std;

ll a[1000006];

int main() {
    ll t,n,k,fi,ki,f;
    cin>>t;

    while(t--) {
        cin>>k>>n;
        bool kk = false;
        ll min_ = LLONG_MAX;
        for(ll i=0; i<n; i++) {
            cin>>a[i];
            if(a[i] <= k) {
                kk=true;
            }
            min_ = min(min_,a[i]);
        }

        ll ans,ans1;
        ll index=-1;
        if(kk == false) {
            ans=0LL;
            ans1=0LL;
            for(ll i=0; i<n; i++) {
                if(a[i] == min_) {
                    index = i;
                    ans = ans + abs(k - a[i]);
                    break;
                }
            }
            for(ll i=0; i<n; i++) {
                if(i != index) {
                    f = a[i] / k;
                    fi = k * f;
                    ki = k * (f+1);
                    ans = ans + min(abs(fi-a[i]),abs(ki-a[i]));
                }
            }
            for(ll i=0; i<n; i++) {
                f = a[i] / k;
                fi = k * f;
                ki = k * (f+1);
                ans1 = ans1 + min(abs(fi - a[i]) , abs(ki - a[i]));
            }
            ans = min(ans , ans1);
            cout<<ans<<endl;
        }
        else {
        ans = 0LL;
        for(ll i=0;i<n;i++) {
            if(a[i] == k)
                continue;
            if(a[i] < k && index != i) {
                ans = ans + abs(a[i] - k);
            }
            if(a[i] > k && index != i) {
                    f = a[i] / k;
                    fi = k * f;
                    ki = k * (f+1);
                    ans = ans + min(abs(fi-a[i]),abs(ki-a[i]));
                }
            }
            cout<<ans<<endl;
        }
    }

    return 0;
}
