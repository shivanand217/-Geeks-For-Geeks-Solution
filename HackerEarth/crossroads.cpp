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
int dx[] = {0,0,1,-1,-1,-1,1,1};
int dy[] = {1,-1,0,0,1,-1,-1,1};
int n;
bool _search(char a[20][20],int x, int y, string s) {
    bool ans = false;
    int len = s.length();
    int k;
    for( int d = 0; d < 8; d++ ) {
        int xx = x + dx[d];
        int yy = y + dy[d];
        for(k = 1; k < len; k++) {
            if(xx < 0 || xx >= n || yy < 0 || yy >= n)
                break;
            if(a[xx][yy] != s[k])
                break;
            xx = xx + dx[d];
            yy = yy + dy[d];
        }
        if(k == len) {
            return true;
        }
    }
    return ans;
}
bool pat( char a[20][20], string s ) {
    bool ans = false;
    for(int i=0; i < n; i++) {
        for(int j=0; j < n; j++) {
            if(a[i][j] == s[0]) {
                if( _search(a,i,j,s) == true ) {
                    return true;
                }
            }
        }
    }
    return ans;
}
int main() {
    fast;
    cin>>n;
    char a[20][20];
    for( int i = 0; i < n; i++ ) {
        for( int j = 0; j < n; j++ ) {
            cin>>a[i][j];
        }
    }
    int q;
    cin>>q;
    string s;
    bool ans = true;

    while(q--) {
        cin>>s;
        if(pat(a,s) == false) {
            ans = false;
        }
    }

    if(ans == true) {
        cout<<"True"<<endl;
    } else {
        cout<<"False"<<endl;
    }

    return 0;
}
