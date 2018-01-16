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

const int mxx = 111060;
// special value of infinity to take for getting rid of overflows
const int inf = 0x3f3f3f3f;

/******************* Problem Code *****************/

vector<int> graph[mxx];
vector<int> rev[mxx];
int size_[mxx] , comp[mxx];
bool vis[mxx];
int c;

void dfs1(int u, stack<int>& st) {
    vis[u] = true;
    for(int i=0; i < graph[u].size(); i++) {
        int to = graph[u][i];
        if(vis[to] == false) {
            dfs1(to, st);
        }
    }
    st.push(u);
}

void dfs2(int u) {
    size_[c]++;
    comp[u] = c;
    vis[u] = false;
    for(int i=0; i < rev[u].size(); i++) {
        int to = rev[u][i];
        if(vis[to] == true){
            dfs2(to);
        }
    }
}

int main() {
    int t , hotels, m, x, y, road;
    scanf("%d", &t);

    while(t--) {
        c = 0;
        scanf("%d %d %d", &hotels, &m, &road);
        for(int i=0; i < mxx; i++) {
            size_[i] = 0;
            comp[i] = 0;
            graph[i].clear();
            rev[i].clear();
            vis[i] = false;
        }

        for(int i = 0; i < road; i++) {
            scanf("%d %d", &x, &y);
            graph[x].push_back(y);
            rev[y].push_back(x);
        }

        stack<int> st;
        for(int i = 1; i<= hotels; i++) {
            if(vis[i] == false) {
                dfs1(i, st);
            }
        }

        while(!st.empty()) {
            int to = st.top();
            st.pop();
            if(vis[to] == true) {
                c++;
                dfs2(to);
            }
        }

        /** remove hotels from components **/
        for(int i = 1; i<=hotels; i++) {
            size_[comp[i]]--;
        }

        int a = -1, b = -1;

        for(int i = 1; i <= hotels; i++) {
            if(size_[comp[i]] > a){
                a = size_[comp[i]];
                b = i;
            }
        }

        printf("%d %d\n", b, a);
    }

    return 0;
}

