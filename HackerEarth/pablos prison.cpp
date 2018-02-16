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

const int mxx = 600010;
// special value of infinity to take for getting rid of overflows
const int inf = 0x3f3f3f3f;

/******************* Problem Code *****************/
int vow[mxx] , con[mxx];

int main() {
    fast;
    int t;
    cin>>t;
    string s;

    while(t--) {
        memset(vow,0,sizeof(vow));
        memset(con,0,sizeof(con));
        cin>>s;
        int len = s.length()-1;
        for(int i = len; i >= 0; i--) {
            if( (s[i]=='a') || (s[i]=='e') || (s[i]=='i') || (s[i]=='o') || (s[i]=='u') ) {
                if(i!=len) {
                    vow[i]=vow[i+1]+1;
                    con[i]=con[i+1];
                } else {
                    vow[i]=1;
                }
            } else {
                if(i != len) {
                    con[i]=con[i+1]+1;
                    vow[i]=vow[i+1];
                }else{
                    con[i]=1;
                }
            }
        }
        ll ans = 0;
        for( int i=0; i <= len; i++ ) {
            if( (s[i] == 'a') || (s[i] == 'e') || (s[i] == 'i') || (s[i] == 'o') || (s[i] == 'u') ) {
                ans += con[i];
            } else {
                ans += vow[i];
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}
