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

vector<int> graph[mx5];
int n,k,tmp,node;
int indegree[mx5];
int superior[mx5];

int main() {

    si(n);
    si(k);
    memset(indegree, 0, sizeof(indegree));
    memset(superior, 0, sizeof(superior));

    queue<int> top_sort;

    for(int i=1; i<=k; i++){
        si(tmp);
        for(int j=0; j<tmp; j++){
            si(node);
                graph[i].pb(node);
                indegree[node]++;
        }
    }

    for(int i=1; i<=n; i++){
        if(indegree[i] == 0){
            top_sort.push(i);
        }
    }

    int prevpop = 0;
    while(!top_sort.empty()) {
        int p = top_sort.front();
        top_sort.pop();
        superior[p] = prevpop;

        for(int i=0; i<graph[p].size(); i++){
            indegree[graph[p][i]]--;
            if(indegree[graph[p][i]] == 0){
                top_sort.push(graph[p][i]);
            }
        }
			prevpop = p;
    }

    for(int i=1;i<=n;i++) {

        printf("%d\n",superior[i]);
    }

    return 0;
}
