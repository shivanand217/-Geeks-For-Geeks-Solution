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

int dx[] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[] = {2, 1, -1, -2, -2, -1, 1, 2};

int main() {
    fast;
    int t;
    cin>>t;
    string s1,s2;
    int x1,y1,x2,y2;
    int ans;

    bool vis[9][9];

    while( t-- ) {
        memset(vis, false, sizeof(vis));
        ans=0;

        cin>>s1>>s2;
        x1 = s1[0] - 'a';
        x1++;
        y1 = s1[1] - '1';
        y1++;
        x2 = s2[0] - 'a';
        x2++;
        y2 = s2[1] - '1';
        y2++;

        queue<pair<int, pair<int,int > > > q;
        q.push(make_pair(0, make_pair(x1,y1) ) );

        vis[x1][y1] = true;
        pair< int, pii > p;
        int a, b, d, x, y;

        while( !q.empty() ) {
            p = q.front();
            q.pop();

            a = p.ss.ff;
            b = p.ss.ss;
            d = p.ff;

            vis[a][b] = true;

            if( ( a == x2 && b == y2 ) ) {
                ans = d;
                break;
            }

            for(int i=0; i < 8; i++) {
                x = a + dx[i];
                y = b + dy[i];
                if( x >= 1 && y >= 1 && x <= 8 && y <= 8 ) {
                    if( vis[x][y] == false ) {
                        q.push(make_pair(d+1,make_pair(x,y)));
                    }
                }
            }
        }

        cout<<ans<<endl;
    }

    return 0;
}
