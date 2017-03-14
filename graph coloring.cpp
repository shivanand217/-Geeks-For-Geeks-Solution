// AUTHOR: SHIV ANAND
// LANGUAGE: CPP

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

vector<int> graph[50];

int main()
{
int n;// vertices
int m;// edges

read(n)
read(m)

int a,b;

for(int i=0; i<m; i++)
{
    read(a)
    read(b)

    graph[a].push_back(b);
    graph[b].push_back(a);
}

bool available[50]={false};
int result[50]={-1}; // store color

// start with vertex 0 give it with color 0
result[0]=0;

// assigning color to the remaining n-1 vertex

for(int i=1; i<n; i++)
{
    for(int j=0; j<graph[i].size(); j++)
    {
        if(result[graph[i][j]] != -1)
            available[result[graph[i][j]]] = true;
    }

    int cr;

    for(cr=0; cr<n; cr++)
    {
        if(available[cr] == false)
        {
            break;
        }
    }
    result[i] = cr;

    // now make available the colors
    for(int j=0; j<graph[i].size(); j++)
    {
        if(result[graph[i][j]] != -1)
            available[result[graph[i][j]]] = false;
    }

}

// finally print the assigned color
for(int i=0; i<n; i++)
{
    cout<<result[i]<<" ";
}
return 0;

}
