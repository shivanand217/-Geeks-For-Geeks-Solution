#include<bits/stdc++.h>
#define maxn 5005
#define mod 998244353
using namespace std;

long long nCk[maxn][maxn];
long long fact[maxn];

void nCr() {

    memset(nCk, 0LL, sizeof(nCk));
    nCk[0][0]=1LL;
    for(int i=1;i<=5000;i++){
        nCk[i][0]=1LL;
        for(int j=1;j<=i;j++){
            nCk[i][j]=(nCk[i-1][j]%mod+nCk[i-1][j-1]%mod)%mod;
        }
    }

}

long long getVal(int a,int b) {
    long long res=0;
    for(int k=0; k<=min(a,b); k++) {
        long long fac=fact[k];
        fac=(1LL*fac*nCk[a][k])%mod;
        fac=(1LL*fac*nCk[b][k])%mod;
        res=(res+fac)%mod;
    }
    return res;
}

int main() {

	nCr();
    int a,b,c;
    scanf("%d %d %d", &a, &b, &c);

    memset(fact, 0LL, sizeof(fact));
    fact[0]=1LL;

    // factorial
    for(int i=1;i<=5000;i++){
        fact[i]=(1LL*fact[i-1]*i)%mod;
    }

    long long ans=1;
    ans=(1LL*ans*getVal(a,b))%mod;
    ans=(1LL*ans*getVal(b,c))%mod;
    ans=(1LL*ans*getVal(a,c))%mod;

    printf("%lld\n", ans);

	return 0;
}
