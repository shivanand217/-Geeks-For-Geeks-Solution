#include<bits/stdc++.h>
using namespace std;

int n;

int main()
{
    int t;
    cin>>t;

    string s;

    while(t--)
	{
        unordered_map<string, int> un;

        cin>>n;

        priority_queue<int> pq;

        int max_ = INT_MIN;

        for(int i=0; i<n; i++)
		{
            cin>>s;
            un[s]++;

            max_ = max(max_, un[s]);
		}

        int sec_most = INT_MIN;
		string ans;

		for(auto it = un.begin(); it != un.end(); ++it)
		{
			if(it->second != max_)
			{
                if(sec_most < it->second)
				{
					sec_most = it->second;
					ans = it->first;
				}
			}
		}

        cout<<ans<<endl;
	}

	return 0;
}
