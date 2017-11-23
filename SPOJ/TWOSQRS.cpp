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

/** theorem:
	A number N is expressible as a sum of 2 squares if and only if in the prime factorization
	of N, every prime of the form (4k+3) occurs an even number of times!
**/

bool solve(ll n) {
    if(n==0)
		return false;
	int tmp=sqrt(n);

    for(int i=2;i<=tmp+1;i++){
        if(n%i==0) {
            int cnt=0;
            while(n%i==0) {
				cnt++;
				n/=i;
            }
            if(i==3 || (i-3)%4==0) {
                if(cnt%2!=0)
					return false;
            }
        }
    }

    if( n > 1 && (n==3 || (n-3)%4==0) ) {
        return false;
    }
    return true;
}

int main() {
    int t;
    si(t);

    ll n;
    while(t--) {
        slli(n);
        if(solve(n)){
            printf("Yes\n");
        } else {
            printf("No\n");
        }
	}

    return 0;
}
