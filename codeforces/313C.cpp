#include<bits/stdc++.h>
using namespace std;

bool comp(long long x,long long y)
{
    return (x > y);
}

int main()
{
    long long n,tmp;
    scanf("%lld", &n);

    vector<long long> v;
    v.resize(n);

    for(long long i=0; i<n; i++)
	{
        scanf("%lld", &tmp);
        v.push_back(tmp);
	}

    sort(v.begin(), v.end(), comp);
    long long sum=0;

    for(long long i=1; i<=n; i*=4)
	{
        sum += accumulate(v.begin(), v.begin()+i, 0LL);
	}

    printf("%lld\n", sum);
    return 0;
}
