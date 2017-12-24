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
string mat[52];
int sol[52][52];
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int dfs(int r,int c,char letter,int h,int w) {
    if(sol[r][c] != -1)
        return sol[r][c];
    int cur_pos=1;
    for(int i=0; i < 8; ++i){
        if(r+dx[i] < 0 || r+dx[i] >= h || c+dy[i] < 0 || c+dy[i] >= w)
            continue;
        if(mat[r+dx[i]][c+dy[i]] == letter)
            cur_pos = max(cur_pos,1+dfs(r+dx[i],c+dy[i],letter+1,h,w));
    }
    sol[r][c] = cur_pos;
    return cur_pos;
}
int main() {
    fast;
    int h,w,t;
    for(int kl=1; ; kl++) {
        cin>>h>>w;
        if(h==0 && w==0)
            break;
        int sol1=0;
        memset(sol,-1,sizeof(sol));
        for(int i=0;i<h;i++) {
            cin>>mat[i];
        }
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                if(mat[i][j]!='A')
                    continue;
                sol1=max(sol1,dfs(i,j,'B',h,w));
            }
        }
        printf("Case %d: %d\n", kl, sol1);
    }
    return 0;
}
