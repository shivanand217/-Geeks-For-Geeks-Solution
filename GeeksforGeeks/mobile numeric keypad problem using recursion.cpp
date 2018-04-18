#include<bits/stdc++.h>
using namespace std;

int row[] = {0,0,1,0,-1};
int col[] = {0,1,0,-1,0};

bool valid(char c[][3], int x, int y)
{
    return (x >=0 && x<4 && y>=0 && y<3 && c[x][y] != '*' && c[x][y] != '#');
}

int count_(char c[][3], int x, int y, int n)
{
    if(c == NULL || n<=0)
		return 0;

	// only one key of length 1 is posssible with this key
	if(n == 1)
		return 1;

    int ro = 0, co = 0, total_count=0;

    for(int m = 0; m<5; m++)
	{
        if(valid(c, x+row[m], y+col[m]))
		{
			total_count += count_(c, x+row[m], y+col[m], n-1);
		}
	}
    return total_count;
}

int count_numeric(char c[][3], int n)
{
    int total_count=0;

    if(c == NULL || n <= 0)
		return 0;

	// 10 numbers are possible with length 1
	if(n == 1)
		return 10;

    for(int i=0; i<4; i++)
	{
        for(int j=0; j<3; j++)
		{
            if(c[i][j] != '*' && c[i][j] != '#')
				total_count += count_(c, i, j, n);
		}
	}

	return total_count;
}

int main()
{
    int t;
    cin>>t;

    char c[][3] = {'1','2','3',
				  '4','5','6',
				  '7','8','9',
				  '*','0','#'};
	int n;
    while(t--)
	{
        cin>>n;
        int ans = count_numeric(c, n);

        cout<<ans<<endl;
	}

	return 0;
}
