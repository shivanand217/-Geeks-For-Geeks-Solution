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

// special value of infinity to take for getting rid of overflows
const int inf = 0x3f3f3f3f;

/******************* Problem Code *****************/
int dist1[100005],dist[100005];
vector< pii > gr[100005];

void init(int n) {
    for(int i=0; i<=n; i++) {
        dist[i]=inf;
        dist1[i]=inf;
        gr[i].clear();
    }
}

int main() {
    fast;
    int t,n,m,x,y,z,p,q;
    cin>>t;
    vector< pii > :: iterator itr;

    /** Roads are Unidirectional **/
    while(t--) {
        cin>>n>>m;
        init(n);
        for(int i = 0; i < m; i++) {
            cin>>x>>y>>z;
            gr[x].push_back(make_pair(y,z));
        }
        priority_queue<pii,vector<pii>,greater<pii> > p;
        p.push(make_pair(0,1));
        dist[1] = 0;
        dist1[1] = 0;
        int val,d,u;
        while( !p.empty() ) {
            u = p.top().ss;
            p.pop();
            for(int i=0; i < gr[u].size(); i++) {
                d=gr[u][i].ss;
                val=gr[u][i].ff;
                if(dist[val] > dist[u] + d) {
                    dist[val] = dist[u]+d;
                    p.push(make_pair(dist[val],val));
                }
                if(dist1[val] > d) {
                    dist1[val] = d;
                }
            }
        }
        bool ans = true;
        ll sum = 0;
        for( int i=1; i<=n; i++ ) {
            if( dist1[i] == inf ) {
                ans = false;
                break;
            }
            sum+=dist1[i];
        }
        if(ans == false) {
            cout<<"-1"<<endl;
        } else {
            cout<<sum<<endl;
        }
    }

    return 0;
}
