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

/**
    care too much because
    time limit is too strict **/

int n;
const int mx = 2002;
int cost[mx],table[mx][mx];

int solve_dp(int lo, int hi) {

    if(table[lo][hi] != -1) {
        return table[lo][hi];
    }
    if(lo == hi) {
        return table[lo][hi] = n*cost[lo];
    }

    int ret = table[lo][hi];
    int age = (lo + n - hi);
    // take high at this age
    ret = max(ret, solve_dp(lo, hi-1) + (age) * cost[hi]);
    // or take low at this age
    ret = max(ret, solve_dp(lo+1, hi) + (age) * cost[lo]);

    return ret;
}

int main() {
    fast;
    cin>>n;
    for(int i=1;i<=n;i++) {
       // si(cost[i]);
        cin>>cost[i];
    }

    for(int i=1; i<=n; i++) {
        for(int j=i; j<=n; j++) {
            table[i][j] = -1;
        }
    }
    // int ans=solve_dp(1,n);
    cout<<solve_dp(1,n)<<endl;

    return 0;
}
