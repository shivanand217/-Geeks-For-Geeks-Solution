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

ll po_fa(ll base,ll exp) {
    ll res=1LL;
    while(exp > 0) {
        if((res&1)) {
            res = (res*base)%mod;
        }
        exp /= 2;
        base = (base*base)%mod;
    }
    return res;
}

int dp_bitmask[1<<20][2];
vector<int> a;

int optimised_dp(int left_mask,int turn,int n) {
    if(left_mask == 0)
        return 0;
    int result = dp_bitmask[left_mask][turn];
    if(result != -1) {
        return result;
    }
    // send a man with minimum rowing time from right to left for bringing another person to right
    if(turn == 1) {
        int pos = -1;
        result = INT_MAX;
        int right_mask = ((1<<n)-1)^left_mask;
        for(int i=0; i<n; i++) {
            // this person is on right side
            if( (right_mask & (1<<i)) ) {
                if(result > a[i]) {
                    pos = i;
                    result = a[i];
                }
            }
        }
        result = result + optimised_dp(left_mask^(1<<pos), turn^1 , n);
    } else {
        // only one person is left at the left side
        if(__builtin_popcount(left_mask) == 1) {
            result = INT_MAX;
            for(int i=0;i<n;i++){
                if(left_mask & (1<<i)){
                    result = min(result , a[i]);
                    result += optimised_dp(left_mask^(1<<i),turn^1 , n);
                }
            }
        } else {
            result = INT_MAX;
            for(int i=0; i<n; i++){
                if( (left_mask & (1<<i)) ){
                    for(int j=i+1;j<n;j++){
                        if( (left_mask & (1<<j) ) ){
                            int lft = left_mask ^ (1<<i) ^ (1<<j);
                            int value = max(a[i], a[j]) + optimised_dp(lft, turn^1, n);
                            result = min(result , value);
                        }
                    }
                }
            }
        }
    }
    return result;
}

int main() {
    fast;
    int t,n;
    cin>>t;
    while(t--) {
        cin>>n;
        a.resize(n);
        for(int i=0; i<n; i++) {
            cin>>a[i];
        }
            memset(dp_bitmask, -1, sizeof(dp_bitmask));
        // currently all the peoples are on the left side we have to send all of them to the right with minimum time
            cout<<optimised_dp((1<<n)-1 , 0, n)<<endl;
    }
    return 0;
}
