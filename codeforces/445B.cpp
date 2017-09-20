#include<bits/stdc++.h>
using namespace std;
#define si(x) scanf("%d",&x)
#define ll long long
vector<int> graph[51];
vector<int> vi(51);
//const int MOD = 1000000007;
ll fast_pow(ll x, ll y)
{
    ll res=1;
    x;//%=MOD;
    while(y>0)
	{
        if((y&1))
		{
            res=res*x;
            res;//%=MOD;
		}
        x=x*x;
        y/=2;
	}
    return res;
}
void dfs(int v){
	vi[v]=1;
    for(int i=0;i<graph[v].size();i++)
	{
        if(vi[graph[v][i]]==0){
                dfs(graph[v][i]);
        }
	}
}
int main()
{
    int n,m;
    si(n); si(m);
	int x,y;
    int connected_comp=0;
    for(int i=0;i<m;i++)
	{
        si(x);si(y);
        graph[x].push_back(y);
        graph[y].push_back(x);
	}
    for(int i=1;i<=n;i++)
	{
        if(vi[i]==0)
		{
            connected_comp++;
            dfs(i);
		}
	}
    if(n==1){
		cout<<"1"<<endl;return 0;
    }
    ll ans = fast_pow(2,n-connected_comp);
    printf("%lld\n",ans);
    return 0;
}
