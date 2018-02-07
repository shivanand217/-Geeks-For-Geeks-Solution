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
long long a[100005];

int main() {
    int n,q,l,r;
    cin>>n>>q;
    for(int i=0; i<n; i++) {
        cin>>a[i];
    }
    sort(a, a + n);
    int ans1 ,ans2;

    while(q--) {
        cin>>l>>r;
        ans1 = lower_bound(a,a+n,l) - a;
        ans2 = lower_bound(a,a+n,r+1) - a;
        cout<<(ans2 - ans1)<<endl;
    }

    return 0;
}
