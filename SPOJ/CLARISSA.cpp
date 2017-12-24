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

ll a[100005];

long long f(long long base,long long exp) {
    long long res=1LL;
    while(exp){
        if((exp&1)) {
            res=((long long)res * base)%mod;
        }
        exp /= 2;
        base=((long long)base * base)%mod;
    }

    return res;
}

int main() {

    fast;
    int t,n;
    cin>>t;
    ll mxx,tmp;

    while(t--) {
        mxx=0;
        cin>>n;
        for(int i=0;i<n;i++) {
            cin>>a[i];
            mxx = max(mxx,a[i]);
        }
        int cnt=0;
        for(int i=0;i<n;i++) {
            if(a[i]==mxx) {
                cnt++;
            }
        }
        ll ans = f(2,cnt) - 1;
        cout<<ans<<endl;
    }

    return 0;
}
