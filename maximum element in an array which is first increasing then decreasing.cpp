#include<bits/stdc++.h>
using namespace std;

int a[1002];
int n;

// O(logn)
int solve()
{
    int lo=0;
    int hi=n-1;
    int mid;

    while(lo <= hi)
	{
        mid = lo + (hi - lo)/2;

        if(lo == hi)
		{
            return a[lo];
		}

        if(hi == lo+1)
		{
            if(a[lo] > a[hi])
			{
                return a[lo];
			}
			else
				return a[hi];
		}

        if(a[mid] > a[mid-1] && a[mid] > a[mid+1])
			return a[mid];

        if(a[mid] > a[mid+1] && a[mid] < a[mid-1])
		{
            hi = mid-1;
		}
		else
		{
            lo = mid+1;
		}
	}
}

int main()
{
    cin>>n;
    for(int i=0; i<n; i++)
	{
        cin>>a[i];
	}

    int ans = solve();

    cout<<ans<<endl;

	return 0;
}
