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

int a[mx5];

int main() {
    fast;
    int n,m;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    int q,ans;
    cin>>q;
    int lo,hi,mid;

    while(q--) {
        cin>>m;
        lo=0,hi=n-1;
        ans=-1;
        while(lo<=hi) {
            mid=(lo+hi)>>1;
            if(a[mid] >= m) {
                hi=mid-1;
            } else {
                ans=mid;
                lo=mid+1;
            }
        }
        if(ans==-1 && lo==0) {
            ans = -1;
            cout<<ans<<endl;
            continue;
        }
        if(ans==-1 && hi==n-1) {
            ans = n;
            cout<<ans<<endl;
            continue;
        }
            cout<<ans+1<<endl;
    }

    return 0;
}
