#include<bits/stdc++.h>
#define mp make_pair

#define pb push_back
#define si(x) scanf("%d",&x)
#define slli(x) scanf("%lld",&x)
#define pi(x) printf("%d",x)
#define mx5 100005
#define mx6 1000006
#define mod 1000000007
#define rep(i,n) for(int i=0; i<n; i++)
#define fast std::ios::sync_with_stdio(false)
#define gc() getchar()
#define pc(x) putchar(x)
using namespace std;

typedef long long ll;

const int mxx = 314169;

ll col[mxx],row[mxx];

int main() {
    fast;
    int n,q;
    cin>>n>>q;
    ll c,x;
    string s;

    memset(col,0LL,sizeof(col));
    memset(row, 0LL, sizeof(row));

    ll rmax=0LL,cmax=0LL;

    while(q--) {
        cin>>s>>c>>x;
        --c;
        if(s == "RowAdd") {
            row[c] += x;
            if(row[c] > cmax)
                cmax = row[c];
        } else {
            col[c] += x;
            if(col[c] > rmax)
                rmax = col[c];
        }
    }

    cout<<(rmax+cmax)<<endl;

    return 0;
}
