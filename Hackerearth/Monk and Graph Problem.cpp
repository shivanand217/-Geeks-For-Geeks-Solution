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
vector<int> graph[100005];
bool vis[100005];
int cnt;
void dfs(int v) {
    vis[v] = true;
    for(int i=0; i < graph[v].size(); i++) {
        int to = graph[v][i];
        cnt++;
        if(vis[to] == false) {
            dfs(to);
        }
    }
}
int main() {
    int n,m,a,b;
    cin>>n>>m;
    for( int i = 0; i < m; i++ ) {
        cin>>a>>b;
        graph[a].pb(b);
        graph[b].pb(a);
    }
    int ans = 0;
    memset(vis, false, sizeof(vis));
    for(int i = 1; i <= n; i++) {
        if(vis[i] == false) {
            cnt = 0;
            dfs(i);
            ans = max(cnt/2, ans);
        }
    }
    cout<<ans<<endl;
    return 0;
}
