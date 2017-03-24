// author: shiv anand
// language: cpp
// time complexity: O(n)

#include <bits/stdc++.h>
using namespace std;

const int maxn = 55;
int ar[maxn][maxn];

int main(){
int n;
scanf("%d",&n);


for(int i=0; i<n; i++)
{
	for(int j=0; j<n; j++)
	{
		scanf("%d",&ar[i][j]);
	}
}

int ele;
scanf("%d",&ele);

int i=0;int j=n-1;

while(i<=n-1 && j>=0)
{

if(ar[i][j] == ele)
{
	printf("element found at position:%d $d ",i,j);
	return 0;
}

if(ar[i][j] > ele)
{
	j--;
}
else
{
	i++;
}
	
}
printf("element is not present in the matrix\n");

return 0;
}
