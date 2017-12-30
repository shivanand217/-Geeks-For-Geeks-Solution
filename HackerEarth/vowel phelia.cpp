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

int pos[100015];

int main() {
    int t,n;
    //furr_int(t);
    cin>>t;
    //char str[100015];
    string str;
    int len;
    while(t--) {
        //furr_int(n);
        cin>>n;
        cin>>str;
        int cn=0;
        pos[cn++]=0;
        for(int i=0; i<n; i++){
            if(str[i]=='a'||str[i]=='e'||str[i]=='i'||str[i]=='o'||str[i]=='u')
                pos[cn++]=i+1;
        }
        pos[cn++]=n+1;
        if(cn <= 4) {
            printf("0\n");
            continue;
        }
        int cn1=0;
        for(int i=0; i+4<cn; i++) {
            cn1 += (pos[i+1]-pos[i])*(pos[i+4]-pos[i+3]);
        }
        printf("%d\n",cn1);
    }

    return 0;
}
