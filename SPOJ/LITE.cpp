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

/** In this problem also like : problem HORRIBLE , we don't need to allocate memory
    to the array , just lazy propagation and range query
    will do the work **/

/** Similar problem is on Codechef flip coin where we have to
    flip coins between a range then output number of
    coins in a range which are up . initially all the coins
    are down **/


int tree[270000];
bool lazy[270000];

void update( int node, int st, int en, int a, int b ) {

	/** if lazy signal of a node is ON then first update it **/
	if(lazy[node]) {
		lazy[node] = false;
		tree[node] = en-st+1 - tree[node];

        /** if this is not a leaf node then propagate its value to its nodes **/
		if(st < en) {
			lazy[node<<1] = !lazy[node<<1];
			lazy[1+(node<<1)] = !lazy[1+(node<<1)];
		}
	}

	if( st > en || a > en || b < st )
        return ;

	if( a<=st && en<=b ) {
		tree[node] = en-st+1 - tree[node];
		if(st < en) {
			lazy[node<<1] = !lazy[node<<1];
			lazy[1+(node<<1)] = !lazy[1+(node<<1)];
		}
        /** must return from here we don't need to go further **/
		return;
	}

	int mid = (st+en)/2;
    /** recur for update in left and right child **/
	update((node<<1),st,mid,a,b);
	update((node<<1)+1,mid+1,en,a,b);

	if(st < en)
        tree[node] = tree[node<<1] + tree[(node<<1)+1];
}

int query(int node, int st, int en, int a, int b) {
	if(st>en || a > en || b < st)
        return 0;

    /** similar lazy things like our update function **/
	if(lazy[node]) {
		lazy[node] = false;
		tree[node] = en-st+1-tree[node];
		if(st < en) {
			lazy[node<<1] = !lazy[node<<1];
			lazy[(node<<1)+1] = !lazy[(node<<1)+1];
		}
	}

	if( a <= st && en <= b ) {
		return tree[node];
	}

	int mid = (st+en)/2;
	int t1 = 0, t2 = 0;
	t1 = query((node<<1),st,mid,a,b);
	t2 = query((node<<1)+1,mid+1,en,a,b);

	return t1+t2;
}


int main() {
	int n, m, q, a, b;
	scanf("%d %d",&n,&m);

	while(m--) {
		scanf("%d %d %d",&q,&a,&b);
		if(q==1)
            printf("%d\n",query(1,1,n,a,b));
		else
            update(1,1,n,a,b);
	}

	return 0;
}
