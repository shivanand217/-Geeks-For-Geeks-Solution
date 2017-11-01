/** Author : Shiv anand **/

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
#define nl putchar('\n')
#define mx5 100005
#define mx6 1000006
#define rep(i,n) for(int i=0; i<n; i++)
using namespace std;

ll arr[mx5],val;
pair<ll, ll> Tree[4 * mx5] , ans;
int n,Q,u,v,in,x,y;
char k;

void build( int node, int s, int e ) {

    if(s == e) {
	Tree[node] = make_pair(arr[s] , -1LL);
        return;
    }

    int mid = (s+e)/2;

    int left = 2*node;
    int right = 2*node+1;

    build(left, s, mid);
    build(right, mid+1, e);

    Tree[node] = make_pair(max(Tree[left].ff,Tree[right].ff), max(max(Tree[left].ss, Tree[right].ss), Tree[left].ff + Tree[right].ff));
}

void update(int node, int s, int e, int index, ll value) {
    if(s == e) {
        Tree[node] = make_pair(value , -1LL);
        return;
    }

    int mid = (s+e)/2;

    int left = 2*node;
    int right = left+1;

    if(index <= mid){
        update(left, s, mid, index, value);
    } else {
	update(right, mid+1, e, index, value);
    }

    Tree[node] = make_pair(max(Tree[left].ff,Tree[right].ff), max(max(Tree[left].ss, Tree[right].ss), Tree[left].ff + Tree[right].ff));
}

pair<ll,ll> query(int node, int s, int e, int l, int r) {
    if(s == l && e == r) {
	return Tree[node];
    }

    int mid = (s+e)/2;
    int left = 2*node;
    int right = left+1;

    if(r <= mid){
        return query(left, s, mid, l, r);
    }

    if(l > mid){
	return query(right, mid+1, e, l, r);
    }

    pair<ll, ll> queryLeft , queryRight;

    queryLeft = query(left, s, mid, l, mid);
    queryRight = query(right, mid+1, e, mid+1, r);

    return make_pair(max(queryLeft.ff,queryRight.ff),max(max(queryLeft.ss,queryRight.ss), queryLeft.ff + queryRight.ff));
}

int main() {
    si(n);
    for(int i=0; i<n; i++){
        slli(arr[i]);
    }

    build(1, 0, n-1);
    si(Q);

    while(Q--) {
        scanf("\n%c ",&k);

        if(k == 'U') {
	    si(in), slli(val);
	    --in;
            update(1, 0, n-1, in, val);

        } else {
            si(u), si(v);
            u--, v--;
            ans = query(1, 0, n-1, u, v);
            printf("%lld", ans.ss);
            nl;
        }
    }

   return 0;
}
