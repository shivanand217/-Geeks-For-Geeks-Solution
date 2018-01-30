/** Bugs, I will not let you Fuck my dreams **/

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

ll a[mxx];
ll l[mxx];
ll r[mxx];
ll d[mxx];
ll op[mxx];
ll aux[mxx];

int main() {
    int n, m, k, x, y;
    memset(op, 0, sizeof(op));

    scanf("%d %d %d", &n, &m, &k);

    for(int i=1; i<=n; i++) {
        scanf("%d", &a[i]);
    }

    for(int i=1; i<=m; i++) {
        scanf("%d %d %d", &l[i], &r[i], &d[i]);
    }

    for(int i=1; i<=k; i++) {
        scanf("%d %d", &x, &y);
        op[x]++;
        op[y+1]--;
    }

    for(int i=1; i<=m; i++) {
        op[i] += op[i-1];
        aux[l[i]] += d[i]*op[i];
        aux[r[i]+1] -= d[i]*op[i];
    }

    for(int i=1; i<=n; i++) {
        aux[i] += aux[i-1];
        cout<<aux[i]+a[i]<<" ";

    } cout<<endl;

    return 0;
}

