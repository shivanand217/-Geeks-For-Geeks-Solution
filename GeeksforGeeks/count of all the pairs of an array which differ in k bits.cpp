// AUTHOR: SHIV ANAND
// LANGUAGE: CPP
// TIME COMPLEXITY : O(Max*Max) // Max is the maximum element present in the array
// SPACE COMPLEXITY : O(Max)

/** we can precompute the number of setbit in the numbers from 0 to maxi(maximum number present in the array) **/

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
int n;

int main()
{
int k;

read(n)read(k)
int maxi=INT_MIN;

for(int i=0; i<n; i++)
{
    read(ar[i])
    if(maxi< ar[i])maxi=ar[i];
}

long long count_[maxi+1];
memset(count_,0,sizeof(maxi));

for(int i=0; i<n; i++)
{
    count_[ar[i]]++;
}

long long ans=0;
// if k is zero // remember pair(i,j) are different

if(k==0)
{
    // then every count have its own count pair
    for(int i=0; i<=maxi; i++)
    {
        ans+=(count_[i]*(count_[i]-1))/2;
    }
}
else
{
    for(int i=0; i<maxi; i++)
    {
        for(int j=i+1; j<=maxi; j++)
        {
            if(count_[i]!=0){
            int p=(i^j);
            if(set_count(p) == k)
            {
                ans+=count_[i]*count_[j];
            }}
        }
    }
}

cout<<ans<<endl;
return 0;

}
