#include<bits/stdc++.h>
using namespace std;

#define maxn 1004

int n;
int a[maxn];

// O(n) space O(n) time
int main()
{
	cin>>n;

    for(int i=0; i<n; i++)
        cin>>a[i];

    int A, B, C;
    cin>>A>>B>>C;

    int maxx=INT_MIN, index;

    for(int i=0; i<n; i++)
	{
        a[i] = (A*a[i]*a[i]+B*a[i]+C);

        if(a[i] > maxx)
		{
			maxx=a[i];
			index=i;
		}
	}

    int *new_ = new int[n];

	int i=0, j=n-1, k=0;

    while(i < index && j > index)
	{
        if(a[i] < a[j])
            new_[k++] = a[i++];
		else
			new_[k++] = a[j--];
	}

    while(i < index)
		new_[k++] = a[i++];

	while(j > index)
		new_[k++] = a[j--];

    new_[k] = maxx;
    for(int i=0; i<n; i++)
	{
		cout<<new_[i]<<" ";
	}
	cout<<endl;

    return 0;
}
