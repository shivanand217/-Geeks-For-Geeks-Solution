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
#define mx4 5004
#define rep(i,n) for(int i=0; i<n; i++)
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
int dist[mx5];
bool vis[mx5];
int n,x,y;
ll ans;

int bfs(int source) {

    queue<int> qu;
	qu.push(source);

    memset(dist, 0, sizeof(dist));
    memset(vis, 0, sizeof(vis));
    vis[source] = true;

    while(!qu.empty()) {

        int k = qu.front();
        qu.pop();

        for(int i=0; i<graph[k].size(); i++){
            if(!vis[graph[k][i]]){
                vis[graph[k][i]] = true;
                dist[graph[k][i]] = dist[k] + 1;
                qu.push(graph[k][i]);
            }
        }
    }

    int ver;
    ll val = LLONG_MIN;

    for(int i=1; i<=n; i++){
        if(dist[i] > val){
			val = dist[i];
			ver = i;
        }
    }

	ans = (long long)dist[ver];
    return ver;
}

int main() {
    si(n);

    for(int i=0; i<n-1; i++) {
		si(x), si(y);

        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    if(n==1){
        printf("0\n");
    } else {
        bfs(bfs(1));
        printf("%lld\n", ans);
    }
   return 0;
}
