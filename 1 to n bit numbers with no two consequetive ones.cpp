#include<bits/stdc++.h>
using namespace std;

const int mod = 1000000007;

map<int, int> ma;

int fast_(int base, int exp)
{
    int res = 1;
    base %= mod;

    while(exp > 0)
	{
        if((exp&1))
		{
            res = (res*base)%mod;
		}

		base = (base*base)%mod;
        exp>>=1;

	}
	return res;
}

void solve(vector<int> ans, int n)
{
	if(ans.size() > n)
		return;

		int po = 0;
        int exp=0;

        for(int i=ans.size()-1; i>=0 ; i--)
		{
			if(ans[i] == 1)
				po += fast_(2, exp);
            exp++;
		}

		ma[po]++;

		if(ans[ans.size()-1] == 1) // if last element is 1 then push 0
		{
            ans.push_back(0);
            solve(ans, n);
		}
		else // if last element is 0 put 0 or 1 with recursion
		{
            ans.push_back(0);
            solve(ans, n);

            ans.pop_back();
            ans.push_back(1);
            solve(ans, n);
		}
}

int main()
{
	int n;
	cin>>n;

	vector<int> ans;
	ans.push_back(1);

    solve(ans, n);

    for(auto it=ma.begin(); it != ma.end(); it++)
	{
        cout<<it->first<<" ";
	}cout<<endl;

    return 0;
}
