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

long long fib[45];

void pre() {
    fib[0]=1;
    fib[1]=2;
    for(int i=2; i < 44; i++) {
        fib[i] = (fib[i-1] + fib[i-2]);
        // fib[i] %= mod;
    }
}
/** dp solution only pass third subtask because X is 10^9 memory limit will be exceeded

long long solution(int X, int K) {
    long long dp[X+2][K+2][44];
    for(int x=0; x <= X; x++){
        for(int k=0; k <= K; k++){
            for(int n=0; n < 44; n++){
                dp[x][k][n] = 0;
            }
        }
    }
    for (int x=0; x <= X; x++) {
        for (int k=0; k <= K; k++) {
            for (int n = 0; n < 44; n++) {
                if (k == 0) {
                    if (x == 0) {
                        dp[x][k][n] = 1;
                    } else {
                        dp[x][k][n] = 0;
                    }
                } else if (n == 0 || x == 0) {
                    // case for k > 0
                    dp[x][k][n] = 0;
                } else {
                    dp[x][k][n] = dp[x][k][n-1];

                    if (x >= fib[n-1]) {
                        dp[x][k][n] += dp[x-fib[n-1]][k-1][n];
                    }
                }
            }
        }
    }

    return dp[X][K][43];
}
    **/

long long ans(int f, int n, int k) {
    if (n < 0) {
        return 0;
    }
    // special case
    if(n == 0 && k == 0) {
        return 1;
    }
    if(n > 0 && k > 0 && f > 0 && n <= fib[f-1] * k) {
        return ans(f-1, n, k) + ans(f, n - fib[f-1], k-1);
    }
    return 0;
}

int main() {
    fast;
    int t;
    cin>>t;
    pre();
    int x,k,n;
    while(t--) {
        cin>>x>>k;
        cout<<ans(43 , x , k)<<endl;
    }
    return 0;
}
