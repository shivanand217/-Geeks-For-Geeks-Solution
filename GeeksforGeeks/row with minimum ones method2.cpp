#include<bits/stdc++.h>
using namespace std;

/**
	0 0 0 0 0
	0 0 0 1 1
	0 0 1 1 1
	0 0 0 0 0
	0 0 0 0 1
**/

int a[105][105];

int main()
{
	int t;
	cin>>t;

	int n ,m;
	bool one;
	int row_index;
	int cnt;
    int min_cnt;

	while(t--)
	{
        cnt = 0;
        min_cnt = INT_MAX;

		one = false;

		cin>>n>>m;

        for(int i=0; i < n; i++)
		{
            cnt=0;
			for(int j=0; j < m; j++)
			{
				cin>>a[i][j];

                if(a[i][j] == 1)
				{
                    one = true;
				}

                if(a[i][j] == 1)
				{
                    cnt++;
				}
			}

            if(cnt < min_cnt && cnt != 0)
            {
                min_cnt = cnt;
                //cnt=0;
                row_index = i;
            }
		}

		if(one == false)
		{
            cout<<"-1"<<endl;
            continue;
		}

		cout<<row_index<<endl;
	}

    return 0;
}
