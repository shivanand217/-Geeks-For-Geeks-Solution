#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007

/** gives the power of x to the n in O(logn) **/
/** memorycomplexity of O(1) **/

int modularExponentiationIterative(int x,int n)
{
int result=1;
while(n>0){

if(n%2 == 1)
{
result = (result*x)%MOD;
}

x=(x*x)%MOD;
n/=2;

}

return result;
}

// recursive
/** Memory complexity: O(log N) because a function call consumes memory and log N recursive function calls are made **/
/** time O(logn) **/

int modularExponentiationRecursive(int x,int n)
{
    if(n == 0)
    {
        return 1;
    }
    else if(n%2 == 0)
        return modularExponentiationRecursive((x*x)%MOD,n/2);
    else
        return (x*modularExponentiationRecursive((x*x)%MOD,n/2))%MOD;
}

int main()
{
    int x;
    scanf("%d",&x);

    int ans = modularExponentiationRecursive(x,4);
    int ans2 = modularExponentiationIterative(x,4);

    printf("%d\n",ans);
    printf("%d\n",ans2);

    return 0;
}

