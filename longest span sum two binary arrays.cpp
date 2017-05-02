// AUTHOR: SHIV ANAND
// LANGUAGE: CPP
// TIME COMPLEXITY : O(n)
// SPACE COMPLEXITY : O(2*n+1)

/**

we are using an extra space of 2*n+1
for that because we can get a difference in the range

        -n to +n
        -n in the case of first array is all 0 && second array is all 1

        vice versa for +n

**/

#include<bits/stdc++.h>
#define si(x) scanf("%d",&x)
#define slli(x) scanf("%lld",&x)
#define sli(x) scanf("%ld",&x)
#define ff first
using namespace std;

int ar1[105];
int ar2[105];

int solve(int n)
{
    int maxlen = 0;

    bool *seen = new bool[2*n+1];
    memset(seen , -1, sizeof(seen));

    int prefix_sum1 =0;
    int prefix_sum2 =0;

    int curr_diff;

    for(int i=0; i<n; i++)
    {

        prefix_sum1 += ar1[i];
        prefix_sum2 += ar2[i];

        curr_diff = prefix_sum1 - prefix_sum2;
        int index_diff = n + curr_diff;

        // if we get a zero diff of prefix sums then current index +1 is our answer
        if(curr_diff == 0)
        {
            maxlen = i+1;
        }
        // if current difference is seen first time
        else if(seen[index_diff] == -1)
        {
            seen[index_diff] = i;
        }
        else
        {
            int len = i - seen[index_diff];

            if(len > maxlen)
            {
                maxlen = len;
            }
        }
    }

    return maxlen;
}

int main()
{
    int n;
    scanf("%d", &n);

    for(int i=0; i<n; i++)
    {
        scanf("%d", &ar1[i]);
    }

    for(int i=0; i<n; i++)
    {
        scanf("%d", &ar2[i]);
    }

    int ans = solve(n);
    cout<<ans<<endl;

    return 0;
}
