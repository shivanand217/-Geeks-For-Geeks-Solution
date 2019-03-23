// AUTHOR: SHIV ANAND
// LANGUAGE: CPP

/**We have given numbers in form of triangle,
by starting at the top of the triangle and moving to adjacent numbers on the row below,
  find the maximum total from top to bottom.

Input :
   3
  7 4
 2 4 6
8 5 9 3
Output : 23
Explanation : 3 + 7 + 4 + 9 = 23

we just convert it in a form of 2d grid and that act as minimum path cost sum problem solved using bottom up dp **/


#include<bits/stdc++.h>
#define si(x) scanf("%d",&x)
#define slli(x) scanf("%lld",&x)
#define sli(x) scanf("%ld",&x)
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define ll long long
#define mod 1000000007
#define pfi(x) printf("%d\n",x)
#define pfli(x) printf("%ld\n",x)
#define pflli(x) printf("%lld\n",x)
#define lli long long int
#define ull unsigned long long int
using namespace std;

const int maxn = 50;
const int n=4;

int dp_bottom_up(int arr[][n+1], int p)
{
    for(int i= p-1; i>=0; i--)
    {
        for(int col=0; col<=i; col++)
        {
            arr[i][col] = arr[i][col] +  min(arr[i+1][col], arr[i+1][col+1]);


          /*  if(arr[i+1][col] > arr[i+1][col+1])
            {
                arr[i][col] = arr[i][col] + arr[i+1][col+1];
            }
            else
            {
                arr[i][col] = arr[i][col] + arr[i+1][col];
            }*/
        }
    }

    return arr[0][0];
}

int main()
{
    //int n; // maximum length of the base of triangle
    //si(n);

    int j;

    int arr[n+1][n+1];

    for(int k=0; k<n; k++)
    {
        for( j=0; j<=k; j++)
        {
            si(arr[k][j]);
        }

        for(int m=j ; m<=n; m++)
        {
            arr[k][m] = 0;
        }
    }
 /*   for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }*/

    int ans = dp_bottom_up(arr, n+1);
    cout<<ans<<endl;

    return 0;
}

