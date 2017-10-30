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
#define mx5 100005
#define mx6 1000006
#define mx4 5004
#define rep(i,n) for(int i=0; i<n; i++)
using namespace std;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef unordered_set<int> usi;
typedef map<int,int> mi;
typedef unordered_map<int,int> umi;

int n,m,k,target,dependent;
set<int> graph[105], node;
int indegree[105];
vector<int> top_order;

void solve() {
    for(int i=1; i<=n; i++) {
		if(indegree[i] == 0) {
                node.insert(i);
		}
    }
    while( node.size() > 0 ) {
		int p = *(node.begin());
        node.erase(node.begin());
        top_order.pb(p);

        for(auto it=graph[p].begin(); it!=graph[p].end(); ++it) {
            int v = *it;
            indegree[v]--;
			if(indegree[v] == 0) {
                    node.insert(v);
			}
        }
    }
}

int main() {

   si(n), si(m);
   for(int i=1; i<=n; i++) {
		indegree[i]=0;
   }

   for(int i=0; i<m; i++) {
		si(target), si(k);
        for(int j=0; j<k; j++) {
            si(dependent);
            graph[dependent].insert(target);
        }
        indegree[target] += k;
   }

   solve();
   for(auto it = top_order.begin(); it != top_order.end(); ++it) {
        printf("%d ", *it);
   } nl();

   return 0;
}
