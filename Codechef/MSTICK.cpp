/** k,c,u,f are my favourite variables **/

/** author : shiv anand **/

#include<bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
#define ll int
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

ll arr[mx5];

struct str {
	ll min_;
	ll max_;
} tree[4*mx5];

void build(ll node, ll s, ll e){

    if(s == e) {
        tree[node].min_ = arr[s];
        tree[node].max_ = arr[s];
        return;
    }

    ll mid=((s+e)/2);
    build(2*node,s,mid);
    build(2*node+1,mid+1,e);

    tree[node].min_ = min(tree[2*node].min_,tree[2*node+1].min_);
    tree[node].max_ = max(tree[2*node].max_,tree[2*node+1].max_);

}

ll query(ll node, ll s, ll e, ll lo, ll hi, int type) {

    if( s > e || hi < lo )
		return -1;

    if(s == lo && e == hi) {
        if(type == 1){ // min query
            return tree[node].min_;
        } else { // max query
        	return tree[node].max_;
        }
    }

    ll mid = ((s+e)/2);

    if(hi <= mid){
        return query(2*node,s,mid,lo,hi,type);
    }
    if(lo > mid){
        return query(2*node+1,mid+1,e,lo,hi,type);
    }

    ll left = query(2*node,s,mid,lo,mid,type);
    ll right = query(2*node+1,mid+1,e,mid+1,hi,type);

    if(type == 1) {
        return min(left,right);
    } else {
        return max(left,right);
    }
}

int main() {
   int N,L,R,Q;
   si(N);

   for(int i=1; i<=N; i++){
        si(arr[i]);
   }

   build(1,1,N);
   si(Q);

   while(Q--) {
        si(L), si(R);
        ++L, ++R;

        ll min_ = query(1,1,N,L,R,1);
        ll max_ = query(1,1,N,L,R,2);

        ll t1 = query(1,1,N,1,L-1,2);
        ll t2 = query(1,1,N,R+1,N,2);

        ll p = max(t1,t2); // max in outer range

        double ans = (min_*1.0) + max(((max_ - min_)*1.0/2*1.0) , p*1.0);

        printf("%.1f\n", ans);
   }

   return 0;
}
