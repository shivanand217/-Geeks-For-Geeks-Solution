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
long long get_div( long long n ) {
    long long i , p, sum = 0;
    for( i = 1; i * i <= n; i++ ) {
        if(n % i == 0) {
            p = (n/i);
            if(p == i) {
                if(p % 2 == 1) {
                    sum += p;
                }
            } else {
                if( p % 2 == 1 ) {
                    sum += p;
                }
                if( i % 2 == 1 ) {
                    sum += i;
                }
            }
        }
    }
    return sum;
}

int main() {
    fast;
    int t;
    long long n;
    cin>>t;

    while( t-- ) {
        cin>>n;
        long long sum = get_div(n);
        cout<<sum<<endl;
    }

    return 0;
}
