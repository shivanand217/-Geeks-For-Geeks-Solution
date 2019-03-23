// AUTHOR: SHIV ANAND
// LANGUAGE: CPP
// TIME COMPLEXITY :
// SPACE COMPLEXITY :

/** using seive **/

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

void seive(int n)
{
    int count_[n+5];
    memset(count_,0,sizeof(count_));

    count_[0]=1;count_[1]=0;

    for(int i=2; i*i<=n; i++)
    {
        if(!count_[i]){

        for(int j=2*i; j<=n; j+=i)
        {
            count_[j]++;
        }
        }
        count_[i]=1;
    }

    int max_val=INT_MAX,max_count=0;

    for(int i=n; i>=0; i--)
    {
        if(count_[i] >= max_count)
        {
            max_val = i;
            max_count = count_[i];
        }
    }

    cout<<max_count<<endl;
    return 0;

}

int main()
{

}
