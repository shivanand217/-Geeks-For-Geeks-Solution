// AUTHOR: SHIV ANAND
// LANGUAGE: CPP
// TIME COMPLEXITY : O(n)
// SPACE COMPLEXITY : O(1)

/** finding first and second largest in an array in one traversal **/

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
#define fo_r(i,n) for(int i=0; i<n; i++)
using namespace std;

int ar[102];
int n;
int main()
{
    si(n);

    for(int i=0; i<n; i++)
    {
        si(ar[i]);
    };

    int m1 = max(ar[0],ar[1]);
    int m2 = max(ar[1],ar[0]);

    for(int i=2; i<n;i++)
    {
        if(ar[i] > m1)
        {
            m2 = m1;
            m1  = ar[i];
        }
        else if(ar[i] > m2 && ar[i] != m1)
        {
            m2 = ar[i];
        }
    }

    cout<<m1<<" "<<m2<<endl;

    cout<<(m1+m2)<<endl;

    return 0;
}
