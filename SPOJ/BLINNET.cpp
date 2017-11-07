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

pair< int, pair<int,int> > krus[mx5];
set<int> graph[mx5];
int par[mx5];
int n,m,p;

void init() {
    for(int i=1;i<=n;i++) {
        par[i]=i;
    }
}

int root(int x) {
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

int solve() {
    int s=0;
    int x,y;
    int wei;

    for(int i=0; i<p; i++) {
        x = krus[i].ss.ff;
        y = krus[i].ss.ss;
        wei = krus[i].ff;

        if(root(x) != root(y)) {
            s += wei;
            union_(x,y);
        }
    }

	return s;
}

int main() {

   int t,neighbor,cost;
   si(t);
   char faltu[20];

   while(t--) {
        getchar();
		p=0;

        si(n);
        init();

        for(int i=1; i<=n; i++){
            graph[i].clear();
        }

        for(int i=1; i <= n; i++) {
            scanf("%s",faltu);
            si(m);

            for(int j=0; j < m; j++) {
                si(neighbor) , si(cost);
                if(neighbor > i)
                    krus[p++]=make_pair(cost,make_pair(i,neighbor));
            }
		}

        sort(krus, krus+p);
		int sum = solve();
		printf("%d\n", sum);
   }

   return 0;
}
