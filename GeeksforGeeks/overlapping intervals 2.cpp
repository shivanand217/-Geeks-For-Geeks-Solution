#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    int x,y,n;
	pair<int,int> pi,k;
    stack<pair<int,int> > s;

	while(t--)
	{
		vector<pair<int,int> > v;
        cin>>n;

        for(int i=0; i<n; i++)
		{
            cin>>x>>y;
            v.push_back({x,y});
		}

        sort(v.begin(), v.end());

        s.push(v[0]);

        for(int i=1; i<v.size(); i++)
		{
            pi = s.top();
			k = v[i];

            if(k.first<=pi.second)
			{
				int u = max(pi.second, k.second);
				s.pop();
                s.push({pi.first,u});
			}
			else
			{
				s.push(k);
			}
		}

        stack<pair<int,int> > vi;

        while(!s.empty())
		{
            vi.push(s.top());
            s.pop();
		}

        while(!vi.empty())
		{
            cout<<vi.top().first<<" "<<vi.top().second<<" ";
            vi.pop();
		}
		cout<<endl;
	}
	return 0;
}
