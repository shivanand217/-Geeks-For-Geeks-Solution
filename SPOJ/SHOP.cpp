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

typedef pair< int,int > pii;
typedef pair< int,pii > edge;

const int mxx = 100001;
// special value of infinity to take for getting rid of overflows
const int inf = 0x3f3f3f3f;

char k[30][30];
int d[30][30];
int n,m;
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};

/**void dfs( int x, int y, bool vis[32][32], int curr_sum ) {
    queue< pair<int, pair<int,int> > > q;
    q.push( make_pair(0, make_pair(sx, sy)) );
    pair< int, pair<int,int> > p;

    vis[x][y] = true;
    if( k[x][y] == 'D' ) {
        min_ = min(min_, curr_sum);
        return;
    }
    if(x + 1 < n) {
        if( k[x+1][y] != 'X' && k[x+1][y] != 'S' && vis[x+1][y] == false ) {
            int value = k[ x + 1 ][ y ] - '0';
            dfs( x + 1, y, vis, curr_sum + value );
        }
    }
    if( x - 1 >= 0) {
        if( k[ x-1 ][ y ] != 'X' && k[ x-1 ][ y ] != 'S' && vis[x-1][y] == false ) {
            int value = k[ x - 1 ][ y ] - '0';
            dfs( x - 1, y, vis, curr_sum + value );
        }
    }
    if( y + 1 < m) {
        if( k[ x ][y + 1] != 'X' && k[ x ][y + 1] != 'S' && vis[x][y + 1] == false) {
            int value = k[ x ][ y + 1] - '0';
            dfs( x, y + 1, vis, curr_sum + value );
        }
    }
    if( y - 1 >= 0 ){
        if( k[x][y-1] != 'X' && k[x][y-1] != 'S' && vis[ x ][ y-1 ] == false) {
            int value = k[ x ][ y - 1 ] - '0';
            dfs( x, y - 1, vis, curr_sum + value );
        }
    }
} **/

bool valid(int x, int y) {
    return ( x>=0 && y>=0 && x<n && y<m );
}
int shortest(pii start, pii dest) {
    /** min heap **/
    priority_queue<edge, vector<edge>, greater<edge> > Q;
    int w, x, y, z, l;
    Q.push(edge(0 ,start));
    k[ start.ff ][ start.ss ] = '0';
    d[ start.ff ][ start.ss ] = 0;
    while( !Q.empty() ) {
        x = Q.top().ss.ff;
        y = Q.top().ss.ss;
        Q.pop();
        for(int i = 0; i < 4; i++) {
            z = x + dx[i];
            l = y + dy[i];
            if( valid(z,l) && k[z][l] != 'X' ) {
                if(k[z][l] == 'D')
                    w = 0;
                else {
                    w = k[z][l] - '0';
                }
                /** relax edge **/
                if(d[x][y] + w < d[z][l]) {
                    d[z][l] = d[x][y] + w;
                    Q.push(edge(d[z][l], pii(z,l)));
                }
            }
        }

        k[x][y] = 'X';
        if(dest.ff == x && dest.ss == y) {
            return d[ x ][ y ];
        }
    }
}

int main() {
    fast;
    int sx, sy, sa, sb;

    while(1) {
        cin>>m>>n;
        if( n==0 && m==0 )
            break;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                cin>>k[i][j];
                d[i][j]=64;
                if( k[i][j] == 'S' ) {
                    sx=i, sy=j;
                }
                if( k[i][j] == 'D' ) {
                    sa=i, sb=j;
                }
            }
        }

        int ans = shortest( pii(sx,sy), pii(sa,sb) );
        cout<<ans<<endl;
    }

    return 0;
}
