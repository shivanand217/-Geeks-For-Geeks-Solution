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

const int mxx = 100001;

// special value of infinity to take for getting rid of overflows
const int inf = 0x3f3f3f3f;

typedef pair<int,int> pii;

int dist1[mxx] , dist2[mxx];
bool flag1[mxx] , flag2[mxx];
vector< pii > graph1[mxx];
vector< pii > graph2[mxx];
int u,v,w,sz;

void dijktsra1(int s) {
    priority_queue< pii , vector< pii >, greater< pii > > Q;
    Q.push(pii(0,s));
    dist1[s] = 0;
    while(!Q.empty()) {
        u = Q.top().ss;
        Q.pop();
        if(flag1[u]==true)
            continue;
        sz=graph1[u].size();
        for(int i=0; i<sz; i++) {
            v=graph1[u][i].ss;
            w=graph1[u][i].ff;
            // if adjancent is not updated before
            if(flag1[v] == false && dist1[v] > dist1[u] + w) {
                dist1[v] = dist1[u] + w;
                Q.push(pii(dist1[v], v));
            }
        }
        flag1[u]=true;
    }
}

void dijktsra2(int s){
    priority_queue< pii , vector< pii >, greater< pii > > Q;
    Q.push(pii(0,s));
    dist2[s]=0;
    while(!Q.empty()){
        u = Q.top().ss;
        Q.pop();
        if(flag2[u]==true)
            continue;
        sz=graph2[u].size();
        for(int i=0; i<sz; i++) {
            v=graph2[u][i].ss;
            w=graph2[u][i].ff;
            if(flag2[v] == false && dist2[v] > dist2[u] + w){
                dist2[v] = dist2[u] + w;
                Q.push(pii(dist2[v], v));
            }
        }
        flag2[u]=true;
    }
}

int main() {
    int t,n,e,k,p,q;
    si(t);
    while(t--) {
        si(n),si(e);
        for(int i=1; i<=n; i++) {
            graph1[i].clear();
            graph2[i].clear();
            dist1[i]=inf;
            dist2[i]=inf;
            flag1[i]=false;
            flag2[i]=false;
        }

        si(k),si(p),si(q);
        for(int i=1;i<=e;i++) {
            si(u),si(v),si(w);
            graph1[u].pb(pii(w,v));
            graph2[v].pb(pii(w,u));
        }

        dijktsra1(p);//source
        dijktsra2(q);//destination

        int ans = inf;

        while(k--) {
            si(u),si(v),si(w);
            ans = min(ans, min(dist1[q], min(dist1[u] + w + dist2[v], dist1[v] + w + dist2[u])));
        }

        if(ans < inf)
            printf("%d\n", ans);
        else
            printf("-1\n");
    }

    return 0;
}
