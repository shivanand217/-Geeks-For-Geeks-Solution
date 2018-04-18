// AUTHOR: SHIV ANAND
// LANGUAGE: CPP
// TIME COMPLEXITY : O(log(n))
// SPACE COMPLEXITY : O(1)

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
#define un unsigned
using namespace std;

/**

Given a function ‘int f(unsigned int x)’ which takes a non-negative integer ‘x’ as input and returns an integer as output.
The function is monotonically increasing with respect to value of x,
i.e., the value of f(x+1) is greater than f(x) for every input x.
Find the value ‘n’ where f() becomes positive for the first time.
Since f() is monotonically increasing, values of f(n+1), f(n+2),… must be positive and values of f(n-2), f(n-3), .. must be negative.
Find n in O(logn) time, you may assume that f(x) can be evaluated in O(1) time for any input x.

**/

int f(unsigned int x)
{
    return (x*x - 10*x -20);
}

int binary_search_(int lo,int hi)
{
    if(hi >= lo)
    {
        int mid = lo + (hi-lo)/2;

        if(f(mid) > 0 && (mid == lo || f(mid-1) <= 0))
           return mid;

        // if f(mid) is smaller than 0 then go to right side
        if(f(mid) <= 0)
            return binary_search_(mid+1, hi);
        else
            return binary_search_(lo, mid-1);
    }

    // if there is no positive value
    return 0;
}

int find_first_positive()
{
    if(f(0) > 0)
    {
        return 0;
    }

    int i=1;

    while(f(i) <= 0)
    {
        i*=2;
    }

    // now f(i) is positive
    return binary_search_(i/2, i);
}


int main()
{
    int ans = find_first_positive();
    cout<<ans<<endl;
    return 0;
}
