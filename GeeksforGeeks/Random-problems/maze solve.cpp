#include<bits/stdc++.h>
using namespace std;

bool dfs(int x,int y, bool &visited[][],int mat[][], int dest_x,int dest_y)
{
    if(x == dest_x && y == dest_y)
        return true;

    if(x >= n || y >= m)
    {
        return false;
    }

    if(visited[x][y] == true)
    {
        return false;
    }

    if(mat[x][y] == true)
    {
        return false;
    }

    visited[x][y]=true;

    if(dfs(x+1,y,visited,n,m,mat,dest_x,dest_y) == true)
        return true;
    if(dfs(x-1,y,visited,n,m,mat,dest_x,dest_y) == true)
        return true;
    if(dfs(x,y+1,visited,n,m,mat,dest_x,dest_y) == true)
        return true;
    if(dfs(x,y-1,visited,n,m,mat,dest_x,dest_y) == true)
        return true;

    return false;
}

int main()
{
    int n,m;

    scanf("%d",&n);
    scanf("%d", &m);

    int mat[50][50];

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            scanf("%d",&mat[i][j]);
        }
    }

    bool visited[50][50];
    memset(visited, false, sizeof(visited));

    int dest_x, dest_y, src_x, src_y;

    src_x = read_int();
    src_y = read_int();
    dest_x = read_int();
    dest_y = read_int();

    if(dfs(src_x, src_y, visited, mat, dest_x, dest_y))
    {
        cout<<"reachable"<<endl;
    }
    else
    {
        cout<<"not reachable"<<endl;
    }

    return 0;
}
