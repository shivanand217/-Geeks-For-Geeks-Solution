#include<bits/stdc++.h>
using namespace std;

void heapify(int a[], int n, int i)
{
    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;

    if(left < n && a[left] > a[largest])
	{
		largest = left;
	}

	if(right < n && a[right] > a[largest])
	{
		largest = right;
	}

	if(largest != i)
	{
        swap(a[i], a[largest]);

        heapify(a, n, largest);
	}
}

void heap_sort(int a[], int n)
{
	// first we heapify the elements in this case i am creating max heap
	for(int i=n/2-1; i>=0; i--)
	{
		heapify(a, n, i);
	}

	for(int i=n-1; i>=0; i--)
	{
		swap(a[i], a[0]);
		heapify(a, i, 0);
	}
}

int main()
{
    int a[] = {4, 10, 3, 5, 1};
    int s = sizeof(a)/sizeof(a[0]);

    heap_sort(a,s);

    for(int i=0; i<s; i++)
	{
        cout<<a[i]<<" ";
	}cout<<endl;

	return 0;
}
