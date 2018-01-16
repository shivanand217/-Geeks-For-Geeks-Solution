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
const int modd = 1e8+7;
int main() {
    fast;
    int t,n;
    cin>>t;
    int tmp;
    for(int p = 1; p <= t; p++) {
        cin>>n;
        int sum = 0;
        int pw = 1;
        cout<<"Case "<<p<<": ";
        for(int i=0; i<n; i++) {
            cin>>tmp;
            sum = (sum%modd + tmp%modd)%modd;
        }
        for(int i=1; i<n; i++) {
            pw = ((long long)pw * (long long)2)%modd;
        }
        cout<<(1LL * sum * pw)%modd<<endl;
    }

    return 0;
}
