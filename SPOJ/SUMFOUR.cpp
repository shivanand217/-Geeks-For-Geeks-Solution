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

/** O(n^2) using some precalculations  **/
//    legendary I/O

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

// **/

int main() {
    //fast;
    int a,b,c,d;
    int n;
    //cin>>n;
    // si(n);
    furr_int(n);

    vector< int > w,x,y,z;
    for(int i=0; i < n; i++) {
        //cin>>a>>b>>c>>d;
        furr_int(a);
        furr_int(b);
        furr_int(c);
        furr_int(d);
        w.pb(a); x.pb(b); y.pb(c); z.pb(d);
    }

    vector< int > v1,v2;
    for(int i=0; i < n; i++){
        for(int j=0; j < n; j++){
            v1.pb(w[i] + x[j]);
            v2.pb(y[i] + z[j]);
        }
    }

    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());

    int ans=0;
    int i=0, j=v1.size()-1;
    int cnt1=1,cnt2=1;

    while(i < v1.size() && j >= 0 ) {
        int sum = v1[i] + v2[j];
        // increment index upto equal elements
        while(i+1 < v1.size() && v1[i] == v1[i+1]){
            cnt1++;
            i++;
        }
        // similarly for v2 also
        while(j-1 >= 0 && v2[j] == v2[j-1]) {
            cnt2++;
            j--;
        }

        if(sum == 0) {
            ans += (ll)cnt1 * (ll)cnt2;
            cnt1=1;
            cnt2=1;
            i++;
            j--;
        } else if(sum > 0){
            j--;
            cnt2=1;
        } else {
            i++;
            cnt1=1;
        }

    }

    printf("%lld\n",ans);

    return 0;
}
