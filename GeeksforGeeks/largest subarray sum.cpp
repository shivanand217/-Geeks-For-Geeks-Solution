#include<iostream>
#include<cstring>
using namespace std;

// kadane O(n)
int a[1004];

int main()
{
    int n;
    cin>>n;

    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }

    int max_so_far = 0, max_ends_here = 0;

    for(int i=0; i < n; i++)
	{
        max_ends_here = max_ends_here + a[i];

        if(max_ends_here < 0)
		{
			max_ends_here=0;
		}
		else if(max_so_far < max_ends_here)
		{
           max_so_far = max_ends_here;
		}
	}

    cout<<max_so_far<<endl;
	return 0;
}
