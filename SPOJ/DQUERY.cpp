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

#define N 300001
#define A 1000007
#define block 555

int cnt[A], a[N], ans[N];

struct node {
    int L, R, i;
} q[ N ];

int answer=0;

/** sort queries **/
bool cmp( node x, node y ) {
    if( x.L/block != y.L/block ) {
        return x.L/block < y.L/block;
    }
    return x.R < y.R;
}

void add(int pos) {
    cnt[a[pos]]++;
    if(cnt[a[pos]] == 1) {
        answer++;
    }
}

void remove_(int pos) {
    cnt[a[pos]]--;
    if(cnt[a[pos]] == 0) {
        answer--;
    }
}

int main() {

    int n;
	scanf("%d", &n);
	for(int i=0; i<n; i++)
		scanf("%d", &a[i]);

	int m;
	scanf("%d", &m);

	for(int i=0; i<m; i++) {
		scanf("%d%d", &q[i].L, &q[i].R);
		q[i].L--; q[i].R--;
		q[i].i = i;
	}

	sort(q, q + m, cmp);
	int currentL = 0, currentR = 0;

	for(int i=0; i<m; i++) {
		int L = q[i].L, R = q[i].R;
		while(currentL < L) {
			remove_(currentL);
			currentL++;
		}
		while(currentL > L) {
			add(currentL-1);
			currentL--;
		}
		while(currentR <= R) {
			add(currentR);
			currentR++;
		}
		while(currentR > R+1) {
			remove_(currentR-1);
			currentR--;
		}
		ans[q[i].i] = answer;
	}

	for(int i=0; i<m; i++)
		printf("%d\n", ans[i]);

    return 0;
}
