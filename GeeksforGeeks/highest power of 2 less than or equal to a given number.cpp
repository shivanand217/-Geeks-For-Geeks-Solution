// AUTHOR: SHIV ANAND
// LANGUAGE: CPP

/** if the number is not a power of two print th required and otherwise print the number itself **/

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
    int cnt_one=0;
    int i=0;
    int last_index;

    int tmp=n;

    while(n > 0)
    {
        if(n&1)
        {
            last_index=i;
            cnt_one++;
        }
        i++;
        n>>=1;
    }

    int k;
    if(cnt_one == 1)
    {
        return tmp;
    }
    else
    {
        k = 1<<last_index;
        return k;
    }
}

int main()
{
    int n;
int query;
read(query)

int ans;

for(int i=0; i<query; i++)
{
    cin>>n;
    ans = solve(n);
    cout<<ans<<endl;
}

return 0;

}
