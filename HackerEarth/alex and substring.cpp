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
int pre[100005];
int a[100005];

int main() {
    fast;
    int t,n;
    cin>>t;
    string s;
    vector<int> p[26];

    while(t--) {
        for(int i = 0; i < 26; i++) {
            p[i].clear();
        }
        cin>>n;
        cin>>s;
        for(int i=0; i<n; i++) {
            cin>>a[i];
            pre[i] = 0;
        }
        pre[0] = a[0];
        for(int i=1; i<n; i++){
            pre[i] = a[i] + pre[i-1];
        }
        for(int i=0; i<s.length(); i++) {
            p[s[i]-'a'].push_back(i);
        }

        int ans = 0;
        for(int i = 0; i < 26; i++) {
            int m = p[i].size();
            if( m <= 1 ) {
                continue;
            }
            for(int j = 0; j < p[i].size()-1; j++) {
                for(int k = j+1; k < p[i].size(); k++) {
                    if(p[i][j] + 1 == p[i][k]) {
                        ans++; continue;
                    }
                    if(pre[p[i][k]-1] - pre[p[i][j]] == 0) {
                        ans++;
                    }
                }
            }
        }

        cout<<ans<<endl;
    }

    return 0;
}
