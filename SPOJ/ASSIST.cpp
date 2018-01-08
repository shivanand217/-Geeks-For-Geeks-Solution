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
bitset<100006> b;
vector<int> p;

void s() {
    b.set();
    b[0] = b[1] = 0;
    for(ll i=2; i < 100006; i++){
        if(b[i] == 1) {
            for(ll j = i*i; j < 100006; j += i){
                b[j]=0;
            }
        }
    }
    for(ll i=2; i < 100006; i++){
        if(b[i] == 1) {
            p.pb(i);
            //cout<<i<<" ";
        }
    }
}
int main() {
    s();int t;
    for( ; ; ) {
        si(t);
        if(!t)
            break;
        printf("%d\n",p[t-1]);
    }
    return 0;
}
