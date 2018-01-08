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

#define rep(i,n) for(int i = 0; i < n; i++)
#define fast std::ios::sync_with_stdio(false)
#define gc() getchar()
#define pc(x) putchar(x)

using namespace std;
typedef pair<int,int> pii;

const int mxx = 100001;
// special value of infinity to take for getting rid of overflows
const int inf = 0x3f3f3f3f;

/** Using BIT for inversion count **/

string s[30016];
unordered_map<string, int> un;
int a[30016];

int getSum(int BIT[], int index) {
    int sum = 0;

    /** Important to take index > 0 here not >= 0 **/

    while(index > 0) {

        sum += BIT[index];
        index = index - ( index & (-index) );
    }

    return sum;
}

void update(int BIT[], int maxx, int index, int val) {

    while( index <= maxx ) {

        BIT[index] += val;
        index = index + ( index & (-index) );
    }
}

int F(int n) {
    int maxx = *max_element( a, a + n );

    int BIT[maxx + 1];

    for( int i=0; i <= maxx; i++ ) {
        BIT[i]=0;
    }

    int invcount = 0;

    for(int i=n-1; i >= 0; i--) {
        invcount += getSum(BIT , a[i] - 1);

        /** send that now update this element in BIT and increase its count **/

         update( BIT, maxx, a[i], 1);
    }

    return invcount;
}

int main() {
    fast;
    int t;
    cin>>t;

    int n;
    string tmp;

    while(t--) {
        cin>>n;
        for(int i = 0 ; i < n ; i++) {
            cin>>s[i];
        }

        /** important to update BIT always when array contain value > 1 **/
        for(int i=0; i < n; i++) {
            cin>>tmp;
            un[tmp] = i+1;
        }

        for(int i=0; i < n; i++) {
            a[i] = un[s[i]];
        }

        /** now we Only need to calculate the inversion count of array a[] **/
        int invcount = F(n);

        cout<<invcount<<endl;
    }

    return 0;
}
