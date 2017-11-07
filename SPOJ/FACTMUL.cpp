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

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
#define ordered_set tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
using namespace __gnu_pbds;

int main() {
   ll n,i;
   ll prev,cur,ans;
   ll mod = 109546051211ll;
   ans=1ll;
   prev=1ll;
   slli(n);

   for(i=2; i<=n; i++) {
        cur = (prev*i)%mod;
        ans = ((ans%mod)*cur)%mod;
        if(ans==0)
			break;
        prev = cur;
   }

   printf("%lld\n",ans);
   return 0;
}
