/**
          General mistakes for C/C++ programmers which can be very much frustating.
          * check for overflows
          * check and mod and use int type variables where possible to avoid tles
          * while multiplying two variables whose value can exceed integer
            limit make sure to typecase them
          * use scanf when you are not working with the best possible optimisation
          * return a value from a function that has a return type sometimes the
            compiler may give the correct answer but there will be problem in the judge
          * be very cautious about uninitialised variables , infact never keep them
            or handle them properly
	  * If you are going to use any variable or value of any type of array must first initialise it
**/

#include <bits/stdc++.h>

#define mp make_pair
#define ll long long
#define pb push_back

#define ss second
#define ff first
#define ss second
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

const int mx = 212;
// special value of infinity to take for getting rid of overflows
const int inf = 0x3f3f3f3f;

int dist1[mx][mx], dist2[mx][mx], dist3[mx][mx];
char k[mx][mx];
int n,m;

int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};

void bfs(int f, int x, int y) {

    queue<pair<int,pair<int,int> > > q;
    q.push(make_pair(0, make_pair(x,y)));
    pair<int,pair<int,int> > p;

    int x1,y1,depth,k1,k2;

    while( !q.empty() ) {
        p = q.front();
        q.pop();

        x1=p.ss.ff;
        y1=p.ss.ss;
        depth=p.ff;

        if(f==1){
            dist1[x1][y1]=depth;
        }
        if(f==2){
            dist2[x1][y1]=depth;
        }
        if(f==3){
            dist3[x1][y1]=depth;
        }

        for(int i=0; i<4; i++) {
            k1 = x1+dx[i];
            k2 = y1+dy[i];
            if(f==1) {
                if( k1>=0 && k2>=0 && k1<n && k2<m && k[k1][k2] != '#' && dist1[k1][k2]==-1 ){
                    q.push(make_pair(depth+1, make_pair(k1,k2)));
                }
            }
            if(f==2) {
                if( k1>=0 && k2>=0 && k1<n && k2<m && k[k1][k2] != '#' && dist2[k1][k2]==-1 ){
                    q.push(make_pair(depth+1, make_pair(k1,k2)));
                }
            }
            if(f==3) {
                if( k1>=0 && k2>=0 && k1<n && k2<m &&  k[k1][k2] != '#' && dist3[k1][k2]==-1 ){
                    q.push(make_pair(depth+1, make_pair(k1,k2)));
                }
            }
        }
    }

}

int main() {
    int t;
    //scanf("%d",&t);
    cin>>t;
    char kl;
    int x1,y1,x2,y2,x3,y3;

    while(t--) {

        cin>>n>>m;
        for(int i=0; i<=n+1; i++){
            k[i][0]='.';
            k[i][m+1]='.';
        }

        for(int j=0; j<=m+1; j++){
            k[0][j]='.';
            k[n+1][j]='.';
        }

        memset(dist1,-1,sizeof(dist1));
        memset(dist2,-1,sizeof(dist2));
        memset(dist3,-1,sizeof(dist3));

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
          //      cin>>k[i][j];
                if(k[i][j] == '1') {
                    x1=i;
                    y1=j;
                }
                if(k[i][j] == '2') {
                    x2=i;
                    y2=j;
                }
                if(k[i][j] == '3') {
                    x3=i;
                    y3=j;
                }
            }
        }

        n+=2;
        m+=2;

        bfs(1,x1,y1);
        bfs(2,x2,y2);
        bfs(3,x3,y3);

        int ans1 , ans2=INT_MAX;

        for(int i=0; i<=n; i++) {
            for(int j=0; j<=m; j++) {
                if(dist1[i][j] != -1 && dist2[i][j]!=-1 && dist3[i][j]!=-1) {
                    ans1 = max(dist1[i][j],max(dist2[i][j], dist3[i][j]));
                    if(ans1 < ans2){
                        ans2=ans1;
                    }
                }
            }
        }

        cout<<ans2<<endl;
    }

    return 0;
}
