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
inline void furr_int(int &num) {
    bool neg=false;
    char ch;
    ch=gc();
    num=0;
    if(ch=='-') {
        neg=true;
        ch=gc();
    }
    for( ; (ch>='0' && ch<='9') ; ch=gc()){
        num = num*10 + (ch - '0');
    }
    if(neg)
        num *= (-1);
}
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

ll a[100005];

int main() {

    int t,n;
    furr_int(t);
    ll sum,m,x,remain;
    int ans;

    while(t--) {

        sum = 0LL;
        furr_int(n);
        for(int i=0; i<n; i++){
            furr_long(a[i]);
            sum += a[i];
        }
        furr_long(x);
        if(x < sum) {
            for(int i=0; i<n; i++){
                if(x-a[i] <= 0){
                    ans = i+1;
                    break;
                }
                    x -= a[i];
            }
        } else {
            ll tm = x/sum;
            if(tm == 1) {
                remain = x - tm*sum;
                for(int i=0; i<n; i++) {
                    if(remain - a[i] <= 0){
                        ans = i+1;
 i+1;
                        break;
                    }
                    remain -= a[i];
                }
            }
        }
        printf("%d\n",ans);
    }

    return 0;
}
