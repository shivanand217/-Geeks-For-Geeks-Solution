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

const int mxx = 100005;
// special value of infinity to take for getting rid of overflows
const int inf = 0x3f3f3f3f;

/******************* Problem Code *****************/
int segtree[4 * mxx];
string s;

void build(int node,int ss,int se) {
    if(ss == se) {
        segtree[node] = (s[ss] - '0');
        return;
    }

    int mid = (ss + se)/2;
    build(2*node, ss, mid);
    build(2*node+1, mid+1, se);
    segtree[node] = (segtree[2*node] & segtree[2*node+1]);
}

void update(int node,int ss,int se,int idx) {
    if(ss == se) {
        segtree[ss] ^=1;
        return;
    }
    int mid = (ss + se)/2;
    if(idx <= mid) {
        update(2*node, ss, mid, idx);
    }
    if(idx > mid) {
        update(2*node+1, mid+1, se, idx);
    }
    segtree[node] = (segtree[2*node] & segtree[2*node+1]);
}

int query(int node,int ss,int se,int l,int r) {
    if(se < ss || l > se || r < ss || segtree[node])
        return -1;
    if(ss == se)
        return ss;
    int mid = (ss + se)/2;
    int lef , rig;
    lef = query(2*node, ss, mid, l, r);
    if(lef != -1 )
        return lef;
    else
        return query(2*node+1, mid+1, se,  l, r);
}

int main() {
    fast;
    int t,typ,l,r,q,idx;
    cin>>t;

    cin>>s;
    build(1, 0, s.length()-1);
    cin>>q;

    while(q--) {
        cin>>typ;
        if(typ == 1) {
            cin>>idx;
            idx--;
            if(s[idx]=='1')
                s[idx]='0';
            else
                s[idx]='1';
            update(1, 0, s.length()-1, idx);
        } else {
            cin>>l>>r;
            l--,r--;
            int ans = query(1, 0, s.length()-1, l, r);
            if(ans == -1) {
                cout<<ans<<endl;
            } else {
                cout<<ans+1<<endl;
            }
        }
    }

    return 0;
}
