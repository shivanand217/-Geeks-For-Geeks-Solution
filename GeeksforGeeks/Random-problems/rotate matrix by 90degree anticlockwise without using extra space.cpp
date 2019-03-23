// AUTHOR: SHIV ANAND
// LANGUAGE: CPP
// TIME COMPLEXITY : O(n*n)
// SPACE COMPLEXITY : O(1)

#include<bits/stdc++.h>
#include<cstdio>
#include<cstdlib>
#define read(val) scanf("%d",&val);
#define print(val) printf("%d ",val);
#define scan(val) scanf("%lld",&val);
#define show(val) printf("%lld ",val);
#define rr(val) for(int i=0; i<val; i++)
#define LL long long
#define mod 1000000007
using namespace std;

const int maxn = 105;
int mat[maxn][maxn];
int n;

/** idea is to first transpose the matrix and after then reverse the column of the matrix **/


void swap_(int *x,int *y)
{
    int *tmp=x;
    x=y;
    y=tmp;
}//*//

void print_matrix()
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
//int n;
read(n)

for(int i=0; i<n; i++)
{
    for(int j=0; j<n; j++)
    {
        read(mat[i][j])
    }
}
print_matrix();

//transpose the matrix
for(int i=0; i<n; i++)
{
    for(int j=i; j<n; j++)
    {
        swap(mat[i][j],mat[j][i]);
    }
}

//reverse the column of the matrix
int low,high;

for(int i=0; i<n; i++)
{
    low = 0;high=n-1;
    while(low < high)
    {
        swap(mat[low][i], mat[high][i]);
        low++;high--;
    }
}
print_matrix();

return 0;
}
