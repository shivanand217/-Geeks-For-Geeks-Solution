#include<bits/stdc++.h>
#define si(x) scanf("%d",&x)
#define pi(x) printf("%d",x)
#define pc putchar('\n')
#define ps putchar(' ')
using namespace std;

const int k = (int)1e5 + 2;
int n, m, K;
int color[k];
int row[5002] , col[5002];

int main()
{
    int t, cell;
	si(n); si(m); si(K);

    for(int i=1; i<=K; i++)
	{
		si(t); si(cell); si(color[i]);
        if(t == 1)
		{
            row[--cell] = i;
		}
		else
		{
			col[--cell] = i;
		}
	}

    for(int i=0; i<n; i++)
	{
        for(int j=0; j<m; j++)
		{
            pi(color[max(row[i],col[j])]);
            ps;
		}pc;
	}

	return 0;
}
