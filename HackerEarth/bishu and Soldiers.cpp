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
int main() {
    fast;
    int n;
    cin>>n;
    ll a[n];
    ll pre[n];
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    sort(a,a+n);
    pre[0]=a[0];
    for(int i=1;i<n;i++){
        pre[i]=pre[i-1]+a[i];
    }
    int q;
    ll m;
    cin>>q;
    int lo,hi,mid,ans1;
    ll ans2;
    while(q--) {
        ans1=-1;
        cin>>m;
        lo=0;hi=n-1;
        while(lo <= hi) {
            mid=(lo+hi)/2;
            if(a[mid] > m){
                hi=mid-1;
            } else {
                ans1=mid;
                lo=mid+1;
            }
        }
        ans2 = pre[ans1];
        cout<<ans1+1<<" "<<ans2<<endl;
    }
    return 0;
}
