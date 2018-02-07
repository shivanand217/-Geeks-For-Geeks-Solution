#include <bits/stdc++.h>
#define mp make_pair
#define ll long long
#define pb push_back
#define se second
#define fi first
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

const int mxx = 200001;
// special value of infinity to take for getting rid of overflows
const int inf = 0x3f3f3f3f;

/** 26 character ka BIT jo ki store karega us character ka frequency us index tak **/
int BIT[27][mxx + 10];

/** ye bolega ki ye index wala element delete hai ya nahi **/
bool vis[200005];

/** Ye update Karega character s ka frequency **/
void update(char s, int index, int val) {

    for( int i = index; i <= mxx; i = i + (i & (-i)) ) {
        BIT[s - 'a'][i] = BIT[s - 'a'][i] + val;
    }
}

/** ye return karega character s ka frequency upto a given index **/
int query(char s, int index) {

    int ans = 0;

    for( int i = index; i >= 1; i = i - (i & (-i)) ) {
        ans += BIT[s - 'a'][i];
    }

    return ans;
}

/** binary search use kar lenge frequency decrease karne ke liye
    Binary Search use karenge jis character ka frequency ghatana hai
    us character ke BIT par
**/

int BS(char s, int ind) {
    int mid, low, high, ans;
    low = 1;
    high = mxx;

    while(low <= high) {
        mid = (low + high)/2;
        if( query(s, mid) >= ind ) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    /** ab us index par update kar dena hai kyonki gauranteed hai ki wo character wahan
        exist karta hi hai
    **/
    update(s, ans, -1);

    return ans;
}

int main() {

    fast;
    memset( vis, 0, sizeof(vis) );
    string s;
    cin>>s;

    int q,k;
    cin>>q;

    char c;

    // update
    for(int i=0; i < s.length(); i++){
        update( s[i], i+1, 1 );
    }

    while( q-- ) {
        cin>>k>>c;
        /** we have to delete kth occurence of charcter c **/
        int index = BS(c, k);

        vis[index-1] = 1;
    }

    for(int i=0; i < s.length(); i++) {
        if(vis[i] == 0){
            cout<<s[i];
        }
    }   cout<<endl;

    return 0;
}
