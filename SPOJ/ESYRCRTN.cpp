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
using namespace std;

int main() {
    int t;
    si(t);
    ll n;
    int f[6] = {1,4,6,5,2,0};
    while(t--) {
        slli(n);
        ll p=n%6;
        --p;
        printf("%d\n",f[p]);
    }

    return 0;
}
