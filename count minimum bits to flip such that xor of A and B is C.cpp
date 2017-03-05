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
#define ret return 0;
#define ll long long
using namespace std;

// always use parantheses when computing bitwise operations

int count_minimum_bits_to_flip(int A,int B,int C)
{
    int cnt=0;
    while(1)
    {
        if(A==0&&B==0&&C==0)break;
        // if both A and B have same bit at the last but C have 1 (bacause xor of same is zero we have to flip one of those bit in A or B)
        if( ((A&1)==1 && (B&1)==1) || ((A&1)==0 && (B&1)== 0) )
        {
            //cout<<"same"<<endl;
            if((C&1) == 1)
            {
                cnt++;
            }
        }
        // if both A and B have different bit at last and C have 0 at the last
        if( ((A&1)==1 && (B&1) == 0) || ((A&1)==0 && (B&1)==1) )
        {
            //cout<<"diff"<<endl;
            if((C&1) == 0 )
            {
                cnt++;
            }
        }

        A>>=1;
        B>>=1;
        C>>=1;
    }
    return cnt;
}

int main()
{

int A,B,C;
scanf("%d%d%d",&A,&B,&C);

int ans=count_minimum_bits_to_flip(A,B,C);

cout<<ans<<endl;
return 0;

}
