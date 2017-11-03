/** k,c,u,f are my favourite variables **/

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
#define mx6 1000010
#define MOD 1000000007
using namespace std;

ll arr[mx5];
ll tree[4*mx5+10];
ll lazy[4*mx5+10];

/** lazy propagation for range sum problem **/

void build(ll node, ll s, ll e) {

    if(s == e) {
        tree[node] = arr[s];
        return;
    }

    ll mid = ((s+e)/2);

    build( 2*node , s, mid );
    build( 2*node+1, mid+1, e );

    tree[node] = tree[2*node] + tree[2*node+1];
}

void updateRange(int node, int s, int e, int l, int r, ll val) {

    if(lazy[node] != 0) {
        tree[node] += (e - s + 1)*lazy[node];

        if(s != e) {
            lazy[2*node] += lazy[node];
			      lazy[2*node+1] += lazy[node];
        }
		        lazy[node] = 0;
    }

    if(s > e || s > r || l > e)
		    return;

    if(s >= l && e <= r) {
        tree[node] += (e - s + 1)*val;

        if(s != e) {
            lazy[2*node] += val;
            lazy[2*node+1] += val;
        }
		    return;
    }

    int mid = ((s+e)/2);

    updateRange( 2*node , s, mid, l, r, val );
    updateRange( 2*node+1 ,mid+1, e, l, r, val );

    tree[node] = tree[2*node] + tree[2*node+1];
}

ll queryRange(ll node, ll s, ll e, ll l, ll r) {

    if(s > e || s > r || e < l)
		    return 0;

    if(lazy[node] != 0) {
		    tree[node] += (e - s + 1)*lazy[node];

        if(s != e) {
            lazy[2*node] += lazy[node];
            lazy[2*node+1] += lazy[node];
        }
			      lazy[node] = 0;
    }

    if(s >= l && e <= r) {
        return tree[node];
    }

    ll mid = ((s+e)/2);

    ll p1 = queryRange( 2*node, s, mid, l, r );
    ll p2 = queryRange( 2*node+1, mid+1, e, l, r );

    return ( p1 + p2 );
}

int main() {

	  ll n,l,r,Q,t,type,value;
    slli(t);

    while(t--) {

    memset(tree, 0, sizeof(tree));
    memset(lazy, 0, sizeof(lazy));

	  slli(n), slli(Q);

    for(ll i=1; i<=n; i++) {
        arr[i]=0LL;
    }

    build(1, 1, n);

    while(Q--) {

		slli(type);
        slli(l), slli(r);

        if(type == 0) {
            slli(value);
			      updateRange( 1, 1, n, l, r, value );

        } else {
        	  ll ans = queryRange( 1, 1, n, l, r );
            printf("%lld\n", ans);
            
        }
    }

    }

	return 0;
}
