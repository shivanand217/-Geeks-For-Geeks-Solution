// AUTHOR: SHIV ANAND
// LANGUAGE: CPP
// TIME COMPLEXITY : O(n)
// SPACE COMPLEXITY : O(1)

#include<bits/stdc++.h>
#define si(x) scanf("%d",&x)
#define slli(x) scanf("%lld",&x)
#define sli(x) scanf("%ld",&x)
#define ll long long
#define mod 1000000007
#define pfi(x) printf("%d\n",x)
#define pfli(x) printf("%ld\n",x)
#define pflli(x) printf("%lld\n",x)
#define lli long long int
#define ull unsigned long long int
#define fo_r(i,n) for(int i=0; i<n; i++)
using namespace std;

/** i have found a formula for this as
    a[0] = pair[0] + pair[1] - pair[3]; // for this original array must contain atleast
**/

int n;

int solve()
{
    int c= -(2*n);
    int b = -1;
    int a = 1;

    int d = b*b - 4*a*c;

    int root1,root2;

    root1 = (-b+sqrt(d))/(2*a);
    root2 = (-b-sqrt(d))/(2*a);

    if(root1 > 0)
    {
        return root1;
    }
    else if(root2 > 0)
    {
        return root2;
    }
}

int main()
{
si(n);

int *a = new int[n];

for(int i=0; i<n; i++)
{
    si(a[i]);
}

int root = solve();

int *original = new int[root];

int i,j;

int sum = a[0] + a[1];
i = root-1;

sum -= a[i];    original[0] = sum/2;    j=0;

int k = 1;
int m = k;

int cnt=0;
int glob = root-1;

for(int k=1; k<root; k++)
{
    if(cnt == root)
    {
    original[k] = a[j++] - original[k-1];
    }
}

for(int i=0; i<root; i++)
{
    cout<<original[i]<<" ";
}

return 0;

}
