#include<bits/stdc++.h>

using namespace std;

vector<vector<int> > :: iterator it;

void solve(int num, int sum, vector<int> vec, vector<vector<int> > &ans, int curr_num)
{
    if(sum > num)
		return;

    if(curr_num == num)
	{
		if(vec.size() == 0)
		{
			vec.push_back(num);
            it = find(ans.begin(), ans.end(), vec);
            if(it == ans.end())
			{
                ans.push_back(vec);
			}
            return;
		}
		return;
	}

    if(sum == num)
	{
		it = find(ans.begin(), ans.end(), vec);
		if(it == ans.end())
		{
			ans.push_back(vec);
		}
		return;
	}

    solve(num, sum, vec, ans, curr_num+1); // send empty vector

    vec.push_back(curr_num);

	solve(num, sum+curr_num, vec, ans, curr_num); // push curr and send it again

	solve(num, sum+curr_num, vec, ans, curr_num+1); // push curr and send curr+1

	return;
}

int main()
{
	int n;
	cin>>n;

    vector<vector<int> > ans;
    vector<int> vec;

    solve(n, 0, vec, ans, 1);

    for(int i=0; i<ans.size(); i++)
	{
        for(int j=0; j<ans[i].size(); j++)
		{
            cout<<ans[i][j]<<" ";
		}cout<<endl;
	}

    return 0;
}
