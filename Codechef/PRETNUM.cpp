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
bool isprime[100005];
void pre() {
    memset(isprime, false, sizeof(isprime));
    isprime[0]=isprime[1]=true;
    /**for(int i=2; i < 10000; i++) {
        int j=2;
        for(; j*j <= i; ++j) {
            if(i % j == 0) {
                break;
            }
        }
        if(j*j > i)
            isprime[i]=true;
    }**/
    for(ll i=2; i < 100005; i++) {
        if(isprime[i] == false) {
            for(ll j=i*i; j < 100005; j += i){
                isprime[j]=true;
            }
        }
    }
}
int divisors[1000005];
int main() {
    pre();
    int t;
    si(t);
    ll L,R;
    while(t--) {
        slli(L),slli(R);
        for(ll i=L; i<=R; i++){
            divisors[i-L]=0;
        }
        for(ll i=1; i*i <= R; i++) {
            ll sq = i*i;
            /** lowest multiple of i in range [L..R]**/
            ll j = ((L)/i)*i;
            if (j < L)
                j += i;
            for( ; j <= R; j += i){
                if( j < sq )
                    continue;
                if( sq ==  j )
                    divisors[ j-L]++;
                else
                    divisors[j-L] += 2;
            }
        }
        int ans=0;
        for(ll i=L; i<=R; i++) {
            if(isprime[divisors[i-L]] == false)
                ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
