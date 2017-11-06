#include<bits/stdc++.h>
using namespace std;

vector<int> graph[100005];
int color[100005];
bool vis[100005];

int val;

void dfs(int ver, int prevColor) {

    vis[ver]=true;
    if(color[ver] != prevColor)
        val=0;
    for(int i=0;i<graph[ver].size();i++) {
        if(vis[graph[ver][i]]==false)
            dfs(graph[ver][i], prevColor);
    }

    return;
}

bool solve(int ver) {

    bool ans=true;
    val=1;
    memset(vis, false, sizeof(vis));
    vis[ver]=true;

    for(int i=0; i<graph[ver].size(); i++) {
        dfs(graph[ver][i], color[graph[ver][i]]);
        if(val==0) {
            ans=false;
            break;
        }
    }
    return ans;
}

int main() {

    int n,u,v;
    scanf("%d",&n);

    for(int i=0;i<n-1;i++) {
        scanf("%d %d",&u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for(int i=1;i<=n;i++){
		scanf("%d", &color[i]);
    }

    int vertex1=0,vertex2=0;

    for(int i=1;i<=n;i++) {

        for(int j=0;j<graph[i].size();i++) {
            if(color[i] != color[graph[i][j]]) {
                vertex1=i;
                vertex2=graph[i][j];
                break;
            }
        }

        if( (vertex1!=0)&&(vertex2!=0) )
			break;
    }

    if(vertex1==0&&vertex2==0) {
        printf("YES\n");
        printf("1\n");
        return 0;
    }

    if(solve(vertex1)) {

        printf("YES\n");
        printf("%d\n",vertex1);

    } else if(solve(vertex2)) {

        printf("YES\n");
        printf("%d\n",vertex2);

    } else {
        printf("NO\n");
    }

    return 0;
}
