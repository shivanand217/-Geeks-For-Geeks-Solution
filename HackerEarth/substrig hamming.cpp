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
    int T;
    cin>>T;

    string s,t;
    int match = 0,lo,hi,len,k;
    int _hash[26];
    unordered_map<char,int> un;

    while(T--) {
        memset(_hash,0,sizeof(_hash));
        cin>>s;
        cin>>t;
        cin>>k;
        match=0;

        int l=s.length()-t.length();
        bool ans=false;
        for(int i=0; i<=l; i++) {
            match = 0;
            for(int j = 0; j<t.length(); j++) {
                if( s[i+j] == t[j] ) {
                    match++;
                }
            }
            if(match >= k){
                ans=true;
                break;
            } else {
                ans=false;
            }
        }

        if(ans == true) {
            cout<<"Yes"<<endl;
        } else {
            cout<<"No"<<endl;
        }
    }

    return 0;
}
