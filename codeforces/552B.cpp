#include<bits/stdc++.h>
using namespace std;

long long int sum[999999];

int main()
{
    long long int n;

    cin>>n;

    int tmp=n;
    int cnt=0;
	int cnt_zero=0;

    long long int ans;

	while(tmp)
	{
        cnt++;

        if(tmp%10==0)
			cnt_zero++;

        tmp/=10;
	}

    sum[1]=1;

    for(int i=2;i<=9;i++)
		sum[i]=sum[i-1]+1;

	for(int i=10;i<=99;i++)
        sum[i]=sum[i-1]+2;

    for(int i=100;i<=999;i++)
		sum[i]=sum[i-1]+3;

    for(int i=1000;i<=9999;i++)
		sum[i]=sum[i-1]+4;

    for(int i=10000;i<=99999;i++)
		sum[i]=sum[i-1]+5;

    for(int i=100000;i<=999998;i++)
		sum[i]=sum[i-1]+6;

    if(n<=999998)
	{
        cout<<sum[n]<<endl;
        return 0;
	}

	if(n==999999)
	{
        cout<<(sum[999998]+6)<<endl;
        return 0;
	}

    if(cnt==7)
	{
        ans = (n-1000000LL+1LL)*7LL+6LL+sum[999998];
	}
	else if(cnt==8)
	{
        ans = (n-10000000LL+1LL)*8LL+(9999999LL-1000000LL+1LL)*7LL+6LL+sum[999998];
	}
	else if(cnt==9)
	{
        ans = (n-100000000LL+1LL)*9+(99999999LL-10000000LL+1LL)*8LL+(9999999LL-1000000LL+1LL)*7LL+6LL+sum[999998];
	}
	else if(cnt==10)
	{
        ans = 10LL+(999999999LL-100000000LL+1LL)*9LL+(99999999LL-10000000LL+1LL)*8LL+(9999999LL-1000000LL+1LL)*7LL+6LL+sum[999998];
	}

    cout<<ans<<endl;

    return 0;
}

