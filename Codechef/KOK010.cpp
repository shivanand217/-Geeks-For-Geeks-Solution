#include<bits/stdc++.h>
#define ss second
#define ff first
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

int arr[10000005];

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

int main() {

    int n,m,q,a,b,k;
    furr_int(n);
    furr_int(m);
    for(int i=0; i<10000005; i++) {
        arr[i]=0;
    }
    for(int i=0;i<m;i++) {
        furr_int(q);
        furr_int(a);
        furr_int(b);
        furr_int(k);
        if(q == 1) k *= (-1);
        arr[a] += k;
        arr[b+1] -= k;
    }
    int curr=0 , mn=INT_MAX , mx=INT_MIN;
    // executed in O(n)
    for(int i=1;i<=n;i++) {
        curr += arr[i];
        mn = min(mn, curr + min(i,n-i));
        mx = max(mx, curr + min(i,n-i));
    }

    printf("%d %d\n" , mn, mx);
    return 0;
}
