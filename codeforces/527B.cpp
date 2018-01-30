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

int main() {
    fast;
    int n;
    cin>>n  ;

    string s , t;
    cin>>s>>t;

    int cnt[26] = {0};
    int cnt1[26] = {0};

    int pos=0; // pos differ

    for(int i=0; i < s.length(); i++) {

        if( s[i] == t[i] )
            continue;
        else {
            pos++;
            cnt[ s[i] - 'a' ]++ ;
            cnt1[ t[i] - 'a' ]++ ;
        }
    }

    if(pos == 0) {
        cout<<"0"<<endl;
        cout<<"-1 -1"<<endl;
        return 0;
    }

    if(pos == 1) {
        cout<<"1"<<endl;
        cout<<"-1 -1"<<endl;
        return 0;
    }



    return 0;
}
