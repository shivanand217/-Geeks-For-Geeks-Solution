#include <bits/stdc++.h>
#define mp make_pair
#define ll long long
#define pb push_back

#define ss second
#define ff first
#define si(x) scanf( "%d", &x )
#define slli(x) scanf( "%lld", &x )
#define pi(x) printf( "%d", x )

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

int arr[ mxx ];
int smaller_left[ mxx ];

int getsum( int BIT[] ,int index ) {
    int sum = 0;

    while(index > 0) {
        sum += BIT[index];
        index = index - (index & (-index) );
    }

    return sum;
}

void update( int BIT[], int index, int maxx, int val ) {

    while( index <= maxx ) {
        BIT[index] += val;
        index = index + (index & (-index) );
    }
}

int solve(int n) {
    int temp[n];
    int invcount_count_3 = 0;

    for(int i = 0; i < n; i++) {
        temp[i] = arr[i];
    }
    sort(temp, temp + n);

    for( int i=0; i < n; i++ ) {
        arr[i] = lower_bound(temp, temp + n, arr[i]) - temp + 1;
    }

    int BIT1[n+1];
    int BIT2[n+1];

    for(int i = 0 ; i <= n; i++) {
        BIT1[i] = 0;
        BIT2[i] = 0;
    }

    /** precomputation to store number of values greater than j before j which is mid in our inversion sequence a[i] > a[j] > a[k] **/
    for( int i = 0; i < n; i++ ) {

        smaller_left[i] = 0;
        smaller_left[i] = getsum( BIT2 , arr[i] );
        update( BIT2, arr[i], n, 1 );
    }

    int greater_element = 0;

    for(int i = n - 1; i >= 0; i-- ) {
        greater_element = (i - smaller_left[i]);

        /** get the elements smaller which are right side **/
        invcount_count_3 +=  ( greater_element * getsum( BIT1 , arr[i] - 1 ) );

        update( BIT1, arr[i] , n, 1 );
    }

    return invcount_count_3;
}

int main() {
    int n;
    cin>>n;

    for(int i = 0; i < n; i++) {
        cin>>arr[i];
    }

    int invcount = solve(n);
    cout<<invcount<<endl;

    return 0;
}
