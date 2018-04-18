#include<bits/stdc++.h>
using namespace std;

// O(1) space
// O(n) time

int a[1002];
int main()
{
	int n;
	cin>>n;

	for(int i=0; i<n; i++)
	{
		cin>>a[i];
	}

	for(int i=0; i<n; i++)
	{
		a[i] -=1;
	}

	for(int i=0; i<n; i++)
	{
		a[a[i]%n] = a[a[i]%n] + n;
	}

	for(int i=0; i<n; i++)
	{
		cout<<(i+1)<<" "<<(a[i]/n)<<endl;
	}

	return 0;
}
