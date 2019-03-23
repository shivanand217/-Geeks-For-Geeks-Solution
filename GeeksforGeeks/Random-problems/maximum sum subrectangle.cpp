#include<bits/stdc++.h>
using namespace std;

int grid[105][105];

// O(n^3)

int kadane(int *temp, int& start, int& finish, int n)
{
    int sum = 0, maxsum = INT_MIN, i;
    finish = -1;

    int local=0;

    for(int i=0; i<n; i++)
	{
        sum += temp[i];
        if(sum < 0)
		{
			sum = 0;
			local = i+1;
		}
		else if(sum > maxsum)
		{
            maxsum = sum;
            start = local;
            finish = i;
		}
	}

    if(finish != -1)
	{
        return maxsum;
	}

    maxsum = temp[0];
    start = finish = 0;

    for(int i=1; i<n; i++)
	{
		if(temp[i] > maxsum)
		{
			maxsum = temp[i];
            start = finish = i;
		}
	}

	return maxsum;
}

int solve(int n, int m)
{
    int maxsum = INT_MIN;

    int fl, fr, ft, fb;
    int left, right, i;

    int temp[n], sum, start=0, finish=0;

    for(left=0; left < m; left++)
	{
		memset(temp, 0, sizeof(temp));

        for(right = left; right < m; right++)
		{
			for(i=0; i<n; i++)
			{
				temp[i] += grid[i][right];
			}

            sum = kadane(temp, start, finish, n);

            if(sum > maxsum)
			{
				maxsum = sum;
				fl = left;
				fr = right;
				ft = start;
				fb = finish;
			}
		}
	}

	return maxsum;
}

int main()
{
	int t;
	cin>>t;

	int n, m, sum;

	while(t--)
	{
    cin>>n>>m;

    for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
            cin>>grid[i][j];
		}
	}

		sum = solve(n, m);
		cout<<sum<<endl;
	}

	return 0;
}
