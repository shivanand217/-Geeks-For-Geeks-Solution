#include<bits/stdc++.h>
using namespace std;
int a[1005];
int main()
{
    int t,n;
    cin>>t;
    int neg=0;
    while(t--)
	{
		neg=0;
        cin>>n;
        for(int i=0; i<n; i++)
		{
			cin>>a[i];
			if(a[i]<0)neg++;
		}
        if(neg == 0)
		{
			for(int i=0; i<n; i++)
			{
            cout<<a[i]<<" ";
			}	cout<<endl;
		}
		else{
        int i=0, j=n-1;
        while(i < n && j >= 0)
		{
            while(i < n)
			{
				if(a[i] < 0)
					i++;
				else break;
			}
			while(j >= 0)
			{
				if(a[j] > 0)
					j--;
				else break;
			}
			if(i > n || j < 0 || i > j)break;
			swap(a[i], a[j]);
		}
        for(int i=0; i<n; i++)
		{
            cout<<a[i]<<" ";
		}cout<<endl;
		}
	}
	return 0;
}
