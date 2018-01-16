#include <bits/stdc++.h>

#define mp make_pair
#define ll long long
#define pb push_back

#define ss second
#define ff first
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

typedef pair<int,int> pii;

const int mxx = 1e5+7;
const int mxx2 = 100005;
// special value of infinity to take for getting rid of overflows
const int inf = 0x3f3f3f3f;

/******************* Problem Code *****************/
const int k = 1e6 + 7;
int prime[k + 1];

void seive() {
    memset(prime,0,sizeof(prime));
    prime[0] = prime[1] = 1;

    for(ll i=2; i < k; i++) {
        if( prime[i] == 0 ) {
            for( ll j = i*i; j < k; j += i ) {
                prime[j] = 1;
            }
        }
    }
}

int arr[ mxx ];
int segtree[ 4 * mxx ];
int lazy[ 4 * mxx ];

void build(int node, int s, int e) {
    if(s == e) {
        if( prime[arr[s]] == 0 ) {
            segtree[node] = 1;
        } else {
            segtree[node] = 0;
        }
        return;
    }

    int mid = (s + e)>>1;
    build(2*node, s, mid);
    build(2*node+1, mid+1, e);

    segtree[node] = segtree[2*node] + segtree[2*node+1];
}

void update(int node, int s, int e, int l, int r, int v) {
    if( lazy[ node ] != 0 ) {
        if( prime[ lazy[ node ] ] == 0 ) {
            segtree[ node ] = (e - s + 1);
        } else {
            segtree[node] = 0;
        }

        if(s != e) {
            lazy[ 2*node ] = lazy[ node ];
            lazy[ 2*node+1 ] = lazy[ node ];
        }
        lazy[node] = 0;
    }
    if( l > e || r < s )
        return;

    if( l <= s && e <= r ) {
        if(prime[v] == 0) {
            segtree[node] = ( e - s + 1 );
        } else {
            segtree[node] = 0;
        }
        if(s != e) {
            lazy[2*node] = v;
            lazy[2*node+1] = v;
        }
        lazy[node]=0;
        return;
    }

    int mid = (s + e)>>1;
    update( 2*node, s, mid, l, r, v);
    update( 2*node+1, mid + 1, e, l, r, v);

    segtree[node] = (segtree[2*node] + segtree[2*node+1]);
}

int query(int node, int s, int e, int l, int r) {

    if( lazy[node] != 0 ) {
        if(prime[lazy[node]] == 0) {
            segtree[node] = (e - s + 1);
        } else {
            segtree[node] = 0;
        }
        if(s != e) {
            lazy[2*node] = lazy[node];
            lazy[2*node+1] = lazy[node];
        }
        lazy[node] = 0;
    }

    int mid = (s + e)>>1;

    if( l > e || r < s )
        return 0;

    if( l <= s && e <= r ) {
        return segtree[node];
    }

    int lef = query(2*node, s, mid, l, r);
    int rig = query(2*node+1, mid + 1, e, l, r);

    return (lef + rig);
}

int main() {
    seive();

    int n, l, r, t, q, v, type;
    scanf("%d",&t);

    for( int ca = 1; ca <= t; ca++ ) {
        printf("Case %d:\n",ca);
        scanf("%d%d", &n, &q);

        memset(lazy,0,sizeof(lazy));
        memset(segtree,0,sizeof(segtree));

        for(int i = 0; i < n; i++ ) {
            scanf("%d", &arr[i]);
        }

        build(1, 0, n-1);

        while( q-- ) {
            scanf("%d", &type);

            if(type == 0) {
                scanf("%d%d%d", &l, &r, &v);
                update(1, 0, n-1, l-1, r-1, v);
            } else {
                scanf("%d%d", &l, &r);
                int ans = query(1, 0, n-1, l-1, r-1);
                printf("%d\n", ans);
            }
        }
    }

    return 0;
}
