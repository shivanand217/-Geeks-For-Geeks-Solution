
#include<bits/stdc++.h>
#define mp make_pair
#define ll long long
#define pb push_back
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
vector<int> graph[10005];
int vis[10005];
int color[10005];
int min_steps = 1;
void dfs(int v,int parent){
    vis[v]=1;
    if(parent != -1) {
        if(color[v] != color[parent])
            min_steps++;
    }
    int p;
    for(int i=0; i<graph[v].size(); i++){
        p = graph[v][i];
        if(vis[p] == 0){
            dfs(p , v);
        }
    }
}
int main() {
    fast;
    int n,m,tmp;
    cin>>n;
    for(int i=1;i<=n;i++) {
        vis[i] = 0;
    }
    for(int i=2; i<=n; i++) {
        cin>>tmp;
        graph[i].pb(tmp);
        graph[tmp].pb(i);
    }
    for(int i=1;i<=n;i++){
        cin>>color[i];
    }
    dfs(1, -1);
    cout<<min_steps<<endl;
    return 0;
}
