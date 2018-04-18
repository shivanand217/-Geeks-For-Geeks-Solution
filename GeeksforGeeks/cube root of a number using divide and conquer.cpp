// AUTHOR: SHIV ANAND
// LANGUAGE: CPP
// COMPLEXITY: O(logn)

/** for using divide and conquer in this we set start=0 end=n
then we set an very small value of e = 0.00001
if the difference between n and mid*mid*mid is less than e then mid is the cube root of n
else we recur for right or left subpart **/


#include<bits/stdc++.h>
#define read(val) scanf("%d",&val)
#define print(val) printf("%d",val)
#define scan(val) scanf("%lld",&val)
#define show(val) printf("%lld",val)
#define ll long long
using namespace std;

#define e 0.00001
const int maxn = 1e5+2;
//ll arr[maxn];

double n;

double absolute_difference(double n,double mid)
{
    return abs(n-(mid*mid*mid));
}

double solve()
{
 double low=0;
double high = n;

double mid;

while(low <= high)
{
    mid=(low+high)/2;

double err = absolute_difference(n,mid);

if(err <= e)
    return mid;

if(mid*mid*mid > n)
    high =mid;
else
    low = mid;
}

}

int main()
{
//    read(n);
cin>>n;
    double ans = solve();
    printf("%.6f\n",ans);
    return 0;
}
