// AUTHOR: SHIV ANAND
// LANGUAGE: CPP
// COMPLEXITY: O(nlogn +logn) // nlogn for sorting logn for binary search

/**
Input : arr[] = {2, 1, 10, 8, 10, 12, 19}, x = 5
Output : 2
2 is the largest element in arr[] smaller than 5.

Input : arr[] = {2, 1, 10, 8, 10, 12, 19}, x = 20
Output : 19
19 is the largest element in arr[] smaller than 20.

Input : arr[] = {1, 2, 8, 10, 10, 12, 19}, x = 0
Output : -1
Since floor doesn't exist, output is -1.
**/

#include<bits/stdc++.h>
#define read(val) scanf("%d",&val)
#define print(val) printf("%d",val)
#define scan(val) scanf("%lld",&val)
#define show(val) printf("%lld",val)
#define ll long long
using namespace std;

const int maxn = 1e5+2;

ll arr[maxn];
int n;


int ans_search(int low,int high,int x)
{
    //base case
    if(low > high)
        return -1;

    if(x >= arr[high])
    {
        return high;
    }

    int mid=(low+high)/2;

    // mid is the value
    if(arr[mid] == x)
        return mid;

    // if lies between mid-1 ans mid
    if(mid > 0 && arr[mid-1] <=x && arr[mid] >x)
        return mid-1;

    if(x < arr[mid]) //recur for left subarray
         return ans_search(low,mid-1,x);
    else
        return ans_search(mid+1,high,x);
}

int main()
{
read(n);

for(int i=0; i<n ;i++)
{
    scan(arr[i]);
}

ll x;
scan(x);

sort(arr,arr+n);
int ans = ans_search(0,n-1,x);

show(arr[ans]);

return 0;

}
