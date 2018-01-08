/** KMP with modification on array **/

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

long long a[100005];
int lps[100005];
string pat ,txt;
bool ans;

void computeLPS(int pat_len) {

    int len = 0;
    int i = 0;
    lps[i] = 0;

    i=1;

    while( i < pat.length() ) {
        if(pat[i] == pat[len]) {
            len++;
            lps[i]=len;
            i++;
        } else {
            if( len != 0 ) {
                len = lps[ len - 1 ];

            } else {
                lps[ i ] = 0;
                i++;
            }
        }
    }
}

void kmp() {
    int pat_len = pat.length();
    int txt_len = txt.length();

    computeLPS(pat_len);
    int i = 0, j = 0;

    while ( i < txt.length() ) {

        if( txt[i] == pat[j] ) {
            i++;
            j++;
        }

        if( j == pat.length() ) {
            ans = true;
            break;

        } else if( i < txt.length() && pat[ j ] != txt[ i ] ) {

            if (j != 0) {
                j = lps[ j - 1 ];
            } else {
                i++;
            }
        }
    }
}

int main() {
    fast;
    int t , n;
    cin>>t;

    while( t-- ) {
        ans = false;
        txt = "";
        cin>>n;

        for( int i = 0 ; i < n ; i++ ) {
            cin>>a[i];
        }
        cin>>pat;

        for( int i = n - 2; i >= 0; i-- ) {
            if( a[ i + 1 ] > a[ i ] ) {
                txt += 'G' ;

            } else if( a[ i + 1 ] < a[ i ] ) {
                txt += 'L' ;

            } else if( a[ i + 1 ] == a[ i ] ) {
                txt += 'E' ;

            }
        }

        reverse( txt.begin() , txt.end() );
        kmp();

        if( ans == true ) {
            cout<<"YES"<<endl;
        } else {
            cout<<"NO"<<endl;
        }
    }

    return 0;
}
