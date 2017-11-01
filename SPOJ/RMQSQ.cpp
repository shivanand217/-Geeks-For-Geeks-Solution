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
#define mx5 100005
#define mx6 1000006
#define mx4 5004
#define rep(i,n) for(int i=0; i<n; i++)
using namespace std;

const int maxn = 1e5+10;

ll Tree[4*maxn];
ll arr[maxn];

void build(int node, int s, int e) {

    if(s == e){
        Tree[node] = arr[s];
        return;
    }

	int mid = ((s+e)>>1);
    int left = 2*node;
    int right = 2*node+1;

    build(left, s, mid);
    build(right, mid+1, e);
    Tree[node] = min(Tree[left],Tree[right]);

}

ll query(int node,int s,int e,int lo,int hi) {
    if(lo > e || hi < s)
		return INT_MAX;

    if(s >= lo && e <= hi){
        return Tree[node];
    }

    int mid = ((s+e)>>1);
    int left = (2*node);
    int right = (2*node+1);

    return min(query(left,s,mid,lo,hi),query(right,mid+1,e,lo,hi));
}

int main() {
    int n,i,j,Q;
    si(n);

    for( int i=0; i<n; i++ ) {
        slli(arr[i]);
    }

    build(1, 0, n-1);
    si(Q);

    while(Q--) {
        si(i), si(j);
		ll ans = query(1, 0, n-1, i, j);
        printf("%lld\n", ans);
    }

    return 0;
}
