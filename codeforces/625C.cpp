#include<bits/stdc++.h>
#define si(x) scanf("%d",&x)
#define pi(x) printf("%d",x)
using namespace std;

int a[502][502];
int main()
{
    int n,k;
    si(n);
    si(k);

    int sum=0;

    int start1 = n*n - (n-k+1)*n + 1;
    int start2 = 1;

    for(int i=1; i<=n; i++)
	{
        for(int j=k; j<=n; j++)
		{
            a[i][j] = start1++;
            if(j == k)
			{
				sum += a[i][j];
			}
		}
	}

    for(int i=1; i<=n; i++)
	{
        for(int j=1; j<k; j++)
		{
            a[i][j] = start2++;
		}
	}

    pi(sum);
    putchar('\n');
    for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
		{
            pi(a[i][j]);
            putchar(' ');

		}putchar('\n');
	}
    return 0;
}
