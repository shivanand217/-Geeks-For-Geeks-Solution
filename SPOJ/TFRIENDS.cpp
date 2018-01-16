#include <bits/stdc++.h>

#define mp make_pair
#define ll long long
#define pb push_back

#define ss second
#define ff first
#define si(x) scanf("%d",&x)
#define slli(x) scanf("%lld",&x)
#define pi(x) printf("%d",x)

#define mx5 100005
#define mx6 1000006
#define mod 1000000007

#define rep(i,n) for(int i=0; i<n; i++)
#define fast std::ios::sync_with_stdio(false)
#define gc() getchar()
#define pc(x) putchar(x)

using namespace std;

typedef pair<int,int> pii;

const int mxx = 1004;
// special value of infinity to take for getting rid of overflows
const int inf = 0x3f3f3f3f;

/******************* Problem Code *****************/

vector<int> graph[ mxx ];
vector<int> rev[ mxx ];
bool vis[mxx];
int cnt;
char st[202];

void dfs1(int u, stack<int>& st) {
    vis[u] = true;
    for(int i=0; i < graph[u].size(); i++){
        int to = graph[u][i];
        if(vis[to]==false){
            dfs1(to, st);
        }
    }
    st.push(u);
}

void dfs2(int u) {
    vis[u] = false;
    for(int i=0; i < rev[u].size(); i++) {
        int to = rev[u][i];
        if(vis[to] == true){
            dfs2(to);
        }
    }
}

int main() {
    int t,n;
    scanf("%d", &t);

    while(t--) {
        cnt = 0;
        scanf("%d", &n);
        for(int i=1; i<=n;i++) {
            graph[i].clear();
            rev[i].clear();
        }
        stack<int> st1;
        for(int i=0; i<n; i++) {
            scanf("%s" , st);
            for(int j=0; j<strlen(st); j++) {
                if(st[j] == 'Y') {
                    graph[i + 1].push_back(j+1);
                    rev[j + 1].push_back(i+1);
                }
            }
        }

        memset(vis, false, sizeof(vis));
        for(int i=1; i <= n; i++) {
            if(vis[i] == false) {
                dfs1(i, st1);
            }
        }

        while(!st1.empty()) {
            int u = st1.top();
            st1.pop();
            if(vis[u] == true) {
                dfs2(u);
                cnt++;
            }
        }
        printf("%d\n", cnt);
    }

    return 0;
}
