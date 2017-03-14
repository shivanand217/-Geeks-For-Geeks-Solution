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

int solve_for_longest_consequetive_one(int n)
{
    int on=0;

    int longest = 0;
    int cnt=0;

    while(n > 0)
    {
        if(n&1)
        {
            if(on)
            {
                cnt++;
                if(cnt > longest)
                    longest = cnt;
            }
            else
            {
                on=1;
                cnt++;
            }
        }
        else
        {
            on = 0;
            cnt=0;
        }
        n>>=1;
    }

return longest;
}


int main()
{

int query;
read(query)

int n;

for(int i=0; i<query; i++)
{
    read(n)
    int ans = solve_for_longest_consequetive_one(n);
    cout<<ans<<endl;
}
return 0;

}
