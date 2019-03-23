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
#define LL long long
#define mod 1000000007
#define ui unsigned int
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

void swap_(ui *a,ui *b)
{

// we maintain a case when both the pointer are equal as to avoid the below case
/**
// Bitwise XOR based method
x = x ^ x; // x becomes 0
x = x ^ x; // x remains 0
x = x ^ x; // x remains 0

// Arithmetic based method
x = x + x; // x becomes 2x
x = x – x; // x becomes 0
x = x – x; // x remains 0*/

if(*a == *b)return;

*a = *a^*b;
*b = *b^*a;
*a = *a^*b;

}

int main(){

ui a,b;
cin>>a>>b;

swap_(&a,&b);

cout<<a<<" "<<b<<endl;return 0;
}
