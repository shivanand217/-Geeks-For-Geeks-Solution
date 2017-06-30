#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t, n;
    cin>>t;
/**char c = 'C';
cout<<c - 'A'<<endl;
int i = 23;
char p = i + 'A';
cout<<p<<endl;
**/
    while(t--)
	{
        cin>>n;
        string ans = "";
        if(n==1)
			cout<<"A"<<endl;
		else{
        while(n)
		{
            if(n % 26 == 0)
			{
				ans += 'Z';
                n = (n/26)-1;
			}
			else
			{
				ans += (n%26)-1 + 'A';
                n/=26;
			}
		}
            reverse(ans.begin(), ans.end());
            cout<<ans<<endl;
		}
	}
    return 0;
}
