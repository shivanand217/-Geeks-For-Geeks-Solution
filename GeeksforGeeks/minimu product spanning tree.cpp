// AUTHOR: SHIV ANAND
// LANGUAGE: CPP
// TIME COMPLEXITY: O()
// SPACE COMPLEXITY: O(N+no.of edges in spanning tree)

/** in this we are using classic kruskals algorithm but we replace each edge with
  the log value of each edge then we find the minimum product spanning tree **/

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

int n,m;

int parent[50];

void init()
{
    for(int i=0; i<n; i++)
    {
        parent[i]=i;
    }
}

int find_(int x)
{
    while(parent[x]!=x)
    {
        x=parent[x];
    }
    return x;
}

void union_(int x,int y)
{
    int root1=find_(x);
    int root2=find_(y);

    if(root1!=root2)
    {
        parent[root1]=root2;
    }
}

bool comp(pair<int,pair<int,double> > x,pair<int,pair<int,double> > y)
{
    return (x.second.second < y.second.second);
}

int main()
{

read(n)
read(m)

// set initially all the parent to itself
init();

int a,b;
double weight;

pair<int,pair<int,double> > pi[50];
vector<pair<int,int> > spanning_tree_edges;

for(int i=0; i<m; i++)
{
    cin>>a>>b>>weight;
    weight=log10(weight);
    pi[i]={a,{b,weight}};
}

//sort all the weight according to the weight
sort(pi,pi+n,comp);

double minimum_cost=0;
int a1,a2;

for(int i=0; i<m; i++)
{
a1=find_(pi[i].first);
a2=find_(pi[i].second.first);

if(a1!=a2)
{
    minimum_cost+=pi[i].second.second;
    spanning_tree_edges.push_back(make_pair(a1,a2));
    union_(a1,a2);
}

}

// show the edged included in the minimum product spanning tree
for(auto it=spanning_tree_edges.begin();it!=spanning_tree_edges.end();it++)
{
    cout<<it->first<<" "<<it->second<<endl;
}

return 0;
}
