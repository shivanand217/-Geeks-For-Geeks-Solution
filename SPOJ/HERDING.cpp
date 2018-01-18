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

const int mxx = 1005;
// special value of infinity to take for getting rid of overflows
const int inf = 0x3f3f3f3f;

/******************* Problem Code *****************/

string mat[mxx];
bool vis[mxx][mxx];
int cnt;
int n , m;

void dfs(int x,int y) {
    vis[x][y] = true;

    if(mat[ x][ y] == 'W') {
        if( y - 1 >=0 && vis[ x][ y - 1] == false ) {
            dfs(x, y - 1);
        }
    }
    if(mat[ x][ y] == 'S') {
        if( x + 1 < n && vis[ x + 1][ y] == false ) {
            dfs(x + 1, y);
        }
    }
    if(mat[ x][ y] == 'E') {
        if( y + 1 < m && vis[ x][ y + 1] == false ) {
            dfs(x, y + 1);
        }
    }
    if(mat[ x][ y] == 'N') {
        if( x - 1 >=0 && vis[ x - 1][ y] == false) {
            dfs(x - 1, y);
        }
    }
    return;
}

int main() {
    fast;
    cin>>n>>m;
    for(int i=0; i<n; i++) {
        cin>>mat[i];
    }

    cnt = 0;
    memset(vis, false ,sizeof(vis));
    for(int i=0; i<n; i++) {
        for(int j=0; j<mat[0].length(); j++) {
            if(vis[i][j] == false){
                dfs(i,j);
                cnt++;
            }
        }
    }
    cout<<cnt<<endl;

    return 0;
}
