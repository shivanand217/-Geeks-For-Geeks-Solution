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
#define MOD 1000000007
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
#define ordered_set tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
using namespace __gnu_pbds;
ll a[mx5];

int main() {
   int t,n;
   si(t);

   while(t--) {
		si(n);
        for(int i=0;i<n;i++) {
			slli(a[i]);
        }
        int prev=0;
        int i=0,j=0;
		ll ans=0;

        while(j < n) {
            if(a[j] == a[j+1]) {
				while(a[j]==a[j+1]) {
					j++;
				}
				ans += (ll)((j-prev+1)*(j-prev+2))/2;
                j++;
                prev=j;
            } else {
				ans += (ll)((j-prev+1)*(j-prev+2))/2;
				j++;
				prev=j;
            }
        }

		printf("%lld\n",ans);
   }

   return 0;
}

