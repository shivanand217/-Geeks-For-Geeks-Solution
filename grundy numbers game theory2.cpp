// AUTHOR: SHIV ANAND
// LANGUAGE: CPP

/** if asked that The game starts with a number- ‘n’ and the player to move divides the number- ‘n’ with 2, 3 or 6 and then takes the floor.
If the integer becomes 0, it is removed. The last player to move wins.
Which player wins the game? **/

/** there is a clear observation in these type is for n=0 poss=0,for n=1 mex{0}=1, for n=2 mex{0,1}=2, n=3 mex{0,1}=2, n=4 mex{0,1,2}=3,n=5 mex{0,1,2}=3
  n=6 mex{1,2,3}=0, rest for all the values the answer will be 0 **/

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
        cout<<0<<endl;
    else if(n==1)
        cout<<1<<endl;
    else if(n==2)
            cout<<2<<endl;
    else if(n==3)
        cout<<2<<endl;
    else if(n==4 || n==5)
        cout<<3<<endl;
    else
        cout<<0<<endl;
return 0;
}

