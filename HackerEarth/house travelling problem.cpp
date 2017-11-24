#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SZ(a) (int)(a.size())
#define ALL(a) a.begin(),a.end()
#define SET(a,b) memset(a,b,sizeof(a))
#define si(n) scanf("%d",&n)
#define dout(n) printf("%d\n",n)
#define sll(n) scanf("%lld",&n)
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

const int N = 3000;
int G[N][N],dsu[N],X[N],Y[N];
pair<LL,pair<int,int> > e[N*N];

int Find(int u)
{
	if(u==dsu[u])return u;
	return dsu[u]=Find(dsu[u]);
}

bool merge(int u,int v)
{
	u=Find(u);v=Find(v);
	if(u==v)return false;
	dsu[u]=v;
	return true;
}

int main()
{
	int n;
	si(n);

	for(int i=0;i<n;i++)
		scanf("%d %d",X+i,Y+i);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			si(G[i][j]);
	int m=0;

	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
			if(G[i][j])
				e[m++]=MP((X[i]-X[j])*1ll*(X[i]-X[j]) + (Y[i]-Y[j])*1ll*(Y[i]-Y[j]),MP(i,j));

	for(int i=0;i<n;i++)
		dsu[i]=i;

	sort(e,e+m);
	LL ans=0;

	for(int i=m-1; i>=0; i++)
		if(merge(e[i].S.F,e[i].S.S))
			ans+=e[i].F;

	for(int i=1;i<n;i++)
		if(Find(i)!=Find(0))
			ans=-1;

	printf("%lld\n",ans);

	return 0;
}
