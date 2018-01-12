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

/** Solution offline with BIT. Merge sort tree won't work in this case BUT it is working with PROBLEM: KQUERYNO **/

#define MAX 30005

int tree[30009];

void update(int pos) {
    while(pos <= MAX) {
        tree[pos] += 1;
        pos += (pos & -pos);
    }
}

int query(int pos) {
    int result = 0;
    while(pos) {
        result += tree[pos];
        pos -= (pos & -pos);
    }
    return result;
}

struct data {
    int value , pos;
};

struct query_data {
    int i , j , k , pos;
};

bool compare( const data &a , const data &b ) {
    return a.value > b.value;
}

bool cmp(const query_data &a , const query_data &b) {
    return a.k > b.k;
}

int main() {
    int n;
    scanf("%d",&n);

    data arr[n+9];

    for(int i = 0 ; i < n ; i++)
        scanf("%d",&arr[i].value), arr[i].pos = i+1;

    /** sorting array in decreasing order **/
    sort(arr , arr+n , compare);

    int q_no;
    scanf("%d",&q_no);

    query_data q[ q_no + 10 ];

    for( int i = 0 ; i < q_no ; i++ )
        scanf("%d%d%d",&q[i].i ,&q[i].j , &q[i].k) , q[i].pos = i;

    int result[q_no + 10];
    /** sort query with decreasing value of k **/
    sort(q , q+q_no , cmp);

    int pos = 0;

    for(int i = 0 ; i<q_no ; i++) {

        while(pos < n && arr[pos].value > q[i].k) {
            update(arr[pos].pos);
            pos++;
        }

        result[q[i].pos] = query(q[i].j) - query(q[i].i - 1);
    }

    for( int i = 0 ; i < q_no ; i++ )
        printf("%d\n",result[i]);

    return 0;
}
