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

const int mxx = 200005;
// special value of infinity to take for getting rid of overflows
const int inf = 0x3f3f3f3f;

/******************* Problem Code *****************/
int intime[mxx];
int outtime[mxx];
vector<int> graph[mxx];
int t = 0;
bool vis[mxx];
void solve( int u ) {
    vis[u] = true;
    ++t;
    intime[u] = t;
    for(int i=0;i < graph[u].size(); i++){
        int to = graph[u][i];
        if(vis[to] == false) {
            solve(to);
        }
    }
    ++t;
    outtime[u] = t;
}
bool yes(int u, int v) {
    if( ((intime[u] < intime[v]) && (outtime[u] > outtime[v]))  || ((intime[v] < intime[u]) && (outtime[v] > outtime[u])) ) {
        return true;
    }
    return false;
}
int main() {
    int n,q,a,b,u,v;
    scanf("%d %d", &n, &q);
    for( int i = 0; i < n-1; i++ ) {
        scanf("%d %d", &a, &b);
        graph[a].pb(b);
        graph[b].pb(a);
    }
    solve(1);
    while( q-- ) {
        scanf("%d %d",&u, &v);
        if(yes(u,v)) {
            cout<<"YES"<<endl;
        } else {
            cout<<"no"<<endl;
        }
    }

    return 0;
}
