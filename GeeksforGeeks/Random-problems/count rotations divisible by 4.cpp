// AUTHOR: SHIV ANAND
// LANGUAGE: CPP

/** in this question we have to count the given numbers rotations on which it is divisible by 4 **/
/** so we can do that we check for all the adjacent pairs and of course the last pair of the last and the first digit **/

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
using namespace std;

void solve(string s)
{
    int cnt = 0,t;

    // base case for single digit
    if(s.length() == 1)
    {
        if((s[0] - '0') % 4  == 0)
        {
            cnt++;
        }
    }

else{

    for(int i=0; i<s.length()-1; i++)
    {
        t = (s[i]-'0')*10 + (s[i+1]-'0');

        if(t % 4 == 0)
        {
            cnt++;
        }
    }
}
    // check for the pair last and first

    t = s[s.length()-1]-'0'*10 + (s[0]-'0');

    if(t % 4 == 0)
    {
        cnt++;
    }

    // print the total counts of digits
    cout<<cnt<<endl;
}

int main()
{
    string s;
    cin>>s;

solve(s);
return 0;

}
