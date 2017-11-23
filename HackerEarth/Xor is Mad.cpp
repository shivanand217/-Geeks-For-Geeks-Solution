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

ll power(ll base,ll exp) {
    ll res=1;
    while(exp>0) {
        if((exp&1))
			res = (res*base)%mod;
		exp/=2;
		base = (base*base)%mod;
    }
    return res;
}

int main() {
   int t;
   si(t);
   ll x;
   int cnt;
   while(t--) {
        slli(x);
		cnt=0;
		while(x) {
            if(!(x&1)){
                cnt++;
            }
            x>>=1;
		}
		ll ans=power(2,cnt)-1;
		printf("%lld\n",ans);
   }

   return 0;
}

