#include<bits/stdc++.h>
#define si(x) scanf("%d", &x)
using namespace std;
int main()
{
	int eq,t,n,k,i,j,a,count,max,flag;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		map <int,int> m;
		scanf("%d%d",&n,&k);
		max=0;

		for(j=0;j<n;j++)
		{
			count=0;
			flag=0;
			scanf("%d" , &a);
			m[a]++;
			if(m[a]>max)
				max=m[a];
			eq=max;
			while(1)
			{
				for(auto it=m.begin();it!=m.end();it++)
				{
					if((it->second)==eq)
					{
						printf("%d ",it->first);
						count++;
					}
					if(count==k)
					{
						flag=1;
						break;
					}
				}
				eq--;
				if(eq==0)
					break;
				if(flag==1)
					break;
			}
		}
		printf("\n");
	}
	return 0;
}
