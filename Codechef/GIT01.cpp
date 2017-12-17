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

char pat1[102][102];
char pat2[102][102];
char ori[102][102];

int main() {
    fast;
    int t,n,m;
    cin>>t;
    while(t--) {
        cin>>n>>m;
        for(int i=0; i < n; i++) {
            for(int j=0; j < m; j++) {
                cin>>ori[i][j];
                if(i==0){
                if((j&1)) {
                    pat1[i][j] = 'G';
                    pat2[i][j] = 'R';
                } else {
                    pat1[i][j] = 'R';
                    pat2[i][j] = 'G';
                }
                } else {
                    if(pat1[i-1][j] == 'G')
                        pat1[i][j] = 'R';
                    else
                        pat1[i][j] = 'G';
                    if(pat2[i-1][j] == 'G')
                        pat2[i][j] = 'R';
                    else
                        pat2[i][j] = 'G';
                }
            }
        }
        int ans1=0,ans2=0;
        for(int i=0; i < n; i++) {
            for(int j=0; j<m; j++) {
                if(ori[i][j] != pat1[i][j]){
                    if(ori[i][j] == 'G') {
                        ans1 += 3;
                    } else {
                        ans1 += 5;
                    }
                }
                if(ori[i][j] != pat2[i][j]){
                    if(ori[i][j] == 'G'){
                        ans2 += 3;
                    } else {
                        ans2 += 5;
                    }
                }
            }
        }
        cout<<min(ans1,ans2)<<endl;
    }

    return 0;
}
