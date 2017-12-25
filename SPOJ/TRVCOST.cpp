#include<bits/stdc++.h>
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
#define INF 100000000000
using namespace std;

const int mx = 10005;
/** easy dijkstras **/

vector<pair<ll,ll> > graph[mx];
vector<ll> d,p;
void dijsktra(ll start,ll n) {
    // vector<int> d(n, INF), p(n);
    d[start]=0;
    set<pair<ll,ll> > q;
    q.insert(make_pair(d[start],start));
    int len;
    while(!q.empty()) {
        ll v = q.begin()->ss;
        q.erase(q.begin());
        for(size_t i=0;i<graph[v].size();i++){
            ll to=graph[v][i].ff;
            len=graph[v][i].ss;
            if(d[v] + len < d[to]) {
                q.erase(make_pair(d[to], to));
                d[to]=d[v]+len;
                // p[to]=v;
                q.insert(make_pair(d[to], to));
            }
        }
    }
}

int main() {
    fast;
    ll n,a,b,w;
    cin>>n;
    for(ll i=0; i < n;i++) {
        cin>>a>>b>>w;
        graph[a].pb(make_pair(b,w));
        graph[b].pb(make_pair(a,w));
    }
    d.resize(mx);
   // p.resize(mx);
    fill(d.begin(),d.end(),INF);
    ll u;
    cin>>u;
    ll q,v;
    cin>>q;
    dijsktra(u,n);
    while(q--) {
        cin>>v;
        if(u == v) {
            cout<<"0"<<endl;
            continue;
        }
            if(d[v] == INF) {
                cout<<"NO PATH"<<endl;
            } else {
                cout<<d[v]<<endl;
            }
    }

    return 0;
}
