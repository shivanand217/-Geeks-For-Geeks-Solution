/** approach : orientation of three coordinate points + union find **/

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

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
#define ordered_set tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
using namespace __gnu_pbds;

struct Point { int x, y; };
struct Segment { Point a, b; };

Segment seg[1055];
int root[1055];

void init(int n) {
    for(int i=1;i<=n;i++) {
        root[i]=i;
    }
}

int find_root(int x) {
    while(root[x]!=x) {
        root[x] = root[root[x]];
        x = root[x];
    }
    return x;
}

void union_(int x,int y) {
    int u = find_root(x);
    int v = find_root(y);
    root[u] = root[v];
}

int direction(Point &pi, Point &pj, Point &pk) {
	return (pk.x-pi.x)*(pj.y-pi.y)-(pj.x-pi.x)*(pk.y-pi.y);
}

bool in(int x,int y,int z){
	return (x<=y && y<=z);
}

bool onsegment(Point &pi, Point &pj, Point &pk) {
	return (in(min(pi.x,pj.x),pk.x,max(pi.x,pj.x)) && in(min(pi.y,pj.y),pk.y,max(pi.y,pj.y)));
}

inline bool intersect(Point &p1, Point &p2, Point &p3, Point &p4) {

	int d1, d2, d3, d4;
	d1 = direction(p3, p4, p1);
	d2 = direction(p3, p4, p2);
	d3 = direction(p1, p2, p3);
	d4 = direction(p1, p2, p4);

	if(((d1>0 && d2<0)||(d1<0 && d2>0)) && ((d3>0 && d4<0)||(d3<0 && d4>0)))
		return true;

	if(!d1 && onsegment(p3, p4, p1)) return true;
	if(!d2 && onsegment(p3, p4, p2)) return true;
	if(!d3 && onsegment(p1, p2, p3)) return true;
	if(!d4 && onsegment(p1, p2, p4)) return true;

	return false;
}

int main() {

	int t, m, n, i, j, u, v;
	scanf("%d", &t);

	while(t--) {

		scanf("%d%d", &n, &m);
        init(n);

		for(i = 1; i <= n; i++) {
			scanf("%d%d%d%d", &seg[i].a.x, &seg[i].a.y, &seg[i].b.x, &seg[i].b.y);
		}
		for(i = 1; i <= n; i++) {
			for(j = 1; j <= n; j++) {

				u = find_root(i);
				v = find_root(j);
				if(u != v && intersect(seg[i].a, seg[i].b, seg[j].a, seg[j].b)) union_(u, v);
			}
		}

		while(m--) {
			scanf("%d%d", &i, &j);
			u = find_root(i);
			v = find_root(j);
			if(u==v) printf("YES\n");
			else printf("NO\n");
		}
	}

	return 0;
}
