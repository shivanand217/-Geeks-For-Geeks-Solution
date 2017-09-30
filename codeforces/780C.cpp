#include<bits/stdc++.h>
using namespace std;

vector<int> graph[200005];
int color[200005];

int total_color_used=0;

void dfs(int vertex_, int parent) {

    int curr = 1;

    for(int i=0; i<graph[vertex_].size(); i++){

        if(color[graph[vertex_][i]] == 0){

				while(color[vertex_] == curr || color[parent] == curr)
					curr++;

				color[graph[vertex_][i]] = curr;
				total_color_used = max(total_color_used , curr);
				curr++;

				dfs(graph[vertex_][i], vertex_);
		}
    }

    return;
}

int main()
{
    int n;
    cin>>n;

    int x , y;
    for(int i=0;i<n-1;i++){

		cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);

    }

	color[1] = 1;
    dfs(1, -1);

    cout<<total_color_used<<endl;

    for(int i=1; i<=n; i++) {

        cout<<color[i]<<" ";

    } cout<<endl;

    return 0;
}
