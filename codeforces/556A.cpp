#include<bits/stdc++.h>
#define si(x) scanf("%d",&x)
using namespace std;
int main()
{
    int n;
    si(n);

    string s;
    cin>>s;
    int o=0,l=0;

    for(int i=0; i<s.length(); i++)
	{
        if(s[i]=='1')
			l++;
        else
			o++;
	}

    int an = min(o,l);
    int ans = s.length()-(2*an);

    cout<<ans<<endl;

    return 0;
}
