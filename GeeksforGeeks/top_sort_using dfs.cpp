//  CODE WRITTEN BY: SHIV ANAND
// TOPOLOGICAL SORTING OF A GRAPH USING DFS TRAVERSAL
// LANGUAGE: CPP
// GRAPH MUST BE CONNECTED AND ACYCLIC AND DIRECTED

#include<bits/stdc++.h>
using namespace std;

// we do dfs until we reach the node which have no outgoing vertex

int n;
int adj[51][51];

bool vi[51];

deque<int> dq;

void top_sort_fun(int cur_vertex)
{
    vi[cur_vertex] = true;

    for(int i=0 ;i< n ;i++)
    {
        if(adj[cur_vertex][i] == 1 and vi[i] == false)
        {
            top_sort_fun(i);
        }
    }
    dq.push_front(cur_vertex);
}

int main()
{
    memset(vi,false,sizeof(vi));
    memset(adj,0,sizeof(adj));

    cin>>n;// number of vertex

    int m; // number of edges
    cin>>m;

int a,b;
    while(m--)
    {
        cin>>a>>b;
        adj[a][b]=1;
    }
top_sort_fun(0);

int fir;
while(!dq.empty())
{
    fir= dq.front();
    dq.pop_front();

    cout<<fir<<" ";

}

return 0;
}
