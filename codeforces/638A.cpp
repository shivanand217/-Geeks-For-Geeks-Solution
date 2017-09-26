#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,a,ans;
    scanf("%d %d", &n, &a);

    if(a%2 == 1)
	{
		ans = (a - 1);
        ans/=2;
        cout<<(ans+1)<<endl;
	}
	else
	{
        ans = (n - a);
        ans/=2;
        cout<<(ans+1)<<endl;
	}
    //cout<<ans<<endl;
	return 0;
}
