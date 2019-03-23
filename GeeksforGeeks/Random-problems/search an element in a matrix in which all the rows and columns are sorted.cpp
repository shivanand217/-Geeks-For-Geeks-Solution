#include<bits/stdc++.h>
using namespace std;

int a[101][101];
int n,m;

int binary_search_(int lo, int hi, int x)
{
	int mid;
	int index;

	while(lo <= hi && lo < n && hi >= 0)
	{
        mid = lo + (hi - lo)/2;
        if(a[mid][0] == x)
		{
            index = mid;
            return index;
		}
		if(a[mid][0] < x)
		{
            index = mid;
            lo = mid+1;
		}
		else
		{
			index = mid-1;
            hi = mid-1;
		}
	}
	return index;
}

int binary_search_2(int lo, int hi, int x, int index)
{
    bool ans = false;
	int mid;

	while(lo <= hi && lo < m && hi >= 0)
	{
		mid = lo + (hi - lo)/2;
        if(a[index][mid] == x)
		{
            return true;
		}
		if(a[index][mid] < x)
		{
            lo = mid+1;
		}
		else
		{
			hi = mid-1;
		}
	}

    return ans;
}

int main()
{
    int t, x;
    cin>>t;

    while(t--)
	{
        cin>>n>>m;

        for(int i=0; i<n; i++)
		{
			for(int j=0; j<m; j++)
			{
                cin>>a[i][j];
			}
		}
		cin>>x;

		int i=0;
		int j=n-1;
		int index = binary_search_(i, j, x);

		if(index == -1)
		{
			cout<<"0"<<endl;
		}
		else
		{
            if(a[index][0] == x)
			{
				cout<<"1"<<endl;
			}
			else
			{
                i=0;
				j = m-1;
                if(binary_search_2(i, j, x, index))
				{
                    cout<<"1"<<endl;
				}
				else
				{
                    cout<<"0"<<endl;
				}
			}
		}
	}

	return 0;
}
