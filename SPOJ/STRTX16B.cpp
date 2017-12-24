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

void multiply(ll F[2][2],ll M[2][2]) {
  long long x =  (F[0][0]*M[0][0]%mod + F[0][1]*M[1][0]%mod)%mod;
  long long y =  (F[0][0]*M[0][1]%mod + F[0][1]*M[1][1]%mod)%mod;
  long long z =  (F[1][0]*M[0][0]%mod + F[1][1]*M[1][0]%mod)%mod;
  long long w =  (F[1][0]*M[0][1]%mod + F[1][1]*M[1][1]%mod)%mod;
  F[0][0] = x;
  F[0][1] = y;
  F[1][0] = z;
  F[1][1] = w;
}

void power(ll F[2][2],long long n) {
    if(n == 0 || n == 1)
        return;
    long long M[2][2] = {
                    {1,1},
                    {1,0}
                  };
    power(F,n/2);
    multiply(F,F);
    if((n&1)){
        multiply(F, M);
    }
}

long long ans(ll n) {
    ll F[2][2] = {{1,1},{1,0}};
    if(n == 0 || n == 1)
        return 0LL;
    power(F, n-1);
    return F[0][0]%mod;
}

int main() {
    fast;
    int t;
    cin>>t;
    long long n;
    while(t--) {
        cin>>n;
        cout<<ans(n)<<endl;
    }

    return 0;
}
