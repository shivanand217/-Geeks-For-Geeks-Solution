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
    int t;
    cin>>t;
    int c1;
    long long n;
    long long ans;
    while(t--) {
        ans = 0;
        cin>>n;
        if(n < 4) {
            ans=n;
            cout<<ans<<endl;
        } else {
            if(n%4 == 0) {
                ans=n/4;
                cout<<ans<<endl;continue;
            }
            if(n%5 == 0) {
                ans=n/5;
                cout<<ans<<endl;continue;
            }
            c1=n/5;
            n/=5;
            if(n%4==0) {
                ans=(c1+n/4);
                cout<<ans<<endl;continue;
            }
            if(n<4){
                ans=c1+n;
                cout<<ans<<endl;continue;
            }
        }
    }
    return 0;
}
