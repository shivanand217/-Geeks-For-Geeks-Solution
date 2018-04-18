// AUTHOR: SHIV ANAND
// LANGUAGE: CPP
// COMPLEXITY:O(Nlog(N) + Qlog(N))

#include<bits/stdc++.h>
#define read(val) scanf("%d",&val)
#define print(val) printf("%d\n",val)
using namespace std;

int solve(int type,int number,int arr[],int p)
{
int low=0,high=p-1;
int mid;

//mid=(low+high)/2;

while(low<=high)
{
    mid=(low+high)/2;

if(type == 0)
{
    if(arr[mid] < number)
        low = mid+1;
    else
        high = mid-1;
}

if(type == 1)
{
    if(arr[mid] <= number)
    {
        low= mid+1;
    }
    else
    high = mid-1;
}

}
return low;
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

    sort(arr,arr+n);

    int query;
    read(query);

    int type,number;

    while(query--)
    {
        read(type);
        read(number);

       int ans = solve(type,number,arr,n);

       print(n-ans);
    }
return 0;

}
