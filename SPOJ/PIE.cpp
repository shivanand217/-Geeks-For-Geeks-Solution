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

/******************* Problem Code *****************/
#define pi 3.14159265358979323846264338327950

long double arr[mxx];
int friends, n;

bool satisfy( long double volume ) {
    if( volume == 0.0 )
        return false;

    int fr = 0;
    /** if all the friends are satisfied with this value of pie then return true **/

    for( int i = 0; i < n; i++ ) {
        fr += (int)(arr[i] / volume);
    }

    if( fr >= friends )
        return true;

    return false;
}

long double binary_search_() {
    long double lo = 0.0 , hi = arr[n-1] , max_ , volume;

    while ( hi - lo >= 1e-6 ) {

        volume = (lo + hi)/2;

        if( satisfy( volume ) ) {
            lo = volume;
        } else {
            hi = volume;
        }

    }
    return lo;
}

int main() {
    int t;
    scanf("%d", &t);

    while(t--) {
        scanf( "%d %d", &n, &friends );

        /** one for himself too **/
        friends++;

        for( int i = 0; i < n; i++ ) {
            scanf("%Lf", &arr[i]);
        }
        sort( arr, arr+n );

        for( int i=0; i<n; i++ ) {
            arr[i] = arr[i]*arr[i]*pi;
        }
        long double ans = binary_search_();

        printf( "%.4Lf\n", ans );
    }

    return 0;
}
