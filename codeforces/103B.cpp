#include<bits/stdc++.h>
using namespace std;
vector<int> graph[102];
int vis[102];
void dfs(int v)
{
    vis[v]=1;
    for(int i=0;i<graph[v].size();i++)
	{
        if(vis[graph[v][i]]==0)
			dfs(graph[v][i]);
	}
}
int main()
{
    int n,m,x,y;
    cin>>n>>m;
    for(int i=0;i<m;i++)
	{
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
	}
    int cnt=0;
    dfs(1);
    bool ans=true;
    for(int i=1;i<=n;i++)
	{
        if(vis[i]==0)
		{
            ans=false;break;
		}
	}
    if(ans==true&&n==m)
	{
        cout<<"FHTAGN!"<<endl;
	}
	else
	{
        cout<<"NO"<<endl;
	}
    return 0;
}
