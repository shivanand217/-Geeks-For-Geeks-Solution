#include<bits/stdc++.h>
using namespace std;

// O(log(max(n,m))
// arrays are sorted

int a[102];
int b[102];
int n ,m;

int missing_element(int lo, int hi, bool k)
{
	if(n == 0 || m == 0)
	{
		if(n == 0)
		{
			return b[0];
		}
		else
		{
			return a[0];
		}
	}

	if(a[0] != b[0])
	{
		if(n < m)
			return b[0];
		return a[0];
	}

    int mid;

    while(lo < hi)
	{
		mid = lo + (hi - lo)/2;

		if(a[mid] == b[mid])
		{
			lo = mid;
		}
		else
		{
			hi = mid;
		}
		if(lo == hi-1)
		{
			break;
		}
	}

	if(k)
		return a[hi];

	return b[hi];
}

int main()
{
    cin>>n>>m;

    for(int i=0; i<n; i++)
	{
        cin>>a[i];
	}

    for(int j=0; j<m; j++)
	{
		cin>>b[j];
	}

    if(n == m)
	{
		cout<<"0"<<endl;
		return 0;
	}

    (n > m) ? (cout<<missing_element(0, n-1, true)<<endl) : (cout<<missing_element(0, m-1, false)<<endl);

    return 0;
}
