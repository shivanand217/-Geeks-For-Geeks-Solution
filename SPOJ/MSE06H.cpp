#include<bits/stdc++.h>
using namespace std;

#define ff first
#define ss second

#define pb push_back
#define mp make_pair

typedef pair<int,int> pii;
vector< pii > v;

int BIT[10009];

/** Sort this by East coast value **/

bool comp( pii x, pii y ) {
    if( x.ff == y.ff )
        return ( x.ss < y.ss ) ;
    return x.ff < y.ff;
}

void update(int pos , int mxx) {
    while(pos <= mxx) {
        BIT[pos] += 1;
        pos += (pos & -pos);
    }
}

long long sum( int pos ) {
    long long s = 0;
    while(pos > 0) {
        s += BIT[pos];
        pos -= (pos & -pos);
    }
    return s;
}

int main() {
    int t;
    scanf( "%d" , &t );

    for( int l = 1; l <= t; l++ ) {

        int n, m, a, b, k;

        v.clear();
        memset(BIT , 0 , sizeof(BIT));

        scanf("%d%d%d", &n, &m, &k);

        for(int i=0; i < k; i++) {

            scanf("%d%d", &a, &b);
            // p = mp(a,b);
            v.push_back(make_pair(a, b));
        }

        sort( v.begin(), v.end(), comp );
        long long s = 0;

        for( int i = 0; i < k; i++ ) {

            /** sum(x) will give number of elements smaller than
                current index present before current index
                so we subtract it with i to get number of greater
                element before current index **/

            s  += ( i - sum( v[i].ss ) );

            /** Sending update upto maxx value **/
            update( v[i].ss ,  m );
        }

        printf("Test case %d: %lld\n", l , s);
    }

    return 0;
}
