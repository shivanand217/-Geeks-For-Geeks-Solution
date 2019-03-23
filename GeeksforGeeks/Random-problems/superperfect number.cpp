// AUTHOR: SHIV ANAND
// LANGUAGE: CPP
// Time: O(sqrt(n) + sqrt(σ(n)))

/** Given an integer n.
    Check whether the number n is superperfect number or not.
    A superperfect number is a positive integer which satisfies pow(σ(n),2) = σ(σ(n)) = 2n,
    where σ is divisor summatory function.

    eg: Input: n = 16
        Output: yes
        Explanation:
        16 is a superperfect number as σ(16) = 1 + 2 + 4 + 8 + 16 = 31,
        and σ(31) = 1 + 31 = 32,
        thus σ(σ(16)) = 32 = 2 × 16. **/

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

bool super_perfect(int n)
{
int sum =0;
int f,s;

for(int i=1; i<=sqrt(n); i++)
{
    if(n % i == 0)
    {
        if((n/i) == i)
        {
            f = n/i;
            sum += f;
        }
        else
        {
            f = n/i;
            s = i;

            sum+=f;
            sum+=s;
        }
    }
}

// calculate sigma of the obtained sum

int sum2 = 0;
for(int i =1; i<=sqrt(sum); i++)
{
    if(sum % i == 0)
    {
        if((sum/i) == i)
        {
            f = n/i;
            sum2 += f;
        }
        else
        {
            f = sum/i;
            s = i;
            //cout<<f<<" "<<s<<endl;

            sum2+=f;
            sum2+=s;
        }
    }
}
cout<<sum<<endl;
cout<<sum2<<endl;

// if that obtained sum is twice of original number then this is a superperfect number

if(2*n == sum2)
{
    return true;
}
else
{
    return false;
}

}

int main()
{
int n;
cin>>n;

if(super_perfect(n))
{
    cout<<"yes"<<endl;
}
else
{
    cout<<"no"<<endl;
}

return 0;

}
