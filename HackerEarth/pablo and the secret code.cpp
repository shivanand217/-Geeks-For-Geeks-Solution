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
// special value of infinity to take for getting rid of overflows
const int inf = 0x3f3f3f3f;

/******************* Problem Code *****************/

ll prime[2000005];

void seive() {
    for( ll i = 0; i < 2000000; i++ )
        prime[i] = 0;
    prime[0] = prime[1] = 1;
    for( ll i = 2; i*i < 2000000; i++ ) {
        if( prime[i] == 0 ) {
            for( ll j = 2*i; j < 2000000; j += i ) {
                prime[j] = 1;
            }
        }
    }
}

bool compare( string x, string y ) {
    return ((x + y) >= (y + x));
}

int main() {
    fast;
    seive();
    ll t, n;
    ll tmp;
    cin>>t;
    vector<string> v;
    string s,ans;
    ll p;

    while(t--) {
        v.clear();
        ans = "";
        cin>>n;

        for( ll i = 0; i < n; i++ ) {
            cin>>tmp;
            if( tmp == 0 ) {
                v.push_back(to_string(tmp));
            } else if( prime[tmp] == 1 ) {
                s = to_string(tmp);
                v.push_back(s);
            }
        }

        if( v.size() == 0 ) {
            cout<<"No Secret Code!"<<endl;
            continue;
        }

        s = "";

        sort(v.begin(), v.end(), compare);
        for(int i = 0; i < v.size(); i++) {
            s += v[i];

        int fl = 0;
        for( int i = 0; i < s.length(); i++ ) {
            if( s[i] != '0' ) {
                fl=1;break;
            }
        }
        if( fl == 1 )
            cout<<s<<endl;
        else
            cout<<0<<endl;
    }

    return 0;
}
