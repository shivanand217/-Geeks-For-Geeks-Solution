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
#define fck std::ios::sync_with_stdio(false);
#define mx5 100010
#define mx6 1000010
#define mod 1000000007
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
#define ordered_set tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
using namespace __gnu_pbds;

ll a[mx5];
ll Segtree[4*mx5+10];

ll gcd(ll a,ll b){
    if(a==0)
		return b;
	return gcd(b%a,a);
}

void multiply(ll F[2][2],ll M[2][2]) {
    ll x = (F[0][0]*M[0][0]+F[0][1]*M[1][0])%mod;
    ll y = (F[0][0]*M[0][1]+F[0][1]*M[1][1])%mod;
    ll k = (F[1][0]*M[0][0]+F[1][1]*M[1][0])%mod;
    ll p = (F[1][0]*M[0][1]+F[1][1]*M[1][1])%mod;

    F[0][0]=x;
    F[0][1]=y;
    F[1][0]=k;
    F[1][1]=p;
}

void power(ll F[2][2],ll n){
    if(n==0 || n==1)
		return;
    ll M[2][2] = {
				  {1LL,1LL},
				  {1LL,0LL}
				 };
    power(F,n/2);
    multiply(F,F);
    if((n&1)) {
        multiply(F,M);
    }
}

ll fib(ll n){
    ll F[2][2] = {
				  {1LL,1LL},
				  {1LL,0LL}
				 };
    if(n == 0)
		return 0;
    power(F,n-1);
    return (F[0][0]);
}

void build(int node,int s,int e){
    if(s==e) {
		Segtree[node]=a[s];
		return;
    }

    int mid = ((s+e)/2);
    build(2*node,s,mid);
    build(2*node+1,mid+1,e);

    Segtree[node] = __gcd(Segtree[2*node],Segtree[2*node+1]);
}

ll query(int node,int s,int e,int l,int r) {
    if(s>e || l>r || e<l || r<s)
		return 0;

    if(l<=s && e<=r){
        return Segtree[node];
    }

    int mid=((s+e)/2);
    ll q1 = query(2*node,s,mid,l,r);
    ll q2 = query(2*node+1,mid+1,e,l,r);

    return __gcd(q1,q2);
}

int main() {
   int n,l,r;
   int q;

   si(n),si(q);

   for(int i=1;i<=n;i++) {
		slli(a[i]);
		a[i] = fib(a[i]);
   }

   build(1,1,n);

   while(q--) {
        si(l),si(r);
        ll ans = query(1,1,n,l,r);
        printf("%lld\n",ans);
   }

   return 0;
}

