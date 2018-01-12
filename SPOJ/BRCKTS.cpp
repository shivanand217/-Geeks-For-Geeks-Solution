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

// special value of infinity to take for getting rid of overflows
const int inf = 0x3f3f3f3f;

/******************* Problem Code *****************/

/** Simple point update segment tree structure **/

const int mxx = 40005;

char B[mxx];

struct Treenode {
    int open_bracket,close_bracket;
};

struct Treenode Tree[ 4 * mxx ];

void init( int n ) {
    for( int i=1; i <= 4*n; i++ ) {
        Tree[i].open_bracket=0;
        Tree[i].close_bracket=0;
    }
}

void build( int node, int s, int e ) {
    if( s == e ) {
        if( B[s] == '(' ) {
            Tree[node].open_bracket = 1;
            Tree[node].close_bracket = 0;
        } else {
            Tree[node].close_bracket = 1;
            Tree[node].open_bracket = 0;
        }
        return;
    }
    int mid=(s+e)/2;
    build(2*node, s, mid);
    build(2*node+1, mid+1, e);

    int left = 2*node;
    int right = 2*node+1;

    if( Tree[left].close_bracket > 0 ) {
        Tree[node].close_bracket = Tree[left].close_bracket;
    }
    if( Tree[right].open_bracket > 0 ) {
        Tree[node].open_bracket = Tree[right].open_bracket;
    }
    if( Tree[left].open_bracket > Tree[right].close_bracket ) {
        Tree[node].open_bracket += ( Tree[left].open_bracket - Tree[right].close_bracket );
    } else if ( Tree[right].close_bracket > Tree[left].open_bracket ) {
        Tree[node].close_bracket += ( Tree[right].close_bracket - Tree[left].open_bracket );
    }
}

void update( int node, int s, int e, int index ) {
    if( s == e ) {
        if( B[index] == '(' ) {
            B[index] = ')';
            Tree[node].close_bracket = 1;
            Tree[node].open_bracket = 0;
        } else {
            B[index] = '(';
            Tree[node].open_bracket=1;
            Tree[node].close_bracket=0;
        }
        return;
    }

    int mid = ( s + e )/2;
    int left = 2*node;
    int right = 2*node+1;

    if( index <= mid ) {
        update( left, s, mid, index );
    } else {
        update( right, mid+1, e, index );
    }

    Tree[node].close_bracket=0;
    Tree[node].open_bracket=0;

    if( Tree[left].close_bracket > 0 ) {
        Tree[node].close_bracket = Tree[left].close_bracket;
    }
    if( Tree[right].open_bracket > 0 ) {
        Tree[node].open_bracket = Tree[right].open_bracket;
    }
    if( Tree[left].open_bracket > Tree[right].close_bracket ) {
        Tree[node].open_bracket += ( Tree[left].open_bracket - Tree[right].close_bracket );
    } else if ( Tree[right].close_bracket > Tree[left].open_bracket ) {
        Tree[node].close_bracket += ( Tree[right].close_bracket - Tree[left].open_bracket );
    }
    return;
}

int main() {
    int t , op ,tmp;
    int p = 10 , i = 1;

    for( ; i <= p ; i++ ) {
        scanf("%d", &t);
        scanf("%\ns", B);
        scanf("%d", &op);

        /** init segment tree **/
        init( strlen(B) );

        build(1, 0, strlen(B)-1);
        printf("Test %d:\n", i);

        while( op-- ) {
            scanf("%d", &tmp);
            if( tmp == 0 ) {
                if( Tree[1].open_bracket == 0 && Tree[1].close_bracket == 0 ){
                    printf("YES\n");
                } else {
                    printf("NO\n");
                }
            } else {
                update( 1, 0, strlen(B)-1, tmp-1 );
            }
        }
    }
    return 0;
}
