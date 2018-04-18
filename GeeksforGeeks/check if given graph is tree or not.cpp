#include<bits/stdc++.h>
using namespace std;

int n, m;

bool cycle(int vertex, bool *vis,  unordered_map<int, vector<int> > graph, int parent)
{
    vis[vertex] = true;

    for(int i=0; i<graph[vertex].size(); i++)
	{
        if(vis[graph[vertex][i]] == false)
		{
			if(cycle(graph[vertex][i], vis, graph, vertex))
				return true;
		}
		else if(graph[vertex][i] != parent)
			return true;
	}

    return false;
}

bool solve(unordered_map<int, vector<int> > graph)
{
	bool *vis = new bool[n];

	for(int i=0; i<n; i++)
	{
		vis[i] = false;
	}

	if(cycle(0, vis, graph, -1))
	{
		return true;
	}

    for(int i=0; i<n; i++)
	{
		if(vis[i] == false)
			return true;
	}

    return false;
}

int main()
{
 	cin>>n>>m;
	unordered_map<int, vector<int> > graph;

	int x,y;
	for(int i=0; i<m; i++)
	{
		cin>>x>>y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}

    if(solve(graph))
	{
		cout<<"graph is not a tree"<<endl;
	}
	else
	{
		cout<<"graph is tree"<<endl;
	}

    for(int i=0; i<n; i++)
		graph[i].clear();

	// second graph
    cin>>n>>m;
    for(int i=0; i<m; i++)
	{
		cin>>x>>y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}

    if(solve(graph))
	{
        cout<<"graph is not a tree"<<endl;
	}
	else
	{
        cout<<"graph is a tree"<<endl;
	}

	return 0;
}
