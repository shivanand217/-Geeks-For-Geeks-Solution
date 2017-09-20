#include<bits/stdc++.h>
using namespace std;
#define si(x) scanf("%d",&x)
#define pi(x) printf("%d",x)
#define pi_ln() printf("\n")
#define pi_sp() printf(" ")
int home[100005], away[100005];
int main()
{
    int n;
    si(n);
    int x,y,k,l;
    map<int,int> home_,away_;
    vector<pair<int,int> > v;
    for(int i=1;i<=n;i++)
	{
        si(home[i]);  si(away[i]);
        home_[home[i]]++;
        away_[away[i]]++;
	}
    for(int i=1;i<=n;i++)
	{
        k=n-1;
        k+=home_[away[i]];
        l=n-1-home_[away[i]];
        v.push_back(make_pair(k,l));
	}
    for(int i=0;i<v.size();i++)
	{
        pi(v[i].first);
        pi_sp();
        pi(v[i].second);
        pi_ln();
	}
    return 0;
}

