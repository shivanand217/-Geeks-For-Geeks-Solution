#include<bits/stdc++.h>
using namespace std;

void solve(int x, int i)
{
    queue<int> q;
    q.push(i);
    while(!q.empty())
	{
        int num = q.front();
        q.pop();

        if(num <= x)
		{
            cout<<num<<" ";
            int last = num%10;

            if(last == 0)
			{
                q.push(num*10 + (last+1));
			}
			else if(last == 9)
			{
				q.push(num*10 + (last-1));
			}
			else
			{
				q.push(num*10 + (last-1));
				q.push(num*10 + (last+1));
			}
		}
	}
}

void print_jumping(int n)
{
    cout<<"0 ";
    for(int i=1; i<=9; i++)
	{
        solve(n, i);
	}
}

int main()
{
    int t,n;
    cin>>t;

    while(t--)
	{
        cin>>n;
        print_jumping(n);
	}
	return 0;
}
