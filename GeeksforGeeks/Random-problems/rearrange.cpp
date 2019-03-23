#include<bits/stdc++.h>
using namespace std;
int a[1005];
int main()
{
    int t;
    cin>>t;
    int n;
    vector<int> aa,b;
    while(t--)
	{
		aa.clear(); b.clear();
		cin>>n;
        for(int i=0; i<n; i++)
			cin>>a[i];

        for(int i=0; i<n; i++)
		{
            if(a[i]<0)
				aa.push_back(a[i]);
			else
				b.push_back(a[i]);
		}

        for(int i=0; i<aa.size(); i++)
			cout<<aa[i]<<" ";
		for(int i=0; i<b.size(); i++)
			cout<<b[i]<<" ";
		cout<<endl;
	}
	return 0;
}
