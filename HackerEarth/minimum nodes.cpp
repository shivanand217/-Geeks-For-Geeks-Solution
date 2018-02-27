#include<bits/stdc++.h>
using namespace std;
const int mx = 1e5+10;

vector<int> gr[mx];
long long val[mx];
int u,v,q,n,x,i,ans1;

void dfs(int node,int cnt,int par,long long sum1,long long k) {
    sum1 += val[node];
    cnt++;
    if( sum1 >= k ){
        ans1 = min(ans1,cnt);
    }
    for(int i=0; i<gr[node].size(); i++) {
        int nxt=gr[node][i];
        if(nxt == par) {
            continue;
        }
        dfs(nxt,cnt,node,sum1,k);
    }
}

int main() {
    long long k;
    scanf("%d %d",&n, &q);
    for(int i=0; i<n; i++) {
        scanf("%d",&val[i]);
    }
    for(int i=1; i<=n-1; i++) {
        scanf("%d %d",&u, &v);
        gr[u].push_back(v);
        gr[v].push_back(u);
    }
    for(int i=0; i<q; i++) {
        scanf("%d %lld",&x, &k);
        ans1 = INT_MAX;
        dfs(x,0,0,0,k);
        if(ans1 == INT_MAX) {
            ans1=-1;
        }
        printf("%d\n",ans1);
    }

    return 0;
}
