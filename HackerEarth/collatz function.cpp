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
ll a[100005];

ll calc(ll num) {
    int steps=0;
    while(num != 1) {
        if(num%2 == 1){
            num=3*num+1;
        }else{
            num/=2;
        }
        steps++;
    }
    return steps++;
}

void pre() {
    a[1] = 0;
    a[2] = 1;
    for( ll i = 3; i < 33000; i++ ) {
        a[i] = calc(i);
    }
}

int main() {
    fast;
    pre();
    int t,n;
    cin>>t;
    while(t--) {
        cin>>n;
        cout<<a[n]<<endl;
    }

    return 0;
}
