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
    int t;
    cin>>t;
    int n,m,k,x;
    int odd,even;
    string s;

    while(t--) {
        odd=0;
        even=0;
        cin>>n>>m>>x>>k;
        cin>>s;
        for(int i=0; i < s.length(); i++) {
            if(s[i]=='E'){
                even++;
            } else {
                odd++;
            }
        }
        bool ans=false;
        int cap;
        for(int i=1; i <= m; i++){
            if( (i%2) == 1) {
                if(odd > 0) {
                    if(odd < x){
                        cap=odd;
                    } else {
                        cap=x;
                    }
                    odd -= cap;
                    n -= cap;
                    if(n<=0){
                        ans=true;
                        break;
                    }
                }
            } else {
                if(even > 0) {
                    if(even < x){
                        cap=even;
                    } else {
                        cap=x;
                    }
                    even -= cap;
                    n -= cap;
                    if(n <= 0){
                        ans=true;
                        break;
                    }
                }
            }
        }
        if(ans == true) {
            cout<<"yes"<<endl;
        } else {
            cout<<"no"<<endl;
        }
    }

    return 0;
}
