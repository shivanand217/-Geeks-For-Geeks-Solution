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

int indegree[26],outdegree[26],v[26],vis[26];
char s[1002];
vector<int> graph[26];

void dfs(int a) {
	vis[a] = 1;
    for(int j=0;j<graph[a].size();j++) {
        if(vis[graph[a][j]] == 0) {
            dfs(graph[a][j]);
        }
    }
}

int main() {

	int t,n,i,j,one,two,exists,connected;
	si(t);

	while(t--) {
		scanf("%d",&n);
		exists = 1;
		one = two = -1;

		for(i=0;i<26;i++) {
			indegree[i] = outdegree[i] = v[i] = vis[i] = 0;
			graph[i].clear();
		}

		for(i=0;i<n;i++){
			scanf("%s",s);
			j = strlen(s);
			outdegree[s[0]-'a']++;
			indegree[s[j-1]-'a']++;
			v[s[0]-'a'] = v[s[j-1]-'a'] = 1;
            graph[s[0]-'a'].pb(s[j-1]-'a');
            graph[s[j-1]-'a'].pb(s[0]-'a');
		}

		connected = 1;

		for(i=0;i<26;i++){
            if(v[i] == 1){
                dfs(i);
                break;
            }
		}

		for(i=0;i<26;i++){
			if(v[i]&&!vis[i]){
				connected = 0;
				break;
			}
		}
		if(!connected) {
			printf("The door cannot be opened.\n");
			continue;
		}

		/** now check for second case either two vertex have odd degree or zero vertex have odd degree **/

		for(i=0;i<26;i++){
			if(indegree[i] != outdegree[i]){
				if(one == -1) one = i;
				else if(two == -1) two = i;
				else{
					exists =  0;
				}
			}
		}

		if(!connected || !exists){
			printf("The door cannot be opened.\n");
			continue;
		}

        /** only one vertex with odd degree cannot possible in undirected graph**/

		exists = 0;

		if(one==-1)
			exists = 1;
        else {
			if((outdegree[one]==indegree[one]+1)&&(indegree[two] = outdegree[two]+1))
				exists = 1;
			else if( (outdegree[two] == indegree[two]+1) && (indegree[one] = outdegree[one]+1) )
				exists = 1;
        }

		if(exists)
			printf("Ordering is possible.\n");
		else
			printf("The door cannot be opened.\n");
	}

	return 0;
}
