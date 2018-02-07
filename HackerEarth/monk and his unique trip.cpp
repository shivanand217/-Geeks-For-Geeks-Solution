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
#define N 100010
#define PB push_back
using namespace std;

const int mxx = 100001;

// special value of infinity to take for getting rid of overflows
const int inf = 0x3f3f3f3f;
vector<int> g[N], h[N], f[N];
vector<pair<int,int> > v;
stack<int> st, st2;
int vis[N], cnt, ans[N], n, m, comp[N];

void dfs(int z) {
	vis[z] = 1;
	for(auto i : g[z]) {
		if(!vis[i]) {
			dfs(i);
		}
	}
	st.push(z);
}

void dfs1(int z) {
	vis[z] = 1;
	comp[z] = cnt;
	for(auto i : h[z]) {
		if(!vis[i]) {
			dfs1(i);
		}
	}
}

void dfs2(int z) {
	vis[z] = 1;
	for(auto i : f[z]) {
		if(!vis[i]) {
			dfs2(i);
		}
	}
	st2.push(z);
}

int main() {

    fast;
	cin>>n>>m;
	for (int i = 0; i < m; ++i) {
		int x, y;
		cin>>x>>y;
		v.PB({x, y});
		g[x].PB(y);
		h[y].PB(x);
	}
	for (int i = 1; i <= n; ++i) {
		if(!vis[i]) {
			dfs(i);
		}
	}
	memset(vis, 0, sizeof(vis));
	while(!st.empty()) {
		int ver = st.top();
		if(!vis[ver]) {
			cnt ++;
			dfs1(ver);
		}
		st.pop();
	}
	for(auto i : v) {
		int x = i.first;
		int y = i.second;
		if(comp[x] != comp[y]) {
			f[comp[x]].PB(comp[y]);
		}
	}
	memset(vis, 0, sizeof(vis));
	for (int i = 1; i <= cnt; ++i) {
		if(!vis[i]) {
			dfs2(i);
		}
	}
	while(!st2.empty()) {
		int tp = st2.top();
		st2.pop();
		for(auto i : f[tp]) {
			ans[i] = max(ans[i], ans[tp] + 1);
		}
	}

	int res = 0;
	for (int i = 1; i <= cnt; ++i) {
		res = max(res, ans[i]);
	}
        cout<<res<<"\n";

	return 0;
}
