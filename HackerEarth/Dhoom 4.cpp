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

typedef pair<long long,int> pii;

const int mxx = 100001;
// special value of infinity to take for getting rid of overflows
const int inf = 0x3f3f3f3f;

/******************* Problem Code *****************/
long long a[1006];

int main() {
    fast;
    int n ,k, m;
    cin>>n>>k;
    cin>>m;
    for(int i=0; i < m; i++) {
        cin>>a[i];
    }
    //sort(a, a + m);
    queue<pair<long long,int> > q;
    long long w;int ans=-1;
    for(int i=0; i < m; i++) {
        w = (long long)n * a[i];
        w %= 100000;
        if(w == k) {
            ans=1;
            break;
        }
        q.push(make_pair(w, 1));
    }
    if(ans != -1) {
        cout<<ans<<endl;
        return 0;
    }
    pii p;
    int time;
    while( !q.empty() ) {
        p = q.front();
        q.pop();
        w = p.ff;
        time = p.ss;
        if(w == k) {
            ans=time;
            break;
        }
        for(int i=0;i<m;i++) {
            w = w * a[i];
            w %= 100000;
            if(w == k) {
                ans=time+1;
                break;
            }
            q.push(make_pair(w,time+1));
        }
    }
    cout<<ans<<endl;

    return 0;
}
