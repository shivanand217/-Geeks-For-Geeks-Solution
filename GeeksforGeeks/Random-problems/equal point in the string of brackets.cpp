#include<bits/stdc++.h>
using namespace std;

int open[1004];
int close[1004];

int main()
{
    string s;

	int t;
	cin>>t;

	int op,cl;

	while(t--)
	{
		op=0, cl=0;
        cin>>s;

        for(int i=0; i<s.length(); i++)
		{
            if(s[i] == '(')
			{
                if(i!=0)
					open[i] = 1+open[i-1];
                else
					open[i] = 1;
                op++;
			}
			else
			{
                if(i==0)
					open[i]=0;
                else
					open[i]=open[i-1];
			}
		}

        for(int i=s.length()-1; i>=0; i--)
		{
			if(s[i] == ')')
			{
                if(i!=s.length()-1)
					close[i] = 1+close[i+1];
                else
					close[i]=1;
				cl++;
			}
			else
			{
                if(i==s.length()-1)
					close[i]=0;
                else
					close[i]=close[i+1];
			}
		}

        if(op==0 || cl == 0)
		{
            cout<<s.length()<<endl;
            continue;
		}

		bool ans = false;
		int pos;

        for(int i=0; i<s.length()-1; i++)
		{
            if(open[i] == close[i+1])
			{
                pos = i+1;
                ans = true;
                break;
			}
		}

        if(ans == true)
		{
            cout<<pos<<endl;
		}
		else
		{
            cout<<s.length()<<endl;
		}
	}

	return 0;
}
