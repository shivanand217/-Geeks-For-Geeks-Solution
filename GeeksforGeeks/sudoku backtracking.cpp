#include<bits/stdc++.h>
using namespace std;

bool in_box(int grid[10][10], int row, int col, int num)
{
    int last_x, last_y, first_x, first_y;

    if(row ==1 || row == 2 || row == 3)
        last_x=3;
	else if(row ==4 || row == 5 || row == 6)
        last_x=6;
	else if(row ==7 || row == 8 || row == 9)
        last_x=9;

	if(col ==1 || col == 2 || col == 3)
        last_y=3;
	else if(col ==4 || col == 5 || col == 6)
        last_y=6;
	else if(col ==7 || col == 8 || col == 9)
        last_y=9;

    first_x=last_x-2;
    first_y=last_y-2;

    for(int i=first_x; i<=last_x; i++)
	{
        for(int j=first_y; j<=last_y; j++)
		{
            if(i!= row && j!= col)
			{
                if(grid[i][j]==num)
					return true;
			}
		}
	}

	return false;
}

bool in_row(int grid[10][10], int row, int col, int num)
{
    for(int i=1; i<=9; i++)
	{
        if(i != col)
		{
            if(grid[row][i]==num)
				return true;
		}
	}

	return false;
}

bool in_col(int grid[10][10], int row, int col, int num)
{
    for(int i=1; i<=9; i++)
	{
		if(i != row)
		{
			if(grid[i][col] == num)
				return true;
		}
	}
	return false;
}

bool safe(int grid[10][10], int row, int col, int num)
{
    return (!in_row(grid, row, col, num) && !in_col(grid, row, col, num) && !in_box(grid, row, col, num));
}

bool empty_any(int grid[10][10], int& row, int& col)
{
    for(row=1; row<=9; row++)
	{
		for(col=1; col<=9; col++)
		{
            if(grid[row][col] == 0)
				return true;
		}
	}return false;
}

bool solve(int grid[10][10])
{
    int row,col;

    if(empty_any(grid, row, col)==false)
		return true;

    for(int i=1; i<=9; i++)
	{
        if(safe(grid, row, col, i))
		{
            grid[row][col]=i;

			if(solve(grid))
				return true;

			// backtrack
			grid[row][col]=0;
		}
	}

	return false;
}

int main()
{
	int grid[10][10];

    int t;
    cin>>t;

	while(t--)
	{

	for(int i=1; i<=9; i++)
        for(int j=1; j<=9; j++)
			cin>>grid[i][j];

    if(solve(grid))
	{
        for(int i=1; i<=9; i++)
		{
			for(int j=1; j<=9; j++)
			{
				cout<<grid[i][j]<<" ";
			}
		}
		cout<<endl;
	}

	}

    return 0;
}
