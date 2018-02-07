#include <bits/stdc++.h>
#define mp make_pair
#define ll long long
#define pb push_back
#define ss second
#define ff first
#define si(x) scanf("%d", &x)
#define slli(x) scanf("%lld", &x)
#define pi(x) printf("%d", x)
#define mx5 100005
#define mx6 1000006
#define mod 1000000007
#define rep(i,n) for(int i=0; i<n; i++)
#define fast std::ios::sync_with_stdio(false)
#define gc() getchar()
#define pc(x) putchar(x)

using namespace std;

const int mxx = 100011;
// special value of infinity to take for getting rid of overflows
const int inf = 0x3f3f3f3f;
typedef pair<int,int> pii;

int par[mxx];
int size_[mxx];
queue< pii > q;

void init(int n) {
    for(int i=1; i <= n; i++) {
        par[i] = i;
        size_[i] = 1;
    }
}

int root(int x) {
    while( x != par[x] ) {
        par[x] = par[par[x]];
        x = par[x];
    }
    return x;
}

void union_(int x, int y) {
    int p = root(x);
    int m = root(y);
    if(p == m)
        return;
    if( size_[p] > size_[m] ) {
        size_[m] += size_[p];
        par[p] = m;
    } else {
        size_[p] += size_[m];
        par[m] = p;
    }
}

int main() {
    fast;
    int n, qq, a, b, type, p, k;
    cin>>n>>qq;
    init(n);
    pii l;

    while(qq--) {
        cin>>type>>a>>b;
        bool flag = true;

        if(type == 1) {
            p = root(a);
            k = root(b);
            if(p != k) {
                cout<<"NO"<<endl;
                q.push( pii(a,b) );
                continue;
            }
            cout<<"YES"<<endl;
        } else {
            union_(a, b);
            while( !q.empty() ) {
                l = q.front();
                int p = root(l.ff);
                int k = root(l.ss);
                if(p != k) {
                    flag = false;
                    break;
                }
                q.pop();
            }
            if( flag == false ) {
                cout<<"NO"<<endl;
            } else {
                cout<<"YES"<<endl;
            }
        }

    }

    return 0;
}
