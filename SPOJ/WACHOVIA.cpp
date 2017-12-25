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

/** Easy DP **/

int w[102],val[102];

int solve(int W,int n) {

    int table[n+2][W+2];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=W;j++){
            table[i][j]=0;
        }
    }

    for(int i=0; i<=n; i++) {
        for(int j=0; j<=W; j++) {
            if( i==0 || j==0 )
                continue;
            if(w[i-1] <= j) {
                table[i][j] = max( val[i-1] + table[i-1][j-w[i-1]] , table[i-1][j] );
            } else {
                table[i][j] = table[i-1][j];
            }
        }
    }
    return table[n][W];
}

int main() {
    fast;
    int t, n, m, a, W;
    cin>>t;

    while(t--) {
        cin>>W>>n;
        for(int i=0;i<n;i++) {
            cin>>w[i]>>val[i];
        }
        int ans = solve(W,n);
        cout<<"Hey stupid robber, you can get "<<ans<<"."<<endl;
    }

    return 0;
}
