#include<bits/stdc++.h>
using namespace std;

int a[102];
int n;
const int max_ = 102*102*102;
int RHS[max_];

// O(n^3 * logn)
int solve()
{
    int index=0;

    for(int i=0; i<n; i++)
	{
        if(a[i] != 0)
		{
            for(int j=0; j<n; j++)
			{
                for(int k=0; k<n; k++)
				{
                    RHS[index++] = a[i]*(a[j] + a[k]);
				}
			}
		}
	}

	sort(RHS, RHS+index);
    int res=0;

    for(int i=0; i<n; i++)
	{
        for(int j=0; j<n; j++)
		{
            for(int k=0; k<n; k++)
			{
                int val = a[i]*a[j] + a[k];
                res += (upper_bound(RHS, RHS+index, val)-
						lower_bound(RHS, RHS+index, val));
			}
		}
	}

	return res;
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
