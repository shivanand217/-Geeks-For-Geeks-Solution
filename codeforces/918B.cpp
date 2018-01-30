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
    int n,m;
    cin>>n>>m;
    string NAME,IP,COMMAND;
    unordered_map<string,string> CACHE;

    for(int i=0; i < n; i++) {
        cin>>NAME>>IP;
        CACHE[IP] = NAME;
    }

    int len;
    vector<pair<string , pair<string, string> > >  ans;

    for(int i=0; i < m; i++) {
        cin>>COMMAND>>IP;
        len = IP.length()-1;
        IP.erase(len, 1);
        ans.push_back( make_pair(COMMAND, make_pair(IP, CACHE[IP]) ) );
    }

    for( int i=0; i<ans.size(); i++ ) {
        cout<<ans[i].ff<<" "<<ans[i].ss.ff<<";"<<" #"<<ans[i].ss.ss<<endl;
    }

    return 0;
}
