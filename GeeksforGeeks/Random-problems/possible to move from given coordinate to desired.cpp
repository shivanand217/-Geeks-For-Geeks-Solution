// AUTHOR: SHIV ANAND
// LANGUAGE: CPP

/** check if possible to move from one coordinate to other with the possible moves
    (i-j, j)
    (i, i-j)
    (i+j, j)
    (i, i+j) **/

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
#define io_file freopen("D:/Coding Problems/Contest/input_file.in", "r", stdin);freopen("D:/Coding Problems/Contest/output_file.out", "w", stdout)

int fast_pow(int x,int n)
{
    int result=1;
    while(n>0)
    {
        if(n % 2 ==1)
            result=(result * x)%mod;
        x=(x*x)%mod;
        n=n/2;
    }
    return result;
}

int gcd(int a,int b)
{
    if(a==0)
        return b;
    return gcd(b%a, a);
}

int lcm(int a,int b)
{
    int ans;
    ans = (a*b)/gcd(a,b);
    return ans;
}

int main()
{
int x1,y1,x2,y2;
read(x1)read(y1)
read(x2)
read(y2)

// if gcd of first cordinate is equal to the second then yes otherwise no

if(gcd(x1,y1) == gcd(x2,y2))
{
    cout<<"yes"<<endl;
}
else
{
    cout<<"no"<<endl;
}

return 0;

}
