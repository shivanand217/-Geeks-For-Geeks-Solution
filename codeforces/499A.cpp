#include<bits/stdc++.h>
#define si(x) scanf("%d",&x)
#define ll long long
using namespace std;

int main()
{
    int n , skipping;
    int l , r;

    si(n); si(skipping);
    vector<pair<int,int> > interval;

    for(int i=0; i<n; i++) {
        si(l); si(r);
        interval.push_back(make_pair(l,r));
    }

    int now=1, fir, sec, gap, skip, time_watched=0;

    for(int i=0; i<interval.size(); i++){
        fir = interval[i].first;
        sec = interval[i].second;
        gap = fir - now;
        skip = gap/skipping;
        skip = skip*skipping;
        now = now + skip;
        time_watched += (sec - now + 1);
        now = sec + 1;
    }

    cout<<time_watched<<endl;
    return 0;
}
