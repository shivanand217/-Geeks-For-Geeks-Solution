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
    if(ch=='-'){
        neg=true;
        ch=gc();
    }
    for(; (ch>='0' && ch<='9'); ch=gc()){
        num = num*10 + (ch - '0');
    }
    if(neg)
        num *= (-1);
}

inline void writeInt(int n) {
    int N=n,rev,coun=0;
    rev=N;
    if(N==0) {pc('0'); pc('\n');return;}
    while((rev%10) == 0){
        coun++;
        rev /= 10;
    }
    rev = 0;
    // storing reverse of N in rev
    while(N != 0) {
        rev = (rev<<3) + (rev<<1) + N%10;
        N /= 10;
    }
    while(rev != 0) {
        pc(rev%10 + '0');
        rev /= 10;
    }
    while(coun) {
        pc('0');
        coun--;
    }
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

inline void writelong(ll n){
    ll N=n,rev,coun=0LL;
    rev=N;
    if(N==0) {pc('0'); pc('\n');return;}
    while((rev%10) == 0) {
        coun++;
        rev /= 10;
    }
    rev = 0;
    while(N != 0) {
        rev = (rev<<3) + (rev<<1) + N%10;
        N /= 10;
    }
    while(rev != 0) {
        pc(rev%10 + '0');
        rev /= 10;
    }
    while(coun) {
        pc('0');
        coun--;
    }
}

// hail preprocessing
ll api(ll diamond) {
    ll evensum=0,oddsum=0;
    while(diamond) {
        if( (diamond&1) ){
            oddsum += diamond%10;
        } else {
            evensum += diamond%10;
        }
            diamond /= 10;
    }
    return abs(evensum - oddsum);
}

ll carpe_diem[2000005];
ll sum[2000005];
ll ans[2000005];

int main() {
    // calculate diamonds
    for(ll i=1; i<=2000000; i++) {
        carpe_diem[i] = api(i);
    }
    // calculate sum
    for(ll i=1; i<=2000000; i++) {
        sum[i] = sum[i-1] + carpe_diem[i];
    }
    ans[1] = 2;
    for(ll i=2; i<=1000000; i++) {
        ans[i] = ans[i-1] + 2*(sum[2*i - 1] - sum[i]) + carpe_diem[2*i];
    }
    int t;
    ll n,diamond;
    furr_int(t);
    while(t--) {
        furr_long(n);
        writelong(ans[n]);
        pc('\n');
    }

    return 0;
}
