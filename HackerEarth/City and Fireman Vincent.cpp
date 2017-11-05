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

int par[10005];
int E[10005];
int n,k,u,v;

void init() {
    for(int i=0; i<=n; i++) {
        par[i]=i;
    }
}

int root(int x) {
    while(x != par[x]){
        par[x] = par[par[x]];
        x = par[x];
    }
    return x;
}

void dfs_root(int x,int min_Comp,int& ans) {
	if(E[x] == min_Comp){
		ans++;
	}
    while(x != par[x]){
        x = par[x];
        if(E[x] == min_Comp){
            ans++;
        }
    }
}

int main() {
   unordered_map<int,int> min_Cost_Component;
   map<int,int> an;

   si(n);
   init();

   for(int i=1; i<=n; i++) {
		si(E[i]);
        min_Cost_Component[i]=E[i];
   }

   si(k);
   while(k--) {
        si(u), si(v);
		int p = root(u);
		int q = root(v);

        if(p != q) {
            if(min_Cost_Component[p] > min_Cost_Component[q]) {
				par[p] = q;
			} else {
                par[q] = p;
            }
        }
    }

    for(int i=1;i<=n;i++){
		int kl = root(i);
        if(E[i] == E[kl]) {
            an[kl]++;
        }
    }

    ll tot=1LL;
    for(auto i = an.begin(); i!=an.end(); ++i){
        tot = (tot*(i->ss))%MOD;
    }

    tot = (tot%MOD);
    printf("%d\n",tot);

	return 0;
}
