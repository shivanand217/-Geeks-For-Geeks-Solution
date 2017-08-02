#include<bits/stdc++.h>
using namespace std;

void solve(vector<string>& ans, int n, vector<char> vec)
{
    if(vec.size() == n)
	{
        string an = "";
        for(int i=0; i<vec.size(); i++)
		{
            an += vec[i];
		}
		ans.push_back(an);
		return;
	}

    if(vec.size() == 0)
	{
        vec.push_back(0+'0');
        solve(ans, n, vec);

        vec.pop_back();
        vec.push_back(1+'0');

        solve(ans, n, vec);
	}
	else
	{
        if(vec[vec.size()-1] == '1')
		{
            vec.push_back(0+'0');
            solve(ans, n, vec);
		}
		else
		{
			vec.push_back(1+'0');
			solve(ans, n, vec);

			vec.pop_back();
			vec.push_back(0+'0');
            solve(ans, n, vec);
		}
	}

	return;
}

int main()
{
    int n;
    cin>>n;

    // generate all the binary string of size k without consecutive ones
	vector<char> vec;
	vector<string> ans;

    solve(ans, n, vec);
    for(int i=0; i<ans.size(); i++)
	{
        cout<<ans[i]<<" ";
	}

	return 0;
}
