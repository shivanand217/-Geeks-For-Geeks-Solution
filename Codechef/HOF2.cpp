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
    fast;
    int t,n;
    cin>>t;
    long long bag,k,hi,sum;

    while(t--) {
        cin>>n;
        if(n<7){
            cout<<"0"<<endl;
            continue;
        }
        bag=(n/7);
        hi=(bag*7);
        sum=(bag*(7+hi))/2;
        cout<<sum<<endl;
    }

    return 0;
}
