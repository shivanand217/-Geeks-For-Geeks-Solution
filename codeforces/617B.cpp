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

const int mxx = 10005;
// special value of infinity to take for getting rid of overflows
const int inf = 0x3f3f3f3f;

int main() {
    int n , tmp;
    cin>>n;
    long long ans = 0LL;
    int last = -1;
    for(int i=1; i <= n; i++) {
        cin>>tmp;
        if(tmp == 1) {
            if(ans == 0) {
                ans = 1;
            } else {
                ans = ans * (i - last);
            }
            last = i;
        }
    }
    cout<<ans<<endl;

    return 0;
}
