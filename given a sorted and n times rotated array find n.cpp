#include<bits/stdc++.h>
using namespace std;

#define maxn 105

int arr[maxn];

int solve(int lo, int hi)
{
    int mid , pivot = -1;

    while(lo <= hi)
	{
        if(lo == hi)
            break;

		mid = lo + (hi - lo)/2;

        if(mid < hi && arr[mid] > arr[mid+1])
		{
            return mid+1;
		}

		if(mid > lo && arr[mid] < arr[mid-1])
		{
            return 0;
		}

        if(arr[hi] == arr[mid])
		{
            int i = mid;

            while(i < hi)
			{
                if(arr[i] == arr[i+1])
					i++;
                else
                    break;
			}

            if(i == hi)
			{
                hi = mid;
			}
			else
			{
                return i+1;
			}
		}
		else
		{

        if(arr[hi] > arr[mid])
		{
            hi = mid;
		}
		else
			lo = mid+1;

		}
	}

    return 0;
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
            cin>>arr[i];
		}

        if(n==1 || n==2)
		{
			if(n==1)
            cout<<"0"<<endl;
            else
			{
				if(arr[0] < arr[1])
					cout<<"0"<<endl;
				else
					cout<<"1"<<endl;
            }
		}
		else
		{
			int pivot = solve(0, n-1);
			cout<<pivot<<endl;
		}
	}

	return 0;
}
