#include <bits/stdc++.h>

#define mp make_pair
#define ll long long
#define pb push_back

#define ss second
#define ff first
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

typedef pair<int,int> pii;

const int mxx = 100001;
// special value of infinity to take for getting rid of overflows
const int inf = 0x3f3f3f3f;

/******************* Problem Code *****************/
int par[2000006];
int size_[2000006];

void init(int n) {
    for(int i =1; i <=n; i++) {
        par[i] = i;
        size_[i] = 1;
    }
}
int root(int x) {
    while(x != par[x]){
        par[x] = par[par[x]];
        x = par[x];
    }
    return x;
}
void union_(int x, int y) {
    int p = root(x);
    int q = root(y);
    if(p == q) {
        return;
    }
    if(size_[p] > size_[q]) {
        par[p] = q;
        size_[q] += size_[p];
    } else {
        par[p] = q;
        size_[p] += size_[q];
    }
}

int main() {
    fast;
    int t,u,v;
    cin>>t;
    vector<pair<int,int> >  vec;
    string p;
    int n,k,r1,r2;
    while(t--) {
        vec.clear();
        cin>>n>>k;
        init(n);
        for(int i = 0; i < k; i++) {
            cin>>u;
            cin>>p;
            cin>>v;
            if(p[0] == '=') {
                union_(u, v);
            } else {
                vec.push_back(make_pair(u, v));
            }
        }
        bool ans = true;
        int k1 , k2;
        for( int i = 0; i < vec.size(); i++ ) {
            k1 = vec[i].ff;
            k2 = vec[i].ss;
            r1 = root(k1);
            r2 = root(k2);
            if( r1 == r2 ) {
                ans = false;
                break;
            }
        }
        if(ans == true) {
            cout<<"YES"<<endl;
        } else {
            cout<<"NO"<<endl;
        }
    }

    return 0;
}
