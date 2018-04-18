// AUTHOR: SHIV ANAND
// LANGUAGE: CPP

/**

Given a gold mine of n*m dimensions.
Each field in this mine contains a positive integer which is the amount of gold in tons.
Initially the miner is at first column but can be at any row. He can move only (right->,right up /,right down\)
that is from a given cell, the miner can move to the cell diagonally up towards the right or right or diagonally down towards the right.
Find out maximum amount of gold he can collect.

**/

/**

Input : mat[][] = {{1, 3, 3},
                   {2, 1, 4},
                  {0, 6, 4}};
Output : 12
{(1,0)->(2,1)->(2,2)}

**/

#include<bits/stdc++.h>
#define si(x) scanf("%d",&x)
#define slli(x) scanf("%lld",&x)
#define sli(x) scanf("%ld",&x)
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define LL long long
#define mod 1000000007
#define pfi(x) printf("%d\n",x)
#define pfli(x) printf("%ld\n",x)
#define pflli(x) printf("%lld\n",x)
#define lli long long int
#define ull unsigned long long int
using namespace std;

const int maxn = 1e2+2;
int gold[maxn][maxn];

int dp_maximum_gold(int n,int m)
{
    int dp_gold[n][m];
    memset(dp_gold, 0, sizeof(dp_gold));

    for(int col=m-1; col>=0; col--)
    {
        for(int row =0; row < n; row++)
        {
            // collects right if it is not the last column
            int right_collect = (col == m-1) ? 0 : dp_gold[row][col+1];

            // collect right up if it is not the first row or last column
            int right_up_collect = (col == m-1 || row == 0) ? 0 : dp_gold[row-1][col+1];

            //collect right down if it is not the last row or last column
            int right_down_collect = (col == m-1 || row == n-1) ? 0 : dp_gold[row+1][col+1];

            // now get the max of all the three movements
            dp_gold[row][col] = gold[row][col] + max(right_collect, max(right_down_collect, right_up_collect));
        }
    }

    int max_ = dp_gold[0][0];
    // returns the maximum collection from the first column because initially miner is at any row in the first column
    for(int row=1; row<n; row++)
    {
        max_ = max(max_ , dp_gold[row][0]);
    }
    return max_;
}



int main()
{
    int n,m;
    si(n);
    si(m);

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            si(gold[i][j]);
        }
    }
    int ans = dp_maximum_gold(n,m);
    cout<<ans<<endl;
    return 0;
}

