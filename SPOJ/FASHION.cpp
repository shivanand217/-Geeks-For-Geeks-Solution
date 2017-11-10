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
    int n,i,t,sum,m[1005],f[1005];
    si(t);
    while(t--) {
		si(n);
		sum = 0;

		for(i = 0; i < n; i++) {
			scanf("%d",&m[i]);
		}
		for(i = 0; i < n; i++) {
			scanf("%d",&f[i]);
		}
		sort(m,m+n);
		sort(f,f+n);
		for(i = 0; i < n; i++) {
			sum = sum + (m[i] * f[i]);
		}
		printf("%d\n",sum);
    }
    return 0;
}
