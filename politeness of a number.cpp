// AUTHOR: SHIV ANAND
// LANGUAGE: CPP
// TIME COMPLEXITY : O(sqrt(n))
// SPACE COMPLEXITY : O(1)

#include<bits/stdc++.h>
#include<cstdio>
#include<cstdlib>
#define read(val) scanf("%d",&val);
#define print(val) printf("%d ",val);
#define scan(val) scanf("%lld",&val);
#define show(val) printf("%lld ",val);
#define rr(val) for(int i=0; i<val; i++)
#define LL long long
#define mod 1000000007
using namespace std;

int count_odd_divisor(int n)
{
    // first remove all the factors of 2
    while(n % 2 == 0)
    {
        n/=2;
    }

    // now count all the odd divisor
    int odd_count;
    int result=1;

    for(int i=3; i*i<=n; i+=2)
    {
        odd_count = 0;

        if(n % i == 0)
        {
            while(n % i == 0)
            {
                n/=i;
                odd_count++;
            }
        }

        result *= (odd_count +1);
    }

    // if still remains factors of odd prime
    if(n > 2)
    result *= 2;

    return result;
}

int find_politeness(int n)
{
    return (count_odd_divisor(n)-1);
}

int main()
{
    int n;
    read(n);

    int ans = find_politeness(n);

    print(ans);
    return 0;
}
