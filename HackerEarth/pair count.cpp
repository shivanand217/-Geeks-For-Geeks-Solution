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
#define mod 1000000007
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
#define ordered_set tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
using namespace __gnu_pbds;

ll arr[mx5];

int main() {
    fck;
    ll t,n,k,m,pi,tij,ko;
    cin>>t;

    while(t--) {
        cin>>n>>k>>m;
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        ll ans=LLONG_MAX,tmp;
        int index;

        for(int i=0; i<n; i++) {
            tmp=0LL;
            ll p=arr[i];
            for(int j=0;j<p;j++) {
                cin>>tij;
                tmp += tij;
            }
            tmp += ( k*arr[i] + m*(arr[i]-1) );
            //cout<<tmp<<endl;
            if(ans > tmp){
                ans = tmp;
                index = i+1;
            }
        }
        cout<<index<<" "<<ans<<endl;
    }

    return 0;
}
