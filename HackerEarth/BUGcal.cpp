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
ll a[mx6];
int main() {

    ll t,n,k;
    cin>>t;
    while( t--) {
        cin>>n>>k;
        for(int i=0; i<n; i++){
            cin>>a[i];
        }
        ll min_= LLONG_MAX;
        ll max_ = LLONG_MIN;
        sort(a,a+n);
        int i=0,j=n-1;
        ll sum;
        while(i<j) {
            sum = a[i] + a[j];
            min_ = min(min_,sum);
            max_ = max(max_,sum);
            i++,j--;
        }
        sum = max_ - min_;
        if(sum > k) {
            cout<<sum<<endl;
            cout<<"No more girlfriends!"<<endl;
        } else if(sum == k) {
            cout<<sum<<endl;
            cout<<"Lucky chap!"<<endl;
        } else {
            cout<<sum<<endl;
            cout<<"Chick magnet Jhool!"<<endl;
        }
    }
    return 0;
}

