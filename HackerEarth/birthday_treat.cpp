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
bool palin(string s) {
    int i = 0, j = s.length() - 1;

    while(i < j) {
        if(s[i] != s[j]) {
            return false;
        }
        i++ , j--;
    }
    return true;
}
int main() {
    fast;
    int t;
    cin>>t;
    string s;

    while(t--) {
        cin>>s;
        if(palin(s)) {
            cout<<"1"<<endl;
        } else {
            cout<<"2"<<endl;
        }
    }

    return 0;
}
