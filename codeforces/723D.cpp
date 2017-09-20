#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair

typedef pair<int,int> pii;

int n,m,k;
int tempx,tempy;
int cnt=0;
int cnt_lakes=0;

map<int,vector<pair<int,int> > > mapp;

vector<pii> mpp;
vector<pii> border;

int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};

char arr[60][60];
bool vis[100][100];

bool sortt(pii x,pii y)
{
    return (x.second<y.second);
}

bool isvalid(int x,int y)
{
return (x>0 && x<n-1 && y>0 && y<m-1 && arr[x][y]!='*' && vis[x][y]!=true);
}

bool isvalid2(int x,int y)
{
    return (x>=0 && x<n && y>=0 && y<m && arr[x][y]!='*' && !vis[x][y]);
}

int lake_no=1;

void dfs(int x,int y)
{
    vis[x][y]=true;
    mapp[lake_no].pb(mp(x,y));

    for(int i=0;i<4;i++)
    {
        tempx=x+dx[i];
        tempy=y+dy[i];

        if(isvalid(tempx,tempy))
            dfs(tempx,tempy);
    }
}

void dfs2(int x,int y)
{
    vis[x][y]=true;

    for(int i=0;i<4;i++)
    {
        int tmpx=x+dx[i];
        int tmpy=y+dy[i];

        if(isvalid2(tmpx,tmpy))
        {
            dfs2(tmpx,tmpy);
        }
    }
}
int cells=0;

int main()
{
    cin>>n>>m>>k;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>arr[i][j];
            vis[i][j]=false;
            if(i==0 || i==n-1 || j==0 || j==m-1)
            {
                if(arr[i][j]=='.')
                border.pb(mp(i,j));
            }
        }
    }

for(auto it=border.begin();it!=border.end();++it)
{
    if(!vis[it->first][it->second])
    {
        dfs2(it->first,it->second);
    }
}

    for(int i=1;i<n-1;i++)
    {
        for(int j=1;j<m-1;j++)
        {
            if(!vis[i][j] && arr[i][j]=='.')
            {
                dfs(i,j);
                mpp.pb(mp(lake_no,mapp[lake_no].size()));
                lake_no++;
                cnt_lakes++;
            }
        }
    }
sort(mpp.begin(),mpp.end(),sortt);

if(cnt_lakes==k)
{
    cout<<0<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<arr[i][j];
        }
        cout<<endl;
    }
}
else
{
    auto it=mpp.begin();
    while(cnt_lakes!=k)
    {
        if(cnt_lakes==k)
            break;
        for(int j=0;j<mapp[it->first].size();j++)
        {
            arr[mapp[it->first][j].first][mapp[it->first][j].second]='*';
            cells++;
        }
        cnt_lakes--;
        it++;
    }

cout<<cells<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<arr[i][j];
        }
        cout<<endl;
    }
}


return 0;
}
