
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
bool cmp(int x,int y){
	return x>y;
}

int main() {
    fast;
    int t,n,m;
    cin>>t;
    for( int k=1; k<=t; k++ ) {
        cin>>m>>n;
        int a[n];
        for(int i=0; i<n;i++){
            cin>>a[i];
        }
        sort(a, a+n, cmp);
        int sum=0,cnt=0;;
        for( int i=0;i<n;i++ ){
            sum += a[i];
            if(sum>=m) {
                cnt++;
                break;
            }
            cnt++;
        }
        cout<<"Scenario #"<<k<<":"<<endl;
        if(sum < m ) {
            cout<<"impossible"<<endl;
        } else {
            cout<<cnt<<endl;
        }
        cout<<endl;
    }

    return 0;
}
