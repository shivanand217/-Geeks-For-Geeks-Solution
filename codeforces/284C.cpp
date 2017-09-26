#include<bits/stdc++.h>
using namespace std;

int a[200005],b[200005];
int ind=1, x, y, op;
double sum;

int main()
{
    int t;
    scanf("%d",&t);

    while(t--)
	{
        scanf("%d",&op);

        if(op == 1)
		{
            scanf("%d %d", &x, &y);
            b[x] += y;
            sum += x*y;
		}
		if(op == 2)
		{
            scanf("%d",&x);
            a[++ind] = x;
            sum += x;
		}
		if(op == 3)
		{
            sum -= a[ind]+b[ind];
            b[ind-1] += b[ind];
            b[ind] = a[ind--] = 0;
		}

        printf("%.6lf\n", ((sum*1.0)/(ind*1.0)));
	}

	return 0;
}
