/** approach : articulation point **/

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
#define mx5 100010
#define mx6 1000010
#define MOD 1000000007
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
#define ordered_set tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
using namespace __gnu_pbds;

const int mx=10005;

bool vis[mx];
int disc[mx];
int low[mx];
int parent[mx];
bool AP[mx];
vector<int> graph[mx];
int n,m,cnt,x,y,_time;

void solve(int u) {

	int child=0;
	vis[u]=true;
	++_time;
	disc[u] = low[u] = (_time);

	for(int i=0; i<graph[u].size(); i++) {
		int v = graph[u][i];

		if(vis[v]==false) {
			child++;
			parent[v]=u;
			solve(v);

			low[u] = min(low[u],low[v]);

			if( parent[u] ==-1 && child>1 ){
				AP[u]=true;
			}

			if( parent[u] !=-1 && low[v] >= disc[u] ){
				AP[u]=true;
			}

		} else if(v != parent[u]) {
			low[u] = min(low[u],disc[v]);
		}
	}
}

void articulation_point() {

	for(int i=1;i<=n;i++){
		parent[i]=-1;
		vis[i]=false;
		AP[i]=false;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==false){
			solve(i);
		}
	}
	for(int i=1;i<=n;i++){
		if(AP[i]==true){
			cnt++;
		}
	}
}

int main() {
	while(1) {
		si(n), si(m);

		if(n==0 && m == 0){
			break;
		}

		_time=0;
        for(int i=1;i<=n;i++){
            graph[i].clear();
        }
		for(int i=1;i<=m;i++){
			si(x), si(y);
			graph[x].pb(y);
			graph[y].pb(x);
		}

		cnt=0;
		articulation_point();
		printf("%d\n",cnt);
	}
	return 0;
}
