#include <bits/stdc++.h>
#define mp make_pair
#define ll long long
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

inline void furr_int(int &num) {
    bool neg=false;
    char ch;
    ch=gc();
    num=0;
    if(ch=='-') {
        neg=true;
        ch=gc();
    }
    for( ; (ch>='0' && ch<='9') ; ch=gc()){
        num = num*10 + (ch - '0');
    }
    if(neg)
        num *= (-1);
}

inline void furr_long(ll &num) {
    bool neg=false;
    char ch;
    ch=gc();
    num=0LL;
    if(ch=='-') {
        neg=true;
        ch=gc();
    }
    for(; (ch>='0' && ch<='9'); ch=gc()){
        num = num*10 + (ch - '0');
    }
    if(neg)
        num *= (ll)(-1);
}

const int maxn = 100005;
int parent[maxn];
int rank_[maxn];

void init(int n) {
    for(int i=0; i<n; i++){
        parent[i]=i;
        rank_[i]=1;
    }
}

int find_root(int x) {
    while(parent[x] != x) {
        parent[x] = parent[parent[x]];
        x = parent[x];
    }
        return x;
}

void union_(int u ,int v) {
    int x = find_root(u);
    int y = find_root(v);
    if(x == y) return;
    parent[x] = y;
    rank_[y] += rank_[x];
}

int main() {
    int n,m,u,v,x,y;
    furr_int(n);
    init(2*n);
    m=2*n;

    for(int i=0; i<n; i++) {
        furr_int(x);
        furr_int(y);
        --x, --y;
        union_(x,y);
    }

    int mn = maxn;
    int mx = 0;

    for(int i=0; i < m; i++) {
        u = find_root(i);
        if(rank_[u] > mx) mx = rank_[u];
        if(rank_[u] > 1 && rank_[u] < mn) mn = rank_[u];
    }

    printf( "%d %d\n", mn, mx );
    return 0;
}
