// AUTHOR: SHIV ANAND
// LANGUAGE: CPP

/** if palindrome then first and second part should be equal then
    we can derive a formula that we see from example
    k = 8 , n=45,
    we have to find the 45th palindrome of k digits
    then suppose first number of 8 digits is 10000000 then we partition it into two half
    1000 and 0000 in the first half we say numbers are
    1000
    1001
    1002.....1099....
    so we say if k is odd then the nth palindrome will be
    num = (n-1)+pow(10,k/2)
    else if k is even
    num = (n-1)+pow(10,k/2-1)

now for complete palindrome we just reverse the first part of the digit and print it
**/

#include<bits/stdc++.h>
#include<cstdio>
#include<cstdlib>
#define read(val) scanf("%d",&val);
#define print(val) printf("%d ",val);
#define scan(val) scanf("%lld",&val);
#define show(val) printf("%lld ",val);
#define rr(val) for(int i=0; i<val; i++)
#define LL long long
#define MOD 1000000007
using namespace std;

int fast_pow(int base,int exponent)
{
    if (exponent == 0)
        return 1;
    if (exponent == 1)
        return base;

    int temp = fast_pow(base, exponent/2);

    if (exponent %2 ==0)
        return (temp%MOD * temp%MOD) % MOD;
    else
        return ((( temp%MOD * temp%MOD)%MOD) * base%MOD) % MOD;
}

int main()
{
    int n,k;
    read(n)
    read(k)

    int num;

    if(k % 2 == 0)
    {
        num = (n-1) + fast_pow(10,(k/2)-1);
    }
    else
    {
        num = (n-1) + fast_pow(10,(k/2));
    }

    //we reverse_ the number
    string p = "";

    int tmp = num;

    while(tmp > 0)
    {
        k = tmp%10;
        p += (k+'0');
        tmp/=10;
    }
    cout << num<<p<<endl;

return 0;
}
