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

int n;
int par[mx5];

void init() {
    for(int i=1; i<=n; i++){
        par[i]=i;
    }
}

int root(int x) {
    while(x != par[x]){
        par[x] = par[par[x]];
        x = par[x];
    }
    return x;
}

void union_(int x, int y) {
    int p = root(x);
    int q = root(y);
    if(p > q){
        par[q] = p;
    } else {
        par[p] = q;
    }
}

int main() {

   int m,Q,u,v,p,q;
   si(n), si(m);

   init();

   for(int i=0; i<m; i++) {
        si(u), si(v);
        p = root(u);
        q = root(v);

        if(p == q)
			continue;
		else {
            union_(u,v);
		}
   }

   si(Q);

   for(int i=0; i<Q; i++) {

        si(u), si(v);

        p = root(u);
        q = root(v);

        if(p == u && q == v) {
            if(p == q) {
                printf("TIE\n");
            } else {
                if(p > q){
                    printf("%d\n",u);
                } else {
                    printf("%d\n",v);
                }
            }
				continue;
        }

        if( p == q ){
            printf("TIE\n");
        } else {
            if(p > q){
                printf("%d\n",u);
            } else {
                printf("%d\n",v);
            }
        }
   }

   return 0;
}
