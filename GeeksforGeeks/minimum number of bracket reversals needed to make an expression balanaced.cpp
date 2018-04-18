#include<bits/stdc++.h>
using namespace std;

/**
	remove all the balanced paranthesis
    then answer will be
    ceil(count("(")/2)) + ceil(count("(")/2))

**/

int main()
{
    string s;
    cin>>s;

    unordered_map<char, int> un;
    for(int i=0; i<s.length(); i++)
	{
        if(s[i]== '(')
			un['(']++;
		else
			un[')']++;
	}

	// removing the balanced paranthesis
	stack<char> st;

	char curr;

    for(int i=0; i < s.length(); i++)
	{
        if(i != 0)
		{
			curr = s[i];

            if( curr == ')' )
			{
                if(st.top() == '(')
				{
                    st.pop();
						un['(']--;
						un[')']--;
				}
				else
				{
                    st.push(s[i]);
				}
			}
			else
			{
                st.push(s[i]);
			}
		}
		else
			st.push(s[i]);
	}

	// if number of one of the two will be odd and other is even then not possible to balance the paranthesis
    if(un[')']%2 == 0 && un['(']%2 == 1 || (un[')']%2 == 1 && un['(']%2 == 0))
	{
        cout<<"not possible"<<endl;return 0;
	}

    int ans = ceil(un['(']*1.0/2*1.0) + ceil(un[')']*1.0/2*1.0);
    cout<<ans<<endl;

    return 0;
}
