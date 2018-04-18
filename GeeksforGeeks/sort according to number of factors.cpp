#include<bits/stdc++.h>
using namespace std;

#define maxn 1004
int a[maxn];

unordered_map<int, pair<int,int> > mapp;

bool comp(int x, int y)
{
    if(mapp[x].first == mapp[y].first)
		return (mapp[x].second < mapp[y].second);

	return (mapp[x].first > mapp[y].first);
}

int factors(int n)
{
    int f=0;

    for(int i=1; i*i<=n; i++)
	{
        if(n%i==0)
		{
			if(i == (n/i))
			{
                f++;
			}
			else
				f += 2;
		}
	}

	return f;
}

int main()
{
    int n;
    cin>>n;

    for(int i=0; i<n; i++)
    {
        cin>>a[i];
        int f = factors(a[i]);
        mapp[a[i]] = make_pair(f, i);
    }

    sort(a, a+n, comp);

    for(int i=0; i<n; i++)
    {
    	cout<<a[i]<<" ";
    }cout<<endl;

    return 0;
}
