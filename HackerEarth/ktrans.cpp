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
inline void furr_int(int &num){
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
int main() {
    int n,q,l,r;
    furr_int(n);
    furr_int(q);
    int k;
    int a[n+10];
    int prod[n+10];
    for(int i=1; i<=n; i++){
        furr_int(a[i]);
    }
    prod[0]=1;
    prod[1]=a[1];
    for(int i=2;i<=n;i++) {
        prod[i]=(prod[i-1]*a[i]);
    }
    while(q--) {
        furr_int(l);
        furr_int(r);
        furr_int(k);
        int ans = prod[r];
        if(prod[l-1] != 0) {
            ans /= prod[l-1];
        }
        int c = 0;
        if(ans != 0) {
            c = (k/ans);
        }
        writeInt(c);
        pc('\n');
    }
    return 0;
}
