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

const int mxx = 3e5+7;
// special value of infinity to take for getting rid of overflows
const int inf = 0x3f3f3f3f;

/******************* Problem Code *****************/

#define all(v) (v.begin() , v.end())

long long m, arr[mxx];
vector<long long> tree[ 4 * mxx ];

void build( int node, int s, int e ) {
    if( s == e ) {
        tree[node].pb(arr[ s ]);
        return;
    }

    int mid = (s + e)/2;
    int le ,ri;

    le = 2*node;
    ri = 2*node+1;

    build( le, s , mid );
    build( ri, mid + 1, e );

    /** This merges the two child node of segtree
        by merge operation of merge sort
        and append to current node of segtree **/
    merge(tree[le].begin(),tree[le].end(),
          tree[ri].begin(),tree[ri].end(),
          back_inserter(tree[node]));
}

vector<long long> query(int node,int s,int e,int i,int j) {
    if( e < s || i > e || j < s ) {
        vector<long long> p;
        return p;
    }

    /** complete in range **/
    if( i <= s && e <= j ) {
        return ( tree[node] );
    }

    int mid = (s + e) / 2;
    int le = 2*node;
    int ri = 2*node+1;

    if(j <= mid) {
        return query(le, s, mid, i, j);
    };
    if(i > mid) {
        return query(ri, mid+1, e, i, j);
    }

    vector<long long> lef , rig;
    lef = query(le, s, mid, i, mid);
    rig = query(ri, mid+1, e, mid+1, j);
    vector<long long> res;

    merge(lef.begin(), lef.end(), rig.begin(), rig.end(), back_inserter(res));
    return res;
}

int main() {
    int n , m;
    ll a , b;
    int l,r;
    vector<long long> last_ans;

    long long k;
    scanf("%d %d", &n, &m);

    for( int i = 0; i < n; i++ ) {
        scanf( "%lld", &arr[i] );
    }

    build(1, 0, n - 1);
    scanf("%d",&m);

    for( int i = 0; i < m; i++ ) {
        last_ans.clear();
        scanf( "%d %d",&l, &r, &k );
        --l , --r;
        last_ans = query( 1, 0, n-1, l, r);
        cout<<last_ans.size()<<endl;
        //if(last_ans.size() >= k) {
        //    printf("%lld\n", last_ans[k-1]);
        //}
    }

    return 0;
}
