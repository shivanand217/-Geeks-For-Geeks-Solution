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
string lcs(string s1, string s2) {

    int n = s1.length();
    int m = s2.length();
    int dp[n + 1][m + 1];

    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            dp[i][j]=0;
        }
    }

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if( s1[i-1] == s2[j-1] ) {
                dp[i][j] = dp[i-1][j-1]+1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    for(int i=0; i<=n; i++){
        for(int j=0; j<=m; j++){
            cout<<dp[i][j]<<" ";
        } cout<<endl;
    }

    int len = dp[n][m];
    string ans="";
    int i = n, j = m;

    while(i > 0 && j > 0) {
        if(s1[i-1] == s2[j-1]) {
            ans += s1[i-1];
            i--,j--,len--;
        } else if(dp[i-1][j] > dp[i][j-1]) {
            i--;
        } else {
            j--;
        }
    }

    reverse(ans.begin(),ans.end());

    return ans;
}

int main() {

    fast;
    int n,k,tmp;
    cin>>n>>k;
    char m;
    string remain = "",s;

    for(int i=0; i < n; i++) {
        cin>>tmp;
        m = tmp + '0';
        remain += m;
    }
    cout<<remain<<endl;
    for( int i = 0; i < k-1; i++ ) {
        s = "";
        for(int j = 0; j < n; j++) {
            cin>>tmp;
            m = tmp+'0';
            s += m;
        }
        remain = lcs(remain,s);
        //cout<<remain<<endl;
        break;
    }

    return 0;
}
