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

const int mxx = 100005;
// special value of infinity to take for getting rid of overflows
const int inf = 0x3f3f3f3f;

vector<int> adj[mxx];
int V,a,b;
int cnt;

void f(){
bool visited[V];

    for (int i=1; i<=V; i++)
        visited[i] = false;

    for (int u=1; u<=V; u++)
    {
        if(u==1){
            visited[u]=true;
            continue;
        }
        if (visited[u] == false)
        {
            int flag=0;
            for (auto i= adj[u].begin(); i != adj[u].end(); ++i)
            {
                int v = *i;
                if (visited[v] == true)
                {
                     flag=1;
                     break;
                }
            }
            if(flag ==0){
                visited[u]=true;
            }
        }
    }

    for (int i=1; i <= V; i++)
        if ( visited[i] )
          cnt++;
}
int main() {
    cin>>V;

    for(int i=0; i<V-1; i++) {
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    f();
    cout<<cnt<<endl;


    return 0;
}
