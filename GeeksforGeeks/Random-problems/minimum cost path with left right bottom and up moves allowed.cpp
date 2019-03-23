// AUTHOR: SHIV ANAND
// LANGUAGE: CPP

/** we are using standard disktra's algorithm **/

#include<bits/stdc++.h>
#include<cstdio>
#include<cstdlib>
#define read(val) scanf("%d",&val);
#define print(val) printf("%d ",val);
#define scan(val) scanf("%lld",&val);
#define show(val) printf("%lld ",val);
#define rr(val) for(int i=0; i<val; i++)
#define ret return 0;
#define ll long long
using namespace std;

int graph[20][20];
int dist[20][20];
set<pair<int,pair<int,int> > > set1; // set to find minimum key always

int dx[] = {1,0,-1,0};
int dy[] = {0,-1,0,1};

set<pair<int,pair<int,int> > > ::iterator it;
int n;

bool is_safe_boundary(int x,int y)
{
    if(x>=0 && x<n && y>=0 && y<n)
        return true;
    else
        return false;
}

void solve_disktra()
{
    //start disktra
    set1.insert(make_pair(0,make_pair(0,0))); // insert vertex first 0,0

    while(!set1.empty())
    {
        it=set1.begin();

        for(int i=0; i<4; i++)
        {
            if(is_safe_boundary(it->second.first+dx[i],it->second.first+dy[i]))
            {
                if(dist[it->second.first+dx[i]][it->second.first+dy[i]] > dist[it->second.first][it->second.second] + graph[it->second.first+dx[i]][it->second.first+dy[i]])
                {
                    if(dist[it->second.first+dx[i]][it->second.first+dy[i]] == INT_MAX)
                    {
                        set1.erase()
                    }
                  dist[it->second.first+dx[i]][it->second.first+dy[i]] = dist[it->second.first][it->second.second] + graph[it->second.first+dx[i]][it->second.first+dy[i]];
                }
            }
        }
    }

}

int main()
{
    int n,m;
    cin>>n>>m;

    for(int i=0; i<n; i++)
    {
        for(int i=0; i<n; i++)
        {
            cin>>graph[i][j];
        }
    }

    memset(dist,INT_MAX,sizeof(dist));

    solve_disktra();
}

