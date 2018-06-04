#include<bits/stdc++.h>
using namespace std;

#define fast std::ios::sync_with_stdio(false)

int k,n,tmp;
vector<int> temp;

bool compare(pair<int,pair<int,long long> > v1,pair<int,pair<int,long long> > v2) {
    return (v1.second.second < v2.second.second);
}

int main() {
    fast;
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>k;
    long long sum=0,new_sum;
    vector<pair<int,pair<int,long long> > > v;

    for(int j=1; j<=k; j++) {
        cin>>n;
        sum=0LL;
        temp.clear();
        for(int i=0; i<n; i++) {
            cin>>tmp;
            sum+=tmp;
            temp.push_back(tmp);
        }
        for(int i=0; i < temp.size(); i++) {
            new_sum = sum - temp[i];
            v.push_back(make_pair(j,make_pair(i+1, new_sum)));
        }
    }

    int x,y;
    int I,J;
    bool ans=false;

    sort(v.begin(), v.end(), compare);
    for(int i=0; i<v.size()-1; i++) {
        if(v[i].second.second == v[i+1].second.second) {
            if(v[i].first != v[i+1].first) {
                ans = true;
                x = v[i].second.first;
                y = v[i+1].second.first;
                I = v[i].first;
                J = v[i+1].first;
            }
        }
    }

    if(ans == true) {
        cout<<"YES"<<endl;
        cout<<I<<" "<<x<<endl;
        cout<<J<<" "<<y<<endl;
    } else {
        cout<<"NO"<<endl;
    }

    return 0;
}
