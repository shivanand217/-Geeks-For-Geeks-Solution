// AUTHOR: SHIV ANAND
// LANGUAGE: CPP
// TIME COMPLEXITY : O(n*n)
// SPACE COMPLEXITY : O(1)

/** idea i am using is to first sort the array and then searching linearly **/

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

int a[102];
int n;

void solve(int x)
{
    int l,r;

    l = 0;
    r = n-1;

    while(l < r)
    {
        if(a[l] + a[r] == x)
        {
            cout<<a[l]<<" "<<a[r]<<endl;
            return;
        }
        else if(a[l] + a[r] > x)
        {
            r--;
        }
        else if(a[l] + a[r] < x)
        {
            l++;
        }
    }
}

int main()
{
    si(n);
    int x;

    for(int i=0; i<n; i++)
    {
        si(a[i]);
    }

    si(x);
    sort(a,a+n); // O(nlogn)
    solve(x);

    return 0;
}
