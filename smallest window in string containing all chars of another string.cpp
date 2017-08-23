#include<bits/stdc++.h>
using namespace std;

// O(n) n is length of larger string

int main()
{
    string s1,s2;

    s1 = "shiv anand is a biggest Dumb";
    s2 = "aivD";

    if(s1.length() < s2.length())
		{cout<<"-1"<<endl; return 0;}

	if(s1.length() == s2.length())
		{cout<<s1.length()<<endl; return 0;}

    unordered_map<char, int> un, un2;

    for(int i=0; i<s2.length(); i++)
	{
        un[s2[i]]++;
	}

    int i=0;

    int bestWindowLength = INT_MAX, start_index=-1, count_=0;
	int start=0;

    for(int i=0; i<s1.length(); i++)
	{
		un2[s1[i]]++;

        if(un[s1[i]] != 0 && un2[s1[i]] <= un[s1[i]])
			count_++;

		if(count_ == s2.length())
		{
            // removing useless characters
            while(un2[s1[start]] > un[s1[start]] || un[s1[start]] == 0)
			{
                if(un2[s1[start]] > un[s1[start]])
					un2[s1[start]]--;
				start++;
			}

			if(bestWindowLength > i-start+1)
				{
					bestWindowLength = i-start+1;
					start_index = start;
				}
		}
	}

	if(start_index == -1)
		{cout<<"-1"<<endl;return 0;}

    cout<<s1.substr(start_index, bestWindowLength)<<endl;
    return 0;
}
