#include<bits/stdc++.h>
using namespace std;
int main() {
    vector<long long> a,b;
    long long n,m,tmp;

    cin>>n>>m;
    for(long long i=0;i<n;i++) {
        cin>>tmp;
        a.push_back(tmp);
    }

    for(long long i=0; i<m; i++){
        cin>>tmp;
        b.push_back(tmp);
    }
    sort(b.begin(), b.end());

    for(long long i=0; i<n; i++) {
        auto p = upper_bound(b.begin(), b.end(), a[i]);
        if(p == b.end()) {
            cout<<"0 ";
        } else {
            auto k = p - b.begin();
            k = b.size() - k;
            cout<<k<<" ";
        }
    }   cout<<endl;

    return 0;
}
