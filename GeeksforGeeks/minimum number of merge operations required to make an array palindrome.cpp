// AUTHOR: SHIV ANAND
// LANGUAGE: CPP
// TIME COMPLEXITY : O(n)
// SPACE COMPLEXITY : O(1)

/** we just check for the current i and j
        if it is equal then then do nothing
        if ith is greater than jth then we merge (j-1) with (j-1)th and jth
        and vice versa
**/

#include<bits/stdc++.h>
#define si(x) scanf("%d",&x)
#define slli(x) scanf("%lld",&x)
#define sli(x) scanf("%ld",&x)
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define ll long long
#define mod 1000000007
#define pfi(x) printf("%d\n",x)
#define pfli(x) printf("%ld\n",x)
#define pflli(x) printf("%lld\n",x)
#define lli long long int
#define ull unsigned long long int
using namespace std;

int ar[10002];

int main()
{
    int n;
    scanf("%d", &n);

    for(int i=0; i<n; i++)
    {
        scanf("%d", &ar[i]);
    }

    int i=0; int j=n-1;
    int ans=0;

    while(i <= j)
    {
        if(ar[i] == ar[j])
        {
            i++; j--;
        }
        else
        {
            if(ar[i] > ar[j])
            {
                ar[j-1]= ar[j-1]+ ar[j];
                ans++;
                j--;
            }
            else
            {
                ar[i+1] = ar[i+1] + ar[i];
                ans++;
                i++;
            }
        }
    }

printf("%d\n", ans);

return 0;
}
