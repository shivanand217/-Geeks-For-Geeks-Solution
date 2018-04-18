#include<bits/stdc++.h>
using namespace std;

int a[100005];

int main()
{
    int t;
    cin>>t;

    int n;

    while(t--)
	{
        cin>>n;

        for(int i=0; i<n; i++)
		{
			cin>>a[i];
		}

        int i=0;

        while(i < n && a[i] == 0)i++;

        if(i == n)
		{
            cout<<"-1"<<endl;
		}
		else
		{
            cout<<i<<endl;
		}
	}

	return 0;
}
