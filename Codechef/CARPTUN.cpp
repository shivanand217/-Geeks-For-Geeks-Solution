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

/******************* Problem Code *****************/
int main() {
    int t;
    cin>>t;

    double t1,t2;
    int N,C,D,S;
    int tmp,k;
    double ans;

    while(t--) {
        cin>>N;
        long long sum = 0;
        for(int i = 0; i < N; i++) {
            cin>>tmp;
            if(i == 0)
                k = tmp;
            sum += tmp;
        }

        cin>>C>>D>>S;

        t1 = (double)(1.0*sum + ((1.0*(N-1)*D)/S*1.0));
        t2 = (double)(1.0*t1 + 1.0*(C-1)*k);
        ans = (double)(1.0*(t2 - t1));

        printf("%.9f\n", ans);
    }

    return 0;
}
