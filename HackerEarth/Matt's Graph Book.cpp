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

const int mxx = 100005;
// special value of infinity to take for getting rid of overflows
const int inf = 0x3f3f3f3f;

/******************* Problem Code *****************/
vector<pair<int,int> > v;
vector<int> graph[mxx];
bool vis[mxx];
void dfs(int x) {
    vis[x] = true;
    for(int i=0; i < graph[x].size(); i++) {
        int to = graph[x][i];
        if(!vis[to]) {
            dfs(to);
        }
    }
}
int main() {
    fast;
    int n, k, a, b, x;
    cin>>n>>k;
    for(int i=0; i < k; i++) {
        cin>>a>>b;
        v.pb(make_pair(a,b));
    }
    cin>>x;
    for( int i = 0; i < v.size(); i++ ) {
        a = v[i].ff;
        b = v[i].ss;
        if( a == x || b == x ) {
            continue;
        }
        graph[a].pb(b);
        graph[b].pb(a);
    }
    memset(vis, false, sizeof(vis));
    for(int i = 0; i < n; i++ ) {
        if( i != x ) {
            dfs(i);
            break;
        }
    }
    bool ans = true;
    for(int i = 0; i < n; i++) {
        if(i != x && vis[x] == false) {
            ans = false;
        }
    }
    if(ans == true) {
        cout<<"Connected"<<endl;
    } else {
        cout<<"Not Connected"<<endl;
    }
    return 0;
}
