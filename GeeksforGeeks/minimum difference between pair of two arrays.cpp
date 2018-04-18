#include<bits/stdc++.h>
using namespace std;

#define maxn 1004

int n, m;
int a1[maxn], a2[maxn];

int main()
{
    cin>>n>>m;

    for(int i = 0; i < n; i++)
		cin>>a1[i];

	for(int i = 0; i < m; i++)
		cin>>a2[i];

    sort(a1, a1+n);
	sort(a2, a2+m);

    int i=0, j=0;
    int minn = abs(a1[i] - a2[j]);

    unordered_map<int, vector<pair<int,int> > > un;

    while(i < n && j < m)
	{
		if(minn >= (abs( a1[i]- a2[j] )))
		{
			minn = abs(a1[i] - a2[j]);

			un[minn].push_back(make_pair(a1[i], a2[j]));
		}

        if(a1[i] > a2[j])
            j++;
		else
			i++;
	}

    cout<<minn<<endl;

    for(int i=0; i < un[minn].size(); i++)
        cout<<un[minn][i].first<<" "<<un[minn][i].second<<endl;

	return 0;
}
