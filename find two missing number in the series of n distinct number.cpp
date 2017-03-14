// AUTHOR: SHIV ANAND
// LANGUAGE: CPP
// TIME: O(n)
// SPACE: O(1)

/** their is a trick we get the rightmost set bit of a number x using [x & ~(x-1)], similarly second rightmost setbit as [x & ~(x-2)] and so on.
    if their is only one bit set then it always give that position as we go for secondmost or thirdmost
    we first do the xor of all the numbers 1 to n with the array elements , then we get the xor of the two missing elements
    then we choose rightmost set bit from that xor ,select that array element which have set bit at that pos by formula xor those with 1 to n
    we get the first number similarly we do the xor of the elements which dont have set bit at that pos xor those with 1 to n we get
    the scond missing element
**/

#include<bits/stdc++.h>
#include<cstdio>
#include<cstdlib>
#define read(val) scanf("%d",&val);
#define print(val) printf("%d ",val);
#define scan(val) scanf("%lld",&val);
#define show(val) printf("%lld ",val);
#define rr(val) for(int i=0; i<val; i++)
#define ret return 0;
#define ll long long
using namespace std;

const int maxn = 105;
int arr[maxn];

void solve(int n) // this n is n-2 2 elements are missing
{
    int xor_=arr[0];

    for(int i=1; i<n-2; i++)
    {
        xor_^= arr[i];
    }

    for(int i=1; i<=n; i++)
    {
        xor_^ =i;
    }

    int set_bit_rightmost = xor_ & ~(xor_-1); // rightmost set bit

    int x,y;

    for(int i=0; i<n-2; i++)
    {
        if(arr[i] & set_bit_rightmost)
        {
            x ^= arr[i];
        }
        else
            y^= arr[i];
    }

    // get the first and second missing element
    for(int i=1; i <= n; i++)
    {
        x ^= i;
        y ^= i;
    }

    cout<<x<<" "<<y<<endl;
}

int main()
{
int n;
read(n)

for(int i=0; i<n-2; i++)
{
    read(arr[i])
}

solve(n);
return 0;
}
