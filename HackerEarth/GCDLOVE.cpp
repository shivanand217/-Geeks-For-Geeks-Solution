/** approach: matrix exponentiation + segment tree **/

#include<bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
#define ll long long
#define max3(a,b,c) max(a, max(b,c))
#define max4(a,b,c,d) max(a, max(b, max(c,d)))
#define pb push_back
#define si(x) scanf("%d",&x)
#define slli(x) scanf("%lld",&x)
#define pi(x) printf("%d",x)
#define sp() putchar(' ')
#define nl() putchar('\n')
#define mx5 100010
#define mx6 1000010
#define MOD 1000000007
using namespace std;

ll arr[mx5];
ll Tree[2*mx5];
int l,r,n;

ll gcd(ll a, ll b) {
    if(a == 0)
		return b;
	return gcd((b%a), a);
}

void multiply(ll F[2][2], ll M[2][2]) {

  ll x =  (F[0][0]*M[0][0] + F[0][1]*M[1][0])%MOD;
  ll y =  (F[0][0]*M[0][1] + F[0][1]*M[1][1])%MOD;
  ll z =  (F[1][0]*M[0][0] + F[1][1]*M[1][0])%MOD;
  ll w =  (F[1][0]*M[0][1] + F[1][1]*M[1][1])%MOD;

  F[0][0] = x;
  F[0][1] = y;
  F[1][0] = z;
  F[1][1] = w;
}

void power(ll F[2][2], ll n) {
    if(n == 0 || n == 1)
		return;

    ll M[2][2] = { {1LL,1LL},{1LL,0LL} };

    power(F, n/2);
    multiply(F, F);

    if((n&1)) {
        multiply(F, M);
    }
}

ll calculate(ll n) {
    ll F[2][2] = {{1LL,1LL},
				  {1LL,0LL}};
    if(n == 0)
		return 0;
    power(F, n-1);

    return (F[0][0]);
}

void build(int node, int s, int e) {
    if(s == e) {
        Tree[node] = arr[s];
        return;
    }

    int mid = s+(e-s)/2;
    int left = 2*node;
    int right = left + 1;

    build(left ,s, mid);
    build(right, mid+1, e);

    Tree[node] = gcd(Tree[left] , Tree[right]);
}

void update(int node, int s, int e, int index, ll val) {

}

ll query(int node, int s, int e, int l, int r) {
    if(l == s && r == e) {
        return Tree[node];
    }

    int mid = s+(e-s)/2;
    int left = 2*node;
    int right = left+1;

    if(r <= mid) {
        return query(left, s, mid, l, r);
    }

    if(l > mid) {
        return query(right, mid+1, e, l, r);
    }

    ll leftAns = query(left, s, mid, l, mid);
    ll rightAns = query(right, mid+1, e, mid+1, r);

    return gcd(leftAns,rightAns);
}

int main() {

    int Q,index;
    char type;
    si(n), si(Q);

    for(int i=0; i<n; i++) {
		slli(arr[i]);
    }

    build(1, 0, n-1);

    while(Q--) {

		scanf("%c ", &type);

        if(type == 'Q') {

            si(l), si(r);
            --l, --r;

			ll ans = query(1, 0, n-1, l, r);
			printf("%lld\n", calculate(ans));

        } else {

			si(index), slli(value)
            update(1, 0, n-1, index, value);
        }
    }

	return 0;
}
