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

const int mxx = 100001;
// special value of infinity to take for getting rid of overflows
const int inf = 0x3f3f3f3f;

vector<int> gr[100005];
bool vis[100005];
int n, m, a, b;
bool ans;

void dfs(int x,int parent) {
    vis[x] = true;
    for(int i=0; i < gr[x].size(); i++) {
        int to=gr[x][i];
        if(to != parent && vis[to] == true ) {
            ans = false;
        }
        if(vis[to] == false) {
            dfs(to, x);
        }
    }
}

int main() {
    fast;
    cin>>n>>m;
    ans=true;
    for(int i=0; i<m; i++){
        cin>>a>>b;
        gr[a].pb(b);
        gr[b].pb(a);
    }

    for(int i=1;i<=n;i++) {
        if(vis[i]==false)  {
            //memset(,false,sizeof(rec));
            dfs(i,-1);
        }
    }
    if(ans==false)
        cout<<"NO"<<endl;
    else
        cout<<"YES"<<endl;
    return 0;
}

