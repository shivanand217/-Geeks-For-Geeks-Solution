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

int n,m,x,y;
vector<int> graph[mx5];
int par[mx5];
bool ans;

void dfs(int source) {

    par[source] = 0;
    stack<int> st;
    st.push(source);

    while(!st.empty()) {

        int k=st.top();
        st.pop();

        for(int i=0; i<graph[k].size(); i++){
            if(par[graph[k][i]] == -1){
                if(par[k] == 1){
					par[graph[k][i]]=0;
                } else {
					par[graph[k][i]]=1;
                }
                st.push(graph[k][i]);
            } else {
                if(par[k] == par[graph[k][i]])
                    {ans=false;break;}
            }
        }
    }

}

int main() {

	memset(par, -1, sizeof(par));
	ans = true;
    si(n);
    si(m);

    for(int i=0; i<m; i++) {
    		si(x), si(y);
			x--, y--;
            graph[x].pb(y);
            graph[y].pb(x);
    }

	int cnt=0;

	for(int j=0; j<n; j++) {
		if(par[j] == -1 && cnt==1) {
			ans = false;
			break;
		}
        if(par[j] == -1 && cnt==0){
            dfs(j);
            cnt++;
        }
	}

	if(ans){
		printf("YES\n");
	} else {
		printf("NO\n");
	}

    return 0;
}
