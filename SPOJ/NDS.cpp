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

const int mxx = 1000025;
// special value of infinity to take for getting rid of overflows
const int inf = 0x3f3f3f3f;

int BIT[ mxx ];
int arr[ mxx ];
int n , t, L;

int sum( int pos ) {
    int s = 0;
    while( pos > 0 ) {
        s = max ( s, BIT[ pos ] );
        pos -= ( pos & -pos );
    }
    return s;
}

void update( int pos , int value ) {
    while( pos < mxx ) {
        BIT[pos] = max ( BIT[pos] , value );
        pos += ( pos & -pos );
    }
}

int main() {
    int t ;
    scanf( "%d" , &t );

    int min_ , sequence = 0, L;

    while(t--) {
        min_ = inf;

        scanf( "%d", &n );

        /** contains length of max subsequnce at BIT positions **/
        fill ( BIT , BIT + mxx , 0 );

        for( int i = 0; i < n; i++ ) {
            scanf( "%d" , &arr[ i ] );
            /** for BIT index to be greater than 0 we are incrementing all
                the values in array by one **/
            arr[ i ]++;
        }

        scanf( "%d" , &L );

        for ( int i = 0 ; i < n; i++ ) {
            /** getting max length sequence at current position from BIT **/
            sequence = sum ( arr[ i ] - 1 ) ;

            if( sequence + 1 >= L ) {
                min_ = min( min_ ,  arr[ i ] - 1 ) ;
            }

            update( arr[ i ] , sequence + 1 ) ;
        }

        if( min_ == inf ) {

            printf( "-1\n" );
        } else {

            printf( "%d\n", min_  ) ;
        }
    }

    return 0;
}
