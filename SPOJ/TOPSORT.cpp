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

const int maxn = 11111;
int n,m,indegree[maxn];
vector<int> graph[maxn];
vector<int> order;
set<int> nexNode;
int cnt=0;

void topology() {

    int u,v;
    set<int> :: iterator it;

    while(!nexNode.empty()) {

        auto it = nexNode.begin();
        u = *it;
        nexNode.erase(nexNode.begin());
        order.push_back(u);
        cnt++;

        for(int i=0; i<graph[u].size(); i++) {
            v = graph[u][i];
            indegree[v]--;
            if(indegree[v] == 0){
                nexNode.insert(v);
            }
        }
    }
}

int main() {
    int n,m,x,y;
    si(n);
    si(m);

    for(int i=1; i<=n; i++){
        indegree[i]=0;
    }

    for(int i=1; i<=m; i++){
        si(x);
        si(y);
        graph[x].push_back(y);
        indegree[y]++;
    }

    for(int i=1; i<=n; i++){
        if(indegree[i] == 0)
			nexNode.insert(i);
    }

    topology();

    if(cnt != n){
        printf("Sandro fails.");
        nl();
        return 0;
    }

    for(int i=0;i<order.size(); i++){
        printf("%d ",order[i]);
    } nl();
	return 0;
}
