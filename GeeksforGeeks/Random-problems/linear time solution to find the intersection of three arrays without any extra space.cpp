// AUTHOR: SHIV ANAND
// LANGUAGE: CPP
// TIME COMPLEXITY : O(n1+n2+n3) // n1,n2,n3 are the sizes of the array
// SPACE COMPLEXITY : O(1)

/** like the idea of calculating intersection of two array without extra space in linear time **/

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
int a[102],b[102],c[102];

void solve(int x,int y,int z)
{
    int i=0;
    int j=0;
    int k=0;

    while(i < x && j < y && k < z)
    {
        // if all the three are equal then print them
        if(a[i] == b[j] && b[j] == c[k])
        {
            cout<<a[i]<<" ";

            i++;j++;k++;
        }
        else if(a[i] < b[j])
        {
            i++;
        }
        else if(b[j] < c[k])
        {
            j++;
        }
        else
        {
            k++;
        }
    }
    return;
}

int main()
{
    int x,y,z;

    si(x);
    si(y);
    si(z);

    for(int i=0; i<x; i++)
    {
        si(a[i]);
    }

    for(int j=0; j<y; j++)
    {
        si(b[j]);
    }

    for(int k=0; k<z; k++)
    {
        si(c[k]);
    }

    solve(x,y,z);
    return 0;
}
