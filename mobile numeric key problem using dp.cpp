#include<bits/stdc++.h>
using namespace std;

long long int champions_solves_dp_losers_use_recursion(char c[4][3], int n)
{
    if(c == NULL || n <= 0)
        return 0;

    if(n == 1)
        return 10LL;

    int row[] = {0, 0, -1, 0, 1};
    int col[] = {0, -1, 0, 1, 0};

	long long int dp[10][n+1];

    int i, j, k, move, ro, co, num;
    int nextNum;

    long long int totalCount;

    for (i=0; i<=9; i++)
    {
		dp[i][0] = 0LL;
        dp[i][1] = 1LL;
    }

    for (k=2; k<=n; k++)
    {
        for (i=0; i<4; i++)  // Loop on keypad row
        {
            for (j=0; j<3; j++)   // Loop on keypad column
            {
                if (c[i][j] != '*' && c[i][j] != '#')
                {
                    num = c[i][j] - '0';
                    dp[num][k] = 0LL;

                    for (move=0; move<5; move++)
                    {
                        ro = i + row[move];
                        co = j + col[move];

                        if (ro >= 0 && ro <= 3 && co >=0 && co <= 2 && c[ro][co] != '*' && c[ro][co] != '#')
                        {
                            nextNum = c[ro][co] - '0';
                            dp[num][k] = (dp[num][k] + dp[nextNum][k-1]);
                        }
                    }
                }
            }
        }
    }


    totalCount = 0LL;

    for (i=0; i<=9; i++)
        totalCount += dp[i][n];
    return totalCount;

}

int main()
{
    int t, n;
    cin>>t;
    char c[4][3] = {{'1','2','3'},
				   {'4','5','6'},
				   {'7','8','9'},
				   {'*','0','#'}};

    while(t--)
	{
        cin>>n;;
        long long int ans = champions_solves_dp_losers_use_recursion(c, n);
        cout<<ans<<endl;
	}
	return 0;
}
