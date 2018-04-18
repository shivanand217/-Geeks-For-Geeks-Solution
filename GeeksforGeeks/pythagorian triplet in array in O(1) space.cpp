// AUTHOR: SHIV ANAND
// LANGUAGE: CPP
// TIME COMPLEXITY : O(n*n)
// SPACE COMPLEXITY : O(1)

/** find a pythagorian triplet in a array without extra space **/

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

ll a[102];

int main()
{
    int n;
    si(n);

    fo_r(i,n)
    {
        slli(a[i]);
        a[i] = a[i]*a[i];
    }

    int l,r;

    for(int i=n-1; i>=2; i--)
    {
        l = 0;
        r = i-1;

        while(l < r)
        {
            if(a[l] + a[r] == a[i])
            {
                cout<<a[l]<<" "<<a[r]<<" "<<a[i]<<endl;return 0;
            }
            else if(a[l] + a[r] > a[i])
            {
                r--;
            }
            else if(a[l] + a[r] < a[i])
            {
                l++;
            }
        }
    }

return 0;
}
