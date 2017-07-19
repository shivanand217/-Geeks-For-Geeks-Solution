#include<bits/stdc++.h>
using namespace std;

//O(n)
int a[1002];

int main()
{
    int n;
    cin>>n;

    for(int i=0; i<n; i++)
	{
		cin>>a[i];
	}

    int ans=0;
    int len=1;

    for(int i=0; i<n-1; i++)
	{
		if(a[i+1] > a[i])
			len++;
		else
		{
			ans += (len*(len-1))/2;
			len = 1;
		}
	}

    if(len > 1)
	{
		ans += (len*(len-1))/2;
	}
    cout<<ans<<endl;
	return 0;
}
