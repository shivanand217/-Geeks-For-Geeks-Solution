#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    string s1,s2;
    bool ans;

    while(t--)
	{
		ans = false;
        cin>>s1>>s2;

        s2 = s2+s2;

        int i;
        int j, k;

        for(int i=0; i<s2.length(); i++)
		{
            if(s2[i] == s1[0])
			{
                j=0;
                k=i;

                while(s2[k] == s1[j] && j < s1.length())
				{
                    k++;
                    j++;
				}

                if(j==s1.length())
				{
					ans=true;
					break;
				}
			}
		}

		if(ans)
		{
			cout<<"1"<<endl;
		}
		else
		{
            cout<<"0"<<endl;
		}
	}

	return 0;
}
