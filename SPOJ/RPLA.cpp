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

int read_int(){
	char r;bool start=false,neg=false;int ret=0;
	while(true){r=getchar();if((r-'0'<0 || r-'0'>9) && r!='-' && !start){continue;}
		if((r-'0'<0 || r-'0'>9) && r!='-' && start){	break;	}if(start)ret*=10;start=true;
		if(r=='-')neg=true;else ret+=r-'0';}if(!neg)return ret;else	return -ret;}

int t,n,m,x,y;
vector<int> graph[mx4];

void solve(vector<int> indegree, map<int, set<int> >& ans) {
    queue<pair<int,int> > top_sort;
    for(int i=0; i<n; i++) {
        if(indegree[i] == 0){
            top_sort.push(mp(0,i));
        }
    }

	pair<int,int> p;
    while(!top_sort.empty()) {
        p = top_sort.front();
        top_sort.pop();
        ans[p.ff].insert(p.ss);
        for(int i=0; i<graph[p.ss].size(); i++){
            indegree[graph[p.ss][i]]--;
            if(indegree[graph[p.ss][i]] == 0) {
                top_sort.push( mp(p.ff+1,graph[p.ss][i]) );
            }
        }
    }
}

int main() {

   si(t);
   for(int k=0; k < t ; k++) {
	getchar();
    si(n), si(m);
    vector<int> indegree(n);

	for(int i=0; i<n; i++){
        indegree[i]=0;
	}

    for(int i=0; i<n; i++){
        graph[i].clear();
    }

    for(int i=0; i<m; i++) {
        si(x), si(y);
        graph[y].pb(x);
        indegree[x]++;
    }

    map<int,set<int> > ans;
	solve(indegree,ans);

	printf("Scenario #%d:\n", (k+1));
    for(auto it=ans.begin(); it!=ans.end();
					++it) {
                    for(auto it2 = (it->second).begin();
							it2 != (it->second).end(); ++it2) {
								printf("%d %d\n", (it->first+1),*it2);
							}
					}
   }
	return 0;
}

