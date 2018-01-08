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
bool ans;
string s = "ALLIZZWELL";
int n,m,k1,k2;
int dx[]={1,0,-1,0,-1,1,1,-1};
int dy[]={0,1,0,-1,1,1,-1,-1};
char a[102][102];
bool vis[102][102];

void dfs( int x, int y, int idx ) {
    int k1, k2;
        vis[x][y] = true;

    for( int i = 0 ; i < 8 ; i++ ) {
        k1= x + dx[i];
        k2= y + dy[i];
        if( k1 >= 0 && k2 >= 0 && k1 < n && k2 < m && vis[k1][k2] == false ) {
            if(a[k1][k2] == s[idx+1]) {
                if( idx+1 == 9 ) {
                    ans = true;
                    return;
                } else {
                    dfs( k1, k2, idx+1 );
                }
            }
        }
    }

    vis[x][y] = false;

}

int main() {

    fast;
    int t;
    cin>>t;

    while( t-- ) {
        cin>>n>>m;
        memset(vis, false, sizeof(vis));
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                cin>>a[i][j];
            }
        }
        ans = false;
        for(int i=0; i<n;i++) {
            for(int j=0; j<m; j++) {
                if(a[i][j] == 'A' ) {
                   // cout<<'A';
                    dfs(i, j, 0);
                }
                if( ans == true ){
                    break;
                }
            }
        }

        if(ans==true) {
            cout<<"YES"<<endl;
        } else {
            cout<<"NO"<<endl;
        }
    }

    return 0;
}
