// AUTHOR: SHIV ANAND
// LANGUAGE: CPP
// TIME COMPLEXITY : O(n)
// SPACE COMPLEXITY : O(sum_of_frequencies)

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

const int maxn = 105;
int ar[maxn];

map<int,int> mapp;

int main()
{
int n;
read(n)

for(int i=1; i<=n; i++)
{
    read(ar[i])
    mapp[ar[i]]++;
}

int low=1;int high = n;

bool ans=false;

for(int i=1; i<=n; i++)
{
int val_1 = n-i;
int val_2 = i-1;

if(mapp[val_1] && mapp[val_2])
{
    if(mapp[val_1] > mapp[val_2])
    {
        mapp[val_1]--;
    }
    else
    {
        mapp[val_2]--;
    }
}
else if(mapp[val_1] && !mapp[val_2])
{
     mapp[val_1]--;
}
else if(!mapp[val_1] && mapp[val_2])
{
    mapp[val_2]--;
}
else
{
    ans=true;break;
}

}

if(ans == true)
{
    cout<<"no"<<endl;
}
else
{
    cout<<"yes"<<endl;
}

return 0;
}
