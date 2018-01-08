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

/** Simple and Persistant segment tree **/

typedef pair<int,int> pii;

const int mxx = 60000;
// special value of infinity to take for getting rid of overflows
const int inf = 0x3f3f3f3f;

struct tree {
    int prefixMaxSum, maxSum, suffixMaxSum, sum;
};

int arr[ mxx ];
struct tree segtree[ 4 * mxx ];
int n , q, x, y;

void build( int node, int s, int e ) {

    if ( s == e ) {
        segtree[ node ].prefixMaxSum = segtree[ node ].suffixMaxSum = segtree[ node ].maxSum = segtree[ node ].sum = arr[ s ];
        return;
    }

    int mid = ( s + e )/2;
    int left = 2 * node;
    int right = 2 * node + 1;

    build ( left, s, mid );
    build ( right, mid + 1, e );

    segtree[ node ].sum = segtree[ left ].sum + segtree[ right ].sum;
    segtree[ node ].prefixMaxSum = max( segtree[ left ].prefixMaxSum , segtree[ left ].sum + segtree[ right ].prefixMaxSum );
    segtree[ node ].suffixMaxSum = max( segtree[ right ].suffixMaxSum, segtree[ right ].sum + segtree[ left ].suffixMaxSum );
    segtree[ node ].maxSum = max( segtree[ node ].prefixMaxSum , max( segtree[ node ].suffixMaxSum, max( segtree[left].maxSum , max( segtree[right].maxSum , segtree[ left ].suffixMaxSum + segtree[ right ].prefixMaxSum ))));

}

struct tree query( int node, int s, int e, int lo, int hi ) {

    if( s == lo && e == hi ) {
        return segtree[ node ];
    }

    int mid = ( s + e )/2;

    if( hi <= mid ) {
        return query( 2 * node , s, mid, lo, hi );
    }

    if( lo > mid ) {
        return query( 2 * node + 1, mid + 1, e, lo, hi );
    }

    struct tree left;
    struct tree right;
    struct tree result;

    left = query( 2*node, s, mid, lo , mid );
    right = query( 2*node + 1, mid + 1, e, mid + 1, hi );

    result.sum = left.sum + right.sum;
    result.prefixMaxSum = max( left.prefixMaxSum , left.sum + right.prefixMaxSum );
    result.suffixMaxSum = max( right.suffixMaxSum, right.sum + left.suffixMaxSum );
    result.maxSum = max( result.prefixMaxSum , max( result.suffixMaxSum, max( left.maxSum , max( right.maxSum , left.suffixMaxSum + right.prefixMaxSum ))));

    return result;

}

int main() {

    scanf( "%d" , &n );

    for(int i = 0 ; i < n ; i++ ) {
        scanf( "%d", &arr[ i ] );
    }

    build( 1 , 0 , n - 1 );
    scanf( "%d", &q );

    struct tree res;

    while( q-- ) {

        scanf( "%d %d", &x, &y );
        --x, --y;
        res = query( 1 , 0 , n-1 , x, y );

        printf( "%d\n", res.maxSum );
    }

    return 0;
}
