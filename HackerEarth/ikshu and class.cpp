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
#define mx5 100010
#define mx6 1000010
#define MOD 1000000007
using namespace std;

bool vis[mx5];
vector<int> graph[mx5];
int C[mx5];
ll fact[mx5];
int components=0;
int n,k,u,v;

void f() {
    fact[0]=fact[1]=1LL;
    for(ll i=2;i<mx5;i++) {
        fact[i] = i*fact[i-1];
        fact[i]%=MOD;
    }
}

void dfs(int x) {
    vis[x]=true;
    ++C[components];
    for(auto p : graph[x]){
        if(!vis[p]){
            dfs(p);
        }
    }
}

int main() {
    f();
    si(n), si(k);
    for(int i=0;i<=n;i++) {
        vis[i]=false;
    }
    for(int i=0;i<=n;i++) {
        C[i]=0;
    }
    while(k--) {
		si(u), si(v);
        graph[u].pb(v);
        graph[v].pb(u);
    }

    for(int i=0;i<n;i++) {
        if(!vis[i]) {
            components++;
            dfs(i);
        }
    }

    ll ans = 1LL;

    for(int i=1;i<=components;i++){
		ans *= fact[C[i]];
        ans %= MOD;
    }

    printf("%lld\n",ans);

   return 0;
}
