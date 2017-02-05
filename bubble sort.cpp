// AUTHOR: SHIV ANAND
// LANGUAGE: CPP
// TIME COMPLEXITY: O(n*n)
// SPACE COMPLEXITY: O(1)

/** simplest sorting algorithm in which we compare adjacent elements in n-1 passes untill the array is sorted **/

#include<bits/stdc++.h>
#define read(val) scanf("%d",&val);
#define print(val) printf("%d ",val);
#define scan(val) scanf("%lld",&val);
#define show(val) printf("%lld ",val);
#define ll long long
using namespace std;

const int maxn = 1e5+2;

int arr[maxn];
int n;

void swap_(int *x,int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}

void bubble_sort()
{
for(int i=0; i < n-1; i++)
{
    for(int j=0; j<n-1; j++)
    {
        if(arr[j] > arr[j+1])
            swap_(&arr[j],&arr[j+1]);
    }
}

}

void print_sorted_array()
{
    for(int i=0; i<n; i++)
    {
        print(arr[i]);
    }
}

int main()
{
    read(n)

    for(int i=0; i<n; i++)
    {
        read(arr[i])
    }

    bubble_sort();
    print_sorted_array();

    return 0;
}
