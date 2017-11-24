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

struct po {
	int lo;
	int hi;
}a[mx5];

int solve(int lo,int hi,int val) {
    int mid;
    int ans;
    while(lo<=hi) {
        mid=lo+(hi-lo)/2;
        if(a[mid].lo<=val&&a[mid].hi>=val){
			ans=mid;
			break;
        }
        if(a[mid].lo > val){
            hi=mid-1;
        } else {
            lo=mid+1;
        }
    }
    return ans;
}

int main() {
   int n,q,tmp;
   si(n);

   for(int i=1; i<=n; i++) {
        si(tmp);
		if(i==1){
            a[i].lo=1;
            a[i].hi=tmp;
		} else {
            a[i].lo=a[i-1].hi+1;
            a[i].hi=a[i].lo+tmp-1;
		}
   }

   si(q);
   int query;

   while(q--) {
		si(query);
        int ans = solve(1,n,query);
        printf("%d\n",ans);
   }

   return 0;
}

