#include <bits/stdc++.h>

#define mp make_pair
#define ll long long
#define pb push_back

#define ss second
#define ff first
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

typedef pair<int,int> pii;

const int mxx = 100001;
// special value of infinity to take for getting rid of overflows
const int inf = 0x3f3f3f3f;

int Solve_edit_distance(string s1,string s2) {
    int m=s1.length(), n=s2.length();
    int dp[ m+1 ][ n+1 ];
    for(int i=0; i<=m; i++){
        for(int j=0; j<=n; j++) {
            if(i==0) {
                dp[i][j]=j;
                continue;
            }
            if(j==0) {
                dp[i][j]=i;
                continue;
            }
            if(s1[i-1] == s2[j-1]) {
                dp[i][j]=dp[i-1][j-1];
            } else {
                dp[i][j]=1+min(dp[i-1][j], min(dp[i][j-1] , dp[i-1][j-1])); /** insert, delete and replace **/
            }
        }
    }
    return dp[m][n];
}

int main() {
    fast;
    int t;
    cin>>t;
    string s1,s2;
    while(t--){
        cin>>s1>>s2;
        int ans = Solve_edit_distance(s1,s2);
        cout<<ans<<endl;
    }
    return 0;
}
