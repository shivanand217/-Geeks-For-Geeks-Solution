#include<stdio.h>
#define si(x) scanf("%d", &x)
#define pi(x) printf("%d\n", x);
int a[1002], lmin[1002], rmax[1002];

int min(int x,int y)
{
	return (x<y) ? x : y;
}

int max(int x, int y)
{
    return (x>y) ? x : y;
}

int main()
{
    int t,i,j;
    si(t);
    int n;
    while(t--)
	{
        si(n);
        for(i=0; i<n; i++)
		{
			si(a[i]);
		}
		lmin[0]=a[0];rmax[n-1]=a[n-1];
        for(i=1; i<n; i++)
		{
            lmin[i]=min(lmin[i-1],a[i]);
		}
		for(j=n-2; j>=0; j--)
		{
			rmax[j]=max(rmax[j+1],a[j]);
		}
        int i=0,j=0,mxdiff=-1;
        while(i<n && j<n)
		{
            if(lmin[i] <= rmax[j])
			{
				mxdiff = max(mxdiff, j-i);
				j++;
			}
			else
			{
				i++;
			}
		}
        pi(mxdiff);
	}
	return 0;
}

