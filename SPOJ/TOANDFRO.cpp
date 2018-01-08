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

typedef pair< int, int > pii;

const int mxx = 100001;
// special value of infinity to take for getting rid of overflows
const int inf = 0x3f3f3f3f;

int main() {
    string s;
    vector< string > v;
    int cnt;

    while(1) {

        cnt=0;
        v.clear();
        int n;
        cin>>n;
        if(n == 0)
            break;
        string tmp = "";
        cin>>s;
        int j = 0;

        for(int i = 0; i < s.length(); i++) {
            cnt++;
            if( cnt == n ) {
                tmp += s[i];
                if( j % 2 == 1 ) {
                    reverse( tmp.begin() , tmp.end() );
                    v.push_back( tmp );
                } else {
                    v.push_back( tmp );
                }
                tmp = "";
                cnt = 0;
                j++;
            } else {
                tmp += s[i];
            }
        }

        string ans = "";
        for ( int j = 0; j < n; j++ ) {
            for ( int i = 0 ; i < v.size(); i++ ) {
                ans += v[i][j];
            }
        }

        cout<<ans<<endl;
    }

    return 0;
}


