// AUTHOR: SHIV ANAND
// LANGUAGE: CPP
// TIME COMPLEXITY : O(n)
// SPACE COMPLEXITY : O(1)

/** if 2*k not divides n evenly then not possible to build the required permutation **/

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

int n,k;
const int maxn = 105;
int ar[maxn];

int main()
{
read(n)
read(k)

for(int i=0; i<n; i++)
{
    read(ar[i])
}

if(n%(2*k) != 0)
{
    cout<<"not possible"<<endl;
}
else
{
    int s,tmp;
    for(int i=0; i<n-k; )
    {
        s=i;
        tmp=i+k;

        while(i < (s+k))
        {
            swap(ar[i], ar[tmp]);
            i++;tmp++;
        }
        i=tmp;
    }
}

// print the required permutation
for(int i=0; i<n; i++)
{
    cout<<ar[i]<<" ";
}

return 0;
}
