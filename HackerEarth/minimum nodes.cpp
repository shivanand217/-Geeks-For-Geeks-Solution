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

vector<int> gr[100005];
bool vis[100005];
ll a[100005];

int solve(int x, ll k) {
    queue<pair<ll,pair<int,int> > > q;
    memset(vis, false, sizeof(vis));
    vis[x] = true;
    q.push(make_pair(a[x], make_pair(1, x)));
    int ans = INT_MAX;

    pair<ll, pair<int,int> > p;
    while( !q.empty() ) {
        p = q.front();
        q.pop();
        for(int i = 0; i < gr[p.ss.ss].size(); i++) {
            int to = gr[p.ss.ss][i];
            if(vis[to] == false ) {
                if(a[to] + p.ff >= k) {
                    ans = min(ans, p.ss.ff + 1);
                } else {
                    if(ans < p.ss.ff + 1)
                        continue;
                    vis[to] = true;
                    q.push(make_pair((p.ff + a[to]), make_pair(p.ss.ff+1, to)));
                }
            }
        }
    }
    return ans;
}

int main() {
    fast;
    int n,q;
    cin>>n>>q;
    for(int i = 1; i <= n; i++)
        cin>>a[i];

    int u,v;
    ll x,k;

    for(int i = 0; i < n-1; i++) {
        cin>>u>>v;
        gr[u].push_back(v);
        gr[v].push_back(u);
    }
    for(int i = 0; i < q; i++) {
        cin>>x>>k;
        int ans = solve(x, k);
        cout<<ans<<endl;
    }

    return 0;
}
