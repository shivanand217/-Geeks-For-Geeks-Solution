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

inline void furr_long(ll &num) {
    bool neg=false;
    char ch;
    ch=gc();
    num=0LL;
    if(ch=='-') {
        neg=true;
        ch=gc();
    }
    for(; (ch>='0' && ch<='9'); ch=gc()){
        num = num*10 + (ch - '0');
    }
    if(neg)
        num *= (ll)(-1);
}

ll fast_po(ll base,ll exp) {
    ll res=1LL;
    while(exp > 0) {
        if((exp&1)) {
            res = ((ll)res*base)%mod;
        }
        exp /= 2;
        base = ((ll)base*base)%mod;
    }
        return res;
}

int main() {
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    int l,r;
    char c,q;
    while(m--) {
        cin>>l>>r>>c>>q;
        --l,--r;
        for(int i=l;i<=r;i++){
            if(s[i]==c){
                s[i]=q;
            }
        }
    }
    cout<<s<<endl;
    return 0;
}
