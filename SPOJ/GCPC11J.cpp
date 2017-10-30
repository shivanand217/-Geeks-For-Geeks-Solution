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

int t,n,x,y;
vector<int> graph[mx5];
bool vis[mx5];
ll dist[mx5];
ll ans;

int bfs(int s) {

	queue<int> qu;
    qu.push(s);

	memset(dist, 0LL, sizeof(dist));
	memset(vis, false, sizeof(vis));
    vis[s]=true;

    while(!qu.empty()) {
        int k = qu.front();
        qu.pop();
        for(int i=0; i<graph[k].size(); i++){

            if(!vis[graph[k][i]]){

                vis[graph[k][i]]=true;
                qu.push(graph[k][i]);
                dist[graph[k][i]]=dist[k]+1;
            }
        }
    }

    int ver;
    ll val = LLONG_MIN;

    for(int i=0; i<n; i++){
        if(dist[i] > val){
			val = dist[i];
			ver = i;
        }
    }

	ans = (long long)dist[ver];
    return ver;
}

int main(){

   si(t);

   while(t--) {
        si(n);
        for(int i=0; i<n; i++){
            graph[i].clear();
        }
        for(int i=0; i<n-1; i++) {
			si(x), si(y);
			graph[x].push_back(y);
            graph[y].push_back(x);
        }

        bfs(bfs(1));
        printf("%lld\n", ((ans+1)/2));
   }

   return 0;
}
