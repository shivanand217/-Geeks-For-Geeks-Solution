#include<bits/stdc++.h>
using namespace std;

bool vi[2005];

int main()
{
    memset(vi, false, sizeof(vi));

    int n, x, y;
    cin>>n>>x>>y;

    vector<pair<int,int> > v;

    pair<int,int> p;

    for(int i=0; i<n; i++)
	{
        cin>>x>>y;

        p = make_pair(x, y);
        v.insert(p);
	}

    for(int i=0; i<n; i++)
	{
        for(int j=i+1; j<n; j++)
		{

		}
	}

    return 0;
}
