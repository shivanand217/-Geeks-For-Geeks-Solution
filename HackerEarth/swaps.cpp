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
int a[100005];
int main() {
    fast;
    int n,k;
    cin>>n>>k;
    for(int i=0; i<n; i++) {
        cin>>a[i];
    }
    int mx = 0, num = 0, one;
    int i=0;
    while(i < n){
        one = 0;
        if(a[i] >= k) {
            while(a[i] >= k){
                num++;
                one++;
                i++;
            }
            if(mx < one) {
                mx = one;
            }
        } else {
            i++;
        }
    }
    if(num == n) {
        cout<<"0"<<endl;
    } else {
        if(mx == num) {
            cout<<"0"<<endl;
        } else {
            cout<<(num - mx)<<endl;
        }
    }

    return 0;
}
