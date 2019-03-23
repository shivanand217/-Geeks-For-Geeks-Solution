#include<bits/stdc++.h>
using namespace std;

int a[100005];

int main()
{
	int t, n, tmp;
	cin>>t;

    queue<int> odd;
    queue<int> even;

	while(t--)
	{
        cin>>n;

        for(int i=0; i<n; i++)
		{
			cin>>tmp;

			if((tmp&1))
			{
				odd.push(tmp);
			}
			else
			{
				even.push(tmp);
			}
		}

		int i = 0, k;

		while(i < n)
		{
            if(odd.empty() || even.empty())break;

            if((i&1))
			{
                k = odd.front();
                odd.pop();
                cout<<k<<" ";
			}
			else
			{
                k = even.front();
                even.pop();
                cout<<k<<" ";
			}

			i++;
		}

        while(odd.empty() == false)
		{
			k = odd.front();
			odd.pop();
            cout<<k<<" ";
		}

		while(even.empty() == false)
		{
			k = even.front();
			even.pop();
            cout<<k<<" ";
		}

        cout<<endl;
	}

	return 0;
}
