#include<bits/stdc++.h>
using namespace std;

int a[1005];

int main()
{
    int t;
    cin>>t;

    int f,l,tmp,n;

    while(t--)
	{
        cin>>n;

        for(int i=0; i<n; i++)
		{
			cin>>a[i];
		}

		if((n&1))
		{
		    l=0;
			for(int i=0; i<n; i+=2)
			{
			    l^=a[i];
			}
			cout<<l<<endl;
		}
		else
		{
            cout<<"0"<<endl;
		}
	}

	return 0;
}
