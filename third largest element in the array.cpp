#include<bits/stdc++.h>
using namespace std;

#define maxn 1004
int ar[maxn];

int main()
{
    int n;
    cin>>n;

    for(int i=0; i<n; i++)
		cin>>ar[i];

    int a=INT_MIN, b=INT_MIN, c=INT_MIN;

    a = max(ar[0], max(ar[1], ar[2]));

    if(ar[0]==a)
	{
		b=max(ar[1], ar[2]);
	}
	else if(ar[1]==a)
	{
		b=max(ar[0], ar[2]);
	}
	else
	{
        b=max(ar[0], ar[1]);
	}

	int i=3;

    while(i < n)
	{
        if(ar[i]>c)
		{
			if(ar[i]>b)
			{
				if(ar[i] > a)
				{
					c=b;
					b=a;
					a=ar[i];
				}
				else
				{
                    c=b;
                    b=ar[i];
				}
			}
			else
			{
                c = ar[i];
			}
		}
		i++;
	}

    cout<<c<<endl;

    return 0;
}
