#include<bits/stdc++.h>
using namespace std;
const int mx = 100005;
#define ll long long

ll segtree[ 4* mx ];
ll lazy[ 4 * mx ];

/** no need of array just lazy update and lazy query on segtree **/

void update(int node, int s, int e, int p, int q,ll v) {
    /** reflects pending update needed **/

    if(lazy[node] != 0) {
        segtree[node] += (e-s+1)*lazy[node];
        if(s != e) {
            lazy[2*node] += lazy[node];
            lazy[2*node+1] += lazy[node];
        }
        lazy[node] = 0;
    }

    /** lies outside **/
    if( e < s || p > e || q < s )
        return;

    /** current segment completly lie in range **/
    if( p <= s && e <= q ) {
        segtree[node] += (e-s+1)*v;
        if(s != e) {
            lazy[2*node] += v;
            lazy[2*node+1] += v;
        }
        /** must return from here **/
        return;
    }

    int mid = (s + e)/2;
    update(2*node, s, mid, p, q, v);
    update(2*node+1, mid+1, e, p, q, v);
    segtree[node] = segtree[2*node] + segtree[2*node+1];
    return;
}

ll query( int node, int s, int e, int p, int q ) {
    if(lazy[node] != 0) {
        segtree[node] += (e-s+1)*lazy[node];
        if(s != e) {
            lazy[2*node] += lazy[node];
            lazy[2*node+1] += lazy[node];
        }
        lazy[node]=0;
    }
    /** outside range **/
    if(e < s || p > e || q < s)
        return 0;
    /** completly in range **/
    if( p <= s && e <= q ) {
        return segtree[node];
    }
    int mid = (s + e)/2;
    ll left = query(2*node, s, mid, p, q);
    ll right = query(2*node+1, mid+1, e, p, q);
    return (left + right);
}

int main() {

    int t, n, m, type, p, q;
    cin>>t;

    ll v;
    while(t--) {
        memset(segtree,0,sizeof(segtree));
        memset(lazy,0,sizeof(lazy));
        cin>>n>>m;
        for(int i = 0; i < m; i++) {
            cin>>type;
            if( type == 0 ) {
                cin>>p>>q>>v;
                --p, --q;
                update(1, 0, n-1, p, q, v);
            } else {
                cin>>p>>q;
                --p,--q;
                ll ans = query(1, 0, n-1, p, q);
                cout<<ans<<endl;
            }
        }
    }

    return 0;
}
