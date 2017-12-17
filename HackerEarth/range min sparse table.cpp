#include<bits/stdc++.h>
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
#define maxx 500
using namespace std;

ll fast_po(ll base,ll exp) {
    ll res=1LL;
    while(exp > 0) {
        if((exp&1)) {
            res = ((ll)res*base)%mod;
        }
        exp /= 2;
        base = ((ll)base*base)%mod;
    }
        return res;
}

ll lookup[mx5][16];
ll arr[mx5];

struct Query {
    int L,R;
};

void preprocess(int n) {
    for(int i=0; i<n; i++) {
        lookup[i][0] = i;
    }
    for(int j=1; (1<<j)<=n; j++) {
        for(int i=0; (i+(1<<j)-1) < n; i++){
            if(arr[lookup[i][j-1]] < arr[lookup[i+(1<<(j-1))][j-1]])
                lookup[i][j] = lookup[i][j-1];
            else
                lookup[i][j] = lookup[i+(1<<(j-1))][j-1];
        }
    }
}

int query(int L,int R) {
    int j = (int)log2(R-L+1);
    if (arr[lookup[L][j]] <= arr[lookup[R - (1<<j) + 1][j]])
        return arr[lookup[L][j]];
   else
        return arr[lookup[R - (1<<j) + 1][j]];
}

int main() {
    int n;
    si(n);
    for(int i=0;i<n;i++){
        slli(arr[i]);
    }
    preprocess(n);
    int q,l,r;
    si(q);
    ll ans;

    while(q--) {
        si(l) , si(r);
        ans = query(l,r);
        printf("%lld\n",ans);
    }

    return 0;
}

