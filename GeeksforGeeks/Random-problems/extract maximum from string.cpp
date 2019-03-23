#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;

	string s;
	int num;
	int max_no;

    while(t--)
	{
		max_no = INT_MIN;
		cin>>s;

        int i=0;

        while(i < s.length())
		{
			string k = "";

			if((int)s[i] == 48)
			{
                if(max_no < 0)
					max_no = 0;
				i++;
			}
            else if((int)s[i] > 48 && (int)s[i] <= 57)
			{
                while((int)s[i] >= 48 && (int)s[i] <= 57)
				{
                    k += s[i++];
				}

				num = 0;
                int m = 0;

                while(m < k.length())
				{
                    num = num*10 + (k[m]-'0');
                    m++;
				}

                if(num > max_no)
					max_no = num;
			}
			else
				i++;
		}

        cout<<max_no<<endl;
	}
    return 0;
}
