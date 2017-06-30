#include<bits/stdc++.h>
using namespace std;
int a[1002], lmin[1002], rmax[1002];
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
		lmin[0]=a[0];rmax[n-1]=a[n-1];
        for(int i=1; i<n; i++)
		{
            lmin[i]=min(lmin[i-1],a[i]);
		}
		for(int j=n-2; j>=0; j--)
		{
			rmax[j]=max(rmax[j+1],a[j]);
		}
        int i=0,j=0,mxdiff=-1;
        while(i<n && j<n)
		{
            if(lmin[i] <= rmax[j])
			{
				mxdiff = max(mxdiff, j-i);
				j++;
			}
			else
			{
				i++;
			}
		}
        cout<<mxdiff<<endl;
	}
	return 0;
}
