#include<bits/stdc++.h>
using namespace std;

int a[1005];

// O(n^2)
int main()
{
	int n,sum;
	int t;
	cin>>t;

	while(t--)
	{
		cin>>n>>sum;

		for(int i=0; i<n; i++)
		{
			cin>>a[i];
		}

		sort(a, a+n); //O(n*logn)
        int i, l, r;

        int count_=0;

        for(i=0; i<n-2; i++)
		{
				l = i+1;
                r = n-1;

				// O(n)
                while(l < r)
				{
					if(a[i] + a[l] + a[r] >= sum)
					{
						r--;
					}
					else
					{
                        count_ += (r-l);
                        l++;
					}
				}
		}
        cout<<count_<<endl;
	}

	return 0;
}
