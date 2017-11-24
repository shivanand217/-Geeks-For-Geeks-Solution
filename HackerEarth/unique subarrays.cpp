/** approach : two pointers **/

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
   set<ll> s;

   while(t--) {
		s.clear();
		si(n);
        for(int i=0;i<n;i++){
            slli(a[i]);
        }
        int i=0,j=0;
        ll sum=0;
        ll ans;
        sum+=n;
        ans=0;
		while(i<n){
            while(j<n && s.find(a[j]) == s.end()){
                s.insert(a[j]);
                j++;
            }
            ans += (1LL*(j-i)*(j-i+1))/2;
            s.erase(a[i]);
            i++;
		}
        printf("%lld\n",ans);
   }

   return 0;
}

