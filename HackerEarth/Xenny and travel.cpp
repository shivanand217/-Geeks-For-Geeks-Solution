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

const int mxx = 2000;
// special value of infinity to take for getting rid of overflows
const int inf = 0x3f3f3f3f;

int A[mxx][mxx];
int B[mxx][mxx];

// reverse graphs
int _A[mxx][mxx];
int _B[mxx][mxx];

bool vis[mxx];

int dist[mxx];
int dist2[mxx];
int n;

void F(int s, int M[][mxx]) {
    memset(dist, inf, sizeof(dist));
    memset(vis, false, sizeof(vis));

    dist[s] = 0;

    while(1) {
        int u=-1, best = inf;
        /** it calculates for single source all dest one by one **/
        /** first starts with the souce then second minimum then
            third and so on **/

        for(int i=1; i<=n; i++) {
            if(vis[i] == false && dist[i] < best) {
                u = i;
                best = dist[i];
            }
        }

        // This occurs when for every vertex minimum is calculated
        if(best >= inf)
            break;
        for(int v = 1; v <= n; v++) {
            if(vis[v]==false && M[u][v] != inf && u != v){
                if(dist[v] > dist[u] + M[u][v]) {
                    dist[v] = dist[u] + M[u][v];
                }
            }
        }
        vis[u] = true;
    }
}

int main() {
    fast;
    cin>>n;

    for(int i=1; i<=n; i++) {
        for(int j=1; j <= n; j++) {
            cin>>A[i][j];
            if(i == j)
                A[i][j]=inf;
            _A[j][i]=A[i][j];
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++) {
            cin>>B[i][j];
            if(i == j)
                B[i][j]=inf;
            _B[j][i]=B[i][j];
        }
    }

    int s,d;
    cin>>s>>d;

    int ans = inf;
    /** first dijstra on roads with s **/
    F(s, A);

    for(int i=1; i <= n; i++)
        dist2[i] = dist[i];

    /** second on rails with d **/
    F(d, _B);

    for(int i=1; i<=n; i++){
        if(i != s && i != d) {
            ans = min( ans, dist[i] + dist2[i] );
        }
    }

    /** on rails with s **/
    F(s, B);

    for(int i=1; i <= n; i++){
        dist2[i] = dist[i];
    }

    /** on roads with s **/
    F(d, _A);

    for(int i=1; i<=n; i++) {
        if( i != s && i != d ) {
            ans = min( ans , dist[i] + dist2[i] );
        }
    }

    cout<<ans<<endl;

    return 0;
}

