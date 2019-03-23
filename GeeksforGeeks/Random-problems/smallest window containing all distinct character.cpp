#include<bits/stdc++.h>
using namespace std;

// O(n) n is length of larger string

int main()
{
    int t;
    cin>>t;

    string s;

    while(t--)
	{
	cin>>s;
    unordered_map<char, int> un;

    int len=0;

    for(int i=0; i<s.length(); i++)
	{
		if(un[s[i]]==0)
			{	un[s[i]]++; len++;	}
	}

    int bestWindowLength=INT_MAX, start=0, start_index=-1, count_=0;
    unordered_map<char, int> un2;

	for(int j=0; j< s.length(); j++)
	{
        un2[s[j]]++;

        if(un2[s[j]]==1)
            count_++;

        if(count_ == len)
		{
            // removing useless characters to produce minimum window
            while(un2[s[start]] > 1)
			{
                if(un2[s[start]] > 1)
					un2[s[start]]--;
				start++;
			}

            if(bestWindowLength > j-start+1)
			{
				bestWindowLength = j-start+1;
                start_index = start;
			}
		}
	}

    cout<<bestWindowLength<<endl;
	}

	return 0;
}
