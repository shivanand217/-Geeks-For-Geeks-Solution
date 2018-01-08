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

char p[1003][1003];
bool vis[1003][1003];

int dx[]={0,-1,1,0};
int dy[]={1,0,0,-1};

int a,b,max_,cnt,n,m,p1,p2;

void dfs(int x,int y,int cnt) {
    vis[x][y]=true;
    if(cnt>max_){
        max_=cnt;
        p1=x;
        p2=y;
    }
    for(int i=0; i < 4; i++) {
        a=dx[i]+x;
        b=dy[i]+y;
        if(a >= 0 && b >= 0 && a < n && b < m){
            if(vis[a][b]==false && p[a][b]=='.'){
                dfs(a, b, cnt+1);
            }
        }
    }
}

int main() {
    fast;
    int t;
    cin>>t;
    //int n,m;
    for (int k = 1; k <= t;  k++ ) {
        cin>>m>>n;
        for( int i=0; i < n; i++ ) {
            for( int j=0; j < m; j++ ) {
                cin>>p[i][j];
                vis[i][j]=false;
            }
        }
        max_ = INT_MIN;
        cnt = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if( vis[i][j] == false && p[i][j] == '.' ) {
                    cnt=0;
                    dfs(i,j,cnt);
                    break;
                }
            }
        }
        max_ = 0;
        memset( vis, false, sizeof(vis) );
        dfs(p1,p2,0);
        cout<<"Maximum rope length is "<<max_<<"."<<endl;
    }
    return 0;
}
