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

string k[302];

int n,m,a,b;
bool vis[300][300];
int cnt1,cnt2,tot1,tot2;

int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};

void dfs(int x, int y){
    vis[x][y]=true;
    if(k[x][y]=='k'){
        cnt1++;
    }
    if(k[x][y]=='v'){
        cnt2++;
    }
    for(int i=0; i<4; i++){
        a=x+dx[i];
        b=y+dy[i];

        if(a>=0 && a<n && b>=0 && b<m && vis[a][b]==false && k[a][b]!='#'){
            dfs(a,b);
        }
    }
}

int main() {
    tot1=0;tot2=0;
    cin>>n>>m;
    for(int i=0;i<n;i++) {
        cin>>k[i];
    }
    memset(vis,false,sizeof(vis));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(vis[i][j]==false && (k[i][j] != '#') ){
                cnt1=0; cnt2=0;

                dfs(i,j);

                if(cnt1 == cnt2){
                    tot2 += cnt2;

                } else if(cnt1 > cnt2){
                    tot1 += cnt1;
                } else {
                    tot2 += cnt2;
                }
            }
        }
    }

    cout<<tot1<<" "<<tot2<<endl;

    return 0;
}
