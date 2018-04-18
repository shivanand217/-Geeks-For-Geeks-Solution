// AUTHOR: SHIV ANAND
// LANGUAGE: CPP
// TIME COMPLEXITY : O(n*n*n)
// Space : O(1)

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
#define f first
#define s second
using namespace std;

int fast_pow(int x,int n)
{
    int result=1;
    while(n>0)
    {
        if(n % 2 ==1)
            result=(result * x)%mod;
        x=(x*x)%mod;
        n=n/2;
    }
    return result;
}

int gcd(int a,int b)
{
    if(a==0)
        return b;
    return gcd(b%a, a);
}

int lcm(int a,int b)
{
    int ans;
    ans = (a*b)/gcd(a,b);
    return ans;
}

const int maxn = 1e5+2;
vector<pair<int,int> > points;

bool determinant(pair<int,int> p1,pair<int,int> p2,pair<int,int> p3)
{
    int area = 0;
    area += p1.f * (p2.s - p3.s) - p1.s*(p2.f - p3.f) + (p2.f*p3.s - p3.f*p2.s);
    return area;
}

int count_number_of_possible_triangles(int n)
{
    int ans = 0;
    pair<int,int> p1,p2,p3;

    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            for(int k=j+1; k<n; k++)
            {
                p1= points[i];p2 = points[j]; p3 = points[k];
                if(determinant(p1,p2,p3))
                {
                    ans ++;
                }
            }
        }
    }
    return ans;
}

int main()
{
    int n;// number of points
    read(n)

    int x,y;

    for(int i=0; i<n; i++)
    {
        read(x)
        read(y)

        points.push_back(make_pair(x,y));
    }

    int ans = count_number_of_possible_triangles(n);

cout<<ans<<endl;

return 0;
}

