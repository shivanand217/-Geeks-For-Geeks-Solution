// AUTHOR: SHIV ANAND
// LANGUAGE: CPP
// TIME COMPLEXITY : O(n)
// SPACE COMPLEXITY : O(1)

#include<bits/stdc++.h>
#define si(x) scanf("%d",&x)
#define slli(x) scanf("%lld",&x)
#define sli(x) scanf("%ld",&x)
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define ll long long
#define mod 1000000007
#define pfi(x) printf("%d\n",x)
#define pfli(x) printf("%ld\n",x)
#define pflli(x) printf("%lld\n",x)
#define lli long long int
#define ull unsigned long long int
#define fo_r(i,n) for(int i=0; i<n; i++)
using namespace std;

/** solution assumes that element is present in the array otherwise it returns zero **/

int solve(int ar[], int n, int x)
{
    // if last element int x
    if(ar[n-1] == x)
    {
        return (n-1);
    }

    int curr,prev;
    prev = ar[n-1];

    int i;

    for(i = n-2; i>=0 && ar[i]!=x; i--)
    {
        curr = ar[i];
        ar[i] = prev;
        prev = curr;
    }

    // if element is not present
    if(i < 0)
    {
        return 0;
    }

    ar[i] = prev;
    return n-1;
}

int main()
{
    int n;
    si(n);

    int *ar = new int[n];
    for(int i=0; i<n; i++)
    {
        si(ar[i]);
    }

    int x;
    si(x);

    int ans = solve(ar, n, x); // after getting n-1 elements show them
    if(ans != 0)
    {
        for(int i=0; i<ans; i++)
        {
            cout<<ar[i]<<" ";
        }
    }
    return 0;
}
