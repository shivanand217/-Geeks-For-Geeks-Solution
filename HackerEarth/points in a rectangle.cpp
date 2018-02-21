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
    int t,n;
    cin>>t;
    int x1,y1,x2,y2;
    int X1,Y1,X2,Y2,X,Y,ans;
    while(t--) {
        ans=0;
        cin>>x1>>y1>>x2>>y2;
        if(x1 > x2) {
            X1=x1;
            X2=x2;
        } else {
            X1=x2;
            X2=x1;
        }
        if(y1 > y2){
            Y1=y1;
            Y2=y2;
        } else {
            Y1=y2;
            Y2=y1;
        }
        cin>>n;
        for(int i = 0; i < n; i++) {
            cin>>X>>Y;
            if( (X < X1 && X > X2) && (Y < Y1 && Y > Y2) )
                ans++;
        }
        cout<<ans<<endl;
    }

    return 0;
}
