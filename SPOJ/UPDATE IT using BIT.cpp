
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
typedef pair<int, int> pii;

const int mxx = 100006;
// special value of infinity to take for getting rid of overflows
const int inf = 0x3f3f3f3f;

int BIT[400006];

int sum(int index ) {
    int s = 0;
    while(index) {
        s += BIT[index];
        index = index-(index&(-index));
    }
    return s;
}

void update(int index, int val){
    while(index < 400000) {
        BIT[index]+=val;
        index = index + (index & (-index));
    }
}

int main() {
    int t;
    scanf("%d",&t);
    int n,u,l,r,val,tmp,q;
    while(t--) {
        scanf("%d %d",&n, &u);
        while(u--) {

            scanf("%d %d %d",&l, &r, &val);
            ++l , ++r;
            update( l , val );
            update( r + 1, (-1)*val );
        }

        scanf("%d",&q);

        while(q--) {
            scanf("%d", &tmp);
            ++tmp;
            int ans = sum(tmp);
            printf("%d\n", ans);
        }
    }
    return 0;
}

