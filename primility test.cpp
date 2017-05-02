#include<bits/stdc++.h>
using namespace std;

// calculate (a^n)%p in O(logn)
int power(int a,unsigned int n,int p)
{
    int res =1;
    a = a%p;

    while(n > 0)
    {
        if(n & 1)
        {
            res = (res*a) % p;
        }
        // n must be even now
        n>>=1;
        a = (a*a)%p;
    }
return res;
}

bool isPrime(unsigned int n, int k)
{
    if(n==1 || n==4)
        return false;
    if(n<=3)
        return true;

    while(k>0)
    {
        int a = 2+ rand()%(n-4);

        if(power(a, n-1, n) != 1)
            return false;

        k--;
    }
}

int main()
{
    unsigned int n;
    cin>>n;

    int k=4;
    if(isPrime(n,k))
    {
        cout<<"yes"<<endl;
    }
    else
    {
        cout<<"no"<<endl;
    }
    return 0;
}
