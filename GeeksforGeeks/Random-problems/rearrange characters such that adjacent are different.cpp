#include<bits/stdc++.h>
using namespace std;

// O(nlog(n))
struct compare{
	bool operator()(const pair<char, int>& x , const pair<char, int>& y)
	{
		return x.second < y.second;
	}
};

int main()
{
    int t;
    cin>>t;

    string s ,ans;
    priority_queue<pair<char, int> , vector<pair<char, int> > , compare> pq;

    int freq[256];

    while(t--)
	{
		ans="";
		memset(freq, 0, sizeof(freq));

        cin>>s;

		for(int i=0; i<s.length(); i++)
		{
			freq[s[i] - 'a']++;
		}

        for(char c='a'; c<='z'; c++)
		{
            if(freq[c - 'a'] > 0)
			{
				pq.push(make_pair(c, freq[c - 'a']));
			}
		}

        pair<char , int> prev;
        prev = {'#', -1};

        pair<char, int> k;

        while(!pq.empty())
		{
			k = pq.top();
            pq.pop();

            ans += k.first;

            if(prev.second > 0)
			{
				pq.push(prev);
			}

			(k.second)--;
            prev = k;
		}

		if(ans.length() == s.length())
			cout<<"1"<<endl;
		else
			cout<<"0"<<endl;

	}

	return 0;
}
