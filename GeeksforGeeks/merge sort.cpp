#include<bits/stdc++.h>
using namespace std;

#define maxn 1004

void MERGE_(int v[], int lo, int mid, int hi)
{
    int n1 = mid - lo + 1;
    int n2 = hi - mid;

    int Left[n1] ,Right[n2];

    for(int i=0; i<n1; i++)
        Left[i] = v[lo + i];

    for(int j=0; j<n2; j++)
        Right[j] = v[mid + 1 + j];

    int i=0, j=0, k = lo;

    while(i < n1 && j < n2)
	{
        if(Left[i] < Right[j])
		{
			v[k++] = Left[i++];
		}
		else
		{
			v[k++] = Right[j++];
		}
	}

    while(i < n1)
	{
        v[k++] = Left[i++];
	}

	while(j < n2)
	{
        v[k++] = Right[j++];
	}

}

void MS(int v[],int lo, int hi)
{
    if(lo < hi)
	{
		int mid = lo + (hi - lo)/2;
        MS(v, lo, mid);
        MS(v, mid+1, hi);
        MERGE_(v, lo, mid, hi);
	}
}

int main()
{
    int n;
    cin>>n;

    int v[n] ,tmp;

    for(int i=0; i<n; i++)
	{
        cin>>v[i];
	}

	MS(v, 0, n-1);

    for(int i=0; i<n; i++)
	{
		cout<<v[i]<<" ";
	}

	cout<<endl;
	return 0;
}
