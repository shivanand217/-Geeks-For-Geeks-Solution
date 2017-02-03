// AUTHOR: SHIV ANAND
// LANGUAGE: CPP
// COMPLEXITY: O(N)
// carreer cup

#include<bits/stdc++.h>
using namespace std;

// Important point to notice is that the consequetive sequence cannot be greater than n/2
// because n/2+(n/2+1) will be greater than n

void solve(int n)
{
    int start=1;int end_=1;
    int sum=1;

    while(start <= n/2)
    {
        if(sum < n)
        {
            end_+=1;
            sum+=end_;
        }
        else if(sum > n)
        {
            sum-=start;
            start+=1;
        }
        else if(sum == n)
        {
            for(int i=start; i<end_; i++)
            {
                printf("%d ",i);
            }
            printf("\n");
            sum-=start;
            start+=1;
        }
    }
}

int main()
{
    int n;
    scanf("%d",&n);

    solve(n);

    return 0;
}
