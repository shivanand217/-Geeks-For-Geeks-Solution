#include<bits/stdc++.h>
using namespace std;

const int maxn = 150010;
bool vi[maxn];
vector<int> graph[maxn];

int n,m;

int dfs(int k,int &cnt)
{
    vi[k]=true;
    for(int i=0; i<graph[k].size(); i++)
    {
        if(!vi[graph[k][i]])
        {
            cnt++;
            dfs(graph[k][i],cnt);
        }
    }
}

bool solve(int x){

       int fir=graph[x].size();
       queue<int> qu;qu.push(x);vi[x]=true;

       int cnt=1;
       while(!qu.empty())
       {
              int e = qu.front();
              qu.pop();
              vi[e]=true;

        dfs(e,cnt);
 //       cout<<cnt<<endl<<endl;

         if(graph[e].size() !=(cnt-1))
            return false;
        for(int i=0; i<graph[e].size(); i++)
        {
            if(graph[graph[e][i]].size()!=(cnt-1))
                return false;
        }
       }
       return true;
}

int main()
{
       scanf("%d%d",&n,&m);
       int a,b;
       memset(vi,false,sizeof(vi));

       for(int i=0; i<m; i++)
       {
              scanf("%d%d",&a,&b);

              graph[a].push_back(b);
              graph[b].push_back(a);
       }

       // finding all the strongly connected components
       for(int i=0; i<n; i++)
       {
              if(!vi[i])
              {
                    if(solve(i) == false){
                           cout<<"NO"<<endl;return 0;
                    }
              }
       }
       cout<<"YES"<<endl;
       return 0;
}
