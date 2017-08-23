#include<bits/stdc++.h>
using namespace std;

int a[1005];

int main()
{
    int t;
    cin>>t;

    int n;
    pair<int,int> q;
	int max_time;
	int cnt;

    while(t--)
	{
		queue<pair<int,int> > ans;

        cin>>n;
        max_time = INT_MIN;
        cnt=0;

        for(int i=0; i<n; i++)
		{
			cin>>a[i];

			if(a[i] == 1)
				{ans.push(make_pair(i, 0));cnt++;}
		}

        if(ans.size() == 0)
		{
            cout<<"-1"<<endl;
            continue;
		}

        if(cnt == n)
		{
            cout<<"0"<<endl;
            continue;
		}

        while(!ans.empty())
		{
			q = ans.front();
			ans.pop();

			max_time = max(max_time, q.second);

            if(q.first == 0)
			{
                if(a[q.first+1] == 0)
				{
                    a[q.first+1] = 1;
                    ans.push(make_pair(q.first+1, q.second+1));
				}
			}
			else if(q.first == n-1)
			{
                if(a[q.first-1] == 0)
				{
					a[q.first-1] = 1;
					ans.push(make_pair(q.first-1, q.second+1));
				}
			}
			else
			{
                if(a[q.first-1] == 0)
				{
					a[q.first-1] = 1;
					ans.push(make_pair(q.first-1, q.second+1));
				}

				if(a[q.first+1] == 0)
				{
                    a[q.first+1] = 1;
                    ans.push(make_pair(q.first+1, q.second+1));
				}
			}
		}

        cout<<max_time<<endl;
	}

	return 0;
}
