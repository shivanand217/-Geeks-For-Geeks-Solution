/** Approach : DP **/

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
int A[100005],B[100005];

int main() {
	int n1,n2,tot,sum1,sum2,i,j;
	scanf("%d",&n1);
	while(n1) {
		tot = 0, sum1 = 0, sum2 = 0;
		for (int i = 0; i < n1; ++i){
			scanf("%d",&A[i]);
		}

		scanf("%d",&n2);
		for (int i = 0; i < n2; ++i){
			scanf("%d",&B[i]);
		}

		i = 0; j = 0;
		while(i < n1 && j < n2){
			if (A[i] == B[j]){
				tot+= max(sum1, sum2) + A[i];
				sum1 = 0, sum2 = 0;
				i++;j++;
			}
			else if (A[i] > B[j]){
				sum2 += B[j++];
			}
			else {
				sum1 += A[i++];
			}
		}

		for (;i < n1;){
			sum1 += A[i++];
		}
		for (;j < n2;){
			sum2 += B[j++];
		}

		tot += max(sum1, sum2);
		printf("%d\n",tot);
		scanf("%d",&n1);
	}

	return 0;
}
