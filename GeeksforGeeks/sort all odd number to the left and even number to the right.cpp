// AUTHOR: SHIV ANAND
// LANGUAGE: CPP
// TIME COMPLEXITY : O(nlogn)
// SPACE COMPLEXITY : O(1)

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

/** algorithm is to first make every odd number negative
    then sort all the numbers
    then remove the negative sign of odd numbers
    **/

const int maxn = 105;
int ar[maxn];

int main()
{
int n;
read(n)

for(int i=0; i<n; i++)
{
    read(ar[i])
    if(ar[i]&1)
    {
        ar[i] = (0-ar[i]);
    }
}

sort(ar,ar+n);

for(int i=0; i<n; i++)
{
    if(!ar[i]%2)
    {
        ar[i]= (0-ar[i]);
    }
}

for(int i=0; i<n; i++)
    print("%d ",ar[i]);

return 0;

}
