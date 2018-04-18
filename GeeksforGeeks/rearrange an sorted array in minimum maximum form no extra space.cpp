// AUTHOR: SHIV ANAND
// LANGUAGE: CPP
// TIME COMPLEXITY : O(n)
// SPACE COMPLEXITY : O(1)

#include<bits/stdc++.h>
#define si(x) scanf("%d",&x)
#define slli(x) scanf("%lld",&x)
#define sli(x) scanf("%ld",&x)
#define ff first

int n;
const int maxn = 1e3+2;

int ar[maxn];

int main()
{
    scanf("%d", &n);

    // array is sorted
    for(int i=0; i<n; i++)
    {
        scanf("%d", &ar[i]);
    }

    int i=0; int j=n-1;

    for(int k=0; k<n; k++)
    {
        if(k%2 == 0)
        {
            printf("%d ", ar[j]);
            j--;
        }
        else
        {
            printf("%d ", ar[i]);
            i++;
        }
    }

    return 0;
}
