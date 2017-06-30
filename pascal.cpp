#include<bits/stdc++.h>
using namespace std;
int a[26][26];
void precomp()
{
	memset(a, 0, sizeof(a));
    a[0][0]=1;
    a[1][0]=1;
    a[1][1]=1;
    for(int i=2; i<25; i++)
	{
        for(int j=0; j<i+1; j++)
		{
            if(j==0)
			{
				a[i][j] = a[i-1][j];
			}
			else if(j == i)
			{
                a[i][j] = a[i-1][j-1];
			}
			else
			{
                a[i][j] = a[i-1][j-1] + a[i-1][j];
			}
		}
	}
}
int main()
{
	precomp();
	int t, n;
	cin>>t;
	while(t--)
	{
        cin>>n;
        n--;
        for(int i=0; i<n+1; i++)
		{
            cout<<a[n][i]<<" ";
		}cout<<endl;
	}

return 0;
}
