#include<bits/stdc++.h>
#define pb push_back

#define fast std::ios::sync_with_stdio(false)
using namespace std;

vector<int> g[2005];
vector <int> lca_h, lca_dfs_list, lca_first, lca_tree;
vector <bool> lca_dfs_used;
int n;

void lca_dfs(int v, int depth) {
	lca_dfs_used [v] = true;
	lca_h [v] = depth;
	lca_dfs_list.push_back (v);
	for (int i=0; i < g[v].size(); ++i ) { // = g [v].begin (); i! = g [v].end (); ++ i) {
		int u = g[v][i];
		if (lca_dfs_used[u] == false)
		{
			lca_dfs (u , depth + 1);
			lca_dfs_list.push_back (v);
		}
	}
}

void lca_build_tree (int i, int l, int r) {
	if (l == r)
		lca_tree [i] = lca_dfs_list [l];
	else
	{
		int m = (l + r) >> 1;
		lca_build_tree (i + i, l, m);
		lca_build_tree (i + i + 1, m + 1, r);
		if (lca_h [lca_tree [i + i]] < lca_h [lca_tree [i + i + 1]])
			lca_tree [i] = lca_tree [i + i];
		else
			lca_tree [i] = lca_tree [i + i + 1];
	}
}

void lca_prepare (int root) {
	lca_h.resize (n);
	lca_dfs_list.resize(n * 2);
	lca_dfs_used.assign (n, false);

	lca_dfs (root, 1);

	int m = (int) lca_dfs_list.size ();
	lca_tree.assign (lca_dfs_list.size () * 4 + 1, -1);
	lca_build_tree (1, 0, m-1);
	lca_first.assign (n, -1);

	for (int i = 0; i < m; ++ i)
	{
		int v = lca_dfs_list [i];
		if (lca_first [v] == -1)
			lca_first [v] = i;
	}
}

int lca_tree_min (int i, int sl, int sr, int l, int r) {
	if (sl == l && sr == r)
		return lca_tree [i];
	int sm = (sl + sr) >> 1;
	if (r <= sm)
		return lca_tree_min (i + i, sl, sm, l, r);
	if (l > sm)
		return lca_tree_min (i + i + 1, sm + 1, sr, l, r);
	int ans1 = lca_tree_min (i + i, sl, sm, l, sm);
	int ans2 = lca_tree_min (i + i + 1, sm + 1, sr, sm + 1, r);
	return lca_h [ans1] < lca_h [ans2] ? ans1 : ans2;
}

int lca (int a, int b) {
	int left = lca_first [a],
		right = lca_first [b];
	if (left > right)
        swap(left,right);
	return lca_tree_min (1, 0, (int) lca_dfs_list.size () - 1, left, right);
}

int main () {
    fast;
	int a,b,parent,q,m,tmp;
	int root;
	int t,cnt,ans;
    scanf("%d",&t);
    vector<int> indegree;

    for(int k=1; k <= t; k++) {
        scanf("%d",&n);
        //indegree.assign(n+10, 0);
        for(int i=1; i <= n; i++) {
            g[i].clear();
        }

        int cnt=0;
        for(int i=1; i <= n; i++) {
            //si(m);
            scanf("%d",&m);
            for(int j=0; j < m; j++) {
                // si(tmp);
                scanf("%d",&tmp);
                g[i].pb(tmp);
                g[tmp].pb(i);
                //indegree[tmp]++;
            }
        }

        lca_prepare(1);
        // si(q);
        scanf("%d",&q);
        printf("Case %d:\n",k);

        for(int p=1; p <= q; p++) {
            // si(a),si(b);
            scanf("%d %d",&a, &b);
            ans = lca(a , b);
            printf("%d\n",ans);
        }
    }

	return 0;
}

