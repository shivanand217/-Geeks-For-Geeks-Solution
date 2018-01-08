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

const int mxx = 100001;
// special value of infinity to take for getting rid of overflows
const int inf = 0x3f3f3f3f;

int a[ 302 ][ 302 ];
bool vis[ 302 ][ 302 ];
int n , m , size_ ;

void bfs( int x , int y ) {
    queue< pii > q;

    vis[ x ][ y ] = true;
    q.push( pii( x , y) );

    int s , t;
    pii p;

    while ( !q.empty() ) {

        p = q.front();
        q.pop();

        s = p.ff;
        t = p.ss;
        size_++;

        if( s + 1 < n ) {
            if( a[ s + 1 ][ t ] == 1 && vis[ s + 1 ][ t ] == false ) {
                q.push( pii( s + 1 , t ) );
                vis[ s + 1 ][ t ] = true;
            }
        }
        if( t + 1 < m ) {
            if( a[ s ][ t + 1 ] == 1 && vis[ s ][ t + 1 ] == false ) {
                q.push( pii( s , t + 1 ) );
                vis[ s ][ t + 1 ] = true;
            }
        }
        if( s - 1 >= 0 ) {
            if( a[ s - 1 ][ t ] == 1 && vis[ s - 1 ][ t ] == false ) {
                q.push( pii( s - 1 , t ) );
                vis[ s - 1 ][ t ] = true;
            }
        }
        if( t - 1 >= 0 ) {
            if( a[ s ][ t - 1 ] == 1 && vis[ s ][ t - 1 ] == false ) {
                q.push( pii( s , t - 1 ) );
                vis[ s ][ t - 1 ] = true;
            }
        }

    }

    //cout<<size_<<endl;
}

int main() {
    while( 1 ) {
        cin>>n>>m;

        if( n == 0 && m == 0 )
            break;

        for( int i = 0 ; i < n; i++ ) {
            for( int j = 0 ; j < m; j++ ) {
                //scanf("%d", &a[ i ][ j ] );
                cin>>a[ i ][ j ];
                vis[ i ][ j ] = false;
            }
        }

        map< int , int > mo;

        for( int i = 0; i < n ; i++ ) {
            for( int j = 0 ; j < m; j++ ) {

                size_ = 0;

                if( a[ i ][ j ] == 1 && vis[ i ][ j ] == false ) {
                    bfs( i , j );
                }

                if( size_ > 0 ) {
                    mo[ size_ ]++;
                }
                    //size_ = 0;
            }
        }

        int cnt = 0;
        for ( auto i = mo.begin(); i != mo.end(); i++ ) {
            cnt += i->second;
        }

        cout<<cnt<<endl;

        for( auto i = mo.begin(); i != mo.end(); i++ ) {
            cout<< i->ff << " " << i->ss<<endl;
        }
    }

    return 0;
}

