#include<bits/stdc++.h>
using namespace std;

int a[105];

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

		if(n==1)
		{
			cout<<a[0]<<endl;
		}
		else{
		int i=0;

		while(i < n-1)
		{
			if(a[i] > a[i+1])
			{
				break;
			}
			i++;
		}

		cout<<a[i]<<endl;
		}
	}

	return 0;
}
