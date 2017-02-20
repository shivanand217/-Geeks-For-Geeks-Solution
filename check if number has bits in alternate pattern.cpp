// AUTHOR: SHIV ANAND
// LANGUAGE: CPP

/** Print “Yes” if it has an alternate pattern otherwise “No”. Here alternate pattern can be like 0101 or 1010. **/

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

int num;

bool solve(int n)
{

bool alt=true;
int last;
int i=0;

while(n > 0)
{
    if(i!=0)
    {
        if(n&1)
        {
            if(last == 1)
                {alt = false;break;}
            last=1;
        }
        else
        {
            if(last == 0)
            {
                alt = false;break;
            }
            last=0;
        }
    }
    if(i==0)
    {
        if(n&1)
            last=1;
        else
            last=0;
    }
    i++;
    n>>=1;
}

if(alt == true)
    return true;
else
    return false;
}

int main()
{

int query;
cin>>query;

for(int i=0; i<query; i++)
{
    cin>>num;

    if(solve(num))
    {
        cout<<"yes"<<endl;
    }
    else
    {
        cout<<"no"<<endl;
    }
}

return 0;
}
