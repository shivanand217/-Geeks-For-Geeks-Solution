#include<bits/stdc++.h>
using namespace std;
int a[105];

// O(n^3)
int main()
{
	int t,n;
	cin>>t;

	int sum;
	int l,r,ans;

	while(t--)
	{
		cin>>n;
		ans=0;
		for(int i=0; i<n; i++)
		{
			cin>>a[i];
		}

        cin>>sum;
        sort(a, a+n);

        for(int i=0; i<n-3; i++)
		{
			if(ans == 1)break;

			for(int j=i+1; j<n-2; j++)
			{
                if(ans==1)break;

				l = j+1;
				r = n-1;

				while(l < r)
				{
					if(a[i]+a[j]+a[l]+a[r] == sum)
					{
						ans=1;break;
					}
					else if(a[i]+a[j]+a[l]+a[r] < sum)
					{
						l++;
					}
					else if(a[i]+a[j]+a[l]+a[r] > sum)
						r--;
				}
			}
		}
        cout<<ans<<endl;
	}
	return 0;
}
