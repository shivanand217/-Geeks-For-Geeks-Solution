// AUTHOR: SHIV ANAND
// LANGUAGE: CPP
// TIME COMPLEXITY : O(n)
// SPACE COMPLEXITY : O(1)

/** simple fact is if two element have gcd equal to one then the whole array length will be the answer otherwise
    answer would be -1 **/

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

int gcd(int a,int b)
{
    if(a==0)
        return b;
    return gcd(b%a, a);
}

int main()
{
int n;
read(n)

for(int i=0; i<n; i++)
{
    read(arr[i])
}

int gcd_ = arr[0];

for(int i=0; i<n; i++)
{
    gcd_ = gcd(gcd_,arr[i]);
    if(gcd_ == 1)
    {
        cout<<n<<endl;
        return 0;
    }
}
cout<<-1<<endl;
return 0;

}
