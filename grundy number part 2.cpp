// AUTHOR: SHIV ANAND
// LANGUAGE: CPP

/** The game starts with a pile of n stones,
and the player to move may take any positive number of stones upto 3 only. The last player to move wins. Which player wins the game?
This game is 1 pile version of Nim. **/

/** we observe in this is if n=1 should mex{0} poss=1,n=2 mex{0,1}=2,n=3 poss=3, n=4 mex{1,2,3}=0 , similarly reapeat from here **/

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

int main()
{
int n;
cin>>n;

if(n==0)
    {cout<<0<<endl;return 0;}
if(n%4==0)cout<<0<<endl;

if(n%4==1)cout<<1<<endl;

if(n%4==2)cout<<2<<endl;

if(n%4==3)cout<<3<<endl;

return 0;
}
