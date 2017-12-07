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
    int t;
    cin>>t;
    while(t--) {
        string s1,s2;
        int n;
        cin>>s1>>s2>>n;
        int cnt=0;
        for(int i=0;i<s1.length();i++){
             cnt += (s1[i]!=s2[i]);
        }
        if(cnt<=n && !((n-cnt)&1)){
            cout<<"Yes\n"<<endl;
        } else {
            cout<<"No"<<endl;
        }
    }

    return 0;
}
