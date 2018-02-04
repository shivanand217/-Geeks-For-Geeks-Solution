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

int main() {
    int k , sum;
    cin>>k;
    int p = 0;
    ll tmp , ans;

    for(long long i = 19; i < 20000000; i++) {
        tmp = i;
        sum = 0;
        while(tmp) {
            sum += ( tmp%10 );
            tmp /= 10;
        }

        if(sum == 10) {
            p++;
            if(p == k) {
                ans = i;
                break;
            }
        }
    }

    cout<<ans<<endl;

    return 0;
}
