// AUTHOR: SHIV ANAND
// LANGUAGE: CPP

#include<bits/stdc++.h>
#include<cstdio>
#include<cstdlib>
#define read(val) scanf("%d",&val);
#define print(val) printf("%d ",val);
#define scan(val) scanf("%lld",&val);
#define show(val) printf("%lld ",val);
#define rr(val) for(int i=0; i<val; i++)
#define ret return 0;
#define LL long long
#define mod 1000000007
using namespace std;

LL pow(LL a, LL b, LL mod) {
    LL x = 1, y = a;
    while(b > 0) {
        if(b%2 == 1) {
            x=(x*y);
            if(x>mod) x%=mod;
        }
        y = (y*y);
        if(y>mod) y%=mod;
        b /= 2;
    }
    return x;
}

LL gcd_(LL a,LL b)
{
    if(b==0)
        return a;
    return (b,a%b);
}

LL lcm_(LL a,LL b)
{
    LL lcm_value=(a*b)%mod/(gcd_(a,b));
}

bool check_for_solution(int arr[],int prime[],int n,int m)
{
    // first we calculate lcm of all the array elements
    int lcm_value=arr[0];

    for(int i=1; i<n; i++)
    {
        lcm_value=lcm_(lcm_value,arr[i]);
    }

    // now one by one we divide it by each the array elements and remove all the factors of the given primes from it
    for(int i=0; i<n; i++)
    {
        lcm_value = lcm_value/arr[i];

        for(int j=0; j<m && lcm_value!=1; j++)
        {
            if(lcm_value % prime[j] == 0)
            {
                lcm_value/=prime[j];
            }
        }
    }

    if(lcm_value!=1)
    {
        return false;
    }
    return true;
}

int main()
{
    int n,m;
    read(n)read(m)

    int *arr = new int[n];
    int *prime= new int[m];

    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    for(int j=0; j<m; j++)
    {
        cin>>prime[j];
    }

    check_for_solution(arr,prime,n,m);
    return 0;
}
