#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s1, s2;

    int t;
    cin>>t;

    while(t--)
	{
        cin>>s1>>s2;
        map<char, vector<int> > un;

        for(int i=0; i<s1.length(); i++)
		{
			if(un[s1[i]].size() == 0)
				un[s1[i]].push_back(1);
		}

        for(int i=0; i<s2.length(); i++)
		{
			auto it = find(un[s2[i]].begin(), un[s2[i]].end(), 2);

            if(it == un[s2[i]].end())
                un[s2[i]].push_back(2);
		}

        for(auto it=un.begin(); it!= un.end(); ++it)
		{
            if(un[it->first].size() == 1)
                cout<<it->first;
		}
		cout<<endl;
	}

	return 0;
}
