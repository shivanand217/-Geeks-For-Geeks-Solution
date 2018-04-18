// AUTHOR: SHIV ANAND
// LANGUAGE: CPP

/** XOR based solution **/

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

void swap_three(int &a,int &b,int &c)
{
    // first do xor of all three and store in first
    a = a ^ b ^ c;

    b = a ^ b ^ c; // b is replaced with a

    c = a ^ b ^ c; // c has the value of b

    a = a ^ b ^ c; // a has the value of c

}

int main()
{
    int a,b,c;
    read(a)
    read(b)
    read(c)

    swap_three(a,b,c);

    cout<<a<<" "<<b<<" "<<c<<endl;
    return 0;
}

