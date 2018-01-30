#include <bits/stdc++.h>

#define mp make_pair
#define ll long long
#define pb push_back

#define ss second
#define ff first
#define si(x) scanf("%d", &x)
#define slli(x) scanf("%lld", &x)
#define pi(x) printf("%d", x)

#define mx5 100005
#define mx6 1000006
#define mod 1000000007

#define rep(i,n) for(int i=0; i<n; i++)
#define fast std::ios::sync_with_stdio(false)
#define gc() getchar()
#define pc(x) putchar(x)

using namespace std;

typedef pair<int,int> pii;

const int mxx = 100005;
// special value of infinity to take for getting rid of overflows
const int inf = 0x3f3f3f3f;

vector<int> graph[ mxx ];
vector<int> transpose[ mxx ];
bool vis[ mxx ];
int ar[ mxx ];

int n, a, b ,m, cnt;
int ans1=1;
long long ans2=0;
vector<int> comp;

void fillStackinOrder(int v, stack<int> & Stack) {
    vis[v] = true;
    for(int i=0; i < graph[v].size(); i++) {
        int to = graph[v][i];
        if( vis[to] == false ) {
            fillStackinOrder(to, Stack);
        }
    }
    Stack.push(v);
}

void dfsOnTranspose(int v) {
    vis[v] = false;
    comp.push_back(v);
    for(int i = 0; i < transpose[v].size(); i++) {
        int to = transpose[v][i];
        if( vis[to] == true ){
            dfsOnTranspose(to);
        }
    }
}

void SCC() {
    stack<int> Stack;
    for(int i=1; i <= n; i++) {
        if(vis[i] == false) {
            fillStackinOrder(i, Stack);
        }
    }
    while( !Stack.empty() ) {
        int to = Stack.top();
        Stack.pop();
        comp.clear();
        if( vis[to] == true ) {
            dfsOnTranspose( to );
            int tmp = INT_MAX;
            for( int i=0; i<comp.size(); i++ ) {
                int to = comp[i];
                tmp = min( ar[to], tmp);
            }
            cnt=0;
            for( int i=0; i < comp.size(); i++ ) {
                int to = ar[comp[i]];
                if( to == tmp ) {
                    cnt++;
                }
            }
            ans1 = ((long long)ans1*cnt)%mod;
            ans2 += tmp;
        }
    }
    cout<<ans2<<" "<<ans1<<endl;
}

int main() {
    fast;
    cin>>n;
    for( int i = 1; i <= n; i++ ) {
        cin>>ar[i];
        vis[i] = false;
    }
    cin>>m;
    for( int i = 1; i <= m; i++ ) {
        cin>>a>>b;
        graph[a].push_back(b);
        transpose[b].push_back(a);
    }
    SCC();
    return 0;
}
