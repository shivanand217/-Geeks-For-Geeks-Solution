// AUTHOR: SHIV ANAND
// LANGUAGE: CPP
// COMPLEXITY: O(N)

// simlest approach
// log(n!) = log(1)+log(2)+log(3)+.......+log(n)
// solution will be floor(log(n!))+1

#include<bits/stdc++.h>
using namespace std;

int find_digits(int n)
{
    if(n<0)
        return 0;

    if(n<=1)
        return 1;

    int digits=0;
    float sum=0;
    for(int i=2;i <=n;i++)
    {
        sum+=log10(i);
    }

    digits=floor(sum)+1;

      return digits;
}

int main()
{
    int n;
    scanf("%d",&n);

    int p=find_digits(n);

    printf("%d\n",p);
    return 0;
}
