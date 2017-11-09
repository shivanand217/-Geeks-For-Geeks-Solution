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

const int N = 2000;
const int M = 2e5;
const int Q = 2e4;
const int W = 1e9;

struct Edge {
    int id, v, u, w;
    Edge() {}
    Edge(int id, int v, int u, int w) : id(id), v(v), u(u), w(w) {}
};

bool mycmp(const Edge& lhs, const Edge& rhs) {
    return lhs.w < rhs.w;
}

vector<int> g[N];
int edge_id[N][N];
bool marked[M];
list<pair<int,int> >::iterator ptr[M];
Edge edges[M];

int member[N];
int uf_rank[N];

/** union find **/
void uf_init(int n) {
    for(int i=0;i<n;i++) {
		member[i] = i;
		uf_rank[i] = 1;
    }
}

int uf_find(int v) {
    if(member[v] == v) return v;
    int fv = uf_find(member[v]);
    member[v] = fv;
    return fv;
}

bool uf_union(int a, int b) {
    int fa = uf_find(a);
    int fb = uf_find(b);
    if (fa == fb) return false;
    if (uf_rank[fa] > uf_rank[fb]) {
        member[fb] = fa;
        uf_rank[fa] += uf_rank[fb];
    } else {
        member[fa] = fb;
        uf_rank[fb] += uf_rank[fa];
    }
    return true;
}

int main() {

    int n, m, q;
    scanf("%d %d %d", &n, &m, &q);

    vector<Edge> tmp_edges;

    for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			edge_id[i][j] = -1;

    for(int i=0;i<m;++i) {
        int v, u, w;
        scanf("%d %d %d", &v, &u, &w);
        --v, --u;
        if (v > u) swap(v, u);
        g[v].pb(u);
        g[u].pb(v);
        edge_id[v][u] = i;
        marked[i] = 0;
        tmp_edges.pb(Edge(i, v, u, w));
        edges[i] = Edge(i, v, u, w);
    }

    sort(tmp_edges.begin(),tmp_edges.end(),mycmp);
    uf_init(n);

    list<pair<int,int> > candidates;
    ll res = 0;

    for (int i = 0; i < tmp_edges.size() && candidates.size() < n-1; ++i) {
        Edge e = tmp_edges[i];
        if (uf_union(e.v, e.u)) {
            res += e.w;
            candidates.pb(mp(e.id, e.w));
        }
    }

    bool need_recomputing = false;

    while (q--) {

        int qtype;
        scanf("%d", &qtype);

        if (qtype == 1 || qtype == 2) {
            int v, u;
            scanf("%d %d", &v, &u);
            --v, --u;

            if (v > u) swap(v, u);
            int eid = edge_id[v][u];

            if (qtype == 1) {
                if (!marked[eid]) {
                    candidates.push_front(mp(eid, 0));
                    ptr[eid] = candidates.begin();
                    marked[eid] = 1;
                    need_recomputing = true;
                }
            } else if (qtype == 2) {
                if (marked[eid]) {
                    candidates.erase(ptr[eid]);
                    marked[eid] = 0;
                    need_recomputing = true;
                }
            }
        } else if (qtype == 3) {
            if (need_recomputing) {
                res = 0;
                int cnt = 0;
                uf_init(n);
                for (auto it = candidates.begin(); it != candidates.end() && cnt < n-1; ++it) {
                    int eid = it->ff;
                    int v = edges[eid].v;
                    int u = edges[eid].u;
                    int w = it->ss;
                    if (uf_union(v, u)) {
                        res += w;
                        ++cnt;
                    }
                }
					need_recomputing = false;
            }
				printf("%lld\n", res);
        }
    }

    return 0;
}
