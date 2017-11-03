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
#define mx5 100011
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

int par[mx5];
int n,m,a,b,c;

int find_root(int u) {
    while(u != par[u]){
        par[u] = par[par[u]];
        u = par[u];
    }
    return u;
}

void union_(int x, int y) {
	par[find_root(x)] = par[find_root(y)];
}

int main() {

   si(n), si(m);
   for(int i=0; i<=n; i++){
		par[i] = i;
   }

   map<int,int> Cost;
   unordered_set<int> components;

   rep(i,m) {
		si(a), si(b);
        int root1 = find_root(a);
        int root2 = find_root(b);

        if(root1 == root2){
            continue;
        } else {
            union_(root1, root2);
        }
   }

   for(int i=1; i<=n; i++){
        components.insert(find_root(i));
   }

   for(int i=1; i<=n; i++){
        Cost[find_root(i)] = INT_MAX;
   }

   if(components.size() == 1) {
        printf("0\n");
        return 0;
   } else {

	vector<int> cost;

	for(int i=1; i<=n; i++){
        si(c);
        if(c < 0)
			c=INT_MAX;
        int p = find_root(i);
        Cost[p] = min(Cost[p], c);
	}

    for(auto it=Cost.begin(); it != Cost.end(); ++it) {
        if(it->second == INT_MAX) {
			printf("-1\n");
			return 0;
        }
			cost.pb(it->second);
    }

    int sum=0;
    sort(cost.begin(), cost.end());

    for(int i=1; i<cost.size(); i++) {
        sum += cost[0];
        sum += cost[i];
    }
		printf("%d\n", sum);
   }

   return 0;
}
