#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+2;
int a[maxn];
int find_pivot(int n)
{
    int pivot = -1;
    for(int i=0; i<n-1; i++)
	{
        if(a[i] > a[i+1])
		{
            pivot = i;break;
		}
	}
	return pivot;
}
int b_search(int lo, int hi, int key)
{
    int mid;
    int index = -1;

    while(lo <= hi)
	{
		mid = lo + (hi - lo)/2;

        if(a[mid] == key)
		{
			index = mid;break;
		}
		if(a[mid] < key)
		{
            lo = mid+1;
		}
		else
		{
            hi = mid-1;
		}
	}
	return index;
}
int main()
{
	int t,n,pivot,k;
    cin>>t;
    while(t--)
	{
        cin>>n;
        for(int i=0; i<n; i++)
		{
            cin>>a[i];
		}
		cin>>k;
        pivot = find_pivot(n);
        if(pivot == -1)
		{
			int index = b_search(0, n-1, k);
			printf("%d\n", index);
		}
		else
		{
            if(k == a[pivot])
			{
                printf("%d\n", pivot);
			}
			else if(k == a[pivot+1])
			{
                printf("%d\n", pivot+1);
			}
			else if(k >= a[0] && k <= a[pivot])
			{
                int index = b_search(0, pivot, k);
                printf("%d\n", index);
			}
			else if(k >= a[pivot+1] && k <= a[n-1])
			{
				int index = b_search(pivot+1, n-1, k);
				printf("%d\n", index);
			}
		}
	}

	return 0;
}
