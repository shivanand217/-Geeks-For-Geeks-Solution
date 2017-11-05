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

int n,q,a,b,k,c,u,f,i,j;
unordered_map<int,int> un;
int par[mx5];

void init() {
    for(i=0;i<=n;i++) {
        par[i]=i;
    }
}

int root(int x) {
    while(x != par[x]) {
        x = par[par[x]];
        x = par[x];
    }
    return x;
}

int main() {
   si(n), si(q);
   init();

   for(i=0; i<q; i++) {
        si(a), si(b);
        f = a, j = b;
        while( f < j ) {
            k = root(f);
            c = root(j);
            if(k != c) {
                par[k]=c;
            }
            f++, j--;
        }
   }

   ll ans = 1LL;

   for(int i=1; i<=n; i++) {
        k = root(i);
        if(un[k] == 0) {
			ans *= 10;
            ans %= MOD;
            un[k]++;
        }
   }
   printf("%lld\n",ans);

   return 0;
}
