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

/** Let p1 and p2 be the two given positions.

Example 1
Input:
x = 47 (00101111)
p1 = 1 (Start from second bit from right side)
p2 = 5 (Start from 6th bit from right side)
n = 3 (No of bits to be swapped)
Output:
227 (11100011)
The 3 bits starting from the second bit (from right side) are
swapped with 3 bits starting from 6th position (from right side)

*/

/** now in our solution we do following steps
    1.move all bits of the first set to rightmost side
    2.move all bits of the second set to rightmost side
    3.take xor of first and second set
    4.put the xor value back to its original position
    5.result is the xor of original number and the obtained xor
    */

unsigned int swap_bits_of_number(unsigned int a,unsigned int num_bits,unsigned int start_1,unsigned int start_2)
{
    ui set1 = (a>>start1)&((1U<<num_bits)-1);
    ui set2 = (a>>start2)&((1U<<num_bits)-1);

    ui xor_ = set1^set2;
    xor_ = (xor_<<start1)|(xor_<<start2);
    ui result = a^xor_;
    return result;
}

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

ui a,start1,start2,x;
cin>>a>>start1>>start2>>x;

ui result=swap_bits_of_number(a,x,start1,start2);
cout<<result<<endl;return 0;

}
