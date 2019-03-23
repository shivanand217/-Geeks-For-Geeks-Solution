// AUTHOR: SHIV ANAND
// LANGUAGE: CPP
// COMPLEXITY:

#include<bits/stdc++.h>
#define read(val) scanf("%d",&val)
#define print(val) printf("%d",val)
using namespace std;

int n;
map<int,int> dist;

int solve(vector<pair<int,int> > points,int radius)
{
    int low=0;int high=n-1;
    int mid;

    while(low<=high)
    {
        mid=(low+high)/2;

        if(dist[mid] < radius)
            low=mid+1;
        else
            high=mid-1;
    }

return low;
}

inline int calc(int x,int y)
{
    return sqrt(x*x+y*y);
}

int main()
{
    //int n;
    read(n);

    int x,y;

    vector<pair<int,int> > points;
int d;

    for(int i=0; i<n; i++)
    {
        read(x);read(y);
        points.push_back(make_pair(x,y));
    }

    sort(points.begin(),points.end());

    for(int i=0; i<n ;i++)
    {
      d = calc(x,y);
      dist[i]=d;
    }

    int qu;
    read(qu);

    int tmp,ans;
    while(qu--)
    {
        read(tmp);
     ans = solve(points,tmp);

     print(ans+1);
    }

    return 0;
}
