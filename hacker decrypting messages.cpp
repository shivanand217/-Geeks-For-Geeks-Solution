#include<bits/stdc++.h>
using namespace std;

const int nax = 1000005;
bool is[nax];
long long int lsp[nax];

void f()
{
    memset(lsp, -1, sizeof(lsp));
    for(int i=2; i<nax; i++)
	{
        if(lsp[i] != -1)
			continue;
        for(int j=i; j<nax; j+=i)
		{
            lsp[j]=i;
		}
	}
}

bool possible(int x)
{
    if(x < 4)
		return false;

    long long int z = x;
    vector<long long int> v;

    while(x != 1)
	{
        int y = lsp[x];
        v.push_back(lsp[x]);
        while(x % y == 0)
			x/=y;
	}

    for(int i=0; i<v.size(); i++)
	{
		for(int j=0; j<v.size(); j++)
		{
			if(z%(v[i]*v[j]) == 0)
			{
				long long int temp = z/(v[i]*v[j]);

                if(temp == 1 || is[temp])
					return true;
			}
		}
	}

	return false;
}

int main()
{
	f();
    int n, q, x;
    cin>>n>>q;

    memset(is, false, sizeof(is));

	for(int i=0; i<n; i++)
	{
		cin>>x;
        is[x]=true;
	}

    for(long long int i=2; i<nax; i++)
	{
		if(is[i] == true)
		{
            for(long long int j=i; j<nax; j*=i)
			{
                if(j < nax)
					is[j] = true;
			}
		}
	}

    while(q--)
	{
		cin>>x;

		if(possible(x))
		{
			cout<<"YES"<<endl;
		}
		else
		{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}
