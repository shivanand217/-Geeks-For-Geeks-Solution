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

long long dp[100005];

void pre() {
    for( long long i = 0; i < 100005; i++ ) {
        if( i <= 11 ) {
            dp[ i ] = i;
        } else {
            dp[i] = max( i , dp[i/2] + dp[i/3] + dp[i/4] );
        }
    }
}

long long ans( long long n ) {
    if ( n < 100005 ) {
        return max( n , dp[ n ] );
    }
    return max( n , ans( n/2 ) + ans( n/3 ) + ans( n/4 ) );
}

int main() {
    pre();
    int t = 10;
    long long n , s;
    while( t-- ) {
        cin>>n;
        s = ans( n );
        cout<<s<<endl;
    }

    return 0;
}
