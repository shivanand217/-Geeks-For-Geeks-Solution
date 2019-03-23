#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    int n, x, y, z;
    string s;

    int max_;

	while(t--)
	{
		unordered_map<int, vector<string> > ans;

        max_ = INT_MIN;

        cin>>n;

        for(int i=0; i<n; i++)
		{
            cin>>s;
            cin>>x>>y>>z;

            int k = (x+y+z)/3;

            if(max_ <= k)
			{
				max_ = k;
                ans[max_].push_back(s);
			}
		}

        for(int i=0; i<ans[max_].size(); i++)
		{
            cout<<ans[max_][i]<<" ";
		}

		cout<<max_<<endl;
	}

	return 0;
}
