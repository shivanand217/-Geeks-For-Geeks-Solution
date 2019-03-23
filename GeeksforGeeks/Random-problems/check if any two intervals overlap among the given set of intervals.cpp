// AUTHOR: SHIV ANAND
// LANGUAGE: CPP
// TIME COMPLEXITY : O(n*logn)
// SPACE COMPLEXITY : O(1)

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

struct pa_ir
{
    int x;int y;
};

struct pa_ir  p[102];

// using compare function
bool compare(struct pa_ir m, struct pa_ir n)
{
    return (m.x < n.x);
}

int solve(int n)
{
    sort(p,p+n, compare);

    int f1,f2,f3,f4;

    for(int i=1; i<n; i++)
    {
        f1 = p[i-1].x; f2 = p[i-1].y;

        f3 = p[i].x;  f4 = p[i].y;

        if(f2 >= f3 )
        {
            cout<<"overlapped pair: ";
            cout<<"{"<<f1<<","<<f2<<"}"<<" "<<"{"<<f3<<","<<f4<<"}"<<endl;return 0;
        }
    }
}

int main()
{
    int n;
    si(n);

    int x,y;

    for(int i=0; i<n; i++)
    {
        si(x);
        si(y);

        p[i].x = x;
        p[i].y = y;
    }
    solve(n);

    return 0;
}
