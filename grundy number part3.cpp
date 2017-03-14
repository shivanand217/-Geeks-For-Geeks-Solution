// AUTHOR: SHIV ANAND
// LANGUAGE: CPP

/** Suppose we change the classic Nim game a bit.
This time each player can only remove 1, 2 or 3 stones only (and not any number of stones as in the classic game of Nim).
Can we predict who will win? **/

/** we can solve this nim of n piles using grundy numbers concept , first we can calculate the grundy value of each of the piles then
   we take the xor of all the values if its A's chance and the xor sum is non zero then A wins and vice versa **/

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

int piles[50];
int n;

int chance;

int main()
{
    cin>>n; // no. of piles

cin>>chance;
    // pile size of each of the piles
    for(int i=0; i<n; i++)
    {
        cin>>piles[i];
    }

    int xor_= piles[0];

    for(int i=1; i<n; i++)
    {
        if(piles[i] % 4 == 0)
            xor_ = xor_^0;
        else if(piles[i] % 4 ==1)
            xor_ = xor_^1;
        else if(piles[i] % 4 ==2)
            xor_ = xor_^2;
        else if(piles[i] % 4 ==3)
            xor_ = xor_^3;
    }
     // 1 for A chance and 0 for B's
    if(chance == 1)
    {
        if(xor_ == 0)
        {
            cout<<"B wins"<<endl;
        }
        else
        {
            cout<<"A wins"<<endl;
        }
    }
    else
    {
        if(xor_ == 0)
        {
            cout<<"A wins"<<endl;
        }
        else
            cout<<"B wins"<<endl;
    }
    return 0;
}
