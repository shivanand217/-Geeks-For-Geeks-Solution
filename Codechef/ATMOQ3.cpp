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
#define pli(x) printf("%lld",x)
#define sp() putchar(' ')
#define nl() putchar('\n')
#define mx5 100005
#define mx6 1000006
using namespace std;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef unordered_set<int> usi;
typedef map<int,int> mi;
typedef unordered_map<int,int> umi;

// using BIT
int n;
void update(ll arr[], int x, int value) {

    for(; x<=n; x += (x&(-x))) {
        arr[x] += value;
    }
}

ll visit(ll arr[], int x) {
    ll sum = 0LL;
    for(; x>0; x -= (x&(-x))){
        sum += (arr[x]);
    }
    return sum;
}

int main() {
int q,l,r,type,x,y,parity;

si(n);
si(q);

ll arr[n+1], even[n+1], odd[n+1];
memset(even, 0LL, sizeof(even));
memset(odd, 0LL, sizeof(odd));

for(int i=1; i<=n; i++){
    si(arr[i]);
    if(arr[i]%2 == 0){
        update(even, i, arr[i]);
    } else {
        update(odd, i, arr[i]);
    }
}

while(q--) {

    si(type);

    if(type == 1) {
        si(x);
        si(y);
        ll original = arr[x];
        arr[x] += y;

        if(y%2 == 0){
            if(arr[x]%2 == 0){
                update(even, x, y);
            } else {
                update(odd, x, y);
            }
        } else if(original%2 == 1 && y%2 == 1) {
            update(odd, x, -original);
            update(even, x, original+y);
        } else if(original%2 == 0 && y%2 == 1) {
            update(even, x, -original);
            update(odd, x, original+y);
        }

    } else {
        si(l);
        si(r);
        si(parity);
        if(parity == 1){
            ll sum = visit(odd, r) - visit(odd, l-1);
            pli(sum);
            nl();
        } else {
            ll sum = visit(even, r) - visit(even, l-1);
            pli(sum);
            nl();
        }
    }

}
	return 0;
}
