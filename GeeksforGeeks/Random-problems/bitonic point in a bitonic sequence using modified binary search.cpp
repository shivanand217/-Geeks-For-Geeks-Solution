// AUTHOR : SHIV ANAND

// BITONIC SEQUENCE IS A SEQUENCE IN WHICH FIRST ELEMENTS ARE STRICTLY INCREASING THEN STRICTLY DECREASING
// BITONIC POINT IS THE POINT WHERE ITS LEFT IS SMALLER AND ITS RIGHT IS ALSO SMALLER

#include<bits/stdc++.h>
#define read(val) scanf("%d",&val)
using namespace std;


// using binary search
int mid;

int bitonic_point(int low,int high,int arr[],int n)
{

mid = (low+high)/2;

while(low <= high)
{
    if(low == high)
    {
        return low;
    }

    if(arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1])
        break;
    else if(arr[mid] < arr[mid+1])
        bitonic_point(mid+1,high,arr,n); // search for right part
    else
        bitonic_point(low,mid-1,arr,n);
}

return mid;

}

int main()
{
    int n;
    read(n);

    int arr[n];

    for(int i=0; i<n; i++)
    {
        read(arr[i]);
    }

int point = bitonic_point(0,n-1,arr,n);
printf("%d",point);

return 0;
}
