#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    string s;
    int cnt1, cnt2;

    while(t--)
	{
        cin>>s;
        cnt1=0;
        cnt2=0;

		char z='0';

        for(int i=0; i<s.length(); i++)
		{
                if(s[i] != z)
				{
                    cnt1++;
				}

				if(z=='0')z='1';else z='0';
		}

        z = '1';

        for(int i=0; i<s.length(); i++)
		{
            if(s[i] != z)
				cnt2++;

			if(z=='0')z='1';else z='0';
		}

        cout<<min(cnt1, cnt2)<<endl;
	}
	return 0;
}
