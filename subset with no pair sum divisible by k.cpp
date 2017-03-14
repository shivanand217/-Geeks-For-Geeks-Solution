// AUTHOR: SHIV ANAND
// LANGUAGE: CPP
// TIME COMPLEXITY : O(n)
// SPACE COMPLEXITY : O(k)

/** we store the remainder upto k
   // we have to handle the special case of 0 and k/2
    // we dont include these remainder more than 1 in our subset
**/

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
int n,k;

int main()
{
    //int n;
    read(n)
    read(k)

    for(int i=0; i<n; i++)
        cin>>ar[i];
    //
    int count_remainder[k];
    memset(count_remainder,0,sizeof(count_remainder));

    for(int i=0; i<n; i++)
    {
        int p=ar[i]%k;
        count_remainder[p]++;
    }

    // for zero remainder
    count_remainder[0]=min(count_remainder[0],1);
    if(k%2==0)
    count_remainder[k/2]=min(count_remainder[k/2],1);

    int ans=count_remainder[0];


    // we have to form maximum subset
    for(int i=1; i<=k/2; i++)
    {
        ans += max(count_remainder[i],count_remainder[k-i]);
    }

    cout<<ans<<endl;

    return 0;
}
