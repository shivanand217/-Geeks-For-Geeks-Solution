// AUTHOR: SHIV ANAND
// LANGUAGE: CPP

/** a bfs approach **/

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

struct data
{
    int value;
    int steps;
    data(int value,int steps): value(value), steps(steps){}
};

void bfs(int n)
{

queue<data> qu;
qu.push({n,0});

set<int> set1;

set1.insert(n);

while(!qu.empty())
{

data f = qu.front();
qu.pop();

cout<<f.value<<" ";

if(f.value == 1)
{
    return f.steps;
}

if(set1.find(f.value-1) == set1.end())
{
    qu.push({f.value-1,f.steps+1});
}

// find all the divisors and push if not visited

for(int i=2; i*i<=f.value; i++)
{
    if(f.value % i == 0 && set1.find(f.value/i) == set1.end())
    {
        qu.push({f.value/i,f.steps+1});
        set1.insert(f.value/i);
    }
}

}



}

int main()
{

int n;
read(n)



}
