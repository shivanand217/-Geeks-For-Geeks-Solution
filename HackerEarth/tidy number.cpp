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

bool check(ll num) {
    string s = "";
    while(num) {
        s += ((num%10) + '0');
        num/=10;
    }
    reverse(s.begin(),s.end());
    int i=1;
    while(i < s.length()) {
        if(s[i]-'0' < s[i-1]-'0'){
            return false;
        }
        i++;
    }
    return true;
}
int solve(int num) {
    int ans = -1;
    while(num) {
        if(check(num)) {
            return num;
        }
        num--;
    }
}
int main() {
    fast;
    int t;
    cin>>t;
    int n;
    while(t--) {
        cin>>n;
        int ans = solve(n);
        cout<<ans<<endl;
    }
    return 0;
}
