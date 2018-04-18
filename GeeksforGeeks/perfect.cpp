#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    int n;
    while(t--)
	{
        cin>>n;
        int sum=1;
        for(int i=2; i*i<=n; i++)
		{
            if(n%i == 0)
			{
                sum += i;
                sum += n/i;
			}
		}
		if(n==1)
		{
			cout<<"0"<<endl;
		}else{
	    if(sum == n)
		{

            cout<<"1"<<endl;
		}
		else
		{
            cout<<"0"<<endl;
		}
		}
	}
	return 0;
}
