// AUTHOR: SHIV ANAND
// LANGUAGE: CPP
// TIME COMPLEXITY : O(n*logn)
// SPACE COMPLEXITY : O(1)

/** approach is greedy in the sorted permutation of the elements we select the elements alternatively **/

const int maxn = 105;
int ar[maxn];

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

int main()
{
int n;
read(n)

int *ar = (int *)malloc(n*sizeof(int));

for(int i=0; i<n; i++)
{
    read(ar[i])
}
sort(ar,ar+n);

int sum=0;;




free(ar);
return 0;

}
