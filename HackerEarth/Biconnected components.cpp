/** Bugs I will not Let you fuck my dreams **/

/**
    Biconnected graph is the graph which has no articulation point ans the graph is connected
    So Biconnected component of a graph is a Biconnected subgraph
**/

/** Same concept
    but little modification for printing BC
    we maintain a stack such that it stores the edges
    when AP is found we pop out and print vertex from stack until
    current u-v is found that is our one component
    do this further
**/

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

const int mxx = 100005;
// special value of infinity to take for getting rid of overflows
const int inf = 0x3f3f3f3f;

typedef pair<int,int> pii;

int low[mxx];
int disc[mxx];
int parent[mxx];
bool vis[mxx];
vector<int> graph[mxx];
stack< pii > s;
pii p;
set<int> set1;
int even = 0 ,odd = 0;

void Bcomponent(int u) {

    static int time = 0;
    disc[u] = low[u] = ++time;
    vis[u] = true;
    int child = 0;

    for(int i = 0; i < graph[u].size(); i++) {
        int to = graph[u][i];

        if(vis[to] == false) {
            child++;
            parent[to] = u;
            s.push( pii(u, to) );
            Bcomponent(to);

            low[u] = min( low[u], low[to] );

            if(parent[u] == -1 && child > 1) {
                set1.clear();
                while( !s.empty() ) {
                    p = s.top();
                    if( ( p.ff == to && p.ss == u ) ||
                        ( p.ff == u && p.ss == to ) ) {
                        break;
                    }
                    set1.insert(p.ss);
                    set1.insert(p.ff);
                    s.pop();
                }
                p=s.top();
                set1.insert(p.ff);
                set1.insert(p.ss);
                s.pop();
                if(set1.size() > 0) {
                    if( set1.size() %2 == 0 )
                        even++;
                    else
                        odd++;
                }
            }
            if(parent[u] != -1 && low[to] >= disc[u]){
                set1.clear();
                while( !s.empty() ){
                    p = s.top();
                    if( (p.ff==to && p.ss == u) ||
                       (p.ff==u && p.ss==to) )
                        break;
                    set1.insert(p.ss);
                    set1.insert(p.ff);
                    s.pop();
                }
                p=s.top();
                set1.insert(p.ff);
                set1.insert(p.ss);
                s.pop();
                if(set1.size() > 0) {
                    if(set1.size() %2 == 0)
                        even++;
                    else
                        odd++;
                }
            }
        } else {
            if(parent[u] != to && disc[to] < low[u]){
                low[u] = disc[to];
                s.push( pii(u,to) );
            }
        }
    }
}

int main() {
    fast;
    int n, m, a, b;
    cin>>n>>m;

    for(int i = 0 ; i < m ; i++) {
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for(int i = 0; i < n; i++) {
        vis[i] = false;
        parent[i] = -1;
    }

    for(int i=0; i<n; i++) {

        if(vis[i] == false) {
            Bcomponent(i);
        }
            set1.clear();

        while( !s.empty() ) {
            p = s.top();
            set1.insert(p.ff);
            set1.insert(p.ss);
            s.pop();
        }

        if(set1.size() != 0) {
            if(set1.size() % 2 == 0)
                even++;
            else
                odd++;
        }
    }

    cout<<odd<<" "<<even<<endl;
    return 0;
}
