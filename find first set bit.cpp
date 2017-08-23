#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    long int n; int pos;

    while(t--)
	{
        cin>>n;

        if(n==0)
		{
			cout<<"0"<<endl;
		}
		else
		{
            pos=1;

            while(n)
			{
				if((n&1))
				{
					break;
				}
				pos++;
				n>>=1;
			}
		}

		cout<<pos<<endl;
	}

	return 0;
}
