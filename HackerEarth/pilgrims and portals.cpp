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

typedef pair<int,int> pii;

const int mxx = 100001;
// special value of infinity to take for getting rid of overflows
const int inf = 0x3f3f3f3f;

/******************* Problem Code *****************/

struct node
{
	int src,dest;
	ll wght;
};

int par[105],rnk[105];

int Find(int nd)
{
	if(par[nd]!=nd)
		par[nd]=Find(par[nd]);
	return par[nd];
}

void Union(int nd1, int nd2)
{
	int x=Find(nd1);
	int y=Find(nd2);
	if(rnk[x]<rnk[y])
		par[x]=y;
	else if(rnk[x]>rnk[y])
		par[y]=x;
	else
	{
		par[y]=x;
		rnk[x]++;
	}
}

bool compare(node n1, node n2) {

	return n1.wght<n2.wght;
}

ll kruskal(vector<node> g, int n)
{
	vector<node> mst;
	for(int i=0;i<n;++i)
	{
		par[i]=i;
		rnk[i]=0;
	}
	sort(g.begin(),g.end(),compare);
	int cnt=0,cnt1=0;
	ll ans=0;
	while(cnt!=n-1)
	{
		node ne=g[cnt1++];
		int x=Find(ne.src);
		int y=Find(ne.dest);
		if(x!=y)
		{
			ans+=ne.wght;
			mst.push_back(ne);
			Union(x,y);
			cnt++;
		}
	}
	return ans;
}

ll dis[105][105];

void floydWarshell(vector<node> g, int n)
{
	for(int i=0;i<g.size();++i)
	{
		dis[g[i].src][g[i].dest]=g[i].wght;
		dis[g[i].dest][g[i].src]=g[i].wght;
	}
	for(int k=0;k<n;++k)
	{
		for(int i=0;i<n;++i)
		{
			for(int j=0;j<n;++j)
			{
				if(dis[i][k]+dis[k][j]<dis[i][j])
					dis[i][j]=dis[i][k]+dis[k][j];
			}
		}
	}
}

int main() {
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m,k;
		scanf("%d %d %d",&n,&m,&k);
		vector<node> graph;
		node nd;
		for(int i=0;i<m;++i)
		{
			scanf("%d %d %lld",&nd.src,&nd.dest,&nd.wght);
			nd.src--;
			nd.dest--;
			graph.push_back(nd);
		}
		for(int i=0;i<n;++i)
			for(int j=0;j<n;++j)
				dis[i][j]=1000000000000000LL;
		for(int i=0;i<n;++i)
			dis[i][i]=0;
		floydWarshell(graph,n);
		graph.clear();
		for(int i=0;i<k;++i)
		{
			for(int j=i+1;j<k;++j)
			{
				nd.src=i,nd.dest=j,nd.wght=dis[i][j];
				graph.push_back(nd);
			}
		}
		printf("%lld\n",kruskal(graph,k));
	}

	return 0;
}

