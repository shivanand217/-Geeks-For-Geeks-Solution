// AUTHOR: SHIV ANAND
// LANGUAGE: CPP

/** Given a positive integer n, count numbers x such that 0 < x <n and x^n > n where ^ is bitwise XOR operation. **/

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
#define mod 1000000007
using namespace std;

ll fast_(ll a, ll b) {
    ll x = 1, y = a;
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

int count_numbers(int n)
{
    int k=0;
    int cnt=0;

    while(n>0)
    {
        // we count for all the 0 bits if the bit is zero then all the number with 1 at that pos will give the answer
        if((n&1) == 0)
        {
            cnt+=fast_(2,k);
        }

        k++;
        n>>=1;
    }
    return cnt;
}

int main()
{
int n;
cin>>n;

int ans=count_numbers(n);

cout<<ans<<endl;
return 0;
}
