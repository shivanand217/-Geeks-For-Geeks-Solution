// AUTHOR: SHIV ANAND
// LANGUAGE: CPP
// TIME COMPLEXITY : O(log(n))
// SPACE COMPLEXITY : O(1)

/** algorithimic paradigm: divide and conquer **/

/**
     find the only one peak element
     An array element is peak if it is NOT smaller than its neighbors.
     For corner elements, we need to consider only one neighbor.
     For example, for input array {5, 10, 20, 15}, 20 is the only peak element.
     For input array {10, 20, 15, 2, 23, 90, 67}, there are two peak elements: 20 and 90.
     Note that we need to return any one peak element.
**/

#include<bits/stdc++.h>
#define si(x) scanf("%d",&x)
#define slli(x) scanf("%lld",&x)
#define sli(x) scanf("%ld",&x)
#define ll long long
#define mod 1000000007
#define pfi(x) printf("%d\n",x)
#define pfli(x) printf("%ld\n",x)
#define pflli(x) printf("%lld\n",x)
#define lli long long int
#define ull unsigned long long int
#define fo_r(i,n) for(int i=0; i<n; i++)
using namespace std;

const int maxn = 103;
int ar[maxn];
int n;

int solve(int lo,int hi)
{
    int mid = lo + (hi-lo)/2;

    //corner case
    if( (mid == 0 && ar[mid+1] <= ar[mid]) || (mid == n-1 && ar[mid-1] <= ar[mid]) )
    {
        return mid;
    }
    else if(mid !=0 && mid!=n-1 && ar[mid-1]<= ar[mid] && ar[mid+1] <= ar[mid])
    {
        return mid;
    }
    else if(mid != 0 && mid!= n-1 && ar[mid-1] > ar[mid])
    {
        solve(lo, mid-1);
    }
    else if(mid != 0 && mid != n-1 && ar[mid+1] > ar[mid])
    {
        solve(mid+1, hi);
    }
}

int main()
{
    si(n);

    for(int i=0; i<n; i++)
    {
        si(ar[i]);
    }

    int index = solve(0, n-1);
    cout<<ar[index]<<endl;


    return 0;
}
