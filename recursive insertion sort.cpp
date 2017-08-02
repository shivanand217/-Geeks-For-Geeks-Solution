#include<bits/stdc++.h>
using namespace std;

int a[102];

void insertion_sort_recursive(int n)
{
    if(n <= 1)
		return;

	insertion_sort_recursive(n-1);

    int last = a[n-1];
    int j=n-2;

    while(j >= 0 && a[j] > last)
	{
		a[j+1] = a[j];
		j--;
	}

	a[j+1] = last;

	return;
}

int main()
{
	int n;
	cin>>n;

	for(int i=0; i<n; i++)
	{
		cin>>a[i];
	}

	insertion_sort_recursive(n);
	for(int i=0; i<n; i++)
		cout<<a[i]<<" ";

	return 0;
}
