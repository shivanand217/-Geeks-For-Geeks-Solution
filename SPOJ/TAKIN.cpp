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

#define MAX 21
using namespace std;

typedef pair<int,int> pii;

const int mxx = 100001;
// special value of infinity to take for getting rid of overflows
const int inf = 0x3f3f3f3f;

/******************* Problem Code *****************/

long long a[ MAX ];
long long sum[ (1<<MAX) ];


int main() {
    int t;
    scanf("%d",&t);

    int n;
    long long m;

    while(t--) {
        scanf("%d%lld", &n, &m);

        for(int i=0; i<n; i++) {
            scanf("%lld\n",&a[i]);
        }

        /** go through all the subsets **/
        for(int i = 0; i < ( 1<<n ); i++) {
            for(int j = 0; j < n; j++) {
                if( i&(1<<j) ) {
                    sum[i] = sum[i ^ (1<<j)] + a[j];
                }
            }
        }
        long long best = 0;

        for(int i=0; i < (1<<n); i++){
            if(sum[i] <= m && sum[i] > best){
                best=sum[i];
            }
        }

        printf("%lld\n", best);
    }

    return 0;
}
