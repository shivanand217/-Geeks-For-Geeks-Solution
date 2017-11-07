/**
	author : shiv anand
	approach : slight modification in dijstra + kruskals
**/

#include<bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
#define ll long long
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

int T,N,M,u,v;
vector<pair<int,ll> > graph[100005];
pair<ll,pair<int,int> > edges[100005];
int par[100005];
ll w;
bool ans;
ll sum1,sum;

void init(){
    for(int i=0;i<N;i++){
        par[i]=i;
    }
}
int root(int x) {
    while(par[x] != x){
        par[x] = par[par[x]];
        x = par[x];
    }
    return x;
}
void union_(int x,int y){
    int p=root(x);
    int q=root(y);
    par[p]=par[q];
}

void modified_dijstra() {
    ll lastAdded[N];
    bool vis[N];
    ll d[N];

    for(int i=0;i<N;i++) {
        lastAdded[i] = 100000000000LL;
        d[i] = 100000000000LL;
    }
    for(int i=0;i<=N;i++) {
        vis[i]=false;
    }

	priority_queue<pair<ll,pair<ll,int> > , vector<pair<ll,pair<ll,int> > > , greater<pair<ll,pair<ll,int> > > > pq;
    pq.push(make_pair(0LL,make_pair(0LL,0)));
    d[0] = 0LL;

    while( !pq.empty() ) {
        int u = pq.top().ss.ss;
        pq.pop();

        if(vis[u] == true) {
            continue;
        }

        for(int i=0; i<graph[u].size();i++) {
            ll wei = graph[u][i].ss;
            int ver = graph[u][i].ff;

            if( ( !vis[ver] && (d[u]+wei < d[ver])) || (d[u]+wei == d[ver] && wei < lastAdded[ver]) ) {
                d[ver] = d[u] + wei;
                lastAdded[ver] = wei;
                pq.push(make_pair(d[ver],make_pair(lastAdded[ver],ver)));
            }
        }
			vis[u]=true;
    }

	sum = 0;
    for(int i=1;i<N;i++) {
        if(lastAdded[i] == 100000000000LL) {
            ans = false;
            break;
        } else {
        	sum += lastAdded[i];
        }
    }
}

void kruskals() {
    int x,y;
    sum1=0;
    ll cost;

    for(int i=0;i<M;i++){
        x = edges[i].ss.ff;
        y = edges[i].ss.ss;
        cost = edges[i].ff;
        if(root(x) != root(y)){
            sum1 += cost;
            union_(x,y);
        }
    }
}

int main() {
   si(T);
   while(T--) {
		ans=true;
		sum=0;
		sum1=0;

        si(N), si(M);
        for(int i=0;i<N;i++){
            graph[i].clear();
        }

        for(int i=0;i<M;i++) {
            si(u), si(v), slli(w);
            graph[u].pb(make_pair(v,w));
            graph[v].pb(make_pair(u,w));
            edges[i] = make_pair(w,make_pair(v,u));
        }

        init();
		sort(edges,edges+M);

        modified_dijstra();
        kruskals();

        if(ans == false) {
            printf("NO\n");
            continue;
        }

        if( sum1 != sum ) {
            printf("NO\n");
        } else {
            printf("YES\n");
        }
   }

   return 0;
}


