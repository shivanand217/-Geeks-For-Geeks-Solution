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

int main() {
    float n;
    int br;

    while(1) {
        cin>>n;
        if( n == 0.00 ) {
            break;
        }
        br = 1;
        float sum=0.00;

        while(sum < n) {
            br++;
            sum += (1*1.0)/(br);
        }

        --br;
        cout<<br<<" card(s)"<<endl;
    }

    return 0;
}
