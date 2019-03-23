// AUTHOR: SHIV ANAND
// LANGUAGE: CPP
// TIME COMPLEXITY : O(n*n)
// SPACE COMPLEXITY : O(1)

/** normal of a matrix is the square root of sum of squares of all the matrix elements **/
/** trace is the sum of the diagonal elements **/

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

const int maxn =105;
int mat[maxn][maxn];

int n;

void normal_and_trace()
{
    int normal=0,trace=0;

    for(int i=0; i<n; i++)
    {
      for(int j=0; j<n; j++)
      {
          normal += (mat[i][i]*mat[i][i])%mod;

          if(i == j)
          {
              trace += mat[i][j];
          }
      }
    }

cout<<normal<<" "<<trace<<endl;
return;

}

int main()
{

int n;
read(n)

for(int i=0; i<n; i++)
{
    for(int j=0; j<m; j++)
    {
        read(mat[i][j])
    }
}

normal_and_trace();

return 0;
}
