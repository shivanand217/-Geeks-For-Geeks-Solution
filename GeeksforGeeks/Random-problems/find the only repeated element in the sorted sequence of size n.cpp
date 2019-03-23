// AUTHOR: SHIV ANAND
// LANGUAGE: CPP
// COMPLEXITY: O(logn) //using binary search

/**
Input :  arr[] = { 1, 2 , 3 , 4 , 4}
Output :  4

Input :  arr[] = { 1 , 1 , 2 , 3 , 4}
Output :  1
**/

#include<bits/stdc++.h>
#define read(val) scanf("%d",&val)
#define print(val) printf("%d",val)
#define ll long long
using namespace std;

const int maxn = 1e5+2;
ll arr[maxn];

int n;

ll solve()
{
    int low=0;
    int high=n-1;

    int mid;

    while(low <= high)
    {
       mid=(low+high)/2;


       if(arr[mid] == mid+1)
       {
         // then recur for the right subarray
         low=mid+1;
       }
       else
       {
           high=mid-1;
       }
    }

    return arr[low];
}

int main()
{
    //int n;
    read(n);

    for(int i=0; i<n; i++)
    {
        scanf("%lld",&arr[i]);
    }

    ll ans =solve();

    printf("%lld\n",ans);
    return 0;
}
