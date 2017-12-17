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

vector<int> v;
set<int> s;

int bs(int x) {
    int lo=0, hi = v.size()-1;
    int res = -1,mid;
    while(lo <= hi){
        mid=(lo+hi)>>1;
        if(v[mid] <= x){
            res=mid;
            lo=mid+1;
        } else {
            hi = mid-1;
        }
    }
    return res+1;
}

int main() {
    fast;
    int t,n,k,p,x;
    cin>>t;
    while(t--){
        cin>>n>>k>>p;
        s.clear();
        v.clear();
        for(int i=0; i<k; i++){
            cin>>x;
            if(s.find(x) == s.end()){
                v.pb(x);
                s.insert(x);
            }
        }
    sort(v.begin(),v.end());
    int lo=1 , hi=2*n;
    int ans=0;

    while(lo <= hi){
        int mid = (lo+hi*1LL)/2;
        x = bs(mid);
        int tot = mid-x;
        if(tot >= p) {
            ans=mid;
            hi=mid-1;
        } else {
            lo=mid+1;
        }
    }
        if(ans > n)
            ans=-1;
        cout<<ans<<endl;
    }

    return 0;
}
