#include <bits/stdc++.h>
#define mp make_pair
#define ll long long
#define pb push_back
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

int main() {
	int t, ng, nm, maxg, maxm, g, m;
	scanf("%d", &t);

	while(t--) {

		scanf("%d %d", &ng, &nm);
		maxg = maxm = -1;

		while(ng--) {
			scanf("%d", &g);
			if(g > maxg) maxg = g;
		}

		while(nm--) {
			scanf("%d", &m);
			if(m > maxm) maxm = m;
		}

		if(maxg >= maxm)
            printf("Godzilla\n");
		else
            printf("MechaGodzilla\n");

	}

	return 0;
}
