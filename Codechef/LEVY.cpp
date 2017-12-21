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
vector<ll> primes;
bool isprime[100005];
int ordered[10006];
void seive() {
    memset(isprime,false,sizeof(isprime));
    isprime[0]=isprime[1]=true;
    for(ll i=2; i<100005; i++){
        if(isprime[i] == false){
            primes.pb(i);
            for(ll j=i*i; j<100005; j += i){
                isprime[j] = true;
            }
        }
    }
}
void precompute() {
    vector<ll> :: iterator up;
    int ans=0;
    ordered[0]=ordered[1]=ordered[2]=0;
    for(int i=3; i<10006; i++) {
        ans=0;
        ordered[i]=0;
        up = lower_bound(primes.begin(),primes.end(),i);
        ll pos = up - primes.begin();
        for(ll j=0; j<pos; j++){
            ll val = 2*primes[j];
            if(val > i)
                break;
            ll diff = i - val;
            if(isprime[diff] == false){
                ans++;
            }
        }
            ordered[i]=ans;
    }
}
int main() {
    int t,n;
    si(t);
    seive();
    precompute();
    while(t--){
        si(n);
        printf("%d\n",ordered[n]);
    }
    return 0;
}
