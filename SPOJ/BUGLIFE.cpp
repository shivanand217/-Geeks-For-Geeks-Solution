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

vector<int> graph[mx4];
int par[10005];
int n,m,x,y,root1,root2;
bool ans;

void init() {
    for(int i=1; i<=n; i++) {
        par[i] = -1;
	}
}

void dfs(int source) {
    for(int i=0; i<graph[source].size(); i++) {
        if(par[graph[source][i]] == -1) {
            if(par[source] == 1)
				par[graph[source][i]]=0;
			else
                par[graph[source][i]]=1;
			dfs(graph[source][i]);
		} else if(par[source] == par[graph[source][i]]){
			ans = false;
            return;
		}
    }
}

int main() {

    int t;
    si(t);

    for(int k=1; k<=t; k++) {

        ans = true;
        si(n), si(m);
        init();

        for(int i=1;i<=n;i++){
            graph[i].clear();
        }

        rep(i,m) {
            si(x), si(y);
            graph[x].pb(y);
            graph[y].pb(x);
        }

        for(int i=1; i<=n; i++){
            if(par[i] == -1){
				par[i]=1;
                dfs(i);
            }

            if(!ans)
				break;
        }

		printf("Scenario #%d:\n", k);
        if(ans == false) {
            printf("Suspicious bugs found!\n");
        } else {
			printf("No suspicious bugs found!\n");
        }
    }

	return 0;
}
