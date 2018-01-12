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

const int mxx = 100005;
// special value of infinity to take for getting rid of overflows
const int inf = 0x3f3f3f3f;

/******************* Problem Code *****************/

struct node {
    long long first_max, second_max;
};

struct node segtree[ 4 * mxx ];
long long arr[ mxx ];
int value1, value2, value3, value4, v1, v2;
struct node p;

void build( int node, int s, int e ) {
    if( s == e ) {
        segtree[ node ].first_max = arr[ s ];
        segtree[ node ].second_max = arr[ s ];
        return;
    }

    int mid = ( s + e )/2;
    int le = 2*node;
    int ri = 2*node+1;

    build( le, s, mid );
    build( ri, mid+1, e );

    value1 = segtree[ le ].first_max;
    value2 = segtree[ le ].second_max;
    value3 = segtree[ ri ].first_max;
    value4 = segtree[ ri ].second_max;

    v1 = max( value1, max( value2, max( value3, value4)) );

    if( value1 == v1 ) {
        v2 = max( value2, max( value3, value4 ) );
    } else if( value2 == v1 ){
        v2 = max( value1, max( value3, value4 ));
    } else if( value3 == v1 ){
        v2 = max( value1, max( value2, value4 ));
    } else if( value4 == v1 ){
        v2 = max( value1, max( value3, value2 ));
    }

    segtree[ node ].first_max = v1;
    segtree[ node ].second_max = v2;
}

struct node query( int node, int s, int e, int l, int r ) {
    if( s > e || r < s || l > e ) {
        return (p);
    }

    /** completely in range **/
    if( s == l && e == r ) {
        return segtree[ node ];
    }

    int mid = ( s + e )/2;
    int le = 2*node;
    int ri = 2*node + 1;

    struct node left , right;

    if( r <= mid ) {
        return query( le, s, mid, l, r );
    }
    if( l > mid ) {
        return query( ri, mid + 1, e, l, r );
    }

    /** if query lies midway **/
    left = query( le, s, mid, l, mid );
    right = query( ri, mid+1, e, mid+1, r );

    struct node result;
    value1 = left.first_max;
    value2 = left.second_max;
    value3 = right.first_max;
    value4 = right.second_max;

    v1 = max( value1, max( value2, max( value3, value4)) );

    if( value1 == v1 ) {
        v2 = max( value2, max( value3, value4 ) );
    } else if( value2 == v1 ){
        v2 = max( value1, max( value3, value4 ));
    } else if( value3 == v1 ){
        v2 = max( value1, max( value2, value4 ));
    } else if( value4 == v1 ){
        v2 = max( value1, max( value3, value2 ));
    }

    result.first_max = v1;
    result.second_max = v2;

    return result;
}

void update( int node, int s, int e, int index, int value ) {

    if( s == e ) {
        arr[ index ] = value;
        segtree[ node ].first_max = arr[ index ];
        segtree[ node ].second_max = arr[ index ];
        return;
    }

    int mid = ( s + e )/2;
    int le = 2*node;
    int ri = 2*node+1;

    if( index <= mid ) {
        update( le, s, mid, index, value );
    }
    if( index > mid ) {
        update( ri, mid+1, e, index, value );
    }

    value1 = segtree[ le ].first_max;
    value2 = segtree[ le ].second_max;
    value3 = segtree[ ri ].first_max;
    value4 = segtree[ ri ].second_max;

    v1 = max( value1, max( value2, max( value3, value4)) );

    if( value1 == v1 ) {
        v2 = max( value2, max( value3, value4 ) );
    } else if( value2 == v1 ){
        v2 = max( value1, max( value3, value4 ));
    } else if( value3 == v1 ){
        v2 = max( value1, max( value2, value4 ));
    } else if( value4 == v1 ){
        v2 = max( value1, max( value3, value2 ));
    }

    segtree[ node ].first_max = v1;
    segtree[ node ].second_max = v2;
}

int main() {
    int  x, y, q, n;
    char c;
    p.first_max = 0LL;
    p.second_max = 0LL;

    scanf( "%d", &n );
    for( int i = 1; i <= n; i++ ) {
        scanf("%lld\n", &arr[ i ] );
    }

    build( 1, 0, n-1 );
    scanf("%d", &q);

    struct node ans;

    while( q-- ) {
        cin>>c>>x>>y;

        if(c == 'Q') {
            --x, --y;
            ans = query( 1, 0, n-1, x, y );
            printf("%lld\n", ans.first_max+ans.second_max );
        } else {
            --x;
            update( 1, 0, n-1, x, y );
        }
    }

    return 0;
}
