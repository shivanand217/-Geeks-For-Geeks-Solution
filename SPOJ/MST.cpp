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

vector< pair<ll,int> > graph[mx6];
pair< ll, pair<int,int> > krus[mx6];
int par[mx6];
int n,m;

void init() {
    for(int i=0;i<n;i++) {
        par[i]=i;
    }
}

int root(int x){
    while(par[x] != x) {
        par[x] = par[par[x]];
        x = par[x];
    }
    return x;
}

void union_(int x,int y) {
    int p = root(x);
    int q = root(y);
    par[p] = par[q];
}

ll solve() {
    ll s=0;
    int x,y;
    ll wei;
    for(int i=0;i<m;i++) {
        x = krus[i].ss.ff;
        y = krus[i].ss.ss;
        wei = krus[i].ff;
        if(root(x) != root(y)){
            s += wei;
            union_(x,y);
        }
    }
		return s;
}

int main() {

   int u,v;
   ll w;
   si(n), si(m);
   init();

   for(int i=0;i<m;i++) {
        si(u), si(v), slli(w);
		--u, --v;
        graph[u].push_back(make_pair(w,v));
        graph[v].push_back(make_pair(w,u));
        krus[i] = make_pair(w,make_pair(u,v));
   }

   sort(krus,krus+m);
   ll sum = solve();
   printf("%lld\n",sum);

   return 0;
}
