#include<bits/stdc++.h>
#define mp make_pair
#define ll long long
#define pb push_back
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
char c[1005][1005];
bool vis[1005][1005];
int mx,mxx;
void f(int x,int y,int x_boundary,int y_boundary) {
    mx++;
    vis[x][y]=true;
    if(x+1 < x_boundary && c[x+1][y]=='x' && vis[x+1][y] == false) {
        f(x+1, y, x_boundary, y_boundary);
    }
    if(y+1 < y_boundary && c[x][y+1]=='x' && vis[x][y+1] == false) {
        f(x, y+1, x_boundary, y_boundary);
    }
    if(x-1 >= 0 && c[x-1][y]=='x' && vis[x-1][y] == false) {
        f(x-1, y, x_boundary, y_boundary);
    }
    if(y-1 >= 0 && c[x][y-1]=='x' && vis[x][y-1] == false) {
        f(x, y-1, x_boundary, y_boundary);
    }
}
int main() {
    fast;
    int n,m;
    cin>>n>>m;
    mxx=0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin>>c[i][j];
            vis[i][j] = false;
        }
    }
    int comp=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(vis[i][j]==false && c[i][j]=='x'){
                mx=0;
                comp++;
                f(i,j,n,m);
                mxx = max(mx,mxx);
            }
        }
    }
    cout<<comp<<" "<<mxx<<endl;

    return 0;
}
