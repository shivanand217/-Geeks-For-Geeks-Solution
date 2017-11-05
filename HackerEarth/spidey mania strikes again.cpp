/** Author : shiv anand **/

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

int arr[mx6+8];
pair<int,int> Tree[4*mx6+8];
pair<int,int> kachra = {INT_MAX,0};

void build(int i,int s,int e) {
    if(s==e) {
        Tree[i].ff=arr[s];
        Tree[i].ss=s;
        return;
    }

    int mid=((s+e)/2);
    int l=2*i;
    int r=2*i+1;

    build(l,s,mid);
    build(r,mid+1,e);

    if(Tree[l].ff < Tree[r].ff) {
        Tree[i] = make_pair(Tree[l].ff,Tree[l].ss);
    } else if(Tree[r].ff < Tree[l].ff) {
        Tree[i] = make_pair(Tree[r].ff,Tree[r].ss);
    } else {
        Tree[i] = make_pair(Tree[l].ff,max(Tree[l].ss,Tree[r].ss));
    }
}

pair<int,int> query(int i,int s,int e,int l,int r) {
    if( e < l || s > r )
        return kachra;

    if( l <= s && e <= r ) {
        return Tree[i];
    }

    int mid=((s+e)/2);

	pair<int,int> p = query(2*i,s,mid,l,r);
	pair<int,int> q = query(2*i+1,mid+1,e,l,r);
    pair<int,int> an;

    if(p.ff < q.ff) {
        an = make_pair(p.ff,p.ss);
    } else if(p.ff > q.ff) {
		an = make_pair(q.ff,q.ss);
    } else {
        an = make_pair(p.ff,max(p.ss,q.ss));
    }
	return an;
}

int main() {
   int t;
   si(t);
   while(t--) {
        int N;
        si(N);

        arr[0]=INT_MAX;
        for(int i=1;i<=N;i++) {
            si(arr[i]);
        }

		build(1,1,N);
		int Q;
        si(Q);

        while(Q--) {
            int L,R;
            si(L), si(R);
            pair<int,int> ans = query(1,1,N,L,R);
            printf("%d\n",ans.ss);
        }
   }
   return 0;
}
