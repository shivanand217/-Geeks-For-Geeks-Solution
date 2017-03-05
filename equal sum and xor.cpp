// AUTHOR: SHIV ANAND
// LANGUAGE: CPP

/** question is Given a positive integer n, find count of positive integers i such that 0 <= i <= n and n+i = n^i
/** idea is simple if both has 1 at same position the answer should be no otherwise answer is yes **/

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

int solve(int n)
{
    int tmp,tmp2;

    int ans =0 ;
    bool yes;

    for(int i=0; i<=n; i++)
    {
        yes = false;
        tmp = n;
        tmp2 = i;

        while(tmp > 0)
        {
            if( (tmp & 1) && (tmp2 & 1))
            {
               yes = true;break;
            }
            tmp >>=1;
            tmp2 >>=1;
        }

        if(yes == false)
        {
            ans++;
        }
    }

    cout<<ans<<endl;
}

int main()
{

int n;
cin>>n;

solve(n);
return 0;
}
