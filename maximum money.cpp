#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t,n,money,ans;
    cin>>t;

    while(t--)
	{
		cin>>n>>money;

        if((n&1))
		{
            ans = (n/2+1)*money;
		}
		else
		{
            ans = (n/2)*money;
		}

		cout<<ans<<endl;
	}

	return 0;
}
