#include<bits/stdc++.h>
using namespace std;

#define maxn 1005

int a[maxn];

int main()
{
    int n;
    cin>>n;

    for(int i=0; i<n; i++)
	{
        cin>>a[i];
	}

    int lo=0, hi=n-1, mid;

    while(lo < hi)
	{
        mid = lo + (hi - lo)/2;

        if(mid == 0 || mid == n-1)
		{
            cout<<a[mid]<<endl;break;
		}

        if((mid&1))
		{
            if(a[mid] != a[mid-1])
			{
                hi = mid-1;
			}
			else
			{
				lo = mid+1;
			}
		}
		else
		{
            if(a[mid] == a[mid+1])
			{
                lo = mid+1;
			}
			else
				hi = mid-1;
		}
	}

    cout<<a[lo]<<endl;

    return 0;
}
