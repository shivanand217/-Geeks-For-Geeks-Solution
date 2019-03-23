// AUTHOR: SHIV ANAND
// LANGUAGE: CPP

/** only works when the divisor is the power of 2
    in this we can divide the decrement the modulus and take the & with the number to obtain the remainder
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
#define mod 1000000007
using namespace std;

LL pow(LL a, LL b) {
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
    LL lcm_value=((a*b)%mod)/(gcd_(a,b));
}

int main(){
int  n,k;
cin>>n>>k; // k should be of power of 2

int rem = n&(k-1);

cout<<rem<<endl;return 0;

}
