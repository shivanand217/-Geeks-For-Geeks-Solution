#include <bits/stdc++.h>
using namespace std;

const int mxx = 100005;
// special value of infinity to take for getting rid of overflows
const int inf = 0x3f3f3f3f;

/******************* Problem Code *****************/

struct segment {
    int cnt0, cnt1, cnt2;
    void modify() {
        int tmp = cnt0;
        cnt0 = cnt2;
        cnt2 = cnt1;
        cnt1 = tmp;
    }
    void merge_node(segment left ,segment right) {
        cnt0 = left.cnt0 + right.cnt0;
        cnt1 = left.cnt1 + right.cnt1;
        cnt2 = left.cnt2 + right.cnt2;
    }
} tree[ 4 * mxx ];
int lazy[ 4 * mxx ];

void build(int node, int s, int e) {
    if(s > e)
        return;

    if(s == e) {
        tree[node].cnt0=1;
        tree[node].cnt1=0;
        tree[node].cnt2=0;
        return;
    }

    int mid = (s + e)/2;
    build(2*node, s, mid);
    build(2*node+1, mid+1, e);

    tree[node].merge_node(tree[2*node] , tree[2*node+1]);
}

void update( int node, int s, int e, int l, int r ) {
    if(lazy[node]%3 == 1) {
        tree[node].modify();
        if(s != e) {
            lazy[2*node] += 1;
            lazy[2*node+1] += 1;
        }
    } else if(lazy[node]%3 == 2) {
        tree[node].modify();
        tree[node].modify();
        if(s != e) {
            lazy[2*node] += 2;
            lazy[2*node+1] += 2;
        }
    } else if(lazy[node] > 0 && lazy[node]%3 == 0) {
        if(s != e) {
            lazy[2*node] += lazy[node]%3;
            lazy[2*node+1] += lazy[node]%3;
        }
    }
    lazy[node] = 0;

    /** Outside range **/
    if( e < s || l > e || r < s ) {
        return;
    }

    /** completely in query range **/
    if( l <= s && e <= r ) {
        tree[node].modify();
        if(s != e) {
            lazy[2*node]++;
            lazy[2*node]++;
        }
        return;
    }

    int mid = (s + e)/2;
    update(2*node, s, mid, l, r);
    update(2*node+1, mid+1, e, l, r);

    tree[node].merge_node( tree[2*node], tree[2*node+1] );
}

segment query(int node, int s, int e, int l, int r) {
    segment seg;
    seg.cnt0 = 0;
    seg.cnt1 = 0;
    seg.cnt2 = 0;

    if( lazy[node]%3 == 1 ) {
        tree[node].modify();
        if(s != e) {
            lazy[2*node]++;
            lazy[2*node+1]++;
        }
    } else if( lazy[node]%3 == 2 ) {
        tree[node].modify();
        tree[node].modify();
        if(s != e) {
            lazy[2*node] += 2;
            lazy[2*node] += 2;
        }
    } else if( lazy[node] > 0 && lazy[node]%3 == 0 ) {
        if( s != e ) {
            lazy[2*node]+=lazy[node]%3;
            lazy[2*node+1]+=lazy[node]%3;
        }
    }
    lazy[node] = 0;

    /** outside range **/
    if(e < s || l > e || r < s)
        return seg;

    /** completely in query range **/
    if( l <= s && e <= r ) {
        return tree[node];
    }

    int mid = (s + e)/2;
    segment lef,rig;

    lef = query(2*node, s, mid, l, r);
    rig = query(2*node+1, mid+1, e, l, r);
    seg.merge_node(lef, rig);
    return seg;
}

int main() {
    std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n, q, type, l, r;
    cin>>n>>q;

    memset(lazy, 0, sizeof(lazy));
    build( 1, 0, n-1 );

    while( q-- ) {
        cin>>type>>l>>r;
        if(type == 0) {
            update(1, 0, n-1, l, r);
        } else {
            segment ans = query(1, 0, n-1, l, r);
            cout<<ans.cnt0<<endl;
        }
    }

    return 0;
}
