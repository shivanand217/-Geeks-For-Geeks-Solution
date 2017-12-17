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
int a[100005];
int main() {
    fast;
    int n,q;
    cin>>n>>q;
    unordered_map<int,vector<int> > un;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
        un[a[i]].pb(i);
    }
    int l,r,ans;
    while(q--) {
        cin>>l>>r;
        ans = INT_MAX;
        if(un[l].size() < un[r].size()) {
            for(int p=0; p<un[l].size(); p++){
                int k=un[l][p];
                int lo=0,hi=un[r].size()-1;
                int mid;
                int higher_pos=-1,lower_pos=-1;
                while(lo <= hi) {
                    mid=(lo+hi)/2;
                    if(un[r][mid] > k){
                        higher_pos = un[r][mid];
                        hi=mid-1;
                    } else {
                        lo=mid+1;
                    }
                }
                lo=0, hi=un[r].size()-1;
                while(lo <= hi) {
                    mid=(lo+hi)/2;
                    if(un[r][mid] > k){
                        hi=mid-1;
                    } else {
                        lower_pos = un[r][mid];
                        lo=mid+1;
                    }
                }
                int diff1=-1,diff2=-1;
                if(lower_pos != -1) {
                    diff1 = k-lower_pos-1;
                }
                if(higher_pos != -1) {
                    diff2 = higher_pos-k-1;
                }
                if(diff1 != -1){
                    ans = min(ans,diff1);
                }
                if(diff2 != -1){
                    ans = min(ans,diff2);
                }
            }
            cout<<ans<<endl;
        } else {
            for(int p=0;p<un[r].size();p++){
                int k=un[r][p];
                int lo=0,hi=un[l].size()-1;
                int mid;
                int higher_pos=-1,lower_pos=-1;
                while(lo <= hi){
                    mid=(lo+hi)/2;
                    if(un[l][mid] >= k){
                        higher_pos=un[l][mid];
                        hi=mid-1;
                    } else {
                        lo=mid+1;
                    }
                }
                lo=0, hi=un[l].size()-1;
                while(lo <= hi){
                    mid=(lo+hi)/2;
                    if(un[l][mid] >= k){
                        hi=mid-1;
                    } else {
                        lower_pos=un[l][mid];
                        lo=mid+1;
                    }
                }
                int diff1=-1,diff2=-1;
                if(lower_pos != -1){
                    diff1 = k - lower_pos - 1;
                }
                if(higher_pos != -1){
                    diff2 = higher_pos - k - 1;
                }
                if(diff1 != -1){
                    ans = min(ans,diff1);
                }
                if(diff2 != -1){
                    ans = min(ans,diff2);
                }
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}
