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

long long arr[1000006];
long long p[1000006];

int main() {
    int n;
    long long target,sum;
    cin>>n>>target;

    for( int i=0; i < n; i++){
        cin>>arr[i];
        p[i]=0;
    }
    sort(arr,arr+n);
    p[0]=arr[0];
    for(int i=1; i<n; i++){
        p[i]= arr[i]+p[i-1];
    }
    p[n] = p[n-1];

    long long lo=1, hi=1<<50, mid, best=1;
    while( lo <= hi) {
        mid = (lo+hi+1)/2;
        auto pos = upper_bound(arr, arr+n, mid) - arr;
        ll s = p[n-1] - p[pos] + arr[pos] - mid*(n - pos);
        if( s >= target ) {
            best = mid;
            lo = mid+1;
        } else {
            hi = mid-1;
        }
    }

    cout<<best<<endl;

    return 0;
}
