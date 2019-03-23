
// AUTHOR: SHIV ANAND
// LANGUAGE: CPP
// TIME COMPLEXITY : O(logn)
// SPACE COMPLEXITY : O(n)

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

int minimax_tree(int node,int depth,int scores[],bool is_max,int h)
{
    if(depth == h)
    {
        return scores[node];
    }

    if(is_max)
    {
        return max(minimax_tree(2*node,depth+1,scores,false,h),minimax_tree(2*node+2,depth+1,scores,false,h));
    }
    else
    {
        return min(minimax_tree(2*node,depth+1,scores,true,h),minimax_tree(2*node+2,depth+1,scores,true,h));
    }
}

int main()
{
int scores[]= {3, 5, 2, 9, 12, 5, 23, 23};
int n = sizeof(scores)/sizeof(scores[0]);

int h=log2(n);

int result = minimax_tree(0,0,scores,true,h);
cout<<result<<endl;
return 0;

}
