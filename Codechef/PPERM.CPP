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

const int mx = 5000005;
int dp[mx];
bool isprime[mx];
int prime[mx];

void pre_compute1() {
    isprime[0] = isprime[1] = false;
    for(int i=2; i < mx; i++)
        isprime[i]=true;
    for(int i=2; i < mx; i++) {
        if(isprime[i]==true) {
            //curr++;
            for(ll j=(long long)i*i; j < mx; j+=(long long)i){
                isprime[j] = false;
            }
        }
    }
}

void pre_compute2() {
    for(int i=0;i<mx;i++) {
        dp[i]=0;
        prime[i]=0;
        if(i>=2) {
            if(isprime[i]){
                prime[i]=prime[i-1]+1;
            } else {
                prime[i]=prime[i-1];
            }
        }
    }
    dp[1]=1;
    for(int i=2; i<mx; i++) {
        dp[i] = ((long long)dp[i-1]*(1+prime[i]))%mod;
    }
}

int main() {
    pre_compute1();
    pre_compute2();
    ll t,tmp;
    scanf("%lld",&t);
    while(t--) {
        scanf("%lld",&tmp);
        printf("%d\n",dp[tmp]);
    }

    return 0;
}
