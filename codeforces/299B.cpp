
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
int a[10004];

int main() {
    fast;
    int n,m,d;
    cin>>n>>m>>d;
    int len=n*m;
    int rem=0;
    int prev;
    bool flag=true;
    for(int i=1;i<=len;i++){
        cin>>a[i];
        if(i==1) {
            prev=a[i]%d;
        } else {
            if(a[i]%d != prev){
                flag=false;
            }
        }
    }
    if(flag==false){
        cout<<"-1"<<endl;
        return 0;
    }
    if(n==1&&m==1) {
        cout<<"0"<<endl;
        return 0;
    }
    sort(a+1,a+len+1);
    int ans1=0,ans2=0;
    if((len&1)) {
        int indx = (len/2+1);
        for(int i=1;i<=len;i++){
            if(i != indx) {
                ans1 += (abs(a[i] - a[indx])/d);
            }
        }
        cout<<ans1<<endl;
    } else {
        int indx1 = (len/2+1);
        int indx = (len/2);
        for(int i=1;i<=len;i++) {
            if(i!=indx) {
                ans1 += (abs(a[i] - a[indx])/d);
            }
        }
        for(int i=1;i<=len;i++) {
            if(i!=indx1) {
                ans2 += (abs(a[i] - a[indx1])/d);
            }
        }
        cout<<min(ans1,ans2)<<endl;
    }

    return 0;
}
