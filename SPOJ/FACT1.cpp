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

int p(ll x) {
    ll fl=0;
    ll o = sqrt(x);
    for(ll j=2;j<=o;j++){
        if(x%j==0) {
            fl=1;
            break;
        }
    }
    if(fl==0)
		return 1;
	return 0;
}

int main() {
    ll n;
    ll cnt;

    while(1) {
		slli(n);
		ll m = (ll)sqrt(n);
        for(ll i=2;i<=m;i++) {
            cnt=0LL;
            if(n%i == 0) {
                ll k = n/i;
                if(p(i)==1) {
                    while(n%i==0){
                        cnt++;
						n/=i;
                    }
                    printf("%lld^%lld ",i,cnt);
                }
                if(n==1){
					break;
                }
                cnt=0;
                if(k!=i) {
                    if(p(k)==1){
                        while(n%k==0) {
                            cnt++;
                            n/=k;
                        }
                        printf("%lld^%lld",k,cnt);
                    }
                }
            }
            if(n==1)
				break;
        }
		printf("\n");

    }

    return 0;
}
