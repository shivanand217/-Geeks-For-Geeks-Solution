// AUTHOR: SHIV ANAND
// LANGUAGE: CPP
// TIME COMPLEXITY : O(h)
// SPACE COMPLEXITY : O(1)

#include<bits/stdc++.h>
#include<cstdio>
#include<cstdlib>
#define read(val) scanf("%d",&val);
#define print(val) printf("%d ",val);
#define scan(val) scanf("%lld",&val);
#define show(val) printf("%lld ",val);
#define rr(val) for(int i=0; i<val; i++)
#define ret return 0;
#define ll long long
using namespace std;

/** Max is for chance is for the maximizer and Min is for the minimizer **/

int game_tree(int depth,int nodeIndex,bool isMax,int h,int tree[])
{
    if(depth == h)
        return tree[nodeIndex];

    if(isMax)
    {
        return max(game_tree(depth+1,2*nodeIndex,false,h,tree),game_tree(depth+1,2*nodeIndex+1,false,h,tree));
    }
    else
    {
        return min(game_tree(depth+1,2*nodeIndex,true,h,tree),game_tree(depth+1,2*nodeIndex+1,true,h,tree));
    }
}

int main()
{
    int n;

    int tree[]= {3, 5, 2, 9, 12, 5, 23, 23};
    n = sizeof(tree)/sizeof(tree[0]);

    int h=int(log2(n));
    int optimal_move = game_tree(0,0,true,h,tree);

    cout<<"the optimal move is: "<<optimal_move<<endl;
    return 0;
}
