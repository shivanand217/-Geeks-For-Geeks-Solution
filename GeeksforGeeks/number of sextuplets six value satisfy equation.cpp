// AUTHOR: SHIV ANAND
// LANGUAGE: CPP

/** number of values satisfy for the equation
    (a*b+c/d) - e = f **/

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

/** we convert it in the form a*b+c = (f+e)*d **/

int find_sextuplets(vector<int> v, int n)
{
    vector<int> rhs;

    for(int i=0; i<n; i++)
    {
        if(v[i]) // not should be zero
            for(int j=0; j<n; j++)
                for(int k=0; k<n; k++)
                    rhs.push_back(v[i]*(v[j] + v[k]));
    }

    sort(rhs.begin(), rhs.end());
    int result = 0;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            for(int k=0; k<n; k++)
            {
                int val = (v[i]*v[j] + v[k]);
                if(binary_search(rhs.begin(),rhs.end(),val))
                {
                    result++;
                }
            }
        }
    }

    return result;
}

int main()

{
int n;
read(n)

vector<int> vect;

int tmp;
for(int i=0; i<n; i++)
{
    read(tmp);

    vect.push_back(tmp);
}
int ans  =  find_sextuplets(vect, vect.size());

cout<<ans<<endl;
return 0;
}
