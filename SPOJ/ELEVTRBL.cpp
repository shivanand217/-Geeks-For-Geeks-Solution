/** approach: bfs **/

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

bool vis[mx6];

int main() {
   int f,s,g,u,d,fir,sec;
   si(f), si(s), si(g), si(u), si(d);

   for(int i=1;i<=f;i++) {
        vis[i]=false;
   }

   vis[s]=true;
   queue<pair<int,int> > bfs;
   bfs.push(make_pair(1,s));

   pair<int,int> pi;
   int ans = INT_MAX;

   while(!bfs.empty()) {

		pi = bfs.front();
        fir = pi.ff;
        sec = pi.ss;

        bfs.pop();
        if(sec==g){
            ans=min(ans,fir);
            --ans;
            break;
        }
        if(sec+u <= f) {
            if(!vis[sec+u]){
				bfs.push(make_pair(fir+1,sec+u));
                vis[sec+u]=true;
            }
        }
        if(sec-d>=1) {
            if(!vis[sec-d]){
                bfs.push(make_pair(fir+1,sec-d));
                vis[sec-d]=true;
            }
        }
   }

   if(ans==INT_MAX) {
        printf("use the stairs\n");
   } else {
        printf("%d\n",ans);
   }

   return 0;
}
