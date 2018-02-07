
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

const int mxx = 100005;
// special value of infinity to take for getting rid of overflows
const int inf = 0x3f3f3f3f;
typedef pair<int,int> pii;

int par[mxx];
vector< pii > edge;

void init(int n) {
    for( int i = 1; i <= n; i++ ) {
        par[i] = i;
    }
}

int root(int x) {
    while(x != par[x]) {
        par[x] = par[par[x]];
        x = par[x];
    }
    return x;
}

void union_(int a, int b) {
    par[a] = b;
}

int main() {
    fast;
    int n, m, a, b;
    cin>>n>>m;
    init(n);

    vector<int> ans;
    for( int i = 0; i < m; i++ ) {
        cin>>a>>b;
        edge.push_back(make_pair(a,b));
    }

    pii p;
    for(int i = m-1; i >= 0; i--) {
        p = edge[i];
        int x = root(p.ff);
        int y = root(p.ss);

        if(x == y) {
            ans.push_back(i+1);
        } else {
            union_(x, y);
        }
    }

    cout<<ans.size()<<endl;

    for(int i = ans.size()-1 ; i >= 0 ; i--) {
        cout<<ans[i]<<endl;
    }

    return 0;
}
