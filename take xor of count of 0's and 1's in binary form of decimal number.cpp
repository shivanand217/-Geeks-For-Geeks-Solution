// AUTHOR: SHIV ANAND
// LANGUAGE: CPP

/** in this problem like for example our binary value is 1010 (10) so we keep on right shifting the digit unless we get 0
    and at every stage we check for that value is even or odd ,for even their is 0 at least significant place and for odd
    their should be 1 at least significant place **/

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

int xor_value_of_countof0_countof1(int n)
{
    int cnt_1=0;
    int cnt_0=0;

    while(n>0)
    {
        if(n&1)
        {
            cnt_1++;
            n>>=1;
        }
        else
        {
            cnt_0++;
            n>>=1;
        }
    }

    return (cnt_1^cnt_0);
}

int main()
{
    int n;
    cin>>n;

    int xor_count = xor_value_of_countof0_countof1(n);

    cout<<xor_count<<endl;
    return 0;
}

