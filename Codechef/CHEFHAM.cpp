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

int a[mx5];
int b[mx5];

int main() {
    int t,n,x,y;
    cin>>t;
    while(t--) {
        cin>>n;
        if(n==1) {
            cin>>x;
            cout<<"0"<<endl;
            cout<<x<<endl;
        } else if(n == 2) {
            cin>>x>>y;
            if(x == y) {
                cout<<"0"<<endl;
                cout<<x<<" "<<y<<endl;
            } else {
                cout<<"2"<<endl;
                cout<<y<<" "<<x<<endl;
            }
        } else if(n == 3) {
            cin>>a[0]>>a[1]>>a[2];
            int z;
            if( (a[0] == a[1]) || (a[1] == a[2]) || (a[0] == a[2]) ) {
                cout<<"2"<<endl;
                cout<<a[2]<<" "<<a[0]<<" "<<a[1]<<endl;
            } else {
                cout<<"3"<<endl;
                cout<<a[2]<<" "<<a[0]<<" "<<a[1]<<endl;
            }
        } else {
            for(int i=0;i<n;i++) {
                cin>>a[i];
            }
            for(int i=2;i<n;i++) {
                b[i-2] = a[i];
            }
            b[n-2] = a[0];
            b[n-1] = a[1];
            for(int i=0;i<n-1;i++) {
                if(a[i] == b[i]) {
                    swap(b[i],b[i+1]);
                }
            }
            if(a[n-1] == b[n-1]){
                swap(b[n-1],b[n-2]);
            }
            cout<<n<<endl;
            for(int i=0;i<n;i++) {
                cout<<b[i]<<" ";
            } cout<<endl;
        }
    }
    return 0;
}
