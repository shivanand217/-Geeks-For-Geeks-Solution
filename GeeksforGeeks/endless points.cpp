#include<bits/stdc++.h>
using namespace std;

const int maxn = 100;

int arr[maxn][maxn];

int endless_points(int n)
{
    // we make two matrix each for row and column
    bool row[n][n];
    bool col[n][n];

    // now for each column start from bottom row then fill the blocks as if it is zero then all blocks above
    // it are not endless

    bool endless;
    int ans=0;

    for(int i=0; i<n; i++)
    {
        endless=1;
        for(int j=n-1; j>=0; j--)
        {
            if(arr[j][i] == 0)
            {
                endless = 0;
            }
            col[i][j] = endless;
        }
    }

    // now for each row follow the same rule start from max column
    for(int i=0; i<n; i++)
    {
        endless = 1;
        for(int j=n-1; j>=0; j--)
        {
            if(arr[i][j] == 0)
            {
                endless = 0;
            }
            row[i][j] = endless;
        }
    }
    // now calculate the answer
    for(int i=0; i<n; i++)
    {
        for(int j=1; j<n; j++)
        {
            if(row[i][j] && col[i][j])
            {
                ans++;
            }
        }
    }
    return ans;
}

int main()
{
    int n;
    scanf("%d", &n);

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    int ans = endless_points(n);

    cout<<ans<<endl;
    return 0;
}
