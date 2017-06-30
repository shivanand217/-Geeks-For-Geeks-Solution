#include<bits/stdc++.h>
using namespace std;
bool comp(pair<int,int> x, pair<int,int> y)
{
    return x.second < y.second;
}
int main()
{
    int t,n,x,y,init;
    cin>>t;
    vector<pair<int,int> > v, ans;
    while(t--)
	{
		v.clear();
		ans.clear();
        cin>>n;
        for(int i=0; i<n; i++)
		{
			cin>>x>>y;
			v.push_back(make_pair(x,y));
		}
        sort(v.begin(), v.end(), comp);
        int i;
        if(v.size()!=1){
        for(i=0; i<v.size()-1; )
		{
            if(v[i].second >= v[i+1].first)
			{
				init = i;
				while(v[i].second >= v[i+1].first)
				{
					i++;
				}
                ans.push_back({v[init].first, v[i].second});
                i++;
			}
			else
			{
                ans.push_back(v[i]);
                i++;
			}
		}
		if(i == v.size()-1)
		{
            ans.push_back(v[i]);
		}
        for(int i=0; i<ans.size(); i++)
		{
            cout<<ans[i].first<<" "<<ans[i].second<<" ";
		}cout<<endl;}
		else{
			cout<<v[0].first<<" "<<v[0].second<<endl;
		}
	}
	return 0;
}
