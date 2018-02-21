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

int _count[26];
int prefix[26][100005];

bool validate(int x, int y) {
    int cnt;
    for(int i = 0; i < 26; i++) {
        if(x !=0 ) {
            cnt = prefix[i][y] - prefix[i][x-1];
        } else {
            cnt = prefix[i][y];
        }
        if(cnt > _count[i]) return false;
    }
    return true;
}

int solve(int x, int l, int r){
    if(l > r) return -1;
    int mid = (l + (r-l)/2);
    if( validate(x, mid) ) {
        if( validate(x, mid+1) == false )
            return mid;
        else
            return solve(x, mid+1, r);
    } else {
        return solve(x, l, mid-1);
    }
}

int main() {
    fast;
    int n;
    cin>>n;
    string s;
    cin>>s;
    memset(prefix, 0, sizeof(prefix));

    for(int i=0;i<26;i++) {
        cin>>_count[i];
    }
    for(int i=0;i<n;i++) {
        prefix[s[i] - 'a'][i]=1;
    }
    for(int i=0;i<26;i++){
        for(int j=1;j<n;j++){
            prefix[i][j]=prefix[i][j]+prefix[i][j-1];
        }
    }

    int mx = 0;
    int l,r;

    for(int i=0; i < n; i++) {
        int res;
        if(validate(i, n-1) == true){
            res = n-1;
        } else {
            res = solve(i, i, n-1);
        }
        if(res != -1 && res-i+1 > mx){
            mx = res-i+1;
            l = i+1;
            r = res+1;
        }
    }

    if(mx > 0) {
        cout<<l<<" "<<r<<endl;
    } else {
        cout<<"No Solution"<<endl;
    }

    return 0;
}
