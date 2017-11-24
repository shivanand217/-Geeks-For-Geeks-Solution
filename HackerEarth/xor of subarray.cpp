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
ll a[10005];

int main() {
   int t,z,n;
   si(t);

	while(t--) {
        si(n), si(z);
        for(int i=1;i<=n;i++){
            slli(a[i]);
        }

        int i=0,j;
        ll prev=0LL;
        int pre=1;
        int curr=z+1;
        for(i=1;i<=z;i++) {
            prev^=a[i];
        }

		ll ans=prev;
		int ind = pre;

        while((curr-pre)==z&&(curr<=n)){
            prev^=a[pre];
            prev^=a[curr];
            ans = min(prev,ans);
            if(ans==prev){
                ind=pre+1;
            }
            pre++;
            curr++;
        }

        printf("%d\n",ind);
	}

   return 0;
}

