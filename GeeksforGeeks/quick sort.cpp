// AUTHOR: SHIV ANAND
// LANGUAGE: CPP
// TIME COMPLEXITY: O(nlogn)
// SPACE COMPLEXITY: O(1)

#include<bits/stdc++.h>
#define read(val) scanf("%d",&val);
#define print(val) printf("%d ",val);
#define scan(val) scanf("%lld",&val);
#define show(val) printf("%lld ",val);
#define rr(val) for(int i=0; i<val; i++)
#define ret return 0;
#define ll long long
using namespace std;

const int maxn = 1e5+2;

int arr[maxn];
int n;

/** in partition process we choose pivot as the last element then place the pivot at its correct position such that every element before pivot is less
than the pivot and every element after pivot is greater than the pivot
**/

void swap_(int *x,int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}

int partition_(int low,int high)
{

    int pivot=high; //choosen last element as the pivot
    int i=low-1; // initial index smaller than low

    for(int j=low; j<=high-1; j++)
    {
        if(arr[pivot] >= arr[j])
        {
            i++;
            swap_(&arr[i],&arr[j]);
        }
    }
    swap_(&arr[i+1],&arr[pivot]);
    return i+1;
}

void quick_sort(int low,int high)
{
    if(high > low)
    {
        int pivot = partition_(low,high);
        quick_sort(low,pivot-1);
        quick_sort(pivot+1,high);
    }
}

void print_sorted_array()
{
    for(int i=0; i<n; i++)
    {
        print(arr[i])
    }printf("\n");
}

int main()
{
    read(n)

    for(int i=0; i<n; i++)
    {
        read(arr[i])
    }
    quick_sort(0,n-1);
    print_sorted_array();
}
