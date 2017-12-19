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
int main() {
    int t;
    ll tmp;
    furr_int(t);
    vector<ll> a,b;
    vector<ll> :: iterator up;
    while(t--) {
        int n,i,c=1;
        furr_int(n);
        a.clear();
        b.clear();
        for(i=0;i<n;i++){
            furr_long(tmp);
            a.pb(tmp);
        }
        for(i=0;i<n;i++) {
            if(i==0){
                b.push_back(a[i]);
            } else if(i==1){
                if(b[0]>a[i]) {
                    b[0]=a[i];
                } else {
                    b.push_back(a[i]);
                    c++;
                }
            } else {
                vector<ll> :: iterator up;
                up = upper_bound(b.begin(),b.end(),a[i]);
                int k = up-b.begin();
                if(k == c) {
                    b.push_back(a[i]);
                    c++;
                } else {
                    b[k] = a[i];
                }
            }
        }
        printf("%d ",b.size());
        for(auto ip : b) {
            printf("%lld ", ip);
        } pc('\n');
    }
    return 0;
}
