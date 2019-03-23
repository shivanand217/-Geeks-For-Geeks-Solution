#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5+2;
int a[maxn];

int main()
{
	int t;
	cin>>t;

	int n, maxlen;
	int k;
	int len;
	bool yes;

	while(t--)
	{
		len=0;
		yes = false;
		maxlen=0;

        cin>>n;

		for(int i=0; i<n; i++)
		{
			cin>>a[i];
		}

        cin>>k;

        while(i < n)
		{
            if(a[i] < k)
			{
				i++;
				len++;
			}
			else if(a[i] == k)
			{
				yes = true;
				i++;
				len++;
			}
			else
			{
				if(yes == true)
				{
					maxlen += len;
				}

				len=0;
				yes=false;
				i++;
			}
		}

		if(yes == true)
		{
			maxlen += len;
		}
        cout<<maxlen<<endl;
	}

	return 0;
}
