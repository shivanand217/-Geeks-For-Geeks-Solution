#include<bits/stdc++.h>
using namespace std;

const int maxn = 3e5+5;
long long ans[maxn];

map<long long ,int> ma;
vector<pair<long long,int> > vect;

bool sortt(pair<long long,int> p1,pair<long long,int> p2)
{
    return p1.first<p2.first;
}

int main()
{
    int n;

    long long temp;
    cin>>n;

    for(int i=0; i<n; i++)
    {
        scanf("%lld", &temp);
        vect.push_back(make_pair(temp,i));
    }
    sort(vect.begin(),vect.end(),sortt);

long long latest_;

for(int p=0; p<vect.size(); p++)
{
    if(ma[vect[p].first] == 0)
    {
        ans[vect[p].second] = vect[p].first;
ma[vect[p].first]++;
latest_ = vect[p].first+1;
    }
    else
    {
        ans[vect[p].second] = latest_;
        ma[latest_]++;
        latest_++;
    }
}

for(int i=0; i<n; i++)
{
   printf("%lld " ,ans[i]);
}
printf("\n");
return 0;
}
