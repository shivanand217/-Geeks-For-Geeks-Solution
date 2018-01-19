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

/******************* Problem Code *****************/

int dp[2005][2005];

int len(char s1, char s2) {
    return abs((int)s1 - (int)s2);
}

int main() {

    fast;
    string s1,s2;
    cin>>s1>>s2;
    int k;
    cin>>k;

    for(int i=0; i<2005; i++) {
        dp[i][0] = i*k;
        dp[0][i] = i*k;
    }

    int n , m;
    n=s1.length();
    m=s2.length();

    for( int i=1; i <=n; i++ )  {
        for(int j=1; j<=m; j++ ) {
            dp[i][j]=min(dp[i-1][j-1]+len(s1[i-1],s2[j-1]),
                         min(dp[i-1][j]+k, dp[i][j-1]+k));
        }
    }
    cout<<dp[n][m]<<endl;

    return 0;
}
