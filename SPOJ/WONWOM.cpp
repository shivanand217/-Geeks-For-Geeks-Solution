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

typedef pair < int,int > pii;
// special value of infinity to take for getting rid of overflows
const int inf = 0x3f3f3f3f;

bool compare(const string& a, const string& b) {

    string f = a+b;
    string s = b+a;
    return ( f > s );

}

int main() {

    fast;
    int n;
    cin>>n;
    string s;
    vector<string> v;
    // string s;
    for(int i=0; i<n; i++){
        cin>>s;
        v.pb(s);
    }
    sort(v.begin(),v.end(),compare);
    for(int i=0;i<v.size();i++) {
        cout<<v[i];
    } cout<<endl;

    return 0;
}
