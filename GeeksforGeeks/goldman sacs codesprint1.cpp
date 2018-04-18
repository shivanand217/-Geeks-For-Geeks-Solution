#include<bits/stdc++.h>
using namespace std;
int pi[105];

int main()
{
	int q;
	cin>>q;

	int n, k, x, d;
	double ans1, ans2;
	double tot1;

	while(q--)
	{
		cin>>n>>k>>x>>d;
		tot1 = 0.0;

        for(int i=0; i<n; i++)
		{
            cin>>pi[i];
            ans1 = max(k*1.0, ((x*1.0/100*1.0)*(pi[i]*1.0)));
            tot1 += ans1;
		}

		if(tot1 > d*1.0)
		{
            cout<<"upfront"<<endl;
		}
		else if(tot1 <= d*1.0)
		{
			cout<<"fee"<<endl;
		}
	}

	return 0;
}
