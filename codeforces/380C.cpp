/** approach : segment tree **/

#include<bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
#define ll long long
#define pb push_back
#define si(x) scanf("%d",&x)
#define slli(x) scanf("%lld",&x)
#define pi(x) printf("%d",x)
#define sp() putchar(' ')
#define nl() putchar('\n')
#define mx5 100010
#define mx6 1000010
#define MOD 1000000007
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
#define ordered_set tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
using namespace __gnu_pbds;

typedef pair<int,int> pii;
typedef pair<int,pii> node;

pii st[4*mx6];
string s;

void build(int i,int l,int r) {

    if(l == r) {
        if(s[l]=='(') {
            st[i]=pii(1,0);
		} else {
            st[i]=pii(0,1);
		}
			return;
    }

    int le=2*i;
    int ri=2*i+1;
    int m=((l+r)/2);

    build(le,l,m);
    build(ri,m+1,r);

    st[i].ff = st[ri].ff + max(0,(st[le].ff-st[ri].ss)); // unused open bracket
    st[i].ss = st[le].ss + max(0,(st[ri].ss-st[le].ff)); // unused close bracket
}

pii query(int v,int l,int r,int x,int y) {

    if(r < x || y < l)
        return pii(0,0);

    if( x <= l && r <= y )
        return st[v];

    int mid = (l+r)/2;
    pii la = query(2*v,l,mid,x,y);
    pii ra = query(2*v+1,mid+1,r,x,y);

    return pii( ra.ff+max(0,la.ff-ra.ss) , la.ss+max(0,ra.ss-la.ff) );
}

int main() {

    cin>>s;
    build(1,0,s.length()-1);

    int Q,L,R;
    si(Q);

    while(Q--) {
        si(L), si(R);
        --L, --R;
        pii an = query(1,0,s.length()-1,L,R);
        printf("%d\n",(R-L+1-(an.ff+an.ss)));
    }

   return 0;
}

