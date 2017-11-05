// Approach: Segment Tree

#include<bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
#define ll long long
#define max3(a,b,c) max(a, max(b,c))
#define max4(a,b,c,d) max(a, max(b, max(c,d)))
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

// policy based data structure
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
#define ordered_set tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
using namespace __gnu_pbds;


const int MAX = 1e5+10;

void buildTree(int node, int s, int e, vector<vector<int> > a , vector<int> sTree[]) {
	if(s == e) {
		sTree[node] = a[s];
		return;
	}

	int mid = (s+e)/2;
    buildTree( 2*node+1 , s, mid, a, sTree );
    buildTree( 2*node+2 , mid+1, e, a, sTree );
    merge(sTree[2*node+1].begin(), sTree[2*node+1].end(), sTree[2*node+2].begin(), sTree[2*node+2].end(), back_inserter(sTree[node]));
}

int queryRec(int node, int s, int e, int x, int y, int k, vector<vector<int> > a, vector<int> sTree[]) {
      if( x > e || y < s )
            return 0;

      if( x <= s && y >= e ) {
        return (upper_bound(sTree[node].begin(), sTree[node].end() , k) - sTree[node].begin());
      }

      int mid = (s+e)/2;
      int p1 = queryRec(2*node+1 , s, mid, x, y, k, a, sTree);
      int p2 = queryRec(2*node+2 , mid+1, e, x, y, k, a, sTree);
      return p1 + p2;
}

int query(int start, int End, int k, vector<vector<int> > a, int n, vector<int> sTree[]) {
    return queryRec(0, 0, n-1, start, End, k, a, sTree);
}

int main() {
    int n,tmp;
    si(n);

	vector<int> v1;
    vector<vector<int> > a;

	// n*n array
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            si(tmp);
			v1.push_back(tmp);
        }
			a.push_back(v1);
    }

    vector<int> sTree[MAX];
    buildTree( 0, 0, n-1, a, sTree );

    int Q, l, r, k;
    si(Q);

    while(Q--) {
        si(l), si(r), si(k);
		cout<<query(l, r, k, a, n, sTree)<<endl;
    }

    return 0;
}

