#include <bits/stdc++.h>

#define mp make_pair
#define ll long long
#define pb push_back

#define ss second
#define ff first
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

typedef pair<int,int> pii;

const int mxx = 100001;
// special value of infinity to take for getting rid of overflows
const int inf = 0x3f3f3f3f;

/******************* Problem Code *****************/

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

void multiply(ll F[2][2], ll M[2][2]) {
	ll x =  (F[0][0]*M[0][0] + F[0][1]*M[1][0])%1000;
 	ll y =  (F[0][0]*M[0][1] + F[0][1]*M[1][1])%1000;
 	ll z =  (F[1][0]*M[0][0] + F[1][1]*M[1][0])%1000;
  	ll w =  (F[1][0]*M[0][1] + F[1][1]*M[1][1])%1000;

 	F[0][0] = x; F[0][1] = y;
  	F[1][0] = z; F[1][1] = w;
}

void fib(ll F[2][2], ll n) {
	ll M[2][2] = {{F[0][0],F[0][1]},{F[1][0],F[1][1]}};
	F[0][0] = F[1][1] = 1; F[0][1] = F[1][0] = 0;

	while(n){
		if(n&1)
            multiply(F,M);
		n = n/=2;

		multiply(M,M);
	}
}

int main() {
	ll n , x;
	furr_long(n);

	ll F[2][2] = {{5,3},{1,0}};

	for(int i = 0; i < n; ++i){
        furr_long(x);
		fib(F, x);
	}

    ll ans = (F[1][0] + F[1][1])%1000;
    printf("%lld\n", ans);

    return 0;
}
