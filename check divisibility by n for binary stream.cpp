// AUTHOR: SHIV ANAND
// LANGUAGE: CPP
// TIME COMPLEXITY: O(input)

/** we are checking for input binary stream is divisible by n or not
    every time we check for the remainder
    for a number m written as n=am+r , r is the remainder
    if we multiply it by x  nx = amx+rx
    checking for divisibility (nx)%m = (amx)%m + (rx)%m
    hence (amx)%m = 0 so it depends on (rx)%m
    we check for remainder
    if stream is 0 then remainder will be 2*r
    if stream is 1 then remainder will be 2*r+1
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

int remainder;

bool is_divisible(int n,int bit)
{

if(bit == 0)
{
    remainder = (remainder * 2) % n;
}
else
{
    remainder = (remainder*2+1) % n;
}
}

int main()
{
    int bit;

    remainder = 0;
    int n;
    cin>>n;

    while(true)
    {
        cin>>bit;

        if(bit!=0 || bit!=1)break;
        is_divisible(n,bit);
    }

    if(remainder == 0)
        cout<<"yes"<<endl;
    else
        cout<<"no"<<endl;
        return 0;

}
