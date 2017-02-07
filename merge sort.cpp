// AUTHOR: SHIV ANAND
// LANGUAGE: CPP
// TIME COMPLEXITY: O(nlogn)
// SPACE COMPLEXITY: O(n)

#include<bits/stdc++.h>
#define read(val) scanf("%d",&val);
#define print(val) printf("%d ",val);
#define scan(val) scanf("%lld",&val);
#define show(val) printf("%lld ",val);
#define ll long long
using namespace std;

const int maxn = 1e5+2;

int arr[maxn];
int n,mid;

/** it is not a tail recursive algorithm that is also the case where quick sort is efficient than merge sort beacuse in modern day compiler there is a process
of tail call elimination **/

void merge_(int l,int mid_,int r)
{
    int n1= mid_-l + 1;
    int n2= r-mid_;

    int left[n1];int right[n2];

    //store both the parts in a temporary array
    // left part
    for(int i=0; i<n1; i++)
    {
        left[i]=arr[l+i];
    }

    // right part
    for(int i=0; i<n2; i++)
    {
        right[i]=arr[mid_+1+i];
    }

    int i=0; // start index of first subarray
    int j=0; // start index of second subarray
    int k=l; // start index of the merged subarray

    while(i < n1 && j< n2)
    {
        if(left[i] <= right[j])
        {
            arr[k]=left[i];
            i++;
        }
        else
        {
            arr[k]=right[j];
            j++;
        }
        k++;
    }

    // copy the remaining part if exist
    while(i < n1)
    {
        arr[k]=left[i];
        i++;
        k++;
    }

    while(j < n2)
    {
        arr[k]=right[j];
        j++;
        k++;
    }
}

void merge_sort(int l,int r)
{
    if(r > l)
    {
        mid=(l+r)/2;
        merge_sort(l,mid);// sort left subpart
        merge_sort(mid+1,r); // sort right subpart
        merge_(l,mid,r);
    }
}

void print_sorted_array()
{
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }cout<<endl;
}

int main()
{
    read(n)

    for(int i=0; i<n; i++)
    {
        read(arr[i])
    }

    int l=0;
    int r=n-1;

    merge_sort(l,r);
    print_sorted_array();
    return 0;
}
