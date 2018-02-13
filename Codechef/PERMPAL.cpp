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

int freq[26];
int ans[100005];

int main() {
    int t;
    cin>>t;
    string s;
    vector<int> adj[26];

    while( t-- ) {
        memset(freq, 0, sizeof(freq));
        cin>>s;
        for(int i=0; i<26; i++) {
            adj[i].clear();
        }

        for(int i=0; i < s.length(); i++) {
            freq[s[i]-'a']++;
            adj[s[i]-'a'].push_back(i+1);
        }
        int one = 0;
        for(int i = 0; i < 26; i++) {
            if(freq[i]%2 == 1) {
                one++;
            }
        }

        if(one > 1 ) {
            cout<<"-1"<<endl;
            continue;
        } else {
            int len = s.length();

            int mid = -1;
            if(one == 1) {
                mid = ((len+1)/2);
            }
            int i = 0, p , q, j;
            int lo = 1, hi = len;

            for(i=0; i < 26; i++){
                for(j=0; j < freq[i]/2; j++) {
                    ans[lo++] = adj[i][2*j];
                    ans[hi--] = adj[i][2*j+1];
                }
                if(freq[i]%2 == 1) {
                    ans[mid] = adj[i][adj[i].size()-1];
                }
            }

            for(i=1; i <= len; i++) {
                cout<<ans[i]<<" ";
            }   cout<<endl;
        }
    }

    return 0;
}
