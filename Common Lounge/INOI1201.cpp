// #include<iostream>
// #include<vector>
// #include<algorithm>
// #include<cstdlib>
#include<bits/stdc++.h>
using namespace std;

#define ff first
#define ss second

bool sort_by_compare(pair<int,pair<int,pair<int,int> > > x, pair<int,pair<int,pair<int,int> > > y) {
    return x.ss.ff > y.ss.ff;
}

int main() {
    int N,a,b,c;
    cin>>N;

    int temp = INT_MAX,ans=0,pre=0;

    for(int i=0; i<N; i++){
        cin>>a>>b>>c;
        ans += a;
        temp = min(temp, b+c);
        pre = max(pre, a+b+c);
    }

    ans += temp;
    ans = max(ans, pre);
    cout<<ans<<endl;

    return 0;
}
