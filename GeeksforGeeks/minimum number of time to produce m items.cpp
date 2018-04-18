#include<bits/stdc++.h>
using namespace std;

int a[102];

int find_(int sec)
{
    int ans=0;
    for(int i=0; i<n; i++)
		ans += sec/a[i];

	return ans;
}

int solve(int tmp, int item)
{
    int lo = 1;
    int hi = tmp;
    int mid;

    int itm;
    while(lo <= hi)
	{
        mid = lo + (hi - lo)/2;

        itm = find_(mid);

        if(itm < item)
		{
            lo = mid+1;
		}
		else
		{
			hi = mid;
		}
	}

	return hi;
}

int main()
{
    int n;
    int item;
    cin>>n;
    int max_val = -1;

    for(int i=0;i<n;i++)
	{
		cin>>a[i];
		max_val = max(max_val, a[i]);
	}

    cin>>item;
	// max time will be max_val*(item to be produced)

    int ans = solve(max_val*item, item);
    cout<<ans<<endl;

    return 0;
}
