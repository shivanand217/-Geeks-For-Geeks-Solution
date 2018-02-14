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

int dp[610][610];
int arr[610][610];

int main() {
    int n,m,t,x,y,r;
    cin>>n>>m;

    for( int i =0; i < n; i++ ) {
        for(int j =0; j < m; j++ ) {
            arr[i][j] = 0;
            dp[i][j] = 0;
        }
    }

    cin>>t;
    while(t--) {
        cin>>x>>y>>r;
        arr[x][y] = r;
    }

    if( arr[0][0] == -1 || arr[n-1][m-1] == -1 ) {
        cout<<"0"<<endl;
        return 0;
    }

    for( int i=0; i < n; i++ ) {
        for( int j = 0; j < m; j++) {
            if(arr[i][j] > 0) {
                    int p = i + arr[i][j];
                    int q = j + arr[i][j];
                    if(p < n){
                        dp[p][j] = 1;
                        //cout<<"on"<<endl;
                    }
                    if(q < m){
                        dp[i][q] = 1;
                        //cout<<"on"<<endl;
                    }
            }
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cout<<dp[i][j]<<" ";
        } cout<<endl;
    }

    dp[0][0] = 1;

    for(int i=0; i < n; i++) {
        for(int j=0; j < m; j++) {
            if(i == 0 && j == 0) {
                continue;
            }

            if(arr[i][j] == -1) {
                dp[i][j] = -1;
                continue;
            }

            if(i == 0) {
                if(dp[i][j-1]!=-1)
                    dp[i][j] = (dp[i][j-1]%mod + dp[i][j]%mod)%1000000007;
                continue;
            }
            if(j == 0) {
                if(dp[i-1][j] != -1)
                    dp[i][j] = (dp[i-1][j]%mod + dp[i][j]%mod)%1000000007;
                continue;
            }

            if(arr[i-1][j] != -1 && arr[i][j-1] != -1)
                dp[i][j] = (dp[i-1][j] + dp[i][j-1])%mod;

            if(arr[i-1][j] == -1 && arr[i][j-1] != -1)
                dp[i][j] = (dp[i][j]%mod + dp[i][j-1]%mod)%mod;

            if(arr[i-1][j] != -1 && arr[i][j-1] == -1)
                dp[i][j] = (dp[i][j]%mod + dp[i-1][j]%mod)%mod;
        }
    }

    /**for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cout<<dp[i][j]<<" ";
        }cout<<endl;
    }**/

    //cout<<dp[n-1][m-1];

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cout<<dp[i][j]<<" ";
        } cout<<endl;
    }

    return 0;
}
