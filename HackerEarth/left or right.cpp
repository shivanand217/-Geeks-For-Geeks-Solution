#include<bits/stdc++.h>
#define pb push_back
#define fast std::ios::sync_with_stdio(false)
#define gc() getchar()
#define pc(x) putchar(x)
using namespace std;

int n, q, z, y, ans;
unordered_map<int, vector<int> > un;
int a[200015];

int main() {
    fast;
    cin>>n>>q;
    for(int i=0; i < n; i++) {
        cin>>a[i];
        un[a[i]].pb(i);
    }

    char c;
    int fir=0, sec=0;

    while(q--) {
        fir=0 , sec=0;
        cin>>y>>z>>c;

        if( a[y] == z ) {
            cout<<"0"<<endl;
            continue;
        }

        if(un[z].size() == 0) {
            cout<<"-1"<<endl;
            continue;
        }

        int ans = INT_MAX;
        if(c == 'L') {
            for(int i=0; i<un[z].size(); i++) {
                if(un[z][i] <= y) {
                    ans = min(ans , y - un[z][i]);
                } else {
                    ans = min(ans , y + n - un[z][i]);
                }
            }
        } else {
            for(int i=0; i<un[z].size(); i++) {
                if(un[z][i] >= y) {
                    ans = min(ans , un[z][i] - y);
                } else {
                    ans = min(ans , n - y + un[z][i]);
                }
            }
        }

        cout<<ans<<endl;
    }

    return 0;
}

