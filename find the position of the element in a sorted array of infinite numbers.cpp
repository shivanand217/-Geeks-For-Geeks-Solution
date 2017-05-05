// AUTHOR: SHIV ANAND
// LANGUAGE: CPP
// TIME COMPLEXITY : O(log(p)) //p is the position of the element
// SPACE COMPLEXITY : O(1)

/** complexity:

    let us suppose that the position of the element will be p
    then we have to go for maximum O(log(p)) positions for high
    then for binary search. Between h and h/2 their will be maximum O(p) elements
    so another O(log(p)) for binary search

    total compexity : 2*O(log(p)) that is O(log(p))

    **/

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

/** array is infinite but here i am showing that as limited one **/
/** i am assuming that element should be cached within this much memory **/

const int maxn = 1e5+2;
int a[maxn];

int main()
{
    int n;
    si(n);

    for(int i=0; i<n; i++)
    {
        si(a[i]);
    }

    int key;
    si(key);

    // taking first two elements

    int lo=0;
    int hi=1;

    int ans;

    while(1)
    {
        if(a[hi] < key)
        {
          lo = hi;
          hi *=2;
        }
        else if(a[hi] == key)
        {
            ans = hi;break;
        }
        else{
            // binary search in between hi and lo
            int mid;

            while(lo <= hi)
            {
                mid = (hi-lo)/2 + lo;

                if(a[mid] == key)
                {
                    ans = mid;break;
                }
                else if(a[mid] > key)
                {
                    hi = mid-1;
                }
                else
                {
                    lo = mid+1;
                }
            }
        }
    }
    cout<<ans<<endl;
return 0;
}

