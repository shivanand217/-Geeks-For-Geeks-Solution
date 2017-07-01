#include<bits/stdc++.h>
using namespace std;

int a[102][102];

// expected complexity of this is exponential O(n^n)
int solve_recursion(int i, int j, int n)
{
	// base case
    if(i == n-1)
	{
        return a[i][j];
	}

	int res=0;
	// for all the next row columns except same column as now
	for(int k=0; k<n; k++)
	{
		if(k!=j)
        res = max(res, solve_recursion(i+1, k, n));
	}

	return res + a[i][j];
}

int solve(int n)
{
    int res=0;
    for(int i=0; i<n; i++)
	{
        res = max(res, solve_recursion(0, i, n));
	}
	return res;
}

int main()
{
    int t, n;
    cin>>t;

    while(t--)
	{
        cin>>n;
        for(int i=0; i<n; i++)
		{
			for(int j=0; j<n; j++)
			{
				cin>>a[i][j];
			}
		}

        int ans = solve(n);
        cout<<ans<<endl;
	}

	return 0;
}
