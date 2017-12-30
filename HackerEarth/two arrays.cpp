/**
    matrix optimization
    Sub matrix sum
    binary search
**/

#include <bits/stdc++.h>
#define mp make_pair
#define ll long long
#define pb push_back
#define se second
#define fi first
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

/** O(n * m * log( min(n, m) ) **/

int p[2002][2002];
long long a[2002];
long long b[2002];
int n,m;

ll query(int li, int lj, int ri, int rj) {
    int res = p[ri][rj];

    if( li > 0 )
        res = res - p[li - 1][rj];

    if( lj > 0 )
        res = res - p[ri][lj - 1];

    if( li > 0 && lj > 0 )
        res = res + p[li-1][lj-1];

    return res;
}


int main() {
    fast;
    int n,m,k;
    cin>>n>>m>>k;

    for(int i=1; i <= n; i++) {
        cin>>a[i];
    }

    for(int i=1; i <= m; i++) {
        cin>>b[i];
    }

    for(int i=0;i<=n;i++) {
        p[i][0]=0;
    }

    for(int j=0;j<=m;j++) {
        p[0][j]=0;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            p[i][j]=0;
            if(a[i]==b[j])
                p[i][j]=1;
        }
    }

    long long ans=0;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            p[i][j] += p[i][j-1];
        }
    }

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            p[i][j] += p[i-1][j];
        }
    }

    ll cnt = 0;

	for(int i=1; i <= n; i++) {

        for( int j=1; j <= m; j++ ) {

			int len = min(i , j);

			int l = 0;
			int r = len-1;
			int ans = -1;

			while(l <= r) {

				int mid = ( l + r ) / 2;

				if( query( i-mid , j-mid , i , j ) >= k) {
					r = mid - 1;
					ans = mid;
				}
				else
					l = mid + 1;
			}

			if(ans != -1)
				cnt += (len - ans) * 1LL;
		}
	}

    cout<<cnt<<endl;

    /** for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++) {

            int lo=1,hi=min(i,j);

            while(lo < hi) {
                int mid = (lo+hi)>>1;
                int sum = query(i, j, mid);
                if(sum >= k) {
                    hi = mid;
                }
            }
        }
    } **/

    return 0;
}
