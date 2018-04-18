#include<bits/stdc++.h>
using namespace std;

int a[100005];

const int mod = 1000000007;

int main()
{
    int t;
    cin>>t;

    int rem[3];
    int n;

    while(t--)
	{
		memset(rem, 0, sizeof(rem));
        cin>>n;

        for(int i=0; i<n; i++)
		{
            cin>>a[i];
            rem[a[i]%3]++;
		}

        int ans = (rem[0]*(rem[0]-1))/2 + (rem[1]*rem[2]);

        ans += (rem[0]*(rem[0]-1)*(rem[0]-2))/6 + (rem[1]*(rem[1]-1)*(rem[1]-2))/6
				+ (rem[2]*(rem[2]-1)*(rem[2]-2))/6
				+ (rem[0]*rem[1]*rem[2]);

        cout<<ans<<endl;
	}

	return 0;
}
