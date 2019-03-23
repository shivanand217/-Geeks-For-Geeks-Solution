#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    int n;
    string s;

    while(t--)
	{
		unordered_map<string ,int> un;
		cin>>n;

        for(int i=0; i<n; i++)
		{
            cin>>s;
            un[s]++;
		}

        int cnt=0;

        for(auto it=un.begin(); it != un.end(); ++it)
		{
            if(it->second == 2)
			{
                cnt++;
			}
		}

        cout<<cnt<<endl;
	}

	return 0;
}
