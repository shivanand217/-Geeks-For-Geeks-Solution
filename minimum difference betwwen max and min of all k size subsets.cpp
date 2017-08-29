#include<bits/stdc++.h>
using namespace std;

#define maxn 1004

int a[maxn];

int main()
{
    int n;
    cin>>n;

    for(int i=0; i<n; i++)
        cin>>a[i];

    int k; // subset size
    cin>>k;

    sort(a, a+n);

    int i=0;
    int min_diff = INT_MAX;

    while(i <= n-k)
	{
        min_diff = min(min_diff, (a[i+k-1]-a[i]));
        i++;
	}

	cout<<min_diff<<endl;

    return 0;
}
