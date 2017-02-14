#include<bits/stdc++.h>
using namespace std;

int m[20][20];
int r,c;

queue<pair<int,int> > qu;

int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};

bool valid(int x,int y)
{
   if(x>=0 && x<r && y>=0 && y<c)
        return true;
   else return false;
}

int global_count=1;

void solve()
{

pair<int,int> curr;

int x_,y_;

while(!qu.empty())
{
    curr=qu.front();
    qu.pop();

if(curr.first < 0)
{
    if(qu.size()!=0)
    {
        global_count++;
        qu.push(make_pair(-1,-1));
    }
}
else
{
    for(int i=0; i<4; i++)
    {
        x_=curr.first+dx[i];y_=curr.second+dy[i];
        if(valid(x_,y_))
        {
            if(m[x_][y_] == 1)
            {
                m[x_][y_]=2;
                qu.push(make_pair(x_,y_));
            }
        }
    }
}
}

}

int main()
{
    cin>>r>>c;

    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            cin>>m[i][j];
            if(m[i][j] == 2)
            {
                qu.push(make_pair(i,j));
            }
        }
    }
    qu.push(make_pair(-1,-1));

    solve();

    // finaly decrement global count by 1
    cout<<global_count-1<<endl;
    return 0;
}
