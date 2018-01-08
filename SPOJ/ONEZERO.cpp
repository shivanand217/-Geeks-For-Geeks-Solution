#include <bits/stdc++.h>

#define mp make_pair
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
string ans;

bool ok(long long n) {
    bool fa=true;
    while(n) {
        if( n/10 == 0 && n != 1 ) {
            fa = false;
        }
        int k = n%10;
        if( k != 1 && k != 0 ) {
            fa = false;
        }
        n /= 10;
    }
    return fa;
}

void bfs( long long n ) {
    queue<pair<string,long long> > q;
    pair<string,int> p;
    q.push(make_pair("1",1));
    long long a;
    while(!q.empty()) {
        p=q.front();
        q.pop();
        a=p.ss;
        if(a%n == 0) {
            ans=p.ff;
            return;
        }

        p.ss = p.ss%n;
        q.push( make_pair(p.ff+"0",p.ss*10) );
        q.push( make_pair(p.ff+"1",p.ss*10+1));
    }
}

int main() {
    fast;
    int t;
    cin>>t;
    long long n;
    bool as;
    while( t-- ) {
        cin>>n;
        if(ok( n )) {
            cout<<n<<endl;
            continue;
        }
        bfs(n);
        cout<<ans<<endl;
    }
    return 0;
}

