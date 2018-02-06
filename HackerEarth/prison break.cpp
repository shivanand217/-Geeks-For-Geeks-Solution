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
bool vis[30][30];
int p[30][30];
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
int ans;

/*** backtracking approach  O(3^m) **/

void rec(int x, int y, int n) {
    // base case
    if( x == n-1 && y == n-1 ) {
        ans++;
        return;
    }
    vis[x][y] = true;
    int xx , xy;
    for(int i=0; i<4; i++) {
        xx = x + dx[i];
        xy = y + dy[i];
        if( xx < 0 || xx >=n || xy < 0 || xy >=n )
            continue;
        if(vis[xx][xy] || p[xx][xy] == 1)
            continue;
        rec(xx, xy, n);
        vis[xx][xy] = false;
    }
}

int main() {
    fast;
    int t,n;
    cin>>t;
    while(t--) {
        ans = 0;
        cin>>n;
        for(int i=0; i < n; i++) {
            for(int j=0; j < n; j++) {
                cin>>p[i][j];
            }
        }
        memset(vis,false,sizeof(vis));
        if(p[n-1][n-1] == 1){
            cout<<"0"<<endl;
            continue;
        }
        rec(0, 0, n);
        cout<<ans<<endl;
    }

    return 0;
}
