#include<stdio.h>
#define mod 1000000007
long long int get(char keypad[][3], int n)
{
    if(keypad == NULL || n <= 0)
        return 0;

    if(n == 1)
        return 10;

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
        for (i=0; i<4; i++)
        {
            for (j=0; j<3; j++)
            {
                if (keypad[i][j] != '*' && keypad[i][j] != '#')
                {
                    num = keypad[i][j] - '0';
                    dp[num][k] = 0LL;

                    for (move=0; move<5; move++)
                    {
                        ro = i + row[move];
                        co = j + col[move];
                        if (ro >= 0 && ro <= 3 && co >=0 && co <= 2 && keypad[ro][co] != '*' && keypad[ro][co] != '#')
                        {
                            nextNum = keypad[ro][co] - '0';

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
   char keypad[4][3] = {{'1','2','3'},
                        {'4','5','6'},
                        {'7','8','9'},
                        {'*','0','#'}};
   int t,n;
   scanf("%d", &t);

   while(t--)
   {
        scanf("%d", &n);
		printf("%lld\n", get(keypad, n));
   }
   return 0;
}
