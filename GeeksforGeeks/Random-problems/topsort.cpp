//  CODE WRITTEN BY: SHIV ANAND
// TOPOLOGICAL SORTING OF A GRAPH USING BFS TRAVERSAL
// LANGUAGE: CPP
// GRAPH MUST BE CONNECTED AND ACYCLIC AND DIRECTED

#include<bits/stdc++.h>
using namespace std;

int adj[51][51];
bool vi[51];
int n;
int in_degree[51];

vector<int> top_sort_array;

void top_sort_fun()
{
    queue<int> qu;

    for(int i=0; i<n; i++)
    {
      in_degree[i]=0;
      vi[i]=false;
    }

    // give indegree to the vertex to the vertices that have
    for(int i=0; i<n ;i++)
    {
        for(int j=0; j<n ;j++)
        {
            if(adj[i][j] == 1)
            {
                in_degree[j]++;
            }
        }
    }

    // now enque to the queue that veretex whose indegree is zero beacause it comes very first in the top_sort array
    for(int i=0; i<n ;i++)
    {
        if(in_degree[i] == 0)
        {
            qu.push(i);
            vi[i] = true;
        }
    }

    // now start the top_sorting
    while(!qu.empty())
    {
        int fir = qu.front();
        qu.pop();
        top_sort_array.push_back(fir);

        for(int i=0; i<n ;i++)
        {
            if(adj[fir][i] == 1 and vi[i]==false)
            {
                in_degree[i]--;
                if(in_degree[i] == 0)
                {
                    qu.push(i);
                    vi[i] = true;
                }
            }
        }
    }
 //   cout<<top_sort_array.size()<<endl;

}

int main()
{ // number of vertex in the graph
cin>>n;

int m;// number of edges in the graph
cin>>m;int a,b;

memset(adj,0,sizeof(adj)); // initialize all the edges to nil (no edges)
while(m--)
{
    cin>>a>>b;
    adj[a][b]=1;
}
top_sort_fun();

// now show the topological sorted array
for(int i=0; i<top_sort_array.size(); i++)
{
    cout<<top_sort_array[i]<<" ";
}cout<<endl;

return 0;

}
