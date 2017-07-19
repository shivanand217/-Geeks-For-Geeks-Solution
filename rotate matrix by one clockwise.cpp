#include<bits/stdc++.h>
using namespace std;

int a[52][52];
// O(n*m)

int main()
{
	int n;
	cin>>n;

	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			cin>>a[i][j];
		}
	}

	int left_x=0, left_y=0;
	int right_x=0, right_y=n-1;
	int b_left_x=n-1, b_left_y=0;
	int b_right_x=n-1, b_right_y=n-1;

    int i, j, k, l;
    int cnt=0;
    int prev, now;

    while(1)
	{
        if(cnt != 0)
		{
            left_x++; left_y++;
            right_x++; right_y--;
            b_left_x--; b_left_y++;
            b_right_x--; b_right_y--;

            if(left_y == right_y || left_x == b_left_x || b_right_y == b_left_y || right_x == b_right_x)
				break;
		}

		i=left_y;
		prev = a[left_x][i];
		a[left_x][i] = a[left_x+1][left_y];
		i++;

		while(i <= right_y)
		{
			now = a[left_x][i];
			a[left_x][i] = prev;
			prev = now;
			i++;
		}

        j = right_x+1;
        while(j <= b_right_x)
		{
            now = a[j][right_y];
            a[j][right_y] = prev;
			prev = now;
			j++;
		}

        k = b_right_y-1;
        while(k >= b_left_y)
		{
            now = a[b_right_x][k];
            a[b_right_x][k] = prev;
            prev = now;
            k--;
		}

		l = b_left_x-1;
        while(l > left_x)
		{
            now = a[l][b_left_y];
            a[l][b_left_y] = prev;
            prev = now;
            l--;
		}

        if(left_y + 2 == right_y || left_y+1 == right_y)
			break;

		cnt++;
	}

	cout<<endl;
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			cout<<a[i][j]<<" ";
		}cout<<endl;
	}

	return 0;
}
