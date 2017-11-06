#include<bits/stdc++.h>
#include<cstdio>
#include<cstdlib>
#define si(x) scanf("%d",&x)
#define slli(x) scanf("%lld",&x)
#define sli(x) scanf("%ld",&x)
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define ll long long
#define mod 1000000007
#define pfi(x) printf("%d\n",x)
#define pfli(x) printf("%ld\n",x)
#define pflli(x) printf("%lld\n",x)
#define lli long long int
using namespace std;

typedef pair<ll, int> PLI;
const int maxn = 100005;
int n, m, ans[maxn], p[maxn];
bool visited[maxn];
vector<pair<int, ll> > adj[maxn];
ll d[maxn];

void spfa() {

	for(int i=0; i<=n; i++){
        d[i] = 1000000000000ll;
	}

	priority_queue<PLI, vector<PLI>, greater<PLI> > q;
	q.push(make_pair(0ll, 1));
	d[1] = 0ll;

	while (!q.empty()) {
		PLI now = q.top();
		q.pop();
		int u = now.second;
		if (visited[u])
			continue;

		visited[u] = true;

		for (int i = 0; i < adj[u].size(); ++i) {
			int v = adj[u][i].first;
			ll w = adj[u][i].second;
			if (d[v] > d[u] + w) {
				d[v] = d[u] + w;
				p[v] = u;
				q.push(make_pair(d[v], v));
			}
		}
	}
}

int main() {

	scanf("%d%d", &n, &m);

	for (int i = 0; i < m; ++i) {

		int x, y;
        ll w;

		scanf("%d%d%lld", &x, &y, &w);

		adj[x].push_back(make_pair(y, w));
		adj[y].push_back(make_pair(x, w));
	}

	spfa();

	if (d[n] == 1000000000000ll) {
		puts("-1");
		return 0;
	}

	int cur = n, pcnt = 0;

	while (cur) {
		ans[pcnt++] = cur;
		cur = p[cur];
	}

	for ( int i = pcnt - 1; i >= 0; --i )
		printf("%d ", ans[i]);

	return 0;

}
