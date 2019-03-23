#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5+2;

#define ll long long

ll int n;
long long int a[maxn];
long long int k;

struct compare
{
    bool operator()(pair<ll int,ll int> x, pair<ll int,ll int> y)
    {
        return x.second > y.second;
    }
};

int main()
{
    cin>>n;
    for(int i=1; i<=n; i++)
	{
		cin>>a[i];
	}

    priority_queue<pair<ll int,ll int>, vector<pair<ll int,ll int> >, compare> pq;

    for(int i=1; i<=n; i++)
	{
        pq.push(make_pair(i, a[i]));
	}

	pair<ll int,ll int> q;
    cin>>k;

    ll int stocks = 0;
    ll int val;

    while(!pq.empty())
	{
        q = pq.top();
        pq.pop();

		val = (q.first*q.second);

        if(val <= k)
		{
			k -= val;
            stocks += q.first;
		}
		else
		{
			if(q.second <= k)
			{
                ll int am = k/q.second;
                k -= (am*q.second);
                stocks += (am);
			}
		}
	}

    cout<<stocks<<endl;
	return 0;
}
