#include<bits/stdc++.h>
using namespace std;

char grid[102][102];
int n,m;

int dx[]={0, 1,  0, -1, -1, 1, 1, -1};
int dy[]={1, 0, -1, 0,  1,  1, -1,-1};

/**bool dfs(int x, int y, string s, int pos, bool &ss)
{
    if(pos == s.length()-1)
	{
        if(grid[x][y] == s[pos])
		{
            return (ss|false);
		}
		return ss|true;
	}

    if(grid[x][y] == s[pos]){

    for(int m=0; m<8; m++)
	{
        if(valid(x+dx[m], y+dy[m]))
		{
				if(dfs(x+dx[m], y+dy[m], s, pos+1, ss))
					return (ss|false);
		}
	}

    }

    return ss|true;
}**/

bool search_(int x, int y, string s)
{
    if(grid[x][y] != s[0])
        return false;

    int len = s.length();

    for(int kp=0; kp<8; kp++)
	{
        int k, ro = x + dx[kp], co = y+ dy[kp];

        for(k = 1; k<len; k++)
		{
            if(ro >= n || ro < 0 || co >= m || co < 0)
				break;

            if(grid[ro][co] != s[k])
				break;

            // move in the same direction
            ro += dx[kp]; co += dy[kp];
		}

		if(k == len)
			return true;
	}

	return false;
}

int main()
{
    int t;
    cin>>t;
    //int n,m;

    while(t--)
	{
		vector<pair<int,int> > v;

		cin>>n>>m;

        for(int i=0; i<n; i++)
			for(int j=0; j<m; j++)
				cin>>grid[i][j];

        string s;
        cin>>s;

        for(int i=0; i<n; i++)
		{
            for(int j=0; j<m; j++)
			{
                if(search_(i, j, s))
				{
                    v.push_back({i, j});
				}
			}
		}

        sort(v.begin(), v.end());

        if(v.size()==0)
		{
            cout<<"-1"<<endl;
		}
		else
		{
		for(int i=0; i<v.size(); i++)
		{
            cout<<v[i].first<<" "<<v[i].second<<", ";
		}
		cout<<endl;
		}
	}

	return 0;
}
