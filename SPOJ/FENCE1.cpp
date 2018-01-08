#include <bits/stdc++.h>
#define mp make_pair
#define ll long long
#define pb push_back
#define se second
#define fi first
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

const int mxx = 100001;
// special value of infinity to take for getting rid of overflows
const int inf = 0x3f3f3f3f;

int main() {

    int L;
    double ans;
    double pi = 3.14159;
    while( 1 )
    {
        scanf("%d",&L);
        if( !L )
            break;
        ans = (double(L * L)/(double)pi )/(double)2.0;
        printf("%.2f\n",ans);
    }

    return 0;
}
