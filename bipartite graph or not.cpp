#include<bits/stdc++.h>
using namespace std;

#define maxn 105
vector<int> graph[maxn];

// assuming graph is connected
// it will be bipartite if it is two colorable

bool is_bipartite(int n)
{
    int *color = new int[n]; //color 0, 1, 2
    queue<int> qu;

    qu.push(0);

    int v;
    color[0]=1;
    bool colorable=true;

    while(!qu.empty())
	{
		v = qu.front();
        qu.pop();

        for(int i=0; i<graph[v].size(); i++)
		{
            int k = graph[v][i];

            if(color[k] == color[v])
			{
                colorable=false;
                break;
			}

            if(color[k] == 0)
			{
				if(color[v]==1){
					color[k]=2;
				}
				else{
					color[k]=1;
				}

				qu.push(k);
			}
		}
	}

	return colorable;
}

int main()
{
	int n, m;
    cin>>n>>m;

    int x,y;

    for(int i=0; i<m; i++)
	{
        cin>>x>>y;
        graph[x].push_back(y);
        graph[x].push_back(y);
	}

    if(is_bipartite(n))
	{
        cout<<"graph is two colorable and bipartite"<<endl;
	}
	else
	{
        cout<<"graph is not two colorable so not bipartite"<<endl;
	}

    return 0;
}
