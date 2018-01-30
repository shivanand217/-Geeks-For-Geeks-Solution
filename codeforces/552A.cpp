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

//const int mxx = 10005;
// special value of infinity to take for getting rid of overflows
const int inf = 0x3f3f3f3f;

int a[1055];
long long C[1055][1055];

int main() {
    C[0][0]=1;
    for(int i=1; i < 1055; i++) {
        C[i][0]=1;
        for(int j=1; j<=i; j++) {
            C[i][j] = (C[i-1][j] + C[i-1][j-1])%mod;
        }
    }
    int k;
    cin>>k;
    vector<int> color(k+2);
    for(int i=0; i<k; i++) {
        cin>>color[i];
    }

    long long res=1;
    int tot=0;
    for(int i=0; i<k; i++) {
        res = (res * C[tot + color[i] - 1][color[i] - 1])%mod;
        tot += color[i];
    }

    cout<<res<<endl;

    return 0;
}
