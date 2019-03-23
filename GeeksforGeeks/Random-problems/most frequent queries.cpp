#include<bits/stdc++.h>
using namespace std;
int n, m, le, ri, k;
long long int a[100005];
int l[100005];
int r[100005];
int main()
{
    scanf("%d %d", &n, &m);
    for(int i=0; i<n; i++)
	{
        scanf("%lld", &a[i]);
	}

    for(int i=0; i<n; i++)
	{
        if(i==0)
		{
            l[i]=i;
		}
		else
		{
            if(a[i] == a[i-1])
			{
                l[i] = l[i-1];
			}
			else
			{
				l[i] = i;
			}
		}
	}
    for(int i=n-1; i>=0; i--)
	{
        if(i==n-1)
		{
			r[i] = i;
		}
		else
		{
            if(a[i] == a[i+1])
			{
				r[i] = r[i+1];
			}
			else
			{
				r[i] = i;
			}
		}
	}

    /**for(int i=0; i<n; i++)
	{
        cout<<l[i]<<" ";
	}cout<<endl;

	for(int j=0; j<n; j++)
	{
        cout<<r[j]<<" ";
	}cout<<endl;
	**/

	for(int i=0; i<m; i++)
	{
		scanf("%d %d %d", &le, &ri, &k);

        if(r[((ri-le)/2)] - l[((ri-le)/2)] + 1 >= k)
        {
            printf("%lld\n", a[((ri-le)/2)]);
        }
        else
		{
			printf("-1\n");
		}
	}

return 0;
}
