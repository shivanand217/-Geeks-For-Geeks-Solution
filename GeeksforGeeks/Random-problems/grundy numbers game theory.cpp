// AUTHOR: SHIV ANAND
// LANGUAGE: CPP

/** The game starts with a pile of n stones, and the player to move may take any positive number of stones.
Calculate the Grundy Numbers for this game. The last player to move wins.
Which player wins the game? **/

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
// thsi is pretty simple
// we can observe that every time a person chooses a number to remove it it can leave the opponent with some possiblity
// if n is 0 then first person lose,if n is 1 possibility will be 0 or mex(0), for n=2 mex=(0,1)=2 so poss=2...... for n=m poss=m **/

int n;
cin>>n;

cout<<n<<endl;

}
