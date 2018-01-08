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
int n, m, a, b, d;

double dist[102][102];
double ans[102][102];

int main() {

    while(1) {
        si(n);

        if( n == 0 )
            break;

        /** have to find maximum probability of not being caught **/
        si(m);

        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++){
                dist[i][j] = 0.0;
                ans[i][j] = 0.0;
            }
        }

        for(int i=0; i<m; i++) {

            scanf("%d %d %d",&a, &b, &d);
            --a,--b;
            ans[a][b] = d/100.0;
            ans[b][a] = d/100.0;
        }

        for(int i=0; i < n; i++) {
            for(int j=0; j < n; j++) {
                dist[i][j] = ans[i][j];
            } // cout<<endl;
        }

        /** go from i to j via k **/
        for(int k=0; k < n; k++) {
            for(int i=0; i < n; i++) {
                for(int j=0; j < n; j++) {
                    if( i==j || j==k || i==k )
                        continue;
                    if( dist[i][j] < ( dist[i][k] * dist[k][j] ) ) {
                        dist[i][j] = ( dist[i][k] * dist[k][j] );
                    }
                }
            }
        }

        printf( "%.6lf percent\n", dist[0][n-1]*100.0 );
    }

    return 0;
}
