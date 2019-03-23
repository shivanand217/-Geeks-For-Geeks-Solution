#include<bits/stdc++.h>
using namespace std;

vector<int> graph[50];
bool vi[50];int V;

void dfs(int i)
{
    vi[i]=true;

    for(int j=0; j<graph[i].size(); j++)
    {
        if(!vi[graph[i][j])
        {
            dfs(graph[i][j]);
        }
    }
}

bool is_connected()
{
    int i;
    memset(vi,false,sizeof(vi));

    // check for the first node with 0 degree
    for(i=0; i<V; i++)
    {
      if(graph[i].size() > 0)
            break;
    }

    // if no vertex with non zero degree
    if(i==V)
        return true;

    dfs(i);

    // after dfs if any vertex with non zero degree is unvisited then the graph is disconnected
    // because eulerian property says that every edge should be visited exactly once
    for(int i=0; i<V; i++)
    {
        if(vi[i] == false && graph[i].size()> 0)
            return false;
    }

    return true;
}

int is_eulerian()
{

if(!is_connected())
    return 0;

int odd=0; // calculate for number of odd vertex
for(int i=0; i<V; i++)
{
    if(graph[i].size() & 1)
        odd++;
}

// if number of odd is greater than 2 then graph is not eulerian
if(odd > 2)
    return 0;

if(odd == 2)return 1; // 0 for not eulerian ,1 for semi eulerian, 2 for eulerian
else if(odd == 0)
{
    return 2;
}

}



int main()
{

cin>>V;
int a,b;

for(int i=0; i<V; i++)
{
    cin>>a>>b;
    graph[a].push_back(b);
    grapg[b].push_back(a);
}

int k=is_eulerian();

if(k == 0)
    cout<<"not a eulerian"<<endl;
else if(k==1)
    cout<<"semi eulerian"<<endl;
else
    cout<<"eulerian"<<endl;

return 0;
}
