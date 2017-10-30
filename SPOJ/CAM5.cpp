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
bool vis[mx5];
int t,e,n,cnt,x,y;

void dfs(int x) {
    vis[x]=true;
    for(int i=0; i<graph[x].size(); i++){
        if(vis[graph[x][i]] == false){
            dfs(graph[x][i]);
        }
    }
}

int main(){
    si(t);
    getchar();

    while(t--) {

		cnt=0;
        si(n);
        memset(vis, false, sizeof(vis));

        for(int i=0; i<n; i++){
            graph[i].clear();
        }

        si(e);
        while(e--) {
            si(x), si(y);
            graph[x].push_back(y);
            graph[y].push_back(x);
        }

        for(int i=0; i<n; i++) {
            if(vis[i] == false){
				cnt++;
                dfs(i);
            }
        }

        printf("%d\n", cnt);
    }

    return 0;
}
