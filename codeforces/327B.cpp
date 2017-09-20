#include<stdio.h>
int map[50][50];
int rui[51][51];
int dat[50][50][50][50];
int ans[51][51][51][51];
int main()
{
	int mx,my,query;
	scanf("%d%d%d",&mx,&my,&query);
	for(int i=0;i<mx;i++)
	{
		for(int j=0;j<my;j++)
		{
			char zan;
			scanf(" %c",&zan);
			map[i][j]=zan-'0';
		}
	}
	for(int i=0;i<mx;i++)
	{
		for(int j=0;j<my;j++)
		{
			rui[i+1][j+1]=rui[i+1][j]+rui[i][j+1]-rui[i][j]+map[i][j];
		}
	}
	for(int i=0;i<mx;i++)
	{
		for(int j=0;j<my;j++)
		{
			for(int k=i;k<mx;k++)
			{
				for(int l=j;l<my;l++)
				{
					if(rui[k+1][l+1]-rui[i][l+1]-rui[k+1][j]+rui[i][j]==0)
					{
						dat[i][j][k][l]=1;
					}
				}
			}
		}
	}
	for(int i=0;i<mx;i++)
	{
		for(int j=0;j<my;j++)
		{
			for(int k=0;k<mx;k++)
			{
				for(int l=0;l<my;l++)
				{
					ans[i+1][j+1][k+1][l+1]
					=ans[i][j+1][k+1][l+1]
					+ans[i+1][j][k+1][l+1]
					+ans[i+1][j+1][k][l+1]
					+ans[i+1][j+1][k+1][l]
					-ans[i][j][k+1][l+1]
					-ans[i][j+1][k][l+1]
					-ans[i][j+1][k+1][l]
					-ans[i+1][j][k][l+1]
					-ans[i+1][j][k+1][l]
					-ans[i+1][j+1][k][l]
					+ans[i+1][j][k][l]
					+ans[i][j+1][k][l]
					+ans[i][j][k+1][l]
					+ans[i][j][k][l+1]
					-ans[i][j][k][l]
					+dat[i][j][k][l];
				}
			}
		}
	}
	for(int p=0;p<query;p++)
	{
		int a,b,c,d;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		a--;
		b--;
		c--;
		d--;
		printf("%d\n",
			ans[c+1][d+1][c+1][d+1]
			-ans[a][d+1][c+1][d+1]
			-ans[c+1][b][c+1][d+1]
			-ans[c+1][d+1][a][d+1]
			-ans[c+1][d+1][c+1][b]
			+ans[a][b][c+1][d+1]
			+ans[a][d+1][a][d+1]
			+ans[a][d+1][c+1][b]
			+ans[c+1][b][a][d+1]
			+ans[c+1][b][c+1][b]
			+ans[c+1][d+1][a][b]
			-ans[c+1][b][a][b]
			-ans[a][d+1][a][b]
			-ans[a][b][c+1][b]
			-ans[a][b][a][d+1]
			+ans[a][b][a][b]);
	}
}
