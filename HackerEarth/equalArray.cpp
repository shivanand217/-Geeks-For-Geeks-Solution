#include<bits/stdc++.h>
using namespace std;

#define fast std::ios::sync_with_stdio(false)
#define t1 cin.tie(0)
#define t2 cout.tie(0)

const int maxn = 100005;
long long pre[maxn],tmp;
int t,n;

int main() {

    fast;
    t1; t2;
    cin>>t;

    while(t--) {
        cin>>n;
        //memset(pre,0LL,sizeof(pre));
        pre[0] = 0LL;

        // prefix sum
        for(int i=1; i <= n; i++) {
            cin>>tmp;
            if(i == 0) {
                pre[i] = tmp;
            } else {
                pre[i] = pre[i-1] + tmp;
            }
        }

        long long minimum = LLONG_MAX;

        for(int i=1; i < n; i++) {
            if( (pre[n] - pre[i]) - (pre[i] - pre[0]) >= 0) {
                minimum = min(minimum, (pre[n] - pre[i]) - (pre[i] - pre[0]));
            }
        }

        if(minimum == LLONG_MAX) {
            cout<<"-1"<<endl;
        } else {
            cout<<minimum<<endl;
        }

    }

    return 0;
}
