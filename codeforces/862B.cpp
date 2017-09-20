#include<bits/stdc++.h>
using namespace std;
vector<int> g[100005];
int v[100005];
int n,u,ve;
int one=0,sec=0;
void dfs(int vr,int m){
    if(m==0)
        one++;
	else
		sec++;
    v[vr]=1;
    for(int j=0;j<g[vr].size();j++){
        if(v[g[vr][j]]==0){
            dfs(g[vr][j],1-m);
        }
    }
}
int main()
{
    cin>>n;
    for(int i=0;i<n-1;i++)
	{
        cin>>u>>ve;
        g[u].push_back(ve);
        g[ve].push_back(u);
	}
    for(int i=1; i<=n; i++) {
        if(v[i]==0)
		{
            dfs(i,0);
		}
    }
	long long ans=(long long)one*sec-(long long)(n-1);
    cout<<ans<<endl;
	return 0;
}
