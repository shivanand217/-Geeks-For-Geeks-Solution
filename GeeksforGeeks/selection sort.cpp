// AUTHOR: SHIV ANAND
// LANGUAGE: CPP
// TIME COMPLEXITY: O(n*n)
// SPACE COMPLEXITY: O(1)

/**
each time in this selection sort we choose the minimum element from the unsorted array and place it to the first position **/

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

void selection_sort()
{
    int minn=INT_MAX;
    int minn_index;

    for(int i=0; i<n; i++)
    {
        if(minn > arr[i])
            {minn=arr[i];
            minn_index=i;}
    }
    swap_(&arr[0],&arr[minn_index]);

    for(int i=1; i<n-1; i++)
    {
        minn = INT_MAX;
        minn_index=i;

        for(int j=i; j<n; j++)
        {
            if(arr[j] < minn)
                {minn = arr[j];
                minn_index = j;}
        }
        swap_(&arr[i],&arr[minn_index]);
    }
}

void print_sorted_array()
{
for(int i=0; i<n; i++)
{
    print(arr[i])
}
}

int main()
{
    read(n);

    for(int i=0; i<n; i++)
    {
        read(arr[i]);
    }

    selection_sort();
    print_sorted_array();

    return 0;
}
