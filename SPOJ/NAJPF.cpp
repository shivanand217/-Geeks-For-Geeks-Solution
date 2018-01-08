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

string txt , pat;
vector<int> ans;

int lps[1000005];

void computeLPS(int pattern_length) {
    int len = 0;
    int i=0;

    lps[ len ] = 0;
    i=1; /** start matching by 0th and 1st character **/

    while( i < pattern_length ) {
        if( pat[ i ] == pat[ len ] ) {
            len++;
            lps[i]=len;
            i++;

        } else {
            if(len != 0) {
                len=lps[len-1];
            } else {
                lps[i]=0;
                i++;
            }
        }
    }
}

void kmp( string pat, string txt ) {
    int pat_len = pat.length();
    int txt_len = txt.length();

    computeLPS( pat_len );
    int i = 0, j = 0;

    while ( i < txt.length() ) {

        if( pat[ j ] == txt[ i ] ) {
            i++;
            j++;
        }

        if( j == pat.length() ) {
            ans.push_back(i - j + 1);
            j = lps[j - 1];

        } else if( i < txt.length() && pat[j] != txt[i] ) {

            if( j != 0 ) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }

}

int main() {
    fast;
    int t;
    cin>>t;

    while( t-- ) {

        ans.clear();
        cin>>txt>>pat;
        kmp( pat, txt );

        if(ans.size() == 0) {
            cout<<"Not Found"<<endl;

        } else {
            cout<<ans.size()<<endl;
            for( auto i : ans ) {
                cout<<i<<" ";

            } cout<<endl;
        }

        cout<<endl;

    }

    return 0;
}
