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
#define fck std::ios::sync_with_stdio(false);
#define mx5 100010
#define mx6 1000010
#define MOD 1000000007
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
#define ordered_set tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
using namespace __gnu_pbds;

pair<ll,pair<ll,ll> > edge[mx5];
int par[mx5];
vector<ll> ans;
int N,M,A,B,L,Q;
ll cable[mx5];

void init() {
    for(int i=1;i<=N;i++){
        par[i]=i;
    }
}

int find_root(int x) {
    while(x != par[x]) {
        par[x]=par[par[x]];
        x = par[x];
    } return x;
}

void kruskals(int p){
    int i=0,f,s;
    pair<ll,pair<ll,ll> > kp;
    while(i<p) {
		kp = edge[i];
		f = kp.ss.ff;
		s = kp.ss.ss;
        int x=find_root(f);
        int y=find_root(s);
        if(x==y) {
			i++;
			continue;
		}
        par[x]=y;
        ans.pb(kp.ff);
        i++;
    }
}

int main() {
    si(N), si(M);
    int p=0;
    init();

    for(int i=0;i<M;i++) {
        si(A), si(B), si(L);
        if(A!=B)
			edge[p++] = make_pair(L,make_pair(A,B));
    }

    sort(edge,edge+p);
    kruskals(p);

    si(Q);
    for(int i=0;i<Q;i++) {
		slli(cable[i]);
    }

    sort(cable,cable+Q);
    int i=0,j=0;
    ll sum=0;

	int k=0;

    while(i<ans.size() && j<Q && k<N-1) {
        if(ans[i]>cable[j]) {
            sum += cable[j++];
        } else {
            sum += ans[i++];
        }
        k++;
    }

    while(i<ans.size() && k<N-1) {
		sum+=ans[i++];
		k++;
    }

    printf("%lld\n",sum);

	return 0;
}
