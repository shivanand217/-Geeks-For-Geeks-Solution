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

const int mxx = 3e5+7;
// special value of infinity to take for getting rid of overflows
const int inf = 0x3f3f3f3f;

/******************* Problem Code *****************/

/** Merge sort tree will work fine for this problem but will give TLE on KQUERY **/

long long m, arr[mxx];
vector<long long> tree[ 4 * mxx ];

/* memory O(n * log(n)) **/

void build( int node, int s, int e ) {
    if( s == e ) {
        tree[node].push_back(arr[ s ]);
        return;
    }

    int mid = (s + e)/2;
    int le ,ri;

    le = 2*node;
    ri = 2*node+1;

    build( le, s , mid );
    build( ri, mid + 1, e );

    /** This merges the two child node of segtree
        by merge operation of merge sort
        and append to current node of segtree **/
    merge(tree[le].begin(),tree[le].end(),
          tree[ri].begin(),tree[ri].end(),
          back_inserter(tree[node]));
}

long long query(int node,int s,int e,ll i,ll j,long long k) {
    if( e < s || i > e || j < s )
        return 0LL;

    /** complete in range **/
    if( i <= s && e <= j ) {
        /** binary search on this node of segtree to find no. of element greater than k present here **/
        ll ans = ( tree[node].size() - ( upper_bound(tree[node].begin(),tree[node].end(),k) - tree[node].begin()) );
        return ans;
    }

    int mid = (s + e) / 2;
    int le = 2*node;
    int ri = 2*node+1;

    return ( query(le, s, mid, i, j, k) + query(ri, mid+1, e, i, j, k) );
}

int main() {

    int n;
    long long l,r,a,b,c;
    long long k, last_ans = 0LL;;
    scanf("%d", &n);

    for( int i = 0; i < n; i++ ) {
        scanf( "%lld", &arr[i] );
    }

    build( 1, 0, n - 1 );
    scanf("%d",&m);

    for( int i = 0; i < m; i++ ) {
        scanf("%lld%lld%lld", &l, &r, &c);
        a = l ^ last_ans;
        b = r ^ last_ans;
        k = c ^ last_ans;
        last_ans = query( 1, 0, n-1, a-1, b-1, k );
        printf("%lld\n" , last_ans);
    }

    return 0;
}
