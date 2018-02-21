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
    int t;
    cin>>t;

    int x1,y1,x2,y2,r1,r2;
    double dist,R;

    while(t--) {
        cin>>x1>>y1>>r1;
        cin>>x2>>y2>>r2;

        dist = (double)sqrt(1.0*(x1-x2)*(x1-x2)*1.0 + 1.0*(y1-y2)*(y1-y2)*1.0);

        R = (double)(r1 * 1.0 + 1.0 * r2);

        if(R < dist) {
            cout<<"not overlapping"<<endl;
        } else if(R == dist) {
            cout<<"tangential"<<endl;
        } else {
            cout<<"overlapping"<<endl;
        }
    }

    return 0;
}
