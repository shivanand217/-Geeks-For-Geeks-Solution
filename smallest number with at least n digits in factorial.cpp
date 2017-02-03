// AUTHOR: SHIV ANAND
// LANGUAGE: CPP
// COMPLEXITY: O(log(2*n)) or O(log n)


/** important observation:

if we choose a number n then we observe that their is always a number k in 0 to 2*n such that k! has at least n digits
hence 0<=k<=2*n (we have to find smallest k)
we are doing binary search in 0 to 2*n for that

**/

#include<bits/stdc++.h>
using namespace std;

#define M_E 2.71828
const double M_PI = 3.14159265358979323846;

int find_digits(int n)
{
    if(n<0) //negative numbers
        return 0;

    if(n == 0 || n==1)
        return 1;

    double x = n*log10(n/M_E) + log10(2*M_PI*n)/2.0;

    return floor(x)+1;
}

int b_search(int n)
{
    int low=0;
    int high=2*n;

    if(n<=0)
        return -1;

    if(find_digits(low) == n)
        return low;

    int mid;

    while(low<=high)
    {
        mid = (low+high)/2;

        if(find_digits(mid-1) < n && find_digits(mid) >=n) // then mid is the answer
            return mid;

        if(find_digits(mid) < n)
            low=mid+1;
        else
            high=mid-1;
    }
    return low;
}

int main()
{
int n;
scanf("%d",&n);

int ans=b_search(n);

printf("%d\n",ans);

return 0;

}
