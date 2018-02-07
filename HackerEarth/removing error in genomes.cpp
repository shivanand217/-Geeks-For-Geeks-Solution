#include <bits/stdc++.h>
#define mp make_pair
#define ll long long
#define pb push_back
#define se second
#define fi first
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

const int mxx = 100011;
// special value of infinity to take for getting rid of overflows
const int inf = 0x3f3f3f3f;

vector<int> graph[mxx];
vector<int> graphT[mxx];
bool vis[mxx];
vector<int> vec;

void dfs1(int u, stack<int>& st1) {
    vis[u] = true;
    for(auto i : graph[u]) {
        if(vis[i] == false) {
            dfs1(i, st1);
        }
    }
    st1.push(u);
}
void dfs2(int u) {
    vis[u] = false;
    vec.push_back(u);
    for(auto i : graphT[u]) {
        if(vis[i] == true) {
            dfs2(i);
        }
    }
}

bool compare(vector<int> a, vector<int> b) {
    return ( a.size() < b.size() );
}

int main() {
    fast;
    int n,m,a,b;
    cin>>n>>m;

    for(int i=1; i <= n; i++) {
        vis[i] = false;
    }

    for(int i=1; i <= m; i++) {
        cin>>a>>b;
        graph[a].pb(b);
        graphT[b].pb(a);
    }

    stack<int> st;
    for(int i=1; i<=n; i++) {
        if(vis[i] == false){
            dfs1(i, st);
        }
    }
    vector< vector<int> > comp;

    while( !st.empty() ) {
        int u = st.top();
        st.pop();
        vec.clear();
        if(vis[u] == true) {
            dfs2(u);
        }
        comp.push_back(vec);
    }

//    cout<<comp.size()<<endl;

    vec.clear();
    sort(comp.begin(), comp.end(), compare);
    vec = comp[comp.size()-1];

  //  cout<<vec.size()<<endl;

    sort(vec.begin(), vec.end());
    for(auto i : vec) {
        cout<<i<<" ";
    }   cout<<endl;

    return 0;
}
