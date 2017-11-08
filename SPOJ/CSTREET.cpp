/** Approach : Kruskals MST **/

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

pair<ll, pair<int,int> > edges[400005];
int par[1055];
int n,m,t,a,b;
ll p,c;

void init() {
    for(int i=1; i<=n; i++)
        par[i]=i;
}

int root(int x) {
    while(x != par[x]) {
        par[x] = par[par[x]];
        x = par[x];
    } return x;
}

void union_(int x,int y) {
    int p = root(x);
    int q = root(y);
    par[p] = par[q];
}

ll kruskals() {
    ll sum=0;
    ll cost;
    for(int i=0;i<m;i++) {
		a = edges[i].ss.ff;
		b = edges[i].ss.ss;
        cost = edges[i].ff;
        if(root(a) != root(b)) {
            sum += cost;
            union_(a,b);
        }
    }

	return sum;
}

int main() {
    si(t);
    while(t--) {
        slli(p);
        si(n);
        init();
        si(m);
        for(int i=0;i<m;i++) {
            si(a), si(b), slli(c);
            c *= p;
			edges[i] = make_pair(c,make_pair(a,b));
        }
        sort(edges,edges+m);
        ll cost = kruskals();
        printf("%lld\n",cost);
    }

	return 0;
}

