#include<bits/stdc++.h>
using namespace std;
long long int a[600005];
long long int cnt[600005];
int main()
{
    int n;
    cin>>n;
    long long int ans=0;
    long long int sum=0;

    for(int i=1; i<=n;i++)
	{
        cin>>a[i];
        sum += a[i];
	}
    if(sum % 3 != 0)
	{
		cout<<"0"<<endl;
		return 0;
	}

    long long int sum2=0;
    for(int i=n; i>=1; i--)
	{
        sum2+=a[i];
        if(sum2 == sum/3)
		{
            if(i==n)
				cnt[i] = 1;
			else
			{
                cnt[i] = cnt[i+1]+1;
			}
		}
		else
		{
            cnt[i] = cnt[i+1];
		}
	}

	sum2=0;
    for(int i=1; i<=n-2; i++)
	{
        sum2 += a[i];
        if(sum2 == sum/3)
		{
            ans += cnt[i+2];
		}
	}

	cout<<ans<<endl;
	return 0;
}
