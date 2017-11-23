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

int main() {
    int n;
    si(n);
    string s;

    while(n--) {
		cin>>s;
        int cnt[26];
        vector<int> pos[26];
        bool an=false;

        memset(cnt,0,sizeof(cnt));
        for(int i=0;i<s.length();i++) {
            cnt[s[i]-'a']++;
            pos[s[i]-'a'].pb(i);
        }
        for(int i=0;i<26;i++){
            if(cnt[i]>1) {
				an=true;
				break;
			}
        }
        if(an==false){
            printf("-1\n");
            continue;
        }
        int ans=INT_MAX;
        int vis[26]={0};

        for(int i=0;i<26;i++) {
			if(vis[i] == 0 && cnt[i] > 1) {
                int k = pos[i].size()-1;
                int f = pos[i][0];
                int sp = pos[i][k];
                int po = s.length()-1-sp;
                int pq = f-0;
                ans = min(ans,(po+pq));
                vis[i]=1;
			}
        }
			printf("%d\n",ans);
    }

   return 0;
}
