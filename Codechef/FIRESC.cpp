#include<bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
#define ll long long
#define max3(a,b,c) max(a, max(b,c))
#define max4(a,b,c,d) max(a, max(b, max(c,d)))
#define pb push_back
#define si(x) scanf("%d",&x)
#define slli(x) scanf("%lld",&x)
#define pi(x) printf("%d",x)
#define sp() putchar(' ')
#define nl() putchar('\n')
#define mx5 100005
#define mx6 1000006
#define MOD 1000000007
using namespace std;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef unordered_set<int> usi;
typedef map<int,int> mi;
typedef unordered_map<int,int> umi;

vector<int> graph[mx5];
bool vis[mx5];
int n,m;

void dfs(int source, int& ans1) {
    vis[source]=true;
    ans1++;
    for(int i=0; i<graph[source].size(); i++){
        if( vis[graph[source][i]] == false )
			dfs(graph[source][i], ans1);
    }
}

void solve(vector<int>& ans) {
    int ans1;
    for(int i=0; i<n; i++){
        if(vis[i] == false){
			ans1 = 0;
            dfs(i, ans1);
            ans.pb(ans1);
        }
    }
}

int main() {
    int t,x,y;
    si(t);
	vector<int> ans;
    while(t--){
        si(n);
        si(m);
        ans.clear();
        for(int i=0; i<n; i++){
            graph[i].clear();
        }
        memset(vis, false, sizeof(vis));
        for(int i=0; i<m; i++){
            si(x);
			si(y);
			x--;
			y--;
            graph[x].pb(y);
            graph[y].pb(x);
        }
        solve(ans);
        ll ans1 = 1LL;
        for(int i=0; i<ans.size(); i++){
            ans1 = (ans1*ans[i]*1LL)%MOD;
        }

        printf("%d ", ans.size());
        printf("%lld\n", ans1);
    }
    return 0;
}
