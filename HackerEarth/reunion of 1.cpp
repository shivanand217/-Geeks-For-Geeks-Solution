#include <bits/stdc++.h>
#define mp make_pair
#define ll long long
#define pb push_back
#define se second
#define fi first
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

const int mxx = 1000001;
// special value of infinity to take for getting rid of overflows
const int inf = 0x3f3f3f3f;
int A[mxx], B[mxx], S[mxx];

int ans = 0;

void init(int n) {
    for(int i = 0; i <= n; i++) {
        B[i] = i;
        A[i] = 0;
    }
}

int root(int x) {
    while( x != B[x] ) {
        B[x] = B[B[x]];
        x = B[x];
    }
    return x;
}

void union_( int a, int b ) {
    int p = root(a);
    int q = root(b);

    if(S[p] > S[q]) {
        B[q] = B[p];
        S[p] += S[q];

    } else {
        B[p] = B[q];
        S[q] += S[p];
    }
}

void update( int index ) {
    if(A[index] == 1)
        return;

    A[index] = 1;
    // size if the chain
    S[index] = 1;
    B[index] = index;

    if(A[index - 1] == 1) {
        union_(index , index - 1);
    }

    if(A[index + 1] == 1) {
        union_(index , index + 1);
    }

    ans = max( ans, S[root(index)]);
}

int main() {
    fast;
    int n,q;
    cin>>n>>q;

    string s;
    cin>>s;

    int len = s.length();
    init(len);

    for( int i = 0; i < len; i++ ) {
        if( s[i] == '1' ) {
            update( i + 1 );
        }
    }

    int type, p;
    while( q-- ) {
        cin>>type;

        if(type == 1) {
            cout<<ans<<endl;
        } else {
            cin>>p;
            update(p);
        }
    }

    return 0;
}


