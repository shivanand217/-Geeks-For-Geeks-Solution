// author: shiv anand
// language: cpp
// time complexity: O(row*col)
// space : O(row+col)

#include<bits/stdc++.h>
using namespace std;
#define read(x) scanf("%d",&x)
#define print(x) printf("%d",x)
#define ll long long
#define ull unsigned long long
#define line cout<<endl;
#define chor cout<<" ";

/** Example 1
The matrix
1 0
0 0
should be changed to following
1 1
1 0

Example 2
The matrix
0 0 0
0 0 1
should be changed to following
0 0 1
1 1 1

Example 3
The matrix
1 0 0 1
0 0 1 0
0 0 0 0
should be changed to following
1 1 1 1
1 1 1 1
1 0 1 1
**/

const int maxn = 55;
int ar[maxn][maxn];
int row,col;

bool rows[55];
bool cols[55];

int main()
{

read(row);
read(col);

memset(rows,false,sizeof(rows));
memset(cols,false,sizeof(cols));

for(int i=0; i<row; i++)
{
	for(int j=0; j<col; j++)
	{
		read(ar[i][j]);
		
		if(ar[i][j] == 1)
		{
			rows[i] = 1;
			cols[j] = 1;
		}
	}
}

for(int i=0; i<row; i++)
{
	for(int j=0; j<col; j++)
	{
		if(rows[i] == 1 || cols[j] == 1)
		{
			ar[i][j] = 1;
		}
	}
}

// now print the matrix
for(int i=0; i<row; i++)
{
	for(int j=0; j<col; j++)
	{
		print(ar[i][j]);
		chor
	}
	line
}

return 0;
} 
