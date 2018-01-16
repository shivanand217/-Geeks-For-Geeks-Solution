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
    fast;
    int n;
    cin>>n;
    long long gcdd;
    for(int i=0; i<n; i++) {
        cin>>a[i];
    }
    gcdd = abs(a[1]-a[0]);
    for(int i=1;i<n;i++) {
        gcdd = __gcd(gcdd, abs(a[i]-a[i-1]));
    }
    long long req = 0;
    for(int i=1; i<n; i++) {
        req += (((a[i] - a[i-1])/gcdd) - 1);
    }
    cout<<req<<endl;
    return 0;
}
