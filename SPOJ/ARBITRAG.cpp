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

long double d[101][101];

int main() {
    int n,p;
    long double r;
    map<string,int> fr;
    string st,s1,s2;

    for(int kl=1; ;kl++) {

		si(n);
		fr.clear();
        memset(d,0.0,sizeof(d));

        if(n == 0){
            break;
        }

        for(int i=1; i<=n; i++) {
            cin>>st;
            fr[st]=i;
        }

        si(p);

        for(int i=0;i<p;i++) {
            cin>>s1;
            cin>>r;
            cin>>s2;
            d[fr[s1]][fr[s2]]=r;
        }

        for(int k=1;k<=n;k++){
            for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
                    d[i][j] = max(d[i][j],d[i][k]*d[k][j]);
				}
            }
        }

        int flag=0;
        for(int i=1;i<=n;i++) {
			for(int j=1;j<=n;j++) {
                if( d[i][j]-1 > 0.000000001 && (i==j) ) {
                    flag=1;
                }
			}
        }

        if(flag == 1) {
            printf("Case %d: Yes\n",kl);
        } else {
            printf("Case %d: No\n",kl);
        }

	}

    return 0;
}
