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

const int mxx = 40005;
// special value of infinity to take for getting rid of overflows
const int inf = 0x3f3f3f3f;

/******************* Problem Code *****************/
int par[mxx];
int dist[mxx];

void init( int n ) {
    for( int i = 1; i <= n; i++ ) {
        par[i] = i;
        dist[i] = 0;
    }
}

void find_(int x) {
    if(x != par[x]) {
        /** first going to the root **/
        find_(par[x]);
        /** after coming back update the distances of childs
            in the recursion **/
        dist[x] += dist[par[x]];
        /** doing path compression **/
        par[x] = par[par[x]];
    }
}

int main() {
    int t, n, ans, x, y, I;
    scanf("%d", &t);
    char c;

    while(t--) {
        scanf("%d", &n);
        init(n);

        while(1) {
            scanf("%c", &c);
            if(c == 'O') {
                break;
            }

            if(c == 'I') {
                scanf("%d %d", &x, &y);
                par[x] = par[y];
                dist[x] = dist[y] + ( abs(x-y))%1000;

            } else if(c == 'E') {
                scanf("%d", &I);
                find_(I);
                printf("%d\n", dist[I]);
            }
        }

    }

    return 0;
}
